#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_8023a424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A424: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A428: lbu         $t6, 0x89B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X89B);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a42c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a42c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A42C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023A438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023A43C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023A440: lw          $a3, 0x98($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X98);
    // 0x8023A444: bne         $t6, $at, L_8023A450
    if (ctx->r14 != ctx->r1) {
        // 0x8023A448: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8023A450;
    }
    // 0x8023A448: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8023A44C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8023A450:
    // 0x8023A450: beq         $a1, $zero, L_8023A464
    if (ctx->r5 == 0) {
        // 0x8023A454: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8023A464;
    }
    // 0x8023A454: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8023A458: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8023A45C: bne         $a1, $at, L_8023A46C
    if (ctx->r5 != ctx->r1) {
        // 0x8023A460: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8023A46C;
    }
    // 0x8023A460: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8023A464:
    // 0x8023A464: b           L_8023A49C
    // 0x8023A468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8023A49C;
    // 0x8023A468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023A46C:
    // 0x8023A46C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8023A470: bne         $v0, $at, L_8023A480
    if (ctx->r2 != ctx->r1) {
        // 0x8023A474: nop
    
            goto L_8023A480;
    }
    // 0x8023A474: nop

    // 0x8023A478: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8023A47C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8023A480:
    // 0x8023A480: jal         0x802333FC
    // 0x8023A484: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x802333FC)(rdram, ctx);
        goto after_0;
    // 0x8023A484: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x8023A488: beql        $v0, $zero, L_8023A49C
    if (ctx->r2 == 0) {
        // 0x8023A48C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8023A49C;
    }
    goto skip_0;
    // 0x8023A48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8023A490: b           L_8023A49C
    // 0x8023A494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8023A49C;
    // 0x8023A494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8023A498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023A49C:
    // 0x8023A49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A4A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023A4A4: jr          $ra
    // 0x8023A4A8: nop

    return;
    // 0x8023A4A8: nop

;}
RECOMP_FUNC void M10_FUN_8023a4ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A4B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023A4B4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8023A4B8: addiu       $a1, $a3, 0x2
    ctx->r5 = ADD32(ctx->r7, 0X2);
    // 0x8023A4BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023A4C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8023A4C4: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x8023A4C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A4CC: mfhi        $a1
    ctx->r5 = hi;
    // 0x8023A4D0: lw          $a0, 0x98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98);
    // 0x8023A4D4: jal         0x8013C8F0
    // 0x8023A4D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8013C8F0)(rdram, ctx);
        goto after_0;
    // 0x8023A4D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8023A4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A4E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023A4E4: jr          $ra
    // 0x8023A4E8: nop

    return;
    // 0x8023A4E8: nop

;}
RECOMP_FUNC void M10_FUN_8023a4ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A4EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8023A4F0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023A4F4: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A4F8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8023A4FC: lbu         $t6, 0x8B8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X8B8);
    // 0x8023A500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023A504: beq         $t6, $zero, L_8023A514
    if (ctx->r14 == 0) {
            // 0x8023A508: nop

    LOOKUP_FUNC(0x8023A514)(rdram, ctx);
    return;
    }
    // 0x8023A508: nop

    // 0x8023A50C: jr          $ra
    // 0x8023A510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8023A510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a514(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A514: jr          $ra
    // 0x8023A518: nop

    return;
    // 0x8023A518: nop

;}
RECOMP_FUNC void M10_FUN_8023a51c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A51C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023A520: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023A524: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023A528: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023A52C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x8023A530: lbu         $a1, 0x1C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1C);
    // 0x8023A534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8023A53C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8023A540: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x8023A544: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8023A548: lbu         $a0, 0x1B($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1B);
    // 0x8023A54C: lbu         $a2, 0x1D($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1D);
    // 0x8023A550: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8023A554: bgez        $a1, L_8023A560
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8023A558: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_8023A560;
    }
    // 0x8023A558: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x8023A55C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
L_8023A560:
    // 0x8023A560: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8023A564: jal         0x80243E50
    // 0x8023A568: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80243E50)(rdram, ctx);
        goto after_0;
    // 0x8023A568: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8023A56C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8023A570: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8023A574: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8023A578: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8023A57C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8023A580: lbu         $t1, 0xA8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XA8);
    // 0x8023A584: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023A588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023A58C: bne         $t1, $at, L_8023A59C
    if (ctx->r9 != ctx->r1) {
        // 0x8023A590: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023A59C;
    }
    // 0x8023A590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A594: b           L_8023A59C
    // 0x8023A598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8023A59C;
    // 0x8023A598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8023A59C:
    // 0x8023A59C: jr          $ra
    // 0x8023A5A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8023A5A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a5a4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a5a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A5A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A5A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A5AC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023A5B0: jal         0x8023A51C
    // 0x8023A5B4: lbu         $a1, 0x89E($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X89E);
    LOOKUP_FUNC(0x8023A51C)(rdram, ctx);
        goto after_0;
    // 0x8023A5B4: lbu         $a1, 0x89E($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X89E);
    after_0:
    // 0x8023A5B8: beq         $v0, $zero, L_8023A5C8
    if (ctx->r2 == 0) {
        // 0x8023A5BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023A5C8;
    }
    // 0x8023A5BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A5C0: b           L_8023A5CC
    // 0x8023A5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8023A5CC;
    // 0x8023A5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8023A5C8:
    // 0x8023A5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023A5CC:
    // 0x8023A5CC: jr          $ra
    // 0x8023A5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8023A5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a5d4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a5d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A5D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8023A5D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8023A5DC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8023A5E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8023A5E4: jal         0x80006214
    // 0x8023A5E8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8023A5E8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_0:
    // 0x8023A5EC: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023A5F0: addiu       $s0, $s0, 0x880
    ctx->r16 = ADD32(ctx->r16, 0X880);
    // 0x8023A5F4: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x8023A5F8: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8023A5FC: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8023A600: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x8023A604: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8023A608: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8023A60C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023A610: addiu       $t1, $zero, 0x20B
    ctx->r9 = ADD32(0, 0X20B);
    // 0x8023A614: addiu       $t7, $t6, -0x12
    ctx->r15 = ADD32(ctx->r14, -0X12);
    // 0x8023A618: sb          $v0, 0x46($sp)
    MEM_B(0X46, ctx->r29) = ctx->r2;
    // 0x8023A61C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8023A620: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8023A624: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8023A628: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023A62C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8023A630: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023A634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023A638: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023A63C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A640: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A644: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8023A648: jal         0x80146208
    // 0x8023A64C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8023A64C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_1:
    // 0x8023A650: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x8023A654: lh          $t2, 0x16($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X16);
    // 0x8023A658: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8023A65C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8023A660: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8023A664: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8023A668: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8023A66C: addiu       $t7, $zero, 0x20B
    ctx->r15 = ADD32(0, 0X20B);
    // 0x8023A670: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8023A674: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x8023A678: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8023A67C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8023A680: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8023A684: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8023A688: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8023A68C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8023A690: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8023A694: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023A698: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023A69C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A6A0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A6A4: jal         0x80146208
    // 0x8023A6A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x8023A6A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x8023A6AC: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x8023A6B0: lh          $t9, 0x16($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X16);
    // 0x8023A6B4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8023A6B8: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x8023A6BC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8023A6C0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8023A6C4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8023A6C8: addiu       $t4, $zero, 0x20B
    ctx->r12 = ADD32(0, 0X20B);
    // 0x8023A6CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8023A6D0: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8023A6D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8023A6D8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8023A6DC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8023A6E0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8023A6E4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8023A6E8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8023A6EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8023A6F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023A6F4: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023A6F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A6FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A700: jal         0x80146208
    // 0x8023A704: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8023A704: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x8023A708: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x8023A70C: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8023A710: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8023A714: addiu       $a3, $a3, -0x12
    ctx->r7 = ADD32(ctx->r7, -0X12);
    // 0x8023A718: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8023A71C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8023A720: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023A724: addiu       $t1, $zero, 0x20B
    ctx->r9 = ADD32(0, 0X20B);
    // 0x8023A728: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8023A72C: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x8023A730: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8023A734: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8023A738: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8023A73C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8023A740: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023A744: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8023A748: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023A74C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023A750: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023A754: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A758: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A75C: jal         0x80146208
    // 0x8023A760: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x8023A760: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x8023A764: lbu         $t3, 0x46($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X46);
    // 0x8023A768: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8023A76C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8023A770: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8023A774: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8023A778: lw          $t5, -0x2578($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2578);
    // 0x8023A77C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8023A780: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x8023A784: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8023A788: jr          $ra
    // 0x8023A78C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8023A78C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a790(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A790: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8023A794: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8023A798: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x8023A79C: addiu       $fp, $fp, 0x880
    ctx->r30 = ADD32(ctx->r30, 0X880);
    // 0x8023A7A0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8023A7A4: lbu         $s0, 0x20($fp)
    ctx->r16 = MEM_BU(ctx->r30, 0X20);
    // 0x8023A7A8: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A7AC: lw          $t6, -0x1AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1AB8);
    // 0x8023A7B0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8023A7B4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8023A7B8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8023A7BC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8023A7C0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8023A7C4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8023A7C8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8023A7CC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8023A7D0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8023A7D4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8023A7D8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023A7DC: jal         0x80006214
    // 0x8023A7E0: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8023A7E0: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    after_0:
    // 0x8023A7E4: addu        $a1, $fp, $s0
    ctx->r5 = ADD32(ctx->r30, ctx->r16);
    // 0x8023A7E8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8023A7EC: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x8023A7F0: addiu       $a2, $a2, -0x2578
    ctx->r6 = ADD32(ctx->r6, -0X2578);
    // 0x8023A7F4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8023A7F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8023A7FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8023A800:
    // 0x8023A800: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8023A804: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8023A808: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8023A80C: addu        $s2, $a1, $s1
    ctx->r18 = ADD32(ctx->r5, ctx->r17);
    // 0x8023A810: lbu         $v0, 0x51($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X51);
    // 0x8023A814: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x8023A818: mflo        $s0
    ctx->r16 = lo;
    // 0x8023A81C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023A820: mfhi        $s6
    ctx->r22 = hi;
    // 0x8023A824: andi        $s6, $s6, 0xFF
    ctx->r22 = ctx->r22 & 0XFF;
    // 0x8023A828: bne         $v1, $zero, L_8023A834
    if (ctx->r3 != 0) {
        // 0x8023A82C: nop
    
            goto L_8023A834;
    }
    // 0x8023A82C: nop

    // 0x8023A830: break       7
    do_break(2149820464);
L_8023A834:
    // 0x8023A834: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8023A838: bne         $v1, $at, L_8023A84C
    if (ctx->r3 != ctx->r1) {
        // 0x8023A83C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8023A84C;
    }
    // 0x8023A83C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8023A840: bne         $v0, $at, L_8023A84C
    if (ctx->r2 != ctx->r1) {
        // 0x8023A844: nop
    
            goto L_8023A84C;
    }
    // 0x8023A844: nop

    // 0x8023A848: break       6
    do_break(2149820488);
L_8023A84C:
    // 0x8023A84C: bgez        $s0, L_8023A860
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8023A850: andi        $s0, $s0, 0x3
        ctx->r16 = ctx->r16 & 0X3;
            goto L_8023A860;
    }
    // 0x8023A850: andi        $s0, $s0, 0x3
    ctx->r16 = ctx->r16 & 0X3;
    // 0x8023A854: beq         $s0, $zero, L_8023A860
    if (ctx->r16 == 0) {
        // 0x8023A858: nop
    
            goto L_8023A860;
    }
    // 0x8023A858: nop

    // 0x8023A85C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_8023A860:
    // 0x8023A860: jal         0x80006214
    // 0x8023A864: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8023A864: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    after_1:
    // 0x8023A868: sll         $s4, $s1, 2
    ctx->r20 = S32(ctx->r17 << 2);
    // 0x8023A86C: addu        $s4, $s4, $s1
    ctx->r20 = ADD32(ctx->r20, ctx->r17);
    // 0x8023A870: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x8023A874: addiu       $s4, $s4, 0x51
    ctx->r20 = ADD32(ctx->r20, 0X51);
    // 0x8023A878: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x8023A87C: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x8023A880: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8023A884: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8023A888: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8023A88C: addiu       $t0, $zero, 0x20B
    ctx->r8 = ADD32(0, 0X20B);
    // 0x8023A890: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8023A894: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8023A898: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8023A89C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023A8A0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8023A8A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A8A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8023A8AC: addu        $t1, $sp, $s0
    ctx->r9 = ADD32(ctx->r29, ctx->r16);
    // 0x8023A8B0: lbu         $t1, 0x78($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X78);
    // 0x8023A8B4: andi        $s3, $v0, 0xFF
    ctx->r19 = ctx->r2 & 0XFF;
    // 0x8023A8B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8023A8BC: addiu       $a1, $sp, 0x7E
    ctx->r5 = ADD32(ctx->r29, 0X7E);
    // 0x8023A8C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A8C4: addiu       $a3, $zero, 0xE1
    ctx->r7 = ADD32(0, 0XE1);
    // 0x8023A8C8: jal         0x80146208
    // 0x8023A8CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x8023A8CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_2:
    // 0x8023A8D0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8023A8D4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8023A8D8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8023A8DC: addiu       $t5, $zero, 0x20B
    ctx->r13 = ADD32(0, 0X20B);
    // 0x8023A8E0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8023A8E4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8023A8E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8023A8EC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8023A8F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8023A8F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023A8F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8023A8FC: addu        $t6, $sp, $s6
    ctx->r14 = ADD32(ctx->r29, ctx->r22);
    // 0x8023A900: lbu         $t6, 0x78($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X78);
    // 0x8023A904: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8023A908: addiu       $a1, $sp, 0x7E
    ctx->r5 = ADD32(ctx->r29, 0X7E);
    // 0x8023A90C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023A910: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    // 0x8023A914: jal         0x80146208
    // 0x8023A918: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8023A918: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_3:
    // 0x8023A91C: lbu         $t7, 0x38($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X38);
    // 0x8023A920: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8023A924: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8023A928: bne         $t7, $zero, L_8023A958
    if (ctx->r15 != 0) {
        // 0x8023A92C: addiu       $a2, $a2, -0x2578
        ctx->r6 = ADD32(ctx->r6, -0X2578);
            goto L_8023A958;
    }
    // 0x8023A92C: addiu       $a2, $a2, -0x2578
    ctx->r6 = ADD32(ctx->r6, -0X2578);
    // 0x8023A930: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x8023A934: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8023A938: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8023A93C: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x8023A940: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8023A944: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x8023A948: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8023A94C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8023A950: lbu         $t1, 0x22($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X22);
    // 0x8023A954: sb          $t1, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r9;
