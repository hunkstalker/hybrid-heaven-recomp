#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80032a60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032A68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80032A6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80032A70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80032A74: jal         0x800267F0
    // 0x80032A78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_0;
    // 0x80032A78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80032A7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80032A80: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80032A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80032A88: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x80032A8C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x80032A90: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80032A94: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80032A98: jal         0x800267F0
    // 0x80032A9C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_1;
    // 0x80032A9C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x80032AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032AA8: jr          $ra
    // 0x80032AAC: nop

    return;
    // 0x80032AAC: nop

;}
RECOMP_FUNC void FUN_80032dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032DC0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80032DC4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80032DC8: jr          $ra
    // 0x80032DCC: nop

    return;
    // 0x80032DCC: nop

;}
RECOMP_FUNC void FUN_800331b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800331B8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800331BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800331C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800331C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800331C8: jal         0x80032D40
    // 0x800331CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80032D40)(rdram, ctx);
        goto after_0;
    // 0x800331CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800331D0: beq         $v0, $zero, L_800331E0
    if (ctx->r2 == 0) {
        // 0x800331D4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800331E0;
    }
    // 0x800331D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800331D8: b           L_800332AC
    // 0x800331DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800332AC;
    // 0x800331DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800331E0:
    // 0x800331E0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800331E4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800331E8: jal         0x80034060
    // 0x800331EC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80034060)(rdram, ctx);
        goto after_1;
    // 0x800331EC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800331F0: beq         $v0, $zero, L_80033200
    if (ctx->r2 == 0) {
        // 0x800331F4: addiu       $v1, $sp, 0x70
        ctx->r3 = ADD32(ctx->r29, 0X70);
            goto L_80033200;
    }
    // 0x800331F4: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x800331F8: b           L_800332AC
    // 0x800331FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800332AC;
    // 0x800331FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033200:
    // 0x80033200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033204: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
L_80033208:
    // 0x80033208: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8003320C: addiu       $t7, $v0, 0x2
    ctx->r15 = ADD32(ctx->r2, 0X2);
    // 0x80033210: addiu       $t8, $v0, 0x3
    ctx->r24 = ADD32(ctx->r2, 0X3);
    // 0x80033214: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80033218: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003321C: sb          $t8, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r24;
    // 0x80033220: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x80033224: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    // 0x80033228: bne         $v0, $a0, L_80033208
    if (ctx->r2 != ctx->r4) {
        // 0x8003322C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80033208;
    }
    // 0x8003322C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80033230: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80033234: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80033238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003323C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80033240: jal         0x80033E10
    // 0x80033244: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    LOOKUP_FUNC(0x80033E10)(rdram, ctx);
        goto after_2;
    // 0x80033244: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_2:
    // 0x80033248: beq         $v0, $zero, L_80033258
    if (ctx->r2 == 0) {
        // 0x8003324C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80033258;
    }
    // 0x8003324C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80033250: b           L_800332AC
    // 0x80033254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800332AC;
    // 0x80033254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033258:
    // 0x80033258: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8003325C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80033260: jal         0x80034060
    // 0x80033264: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80034060)(rdram, ctx);
        goto after_3;
    // 0x80033264: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x80033268: beq         $v0, $zero, L_80033278
    if (ctx->r2 == 0) {
        // 0x8003326C: addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
            goto L_80033278;
    }
    // 0x8003326C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80033270: b           L_800332AC
    // 0x80033274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800332AC;
    // 0x80033274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033278:
    // 0x80033278: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8003327C: jal         0x80031070
    // 0x80033280: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x80031070)(rdram, ctx);
        goto after_4;
    // 0x80033280: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x80033284: beq         $v0, $zero, L_80033294
    if (ctx->r2 == 0) {
        // 0x80033288: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80033294;
    }
    // 0x80033288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003328C: b           L_800332A8
    // 0x80033290: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800332A8;
    // 0x80033290: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80033294:
    // 0x80033294: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80033298: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8003329C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800332A0: jal         0x80033E10
    // 0x800332A4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80033E10)(rdram, ctx);
        goto after_5;
    // 0x800332A4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_5:
L_800332A8:
    // 0x800332A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800332AC:
    // 0x800332AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800332B0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x800332B4: jr          $ra
    // 0x800332B8: nop

    return;
    // 0x800332B8: nop

    // 0x800332BC: nop

;}
RECOMP_FUNC void FUN_800337f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800337F8: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x800337FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80033800: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80033804: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80033808: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8003380C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80033810: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80033814: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80033818: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003381C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80033820: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80033824: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80033828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003382C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80033830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033834: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80033838:
    // 0x80033838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003383C: sb          $zero, 0x102($v1)
    MEM_B(0X102, ctx->r3) = 0;
    // 0x80033840: sb          $zero, 0x103($v1)
    MEM_B(0X103, ctx->r3) = 0;
    // 0x80033844: sb          $zero, 0x104($v1)
    MEM_B(0X104, ctx->r3) = 0;
    // 0x80033848: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003384C: bne         $v0, $a0, L_80033838
    if (ctx->r2 != ctx->r4) {
        // 0x80033850: sb          $zero, 0xFD($v1)
        MEM_B(0XFD, ctx->r3) = 0;
            goto L_80033838;
    }
    // 0x80033850: sb          $zero, 0xFD($v1)
    MEM_B(0XFD, ctx->r3) = 0;
    // 0x80033854: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80033858: sb          $t6, 0x100($s4)
    MEM_B(0X100, ctx->r20) = ctx->r14;
    // 0x8003385C: lbu         $t7, 0x64($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X64);
    // 0x80033860: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80033864: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80033868: blez        $t7, L_80033A90
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003386C: addiu       $fp, $zero, 0x80
        ctx->r30 = ADD32(0, 0X80);
            goto L_80033A90;
    }
    // 0x8003386C: addiu       $fp, $zero, 0x80
    ctx->r30 = ADD32(0, 0X80);
    // 0x80033870: addiu       $s6, $sp, 0x15A
    ctx->r22 = ADD32(ctx->r29, 0X15A);
    // 0x80033874: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80033878: addiu       $s2, $sp, 0x158
    ctx->r18 = ADD32(ctx->r29, 0X158);
L_8003387C:
    // 0x8003387C: blez        $s0, L_8003388C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80033880: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003388C;
    }
    // 0x80033880: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80033884: b           L_80033890
    // 0x80033888: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80033890;
    // 0x80033888: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8003388C:
    // 0x8003388C: lw          $s1, 0x60($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X60);
L_80033890:
    // 0x80033890: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80033894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80033898: jal         0x8002BCB4
    // 0x8003389C: andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    LOOKUP_FUNC(0x8002BCB4)(rdram, ctx);
        goto after_0;
    // 0x8003389C: andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    after_0:
    // 0x800338A0: beq         $v0, $zero, L_800338B8
    if (ctx->r2 == 0) {
        // 0x800338A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800338B8;
    }
    // 0x800338A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800338A8: beql        $v0, $at, L_800338BC
    if (ctx->r2 == ctx->r1) {
        // 0x800338AC: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_800338BC;
    }
    goto skip_0;
    // 0x800338AC: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    skip_0:
    // 0x800338B0: b           L_80033A98
    // 0x800338B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80033A98;
    // 0x800338B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800338B8:
    // 0x800338B8: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
L_800338BC:
    // 0x800338BC: beq         $at, $zero, L_80033A78
    if (ctx->r1 == 0) {
        // 0x800338C0: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80033A78;
    }
    // 0x800338C0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800338C4: subu        $v1, $fp, $s1
    ctx->r3 = SUB32(ctx->r30, ctx->r17);
    // 0x800338C8: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800338CC: beq         $t8, $zero, L_80033960
    if (ctx->r24 == 0) {
        // 0x800338D0: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_80033960;
    }
    // 0x800338D0: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x800338D4: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x800338D8: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800338DC: sh          $at, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r1;
    // 0x800338E0: lw          $t4, 0x60($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X60);
    // 0x800338E4: lhu         $t3, 0x158($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X158);
    // 0x800338E8: lbu         $t5, 0x158($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X158);
    // 0x800338EC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800338F0: bnel        $at, $zero, L_8003395C
    if (ctx->r1 != 0) {
        // 0x800338F4: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_8003395C;
    }
    goto skip_1;
    // 0x800338F4: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800338F8: beq         $s0, $t5, L_80033958
    if (ctx->r16 == ctx->r13) {
        // 0x800338FC: lbu         $t6, 0x159($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X159);
            goto L_80033958;
    }
    // 0x800338FC: lbu         $t6, 0x159($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X159);
    // 0x80033900: bgez        $t6, L_80033910
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80033904: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_80033910;
    }
    // 0x80033904: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80033908: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x8003390C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_80033910:
    // 0x80033910: bgez        $t5, L_80033924
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80033914: andi        $t8, $t5, 0x7
        ctx->r24 = ctx->r13 & 0X7;
            goto L_80033924;
    }
    // 0x80033914: andi        $t8, $t5, 0x7
    ctx->r24 = ctx->r13 & 0X7;
    // 0x80033918: beq         $t8, $zero, L_80033924
    if (ctx->r24 == 0) {
        // 0x8003391C: nop
    
            goto L_80033924;
    }
    // 0x8003391C: nop

    // 0x80033920: addiu       $t8, $t8, -0x8
    ctx->r24 = ADD32(ctx->r24, -0X8);
