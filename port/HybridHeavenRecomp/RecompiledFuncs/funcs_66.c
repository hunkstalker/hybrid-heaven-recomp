#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801ee550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE554: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE55C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE560: lui         $a1, 0x214
    ctx->r5 = S32(0X214 << 16);
    // 0x801EE564: ori         $a1, $a1, 0x8820
    ctx->r5 = ctx->r5 | 0X8820;
    // 0x801EE568: jal         0x801C0B8C
    // 0x801EE56C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE56C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE570: beq         $v0, $zero, L_801EE5A0
    if (ctx->r2 == 0) {
        // 0x801EE574: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_801EE5A0;
    }
    // 0x801EE574: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE578: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EE57C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE580: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE584: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x801EE588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE58C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EE590: jal         0x801CC470
    // 0x801EE594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EE598: b           L_801EE5A4
    // 0x801EE59C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801EE5A4;
    // 0x801EE59C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EE5A0:
    // 0x801EE5A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EE5A4:
    // 0x801EE5A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE5A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE5AC: jr          $ra
    // 0x801EE5B0: nop

    return;
    // 0x801EE5B0: nop

;}
RECOMP_FUNC void M25_FUN_801ee5b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE5B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE5B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE5BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE5C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE5C4: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801EE5C8: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801EE5CC: jal         0x801C0B8C
    // 0x801EE5D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE5D0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE5D4: beq         $v0, $zero, L_801EE6A4
    if (ctx->r2 == 0) {
        // 0x801EE5D8: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EE6A4;
    }
    // 0x801EE5D8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EE5DC: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EE5E0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EE5E4: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EE5E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE5EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE5F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EE5F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE5F8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE5FC: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE600: ori         $a1, $a1, 0x1C
    ctx->r5 = ctx->r5 | 0X1C;
    // 0x801EE604: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE608: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE60C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE610: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE614: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EE618: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EE61C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EE620: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EE624: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801EE628: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE62C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE630: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE634: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE638: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EE63C: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801EE640: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EE644: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EE648: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EE64C: lwc1        $f8, -0x3718($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3718);
    // 0x801EE650: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801EE654: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE658: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EE65C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE660: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE664: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE668: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EE66C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EE670: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EE674: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EE678: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE67C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE680: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE684: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE688: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EE68C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EE690: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
    // 0x801EE694: jal         0x801CC470
    // 0x801EE698: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE698: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EE69C: b           L_801EE6A8
    // 0x801EE6A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EE6A8;
    // 0x801EE6A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EE6A4:
    // 0x801EE6A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EE6A8:
    // 0x801EE6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE6AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE6B0: jr          $ra
    // 0x801EE6B4: nop

    return;
    // 0x801EE6B4: nop

;}
RECOMP_FUNC void M25_FUN_801ee6b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE6B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EE6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE6C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE6C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EE6C8: jal         0x801BF6B0
    // 0x801EE6CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801EE6CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801EE6D0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801EE6D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EE6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE6DC: slti        $at, $t6, 0xE
    ctx->r1 = SIGNED(ctx->r14) < 0XE ? 1 : 0;
    // 0x801EE6E0: bne         $at, $zero, L_801EE6F0
    if (ctx->r1 != 0) {
        // 0x801EE6E4: nop
    
            goto L_801EE6F0;
    }
    // 0x801EE6E4: nop

    // 0x801EE6E8: b           L_801EE6F0
    // 0x801EE6EC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EE6F0;
    // 0x801EE6EC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EE6F0:
    // 0x801EE6F0: jr          $ra
    // 0x801EE6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EE6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee6f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee6f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE6F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE6FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE700: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE704: sw          $zero, -0x4A04($at)
    MEM_W(-0X4A04, ctx->r1) = 0;
    // 0x801EE708: jr          $ra
    // 0x801EE70C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801EE70C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee710(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE710: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EE714: lw          $v0, -0x4A04($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A04);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee718(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE71C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE720: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE724: beq         $v0, $zero, L_801EE740
    if (ctx->r2 == 0) {
        // 0x801EE728: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801EE740;
    }
    // 0x801EE728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE72C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801EE730: beq         $v0, $at, L_801EE828
    if (ctx->r2 == ctx->r1) {
        // 0x801EE734: nop
    
            goto L_801EE828;
    }
    // 0x801EE734: nop

    // 0x801EE738: b           L_801EE864
    // 0x801EE73C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EE864;
    // 0x801EE73C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EE740:
    // 0x801EE740: lui         $a1, 0x4FF
    ctx->r5 = S32(0X4FF << 16);
    // 0x801EE744: ori         $a1, $a1, 0xB42A
    ctx->r5 = ctx->r5 | 0XB42A;
    // 0x801EE748: jal         0x801C0B8C
    // 0x801EE74C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE74C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE750: beq         $v0, $zero, L_801EE860
    if (ctx->r2 == 0) {
        // 0x801EE754: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EE860;
    }
    // 0x801EE754: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EE758: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EE75C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EE760: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EE764: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE768: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE76C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EE770: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE774: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE778: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE77C: ori         $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 | 0X1F;
    // 0x801EE780: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE784: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE788: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x801EE78C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EE794: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EE798: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EE79C: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EE7A0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801EE7A4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE7A8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE7AC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE7B0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE7B4: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EE7B8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801EE7BC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EE7C0: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EE7C4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EE7C8: lwc1        $f8, -0x3714($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3714);
    // 0x801EE7CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EE7D0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE7D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EE7D8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE7DC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE7E0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE7E4: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EE7E8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EE7EC: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EE7F0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EE7F4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE7F8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE7FC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE800: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE804: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EE808: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EE80C: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
    // 0x801EE810: jal         0x801CC470
    // 0x801EE814: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EE814: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EE818: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801EE81C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE820: b           L_801EE860
    // 0x801EE824: sw          $t5, -0x4A04($at)
    MEM_W(-0X4A04, ctx->r1) = ctx->r13;
        goto L_801EE860;
    // 0x801EE824: sw          $t5, -0x4A04($at)
    MEM_W(-0X4A04, ctx->r1) = ctx->r13;