L_8023A958:
    // 0x8023A958: lbu         $v0, 0x20($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X20);
    // 0x8023A95C: lbu         $t5, 0x22($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X22);
    // 0x8023A960: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8023A964: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x8023A968: bne         $t5, $v0, L_8023A988
    if (ctx->r13 != ctx->r2) {
        // 0x8023A96C: addiu       $a2, $a2, -0x2578
        ctx->r6 = ADD32(ctx->r6, -0X2578);
            goto L_8023A988;
    }
    // 0x8023A96C: addiu       $a2, $a2, -0x2578
    ctx->r6 = ADD32(ctx->r6, -0X2578);
    // 0x8023A970: lbu         $t6, 0x23($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X23);
    // 0x8023A974: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8023A978: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8023A97C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8023A980: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8023A984: beq         $at, $zero, L_8023A994
    if (ctx->r1 == 0) {
        // 0x8023A988: slti        $at, $s5, 0x4
        ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
            goto L_8023A994;
    }
L_8023A988:
    // 0x8023A988: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8023A98C: bne         $at, $zero, L_8023A800
    if (ctx->r1 != 0) {
        // 0x8023A990: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_8023A800;
    }
    // 0x8023A990: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_8023A994:
    // 0x8023A994: lbu         $t0, 0x7D($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7D);
    // 0x8023A998: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8023A99C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8023A9A0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8023A9A4: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8023A9A8: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8023A9AC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8023A9B0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8023A9B4: sw          $t1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r9;
    // 0x8023A9B8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8023A9BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8023A9C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8023A9C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8023A9C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8023A9CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8023A9D0: jr          $ra
    // 0x8023A9D4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8023A9D4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a9d8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a9d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A9D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8023A9DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8023A9E0: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x8023A9E4: addiu       $s2, $s2, 0x880
    ctx->r18 = ADD32(ctx->r18, 0X880);
    // 0x8023A9E8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8023A9EC: lbu         $s5, 0x20($s2)
    ctx->r21 = MEM_BU(ctx->r18, 0X20);
    // 0x8023A9F0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8023A9F4: andi        $s4, $a0, 0xFF
    ctx->r20 = ctx->r4 & 0XFF;
    // 0x8023A9F8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8023A9FC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8023AA00: sll         $s5, $s5, 2
    ctx->r21 = S32(ctx->r21 << 2);
    // 0x8023AA04: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8023AA08: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8023AA0C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8023AA10: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8023AA14: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8023AA18: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8023AA1C: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x8023AA20: jal         0x80147D60
    // 0x8023AA24: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_0;
    // 0x8023AA24: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8023AA28: addu        $s3, $s2, $s5
    ctx->r19 = ADD32(ctx->r18, ctx->r21);
    // 0x8023AA2C: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x8023AA30: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x8023AA34: addiu       $s7, $s7, 0x5E0
    ctx->r23 = ADD32(ctx->r23, 0X5E0);
    // 0x8023AA38: addiu       $fp, $fp, 0x5E8
    ctx->r30 = ADD32(ctx->r30, 0X5E8);
    // 0x8023AA3C: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8023AA40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8023AA44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023AA48: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
L_8023AA4C:
    // 0x8023AA4C: addu        $v1, $s3, $s0
    ctx->r3 = ADD32(ctx->r19, ctx->r16);
    // 0x8023AA50: lbu         $t6, 0x51($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X51);
    // 0x8023AA54: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x8023AA58: bne         $s5, $zero, L_8023AA64
    if (ctx->r21 != 0) {
        // 0x8023AA5C: nop
    
            goto L_8023AA64;
    }
    // 0x8023AA5C: nop

    // 0x8023AA60: break       7
    do_break(2149821024);
L_8023AA64:
    // 0x8023AA64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8023AA68: bne         $s5, $at, L_8023AA7C
    if (ctx->r21 != ctx->r1) {
        // 0x8023AA6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8023AA7C;
    }
    // 0x8023AA6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8023AA70: bne         $t6, $at, L_8023AA7C
    if (ctx->r14 != ctx->r1) {
        // 0x8023AA74: nop
    
            goto L_8023AA7C;
    }
    // 0x8023AA74: nop

    // 0x8023AA78: break       6
    do_break(2149821048);
L_8023AA7C:
    // 0x8023AA7C: mflo        $v0
    ctx->r2 = lo;
    // 0x8023AA80: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8023AA84: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8023AA88: bnel        $at, $zero, L_8023AAD8
    if (ctx->r1 != 0) {
        // 0x8023AA8C: lbu         $v0, 0x20($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X20);
            goto L_8023AAD8;
    }
    goto skip_0;
    // 0x8023AA8C: lbu         $v0, 0x20($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X20);
    skip_0:
    // 0x8023AA90: lbu         $t7, 0x38($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X38);
    // 0x8023AA94: beql        $t7, $zero, L_8023AAD8
    if (ctx->r15 == 0) {
        // 0x8023AA98: lbu         $v0, 0x20($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X20);
            goto L_8023AAD8;
    }
    goto skip_1;
    // 0x8023AA98: lbu         $v0, 0x20($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X20);
    skip_1:
    // 0x8023AA9C: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023AAA0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8023AAA4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8023AAA8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023AAAC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023AAB0: addiu       $a1, $zero, 0xD1
    ctx->r5 = ADD32(0, 0XD1);
    // 0x8023AAB4: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8023AAB8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8023AABC: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8023AAC0: mflo        $a2
    ctx->r6 = lo;
    // 0x8023AAC4: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8023AAC8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8023AACC: jal         0x8001B204
    // 0x8023AAD0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8023AAD0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_1:
    // 0x8023AAD4: lbu         $v0, 0x20($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X20);
L_8023AAD8:
    // 0x8023AAD8: lbu         $t9, 0x22($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X22);
    // 0x8023AADC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8023AAE0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8023AAE4: bnel        $t9, $v0, L_8023AB08
    if (ctx->r25 != ctx->r2) {
        // 0x8023AAE8: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8023AB08;
    }
    goto skip_2;
    // 0x8023AAE8: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    skip_2:
    // 0x8023AAEC: lbu         $t0, 0x23($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X23);
    // 0x8023AAF0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8023AAF4: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8023AAF8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8023AAFC: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8023AB00: beq         $at, $zero, L_8023AB10
    if (ctx->r1 == 0) {
        // 0x8023AB04: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8023AB10;
    }
    // 0x8023AB04: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
L_8023AB08:
    // 0x8023AB08: bne         $at, $zero, L_8023AA4C
    if (ctx->r1 != 0) {
        // 0x8023AB0C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8023AA4C;
    }
    // 0x8023AB0C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8023AB10:
    // 0x8023AB10: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8023AB14: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8023AB18: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8023AB1C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8023AB20: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8023AB24: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8023AB28: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8023AB2C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8023AB30: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8023AB34: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8023AB38: jr          $ra
    // 0x8023AB3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8023AB3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023ab40(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023ab40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AB40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8023AB44: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8023AB48: addiu       $t6, $zero, 0xCC
    ctx->r14 = ADD32(0, 0XCC);
    // 0x8023AB4C: addiu       $t7, $zero, 0x54
    ctx->r15 = ADD32(0, 0X54);
    // 0x8023AB50: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8023AB54: addiu       $t9, $zero, 0x66
    ctx->r25 = ADD32(0, 0X66);
    // 0x8023AB58: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8023AB5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8023AB60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023AB64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8023AB68: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x8023AB6C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023AB70: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8023AB74: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8023AB78: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    // 0x8023AB7C: jal         0x80146178
    // 0x8023AB80: addiu       $a3, $zero, 0x4D
    ctx->r7 = ADD32(0, 0X4D);
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_0;
    // 0x8023AB80: addiu       $a3, $zero, 0x4D
    ctx->r7 = ADD32(0, 0X4D);
    after_0:
    // 0x8023AB84: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8023AB88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8023AB8C: jr          $ra
    // 0x8023AB90: nop

    return;
    // 0x8023AB90: nop

