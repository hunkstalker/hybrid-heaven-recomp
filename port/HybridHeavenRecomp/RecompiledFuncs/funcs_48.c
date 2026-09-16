#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801cc528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC528: jr          $ra
    // 0x801CC52C: nop

    return;
    // 0x801CC52C: nop

;}
RECOMP_FUNC void M24_FUN_801cc530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC530: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CC534: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC538: jr          $ra
    // 0x801CC53C: sw          $t6, -0x5538($at)
    MEM_W(-0X5538, ctx->r1) = ctx->r14;
    return;
    // 0x801CC53C: sw          $t6, -0x5538($at)
    MEM_W(-0X5538, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc540(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC540: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CC544: lw          $v0, -0x5538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5538);
    // 0x801CC548: jr          $ra
    // 0x801CC54C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801CC54C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc550(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC550: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC554: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC558: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801CC55C: jr          $ra
    // 0x801CC560: sw          $zero, -0x5534($at)
    MEM_W(-0X5534, ctx->r1) = 0;
    return;
    // 0x801CC560: sw          $zero, -0x5534($at)
    MEM_W(-0X5534, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc564(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC564: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CC568: addiu       $t7, $t7, -0x5534
    ctx->r15 = ADD32(ctx->r15, -0X5534);
    // 0x801CC56C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC570: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801CC574: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc578(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC578: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CC57C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CC580: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CC584: beq         $v0, $zero, L_801CC5A8
    if (ctx->r2 == 0) {
        // 0x801CC588: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801CC5A8;
    }
    // 0x801CC588: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801CC58C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CC590: beq         $v0, $at, L_801CC5D4
    if (ctx->r2 == ctx->r1) {
        // 0x801CC594: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801CC5D4;
    }
    // 0x801CC594: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CC598: beql        $v0, $at, L_801CC61C
    if (ctx->r2 == ctx->r1) {
        // 0x801CC59C: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_801CC61C;
    }
    goto skip_0;
    // 0x801CC59C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x801CC5A0: b           L_801CC644
    // 0x801CC5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801CC644;
    // 0x801CC5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CC5A8:
    // 0x801CC5A8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801CC5AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801CC5B0: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x801CC5B4: lhu         $a3, 0x3A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3A);
    // 0x801CC5B8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801CC5BC: jal         0x801CC470
    // 0x801CC5C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801CC5C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801CC5C4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CC5C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CC5CC: b           L_801CC640
    // 0x801CC5D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_801CC640;
    // 0x801CC5D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801CC5D4:
    // 0x801CC5D4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801CC5D8: jalr        $a1
    // 0x801CC5DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_1;
    // 0x801CC5DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CC5E0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CC5E4: beq         $v0, $zero, L_801CC640
    if (ctx->r2 == 0) {
        // 0x801CC5E8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_801CC640;
    }
    // 0x801CC5E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801CC5EC: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801CC5F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801CC5F4: lhu         $a2, 0x4A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X4A);
    // 0x801CC5F8: lhu         $a3, 0x4E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X4E);
    // 0x801CC5FC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801CC600: jal         0x801CC4D8
    // 0x801CC604: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801CC4D8)(rdram, ctx);
        goto after_2;
    // 0x801CC604: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801CC608: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CC60C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801CC610: b           L_801CC640
    // 0x801CC614: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_801CC640;
    // 0x801CC614: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801CC618: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_801CC61C:
    // 0x801CC61C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801CC620: jalr        $t9
    // 0x801CC624: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x801CC624: nop

    after_3:
    // 0x801CC628: bne         $v0, $zero, L_801CC640
    if (ctx->r2 != 0) {
        // 0x801CC62C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_801CC640;
    }
    // 0x801CC62C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801CC630: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801CC634: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801CC638: b           L_801CC644
    // 0x801CC63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801CC644;
    // 0x801CC63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801CC640:
    // 0x801CC640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CC644:
    // 0x801CC644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CC648: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CC64C: jr          $ra
    // 0x801CC650: nop

    return;
    // 0x801CC650: nop

;}
RECOMP_FUNC void M24_FUN_801cc654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC654: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CC658: addiu       $t0, $t0, -0x5504
    ctx->r8 = ADD32(ctx->r8, -0X5504);
    // 0x801CC65C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801CC660: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CC664: addiu       $t8, $t8, 0x7A0
    ctx->r24 = ADD32(ctx->r24, 0X7A0);
    // 0x801CC668: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801CC66C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801CC670: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801CC674: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801CC678: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x801CC67C: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x801CC680: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x801CC684: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x801CC688: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x801CC68C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CC690: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x801CC694: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x801CC698: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CC69C: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
    // 0x801CC6A0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x801CC6A4: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x801CC6A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801CC6AC: sw          $t3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r11;
    // 0x801CC6B0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x801CC6B4: sw          $t4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r12;
    // 0x801CC6B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x801CC6BC: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x801CC6C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801CC6C4: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x801CC6C8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801CC6CC: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    // 0x801CC6D0: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x801CC6D4: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x801CC6D8: sw          $t9, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r25;
    // 0x801CC6DC: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x801CC6E0: sw          $t7, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r15;
    // 0x801CC6E4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CC6E8: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x801CC6EC: jr          $ra
    // 0x801CC6F0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    return;
    // 0x801CC6F0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc6f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc6f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC6F4: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x801CC6F8: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC6FC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CC700: addiu       $v1, $v1, 0x7A0
    ctx->r3 = ADD32(ctx->r3, 0X7A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc704(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC704: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CC708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CC70C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CC710: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x801CC714: mflo        $t6
    ctx->r14 = lo;
    // 0x801CC718: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x801CC71C: lw          $t8, -0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X14);
    // 0x801CC720: beql        $t8, $zero, L_801CC878
    if (ctx->r24 == 0) {
        // 0x801CC724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CC878;
    }
    goto skip_0;
    // 0x801CC724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801CC728: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC72C: mflo        $t9
    ctx->r25 = lo;
    // 0x801CC730: addu        $s0, $v1, $t9
    ctx->r16 = ADD32(ctx->r3, ctx->r25);
    // 0x801CC734: lw          $t0, 0x34($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X34);
    // 0x801CC738: bnel        $t0, $zero, L_801CC7A8
    if (ctx->r8 != 0) {
        // 0x801CC73C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_801CC7A8;
    }
    goto skip_1;
    // 0x801CC73C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801CC740: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x801CC744: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CC748: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801CC74C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801CC750: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x801CC754: lw          $a1, -0x550C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X550C);
    // 0x801CC758: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x801CC75C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801CC760: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x801CC764: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801CC768: sll         $t4, $zero, 3
    ctx->r12 = S32(0 << 3);
    // 0x801CC76C: bnel        $a0, $at, L_801CC788
    if (ctx->r4 != ctx->r1) {
        // 0x801CC770: sw          $a0, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->r4;
            goto L_801CC788;
    }
    goto skip_2;
    // 0x801CC770: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
    skip_2:
    // 0x801CC774: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x801CC778: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x801CC77C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801CC780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CC784: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
L_801CC788:
    // 0x801CC788: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x801CC78C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801CC790: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CC794: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
    // 0x801CC798: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    // 0x801CC79C: b           L_801CC874
    // 0x801CC7A0: sw          $t5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r13;
        goto L_801CC874;
    // 0x801CC7A0: sw          $t5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r13;
    // 0x801CC7A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_801CC7A8:
    // 0x801CC7A8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801CC7AC: beql        $t7, $zero, L_801CC878
    if (ctx->r15 == 0) {
        // 0x801CC7B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CC878;
    }
    goto skip_3;
    // 0x801CC7B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801CC7B4: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x801CC7B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801CC7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CC7C0: bne         $a1, $v1, L_801CC7D4
    if (ctx->r5 != ctx->r3) {
        // 0x801CC7C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801CC7D4;
    }
    // 0x801CC7C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CC7C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801CC7CC: b           L_801CC7E4
    // 0x801CC7D0: addiu       $v0, $v0, -0x27BC
    ctx->r2 = ADD32(ctx->r2, -0X27BC);
        goto L_801CC7E4;
    // 0x801CC7D0: addiu       $v0, $v0, -0x27BC
    ctx->r2 = ADD32(ctx->r2, -0X27BC);
L_801CC7D4:
    // 0x801CC7D4: bnel        $v1, $at, L_801CC7E8
    if (ctx->r3 != ctx->r1) {
        // 0x801CC7D8: lw          $v1, 0x3C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X3C);
            goto L_801CC7E8;
    }
    goto skip_4;
    // 0x801CC7D8: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    skip_4:
    // 0x801CC7DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801CC7E0: addiu       $v0, $v0, -0x276C
    ctx->r2 = ADD32(ctx->r2, -0X276C);
L_801CC7E4:
    // 0x801CC7E4: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
L_801CC7E8:
    // 0x801CC7E8: beql        $v1, $zero, L_801CC804
    if (ctx->r3 == 0) {
        // 0x801CC7EC: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_801CC804;
    }
    goto skip_5;
    // 0x801CC7EC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_5:
    // 0x801CC7F0: beql        $v1, $a1, L_801CC838
    if (ctx->r3 == ctx->r5) {
        // 0x801CC7F4: lw          $t9, 0x2C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X2C);
            goto L_801CC838;
    }
    goto skip_6;
    // 0x801CC7F4: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    skip_6:
    // 0x801CC7F8: b           L_801CC864
    // 0x801CC7FC: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
        goto L_801CC864;
    // 0x801CC7FC: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x801CC800: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_801CC804:
    // 0x801CC804: beql        $t8, $zero, L_801CC824
    if (ctx->r24 == 0) {
        // 0x801CC808: lw          $a1, 0x4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X4);
            goto L_801CC824;
    }
    goto skip_7;
    // 0x801CC808: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    skip_7:
    // 0x801CC80C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x801CC810: jalr        $v0
    // 0x801CC814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801CC814: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x801CC818: b           L_801CC864
    // 0x801CC81C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
        goto L_801CC864;
    // 0x801CC81C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x801CC820: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_801CC824:
    // 0x801CC824: jalr        $v0
    // 0x801CC828: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x801CC828: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x801CC82C: b           L_801CC864
    // 0x801CC830: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
        goto L_801CC864;
    // 0x801CC830: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x801CC834: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
L_801CC838:
    // 0x801CC838: beql        $t9, $zero, L_801CC858
    if (ctx->r25 == 0) {
        // 0x801CC83C: lw          $a1, 0xC($s0)
        ctx->r5 = MEM_W(ctx->r16, 0XC);
            goto L_801CC858;
    }
    goto skip_8;
    // 0x801CC83C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    skip_8:
    // 0x801CC840: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x801CC844: jalr        $v0
    // 0x801CC848: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x801CC848: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x801CC84C: b           L_801CC864
    // 0x801CC850: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
        goto L_801CC864;
    // 0x801CC850: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x801CC854: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
L_801CC858:
    // 0x801CC858: jalr        $v0
    // 0x801CC85C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x801CC85C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    after_3:
    // 0x801CC860: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
L_801CC864:
    // 0x801CC864: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801CC868: bne         $t1, $zero, L_801CC874
    if (ctx->r9 != 0) {
        // 0x801CC86C: sw          $t1, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r9;
            goto L_801CC874;
    }
    // 0x801CC86C: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x801CC870: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_801CC874:
    // 0x801CC874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CC878:
    // 0x801CC878: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CC87C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CC880: jr          $ra
    // 0x801CC884: nop

    return;
    // 0x801CC884: nop

;}
RECOMP_FUNC void M24_FUN_801cc888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC888: addiu       $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
    // 0x801CC88C: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC890: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CC894: addiu       $a2, $a2, 0x7A0
    ctx->r6 = ADD32(ctx->r6, 0X7A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc898(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC89C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC8A0: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x801CC8A4: mflo        $t6
    ctx->r14 = lo;
    // 0x801CC8A8: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801CC8AC: lw          $a3, -0x44($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X44);
    // 0x801CC8B0: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x801CC8B4: beql        $t8, $zero, L_801CC93C
    if (ctx->r24 == 0) {
        // 0x801CC8B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC93C;
    }
    goto skip_0;
    // 0x801CC8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CC8BC: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC8C0: mflo        $t9
    ctx->r25 = lo;
    // 0x801CC8C4: addu        $v0, $a2, $t9
    ctx->r2 = ADD32(ctx->r6, ctx->r25);
    // 0x801CC8C8: bne         $a1, $zero, L_801CC938
    if (ctx->r5 != 0) {
        // 0x801CC8CC: sw          $a1, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->r5;
            goto L_801CC938;
    }
    // 0x801CC8CC: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x801CC8D0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x801CC8D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CC8D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CC8DC: bnel        $a0, $at, L_801CC8F4
    if (ctx->r4 != ctx->r1) {
        // 0x801CC8E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801CC8F4;
    }
    goto skip_1;
    // 0x801CC8E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x801CC8E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801CC8E8: b           L_801CC904
    // 0x801CC8EC: addiu       $v1, $v1, -0x27BC
    ctx->r3 = ADD32(ctx->r3, -0X27BC);
        goto L_801CC904;
    // 0x801CC8EC: addiu       $v1, $v1, -0x27BC
    ctx->r3 = ADD32(ctx->r3, -0X27BC);
    // 0x801CC8F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801CC8F4:
    // 0x801CC8F4: bnel        $a0, $at, L_801CC908
    if (ctx->r4 != ctx->r1) {
        // 0x801CC8F8: lw          $t1, 0x2C($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X2C);
            goto L_801CC908;
    }
    goto skip_2;
    // 0x801CC8F8: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    skip_2:
    // 0x801CC8FC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801CC900: addiu       $v1, $v1, -0x276C
    ctx->r3 = ADD32(ctx->r3, -0X276C);
L_801CC904:
    // 0x801CC904: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
L_801CC908:
    // 0x801CC908: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CC90C: beql        $t1, $zero, L_801CC930
    if (ctx->r9 == 0) {
        // 0x801CC910: lw          $a1, 0x4($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X4);
            goto L_801CC930;
    }
    goto skip_3;
    // 0x801CC910: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    skip_3:
    // 0x801CC914: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CC918: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x801CC91C: jalr        $v1
    // 0x801CC920: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x801CC920: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    after_0:
    // 0x801CC924: b           L_801CC93C
    // 0x801CC928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CC93C;
    // 0x801CC928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC92C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
L_801CC930:
    // 0x801CC930: jalr        $v1
    // 0x801CC934: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x801CC934: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_1:
L_801CC938:
    // 0x801CC938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC93C:
    // 0x801CC93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC940: jr          $ra
    // 0x801CC944: nop

    return;
    // 0x801CC944: nop

;}
RECOMP_FUNC void M24_FUN_801cc948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC948: addiu       $t1, $zero, 0x44
    ctx->r9 = ADD32(0, 0X44);
    // 0x801CC94C: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC950: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CC954: addiu       $t0, $t0, 0x7A0
    ctx->r8 = ADD32(ctx->r8, 0X7A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc958(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC960: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x801CC964: mflo        $t6
    ctx->r14 = lo;
    // 0x801CC968: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801CC96C: lw          $a3, -0x44($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X44);
    // 0x801CC970: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x801CC974: beql        $t8, $zero, L_801CC9F0
    if (ctx->r24 == 0) {
        // 0x801CC978: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC9F0;
    }
    goto skip_0;
    // 0x801CC978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CC97C: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CC980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CC984: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CC988: mflo        $t9
    ctx->r25 = lo;
    // 0x801CC98C: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x801CC990: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x801CC994: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x801CC998: bnel        $a0, $at, L_801CC9B0
    if (ctx->r4 != ctx->r1) {
        // 0x801CC99C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801CC9B0;
    }
    goto skip_1;
    // 0x801CC99C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x801CC9A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801CC9A4: b           L_801CC9C0
    // 0x801CC9A8: addiu       $v1, $v1, -0x27BC
    ctx->r3 = ADD32(ctx->r3, -0X27BC);
        goto L_801CC9C0;
    // 0x801CC9A8: addiu       $v1, $v1, -0x27BC
    ctx->r3 = ADD32(ctx->r3, -0X27BC);
    // 0x801CC9AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801CC9B0:
    // 0x801CC9B0: bne         $a0, $at, L_801CC9C0
    if (ctx->r4 != ctx->r1) {
        // 0x801CC9B4: nop
    
            goto L_801CC9C0;
    }
    // 0x801CC9B4: nop

    // 0x801CC9B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801CC9BC: addiu       $v1, $v1, -0x276C
    ctx->r3 = ADD32(ctx->r3, -0X276C);
L_801CC9C0:
    // 0x801CC9C0: beq         $a1, $zero, L_801CC9E0
    if (ctx->r5 == 0) {
        // 0x801CC9C4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801CC9E0;
    }
    // 0x801CC9C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CC9C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801CC9CC: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x801CC9D0: jalr        $v1
    // 0x801CC9D4: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x801CC9D4: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    after_0:
    // 0x801CC9D8: b           L_801CC9F0
    // 0x801CC9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CC9F0;
    // 0x801CC9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC9E0:
    // 0x801CC9E0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801CC9E4: jalr        $v1
    // 0x801CC9E8: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x801CC9E8: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x801CC9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC9F0:
    // 0x801CC9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC9F4: jr          $ra
    // 0x801CC9F8: nop

    return;
    // 0x801CC9F8: nop

;}
RECOMP_FUNC void M24_FUN_801cc9fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC9FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cca00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cca00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCA04: sw          $zero, -0x5540($at)
    MEM_W(-0X5540, ctx->r1) = 0;
    // 0x801CCA08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCA0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCA10: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CCA14: sw          $zero, -0x553C($at)
    MEM_W(-0X553C, ctx->r1) = 0;
    // 0x801CCA18: addiu       $a1, $a1, 0xA48
    ctx->r5 = ADD32(ctx->r5, 0XA48);
    // 0x801CCA1C: jal         0x801C2608
    // 0x801CCA20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801C2608)(rdram, ctx);
        goto after_0;
    // 0x801CCA20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x801CCA24: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CCA28: addiu       $a1, $a1, 0xB38
    ctx->r5 = ADD32(ctx->r5, 0XB38);
    // 0x801CCA2C: jal         0x801C26C4
    // 0x801CCA30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801C26C4)(rdram, ctx);
        goto after_1;
    // 0x801CCA30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x801CCA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCA3C: jr          $ra
    // 0x801CCA40: nop

    return;
    // 0x801CCA40: nop

;}
RECOMP_FUNC void M24_FUN_801cca44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCA44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCA48: sw          $zero, 0x6D8($at)
    MEM_W(0X6D8, ctx->r1) = 0;
    // 0x801CCA4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCA50: sw          $zero, 0x778($at)
    MEM_W(0X778, ctx->r1) = 0;
    // 0x801CCA54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCA58: sw          $zero, 0x6DC($at)
    MEM_W(0X6DC, ctx->r1) = 0;
    // 0x801CCA5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCA60: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CCA64: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CCA68: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCA6C: addiu       $v0, $v0, 0x7A0
    ctx->r2 = ADD32(ctx->r2, 0X7A0);
    // 0x801CCA70: addiu       $a0, $a0, 0x780
    ctx->r4 = ADD32(ctx->r4, 0X780);
    // 0x801CCA74: addiu       $v1, $v1, 0x6E0
    ctx->r3 = ADD32(ctx->r3, 0X6E0);
    // 0x801CCA78: sw          $zero, 0x77C($at)
    MEM_W(0X77C, ctx->r1) = 0;
L_801CCA7C:
    // 0x801CCA7C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801CCA80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801CCA84: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x801CCA88: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801CCA8C: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x801CCA90: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801CCA94: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x801CCA98: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801CCA9C: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801CCAA0: bne         $a0, $v0, L_801CCA7C
    if (ctx->r4 != ctx->r2) {
        // 0x801CCAA4: sw          $zero, -0x10($a0)
        MEM_W(-0X10, ctx->r4) = 0;
            goto L_801CCA7C;
    }
    // 0x801CCAA4: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x801CCAA8: jr          $ra
    // 0x801CCAAC: nop

    return;
    // 0x801CCAAC: nop

;}
RECOMP_FUNC void M24_FUN_801ccab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCAB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAB4: sw          $zero, -0x5504($at)
    MEM_W(-0X5504, ctx->r1) = 0;
    // 0x801CCAB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCABC: sw          $zero, 0x7A0($at)
    MEM_W(0X7A0, ctx->r1) = 0;
    // 0x801CCAC0: sw          $zero, 0x7A4($at)
    MEM_W(0X7A4, ctx->r1) = 0;
    // 0x801CCAC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAC8: sw          $zero, 0x7A8($at)
    MEM_W(0X7A8, ctx->r1) = 0;
    // 0x801CCACC: sw          $zero, 0x7AC($at)
    MEM_W(0X7AC, ctx->r1) = 0;
    // 0x801CCAD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAD4: sw          $zero, 0x7B0($at)
    MEM_W(0X7B0, ctx->r1) = 0;
    // 0x801CCAD8: sw          $zero, 0x7B4($at)
    MEM_W(0X7B4, ctx->r1) = 0;
    // 0x801CCADC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAE0: sw          $zero, 0x7B8($at)
    MEM_W(0X7B8, ctx->r1) = 0;
    // 0x801CCAE4: sw          $zero, 0x7BC($at)
    MEM_W(0X7BC, ctx->r1) = 0;
    // 0x801CCAE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAEC: sw          $zero, 0x7C0($at)
    MEM_W(0X7C0, ctx->r1) = 0;
    // 0x801CCAF0: sw          $zero, 0x7C4($at)
    MEM_W(0X7C4, ctx->r1) = 0;
    // 0x801CCAF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCAF8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801CCAFC: sw          $t6, 0x7C8($at)
    MEM_W(0X7C8, ctx->r1) = ctx->r14;
    // 0x801CCB00: sw          $zero, 0x7CC($at)
    MEM_W(0X7CC, ctx->r1) = 0;
    // 0x801CCB04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB08: sw          $zero, 0x7D0($at)
    MEM_W(0X7D0, ctx->r1) = 0;
    // 0x801CCB0C: sw          $zero, 0x7D4($at)
    MEM_W(0X7D4, ctx->r1) = 0;
    // 0x801CCB10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB14: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801CCB18: sw          $t7, 0x7DC($at)
    MEM_W(0X7DC, ctx->r1) = ctx->r15;
    // 0x801CCB1C: sw          $zero, 0x7D8($at)
    MEM_W(0X7D8, ctx->r1) = 0;
    // 0x801CCB20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB24: sw          $zero, 0x7E0($at)
    MEM_W(0X7E0, ctx->r1) = 0;
    // 0x801CCB28: sw          $zero, 0x7E4($at)
    MEM_W(0X7E4, ctx->r1) = 0;
    // 0x801CCB2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB30: sw          $zero, 0x7E8($at)
    MEM_W(0X7E8, ctx->r1) = 0;
    // 0x801CCB34: sw          $zero, 0x7EC($at)
    MEM_W(0X7EC, ctx->r1) = 0;
    // 0x801CCB38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB3C: sw          $zero, 0x7F0($at)
    MEM_W(0X7F0, ctx->r1) = 0;
    // 0x801CCB40: sw          $zero, 0x7F4($at)
    MEM_W(0X7F4, ctx->r1) = 0;
    // 0x801CCB44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB48: sw          $zero, 0x7F8($at)
    MEM_W(0X7F8, ctx->r1) = 0;
    // 0x801CCB4C: sw          $zero, 0x7FC($at)
    MEM_W(0X7FC, ctx->r1) = 0;
    // 0x801CCB50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB54: sw          $zero, 0x800($at)
    MEM_W(0X800, ctx->r1) = 0;
    // 0x801CCB58: sw          $zero, 0x804($at)
    MEM_W(0X804, ctx->r1) = 0;
    // 0x801CCB5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801CCB64: sw          $t8, 0x80C($at)
    MEM_W(0X80C, ctx->r1) = ctx->r24;
    // 0x801CCB68: sw          $zero, 0x808($at)
    MEM_W(0X808, ctx->r1) = 0;
    // 0x801CCB6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB70: sw          $zero, 0x810($at)
    MEM_W(0X810, ctx->r1) = 0;
    // 0x801CCB74: sw          $zero, 0x814($at)
    MEM_W(0X814, ctx->r1) = 0;
    // 0x801CCB78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB7C: sw          $zero, 0x818($at)
    MEM_W(0X818, ctx->r1) = 0;
    // 0x801CCB80: sw          $zero, 0x81C($at)
    MEM_W(0X81C, ctx->r1) = 0;
    // 0x801CCB84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCB88: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CCB8C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCB90: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CCB94: addiu       $a0, $a0, 0xA48
    ctx->r4 = ADD32(ctx->r4, 0XA48);
    // 0x801CCB98: addiu       $v0, $v0, 0x828
    ctx->r2 = ADD32(ctx->r2, 0X828);
    // 0x801CCB9C: sw          $t9, 0x820($at)
    MEM_W(0X820, ctx->r1) = ctx->r25;
    // 0x801CCBA0: sw          $zero, 0x824($at)
    MEM_W(0X824, ctx->r1) = 0;
    // 0x801CCBA4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_801CCBA8:
    // 0x801CCBA8: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
    // 0x801CCBAC: sw          $zero, -0xCC($v0)
    MEM_W(-0XCC, ctx->r2) = 0;
    // 0x801CCBB0: sw          $zero, -0xC8($v0)
    MEM_W(-0XC8, ctx->r2) = 0;
    // 0x801CCBB4: sw          $zero, -0xC4($v0)
    MEM_W(-0XC4, ctx->r2) = 0;
    // 0x801CCBB8: sw          $zero, -0xC0($v0)
    MEM_W(-0XC0, ctx->r2) = 0;
    // 0x801CCBBC: sw          $zero, -0xBC($v0)
    MEM_W(-0XBC, ctx->r2) = 0;
    // 0x801CCBC0: sw          $zero, -0xB8($v0)
    MEM_W(-0XB8, ctx->r2) = 0;
    // 0x801CCBC4: sw          $zero, -0xB4($v0)
    MEM_W(-0XB4, ctx->r2) = 0;
    // 0x801CCBC8: sw          $zero, -0xB0($v0)
    MEM_W(-0XB0, ctx->r2) = 0;
    // 0x801CCBCC: sw          $zero, -0xAC($v0)
    MEM_W(-0XAC, ctx->r2) = 0;
    // 0x801CCBD0: sw          $zero, -0xA8($v0)
    MEM_W(-0XA8, ctx->r2) = 0;
    // 0x801CCBD4: sw          $v1, -0xA4($v0)
    MEM_W(-0XA4, ctx->r2) = ctx->r3;
    // 0x801CCBD8: sw          $zero, -0xA0($v0)
    MEM_W(-0XA0, ctx->r2) = 0;
    // 0x801CCBDC: sw          $zero, -0x9C($v0)
    MEM_W(-0X9C, ctx->r2) = 0;
    // 0x801CCBE0: sw          $zero, -0x98($v0)
    MEM_W(-0X98, ctx->r2) = 0;
    // 0x801CCBE4: sw          $zero, -0x94($v0)
    MEM_W(-0X94, ctx->r2) = 0;
    // 0x801CCBE8: sw          $v1, -0x90($v0)
    MEM_W(-0X90, ctx->r2) = ctx->r3;
    // 0x801CCBEC: sw          $zero, -0x8C($v0)
    MEM_W(-0X8C, ctx->r2) = 0;
    // 0x801CCBF0: sw          $zero, -0x88($v0)
    MEM_W(-0X88, ctx->r2) = 0;
    // 0x801CCBF4: sw          $zero, -0x84($v0)
    MEM_W(-0X84, ctx->r2) = 0;
    // 0x801CCBF8: sw          $zero, -0x80($v0)
    MEM_W(-0X80, ctx->r2) = 0;
    // 0x801CCBFC: sw          $zero, -0x7C($v0)
    MEM_W(-0X7C, ctx->r2) = 0;
    // 0x801CCC00: sw          $zero, -0x78($v0)
    MEM_W(-0X78, ctx->r2) = 0;
    // 0x801CCC04: sw          $zero, -0x74($v0)
    MEM_W(-0X74, ctx->r2) = 0;
    // 0x801CCC08: sw          $zero, -0x70($v0)
    MEM_W(-0X70, ctx->r2) = 0;
    // 0x801CCC0C: sw          $zero, -0x6C($v0)
    MEM_W(-0X6C, ctx->r2) = 0;
    // 0x801CCC10: sw          $zero, -0x68($v0)
    MEM_W(-0X68, ctx->r2) = 0;
    // 0x801CCC14: sw          $zero, -0x64($v0)
    MEM_W(-0X64, ctx->r2) = 0;
    // 0x801CCC18: sw          $v1, -0x60($v0)
    MEM_W(-0X60, ctx->r2) = ctx->r3;
    // 0x801CCC1C: sw          $zero, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = 0;
    // 0x801CCC20: sw          $zero, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = 0;
    // 0x801CCC24: sw          $zero, -0x54($v0)
    MEM_W(-0X54, ctx->r2) = 0;
    // 0x801CCC28: sw          $zero, -0x50($v0)
    MEM_W(-0X50, ctx->r2) = 0;
    // 0x801CCC2C: sw          $v1, -0x4C($v0)
    MEM_W(-0X4C, ctx->r2) = ctx->r3;
    // 0x801CCC30: sw          $zero, -0x48($v0)
    MEM_W(-0X48, ctx->r2) = 0;
    // 0x801CCC34: sw          $zero, -0x44($v0)
    MEM_W(-0X44, ctx->r2) = 0;
    // 0x801CCC38: sw          $zero, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = 0;
    // 0x801CCC3C: sw          $zero, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = 0;
    // 0x801CCC40: sw          $zero, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = 0;
    // 0x801CCC44: sw          $zero, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = 0;
    // 0x801CCC48: sw          $zero, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = 0;
    // 0x801CCC4C: sw          $zero, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = 0;
    // 0x801CCC50: sw          $zero, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = 0;
    // 0x801CCC54: sw          $zero, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = 0;
    // 0x801CCC58: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x801CCC5C: sw          $v1, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r3;
    // 0x801CCC60: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x801CCC64: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x801CCC68: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801CCC6C: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801CCC70: sw          $v1, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r3;
    // 0x801CCC74: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801CCC78: sw          $zero, -0x110($v0)
    MEM_W(-0X110, ctx->r2) = 0;
    // 0x801CCC7C: sw          $zero, -0x10C($v0)
    MEM_W(-0X10C, ctx->r2) = 0;
    // 0x801CCC80: sw          $zero, -0x108($v0)
    MEM_W(-0X108, ctx->r2) = 0;
    // 0x801CCC84: sw          $zero, -0x104($v0)
    MEM_W(-0X104, ctx->r2) = 0;
    // 0x801CCC88: sw          $zero, -0x100($v0)
    MEM_W(-0X100, ctx->r2) = 0;
    // 0x801CCC8C: sw          $zero, -0xFC($v0)
    MEM_W(-0XFC, ctx->r2) = 0;
    // 0x801CCC90: sw          $zero, -0xF8($v0)
    MEM_W(-0XF8, ctx->r2) = 0;
    // 0x801CCC94: sw          $zero, -0xF4($v0)
    MEM_W(-0XF4, ctx->r2) = 0;
    // 0x801CCC98: sw          $zero, -0xF0($v0)
    MEM_W(-0XF0, ctx->r2) = 0;
    // 0x801CCC9C: sw          $zero, -0xEC($v0)
    MEM_W(-0XEC, ctx->r2) = 0;
    // 0x801CCCA0: sw          $v1, -0xE8($v0)
    MEM_W(-0XE8, ctx->r2) = ctx->r3;
    // 0x801CCCA4: sw          $zero, -0xE4($v0)
    MEM_W(-0XE4, ctx->r2) = 0;
    // 0x801CCCA8: sw          $zero, -0xE0($v0)
    MEM_W(-0XE0, ctx->r2) = 0;
    // 0x801CCCAC: sw          $zero, -0xDC($v0)
    MEM_W(-0XDC, ctx->r2) = 0;
    // 0x801CCCB0: sw          $zero, -0xD8($v0)
    MEM_W(-0XD8, ctx->r2) = 0;
    // 0x801CCCB4: sw          $v1, -0xD4($v0)
    MEM_W(-0XD4, ctx->r2) = ctx->r3;
    // 0x801CCCB8: bne         $v0, $a0, L_801CCBA8
    if (ctx->r2 != ctx->r4) {
        // 0x801CCCBC: sw          $zero, -0xD0($v0)
        MEM_W(-0XD0, ctx->r2) = 0;
            goto L_801CCBA8;
    }
    // 0x801CCCBC: sw          $zero, -0xD0($v0)
    MEM_W(-0XD0, ctx->r2) = 0;
    // 0x801CCCC0: jr          $ra
    // 0x801CCCC4: nop

    return;
    // 0x801CCCC4: nop

;}
RECOMP_FUNC void M24_FUN_801cccc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCCC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CCCCC: jr          $ra
    // 0x801CCCD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CCCD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cccd4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cccd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCCD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CCCDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CCCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCCE4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CCCE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCCEC: lw          $a0, -0x54EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54EC);
    // 0x801CCCF0: jal         0x800058DC
    // 0x801CCCF4: addiu       $a1, $a1, -0x3D88
    ctx->r5 = ADD32(ctx->r5, -0X3D88);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CCCF4: addiu       $a1, $a1, -0x3D88
    ctx->r5 = ADD32(ctx->r5, -0X3D88);
    after_0:
    // 0x801CCCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCCFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCD00: jr          $ra
    // 0x801CCD04: nop

    return;
    // 0x801CCD04: nop

;}
RECOMP_FUNC void M24_FUN_801ccd08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CCD0C: jr          $ra
    // 0x801CCD10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CCD10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ccd14(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ccd14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD14: nop

    // 0x801CCD18: nop

    // 0x801CCD1C: nop

;}
RECOMP_FUNC void M24_FUN_801ccd20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCD28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCD2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CCD30: jal         0x801CCF48
    // 0x801CCD34: sw          $zero, 0xC38($at)
    MEM_W(0XC38, ctx->r1) = 0;
    LOOKUP_FUNC(0x801CCF48)(rdram, ctx);
        goto after_0;
    // 0x801CCD34: sw          $zero, 0xC38($at)
    MEM_W(0XC38, ctx->r1) = 0;
    after_0:
    // 0x801CCD38: jal         0x801BF6C4
    // 0x801CCD3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_1;
    // 0x801CCD3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801CCD40: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCD44: addiu       $a1, $a1, -0x32A0
    ctx->r5 = ADD32(ctx->r5, -0X32A0);
    // 0x801CCD48: jal         0x800058DC
    // 0x801CCD4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CCD4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801CCD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCD58: jr          $ra
    // 0x801CCD5C: nop

    return;
    // 0x801CCD5C: nop

