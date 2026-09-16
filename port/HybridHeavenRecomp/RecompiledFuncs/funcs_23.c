#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8012e454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012E458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E45C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8012E460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8012E464: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012E468: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012E46C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012E470: beql        $t6, $zero, L_8012E574
    if (ctx->r14 == 0) {
        // 0x8012E474: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E574;
    }
    goto skip_0;
    // 0x8012E474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8012E478: jal         0x8012D7A8
    // 0x8012E47C: nop

    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x8012E47C: nop

    after_0:
    // 0x8012E480: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8012E484: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x8012E488: lhu         $t7, 0xEF0($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XEF0);
    // 0x8012E48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E490: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8012E494: bnel        $t8, $zero, L_8012E574
    if (ctx->r24 != 0) {
        // 0x8012E498: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E574;
    }
    goto skip_1;
    // 0x8012E498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8012E49C: jal         0x8012E25C
    // 0x8012E4A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8012E25C)(rdram, ctx);
        goto after_1;
    // 0x8012E4A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8012E4A4: jal         0x8012DA90
    // 0x8012E4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012DA90)(rdram, ctx);
        goto after_2;
    // 0x8012E4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8012E4AC: jal         0x8012CB4C
    // 0x8012E4B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CB4C)(rdram, ctx);
        goto after_3;
    // 0x8012E4B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8012E4B4: jal         0x8012C9C0
    // 0x8012E4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012C9C0)(rdram, ctx);
        goto after_4;
    // 0x8012E4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8012E4BC: jal         0x8012CE10
    // 0x8012E4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CE10)(rdram, ctx);
        goto after_5;
    // 0x8012E4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8012E4C4: jal         0x8012DE58
    // 0x8012E4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012DE58)(rdram, ctx);
        goto after_6;
    // 0x8012E4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8012E4CC: lw          $t9, 0xE0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XE0);
    // 0x8012E4D0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8012E4D4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012E4D8: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012E4DC: jal         0x80108634
    // 0x8012E4E0: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x80108634)(rdram, ctx);
        goto after_7;
    // 0x8012E4E0: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_7:
    // 0x8012E4E4: beq         $v0, $zero, L_8012E51C
    if (ctx->r2 == 0) {
        // 0x8012E4E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8012E51C;
    }
    // 0x8012E4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E4EC: lw          $t0, 0xE0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XE0);
    // 0x8012E4F0: lwc1        $f4, 0x374($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X374);
    // 0x8012E4F4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012E4F8: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x8012E4FC: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x8012E500: lwc1        $f6, 0x378($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X378);
    // 0x8012E504: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8012E508: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x8012E50C: lw          $t4, 0xE0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE0);
    // 0x8012E510: lwc1        $f8, 0x37C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X37C);
    // 0x8012E514: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012E518: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
L_8012E51C:
    // 0x8012E51C: jal         0x801C4A5C
    // 0x8012E520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_8;
    // 0x8012E520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8012E524: jal         0x801C787C
    // 0x8012E528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C787C)(rdram, ctx);
        goto after_9;
    // 0x8012E528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8012E52C: jal         0x80126944
    // 0x8012E530: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_10;
    // 0x8012E530: nop

    after_10:
    // 0x8012E534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012E538: bne         $v0, $at, L_8012E568
    if (ctx->r2 != ctx->r1) {
        // 0x8012E53C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8012E568;
    }
    // 0x8012E53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E540: lbu         $v0, 0x1031($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1031);
    // 0x8012E544: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8012E548: beq         $v0, $at, L_8012E568
    if (ctx->r2 == ctx->r1) {
        // 0x8012E54C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8012E568;
    }
    // 0x8012E54C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8012E550: beq         $v0, $at, L_8012E568
    if (ctx->r2 == ctx->r1) {
        // 0x8012E554: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8012E568;
    }
    // 0x8012E554: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012E558: beq         $v0, $at, L_8012E568
    if (ctx->r2 == ctx->r1) {
        // 0x8012E55C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8012E568;
    }
    // 0x8012E55C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8012E560: bnel        $v0, $at, L_8012E574
    if (ctx->r2 != ctx->r1) {
        // 0x8012E564: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E574;
    }
    goto skip_2;
    // 0x8012E564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8012E568:
    // 0x8012E568: jal         0x8012E31C
    // 0x8012E56C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8012E31C)(rdram, ctx);
        goto after_11;
    // 0x8012E56C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x8012E570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E574:
    // 0x8012E574: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8012E578: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8012E57C: jr          $ra
    // 0x8012E580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8012E580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012e584(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012e584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012E588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012E58C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8012E590: jal         0x8012E774
    // 0x8012E594: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012E774)(rdram, ctx);
        goto after_0;
    // 0x8012E594: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8012E598: jal         0x8012B7C0
    // 0x8012E59C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x8012B7C0)(rdram, ctx);
        goto after_1;
    // 0x8012E59C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8012E5A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012E5A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012E5A8: jr          $ra
    // 0x8012E5AC: nop

    return;
    // 0x8012E5AC: nop

;}
RECOMP_FUNC void M7_FUN_8012e5b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E5B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012E5B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E5B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012E5BC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012E5C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012E5C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8012E5C8: beql        $t6, $zero, L_8012E644
    if (ctx->r14 == 0) {
        // 0x8012E5CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E644;
    }
    goto skip_0;
    // 0x8012E5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8012E5D0: jal         0x8012DF38
    // 0x8012E5D4: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8012DF38)(rdram, ctx);
        goto after_0;
    // 0x8012E5D4: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_0:
    // 0x8012E5D8: jal         0x80126944
    // 0x8012E5DC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x8012E5DC: nop

    after_1:
    // 0x8012E5E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012E5E4: bne         $v0, $at, L_8012E61C
    if (ctx->r2 != ctx->r1) {
        // 0x8012E5E8: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8012E61C;
    }
    // 0x8012E5E8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012E5EC: lbu         $v0, -0x33DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33DF);
    // 0x8012E5F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8012E5F4: beq         $v0, $at, L_8012E61C
    if (ctx->r2 == ctx->r1) {
        // 0x8012E5F8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8012E61C;
    }
    // 0x8012E5F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8012E5FC: beq         $v0, $at, L_8012E61C
    if (ctx->r2 == ctx->r1) {
        // 0x8012E600: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8012E61C;
    }
    // 0x8012E600: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8012E604: beq         $v0, $at, L_8012E61C
    if (ctx->r2 == ctx->r1) {
        // 0x8012E608: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8012E61C;
    }
    // 0x8012E608: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012E60C: beq         $v0, $at, L_8012E61C
    if (ctx->r2 == ctx->r1) {
        // 0x8012E610: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8012E61C;
    }
    // 0x8012E610: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8012E614: bnel        $v0, $at, L_8012E644
    if (ctx->r2 != ctx->r1) {
        // 0x8012E618: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E644;
    }
    goto skip_1;
    // 0x8012E618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8012E61C:
    // 0x8012E61C: jal         0x8012B7C0
    // 0x8012E620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012B7C0)(rdram, ctx);
        goto after_2;
    // 0x8012E620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8012E624: jal         0x8012E774
    // 0x8012E628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012E774)(rdram, ctx);
        goto after_3;
    // 0x8012E628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8012E62C: jal         0x8013C608
    // 0x8012E630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8013C608)(rdram, ctx);
        goto after_4;
    // 0x8012E630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8012E634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E638: jal         0x801DE7EC
    // 0x8012E63C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x801DE7EC)(rdram, ctx);
        goto after_5;
    // 0x8012E63C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x8012E640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E644:
    // 0x8012E644: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012E648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012E64C: jr          $ra
    // 0x8012E650: nop

    return;
    // 0x8012E650: nop

;}
RECOMP_FUNC void M7_FUN_8012e654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012E658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E65C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012E660: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012E664: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012E668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012E66C: beql        $t6, $zero, L_8012E6AC
    if (ctx->r14 == 0) {
        // 0x8012E670: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E6AC;
    }
    goto skip_0;
    // 0x8012E670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8012E674: jal         0x8012D7A8
    // 0x8012E678: nop

    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x8012E678: nop

    after_0:
    // 0x8012E67C: jal         0x8012CD28
    // 0x8012E680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CD28)(rdram, ctx);
        goto after_1;
    // 0x8012E680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8012E684: jal         0x8012C9C0
    // 0x8012E688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012C9C0)(rdram, ctx);
        goto after_2;
    // 0x8012E688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8012E68C: jal         0x8012CE10
    // 0x8012E690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CE10)(rdram, ctx);
        goto after_3;
    // 0x8012E690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8012E694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E698: jal         0x8012B1E4
    // 0x8012E69C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012B1E4)(rdram, ctx);
        goto after_4;
    // 0x8012E69C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8012E6A0: jal         0x8012BFA0
    // 0x8012E6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012BFA0)(rdram, ctx);
        goto after_5;
    // 0x8012E6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8012E6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E6AC:
    // 0x8012E6AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012E6B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012E6B4: jr          $ra
    // 0x8012E6B8: nop

    return;
    // 0x8012E6B8: nop

;}
RECOMP_FUNC void M7_FUN_8012e6bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E6BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012E6C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012E6C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012E6C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012E6CC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012E6D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012E6D4: beql        $t6, $zero, L_8012E764
    if (ctx->r14 == 0) {
        // 0x8012E6D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E764;
    }
    goto skip_0;
    // 0x8012E6D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8012E6DC: jal         0x8012E25C
    // 0x8012E6E0: nop

    LOOKUP_FUNC(0x8012E25C)(rdram, ctx);
        goto after_0;
    // 0x8012E6E0: nop

    after_0:
    // 0x8012E6E4: jal         0x80126944
    // 0x8012E6E8: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x8012E6E8: nop

    after_1:
    // 0x8012E6EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012E6F0: bne         $v0, $at, L_8012E720
    if (ctx->r2 != ctx->r1) {
        // 0x8012E6F4: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8012E720;
    }
    // 0x8012E6F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012E6F8: lbu         $v0, -0x33DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33DF);
    // 0x8012E6FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8012E700: beq         $v0, $at, L_8012E720
    if (ctx->r2 == ctx->r1) {
        // 0x8012E704: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8012E720;
    }
    // 0x8012E704: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8012E708: beq         $v0, $at, L_8012E720
    if (ctx->r2 == ctx->r1) {
        // 0x8012E70C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8012E720;
    }
    // 0x8012E70C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012E710: beq         $v0, $at, L_8012E720
    if (ctx->r2 == ctx->r1) {
        // 0x8012E714: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8012E720;
    }
    // 0x8012E714: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8012E718: bnel        $v0, $at, L_8012E764
    if (ctx->r2 != ctx->r1) {
        // 0x8012E71C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8012E764;
    }
    goto skip_1;
    // 0x8012E71C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8012E720:
    // 0x8012E720: jal         0x8012CD28
    // 0x8012E724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CD28)(rdram, ctx);
        goto after_2;
    // 0x8012E724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8012E728: jal         0x8012C9C0
    // 0x8012E72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012C9C0)(rdram, ctx);
        goto after_3;
    // 0x8012E72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8012E730: jal         0x8012CE10
    // 0x8012E734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012CE10)(rdram, ctx);
        goto after_4;
    // 0x8012E734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8012E738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E73C: jal         0x8012B1E4
    // 0x8012E740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012B1E4)(rdram, ctx);
        goto after_5;
    // 0x8012E740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8012E744: jal         0x8012BFA0
    // 0x8012E748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012BFA0)(rdram, ctx);
        goto after_6;
    // 0x8012E748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8012E74C: jal         0x8012D7A8
    // 0x8012E750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_7;
    // 0x8012E750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8012E754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012E758: jal         0x8012E31C
    // 0x8012E75C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8012E31C)(rdram, ctx);
        goto after_8;
    // 0x8012E75C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x8012E760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8012E764:
    // 0x8012E764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012E768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012E76C: jr          $ra
    // 0x8012E770: nop

    return;
    // 0x8012E770: nop

;}
RECOMP_FUNC void M7_FUN_8012e774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E774: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E778: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E77C: lhu         $t6, 0xFE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XFE);
    // 0x8012E780: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8012E784: sh          $t7, 0xFE($v1)
    MEM_H(0XFE, ctx->r3) = ctx->r15;
    // 0x8012E788: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8012E78C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8012E790: beql        $t9, $zero, L_8012E7D4
    if (ctx->r25 == 0) {
        // 0x8012E794: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_8012E7D4;
    }
    goto skip_0;
    // 0x8012E794: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x8012E798: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x8012E79C: beql        $v0, $zero, L_8012E7D4
    if (ctx->r2 == 0) {
        // 0x8012E7A0: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_8012E7D4;
    }
    goto skip_1;
    // 0x8012E7A0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x8012E7A4: lhu         $t0, 0x72($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X72);
    // 0x8012E7A8: and         $t1, $t0, $v0
    ctx->r9 = ctx->r8 & ctx->r2;
    // 0x8012E7AC: beql        $t1, $zero, L_8012E7D4
    if (ctx->r9 == 0) {
        // 0x8012E7B0: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_8012E7D4;
    }
    goto skip_2;
    // 0x8012E7B0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_2:
    // 0x8012E7B4: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8012E7B8: lw          $t2, 0x8C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8C);
    // 0x8012E7BC: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8012E7C0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8012E7C4: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x8012E7C8: jr          $ra
    // 0x8012E7CC: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    return;
    // 0x8012E7CC: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x8012E7D0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_8012E7D4:
    // 0x8012E7D4: beq         $v0, $zero, L_8012E814
    if (ctx->r2 == 0) {
        // 0x8012E7D8: nop
    
            goto L_8012E814;
    }
    // 0x8012E7D8: nop

    // 0x8012E7DC: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x8012E7E0: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x8012E7E4: lui         $v0, 0xFF7F
    ctx->r2 = S32(0XFF7F << 16);
    // 0x8012E7E8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8012E7EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012E7F0: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x8012E7F4: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8012E7F8: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x8012E7FC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8012E800: swc1        $f4, 0x440($v1)
    MEM_W(0X440, ctx->r3) = ctx->f4.u32l;
    // 0x8012E804: lwc1        $f6, 0x440($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X440);
    // 0x8012E808: swc1        $f6, 0x43C($v1)
    MEM_W(0X43C, ctx->r3) = ctx->f6.u32l;
    // 0x8012E80C: lwc1        $f8, 0x43C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X43C);
    // 0x8012E810: swc1        $f8, 0x438($v1)
    MEM_W(0X438, ctx->r3) = ctx->f8.u32l;
