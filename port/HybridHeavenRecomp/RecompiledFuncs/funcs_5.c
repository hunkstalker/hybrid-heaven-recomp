#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_800162ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800162EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800162F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800162F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800162F8: jal         0x80016CE4
    // 0x800162FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_0;
    // 0x800162FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_0:
    // 0x80016300: beq         $v0, $zero, L_80016318
    if (ctx->r2 == 0) {
        // 0x80016304: nop
    
            goto L_80016318;
    }
    // 0x80016304: nop

L_80016308:
    // 0x80016308: jal         0x80016CE4
    // 0x8001630C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_1;
    // 0x8001630C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
    // 0x80016310: bne         $v0, $zero, L_80016308
    if (ctx->r2 != 0) {
        // 0x80016314: nop
    
            goto L_80016308;
    }
    // 0x80016314: nop

L_80016318:
    // 0x80016318: jal         0x80016D50
    // 0x8001631C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_2;
    // 0x8001631C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80016320: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80016324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016328: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x8001632C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80016330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016338: jr          $ra
    // 0x8001633C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x8001633C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016340(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001634C: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x80016350: slti        $at, $a1, 0xF
    ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
    // 0x80016354: bne         $at, $zero, L_800163A4
    if (ctx->r1 != 0) {
        // 0x80016358: nop
    
            goto L_800163A4;
    }
    // 0x80016358: nop

    // 0x8001635C: jal         0x80016CE4
    // 0x80016360: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_0;
    // 0x80016360: nop

    after_0:
    // 0x80016364: beq         $v0, $zero, L_80016388
    if (ctx->r2 == 0) {
        // 0x80016368: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80016388;
    }
    // 0x80016368: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001636C: jal         0x80016D50
    // 0x80016370: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_1;
    // 0x80016370: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x80016374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016378: jal         0x80016500
    // 0x8001637C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80016500)(rdram, ctx);
        goto after_2;
    // 0x8001637C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80016380: b           L_800163B0
    // 0x80016384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800163B0;
    // 0x80016384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016388:
    // 0x80016388: jal         0x80016D50
    // 0x8001638C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_3;
    // 0x8001638C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    after_3:
    // 0x80016390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016394: jal         0x8001643C
    // 0x80016398: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001643C)(rdram, ctx);
        goto after_4;
    // 0x80016398: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8001639C: b           L_800163B0
    // 0x800163A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800163B0;
    // 0x800163A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800163A4:
    // 0x800163A4: jal         0x80016D50
    // 0x800163A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_5;
    // 0x800163A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x800163AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800163B0:
    // 0x800163B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800163B4: jr          $ra
    // 0x800163B8: nop

    return;
    // 0x800163B8: nop

;}
RECOMP_FUNC void FUN_800163bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800163BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800163C0: addiu       $v1, $v1, -0x2358
    ctx->r3 = ADD32(ctx->r3, -0X2358);
    // 0x800163C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800163C8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
L_800163CC:
    // 0x800163CC: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    // 0x800163D0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x800163D4: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x800163D8: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x800163DC: addiu       $t7, $v0, 0x3
    ctx->r15 = ADD32(ctx->r2, 0X3);
    // 0x800163E0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800163E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800163E8: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x800163EC: sh          $a0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r4;
    // 0x800163F0: sh          $a2, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r6;
    // 0x800163F4: sh          $a1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r5;
    // 0x800163F8: sh          $a1, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r5;
    // 0x800163FC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80016400: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80016404: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x80016408: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8001640C: sh          $zero, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = 0;
    // 0x80016410: sh          $a0, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r4;
    // 0x80016414: bne         $a2, $a3, L_800163CC
    if (ctx->r6 != ctx->r7) {
        // 0x80016418: sh          $t6, -0x16($v1)
        MEM_H(-0X16, ctx->r3) = ctx->r14;
            goto L_800163CC;
    }
    // 0x80016418: sh          $t6, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r14;
    // 0x8001641C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80016420: addiu       $v0, $v0, -0x2358
    ctx->r2 = ADD32(ctx->r2, -0X2358);
    // 0x80016424: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80016428: sh          $zero, 0x2FE($v0)
    MEM_H(0X2FE, ctx->r2) = 0;
    // 0x8001642C: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x80016430: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80016434: jr          $ra
    // 0x80016438: sw          $zero, -0x2058($at)
    MEM_W(-0X2058, ctx->r1) = 0;
    return;
    // 0x80016438: sw          $zero, -0x2058($at)
    MEM_W(-0X2058, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001643c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001643c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001643C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80016440: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80016444: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80016448: bne         $t6, $at, L_800164A8
    if (ctx->r14 != ctx->r1) {
        // 0x8001644C: addiu       $v1, $v1, -0x2058
        ctx->r3 = ADD32(ctx->r3, -0X2058);
            goto L_800164A8;
    }
    // 0x8001644C: addiu       $v1, $v1, -0x2058
    ctx->r3 = ADD32(ctx->r3, -0X2058);
    // 0x80016450: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80016454: addiu       $v1, $v1, -0x2058
    ctx->r3 = ADD32(ctx->r3, -0X2058);
    // 0x80016458: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8001645C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80016460: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80016464: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016468: addiu       $a0, $a0, -0x2358
    ctx->r4 = ADD32(ctx->r4, -0X2358);
    // 0x8001646C: sra         $t7, $a1, 5
    ctx->r15 = S32(SIGNED(ctx->r5) >> 5);
    // 0x80016470: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80016474: andi        $t9, $a1, 0x1F
    ctx->r25 = ctx->r5 & 0X1F;
    // 0x80016478: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8001647C: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80016480: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80016484: mflo        $t2
    ctx->r10 = lo;
    // 0x80016488: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8001648C: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80016490: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016494: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80016498: mflo        $t6
    ctx->r14 = lo;
    // 0x8001649C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800164A0: jr          $ra
    // 0x800164A4: sh          $a1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r5;
    return;
    // 0x800164A4: sh          $a1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r5;
L_800164A8:
    // 0x800164A8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800164AC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800164B0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800164B4: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800164B8: addiu       $a0, $a0, -0x2358
    ctx->r4 = ADD32(ctx->r4, -0X2358);
    // 0x800164BC: andi        $t9, $a1, 0xFFC0
    ctx->r25 = ctx->r5 & 0XFFC0;
    // 0x800164C0: andi        $t0, $a1, 0x3E
    ctx->r8 = ctx->r5 & 0X3E;
    // 0x800164C4: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x800164C8: sra         $t8, $t9, 5
    ctx->r24 = S32(SIGNED(ctx->r25) >> 5);
    // 0x800164CC: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800164D0: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x800164D4: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x800164D8: mflo        $t5
    ctx->r13 = lo;
    // 0x800164DC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800164E0: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800164E4: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800164E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800164EC: mflo        $t0
    ctx->r8 = lo;
    // 0x800164F0: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800164F4: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x800164F8: jr          $ra
    // 0x800164FC: nop

    return;
    // 0x800164FC: nop

;}
RECOMP_FUNC void FUN_80016500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016500: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80016504: addiu       $a3, $a3, -0x2058
    ctx->r7 = ADD32(ctx->r7, -0X2058);
    // 0x80016508: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001650C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80016510: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80016514: beq         $a1, $v0, L_80016594
    if (ctx->r5 == ctx->r2) {
        // 0x80016518: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80016594;
    }
    // 0x80016518: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8001651C: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016520: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80016524: addiu       $t0, $t0, -0x2358
    ctx->r8 = ADD32(ctx->r8, -0X2358);
    // 0x80016528: mflo        $t6
    ctx->r14 = lo;
    // 0x8001652C: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x80016530: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80016534: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80016538: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001653C: mflo        $t9
    ctx->r25 = lo;
    // 0x80016540: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80016544: sh          $t7, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r15;
    // 0x80016548: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x8001654C: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x80016550: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016554: mflo        $t5
    ctx->r13 = lo;
    // 0x80016558: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x8001655C: sh          $t3, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r11;
    // 0x80016560: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016564: mflo        $t8
    ctx->r24 = lo;
    // 0x80016568: addu        $a0, $t0, $t8
    ctx->r4 = ADD32(ctx->r8, ctx->r24);
    // 0x8001656C: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80016570: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016574: mflo        $t7
    ctx->r15 = lo;
    // 0x80016578: addu        $t2, $t0, $t7
    ctx->r10 = ADD32(ctx->r8, ctx->r15);
    // 0x8001657C: sh          $a1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r5;
    // 0x80016580: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x80016584: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x80016588: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x8001658C: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x80016590: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80016594:
    // 0x80016594: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80016598: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8001659C: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x800165A0: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x800165A4: addiu       $t3, $t3, -0x2358
    ctx->r11 = ADD32(ctx->r11, -0X2358);
    // 0x800165A8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800165AC: bne         $t6, $at, L_800165BC
    if (ctx->r14 != ctx->r1) {
        // 0x800165B0: addu        $v1, $t5, $t3
        ctx->r3 = ADD32(ctx->r13, ctx->r11);
            goto L_800165BC;
    }
    // 0x800165B0: addu        $v1, $t5, $t3
    ctx->r3 = ADD32(ctx->r13, ctx->r11);
    // 0x800165B4: jr          $ra
    // 0x800165B8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    return;
    // 0x800165B8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800165BC:
    // 0x800165BC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800165C0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800165C4: jr          $ra
    // 0x800165C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800165C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800165cc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800165cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800165CC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800165D0: lw          $t7, -0x236C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X236C);
    // 0x800165D4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800165D8: lw          $t6, -0x2054($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2054);
    // 0x800165DC: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800165E0: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x800165E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800165E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800165EC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800165F0: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x800165F4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800165F8: lhu         $v1, 0x0($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X0);
    // 0x800165FC: andi        $t3, $v1, 0x3E
    ctx->r11 = ctx->r3 & 0X3E;
    // 0x80016600: andi        $t7, $v1, 0x7C0
    ctx->r15 = ctx->r3 & 0X7C0;
    // 0x80016604: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80016608: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8001660C: andi        $t0, $v1, 0xF800
    ctx->r8 = ctx->r3 & 0XF800;
    // 0x80016610: sra         $t1, $t0, 11
    ctx->r9 = S32(SIGNED(ctx->r8) >> 11);
    // 0x80016614: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80016618: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x8001661C: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x80016620: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80016624: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80016628: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x8001662C: jr          $ra
    // 0x80016630: or          $v0, $t3, $t4
    ctx->r2 = ctx->r11 | ctx->r12;
    return;
    // 0x80016630: or          $v0, $t3, $t4
    ctx->r2 = ctx->r11 | ctx->r12;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016634(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016634: bltz        $a1, L_800166CC
    if (SIGNED(ctx->r5) < 0) {
        // 0x80016638: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800166CC;
    }
    // 0x80016638: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001663C: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
    // 0x80016640: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016644: beq         $at, $zero, L_800166CC
    if (ctx->r1 == 0) {
        // 0x80016648: nop
    
            goto L_800166CC;
    }
    // 0x80016648: nop

    // 0x8001664C: bltz        $a2, L_800166CC
    if (SIGNED(ctx->r6) < 0) {
        // 0x80016650: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_800166CC;
    }
    // 0x80016650: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80016654: lw          $t6, -0x2368($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2368);
    // 0x80016658: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x8001665C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80016660: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80016664: bne         $at, $zero, L_800166CC
    if (ctx->r1 != 0) {
        // 0x80016668: sll         $t0, $t9, 11
        ctx->r8 = S32(ctx->r25 << 11);
            goto L_800166CC;
    }
    // 0x80016668: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x8001666C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80016670: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80016674: andi        $t1, $a3, 0x7C0
    ctx->r9 = ctx->r7 & 0X7C0;
    // 0x80016678: bne         $t7, $at, L_80016688
    if (ctx->r15 != ctx->r1) {
        // 0x8001667C: sra         $t2, $t1, 6
        ctx->r10 = S32(SIGNED(ctx->r9) >> 6);
            goto L_80016688;
    }
    // 0x8001667C: sra         $t2, $t1, 6
    ctx->r10 = S32(SIGNED(ctx->r9) >> 6);
    // 0x80016680: b           L_8001668C
    // 0x80016684: andi        $v1, $a3, 0x1
    ctx->r3 = ctx->r7 & 0X1;
        goto L_8001668C;
    // 0x80016684: andi        $v1, $a3, 0x1
    ctx->r3 = ctx->r7 & 0X1;
L_80016688:
    // 0x80016688: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001668C:
    // 0x8001668C: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016690: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80016694: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80016698: lw          $t1, -0x2054($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2054);
    // 0x8001669C: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800166A0: andi        $t5, $a3, 0xF800
    ctx->r13 = ctx->r7 & 0XF800;
    // 0x800166A4: sra         $t6, $t5, 11
    ctx->r14 = S32(SIGNED(ctx->r13) >> 11);
    // 0x800166A8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800166AC: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800166B0: sll         $t5, $a1, 1
    ctx->r13 = S32(ctx->r5 << 1);
    // 0x800166B4: mflo        $t2
    ctx->r10 = lo;
    // 0x800166B8: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800166BC: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x800166C0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800166C4: or          $t9, $t8, $v1
    ctx->r25 = ctx->r24 | ctx->r3;
    // 0x800166C8: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
L_800166CC:
    // 0x800166CC: jr          $ra
    // 0x800166D0: nop

    return;
    // 0x800166D0: nop

;}
RECOMP_FUNC void FUN_800166d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800166D4: bltz        $a0, L_80016728
    if (SIGNED(ctx->r4) < 0) {
        // 0x800166D8: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80016728;
    }
    // 0x800166D8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800166DC: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
    // 0x800166E0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800166E4: beq         $at, $zero, L_80016728
    if (ctx->r1 == 0) {
        // 0x800166E8: nop
    
            goto L_80016728;
    }
    // 0x800166E8: nop

    // 0x800166EC: bltz        $a1, L_80016728
    if (SIGNED(ctx->r5) < 0) {
        // 0x800166F0: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_80016728;
    }
    // 0x800166F0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800166F4: lw          $t6, -0x2368($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2368);
    // 0x800166F8: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800166FC: bne         $at, $zero, L_80016728
    if (ctx->r1 != 0) {
        // 0x80016700: nop
    
            goto L_80016728;
    }
    // 0x80016700: nop

    // 0x80016704: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016708: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001670C: lw          $t7, -0x2054($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2054);
    // 0x80016710: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80016714: mflo        $t8
    ctx->r24 = lo;
    // 0x80016718: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001671C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80016720: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80016724: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80016728:
    // 0x80016728: jr          $ra
    // 0x8001672C: nop

    return;
    // 0x8001672C: nop