L_801EE828:
    // 0x801EE828: jal         0x801D0408
    // 0x801EE82C: nop

    LOOKUP_FUNC(0x801D0408)(rdram, ctx);
        goto after_2;
    // 0x801EE82C: nop

    after_2:
    // 0x801EE830: beq         $v0, $zero, L_801EE860
    if (ctx->r2 == 0) {
        // 0x801EE834: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_801EE860;
    }
    // 0x801EE834: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE838: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801EE83C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EE840: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE844: ori         $a1, $a1, 0x1D
    ctx->r5 = ctx->r5 | 0X1D;
    // 0x801EE848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE84C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EE850: jal         0x801CC470
    // 0x801EE854: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801EE854: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801EE858: b           L_801EE864
    // 0x801EE85C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801EE864;
    // 0x801EE85C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EE860:
    // 0x801EE860: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EE864:
    // 0x801EE864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE86C: jr          $ra
    // 0x801EE870: nop

    return;
    // 0x801EE870: nop

;}
RECOMP_FUNC void M25_FUN_801ee874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EE878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EE87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE884: lui         $a1, 0x517
    ctx->r5 = S32(0X517 << 16);
    // 0x801EE888: ori         $a1, $a1, 0x5ADA
    ctx->r5 = ctx->r5 | 0X5ADA;
    // 0x801EE88C: jal         0x801C0B8C
    // 0x801EE890: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE890: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE894: beq         $v0, $zero, L_801EE940
    if (ctx->r2 == 0) {
        // 0x801EE898: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801EE940;
    }
    // 0x801EE898: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EE89C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EE8A0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EE8A4: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801EE8A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE8AC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE8B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EE8B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EE8B8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EE8BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801EE8C0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE8C4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE8C8: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EE8CC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EE8D0: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EE8D4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EE8D8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE8DC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EE8E0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EE8E4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EE8E8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EE8EC: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x801EE8F0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EE8F4: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EE8F8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801EE8FC: lwc1        $f8, -0x3710($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3710);
    // 0x801EE900: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE904: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE908: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EE90C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EE910: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EE914: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EE918: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EE91C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EE920: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EE924: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EE928: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EE92C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EE930: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EE934: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EE938: b           L_801EE944
    // 0x801EE93C: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
        goto L_801EE944;
    // 0x801EE93C: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
L_801EE940:
    // 0x801EE940: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EE944:
    // 0x801EE944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EE94C: jr          $ra
    // 0x801EE950: nop

    return;
    // 0x801EE950: nop

;}
RECOMP_FUNC void M25_FUN_801ee954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE958: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EE95C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EE960: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EE964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EE968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EE96C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EE970: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    // 0x801EE974: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EE978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EE97C: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801EE980: jal         0x801CC470
    // 0x801EE984: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801EE984: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801EE988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EE98C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EE990: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801EE994: jr          $ra
    // 0x801EE998: nop

    return;
    // 0x801EE998: nop