L_80033924:
    // 0x80033924: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80033928: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8003392C: addu        $v0, $s4, $v1
    ctx->r2 = ADD32(ctx->r20, ctx->r3);
    // 0x80033930: lbu         $t1, 0x101($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X101);
    // 0x80033934: bgez        $s0, L_80033948
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80033938: andi        $t0, $s0, 0x7
        ctx->r8 = ctx->r16 & 0X7;
            goto L_80033948;
    }
    // 0x80033938: andi        $t0, $s0, 0x7
    ctx->r8 = ctx->r16 & 0X7;
    // 0x8003393C: beq         $t0, $zero, L_80033948
    if (ctx->r8 == 0) {
        // 0x80033940: nop
    
            goto L_80033948;
    }
    // 0x80033940: nop

    // 0x80033944: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80033948:
    // 0x80033948: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003394C: sllv        $t3, $t2, $t0
    ctx->r11 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x80033950: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80033954: sb          $t4, 0x101($v0)
    MEM_B(0X101, ctx->r2) = ctx->r12;
L_80033958:
    // 0x80033958: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_8003395C:
    // 0x8003395C: beq         $v0, $fp, L_80033A78
    if (ctx->r2 == ctx->r30) {
        // 0x80033960: sll         $t6, $v0, 1
        ctx->r14 = S32(ctx->r2 << 1);
            goto L_80033A78;
    }
L_80033960:
    // 0x80033960: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80033964: addu        $a1, $s5, $t6
    ctx->r5 = ADD32(ctx->r21, ctx->r14);
    // 0x80033968: addiu       $a0, $a1, 0x2
    ctx->r4 = ADD32(ctx->r5, 0X2);
L_8003396C:
    // 0x8003396C: lhu         $at, 0x0($a1)
    ctx->r1 = MEM_HU(ctx->r5, 0X0);
    // 0x80033970: sh          $at, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r1;
    // 0x80033974: lw          $t9, 0x60($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X60);
    // 0x80033978: lhu         $t7, 0x158($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X158);
    // 0x8003397C: lbu         $t2, 0x158($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X158);
    // 0x80033980: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033984: bnel        $at, $zero, L_800339F0
    if (ctx->r1 != 0) {
        // 0x80033988: lhu         $at, 0x0($a0)
        ctx->r1 = MEM_HU(ctx->r4, 0X0);
            goto L_800339F0;
    }
    goto skip_2;
    // 0x80033988: lhu         $at, 0x0($a0)
    ctx->r1 = MEM_HU(ctx->r4, 0X0);
    skip_2:
    // 0x8003398C: beq         $s0, $t2, L_800339EC
    if (ctx->r16 == ctx->r10) {
        // 0x80033990: lbu         $t0, 0x159($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X159);
            goto L_800339EC;
    }
    // 0x80033990: lbu         $t0, 0x159($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X159);
    // 0x80033994: bgez        $t0, L_800339A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80033998: sra         $t1, $t0, 2
        ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
            goto L_800339A4;
    }
    // 0x80033998: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8003399C: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
    // 0x800339A0: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_800339A4:
    // 0x800339A4: bgez        $t2, L_800339B8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800339A8: andi        $t3, $t2, 0x7
        ctx->r11 = ctx->r10 & 0X7;
            goto L_800339B8;
    }
    // 0x800339A8: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x800339AC: beq         $t3, $zero, L_800339B8
    if (ctx->r11 == 0) {
        // 0x800339B0: nop
    
            goto L_800339B8;
    }
    // 0x800339B0: nop

    // 0x800339B4: addiu       $t3, $t3, -0x8
    ctx->r11 = ADD32(ctx->r11, -0X8);
L_800339B8:
    // 0x800339B8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800339BC: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x800339C0: addu        $v0, $s4, $v1
    ctx->r2 = ADD32(ctx->r20, ctx->r3);
    // 0x800339C4: lbu         $t6, 0x101($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X101);
    // 0x800339C8: bgez        $s0, L_800339DC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800339CC: andi        $t5, $s0, 0x7
        ctx->r13 = ctx->r16 & 0X7;
            goto L_800339DC;
    }
    // 0x800339CC: andi        $t5, $s0, 0x7
    ctx->r13 = ctx->r16 & 0X7;
    // 0x800339D0: beq         $t5, $zero, L_800339DC
    if (ctx->r13 == 0) {
        // 0x800339D4: nop
    
            goto L_800339DC;
    }
    // 0x800339D4: nop

    // 0x800339D8: addiu       $t5, $t5, -0x8
    ctx->r13 = ADD32(ctx->r13, -0X8);
L_800339DC:
    // 0x800339DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800339E0: sllv        $t7, $t8, $t5
    ctx->r15 = S32(ctx->r24 << (ctx->r13 & 31));
    // 0x800339E4: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800339E8: sb          $t9, 0x101($v0)
    MEM_B(0X101, ctx->r2) = ctx->r25;
L_800339EC:
    // 0x800339EC: lhu         $at, 0x0($a0)
    ctx->r1 = MEM_HU(ctx->r4, 0X0);
L_800339F0:
    // 0x800339F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800339F4: sh          $at, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r1;
    // 0x800339F8: lw          $t1, 0x60($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X60);
    // 0x800339FC: lhu         $t3, 0x158($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X158);
    // 0x80033A00: lbu         $t4, 0x158($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X158);
    // 0x80033A04: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80033A08: bne         $at, $zero, L_80033A70
    if (ctx->r1 != 0) {
        // 0x80033A0C: nop
    
            goto L_80033A70;
    }
    // 0x80033A0C: nop

    // 0x80033A10: beq         $s0, $t4, L_80033A70
    if (ctx->r16 == ctx->r12) {
        // 0x80033A14: lbu         $t8, 0x159($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X159);
            goto L_80033A70;
    }
    // 0x80033A14: lbu         $t8, 0x159($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X159);
    // 0x80033A18: bgez        $t8, L_80033A28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80033A1C: sra         $t5, $t8, 2
        ctx->r13 = S32(SIGNED(ctx->r24) >> 2);
            goto L_80033A28;
    }
    // 0x80033A1C: sra         $t5, $t8, 2
    ctx->r13 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80033A20: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x80033A24: sra         $t5, $at, 2
    ctx->r13 = S32(SIGNED(ctx->r1) >> 2);
L_80033A28:
    // 0x80033A28: bgez        $t4, L_80033A3C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80033A2C: andi        $t6, $t4, 0x7
        ctx->r14 = ctx->r12 & 0X7;
            goto L_80033A3C;
    }
    // 0x80033A2C: andi        $t6, $t4, 0x7
    ctx->r14 = ctx->r12 & 0X7;
    // 0x80033A30: beq         $t6, $zero, L_80033A3C
    if (ctx->r14 == 0) {
        // 0x80033A34: nop
    
            goto L_80033A3C;
    }
    // 0x80033A34: nop

    // 0x80033A38: addiu       $t6, $t6, -0x8
    ctx->r14 = ADD32(ctx->r14, -0X8);
L_80033A3C:
    // 0x80033A3C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80033A40: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x80033A44: addu        $v0, $s4, $v1
    ctx->r2 = ADD32(ctx->r20, ctx->r3);
    // 0x80033A48: lbu         $t9, 0x101($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X101);
    // 0x80033A4C: bgez        $s0, L_80033A60
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80033A50: andi        $t0, $s0, 0x7
        ctx->r8 = ctx->r16 & 0X7;
            goto L_80033A60;
    }
    // 0x80033A50: andi        $t0, $s0, 0x7
    ctx->r8 = ctx->r16 & 0X7;
    // 0x80033A54: beq         $t0, $zero, L_80033A60
    if (ctx->r8 == 0) {
        // 0x80033A58: nop
    
            goto L_80033A60;
    }
    // 0x80033A58: nop

    // 0x80033A5C: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80033A60:
    // 0x80033A60: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80033A64: sllv        $t3, $t2, $t0
    ctx->r11 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x80033A68: or          $t1, $t9, $t3
    ctx->r9 = ctx->r25 | ctx->r11;
    // 0x80033A6C: sb          $t1, 0x101($v0)
    MEM_B(0X101, ctx->r2) = ctx->r9;