;}
RECOMP_FUNC void M10_FUN_8023ab94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AB94: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8023AB98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8023AB9C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8023ABA0: jal         0x80006214
    // 0x8023ABA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8023ABA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8023ABA8: addiu       $t6, $zero, 0x70
    ctx->r14 = ADD32(0, 0X70);
    // 0x8023ABAC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8023ABB0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8023ABB4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8023ABB8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023ABBC: addiu       $t1, $zero, 0x209
    ctx->r9 = ADD32(0, 0X209);
    // 0x8023ABC0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8023ABC4: sb          $v0, 0x46($sp)
    MEM_B(0X46, ctx->r29) = ctx->r2;
    // 0x8023ABC8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8023ABCC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8023ABD0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8023ABD4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8023ABD8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8023ABDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023ABE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8023ABE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023ABE8: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023ABEC: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8023ABF0: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    // 0x8023ABF4: jal         0x80146208
    // 0x8023ABF8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8023ABF8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x8023ABFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023AC00: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8023AC04: jal         0x80145348
    // 0x8023AC08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8023AC08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x8023AC0C: addiu       $t3, $zero, 0x70
    ctx->r11 = ADD32(0, 0X70);
    // 0x8023AC10: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8023AC14: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8023AC18: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8023AC1C: addiu       $t7, $zero, 0x209
    ctx->r15 = ADD32(0, 0X209);
    // 0x8023AC20: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8023AC24: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8023AC28: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8023AC2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8023AC30: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8023AC34: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8023AC38: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8023AC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023AC40: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023AC44: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8023AC48: addiu       $a3, $zero, 0x10A
    ctx->r7 = ADD32(0, 0X10A);
    // 0x8023AC4C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023AC50: jal         0x80146208
    // 0x8023AC54: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8023AC54: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x8023AC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023AC5C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8023AC60: jal         0x80145348
    // 0x8023AC64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x8023AC64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x8023AC68: lbu         $t9, 0x46($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X46);
    // 0x8023AC6C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8023AC70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8023AC74: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8023AC78: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8023AC7C: lw          $t1, -0x2578($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2578);
    // 0x8023AC80: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023AC84: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8023AC88: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8023AC8C: jr          $ra
    // 0x8023AC90: sw          $t1, 0x884($at)
    MEM_W(0X884, ctx->r1) = ctx->r9;
    return;
    // 0x8023AC90: sw          $t1, 0x884($at)
    MEM_W(0X884, ctx->r1) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023ac94(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023ac94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AC94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023AC98: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023AC9C: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023ACA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8023ACA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8023ACA8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8023ACAC: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x8023ACB0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8023ACB4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023ACB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8023ACBC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8023ACC0: addiu       $a1, $zero, 0x180
    ctx->r5 = ADD32(0, 0X180);
    // 0x8023ACC4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8023ACC8: jal         0x801453CC
    // 0x8023ACCC: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8023ACCC: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_0:
    // 0x8023ACD0: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023ACD4: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023ACD8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8023ACDC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8023ACE0: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8023ACE4: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x8023ACE8: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x8023ACEC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8023ACF0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8023ACF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8023ACF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8023ACFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8023AD00: jal         0x801453CC
    // 0x8023AD04: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_1;
    // 0x8023AD04: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_1:
    // 0x8023AD08: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023AD0C: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023AD10: lbu         $t3, 0x20($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X20);
    // 0x8023AD14: bnel        $t3, $zero, L_8023AD2C
    if (ctx->r11 != 0) {
        // 0x8023AD18: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_8023AD2C;
    }
    goto skip_0;
    // 0x8023AD18: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8023AD1C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8023AD20: b           L_8023AD34
    // 0x8023AD24: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
        goto L_8023AD34;
    // 0x8023AD24: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    // 0x8023AD28: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_8023AD2C:
    // 0x8023AD2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8023AD30: sb          $t5, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r13;
L_8023AD34:
    // 0x8023AD34: lbu         $t7, 0x22($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X22);
    // 0x8023AD38: lbu         $t8, 0x20($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X20);
    // 0x8023AD3C: bnel        $t7, $t8, L_8023AD58
    if (ctx->r15 != ctx->r24) {
        // 0x8023AD40: lw          $t2, 0x4($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X4);
            goto L_8023AD58;
    }
    goto skip_1;
    // 0x8023AD40: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8023AD44: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8023AD48: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8023AD4C: b           L_8023AD64
    // 0x8023AD50: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
        goto L_8023AD64;
    // 0x8023AD50: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x8023AD54: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
L_8023AD58:
    // 0x8023AD58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8023AD5C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8023AD60: sb          $t1, 0x22($t3)
    MEM_B(0X22, ctx->r11) = ctx->r9;
L_8023AD64:
    // 0x8023AD64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8023AD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023AD6C: jr          $ra
    // 0x8023AD70: nop

    return;
    // 0x8023AD70: nop

;}
RECOMP_FUNC void M10_FUN_8023ad74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AD74: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023AD78: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023AD7C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023ad80(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023ad80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AD80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023AD84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8023AD88: beq         $a0, $zero, L_8023ADAC
    if (ctx->r4 == 0) {
        // 0x8023AD8C: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8023ADAC;
    }
    // 0x8023AD8C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8023AD90: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8023AD94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8023AD98: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x8023AD9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8023ADA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8023ADA4: jal         0x801453CC
    // 0x8023ADA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8023ADA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
L_8023ADAC:
    // 0x8023ADAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8023ADB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023ADB4: jr          $ra
    // 0x8023ADB8: nop

    return;
    // 0x8023ADB8: nop

;}
RECOMP_FUNC void M10_FUN_8023adbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023ADBC: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x8023ADC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8023ADC4: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x8023ADC8: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x8023ADCC: andi        $t6, $a1, 0x8
    ctx->r14 = ctx->r5 & 0X8;
    // 0x8023ADD0: beq         $t6, $zero, L_8023ADDC
    if (ctx->r14 == 0) {
        // 0x8023ADD4: andi        $t7, $a1, 0x1
        ctx->r15 = ctx->r5 & 0X1;
            goto L_8023ADDC;
    }
    // 0x8023ADD4: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8023ADD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8023ADDC:
    // 0x8023ADDC: beq         $t7, $zero, L_8023ADE8
    if (ctx->r15 == 0) {
        // 0x8023ADE0: andi        $t8, $a1, 0x4
        ctx->r24 = ctx->r5 & 0X4;
            goto L_8023ADE8;
    }
    // 0x8023ADE0: andi        $t8, $a1, 0x4
    ctx->r24 = ctx->r5 & 0X4;
    // 0x8023ADE4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8023ADE8:
    // 0x8023ADE8: beq         $t8, $zero, L_8023ADF4
    if (ctx->r24 == 0) {
        // 0x8023ADEC: andi        $a0, $a1, 0x2
        ctx->r4 = ctx->r5 & 0X2;
            goto L_8023ADF4;
    }
    // 0x8023ADEC: andi        $a0, $a1, 0x2
    ctx->r4 = ctx->r5 & 0X2;
    // 0x8023ADF0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8023ADF4:
    // 0x8023ADF4: beq         $a0, $zero, L_8023AE00
    if (ctx->r4 == 0) {
        // 0x8023ADF8: nop
    
            goto L_8023AE00;
    }
    // 0x8023ADF8: nop

    // 0x8023ADFC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8023AE00:
    // 0x8023AE00: lbu         $t9, 0x8A0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X8A0);
    // 0x8023AE04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023AE08: bne         $t9, $at, L_8023AE2C
    if (ctx->r25 != ctx->r1) {
        // 0x8023AE0C: nop
    
            goto L_8023AE2C;
    }
    // 0x8023AE0C: nop

    // 0x8023AE10: beq         $a0, $zero, L_8023AE2C
    if (ctx->r4 == 0) {
        // 0x8023AE14: nop
    
            goto L_8023AE2C;
    }
    // 0x8023AE14: nop

    // 0x8023AE18: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x8023AE1C: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8023AE20: beq         $t1, $zero, L_8023AE2C
    if (ctx->r9 == 0) {
        // 0x8023AE24: nop
    
            goto L_8023AE2C;
    }
    // 0x8023AE24: nop

    // 0x8023AE28: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8023AE2C:
    // 0x8023AE2C: jr          $ra
    // 0x8023AE30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8023AE30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023ae34(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023ae34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AE34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023AE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023AE3C: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x8023AE40: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8023AE44: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x8023AE48: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x8023AE4C: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // 0x8023AE50: sh          $a1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r5;
    // 0x8023AE54: jal         0x8023A210
    // 0x8023AE58: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8023A210)(rdram, ctx);
        goto after_0;
    // 0x8023AE58: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8023AE5C: lhu         $v1, 0x1E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1E);
    // 0x8023AE60: beq         $v0, $zero, L_8023AE70
    if (ctx->r2 == 0) {
        // 0x8023AE64: lhu         $a1, 0x22($sp)
        ctx->r5 = MEM_HU(ctx->r29, 0X22);
            goto L_8023AE70;
    }
    // 0x8023AE64: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    // 0x8023AE68: b           L_8023AFC0
    // 0x8023AE6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8023AFC0;
    // 0x8023AE6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023AE70:
    // 0x8023AE70: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023AE74: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023AE78: lbu         $a3, 0x6A($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X6A);
    // 0x8023AE7C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023AE80: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x8023AE84: bnel        $t0, $a3, L_8023AF08
    if (ctx->r8 != ctx->r7) {
        // 0x8023AE88: lbu         $t4, 0x6B($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X6B);
            goto L_8023AF08;
    }
    goto skip_0;
    // 0x8023AE88: lbu         $t4, 0x6B($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6B);
    skip_0:
    // 0x8023AE8C: beq         $t7, $zero, L_8023AE9C
    if (ctx->r15 == 0) {
        // 0x8023AE90: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8023AE9C;
    }
    // 0x8023AE90: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8023AE94: b           L_8023AECC
    // 0x8023AE98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8023AECC;
    // 0x8023AE98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8023AE9C:
    // 0x8023AE9C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8023AEA0: beq         $t8, $zero, L_8023AEB0
    if (ctx->r24 == 0) {
        // 0x8023AEA4: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_8023AEB0;
    }
    // 0x8023AEA4: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8023AEA8: b           L_8023AECC
    // 0x8023AEAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8023AECC;
    // 0x8023AEAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8023AEB0:
    // 0x8023AEB0: beq         $t9, $zero, L_8023AEC0
    if (ctx->r25 == 0) {
        // 0x8023AEB4: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_8023AEC0;
    }
    // 0x8023AEB4: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x8023AEB8: b           L_8023AECC
    // 0x8023AEBC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8023AECC;
    // 0x8023AEBC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8023AEC0:
    // 0x8023AEC0: beql        $t1, $zero, L_8023AED0
    if (ctx->r9 == 0) {
        // 0x8023AEC4: lhu         $v0, 0x20($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X20);
            goto L_8023AED0;
    }
    goto skip_1;
    // 0x8023AEC4: lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X20);
    skip_1:
    // 0x8023AEC8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8023AECC:
    // 0x8023AECC: lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X20);
L_8023AED0:
    // 0x8023AED0: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
    // 0x8023AED4: bne         $t2, $zero, L_8023AEE4
    if (ctx->r10 != 0) {
        // 0x8023AED8: andi        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 & 0X10;
            goto L_8023AEE4;
    }
    // 0x8023AED8: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x8023AEDC: beql        $t3, $zero, L_8023AEF0
    if (ctx->r11 == 0) {
        // 0x8023AEE0: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_8023AEF0;
    }
    goto skip_2;
    // 0x8023AEE0: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    skip_2:
L_8023AEE4:
    // 0x8023AEE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8023AEE8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8023AEEC: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
L_8023AEF0:
    // 0x8023AEF0: beq         $at, $zero, L_8023AEFC
    if (ctx->r1 == 0) {
        // 0x8023AEF4: nop
    
            goto L_8023AEFC;
    }
    // 0x8023AEF4: nop

    // 0x8023AEF8: sb          $v1, 0x6A($a2)
    MEM_B(0X6A, ctx->r6) = ctx->r3;
L_8023AEFC:
    // 0x8023AEFC: b           L_8023AFC0
    // 0x8023AF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8023AFC0;
    // 0x8023AF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023AF04: lbu         $t4, 0x6B($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6B);
L_8023AF08:
    // 0x8023AF08: andi        $t5, $a1, 0x8
    ctx->r13 = ctx->r5 & 0X8;
    // 0x8023AF0C: bnel        $t0, $t4, L_8023AFC0
    if (ctx->r8 != ctx->r12) {
        // 0x8023AF10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8023AFC0;
    }
    goto skip_3;
    // 0x8023AF10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8023AF14: beq         $t5, $zero, L_8023AF24
    if (ctx->r13 == 0) {
        // 0x8023AF18: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8023AF24;
    }
    // 0x8023AF18: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8023AF1C: b           L_8023AF54
    // 0x8023AF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8023AF54;
    // 0x8023AF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8023AF24:
    // 0x8023AF24: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8023AF28: beq         $t6, $zero, L_8023AF38
    if (ctx->r14 == 0) {
        // 0x8023AF2C: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8023AF38;
    }
    // 0x8023AF2C: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8023AF30: b           L_8023AF54
    // 0x8023AF34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8023AF54;
    // 0x8023AF34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8023AF38:
    // 0x8023AF38: beq         $t7, $zero, L_8023AF48
    if (ctx->r15 == 0) {
        // 0x8023AF3C: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_8023AF48;
    }
    // 0x8023AF3C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8023AF40: b           L_8023AF54
    // 0x8023AF44: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8023AF54;
    // 0x8023AF44: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8023AF48:
    // 0x8023AF48: beq         $t8, $zero, L_8023AF54
    if (ctx->r24 == 0) {
        // 0x8023AF4C: nop
    
            goto L_8023AF54;
    }
    // 0x8023AF4C: nop

    // 0x8023AF50: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8023AF54:
    // 0x8023AF54: beq         $t0, $v1, L_8023AFBC
    if (ctx->r8 == ctx->r3) {
        // 0x8023AF58: sll         $t1, $a3, 2
        ctx->r9 = S32(ctx->r7 << 2);
            goto L_8023AFBC;
    }
    // 0x8023AF58: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8023AF5C: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x8023AF60: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8023AF64: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    // 0x8023AF68: sb          $v1, 0x6B($a2)
    MEM_B(0X6B, ctx->r6) = ctx->r3;
    // 0x8023AF6C: jal         0x8023A3C4
    // 0x8023AF70: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x8023A3C4)(rdram, ctx);
        goto after_1;
    // 0x8023AF70: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_1:
    // 0x8023AF74: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023AF78: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023AF7C: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023AF80: beq         $t0, $v0, L_8023AF9C
    if (ctx->r8 == ctx->r2) {
        // 0x8023AF84: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_8023AF9C;
    }
    // 0x8023AF84: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8023AF88: jal         0x8023A4EC
    // 0x8023AF8C: nop

    LOOKUP_FUNC(0x8023A4EC)(rdram, ctx);
        goto after_2;
    // 0x8023AF8C: nop

    after_2:
    // 0x8023AF90: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023AF94: bne         $v0, $zero, L_8023AFB4
    if (ctx->r2 != 0) {
        // 0x8023AF98: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023AFB4;
    }
    // 0x8023AF98: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
L_8023AF9C:
    // 0x8023AF9C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8023AFA0: sb          $t3, 0x6B($a2)
    MEM_B(0X6B, ctx->r6) = ctx->r11;
    // 0x8023AFA4: jal         0x8023A234
    // 0x8023AFA8: sb          $t3, 0x6A($a2)
    MEM_B(0X6A, ctx->r6) = ctx->r11;
    LOOKUP_FUNC(0x8023A234)(rdram, ctx);
        goto after_3;
    // 0x8023AFA8: sb          $t3, 0x6A($a2)
    MEM_B(0X6A, ctx->r6) = ctx->r11;
    after_3:
    // 0x8023AFAC: b           L_8023AFC0
    // 0x8023AFB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8023AFC0;
    // 0x8023AFB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023AFB4:
    // 0x8023AFB4: b           L_8023AFC0
    // 0x8023AFB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8023AFC0;
    // 0x8023AFB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8023AFBC:
    // 0x8023AFBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023AFC0:
    // 0x8023AFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023AFC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023AFC8: jr          $ra
    // 0x8023AFCC: nop

    return;
    // 0x8023AFCC: nop

;}
RECOMP_FUNC void M10_FUN_8023afd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AFD0: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x8023AFD4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023afd8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023afd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023AFD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023AFDC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8023AFE0: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x8023AFE4: addiu       $t9, $t9, -0x1AB4
    ctx->r25 = ADD32(ctx->r25, -0X1AB4);
    // 0x8023AFE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8023AFEC: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023AFF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023AFF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8023AFF8: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023AFFC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8023B000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023B004: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8023B008:
    // 0x8023B008: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8023B00C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8023B010: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8023B014: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8023B018: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8023B01C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8023B020: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8023B024: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8023B028: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8023B02C: bne         $at, $zero, L_8023B008
    if (ctx->r1 != 0) {
        // 0x8023B030: sw          $t2, 0x24($t4)
        MEM_W(0X24, ctx->r12) = ctx->r10;
            goto L_8023B008;
    }
    // 0x8023B030: sw          $t2, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r10;
    // 0x8023B034: bne         $a3, $zero, L_8023B118
    if (ctx->r7 != 0) {
        // 0x8023B038: sw          $a3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r7;
            goto L_8023B118;
    }
    // 0x8023B038: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8023B03C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023B040: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    // 0x8023B044: jal         0x80236320
    // 0x8023B048: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80236320)(rdram, ctx);
        goto after_0;
    // 0x8023B048: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8023B04C: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023B050: bne         $v0, $zero, L_8023B068
    if (ctx->r2 != 0) {
        // 0x8023B054: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023B068;
    }
    // 0x8023B054: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023B058: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x8023B05C: addiu       $t5, $t5, 0x678
    ctx->r13 = ADD32(ctx->r13, 0X678);
    // 0x8023B060: b           L_8023B074
    // 0x8023B064: sw          $t5, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r13;
        goto L_8023B074;
    // 0x8023B064: sw          $t5, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r13;
L_8023B068:
    // 0x8023B068: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023B06C: addiu       $t6, $t6, 0x67C
    ctx->r14 = ADD32(ctx->r14, 0X67C);
    // 0x8023B070: sw          $t6, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r14;