;}
RECOMP_FUNC void M24_FUN_801ccd60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCD60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCD68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CCD6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCD70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CCD74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CCD78: jal         0x801CD71C
    // 0x801CCD7C: sw          $t6, 0xC38($at)
    MEM_W(0XC38, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801CD71C)(rdram, ctx);
        goto after_0;
    // 0x801CCD7C: sw          $t6, 0xC38($at)
    MEM_W(0XC38, ctx->r1) = ctx->r14;
    after_0:
    // 0x801CCD80: jal         0x801BF968
    // 0x801CCD84: nop

    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_1;
    // 0x801CCD84: nop

    after_1:
    // 0x801CCD88: beq         $v0, $zero, L_801CCD9C
    if (ctx->r2 == 0) {
        // 0x801CCD8C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801CCD9C;
    }
    // 0x801CCD8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CCD90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CCD94: jal         0x800058DC
    // 0x801CCD98: addiu       $a1, $a1, -0x3254
    ctx->r5 = ADD32(ctx->r5, -0X3254);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CCD98: addiu       $a1, $a1, -0x3254
    ctx->r5 = ADD32(ctx->r5, -0X3254);
    after_2:
L_801CCD9C:
    // 0x801CCD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCDA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCDA4: jr          $ra
    // 0x801CCDA8: nop

    return;
    // 0x801CCDA8: nop