L_8012E814:
    // 0x8012E814: jr          $ra
    // 0x8012E818: nop

    return;
    // 0x8012E818: nop

;}
RECOMP_FUNC void M7_FUN_8012e81c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E81C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E820: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E824: lhu         $t6, 0x30($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X30);
    // 0x8012E828: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012e82c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012e82c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012E82C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8012E830: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8012E834: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8012E838: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8012E83C: beq         $v0, $at, L_8012EA48
    if (ctx->r2 == ctx->r1) {
        // 0x8012E840: sh          $t7, 0x30($v1)
        MEM_H(0X30, ctx->r3) = ctx->r15;
            goto L_8012EA48;
    }
    // 0x8012E840: sh          $t7, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r15;
    // 0x8012E844: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8012E848: beq         $v0, $at, L_8012E9F8
    if (ctx->r2 == ctx->r1) {
        // 0x8012E84C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8012E9F8;
    }
    // 0x8012E84C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8012E850: jal         0x80151BC4
    // 0x8012E854: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_0;
    // 0x8012E854: nop

    after_0:
    // 0x8012E858: beq         $v0, $zero, L_8012E880
    if (ctx->r2 == 0) {
        // 0x8012E85C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8012E880;
    }
    // 0x8012E85C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8012E860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012E864: beq         $v0, $at, L_8012E8D0
    if (ctx->r2 == ctx->r1) {
        // 0x8012E868: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_8012E8D0;
    }
    // 0x8012E868: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012E86C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8012E870: beq         $v0, $at, L_8012E920
    if (ctx->r2 == ctx->r1) {
        // 0x8012E874: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_8012E920;
    }
    // 0x8012E874: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012E878: b           L_8012E99C
    // 0x8012E87C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
        goto L_8012E99C;
    // 0x8012E87C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
L_8012E880:
    // 0x8012E880: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8012E884: addiu       $t9, $t9, 0x6090
    ctx->r25 = ADD32(ctx->r25, 0X6090);
    // 0x8012E888: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8012E88C: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8012E890: addiu       $t8, $t8, -0x4374
    ctx->r24 = ADD32(ctx->r24, -0X4374);
    // 0x8012E894: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8012E898: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8012E89C: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8012E8A0: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8012E8A4: sw          $t2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r10;
    // 0x8012E8A8: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
    // 0x8012E8AC: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x8012E8B0: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8012E8B4: sw          $t3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r11;
    // 0x8012E8B8: sw          $t2, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r10;
    // 0x8012E8BC: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x8012E8C0: lw          $t3, 0x18($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X18);
    // 0x8012E8C4: sw          $t2, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r10;
    // 0x8012E8C8: b           L_8012E9E4
    // 0x8012E8CC: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
        goto L_8012E9E4;
    // 0x8012E8CC: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
L_8012E8D0:
    // 0x8012E8D0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8012E8D4: addiu       $t5, $t5, -0x6B8C
    ctx->r13 = ADD32(ctx->r13, -0X6B8C);
    // 0x8012E8D8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012E8DC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012E8E0: addiu       $t4, $t4, -0x4374
    ctx->r12 = ADD32(ctx->r12, -0X4374);
    // 0x8012E8E4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8012E8E8: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8012E8EC: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012E8F0: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012E8F4: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8012E8F8: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8012E8FC: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012E900: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8012E904: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x8012E908: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x8012E90C: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8012E910: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x8012E914: sw          $t6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r14;
    // 0x8012E918: b           L_8012E9E4
    // 0x8012E91C: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
        goto L_8012E9E4;
    // 0x8012E91C: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
L_8012E920:
    // 0x8012E920: jal         0x80151BFC
    // 0x8012E924: nop

    LOOKUP_FUNC(0x80151BFC)(rdram, ctx);
        goto after_1;
    // 0x8012E924: nop

    after_1:
    // 0x8012E928: bne         $v0, $zero, L_8012E944
    if (ctx->r2 != 0) {
        // 0x8012E92C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8012E944;
    }
    // 0x8012E92C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8012E930: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8012E934: jal         0x80151DA4
    // 0x8012E938: addiu       $a0, $a0, -0x4374
    ctx->r4 = ADD32(ctx->r4, -0X4374);
    LOOKUP_FUNC(0x80151DA4)(rdram, ctx);
        goto after_2;
    // 0x8012E938: addiu       $a0, $a0, -0x4374
    ctx->r4 = ADD32(ctx->r4, -0X4374);
    after_2:
    // 0x8012E93C: b           L_8012E9E4
    // 0x8012E940: nop

        goto L_8012E9E4;
    // 0x8012E940: nop

L_8012E944:
    // 0x8012E944: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8012E948: addiu       $t9, $t9, -0x6B8C
    ctx->r25 = ADD32(ctx->r25, -0X6B8C);
    // 0x8012E94C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8012E950: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8012E954: addiu       $t8, $t8, -0x4374
    ctx->r24 = ADD32(ctx->r24, -0X4374);
    // 0x8012E958: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8012E95C: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8012E960: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8012E964: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8012E968: sw          $t2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r10;
    // 0x8012E96C: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
    // 0x8012E970: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x8012E974: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8012E978: sw          $t3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r11;
    // 0x8012E97C: sw          $t2, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r10;
    // 0x8012E980: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x8012E984: lw          $t3, 0x18($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X18);
    // 0x8012E988: sw          $t2, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r10;
    // 0x8012E98C: jal         0x801521C8
    // 0x8012E990: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
    LOOKUP_FUNC(0x801521C8)(rdram, ctx);
        goto after_3;
    // 0x8012E990: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
    after_3:
    // 0x8012E994: b           L_8012E9E4
    // 0x8012E998: nop

        goto L_8012E9E4;
    // 0x8012E998: nop

L_8012E99C:
    // 0x8012E99C: addiu       $t5, $t5, -0x6B8C
    ctx->r13 = ADD32(ctx->r13, -0X6B8C);
    // 0x8012E9A0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012E9A4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012E9A8: addiu       $t4, $t4, -0x4374
    ctx->r12 = ADD32(ctx->r12, -0X4374);
    // 0x8012E9AC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8012E9B0: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8012E9B4: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012E9B8: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012E9BC: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8012E9C0: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8012E9C4: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012E9C8: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8012E9CC: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x8012E9D0: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x8012E9D4: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8012E9D8: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x8012E9DC: sw          $t6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r14;
    // 0x8012E9E0: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
L_8012E9E4:
    // 0x8012E9E4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012E9E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012E9EC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012E9F0: b           L_8012EA48
    // 0x8012E9F4: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
        goto L_8012EA48;
    // 0x8012E9F4: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
L_8012E9F8:
    // 0x8012E9F8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8012E9FC: addiu       $t9, $t9, -0x6B8C
    ctx->r25 = ADD32(ctx->r25, -0X6B8C);
    // 0x8012EA00: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8012EA04: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8012EA08: addiu       $t8, $t8, -0x4374
    ctx->r24 = ADD32(ctx->r24, -0X4374);
    // 0x8012EA0C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8012EA10: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8012EA14: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8012EA18: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8012EA1C: sw          $t2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r10;
    // 0x8012EA20: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
    // 0x8012EA24: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x8012EA28: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8012EA2C: sw          $t3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r11;
    // 0x8012EA30: sw          $t2, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r10;
    // 0x8012EA34: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x8012EA38: lw          $t3, 0x18($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X18);
    // 0x8012EA3C: sw          $t2, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r10;
    // 0x8012EA40: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
    // 0x8012EA44: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
L_8012EA48:
    // 0x8012EA48: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012EA4C: beq         $v0, $at, L_8012EA5C
    if (ctx->r2 == ctx->r1) {
        // 0x8012EA50: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8012EA5C;
    }
    // 0x8012EA50: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8012EA54: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8012EA58: bne         $v0, $at, L_8012EAAC
    if (ctx->r2 != ctx->r1) {
        // 0x8012EA5C: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_8012EAAC;
    }
L_8012EA5C:
    // 0x8012EA5C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8012EA60: addiu       $t5, $t5, -0x6B6C
    ctx->r13 = ADD32(ctx->r13, -0X6B6C);
    // 0x8012EA64: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012EA68: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012EA6C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012EA70: addiu       $t4, $t4, -0x4354
    ctx->r12 = ADD32(ctx->r12, -0X4354);
    // 0x8012EA74: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8012EA78: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8012EA7C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012EA80: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012EA84: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8012EA88: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8012EA8C: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012EA90: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8012EA94: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x8012EA98: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x8012EA9C: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8012EAA0: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x8012EAA4: sw          $t6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r14;
    // 0x8012EAA8: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
L_8012EAAC:
    // 0x8012EAAC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8012EAB0: addiu       $t9, $t9, -0x6B2C
    ctx->r25 = ADD32(ctx->r25, -0X6B2C);
    // 0x8012EAB4: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8012EAB8: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8012EABC: addiu       $t8, $t8, -0x4394
    ctx->r24 = ADD32(ctx->r24, -0X4394);
    // 0x8012EAC0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8012EAC4: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8012EAC8: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8012EACC: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8012EAD0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8012EAD4: sw          $t2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r10;
    // 0x8012EAD8: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
    // 0x8012EADC: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x8012EAE0: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8012EAE4: addiu       $t5, $t5, 0x6090
    ctx->r13 = ADD32(ctx->r13, 0X6090);
    // 0x8012EAE8: sw          $t3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r11;
    // 0x8012EAEC: sw          $t2, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r10;
    // 0x8012EAF0: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x8012EAF4: lw          $t3, 0x18($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X18);
    // 0x8012EAF8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012EAFC: sw          $t2, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r10;
    // 0x8012EB00: sw          $t3, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r11;
    // 0x8012EB04: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012EB08: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012EB0C: addiu       $t4, $t4, -0x43B4
    ctx->r12 = ADD32(ctx->r12, -0X43B4);
    // 0x8012EB10: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8012EB14: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8012EB18: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012EB1C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012EB20: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8012EB24: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8012EB28: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8012EB2C: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8012EB30: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012EB34: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EB38: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x8012EB3C: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x8012EB40: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x8012EB44: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8012EB48: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8012EB4C: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
    // 0x8012EB50: sw          $t6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r14;
    // 0x8012EB54: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x8012EB58: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EB5C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8012EB60: bne         $t9, $zero, L_8012EB7C
    if (ctx->r25 != 0) {
        // 0x8012EB64: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8012EB7C;
    }
    // 0x8012EB64: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8012EB68: lw          $t2, 0x60B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X60B0);
    // 0x8012EB6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8012EB70: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8012EB74: b           L_8012F2FC
    // 0x8012EB78: sw          $t3, 0x60B0($at)
    MEM_W(0X60B0, ctx->r1) = ctx->r11;
        goto L_8012F2FC;
    // 0x8012EB78: sw          $t3, 0x60B0($at)
    MEM_W(0X60B0, ctx->r1) = ctx->r11;
L_8012EB7C:
    // 0x8012EB7C: jal         0x8001DFFC
    // 0x8012EB80: addiu       $a3, $a3, -0x2C74
    ctx->r7 = ADD32(ctx->r7, -0X2C74);
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_4;
    // 0x8012EB80: addiu       $a3, $a3, -0x2C74
    ctx->r7 = ADD32(ctx->r7, -0X2C74);
    after_4:
    // 0x8012EB84: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EB88: addiu       $a3, $a3, -0x2C70
    ctx->r7 = ADD32(ctx->r7, -0X2C70);
    // 0x8012EB8C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8012EB90: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EB94: jal         0x8001DFFC
    // 0x8012EB98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_5;
    // 0x8012EB98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_5:
    // 0x8012EB9C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EBA0: addiu       $a3, $a3, -0x2C6C
    ctx->r7 = ADD32(ctx->r7, -0X2C6C);
    // 0x8012EBA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8012EBA8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EBAC: jal         0x8001DFFC
    // 0x8012EBB0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_6;
    // 0x8012EBB0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_6:
    // 0x8012EBB4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012EBB8: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x8012EBBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012EBC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8012EBC4: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8012EBC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012EBCC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8012EBD0: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8012EBD4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8012EBD8: nop

    // 0x8012EBDC: bc1fl       L_8012EBF4
    if (!c1cs) {
        // 0x8012EBE0: swc1        $f18, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
            goto L_8012EBF4;
    }
    goto skip_0;
    // 0x8012EBE0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    skip_0:
    // 0x8012EBE4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x8012EBE8: b           L_8012EBF4
    // 0x8012EBEC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8012EBF4;
    // 0x8012EBEC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8012EBF0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8012EBF4:
    // 0x8012EBF4: lwc1        $f12, 0x34($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8012EBF8: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8012EBFC: nop

    // 0x8012EC00: bc1fl       L_8012EC14
    if (!c1cs) {
        // 0x8012EC04: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8012EC14;
    }
    goto skip_1;
    // 0x8012EC04: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_1:
    // 0x8012EC08: b           L_8012EC14
    // 0x8012EC0C: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
        goto L_8012EC14;
    // 0x8012EC0C: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    // 0x8012EC10: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_8012EC14:
    // 0x8012EC14: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8012EC18: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8012EC1C: nop

    // 0x8012EC20: bc1fl       L_8012EC34
    if (!c1cs) {
        // 0x8012EC24: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8012EC34;
    }
    goto skip_2;
    // 0x8012EC24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x8012EC28: b           L_8012EC34
    // 0x8012EC2C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8012EC34;
    // 0x8012EC2C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8012EC30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8012EC34:
    // 0x8012EC34: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012EC38: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012EC3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012EC40: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8012EC44: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8012EC48: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012EC4C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8012EC50: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8012EC54: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8012EC58: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EC5C: addiu       $a3, $a3, -0x2C68
    ctx->r7 = ADD32(ctx->r7, -0X2C68);
    // 0x8012EC60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012EC64: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8012EC68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8012EC6C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EC70: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012EC74: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012EC78: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8012EC7C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012EC80: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8012EC84: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012EC88: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8012EC8C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x8012EC90: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012EC94: mfhi        $t9
    ctx->r25 = hi;
    // 0x8012EC98: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012EC9C: bne         $v0, $zero, L_8012ECA8
    if (ctx->r2 != 0) {
        // 0x8012ECA0: nop
    
            goto L_8012ECA8;
    }
    // 0x8012ECA0: nop

    // 0x8012ECA4: break       7
    do_break(2148723876);