L_8023B074:
    // 0x8023B074: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023B078: jal         0x8023639C
    // 0x8023B07C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    LOOKUP_FUNC(0x8023639C)(rdram, ctx);
        goto after_1;
    // 0x8023B07C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    after_1:
    // 0x8023B080: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023B084: beq         $v0, $zero, L_8023B0B0
    if (ctx->r2 == 0) {
        // 0x8023B088: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023B0B0;
    }
    // 0x8023B088: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023B08C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023B090: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x8023B094: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x8023B098: addiu       $t7, $t7, 0x684
    ctx->r15 = ADD32(ctx->r15, 0X684);
    // 0x8023B09C: addiu       $t8, $t8, 0x688
    ctx->r24 = ADD32(ctx->r24, 0X688);
    // 0x8023B0A0: addiu       $t9, $t9, 0x690
    ctx->r25 = ADD32(ctx->r25, 0X690);
    // 0x8023B0A4: sw          $t7, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r15;
    // 0x8023B0A8: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
    // 0x8023B0AC: sw          $t9, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r25;
L_8023B0B0:
    // 0x8023B0B0: jal         0x80236C9C
    // 0x8023B0B4: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_2;
    // 0x8023B0B4: nop

    after_2:
    // 0x8023B0B8: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023B0BC: beq         $v0, $zero, L_8023B118
    if (ctx->r2 == 0) {
        // 0x8023B0C0: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023B118;
    }
    // 0x8023B0C0: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023B0C4: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023B0C8: jal         0x80234CE8
    // 0x8023B0CC: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    LOOKUP_FUNC(0x80234CE8)(rdram, ctx);
        goto after_3;
    // 0x8023B0CC: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    after_3:
    // 0x8023B0D0: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023B0D4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8023B0D8: bne         $t0, $zero, L_8023B0F4
    if (ctx->r8 != 0) {
        // 0x8023B0DC: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023B0F4;
    }
    // 0x8023B0DC: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023B0E0: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023B0E4: addiu       $v1, $v1, 0x69C
    ctx->r3 = ADD32(ctx->r3, 0X69C);
    // 0x8023B0E8: sw          $v1, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r3;
    // 0x8023B0EC: sw          $v1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r3;
    // 0x8023B0F0: sw          $v1, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r3;
L_8023B0F4:
    // 0x8023B0F4: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8023B0F8: beq         $t3, $zero, L_8023B110
    if (ctx->r11 == 0) {
        // 0x8023B0FC: lui         $t4, 0x8024
        ctx->r12 = S32(0X8024 << 16);
            goto L_8023B110;
    }
    // 0x8023B0FC: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x8023B100: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x8023B104: addiu       $t2, $t2, 0x6A0
    ctx->r10 = ADD32(ctx->r10, 0X6A0);
    // 0x8023B108: b           L_8023B118
    // 0x8023B10C: sw          $t2, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r10;
        goto L_8023B118;
    // 0x8023B10C: sw          $t2, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r10;
L_8023B110:
    // 0x8023B110: addiu       $t4, $t4, 0x6A8
    ctx->r12 = ADD32(ctx->r12, 0X6A8);
    // 0x8023B114: sw          $t4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r12;
L_8023B118:
    // 0x8023B118: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8023B11C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023B120: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x8023B124: bne         $a3, $at, L_8023B130
    if (ctx->r7 != ctx->r1) {
        // 0x8023B128: addiu       $t5, $t5, 0x6AC
        ctx->r13 = ADD32(ctx->r13, 0X6AC);
            goto L_8023B130;
    }
    // 0x8023B128: addiu       $t5, $t5, 0x6AC
    ctx->r13 = ADD32(ctx->r13, 0X6AC);
    // 0x8023B12C: sw          $t5, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r13;
L_8023B130:
    // 0x8023B130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023B134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023B138: jr          $ra
    // 0x8023B13C: nop

    return;
    // 0x8023B13C: nop

;}
RECOMP_FUNC void M10_FUN_8023b140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B140: jr          $ra
    // 0x8023B144: nop

    return;
    // 0x8023B144: nop

;}
RECOMP_FUNC void M10_FUN_8023b148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B148: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8023B14C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8023B150: andi        $fp, $a1, 0xFF
    ctx->r30 = ctx->r5 & 0XFF;
    // 0x8023B154: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023B158: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023B15C: addiu       $v0, $fp, -0x96
    ctx->r2 = ADD32(ctx->r30, -0X96);
    // 0x8023B160: lw          $t6, -0x1A54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1A54);
    // 0x8023B164: lw          $t7, -0x1A50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1A50);
    // 0x8023B168: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8023B16C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8023B170: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8023B174: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8023B178: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8023B17C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8023B180: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8023B184: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8023B188: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8023B18C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8023B190: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8023B194: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8023B198: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8023B19C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8023B1A0: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8023B1A4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8023B1A8: bgez        $t9, L_8023B1B4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8023B1AC: sw          $t7, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r15;
            goto L_8023B1B4;
    }
    // 0x8023B1AC: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x8023B1B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8023B1B4:
    // 0x8023B1B4: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x8023B1B8: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x8023B1BC: addiu       $s1, $s1, 0x880
    ctx->r17 = ADD32(ctx->r17, 0X880);
    // 0x8023B1C0: addiu       $s5, $s5, 0x6D0
    ctx->r21 = ADD32(ctx->r21, 0X6D0);
    // 0x8023B1C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023B1C8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8023B1CC: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8023B1D0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x8023B1D4: lbu         $t0, 0x20($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X20);
L_8023B1D8:
    // 0x8023B1D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8023B1DC: bnel        $s4, $t0, L_8023B200
    if (ctx->r20 != ctx->r8) {
        // 0x8023B1E0: lbu         $t1, 0x20($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X20);
            goto L_8023B200;
    }
    goto skip_0;
    // 0x8023B1E0: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
    skip_0:
    // 0x8023B1E4: jal         0x8023A51C
    // 0x8023B1E8: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x8023A51C)(rdram, ctx);
        goto after_0;
    // 0x8023B1E8: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_0:
    // 0x8023B1EC: bnel        $v0, $zero, L_8023B200
    if (ctx->r2 != 0) {
        // 0x8023B1F0: lbu         $t1, 0x20($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X20);
            goto L_8023B200;
    }
    goto skip_1;
    // 0x8023B1F0: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
    skip_1:
    // 0x8023B1F4: b           L_8023B250
    // 0x8023B1F8: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
        goto L_8023B250;
    // 0x8023B1F8: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8023B1FC: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
L_8023B200:
    // 0x8023B200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8023B204: bnel        $s6, $t1, L_8023B228
    if (ctx->r22 != ctx->r9) {
        // 0x8023B208: lbu         $t2, 0x20($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X20);
            goto L_8023B228;
    }
    goto skip_2;
    // 0x8023B208: lbu         $t2, 0x20($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X20);
    skip_2:
    // 0x8023B20C: jal         0x8023A4AC
    // 0x8023B210: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x8023A4AC)(rdram, ctx);
        goto after_1;
    // 0x8023B210: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_1:
    // 0x8023B214: bnel        $v0, $zero, L_8023B228
    if (ctx->r2 != 0) {
        // 0x8023B218: lbu         $t2, 0x20($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X20);
            goto L_8023B228;
    }
    goto skip_3;
    // 0x8023B218: lbu         $t2, 0x20($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X20);
    skip_3:
    // 0x8023B21C: b           L_8023B250
    // 0x8023B220: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
        goto L_8023B250;
    // 0x8023B220: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8023B224: lbu         $t2, 0x20($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X20);
L_8023B228:
    // 0x8023B228: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8023B22C: bnel        $s7, $t2, L_8023B250
    if (ctx->r23 != ctx->r10) {
        // 0x8023B230: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_8023B250;
    }
    goto skip_4;
    // 0x8023B230: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    skip_4:
    // 0x8023B234: jal         0x8023A424
    // 0x8023B238: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x8023A424)(rdram, ctx);
        goto after_2;
    // 0x8023B238: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_2:
    // 0x8023B23C: bnel        $v0, $zero, L_8023B250
    if (ctx->r2 != 0) {
        // 0x8023B240: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_8023B250;
    }
    goto skip_5;
    // 0x8023B240: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    skip_5:
    // 0x8023B244: b           L_8023B250
    // 0x8023B248: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
        goto L_8023B250;
    // 0x8023B248: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8023B24C: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_8023B250:
    // 0x8023B250: addu        $t3, $sp, $s0
    ctx->r11 = ADD32(ctx->r29, ctx->r16);
    // 0x8023B254: lb          $t3, 0x5C($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X5C);
    // 0x8023B258: lh          $t4, 0x14($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X14);
    // 0x8023B25C: addu        $t5, $sp, $s0
    ctx->r13 = ADD32(ctx->r29, ctx->r16);
    // 0x8023B260: lb          $t5, 0x58($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X58);
    // 0x8023B264: lh          $t6, 0x16($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X16);
    // 0x8023B268: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8023B26C: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8023B270: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8023B274: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8023B278: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x8023B27C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8023B280: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8023B284: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8023B288: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8023B28C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8023B290: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8023B294: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8023B298: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8023B29C: jal         0x8001B204
    // 0x8023B2A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x8023B2A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x8023B2A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8023B2A8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023B2AC: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8023B2B0: bnel        $at, $zero, L_8023B1D8
    if (ctx->r1 != 0) {
        // 0x8023B2B4: lbu         $t0, 0x20($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X20);
            goto L_8023B1D8;
    }
    goto skip_6;
    // 0x8023B2B4: lbu         $t0, 0x20($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X20);
    skip_6:
    // 0x8023B2B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8023B2BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8023B2C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8023B2C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8023B2C8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8023B2CC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8023B2D0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8023B2D4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8023B2D8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8023B2DC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8023B2E0: jr          $ra
    // 0x8023B2E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8023B2E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b2e8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b2e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B2E8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B2EC: addiu       $a1, $a1, 0x880
    ctx->r5 = ADD32(ctx->r5, 0X880);
    // 0x8023B2F0: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8023B2F4: lbu         $t8, 0x20($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b2f8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b2f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B2F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023B2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023B300: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8023B304: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8023B308: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8023B30C: sb          $t9, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r25;
    // 0x8023B310: jal         0x80147D60
    // 0x8023B314: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_0;
    // 0x8023B314: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8023B318: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B31C: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023B320: addiu       $a1, $a1, 0x880
    ctx->r5 = ADD32(ctx->r5, 0X880);
    // 0x8023B324: addiu       $v1, $v1, 0x6D8
    ctx->r3 = ADD32(ctx->r3, 0X6D8);
    // 0x8023B328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023B32C:
    // 0x8023B32C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8023B330: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8023B334: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8023B338: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8023B33C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8023B340: bne         $at, $zero, L_8023B32C
    if (ctx->r1 != 0) {
        // 0x8023B344: sw          $v1, 0x24($t1)
        MEM_W(0X24, ctx->r9) = ctx->r3;
            goto L_8023B32C;
    }
    // 0x8023B344: sw          $v1, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r3;
    // 0x8023B348: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x8023B34C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8023B350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023B354: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8023B358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8023B35C: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
L_8023B360:
    // 0x8023B360: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x8023B364: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x8023B368: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8023B36C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8023B370: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8023B374: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8023B378: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8023B37C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8023B380: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8023B384: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x8023B388: lbu         $t3, 0x22($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X22);
    // 0x8023B38C: lbu         $a0, 0x20($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X20);
    // 0x8023B390: bnel        $t3, $a0, L_8023B3B4
    if (ctx->r11 != ctx->r4) {
        // 0x8023B394: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8023B3B4;
    }
    goto skip_0;
    // 0x8023B394: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_0:
    // 0x8023B398: lbu         $t2, 0x23($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X23);
    // 0x8023B39C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8023B3A0: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x8023B3A4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8023B3A8: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8023B3AC: beq         $at, $zero, L_8023B3BC
    if (ctx->r1 == 0) {
        // 0x8023B3B0: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8023B3BC;
    }
    // 0x8023B3B0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_8023B3B4:
    // 0x8023B3B4: bne         $at, $zero, L_8023B360
    if (ctx->r1 != 0) {
        // 0x8023B3B8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8023B360;
    }
    // 0x8023B3B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8023B3BC:
    // 0x8023B3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023B3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023B3C4: jr          $ra
    // 0x8023B3C8: nop

    return;
    // 0x8023B3C8: nop