;}
RECOMP_FUNC void FUN_80016730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001673C: bltz        $a1, L_800167EC
    if (SIGNED(ctx->r5) < 0) {
        // 0x80016740: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800167EC;
    }
    // 0x80016740: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80016744: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80016748: addiu       $v1, $v1, -0x236C
    ctx->r3 = ADD32(ctx->r3, -0X236C);
    // 0x8001674C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80016750: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016754: beql        $at, $zero, L_800167F0
    if (ctx->r1 == 0) {
        // 0x80016758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800167F0;
    }
    goto skip_0;
    // 0x80016758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001675C: bltz        $a2, L_800167EC
    if (SIGNED(ctx->r6) < 0) {
        // 0x80016760: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_800167EC;
    }
    // 0x80016760: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80016764: lw          $t7, -0x2368($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2368);
    // 0x80016768: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x8001676C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80016770: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80016774: bne         $at, $zero, L_800167EC
    if (ctx->r1 != 0) {
        // 0x80016778: sll         $t0, $t9, 11
        ctx->r8 = S32(ctx->r25 << 11);
            goto L_800167EC;
    }
    // 0x80016778: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x8001677C: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016780: andi        $t1, $a3, 0x7C0
    ctx->r9 = ctx->r7 & 0X7C0;
    // 0x80016784: sra         $t2, $t1, 6
    ctx->r10 = S32(SIGNED(ctx->r9) >> 6);
    // 0x80016788: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8001678C: andi        $t5, $a3, 0xF800
    ctx->r13 = ctx->r7 & 0XF800;
    // 0x80016790: sra         $t6, $t5, 11
    ctx->r14 = S32(SIGNED(ctx->r13) >> 11);
    // 0x80016794: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80016798: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001679C: lw          $t2, -0x2054($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2054);
    // 0x800167A0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800167A4: mflo        $t0
    ctx->r8 = lo;
    // 0x800167A8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800167AC: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x800167B0: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x800167B4: andi        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 & 0X1;
    // 0x800167B8: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800167BC: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x800167C0: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800167C4: sh          $t1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r9;
    // 0x800167C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800167CC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800167D0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800167D4: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800167D8: lw          $a0, -0x204C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X204C);
    // 0x800167DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800167E0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x800167E4: jal         0x80016B40
    // 0x800167E8: nop

    LOOKUP_FUNC(0x80016B40)(rdram, ctx);
        goto after_0;
    // 0x800167E8: nop

    after_0:
L_800167EC:
    // 0x800167EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800167F0:
    // 0x800167F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800167F4: jr          $ra
    // 0x800167F8: nop

    return;
    // 0x800167F8: nop

    // 0x800167FC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80016800: lw          $t6, -0x236C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X236C);
    // 0x80016804: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80016808: lw          $t9, -0x2050($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2050);
    // 0x8001680C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016810: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016814: mflo        $t7
    ctx->r15 = lo;
    // 0x80016818: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8001681C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016820: jr          $ra
    // 0x80016824: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    return;
    // 0x80016824: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016828(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001682C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016834: bltz        $a1, L_80016868
    if (SIGNED(ctx->r5) < 0) {
        // 0x80016838: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80016868;
    }
    // 0x80016838: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001683C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80016840: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
    // 0x80016844: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016848: beq         $at, $zero, L_80016868
    if (ctx->r1 == 0) {
        // 0x8001684C: nop
    
            goto L_80016868;
    }
    // 0x8001684C: nop

    // 0x80016850: bltz        $a2, L_80016868
    if (SIGNED(ctx->r6) < 0) {
        // 0x80016854: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_80016868;
    }
    // 0x80016854: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80016858: lw          $t7, -0x2368($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2368);
    // 0x8001685C: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80016860: beq         $at, $zero, L_80016870
    if (ctx->r1 == 0) {
        // 0x80016864: nop
    
            goto L_80016870;
    }
    // 0x80016864: nop