L_8012ECA8:
    // 0x8012ECA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012ECAC: bne         $v0, $at, L_8012ECC0
    if (ctx->r2 != ctx->r1) {
        // 0x8012ECB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012ECC0;
    }
    // 0x8012ECB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012ECB4: bne         $t8, $at, L_8012ECC0
    if (ctx->r24 != ctx->r1) {
        // 0x8012ECB8: nop
    
            goto L_8012ECC0;
    }
    // 0x8012ECB8: nop

    // 0x8012ECBC: break       6
    do_break(2148723900);
L_8012ECC0:
    // 0x8012ECC0: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8012ECC4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012ECC8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012ECCC: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x8012ECD0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8012ECD4: mfhi        $t6
    ctx->r14 = hi;
    // 0x8012ECD8: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8012ECDC: bne         $v0, $zero, L_8012ECE8
    if (ctx->r2 != 0) {
        // 0x8012ECE0: nop
    
            goto L_8012ECE8;
    }
    // 0x8012ECE0: nop

    // 0x8012ECE4: break       7
    do_break(2148723940);
L_8012ECE8:
    // 0x8012ECE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012ECEC: bne         $v0, $at, L_8012ED00
    if (ctx->r2 != ctx->r1) {
        // 0x8012ECF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012ED00;
    }
    // 0x8012ECF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012ECF4: bne         $t5, $at, L_8012ED00
    if (ctx->r13 != ctx->r1) {
        // 0x8012ECF8: nop
    
            goto L_8012ED00;
    }
    // 0x8012ECF8: nop

    // 0x8012ECFC: break       6
    do_break(2148723964);
L_8012ED00:
    // 0x8012ED00: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x8012ED04: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8012ED08: mfhi        $t3
    ctx->r11 = hi;
    // 0x8012ED0C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8012ED10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8012ED14: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8012ED18: bne         $v0, $zero, L_8012ED24
    if (ctx->r2 != 0) {
        // 0x8012ED1C: nop
    
            goto L_8012ED24;
    }
    // 0x8012ED1C: nop

    // 0x8012ED20: break       7
    do_break(2148724000);
L_8012ED24:
    // 0x8012ED24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012ED28: bne         $v0, $at, L_8012ED3C
    if (ctx->r2 != ctx->r1) {
        // 0x8012ED2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012ED3C;
    }
    // 0x8012ED2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012ED30: bne         $t2, $at, L_8012ED3C
    if (ctx->r10 != ctx->r1) {
        // 0x8012ED34: nop
    
            goto L_8012ED3C;
    }
    // 0x8012ED34: nop

    // 0x8012ED38: break       6
    do_break(2148724024);
L_8012ED3C:
    // 0x8012ED3C: jal         0x8001DFFC
    // 0x8012ED40: nop

    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_7;
    // 0x8012ED40: nop

    after_7:
    // 0x8012ED44: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012ED48: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x8012ED4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012ED50: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8012ED54: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8012ED58: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012ED5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012ED60: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8012ED64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8012ED68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8012ED6C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8012ED70: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8012ED74: bc1fl       L_8012ED8C
    if (!c1cs) {
        // 0x8012ED78: swc1        $f18, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
            goto L_8012ED8C;
    }
    goto skip_3;
    // 0x8012ED78: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    skip_3:
    // 0x8012ED7C: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8012ED80: b           L_8012ED8C
    // 0x8012ED84: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_8012ED8C;
    // 0x8012ED84: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x8012ED88: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8012ED8C:
    // 0x8012ED8C: lwc1        $f12, 0x40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8012ED90: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8012ED94: nop

    // 0x8012ED98: bc1fl       L_8012EDAC
    if (!c1cs) {
        // 0x8012ED9C: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8012EDAC;
    }
    goto skip_4;
    // 0x8012ED9C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_4:
    // 0x8012EDA0: b           L_8012EDAC
    // 0x8012EDA4: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
        goto L_8012EDAC;
    // 0x8012EDA4: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    // 0x8012EDA8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_8012EDAC:
    // 0x8012EDAC: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8012EDB0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8012EDB4: nop

    // 0x8012EDB8: bc1fl       L_8012EDCC
    if (!c1cs) {
        // 0x8012EDBC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8012EDCC;
    }
    goto skip_5;
    // 0x8012EDBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
    // 0x8012EDC0: b           L_8012EDCC
    // 0x8012EDC4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8012EDCC;
    // 0x8012EDC4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8012EDC8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8012EDCC:
    // 0x8012EDCC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012EDD0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8012EDD4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8012EDD8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012EDDC: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8012EDE0: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012EDE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012EDE8: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8012EDEC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8012EDF0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EDF4: addiu       $a3, $a3, -0x2C50
    ctx->r7 = ADD32(ctx->r7, -0X2C50);
    // 0x8012EDF8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012EDFC: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8012EE00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8012EE04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EE08: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8012EE0C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012EE10: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8012EE14: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012EE18: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8012EE1C: nop

    // 0x8012EE20: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x8012EE24: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8012EE28: mfhi        $t9
    ctx->r25 = hi;
    // 0x8012EE2C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012EE30: bne         $v0, $zero, L_8012EE3C
    if (ctx->r2 != 0) {
        // 0x8012EE34: nop
    
            goto L_8012EE3C;
    }
    // 0x8012EE34: nop

    // 0x8012EE38: break       7
    do_break(2148724280);
L_8012EE3C:
    // 0x8012EE3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012EE40: bne         $v0, $at, L_8012EE54
    if (ctx->r2 != ctx->r1) {
        // 0x8012EE44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012EE54;
    }
    // 0x8012EE44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012EE48: bne         $t8, $at, L_8012EE54
    if (ctx->r24 != ctx->r1) {
        // 0x8012EE4C: nop
    
            goto L_8012EE54;
    }
    // 0x8012EE4C: nop

    // 0x8012EE50: break       6
    do_break(2148724304);
L_8012EE54:
    // 0x8012EE54: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8012EE58: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8012EE5C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8012EE60: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x8012EE64: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8012EE68: mfhi        $t6
    ctx->r14 = hi;
    // 0x8012EE6C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8012EE70: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012EE74: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x8012EE78: bne         $v0, $zero, L_8012EE84
    if (ctx->r2 != 0) {
        // 0x8012EE7C: nop
    
            goto L_8012EE84;
    }
    // 0x8012EE7C: nop

    // 0x8012EE80: break       7
    do_break(2148724352);
L_8012EE84:
    // 0x8012EE84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012EE88: bne         $v0, $at, L_8012EE9C
    if (ctx->r2 != ctx->r1) {
        // 0x8012EE8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012EE9C;
    }
    // 0x8012EE8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012EE90: bne         $t5, $at, L_8012EE9C
    if (ctx->r13 != ctx->r1) {
        // 0x8012EE94: nop
    
            goto L_8012EE9C;
    }
    // 0x8012EE94: nop

    // 0x8012EE98: break       6
    do_break(2148724376);
L_8012EE9C:
    // 0x8012EE9C: mfhi        $t3
    ctx->r11 = hi;
    // 0x8012EEA0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8012EEA4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8012EEA8: bne         $v0, $zero, L_8012EEB4
    if (ctx->r2 != 0) {
        // 0x8012EEAC: nop
    
            goto L_8012EEB4;
    }
    // 0x8012EEAC: nop

    // 0x8012EEB0: break       7
    do_break(2148724400);
L_8012EEB4:
    // 0x8012EEB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012EEB8: bne         $v0, $at, L_8012EECC
    if (ctx->r2 != ctx->r1) {
        // 0x8012EEBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012EECC;
    }
    // 0x8012EEBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012EEC0: bne         $t2, $at, L_8012EECC
    if (ctx->r10 != ctx->r1) {
        // 0x8012EEC4: nop
    
            goto L_8012EECC;
    }
    // 0x8012EEC4: nop

    // 0x8012EEC8: break       6
    do_break(2148724424);
L_8012EECC:
    // 0x8012EECC: jal         0x8001DFFC
    // 0x8012EED0: nop

    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_8;
    // 0x8012EED0: nop

    after_8:
    // 0x8012EED4: addiu       $a0, $sp, 0x66
    ctx->r4 = ADD32(ctx->r29, 0X66);
    // 0x8012EED8: jal         0x80119F9C
    // 0x8012EEDC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_9;
    // 0x8012EEDC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_9:
    // 0x8012EEE0: jal         0x8011A0F0
    // 0x8012EEE4: addiu       $a0, $sp, 0x62
    ctx->r4 = ADD32(ctx->r29, 0X62);
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_10;
    // 0x8012EEE4: addiu       $a0, $sp, 0x62
    ctx->r4 = ADD32(ctx->r29, 0X62);
    after_10:
    // 0x8012EEE8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012EEEC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012EEF0: lw          $t4, 0xE0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XE0);
    // 0x8012EEF4: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x8012EEF8: lh          $t8, 0x66($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X66);
    // 0x8012EEFC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8012EF00: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x8012EF04: subu        $t1, $t7, $t6
    ctx->r9 = SUB32(ctx->r15, ctx->r14);
    // 0x8012EF08: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8012EF0C: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8012EF10: andi        $t1, $t1, 0x1FFF
    ctx->r9 = ctx->r9 & 0X1FFF;
    // 0x8012EF14: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8012EF18: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8012EF1C: subu        $v0, $t1, $t8
    ctx->r2 = SUB32(ctx->r9, ctx->r24);
    // 0x8012EF20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8012EF24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8012EF28: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x8012EF2C: beq         $t9, $zero, L_8012EF44
    if (ctx->r25 == 0) {
        // 0x8012EF30: andi        $t0, $v0, 0x1FFF
        ctx->r8 = ctx->r2 & 0X1FFF;
            goto L_8012EF44;
    }
    // 0x8012EF30: andi        $t0, $v0, 0x1FFF
    ctx->r8 = ctx->r2 & 0X1FFF;
    // 0x8012EF34: addiu       $t0, $t0, -0x2000
    ctx->r8 = ADD32(ctx->r8, -0X2000);
    // 0x8012EF38: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8012EF3C: b           L_8012EF50
    // 0x8012EF40: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8012EF50;
    // 0x8012EF40: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8012EF44:
    // 0x8012EF44: andi        $t0, $v0, 0x1FFF
    ctx->r8 = ctx->r2 & 0X1FFF;
    // 0x8012EF48: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8012EF4C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8012EF50:
    // 0x8012EF50: lw          $t2, 0xE8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XE8);
    // 0x8012EF54: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x8012EF58: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8012EF5C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8012EF60: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8012EF64: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8012EF68: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012EF6C: sh          $t1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r9;
    // 0x8012EF70: sh          $t0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r8;
    // 0x8012EF74: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012EF78: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8012EF7C: nop

    // 0x8012EF80: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012EF84: jal         0x8002FC20
    // 0x8012EF88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_11;
    // 0x8012EF88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_11:
    // 0x8012EF8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8012EF90: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x8012EF94: lw          $t3, 0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XE8);
    // 0x8012EF98: lw          $t4, 0xE0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE0);
    // 0x8012EF9C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8012EFA0: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8012EFA4: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8012EFA8: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8012EFAC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012EFB0: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8012EFB4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012EFB8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012EFBC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012EFC0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012EFC4: nop

    // 0x8012EFC8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012EFCC: jal         0x8002FC20
    // 0x8012EFD0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_12;
    // 0x8012EFD0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_12:
    // 0x8012EFD4: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8012EFD8: lh          $t1, 0x60($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X60);
    // 0x8012EFDC: lh          $t5, 0x66($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X66);
    // 0x8012EFE0: lh          $t7, 0x64($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X64);
    // 0x8012EFE4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012EFE8: addiu       $a3, $a3, -0x2C38
    ctx->r7 = ADD32(ctx->r7, -0X2C38);
    // 0x8012EFEC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8012EFF0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012EFF4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8012EFF8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8012EFFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8012F000: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8012F004: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8012F008: jal         0x8001DFFC
    // 0x8012F00C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_13;
    // 0x8012F00C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_13:
    // 0x8012F010: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8012F014: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8012F018: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012F01C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012F020: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012F024: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8012F028: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012F02C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8012F030: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8012F034: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012F038: addiu       $a3, $a3, -0x2C20
    ctx->r7 = ADD32(ctx->r7, -0X2C20);
    // 0x8012F03C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8012F040: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8012F044: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8012F048: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8012F04C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012F050: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8012F054: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8012F058: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8012F05C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012F060: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8012F064: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8012F068: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8012F06C: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x8012F070: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8012F074: mfhi        $t3
    ctx->r11 = hi;
    // 0x8012F078: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8012F07C: bne         $v0, $zero, L_8012F088
    if (ctx->r2 != 0) {
        // 0x8012F080: nop
    
            goto L_8012F088;
    }
    // 0x8012F080: nop

    // 0x8012F084: break       7
    do_break(2148724868);
L_8012F088:
    // 0x8012F088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012F08C: bne         $v0, $at, L_8012F0A0
    if (ctx->r2 != ctx->r1) {
        // 0x8012F090: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012F0A0;
    }
    // 0x8012F090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012F094: bne         $t2, $at, L_8012F0A0
    if (ctx->r10 != ctx->r1) {
        // 0x8012F098: nop
    
            goto L_8012F0A0;
    }
    // 0x8012F098: nop

    // 0x8012F09C: break       6
    do_break(2148724892);
L_8012F0A0:
    // 0x8012F0A0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8012F0A4: nop

    // 0x8012F0A8: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x8012F0AC: mfhi        $t8
    ctx->r24 = hi;
    // 0x8012F0B0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8012F0B4: bne         $v0, $zero, L_8012F0C0
    if (ctx->r2 != 0) {
        // 0x8012F0B8: nop
    
            goto L_8012F0C0;
    }
    // 0x8012F0B8: nop

    // 0x8012F0BC: break       7
    do_break(2148724924);
L_8012F0C0:
    // 0x8012F0C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012F0C4: bne         $v0, $at, L_8012F0D8
    if (ctx->r2 != ctx->r1) {
        // 0x8012F0C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8012F0D8;
    }
    // 0x8012F0C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012F0CC: bne         $t6, $at, L_8012F0D8
    if (ctx->r14 != ctx->r1) {
        // 0x8012F0D0: nop
    
            goto L_8012F0D8;
    }
    // 0x8012F0D0: nop

    // 0x8012F0D4: break       6
    do_break(2148724948);