;}
RECOMP_FUNC void M25_FUN_801ee99c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE99C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE9A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE9A4: jr          $ra
    // 0x801EE9A8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x801EE9A8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee9ac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee9ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE9AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EE9B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EE9B4: jr          $ra
    // 0x801EE9B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801EE9B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee9bc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee9bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE9BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EE9C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EE9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EE9C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EE9CC: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801EE9D0: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801EE9D4: jal         0x801C0B8C
    // 0x801EE9D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EE9D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EE9DC: beq         $v0, $zero, L_801EE9EC
    if (ctx->r2 == 0) {
        // 0x801EE9E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EE9EC;
    }
    // 0x801EE9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EE9E4: b           L_801EE9F0
    // 0x801EE9E8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801EE9F0;
    // 0x801EE9E8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801EE9EC:
    // 0x801EE9EC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EE9F0:
    // 0x801EE9F0: jr          $ra
    // 0x801EE9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EE9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ee9f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ee9f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EE9F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EE9FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EEA00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EEA04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EEA08: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801EEA0C: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801EEA10: jal         0x801C0B8C
    // 0x801EEA14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEA14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EEA18: beq         $v0, $zero, L_801EEAE8
    if (ctx->r2 == 0) {
        // 0x801EEA1C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EEAE8;
    }
    // 0x801EEA1C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EEA20: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EEA24: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EEA28: lui         $at, 0xC347
    ctx->r1 = S32(0XC347 << 16);
    // 0x801EEA2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EEA30: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEA34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EEA38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EEA3C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EEA40: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EEA44: ori         $a1, $a1, 0x1E
    ctx->r5 = ctx->r5 | 0X1E;
    // 0x801EEA48: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEA4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EEA50: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x801EEA54: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEA58: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EEA5C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EEA60: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EEA64: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EEA68: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801EEA6C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEA70: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EEA74: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EEA78: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEA7C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EEA80: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x801EEA84: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EEA88: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EEA8C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EEA90: lwc1        $f8, -0x370C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X370C);
    // 0x801EEA94: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801EEA98: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEA9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EEAA0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEAA4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EEAA8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEAAC: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EEAB0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EEAB4: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EEAB8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EEABC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEAC0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEAC4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEAC8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEACC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EEAD0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EEAD4: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
    // 0x801EEAD8: jal         0x801CC470
    // 0x801EEADC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EEADC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EEAE0: b           L_801EEAEC
    // 0x801EEAE4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801EEAEC;
    // 0x801EEAE4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801EEAE8:
    // 0x801EEAE8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801EEAEC:
    // 0x801EEAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EEAF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EEAF4: jr          $ra
    // 0x801EEAF8: nop

    return;
    // 0x801EEAF8: nop

;}
RECOMP_FUNC void M25_FUN_801eeafc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEAFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EEB00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EEB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EEB08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EEB0C: lui         $a1, 0x622
    ctx->r5 = S32(0X622 << 16);
    // 0x801EEB10: ori         $a1, $a1, 0x623A
    ctx->r5 = ctx->r5 | 0X623A;
    // 0x801EEB14: jal         0x801C0B8C
    // 0x801EEB18: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEB18: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EEB1C: beq         $v0, $zero, L_801EEB2C
    if (ctx->r2 == 0) {
        // 0x801EEB20: nop
    
            goto L_801EEB2C;
    }
    // 0x801EEB20: nop

    // 0x801EEB24: b           L_801EEB38
    // 0x801EEB28: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801EEB38;
    // 0x801EEB28: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801EEB2C:
    // 0x801EEB2C: jal         0x801C13F8
    // 0x801EEB30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C13F8)(rdram, ctx);
        goto after_1;
    // 0x801EEB30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x801EEB34: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801EEB38:
    // 0x801EEB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EEB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EEB40: jr          $ra
    // 0x801EEB44: nop

    return;
    // 0x801EEB44: nop

;}
RECOMP_FUNC void M25_FUN_801eeb48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEB48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EEB4C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801EEB50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EEB54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EEB58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EEB5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EEB60: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EEB64: ori         $a1, $a1, 0x1E
    ctx->r5 = ctx->r5 | 0X1E;
    // 0x801EEB68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EEB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EEB70: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EEB74: jal         0x801CC470
    // 0x801EEB78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801EEB78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801EEB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EEB80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EEB84: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801EEB88: jr          $ra
    // 0x801EEB8C: nop

    return;
    // 0x801EEB8C: nop