;}
RECOMP_FUNC void M10_FUN_8023b3cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B3CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8023B3D0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8023B3D4: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x8023B3D8: addiu       $s1, $s1, 0x880
    ctx->r17 = ADD32(ctx->r17, 0X880);
    // 0x8023B3DC: lbu         $v1, 0x20($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X20);
    // 0x8023B3E0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8023B3E4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8023B3E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8023B3EC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8023B3F0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8023B3F4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8023B3F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8023B3FC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8023B400: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x8023B404: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x8023B408: andi        $s4, $a0, 0xFF
    ctx->r20 = ctx->r4 & 0XFF;
    // 0x8023B40C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8023B410: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8023B414: addiu       $s6, $s6, 0x6E4
    ctx->r22 = ADD32(ctx->r22, 0X6E4);
    // 0x8023B418: addiu       $s5, $s5, 0x6DC
    ctx->r21 = ADD32(ctx->r21, 0X6DC);
    // 0x8023B41C: addu        $s3, $s1, $v1
    ctx->r19 = ADD32(ctx->r17, ctx->r3);
    // 0x8023B420: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023B424: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x8023B428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8023B42C:
    // 0x8023B42C: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x8023B430: lbu         $t7, 0x38($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X38);
    // 0x8023B434: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8023B438: beq         $t7, $zero, L_8023B484
    if (ctx->r15 == 0) {
        // 0x8023B43C: nop
    
            goto L_8023B484;
    }
    // 0x8023B43C: nop

    // 0x8023B440: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023B444: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8023B448: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8023B44C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x8023B450: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8023B454: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8023B458: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8023B45C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8023B460: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8023B464: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8023B468: mflo        $a2
    ctx->r6 = lo;
    // 0x8023B46C: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8023B470: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8023B474: jal         0x8001B204
    // 0x8023B478: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x8023B478: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_0:
    // 0x8023B47C: b           L_8023B4C4
    // 0x8023B480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8023B4C4;
    // 0x8023B480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8023B484:
    // 0x8023B484: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023B488: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8023B48C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8023B490: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8023B494: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8023B498: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8023B49C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8023B4A0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8023B4A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8023B4A8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8023B4AC: mflo        $a2
    ctx->r6 = lo;
    // 0x8023B4B0: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8023B4B4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8023B4B8: jal         0x8001B204
    // 0x8023B4BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x8023B4BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_1:
    // 0x8023B4C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8023B4C4:
    // 0x8023B4C4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023B4C8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8023B4CC: bne         $at, $zero, L_8023B42C
    if (ctx->r1 != 0) {
        // 0x8023B4D0: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8023B42C;
    }
    // 0x8023B4D0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8023B4D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8023B4D8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8023B4DC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8023B4E0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8023B4E4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8023B4E8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8023B4EC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8023B4F0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8023B4F4: jr          $ra
    // 0x8023B4F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8023B4F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b4fc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b4fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B4FC: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023B500: lbu         $v1, 0x8A0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X8A0);
    // 0x8023B504: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8023B508: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023B50C: bne         $v1, $zero, L_8023B528
    if (ctx->r3 != 0) {
        // 0x8023B510: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8023B528;
    }
    // 0x8023B510: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8023B514: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8023B518: bnel        $a0, $at, L_8023B52C
    if (ctx->r4 != ctx->r1) {
        // 0x8023B51C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8023B52C;
    }
    goto skip_0;
    // 0x8023B51C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x8023B520: jr          $ra
    // 0x8023B524: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x8023B524: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8023B528:
    // 0x8023B528: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8023B52C:
    // 0x8023B52C: beq         $v0, $at, L_8023B53C
    if (ctx->r2 == ctx->r1) {
        // 0x8023B530: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8023B53C;
    }
    // 0x8023B530: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023B534: bne         $v0, $at, L_8023B544
    if (ctx->r2 != ctx->r1) {
            // 0x8023B538: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    LOOKUP_FUNC(0x8023B544)(rdram, ctx);
    return;
    }
    // 0x8023B538: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8023B53C:
    // 0x8023B53C: jr          $ra
    // 0x8023B540: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x8023B540: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b544(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B544: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8023B548: jr          $ra
    // 0x8023B54C: nop

    return;
    // 0x8023B54C: nop

;}
RECOMP_FUNC void M10_FUN_8023b550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B550: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023B554: lbu         $v1, 0x8A0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X8A0);
    // 0x8023B558: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023B55C: bnel        $v1, $at, L_8023B570
    if (ctx->r3 != ctx->r1) {
        // 0x8023B560: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8023B570;
    }
    goto skip_0;
    // 0x8023B560: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8023B564: jr          $ra
    // 0x8023B568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8023B568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023B56C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_8023B570:
    // 0x8023B570: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8023B574: jr          $ra
    // 0x8023B578: nop

    return;
    // 0x8023B578: nop

;}
RECOMP_FUNC void M10_FUN_8023b57c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B57C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8023B580: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023B584: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8023B588: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023B58C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8023B590: lw          $t7, 0x8A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X8A0);
    // 0x8023B594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8023B598: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8023B59C: bne         $t8, $zero, L_8023B5AC
    if (ctx->r24 != 0) {
            // 0x8023B5A0: nop

    LOOKUP_FUNC(0x8023B5AC)(rdram, ctx);
    return;
    }
    // 0x8023B5A0: nop

    // 0x8023B5A4: jr          $ra
    // 0x8023B5A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8023B5A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b5ac(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b5ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B5AC: jr          $ra
    // 0x8023B5B0: nop

    return;
    // 0x8023B5B0: nop

;}
RECOMP_FUNC void M10_FUN_8023b5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B5B4: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023B5B8: addiu       $v1, $v1, 0x880
    ctx->r3 = ADD32(ctx->r3, 0X880);
    // 0x8023B5BC: lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X20);
    // 0x8023B5C0: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8023B5C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8023B5C8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8023B5CC: jr          $ra
    // 0x8023B5D0: sb          $t6, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r14;
    return;
    // 0x8023B5D0: sb          $t6, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b5d4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b5d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B5D4: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023B5D8: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023B5DC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b5e0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b5e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023B5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023B5E8: beq         $a0, $zero, L_8023B5F8
    if (ctx->r4 == 0) {
        // 0x8023B5EC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8023B5F8;
    }
    // 0x8023B5EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8023B5F0: jal         0x80145310
    // 0x8023B5F4: lbu         $a1, 0x18($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X18);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x8023B5F4: lbu         $a1, 0x18($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X18);
    after_0:
L_8023B5F8:
    // 0x8023B5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023B5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023B600: jr          $ra
    // 0x8023B604: nop

    return;
    // 0x8023B604: nop

;}
RECOMP_FUNC void M10_FUN_8023b608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8023B60C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8023B610: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x8023B614: addiu       $s2, $s2, 0x880
    ctx->r18 = ADD32(ctx->r18, 0X880);
    // 0x8023B618: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8023B61C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x8023B620: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8023B624: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8023B628: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8023B62C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8023B630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8023B634: sb          $t7, 0x6A($s2)
    MEM_B(0X6A, ctx->r18) = ctx->r15;
    // 0x8023B638: sb          $t6, 0x6B($s2)
    MEM_B(0X6B, ctx->r18) = ctx->r14;
    // 0x8023B63C: sw          $a1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r5;
    // 0x8023B640: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8023B644: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8023B648: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
    // 0x8023B64C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    // 0x8023B650: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8023B654: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023B658: sb          $t8, 0x23($s2)
    MEM_B(0X23, ctx->r18) = ctx->r24;
    // 0x8023B65C: bgez        $t9, L_8023B66C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8023B660: sra         $t0, $t9, 2
        ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
            goto L_8023B66C;
    }
    // 0x8023B660: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8023B664: addiu       $at, $t9, 0x3
    ctx->r1 = ADD32(ctx->r25, 0X3);
    // 0x8023B668: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
L_8023B66C:
    // 0x8023B66C: blez        $v0, L_8023B6BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8023B670: sb          $t0, 0x22($s2)
        MEM_B(0X22, ctx->r18) = ctx->r8;
            goto L_8023B6BC;
    }
    // 0x8023B670: sb          $t0, 0x22($s2)
    MEM_B(0X22, ctx->r18) = ctx->r8;
    // 0x8023B674: addiu       $s3, $a1, 0x4
    ctx->r19 = ADD32(ctx->r5, 0X4);
    // 0x8023B678: sll         $t1, $s0, 3
    ctx->r9 = S32(ctx->r16 << 3);
L_8023B67C:
    // 0x8023B67C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8023B680: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8023B684: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x8023B688: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8023B68C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8023B690: jal         0x8023A398
    // 0x8023B694: sb          $t3, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r11;
    LOOKUP_FUNC(0x8023A398)(rdram, ctx);
        goto after_0;
    // 0x8023B694: sb          $t3, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r11;
    after_0:
    // 0x8023B698: jal         0x8024402C
    // 0x8023B69C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8024402C)(rdram, ctx);
        goto after_1;
    // 0x8023B69C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_1:
    // 0x8023B6A0: sb          $v0, 0x51($s1)
    MEM_B(0X51, ctx->r17) = ctx->r2;
    // 0x8023B6A4: lbu         $t4, 0x23($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X23);
    // 0x8023B6A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8023B6AC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023B6B0: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8023B6B4: bnel        $at, $zero, L_8023B67C
    if (ctx->r1 != 0) {
        // 0x8023B6B8: sll         $t1, $s0, 3
        ctx->r9 = S32(ctx->r16 << 3);
            goto L_8023B67C;
    }
    goto skip_0;
    // 0x8023B6B8: sll         $t1, $s0, 3
    ctx->r9 = S32(ctx->r16 << 3);
    skip_0:
L_8023B6BC:
    // 0x8023B6BC: jal         0x8023AB40
    // 0x8023B6C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8023AB40)(rdram, ctx);
        goto after_2;
    // 0x8023B6C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8023B6C4: jal         0x8023AB94
    // 0x8023B6C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8023AB94)(rdram, ctx);
        goto after_3;
    // 0x8023B6C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x8023B6CC: jal         0x8023AC94
    // 0x8023B6D0: nop

    LOOKUP_FUNC(0x8023AC94)(rdram, ctx);
        goto after_4;
    // 0x8023B6D0: nop

    after_4:
    // 0x8023B6D4: jal         0x8023B2E8
    // 0x8023B6D8: nop

    LOOKUP_FUNC(0x8023B2E8)(rdram, ctx);
        goto after_5;
    // 0x8023B6D8: nop

    after_5:
    // 0x8023B6DC: jal         0x8023A790
    // 0x8023B6E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8023A790)(rdram, ctx);
        goto after_6;
    // 0x8023B6E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x8023B6E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8023B6E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8023B6EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8023B6F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8023B6F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8023B6F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8023B6FC: jr          $ra
    // 0x8023B700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8023B700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b704(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B704: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8023B708: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8023B70C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8023B710: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8023B714: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8023B718: jal         0x8023A2BC
    // 0x8023B71C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8023A2BC)(rdram, ctx);
        goto after_0;
    // 0x8023B71C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8023B720: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8023B724: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8023B728: lbu         $t6, 0x1030($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1030);
    // 0x8023B72C: bnel        $t6, $zero, L_8023B740
    if (ctx->r14 != 0) {
        // 0x8023B730: lw          $a0, 0xEC($v0)
        ctx->r4 = MEM_W(ctx->r2, 0XEC);
            goto L_8023B740;
    }
    goto skip_0;
    // 0x8023B730: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    skip_0:
    // 0x8023B734: b           L_8023B740
    // 0x8023B738: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
        goto L_8023B740;
    // 0x8023B738: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    // 0x8023B73C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