L_8012F0D8:
    // 0x8012F0D8: jal         0x8001DFFC
    // 0x8012F0DC: nop

    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_14;
    // 0x8012F0DC: nop

    after_14:
    // 0x8012F0E0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8012F0E4: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x8012F0E8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8012F0EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8012F0F0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8012F0F4: lh          $t8, 0x62($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X62);
    // 0x8012F0F8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012F0FC: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8012F100: addiu       $a3, $a3, -0x2C04
    ctx->r7 = ADD32(ctx->r7, -0X2C04);
    // 0x8012F104: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8012F108: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8012F10C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012F110: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8012F114: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8012F118: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8012F11C: nop

    // 0x8012F120: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8012F124: lwc1        $f6, 0x4C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8012F128: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8012F12C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8012F130: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8012F134: nop

    // 0x8012F138: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8012F13C: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8012F140: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8012F144: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8012F148: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8012F14C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8012F150: jal         0x8001DFFC
    // 0x8012F154: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_15;
    // 0x8012F154: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_15:
    // 0x8012F158: jal         0x80108280
    // 0x8012F15C: nop

    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_16;
    // 0x8012F15C: nop

    after_16:
    // 0x8012F160: jal         0x80108280
    // 0x8012F164: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80108280)(rdram, ctx);
        goto after_17;
    // 0x8012F164: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    after_17:
    // 0x8012F168: lhu         $t9, 0x40($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X40);
    // 0x8012F16C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012F170: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8012F174: sra         $t2, $t9, 8
    ctx->r10 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8012F178: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8012F17C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8012F180: addiu       $a3, $a3, -0x2BF0
    ctx->r7 = ADD32(ctx->r7, -0X2BF0);
    // 0x8012F184: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8012F188: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012F18C: jal         0x8001DFFC
    // 0x8012F190: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_18;
    // 0x8012F190: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_18:
    // 0x8012F194: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012F198: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x8012F19C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012F1A0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8012F1A4: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8012F1A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8012F1AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012F1B0: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012F1B4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8012F1B8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8012F1BC: bc1fl       L_8012F1D4
    if (!c1cs) {
        // 0x8012F1C0: swc1        $f18, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
            goto L_8012F1D4;
    }
    goto skip_6;
    // 0x8012F1C0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    skip_6:
    // 0x8012F1C4: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8012F1C8: b           L_8012F1D4
    // 0x8012F1CC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_8012F1D4;
    // 0x8012F1CC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8012F1D0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8012F1D4:
    // 0x8012F1D4: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012F1D8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8012F1DC: nop

    // 0x8012F1E0: bc1fl       L_8012F1F4
    if (!c1cs) {
        // 0x8012F1E4: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8012F1F4;
    }
    goto skip_7;
    // 0x8012F1E4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_7:
    // 0x8012F1E8: b           L_8012F1F4
    // 0x8012F1EC: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
        goto L_8012F1F4;
    // 0x8012F1EC: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    // 0x8012F1F0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_8012F1F4:
    // 0x8012F1F4: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012F1F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8012F1FC: nop

    // 0x8012F200: bc1fl       L_8012F214
    if (!c1cs) {
        // 0x8012F204: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8012F214;
    }
    goto skip_8;
    // 0x8012F204: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_8:
    // 0x8012F208: b           L_8012F214
    // 0x8012F20C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8012F214;
    // 0x8012F20C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8012F210: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8012F214:
    // 0x8012F214: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012F218: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8012F21C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8012F220: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8012F224: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012F228: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012F22C: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8012F230: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8012F234: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012F238: addiu       $a3, $a3, -0x2BDC
    ctx->r7 = ADD32(ctx->r7, -0X2BDC);
    // 0x8012F23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8012F240: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8012F244: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8012F248: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012F24C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012F250: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012F254: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012F258: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8012F25C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8012F260: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8012F264: nop

    // 0x8012F268: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8012F26C: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012F270: mfhi        $t9
    ctx->r25 = hi;
    // 0x8012F274: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8012F278: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8012F27C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8012F280: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012F284: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8012F288: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8012F28C: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012F290: mfhi        $t7
    ctx->r15 = hi;
    // 0x8012F294: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8012F298: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8012F29C: nop

    // 0x8012F2A0: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8012F2A4: mfhi        $t3
    ctx->r11 = hi;
    // 0x8012F2A8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8012F2AC: jal         0x8001DFFC
    // 0x8012F2B0: nop

    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_19;
    // 0x8012F2B0: nop

    after_19:
    // 0x8012F2B4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012F2B8: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x8012F2BC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8012F2C0: addiu       $a3, $a3, -0x2BC4
    ctx->r7 = ADD32(ctx->r7, -0X2BC4);
    // 0x8012F2C4: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8012F2C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8012F2CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8012F2D0: lh          $t5, 0x10($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X10);
    // 0x8012F2D4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8012F2D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8012F2DC: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
    // 0x8012F2E0: andi        $t6, $t7, 0x1FFF
    ctx->r14 = ctx->r15 & 0X1FFF;
    // 0x8012F2E4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8012F2E8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8012F2EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8012F2F0: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8012F2F4: jal         0x8001DFFC
    // 0x8012F2F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_20;
    // 0x8012F2F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_20:
L_8012F2FC:
    // 0x8012F2FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8012F300: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8012F304: jr          $ra
    // 0x8012F308: nop

    return;
    // 0x8012F308: nop

;}
RECOMP_FUNC void M7_FUN_8012f30c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012F30C: lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X35);
    // 0x8012F310: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012F314: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012F318: beql        $v0, $zero, L_8012F338
    if (ctx->r2 == 0) {
        // 0x8012F31C: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8012F338;
    }
    goto skip_0;
    // 0x8012F31C: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8012F320: lbu         $t6, 0x108($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X108);
    // 0x8012F324: bnel        $t6, $v0, L_8012F338
    if (ctx->r14 != ctx->r2) {
        // 0x8012F328: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8012F338;
    }
    goto skip_1;
    // 0x8012F328: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x8012F32C: jr          $ra
    // 0x8012F330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012F330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8012F334: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_8012F338:
    // 0x8012F338: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012F33C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012F340: beql        $a0, $zero, L_8012F380
    if (ctx->r4 == 0) {
        // 0x8012F344: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012F380;
    }
    goto skip_2;
    // 0x8012F344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8012F348: beql        $a0, $zero, L_8012F380
    if (ctx->r4 == 0) {
        // 0x8012F34C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012F380;
    }
    goto skip_3;
    // 0x8012F34C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8012F350: lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X35);
L_8012F354:
    // 0x8012F354: beql        $v0, $zero, L_8012F374
    if (ctx->r2 == 0) {
        // 0x8012F358: lw          $a0, 0x0($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X0);
            goto L_8012F374;
    }
    goto skip_4;
    // 0x8012F358: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    skip_4:
    // 0x8012F35C: lbu         $t7, 0x108($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X108);
    // 0x8012F360: bnel        $t7, $v0, L_8012F374
    if (ctx->r15 != ctx->r2) {
        // 0x8012F364: lw          $a0, 0x0($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X0);
            goto L_8012F374;
    }
    goto skip_5;
    // 0x8012F364: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x8012F368: jr          $ra
    // 0x8012F36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012F36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8012F370: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_8012F374:
    // 0x8012F374: bnel        $a0, $zero, L_8012F354
    if (ctx->r4 != 0) {
        // 0x8012F378: lbu         $v0, 0x35($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X35);
            goto L_8012F354;
    }
    goto skip_6;
    // 0x8012F378: lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X35);
    skip_6:
    // 0x8012F37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012F380:
    // 0x8012F380: jr          $ra
    // 0x8012F384: nop

    return;
    // 0x8012F384: nop

;}
RECOMP_FUNC void M7_FUN_8012f388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012F388: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012F38C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012F390: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8012F394: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8012F398: lbu         $v0, 0x108($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X108);
    // 0x8012F39C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8012F3A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8012F3A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8012F3A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012F3AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8012F3B0: addu        $t6, $v0, $s2
    ctx->r14 = ADD32(ctx->r2, ctx->r18);