;}
RECOMP_FUNC void M25_FUN_801eeb90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEB90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEB94: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEB98: jr          $ra
    // 0x801EEB9C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801EEB9C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eeba0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eeba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEBA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEBA4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEBA8: jr          $ra
    // 0x801EEBAC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x801EEBAC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eebb0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eebb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEBB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEBB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEBB8: jr          $ra
    // 0x801EEBBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801EEBBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eebc0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eebc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EEBC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EEBC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EEBCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EEBD0: lui         $a1, 0x667
    ctx->r5 = S32(0X667 << 16);
    // 0x801EEBD4: ori         $a1, $a1, 0xC5A
    ctx->r5 = ctx->r5 | 0XC5A;
    // 0x801EEBD8: jal         0x801C0B8C
    // 0x801EEBDC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEBDC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EEBE0: beq         $v0, $zero, L_801EEBF0
    if (ctx->r2 == 0) {
        // 0x801EEBE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EEBF0;
    }
    // 0x801EEBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EEBE8: b           L_801EEBF4
    // 0x801EEBEC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801EEBF4;
    // 0x801EEBEC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801EEBF0:
    // 0x801EEBF0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801EEBF4:
    // 0x801EEBF4: jr          $ra
    // 0x801EEBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EEBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eebfc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eebfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEBFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EEC00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EEC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EEC08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EEC0C: lui         $a1, 0x667
    ctx->r5 = S32(0X667 << 16);
    // 0x801EEC10: ori         $a1, $a1, 0xC5A
    ctx->r5 = ctx->r5 | 0XC5A;
    // 0x801EEC14: jal         0x801C0B8C
    // 0x801EEC18: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEC18: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EEC1C: beq         $v0, $zero, L_801EECEC
    if (ctx->r2 == 0) {
        // 0x801EEC20: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EECEC;
    }
    // 0x801EEC20: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EEC24: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EEC28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EEC2C: lui         $at, 0xC34A
    ctx->r1 = S32(0XC34A << 16);
    // 0x801EEC30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EEC34: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEC38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EEC3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EEC40: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EEC44: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EEC48: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    // 0x801EEC4C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEC50: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EEC54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EEC58: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEC5C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EEC60: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EEC64: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EEC68: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EEC6C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801EEC70: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEC74: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EEC78: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EEC7C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEC80: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EEC84: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x801EEC88: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EEC8C: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EEC90: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EEC94: lwc1        $f8, -0x3708($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3708);
    // 0x801EEC98: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EEC9C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EECA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EECA4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EECA8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EECAC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EECB0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EECB4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EECB8: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EECBC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EECC0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EECC4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EECC8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EECCC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EECD0: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EECD4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EECD8: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
    // 0x801EECDC: jal         0x801CC470
    // 0x801EECE0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EECE0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EECE4: b           L_801EECF0
    // 0x801EECE8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_801EECF0;
    // 0x801EECE8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801EECEC:
    // 0x801EECEC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801EECF0:
    // 0x801EECF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EECF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EECF8: jr          $ra
    // 0x801EECFC: nop

    return;
    // 0x801EECFC: nop

;}
RECOMP_FUNC void M25_FUN_801eed00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EED00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EED04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EED08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EED0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EED10: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801EED14: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    // 0x801EED18: jal         0x801C0B8C
    // 0x801EED1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EED1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EED20: beq         $v0, $zero, L_801EEDF4
    if (ctx->r2 == 0) {
        // 0x801EED24: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EEDF4;
    }
    // 0x801EED24: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EED28: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EED2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EED30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EED34: lwc1        $f4, -0x3704($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3704);
    // 0x801EED38: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EED3C: lui         $at, 0xC178
    ctx->r1 = S32(0XC178 << 16);
    // 0x801EED40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EED44: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EED48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EED4C: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801EED50: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EED54: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    // 0x801EED58: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801EED5C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EED60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EED64: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EED68: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EED6C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EED70: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801EED74: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801EED78: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EED7C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EED80: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EED84: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EED88: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EED8C: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x801EED90: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EED94: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801EED98: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801EED9C: lwc1        $f8, -0x3700($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3700);
    // 0x801EEDA0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EEDA4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEDA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EEDAC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEDB0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EEDB4: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEDB8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EEDBC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EEDC0: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EEDC4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801EEDC8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEDCC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEDD0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEDD4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEDD8: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EEDDC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EEDE0: sh          $t7, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r15;
    // 0x801EEDE4: jal         0x801CC470
    // 0x801EEDE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EEDE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EEDEC: b           L_801EEDF8
    // 0x801EEDF0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801EEDF8;
    // 0x801EEDF0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801EEDF4:
    // 0x801EEDF4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801EEDF8:
    // 0x801EEDF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EEDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EEE00: jr          $ra
    // 0x801EEE04: nop

    return;
    // 0x801EEE04: nop

;}
RECOMP_FUNC void M25_FUN_801eee08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EEE0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EEE10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EEE14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EEE18: lui         $a1, 0x70E
    ctx->r5 = S32(0X70E << 16);
    // 0x801EEE1C: ori         $a1, $a1, 0xE51A
    ctx->r5 = ctx->r5 | 0XE51A;
    // 0x801EEE20: jal         0x801C0B8C
    // 0x801EEE24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEE24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EEE28: beq         $v0, $zero, L_801EEE60
    if (ctx->r2 == 0) {
        // 0x801EEE2C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801EEE60;
    }
    // 0x801EEE2C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801EEE30: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801EEE34: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EEE38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EEE3C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEE40: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801EEE44: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EEE48: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEE4C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEE50: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EEE54: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EEE58: b           L_801EEE64
    // 0x801EEE5C: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
        goto L_801EEE64;
    // 0x801EEE5C: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
L_801EEE60:
    // 0x801EEE60: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801EEE64:
    // 0x801EEE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EEE68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EEE6C: jr          $ra
    // 0x801EEE70: nop

    return;
    // 0x801EEE70: nop