L_8023B740:
    // 0x8023B740: jal         0x802242D0
    // 0x8023B744: nop

    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_1;
    // 0x8023B744: nop

    after_1:
    // 0x8023B748: jal         0x80236C9C
    // 0x8023B74C: sb          $v0, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r2;
    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_2;
    // 0x8023B74C: sb          $v0, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r2;
    after_2:
    // 0x8023B750: bne         $v0, $zero, L_8023B7EC
    if (ctx->r2 != 0) {
        // 0x8023B754: lui         $s0, 0x8024
        ctx->r16 = S32(0X8024 << 16);
            goto L_8023B7EC;
    }
    // 0x8023B754: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023B758: jal         0x80006214
    // 0x8023B75C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x8023B75C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8023B760: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023B764: addiu       $s0, $s0, 0x880
    ctx->r16 = ADD32(ctx->r16, 0X880);
    // 0x8023B768: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x8023B76C: lbu         $t2, 0x1A($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1A);
    // 0x8023B770: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8023B774: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8023B778: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8023B77C: addiu       $t1, $zero, 0x20C
    ctx->r9 = ADD32(0, 0X20C);
    // 0x8023B780: sb          $v0, 0x4E($sp)
    MEM_B(0X4E, ctx->r29) = ctx->r2;
    // 0x8023B784: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8023B788: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8023B78C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023B790: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023B794: lh          $a3, 0x10($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X10);
    // 0x8023B798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023B79C: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8023B7A0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8023B7A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023B7A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8023B7AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8023B7B0: jal         0x80146208
    // 0x8023B7B4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x8023B7B4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8023B7B8: lbu         $t4, 0x4E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4E);
    // 0x8023B7BC: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8023B7C0: lbu         $a1, 0x19($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X19);
    // 0x8023B7C4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8023B7C8: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x8023B7CC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8023B7D0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8023B7D4: jal         0x80145310
    // 0x8023B7D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_5;
    // 0x8023B7D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8023B7DC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8023B7E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8023B7E4: b           L_8023B7F4
    // 0x8023B7E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
        goto L_8023B7F4;
    // 0x8023B7E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_8023B7EC:
    // 0x8023B7EC: addiu       $s0, $s0, 0x880
    ctx->r16 = ADD32(ctx->r16, 0X880);
    // 0x8023B7F0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8023B7F4:
    // 0x8023B7F4: jal         0x80236374
    // 0x8023B7F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80236374)(rdram, ctx);
        goto after_6;
    // 0x8023B7F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8023B7FC: beq         $v0, $zero, L_8023B82C
    if (ctx->r2 == 0) {
        // 0x8023B800: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8023B82C;
    }
    // 0x8023B800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023B804: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8023B808: addiu       $a1, $a1, -0x3140
    ctx->r5 = ADD32(ctx->r5, -0X3140);
    // 0x8023B80C: jal         0x8023B608
    // 0x8023B810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8023B608)(rdram, ctx);
        goto after_7;
    // 0x8023B810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8023B814: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B818: addiu       $a1, $a1, -0x4284
    ctx->r5 = ADD32(ctx->r5, -0X4284);
    // 0x8023B81C: jal         0x800058DC
    // 0x8023B820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8023B820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8023B824: b           L_8023B85C
    // 0x8023B828: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8023B85C;
    // 0x8023B828: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8023B82C:
    // 0x8023B82C: jal         0x8023A5D4
    // 0x8023B830: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    LOOKUP_FUNC(0x8023A5D4)(rdram, ctx);
        goto after_9;
    // 0x8023B830: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    after_9:
    // 0x8023B834: jal         0x8023AFD0
    // 0x8023B838: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    LOOKUP_FUNC(0x8023AFD0)(rdram, ctx);
        goto after_10;
    // 0x8023B838: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    after_10:
    // 0x8023B83C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8023B840: jal         0x8023B148
    // 0x8023B844: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8023B148)(rdram, ctx);
        goto after_11;
    // 0x8023B844: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_11:
    // 0x8023B848: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B84C: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8023B850: jal         0x800058DC
    // 0x8023B854: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8023B854: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8023B858: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8023B85C:
    // 0x8023B85C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8023B860: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8023B864: jr          $ra
    // 0x8023B868: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8023B868: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023b86c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023b86c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023B86C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023B870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8023B874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8023B878: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023B87C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x8023B880: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8023B884: jal         0x8023ADBC
    // 0x8023B888: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8023ADBC)(rdram, ctx);
        goto after_0;
    // 0x8023B888: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8023B88C: jal         0x8023AD74
    // 0x8023B890: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8023AD74)(rdram, ctx);
        goto after_1;
    // 0x8023B890: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
    after_1:
    // 0x8023B894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023B898: jal         0x8023B148
    // 0x8023B89C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8023B148)(rdram, ctx);
        goto after_2;
    // 0x8023B89C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x8023B8A0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8023B8A4: jal         0x80147148
    // 0x8023B8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_3;
    // 0x8023B8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8023B8AC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8023B8B0: beql        $a0, $zero, L_8023B9F8
    if (ctx->r4 == 0) {
        // 0x8023B8B4: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8023B9F8;
    }
    goto skip_0;
    // 0x8023B8B4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8023B8B8: jal         0x8023B57C
    // 0x8023B8BC: nop

    LOOKUP_FUNC(0x8023B57C)(rdram, ctx);
        goto after_4;
    // 0x8023B8BC: nop

    after_4:
    // 0x8023B8C0: beql        $v0, $zero, L_8023B9F8
    if (ctx->r2 == 0) {
        // 0x8023B8C4: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8023B9F8;
    }
    goto skip_1;
    // 0x8023B8C4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8023B8C8: jal         0x80020744
    // 0x8023B8CC: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_5;
    // 0x8023B8CC: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_5:
    // 0x8023B8D0: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023B8D4: lbu         $t7, 0x8A0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X8A0);
    // 0x8023B8D8: bne         $t7, $zero, L_8023B9C4
    if (ctx->r15 != 0) {
        // 0x8023B8DC: nop
    
            goto L_8023B9C4;
    }
    // 0x8023B8DC: nop

    // 0x8023B8E0: jal         0x8023639C
    // 0x8023B8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023639C)(rdram, ctx);
        goto after_6;
    // 0x8023B8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8023B8E8: beq         $v0, $zero, L_8023B970
    if (ctx->r2 == 0) {
        // 0x8023B8EC: lbu         $t8, 0x23($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X23);
            goto L_8023B970;
    }
    // 0x8023B8EC: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x8023B8F0: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8023B8F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8023B8F8: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023B8FC: bnel        $v0, $at, L_8023B938
    if (ctx->r2 != ctx->r1) {
        // 0x8023B900: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8023B938;
    }
    goto skip_2;
    // 0x8023B900: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x8023B904: jal         0x801471DC
    // 0x8023B908: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_7;
    // 0x8023B908: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    after_7:
    // 0x8023B90C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8023B910: addiu       $a1, $a1, -0x3140
    ctx->r5 = ADD32(ctx->r5, -0X3140);
    // 0x8023B914: jal         0x8023B608
    // 0x8023B918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023B608)(rdram, ctx);
        goto after_8;
    // 0x8023B918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8023B91C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B920: addiu       $a1, $a1, -0x4284
    ctx->r5 = ADD32(ctx->r5, -0X4284);
    // 0x8023B924: jal         0x800058DC
    // 0x8023B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x8023B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8023B92C: b           L_8023BA54
    // 0x8023B930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BA54;
    // 0x8023B930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8023B934: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8023B938:
    // 0x8023B938: bne         $v0, $at, L_8023B970
    if (ctx->r2 != ctx->r1) {
        // 0x8023B93C: lui         $a0, 0x8024
        ctx->r4 = S32(0X8024 << 16);
            goto L_8023B970;
    }
    // 0x8023B93C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023B940: jal         0x801471DC
    // 0x8023B944: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_10;
    // 0x8023B944: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    after_10:
    // 0x8023B948: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8023B94C: addiu       $a1, $a1, -0x31E8
    ctx->r5 = ADD32(ctx->r5, -0X31E8);
    // 0x8023B950: jal         0x8023B608
    // 0x8023B954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023B608)(rdram, ctx);
        goto after_11;
    // 0x8023B954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8023B958: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B95C: addiu       $a1, $a1, -0x4284
    ctx->r5 = ADD32(ctx->r5, -0X4284);
    // 0x8023B960: jal         0x800058DC
    // 0x8023B964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8023B964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8023B968: b           L_8023BA54
    // 0x8023B96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BA54;
    // 0x8023B96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023B970:
    // 0x8023B970: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023B974: bne         $t8, $at, L_8023B9C4
    if (ctx->r24 != ctx->r1) {
        // 0x8023B978: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8023B9C4;
    }
    // 0x8023B978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8023B97C: jal         0x80147148
    // 0x8023B980: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_13;
    // 0x8023B980: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_13:
    // 0x8023B984: jal         0x80147D60
    // 0x8023B988: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_14;
    // 0x8023B988: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_14:
    // 0x8023B98C: jal         0x80236BC8
    // 0x8023B990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80236BC8)(rdram, ctx);
        goto after_15;
    // 0x8023B990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8023B994: jal         0x80236A3C
    // 0x8023B998: nop

    LOOKUP_FUNC(0x80236A3C)(rdram, ctx);
        goto after_16;
    // 0x8023B998: nop

    after_16:
    // 0x8023B99C: jal         0x80236BD8
    // 0x8023B9A0: nop

    LOOKUP_FUNC(0x80236BD8)(rdram, ctx);
        goto after_17;
    // 0x8023B9A0: nop

    after_17:
    // 0x8023B9A4: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x8023B9A8: addiu       $a1, $a1, 0x7630
    ctx->r5 = ADD32(ctx->r5, 0X7630);
    // 0x8023B9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023B9B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8023B9B4: jal         0x80148FC4
    // 0x8023B9B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_18;
    // 0x8023B9B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8023B9BC: b           L_8023BA54
    // 0x8023B9C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BA54;
    // 0x8023B9C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023B9C4:
    // 0x8023B9C4: jal         0x8023B5B4
    // 0x8023B9C8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x8023B5B4)(rdram, ctx);
        goto after_19;
    // 0x8023B9C8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_19:
    // 0x8023B9CC: jal         0x8023B4FC
    // 0x8023B9D0: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x8023B4FC)(rdram, ctx);
        goto after_20;
    // 0x8023B9D0: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_20:
    // 0x8023B9D4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023B9D8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023B9DC: sb          $v0, 0x8A1($at)
    MEM_B(0X8A1, ctx->r1) = ctx->r2;
    // 0x8023B9E0: addiu       $a1, $a1, -0x459C
    ctx->r5 = ADD32(ctx->r5, -0X459C);
    // 0x8023B9E4: jal         0x800058DC
    // 0x8023B9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_21;
    // 0x8023B9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8023B9EC: b           L_8023BA54
    // 0x8023B9F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BA54;
    // 0x8023B9F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8023B9F4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_8023B9F8:
    // 0x8023B9F8: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x8023B9FC: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x8023BA00: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8023BA04: beql        $t1, $zero, L_8023BA54
    if (ctx->r9 == 0) {
        // 0x8023BA08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8023BA54;
    }
    goto skip_3;
    // 0x8023BA08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8023BA0C: lbu         $t2, 0x8A0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X8A0);
    // 0x8023BA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023BA14: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BA18: bne         $t2, $zero, L_8023BA30
    if (ctx->r10 != 0) {
        // 0x8023BA1C: nop
    
            goto L_8023BA30;
    }
    // 0x8023BA1C: nop

    // 0x8023BA20: jal         0x800058DC
    // 0x8023BA24: addiu       $a1, $a1, -0x4424
    ctx->r5 = ADD32(ctx->r5, -0X4424);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_22;
    // 0x8023BA24: addiu       $a1, $a1, -0x4424
    ctx->r5 = ADD32(ctx->r5, -0X4424);
    after_22:
    // 0x8023BA28: b           L_8023BA54
    // 0x8023BA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BA54;
    // 0x8023BA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023BA30:
    // 0x8023BA30: jal         0x8023B550
    // 0x8023BA34: nop

    LOOKUP_FUNC(0x8023B550)(rdram, ctx);
        goto after_23;
    // 0x8023BA34: nop

    after_23:
    // 0x8023BA38: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023BA3C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BA40: sb          $v0, 0x8A1($at)
    MEM_B(0X8A1, ctx->r1) = ctx->r2;
    // 0x8023BA44: addiu       $a1, $a1, -0x459C
    ctx->r5 = ADD32(ctx->r5, -0X459C);
    // 0x8023BA48: jal         0x800058DC
    // 0x8023BA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_24;
    // 0x8023BA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8023BA50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023BA54:
    // 0x8023BA54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8023BA58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023BA5C: jr          $ra
    // 0x8023BA60: nop

    return;
    // 0x8023BA60: nop

;}
RECOMP_FUNC void M10_FUN_8023ba64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BA64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023BA68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8023BA6C: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023BA70: lh          $s0, -0x1A4C($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X1A4C);
    // 0x8023BA74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8023BA78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8023BA7C: slti        $at, $s0, 0x79
    ctx->r1 = SIGNED(ctx->r16) < 0X79 ? 1 : 0;
    // 0x8023BA80: bne         $at, $zero, L_8023BA98
    if (ctx->r1 != 0) {
        // 0x8023BA84: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8023BA98;
    }
    // 0x8023BA84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023BA88: jal         0x8023B5D4
    // 0x8023BA8C: nop

    LOOKUP_FUNC(0x8023B5D4)(rdram, ctx);
        goto after_0;
    // 0x8023BA8C: nop

    after_0:
    // 0x8023BA90: b           L_8023BAA0
    // 0x8023BA94: nop

        goto L_8023BAA0;
    // 0x8023BA94: nop

L_8023BA98:
    // 0x8023BA98: jal         0x8023AD74
    // 0x8023BA9C: nop

    LOOKUP_FUNC(0x8023AD74)(rdram, ctx);
        goto after_1;
    // 0x8023BA9C: nop

    after_1:
L_8023BAA0:
    // 0x8023BAA0: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023BAA4: lh          $s0, -0x1A4C($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X1A4C);
    // 0x8023BAA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BAAC: jal         0x8023B148
    // 0x8023BAB0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x8023B148)(rdram, ctx);
        goto after_2;
    // 0x8023BAB0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_2:
    // 0x8023BAB4: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023BAB8: lh          $s0, -0x1A4C($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X1A4C);
    // 0x8023BABC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8023BAC0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023BAC4: addiu       $s0, $s0, -0x18
    ctx->r16 = ADD32(ctx->r16, -0X18);
    // 0x8023BAC8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8023BACC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8023BAD0: blezl       $s0, L_8023BAE8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8023BAD4: addiu       $s0, $zero, 0xF0
        ctx->r16 = ADD32(0, 0XF0);
            goto L_8023BAE8;
    }
    goto skip_0;
    // 0x8023BAD4: addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
    skip_0:
    // 0x8023BAD8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023BADC: b           L_8023BBC8
    // 0x8023BAE0: sh          $s0, -0x1A4C($at)
    MEM_H(-0X1A4C, ctx->r1) = ctx->r16;
        goto L_8023BBC8;
    // 0x8023BAE0: sh          $s0, -0x1A4C($at)
    MEM_H(-0X1A4C, ctx->r1) = ctx->r16;
    // 0x8023BAE4: addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