L_80016868:
    // 0x80016868: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001686C: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
L_80016870:
    // 0x80016870: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016874: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80016878: lw          $t8, -0x2050($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2050);
    // 0x8001687C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80016880: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80016884: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80016888: mflo        $t9
    ctx->r25 = lo;
    // 0x8001688C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016890: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80016894: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x80016898: lw          $t3, -0x236C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X236C);
    // 0x8001689C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800168A0: lw          $a0, -0x204C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X204C);
    // 0x800168A4: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168A8: mflo        $t4
    ctx->r12 = lo;
    // 0x800168AC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800168B0: jal         0x80016B40
    // 0x800168B4: nop

    LOOKUP_FUNC(0x80016B40)(rdram, ctx);
        goto after_0;
    // 0x800168B4: nop

    after_0:
    // 0x800168B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800168BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800168C0: jr          $ra
    // 0x800168C4: nop

    return;
    // 0x800168C4: nop

    // 0x800168C8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800168CC: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
    // 0x800168D0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800168D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800168D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800168DC: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x800168E0: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168E4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800168E8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800168EC: mflo        $t6
    ctx->r14 = lo;
    // 0x800168F0: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x800168F4: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800168F8: beq         $t7, $zero, L_80016924
    if (ctx->r15 == 0) {
        // 0x800168FC: nop
    
            goto L_80016924;
    }
    // 0x800168FC: nop

    // 0x80016900: lw          $t9, -0x2050($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2050);
    // 0x80016904: bgez        $v1, L_80016914
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80016908: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80016914;
    }
    // 0x80016908: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8001690C: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80016910: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80016914:
    // 0x80016914: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016918: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8001691C: jr          $ra
    // 0x80016920: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    return;
    // 0x80016920: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_80016924:
    // 0x80016924: lw          $t2, -0x2050($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2050);
    // 0x80016928: bgez        $v1, L_80016938
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001692C: sra         $t1, $v1, 1
        ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80016938;
    }
    // 0x8001692C: sra         $t1, $v1, 1
    ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80016930: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80016934: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80016938:
    // 0x80016938: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001693C: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x80016940: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x80016944: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80016948: jr          $ra
    // 0x8001694C: nop

    return;
    // 0x8001694C: nop

;}
RECOMP_FUNC void FUN_80016950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016950: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80016954: lw          $v0, -0x236C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X236C);
    // 0x80016958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001695C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80016960: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80016964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001696C: bltz        $a1, L_80016A14
    if (SIGNED(ctx->r5) < 0) {
        // 0x80016970: and         $v1, $v1, $at
        ctx->r3 = ctx->r3 & ctx->r1;
            goto L_80016A14;
    }
    // 0x80016970: and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // 0x80016974: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016978: beql        $at, $zero, L_80016A18
    if (ctx->r1 == 0) {
        // 0x8001697C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016A18;
    }
    goto skip_0;
    // 0x8001697C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80016980: bltz        $a2, L_80016A14
    if (SIGNED(ctx->r6) < 0) {
        // 0x80016984: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_80016A14;
    }
    // 0x80016984: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80016988: lw          $t6, -0x2368($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2368);
    // 0x8001698C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80016990: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80016994: bnel        $at, $zero, L_80016A18
    if (ctx->r1 != 0) {
        // 0x80016998: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016A18;
    }
    goto skip_1;
    // 0x80016998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8001699C: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800169A0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800169A4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800169A8: mflo        $t7
    ctx->r15 = lo;
    // 0x800169AC: addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    // 0x800169B0: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x800169B4: beq         $t8, $zero, L_800169E4
    if (ctx->r24 == 0) {
        // 0x800169B8: nop
    
            goto L_800169E4;
    }
    // 0x800169B8: nop

    // 0x800169BC: lw          $t0, -0x2050($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2050);
    // 0x800169C0: bgez        $a1, L_800169D0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800169C4: sra         $t9, $a1, 1
        ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800169D0;
    }
    // 0x800169C4: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800169C8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800169CC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800169D0:
    // 0x800169D0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800169D4: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x800169D8: or          $t3, $t1, $a3
    ctx->r11 = ctx->r9 | ctx->r7;
    // 0x800169DC: b           L_80016A0C
    // 0x800169E0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
        goto L_80016A0C;
    // 0x800169E0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_800169E4:
    // 0x800169E4: lw          $t5, -0x2050($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2050);
    // 0x800169E8: bgez        $a1, L_800169F8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800169EC: sra         $t4, $a1, 1
        ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800169F8;
    }
    // 0x800169EC: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800169F0: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800169F4: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_800169F8:
    // 0x800169F8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800169FC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80016A00: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x80016A04: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80016A08: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80016A0C:
    // 0x80016A0C: jal         0x80016B40
    // 0x80016A10: lw          $a0, -0x204C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X204C);
    LOOKUP_FUNC(0x80016B40)(rdram, ctx);
        goto after_0;
    // 0x80016A10: lw          $a0, -0x204C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X204C);
    after_0:
L_80016A14:
    // 0x80016A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016A18:
    // 0x80016A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016A1C: jr          $ra
    // 0x80016A20: nop

    return;
    // 0x80016A20: nop

;}
RECOMP_FUNC void FUN_80016a24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A24: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80016A28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80016A2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016A30: addiu       $a3, $a3, -0x369C
    ctx->r7 = ADD32(ctx->r7, -0X369C);
    // 0x80016A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016A38: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80016A3C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80016A40:
    // 0x80016A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016A44: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x80016A48: addu        $t6, $a3, $a0
    ctx->r14 = ADD32(ctx->r7, ctx->r4);
L_80016A4C:
    // 0x80016A4C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80016A50: bnel        $a2, $t7, L_80016A6C
    if (ctx->r6 != ctx->r15) {
        // 0x80016A54: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80016A6C;
    }
    goto skip_0;
    // 0x80016A54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80016A58: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x80016A5C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80016A60: b           L_80016A7C
    // 0x80016A64: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
        goto L_80016A7C;
    // 0x80016A64: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80016A68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80016A6C:
    // 0x80016A6C: bnel        $a0, $t1, L_80016A4C
    if (ctx->r4 != ctx->r9) {
        // 0x80016A70: addu        $t6, $a3, $a0
        ctx->r14 = ADD32(ctx->r7, ctx->r4);
            goto L_80016A4C;
    }
    goto skip_1;
    // 0x80016A70: addu        $t6, $a3, $a0
    ctx->r14 = ADD32(ctx->r7, ctx->r4);
    skip_1:
    // 0x80016A74: jr          $ra
    // 0x80016A78: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    return;
    // 0x80016A78: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
L_80016A7C:
    // 0x80016A7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80016A80: sllv        $t8, $a0, $a2
    ctx->r24 = S32(ctx->r4 << (ctx->r6 & 31));
    // 0x80016A84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80016A88: bne         $v0, $t0, L_80016A40
    if (ctx->r2 != ctx->r8) {
        // 0x80016A8C: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_80016A40;
    }
    // 0x80016A8C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80016A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016A94: jr          $ra
    // 0x80016A98: nop

    return;
    // 0x80016A98: nop

;}
RECOMP_FUNC void FUN_80016a9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016AA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016AA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016AA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80016AAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016AB0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80016AB4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80016AB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016ABC: blezl       $v1, L_80016B2C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80016AC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016B2C;
    }
    goto skip_0;
    // 0x80016AC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80016AC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80016AC8:
    // 0x80016AC8: blez        $v0, L_80016B18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016ACC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80016B18;
    }
    // 0x80016ACC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016AD0: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
L_80016AD4:
    // 0x80016AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80016AD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016ADC: jalr        $t9
    // 0x80016AE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80016AE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x80016AE4: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x80016AE8: andi        $t7, $v0, 0xFFFE
    ctx->r15 = ctx->r2 & 0XFFFE;
    // 0x80016AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016AF0: bnel        $t6, $t7, L_80016B04
    if (ctx->r14 != ctx->r15) {
        // 0x80016AF4: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_80016B04;
    }
    goto skip_1;
    // 0x80016AF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80016AF8: jal         0x800166D4
    // 0x80016AFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800166D4)(rdram, ctx);
        goto after_1;
    // 0x80016AFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80016B00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80016B04:
    // 0x80016B04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80016B08: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016B0C: bnel        $at, $zero, L_80016AD4
    if (ctx->r1 != 0) {
        // 0x80016B10: lw          $t9, 0x28($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X28);
            goto L_80016AD4;
    }
    goto skip_2;
    // 0x80016B10: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    skip_2:
    // 0x80016B14: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
L_80016B18:
    // 0x80016B18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80016B1C: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80016B20: bne         $at, $zero, L_80016AC8
    if (ctx->r1 != 0) {
        // 0x80016B24: nop
    
            goto L_80016AC8;
    }
    // 0x80016B24: nop

    // 0x80016B28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016B2C:
    // 0x80016B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016B30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016B34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016B38: jr          $ra
    // 0x80016B3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016B3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016b40(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016b40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B40: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80016B44: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80016B48: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80016B4C: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x80016B50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80016B54: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80016B58: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80016B5C: jr          $ra
    // 0x80016B60: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80016B60: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80016B64: jr          $ra
    // 0x80016B68: nop

    return;
    // 0x80016B68: nop