L_80033A70:
    // 0x80033A70: bne         $a0, $s6, L_8003396C
    if (ctx->r4 != ctx->r22) {
        // 0x80033A74: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8003396C;
    }
    // 0x80033A74: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80033A78:
    // 0x80033A78: lbu         $t4, 0x64($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X64);
    // 0x80033A7C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80033A80: andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    // 0x80033A84: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80033A88: bne         $at, $zero, L_8003387C
    if (ctx->r1 != 0) {
        // 0x80033A8C: or          $s7, $s0, $zero
        ctx->r23 = ctx->r16 | 0;
            goto L_8003387C;
    }
    // 0x80033A8C: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_80033A90:
    // 0x80033A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033A94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80033A98:
    // 0x80033A98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033A9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80033AA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80033AA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80033AA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80033AAC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80033AB0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80033AB4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80033AB8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80033ABC: jr          $ra
    // 0x80033AC0: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x80033AC0: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80033ac4(rdram, ctx);
;}
RECOMP_FUNC void FUN_80033ac4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80033AC8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80033ACC: lbu         $t8, 0x3C($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3C);
    // 0x80033AD0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80033AD4: lbu         $t6, 0x3D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3D);
    // 0x80033AD8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80033ADC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80033AE0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80033AE4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80033AE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80033AEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80033AF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80033AF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80033AF8: lbu         $t1, 0x64($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X64);
    // 0x80033AFC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80033B00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80033B04: bgez        $t6, L_80033B14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80033B08: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_80033B14;
    }
    // 0x80033B08: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80033B0C: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x80033B10: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_80033B14:
    // 0x80033B14: bgez        $t8, L_80033B28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80033B18: andi        $t9, $t8, 0x7
        ctx->r25 = ctx->r24 & 0X7;
            goto L_80033B28;
    }
    // 0x80033B18: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80033B1C: beq         $t9, $zero, L_80033B28
    if (ctx->r25 == 0) {
        // 0x80033B20: nop
    
            goto L_80033B28;
    }
    // 0x80033B20: nop

    // 0x80033B24: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80033B28:
    // 0x80033B28: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80033B2C: addu        $s6, $t7, $t0
    ctx->r22 = ADD32(ctx->r15, ctx->r8);
    // 0x80033B30: blez        $t1, L_80033C34
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80033B34: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80033C34;
    }
    // 0x80033B34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80033B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033B3C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80033B40:
    // 0x80033B40: blez        $v0, L_80033B50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80033B44: lbu         $t2, 0x3C($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X3C);
            goto L_80033B50;
    }
    // 0x80033B44: lbu         $t2, 0x3C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3C);
    // 0x80033B48: b           L_80033B54
    // 0x80033B4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80033B54;
    // 0x80033B4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80033B50:
    // 0x80033B50: lw          $s1, 0x60($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X60);
L_80033B54:
    // 0x80033B54: beq         $t2, $v0, L_80033B88
    if (ctx->r10 == ctx->r2) {
        // 0x80033B58: addu        $t3, $s3, $s6
        ctx->r11 = ADD32(ctx->r19, ctx->r22);
            goto L_80033B88;
    }
    // 0x80033B58: addu        $t3, $s3, $s6
    ctx->r11 = ADD32(ctx->r19, ctx->r22);
    // 0x80033B5C: lbu         $t4, 0x101($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X101);
    // 0x80033B60: bgez        $v0, L_80033B74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80033B64: andi        $t5, $v0, 0x7
        ctx->r13 = ctx->r2 & 0X7;
            goto L_80033B74;
    }
    // 0x80033B64: andi        $t5, $v0, 0x7
    ctx->r13 = ctx->r2 & 0X7;
    // 0x80033B68: beq         $t5, $zero, L_80033B74
    if (ctx->r13 == 0) {
        // 0x80033B6C: nop
    
            goto L_80033B74;
    }
    // 0x80033B6C: nop

    // 0x80033B70: addiu       $t5, $t5, -0x8
    ctx->r13 = ADD32(ctx->r13, -0X8);
L_80033B74:
    // 0x80033B74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80033B78: sllv        $t8, $t6, $t5
    ctx->r24 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x80033B7C: and         $t9, $t4, $t8
    ctx->r25 = ctx->r12 & ctx->r24;
    // 0x80033B80: beql        $t9, $zero, L_80033C20
    if (ctx->r25 == 0) {
        // 0x80033B84: lbu         $t3, 0x64($s4)
        ctx->r11 = MEM_BU(ctx->r20, 0X64);
            goto L_80033C20;
    }
    goto skip_0;
    // 0x80033B84: lbu         $t3, 0x64($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X64);
    skip_0:
L_80033B88:
    // 0x80033B88: lbu         $t7, 0x100($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X100);
    // 0x80033B8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80033B90: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80033B94: beq         $t7, $v0, L_80033BC0
    if (ctx->r15 == ctx->r2) {
        // 0x80033B98: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80033BC0;
    }
    // 0x80033B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80033B9C: jal         0x8002BCB4
    // 0x80033BA0: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x8002BCB4)(rdram, ctx);
        goto after_0;
    // 0x80033BA0: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    after_0:
    // 0x80033BA4: beql        $v0, $zero, L_80033BC0
    if (ctx->r2 == 0) {
        // 0x80033BA8: sb          $s2, 0x100($s3)
        MEM_B(0X100, ctx->r19) = ctx->r18;
            goto L_80033BC0;
    }
    goto skip_1;
    // 0x80033BA8: sb          $s2, 0x100($s3)
    MEM_B(0X100, ctx->r19) = ctx->r18;
    skip_1:
    // 0x80033BAC: beql        $v0, $s5, L_80033BC0
    if (ctx->r2 == ctx->r21) {
        // 0x80033BB0: sb          $s2, 0x100($s3)
        MEM_B(0X100, ctx->r19) = ctx->r18;
            goto L_80033BC0;
    }
    goto skip_2;
    // 0x80033BB0: sb          $s2, 0x100($s3)
    MEM_B(0X100, ctx->r19) = ctx->r18;
    skip_2:
    // 0x80033BB4: b           L_80033C3C
    // 0x80033BB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80033C3C;
    // 0x80033BB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80033BBC: sb          $s2, 0x100($s3)
    MEM_B(0X100, ctx->r19) = ctx->r18;
L_80033BC0:
    // 0x80033BC0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80033BC4: beq         $at, $zero, L_80033C08
    if (ctx->r1 == 0) {
        // 0x80033BC8: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_80033C08;
    }
    // 0x80033BC8: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x80033BCC: beq         $at, $zero, L_80033C08
    if (ctx->r1 == 0) {
        // 0x80033BD0: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_80033C08;
    }
    // 0x80033BD0: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80033BD4: addu        $v1, $s3, $v0
    ctx->r3 = ADD32(ctx->r19, ctx->r2);
    // 0x80033BD8: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
L_80033BDC:
    // 0x80033BDC: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x80033BE0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80033BE4: bnel        $t0, $t1, L_80033BF4
    if (ctx->r8 != ctx->r9) {
        // 0x80033BE8: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80033BF4;
    }
    goto skip_3;
    // 0x80033BE8: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    skip_3:
    // 0x80033BEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80033BF0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
L_80033BF4:
    // 0x80033BF4: beq         $at, $zero, L_80033C08
    if (ctx->r1 == 0) {
        // 0x80033BF8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80033C08;
    }
    // 0x80033BF8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80033BFC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80033C00: bnel        $at, $zero, L_80033BDC
    if (ctx->r1 != 0) {
        // 0x80033C04: lhu         $t0, 0x3C($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X3C);
            goto L_80033BDC;
    }
    goto skip_4;
    // 0x80033C04: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    skip_4:
L_80033C08:
    // 0x80033C08: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80033C0C: bnel        $at, $zero, L_80033C20
    if (ctx->r1 != 0) {
        // 0x80033C10: lbu         $t3, 0x64($s4)
        ctx->r11 = MEM_BU(ctx->r20, 0X64);
            goto L_80033C20;
    }
    goto skip_5;
    // 0x80033C10: lbu         $t3, 0x64($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X64);
    skip_5:
    // 0x80033C14: b           L_80033C38
    // 0x80033C18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80033C38;
    // 0x80033C18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80033C1C: lbu         $t3, 0x64($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X64);
L_80033C20:
    // 0x80033C20: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033C24: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80033C28: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80033C2C: bne         $at, $zero, L_80033B40
    if (ctx->r1 != 0) {
        // 0x80033C30: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80033B40;
    }
    // 0x80033C30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80033C34:
    // 0x80033C34: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80033C38:
    // 0x80033C38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80033C3C:
    // 0x80033C3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033C40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80033C44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80033C48: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80033C4C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80033C50: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80033C54: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80033C58: jr          $ra
    // 0x80033C5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80033C5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void FUN_80033c70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C70: mfc0        $t0, EntryHi
    ctx->r8 = cop0_register_read(ctx, 10);
    // 0x80033C74: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x80033C78: mtc0        $t1, Index
    cop0_register_write(ctx, 0, ctx->r9);    // 0x80033C7C: mtc0        $zero, PageMask
    cop0_register_write(ctx, 5, 0);    // 0x80033C80: addiu       $t2, $zero, 0x17
    ctx->r10 = ADD32(0, 0X17);
    // 0x80033C84: lui         $t1, 0xC000
    ctx->r9 = S32(0XC000 << 16);
    // 0x80033C88: mtc0        $t1, EntryHi
    cop0_register_write(ctx, 10, ctx->r9);    // 0x80033C8C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80033C90: srl         $t3, $t1, 6
    ctx->r11 = S32(U32(ctx->r9) >> 6);
    // 0x80033C94: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x80033C98: mtc0        $t3, EntryLo0
    cop0_register_write(ctx, 2, ctx->r11);    // 0x80033C9C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80033CA0: mtc0        $t1, EntryLo1
    cop0_register_write(ctx, 3, ctx->r9);    // 0x80033CA4: nop

    // 0x80033CA8: tlbwi

    // 0x80033CAC: nop

    // 0x80033CB0: nop

    // 0x80033CB4: nop

    // 0x80033CB8: nop

    // 0x80033CBC: mtc0        $t0, EntryHi
    cop0_register_write(ctx, 10, ctx->r8);    // 0x80033CC0: jr          $ra
    // 0x80033CC4: nop

    return;
    // 0x80033CC4: nop

    // 0x80033CC8: nop

    // 0x80033CCC: nop

;}
RECOMP_FUNC void FUN_80033d20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033D28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80033D2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80033D30: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80033D34: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80033D38: beql        $t6, $zero, L_80033DF4
    if (ctx->r14 == 0) {
        // 0x80033D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80033DF4;
    }
    goto skip_0;
    // 0x80033D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80033D40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033D44: jal         0x8002C6A0
    // 0x80033D48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x80033D48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80033D4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033D50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80033D54: beq         $v0, $zero, L_80033DF0
    if (ctx->r2 == 0) {
        // 0x80033D58: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80033DF0;
    }
    // 0x80033D58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80033D5C: lbu         $v0, 0x3B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X3B);
    // 0x80033D60: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80033D64: bnel        $at, $zero, L_80033D74
    if (ctx->r1 != 0) {
        // 0x80033D68: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_80033D74;
    }
    goto skip_1;
    // 0x80033D68: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_1:
    // 0x80033D6C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80033D70: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_80033D74:
    // 0x80033D74: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80033D78: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x80033D7C: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x80033D80: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80033D84: sh          $t1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r9;
    // 0x80033D88: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80033D8C: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x80033D90: lh          $t2, 0x1A($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1A);
    // 0x80033D94: sh          $t2, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r10;
    // 0x80033D98: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x80033D9C: sb          $t3, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r11;
    // 0x80033DA0: lh          $t4, 0x32($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X32);
    // 0x80033DA4: sb          $v0, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r2;
    // 0x80033DA8: sh          $t4, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r12;
    // 0x80033DAC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80033DB0: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80033DB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80033DB8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80033DBC: jal         0x8002C7CC
    // 0x80033DC0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8002C7CC)(rdram, ctx);
        goto after_1;
    // 0x80033DC0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80033DC4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80033DCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80033DD0: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80033DD4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80033DD8: sw          $t5, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r13;
    // 0x80033DDC: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x80033DE0: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80033DE4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80033DE8: jalr        $t9
    // 0x80033DEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80033DEC: nop

    after_2:
L_80033DF0:
    // 0x80033DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033DF4:
    // 0x80033DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033DF8: jr          $ra
    // 0x80033DFC: nop

    return;
    // 0x80033DFC: nop

;}
RECOMP_FUNC void __osGetCause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E00: mfc0        $v0, Cause
    ctx->r2 = cop0_cause_read(ctx);
    // 0x80033E04: jr          $ra
    // 0x80033E08: nop

    return;
    // 0x80033E08: nop

    // 0x80033E0C: nop

;}
RECOMP_FUNC void FUN_80034290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034290: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034294: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80034298: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8003429C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800342A0: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
L_800342A4:
    // 0x800342A4: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800342A8: and         $t8, $a0, $v0
    ctx->r24 = ctx->r4 & ctx->r2;
    // 0x800342AC: beq         $t8, $zero, L_800342D0
    if (ctx->r24 == 0) {
        // 0x800342B0: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800342D0;
    }
    // 0x800342B0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800342B4: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x800342B8: beq         $t9, $zero, L_800342C8
    if (ctx->r25 == 0) {
        // 0x800342BC: nop
    
            goto L_800342C8;
    }
    // 0x800342BC: nop

    // 0x800342C0: b           L_800342E0
    // 0x800342C4: xori        $v1, $t7, 0x14
    ctx->r3 = ctx->r15 ^ 0X14;
        goto L_800342E0;
    // 0x800342C4: xori        $v1, $t7, 0x14
    ctx->r3 = ctx->r15 ^ 0X14;
L_800342C8:
    // 0x800342C8: b           L_800342E0
    // 0x800342CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800342E0;
    // 0x800342CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800342D0:
    // 0x800342D0: andi        $t1, $v1, 0x20
    ctx->r9 = ctx->r3 & 0X20;
    // 0x800342D4: beq         $t1, $zero, L_800342E0
    if (ctx->r9 == 0) {
        // 0x800342D8: xori        $t2, $v1, 0x15
        ctx->r10 = ctx->r3 ^ 0X15;
            goto L_800342E0;
    }
    // 0x800342D8: xori        $t2, $v1, 0x15
    ctx->r10 = ctx->r3 ^ 0X15;
    // 0x800342DC: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800342E0:
    // 0x800342E0: srl         $t3, $v0, 1
    ctx->r11 = S32(U32(ctx->r2) >> 1);
    // 0x800342E4: bne         $t3, $zero, L_800342A4
    if (ctx->r11 != 0) {
        // 0x800342E8: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_800342A4;
    }
    // 0x800342E8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800342EC: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800342F0: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x800342F4: beq         $t5, $zero, L_80034300
    if (ctx->r13 == 0) {
        // 0x800342F8: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80034300;
    }
    // 0x800342F8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800342FC: xori        $v1, $t4, 0x15
    ctx->r3 = ctx->r12 ^ 0X15;
L_80034300:
    // 0x80034300: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80034304: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80034308: beq         $t8, $zero, L_80034314
    if (ctx->r24 == 0) {
        // 0x8003430C: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80034314;
    }
    // 0x8003430C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80034310: xori        $v1, $t7, 0x15
    ctx->r3 = ctx->r15 ^ 0X15;
L_80034314:
    // 0x80034314: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80034318: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8003431C: beq         $t1, $zero, L_80034328
    if (ctx->r9 == 0) {
        // 0x80034320: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80034328;
    }
    // 0x80034320: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80034324: xori        $v1, $t0, 0x15
    ctx->r3 = ctx->r8 ^ 0X15;
L_80034328:
    // 0x80034328: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8003432C: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80034330: beq         $t4, $zero, L_8003433C
    if (ctx->r12 == 0) {
        // 0x80034334: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_8003433C;
    }
    // 0x80034334: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80034338: xori        $v1, $t3, 0x15
    ctx->r3 = ctx->r11 ^ 0X15;