L_8012F3B4:
    // 0x8012F3B4: sb          $t6, 0x108($s0)
    MEM_B(0X108, ctx->r16) = ctx->r14;
    // 0x8012F3B8: jal         0x8012F30C
    // 0x8012F3BC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    LOOKUP_FUNC(0x8012F30C)(rdram, ctx);
        goto after_0;
    // 0x8012F3BC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    after_0:
    // 0x8012F3C0: bnel        $v0, $zero, L_8012F408
    if (ctx->r2 != 0) {
        // 0x8012F3C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8012F408;
    }
    goto skip_0;
    // 0x8012F3C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8012F3C8: jal         0x8012F30C
    // 0x8012F3CC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    LOOKUP_FUNC(0x8012F30C)(rdram, ctx);
        goto after_1;
    // 0x8012F3CC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    after_1:
    // 0x8012F3D0: bnel        $v0, $zero, L_8012F408
    if (ctx->r2 != 0) {
        // 0x8012F3D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8012F408;
    }
    goto skip_1;
    // 0x8012F3D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8012F3D8: jal         0x8012F30C
    // 0x8012F3DC: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    LOOKUP_FUNC(0x8012F30C)(rdram, ctx);
        goto after_2;
    // 0x8012F3DC: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    after_2:
    // 0x8012F3E0: bnel        $v0, $zero, L_8012F408
    if (ctx->r2 != 0) {
        // 0x8012F3E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8012F408;
    }
    goto skip_2;
    // 0x8012F3E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8012F3E8: jal         0x8012F30C
    // 0x8012F3EC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    LOOKUP_FUNC(0x8012F30C)(rdram, ctx);
        goto after_3;
    // 0x8012F3EC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_3:
    // 0x8012F3F0: bnel        $v0, $zero, L_8012F408
    if (ctx->r2 != 0) {
        // 0x8012F3F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8012F408;
    }
    goto skip_3;
    // 0x8012F3F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8012F3F8: lbu         $v0, 0x108($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X108);
    // 0x8012F3FC: bnel        $v0, $s1, L_8012F3B4
    if (ctx->r2 != ctx->r17) {
        // 0x8012F400: addu        $t6, $v0, $s2
        ctx->r14 = ADD32(ctx->r2, ctx->r18);
            goto L_8012F3B4;
    }
    goto skip_4;
    // 0x8012F400: addu        $t6, $v0, $s2
    ctx->r14 = ADD32(ctx->r2, ctx->r18);
    skip_4:
    // 0x8012F404: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8012F408:
    // 0x8012F408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8012F40C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8012F410: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8012F414: jr          $ra
    // 0x8012F418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8012F418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012f41c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012f41c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012F41C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8012F420: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8012F424: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8012F428: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8012F42C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8012F430: ori         $t6, $t6, 0x600
    ctx->r14 = ctx->r14 | 0X600;
    // 0x8012F434: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x8012F438: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8012F43C: addiu       $t8, $t8, -0x4B60
    ctx->r24 = ADD32(ctx->r24, -0X4B60);
    // 0x8012F440: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x8012F444: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8012F448: sw          $t7, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r15;
    // 0x8012F44C: sw          $t8, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r24;
    // 0x8012F450: sw          $t9, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->r25;
    // 0x8012F454: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x8012F458: lbu         $t9, 0x13($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X13);
    // 0x8012F45C: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8012F460: sll         $t1, $a1, 24
    ctx->r9 = S32(ctx->r5 << 24);
    // 0x8012F464: andi        $t5, $a3, 0xFF
    ctx->r13 = ctx->r7 & 0XFF;
    // 0x8012F468: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8012F46C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8012F470: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8012F474: lui         $t2, 0xDF00
    ctx->r10 = S32(0XDF00 << 16);
    // 0x8012F478: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8012F47C: sw          $t0, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->r8;
    // 0x8012F480: sw          $t2, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r10;
    // 0x8012F484: sw          $zero, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = 0;
    // 0x8012F488: jr          $ra
    // 0x8012F48C: addiu       $v0, $a0, 0x9C
    ctx->r2 = ADD32(ctx->r4, 0X9C);
    return;
    // 0x8012F48C: addiu       $v0, $a0, 0x9C
    ctx->r2 = ADD32(ctx->r4, 0X9C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012f490(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012f490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012F490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012F494: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012F498: beq         $a1, $zero, L_8012F4B4
    if (ctx->r5 == 0) {
        // 0x8012F49C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8012F4B4;
    }
    // 0x8012F49C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8012F4A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012F4A4: beq         $a1, $at, L_8012F69C
    if (ctx->r5 == ctx->r1) {
        // 0x8012F4A8: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_8012F69C;
    }
    // 0x8012F4A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8012F4AC: b           L_8012F86C
    // 0x8012F4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012F86C;
    // 0x8012F4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012F4B4:
    // 0x8012F4B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8012F4B8: addiu       $t6, $t6, -0x73F0
    ctx->r14 = ADD32(ctx->r14, -0X73F0);
    // 0x8012F4BC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8012F4C0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8012F4C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F4C8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8012F4CC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8012F4D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F4D4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8012F4D8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8012F4DC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F4E0: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8012F4E4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8012F4E8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F4EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012F4F0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8012F4F4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012F4F8: jal         0x8012C4D0
    // 0x8012F4FC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8012F4FC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8012F500: beq         $v0, $zero, L_8012F514
    if (ctx->r2 == 0) {
        // 0x8012F504: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_8012F514;
    }
    // 0x8012F504: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8012F508: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8012F50C: sh          $t0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r8;
    // 0x8012F510: sh          $zero, 0x98($v0)
    MEM_H(0X98, ctx->r2) = 0;
L_8012F514:
    // 0x8012F514: addiu       $t1, $t1, -0x73F0
    ctx->r9 = ADD32(ctx->r9, -0X73F0);
    // 0x8012F518: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8012F51C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8012F520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F524: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8012F528: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8012F52C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F530: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8012F534: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8012F538: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F53C: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8012F540: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8012F544: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F548: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8012F54C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8012F550: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8012F554: jal         0x8012C4D0
    // 0x8012F558: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x8012F558: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x8012F55C: beq         $v0, $zero, L_8012F574
    if (ctx->r2 == 0) {
        // 0x8012F560: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8012F574;
    }
    // 0x8012F560: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8012F564: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8012F568: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8012F56C: sh          $t5, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r13;
    // 0x8012F570: sh          $t6, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r14;
L_8012F574:
    // 0x8012F574: addiu       $t7, $t7, -0x73F0
    ctx->r15 = ADD32(ctx->r15, -0X73F0);
    // 0x8012F578: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012F57C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8012F580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F584: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8012F588: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8012F58C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F590: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8012F594: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8012F598: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F59C: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8012F5A0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8012F5A4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F5A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012F5AC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8012F5B0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8012F5B4: jal         0x8012C4D0
    // 0x8012F5B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_2;
    // 0x8012F5B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x8012F5BC: beq         $v0, $zero, L_8012F5D4
    if (ctx->r2 == 0) {
        // 0x8012F5C0: lui         $t3, 0x8018
        ctx->r11 = S32(0X8018 << 16);
            goto L_8012F5D4;
    }
    // 0x8012F5C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8012F5C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8012F5C8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8012F5CC: sh          $t1, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r9;
    // 0x8012F5D0: sh          $t2, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r10;
L_8012F5D4:
    // 0x8012F5D4: addiu       $t3, $t3, -0x73F0
    ctx->r11 = ADD32(ctx->r11, -0X73F0);
    // 0x8012F5D8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8012F5DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8012F5E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F5E4: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8012F5E8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8012F5EC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F5F0: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8012F5F4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8012F5F8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F5FC: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8012F600: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8012F604: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F608: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8012F60C: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x8012F610: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8012F614: jal         0x8012C4D0
    // 0x8012F618: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_3;
    // 0x8012F618: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8012F61C: beq         $v0, $zero, L_8012F634
    if (ctx->r2 == 0) {
        // 0x8012F620: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8012F634;
    }
    // 0x8012F620: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8012F624: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8012F628: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8012F62C: sh          $t7, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r15;
    // 0x8012F630: sh          $t8, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r24;
L_8012F634:
    // 0x8012F634: addiu       $t9, $t9, -0x73F0
    ctx->r25 = ADD32(ctx->r25, -0X73F0);
    // 0x8012F638: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8012F63C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8012F640: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F644: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8012F648: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8012F64C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F650: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8012F654: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8012F658: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F65C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8012F660: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8012F664: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F668: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8012F66C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8012F670: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8012F674: jal         0x8012C4D0
    // 0x8012F678: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_4;
    // 0x8012F678: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_4:
    // 0x8012F67C: beq         $v0, $zero, L_8012F694
    if (ctx->r2 == 0) {
        // 0x8012F680: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012F694;
    }
    // 0x8012F680: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012F684: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8012F688: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8012F68C: sh          $t3, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r11;
    // 0x8012F690: sh          $t4, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r12;
L_8012F694:
    // 0x8012F694: b           L_8012F86C
    // 0x8012F698: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012F86C;
    // 0x8012F698: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012F69C:
    // 0x8012F69C: addiu       $t5, $t5, -0x73F0
    ctx->r13 = ADD32(ctx->r13, -0X73F0);
    // 0x8012F6A0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012F6A4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8012F6A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F6AC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8012F6B0: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012F6B4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F6B8: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8012F6BC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012F6C0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F6C4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8012F6C8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012F6CC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F6D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012F6D4: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012F6D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012F6DC: jal         0x8012C4D0
    // 0x8012F6E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_5;
    // 0x8012F6E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_5:
    // 0x8012F6E4: beq         $v0, $zero, L_8012F6F4
    if (ctx->r2 == 0) {
        // 0x8012F6E8: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8012F6F4;
    }
    // 0x8012F6E8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8012F6EC: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x8012F6F0: sh          $zero, 0x98($v0)
    MEM_H(0X98, ctx->r2) = 0;
L_8012F6F4:
    // 0x8012F6F4: addiu       $t9, $t9, -0x73F0
    ctx->r25 = ADD32(ctx->r25, -0X73F0);
    // 0x8012F6F8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8012F6FC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8012F700: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F704: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8012F708: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8012F70C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F710: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8012F714: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8012F718: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F71C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8012F720: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8012F724: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F728: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8012F72C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8012F730: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8012F734: jal         0x8012C4D0
    // 0x8012F738: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_6;
    // 0x8012F738: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_6:
    // 0x8012F73C: beq         $v0, $zero, L_8012F750
    if (ctx->r2 == 0) {
        // 0x8012F740: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8012F750;
    }
    // 0x8012F740: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8012F744: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8012F748: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x8012F74C: sh          $t3, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r11;
L_8012F750:
    // 0x8012F750: addiu       $t4, $t4, -0x73F0
    ctx->r12 = ADD32(ctx->r12, -0X73F0);
    // 0x8012F754: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8012F758: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8012F75C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F760: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8012F764: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8012F768: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F76C: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8012F770: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8012F774: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F778: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8012F77C: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8012F780: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F784: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8012F788: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8012F78C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8012F790: jal         0x8012C4D0
    // 0x8012F794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_7;
    // 0x8012F794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_7:
    // 0x8012F798: beq         $v0, $zero, L_8012F7AC
    if (ctx->r2 == 0) {
        // 0x8012F79C: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8012F7AC;
    }
    // 0x8012F79C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8012F7A0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8012F7A4: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x8012F7A8: sh          $t8, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r24;
L_8012F7AC:
    // 0x8012F7AC: addiu       $t9, $t9, -0x73F0
    ctx->r25 = ADD32(ctx->r25, -0X73F0);
    // 0x8012F7B0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8012F7B4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8012F7B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F7BC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8012F7C0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8012F7C4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F7C8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8012F7CC: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8012F7D0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F7D4: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8012F7D8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8012F7DC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F7E0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8012F7E4: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8012F7E8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8012F7EC: jal         0x8012C4D0
    // 0x8012F7F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_8;
    // 0x8012F7F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_8:
    // 0x8012F7F4: beq         $v0, $zero, L_8012F808
    if (ctx->r2 == 0) {
        // 0x8012F7F8: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8012F808;
    }
    // 0x8012F7F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8012F7FC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8012F800: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x8012F804: sh          $t3, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r11;
L_8012F808:
    // 0x8012F808: addiu       $t4, $t4, -0x73F0
    ctx->r12 = ADD32(ctx->r12, -0X73F0);
    // 0x8012F80C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8012F810: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8012F814: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F818: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8012F81C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8012F820: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F824: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8012F828: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8012F82C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F830: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8012F834: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8012F838: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F83C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8012F840: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8012F844: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8012F848: jal         0x8012C4D0
    // 0x8012F84C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_9;
    // 0x8012F84C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_9:
    // 0x8012F850: beq         $v0, $zero, L_8012F864
    if (ctx->r2 == 0) {
        // 0x8012F854: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012F864;
    }
    // 0x8012F854: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012F858: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8012F85C: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x8012F860: sh          $t8, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r24;
L_8012F864:
    // 0x8012F864: b           L_8012F86C
    // 0x8012F868: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012F86C;
    // 0x8012F868: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012F86C:
    // 0x8012F86C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012F870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012F874: jr          $ra
    // 0x8012F878: nop

    return;
    // 0x8012F878: nop

;}
RECOMP_FUNC void M7_FUN_8012f87c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012F87C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012F880: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012F884: beq         $a1, $zero, L_8012F8A0
    if (ctx->r5 == 0) {
        // 0x8012F888: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8012F8A0;
    }
    // 0x8012F888: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8012F88C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012F890: beq         $a1, $at, L_8012F958
    if (ctx->r5 == ctx->r1) {
        // 0x8012F894: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_8012F958;
    }
    // 0x8012F894: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8012F898: b           L_8012FA10
    // 0x8012F89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FA10;
    // 0x8012F89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012F8A0:
    // 0x8012F8A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8012F8A4: addiu       $t6, $t6, -0x734C
    ctx->r14 = ADD32(ctx->r14, -0X734C);
    // 0x8012F8A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8012F8AC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8012F8B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F8B4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8012F8B8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8012F8BC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F8C0: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8012F8C4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8012F8C8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F8CC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8012F8D0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8012F8D4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F8D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012F8DC: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8012F8E0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012F8E4: jal         0x8012C4D0
    // 0x8012F8E8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8012F8E8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8012F8EC: beq         $v0, $zero, L_8012F8F8
    if (ctx->r2 == 0) {
        // 0x8012F8F0: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8012F8F8;
    }
    // 0x8012F8F0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8012F8F4: sb          $zero, 0x90($v0)
    MEM_B(0X90, ctx->r2) = 0;
L_8012F8F8:
    // 0x8012F8F8: addiu       $t0, $t0, -0x734C
    ctx->r8 = ADD32(ctx->r8, -0X734C);
    // 0x8012F8FC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8012F900: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8012F904: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F908: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8012F90C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8012F910: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F914: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8012F918: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8012F91C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F920: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8012F924: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8012F928: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F92C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8012F930: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8012F934: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012F938: jal         0x8012C4D0
    // 0x8012F93C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x8012F93C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x8012F940: beq         $v0, $zero, L_8012F950
    if (ctx->r2 == 0) {
        // 0x8012F944: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012F950;
    }
    // 0x8012F944: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012F948: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8012F94C: sb          $t4, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r12;
L_8012F950:
    // 0x8012F950: b           L_8012FA10
    // 0x8012F954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012FA10;
    // 0x8012F954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012F958:
    // 0x8012F958: addiu       $t5, $t5, -0x734C
    ctx->r13 = ADD32(ctx->r13, -0X734C);
    // 0x8012F95C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012F960: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8012F964: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F968: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8012F96C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012F970: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F974: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8012F978: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012F97C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F980: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8012F984: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012F988: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F98C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012F990: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012F994: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012F998: jal         0x8012C4D0
    // 0x8012F99C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_2;
    // 0x8012F99C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x8012F9A0: beq         $v0, $zero, L_8012F9B0
    if (ctx->r2 == 0) {
        // 0x8012F9A4: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8012F9B0;
    }
    // 0x8012F9A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8012F9A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8012F9AC: sb          $t9, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r25;
L_8012F9B0:
    // 0x8012F9B0: addiu       $t0, $t0, -0x734C
    ctx->r8 = ADD32(ctx->r8, -0X734C);
    // 0x8012F9B4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8012F9B8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8012F9BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012F9C0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8012F9C4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8012F9C8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012F9CC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8012F9D0: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8012F9D4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012F9D8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8012F9DC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8012F9E0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012F9E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8012F9E8: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8012F9EC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012F9F0: jal         0x8012C4D0
    // 0x8012F9F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_3;
    // 0x8012F9F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x8012F9F8: beq         $v0, $zero, L_8012FA08
    if (ctx->r2 == 0) {
        // 0x8012F9FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012FA08;
    }
    // 0x8012F9FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012FA00: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8012FA04: sb          $t4, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r12;
L_8012FA08:
    // 0x8012FA08: b           L_8012FA10
    // 0x8012FA0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012FA10;
    // 0x8012FA0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012FA10:
    // 0x8012FA10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012FA14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012FA18: jr          $ra
    // 0x8012FA1C: nop

    return;
    // 0x8012FA1C: nop

;}
RECOMP_FUNC void M7_FUN_8012fa20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FA20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012FA24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012FA28: beq         $a1, $zero, L_8012FA44
    if (ctx->r5 == 0) {
        // 0x8012FA2C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8012FA44;
    }
    // 0x8012FA2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8012FA30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012FA34: beq         $a1, $at, L_8012FAFC
    if (ctx->r5 == ctx->r1) {
        // 0x8012FA38: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_8012FAFC;
    }
    // 0x8012FA38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8012FA3C: b           L_8012FBB4
    // 0x8012FA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FBB4;
    // 0x8012FA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FA44:
    // 0x8012FA44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8012FA48: addiu       $t6, $t6, -0x7338
    ctx->r14 = ADD32(ctx->r14, -0X7338);
    // 0x8012FA4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8012FA50: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8012FA54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FA58: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8012FA5C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8012FA60: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012FA64: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8012FA68: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8012FA6C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012FA70: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8012FA74: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8012FA78: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012FA7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012FA80: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8012FA84: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012FA88: jal         0x8012C4D0
    // 0x8012FA8C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8012FA8C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8012FA90: beq         $v0, $zero, L_8012FA9C
    if (ctx->r2 == 0) {
        // 0x8012FA94: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8012FA9C;
    }
    // 0x8012FA94: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8012FA98: sb          $zero, 0x90($v0)
    MEM_B(0X90, ctx->r2) = 0;
L_8012FA9C:
    // 0x8012FA9C: addiu       $t0, $t0, -0x7338
    ctx->r8 = ADD32(ctx->r8, -0X7338);
    // 0x8012FAA0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8012FAA4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8012FAA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FAAC: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8012FAB0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8012FAB4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012FAB8: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8012FABC: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8012FAC0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012FAC4: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8012FAC8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8012FACC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012FAD0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8012FAD4: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8012FAD8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012FADC: jal         0x8012C4D0
    // 0x8012FAE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x8012FAE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x8012FAE4: beq         $v0, $zero, L_8012FAF4
    if (ctx->r2 == 0) {
        // 0x8012FAE8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012FAF4;
    }
    // 0x8012FAE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012FAEC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8012FAF0: sb          $t4, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r12;
L_8012FAF4:
    // 0x8012FAF4: b           L_8012FBB4
    // 0x8012FAF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012FBB4;
    // 0x8012FAF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012FAFC:
    // 0x8012FAFC: addiu       $t5, $t5, -0x7338
    ctx->r13 = ADD32(ctx->r13, -0X7338);
    // 0x8012FB00: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012FB04: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8012FB08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FB0C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8012FB10: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012FB14: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012FB18: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8012FB1C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012FB20: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012FB24: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8012FB28: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012FB2C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012FB30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012FB34: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012FB38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012FB3C: jal         0x8012C4D0
    // 0x8012FB40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_2;
    // 0x8012FB40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x8012FB44: beq         $v0, $zero, L_8012FB54
    if (ctx->r2 == 0) {
        // 0x8012FB48: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8012FB54;
    }
    // 0x8012FB48: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8012FB4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8012FB50: sb          $t9, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r25;
L_8012FB54:
    // 0x8012FB54: addiu       $t0, $t0, -0x7338
    ctx->r8 = ADD32(ctx->r8, -0X7338);
    // 0x8012FB58: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8012FB5C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8012FB60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FB64: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8012FB68: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8012FB6C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012FB70: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8012FB74: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8012FB78: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012FB7C: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8012FB80: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8012FB84: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012FB88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8012FB8C: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8012FB90: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8012FB94: jal         0x8012C4D0
    // 0x8012FB98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_3;
    // 0x8012FB98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x8012FB9C: beq         $v0, $zero, L_8012FBAC
    if (ctx->r2 == 0) {
        // 0x8012FBA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8012FBAC;
    }
    // 0x8012FBA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8012FBA4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8012FBA8: sb          $t4, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r12;