;}
RECOMP_FUNC void M24_FUN_801ccdac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCDAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ccdb0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ccdb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCDB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CCDB4: sw          $a0, -0x5448($at)
    MEM_W(-0X5448, ctx->r1) = ctx->r4;
    // 0x801CCDB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CCDC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CCDC4: sw          $a1, -0x5444($at)
    MEM_W(-0X5444, ctx->r1) = ctx->r5;
    // 0x801CCDC8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CCDCC: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CCDD0: addiu       $a2, $a2, 0xCF8
    ctx->r6 = ADD32(ctx->r6, 0XCF8);
    // 0x801CCDD4: addiu       $a0, $a0, -0x5478
    ctx->r4 = ADD32(ctx->r4, -0X5478);
    // 0x801CCDD8: jal         0x801BF850
    // 0x801CCDDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_0;
    // 0x801CCDDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801CCDE0: jal         0x801CD804
    // 0x801CCDE4: nop

    LOOKUP_FUNC(0x801CD804)(rdram, ctx);
        goto after_1;
    // 0x801CCDE4: nop

    after_1:
    // 0x801CCDE8: jal         0x801CD8D0
    // 0x801CCDEC: nop

    LOOKUP_FUNC(0x801CD8D0)(rdram, ctx);
        goto after_2;
    // 0x801CCDEC: nop

    after_2:
    // 0x801CCDF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CCDF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CCDF8: jr          $ra
    // 0x801CCDFC: nop

    return;
    // 0x801CCDFC: nop