L_8003433C:
    // 0x8003433C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80034340: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80034344: beq         $t7, $zero, L_80034350
    if (ctx->r15 == 0) {
        // 0x80034348: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80034350;
    }
    // 0x80034348: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8003434C: xori        $v1, $t6, 0x15
    ctx->r3 = ctx->r14 ^ 0X15;
L_80034350:
    // 0x80034350: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80034354: andi        $t9, $v0, 0x1F
    ctx->r25 = ctx->r2 & 0X1F;
    // 0x80034358: jr          $ra
    // 0x8003435C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x8003435C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
RECOMP_FUNC void FUN_80034400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034400: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x80034404: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80034408: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003440C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80034410: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80034414: beql        $t6, $zero, L_80034430
    if (ctx->r14 == 0) {
        // 0x80034418: lbu         $v0, 0x9($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X9);
            goto L_80034430;
    }
    goto skip_0;
    // 0x80034418: lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9);
    skip_0:
    // 0x8003441C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80034420:
    // 0x80034420: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x80034424: bnel        $t7, $zero, L_80034420
    if (ctx->r15 != 0) {
        // 0x80034428: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80034420;
    }
    goto skip_1;
    // 0x80034428: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8003442C: lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9);
L_80034430:
    // 0x80034430: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80034434: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x80034438: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8003443C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80034440: lw          $v1, -0x54D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X54D0);
    // 0x80034444: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x80034448: beql        $t9, $t0, L_80034540
    if (ctx->r25 == ctx->r8) {
        // 0x8003444C: lw          $t2, 0xC($a0)
        ctx->r10 = MEM_W(ctx->r4, 0XC);
            goto L_80034540;
    }
    goto skip_2;
    // 0x8003444C: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80034450: bne         $v0, $zero, L_800344B8
    if (ctx->r2 != 0) {
        // 0x80034454: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800344B8;
    }
    // 0x80034454: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80034458: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8003445C: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x80034460: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80034464: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80034468: beq         $v0, $t1, L_80034474
    if (ctx->r2 == ctx->r9) {
        // 0x8003446C: lui         $t6, 0xA460
        ctx->r14 = S32(0XA460 << 16);
            goto L_80034474;
    }
    // 0x8003446C: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80034470: sw          $v0, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r2;
L_80034474:
    // 0x80034474: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80034478: lbu         $t3, 0x6($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X6);
    // 0x8003447C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80034480: beql        $v0, $t3, L_80034490
    if (ctx->r2 == ctx->r11) {
        // 0x80034484: lbu         $v0, 0x7($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X7);
            goto L_80034490;
    }
    goto skip_3;
    // 0x80034484: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    skip_3:
    // 0x80034488: sw          $v0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r2;
    // 0x8003448C: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
L_80034490:
    // 0x80034490: lbu         $t5, 0x7($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X7);
    // 0x80034494: beql        $v0, $t5, L_800344A4
    if (ctx->r2 == ctx->r13) {
        // 0x80034498: lbu         $v0, 0x8($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X8);
            goto L_800344A4;
    }
    goto skip_4;
    // 0x80034498: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    skip_4:
    // 0x8003449C: sw          $v0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r2;
    // 0x800344A0: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
L_800344A4:
    // 0x800344A4: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x800344A8: beql        $v0, $t7, L_80034518
    if (ctx->r2 == ctx->r15) {
        // 0x800344AC: lbu         $t7, 0x4($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X4);
            goto L_80034518;
    }
    goto skip_5;
    // 0x800344AC: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    skip_5:
    // 0x800344B0: b           L_80034514
    // 0x800344B4: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
        goto L_80034514;
    // 0x800344B4: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
L_800344B8:
    // 0x800344B8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800344BC: lbu         $t9, 0x5($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5);
    // 0x800344C0: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x800344C4: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x800344C8: beq         $v0, $t9, L_800344D4
    if (ctx->r2 == ctx->r25) {
        // 0x800344CC: lui         $t4, 0xA460
        ctx->r12 = S32(0XA460 << 16);
            goto L_800344D4;
    }
    // 0x800344CC: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x800344D0: sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
L_800344D4:
    // 0x800344D4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x800344D8: lbu         $t1, 0x6($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X6);
    // 0x800344DC: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x800344E0: beql        $v0, $t1, L_800344F0
    if (ctx->r2 == ctx->r9) {
        // 0x800344E4: lbu         $v0, 0x7($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X7);
            goto L_800344F0;
    }
    goto skip_6;
    // 0x800344E4: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    skip_6:
    // 0x800344E8: sw          $v0, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r2;
    // 0x800344EC: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
L_800344F0:
    // 0x800344F0: lbu         $t3, 0x7($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X7);
    // 0x800344F4: beql        $v0, $t3, L_80034504
    if (ctx->r2 == ctx->r11) {
        // 0x800344F8: lbu         $v0, 0x8($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X8);
            goto L_80034504;
    }
    goto skip_7;
    // 0x800344F8: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    skip_7:
    // 0x800344FC: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80034500: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
L_80034504:
    // 0x80034504: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80034508: beql        $v0, $t5, L_80034518
    if (ctx->r2 == ctx->r13) {
        // 0x8003450C: lbu         $t7, 0x4($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X4);
            goto L_80034518;
    }
    goto skip_8;
    // 0x8003450C: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    skip_8:
    // 0x80034510: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
L_80034514:
    // 0x80034514: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
L_80034518:
    // 0x80034518: sb          $t7, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r15;
    // 0x8003451C: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
    // 0x80034520: sb          $t8, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r24;
    // 0x80034524: lbu         $t9, 0x6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X6);
    // 0x80034528: sb          $t9, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r25;
    // 0x8003452C: lbu         $t0, 0x7($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X7);
    // 0x80034530: sb          $t0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r8;
    // 0x80034534: lbu         $t1, 0x8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X8);
    // 0x80034538: sb          $t1, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r9;
    // 0x8003453C: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
L_80034540:
    // 0x80034540: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80034544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034548: or          $t3, $t2, $a3
    ctx->r11 = ctx->r10 | ctx->r7;
    // 0x8003454C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80034550: jr          $ra
    // 0x80034554: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    return;
    // 0x80034554: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    // 0x80034558: nop

    // 0x8003455C: nop

;}
RECOMP_FUNC void __osSpRawWriteIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003464C: jal         0x800309E0
    // 0x80034650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800309E0)(rdram, ctx);
        goto after_0;
    // 0x80034650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034654: beq         $v0, $zero, L_80034664
    if (ctx->r2 == 0) {
        // 0x80034658: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80034664;
    }
    // 0x80034658: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003465C: b           L_80034678
    // 0x80034660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80034678;
    // 0x80034660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80034664:
    // 0x80034664: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80034668: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8003466C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034670: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80034674: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_80034678:
    // 0x80034678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003467C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034680: jr          $ra
    // 0x80034684: nop

    return;
    // 0x80034684: nop

    // 0x80034688: nop

    // 0x8003468C: nop

;}
RECOMP_FUNC void FUN_80034690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034690: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x80034694: jr          $ra
    // 0x80034698: sw          $a0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r4;
    return;
    // 0x80034698: sw          $a0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r4;
    // 0x8003469C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800346a0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800346a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346A0: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x800346A4: jr          $ra
    // 0x800346A8: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    return;
    // 0x800346A8: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    // 0x800346AC: nop

    // 0x800346B0: nop

    // 0x800346B4: nop

    // 0x800346B8: nop

    // 0x800346BC: nop