L_8012FBAC:
    // 0x8012FBAC: b           L_8012FBB4
    // 0x8012FBB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8012FBB4;
    // 0x8012FBB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8012FBB4:
    // 0x8012FBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012FBB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012FBBC: jr          $ra
    // 0x8012FBC0: nop

    return;
    // 0x8012FBC0: nop

;}
RECOMP_FUNC void M7_FUN_8012fbc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FBC4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012FBC8: lbu         $t6, -0x42AB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012fbcc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012fbcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FBCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012FBD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012FBD4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8012FBD8: beq         $at, $zero, L_8012FD04
    if (ctx->r1 == 0) {
        // 0x8012FBDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8012FD04;
    }
    // 0x8012FBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012FBE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8012FBE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012FBE8: addu        $at, $at, $t6
    gpr jr_addend_8012FBF0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8012FBEC: lw          $t6, -0x2A58($at)
    ctx->r14 = ADD32(ctx->r1, -0X2A58);
    // 0x8012FBF0: jr          $t6
    // 0x8012FBF4: nop

    switch (jr_addend_8012FBF0 >> 2) {
        case 0: goto L_8012FBF8; break;
        case 1: goto L_8012FC08; break;
        case 2: goto L_8012FC58; break;
        case 3: goto L_8012FCA8; break;
        case 4: goto L_8012FCC0; break;
        case 5: goto L_8012FCD8; break;
        case 6: goto L_8012FCF0; break;
        default: switch_error(__func__, 0x8012FBF0, 0x8018D5A8);
    }
    // 0x8012FBF4: nop

L_8012FBF8:
    // 0x8012FBF8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FBFC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FC00: b           L_8012FD0C
    // 0x8012FC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FD0C;
    // 0x8012FC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FC08:
    // 0x8012FC08: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8012FC0C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FC10: sh          $t7, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r15;
    // 0x8012FC14: jal         0x8001EAA4
    // 0x8012FC18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAA4)(rdram, ctx);
        goto after_0;
    // 0x8012FC18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012FC1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012FC20: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8012FC24: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8012FC28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FC2C: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x8012FC30: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012FC34: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012FC38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8012FC3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8012FC40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8012FC44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8012FC48: jal         0x8001E978
    // 0x8012FC4C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_1;
    // 0x8012FC4C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x8012FC50: b           L_8012FD0C
    // 0x8012FC54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FD0C;
    // 0x8012FC54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FC58:
    // 0x8012FC58: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8012FC5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FC60: sh          $t0, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r8;
    // 0x8012FC64: jal         0x8001EAA4
    // 0x8012FC68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAA4)(rdram, ctx);
        goto after_2;
    // 0x8012FC68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x8012FC6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012FC70: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8012FC74: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8012FC78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012FC7C: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x8012FC80: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8012FC84: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8012FC88: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8012FC8C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8012FC90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8012FC94: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8012FC98: jal         0x8001E978
    // 0x8012FC9C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_3;
    // 0x8012FC9C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_3:
    // 0x8012FCA0: b           L_8012FD0C
    // 0x8012FCA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FD0C;
    // 0x8012FCA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FCA8:
    // 0x8012FCA8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FCAC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FCB0: jal         0x8012F490
    // 0x8012FCB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012F490)(rdram, ctx);
        goto after_4;
    // 0x8012FCB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8012FCB8: b           L_8012FD0C
    // 0x8012FCBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FD0C;
    // 0x8012FCBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FCC0:
    // 0x8012FCC0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FCC4: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FCC8: jal         0x8012F87C
    // 0x8012FCCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012F87C)(rdram, ctx);
        goto after_5;
    // 0x8012FCCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8012FCD0: b           L_8012FD0C
    // 0x8012FCD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FD0C;
    // 0x8012FCD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FCD8:
    // 0x8012FCD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FCDC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FCE0: jal         0x8012FA20
    // 0x8012FCE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012FA20)(rdram, ctx);
        goto after_6;
    // 0x8012FCE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8012FCE8: b           L_8012FD0C
    // 0x8012FCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FD0C;
    // 0x8012FCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FCF0:
    // 0x8012FCF0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8012FCF4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FCF8: sh          $t3, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r11;
    // 0x8012FCFC: b           L_8012FD0C
    // 0x8012FD00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FD0C;
    // 0x8012FD00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FD04:
    // 0x8012FD04: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FD08: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
L_8012FD0C:
    // 0x8012FD0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012FD10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012FD14: jr          $ra
    // 0x8012FD18: nop

    return;
    // 0x8012FD18: nop

;}
RECOMP_FUNC void M7_FUN_8012fd1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FD1C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012FD20: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8012FD24: lbu         $t6, 0x166($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X166);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012fd28(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012fd28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FD28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012FD2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8012FD30: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8012FD34: beq         $at, $zero, L_8012FE3C
    if (ctx->r1 == 0) {
        // 0x8012FD38: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8012FE3C;
    }
    // 0x8012FD38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8012FD3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012FD40: addu        $at, $at, $t6
    gpr jr_addend_8012FD48 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8012FD44: lw          $t6, -0x2A3C($at)
    ctx->r14 = ADD32(ctx->r1, -0X2A3C);
    // 0x8012FD48: jr          $t6
    // 0x8012FD4C: nop

    switch (jr_addend_8012FD48 >> 2) {
        case 0: goto L_8012FD50; break;
        case 1: goto L_8012FD60; break;
        case 2: goto L_8012FDA0; break;
        case 3: goto L_8012FDE0; break;
        case 4: goto L_8012FDF8; break;
        case 5: goto L_8012FE10; break;
        case 6: goto L_8012FE28; break;
        default: switch_error(__func__, 0x8012FD48, 0x8018D5C4);
    }
    // 0x8012FD4C: nop

L_8012FD50:
    // 0x8012FD50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FD54: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FD58: b           L_8012FE40
    // 0x8012FD5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FE40;
    // 0x8012FD5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FD60:
    // 0x8012FD60: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FD64: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FD68: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8012FD6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8012FD70: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    // 0x8012FD74: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x8012FD78: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012FD7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012FD80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8012FD84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8012FD88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8012FD8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8012FD90: jal         0x8001E978
    // 0x8012FD94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_0;
    // 0x8012FD94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8012FD98: b           L_8012FE40
    // 0x8012FD9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FE40;
    // 0x8012FD9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FDA0:
    // 0x8012FDA0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FDA4: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FDA8: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8012FDAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8012FDB0: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    // 0x8012FDB4: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x8012FDB8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8012FDBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8012FDC0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8012FDC4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8012FDC8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8012FDCC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8012FDD0: jal         0x8001E978
    // 0x8012FDD4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_1;
    // 0x8012FDD4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x8012FDD8: b           L_8012FE40
    // 0x8012FDDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FE40;
    // 0x8012FDDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FDE0:
    // 0x8012FDE0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FDE4: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FDE8: jal         0x8012F490
    // 0x8012FDEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012F490)(rdram, ctx);
        goto after_2;
    // 0x8012FDEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8012FDF0: b           L_8012FE40
    // 0x8012FDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FE40;
    // 0x8012FDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FDF8:
    // 0x8012FDF8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FDFC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FE00: jal         0x8012F87C
    // 0x8012FE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012F87C)(rdram, ctx);
        goto after_3;
    // 0x8012FE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8012FE08: b           L_8012FE40
    // 0x8012FE0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FE40;
    // 0x8012FE0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FE10:
    // 0x8012FE10: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FE14: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x8012FE18: jal         0x8012FA20
    // 0x8012FE1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012FA20)(rdram, ctx);
        goto after_4;
    // 0x8012FE1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8012FE20: b           L_8012FE40
    // 0x8012FE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012FE40;
    // 0x8012FE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FE28:
    // 0x8012FE28: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8012FE2C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8012FE30: sh          $t1, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r9;
    // 0x8012FE34: b           L_8012FE40
    // 0x8012FE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012FE40;
    // 0x8012FE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FE3C:
    // 0x8012FE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012FE40:
    // 0x8012FE40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012FE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012FE48: jr          $ra
    // 0x8012FE4C: nop

    return;
    // 0x8012FE4C: nop

;}
RECOMP_FUNC void M7_FUN_8012fe50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FE50: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012FE54: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8012FE58: lbu         $t6, 0x17D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X17D);
    // 0x8012FE5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012FE60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8012FE64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8012FE68: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8012FE6C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8012FE70: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8012FE74: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8012FE78: bne         $t6, $zero, L_8012FE98
    if (ctx->r14 != 0) {
        // 0x8012FE7C: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8012FE98;
    }
    // 0x8012FE7C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8012FE80: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8012FE84: lbu         $t7, -0x2AB0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2AB0);
    // 0x8012FE88: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8012FE8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8012FE90: beq         $t7, $zero, L_8012FEA0
    if (ctx->r15 == 0) {
            // 0x8012FE94: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    LOOKUP_FUNC(0x8012FEA0)(rdram, ctx);
    return;
    }
    // 0x8012FE94: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
L_8012FE98:
    // 0x8012FE98: jr          $ra
    // 0x8012FE9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8012FE9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012fea0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012fea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FEA0: lbu         $t8, 0x13($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X13);
    // 0x8012FEA4: sltiu       $at, $t1, 0x24
    ctx->r1 = ctx->r9 < 0X24 ? 1 : 0;
    // 0x8012FEA8: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x8012FEAC: sb          $a2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r6;
    // 0x8012FEB0: sb          $a3, 0x166($v1)
    MEM_B(0X166, ctx->r3) = ctx->r7;
    // 0x8012FEB4: sb          $a0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r4;
    // 0x8012FEB8: sb          $t0, 0x17D($v1)
    MEM_B(0X17D, ctx->r3) = ctx->r8;
    // 0x8012FEBC: beq         $at, $zero, L_8012FF34
    if (ctx->r1 == 0) {
        // 0x8012FEC0: sb          $t8, 0x180($v1)
        MEM_B(0X180, ctx->r3) = ctx->r24;
            goto L_8012FF34;
    }
    // 0x8012FEC0: sb          $t8, 0x180($v1)
    MEM_B(0X180, ctx->r3) = ctx->r24;
    // 0x8012FEC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8012FEC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012FECC: addu        $at, $at, $t1
    gpr jr_addend_8012FED4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8012FED0: lw          $t1, -0x2A20($at)
    ctx->r9 = ADD32(ctx->r1, -0X2A20);
    // 0x8012FED4: jr          $t1
    // 0x8012FED8: nop

    switch (jr_addend_8012FED4 >> 2) {
        case 0: goto L_8012FF28; break;
        case 1: goto L_8012FF28; break;
        case 2: goto L_8012FF28; break;
        case 3: goto L_8012FF28; break;
        case 4: goto L_8012FF28; break;
        case 5: goto L_8012FF28; break;
        case 6: goto L_8012FEDC; break;
        case 7: goto L_8012FF28; break;
        case 8: goto L_8012FEEC; break;
        case 9: goto L_8012FEF8; break;
        case 10: goto L_8012FF28; break;
        case 11: goto L_8012FF28; break;
        case 12: goto L_8012FF34; break;
        case 13: goto L_8012FF28; break;
        case 14: goto L_8012FF28; break;
        case 15: goto L_8012FF28; break;
        case 16: goto L_8012FF08; break;
        case 17: goto L_8012FF28; break;
        case 18: goto L_8012FF28; break;
        case 19: goto L_8012FF28; break;
        case 20: goto L_8012FF28; break;
        case 21: goto L_8012FF18; break;
        case 22: goto L_8012FF28; break;
        case 23: goto L_8012FF28; break;
        case 24: goto L_8012FF28; break;
        case 25: goto L_8012FF28; break;
        case 26: goto L_8012FF28; break;
        case 27: goto L_8012FF28; break;
        case 28: goto L_8012FF28; break;
        case 29: goto L_8012FEF8; break;
        case 30: goto L_8012FF28; break;
        case 31: goto L_8012FF28; break;
        case 32: goto L_8012FF28; break;
        case 33: goto L_8012FF28; break;
        case 34: goto L_8012FF28; break;
        case 35: goto L_8012FF28; break;
        default: switch_error(__func__, 0x8012FED4, 0x8018D5E0);
    }
    // 0x8012FED8: nop

L_8012FEDC:
    // 0x8012FEDC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8012FEE0: sb          $t2, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = ctx->r10;
    // 0x8012FEE4: jr          $ra
    // 0x8012FEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FEEC:
    // 0x8012FEEC: sb          $t0, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = ctx->r8;
    // 0x8012FEF0: jr          $ra
    // 0x8012FEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FEF8:
    // 0x8012FEF8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8012FEFC: sb          $t3, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = ctx->r11;
    // 0x8012FF00: jr          $ra
    // 0x8012FF04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FF04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FF08:
    // 0x8012FF08: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8012FF0C: sb          $t4, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = ctx->r12;
    // 0x8012FF10: jr          $ra
    // 0x8012FF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FF18:
    // 0x8012FF18: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8012FF1C: sb          $t5, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = ctx->r13;
    // 0x8012FF20: jr          $ra
    // 0x8012FF24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FF24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FF28:
    // 0x8012FF28: sb          $zero, 0x17F($v1)
    MEM_B(0X17F, ctx->r3) = 0;
    // 0x8012FF2C: jr          $ra
    // 0x8012FF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012FF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012FF34:
    // 0x8012FF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012FF38: jr          $ra
    // 0x8012FF3C: nop

    return;
    // 0x8012FF3C: nop

;}
RECOMP_FUNC void M7_FUN_8012ff40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FF40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012FF44: jr          $ra
    // 0x8012FF48: lbu         $v0, -0x4292($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4292);
    return;
    // 0x8012FF48: lbu         $v0, -0x4292($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4292);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012ff4c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012ff4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FF4C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012FF50: jr          $ra
    // 0x8012FF54: lbu         $v0, -0x4294($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4294);
    return;
    // 0x8012FF54: lbu         $v0, -0x4294($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4294);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012ff58(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012ff58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012FF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012FF60: jal         0x80151BC4
    // 0x8012FF64: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_0;
    // 0x8012FF64: nop

    after_0:
    // 0x8012FF68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8012FF6C: bne         $v0, $at, L_8012FFA8
    if (ctx->r2 != ctx->r1) {
        // 0x8012FF70: nop
    
            goto L_8012FFA8;
    }
    // 0x8012FF70: nop

    // 0x8012FF74: jal         0x80151C34
    // 0x8012FF78: nop

    LOOKUP_FUNC(0x80151C34)(rdram, ctx);
        goto after_1;
    // 0x8012FF78: nop

    after_1:
    // 0x8012FF7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8012FF80: beq         $v0, $at, L_8012FF98
    if (ctx->r2 == ctx->r1) {
        // 0x8012FF84: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8012FF98;
    }
    // 0x8012FF84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8012FF88: beq         $v0, $at, L_8012FFA0
    if (ctx->r2 == ctx->r1) {
        // 0x8012FF8C: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_8012FFA0;
    }
    // 0x8012FF8C: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8012FF90: bne         $v0, $at, L_8012FFA8
    if (ctx->r2 != ctx->r1) {
        // 0x8012FF94: nop
    
            goto L_8012FFA8;
    }
    // 0x8012FF94: nop