;}
RECOMP_FUNC void M24_FUN_801cce00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE00: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCE04: jr          $ra
    // 0x801CCE08: lw          $v0, 0xC38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC38);
    return;
    // 0x801CCE08: lw          $v0, 0xC38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cce0c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cce0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE0C: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x801CCE10: bne         $at, $zero, L_801CCE28
    if (ctx->r1 != 0) {
            // 0x801CCE14: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801CCE28)(rdram, ctx);
    return;
    }
    // 0x801CCE14: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801CCE18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCE1C: sw          $t6, -0x54E0($at)
    MEM_W(-0X54E0, ctx->r1) = ctx->r14;
    // 0x801CCE20: jr          $ra
    // 0x801CCE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CCE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cce28(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cce28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE28: bgez        $a0, L_801CCE40
    if (SIGNED(ctx->r4) >= 0) {
            // 0x801CCE2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    LOOKUP_FUNC(0x801CCE40)(rdram, ctx);
    return;
    }
    // 0x801CCE2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCE30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CCE34: sw          $zero, -0x54E0($at)
    MEM_W(-0X54E0, ctx->r1) = 0;
    // 0x801CCE38: jr          $ra
    // 0x801CCE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CCE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cce40(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cce40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE40: sw          $a0, -0x54E0($at)
    MEM_W(-0X54E0, ctx->r1) = ctx->r4;
    // 0x801CCE44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CCE48: jr          $ra
    // 0x801CCE4C: nop

    return;
    // 0x801CCE4C: nop

;}
RECOMP_FUNC void M24_FUN_801cce50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE50: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCE54: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x801CCE58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CCE5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CCE60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CCE64: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x801CCE68: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x801CCE6C: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // 0x801CCE70: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x801CCE74: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x801CCE78: sb          $a1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r5;
    // 0x801CCE7C: sb          $a2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r6;
    // 0x801CCE80: jr          $ra
    // 0x801CCE84: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    return;
    // 0x801CCE84: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cce88(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cce88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCE88: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCE8C: addiu       $t7, $t7, 0xBC0
    ctx->r15 = ADD32(ctx->r15, 0XBC0);
    // 0x801CCE90: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x801CCE94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801CCE98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CCE9C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CCEA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801CCEA4: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x801CCEA8: sb          $a2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r6;
    // 0x801CCEAC: sb          $a3, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r7;
    // 0x801CCEB0: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x801CCEB4: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x801CCEB8: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x801CCEBC: sb          $a3, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r7;
    // 0x801CCEC0: jr          $ra
    // 0x801CCEC4: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    return;
    // 0x801CCEC4: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ccec8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ccec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCEC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CCECC: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801CCED0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CCED4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801CCED8: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801CCEDC: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801CCEE0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801CCEE4: addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // 0x801CCEE8: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801CCEEC: bne         $a1, $v0, L_801CCEF8
    if (ctx->r5 != ctx->r2) {
        // 0x801CCEF0: sra         $a3, $a3, 24
        ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
            goto L_801CCEF8;
    }
    // 0x801CCEF0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x801CCEF4: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_801CCEF8:
    // 0x801CCEF8: bne         $a2, $v0, L_801CCF04
    if (ctx->r6 != ctx->r2) {
        // 0x801CCEFC: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_801CCF04;
    }
    // 0x801CCEFC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x801CCF00: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_801CCF04:
    // 0x801CCF04: bne         $a3, $v0, L_801CCF10
    if (ctx->r7 != ctx->r2) {
        // 0x801CCF08: lui         $t7, 0x801E
        ctx->r15 = S32(0X801E << 16);
            goto L_801CCF10;
    }
    // 0x801CCF08: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCF0C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_801CCF10:
    // 0x801CCF10: bne         $a1, $zero, L_801CCF1C
    if (ctx->r5 != 0) {
        // 0x801CCF14: addiu       $t7, $t7, 0xBC0
        ctx->r15 = ADD32(ctx->r15, 0XBC0);
            goto L_801CCF1C;
    }
    // 0x801CCF14: addiu       $t7, $t7, 0xBC0
    ctx->r15 = ADD32(ctx->r15, 0XBC0);
    // 0x801CCF18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801CCF1C:
    // 0x801CCF1C: bne         $a2, $zero, L_801CCF28
    if (ctx->r6 != 0) {
        // 0x801CCF20: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_801CCF28;
    }
    // 0x801CCF20: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801CCF24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801CCF28:
    // 0x801CCF28: bnel        $a3, $zero, L_801CCF38
    if (ctx->r7 != 0) {
        // 0x801CCF2C: sb          $a1, 0x10($v0)
        MEM_B(0X10, ctx->r2) = ctx->r5;
            goto L_801CCF38;
    }
    goto skip_0;
    // 0x801CCF2C: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    skip_0:
    // 0x801CCF30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CCF34: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