L_8023BAE8:
    // 0x8023BAE8: jal         0x80147D60
    // 0x8023BAEC: sh          $s0, -0x1A4C($at)
    MEM_H(-0X1A4C, ctx->r1) = ctx->r16;
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_3;
    // 0x8023BAEC: sh          $s0, -0x1A4C($at)
    MEM_H(-0X1A4C, ctx->r1) = ctx->r16;
    after_3:
    // 0x8023BAF0: lui         $s0, 0x8024
    ctx->r16 = S32(0X8024 << 16);
    // 0x8023BAF4: addiu       $s0, $s0, 0x880
    ctx->r16 = ADD32(ctx->r16, 0X880);
    // 0x8023BAF8: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x8023BAFC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8023BB00: bnel        $v0, $at, L_8023BB88
    if (ctx->r2 != ctx->r1) {
        // 0x8023BB04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8023BB88;
    }
    goto skip_1;
    // 0x8023BB04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8023BB08: lbu         $t6, 0x20($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20);
    // 0x8023BB0C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8023BB10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BB14: bne         $t6, $at, L_8023BB50
    if (ctx->r14 != ctx->r1) {
        // 0x8023BB18: nop
    
            goto L_8023BB50;
    }
    // 0x8023BB18: nop

    // 0x8023BB1C: jal         0x8023A4AC
    // 0x8023BB20: lbu         $a1, 0x1F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1F);
    LOOKUP_FUNC(0x8023A4AC)(rdram, ctx);
        goto after_4;
    // 0x8023BB20: lbu         $a1, 0x1F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1F);
    after_4:
    // 0x8023BB24: beq         $v0, $zero, L_8023BB40
    if (ctx->r2 == 0) {
        // 0x8023BB28: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8023BB40;
    }
    // 0x8023BB28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BB2C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BB30: jal         0x800058DC
    // 0x8023BB34: addiu       $a1, $a1, -0x3FE0
    ctx->r5 = ADD32(ctx->r5, -0X3FE0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8023BB34: addiu       $a1, $a1, -0x3FE0
    ctx->r5 = ADD32(ctx->r5, -0X3FE0);
    after_5:
    // 0x8023BB38: b           L_8023BBCC
    // 0x8023BB3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BBCC;
    // 0x8023BB3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023BB40:
    // 0x8023BB40: jal         0x8023A234
    // 0x8023BB44: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    LOOKUP_FUNC(0x8023A234)(rdram, ctx);
        goto after_6;
    // 0x8023BB44: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    after_6:
    // 0x8023BB48: b           L_8023BBA8
    // 0x8023BB4C: nop

        goto L_8023BBA8;
    // 0x8023BB4C: nop

L_8023BB50:
    // 0x8023BB50: jal         0x8023A5A4
    // 0x8023BB54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8023A5A4)(rdram, ctx);
        goto after_7;
    // 0x8023BB54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8023BB58: beq         $v0, $zero, L_8023BB74
    if (ctx->r2 == 0) {
        // 0x8023BB5C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8023BB74;
    }
    // 0x8023BB5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BB60: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BB64: jal         0x800058DC
    // 0x8023BB68: addiu       $a1, $a1, -0x40F0
    ctx->r5 = ADD32(ctx->r5, -0X40F0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8023BB68: addiu       $a1, $a1, -0x40F0
    ctx->r5 = ADD32(ctx->r5, -0X40F0);
    after_8:
    // 0x8023BB6C: b           L_8023BBCC
    // 0x8023BB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8023BBCC;
    // 0x8023BB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023BB74:
    // 0x8023BB74: jal         0x8023A234
    // 0x8023BB78: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    LOOKUP_FUNC(0x8023A234)(rdram, ctx);
        goto after_9;
    // 0x8023BB78: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    after_9:
    // 0x8023BB7C: b           L_8023BBA8
    // 0x8023BB80: nop

        goto L_8023BBA8;
    // 0x8023BB80: nop

    // 0x8023BB84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8023BB88:
    // 0x8023BB88: bne         $v0, $at, L_8023BBA8
    if (ctx->r2 != ctx->r1) {
        // 0x8023BB8C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8023BBA8;
    }
    // 0x8023BB8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BB90: jal         0x8023A424
    // 0x8023BB94: lbu         $a1, 0x1C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C);
    LOOKUP_FUNC(0x8023A424)(rdram, ctx);
        goto after_10;
    // 0x8023BB94: lbu         $a1, 0x1C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C);
    after_10:
    // 0x8023BB98: bne         $v0, $zero, L_8023BBA8
    if (ctx->r2 != 0) {
        // 0x8023BB9C: nop
    
            goto L_8023BBA8;
    }
    // 0x8023BB9C: nop

    // 0x8023BBA0: jal         0x8023A234
    // 0x8023BBA4: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    LOOKUP_FUNC(0x8023A234)(rdram, ctx);
        goto after_11;
    // 0x8023BBA4: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    after_11:
L_8023BBA8:
    // 0x8023BBA8: jal         0x8023AFD0
    // 0x8023BBAC: lbu         $a0, 0x21($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X21);
    LOOKUP_FUNC(0x8023AFD0)(rdram, ctx);
        goto after_12;
    // 0x8023BBAC: lbu         $a0, 0x21($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X21);
    after_12:
    // 0x8023BBB0: lbu         $t7, 0x21($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X21);
    // 0x8023BBB4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BBB8: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8023BBBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BBC0: jal         0x800058DC
    // 0x8023BBC4: sb          $t7, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x8023BBC4: sb          $t7, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r15;
    after_13:
L_8023BBC8:
    // 0x8023BBC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023BBCC:
    // 0x8023BBCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8023BBD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023BBD4: jr          $ra
    // 0x8023BBD8: nop

    return;
    // 0x8023BBD8: nop

;}
RECOMP_FUNC void M10_FUN_8023bbdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BBDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023BBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023BBE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023BBE8: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8023BBEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8023BBF0: lw          $v1, 0x98($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X98);
    // 0x8023BBF4: beq         $v0, $zero, L_8023BC08
    if (ctx->r2 == 0) {
        // 0x8023BBF8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8023BC08;
    }
    // 0x8023BBF8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8023BBFC: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x8023BC00: lbu         $a2, 0xB($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XB);
    // 0x8023BC04: sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
L_8023BC08:
    // 0x8023BC08: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8023BC0C: addiu       $a2, $a2, -0x19
    ctx->r6 = ADD32(ctx->r6, -0X19);
    // 0x8023BC10: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8023BC14: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8023BC18: blez        $a2, L_8023BC60
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8023BC1C: andi        $a1, $a2, 0xFF
        ctx->r5 = ctx->r6 & 0XFF;
            goto L_8023BC60;
    }
    // 0x8023BC1C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x8023BC20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8023BC24: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8023BC28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8023BC2C: jal         0x8023B148
    // 0x8023BC30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8023B148)(rdram, ctx);
        goto after_0;
    // 0x8023BC30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8023BC34: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8023BC38: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8023BC3C: beql        $v0, $zero, L_8023BC8C
    if (ctx->r2 == 0) {
        // 0x8023BC40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023BC8C;
    }
    goto skip_0;
    // 0x8023BC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8023BC44: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
L_8023BC48:
    // 0x8023BC48: sb          $v1, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r3;
    // 0x8023BC4C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8023BC50: bnel        $v0, $zero, L_8023BC48
    if (ctx->r2 != 0) {
        // 0x8023BC54: lw          $t7, 0x30($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X30);
            goto L_8023BC48;
    }
    goto skip_1;
    // 0x8023BC54: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    skip_1:
    // 0x8023BC58: b           L_8023BC8C
    // 0x8023BC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023BC8C;
    // 0x8023BC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BC60:
    // 0x8023BC60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8023BC64: jal         0x80147D60
    // 0x8023BC68: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_1;
    // 0x8023BC68: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8023BC6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8023BC70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8023BC74: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8023BC78: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BC7C: addiu       $a1, $a1, -0x5EAC
    ctx->r5 = ADD32(ctx->r5, -0X5EAC);
    // 0x8023BC80: jal         0x800058DC
    // 0x8023BC84: sh          $t8, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8023BC84: sh          $t8, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r24;
    after_2:
    // 0x8023BC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BC8C:
    // 0x8023BC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023BC90: jr          $ra
    // 0x8023BC94: nop

    return;
    // 0x8023BC94: nop

;}
RECOMP_FUNC void M10_FUN_8023bc98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BC98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8023BC9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023BCA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8023BCA4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8023BCA8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8023BCAC: lw          $a3, 0x98($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X98);
    // 0x8023BCB0: beq         $v0, $zero, L_8023BCC4
    if (ctx->r2 == 0) {
        // 0x8023BCB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8023BCC4;
    }
    // 0x8023BCB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8023BCB8: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x8023BCBC: lbu         $a1, 0xB($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0XB);
    // 0x8023BCC0: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
L_8023BCC4:
    // 0x8023BCC4: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x8023BCC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8023BCCC: addiu       $a1, $a1, -0x19
    ctx->r5 = ADD32(ctx->r5, -0X19);
    // 0x8023BCD0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8023BCD4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8023BCD8: blezl       $a1, L_8023BD48
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8023BCDC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8023BD48;
    }
    goto skip_0;
    // 0x8023BCDC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    skip_0:
    // 0x8023BCE0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8023BCE4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8023BCE8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8023BCEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8023BCF0: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
    // 0x8023BCF4: jal         0x8023A9D8
    // 0x8023BCF8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8023A9D8)(rdram, ctx);
        goto after_0;
    // 0x8023BCF8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8023BCFC: jal         0x8023B3CC
    // 0x8023BD00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8023B3CC)(rdram, ctx);
        goto after_1;
    // 0x8023BD00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8023BD04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8023BD08: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x8023BD0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8023BD10: beql        $v1, $zero, L_8023BD70
    if (ctx->r3 == 0) {
        // 0x8023BD14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023BD70;
    }
    goto skip_1;
    // 0x8023BD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8023BD18: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
L_8023BD1C:
    // 0x8023BD1C: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x8023BD20: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8023BD24: beql        $at, $zero, L_8023BD34
    if (ctx->r1 == 0) {
        // 0x8023BD28: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8023BD34;
    }
    goto skip_2;
    // 0x8023BD28: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x8023BD2C: sb          $a2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r6;
    // 0x8023BD30: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8023BD34:
    // 0x8023BD34: bnel        $v1, $zero, L_8023BD1C
    if (ctx->r3 != 0) {
        // 0x8023BD38: lw          $v0, 0x30($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X30);
            goto L_8023BD1C;
    }
    goto skip_3;
    // 0x8023BD38: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    skip_3:
    // 0x8023BD3C: b           L_8023BD70
    // 0x8023BD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023BD70;
    // 0x8023BD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023BD44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
L_8023BD48:
    // 0x8023BD48: jal         0x80147D60
    // 0x8023BD4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_2;
    // 0x8023BD4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8023BD50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8023BD54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8023BD58: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8023BD5C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BD60: addiu       $a1, $a1, -0x5EAC
    ctx->r5 = ADD32(ctx->r5, -0X5EAC);
    // 0x8023BD64: jal         0x800058DC
    // 0x8023BD68: sh          $t8, 0x44($a3)
    MEM_H(0X44, ctx->r7) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8023BD68: sh          $t8, 0x44($a3)
    MEM_H(0X44, ctx->r7) = ctx->r24;
    after_3:
    // 0x8023BD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BD70:
    // 0x8023BD70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8023BD74: jr          $ra
    // 0x8023BD78: nop

    return;
    // 0x8023BD78: nop

;}
RECOMP_FUNC void M10_FUN_8023bd7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023BD80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023BD84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8023BD88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023BD8C: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x8023BD90: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x8023BD94: jal         0x8023AD74
    // 0x8023BD98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8023AD74)(rdram, ctx);
        goto after_0;
    // 0x8023BD98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8023BD9C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8023BDA0: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023BDA4: lbu         $a1, 0x1B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1B);
    // 0x8023BDA8: lhu         $v1, 0xC($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0XC);
    // 0x8023BDAC: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023BDB0: andi        $t9, $v1, 0x200
    ctx->r25 = ctx->r3 & 0X200;
    // 0x8023BDB4: beq         $t9, $zero, L_8023BDD8
    if (ctx->r25 == 0) {
        // 0x8023BDB8: nop
    
            goto L_8023BDD8;
    }
    // 0x8023BDB8: nop

    // 0x8023BDBC: lbu         $v0, 0x20($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X20);
    // 0x8023BDC0: blez        $v0, L_8023BDD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8023BDC4: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8023BDD8;
    }
    // 0x8023BDC4: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8023BDC8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8023BDCC: sb          $t0, 0x20($a2)
    MEM_B(0X20, ctx->r6) = ctx->r8;
    // 0x8023BDD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8023BDD4: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
L_8023BDD8:
    // 0x8023BDD8: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023BDDC: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x8023BDE0: beq         $t2, $zero, L_8023BE08
    if (ctx->r10 == 0) {
        // 0x8023BDE4: addiu       $a2, $a2, 0x880
        ctx->r6 = ADD32(ctx->r6, 0X880);
            goto L_8023BE08;
    }
    // 0x8023BDE4: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023BDE8: lbu         $v0, 0x20($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X20);
    // 0x8023BDEC: lbu         $t3, 0x22($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X22);
    // 0x8023BDF0: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8023BDF4: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8023BDF8: beq         $at, $zero, L_8023BE08
    if (ctx->r1 == 0) {
        // 0x8023BDFC: nop
    
            goto L_8023BE08;
    }
    // 0x8023BDFC: nop

    // 0x8023BE00: sb          $t4, 0x20($a2)
    MEM_B(0X20, ctx->r6) = ctx->r12;
    // 0x8023BE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8023BE08:
    // 0x8023BE08: beq         $a1, $zero, L_8023BE34
    if (ctx->r5 == 0) {
        // 0x8023BE0C: nop
    
            goto L_8023BE34;
    }
    // 0x8023BE0C: nop

    // 0x8023BE10: jal         0x80020744
    // 0x8023BE14: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x8023BE14: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x8023BE18: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023BE1C: jal         0x801471DC
    // 0x8023BE20: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_2;
    // 0x8023BE20: lw          $a0, 0x888($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X888);
    after_2:
    // 0x8023BE24: jal         0x8023B2E8
    // 0x8023BE28: nop

    LOOKUP_FUNC(0x8023B2E8)(rdram, ctx);
        goto after_3;
    // 0x8023BE28: nop

    after_3:
    // 0x8023BE2C: jal         0x8023A790
    // 0x8023BE30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8023A790)(rdram, ctx);
        goto after_4;
    // 0x8023BE30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_8023BE34:
    // 0x8023BE34: jal         0x8023AC94
    // 0x8023BE38: nop

    LOOKUP_FUNC(0x8023AC94)(rdram, ctx);
        goto after_5;
    // 0x8023BE38: nop

    after_5:
    // 0x8023BE3C: jal         0x8023A9D8
    // 0x8023BE40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8023A9D8)(rdram, ctx);
        goto after_6;
    // 0x8023BE40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_6:
    // 0x8023BE44: jal         0x8023B3CC
    // 0x8023BE48: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8023B3CC)(rdram, ctx);
        goto after_7;
    // 0x8023BE48: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_7:
    // 0x8023BE4C: jal         0x8023AE34
    // 0x8023BE50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8023AE34)(rdram, ctx);
        goto after_8;
    // 0x8023BE50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x8023BE54: beq         $v0, $zero, L_8023BE7C
    if (ctx->r2 == 0) {
        // 0x8023BE58: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_8023BE7C;
    }
    // 0x8023BE58: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8023BE5C: jal         0x80020744
    // 0x8023BE60: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_9;
    // 0x8023BE60: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_9:
    // 0x8023BE64: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BE68: addiu       $a1, $a1, -0x4058
    ctx->r5 = ADD32(ctx->r5, -0X4058);
    // 0x8023BE6C: jal         0x800058DC
    // 0x8023BE70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x8023BE70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x8023BE74: b           L_8023BF04
    // 0x8023BE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023BF04;
    // 0x8023BE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BE7C:
    // 0x8023BE7C: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x8023BE80: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8023BE84: beql        $t7, $zero, L_8023BF04
    if (ctx->r15 == 0) {
        // 0x8023BE88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023BF04;
    }
    goto skip_0;
    // 0x8023BE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8023BE8C: jal         0x80236374
    // 0x8023BE90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80236374)(rdram, ctx);
        goto after_11;
    // 0x8023BE90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8023BE94: beq         $v0, $zero, L_8023BEB0
    if (ctx->r2 == 0) {
        // 0x8023BE98: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8023BEB0;
    }
    // 0x8023BE98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BE9C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BEA0: jal         0x800058DC
    // 0x8023BEA4: addiu       $a1, $a1, -0x4368
    ctx->r5 = ADD32(ctx->r5, -0X4368);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x8023BEA4: addiu       $a1, $a1, -0x4368
    ctx->r5 = ADD32(ctx->r5, -0X4368);
    after_12:
    // 0x8023BEA8: b           L_8023BF04
    // 0x8023BEAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023BF04;
    // 0x8023BEAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BEB0:
    // 0x8023BEB0: jal         0x80147D60
    // 0x8023BEB4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_13;
    // 0x8023BEB4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8023BEB8: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x8023BEBC: lw          $t8, 0x880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X880);
    // 0x8023BEC0: jal         0x801471DC
    // 0x8023BEC4: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_14;
    // 0x8023BEC4: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_14:
    // 0x8023BEC8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023BECC: sb          $zero, 0x8A0($at)
    MEM_B(0X8A0, ctx->r1) = 0;
    // 0x8023BED0: jal         0x8023A5D4
    // 0x8023BED4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8023A5D4)(rdram, ctx);
        goto after_15;
    // 0x8023BED4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x8023BED8: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023BEDC: jal         0x8023AFD0
    // 0x8023BEE0: lbu         $a0, 0x8A0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X8A0);
    LOOKUP_FUNC(0x8023AFD0)(rdram, ctx);
        goto after_16;
    // 0x8023BEE0: lbu         $a0, 0x8A0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X8A0);
    after_16:
    // 0x8023BEE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BEE8: jal         0x8023B148
    // 0x8023BEEC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8023B148)(rdram, ctx);
        goto after_17;
    // 0x8023BEEC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_17:
    // 0x8023BEF0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BEF4: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8023BEF8: jal         0x800058DC
    // 0x8023BEFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x8023BEFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x8023BF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023BF04:
    // 0x8023BF04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023BF08: jr          $ra
    // 0x8023BF0C: nop

    return;
    // 0x8023BF0C: nop