;}
RECOMP_FUNC void M25_FUN_801eee74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEE74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEE78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEE7C: jr          $ra
    // 0x801EEE80: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x801EEE80: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eee84(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eee84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEE84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEE88: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEE8C: jr          $ra
    // 0x801EEE90: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    return;
    // 0x801EEE90: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eee94(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eee94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEE94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEE98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEE9C: jr          $ra
    // 0x801EEEA0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x801EEEA0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eeea4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eeea4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEEA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EEEA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EEEAC: jr          $ra
    // 0x801EEEB0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x801EEEB0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eeeb4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eeeb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEEB4: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801EEEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EEEBC: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801EEEC0: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801EEEC4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801EEEC8: jal         0x801BF628
    // 0x801EEECC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801EEECC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801EEED0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801EEED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EEED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801EEEDC: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801EEEE0: bne         $at, $zero, L_801EEEF0
    if (ctx->r1 != 0) {
        // 0x801EEEE4: nop
    
            goto L_801EEEF0;
    }
    // 0x801EEEE4: nop

    // 0x801EEEE8: b           L_801EEEF0
    // 0x801EEEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EEEF0;
    // 0x801EEEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EEEF0:
    // 0x801EEEF0: jr          $ra
    // 0x801EEEF4: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801EEEF4: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eeef8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eeef8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEEF8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EEEFC: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eef00(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eef00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EEF00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EEF04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EEF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EEF0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EEF10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EEF14: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEF18: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801EEF1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EEF20: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EEF24: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEF28: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEF2C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEF30: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EEF34: beql        $t2, $zero, L_801EF0D0
    if (ctx->r10 == 0) {
        // 0x801EEF38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801EF0D0;
    }
    goto skip_0;
    // 0x801EEF38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801EEF3C: jal         0x801C0B8C
    // 0x801EEF40: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EEF40: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    after_0:
    // 0x801EEF44: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EEF48: beq         $v0, $zero, L_801EF024
    if (ctx->r2 == 0) {
        // 0x801EEF4C: addiu       $v1, $v1, -0x54EC
        ctx->r3 = ADD32(ctx->r3, -0X54EC);
            goto L_801EF024;
    }
    // 0x801EEF4C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EEF50: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EEF54: lui         $at, 0xC34C
    ctx->r1 = S32(0XC34C << 16);
    // 0x801EEF58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EEF5C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEF60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EEF64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EEF68: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EEF6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EEF70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EEF74: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EEF78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EEF7C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EEF80: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EEF84: ori         $a1, $a1, 0x13
    ctx->r5 = ctx->r5 | 0X13;
    // 0x801EEF88: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EEF8C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EEF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EEF94: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801EEF98: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EEF9C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EEFA0: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801EEFA4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EEFA8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEFAC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EEFB0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEFB4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EEFB8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EEFBC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EEFC0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EEFC4: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801EEFC8: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801EEFCC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801EEFD0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEFD4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EEFD8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EEFDC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EEFE0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EEFE4: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801EEFE8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801EEFEC: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801EEFF0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801EEFF4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EEFF8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EEFFC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF000: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF004: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF008: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801EF00C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801EF010: sh          $t7, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r15;
    // 0x801EF014: jal         0x801CC470
    // 0x801EF018: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF018: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EF01C: b           L_801EF0D0
    // 0x801EF020: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EF0D0;
    // 0x801EF020: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EF024:
    // 0x801EF024: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EF028: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EF02C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EF030: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801EF034: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801EF038: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EF03C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF044: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF048: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF04C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF050: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801EF054: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801EF058: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x801EF05C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801EF060: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x801EF064: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF068: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801EF06C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF070: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF074: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801EF078: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801EF07C: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x801EF080: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x801EF084: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801EF088: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF08C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x801EF090: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x801EF094: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF098: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801EF09C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801EF0A0: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801EF0A4: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x801EF0A8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EF0AC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF0B0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF0B4: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x801EF0B8: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x801EF0BC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF0C0: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x801EF0C4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EF0C8: sh          $t1, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r9;
    // 0x801EF0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EF0D0:
    // 0x801EF0D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF0D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF0D8: jr          $ra
    // 0x801EF0DC: nop

    return;
    // 0x801EF0DC: nop

;}
RECOMP_FUNC void M25_FUN_801ef0e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF0E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EF0E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EF0E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EF0EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EF0F0: lui         $a1, 0x21C
    ctx->r5 = S32(0X21C << 16);
    // 0x801EF0F4: ori         $a1, $a1, 0x2940
    ctx->r5 = ctx->r5 | 0X2940;
    // 0x801EF0F8: jal         0x801C0B8C
    // 0x801EF0FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF0FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF100: beq         $v0, $zero, L_801EF130
    if (ctx->r2 == 0) {
        // 0x801EF104: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_801EF130;
    }
    // 0x801EF104: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EF108: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EF10C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF110: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EF114: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x801EF118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF11C: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EF120: jal         0x801CC470
    // 0x801EF124: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF124: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EF128: b           L_801EF134
    // 0x801EF12C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801EF134;
    // 0x801EF12C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EF130:
    // 0x801EF130: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EF134:
    // 0x801EF134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF13C: jr          $ra
    // 0x801EF140: nop

    return;
    // 0x801EF140: nop