;}
RECOMP_FUNC void FUN_80016b6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B6C: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80016B70: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80016B74: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80016B78: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x80016B7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80016B80: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80016B84: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80016B88: beq         $t2, $zero, L_80016B98
    if (ctx->r10 == 0) {
        // 0x80016B8C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80016B98;
    }
    // 0x80016B8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016B90: jr          $ra
    // 0x80016B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80016B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016B98:
    // 0x80016B98: jr          $ra
    // 0x80016B9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80016B9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016ba0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016ba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016BA4: addiu       $a2, $a0, 0x7
    ctx->r6 = ADD32(ctx->r4, 0X7);
    // 0x80016BA8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80016BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016BB0: and         $a0, $a2, $at
    ctx->r4 = ctx->r6 & ctx->r1;
    // 0x80016BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80016BB8: jal         0x8001F290
    // 0x80016BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x80016BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016BC0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80016BC4: bne         $v0, $zero, L_80016C70
    if (ctx->r2 != 0) {
        // 0x80016BC8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80016C70;
    }
    // 0x80016BC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80016BCC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80016BD0: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80016BD4: lh          $t6, 0xA4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA4);
    // 0x80016BD8: beq         $t6, $zero, L_80016C68
    if (ctx->r14 == 0) {
        // 0x80016BDC: nop
    
            goto L_80016C68;
    }
    // 0x80016BDC: nop

    // 0x80016BE0: jal         0x80001060
    // 0x80016BE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_1;
    // 0x80016BE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80016BE8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80016BEC: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80016BF0: beq         $v0, $zero, L_80016C24
    if (ctx->r2 == 0) {
        // 0x80016BF4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80016C24;
    }
    // 0x80016BF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80016BF8: lh          $v0, 0xA0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA0);
    // 0x80016BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016C00: lui         $t8, 0x8040
    ctx->r24 = S32(0X8040 << 16);
    // 0x80016C04: bne         $v0, $at, L_80016C14
    if (ctx->r2 != ctx->r1) {
        // 0x80016C08: addiu       $t8, $t8, 0x0
        ctx->r24 = ADD32(ctx->r24, 0X0);
            goto L_80016C14;
    }
    // 0x80016C08: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80016C0C: b           L_80016C18
    // 0x80016C10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80016C18;
    // 0x80016C10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80016C14:
    // 0x80016C14: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80016C18:
    // 0x80016C18: sll         $t7, $v1, 20
    ctx->r15 = S32(ctx->r3 << 20);
    // 0x80016C1C: b           L_80016C7C
    // 0x80016C20: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
        goto L_80016C7C;
    // 0x80016C20: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
L_80016C24:
    // 0x80016C24: lh          $v0, 0xA0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA0);
    // 0x80016C28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016C2C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80016C30: bne         $v0, $at, L_80016C40
    if (ctx->r2 != ctx->r1) {
        // 0x80016C34: addiu       $t0, $t0, -0x800
        ctx->r8 = ADD32(ctx->r8, -0X800);
            goto L_80016C40;
    }
    // 0x80016C34: addiu       $t0, $t0, -0x800
    ctx->r8 = ADD32(ctx->r8, -0X800);
    // 0x80016C38: b           L_80016C44
    // 0x80016C3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80016C44;
    // 0x80016C3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80016C40:
    // 0x80016C40: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80016C44:
    // 0x80016C44: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80016C48: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80016C4C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80016C50: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80016C54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80016C58: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80016C5C: sll         $t9, $t9, 11
    ctx->r25 = S32(ctx->r25 << 11);
    // 0x80016C60: b           L_80016C7C
    // 0x80016C64: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
        goto L_80016C7C;
    // 0x80016C64: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
L_80016C68:
    // 0x80016C68: b           L_80016CA4
    // 0x80016C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016CA4;
    // 0x80016C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016C70:
    // 0x80016C70: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80016C78: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80016C7C:
    // 0x80016C7C: srl         $a0, $a2, 2
    ctx->r4 = S32(U32(ctx->r6) >> 2);
    // 0x80016C80: beq         $a0, $zero, L_80016CA0
    if (ctx->r4 == 0) {
        // 0x80016C84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80016CA0;
    }
    // 0x80016C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016C88: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80016C8C:
    // 0x80016C8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80016C90: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80016C94: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80016C98: bne         $at, $zero, L_80016C8C
    if (ctx->r1 != 0) {
        // 0x80016C9C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80016C8C;
    }
    // 0x80016C9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80016CA0:
    // 0x80016CA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80016CA4:
    // 0x80016CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016CAC: jr          $ra
    // 0x80016CB0: nop

    return;
    // 0x80016CB0: nop

;}
RECOMP_FUNC void FUN_80016cb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016CB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016CB8: sw          $zero, 0x4080($at)
    MEM_W(0X4080, ctx->r1) = 0;
    // 0x80016CBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016CC0: sw          $zero, 0x4084($at)
    MEM_W(0X4084, ctx->r1) = 0;
    // 0x80016CC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016CC8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80016CCC: sw          $t6, 0x4088($at)
    MEM_W(0X4088, ctx->r1) = ctx->r14;
    // 0x80016CD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016CD4: sw          $zero, 0x408C($at)
    MEM_W(0X408C, ctx->r1) = 0;
    // 0x80016CD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80016CDC: jr          $ra
    // 0x80016CE0: sw          $a0, -0x2048($at)
    MEM_W(-0X2048, ctx->r1) = ctx->r4;
    return;
    // 0x80016CE0: sw          $a0, -0x2048($at)
    MEM_W(-0X2048, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016ce4(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016ce4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016CE4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80016CE8: addiu       $a0, $a0, 0x4084
    ctx->r4 = ADD32(ctx->r4, 0X4084);
    // 0x80016CEC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80016CF0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80016CF4: addiu       $a1, $a1, 0x408C
    ctx->r5 = ADD32(ctx->r5, 0X408C);
    // 0x80016CF8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80016CFC: bltz        $t7, L_80016D1C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80016D00: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_80016D1C;
    }
    // 0x80016D00: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80016D04: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80016D08: addiu       $a1, $a1, 0x408C
    ctx->r5 = ADD32(ctx->r5, 0X408C);
    // 0x80016D0C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80016D10: srlv        $v0, $t8, $t7
    ctx->r2 = S32(U32(ctx->r24) >> (ctx->r15 & 31));
    // 0x80016D14: jr          $ra
    // 0x80016D18: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    return;
    // 0x80016D18: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
L_80016D1C:
    // 0x80016D1C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80016D20: addiu       $a2, $a2, -0x2048
    ctx->r6 = ADD32(ctx->r6, -0X2048);
    // 0x80016D24: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80016D28: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80016D2C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80016D30: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80016D34: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80016D38: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80016D3C: srl         $v0, $t0, 7
    ctx->r2 = S32(U32(ctx->r8) >> 7);
    // 0x80016D40: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80016D44: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80016D48: jr          $ra
    // 0x80016D4C: nop

    return;
    // 0x80016D4C: nop

;}
RECOMP_FUNC void FUN_80016d50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016D50: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80016D54: addiu       $a2, $a2, 0x4084
    ctx->r6 = ADD32(ctx->r6, 0X4084);
    // 0x80016D58: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80016D5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80016D60: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80016D64: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80016D68: beq         $at, $zero, L_80016DC0
    if (ctx->r1 == 0) {
        // 0x80016D6C: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_80016DC0;
    }
    // 0x80016D6C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80016D70: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80016D74: addiu       $a3, $a3, 0x408C
    ctx->r7 = ADD32(ctx->r7, 0X408C);
    // 0x80016D78: addiu       $t0, $t0, -0x2048
    ctx->r8 = ADD32(ctx->r8, -0X2048);