;}
RECOMP_FUNC void M10_FUN_8023bf10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BF10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023BF14: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023BF18: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023BF1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023BF20: lbu         $a1, 0x1C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1C);
    // 0x8023BF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023BF28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8023BF2C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8023BF30: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x8023BF34: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8023BF38: lbu         $a0, 0x1B($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1B);
    // 0x8023BF3C: lbu         $a2, 0x1D($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1D);
    // 0x8023BF40: lbu         $a3, 0x1E($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X1E);
    // 0x8023BF44: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8023BF48: bgez        $a1, L_8023BF54
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8023BF4C: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_8023BF54;
    }
    // 0x8023BF4C: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x8023BF50: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
L_8023BF54:
    // 0x8023BF54: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8023BF58: jal         0x80243E50
    // 0x8023BF5C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80243E50)(rdram, ctx);
        goto after_0;
    // 0x8023BF5C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8023BF60: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8023BF64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8023BF68: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8023BF6C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8023BF70: addiu       $t9, $t9, 0x42A0
    ctx->r25 = ADD32(ctx->r25, 0X42A0);
    // 0x8023BF74: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8023BF78: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8023BF7C: sw          $t0, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r8;
    // 0x8023BF80: jal         0x80376BE4
    // 0x8023BF84: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    LOOKUP_FUNC(0x80376BE4)(rdram, ctx);
        goto after_1;
    // 0x8023BF84: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    after_1:
    // 0x8023BF88: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023BF8C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    // 0x8023BF90: jal         0x800058DC
    // 0x8023BF94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8023BF94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8023BF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023BF9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023BFA0: jr          $ra
    // 0x8023BFA4: nop

    return;
    // 0x8023BFA4: nop

;}
RECOMP_FUNC void M10_FUN_8023bfa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BFA8: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8023BFAC: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, 0X880);
    // 0x8023BFB0: lbu         $t9, 0x6A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X6A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023bfb4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023bfb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023BFB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023BFB8: lbu         $t8, 0x6B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6B);
    // 0x8023BFBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023BFC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8023BFC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023BFC8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8023BFCC: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x8023BFD0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8023BFD4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8023BFD8: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8023BFDC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023BFE0: jal         0x8023A3C4
    // 0x8023BFE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8023A3C4)(rdram, ctx);
        goto after_0;
    // 0x8023BFE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8023BFE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8023BFEC: jal         0x8023A398
    // 0x8023BFF0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8023A398)(rdram, ctx);
        goto after_1;
    // 0x8023BFF0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // 0x8023BFF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8023BFF8: jal         0x80376BE4
    // 0x8023BFFC: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    LOOKUP_FUNC(0x80376BE4)(rdram, ctx);
        goto after_2;
    // 0x8023BFFC: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    after_2:
    // 0x8023C000: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023C004: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    // 0x8023C008: jal         0x800058DC
    // 0x8023C00C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8023C00C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8023C010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023C014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023C018: jr          $ra
    // 0x8023C01C: nop

    return;
    // 0x8023C01C: nop

;}
RECOMP_FUNC void M10_FUN_8023c020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023C020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023C024: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023C028: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023C02C: lbu         $a1, 0x89F($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X89F);
    // 0x8023C030: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8023C034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023C038: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8023C03C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023C040: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x8023C044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8023C048: lw          $a0, 0x98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98);
    // 0x8023C04C: mfhi        $a1
    ctx->r5 = hi;
    // 0x8023C050: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8023C054: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023C058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8023C05C: jal         0x8013CD04
    // 0x8023C060: sb          $t7, 0x2D8($a0)
    MEM_B(0X2D8, ctx->r4) = ctx->r15;
    LOOKUP_FUNC(0x8013CD04)(rdram, ctx);
        goto after_0;
    // 0x8023C060: sb          $t7, 0x2D8($a0)
    MEM_B(0X2D8, ctx->r4) = ctx->r15;
    after_0:
    // 0x8023C064: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023C068: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    // 0x8023C06C: jal         0x800058DC
    // 0x8023C070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8023C070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8023C074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023C078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023C07C: jr          $ra
    // 0x8023C080: nop

    return;
    // 0x8023C080: nop

;}
RECOMP_FUNC void M10_FUN_8023c084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023C084: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8023C088: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8023C08C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8023C090: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8023C094: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8023C098: jal         0x80116E80
    // 0x8023C09C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x8023C09C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8023C0A0: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8023C0A4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8023C0A8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8023C0AC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8023C0B0: addiu       $t0, $zero, 0x20B
    ctx->r8 = ADD32(0, 0X20B);
    // 0x8023C0B4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8023C0B8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8023C0BC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8023C0C0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8023C0C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8023C0C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023C0CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8023C0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023C0D4: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8023C0D8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8023C0DC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8023C0E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023C0E4: jal         0x80146208
    // 0x8023C0E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8023C0E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x8023C0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023C0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8023C0F4: jal         0x80145348
    // 0x8023C0F8: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8023C0F8: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_2:
    // 0x8023C0FC: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8023C100: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8023C104: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8023C108: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023C10C: sh          $t2, 0x28($t3)
    MEM_H(0X28, ctx->r11) = ctx->r10;
    // 0x8023C110: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x8023C114: addiu       $a1, $a1, -0x3ECC
    ctx->r5 = ADD32(ctx->r5, -0X3ECC);
    // 0x8023C118: jal         0x800058DC
    // 0x8023C11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8023C11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8023C120: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8023C124: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8023C128: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8023C12C: jr          $ra
    // 0x8023C130: nop

    return;
    // 0x8023C130: nop

;}
RECOMP_FUNC void M10_FUN_8023c134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023C134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023C138: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8023C13C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8023C140: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023C144: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x8023C148: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8023C14C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8023C150: addiu       $t9, $zero, 0x21
    ctx->r25 = ADD32(0, 0X21);
    // 0x8023C154: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023C158: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023C15C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8023C160: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8023C164: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8023C168: jal         0x801453CC
    // 0x8023C16C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8023C16C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8023C170: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8023C174: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023C178: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x8023C17C: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8023C180: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8023C184: bne         $v1, $zero, L_8023C194
    if (ctx->r3 != 0) {
        // 0x8023C188: sh          $t0, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r8;
            goto L_8023C194;
    }
    // 0x8023C188: sh          $t0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r8;
    // 0x8023C18C: jal         0x800058DC
    // 0x8023C190: addiu       $a1, $a1, -0x3E5C
    ctx->r5 = ADD32(ctx->r5, -0X3E5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8023C190: addiu       $a1, $a1, -0x3E5C
    ctx->r5 = ADD32(ctx->r5, -0X3E5C);
    after_1:
L_8023C194:
    // 0x8023C194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8023C198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023C19C: jr          $ra
    // 0x8023C1A0: nop

    return;
    // 0x8023C1A0: nop

;}
RECOMP_FUNC void M10_FUN_8023c1a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023C1A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8023C1A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8023C1AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8023C1B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8023C1B4: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x8023C1B8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8023C1BC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8023C1C0: addiu       $t9, $zero, 0x21
    ctx->r25 = ADD32(0, 0X21);
    // 0x8023C1C4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023C1C8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023C1CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8023C1D0: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x8023C1D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8023C1D8: jal         0x801453CC
    // 0x8023C1DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8023C1DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8023C1E0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8023C1E4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023C1E8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8023C1EC: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x8023C1F0: beql        $v0, $zero, L_8023C208
    if (ctx->r2 == 0) {
        // 0x8023C1F4: lh          $v1, 0x2E($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X2E);
            goto L_8023C208;
    }
    goto skip_0;
    // 0x8023C1F4: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    skip_0:
    // 0x8023C1F8: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x8023C1FC: lbu         $v1, 0xB($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0XB);
    // 0x8023C200: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8023C204: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
L_8023C208:
    // 0x8023C208: addiu       $v1, $v1, -0x19
    ctx->r3 = ADD32(ctx->r3, -0X19);
    // 0x8023C20C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8023C210: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8023C214: blez        $v1, L_8023C228
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8023C218: nop
    
            goto L_8023C228;
    }
    // 0x8023C218: nop

    // 0x8023C21C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x8023C220: b           L_8023C238
    // 0x8023C224: sb          $v1, 0xB($t2)
    MEM_B(0XB, ctx->r10) = ctx->r3;
        goto L_8023C238;
    // 0x8023C224: sb          $v1, 0xB($t2)
    MEM_B(0XB, ctx->r10) = ctx->r3;
L_8023C228:
    // 0x8023C228: jal         0x801170DC
    // 0x8023C22C: sw          $zero, -0x1ABC($at)
    MEM_W(-0X1ABC, ctx->r1) = 0;
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_1;
    // 0x8023C22C: sw          $zero, -0x1ABC($at)
    MEM_W(-0X1ABC, ctx->r1) = 0;
    after_1:
    // 0x8023C230: jal         0x80005700
    // 0x8023C234: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x8023C234: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
L_8023C238:
    // 0x8023C238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8023C23C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8023C240: jr          $ra
    // 0x8023C244: nop

    return;
    // 0x8023C244: nop

;}
RECOMP_FUNC void M10_FUN_8023c248(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8023C248u);
    return;
}
RECOMP_FUNC void M10_FUN_8023f3cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023F3CC: sb          $s1, -0x5C30($sp)
    MEM_B(-0X5C30, ctx->r29) = ctx->r17;
    // 0x8023F3D0: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023f3d4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023f3d4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8023F3D4u);
    return;
}
RECOMP_FUNC void M12_FUN_802408f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802408F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802408F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802408F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802408FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80240900: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80240904: jal         0x80133A24
    // 0x80240908: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80240908: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8024090C: beq         $v0, $zero, L_8024091C
    if (ctx->r2 == 0) {
        // 0x80240910: nop
    
            goto L_8024091C;
    }
    // 0x80240910: nop

    // 0x80240914: jal         0x80005700
    // 0x80240918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80240918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8024091C:
    // 0x8024091C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80240920: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80240924: lw          $t6, 0xE0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE0);
    // 0x80240928: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x8024092C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80240930: beq         $t6, $zero, L_80240998
    if (ctx->r14 == 0) {
        // 0x80240934: addiu       $t0, $t0, 0xF0C
        ctx->r8 = ADD32(ctx->r8, 0XF0C);
            goto L_80240998;
    }
    // 0x80240934: addiu       $t0, $t0, 0xF0C
    ctx->r8 = ADD32(ctx->r8, 0XF0C);
    // 0x80240938: sb          $t7, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r15;
    // 0x8024093C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80240940: lhu         $t1, 0x36($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X36);
    // 0x80240944: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80240948: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x8024094C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80240950: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80240954: sw          $t0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r8;
    // 0x80240958: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8024095C: lw          $t3, 0x1CEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1CEC);
    // 0x80240960: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80240964: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80240968: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8024096C: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    // 0x80240970: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x80240974: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80240978: jal         0x801267B8
    // 0x8024097C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_2;
    // 0x8024097C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_2:
    // 0x80240980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80240984: bne         $v0, $at, L_80240998
    if (ctx->r2 != ctx->r1) {
        // 0x80240988: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80240998;
    }
    // 0x80240988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8024098C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80240990: jal         0x800058DC
    // 0x80240994: addiu       $a1, $a1, 0x9AC
    ctx->r5 = ADD32(ctx->r5, 0X9AC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80240994: addiu       $a1, $a1, 0x9AC
    ctx->r5 = ADD32(ctx->r5, 0X9AC);
    after_3:
L_80240998:
    // 0x80240998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8024099C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802409A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802409A4: jr          $ra
    // 0x802409A8: nop

    return;
    // 0x802409A8: nop

;}