L_8012FF98:
    // 0x8012FF98: b           L_8012FFB0
    // 0x8012FF9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8012FFB0;
    // 0x8012FF9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8012FFA0:
    // 0x8012FFA0: b           L_8012FFB0
    // 0x8012FFA4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_8012FFB0;
    // 0x8012FFA4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_8012FFA8:
    // 0x8012FFA8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012FFAC: lhu         $v0, -0x43E2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E2);
L_8012FFB0:
    // 0x8012FFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012FFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012FFB8: jr          $ra
    // 0x8012FFBC: nop

    return;
    // 0x8012FFBC: nop

;}
RECOMP_FUNC void M7_FUN_8012ffc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FFC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8012FFC4: jr          $ra
    // 0x8012FFC8: lbu         $v0, -0x43FA($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43FA);
    return;
    // 0x8012FFC8: lbu         $v0, -0x43FA($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43FA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012ffcc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012ffcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FFCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012FFD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012FFD4: jr          $ra
    // 0x8012FFD8: sb          $a0, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r4;
    return;
    // 0x8012FFD8: sb          $a0, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012ffdc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012ffdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012FFDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012FFE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8012FFE4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8012FFE8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8012FFEC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8012FFF0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012FFF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8012FFF8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012FFFC: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80130000: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80130004: sub.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80130008: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8013000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130010: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80130014: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80130018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013001C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80130020: jal         0x8002FC20
    // 0x80130024: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80130024: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80130028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80130030: jr          $ra
    // 0x80130034: nop

    return;
    // 0x80130034: nop

;}
RECOMP_FUNC void M7_FUN_80130038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013003C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80130040: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80130044: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80130048: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8013004C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80130050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130054: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80130058: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013005C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80130060: jal         0x8002FC20
    // 0x80130064: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80130064: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_0:
    // 0x80130068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80130070: jr          $ra
    // 0x80130074: nop

    return;
    // 0x80130074: nop

;}
RECOMP_FUNC void M7_FUN_80130078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130078: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8013007C: lbu         $t6, -0x42B3($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42B3);
    // 0x80130080: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80130084: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80130088: bne         $t7, $zero, L_801300A0
    if (ctx->r15 != 0) {
        // 0x8013008C: nop
    
            goto L_801300A0;
    }
    // 0x8013008C: nop

    // 0x80130090: lh          $t8, -0x6CAC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6CAC);
    // 0x80130094: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80130098: beq         $t8, $zero, L_801300A8
    if (ctx->r24 == 0) {
            // 0x8013009C: nop

    LOOKUP_FUNC(0x801300A8)(rdram, ctx);
    return;
    }
    // 0x8013009C: nop

L_801300A0:
    // 0x801300A0: jr          $ra
    // 0x801300A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801300A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801300a8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801300a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801300A8: jr          $ra
    // 0x801300AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801300AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801300b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801300b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801300B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801300B4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801300B8: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x801300BC: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801300C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801300C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801300C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801300CC: sw          $t6, 0x112C($v0)
    MEM_W(0X112C, ctx->r2) = ctx->r14;
    // 0x801300D0: swc1        $f12, 0x1130($v0)
    MEM_W(0X1130, ctx->r2) = ctx->f12.u32l;
    // 0x801300D4: sw          $a2, 0x1138($v0)
    MEM_W(0X1138, ctx->r2) = ctx->r6;
    // 0x801300D8: swc1        $f14, 0x1144($v0)
    MEM_W(0X1144, ctx->r2) = ctx->f14.u32l;
    // 0x801300DC: swc1        $f4, 0x1148($v0)
    MEM_W(0X1148, ctx->r2) = ctx->f4.u32l;
    // 0x801300E0: jr          $ra
    // 0x801300E4: swc1        $f6, 0x114C($v0)
    MEM_W(0X114C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x801300E4: swc1        $f6, 0x114C($v0)
    MEM_W(0X114C, ctx->r2) = ctx->f6.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801300e8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801300e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801300E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801300EC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801300F0: lw          $t6, 0x112C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X112C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801300f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801300f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801300F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801300F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801300FC: beql        $t6, $zero, L_80130248
    if (ctx->r14 == 0) {
        // 0x80130100: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80130248;
    }
    goto skip_0;
    // 0x80130100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80130104: lhu         $t7, 0x30($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X30);
    // 0x80130108: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013010C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80130110: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80130114: mfhi        $t8
    ctx->r24 = hi;
    // 0x80130118: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8013011C: bne         $t8, $zero, L_80130178
    if (ctx->r24 != 0) {
        // 0x80130120: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_80130178;
    }
    // 0x80130120: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80130124: lwc1        $f4, 0x1130($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1130);
    // 0x80130128: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8013012C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80130130: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80130134: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80130138: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8013013C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80130140: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80130144: nop

    // 0x80130148: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8013014C: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80130150: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80130154: nop

    // 0x80130158: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8013015C: bne         $at, $zero, L_80130168
    if (ctx->r1 != 0) {
        // 0x80130160: nop
    
            goto L_80130168;
    }
    // 0x80130160: nop

    // 0x80130164: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80130168:
    // 0x80130168: jal         0x801518D4
    // 0x8013016C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_0;
    // 0x8013016C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_0:
    // 0x80130170: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80130174: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_80130178:
    // 0x80130178: lw          $v0, 0x1138($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1138);
    // 0x8013017C: beq         $v0, $zero, L_801301A0
    if (ctx->r2 == 0) {
        // 0x80130180: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_801301A0;
    }
    // 0x80130180: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80130184: sw          $t0, 0x1138($v1)
    MEM_W(0X1138, ctx->r3) = ctx->r8;
    // 0x80130188: bne         $t0, $zero, L_801301A0
    if (ctx->r8 != 0) {
        // 0x8013018C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_801301A0;
    }
    // 0x8013018C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80130190: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80130194: sw          $zero, 0x112C($v1)
    MEM_W(0X112C, ctx->r3) = 0;
    // 0x80130198: b           L_80130244
    // 0x8013019C: swc1        $f12, 0x114C($v1)
    MEM_W(0X114C, ctx->r3) = ctx->f12.u32l;
        goto L_80130244;
    // 0x8013019C: swc1        $f12, 0x114C($v1)
    MEM_W(0X114C, ctx->r3) = ctx->f12.u32l;
L_801301A0:
    // 0x801301A0: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x801301A4: bne         $t1, $zero, L_80130244
    if (ctx->r9 != 0) {
        // 0x801301A8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80130244;
    }
    // 0x801301A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801301AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801301B0: lwc1        $f0, 0x1130($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1130);
    // 0x801301B4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801301B8: nop

    // 0x801301BC: bc1fl       L_801301FC
    if (!c1cs) {
        // 0x801301C0: neg.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
            goto L_801301FC;
    }
    goto skip_1;
    // 0x801301C0: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    skip_1:
    // 0x801301C4: lwc1        $f6, 0x1148($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1148);
    // 0x801301C8: swc1        $f0, 0x324($v1)
    MEM_W(0X324, ctx->r3) = ctx->f0.u32l;
    // 0x801301CC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801301D0: nop

    // 0x801301D4: bc1fl       L_801301F0
    if (!c1cs) {
        // 0x801301D8: neg.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
            goto L_801301F0;
    }
    goto skip_2;
    // 0x801301D8: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    skip_2:
    // 0x801301DC: lwc1        $f8, 0x1144($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1144);
    // 0x801301E0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801301E4: swc1        $f10, 0x1130($v1)
    MEM_W(0X1130, ctx->r3) = ctx->f10.u32l;
    // 0x801301E8: lwc1        $f0, 0x1130($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1130);
    // 0x801301EC: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
L_801301F0:
    // 0x801301F0: b           L_80130204
    // 0x801301F4: swc1        $f16, 0x1130($v1)
    MEM_W(0X1130, ctx->r3) = ctx->f16.u32l;
        goto L_80130204;
    // 0x801301F4: swc1        $f16, 0x1130($v1)
    MEM_W(0X1130, ctx->r3) = ctx->f16.u32l;
    // 0x801301F8: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
L_801301FC:
    // 0x801301FC: swc1        $f0, 0x324($v1)
    MEM_W(0X324, ctx->r3) = ctx->f0.u32l;
    // 0x80130200: swc1        $f18, 0x1130($v1)
    MEM_W(0X1130, ctx->r3) = ctx->f18.u32l;
L_80130204:
    // 0x80130204: lwc1        $f0, 0x1130($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1130);
    // 0x80130208: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8013020C: nop

    // 0x80130210: bc1fl       L_80130224
    if (!c1cs) {
        // 0x80130214: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80130224;
    }
    goto skip_3;
    // 0x80130214: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
    // 0x80130218: b           L_80130224
    // 0x8013021C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80130224;
    // 0x8013021C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80130220: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80130224:
    // 0x80130224: ldc1        $f6, -0x2990($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2990);
    // 0x80130228: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8013022C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80130230: nop

    // 0x80130234: bc1fl       L_80130248
    if (!c1cs) {
        // 0x80130238: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80130248;
    }
    goto skip_4;
    // 0x80130238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8013023C: sw          $zero, 0x112C($v1)
    MEM_W(0X112C, ctx->r3) = 0;
    // 0x80130240: swc1        $f12, 0x324($v1)
    MEM_W(0X324, ctx->r3) = ctx->f12.u32l;
L_80130244:
    // 0x80130244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80130248:
    // 0x80130248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013024C: jr          $ra
    // 0x80130250: nop

    return;
    // 0x80130250: nop

;}
RECOMP_FUNC void M7_FUN_80130254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80130258: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013025C: jr          $ra
    // 0x80130260: sb          $a0, 0x60B4($at)
    MEM_B(0X60B4, ctx->r1) = ctx->r4;
    return;
    // 0x80130260: sb          $a0, 0x60B4($at)
    MEM_B(0X60B4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130264(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80130268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013026C: jal         0x80001060
    // 0x80130270: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80130270: nop

    after_0:
    // 0x80130274: beq         $v0, $zero, L_80130284
    if (ctx->r2 == 0) {
        // 0x80130278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80130284;
    }
    // 0x80130278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013027C: b           L_80130288
    // 0x80130280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80130288;
    // 0x80130280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80130284:
    // 0x80130284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80130288:
    // 0x80130288: jr          $ra
    // 0x8013028C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8013028C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130290(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80130294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130298: jal         0x80130264
    // 0x8013029C: nop

    LOOKUP_FUNC(0x80130264)(rdram, ctx);
        goto after_0;
    // 0x8013029C: nop

    after_0:
    // 0x801302A0: beq         $v0, $zero, L_801302C0
    if (ctx->r2 == 0) {
        // 0x801302A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801302C0;
    }
    // 0x801302A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801302A8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801302AC: lbu         $t6, 0x60B4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X60B4);
    // 0x801302B0: bnel        $t6, $zero, L_801302C4
    if (ctx->r14 != 0) {
        // 0x801302B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801302C4;
    }
    goto skip_0;
    // 0x801302B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801302B8: b           L_801302C4
    // 0x801302BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801302C4;
    // 0x801302BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801302C0:
    // 0x801302C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801302C4:
    // 0x801302C4: jr          $ra
    // 0x801302C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801302C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801302cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801302cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801302CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801302D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801302D4: jal         0x80130264
    // 0x801302D8: nop

    LOOKUP_FUNC(0x80130264)(rdram, ctx);
        goto after_0;
    // 0x801302D8: nop

    after_0:
    // 0x801302DC: beq         $v0, $zero, L_80130300
    if (ctx->r2 == 0) {
        // 0x801302E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80130300;
    }
    // 0x801302E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801302E4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801302E8: lbu         $t6, 0x60B4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X60B4);
    // 0x801302EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801302F0: bnel        $t6, $at, L_80130304
    if (ctx->r14 != ctx->r1) {
        // 0x801302F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80130304;
    }
    goto skip_0;
    // 0x801302F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801302F8: b           L_80130304
    // 0x801302FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80130304;
    // 0x801302FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80130300:
    // 0x80130300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80130304:
    // 0x80130304: jr          $ra
    // 0x80130308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80130308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013030c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013030c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013030C: nop

;}
RECOMP_FUNC void M7_FUN_80130310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130310: sltiu       $at, $a0, 0xD42
    ctx->r1 = ctx->r4 < 0XD42 ? 1 : 0;
    // 0x80130314: beq         $at, $zero, L_80130368
    if (ctx->r1 == 0) {
        // 0x80130318: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80130368;
    }
    // 0x80130318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013031C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80130320: addiu       $v0, $v0, -0x7454
    ctx->r2 = ADD32(ctx->r2, -0X7454);
    // 0x80130324: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
L_80130328:
    // 0x80130328: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8013032C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80130330: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x80130334: beq         $at, $zero, L_80130354
    if (ctx->r1 == 0) {
        // 0x80130338: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80130354;
    }
    // 0x80130338: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8013033C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80130340: lbu         $t9, 0x6BA8($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X6BA8);
    // 0x80130344: sll         $t0, $v1, 8
    ctx->r8 = S32(ctx->r3 << 8);
    // 0x80130348: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8013034C: jr          $ra
    // 0x80130350: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80130350: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80130354:
    // 0x80130354: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80130358: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8013035C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80130360: bnel        $at, $zero, L_80130328
    if (ctx->r1 != 0) {
        // 0x80130364: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_80130328;
    }
    goto skip_0;
    // 0x80130364: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    skip_0:
L_80130368:
    // 0x80130368: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8013036C: addiu       $v0, $v0, -0x7454
    ctx->r2 = ADD32(ctx->r2, -0X7454);
    // 0x80130370: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x80130374: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
L_80130378:
    // 0x80130378: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8013037C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80130380: sltu        $at, $a0, $t3
    ctx->r1 = ctx->r4 < ctx->r11 ? 1 : 0;
    // 0x80130384: bne         $at, $zero, L_801303A8
    if (ctx->r1 != 0) {
        // 0x80130388: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_801303A8;
    }
    // 0x80130388: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8013038C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80130390: lbu         $t4, 0x6BA8($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X6BA8);
    // 0x80130394: sll         $t5, $v1, 8
    ctx->r13 = S32(ctx->r3 << 8);
    // 0x80130398: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8013039C: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x801303A0: jr          $ra
    // 0x801303A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x801303A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_801303A8:
    // 0x801303A8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x801303AC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801303B0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x801303B4: beql        $at, $zero, L_80130378
    if (ctx->r1 == 0) {
        // 0x801303B8: sll         $t1, $v1, 1
        ctx->r9 = S32(ctx->r3 << 1);
            goto L_80130378;
    }
    goto skip_1;
    // 0x801303B8: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    skip_1:
    // 0x801303BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801303C0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x801303C4: lbu         $v0, 0x6BA8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6BA8);
    // 0x801303C8: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x801303CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801303D0: jr          $ra
    // 0x801303D4: nop

    return;
    // 0x801303D4: nop

;}
RECOMP_FUNC void M7_FUN_801303d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801303D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801303DC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801303E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801303E4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801303E8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801303EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801303F0: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x801303F4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801303F8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801303FC: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80130400: bc1f        L_80130410
    if (!c1cs) {
        // 0x80130404: nop
    
            goto L_80130410;
    }
    // 0x80130404: nop

    // 0x80130408: b           L_80130410
    // 0x8013040C: neg.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = -ctx->f4.fl;
        goto L_80130410;
    // 0x8013040C: neg.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = -ctx->f4.fl;