L_80016D7C:
    // 0x80016D7C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80016D80: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80016D84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80016D88: sllv        $t8, $t7, $a1
    ctx->r24 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x80016D8C: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x80016D90: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80016D94: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80016D98: and         $t2, $t6, $t9
    ctx->r10 = ctx->r14 & ctx->r25;
    // 0x80016D9C: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80016DA0: sllv        $t3, $t2, $a0
    ctx->r11 = S32(ctx->r10 << (ctx->r4 & 31));
    // 0x80016DA4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80016DA8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80016DAC: or          $v1, $v1, $t3
    ctx->r3 = ctx->r3 | ctx->r11;
    // 0x80016DB0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80016DB4: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80016DB8: bne         $at, $zero, L_80016D7C
    if (ctx->r1 != 0) {
        // 0x80016DBC: sw          $t4, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r12;
            goto L_80016D7C;
    }
    // 0x80016DBC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_80016DC0:
    // 0x80016DC0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80016DC4: addiu       $a3, $a3, 0x408C
    ctx->r7 = ADD32(ctx->r7, 0X408C);
    // 0x80016DC8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80016DCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80016DD0: subu        $t7, $a1, $a0
    ctx->r15 = SUB32(ctx->r5, ctx->r4);
    // 0x80016DD4: sllv        $t3, $t2, $a0
    ctx->r11 = S32(ctx->r10 << (ctx->r4 & 31));
    // 0x80016DD8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80016DDC: srlv        $t9, $t8, $t7
    ctx->r25 = S32(U32(ctx->r24) >> (ctx->r15 & 31));
    // 0x80016DE0: and         $t5, $t9, $t4
    ctx->r13 = ctx->r25 & ctx->r12;
    // 0x80016DE4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80016DE8: jr          $ra
    // 0x80016DEC: or          $v0, $t5, $v1
    ctx->r2 = ctx->r13 | ctx->r3;
    return;
    // 0x80016DEC: or          $v0, $t5, $v1
    ctx->r2 = ctx->r13 | ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016df0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016df0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016DF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016DF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80016DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016E00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016E04: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
    // 0x80016E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80016E0C:
    // 0x80016E0C: jal         0x80017384
    // 0x80016E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80017384)(rdram, ctx);
        goto after_0;
    // 0x80016E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80016E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016E18: jal         0x800173B8
    // 0x80016E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x800173B8)(rdram, ctx);
        goto after_1;
    // 0x80016E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80016E20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80016E24: bnel        $s0, $s1, L_80016E0C
    if (ctx->r16 != ctx->r17) {
        // 0x80016E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80016E0C;
    }
    goto skip_0;
    // 0x80016E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80016E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016E30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80016E34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80016E38: jr          $ra
    // 0x80016E3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80016E3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016e40(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016e40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E40: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80016E44: lw          $t6, -0x43F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X43F0);
    // 0x80016E48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016E50: beq         $t6, $zero, L_80016E60
    if (ctx->r14 == 0) {
        // 0x80016E54: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80016E60;
    }
    // 0x80016E54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80016E58: b           L_80016E9C
    // 0x80016E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016E9C;
    // 0x80016E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016E60:
    // 0x80016E60: jal         0x8001F364
    // 0x80016E64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001F364)(rdram, ctx);
        goto after_0;
    // 0x80016E64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80016E68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80016E6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80016E70: sw          $v0, -0x43F0($at)
    MEM_W(-0X43F0, ctx->r1) = ctx->r2;
    // 0x80016E74: ori         $a0, $zero, 0xFFFE
    ctx->r4 = 0 | 0XFFFE;
    // 0x80016E78: jal         0x80016EAC
    // 0x80016E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_1;
    // 0x80016E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80016E80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016E84: jal         0x800306C0
    // 0x80016E88: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800306C0)(rdram, ctx);
        goto after_2;
    // 0x80016E88: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80016E8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016E90: jal         0x80030640
    // 0x80016E94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_3;
    // 0x80016E94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80016E98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80016E9C:
    // 0x80016E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016EA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016EA4: jr          $ra
    // 0x80016EA8: nop

    return;
    // 0x80016EA8: nop

;}
RECOMP_FUNC void FUN_80016eac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016EAC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80016EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016EB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016EB8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80016EBC: jal         0x80016F90
    // 0x80016EC0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x80016EC0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80016EC4: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80016EC8: bne         $at, $zero, L_80016ED8
    if (ctx->r1 != 0) {
        // 0x80016ECC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80016ED8;
    }
    // 0x80016ECC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80016ED0: b           L_80016F20
    // 0x80016ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80016F20;
    // 0x80016ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016ED8:
    // 0x80016ED8: jal         0x80017014
    // 0x80016EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80016EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80016EE0: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80016EE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80016EE8: jal         0x80017384
    // 0x80016EEC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80017384)(rdram, ctx);
        goto after_2;
    // 0x80016EEC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80016EF0: jal         0x8001703C
    // 0x80016EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_3;
    // 0x80016EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80016EF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80016EFC: jal         0x800173B8
    // 0x80016F00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x800173B8)(rdram, ctx);
        goto after_4;
    // 0x80016F00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80016F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016F08: jal         0x80017384
    // 0x80016F0C: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    LOOKUP_FUNC(0x80017384)(rdram, ctx);
        goto after_5;
    // 0x80016F0C: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    after_5:
    // 0x80016F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016F14: jal         0x800173B8
    // 0x80016F18: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x800173B8)(rdram, ctx);
        goto after_6;
    // 0x80016F18: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80016F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016F20:
    // 0x80016F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016F28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80016F2C: jr          $ra
    // 0x80016F30: nop

    return;
    // 0x80016F30: nop

;}
RECOMP_FUNC void FUN_80016f34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016F40: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80016F44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80016F48: jal         0x80016EAC
    // 0x80016F4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_0;
    // 0x80016F4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80016F50: beq         $v0, $zero, L_80016F60
    if (ctx->r2 == 0) {
        // 0x80016F54: nop
    
            goto L_80016F60;
    }
    // 0x80016F54: nop

    // 0x80016F58: b           L_80016F80
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80016F80;
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016F60:
    // 0x80016F60: jal         0x80016F90
    // 0x80016F64: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_1;
    // 0x80016F64: nop

    after_1:
    // 0x80016F68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80016F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80016F74: jal         0x800173B8
    // 0x80016F78: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x800173B8)(rdram, ctx);
        goto after_2;
    // 0x80016F78: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80016F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016F80:
    // 0x80016F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016F88: jr          $ra
    // 0x80016F8C: nop

    return;
    // 0x80016F8C: nop

;}
RECOMP_FUNC void FUN_80016f90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016F94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016F98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80016F9C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80016FA0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80016FA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016FA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016FAC: jal         0x80017014
    // 0x80016FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_0;
    // 0x80016FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80016FB4: beq         $v0, $zero, L_80016FF4
    if (ctx->r2 == 0) {
        // 0x80016FB8: addiu       $s3, $zero, 0x100
        ctx->r19 = ADD32(0, 0X100);
            goto L_80016FF4;
    }
    // 0x80016FB8: addiu       $s3, $zero, 0x100
    ctx->r19 = ADD32(0, 0X100);
    // 0x80016FBC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80016FC0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_80016FC4:
    // 0x80016FC4: beql        $s0, $s1, L_80016FF8
    if (ctx->r16 == ctx->r17) {
        // 0x80016FC8: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80016FF8;
    }
    goto skip_0;
    // 0x80016FC8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x80016FCC: bne         $s2, $v0, L_80016FDC
    if (ctx->r18 != ctx->r2) {
        // 0x80016FD0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80016FDC;
    }
    // 0x80016FD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80016FD4: b           L_80016FF8
    // 0x80016FD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80016FF8;
    // 0x80016FD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80016FDC:
    // 0x80016FDC: jal         0x80017014
    // 0x80016FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80016FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80016FE4: beql        $v0, $zero, L_80016FF8
    if (ctx->r2 == 0) {
        // 0x80016FE8: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80016FF8;
    }
    goto skip_1;
    // 0x80016FE8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_1:
    // 0x80016FEC: bne         $s0, $s3, L_80016FC4
    if (ctx->r16 != ctx->r19) {
        // 0x80016FF0: nop
    
            goto L_80016FC4;
    }
    // 0x80016FF0: nop

L_80016FF4:
    // 0x80016FF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80016FF8:
    // 0x80016FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80016FFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80017000: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80017004: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80017008: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001700C: jr          $ra
    // 0x80017010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80017010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017014(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017014: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80017018: bne         $at, $zero, L_80017028
    if (ctx->r1 != 0) {
        // 0x8001701C: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80017028;
    }
    // 0x8001701C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80017020: jr          $ra
    // 0x80017024: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x80017024: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80017028:
    // 0x80017028: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001702C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80017030: lhu         $v0, -0x2040($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2040);
    // 0x80017034: jr          $ra
    // 0x80017038: nop

    return;
    // 0x80017038: nop

;}
RECOMP_FUNC void FUN_8001703c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001703C: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80017040: bne         $at, $zero, L_80017050
    if (ctx->r1 != 0) {
        // 0x80017044: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80017050;
    }
    // 0x80017044: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80017048: jr          $ra
    // 0x8001704C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8001704C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017050:
    // 0x80017050: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80017054: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80017058: lw          $v0, -0x203C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X203C);
    // 0x8001705C: jr          $ra
    // 0x80017060: nop

    return;
    // 0x80017060: nop

;}
RECOMP_FUNC void FUN_80017064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80017068: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001706C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017074: andi        $s1, $a0, 0xFFFF
    ctx->r17 = ctx->r4 & 0XFFFF;
    // 0x80017078: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001707C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80017080: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017084: addiu       $s2, $zero, 0x100
    ctx->r18 = ADD32(0, 0X100);