;}
RECOMP_FUNC void M25_FUN_801ef144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EF148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EF14C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EF150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EF154: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801EF158: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801EF15C: jal         0x801C0B8C
    // 0x801EF160: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF160: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF164: beq         $v0, $zero, L_801EF244
    if (ctx->r2 == 0) {
        // 0x801EF168: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EF244;
    }
    // 0x801EF168: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EF16C: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EF170: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EF174: lui         $at, 0xC34E
    ctx->r1 = S32(0XC34E << 16);
    // 0x801EF178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF17C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF180: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EF184: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801EF188: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF18C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EF190: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF194: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF198: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EF19C: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801EF1A0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF1A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EF1A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF1AC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF1B0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EF1B4: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EF1B8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EF1BC: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801EF1C0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801EF1C4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF1C8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF1CC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF1D0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF1D4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF1D8: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EF1DC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EF1E0: addiu       $t0, $zero, 0xC2D
    ctx->r8 = ADD32(0, 0XC2D);
    // 0x801EF1E4: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801EF1E8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EF1EC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF1F0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF1F4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF1F8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF1FC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF200: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EF204: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EF208: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x801EF20C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801EF210: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF214: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF218: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF21C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF220: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF224: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EF228: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EF22C: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
    // 0x801EF230: lwc1        $f10, -0x36FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X36FC);
    // 0x801EF234: jal         0x801CC470
    // 0x801EF238: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF238: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EF23C: b           L_801EF248
    // 0x801EF240: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EF248;
    // 0x801EF240: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EF244:
    // 0x801EF244: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EF248:
    // 0x801EF248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF24C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF250: jr          $ra
    // 0x801EF254: nop

    return;
    // 0x801EF254: nop

;}
RECOMP_FUNC void M25_FUN_801ef258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF258: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF25C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF260: jr          $ra
    // 0x801EF264: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801EF264: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef268(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EF26C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EF270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EF274: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EF278: lui         $a1, 0x4B0
    ctx->r5 = S32(0X4B0 << 16);
    // 0x801EF27C: ori         $a1, $a1, 0x5BAA
    ctx->r5 = ctx->r5 | 0X5BAA;
    // 0x801EF280: jal         0x801C0B8C
    // 0x801EF284: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF284: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF288: beq         $v0, $zero, L_801EF2B8
    if (ctx->r2 == 0) {
        // 0x801EF28C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_801EF2B8;
    }
    // 0x801EF28C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EF290: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801EF294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF298: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EF29C: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801EF2A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF2A4: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EF2A8: jal         0x801CC470
    // 0x801EF2AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF2AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EF2B0: b           L_801EF2BC
    // 0x801EF2B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EF2BC;
    // 0x801EF2B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EF2B8:
    // 0x801EF2B8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EF2BC:
    // 0x801EF2BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF2C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF2C4: jr          $ra
    // 0x801EF2C8: nop

    return;
    // 0x801EF2C8: nop

;}
RECOMP_FUNC void M25_FUN_801ef2cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF2CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EF2D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EF2D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EF2D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EF2DC: lui         $a1, 0x4FF
    ctx->r5 = S32(0X4FF << 16);
    // 0x801EF2E0: ori         $a1, $a1, 0xB42A
    ctx->r5 = ctx->r5 | 0XB42A;
    // 0x801EF2E4: jal         0x801C0B8C
    // 0x801EF2E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF2E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF2EC: beq         $v0, $zero, L_801EF31C
    if (ctx->r2 == 0) {
        // 0x801EF2F0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_801EF31C;
    }
    // 0x801EF2F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EF2F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801EF2F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF2FC: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801EF300: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801EF304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF308: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801EF30C: jal         0x801CC470
    // 0x801EF310: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF310: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801EF314: b           L_801EF320
    // 0x801EF318: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801EF320;
    // 0x801EF318: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EF31C:
    // 0x801EF31C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EF320:
    // 0x801EF320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF328: jr          $ra
    // 0x801EF32C: nop

    return;
    // 0x801EF32C: nop

;}
RECOMP_FUNC void M25_FUN_801ef330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EF334: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EF338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF33C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EF340: lui         $a1, 0x5E5
    ctx->r5 = S32(0X5E5 << 16);
    // 0x801EF344: ori         $a1, $a1, 0x593A
    ctx->r5 = ctx->r5 | 0X593A;
    // 0x801EF348: jal         0x801C0B8C
    // 0x801EF34C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF34C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF350: beq         $v0, $zero, L_801EF40C
    if (ctx->r2 == 0) {
        // 0x801EF354: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801EF40C;
    }
    // 0x801EF354: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EF358: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EF35C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EF360: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF364: lwc1        $f4, -0x36F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X36F8);
    // 0x801EF368: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF36C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EF370: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF374: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF378: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801EF37C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF380: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF384: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF388: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EF38C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EF390: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801EF394: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EF398: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF39C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF3A0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF3A4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF3A8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF3AC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EF3B0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EF3B4: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x801EF3B8: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801EF3BC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EF3C0: lwc1        $f8, -0x36F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X36F4);
    // 0x801EF3C4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF3C8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF3CC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF3D0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF3D4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF3D8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EF3DC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EF3E0: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x801EF3E4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EF3E8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF3EC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF3F0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF3F4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF3F8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF3FC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EF400: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EF404: b           L_801EF410
    // 0x801EF408: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
        goto L_801EF410;
    // 0x801EF408: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