L_801CCF38:
    // 0x801CCF38: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // 0x801CCF3C: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // 0x801CCF40: jr          $ra
    // 0x801CCF44: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    return;
    // 0x801CCF44: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ccf48(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ccf48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CCF48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CCF4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CCF50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CCF54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CCF58: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CCF5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CCF60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CCF64: jal         0x80005E44
    // 0x801CCF68: addiu       $a1, $a1, -0x5458
    ctx->r5 = ADD32(ctx->r5, -0X5458);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CCF68: addiu       $a1, $a1, -0x5458
    ctx->r5 = ADD32(ctx->r5, -0X5458);
    after_0:
    // 0x801CCF6C: jal         0x80006214
    // 0x801CCF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CCF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CCF74: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CCF78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CCF7C: addiu       $v0, $v0, -0x54E0
    ctx->r2 = ADD32(ctx->r2, -0X54E0);
    // 0x801CCF80: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CCF84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CCF88: addiu       $t0, $t0, -0x2C50
    ctx->r8 = ADD32(ctx->r8, -0X2C50);
    // 0x801CCF8C: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x801CCF90: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801CCF94: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CCF98: lw          $t7, -0x5480($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5480);
    // 0x801CCF9C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801CCFA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CCFA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CCFA8: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x801CCFAC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801CCFB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCFB4: jal         0x801CCE50
    // 0x801CCFB8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_2;
    // 0x801CCFB8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    after_2:
    // 0x801CCFBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CCFC0: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x801CCFC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801CCFC8:
    // 0x801CCFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CCFCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCFD0: jal         0x801CCE88
    // 0x801CCFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801CCFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801CCFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CCFDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CCFE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CCFE4: jal         0x801CCEC8
    // 0x801CCFE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801CCFE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801CCFEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CCFF0: bnel        $s0, $s1, L_801CCFC8
    if (ctx->r16 != ctx->r17) {
        // 0x801CCFF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801CCFC8;
    }
    goto skip_0;
    // 0x801CCFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801CCFF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801CCFFC: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CD000: addiu       $t4, $t4, -0x54D8
    ctx->r12 = ADD32(ctx->r12, -0X54D8);
    // 0x801CD004: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CD008: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CD00C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801CD010: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801CD014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD018: sw          $t5, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r13;
    // 0x801CD01C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801CD020: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CD024: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x801CD028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD02C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CD030: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CD034: jr          $ra
    // 0x801CD038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CD038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd03c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd03c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD03C: jr          $ra
    // 0x801CD040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd044(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD044: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CD048: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CD04C: sb          $zero, 0xF20($v0)
    MEM_B(0XF20, ctx->r2) = 0;
    // 0x801CD050: sb          $zero, 0xF21($v0)
    MEM_B(0XF21, ctx->r2) = 0;
    // 0x801CD054: sb          $zero, 0xF22($v0)
    MEM_B(0XF22, ctx->r2) = 0;
    // 0x801CD058: sb          $zero, 0xF23($v0)
    MEM_B(0XF23, ctx->r2) = 0;
    // 0x801CD05C: sb          $zero, 0xF24($v0)
    MEM_B(0XF24, ctx->r2) = 0;
    // 0x801CD060: sb          $zero, 0xF25($v0)
    MEM_B(0XF25, ctx->r2) = 0;
    // 0x801CD064: sb          $zero, 0xF29($v0)
    MEM_B(0XF29, ctx->r2) = 0;
    // 0x801CD068: sb          $zero, 0xF2A($v0)
    MEM_B(0XF2A, ctx->r2) = 0;
    // 0x801CD06C: jr          $ra
    // 0x801CD070: sb          $zero, 0xF2B($v0)
    MEM_B(0XF2B, ctx->r2) = 0;
    return;
    // 0x801CD070: sb          $zero, 0xF2B($v0)
    MEM_B(0XF2B, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd074(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD07C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801CD080: jal         0x801C0D04
    // 0x801CD084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x801CD084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801CD088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD08C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CD090: jr          $ra
    // 0x801CD094: nop

    return;
    // 0x801CD094: nop

;}
RECOMP_FUNC void M24_FUN_801cd098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD098: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801CD09C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CD0A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801CD0A4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801CD0A8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801CD0AC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801CD0B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CD0B4: jal         0x801C0DE4
    // 0x801CD0B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x801CD0B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CD0BC: beq         $v0, $zero, L_801CD0D4
    if (ctx->r2 == 0) {
        // 0x801CD0C0: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_801CD0D4;
    }
    // 0x801CD0C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x801CD0C4: jal         0x801C0EB0
    // 0x801CD0C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x801CD0C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801CD0CC: b           L_801CD340
    // 0x801CD0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801CD340;
    // 0x801CD0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801CD0D4:
    // 0x801CD0D4: jal         0x801C0F18
    // 0x801CD0D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_2;
    // 0x801CD0D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801CD0DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801CD0E0: jal         0x80034C24
    // 0x801CD0E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801CD0E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801CD0E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD0EC: ldc1        $f4, -0x2C10($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C10);
    // 0x801CD0F0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801CD0F4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801CD0F8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CD0FC: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801CD100: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CD104: div.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801CD108: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD10C: jal         0x801CDBD4
    // 0x801CD110: nop

    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_4;
    // 0x801CD110: nop

    after_4:
    // 0x801CD114: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CD118: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CD11C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD120: nop

    // 0x801CD124: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD128: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CD12C: nop

    // 0x801CD130: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CD134: beq         $t7, $zero, L_801CD180
    if (ctx->r15 == 0) {
        // 0x801CD138: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801CD180;
    }
    // 0x801CD138: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD13C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CD140: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CD144: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801CD148: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD14C: nop

    // 0x801CD150: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801CD154: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CD158: nop

    // 0x801CD15C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CD160: bne         $t7, $zero, L_801CD178
    if (ctx->r15 != 0) {
        // 0x801CD164: nop
    
            goto L_801CD178;
    }
    // 0x801CD164: nop

    // 0x801CD168: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801CD16C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD170: b           L_801CD190
    // 0x801CD174: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801CD190;
    // 0x801CD174: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801CD178:
    // 0x801CD178: b           L_801CD190
    // 0x801CD17C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801CD190;
    // 0x801CD17C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_801CD180:
    // 0x801CD180: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801CD184: nop

    // 0x801CD188: bltz        $t7, L_801CD178
    if (SIGNED(ctx->r15) < 0) {
        // 0x801CD18C: nop
    
            goto L_801CD178;
    }
    // 0x801CD18C: nop

L_801CD190:
    // 0x801CD190: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CD194: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD198: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    // 0x801CD19C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801CD1A0: jal         0x801CDBD4
    // 0x801CD1A4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_5;
    // 0x801CD1A4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_5:
    // 0x801CD1A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CD1AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CD1B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CD1B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD1B8: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD1BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CD1C0: nop

    // 0x801CD1C4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CD1C8: beql        $t9, $zero, L_801CD218
    if (ctx->r25 == 0) {
        // 0x801CD1CC: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_801CD218;
    }
    goto skip_0;
    // 0x801CD1CC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801CD1D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CD1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CD1D8: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801CD1DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CD1E0: nop

    // 0x801CD1E4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CD1E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CD1EC: nop

    // 0x801CD1F0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CD1F4: bne         $t9, $zero, L_801CD20C
    if (ctx->r25 != 0) {
        // 0x801CD1F8: nop
    
            goto L_801CD20C;
    }
    // 0x801CD1F8: nop

    // 0x801CD1FC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x801CD200: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD204: b           L_801CD224
    // 0x801CD208: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CD224;
    // 0x801CD208: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CD20C:
    // 0x801CD20C: b           L_801CD224
    // 0x801CD210: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CD224;
    // 0x801CD210: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CD214: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_801CD218:
    // 0x801CD218: nop

    // 0x801CD21C: bltz        $t9, L_801CD20C
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CD220: nop
    
            goto L_801CD20C;
    }
    // 0x801CD220: nop

L_801CD224:
    // 0x801CD224: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CD228: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD22C: sb          $t9, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r25;
    // 0x801CD230: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801CD234: jal         0x801CDBD4
    // 0x801CD238: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_6;
    // 0x801CD238: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    after_6:
    // 0x801CD23C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CD240: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CD244: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CD248: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD24C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD250: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CD254: nop

    // 0x801CD258: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CD25C: beql        $t1, $zero, L_801CD2AC
    if (ctx->r9 == 0) {
        // 0x801CD260: mfc1        $t1, $f4
        ctx->r9 = (int32_t)ctx->f4.u32l;
            goto L_801CD2AC;
    }
    goto skip_1;
    // 0x801CD260: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801CD264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CD268: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CD26C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801CD270: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CD274: nop

    // 0x801CD278: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CD27C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CD280: nop

    // 0x801CD284: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CD288: bne         $t1, $zero, L_801CD2A0
    if (ctx->r9 != 0) {
        // 0x801CD28C: nop
    
            goto L_801CD2A0;
    }
    // 0x801CD28C: nop

    // 0x801CD290: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x801CD294: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD298: b           L_801CD2B8
    // 0x801CD29C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801CD2B8;
    // 0x801CD29C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801CD2A0:
    // 0x801CD2A0: b           L_801CD2B8
    // 0x801CD2A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801CD2B8;
    // 0x801CD2A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CD2A8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