;}
RECOMP_FUNC void osCreateViManager(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800346C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800346C8: lui         $s0, 0x8005
    ctx->r16 = S32(0X8005 << 16);
    // 0x800346CC: addiu       $s0, $s0, -0x5010
    ctx->r16 = ADD32(ctx->r16, -0X5010);
    // 0x800346D0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800346D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800346D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800346DC: bnel        $t6, $zero, L_80034830
    if (ctx->r14 != 0) {
        // 0x800346E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80034830;
    }
    goto skip_0;
    // 0x800346E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800346E4: jal         0x80031220
    // 0x800346E8: nop

    LOOKUP_FUNC(0x80031220)(rdram, ctx);
        goto after_0;
    // 0x800346E8: nop

    after_0:
    // 0x800346EC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800346F0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800346F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800346F8: sw          $zero, -0x4FF4($at)
    MEM_W(-0X4FF4, ctx->r1) = 0;
    // 0x800346FC: addiu       $a1, $a1, -0x16C8
    ctx->r5 = ADD32(ctx->r5, -0X16C8);
    // 0x80034700: addiu       $a0, $a0, -0x16E0
    ctx->r4 = ADD32(ctx->r4, -0X16E0);
    // 0x80034704: jal         0x80030610
    // 0x80034708: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_1;
    // 0x80034708: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8003470C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80034710: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80034714: addiu       $a3, $a3, -0x1698
    ctx->r7 = ADD32(ctx->r7, -0X1698);
    // 0x80034718: addiu       $a2, $a2, -0x16B0
    ctx->r6 = ADD32(ctx->r6, -0X16B0);
    // 0x8003471C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80034720: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80034724: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80034728: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x8003472C: sb          $zero, 0x2($a2)
    MEM_B(0X2, ctx->r6) = 0;
    // 0x80034730: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80034734: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x80034738: sb          $zero, 0x2($a3)
    MEM_B(0X2, ctx->r7) = 0;
    // 0x8003473C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80034740: addiu       $a1, $a1, -0x16E0
    ctx->r5 = ADD32(ctx->r5, -0X16E0);
    // 0x80034744: jal         0x8002FB60
    // 0x80034748: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_2;
    // 0x80034748: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x8003474C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80034750: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80034754: addiu       $a2, $a3, -0x1698
    ctx->r6 = ADD32(ctx->r7, -0X1698);
    // 0x80034758: addiu       $a1, $a1, -0x16E0
    ctx->r5 = ADD32(ctx->r5, -0X16E0);
    // 0x8003475C: jal         0x8002FB60
    // 0x80034760: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_3;
    // 0x80034760: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80034764: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80034768: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8003476C: jal         0x80030C40
    // 0x80034770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80030C40)(rdram, ctx);
        goto after_4;
    // 0x80034770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80034774: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80034778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003477C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80034780: beq         $at, $zero, L_80034790
    if (ctx->r1 == 0) {
        // 0x80034784: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_80034790;
    }
    // 0x80034784: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80034788: jal         0x80030B60
    // 0x8003478C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80030B60)(rdram, ctx);
        goto after_5;
    // 0x8003478C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
L_80034790:
    // 0x80034790: jal         0x80032660
    // 0x80034794: nop

    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_6;
    // 0x80034794: nop

    after_6:
    // 0x80034798: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003479C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800347A0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800347A4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800347A8: addiu       $a0, $a0, -0x2890
    ctx->r4 = ADD32(ctx->r4, -0X2890);
    // 0x800347AC: addiu       $v1, $v1, -0x16E0
    ctx->r3 = ADD32(ctx->r3, -0X16E0);
    // 0x800347B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800347B4: addiu       $t2, $t2, -0x16E0
    ctx->r10 = ADD32(ctx->r10, -0X16E0);
    // 0x800347B8: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x800347BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800347C0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800347C4: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x800347C8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800347CC: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x800347D0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800347D4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800347D8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800347DC: addiu       $a2, $a2, 0x4840
    ctx->r6 = ADD32(ctx->r6, 0X4840);
    // 0x800347E0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800347E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800347E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800347EC: jal         0x80028260
    // 0x800347F0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_7;
    // 0x800347F0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_7:
    // 0x800347F4: jal         0x80032220
    // 0x800347F8: nop

    LOOKUP_FUNC(0x80032220)(rdram, ctx);
        goto after_8;
    // 0x800347F8: nop

    after_8:
    // 0x800347FC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80034800: jal         0x80034C90
    // 0x80034804: addiu       $a0, $a0, -0x2890
    ctx->r4 = ADD32(ctx->r4, -0X2890);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_9;
    // 0x80034804: addiu       $a0, $a0, -0x2890
    ctx->r4 = ADD32(ctx->r4, -0X2890);
    after_9:
    // 0x80034808: jal         0x800326D0
    // 0x8003480C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_10;
    // 0x8003480C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80034810: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80034814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003481C: beql        $t4, $at, L_80034830
    if (ctx->r12 == ctx->r1) {
        // 0x80034820: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80034830;
    }
    goto skip_1;
    // 0x80034820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80034824: jal         0x80030B60
    // 0x80034828: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    LOOKUP_FUNC(0x80030B60)(rdram, ctx);
        goto after_11;
    // 0x80034828: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_11:
    // 0x8003482C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80034830:
    // 0x80034830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80034834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80034838: jr          $ra
    // 0x8003483C: nop

    return;
    // 0x8003483C: nop

;}
RECOMP_FUNC void FUN_80034840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034840: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80034844: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80034848: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8003484C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80034850: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80034854: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80034858: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8003485C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80034860: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80034864: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80034868: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003486C: jal         0x800349D0
    // 0x80034870: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    LOOKUP_FUNC(0x800349D0)(rdram, ctx);
        goto after_0;
    // 0x80034870: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x80034874: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x80034878: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003487C: addiu       $s6, $zero, 0xE
    ctx->r22 = ADD32(0, 0XE);
    // 0x80034880: bne         $v1, $zero, L_80034894
    if (ctx->r3 != 0) {
        // 0x80034884: sh          $v1, -0x1680($at)
        MEM_H(-0X1680, ctx->r1) = ctx->r3;
            goto L_80034894;
    }
    // 0x80034884: sh          $v1, -0x1680($at)
    MEM_H(-0X1680, ctx->r1) = ctx->r3;
    // 0x80034888: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003488C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80034890: sh          $v1, -0x1680($at)
    MEM_H(-0X1680, ctx->r1) = ctx->r3;
L_80034894:
    // 0x80034894: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80034898: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8003489C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800348A0: addiu       $s1, $s1, -0x2970
    ctx->r17 = ADD32(ctx->r17, -0X2970);
    // 0x800348A4: addiu       $s2, $s2, -0x2968
    ctx->r18 = ADD32(ctx->r18, -0X2968);
    // 0x800348A8: addiu       $s3, $s3, -0x2964
    ctx->r19 = ADD32(ctx->r19, -0X2964);
    // 0x800348AC: addiu       $s5, $zero, 0xD
    ctx->r21 = ADD32(0, 0XD);
    // 0x800348B0: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
L_800348B4:
    // 0x800348B4: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
L_800348B8:
    // 0x800348B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800348BC: jal         0x800266B0
    // 0x800348C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_1;
    // 0x800348C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800348C4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800348C8: lhu         $v1, 0x0($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X0);
    // 0x800348CC: beq         $v1, $s5, L_800348E4
    if (ctx->r3 == ctx->r21) {
        // 0x800348D0: nop
    
            goto L_800348E4;
    }
    // 0x800348D0: nop

    // 0x800348D4: beq         $v1, $s6, L_80034980
    if (ctx->r3 == ctx->r22) {
        // 0x800348D8: nop
    
            goto L_80034980;
    }
    // 0x800348D8: nop

    // 0x800348DC: b           L_800348B8
    // 0x800348E0: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
        goto L_800348B8;
    // 0x800348E0: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
L_800348E4:
    // 0x800348E4: jal         0x80032360
    // 0x800348E8: nop

    LOOKUP_FUNC(0x80032360)(rdram, ctx);
        goto after_2;
    // 0x800348E8: nop

    after_2:
    // 0x800348EC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800348F0: lhu         $v1, -0x1680($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X1680);
    // 0x800348F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800348F8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800348FC: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x80034900: bne         $t7, $zero, L_8003493C
    if (ctx->r15 != 0) {
        // 0x80034904: sh          $t7, -0x1680($at)
        MEM_H(-0X1680, ctx->r1) = ctx->r15;
            goto L_8003493C;
    }
    // 0x80034904: sh          $t7, -0x1680($at)
    MEM_H(-0X1680, ctx->r1) = ctx->r15;
    // 0x80034908: jal         0x800349D0
    // 0x8003490C: nop

    LOOKUP_FUNC(0x800349D0)(rdram, ctx);
        goto after_3;
    // 0x8003490C: nop

    after_3:
    // 0x80034910: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80034914: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80034918: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003491C: beql        $t8, $zero, L_80034934
    if (ctx->r24 == 0) {
        // 0x80034920: lhu         $v1, 0x2($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X2);
            goto L_80034934;
    }
    goto skip_0;
    // 0x80034920: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    skip_0:
    // 0x80034924: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80034928: jal         0x80026300
    // 0x8003492C: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_4;
    // 0x8003492C: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    after_4:
    // 0x80034930: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
L_80034934:
    // 0x80034934: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80034938: sh          $v1, -0x1680($at)
    MEM_H(-0X1680, ctx->r1) = ctx->r3;