L_80017088:
    // 0x80017088: jal         0x80017014
    // 0x8001708C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_0;
    // 0x8001708C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80017090: bnel        $s1, $v0, L_800170A4
    if (ctx->r17 != ctx->r2) {
        // 0x80017094: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800170A4;
    }
    goto skip_0;
    // 0x80017094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80017098: b           L_800170B0
    // 0x8001709C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800170B0;
    // 0x8001709C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800170A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800170A4:
    // 0x800170A4: bne         $s0, $s2, L_80017088
    if (ctx->r16 != ctx->r18) {
        // 0x800170A8: nop
    
            goto L_80017088;
    }
    // 0x800170A8: nop

    // 0x800170AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800170B0:
    // 0x800170B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800170B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800170B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800170BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800170C0: jr          $ra
    // 0x800170C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800170C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800170c8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800170c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800170C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800170CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800170D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800170D4: jal         0x80017064
    // 0x800170D8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x800170D8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x800170DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800170E0: bne         $v0, $at, L_800170F0
    if (ctx->r2 != ctx->r1) {
        // 0x800170E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800170F0;
    }
    // 0x800170E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800170E8: b           L_80017110
    // 0x800170EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017110;
    // 0x800170EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800170F0:
    // 0x800170F0: jal         0x8001703C
    // 0x800170F4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_1;
    // 0x800170F4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800170F8: jal         0x8001F540
    // 0x800170FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_2;
    // 0x800170FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80017100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80017104: jal         0x800173E4
    // 0x80017108: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x800173E4)(rdram, ctx);
        goto after_3;
    // 0x80017108: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8001710C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80017110:
    // 0x80017110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017118: jr          $ra
    // 0x8001711C: nop

    return;
    // 0x8001711C: nop

;}
RECOMP_FUNC void FUN_80017120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001712C: jal         0x80017064
    // 0x80017130: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x80017130: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80017134: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017138: bne         $v0, $at, L_80017148
    if (ctx->r2 != ctx->r1) {
        // 0x8001713C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80017148;
    }
    // 0x8001713C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80017140: b           L_80017154
    // 0x80017144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017154;
    // 0x80017144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017148:
    // 0x80017148: jal         0x800173E4
    // 0x8001714C: nop

    LOOKUP_FUNC(0x800173E4)(rdram, ctx);
        goto after_1;
    // 0x8001714C: nop

    after_1:
    // 0x80017150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017154:
    // 0x80017154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001715C: jr          $ra
    // 0x80017160: nop

    return;
    // 0x80017160: nop

;}
RECOMP_FUNC void FUN_80017164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80017168: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001716C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80017170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017174: lui         $s1, 0xFFF
    ctx->r17 = S32(0XFFF << 16);
    // 0x80017178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001717C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80017180: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x80017184: lui         $s2, 0x4000
    ctx->r18 = S32(0X4000 << 16);
L_80017188:
    // 0x80017188: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8001718C: and         $a0, $t6, $s1
    ctx->r4 = ctx->r14 & ctx->r17;
    // 0x80017190: jal         0x800170C8
    // 0x80017194: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x800170C8)(rdram, ctx);
        goto after_0;
    // 0x80017194: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80017198: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8001719C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800171A0: and         $t8, $t7, $s2
    ctx->r24 = ctx->r15 & ctx->r18;
    // 0x800171A4: bnel        $t8, $zero, L_800171B8
    if (ctx->r24 != 0) {
        // 0x800171A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800171B8;
    }
    goto skip_0;
    // 0x800171A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800171AC: b           L_80017188
    // 0x800171B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80017188;
    // 0x800171B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800171B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800171B8:
    // 0x800171B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800171BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800171C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800171C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800171C8: jr          $ra
    // 0x800171CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800171CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800171d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800171d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800171D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800171D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800171D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800171DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800171E0: andi        $s2, $a0, 0xFFFF
    ctx->r18 = ctx->r4 & 0XFFFF;
    // 0x800171E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800171E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800171EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800171F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800171F4:
    // 0x800171F4: jal         0x80016F90
    // 0x800171F8: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x800171F8: nop

    after_0:
    // 0x800171FC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80017200: bnel        $at, $zero, L_8001723C
    if (ctx->r1 != 0) {
        // 0x80017204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001723C;
    }
    goto skip_0;
    // 0x80017204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80017208: jal         0x80017014
    // 0x8001720C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x8001720C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80017210: beql        $v0, $zero, L_8001723C
    if (ctx->r2 == 0) {
        // 0x80017214: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001723C;
    }
    goto skip_1;
    // 0x80017214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80017218: beq         $v0, $s2, L_80017230
    if (ctx->r2 == ctx->r18) {
        // 0x8001721C: nop
    
            goto L_80017230;
    }
    // 0x8001721C: nop

    // 0x80017220: jal         0x800170C8
    // 0x80017224: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x800170C8)(rdram, ctx);
        goto after_2;
    // 0x80017224: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80017228: b           L_800171F4
    // 0x8001722C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800171F4;
    // 0x8001722C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80017230:
    // 0x80017230: b           L_800171F4
    // 0x80017234: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800171F4;
    // 0x80017234: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001723C:
    // 0x8001723C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80017240: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017248: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001724C: jr          $ra
    // 0x80017250: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80017250: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017254(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017254: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80017258: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001725C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80017260: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80017264: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017268: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001726C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80017270: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017274: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017278: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001727C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80017280:
    // 0x80017280: jal         0x80016F90
    // 0x80017284: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x80017284: nop

    after_0:
    // 0x80017288: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001728C: bnel        $at, $zero, L_800172D4
    if (ctx->r1 != 0) {
        // 0x80017290: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800172D4;
    }
    goto skip_0;
    // 0x80017290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80017294: jal         0x80017014
    // 0x80017298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80017298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8001729C: beq         $v0, $zero, L_800172D0
    if (ctx->r2 == 0) {
        // 0x800172A0: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_800172D0;
    }
    // 0x800172A0: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800172A4: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800172A8: jal         0x80017480
    // 0x800172AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80017480)(rdram, ctx);
        goto after_2;
    // 0x800172AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800172B0: bne         $v0, $s4, L_800172C8
    if (ctx->r2 != ctx->r20) {
        // 0x800172B4: nop
    
            goto L_800172C8;
    }
    // 0x800172B4: nop

    // 0x800172B8: jal         0x800170C8
    // 0x800172BC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x800170C8)(rdram, ctx);
        goto after_3;
    // 0x800172BC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_3:
    // 0x800172C0: b           L_80017280
    // 0x800172C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80017280;
    // 0x800172C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800172C8:
    // 0x800172C8: b           L_80017280
    // 0x800172CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80017280;
    // 0x800172CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800172D0:
    // 0x800172D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800172D4:
    // 0x800172D4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800172D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800172DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800172E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800172E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800172E8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800172EC: jr          $ra
    // 0x800172F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800172F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800172f4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800172f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800172F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800172F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800172FC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80017300: lw          $s0, -0x43F0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X43F0);
    // 0x80017304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80017308: beql        $s0, $zero, L_8001732C
    if (ctx->r16 == 0) {
        // 0x8001730C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001732C;
    }
    goto skip_0;
    // 0x8001730C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80017310: jal         0x800174CC
    // 0x80017314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800174CC)(rdram, ctx);
        goto after_0;
    // 0x80017314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80017318: jal         0x800173E4
    // 0x8001731C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x800173E4)(rdram, ctx);
        goto after_1;
    // 0x8001731C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80017320: jal         0x8001F540
    // 0x80017324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_2;
    // 0x80017324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80017328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001732C:
    // 0x8001732C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80017330: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80017334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017338: sw          $zero, -0x43F0($at)
    MEM_W(-0X43F0, ctx->r1) = 0;
    // 0x8001733C: jr          $ra
    // 0x80017340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80017340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017344(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001734C: jal         0x800174CC
    // 0x80017350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800174CC)(rdram, ctx);
        goto after_0;
    // 0x80017350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80017354: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017358: bne         $v0, $at, L_80017368
    if (ctx->r2 != ctx->r1) {
        // 0x8001735C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80017368;
    }
    // 0x8001735C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80017360: b           L_80017374
    // 0x80017364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017374;
    // 0x80017364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017368:
    // 0x80017368: jal         0x800173E4
    // 0x8001736C: nop

    LOOKUP_FUNC(0x800173E4)(rdram, ctx);
        goto after_1;
    // 0x8001736C: nop

    after_1:
    // 0x80017370: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80017374:
    // 0x80017374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001737C: jr          $ra
    // 0x80017380: nop

    return;
    // 0x80017380: nop

;}
RECOMP_FUNC void FUN_80017384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017384: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80017388: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8001738C: bne         $at, $zero, L_8001739C
    if (ctx->r1 != 0) {
        // 0x80017390: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8001739C;
    }
    // 0x80017390: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80017394: jr          $ra
    // 0x80017398: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80017398: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001739C:
    // 0x8001739C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800173A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800173A4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800173A8: sh          $a1, -0x2040($at)
    MEM_H(-0X2040, ctx->r1) = ctx->r5;
    // 0x800173AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800173B0: jr          $ra
    // 0x800173B4: nop

    return;
    // 0x800173B4: nop

;}
RECOMP_FUNC void FUN_800173b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173B8: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800173BC: bne         $at, $zero, L_800173CC
    if (ctx->r1 != 0) {
        // 0x800173C0: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_800173CC;
    }
    // 0x800173C0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800173C4: jr          $ra
    // 0x800173C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800173C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800173CC:
    // 0x800173CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800173D0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800173D4: sw          $a1, -0x203C($at)
    MEM_W(-0X203C, ctx->r1) = ctx->r5;
    // 0x800173D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800173DC: jr          $ra
    // 0x800173E0: nop

    return;
    // 0x800173E0: nop