L_801CD2AC:
    // 0x801CD2AC: nop

    // 0x801CD2B0: bltz        $t1, L_801CD2A0
    if (SIGNED(ctx->r9) < 0) {
        // 0x801CD2B4: nop
    
            goto L_801CD2A0;
    }
    // 0x801CD2B4: nop

L_801CD2B8:
    // 0x801CD2B8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CD2BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD2C0: sb          $t1, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r9;
    // 0x801CD2C4: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801CD2C8: jal         0x801CDBD4
    // 0x801CD2CC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_7;
    // 0x801CD2CC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    after_7:
    // 0x801CD2D0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801CD2D4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD2D8: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801CD2DC: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801CD2E0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801CD2E4: jal         0x801CDBD4
    // 0x801CD2E8: sb          $t3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_8;
    // 0x801CD2E8: sb          $t3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r11;
    after_8:
    // 0x801CD2EC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801CD2F0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801CD2F4: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801CD2F8: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801CD2FC: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x801CD300: jal         0x801CDBD4
    // 0x801CD304: sb          $t5, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_9;
    // 0x801CD304: sb          $t5, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r13;
    after_9:
    // 0x801CD308: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801CD30C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801CD310: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x801CD314: lbu         $a2, 0x26($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X26);
    // 0x801CD318: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801CD31C: lbu         $a3, 0x25($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X25);
    // 0x801CD320: jal         0x801CCE88
    // 0x801CD324: sb          $t7, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_10;
    // 0x801CD324: sb          $t7, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r15;
    after_10:
    // 0x801CD328: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801CD32C: lb          $a1, 0x24($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X24);
    // 0x801CD330: lb          $a2, 0x23($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X23);
    // 0x801CD334: jal         0x801CCEC8
    // 0x801CD338: lb          $a3, 0x22($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X22);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_11;
    // 0x801CD338: lb          $a3, 0x22($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X22);
    after_11:
    // 0x801CD33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CD340:
    // 0x801CD340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD344: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801CD348: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801CD34C: jr          $ra
    // 0x801CD350: nop

    return;
    // 0x801CD350: nop

;}
RECOMP_FUNC void M24_FUN_801cd354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CD358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD35C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CD360: jal         0x801C0D04
    // 0x801CD364: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x801CD364: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    after_0:
    // 0x801CD368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD36C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CD370: jr          $ra
    // 0x801CD374: nop

    return;
    // 0x801CD374: nop

;}
RECOMP_FUNC void M24_FUN_801cd378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD378: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CD37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CD380: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801CD384: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801CD388: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801CD38C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801CD390: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CD394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CD398: jal         0x801C0DE4
    // 0x801CD39C: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x801CD39C: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    after_0:
    // 0x801CD3A0: beq         $v0, $zero, L_801CD3BC
    if (ctx->r2 == 0) {
        // 0x801CD3A4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801CD3BC;
    }
    // 0x801CD3A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CD3A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CD3AC: jal         0x801C0EB0
    // 0x801CD3B0: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x801CD3B0: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    after_1:
    // 0x801CD3B4: b           L_801CD5B8
    // 0x801CD3B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801CD5B8;
    // 0x801CD3B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801CD3BC:
    // 0x801CD3BC: jal         0x801C0F18
    // 0x801CD3C0: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_2;
    // 0x801CD3C0: addiu       $a1, $zero, 0x56D8
    ctx->r5 = ADD32(0, 0X56D8);
    after_2:
    // 0x801CD3C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801CD3C8: jal         0x80034C24
    // 0x801CD3CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801CD3CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801CD3D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD3D4: ldc1        $f4, -0x2C08($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C08);
    // 0x801CD3D8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801CD3DC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801CD3E0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CD3E4: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801CD3E8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801CD3EC: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801CD3F0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801CD3F4: jal         0x801CDBD4
    // 0x801CD3F8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_4;
    // 0x801CD3F8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x801CD3FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801CD400: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CD404: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD408: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD40C: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD410: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CD414: nop

    // 0x801CD418: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CD41C: beql        $t7, $zero, L_801CD46C
    if (ctx->r15 == 0) {
        // 0x801CD420: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_801CD46C;
    }
    goto skip_0;
    // 0x801CD420: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801CD424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CD428: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CD42C: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801CD430: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CD434: nop

    // 0x801CD438: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801CD43C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CD440: nop

    // 0x801CD444: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801CD448: bne         $t7, $zero, L_801CD460
    if (ctx->r15 != 0) {
        // 0x801CD44C: nop
    
            goto L_801CD460;
    }
    // 0x801CD44C: nop

    // 0x801CD450: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801CD454: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD458: b           L_801CD478
    // 0x801CD45C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801CD478;
    // 0x801CD45C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801CD460:
    // 0x801CD460: b           L_801CD478
    // 0x801CD464: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801CD478;
    // 0x801CD464: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801CD468: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_801CD46C:
    // 0x801CD46C: nop

    // 0x801CD470: bltz        $t7, L_801CD460
    if (SIGNED(ctx->r15) < 0) {
        // 0x801CD474: nop
    
            goto L_801CD460;
    }
    // 0x801CD474: nop

L_801CD478:
    // 0x801CD478: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801CD47C: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
    // 0x801CD480: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801CD484: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801CD488: jal         0x801CDBD4
    // 0x801CD48C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_5;
    // 0x801CD48C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x801CD490: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CD494: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CD498: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CD49C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD4A0: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD4A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CD4A8: nop

    // 0x801CD4AC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CD4B0: beql        $t9, $zero, L_801CD500
    if (ctx->r25 == 0) {
        // 0x801CD4B4: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_801CD500;
    }
    goto skip_1;
    // 0x801CD4B4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x801CD4B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CD4BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CD4C0: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801CD4C4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CD4C8: nop

    // 0x801CD4CC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CD4D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CD4D4: nop

    // 0x801CD4D8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CD4DC: bne         $t9, $zero, L_801CD4F4
    if (ctx->r25 != 0) {
        // 0x801CD4E0: nop
    
            goto L_801CD4F4;
    }
    // 0x801CD4E0: nop

    // 0x801CD4E4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x801CD4E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD4EC: b           L_801CD50C
    // 0x801CD4F0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CD50C;
    // 0x801CD4F0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CD4F4:
    // 0x801CD4F4: b           L_801CD50C
    // 0x801CD4F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CD50C;
    // 0x801CD4F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CD4FC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_801CD500:
    // 0x801CD500: nop

    // 0x801CD504: bltz        $t9, L_801CD4F4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CD508: nop
    
            goto L_801CD4F4;
    }
    // 0x801CD508: nop

L_801CD50C:
    // 0x801CD50C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CD510: sb          $t9, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r25;
    // 0x801CD514: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801CD518: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801CD51C: jal         0x801CDBD4
    // 0x801CD520: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801CDBD4)(rdram, ctx);
        goto after_6;
    // 0x801CD520: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801CD524: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CD528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CD52C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801CD530: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x801CD534: lbu         $a1, 0x1E($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1E);
    // 0x801CD538: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801CD53C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CD540: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801CD544: nop

    // 0x801CD548: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801CD54C: beql        $a2, $zero, L_801CD59C
    if (ctx->r6 == 0) {
        // 0x801CD550: mfc1        $a2, $f4
        ctx->r6 = (int32_t)ctx->f4.u32l;
            goto L_801CD59C;
    }
    goto skip_2;
    // 0x801CD550: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x801CD554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CD558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CD55C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801CD560: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801CD564: nop

    // 0x801CD568: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CD56C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801CD570: nop

    // 0x801CD574: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801CD578: bne         $a2, $zero, L_801CD590
    if (ctx->r6 != 0) {
        // 0x801CD57C: nop
    
            goto L_801CD590;
    }
    // 0x801CD57C: nop

    // 0x801CD580: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801CD584: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CD588: b           L_801CD5A8
    // 0x801CD58C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801CD5A8;
    // 0x801CD58C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801CD590:
    // 0x801CD590: b           L_801CD5A8
    // 0x801CD594: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801CD5A8;
    // 0x801CD594: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801CD598: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
L_801CD59C:
    // 0x801CD59C: nop

    // 0x801CD5A0: bltz        $a2, L_801CD590
    if (SIGNED(ctx->r6) < 0) {
        // 0x801CD5A4: nop
    
            goto L_801CD590;
    }
    // 0x801CD5A4: nop

L_801CD5A8:
    // 0x801CD5A8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CD5AC: jal         0x801CCE50
    // 0x801CD5B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_7;
    // 0x801CD5B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_7:
    // 0x801CD5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CD5B8:
    // 0x801CD5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CD5BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CD5C0: jr          $ra
    // 0x801CD5C4: nop

    return;
    // 0x801CD5C4: nop