L_801EF40C:
    // 0x801EF40C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EF410:
    // 0x801EF410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EF418: jr          $ra
    // 0x801EF41C: nop

    return;
    // 0x801EF41C: nop

;}
RECOMP_FUNC void M25_FUN_801ef420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF420: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801EF424: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801EF428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EF42C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801EF430: lui         $a1, 0x66E
    ctx->r5 = S32(0X66E << 16);
    // 0x801EF434: ori         $a1, $a1, 0xAD7A
    ctx->r5 = ctx->r5 | 0XAD7A;
    // 0x801EF438: jal         0x801C0B8C
    // 0x801EF43C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF43C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF440: beq         $v0, $zero, L_801EF520
    if (ctx->r2 == 0) {
        // 0x801EF444: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801EF520;
    }
    // 0x801EF444: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801EF448: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801EF44C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801EF450: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF454: lwc1        $f4, -0x36F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X36F0);
    // 0x801EF458: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF45C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801EF460: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF464: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF468: lui         $a1, 0x168
    ctx->r5 = S32(0X168 << 16);
    // 0x801EF46C: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    // 0x801EF470: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF474: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801EF478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF47C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF480: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801EF484: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF488: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EF48C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EF490: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801EF494: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801EF498: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF49C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF4A0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF4A4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF4A8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF4AC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EF4B0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EF4B4: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x801EF4B8: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801EF4BC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801EF4C0: lwc1        $f8, -0x36EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X36EC);
    // 0x801EF4C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801EF4C8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF4CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EF4D0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF4D4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF4D8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF4DC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF4E0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EF4E4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EF4E8: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x801EF4EC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801EF4F0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF4F4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF4F8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF4FC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF500: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF504: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EF508: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EF50C: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
    // 0x801EF510: jal         0x801CC470
    // 0x801EF514: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801EF514: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801EF518: b           L_801EF524
    // 0x801EF51C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801EF524;
    // 0x801EF51C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801EF520:
    // 0x801EF520: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801EF524:
    // 0x801EF524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801EF52C: jr          $ra
    // 0x801EF530: nop

    return;
    // 0x801EF530: nop

;}
RECOMP_FUNC void M25_FUN_801ef534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EF538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EF53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EF544: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801EF548: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    // 0x801EF54C: jal         0x801C0B8C
    // 0x801EF550: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF550: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF554: beq         $v0, $zero, L_801EF614
    if (ctx->r2 == 0) {
        // 0x801EF558: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801EF614;
    }
    // 0x801EF558: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801EF55C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801EF560: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801EF564: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF568: lwc1        $f4, -0x36E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X36E8);
    // 0x801EF56C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF570: lui         $at, 0xC178
    ctx->r1 = S32(0XC178 << 16);
    // 0x801EF574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EF578: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF57C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF580: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801EF584: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF588: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF58C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF590: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EF594: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EF598: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801EF59C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801EF5A0: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF5A4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF5A8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF5AC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF5B0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF5B4: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801EF5B8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801EF5BC: addiu       $t0, $zero, 0x1800
    ctx->r8 = ADD32(0, 0X1800);
    // 0x801EF5C0: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801EF5C4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801EF5C8: lwc1        $f8, -0x36E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X36E4);
    // 0x801EF5CC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF5D0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF5D4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF5D8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF5DC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF5E0: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801EF5E4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801EF5E8: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x801EF5EC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801EF5F0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801EF5F4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801EF5F8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801EF5FC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801EF600: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801EF604: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801EF608: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801EF60C: b           L_801EF618
    // 0x801EF610: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
        goto L_801EF618;
    // 0x801EF610: sh          $t0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r8;
L_801EF614:
    // 0x801EF614: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801EF618:
    // 0x801EF618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EF620: jr          $ra
    // 0x801EF624: nop

    return;
    // 0x801EF624: nop

;}
RECOMP_FUNC void M25_FUN_801ef628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EF62C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EF630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF634: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EF638: lui         $a1, 0x70E
    ctx->r5 = S32(0X70E << 16);
    // 0x801EF63C: ori         $a1, $a1, 0xE51A
    ctx->r5 = ctx->r5 | 0XE51A;
    // 0x801EF640: jal         0x801C0B8C
    // 0x801EF644: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF644: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF648: beq         $v0, $zero, L_801EF684
    if (ctx->r2 == 0) {
        // 0x801EF64C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801EF684;
    }
    // 0x801EF64C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801EF650: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801EF654: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801EF658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EF65C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801EF660: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801EF664: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801EF668: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801EF66C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801EF670: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801EF674: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801EF678: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801EF67C: b           L_801EF688
    // 0x801EF680: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
        goto L_801EF688;
    // 0x801EF680: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