L_80130410:
    // 0x80130410: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80130414: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80130418: bc1f        L_80130428
    if (!c1cs) {
        // 0x8013041C: nop
    
            goto L_80130428;
    }
    // 0x8013041C: nop

    // 0x80130420: b           L_80130428
    // 0x80130424: neg.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = -ctx->f6.fl;
        goto L_80130428;
    // 0x80130424: neg.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = -ctx->f6.fl;
L_80130428:
    // 0x80130428: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8013042C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80130430: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x80130434: jal         0x8002FC20
    // 0x80130438: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80130438: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8013043C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80130440: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80130444: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80130448: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013044C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80130450: bc1fl       L_80130464
    if (!c1cs) {
        // 0x80130454: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80130464;
    }
    goto skip_0;
    // 0x80130454: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x80130458: b           L_80130464
    // 0x8013045C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_80130464;
    // 0x8013045C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80130460: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80130464:
    // 0x80130464: ldc1        $f4, -0x2980($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2980);
    // 0x80130468: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8013046C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80130470: nop

    // 0x80130474: bc1tl       L_80130488
    if (c1cs) {
        // 0x80130478: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80130488;
    }
    goto skip_1;
    // 0x80130478: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_1:
    // 0x8013047C: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80130480: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80130484: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80130488:
    // 0x80130488: nop

    // 0x8013048C: bc1fl       L_801304F0
    if (!c1cs) {
        // 0x80130490: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_801304F0;
    }
    goto skip_2;
    // 0x80130490: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x80130494: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x80130498: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x8013049C: bc1fl       L_801304B0
    if (!c1cs) {
        // 0x801304A0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_801304B0;
    }
    goto skip_3;
    // 0x801304A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_3:
    // 0x801304A4: b           L_80130600
    // 0x801304A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80130600;
    // 0x801304A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801304AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_801304B0:
    // 0x801304B0: nop

    // 0x801304B4: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801304B8: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x801304BC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801304C0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801304C4: nop

    // 0x801304C8: sltiu       $at, $a0, 0x2001
    ctx->r1 = ctx->r4 < 0X2001 ? 1 : 0;
    // 0x801304CC: bne         $at, $zero, L_801304D8
    if (ctx->r1 != 0) {
        // 0x801304D0: nop
    
            goto L_801304D8;
    }
    // 0x801304D0: nop

    // 0x801304D4: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
L_801304D8:
    // 0x801304D8: jal         0x80130310
    // 0x801304DC: nop

    LOOKUP_FUNC(0x80130310)(rdram, ctx);
        goto after_1;
    // 0x801304DC: nop

    after_1:
    // 0x801304E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801304E4: b           L_80130570
    // 0x801304E8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
        goto L_80130570;
    // 0x801304E8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x801304EC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_801304F0:
    // 0x801304F0: nop

    // 0x801304F4: bc1fl       L_80130560
    if (!c1cs) {
        // 0x801304F8: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80130560;
    }
    goto skip_4;
    // 0x801304F8: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_4:
    // 0x801304FC: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x80130500: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80130504: bc1fl       L_80130518
    if (!c1cs) {
        // 0x80130508: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80130518;
    }
    goto skip_5;
    // 0x80130508: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_5:
    // 0x8013050C: b           L_80130600
    // 0x80130510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80130600;
    // 0x80130510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80130514: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80130518:
    // 0x80130518: nop

    // 0x8013051C: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80130520: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80130524: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80130528: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8013052C: nop

    // 0x80130530: sltiu       $at, $a0, 0x2001
    ctx->r1 = ctx->r4 < 0X2001 ? 1 : 0;
    // 0x80130534: bne         $at, $zero, L_80130540
    if (ctx->r1 != 0) {
        // 0x80130538: nop
    
            goto L_80130540;
    }
    // 0x80130538: nop

    // 0x8013053C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
L_80130540:
    // 0x80130540: jal         0x80130310
    // 0x80130544: nop

    LOOKUP_FUNC(0x80130310)(rdram, ctx);
        goto after_2;
    // 0x80130544: nop

    after_2:
    // 0x80130548: addiu       $t8, $zero, 0x4000
    ctx->r24 = ADD32(0, 0X4000);
    // 0x8013054C: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x80130550: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80130554: b           L_80130570
    // 0x80130558: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
        goto L_80130570;
    // 0x80130558: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // 0x8013055C: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_80130560:
    // 0x80130560: addiu       $v1, $zero, 0x2000
    ctx->r3 = ADD32(0, 0X2000);
    // 0x80130564: bc1fl       L_80130574
    if (!c1cs) {
        // 0x80130568: lwc1        $f0, 0x34($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80130574;
    }
    goto skip_6;
    // 0x80130568: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x8013056C: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
L_80130570:
    // 0x80130570: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
L_80130574:
    // 0x80130574: lhu         $v1, 0x1E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1E);
    // 0x80130578: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8013057C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80130580: nop

    // 0x80130584: bc1fl       L_801305AC
    if (!c1cs) {
        // 0x80130588: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_801305AC;
    }
    goto skip_7;
    // 0x80130588: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_7:
    // 0x8013058C: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x80130590: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80130594: bc1fl       L_801305AC
    if (!c1cs) {
        // 0x80130598: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_801305AC;
    }
    goto skip_8;
    // 0x80130598: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_8:
    // 0x8013059C: subu        $v1, $t9, $v1
    ctx->r3 = SUB32(ctx->r25, ctx->r3);
    // 0x801305A0: b           L_801305FC
    // 0x801305A4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_801305FC;
    // 0x801305A4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801305A8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_801305AC:
    // 0x801305AC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801305B0: bc1fl       L_801305D8
    if (!c1cs) {
        // 0x801305B4: c.le.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
            goto L_801305D8;
    }
    goto skip_9;
    // 0x801305B4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    skip_9:
    // 0x801305B8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801305BC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x801305C0: bc1fl       L_801305D8
    if (!c1cs) {
        // 0x801305C4: c.le.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
            goto L_801305D8;
    }
    goto skip_10;
    // 0x801305C4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    skip_10:
    // 0x801305C8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x801305CC: b           L_801305FC
    // 0x801305D0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_801305FC;
    // 0x801305D0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801305D4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
L_801305D8:
    // 0x801305D8: nop

    // 0x801305DC: bc1fl       L_80130600
    if (!c1cs) {
        // 0x801305E0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80130600;
    }
    goto skip_11;
    // 0x801305E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_11:
    // 0x801305E4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801305E8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801305EC: bc1fl       L_80130600
    if (!c1cs) {
        // 0x801305F0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80130600;
    }
    goto skip_12;
    // 0x801305F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_12:
    // 0x801305F4: subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    // 0x801305F8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_801305FC:
    // 0x801305FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80130600:
    // 0x80130600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130604: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80130608: jr          $ra
    // 0x8013060C: nop

    return;
    // 0x8013060C: nop

;}
RECOMP_FUNC void M7_FUN_80130610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80130614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80130618: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8013061C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80130620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130624: bgez        $a0, L_8013063C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80130628: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013063C;
    }
    // 0x80130628: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013062C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80130630: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80130634: nop

    // 0x80130638: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8013063C:
    // 0x8013063C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80130640: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80130644: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80130648: ldc1        $f4, -0x2978($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2978);
    // 0x8013064C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80130650: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80130654: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80130658: jal         0x80029280
    // 0x8013065C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_0;
    // 0x8013065C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_0:
    // 0x80130660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80130668: jr          $ra
    // 0x8013066C: nop

    return;
    // 0x8013066C: nop

;}
RECOMP_FUNC void M7_FUN_80130670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80130674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80130678: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8013067C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80130680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130684: bgez        $a0, L_8013069C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80130688: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013069C;
    }
    // 0x80130688: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013068C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80130690: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80130694: nop

    // 0x80130698: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8013069C:
    // 0x8013069C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x801306A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801306A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801306A8: ldc1        $f4, -0x2970($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2970);
    // 0x801306AC: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801306B0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801306B4: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801306B8: jal         0x80032720
    // 0x801306BC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_0;
    // 0x801306BC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_0:
    // 0x801306C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801306C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801306C8: jr          $ra
    // 0x801306CC: nop

    return;
    // 0x801306CC: nop

;}
RECOMP_FUNC void M7_FUN_801306d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801306D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801306D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801306D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801306DC: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x801306E0: jal         0x80130670
    // 0x801306E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80130670)(rdram, ctx);
        goto after_0;
    // 0x801306E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801306E8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801306EC: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x801306F0: jal         0x80130610
    // 0x801306F4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80130610)(rdram, ctx);
        goto after_1;
    // 0x801306F4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x801306F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801306FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80130700: jr          $ra
    // 0x80130704: nop

    return;
    // 0x80130704: nop

;}
RECOMP_FUNC void M7_FUN_80130708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013070C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130710: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80130714: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130718: jal         0x801306D0
    // 0x8013071C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801306D0)(rdram, ctx);
        goto after_0;
    // 0x8013071C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80130720: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80130724: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80130728: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8013072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130730: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x80130734: nop

    // 0x80130738: bc1fl       L_8013074C
    if (!c1cs) {
        // 0x8013073C: div.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
            goto L_8013074C;
    }
    goto skip_0;
    // 0x8013073C: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    skip_0:
    // 0x80130740: b           L_8013074C
    // 0x80130744: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8013074C;
    // 0x80130744: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80130748: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_8013074C:
    // 0x8013074C: jr          $ra
    // 0x80130750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80130750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130754(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130754: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80130758: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8013075C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80130760: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130764: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x80130768: beq         $at, $zero, L_80130784
    if (ctx->r1 == 0) {
            // 0x8013076C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    LOOKUP_FUNC(0x80130784)(rdram, ctx);
    return;
    }
    // 0x8013076C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80130770: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80130774: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80130778: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013077C: jr          $ra
    // 0x80130780: lwc1        $f0, 0x63A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X63A0);
    return;
    // 0x80130780: lwc1        $f0, 0x63A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X63A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130784(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130784: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x80130788: beq         $at, $zero, L_801307A4
    if (ctx->r1 == 0) {
            // 0x8013078C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    LOOKUP_FUNC(0x801307A4)(rdram, ctx);
    return;
    }
    // 0x8013078C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80130790: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80130794: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80130798: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8013079C: jr          $ra
    // 0x801307A0: lwc1        $f0, 0x73A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73A0);
    return;
    // 0x801307A0: lwc1        $f0, 0x73A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801307a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801307a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801307A4: slti        $at, $v0, 0x600
    ctx->r1 = SIGNED(ctx->r2) < 0X600 ? 1 : 0;
    // 0x801307A8: beq         $at, $zero, L_801307C8
    if (ctx->r1 == 0) {
            // 0x801307AC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    LOOKUP_FUNC(0x801307C8)(rdram, ctx);
    return;
    }
    // 0x801307AC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801307B0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801307B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801307B8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801307BC: lwc1        $f0, 0x53A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53A0);
    // 0x801307C0: jr          $ra
    // 0x801307C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x801307C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801307c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801307c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801307C8: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801307CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801307D0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801307D4: lwc1        $f0, -0x7C60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7C60);
    // 0x801307D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x801307DC: jr          $ra
    // 0x801307E0: nop

    return;
    // 0x801307E0: nop

;}
RECOMP_FUNC void M7_FUN_801307e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801307E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801307E8: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x801307EC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x801307F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801307F4: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x801307F8: beq         $at, $zero, L_80130814
    if (ctx->r1 == 0) {
            // 0x801307FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    LOOKUP_FUNC(0x80130814)(rdram, ctx);
    return;
    }
    // 0x801307FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80130800: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80130804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80130808: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013080C: jr          $ra
    // 0x80130810: lwc1        $f0, 0x63A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X63A4);
    return;
    // 0x80130810: lwc1        $f0, 0x63A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X63A4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130814(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130814: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x80130818: beq         $at, $zero, L_80130838
    if (ctx->r1 == 0) {
            // 0x8013081C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    LOOKUP_FUNC(0x80130838)(rdram, ctx);
    return;
    }
    // 0x8013081C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80130820: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80130824: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80130828: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8013082C: lwc1        $f0, 0x73A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73A4);
    // 0x80130830: jr          $ra
    // 0x80130834: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80130834: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130838(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130838: slti        $at, $v0, 0x600
    ctx->r1 = SIGNED(ctx->r2) < 0X600 ? 1 : 0;
    // 0x8013083C: beq         $at, $zero, L_8013085C
    if (ctx->r1 == 0) {
            // 0x80130840: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    LOOKUP_FUNC(0x8013085C)(rdram, ctx);
    return;
    }
    // 0x80130840: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80130844: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80130848: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8013084C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80130850: lwc1        $f0, 0x53A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53A4);
    // 0x80130854: jr          $ra
    // 0x80130858: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80130858: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013085c(rdram, ctx);
;}