;}
RECOMP_FUNC void M24_FUN_801cd5c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD5C8: beq         $a1, $zero, L_801CD6A4
    if (ctx->r5 == 0) {
            // 0x801CD5CC: andi        $t6, $a2, 0x1
    ctx->r14 = ctx->r6 & 0X1;
    LOOKUP_FUNC(0x801CD6A4)(rdram, ctx);
    return;
    }
    // 0x801CD5CC: andi        $t6, $a2, 0x1
    ctx->r14 = ctx->r6 & 0X1;
    // 0x801CD5D0: beq         $t6, $zero, L_801CD614
    if (ctx->r14 == 0) {
            // 0x801CD5D4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    LOOKUP_FUNC(0x801CD614)(rdram, ctx);
    return;
    }
    // 0x801CD5D4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x801CD5D8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x801CD5DC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CD5E0: addiu       $t8, $t8, 0xC40
    ctx->r24 = ADD32(ctx->r24, 0XC40);
    // 0x801CD5E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801CD5E8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801CD5EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CD5F0: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x801CD5F4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CD5F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801CD5FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801CD600: lb          $t1, 0xBD0($t1)
    ctx->r9 = MEM_B(ctx->r9, 0XBD0);
    // 0x801CD604: sw          $a3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r7;
    // 0x801CD608: sb          $t1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r9;
    // 0x801CD60C: jr          $ra
    // 0x801CD610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd614(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD614: andi        $t2, $a2, 0x2
    ctx->r10 = ctx->r6 & 0X2;
    // 0x801CD618: beq         $t2, $zero, L_801CD65C
    if (ctx->r10 == 0) {
            // 0x801CD61C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    LOOKUP_FUNC(0x801CD65C)(rdram, ctx);
    return;
    }
    // 0x801CD61C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x801CD620: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x801CD624: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801CD628: addiu       $t4, $t4, 0xC40
    ctx->r12 = ADD32(ctx->r12, 0XC40);
    // 0x801CD62C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801CD630: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x801CD634: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CD638: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x801CD63C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CD640: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801CD644: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801CD648: lb          $t7, 0xBD1($t7)
    ctx->r15 = MEM_B(ctx->r15, 0XBD1);
    // 0x801CD64C: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x801CD650: sb          $t7, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r15;
    // 0x801CD654: jr          $ra
    // 0x801CD658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd65c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd65c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD65C: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x801CD660: beq         $t8, $zero, L_801CD714
    if (ctx->r24 == 0) {
        // 0x801CD664: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
        LOOKUP_FUNC(0x801CD714)(rdram, ctx);
        return;
    }
    // 0x801CD664: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801CD668: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x801CD66C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CD670: addiu       $t0, $t0, 0xC40
    ctx->r8 = ADD32(ctx->r8, 0XC40);
    // 0x801CD674: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801CD678: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x801CD67C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CD680: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x801CD684: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CD688: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x801CD68C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801CD690: lb          $t3, 0xBD2($t3)
    ctx->r11 = MEM_B(ctx->r11, 0XBD2);
    // 0x801CD694: sw          $a3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r7;
    // 0x801CD698: sb          $t3, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r11;
    // 0x801CD69C: jr          $ra
    // 0x801CD6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd6a4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd6a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD6A4: andi        $t4, $a2, 0x1
    ctx->r12 = ctx->r6 & 0X1;
    // 0x801CD6A8: beq         $t4, $zero, L_801CD6CC
    if (ctx->r12 == 0) {
            // 0x801CD6AC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    LOOKUP_FUNC(0x801CD6CC)(rdram, ctx);
    return;
    }
    // 0x801CD6AC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x801CD6B0: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x801CD6B4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801CD6B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD6BC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801CD6C0: sw          $zero, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = 0;
    // 0x801CD6C4: jr          $ra
    // 0x801CD6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd6cc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd6cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD6CC: andi        $t6, $a2, 0x2
    ctx->r14 = ctx->r6 & 0X2;
    // 0x801CD6D0: beq         $t6, $zero, L_801CD6F8
    if (ctx->r14 == 0) {
            // 0x801CD6D4: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    LOOKUP_FUNC(0x801CD6F8)(rdram, ctx);
    return;
    }
    // 0x801CD6D4: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x801CD6D8: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x801CD6DC: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x801CD6E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801CD6E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD6E8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801CD6EC: sw          $zero, 0xC44($at)
    MEM_W(0XC44, ctx->r1) = 0;
    // 0x801CD6F0: jr          $ra
    // 0x801CD6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd6f8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd6f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD6F8: beq         $t8, $zero, L_801CD714
    if (ctx->r24 == 0) {
        // 0x801CD6FC: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_801CD714;
    }
    // 0x801CD6FC: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801CD700: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x801CD704: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801CD708: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD70C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801CD710: sw          $zero, 0xC48($at)
    MEM_W(0XC48, ctx->r1) = 0;
L_801CD714:
    // 0x801CD714: jr          $ra
    // 0x801CD718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd71c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd71c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD71C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD720: sw          $zero, 0xC40($at)
    MEM_W(0XC40, ctx->r1) = 0;
    // 0x801CD724: sw          $zero, 0xC44($at)
    MEM_W(0XC44, ctx->r1) = 0;
    // 0x801CD728: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD72C: sw          $zero, 0xC48($at)
    MEM_W(0XC48, ctx->r1) = 0;
    // 0x801CD730: sb          $zero, 0xC4C($at)
    MEM_B(0XC4C, ctx->r1) = 0;
    // 0x801CD734: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD738: sw          $zero, 0xC50($at)
    MEM_W(0XC50, ctx->r1) = 0;
    // 0x801CD73C: sb          $zero, 0xC54($at)
    MEM_B(0XC54, ctx->r1) = 0;
    // 0x801CD740: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD748: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x801CD74C: sw          $zero, 0xC58($at)
    MEM_W(0XC58, ctx->r1) = 0;
    // 0x801CD750: sb          $zero, 0xC5C($at)
    MEM_B(0XC5C, ctx->r1) = 0;
    // 0x801CD754: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x801CD758: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CD75C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CD760: addiu       $t7, $t7, 0xC40
    ctx->r15 = ADD32(ctx->r15, 0XC40);
    // 0x801CD764: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801CD768: sw          $zero, 0xC60($at)
    MEM_W(0XC60, ctx->r1) = 0;
    // 0x801CD76C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801CD770: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x801CD774: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x801CD778: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x801CD77C: sb          $zero, 0x30($v1)
    MEM_B(0X30, ctx->r3) = 0;
    // 0x801CD780: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x801CD784: sb          $zero, 0x38($v1)
    MEM_B(0X38, ctx->r3) = 0;
    // 0x801CD788: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x801CD78C: sb          $zero, 0x40($v1)
    MEM_B(0X40, ctx->r3) = 0;
    // 0x801CD790: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x801CD794: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x801CD798: sw          $zero, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = 0;
    // 0x801CD79C: sw          $zero, 0x50($v1)
    MEM_W(0X50, ctx->r3) = 0;
    // 0x801CD7A0: sb          $zero, 0x54($v1)
    MEM_B(0X54, ctx->r3) = 0;
    // 0x801CD7A4: sw          $zero, 0x58($v1)
    MEM_W(0X58, ctx->r3) = 0;
    // 0x801CD7A8: sb          $zero, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = 0;
    // 0x801CD7AC: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x801CD7B0: sb          $zero, 0x64($v1)
    MEM_B(0X64, ctx->r3) = 0;
    // 0x801CD7B4: sw          $zero, 0x68($v1)
    MEM_W(0X68, ctx->r3) = 0;
    // 0x801CD7B8: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x801CD7BC: sw          $zero, 0x70($v1)
    MEM_W(0X70, ctx->r3) = 0;
    // 0x801CD7C0: sw          $zero, 0x74($v1)
    MEM_W(0X74, ctx->r3) = 0;
    // 0x801CD7C4: sb          $zero, 0x78($v1)
    MEM_B(0X78, ctx->r3) = 0;
    // 0x801CD7C8: sw          $zero, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = 0;
    // 0x801CD7CC: sb          $zero, 0x80($v1)
    MEM_B(0X80, ctx->r3) = 0;
    // 0x801CD7D0: sw          $zero, 0x84($v1)
    MEM_W(0X84, ctx->r3) = 0;
    // 0x801CD7D4: sb          $zero, 0x88($v1)
    MEM_B(0X88, ctx->r3) = 0;
    // 0x801CD7D8: sw          $zero, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = 0;
    // 0x801CD7DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801CD7E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801CD7E4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801CD7E8: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x801CD7EC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x801CD7F0: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
    // 0x801CD7F4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x801CD7F8: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x801CD7FC: jr          $ra
    // 0x801CD800: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    return;
    // 0x801CD800: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd804(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CD808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CD80C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CD810: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CD814: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801CD818: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CD81C: addiu       $s0, $s0, 0xC40
    ctx->r16 = ADD32(ctx->r16, 0XC40);
    // 0x801CD820: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801CD824: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_801CD828:
    // 0x801CD828: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CD82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CD830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CD834: beql        $t6, $zero, L_801CD854
    if (ctx->r14 == 0) {
        // 0x801CD838: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_801CD854;
    }
    goto skip_0;
    // 0x801CD838: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x801CD83C: lb          $t7, 0xC($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XC);
    // 0x801CD840: lb          $t8, 0x13($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X13);
    // 0x801CD844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD848: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801CD84C: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x801CD850: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
L_801CD854:
    // 0x801CD854: beql        $t0, $zero, L_801CD874
    if (ctx->r8 == 0) {
        // 0x801CD858: lw          $t4, 0x8($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X8);
            goto L_801CD874;
    }
    goto skip_1;
    // 0x801CD858: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x801CD85C: lb          $t1, 0x14($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X14);
    // 0x801CD860: lb          $t2, 0x1B($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1B);
    // 0x801CD864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD868: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801CD86C: sb          $t3, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r11;
    // 0x801CD870: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
L_801CD874:
    // 0x801CD874: beq         $t4, $zero, L_801CD890
    if (ctx->r12 == 0) {
        // 0x801CD878: nop
    
            goto L_801CD890;
    }
    // 0x801CD878: nop

    // 0x801CD87C: lb          $t5, 0x1C($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1C);
    // 0x801CD880: lb          $t6, 0x23($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X23);
    // 0x801CD884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CD888: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801CD88C: sb          $t7, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r15;