L_801EF684:
    // 0x801EF684: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EF688:
    // 0x801EF688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EF690: jr          $ra
    // 0x801EF694: nop

    return;
    // 0x801EF694: nop

;}
RECOMP_FUNC void M25_FUN_801ef698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF698: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF69C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF6A0: jr          $ra
    // 0x801EF6A4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801EF6A4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef6a8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef6a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF6A8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801EF6AC: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef6b0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF6B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801EF6B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801EF6B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801EF6BC: beq         $t6, $zero, L_801EF6CC
    if (ctx->r14 == 0) {
        // 0x801EF6C0: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801EF6CC;
    }
    // 0x801EF6C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801EF6C4: b           L_801EF704
    // 0x801EF6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801EF704;
    // 0x801EF6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801EF6CC:
    // 0x801EF6CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801EF6D0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801EF6D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801EF6D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801EF6DC: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801EF6E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801EF6E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801EF6E8: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801EF6EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EF6F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF6F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EF6F8: jal         0x8038C97C
    // 0x801EF6FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_0;
    // 0x801EF6FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x801EF700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EF704:
    // 0x801EF704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801EF708: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801EF70C: jr          $ra
    // 0x801EF710: nop

    return;
    // 0x801EF710: nop

;}
RECOMP_FUNC void M25_FUN_801ef714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF714: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801EF718: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801EF71C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF720: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF724: beq         $t6, $zero, L_801EF734
    if (ctx->r14 == 0) {
            // 0x801EF728: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801EF734)(rdram, ctx);
    return;
    }
    // 0x801EF728: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801EF72C: jr          $ra
    // 0x801EF730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801EF730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef734(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF734: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801EF738: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801EF73C: jr          $ra
    // 0x801EF740: nop

    return;
    // 0x801EF740: nop

;}
RECOMP_FUNC void M25_FUN_801ef744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801EF748: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801EF74C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801EF750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801EF754: lui         $a1, 0x758
    ctx->r5 = S32(0X758 << 16);
    // 0x801EF758: ori         $a1, $a1, 0x231A
    ctx->r5 = ctx->r5 | 0X231A;
    // 0x801EF75C: jal         0x801C0B8C
    // 0x801EF760: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF760: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF764: beq         $v0, $zero, L_801EF7B8
    if (ctx->r2 == 0) {
        // 0x801EF768: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801EF7B8;
    }
    // 0x801EF768: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801EF76C: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801EF770: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801EF774: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801EF778: beq         $t6, $zero, L_801EF788
    if (ctx->r14 == 0) {
        // 0x801EF77C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801EF788;
    }
    // 0x801EF77C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EF780: b           L_801EF7BC
    // 0x801EF784: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EF7BC;
    // 0x801EF784: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EF788:
    // 0x801EF788: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x801EF78C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801EF790: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801EF794: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801EF798: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801EF79C: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801EF7A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EF7A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801EF7A8: jal         0x8038C97C
    // 0x801EF7AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801EF7AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801EF7B0: b           L_801EF7BC
    // 0x801EF7B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801EF7BC;
    // 0x801EF7B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EF7B8:
    // 0x801EF7B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EF7BC:
    // 0x801EF7BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801EF7C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801EF7C4: jr          $ra
    // 0x801EF7C8: nop

    return;
    // 0x801EF7C8: nop

;}
RECOMP_FUNC void M25_FUN_801ef7cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF7CC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801EF7D0: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801EF7D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF7D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF7DC: beq         $t6, $zero, L_801EF7EC
    if (ctx->r14 == 0) {
            // 0x801EF7E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801EF7EC)(rdram, ctx);
    return;
    }
    // 0x801EF7E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EF7E4: jr          $ra
    // 0x801EF7E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801EF7E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef7ec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef7ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF7EC: jr          $ra
    // 0x801EF7F0: nop

    return;
    // 0x801EF7F0: nop

;}
RECOMP_FUNC void M25_FUN_801ef7f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF7F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF7F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF7FC: jr          $ra
    // 0x801EF800: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801EF800: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef804(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF804: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF808: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF80C: jr          $ra
    // 0x801EF810: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801EF810: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef814(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF814: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF818: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF81C: jr          $ra
    // 0x801EF820: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801EF820: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef824(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF824: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF828: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF82C: jr          $ra
    // 0x801EF830: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801EF830: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef834(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF834: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF838: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF83C: jr          $ra
    // 0x801EF840: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801EF840: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef844(rdram, ctx);
;}