;}
RECOMP_FUNC void FUN_800173e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800173E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800173EC: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800173F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800173F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800173F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800173FC: beq         $at, $zero, L_80017418
    if (ctx->r1 == 0) {
        // 0x80017400: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80017418;
    }
    // 0x80017400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017404: jal         0x80016F90
    // 0x80017408: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x80017408: nop

    after_0:
    // 0x8001740C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80017410: beq         $at, $zero, L_80017420
    if (ctx->r1 == 0) {
        // 0x80017414: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80017420;
    }
    // 0x80017414: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80017418:
    // 0x80017418: b           L_80017468
    // 0x8001741C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017468;
    // 0x8001741C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017420:
    // 0x80017420: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80017424: bne         $at, $zero, L_80017464
    if (ctx->r1 != 0) {
        // 0x80017428: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80017464;
    }
    // 0x80017428: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8001742C: addiu       $s2, $v1, 0x1
    ctx->r18 = ADD32(ctx->r3, 0X1);
L_80017430:
    // 0x80017430: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80017434: jal         0x80017014
    // 0x80017438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80017438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001743C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017440: jal         0x80017384
    // 0x80017444: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80017384)(rdram, ctx);
        goto after_2;
    // 0x80017444: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80017448: jal         0x8001703C
    // 0x8001744C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_3;
    // 0x8001744C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80017450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017454: jal         0x800173B8
    // 0x80017458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x800173B8)(rdram, ctx);
        goto after_4;
    // 0x80017458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8001745C: bne         $s2, $s0, L_80017430
    if (ctx->r18 != ctx->r16) {
        // 0x80017460: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80017430;
    }
    // 0x80017460: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80017464:
    // 0x80017464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017468:
    // 0x80017468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001746C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017470: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017474: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80017478: jr          $ra
    // 0x8001747C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001747C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017480(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017480: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80017484: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80017488: lui         $a0, 0xFFF
    ctx->r4 = S32(0XFFF << 16);
    // 0x8001748C: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x80017490: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
L_80017494:
    // 0x80017494: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80017498: and         $t6, $v1, $a0
    ctx->r14 = ctx->r3 & ctx->r4;
    // 0x8001749C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800174A0: bne         $v0, $t7, L_800174B0
    if (ctx->r2 != ctx->r15) {
        // 0x800174A4: and         $t8, $v1, $a2
        ctx->r24 = ctx->r3 & ctx->r6;
            goto L_800174B0;
    }
    // 0x800174A4: and         $t8, $v1, $a2
    ctx->r24 = ctx->r3 & ctx->r6;
    // 0x800174A8: jr          $ra
    // 0x800174AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800174AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800174B0:
    // 0x800174B0: bnel        $t8, $zero, L_800174C4
    if (ctx->r24 != 0) {
        // 0x800174B4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800174C4;
    }
    goto skip_0;
    // 0x800174B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800174B8: b           L_80017494
    // 0x800174BC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
        goto L_80017494;
    // 0x800174BC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800174C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800174C4:
    // 0x800174C4: jr          $ra
    // 0x800174C8: nop

    return;
    // 0x800174C8: nop

;}
RECOMP_FUNC void FUN_800174cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800174CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800174D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800174D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800174D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800174DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800174E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800174E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800174E8: addiu       $s2, $zero, 0x100
    ctx->r18 = ADD32(0, 0X100);
L_800174EC:
    // 0x800174EC: jal         0x8001703C
    // 0x800174F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_0;
    // 0x800174F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800174F4: bnel        $v0, $s1, L_80017508
    if (ctx->r2 != ctx->r17) {
        // 0x800174F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80017508;
    }
    goto skip_0;
    // 0x800174F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800174FC: b           L_80017514
    // 0x80017500: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80017514;
    // 0x80017500: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80017504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80017508:
    // 0x80017508: bne         $s0, $s2, L_800174EC
    if (ctx->r16 != ctx->r18) {
        // 0x8001750C: nop
    
            goto L_800174EC;
    }
    // 0x8001750C: nop

    // 0x80017510: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017514:
    // 0x80017514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80017518: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001751C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017520: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80017524: jr          $ra
    // 0x80017528: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80017528: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001752c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001752c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001752C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017538: jal         0x80016EAC
    // 0x8001753C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_0;
    // 0x8001753C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x80017540: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80017544: addiu       $a1, $a1, -0x6D50
    ctx->r5 = ADD32(ctx->r5, -0X6D50);
    // 0x80017548: lhu         $v0, 0x42FC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X42FC);
    // 0x8001754C: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80017550: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017554: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80017558: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8001755C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017560: addiu       $t7, $t7, -0x1640
    ctx->r15 = ADD32(ctx->r15, -0X1640);
    // 0x80017564: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80017568: sh          $t6, -0x1840($at)
    MEM_H(-0X1840, ctx->r1) = ctx->r14;
    // 0x8001756C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80017570: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80017574: sh          $t0, 0x42FC($a1)
    MEM_H(0X42FC, ctx->r5) = ctx->r8;
    // 0x80017578: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001757C: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80017580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001758C: jr          $ra
    // 0x80017590: nop

    return;
    // 0x80017590: nop

;}
RECOMP_FUNC void FUN_80017594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017594: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80017598: lhu         $v1, -0x2A54($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2A54);
    // 0x8001759C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800175A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800175A4: bltz        $v1, L_800175FC
    if (SIGNED(ctx->r3) < 0) {
        // 0x800175A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800175FC;
    }
    // 0x800175A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800175AC: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x800175B0: addiu       $a3, $a3, -0x1840
    ctx->r7 = ADD32(ctx->r7, -0X1840);
    // 0x800175B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800175B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800175BC:
    // 0x800175BC: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800175C0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800175C4: addiu       $t7, $t7, -0x1640
    ctx->r15 = ADD32(ctx->r15, -0X1640);
    // 0x800175C8: bnel        $a1, $t6, L_800175EC
    if (ctx->r5 != ctx->r14) {
        // 0x800175CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800175EC;
    }
    goto skip_0;
    // 0x800175CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800175D0: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
    // 0x800175D4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800175D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800175DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800175E0: jr          $ra
    // 0x800175E4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x800175E4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x800175E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800175EC:
    // 0x800175EC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800175F0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800175F4: beq         $at, $zero, L_800175BC
    if (ctx->r1 == 0) {
        // 0x800175F8: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800175BC;
    }
    // 0x800175F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_800175FC:
    // 0x800175FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017600: jr          $ra
    // 0x80017604: nop

    return;
    // 0x80017604: nop

;}
RECOMP_FUNC void FUN_80017608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001760C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80017610: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80017614: addiu       $s1, $s1, -0x6D50
    ctx->r17 = ADD32(ctx->r17, -0X6D50);
    // 0x80017618: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001761C: lhu         $s0, 0x42FC($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X42FC);
    // 0x80017620: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80017624: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80017628: beq         $s0, $zero, L_80017678
    if (ctx->r16 == 0) {
        // 0x8001762C: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_80017678;
    }
    // 0x8001762C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80017630: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80017634: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80017638: addiu       $s2, $s2, -0x1840
    ctx->r18 = ADD32(ctx->r18, -0X1840);
    // 0x8001763C: addiu       $s3, $s3, -0x1640
    ctx->r19 = ADD32(ctx->r19, -0X1640);
L_80017640:
    // 0x80017640: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x80017644: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80017648: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001764C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80017650: sh          $t6, 0x42FC($s1)
    MEM_H(0X42FC, ctx->r17) = ctx->r14;
    // 0x80017654: jal         0x800170C8
    // 0x80017658: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    LOOKUP_FUNC(0x800170C8)(rdram, ctx);
        goto after_0;
    // 0x80017658: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    after_0:
    // 0x8001765C: lhu         $s0, 0x42FC($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X42FC);
    // 0x80017660: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80017664: addu        $t0, $s3, $v0
    ctx->r8 = ADD32(ctx->r19, ctx->r2);
    // 0x80017668: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8001766C: addu        $t1, $s2, $v0
    ctx->r9 = ADD32(ctx->r18, ctx->r2);
    // 0x80017670: bne         $s0, $zero, L_80017640
    if (ctx->r16 != 0) {
        // 0x80017674: sh          $zero, 0x0($t1)
        MEM_H(0X0, ctx->r9) = 0;
            goto L_80017640;
    }
    // 0x80017674: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