L_801CD890:
    // 0x801CD890: beql        $v0, $zero, L_801CD8AC
    if (ctx->r2 == 0) {
        // 0x801CD894: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801CD8AC;
    }
    goto skip_2;
    // 0x801CD894: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x801CD898: lb          $a1, 0xC($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XC);
    // 0x801CD89C: lb          $a2, 0x14($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X14);
    // 0x801CD8A0: jal         0x801CCEC8
    // 0x801CD8A4: lb          $a3, 0x1C($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1C);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_0;
    // 0x801CD8A4: lb          $a3, 0x1C($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1C);
    after_0:
    // 0x801CD8A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801CD8AC:
    // 0x801CD8AC: bne         $s1, $s2, L_801CD828
    if (ctx->r17 != ctx->r18) {
        // 0x801CD8B0: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_801CD828;
    }
    // 0x801CD8B0: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x801CD8B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CD8B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CD8BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CD8C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CD8C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CD8C8: jr          $ra
    // 0x801CD8CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CD8CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd8d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd8d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD8D0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CD8D4: addiu       $v1, $v1, -0x54E0
    ctx->r3 = ADD32(ctx->r3, -0X54E0);
    // 0x801CD8D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cd8dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cd8dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CD8DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801CD8E0: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801CD8E4: addiu       $t9, $t9, -0x2C50
    ctx->r25 = ADD32(ctx->r25, -0X2C50);
    // 0x801CD8E8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801CD8EC: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x801CD8F0: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x801CD8F4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x801CD8F8: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x801CD8FC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CD900: lw          $t6, -0x5480($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5480);
    // 0x801CD904: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801CD908: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801CD90C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801CD910: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801CD914: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801CD918: bne         $v0, $zero, L_801CD928
    if (ctx->r2 != 0) {
        // 0x801CD91C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801CD928;
    }
    // 0x801CD91C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801CD920: b           L_801CD928
    // 0x801CD924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801CD928;
    // 0x801CD924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801CD928:
    // 0x801CD928: blez        $a0, L_801CDAFC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801CD92C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801CDAFC;
    }
    // 0x801CD92C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CD930: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x801CD934: beq         $v0, $zero, L_801CD9B8
    if (ctx->r2 == 0) {
        // 0x801CD938: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_801CD9B8;
    }
    // 0x801CD938: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x801CD93C: sll         $a2, $zero, 2
    ctx->r6 = S32(0 << 2);
    // 0x801CD940: subu        $a2, $a2, $zero
    ctx->r6 = SUB32(ctx->r6, 0);
    // 0x801CD944: sll         $t6, $zero, 4
    ctx->r14 = S32(0 << 4);
    // 0x801CD948: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CD94C: addiu       $t8, $t8, 0xBC0
    ctx->r24 = ADD32(ctx->r24, 0XBC0);
    // 0x801CD950: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801CD954: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x801CD958: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CD95C: addiu       $s1, $s1, -0x547C
    ctx->r17 = ADD32(ctx->r17, -0X547C);
    // 0x801CD960: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x801CD964: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x801CD968: sll         $a1, $zero, 3
    ctx->r5 = S32(0 << 3);
    // 0x801CD96C: lui         $s2, 0xDC08
    ctx->r18 = S32(0XDC08 << 16);
L_801CD970:
    // 0x801CD970: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801CD974: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CD978: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x801CD97C: bgez        $a2, L_801CD98C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801CD980: sra         $t6, $a2, 3
        ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
            goto L_801CD98C;
    }
    // 0x801CD980: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x801CD984: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x801CD988: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801CD98C:
    // 0x801CD98C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801CD990: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x801CD994: or          $t9, $t8, $s2
    ctx->r25 = ctx->r24 | ctx->r18;
    // 0x801CD998: ori         $t6, $t9, 0xA
    ctx->r14 = ctx->r25 | 0XA;
    // 0x801CD99C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801CD9A0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x801CD9A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CD9A8: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x801CD9AC: bne         $a3, $v1, L_801CD970
    if (ctx->r7 != ctx->r3) {
        // 0x801CD9B0: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_801CD970;
    }
    // 0x801CD9B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x801CD9B4: beq         $v1, $a0, L_801CDAFC
    if (ctx->r3 == ctx->r4) {
        // 0x801CD9B8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_801CDAFC;
    }
L_801CD9B8:
    // 0x801CD9B8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801CD9BC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CD9C0: addiu       $t8, $t8, 0xBC0
    ctx->r24 = ADD32(ctx->r24, 0XBC0);
    // 0x801CD9C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x801CD9C8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x801CD9CC: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x801CD9D0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801CD9D4: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CD9D8: addiu       $s1, $s1, -0x547C
    ctx->r17 = ADD32(ctx->r17, -0X547C);
    // 0x801CD9DC: addiu       $a2, $v0, 0x30
    ctx->r6 = ADD32(ctx->r2, 0X30);
    // 0x801CD9E0: addiu       $t1, $v0, 0x48
    ctx->r9 = ADD32(ctx->r2, 0X48);
    // 0x801CD9E4: addiu       $t3, $v0, 0x60
    ctx->r11 = ADD32(ctx->r2, 0X60);
    // 0x801CD9E8: addiu       $t5, $v0, 0x78
    ctx->r13 = ADD32(ctx->r2, 0X78);
    // 0x801CD9EC: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x801CD9F0: addiu       $t2, $a3, 0x18
    ctx->r10 = ADD32(ctx->r7, 0X18);
    // 0x801CD9F4: addiu       $t4, $a3, 0x28
    ctx->r12 = ADD32(ctx->r7, 0X28);
    // 0x801CD9F8: addiu       $s0, $a3, 0x38
    ctx->r16 = ADD32(ctx->r7, 0X38);
    // 0x801CD9FC: lui         $s2, 0xDC08
    ctx->r18 = S32(0XDC08 << 16);
    // 0x801CDA00: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
L_801CDA04:
    // 0x801CDA04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801CDA08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801CDA0C: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x801CDA10: bgez        $a2, L_801CDA20
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801CDA14: sra         $t6, $a2, 3
        ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
            goto L_801CDA20;
    }
    // 0x801CDA14: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x801CDA18: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x801CDA1C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801CDA20:
    // 0x801CDA20: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801CDA24: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x801CDA28: or          $t9, $t8, $s2
    ctx->r25 = ctx->r24 | ctx->r18;
    // 0x801CDA2C: ori         $t6, $t9, 0xA
    ctx->r14 = ctx->r25 | 0XA;
    // 0x801CDA30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CDA34: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801CDA38: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801CDA3C: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x801CDA40: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    // 0x801CDA44: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x801CDA48: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x801CDA4C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801CDA50: bgez        $t1, L_801CDA60
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CDA54: sra         $t8, $t1, 3
        ctx->r24 = S32(SIGNED(ctx->r9) >> 3);
            goto L_801CDA60;
    }
    // 0x801CDA54: sra         $t8, $t1, 3
    ctx->r24 = S32(SIGNED(ctx->r9) >> 3);
    // 0x801CDA58: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x801CDA5C: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_801CDA60:
    // 0x801CDA60: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801CDA64: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x801CDA68: or          $t7, $t6, $s2
    ctx->r15 = ctx->r14 | ctx->r18;
    // 0x801CDA6C: ori         $t8, $t7, 0xA
    ctx->r24 = ctx->r15 | 0XA;
    // 0x801CDA70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801CDA74: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801CDA78: addiu       $t1, $t1, 0x60
    ctx->r9 = ADD32(ctx->r9, 0X60);
    // 0x801CDA7C: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
    // 0x801CDA80: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x801CDA84: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x801CDA88: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801CDA8C: bgez        $t3, L_801CDA9C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801CDA90: sra         $t6, $t3, 3
        ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
            goto L_801CDA9C;
    }
    // 0x801CDA90: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x801CDA94: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x801CDA98: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801CDA9C:
    // 0x801CDA9C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801CDAA0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x801CDAA4: or          $t9, $t8, $s2
    ctx->r25 = ctx->r24 | ctx->r18;
    // 0x801CDAA8: ori         $t6, $t9, 0xA
    ctx->r14 = ctx->r25 | 0XA;
    // 0x801CDAAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801CDAB0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801CDAB4: addiu       $t3, $t3, 0x60
    ctx->r11 = ADD32(ctx->r11, 0X60);
    // 0x801CDAB8: addiu       $t4, $t4, 0x40
    ctx->r12 = ADD32(ctx->r12, 0X40);
    // 0x801CDABC: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x801CDAC0: sw          $s0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r16;
    // 0x801CDAC4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x801CDAC8: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x801CDACC: bgez        $t5, L_801CDADC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801CDAD0: sra         $t8, $t5, 3
        ctx->r24 = S32(SIGNED(ctx->r13) >> 3);
            goto L_801CDADC;
    }
    // 0x801CDAD0: sra         $t8, $t5, 3
    ctx->r24 = S32(SIGNED(ctx->r13) >> 3);
    // 0x801CDAD4: addiu       $at, $t5, 0x7
    ctx->r1 = ADD32(ctx->r13, 0X7);
    // 0x801CDAD8: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_801CDADC:
    // 0x801CDADC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801CDAE0: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x801CDAE4: or          $t7, $t6, $s2
    ctx->r15 = ctx->r14 | ctx->r18;
    // 0x801CDAE8: ori         $t8, $t7, 0xA
    ctx->r24 = ctx->r15 | 0XA;
    // 0x801CDAEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801CDAF0: addiu       $t5, $t5, 0x60
    ctx->r13 = ADD32(ctx->r13, 0X60);
    // 0x801CDAF4: bne         $v1, $a0, L_801CDA04
    if (ctx->r3 != ctx->r4) {
        // 0x801CDAF8: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_801CDA04;
    }
    // 0x801CDAF8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
L_801CDAFC:
    // 0x801CDAFC: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CDB00: addiu       $s1, $s1, -0x547C
    ctx->r17 = ADD32(ctx->r17, -0X547C);
    // 0x801CDB04: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801CDB08: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801CDB0C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801CDB10: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x801CDB14: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801CDB18: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x801CDB1C: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x801CDB20: lui         $s2, 0xDC08
    ctx->r18 = S32(0XDC08 << 16);
    // 0x801CDB24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801CDB28: bgez        $t8, L_801CDB38
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801CDB2C: sra         $t9, $t8, 3
        ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
            goto L_801CDB38;
    }
    // 0x801CDB2C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x801CDB30: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x801CDB34: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_801CDB38:
    // 0x801CDB38: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x801CDB3C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801CDB40: or          $t8, $t7, $s2
    ctx->r24 = ctx->r15 | ctx->r18;
    // 0x801CDB44: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CDB48: addiu       $t6, $t6, 0xBC0
    ctx->r14 = ADD32(ctx->r14, 0XBC0);
    // 0x801CDB4C: ori         $t9, $t8, 0xA
    ctx->r25 = ctx->r24 | 0XA;
    // 0x801CDB50: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801CDB54: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801CDB58: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801CDB5C: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x801CDB60: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x801CDB64: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x801CDB68: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801CDB6C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801CDB70: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x801CDB74: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x801CDB78: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x801CDB7C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x801CDB80: jr          $ra
    // 0x801CDB84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CDB84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdb88(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cdb88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CDB88: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CDB8C: jr          $ra
    // 0x801CDB90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CDB90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cdb94(rdram, ctx);
;}