L_8003493C:
    // 0x8003493C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80034940: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80034944: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80034948: jal         0x8002BF90
    // 0x8003494C: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    LOOKUP_FUNC(0x8002BF90)(rdram, ctx);
        goto after_5;
    // 0x8003494C: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    after_5:
    // 0x80034950: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80034954: subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
    // 0x80034958: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8003495C: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x80034960: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80034964: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x80034968: addu        $t6, $at, $t2
    ctx->r14 = ADD32(ctx->r1, ctx->r10);
    // 0x8003496C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80034970: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80034974: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80034978: b           L_800348B4
    // 0x8003497C: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
        goto L_800348B4;
    // 0x8003497C: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
L_80034980:
    // 0x80034980: jal         0x800312AC
    // 0x80034984: nop

    LOOKUP_FUNC(0x800312AC)(rdram, ctx);
        goto after_6;
    // 0x80034984: nop

    after_6:
    // 0x80034988: b           L_800348B8
    // 0x8003498C: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
        goto L_800348B8;
    // 0x8003498C: lw          $a0, 0xC($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XC);
    // 0x80034990: nop

    // 0x80034994: nop

    // 0x80034998: nop

    // 0x8003499C: nop

    // 0x800349A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800349A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800349A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800349AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800349B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800349B4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800349B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800349BC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800349C0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800349C4: jr          $ra
    // 0x800349C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800349C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800349CC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800349d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800349d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349D0: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x800349D4: jr          $ra
    // 0x800349D8: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    return;
    // 0x800349D8: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x800349DC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800349e0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800349e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349E0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800349E4: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x800349E8: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x800349EC: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
L_800349F0:
    // 0x800349F0: cache       0x01, 0x0($t0)

    // 0x800349F4: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800349F8: bne         $at, $zero, L_800349F0
    if (ctx->r1 != 0) {
        // 0x800349FC: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800349F0;
    }
    // 0x800349FC: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80034A00: jr          $ra
    // 0x80034A04: nop

    return;
    // 0x80034A04: nop

    // 0x80034A08: nop

    // 0x80034A0C: nop

;}
RECOMP_FUNC void FUN_80034a10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A10: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80034A14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034A18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034A1C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034A20: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80034A24: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80034A28: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80034A2C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80034A30: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80034A34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80034A38: mflo        $v0
    ctx->r2 = lo;
    // 0x80034A3C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80034A40: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80034A44: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80034A48: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80034A4C: bne         $at, $zero, L_80034A5C
    if (ctx->r1 != 0) {
        // 0x80034A50: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_80034A5C;
    }
    // 0x80034A50: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x80034A54: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034A58: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_80034A5C:
    // 0x80034A5C: jr          $ra
    // 0x80034A60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80034A60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80034A64: nop

    // 0x80034A68: nop

    // 0x80034A6C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80034a70(rdram, ctx);
;}
RECOMP_FUNC void FUN_80034a70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A70: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80034A74: jr          $ra
    // 0x80034A78: lw          $v0, -0x66BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X66BC);
    return;
    // 0x80034A78: lw          $v0, -0x66BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X66BC);
    // 0x80034A7C: nop

    // 0x80034A80: trunc.l.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f4.u64 = TRUNC_L_D(ctx->f12.d);
    // 0x80034A84: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034A88: nop

    // 0x80034A8C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80034A90: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80034A94: jr          $ra
    // 0x80034A98: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80034A98: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80034A9C: trunc.l.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.u64 = TRUNC_L_S(ctx->f12.fl);
    // 0x80034AA0: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034AA4: nop

    // 0x80034AA8: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80034AAC: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80034AB0: jr          $ra
    // 0x80034AB4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80034AB4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80034ab8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80034ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034AB8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80034ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034AC0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80034AC4: nop

    // 0x80034AC8: cvt.l.d     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f4.u64 = CVT_L_D(ctx->f12.d);
    // 0x80034ACC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80034AD0: nop

    // 0x80034AD4: andi        $at, $v0, 0x4
    ctx->r1 = ctx->r2 & 0X4;
    // 0x80034AD8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80034ADC: beq         $v0, $zero, L_80034B34
    if (ctx->r2 == 0) {
        // 0x80034AE0: lui         $at, 0x43E0
        ctx->r1 = S32(0X43E0 << 16);
            goto L_80034B34;
    }
    // 0x80034AE0: lui         $at, 0x43E0
    ctx->r1 = S32(0X43E0 << 16);
    // 0x80034AE4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034AE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034AF0: sub.d       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f12.d - ctx->f4.d;
    // 0x80034AF4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80034AF8: nop

    // 0x80034AFC: cvt.l.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.u64 = CVT_L_D(ctx->f4.d);
    // 0x80034B00: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80034B04: nop

    // 0x80034B08: andi        $at, $v0, 0x4
    ctx->r1 = ctx->r2 & 0X4;
    // 0x80034B0C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80034B10: bne         $v0, $zero, L_80034B2C
    if (ctx->r2 != 0) {
        // 0x80034B14: nop
    
            goto L_80034B2C;
    }
    // 0x80034B14: nop

    // 0x80034B18: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80034B1C: ld          $t7, -0x2B20($t7)
    ctx->r15 = LD(ctx->r15, -0X2B20);
    // 0x80034B20: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034B24: b           L_80034B44
    // 0x80034B28: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
        goto L_80034B44;
    // 0x80034B28: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
L_80034B2C:
    // 0x80034B2C: b           L_80034B44
    // 0x80034B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80034B44;
    // 0x80034B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80034B34:
    // 0x80034B34: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034B38: nop

    // 0x80034B3C: bltz        $v0, L_80034B2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80034B40: nop
    
            goto L_80034B2C;
    }
    // 0x80034B40: nop

L_80034B44:
    // 0x80034B44: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034B48: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80034B4C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80034B50: jr          $ra
    // 0x80034B54: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80034B54: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80034B58: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80034B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034B60: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80034B64: nop

    // 0x80034B68: cvt.l.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.u64 = CVT_L_S(ctx->f12.fl);
    // 0x80034B6C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80034B70: nop

    // 0x80034B74: andi        $at, $v0, 0x4
    ctx->r1 = ctx->r2 & 0X4;
    // 0x80034B78: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80034B7C: beq         $v0, $zero, L_80034BD0
    if (ctx->r2 == 0) {
        // 0x80034B80: lui         $at, 0x5F00
        ctx->r1 = S32(0X5F00 << 16);
            goto L_80034BD0;
    }
    // 0x80034B80: lui         $at, 0x5F00
    ctx->r1 = S32(0X5F00 << 16);
    // 0x80034B84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034B8C: sub.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80034B90: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80034B94: nop

    // 0x80034B98: cvt.l.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.u64 = CVT_L_S(ctx->f4.fl);
    // 0x80034B9C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80034BA0: nop

    // 0x80034BA4: andi        $at, $v0, 0x4
    ctx->r1 = ctx->r2 & 0X4;
    // 0x80034BA8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80034BAC: bne         $v0, $zero, L_80034BC8
    if (ctx->r2 != 0) {
        // 0x80034BB0: nop
    
            goto L_80034BC8;
    }
    // 0x80034BB0: nop

    // 0x80034BB4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80034BB8: ld          $t7, -0x2B18($t7)
    ctx->r15 = LD(ctx->r15, -0X2B18);
    // 0x80034BBC: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034BC0: b           L_80034BE0
    // 0x80034BC4: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
        goto L_80034BE0;
    // 0x80034BC4: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
L_80034BC8:
    // 0x80034BC8: b           L_80034BE0
    // 0x80034BCC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80034BE0;
    // 0x80034BCC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80034BD0:
    // 0x80034BD0: dmfc1       $v0, $f4
    ctx->r2 = ctx->f4.u64;
    // 0x80034BD4: nop

    // 0x80034BD8: bltz        $v0, L_80034BC8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80034BDC: nop
    
            goto L_80034BC8;
    }
    // 0x80034BDC: nop

L_80034BE0:
    // 0x80034BE0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034BE4: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80034BE8: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80034BEC: jr          $ra
    // 0x80034BF0: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80034BF0: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80034BF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034BF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034BFC: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80034C00: dmtc1       $t6, $f4
    ctx->f4.u64 = ctx->r14;
    // 0x80034C04: jr          $ra
    // 0x80034C08: cvt.d.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_L(ctx->f4.u64);
    return;
    // 0x80034C08: cvt.d.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_L(ctx->f4.u64);
    // 0x80034C0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034C10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034C14: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80034C18: dmtc1       $t6, $f4
    ctx->f4.u64 = ctx->r14;
    // 0x80034C1C: jr          $ra
    // 0x80034C20: cvt.s.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_L(ctx->f4.u64);
    return;
    // 0x80034C20: cvt.s.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_L(ctx->f4.u64);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80034c24(rdram, ctx);