L_80017678:
    // 0x80017678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001767C: sh          $zero, 0x42FC($s1)
    MEM_H(0X42FC, ctx->r17) = 0;
    // 0x80017680: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80017684: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80017688: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001768C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80017690: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80017694: jr          $ra
    // 0x80017698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80017698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001769c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001769c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001769C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800176A0: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x800176A4: lhu         $a2, 0x42FC($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X42FC);
    // 0x800176A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800176AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800176B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800176B4: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x800176B8: bltz        $a2, L_800177A8
    if (SIGNED(ctx->r6) < 0) {
        // 0x800176BC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800177A8;
    }
    // 0x800176BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800176C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800176C4: addiu       $v0, $v0, -0x1840
    ctx->r2 = ADD32(ctx->r2, -0X1840);
    // 0x800176C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800176CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800176D0:
    // 0x800176D0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800176D4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800176D8: bne         $a1, $t6, L_80017798
    if (ctx->r5 != ctx->r14) {
        // 0x800176DC: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_80017798;
    }
    // 0x800176DC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800176E0: addiu       $t7, $t7, -0x1640
    ctx->r15 = ADD32(ctx->r15, -0X1640);
    // 0x800176E4: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800176E8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800176EC: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x800176F0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800176F4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x800176F8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800176FC: bgtz        $t2, L_80017790
    if (SIGNED(ctx->r10) > 0) {
        // 0x80017700: nop
    
            goto L_80017790;
    }
    // 0x80017700: nop

    // 0x80017704: jal         0x800170C8
    // 0x80017708: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800170C8)(rdram, ctx);
        goto after_0;
    // 0x80017708: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001770C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80017710: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x80017714: lhu         $a3, 0x42FC($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X42FC);
    // 0x80017718: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001771C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80017720: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80017724: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80017728: beq         $at, $zero, L_80017770
    if (ctx->r1 == 0) {
        // 0x8001772C: addiu       $t8, $a2, -0x1
        ctx->r24 = ADD32(ctx->r6, -0X1);
            goto L_80017770;
    }
    // 0x8001772C: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x80017730: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80017734: addiu       $t4, $t4, -0x1840
    ctx->r12 = ADD32(ctx->r12, -0X1840);
    // 0x80017738: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x8001773C: addiu       $t3, $t3, -0x1640
    ctx->r11 = ADD32(ctx->r11, -0X1640);
    // 0x80017740: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x80017744: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    // 0x80017748: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x8001774C: addu        $v0, $a1, $t4
    ctx->r2 = ADD32(ctx->r5, ctx->r12);
L_80017750:
    // 0x80017750: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80017754: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80017758: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8001775C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80017760: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80017764: sh          $t6, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r14;
    // 0x80017768: bne         $at, $zero, L_80017750
    if (ctx->r1 != 0) {
        // 0x8001776C: sh          $t7, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r15;
            goto L_80017750;
    }
    // 0x8001776C: sh          $t7, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r15;
L_80017770:
    // 0x80017770: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80017774: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017778: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001777C: sh          $zero, -0x1640($at)
    MEM_H(-0X1640, ctx->r1) = 0;
    // 0x80017780: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017784: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017788: sh          $zero, -0x1840($at)
    MEM_H(-0X1840, ctx->r1) = 0;
    // 0x8001778C: sh          $t8, 0x42FC($t1)
    MEM_H(0X42FC, ctx->r9) = ctx->r24;
L_80017790:
    // 0x80017790: b           L_800177AC
    // 0x80017794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800177AC;
    // 0x80017794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017798:
    // 0x80017798: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001779C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800177A0: beq         $at, $zero, L_800176D0
    if (ctx->r1 == 0) {
        // 0x800177A4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800176D0;
    }
    // 0x800177A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800177A8:
    // 0x800177A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800177AC:
    // 0x800177AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800177B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800177B4: jr          $ra
    // 0x800177B8: nop

    return;
    // 0x800177B8: nop

;}
RECOMP_FUNC void FUN_800177bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800177C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800177C4: jal         0x80016F90
    // 0x800177C8: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x800177C8: nop

    after_0:
    // 0x800177CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800177D0: bltz        $v0, L_800177E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800177D4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800177E8;
    }
    // 0x800177D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800177D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800177DC:
    // 0x800177DC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800177E0: beql        $at, $zero, L_800177DC
    if (ctx->r1 == 0) {
        // 0x800177E4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800177DC;
    }
    goto skip_0;
    // 0x800177E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800177E8:
    // 0x800177E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800177EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800177F0: jr          $ra
    // 0x800177F4: nop

    return;
    // 0x800177F4: nop

    // 0x800177F8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800177FC: lhu         $v1, -0x2A54($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2A54);
    // 0x80017800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017804: bltz        $v1, L_80017818
    if (SIGNED(ctx->r3) < 0) {
        // 0x80017808: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80017818;
    }
    // 0x80017808: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001780C:
    // 0x8001780C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80017810: beql        $at, $zero, L_8001780C
    if (ctx->r1 == 0) {
        // 0x80017814: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001780C;
    }
    goto skip_1;
    // 0x80017814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
L_80017818:
    // 0x80017818: jr          $ra
    // 0x8001781C: nop

    return;
    // 0x8001781C: nop

;}
RECOMP_FUNC void FUN_80017820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017820: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017824: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80017828: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001782C: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80017830: addiu       $t6, $t6, 0x413C
    ctx->r14 = ADD32(ctx->r14, 0X413C);
    // 0x80017834: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80017838: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x8001783C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80017840:
    // 0x80017840: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80017844: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80017848: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8001784C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80017850: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80017854: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80017858: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8001785C: bne         $t6, $t0, L_80017840
    if (ctx->r14 != ctx->r8) {
        // 0x80017860: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80017840;
    }
    // 0x80017860: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80017864: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x80017868: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8001786C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80017870: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80017874: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x80017878: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001787C: sh          $t2, -0x142C($at)
    MEM_H(-0X142C, ctx->r1) = ctx->r10;
    // 0x80017880: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x80017884: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017888: sh          $t3, -0x142A($at)
    MEM_H(-0X142A, ctx->r1) = ctx->r11;
    // 0x8001788C: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x80017890: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80017894: sh          $t4, -0x1428($at)
    MEM_H(-0X1428, ctx->r1) = ctx->r12;
    // 0x80017898: lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X6);
    // 0x8001789C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178A0: sh          $t5, -0x1426($at)
    MEM_H(-0X1426, ctx->r1) = ctx->r13;
    // 0x800178A4: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x800178A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178AC: sh          $t0, -0x1422($at)
    MEM_H(-0X1422, ctx->r1) = ctx->r8;
    // 0x800178B0: lhu         $t6, 0xA($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XA);
    // 0x800178B4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178B8: sh          $t6, -0x1420($at)
    MEM_H(-0X1420, ctx->r1) = ctx->r14;
    // 0x800178BC: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x800178C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178C4: sh          $t9, -0x1424($at)
    MEM_H(-0X1424, ctx->r1) = ctx->r25;
    // 0x800178C8: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x800178CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178D0: sh          $t7, -0x141E($at)
    MEM_H(-0X141E, ctx->r1) = ctx->r15;
    // 0x800178D4: lhu         $t8, 0x10($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X10);
    // 0x800178D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800178DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800178E0: jr          $ra
    // 0x800178E4: sh          $t8, -0x141A($at)
    MEM_H(-0X141A, ctx->r1) = ctx->r24;
    return;
    // 0x800178E4: sh          $t8, -0x141A($at)
    MEM_H(-0X141A, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800178e8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800178e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800178E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800178EC: lw          $v0, -0x1188($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1188);
    // 0x800178F0: jr          $ra
    // 0x800178F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x800178F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800178F8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800178FC: jr          $ra
    // 0x80017900: lbu         $v0, -0x117E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117E);
    return;
    // 0x80017900: lbu         $v0, -0x117E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117E);
    // 0x80017904: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80017908: jr          $ra
    // 0x8001790C: lbu         $v0, -0x117E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117E);
    return;
    // 0x8001790C: lbu         $v0, -0x117E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80017910(rdram, ctx);
;}
RECOMP_FUNC void FUN_80017910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017910: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80017914: jr          $ra
    // 0x80017918: lbu         $v0, -0x117D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117D);
    return;
    // 0x80017918: lbu         $v0, -0x117D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X117D);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001791c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001791c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001791C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80017920: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80017924: lhu         $t6, 0x354($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X354);
    // 0x80017928: lhu         $t7, 0x352($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X352);
    // 0x8001792C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017930: bne         $t6, $t7, L_80017940
    if (ctx->r14 != ctx->r15) {
        // 0x80017934: nop
    
            goto L_80017940;
    }
    // 0x80017934: nop

    // 0x80017938: jr          $ra
    // 0x8001793C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001793C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017940:
    // 0x80017940: jr          $ra
    // 0x80017944: nop

    return;
    // 0x80017944: nop

;}
RECOMP_FUNC void FUN_80017948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001794C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017950: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017954: jal         0x80017990
    // 0x80017958: sw          $a1, 0x4118($at)
    MEM_W(0X4118, ctx->r1) = ctx->r5;
    LOOKUP_FUNC(0x80017990)(rdram, ctx);
        goto after_0;
    // 0x80017958: sw          $a1, 0x4118($at)
    MEM_W(0X4118, ctx->r1) = ctx->r5;
    after_0:
    // 0x8001795C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017964: jr          $ra
    // 0x80017968: nop

    return;
    // 0x80017968: nop

;}
RECOMP_FUNC void FUN_8001796c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001796C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017974: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017978: jal         0x800179B0
    // 0x8001797C: sw          $a1, 0x4118($at)
    MEM_W(0X4118, ctx->r1) = ctx->r5;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x8001797C: sw          $a1, 0x4118($at)
    MEM_W(0X4118, ctx->r1) = ctx->r5;
    after_0:
    // 0x80017980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017988: jr          $ra
    // 0x8001798C: nop

    return;
    // 0x8001798C: nop

;}