;}
RECOMP_FUNC void FUN_80034c24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034C24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034C28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034C2C: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80034C30: dmtc1       $t6, $f4
    ctx->f4.u64 = ctx->r14;
    // 0x80034C34: bgez        $t6, L_80034C50
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80034C38: cvt.d.l     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_L(ctx->f4.u64);
            goto L_80034C50;
    }
    // 0x80034C38: cvt.d.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_L(ctx->f4.u64);
    // 0x80034C3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80034C40: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80034C44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034C48: nop

    // 0x80034C4C: add.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f0.d + ctx->f6.d;
L_80034C50:
    // 0x80034C50: jr          $ra
    // 0x80034C54: nop

    return;
    // 0x80034C54: nop

    // 0x80034C58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034C5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034C60: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80034C64: dmtc1       $t6, $f4
    ctx->f4.u64 = ctx->r14;
    // 0x80034C68: bgez        $t6, L_80034C80
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80034C6C: cvt.s.l     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_L(ctx->f4.u64);
            goto L_80034C80;
    }
    // 0x80034C6C: cvt.s.l     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_L(ctx->f4.u64);
    // 0x80034C70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80034C74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034C78: nop

    // 0x80034C7C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80034C80:
    // 0x80034C80: jr          $ra
    // 0x80034C84: nop

    return;
    // 0x80034C84: nop

    // 0x80034C88: nop

    // 0x80034C8C: nop

;}
RECOMP_FUNC void FUN_80034e40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034E44: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80034E48: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80034E4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80034E50: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x80034E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034E58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80034E5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80034E60: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80034E64: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80034E68: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80034E6C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x80034E70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034E74: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80034E78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80034E7C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x80034E80: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80034E84: jal         0x8002C8F0
    // 0x80034E88: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8002C8F0)(rdram, ctx);
        goto after_0;
    // 0x80034E88: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80034E8C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80034E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80034E94: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x80034E98: jal         0x8002D490
    // 0x80034E9C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    LOOKUP_FUNC(0x8002D490)(rdram, ctx);
        goto after_1;
    // 0x80034E9C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x80034EA0: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80034EA4: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80034EA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80034EAC: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x80034EB0: jal         0x8002D000
    // 0x80034EB4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    LOOKUP_FUNC(0x8002D000)(rdram, ctx);
        goto after_2;
    // 0x80034EB4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x80034EB8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80034EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034EC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80034EC4: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x80034EC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80034ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034ED0: jr          $ra
    // 0x80034ED4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x80034ED4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80034ED8: nop

    // 0x80034EDC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80034ee0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80034ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80034EEC: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80034EF0: beql        $t6, $zero, L_80034F4C
    if (ctx->r14 == 0) {
        // 0x80034EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80034F4C;
    }
    goto skip_0;
    // 0x80034EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80034EF8: jal         0x8002C6A0
    // 0x80034EFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x80034EFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034F00: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80034F04: beq         $v0, $zero, L_80034F48
    if (ctx->r2 == 0) {
        // 0x80034F08: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80034F48;
    }
    // 0x80034F08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80034F0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80034F10: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80034F14: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80034F18: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80034F1C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80034F20: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80034F24: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80034F28: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80034F2C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80034F30: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80034F34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80034F38: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80034F3C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80034F40: jalr        $t9
    // 0x80034F44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80034F44: nop

    after_1:
L_80034F48:
    // 0x80034F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80034F4C:
    // 0x80034F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034F50: jr          $ra
    // 0x80034F54: nop

    return;
    // 0x80034F54: nop

    // 0x80034F58: nop

    // 0x80034F5C: nop

;}
RECOMP_FUNC void FUN_80034f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F60: jr          $ra
    // 0x80034F64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x80034F64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80034F68: nop

    // 0x80034F6C: nop

;}
RECOMP_FUNC void FUN_80035020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035020: lui         $t6, 0xA450
    ctx->r14 = S32(0XA450 << 16);
    // 0x80035024: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80035028: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003502C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80035030: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x80035034: beq         $t7, $zero, L_80035044
    if (ctx->r15 == 0) {
        // 0x80035038: nop
    
            goto L_80035044;
    }
    // 0x80035038: nop

    // 0x8003503C: b           L_80035048
    // 0x80035040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035048;
    // 0x80035040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035044:
    // 0x80035044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035048:
    // 0x80035048: jr          $ra
    // 0x8003504C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003504C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80035050(rdram, ctx);
;}
RECOMP_FUNC void FUN_80035050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80035054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035058: jal         0x80032660
    // 0x8003505C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x8003505C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80035060: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80035064: lw          $t6, -0x5130($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5130);
    // 0x80035068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003506C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035070: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80035074: jal         0x800326D0
    // 0x80035078: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80035078: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_1:
    // 0x8003507C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035080: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80035084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035088: jr          $ra
    // 0x8003508C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003508C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void FUN_80037614(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80037614u);
    return;
}
RECOMP_FUNC void FUN_80039ff0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80039FF0u);
    return;
}
RECOMP_FUNC void FUN_80043cac(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80043CACu);
    return;
}
RECOMP_FUNC void FUN_80048b20(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048B20u);
    return;
}
RECOMP_FUNC void FUN_80048b2c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048B2Cu);
    return;
}
RECOMP_FUNC void FUN_80048c98(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048C98u);
    return;
}
RECOMP_FUNC void FUN_80048cec(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048CECu);
    return;
}
RECOMP_FUNC void FUN_80048d9c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048D9Cu);
    return;
}
RECOMP_FUNC void FUN_80048db4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048DB4u);
    return;
}
RECOMP_FUNC void FUN_80048db8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80048DB8u);
    return;
}
RECOMP_FUNC void FUN_80049230(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049230u);
    return;
}
RECOMP_FUNC void FUN_8004923c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8004923Cu);
    return;
}
RECOMP_FUNC void FUN_800492b8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x800492B8u);
    return;
}
RECOMP_FUNC void FUN_800492c4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x800492C4u);
    return;
}
RECOMP_FUNC void FUN_800493b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493B8: tlt         $zero, $zero, 16

    // 0x800493BC: nop

    // 0x800493C0: bgezall     $at, L_800493C4
    if (SIGNED(ctx->r1) >= 0) {
        // 0x800493C4: teq         $zero, $zero, 16

    LOOKUP_FUNC(0x800493C4)(rdram, ctx);
        goto after_0;
    }
    goto skip_0;
L_800493C4:
    // 0x800493C4: teq         $zero, $zero, 16

    after_0:
    skip_0:
;}
RECOMP_FUNC void FUN_8004940c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8004940Cu);
    return;
}
RECOMP_FUNC void FUN_80049418(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049418u);
    return;
}
RECOMP_FUNC void FUN_80049424(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049424u);
    return;
}
RECOMP_FUNC void FUN_80049448(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049448u);
    return;
}
RECOMP_FUNC void FUN_80049544(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049544u);
    return;
}
RECOMP_FUNC void FUN_8004955c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8004955Cu);
    return;
}
RECOMP_FUNC void FUN_800495e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495E0: sra         $zero, $zero, 21
    // write to $zero
    // 0x800495E4: nop

    // 0x800495E8: bltzal      $t1, L_800495EC
    if (SIGNED(ctx->r9) < 0) {
        // 0x800495EC: .word       0x0000052C                   # dadd        $zero, $zero, $zero # 00000500 <InstrIdType: CPU_SPECIAL>
    // write to $zero
    LOOKUP_FUNC(0x800495EC)(rdram, ctx);
        goto after_0;
    }
L_800495EC:
    // 0x800495EC: .word       0x0000052C                   # dadd        $zero, $zero, $zero # 00000500 <InstrIdType: CPU_SPECIAL>
    // write to $zero
    after_0:
;}
RECOMP_FUNC void FUN_800495f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495F8: tlt         $zero, $zero, 20

    // 0x800495FC: nop

    // 0x80049600: bgezall     $t1, L_80049604
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80049604: teq         $zero, $zero, 20

    LOOKUP_FUNC(0x80049604)(rdram, ctx);
        goto after_0;
    }
    goto skip_0;
L_80049604:
    // 0x80049604: teq         $zero, $zero, 20

    after_0:
    skip_0:
;}
RECOMP_FUNC void FUN_80049604(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80049604u);
    return;
}
