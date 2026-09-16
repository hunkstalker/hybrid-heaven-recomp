#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_802227a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802227A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802227A8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802227AC: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802227B0: lw          $v1, 0xDC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XDC);
    // 0x802227B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802227B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802227BC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x802227C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x802227C4: bne         $a0, $v1, L_802227D8
    if (ctx->r4 != ctx->r3) {
        // 0x802227C8: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_802227D8;
    }
    // 0x802227C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x802227CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802227D0: b           L_802227E0
    // 0x802227D4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_802227E0;
    // 0x802227D4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_802227D8:
    // 0x802227D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802227DC: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_802227E0:
    // 0x802227E0: beq         $a3, $v1, L_802227F4
    if (ctx->r7 == ctx->r3) {
        // 0x802227E4: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_802227F4;
    }
    // 0x802227E4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x802227E8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x802227EC: b           L_802227F8
    // 0x802227F0: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_802227F8;
    // 0x802227F0: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_802227F4:
    // 0x802227F4: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_802227F8:
    // 0x802227F8: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x802227FC: sb          $zero, 0x392($v0)
    MEM_B(0X392, ctx->r2) = 0;
    // 0x80222800: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80222804: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80222808: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8022280C: bnel        $t9, $zero, L_80222838
    if (ctx->r25 != 0) {
        // 0x80222810: lbu         $t9, 0x30($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X30);
            goto L_80222838;
    }
    goto skip_0;
    // 0x80222810: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    skip_0:
    // 0x80222814: lbu         $t1, 0x2F9($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2F9);
    // 0x80222818: lbu         $t6, 0x31($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X31);
    // 0x8022281C: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x80222820: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80222824: andi        $t5, $t4, 0x60
    ctx->r13 = ctx->r12 & 0X60;
    // 0x80222828: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x8022282C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80222830: sb          $t8, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r24;
    // 0x80222834: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
L_80222838:
    // 0x80222838: lbu         $t2, 0x31($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X31);
    // 0x8022283C: lbu         $t5, 0x32($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X32);
    // 0x80222840: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80222844: andi        $t4, $t9, 0xFF7F
    ctx->r12 = ctx->r25 & 0XFF7F;
    // 0x80222848: sb          $t4, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r12;
    // 0x8022284C: andi        $t6, $t4, 0xFE
    ctx->r14 = ctx->r12 & 0XFE;
    // 0x80222850: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80222854: andi        $t7, $t5, 0xFF1F
    ctx->r15 = ctx->r13 & 0XFF1F;
    // 0x80222858: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
    // 0x8022285C: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x80222860: blez        $t8, L_8022287C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80222864: sb          $t7, 0x32($v0)
        MEM_B(0X32, ctx->r2) = ctx->r15;
            goto L_8022287C;
    }
    // 0x80222864: sb          $t7, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r15;
    // 0x80222868: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8022286C: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80222870: srl         $t1, $t9, 30
    ctx->r9 = S32(U32(ctx->r25) >> 30);
    // 0x80222874: beql        $t1, $zero, L_80222890
    if (ctx->r9 == 0) {
        // 0x80222878: lbu         $t2, 0x1031($t0)
        ctx->r10 = MEM_BU(ctx->r8, 0X1031);
            goto L_80222890;
    }
    goto skip_1;
    // 0x80222878: lbu         $t2, 0x1031($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1031);
    skip_1:
L_8022287C:
    // 0x8022287C: jal         0x802233B0
    // 0x80222880: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802233B0)(rdram, ctx);
        goto after_0;
    // 0x80222880: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80222884: b           L_80222AFC
    // 0x80222888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222AFC;
    // 0x80222888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8022288C: lbu         $t2, 0x1031($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1031);
L_80222890:
    // 0x80222890: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80222894: sll         $t7, $v1, 27
    ctx->r15 = S32(ctx->r3 << 27);
    // 0x80222898: beq         $a0, $t2, L_802228C0
    if (ctx->r4 == ctx->r10) {
        // 0x8022289C: srl         $t8, $t7, 30
        ctx->r24 = S32(U32(ctx->r15) >> 30);
            goto L_802228C0;
    }
    // 0x8022289C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x802228A0: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x802228A4: blez        $t3, L_802228C0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x802228A8: nop
    
            goto L_802228C0;
    }
    // 0x802228A8: nop

    // 0x802228AC: lw          $t4, 0x30($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X30);
    // 0x802228B0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x802228B4: srl         $t5, $t6, 30
    ctx->r13 = S32(U32(ctx->r14) >> 30);
    // 0x802228B8: beql        $t5, $zero, L_80222AFC
    if (ctx->r13 == 0) {
        // 0x802228BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80222AFC;
    }
    goto skip_2;
    // 0x802228BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_802228C0:
    // 0x802228C0: beql        $t8, $zero, L_80222938
    if (ctx->r24 == 0) {
        // 0x802228C4: lhu         $t9, 0x30($v0)
        ctx->r25 = MEM_HU(ctx->r2, 0X30);
            goto L_80222938;
    }
    goto skip_3;
    // 0x802228C4: lhu         $t9, 0x30($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X30);
    skip_3:
    // 0x802228C8: lhu         $v1, 0x36($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X36);
    // 0x802228CC: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x802228D0: bnel        $v1, $at, L_80222900
    if (ctx->r3 != ctx->r1) {
        // 0x802228D4: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_80222900;
    }
    goto skip_4;
    // 0x802228D4: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    skip_4:
    // 0x802228D8: lbu         $t9, 0x390($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X390);
    // 0x802228DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802228E0: bnel        $t9, $at, L_80222900
    if (ctx->r25 != ctx->r1) {
        // 0x802228E4: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_80222900;
    }
    goto skip_5;
    // 0x802228E4: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    skip_5:
    // 0x802228E8: lbu         $t1, 0x33($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X33);
    // 0x802228EC: andi        $t2, $t1, 0xFFE7
    ctx->r10 = ctx->r9 & 0XFFE7;
    // 0x802228F0: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x802228F4: b           L_80222934
    // 0x802228F8: sb          $t3, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r11;
        goto L_80222934;
    // 0x802228F8: sb          $t3, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r11;
    // 0x802228FC: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
L_80222900:
    // 0x80222900: bnel        $v1, $at, L_80222928
    if (ctx->r3 != ctx->r1) {
        // 0x80222904: lbu         $t7, 0x33($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X33);
            goto L_80222928;
    }
    goto skip_6;
    // 0x80222904: lbu         $t7, 0x33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X33);
    skip_6:
    // 0x80222908: lbu         $t4, 0x390($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X390);
    // 0x8022290C: bnel        $a0, $t4, L_80222928
    if (ctx->r4 != ctx->r12) {
        // 0x80222910: lbu         $t7, 0x33($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X33);
            goto L_80222928;
    }
    goto skip_7;
    // 0x80222910: lbu         $t7, 0x33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X33);
    skip_7:
    // 0x80222914: lbu         $t6, 0x33($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X33);
    // 0x80222918: andi        $t5, $t6, 0xFFE7
    ctx->r13 = ctx->r14 & 0XFFE7;
    // 0x8022291C: b           L_80222934
    // 0x80222920: sb          $t5, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r13;
        goto L_80222934;
    // 0x80222920: sb          $t5, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r13;
    // 0x80222924: lbu         $t7, 0x33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X33);
L_80222928:
    // 0x80222928: sb          $zero, 0x390($v0)
    MEM_B(0X390, ctx->r2) = 0;
    // 0x8022292C: andi        $t8, $t7, 0xFFE7
    ctx->r24 = ctx->r15 & 0XFFE7;
    // 0x80222930: sb          $t8, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r24;
L_80222934:
    // 0x80222934: lhu         $t9, 0x30($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X30);
L_80222938:
    // 0x80222938: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022293C: andi        $t1, $t9, 0x7
    ctx->r9 = ctx->r25 & 0X7;
    // 0x80222940: bnel        $t1, $at, L_8022295C
    if (ctx->r9 != ctx->r1) {
        // 0x80222944: lbu         $v1, 0x32($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X32);
            goto L_8022295C;
    }
    goto skip_8;
    // 0x80222944: lbu         $v1, 0x32($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X32);
    skip_8:
    // 0x80222948: jal         0x8022397C
    // 0x8022294C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8022397C)(rdram, ctx);
        goto after_1;
    // 0x8022294C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80222950: b           L_80222AFC
    // 0x80222954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222AFC;
    // 0x80222954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80222958: lbu         $v1, 0x32($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X32);
L_8022295C:
    // 0x8022295C: andi        $t2, $v1, 0x3
    ctx->r10 = ctx->r3 & 0X3;
    // 0x80222960: beq         $t2, $zero, L_80222978
    if (ctx->r10 == 0) {
        // 0x80222964: andi        $t3, $v1, 0xFFFC
        ctx->r11 = ctx->r3 & 0XFFFC;
            goto L_80222978;
    }
    // 0x80222964: andi        $t3, $v1, 0xFFFC
    ctx->r11 = ctx->r3 & 0XFFFC;
    // 0x80222968: ori         $t6, $t3, 0x2
    ctx->r14 = ctx->r11 | 0X2;
    // 0x8022296C: sb          $t6, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r14;
    // 0x80222970: andi        $t5, $t6, 0xF3
    ctx->r13 = ctx->r14 & 0XF3;
    // 0x80222974: sb          $t5, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r13;
L_80222978:
    // 0x80222978: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8022297C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80222980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80222984: sll         $t8, $t7, 27
    ctx->r24 = S32(ctx->r15 << 27);
    // 0x80222988: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8022298C: beql        $t9, $zero, L_802229CC
    if (ctx->r25 == 0) {
        // 0x80222990: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_802229CC;
    }
    goto skip_9;
    // 0x80222990: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_9:
    // 0x80222994: lhu         $t1, 0x36($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X36);
    // 0x80222998: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x8022299C: bnel        $t1, $at, L_802229CC
    if (ctx->r9 != ctx->r1) {
        // 0x802229A0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_802229CC;
    }
    goto skip_10;
    // 0x802229A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_10:
    // 0x802229A4: lbu         $t2, 0x390($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X390);
    // 0x802229A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802229AC: bnel        $t2, $at, L_802229CC
    if (ctx->r10 != ctx->r1) {
        // 0x802229B0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_802229CC;
    }
    goto skip_11;
    // 0x802229B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_11:
    // 0x802229B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x802229B8: jal         0x8036F528
    // 0x802229BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8036F528)(rdram, ctx);
        goto after_2;
    // 0x802229BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x802229C0: b           L_80222AFC
    // 0x802229C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222AFC;
    // 0x802229C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802229C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_802229CC:
    // 0x802229CC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x802229D0: jal         0x80010550
    // 0x802229D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x802229D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_3:
    // 0x802229D8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802229DC: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802229E0: lbu         $v1, 0x1031($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X1031);
    // 0x802229E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x802229E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x802229EC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x802229F0: bne         $at, $zero, L_80222A14
    if (ctx->r1 != 0) {
        // 0x802229F4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80222A14;
    }
    // 0x802229F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x802229F8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802229FC: beq         $v1, $at, L_80222A14
    if (ctx->r3 == ctx->r1) {
        // 0x80222A00: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80222A14;
    }
    // 0x80222A00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80222A04: jal         0x8022310C
    // 0x80222A08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8022310C)(rdram, ctx);
        goto after_4;
    // 0x80222A08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80222A0C: b           L_80222AFC
    // 0x80222A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222AFC;
    // 0x80222A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222A14:
    // 0x80222A14: lbu         $t3, 0x33($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X33);
    // 0x80222A18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80222A1C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80222A20: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80222A24: bnel        $t4, $at, L_80222A68
    if (ctx->r12 != ctx->r1) {
        // 0x80222A28: lbu         $t1, 0x74($t9)
        ctx->r9 = MEM_BU(ctx->r25, 0X74);
            goto L_80222A68;
    }
    goto skip_12;
    // 0x80222A28: lbu         $t1, 0x74($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X74);
    skip_12:
    // 0x80222A2C: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x80222A30: blezl       $t6, L_80222A68
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80222A34: lbu         $t1, 0x74($t9)
        ctx->r9 = MEM_BU(ctx->r25, 0X74);
            goto L_80222A68;
    }
    goto skip_13;
    // 0x80222A34: lbu         $t1, 0x74($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X74);
    skip_13:
    // 0x80222A38: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    // 0x80222A3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80222A40: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222A44: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80222A48: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80222A4C: bnel        $t8, $zero, L_80222A68
    if (ctx->r24 != 0) {
        // 0x80222A50: lbu         $t1, 0x74($t9)
        ctx->r9 = MEM_BU(ctx->r25, 0X74);
            goto L_80222A68;
    }
    goto skip_14;
    // 0x80222A50: lbu         $t1, 0x74($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X74);
    skip_14:
    // 0x80222A54: jal         0x800058DC
    // 0x80222A58: addiu       $a1, $a1, -0x2394
    ctx->r5 = ADD32(ctx->r5, -0X2394);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80222A58: addiu       $a1, $a1, -0x2394
    ctx->r5 = ADD32(ctx->r5, -0X2394);
    after_5:
    // 0x80222A5C: b           L_80222AFC
    // 0x80222A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222AFC;
    // 0x80222A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80222A64: lbu         $t1, 0x74($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X74);
L_80222A68:
    // 0x80222A68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80222A6C: bnel        $t1, $at, L_80222AB8
    if (ctx->r9 != ctx->r1) {
        // 0x80222A70: lw          $t5, 0x30($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X30);
            goto L_80222AB8;
    }
    goto skip_15;
    // 0x80222A70: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    skip_15:
    // 0x80222A74: lhu         $t2, 0x36($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X36);
    // 0x80222A78: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x80222A7C: bnel        $t2, $at, L_80222AB8
    if (ctx->r10 != ctx->r1) {
        // 0x80222A80: lw          $t5, 0x30($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X30);
            goto L_80222AB8;
    }
    goto skip_16;
    // 0x80222A80: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    skip_16:
    // 0x80222A84: lw          $t3, 0x30($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X30);
    // 0x80222A88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80222A8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80222A90: sll         $t4, $t3, 11
    ctx->r12 = S32(ctx->r11 << 11);
    // 0x80222A94: srl         $t6, $t4, 30
    ctx->r14 = S32(U32(ctx->r12) >> 30);
    // 0x80222A98: beq         $t6, $zero, L_80222AB4
    if (ctx->r14 == 0) {
        // 0x80222A9C: addiu       $a1, $zero, 0x509
        ctx->r5 = ADD32(0, 0X509);
            goto L_80222AB4;
    }
    // 0x80222A9C: addiu       $a1, $zero, 0x509
    ctx->r5 = ADD32(0, 0X509);
    // 0x80222AA0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80222AA4: jal         0x80226710
    // 0x80222AA8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80226710)(rdram, ctx);
        goto after_6;
    // 0x80222AA8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_6:
    // 0x80222AAC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80222AB0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_80222AB4:
    // 0x80222AB4: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
L_80222AB8:
    // 0x80222AB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80222ABC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222AC0: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x80222AC4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80222AC8: bne         $t8, $zero, L_80222AF0
    if (ctx->r24 != 0) {
        // 0x80222ACC: nop
    
            goto L_80222AF0;
    }
    // 0x80222ACC: nop

    // 0x80222AD0: lbu         $t9, 0x2F9($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2F9);
    // 0x80222AD4: lbu         $t6, 0x31($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X31);
    // 0x80222AD8: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x80222ADC: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80222AE0: andi        $t4, $t3, 0x60
    ctx->r12 = ctx->r11 & 0X60;
    // 0x80222AE4: andi        $t5, $t6, 0xFF9F
    ctx->r13 = ctx->r14 & 0XFF9F;
    // 0x80222AE8: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80222AEC: sb          $t7, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r15;
L_80222AF0:
    // 0x80222AF0: jal         0x800058DC
    // 0x80222AF4: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80222AF4: addiu       $a1, $a1, -0x1A64
    ctx->r5 = ADD32(ctx->r5, -0X1A64);
    after_7:
    // 0x80222AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222AFC:
    // 0x80222AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80222B00: jr          $ra
    // 0x80222B04: nop

    return;
    // 0x80222B04: nop

;}
RECOMP_FUNC void M10_FUN_80222b08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222B08: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80222B0C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222B10: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80222B14: lw          $t7, 0xDC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XDC);
    // 0x80222B18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80222B1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80222B20: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80222B24: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80222B28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80222B2C: bne         $a0, $t7, L_80222B40
    if (ctx->r4 != ctx->r15) {
        // 0x80222B30: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_80222B40;
    }
    // 0x80222B30: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80222B34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222B38: b           L_80222B48
    // 0x80222B3C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222B48;
    // 0x80222B3C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80222B40:
    // 0x80222B40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222B44: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222B48:
    // 0x80222B48: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80222B4C: addiu       $t9, $t9, -0x3D44
    ctx->r25 = ADD32(ctx->r25, -0X3D44);
    // 0x80222B50: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80222B54: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80222B58: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80222B5C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80222B60: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80222B64: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80222B68: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222B6C: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80222B70: lbu         $t2, 0x1031($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1031);
    // 0x80222B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80222B78: beql        $t2, $at, L_80222C20
    if (ctx->r10 == ctx->r1) {
        // 0x80222B7C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80222C20;
    }
    goto skip_0;
    // 0x80222B7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80222B80: lbu         $t5, 0x30($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X30);
    // 0x80222B84: lbu         $t3, 0x32($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X32);
    // 0x80222B88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80222B8C: andi        $t6, $t5, 0xFF9F
    ctx->r14 = ctx->r13 & 0XFF9F;
    // 0x80222B90: ori         $t9, $t6, 0x20
    ctx->r25 = ctx->r14 | 0X20;
    // 0x80222B94: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x80222B98: sb          $t9, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r25;
    // 0x80222B9C: andi        $t4, $t3, 0xFF1F
    ctx->r12 = ctx->r11 & 0XFF1F;
    // 0x80222BA0: sb          $t2, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r10;
    // 0x80222BA4: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x80222BA8: sb          $t4, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r12;
    // 0x80222BAC: jal         0x802237B0
    // 0x80222BB0: sb          $t3, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80222BB0: sb          $t3, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r11;
    after_0:
    // 0x80222BB4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80222BB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80222BBC: jal         0x800113D0
    // 0x80222BC0: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_1;
    // 0x80222BC0: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_1:
    // 0x80222BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80222BC8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80222BCC: jal         0x8013C6FC
    // 0x80222BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013C6FC)(rdram, ctx);
        goto after_2;
    // 0x80222BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80222BD4: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x80222BD8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80222BDC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80222BE0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80222BE4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80222BE8: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x80222BEC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80222BF0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80222BF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80222BF8: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80222BFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80222C00: jal         0x80011140
    // 0x80222C04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_3;
    // 0x80222C04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x80222C08: beq         $v0, $zero, L_80222C1C
    if (ctx->r2 == 0) {
        // 0x80222C0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80222C1C;
    }
    // 0x80222C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80222C10: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222C14: jal         0x800058DC
    // 0x80222C18: addiu       $a1, $a1, 0x2C30
    ctx->r5 = ADD32(ctx->r5, 0X2C30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80222C18: addiu       $a1, $a1, 0x2C30
    ctx->r5 = ADD32(ctx->r5, 0X2C30);
    after_4:
L_80222C1C:
    // 0x80222C1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80222C20:
    // 0x80222C20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80222C24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80222C28: jr          $ra
    // 0x80222C2C: nop

    return;
    // 0x80222C2C: nop

;}
RECOMP_FUNC void M10_FUN_80222c30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222C30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80222C34: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80222C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80222C3C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80222C40: addiu       $t7, $t7, -0x3D38
    ctx->r15 = ADD32(ctx->r15, -0X3D38);
    // 0x80222C44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80222C48: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x80222C4C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80222C50: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80222C54: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80222C58: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80222C5C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222C60: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80222C64: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80222C68: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80222C6C: lbu         $t0, 0x1031($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1031);
    // 0x80222C70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80222C74: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222C78: beq         $t0, $at, L_80222CEC
    if (ctx->r8 == ctx->r1) {
        // 0x80222C7C: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80222CEC;
    }
    // 0x80222C7C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80222C80: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80222C84: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80222C88: jal         0x80010550
    // 0x80222C8C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80222C8C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80222C90: beq         $v0, $zero, L_80222CEC
    if (ctx->r2 == 0) {
        // 0x80222C94: addiu       $t1, $sp, 0x24
        ctx->r9 = ADD32(ctx->r29, 0X24);
            goto L_80222CEC;
    }
    // 0x80222C94: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80222C98: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80222C9C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80222CA0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80222CA4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80222CA8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80222CAC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80222CB0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80222CB4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80222CB8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x80222CBC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80222CC0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80222CC4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80222CC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80222CCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80222CD0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80222CD4: jal         0x8013A28C
    // 0x80222CD8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x80222CD8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x80222CDC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222CE0: addiu       $a1, $a1, 0x2CFC
    ctx->r5 = ADD32(ctx->r5, 0X2CFC);
    // 0x80222CE4: jal         0x800058DC
    // 0x80222CE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80222CE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
L_80222CEC:
    // 0x80222CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80222CF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80222CF4: jr          $ra
    // 0x80222CF8: nop

    return;
    // 0x80222CF8: nop

;}
RECOMP_FUNC void M10_FUN_80222cfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222CFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80222D00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80222D04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80222D08: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x80222D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80222D10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80222D14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80222D18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80222D1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80222D20: bne         $a0, $t6, L_80222D34
    if (ctx->r4 != ctx->r14) {
        // 0x80222D24: lw          $s0, 0x5C($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X5C);
            goto L_80222D34;
    }
    // 0x80222D24: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x80222D28: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222D2C: b           L_80222D3C
    // 0x80222D30: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222D3C;
    // 0x80222D30: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80222D34:
    // 0x80222D34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222D38: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222D3C:
    // 0x80222D3C: lbu         $t7, 0x1031($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1031);
    // 0x80222D40: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80222D48: beq         $t7, $at, L_80222E70
    if (ctx->r15 == ctx->r1) {
        // 0x80222D4C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80222E70;
    }
    // 0x80222D4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80222D50: jal         0x802237B0
    // 0x80222D54: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80222D54: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80222D58: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80222D5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80222D60: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x80222D64: andi        $t9, $t8, 0xFF9F
    ctx->r25 = ctx->r24 & 0XFF9F;
    // 0x80222D68: ori         $t2, $t9, 0x20
    ctx->r10 = ctx->r25 | 0X20;
    // 0x80222D6C: ori         $t5, $t2, 0x1
    ctx->r13 = ctx->r10 | 0X1;
    // 0x80222D70: sb          $t2, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r10;
    // 0x80222D74: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80222D78: sb          $t5, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r13;
    // 0x80222D7C: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x80222D80: jal         0x80010550
    // 0x80222D84: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80222D84: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80222D88: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80222D8C: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x80222D90: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x80222D94: ori         $at, $at, 0x6F
    ctx->r1 = ctx->r1 | 0X6F;
    // 0x80222D98: bne         $t7, $at, L_80222E54
    if (ctx->r15 != ctx->r1) {
        // 0x80222D9C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80222E54;
    }
    // 0x80222D9C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80222DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80222DA4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80222DA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80222DAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80222DB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80222DB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80222DB8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80222DBC: nop

    // 0x80222DC0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80222DC4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80222DC8: nop

    // 0x80222DCC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80222DD0: beql        $a0, $zero, L_80222E20
    if (ctx->r4 == 0) {
        // 0x80222DD4: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_80222E20;
    }
    goto skip_0;
    // 0x80222DD4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80222DD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80222DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80222DE0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80222DE4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80222DE8: nop

    // 0x80222DEC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80222DF0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80222DF4: nop

    // 0x80222DF8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80222DFC: bne         $a0, $zero, L_80222E14
    if (ctx->r4 != 0) {
        // 0x80222E00: nop
    
            goto L_80222E14;
    }
    // 0x80222E00: nop

    // 0x80222E04: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80222E08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80222E0C: b           L_80222E2C
    // 0x80222E10: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80222E2C;
    // 0x80222E10: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80222E14:
    // 0x80222E14: b           L_80222E2C
    // 0x80222E18: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80222E2C;
    // 0x80222E18: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80222E1C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_80222E20:
    // 0x80222E20: nop

    // 0x80222E24: bltz        $a0, L_80222E14
    if (SIGNED(ctx->r4) < 0) {
        // 0x80222E28: nop
    
            goto L_80222E14;
    }
    // 0x80222E28: nop

L_80222E2C:
    // 0x80222E2C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80222E30: jal         0x80011590
    // 0x80222E34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x80222E34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_2:
    // 0x80222E38: lhu         $t9, 0x20($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X20);
    // 0x80222E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80222E40: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80222E44: bnel        $t9, $v0, L_80222E58
    if (ctx->r25 != ctx->r2) {
        // 0x80222E48: lhu         $t0, 0x26($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X26);
            goto L_80222E58;
    }
    goto skip_1;
    // 0x80222E48: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    skip_1:
    // 0x80222E4C: jal         0x803697AC
    // 0x80222E50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x803697AC)(rdram, ctx);
        goto after_3;
    // 0x80222E50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
L_80222E54:
    // 0x80222E54: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
L_80222E58:
    // 0x80222E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80222E5C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222E60: beql        $t0, $zero, L_80222E74
    if (ctx->r8 == 0) {
        // 0x80222E64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80222E74;
    }
    goto skip_2;
    // 0x80222E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80222E68: jal         0x800058DC
    // 0x80222E6C: addiu       $a1, $a1, 0x2E84
    ctx->r5 = ADD32(ctx->r5, 0X2E84);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80222E6C: addiu       $a1, $a1, 0x2E84
    ctx->r5 = ADD32(ctx->r5, 0X2E84);
    after_4:
L_80222E70:
    // 0x80222E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80222E74:
    // 0x80222E74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80222E78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80222E7C: jr          $ra
    // 0x80222E80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80222E80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80222e84(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80222e84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222E84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80222E88: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80222E8C: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80222E90: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // 0x80222E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80222E98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80222E9C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80222EA0: bne         $a0, $v0, L_80222EB4
    if (ctx->r4 != ctx->r2) {
        // 0x80222EA4: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_80222EB4;
    }
    // 0x80222EA4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80222EA8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222EAC: b           L_80222EBC
    // 0x80222EB0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80222EBC;
    // 0x80222EB0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80222EB4:
    // 0x80222EB4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80222EB8: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80222EBC:
    // 0x80222EBC: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x80222EC0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80222EC4: andi        $t8, $t7, 0xFF9F
    ctx->r24 = ctx->r15 & 0XFF9F;
    // 0x80222EC8: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x80222ECC: andi        $t3, $t0, 0xFE
    ctx->r11 = ctx->r8 & 0XFE;
    // 0x80222ED0: sb          $t0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r8;
    // 0x80222ED4: sb          $t3, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r11;
    // 0x80222ED8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80222EDC: sb          $t4, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r12;
    // 0x80222EE0: lbu         $v1, 0x1031($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X1031);
    // 0x80222EE4: beq         $v1, $at, L_80222FBC
    if (ctx->r3 == ctx->r1) {
        // 0x80222EE8: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_80222FBC;
    }
    // 0x80222EE8: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80222EEC: bne         $at, $zero, L_80222FBC
    if (ctx->r1 != 0) {
        // 0x80222EF0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80222FBC;
    }
    // 0x80222EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80222EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80222EF8: jal         0x802237B0
    // 0x80222EFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80222EFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80222F00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80222F04: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80222F08: jal         0x8013C6FC
    // 0x80222F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013C6FC)(rdram, ctx);
        goto after_1;
    // 0x80222F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80222F10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80222F14: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80222F18: jal         0x8013B808
    // 0x80222F1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B808)(rdram, ctx);
        goto after_2;
    // 0x80222F1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80222F20: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80222F24: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80222F28: lhu         $t5, 0x2C($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2C);
    // 0x80222F2C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80222F30: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80222F34: beq         $t5, $at, L_80222FA4
    if (ctx->r13 == ctx->r1) {
        // 0x80222F38: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80222FA4;
    }
    // 0x80222F38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80222F3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80222F40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80222F44: lbu         $t7, 0x74($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X74);
    // 0x80222F48: bnel        $t7, $at, L_80222FA8
    if (ctx->r15 != ctx->r1) {
        // 0x80222F4C: lbu         $t2, 0x30($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X30);
            goto L_80222FA8;
    }
    goto skip_0;
    // 0x80222F4C: lbu         $t2, 0x30($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X30);
    skip_0:
    // 0x80222F50: lhu         $v1, 0x36($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X36);
    // 0x80222F54: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x80222F58: beq         $v1, $at, L_80222F70
    if (ctx->r3 == ctx->r1) {
        // 0x80222F5C: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80222F70;
    }
    // 0x80222F5C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80222F60: beq         $v1, $at, L_80222F70
    if (ctx->r3 == ctx->r1) {
        // 0x80222F64: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_80222F70;
    }
    // 0x80222F64: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x80222F68: bne         $v1, $at, L_80222F90
    if (ctx->r3 != ctx->r1) {
        // 0x80222F6C: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_80222F90;
    }
    // 0x80222F6C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
L_80222F70:
    // 0x80222F70: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    // 0x80222F74: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222F78: addiu       $a1, $a1, 0x2FCC
    ctx->r5 = ADD32(ctx->r5, 0X2FCC);
    // 0x80222F7C: ori         $t0, $t9, 0x60
    ctx->r8 = ctx->r25 | 0X60;
    // 0x80222F80: jal         0x800058DC
    // 0x80222F84: sb          $t0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80222F84: sb          $t0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r8;
    after_3:
    // 0x80222F88: b           L_80222FC0
    // 0x80222F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222FC0;
    // 0x80222F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222F90:
    // 0x80222F90: sh          $zero, 0xB9A($a2)
    MEM_H(0XB9A, ctx->r6) = 0;
    // 0x80222F94: jal         0x800058DC
    // 0x80222F98: addiu       $a1, $a1, 0x2FD8
    ctx->r5 = ADD32(ctx->r5, 0X2FD8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80222F98: addiu       $a1, $a1, 0x2FD8
    ctx->r5 = ADD32(ctx->r5, 0X2FD8);
    after_4:
    // 0x80222F9C: b           L_80222FC0
    // 0x80222FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80222FC0;
    // 0x80222FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222FA4:
    // 0x80222FA4: lbu         $t2, 0x30($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X30);
L_80222FA8:
    // 0x80222FA8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80222FAC: addiu       $a1, $a1, 0x2FCC
    ctx->r5 = ADD32(ctx->r5, 0X2FCC);
    // 0x80222FB0: ori         $t3, $t2, 0x60
    ctx->r11 = ctx->r10 | 0X60;
    // 0x80222FB4: jal         0x800058DC
    // 0x80222FB8: sb          $t3, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80222FB8: sb          $t3, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r11;
    after_5:
L_80222FBC:
    // 0x80222FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80222FC0:
    // 0x80222FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80222FC4: jr          $ra
    // 0x80222FC8: nop

    return;
    // 0x80222FC8: nop

;}
RECOMP_FUNC void M10_FUN_80222fcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222FCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80222FD0: jr          $ra
    // 0x80222FD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80222FD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80222fd8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80222fd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222FD8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80222FDC: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80222fe0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80222fe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80222FE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80222FE4: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // 0x80222FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80222FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80222FF0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80222FF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80222FF8: bne         $a0, $v0, L_8022300C
    if (ctx->r4 != ctx->r2) {
        // 0x80222FFC: lw          $a1, 0x5C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X5C);
            goto L_8022300C;
    }
    // 0x80222FFC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80223000: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80223004: b           L_80223014
    // 0x80223008: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
        goto L_80223014;
    // 0x80223008: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_8022300C:
    // 0x8022300C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80223010: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_80223014:
    // 0x80223014: beq         $s0, $v0, L_80223028
    if (ctx->r16 == ctx->r2) {
        // 0x80223018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80223028;
    }
    // 0x80223018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8022301C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223020: b           L_80223030
    // 0x80223024: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80223030;
    // 0x80223024: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80223028:
    // 0x80223028: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8022302C: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80223030:
    // 0x80223030: lbu         $t6, 0x1031($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1031);
    // 0x80223034: lhu         $v1, 0xE($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XE);
    // 0x80223038: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8022303C: beq         $t6, $at, L_802230F8
    if (ctx->r14 == ctx->r1) {
        // 0x80223040: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_802230F8;
    }
    // 0x80223040: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80223044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80223048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8022304C: sb          $v1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r3;
    // 0x80223050: jal         0x802237B0
    // 0x80223054: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80223054: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80223058: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8022305C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80223060: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x80223064: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x80223068: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8022306C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80223070: beq         $t8, $at, L_802230F8
    if (ctx->r24 == ctx->r1) {
        // 0x80223074: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_802230F8;
    }
    // 0x80223074: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80223078: beq         $v1, $at, L_80223094
    if (ctx->r3 == ctx->r1) {
        // 0x8022307C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80223094;
    }
    // 0x8022307C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80223080: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80223084: beq         $v1, $at, L_80223094
    if (ctx->r3 == ctx->r1) {
        // 0x80223088: addiu       $at, $zero, 0xF6
        ctx->r1 = ADD32(0, 0XF6);
            goto L_80223094;
    }
    // 0x80223088: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x8022308C: bne         $v1, $at, L_802230A4
    if (ctx->r3 != ctx->r1) {
        // 0x80223090: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_802230A4;
    }
    // 0x80223090: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80223094:
    // 0x80223094: jal         0x8037FFF0
    // 0x80223098: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8037FFF0)(rdram, ctx);
        goto after_1;
    // 0x80223098: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8022309C: b           L_802230B8
    // 0x802230A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
        goto L_802230B8;
    // 0x802230A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_802230A4:
    // 0x802230A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802230A8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x802230AC: jal         0x80129554
    // 0x802230B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80129554)(rdram, ctx);
        goto after_2;
    // 0x802230B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x802230B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_802230B8:
    // 0x802230B8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x802230BC: beql        $t9, $zero, L_802230FC
    if (ctx->r25 == 0) {
        // 0x802230C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_802230FC;
    }
    goto skip_0;
    // 0x802230C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x802230C4: lbu         $t1, 0x30($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X30);
    // 0x802230C8: ori         $t2, $t1, 0x60
    ctx->r10 = ctx->r9 | 0X60;
    // 0x802230CC: sb          $t2, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r10;
    // 0x802230D0: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x802230D4: beq         $a0, $zero, L_802230E8
    if (ctx->r4 == 0) {
        // 0x802230D8: nop
    
            goto L_802230E8;
    }
    // 0x802230D8: nop

    // 0x802230DC: jal         0x80005700
    // 0x802230E0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x802230E0: nop

    after_3:
    // 0x802230E4: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_802230E8:
    // 0x802230E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x802230EC: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x802230F0: jal         0x800058DC
    // 0x802230F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x802230F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_802230F8:
    // 0x802230F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802230FC:
    // 0x802230FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80223100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80223104: jr          $ra
    // 0x80223108: nop

    return;
    // 0x80223108: nop

;}
RECOMP_FUNC void M10_FUN_8022310c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022310C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80223110: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80223114(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80223114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80223118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022311C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80223120: bne         $a0, $t6, L_80223134
    if (ctx->r4 != ctx->r14) {
        // 0x80223124: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80223134;
    }
    // 0x80223124: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80223128: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8022312C: b           L_8022313C
    // 0x80223130: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_8022313C;
    // 0x80223130: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80223134:
    // 0x80223134: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80223138: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_8022313C:
    // 0x8022313C: lw          $a1, 0x5C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X5C);
    // 0x80223140: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80223144: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80223148: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8022314C: jal         0x80011198
    // 0x80223150: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_0;
    // 0x80223150: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80223154: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80223158: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8022315C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80223160: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80223164: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80223168: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8022316C: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80223170: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80223174: beq         $t9, $zero, L_80223204
    if (ctx->r25 == 0) {
        // 0x80223178: nop
    
            goto L_80223204;
    }
    // 0x80223178: nop

    // 0x8022317C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80223180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80223184: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80223188: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8022318C: jal         0x802237B0
    // 0x80223190: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_1;
    // 0x80223190: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80223194: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80223198: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8022319C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x802231A0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x802231A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x802231A8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802231AC: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x802231B0: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x802231B4: bne         $t0, $v0, L_802231CC
    if (ctx->r8 != ctx->r2) {
        // 0x802231B8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_802231CC;
    }
    // 0x802231B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x802231BC: lui         $t1, 0x8038
    ctx->r9 = S32(0X8038 << 16);
    // 0x802231C0: addiu       $t1, $t1, 0x6480
    ctx->r9 = ADD32(ctx->r9, 0X6480);
    // 0x802231C4: b           L_802231F0
    // 0x802231C8: sw          $t1, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r9;
        goto L_802231F0;
    // 0x802231C8: sw          $t1, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r9;
L_802231CC:
    // 0x802231CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802231D0: bne         $v0, $at, L_802231E8
    if (ctx->r2 != ctx->r1) {
        // 0x802231D4: lui         $t3, 0x8038
        ctx->r11 = S32(0X8038 << 16);
            goto L_802231E8;
    }
    // 0x802231D4: lui         $t3, 0x8038
    ctx->r11 = S32(0X8038 << 16);
    // 0x802231D8: lui         $t2, 0x8038
    ctx->r10 = S32(0X8038 << 16);
    // 0x802231DC: addiu       $t2, $t2, 0x6470
    ctx->r10 = ADD32(ctx->r10, 0X6470);
    // 0x802231E0: b           L_802231F0
    // 0x802231E4: sw          $t2, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r10;
        goto L_802231F0;
    // 0x802231E4: sw          $t2, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r10;
L_802231E8:
    // 0x802231E8: addiu       $t3, $t3, 0x6450
    ctx->r11 = ADD32(ctx->r11, 0X6450);
    // 0x802231EC: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
L_802231F0:
    // 0x802231F0: sh          $t0, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r8;
    // 0x802231F4: jal         0x800058DC
    // 0x802231F8: addiu       $a1, $a1, 0x321C
    ctx->r5 = ADD32(ctx->r5, 0X321C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x802231F8: addiu       $a1, $a1, 0x321C
    ctx->r5 = ADD32(ctx->r5, 0X321C);
    after_2:
    // 0x802231FC: b           L_80223210
    // 0x80223200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80223210;
    // 0x80223200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80223204:
    // 0x80223204: jal         0x800058DC
    // 0x80223208: addiu       $a1, $a1, 0x3260
    ctx->r5 = ADD32(ctx->r5, 0X3260);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80223208: addiu       $a1, $a1, 0x3260
    ctx->r5 = ADD32(ctx->r5, 0X3260);
    after_3:
    // 0x8022320C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80223210:
    // 0x80223210: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80223214: jr          $ra
    // 0x80223218: nop

    return;
    // 0x80223218: nop

;}
RECOMP_FUNC void M10_FUN_8022321c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022321C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80223220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80223224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80223228: jal         0x801DB6B8
    // 0x8022322C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801DB6B8)(rdram, ctx);
        goto after_0;
    // 0x8022322C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80223230: beq         $v0, $zero, L_80223250
    if (ctx->r2 == 0) {
        // 0x80223234: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80223250;
    }
    // 0x80223234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80223238: jal         0x802237B0
    // 0x8022323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_1;
    // 0x8022323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80223240: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80223244: addiu       $a1, $a1, 0x3260
    ctx->r5 = ADD32(ctx->r5, 0X3260);
    // 0x80223248: jal         0x800058DC
    // 0x8022324C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8022324C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80223250:
    // 0x80223250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80223254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80223258: jr          $ra
    // 0x8022325C: nop

    return;
    // 0x8022325C: nop

;}
RECOMP_FUNC void M10_FUN_80223260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223260: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80223264: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80223268: lhu         $t7, -0x43E4($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X43E4);
    // 0x8022326C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80223270: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80223274: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80223278: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8022327C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80223280: bne         $t7, $at, L_80223298
    if (ctx->r15 != ctx->r1) {
        // 0x80223284: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80223298;
    }
    // 0x80223284: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80223288: jal         0x802408F0
    // 0x8022328C: nop

    LOOKUP_FUNC(0x802408F0)(rdram, ctx);
        goto after_0;
    // 0x8022328C: nop

    after_0:
    // 0x80223290: b           L_80223398
    // 0x80223294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80223398;
    // 0x80223294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80223298:
    // 0x80223298: lhu         $v0, 0x36($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X36);
    // 0x8022329C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x802232A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x802232A4: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232A8: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_802232F0;
    }
    // 0x802232A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x802232AC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x802232B0: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232B4: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_802232F0;
    }
    // 0x802232B4: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x802232B8: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232BC: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_802232F0;
    }
    // 0x802232BC: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x802232C0: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232C4: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_802232F0;
    }
    // 0x802232C4: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x802232C8: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232CC: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_802232F0;
    }
    // 0x802232CC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x802232D0: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232D4: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_802232F0;
    }
    // 0x802232D4: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x802232D8: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232DC: addiu       $at, $zero, 0x58
        ctx->r1 = ADD32(0, 0X58);
            goto L_802232F0;
    }
    // 0x802232DC: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x802232E0: beq         $v0, $at, L_802232F0
    if (ctx->r2 == ctx->r1) {
        // 0x802232E4: addiu       $at, $zero, 0x59
        ctx->r1 = ADD32(0, 0X59);
            goto L_802232F0;
    }
    // 0x802232E4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x802232E8: bne         $v0, $at, L_80223308
    if (ctx->r2 != ctx->r1) {
        // 0x802232EC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80223308;
    }
    // 0x802232EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_802232F0:
    // 0x802232F0: lui         $a2, 0x168
    ctx->r6 = S32(0X168 << 16);
    // 0x802232F4: ori         $a2, $a2, 0x41
    ctx->r6 = ctx->r6 | 0X41;
    // 0x802232F8: jal         0x80225664
    // 0x802232FC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80225664)(rdram, ctx);
        goto after_1;
    // 0x802232FC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x80223300: b           L_8022331C
    // 0x80223304: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
        goto L_8022331C;
    // 0x80223304: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
L_80223308:
    // 0x80223308: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8022330C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80223310: jal         0x802256E4
    // 0x80223314: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_2;
    // 0x80223314: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x80223318: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
L_8022331C:
    // 0x8022331C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80223320: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80223324: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80223328: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8022332C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80223330: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80223334: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80223338: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8022333C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80223340: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80223344: jal         0x80011140
    // 0x80223348: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_3;
    // 0x80223348: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x8022334C: beq         $v0, $zero, L_80223394
    if (ctx->r2 == 0) {
        // 0x80223350: addiu       $t2, $sp, 0x28
        ctx->r10 = ADD32(ctx->r29, 0X28);
            goto L_80223394;
    }
    // 0x80223350: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80223354: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80223358: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8022335C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80223360: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x80223364: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80223368: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8022336C: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x80223370: jal         0x8013A28C
    // 0x80223374: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_4;
    // 0x80223374: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x80223378: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8022337C: jal         0x80010550
    // 0x80223380: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x80223380: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80223384: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80223388: addiu       $a1, $a1, 0x33A4
    ctx->r5 = ADD32(ctx->r5, 0X33A4);
    // 0x8022338C: jal         0x800058DC
    // 0x80223390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80223390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
L_80223394:
    // 0x80223394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80223398:
    // 0x80223398: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8022339C: jr          $ra
    // 0x802233A0: nop

    return;
    // 0x802233A0: nop

;}
RECOMP_FUNC void M10_FUN_802233a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802233A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x802233A8: jr          $ra
    // 0x802233AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x802233AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802233b0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802233b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802233B0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x802233B4: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802233b8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802233b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802233B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802233BC: lw          $v1, 0xDC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XDC);
    // 0x802233C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802233C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802233C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802233CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802233D0: bne         $a0, $v1, L_802233E4
    if (ctx->r4 != ctx->r3) {
        // 0x802233D4: lw          $a2, 0x5C($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X5C);
            goto L_802233E4;
    }
    // 0x802233D4: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x802233D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802233DC: b           L_802233EC
    // 0x802233E0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_802233EC;
    // 0x802233E0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_802233E4:
    // 0x802233E4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802233E8: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_802233EC:
    // 0x802233EC: beq         $s0, $v1, L_80223400
    if (ctx->r16 == ctx->r3) {
        // 0x802233F0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80223400;
    }
    // 0x802233F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802233F4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802233F8: b           L_80223408
    // 0x802233FC: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80223408;
    // 0x802233FC: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80223400:
    // 0x80223400: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80223404: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80223408:
    // 0x80223408: lbu         $t6, 0x1031($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1031);
    // 0x8022340C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80223410: beql        $t6, $at, L_802234E8
    if (ctx->r14 == ctx->r1) {
        // 0x80223414: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_802234E8;
    }
    goto skip_0;
    // 0x80223414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80223418: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x8022341C: lbu         $t6, 0x32($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X32);
    // 0x80223420: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80223424: andi        $t8, $t7, 0xFF9F
    ctx->r24 = ctx->r15 & 0XFF9F;
    // 0x80223428: ori         $t1, $t8, 0x20
    ctx->r9 = ctx->r24 | 0X20;
    // 0x8022342C: ori         $t4, $t1, 0x1
    ctx->r12 = ctx->r9 | 0X1;
    // 0x80223430: sb          $t1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r9;
    // 0x80223434: sb          $t4, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r12;
    // 0x80223438: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x8022343C: andi        $t7, $t6, 0xFF1F
    ctx->r15 = ctx->r14 & 0XFF1F;
    // 0x80223440: sb          $t5, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r13;
    // 0x80223444: sb          $t7, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r15;
    // 0x80223448: lbu         $t8, 0x30($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X30);
    // 0x8022344C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80223450: andi        $t1, $t8, 0xFFFE
    ctx->r9 = ctx->r24 & 0XFFFE;
    // 0x80223454: sb          $t1, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r9;
    // 0x80223458: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x8022345C: sb          $t2, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r10;
    // 0x80223460: lbu         $a0, 0x9C($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X9C);
    // 0x80223464: beq         $a0, $at, L_80223474
    if (ctx->r4 == ctx->r1) {
        // 0x80223468: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80223474;
    }
    // 0x80223468: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8022346C: bnel        $a0, $at, L_8022347C
    if (ctx->r4 != ctx->r1) {
        // 0x80223470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8022347C;
    }
    goto skip_1;
    // 0x80223470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80223474:
    // 0x80223474: sb          $t3, 0x9C($a2)
    MEM_B(0X9C, ctx->r6) = ctx->r11;
    // 0x80223478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8022347C:
    // 0x8022347C: jal         0x802237B0
    // 0x80223480: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_0;
    // 0x80223480: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80223484: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80223488: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8022348C: jal         0x800113D0
    // 0x80223490: addiu       $a1, $a2, 0x22
    ctx->r5 = ADD32(ctx->r6, 0X22);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_1;
    // 0x80223490: addiu       $a1, $a2, 0x22
    ctx->r5 = ADD32(ctx->r6, 0X22);
    after_1:
    // 0x80223494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80223498: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8022349C: jal         0x8013C6FC
    // 0x802234A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013C6FC)(rdram, ctx);
        goto after_2;
    // 0x802234A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x802234A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802234A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802234AC: jal         0x8013B808
    // 0x802234B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8013B808)(rdram, ctx);
        goto after_3;
    // 0x802234B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x802234B4: lhu         $t4, 0x36($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X36);
    // 0x802234B8: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x802234BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802234C0: bne         $t4, $at, L_802234DC
    if (ctx->r12 != ctx->r1) {
        // 0x802234C4: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_802234DC;
    }
    // 0x802234C4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802234C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802234CC: jal         0x80366F88
    // 0x802234D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80366F88)(rdram, ctx);
        goto after_4;
    // 0x802234D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x802234D4: b           L_802234E8
    // 0x802234D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_802234E8;
    // 0x802234D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802234DC:
    // 0x802234DC: jal         0x800058DC
    // 0x802234E0: addiu       $a1, $a1, 0x34F8
    ctx->r5 = ADD32(ctx->r5, 0X34F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x802234E0: addiu       $a1, $a1, 0x34F8
    ctx->r5 = ADD32(ctx->r5, 0X34F8);
    after_5:
    // 0x802234E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802234E8:
    // 0x802234E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802234EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x802234F0: jr          $ra
    // 0x802234F4: nop

    return;
    // 0x802234F4: nop

;}
RECOMP_FUNC void M10_FUN_802234f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802234F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802234FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80223500: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80223504: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80223508: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x8022350C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80223510: addiu       $t8, $t8, -0x3D2C
    ctx->r24 = ADD32(ctx->r24, -0X3D2C);
    // 0x80223514: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80223518: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8022351C: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80223520: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80223524: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80223528: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8022352C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80223530: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80223534: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80223538: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8022353C: lbu         $t1, -0x33DF($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X33DF);
    // 0x80223540: beql        $t1, $at, L_80223590
    if (ctx->r9 == ctx->r1) {
        // 0x80223544: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80223590;
    }
    goto skip_0;
    // 0x80223544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80223548: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8022354C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80223550: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80223554: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x80223558: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8022355C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80223560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80223564: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80223568: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8022356C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80223570: jal         0x80011140
    // 0x80223574: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80223574: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x80223578: beq         $v0, $zero, L_8022358C
    if (ctx->r2 == 0) {
        // 0x8022357C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8022358C;
    }
    // 0x8022357C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80223580: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80223584: jal         0x800058DC
    // 0x80223588: addiu       $a1, $a1, 0x359C
    ctx->r5 = ADD32(ctx->r5, 0X359C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80223588: addiu       $a1, $a1, 0x359C
    ctx->r5 = ADD32(ctx->r5, 0X359C);
    after_1:
L_8022358C:
    // 0x8022358C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80223590:
    // 0x80223590: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80223594: jr          $ra
    // 0x80223598: nop

    return;
    // 0x80223598: nop

;}
RECOMP_FUNC void M10_FUN_8022359c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022359C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802235A0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802235A4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x802235A8: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x802235AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802235B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x802235B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x802235B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802235BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802235C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x802235C4: bne         $a0, $t6, L_802235D8
    if (ctx->r4 != ctx->r14) {
        // 0x802235C8: lw          $s0, 0x5C($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X5C);
            goto L_802235D8;
    }
    // 0x802235C8: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x802235CC: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x802235D0: b           L_802235E0
    // 0x802235D4: addiu       $s2, $s2, -0x3FC4
    ctx->r18 = ADD32(ctx->r18, -0X3FC4);
        goto L_802235E0;
    // 0x802235D4: addiu       $s2, $s2, -0x3FC4
    ctx->r18 = ADD32(ctx->r18, -0X3FC4);
L_802235D8:
    // 0x802235D8: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x802235DC: addiu       $s2, $s2, -0x3C28
    ctx->r18 = ADD32(ctx->r18, -0X3C28);
L_802235E0:
    // 0x802235E0: lbu         $t7, 0x1031($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1031);
    // 0x802235E4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802235E8: beq         $t7, $at, L_80223790
    if (ctx->r15 == ctx->r1) {
        // 0x802235EC: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80223790;
    }
    // 0x802235EC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x802235F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802235F4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x802235F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802235FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80223600: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80223604: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80223608: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8022360C: nop

    // 0x80223610: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80223614: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80223618: nop

    // 0x8022361C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80223620: beql        $a0, $zero, L_80223670
    if (ctx->r4 == 0) {
        // 0x80223624: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_80223670;
    }
    goto skip_0;
    // 0x80223624: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80223628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8022362C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80223630: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80223634: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80223638: nop

    // 0x8022363C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80223640: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80223644: nop

    // 0x80223648: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8022364C: bne         $a0, $zero, L_80223664
    if (ctx->r4 != 0) {
        // 0x80223650: nop
    
            goto L_80223664;
    }
    // 0x80223650: nop

    // 0x80223654: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80223658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8022365C: b           L_8022367C
    // 0x80223660: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8022367C;
    // 0x80223660: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80223664:
    // 0x80223664: b           L_8022367C
    // 0x80223668: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8022367C;
    // 0x80223668: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8022366C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_80223670:
    // 0x80223670: nop

    // 0x80223674: bltz        $a0, L_80223664
    if (SIGNED(ctx->r4) < 0) {
        // 0x80223678: nop
    
            goto L_80223664;
    }
    // 0x80223678: nop

L_8022367C:
    // 0x8022367C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80223680: jal         0x80011590
    // 0x80223684: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x80223684: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80223688: lhu         $t9, 0x20($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X20);
    // 0x8022368C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80223690: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80223694: bne         $t9, $v0, L_802236AC
    if (ctx->r25 != ctx->r2) {
        // 0x80223698: lui         $at, 0x4190
        ctx->r1 = S32(0X4190 << 16);
            goto L_802236AC;
    }
    // 0x80223698: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8022369C: jal         0x803697AC
    // 0x802236A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x803697AC)(rdram, ctx);
        goto after_1;
    // 0x802236A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x802236A4: b           L_80223764
    // 0x802236A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_80223764;
    // 0x802236A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_802236AC:
    // 0x802236AC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x802236B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x802236B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802236B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x802236BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x802236C0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x802236C4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x802236C8: nop

    // 0x802236CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x802236D0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x802236D4: nop

    // 0x802236D8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x802236DC: beql        $a0, $zero, L_8022372C
    if (ctx->r4 == 0) {
        // 0x802236E0: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_8022372C;
    }
    goto skip_1;
    // 0x802236E0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x802236E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802236E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802236EC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x802236F0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x802236F4: nop

    // 0x802236F8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x802236FC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80223700: nop

    // 0x80223704: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80223708: bne         $a0, $zero, L_80223720
    if (ctx->r4 != 0) {
        // 0x8022370C: nop
    
            goto L_80223720;
    }
    // 0x8022370C: nop

    // 0x80223710: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80223714: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80223718: b           L_80223738
    // 0x8022371C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80223738;
    // 0x8022371C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80223720:
    // 0x80223720: b           L_80223738
    // 0x80223724: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80223738;
    // 0x80223724: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80223728: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_8022372C:
    // 0x8022372C: nop

    // 0x80223730: bltz        $a0, L_80223720
    if (SIGNED(ctx->r4) < 0) {
        // 0x80223734: nop
    
            goto L_80223720;
    }
    // 0x80223734: nop

L_80223738:
    // 0x80223738: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8022373C: jal         0x80011590
    // 0x80223740: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x80223740: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_2:
    // 0x80223744: lhu         $t1, 0x20($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X20);
    // 0x80223748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8022374C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80223750: bnel        $t1, $v0, L_80223764
    if (ctx->r9 != ctx->r2) {
        // 0x80223754: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80223764;
    }
    goto skip_2;
    // 0x80223754: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80223758: jal         0x803697AC
    // 0x8022375C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x803697AC)(rdram, ctx);
        goto after_3;
    // 0x8022375C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80223760: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80223764:
    // 0x80223764: jal         0x80010550
    // 0x80223768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_4;
    // 0x80223768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8022376C: beq         $v0, $zero, L_8022378C
    if (ctx->r2 == 0) {
        // 0x80223770: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8022378C;
    }
    // 0x80223770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80223774: lbu         $t2, 0x30($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X30);
    // 0x80223778: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8022377C: addiu       $a1, $a1, 0x2E84
    ctx->r5 = ADD32(ctx->r5, 0X2E84);
    // 0x80223780: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80223784: jal         0x800058DC
    // 0x80223788: sb          $t3, 0x30($s2)
    MEM_B(0X30, ctx->r18) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80223788: sb          $t3, 0x30($s2)
    MEM_B(0X30, ctx->r18) = ctx->r11;
    after_5:
L_8022378C:
    // 0x8022378C: sb          $zero, 0x392($s2)
    MEM_B(0X392, ctx->r18) = 0;
L_80223790:
    // 0x80223790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80223794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80223798: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8022379C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x802237A0: jr          $ra
    // 0x802237A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x802237A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802237a8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802237a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802237A8: nop

    // 0x802237AC: nop

;}
RECOMP_FUNC void M10_FUN_802237b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802237B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x802237B4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x802237B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x802237BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802237C0: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x802237C4: beq         $v1, $zero, L_802237D0
    if (ctx->r3 == 0) {
        // 0x802237C8: nop
    
            goto L_802237D0;
    }
    // 0x802237C8: nop

    // 0x802237CC: bne         $v1, $at, L_802237DC
    if (ctx->r3 != ctx->r1) {
            // 0x802237D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    LOOKUP_FUNC(0x802237DC)(rdram, ctx);
    return;
    }
L_802237D0:
    // 0x802237D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x802237D4: jr          $ra
    // 0x802237D8: sb          $a1, -0x41E0($at)
    MEM_B(-0X41E0, ctx->r1) = ctx->r5;
    return;
    // 0x802237D8: sb          $a1, -0x41E0($at)
    MEM_B(-0X41E0, ctx->r1) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802237dc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802237dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802237DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x802237E0: sb          $a1, -0x41DF($at)
    MEM_B(-0X41DF, ctx->r1) = ctx->r5;
    // 0x802237E4: jr          $ra
    // 0x802237E8: nop

    return;
    // 0x802237E8: nop

;}
RECOMP_FUNC void M10_FUN_802237ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802237EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x802237F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802237F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802237F8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x802237FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223800: lw          $v0, -0x4334($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4334);
    // 0x80223804: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80223808: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x8022380C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80223810: bne         $a0, $v0, L_80223824
    if (ctx->r4 != ctx->r2) {
        // 0x80223814: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_80223824;
    }
    // 0x80223814: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80223818: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8022381C: b           L_8022382C
    // 0x80223820: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_8022382C;
    // 0x80223820: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80223824:
    // 0x80223824: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80223828: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_8022382C:
    // 0x8022382C: beq         $s0, $v0, L_80223840
    if (ctx->r16 == ctx->r2) {
        // 0x80223830: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80223840;
    }
    // 0x80223830: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80223834: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80223838: b           L_80223844
    // 0x8022383C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80223844;
    // 0x8022383C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80223840:
    // 0x80223840: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80223844:
    // 0x80223844: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80223848: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8022384C: jal         0x8022696C
    // 0x80223850: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8022696C)(rdram, ctx);
        goto after_0;
    // 0x80223850: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80223854: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80223858: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x8022385C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80223860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80223864: jal         0x802237B0
    // 0x80223868: sw          $t8, 0x324($a2)
    MEM_W(0X324, ctx->r6) = ctx->r24;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_1;
    // 0x80223868: sw          $t8, 0x324($a2)
    MEM_W(0X324, ctx->r6) = ctx->r24;
    after_1:
    // 0x8022386C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80223870: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80223874: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80223878: lbu         $t0, 0x74($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X74);
    // 0x8022387C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80223880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80223884: bnel        $t0, $at, L_802238A8
    if (ctx->r8 != ctx->r1) {
        // 0x80223888: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_802238A8;
    }
    goto skip_0;
    // 0x80223888: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8022388C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80223890: jal         0x80242E58
    // 0x80223894: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80242E58)(rdram, ctx);
        goto after_2;
    // 0x80223894: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80223898: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8022389C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x802238A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x802238A4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_802238A8:
    // 0x802238A8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802238AC: addiu       $a1, $a1, -0x1C3C
    ctx->r5 = ADD32(ctx->r5, -0X1C3C);
    // 0x802238B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x802238B4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x802238B8: jal         0x80005670
    // 0x802238BC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x802238BC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x802238C0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x802238C4: beq         $v0, $zero, L_80223968
    if (ctx->r2 == 0) {
        // 0x802238C8: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80223968;
    }
    // 0x802238C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x802238CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x802238D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802238D4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x802238D8: beql        $t2, $zero, L_802238E8
    if (ctx->r10 == 0) {
        // 0x802238DC: lw          $t4, 0x30($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X30);
            goto L_802238E8;
    }
    goto skip_1;
    // 0x802238DC: lw          $t4, 0x30($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X30);
    skip_1:
    // 0x802238E0: sw          $v0, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r2;
    // 0x802238E4: lw          $t4, 0x30($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X30);
L_802238E8:
    // 0x802238E8: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x802238EC: sw          $t4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r12;
    // 0x802238F0: sw          $t6, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r14;
    // 0x802238F4: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x802238F8: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    // 0x802238FC: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x80223900: sw          $t0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r8;
    // 0x80223904: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80223908: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8022390C: sw          $t1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r9;
    // 0x80223910: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80223914: sw          $a2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r6;
    // 0x80223918: sw          $v1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r3;
    // 0x8022391C: sw          $t2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r10;
    // 0x80223920: lbu         $t3, 0x31($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X31);
    // 0x80223924: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223928: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8022392C: andi        $t4, $t3, 0xFFF8
    ctx->r12 = ctx->r11 & 0XFFF8;
    // 0x80223930: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80223934: sb          $t5, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r13;
    // 0x80223938: lbu         $t6, 0x31($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X31);
    // 0x8022393C: andi        $t7, $t6, 0xFFF8
    ctx->r15 = ctx->r14 & 0XFFF8;
    // 0x80223940: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x80223944: sb          $t8, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r24;
    // 0x80223948: lw          $t9, 0xDC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XDC);
    // 0x8022394C: bnel        $s0, $t9, L_80223960
    if (ctx->r16 != ctx->r25) {
        // 0x80223950: sb          $t0, 0x1030($v0)
        MEM_B(0X1030, ctx->r2) = ctx->r8;
            goto L_80223960;
    }
    goto skip_2;
    // 0x80223950: sb          $t0, 0x1030($v0)
    MEM_B(0X1030, ctx->r2) = ctx->r8;
    skip_2:
    // 0x80223954: b           L_80223960
    // 0x80223958: sb          $zero, 0x1030($v0)
    MEM_B(0X1030, ctx->r2) = 0;
        goto L_80223960;
    // 0x80223958: sb          $zero, 0x1030($v0)
    MEM_B(0X1030, ctx->r2) = 0;
    // 0x8022395C: sb          $t0, 0x1030($v0)
    MEM_B(0X1030, ctx->r2) = ctx->r8;
L_80223960:
    // 0x80223960: jal         0x800058DC
    // 0x80223964: addiu       $a1, $a1, 0x8B0
    ctx->r5 = ADD32(ctx->r5, 0X8B0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80223964: addiu       $a1, $a1, 0x8B0
    ctx->r5 = ADD32(ctx->r5, 0X8B0);
    after_4:
L_80223968:
    // 0x80223968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8022396C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80223970: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80223974: jr          $ra
    // 0x80223978: nop

    return;
    // 0x80223978: nop

;}
RECOMP_FUNC void M10_FUN_8022397c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022397C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80223980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80223984: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80223988: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8022398C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80223990: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223994: lw          $v0, -0x4334($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4334);
    // 0x80223998: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8022399C: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x802239A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x802239A4: bne         $a0, $v0, L_802239B8
    if (ctx->r4 != ctx->r2) {
        // 0x802239A8: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_802239B8;
    }
    // 0x802239A8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x802239AC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x802239B0: b           L_802239C0
    // 0x802239B4: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
        goto L_802239C0;
    // 0x802239B4: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
L_802239B8:
    // 0x802239B8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x802239BC: addiu       $s0, $s0, -0x3C28
    ctx->r16 = ADD32(ctx->r16, -0X3C28);
L_802239C0:
    // 0x802239C0: beq         $s1, $v0, L_802239D8
    if (ctx->r17 == ctx->r2) {
        // 0x802239C4: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_802239D8;
    }
    // 0x802239C4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x802239C8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x802239CC: addiu       $t8, $t8, -0x3FC4
    ctx->r24 = ADD32(ctx->r24, -0X3FC4);
    // 0x802239D0: b           L_802239E0
    // 0x802239D4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_802239E0;
    // 0x802239D4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_802239D8:
    // 0x802239D8: addiu       $t9, $t9, -0x3C28
    ctx->r25 = ADD32(ctx->r25, -0X3C28);
    // 0x802239DC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_802239E0:
    // 0x802239E0: jal         0x8022696C
    // 0x802239E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x8022696C)(rdram, ctx);
        goto after_0;
    // 0x802239E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
    // 0x802239E8: lw          $t0, 0x1C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1C);
    // 0x802239EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802239F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802239F4: jal         0x802237B0
    // 0x802239F8: sw          $t0, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_1;
    // 0x802239F8: sw          $t0, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->r8;
    after_1:
    // 0x802239FC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80223A00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80223A04: lbu         $t2, 0x74($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X74);
    // 0x80223A08: bnel        $t2, $at, L_80223A20
    if (ctx->r10 != ctx->r1) {
        // 0x80223A0C: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_80223A20;
    }
    goto skip_0;
    // 0x80223A0C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80223A10: jal         0x80242E58
    // 0x80223A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80242E58)(rdram, ctx);
        goto after_2;
    // 0x80223A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80223A18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80223A1C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80223A20:
    // 0x80223A20: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80223A24: addiu       $a1, $a1, -0x1C3C
    ctx->r5 = ADD32(ctx->r5, -0X1C3C);
    // 0x80223A28: jal         0x80005670
    // 0x80223A2C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x80223A2C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_3:
    // 0x80223A30: beq         $v0, $zero, L_80223AA4
    if (ctx->r2 == 0) {
        // 0x80223A34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80223AA4;
    }
    // 0x80223A34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80223A38: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80223A3C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80223A40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80223A44: beq         $t4, $zero, L_80223A50
    if (ctx->r12 == 0) {
        // 0x80223A48: nop
    
            goto L_80223A50;
    }
    // 0x80223A48: nop

    // 0x80223A4C: sw          $v0, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->r2;
L_80223A50:
    // 0x80223A50: sb          $t5, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r13;
    // 0x80223A54: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x80223A58: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    // 0x80223A5C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80223A60: ori         $t2, $t0, 0x80
    ctx->r10 = ctx->r8 | 0X80;
    // 0x80223A64: andi        $t7, $t6, 0xFFF8
    ctx->r15 = ctx->r14 & 0XFFF8;
    // 0x80223A68: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80223A6C: sb          $t2, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r10;
    // 0x80223A70: andi        $t3, $t2, 0xFE
    ctx->r11 = ctx->r10 & 0XFE;
    // 0x80223A74: sb          $t8, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r24;
    // 0x80223A78: sb          $t3, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r11;
    // 0x80223A7C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80223A80: addiu       $a1, $a1, 0x8B0
    ctx->r5 = ADD32(ctx->r5, 0X8B0);
    // 0x80223A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80223A88: sw          $t4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r12;
    // 0x80223A8C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80223A90: sw          $s0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r16;
    // 0x80223A94: sw          $t5, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r13;
    // 0x80223A98: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80223A9C: jal         0x800058DC
    // 0x80223AA0: sw          $t6, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80223AA0: sw          $t6, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r14;
    after_4:
L_80223AA4:
    // 0x80223AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80223AA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80223AAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80223AB0: jr          $ra
    // 0x80223AB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80223AB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80223ab8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80223ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223AB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80223ABC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80223AC0: beq         $a0, $zero, L_80223AD0
    if (ctx->r4 == 0) {
        // 0x80223AC4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80223AD0;
    }
    // 0x80223AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80223AC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80223ACC: bne         $a0, $at, L_80223AE0
    if (ctx->r4 != ctx->r1) {
            // 0x80223AD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x80223AE0)(rdram, ctx);
    return;
    }
L_80223AD0:
    // 0x80223AD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80223AD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80223AD8: jr          $ra
    // 0x80223ADC: nop

    return;
    // 0x80223ADC: nop

;}
RECOMP_FUNC void M10_FUN_80223ae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223AE0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80223AE4: beq         $v0, $at, L_80223AF0
    if (ctx->r2 == ctx->r1) {
        // 0x80223AE8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80223AF0;
    }
    // 0x80223AE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80223AEC: bne         $v0, $at, L_80223AFC
    if (ctx->r2 != ctx->r1) {
            // 0x80223AF0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    LOOKUP_FUNC(0x80223AFC)(rdram, ctx);
    return;
    }
L_80223AF0:
    // 0x80223AF0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80223AF4: jr          $ra
    // 0x80223AF8: lwc1        $f0, -0x1098($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1098);
    return;
    // 0x80223AF8: lwc1        $f0, -0x1098($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1098);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80223afc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80223afc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80223B00: beq         $v0, $at, L_80223B0C
    if (ctx->r2 == ctx->r1) {
        // 0x80223B04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80223B0C;
    }
    // 0x80223B04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80223B08: bne         $v0, $at, L_80223B1C
    if (ctx->r2 != ctx->r1) {
            // 0x80223B0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    LOOKUP_FUNC(0x80223B1C)(rdram, ctx);
    return;
    }
L_80223B0C:
    // 0x80223B0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80223B10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80223B14: jr          $ra
    // 0x80223B18: nop

    return;
    // 0x80223B18: nop

;}
RECOMP_FUNC void M10_FUN_80223b1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223B1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80223B20: nop

    // 0x80223B24: jr          $ra
    // 0x80223B28: nop

    return;
    // 0x80223B28: nop

;}
RECOMP_FUNC void M10_FUN_80223b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223B2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80223B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80223B34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80223B38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80223B3C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80223B40: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80223B44: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x80223B48: lh          $a0, 0x12($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X12);
    // 0x80223B4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80223B50: jal         0x8001EAD0
    // 0x80223B54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80223B54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80223B58: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80223B5C: lh          $a0, 0x12($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X12);
    // 0x80223B60: jal         0x8001EB64
    // 0x80223B64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80223B64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80223B68: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80223B6C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80223B70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80223B74: lhu         $t8, 0x36($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X36);
    // 0x80223B78: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80223B7C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80223B80: bnel        $t8, $at, L_80223C18
    if (ctx->r24 != ctx->r1) {
        // 0x80223B84: lwc1        $f6, 0x30($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80223C18;
    }
    goto skip_0;
    // 0x80223B84: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80223B88: lw          $t9, -0x4334($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4334);
    // 0x80223B8C: bne         $v0, $t9, L_80223B9C
    if (ctx->r2 != ctx->r25) {
        // 0x80223B90: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80223B9C;
    }
    // 0x80223B90: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223B94: b           L_80223BA4
    // 0x80223B98: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80223BA4;
    // 0x80223B98: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80223B9C:
    // 0x80223B9C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80223BA0: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80223BA4:
    // 0x80223BA4: lbu         $t0, 0x390($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X390);
    // 0x80223BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80223BAC: bnel        $t0, $at, L_80223C18
    if (ctx->r8 != ctx->r1) {
        // 0x80223BB0: lwc1        $f6, 0x30($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80223C18;
    }
    goto skip_1;
    // 0x80223BB0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80223BB4: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x80223BB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80223BBC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80223BC0: sll         $t2, $t1, 27
    ctx->r10 = S32(ctx->r9 << 27);
    // 0x80223BC4: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80223BC8: bne         $t3, $at, L_80223C14
    if (ctx->r11 != ctx->r1) {
        // 0x80223BCC: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_80223C14;
    }
    // 0x80223BCC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80223BD0: ldc1        $f2, -0x1090($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1090);
    // 0x80223BD4: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80223BD8: ldc1        $f8, -0x1088($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1088);
    // 0x80223BDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80223BE0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80223BE4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80223BE8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80223BEC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80223BF0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80223BF4: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80223BF8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80223BFC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80223C00: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80223C04: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80223C08: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80223C0C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80223C10: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_80223C14:
    // 0x80223C14: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
L_80223C18:
    // 0x80223C18: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80223C1C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80223C20: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80223C24: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80223C28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80223C2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80223C30: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80223C34: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80223C38: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80223C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80223C40: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x80223C44: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80223C48: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80223C4C: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80223C50: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x80223C54: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80223C58: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80223C5C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80223C60: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80223C64: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80223C68: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80223C6C: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80223C70: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80223C74: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80223C78: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80223C7C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80223C80: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80223C84: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80223C88: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80223C8C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80223C90: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80223C94: nop

    // 0x80223C98: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80223C9C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80223CA0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80223CA4: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80223CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80223CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80223CB0: jr          $ra
    // 0x80223CB4: nop

    return;
    // 0x80223CB4: nop

;}
RECOMP_FUNC void M10_FUN_80223cb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223CB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80223CBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80223CC0: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80223CC4: lw          $t7, 0xC8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC8);
    // 0x80223CC8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80223CCC: lw          $a3, 0xCC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XCC);
    // 0x80223CD0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80223CD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80223CD8: lw          $t7, 0xD0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XD0);
    // 0x80223CDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80223CE0: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80223CE4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80223CE8: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x80223CEC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80223CF0: lw          $t9, 0xDC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XDC);
    // 0x80223CF4: jal         0x80223B2C
    // 0x80223CF8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80223B2C)(rdram, ctx);
        goto after_0;
    // 0x80223CF8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80223CFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80223D00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80223D04: jr          $ra
    // 0x80223D08: nop

    return;
    // 0x80223D08: nop

;}
RECOMP_FUNC void M10_FUN_80223d0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223D0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80223D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80223D14: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80223D18: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80223D1C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80223D20: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80223D24: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80223D28: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80223D2C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80223D30: jal         0x8001EAD0
    // 0x80223D34: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80223D34: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80223D38: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80223D3C: jal         0x8001EAD0
    // 0x80223D40: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80223D40: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    after_1:
    // 0x80223D44: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80223D48: jal         0x8001EB64
    // 0x80223D4C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80223D4C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    after_2:
    // 0x80223D50: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80223D54: jal         0x8001EB64
    // 0x80223D58: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80223D58: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    after_3:
    // 0x80223D5C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80223D60: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80223D64: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80223D68: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80223D6C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80223D70: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80223D74: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80223D78: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80223D7C: nop

    // 0x80223D80: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80223D84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80223D88: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80223D8C: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80223D90: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80223D94: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80223D98: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x80223D9C: nop

    // 0x80223DA0: bc1f        L_80223DB4
    if (!c1cs) {
        // 0x80223DA4: nop
    
            goto L_80223DB4;
    }
    // 0x80223DA4: nop

    // 0x80223DA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80223DAC: b           L_80223DC4
    // 0x80223DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80223DC4;
    // 0x80223DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80223DB4:
    // 0x80223DB4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80223DB8: jal         0x8002FC20
    // 0x80223DBC: div.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x80223DBC: div.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    after_4:
    // 0x80223DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80223DC4:
    // 0x80223DC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80223DC8: jr          $ra
    // 0x80223DCC: nop

    return;
    // 0x80223DCC: nop

;}
RECOMP_FUNC void M10_FUN_80223dd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223DD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80223DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80223DD8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80223DDC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80223DE0: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80223DE4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80223DE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80223DEC: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80223DF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80223DF4: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80223DF8: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80223DFC: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80223E00: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80223E04: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80223E08: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80223E0C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80223E10: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80223E14: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80223E18: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80223E1C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80223E20: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80223E24: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80223E28: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80223E2C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80223E30: jal         0x8002FC20
    // 0x80223E34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80223E34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80223E38: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80223E3C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80223E40: jal         0x8001EF38
    // 0x80223E44: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x80223E44: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80223E48: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80223E4C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80223E50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80223E54: lh          $t7, 0x12($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X12);
    // 0x80223E58: subu        $a1, $v0, $t7
    ctx->r5 = SUB32(ctx->r2, ctx->r15);
    // 0x80223E5C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80223E60: jal         0x80223D0C
    // 0x80223E64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x80223D0C)(rdram, ctx);
        goto after_2;
    // 0x80223E64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_2:
    // 0x80223E68: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80223E6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80223E70: lh          $t8, 0x1A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1A);
    // 0x80223E74: lh          $t0, 0x12($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X12);
    // 0x80223E78: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80223E7C: subu        $a1, $t8, $t0
    ctx->r5 = SUB32(ctx->r24, ctx->r8);
    // 0x80223E80: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x80223E84: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80223E88: jal         0x80223D0C
    // 0x80223E8C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x80223D0C)(rdram, ctx);
        goto after_3;
    // 0x80223E8C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x80223E90: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80223E94: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80223E98: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80223E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80223EA0: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80223EA4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80223EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80223EAC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80223EB0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80223EB4: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80223EB8: nop

    // 0x80223EBC: bc1f        L_80223ECC
    if (!c1cs) {
        // 0x80223EC0: nop
    
            goto L_80223ECC;
    }
    // 0x80223EC0: nop

    // 0x80223EC4: b           L_80223ECC
    // 0x80223EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80223ECC;
    // 0x80223EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80223ECC:
    // 0x80223ECC: jr          $ra
    // 0x80223ED0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80223ED0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80223ed4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80223ed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223ED4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80223ED8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80223EDC: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80223ee0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80223ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80223EE0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80223EE4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80223EE8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80223EEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80223EF0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80223EF4: beq         $a0, $v0, L_80223F04
    if (ctx->r4 == ctx->r2) {
        // 0x80223EF8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80223F04;
    }
    // 0x80223EF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80223EFC: b           L_80223F0C
    // 0x80223F00: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
        goto L_80223F0C;
    // 0x80223F00: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_80223F04:
    // 0x80223F04: lw          $t6, 0xEC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XEC);
    // 0x80223F08: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_80223F0C:
    // 0x80223F0C: bne         $a3, $v0, L_80223F20
    if (ctx->r7 != ctx->r2) {
        // 0x80223F10: lw          $a1, 0x5C($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X5C);
            goto L_80223F20;
    }
    // 0x80223F10: lw          $a1, 0x5C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X5C);
    // 0x80223F14: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80223F18: b           L_80223F28
    // 0x80223F1C: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_80223F28;
    // 0x80223F1C: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80223F20:
    // 0x80223F20: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80223F24: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_80223F28:
    // 0x80223F28: beq         $a3, $v0, L_80223F40
    if (ctx->r7 == ctx->r2) {
        // 0x80223F2C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_80223F40;
    }
    // 0x80223F2C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80223F30: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80223F34: addiu       $t7, $t7, -0x3FC4
    ctx->r15 = ADD32(ctx->r15, -0X3FC4);
    // 0x80223F38: b           L_80223F48
    // 0x80223F3C: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
        goto L_80223F48;
    // 0x80223F3C: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80223F40:
    // 0x80223F40: addiu       $t8, $t8, -0x3C28
    ctx->r24 = ADD32(ctx->r24, -0X3C28);
    // 0x80223F44: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
L_80223F48:
    // 0x80223F48: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80223F4C: bne         $a3, $v0, L_80223F60
    if (ctx->r7 != ctx->r2) {
        // 0x80223F50: lw          $s1, 0x2C($t9)
        ctx->r17 = MEM_W(ctx->r25, 0X2C);
            goto L_80223F60;
    }
    // 0x80223F50: lw          $s1, 0x2C($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X2C);
    // 0x80223F54: lw          $t0, 0xF0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XF0);
    // 0x80223F58: b           L_80223F68
    // 0x80223F5C: lw          $s0, 0x2C($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X2C);
        goto L_80223F68;
    // 0x80223F5C: lw          $s0, 0x2C($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X2C);
L_80223F60:
    // 0x80223F60: lw          $t1, 0xE0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE0);
    // 0x80223F64: lw          $s0, 0x2C($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X2C);
L_80223F68:
    // 0x80223F68: lw          $t4, 0xA4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XA4);
    // 0x80223F6C: addiu       $t2, $sp, 0x6C
    ctx->r10 = ADD32(ctx->r29, 0X6C);
    // 0x80223F70: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80223F74: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80223F78: lw          $t3, 0xA8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XA8);
    // 0x80223F7C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x80223F80: lw          $t4, 0xAC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XAC);
    // 0x80223F84: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x80223F88: lbu         $a0, 0x392($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X392);
    // 0x80223F8C: beql        $a0, $at, L_802242C0
    if (ctx->r4 == ctx->r1) {
        // 0x80223F90: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_802242C0;
    }
    goto skip_0;
    // 0x80223F90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80223F94: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80223F98: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x80223F9C: jal         0x80223AB8
    // 0x80223FA0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80223AB8)(rdram, ctx);
        goto after_0;
    // 0x80223FA0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_0:
    // 0x80223FA4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80223FA8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80223FAC: jal         0x80223AB8
    // 0x80223FB0: lbu         $a0, 0x392($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X392);
    LOOKUP_FUNC(0x80223AB8)(rdram, ctx);
        goto after_1;
    // 0x80223FB0: lbu         $a0, 0x392($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X392);
    after_1:
    // 0x80223FB4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80223FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80223FBC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80223FC0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80223FC4: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80223FC8: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80223FCC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80223FD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80223FD4: bc1t        L_802242BC
    if (c1cs) {
        // 0x80223FD8: addiu       $a1, $sp, 0x5C
        ctx->r5 = ADD32(ctx->r29, 0X5C);
            goto L_802242BC;
    }
    // 0x80223FD8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80223FDC: beq         $v0, $at, L_80223FF8
    if (ctx->r2 == ctx->r1) {
        // 0x80223FE0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80223FF8;
    }
    // 0x80223FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80223FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80223FE8: beq         $v0, $at, L_80223FF8
    if (ctx->r2 == ctx->r1) {
        // 0x80223FEC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80223FF8;
    }
    // 0x80223FEC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80223FF0: bnel        $v0, $at, L_80224004
    if (ctx->r2 != ctx->r1) {
        // 0x80223FF4: sb          $zero, 0x3A($sp)
        MEM_B(0X3A, ctx->r29) = 0;
            goto L_80224004;
    }
    goto skip_1;
    // 0x80223FF4: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
    skip_1:
L_80223FF8:
    // 0x80223FF8: b           L_80224004
    // 0x80223FFC: sb          $t6, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r14;
        goto L_80224004;
    // 0x80223FFC: sb          $t6, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r14;
    // 0x80224000: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
L_80224004:
    // 0x80224004: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80224008: jal         0x80223CB8
    // 0x8022400C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80223CB8)(rdram, ctx);
        goto after_2;
    // 0x8022400C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_2:
    // 0x80224010: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80224014: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80224018: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8022401C: lbu         $v0, 0x392($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X392);
    // 0x80224020: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80224024: beq         $v0, $at, L_80224030
    if (ctx->r2 == ctx->r1) {
        // 0x80224028: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80224030;
    }
    // 0x80224028: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8022402C: bne         $v0, $at, L_8022404C
    if (ctx->r2 != ctx->r1) {
        // 0x80224030: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8022404C;
    }
L_80224030:
    // 0x80224030: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80224034: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80224038: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8022403C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80224040: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80224044: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80224048: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
L_8022404C:
    // 0x8022404C: jal         0x80223CB8
    // 0x80224050: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    LOOKUP_FUNC(0x80223CB8)(rdram, ctx);
        goto after_3;
    // 0x80224050: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_3:
    // 0x80224054: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80224058: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8022405C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80224060: lbu         $v0, 0x392($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X392);
    // 0x80224064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80224068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8022406C: beq         $v0, $at, L_8022407C
    if (ctx->r2 == ctx->r1) {
        // 0x80224070: addiu       $a2, $sp, 0x5C
        ctx->r6 = ADD32(ctx->r29, 0X5C);
            goto L_8022407C;
    }
    // 0x80224070: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80224074: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80224078: bne         $v0, $at, L_80224094
    if (ctx->r2 != ctx->r1) {
        // 0x8022407C: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_80224094;
    }
L_8022407C:
    // 0x8022407C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80224080: ldc1        $f6, -0x1080($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1080);
    // 0x80224084: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80224088: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8022408C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80224090: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
L_80224094:
    // 0x80224094: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80224098: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8022409C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x802240A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x802240A4: jal         0x80223DD0
    // 0x802240A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80223DD0)(rdram, ctx);
        goto after_4;
    // 0x802240A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x802240AC: beq         $v0, $zero, L_802242BC
    if (ctx->r2 == 0) {
        // 0x802240B0: lbu         $t8, 0x3A($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X3A);
            goto L_802242BC;
    }
    // 0x802240B0: lbu         $t8, 0x3A($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3A);
    // 0x802240B4: beql        $t8, $zero, L_80224148
    if (ctx->r24 == 0) {
        // 0x802240B8: lwc1        $f6, 0x6C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_80224148;
    }
    goto skip_2;
    // 0x802240B8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    skip_2:
    // 0x802240BC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x802240C0: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x802240C4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x802240C8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x802240CC: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x802240D0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x802240D4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x802240D8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x802240DC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x802240E0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x802240E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x802240E8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x802240EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x802240F0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x802240F4: jal         0x8010843C
    // 0x802240F8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_5;
    // 0x802240F8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x802240FC: beq         $v0, $zero, L_80224144
    if (ctx->r2 == 0) {
        // 0x80224100: lwc1        $f10, 0x6C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_80224144;
    }
    // 0x80224100: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80224104: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80224108: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8022410C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80224110: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80224114: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80224118: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8022411C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80224120: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80224124: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80224128: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8022412C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80224130: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80224134: jal         0x802237B0
    // 0x80224138: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_6;
    // 0x80224138: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_6:
    // 0x8022413C: b           L_80224164
    // 0x80224140: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
        goto L_80224164;
    // 0x80224140: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
L_80224144:
    // 0x80224144: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
L_80224148:
    // 0x80224148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8022414C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80224150: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80224154: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x80224158: jal         0x802237B0
    // 0x8022415C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_7;
    // 0x8022415C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_7:
    // 0x80224160: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
L_80224164:
    // 0x80224164: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80224168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8022416C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224170: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80224174: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x80224178: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8022417C: jal         0x80223DD0
    // 0x80224180: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80223DD0)(rdram, ctx);
        goto after_8;
    // 0x80224180: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80224184: beq         $v0, $zero, L_802242BC
    if (ctx->r2 == 0) {
        // 0x80224188: lbu         $t9, 0x3A($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X3A);
            goto L_802242BC;
    }
    // 0x80224188: lbu         $t9, 0x3A($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3A);
    // 0x8022418C: beql        $t9, $zero, L_80224230
    if (ctx->r25 == 0) {
        // 0x80224190: lwc1        $f2, 0x4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80224230;
    }
    goto skip_3;
    // 0x80224190: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x80224194: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80224198: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8022419C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802241A0: ldc1        $f4, -0x1078($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1078);
    // 0x802241A4: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x802241A8: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x802241AC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x802241B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802241B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x802241B8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x802241BC: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x802241C0: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x802241C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x802241C8: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x802241CC: ldc1        $f10, -0x1070($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1070);
    // 0x802241D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x802241D4: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x802241D8: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x802241DC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x802241E0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x802241E4: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x802241E8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x802241EC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x802241F0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x802241F4: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x802241F8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x802241FC: jal         0x80108480
    // 0x80224200: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_9;
    // 0x80224200: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80224204: bne         $v0, $zero, L_802242BC
    if (ctx->r2 != 0) {
        // 0x80224208: lwc1        $f18, 0x48($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
            goto L_802242BC;
    }
    // 0x80224208: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8022420C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80224210: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80224214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80224218: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8022421C: jal         0x802237B0
    // 0x80224220: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_10;
    // 0x80224220: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_10:
    // 0x80224224: b           L_802242C0
    // 0x80224228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802242C0;
    // 0x80224228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8022422C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_80224230:
    // 0x80224230: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80224234: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80224238: ldc1        $f10, -0x1068($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1068);
    // 0x8022423C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80224240: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80224244: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80224248: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8022424C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80224250: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80224254: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80224258: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8022425C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80224260: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80224264: ldc1        $f4, -0x1060($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1060);
    // 0x80224268: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8022426C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80224270: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80224274: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80224278: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8022427C: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80224280: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80224284: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80224288: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8022428C: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80224290: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80224294: jal         0x80108480
    // 0x80224298: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_11;
    // 0x80224298: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x8022429C: bne         $v0, $zero, L_802242BC
    if (ctx->r2 != 0) {
        // 0x802242A0: lwc1        $f18, 0x48($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
            goto L_802242BC;
    }
    // 0x802242A0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x802242A4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x802242A8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x802242AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802242B0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x802242B4: jal         0x802237B0
    // 0x802242B8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_12;
    // 0x802242B8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_12:
L_802242BC:
    // 0x802242BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802242C0:
    // 0x802242C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x802242C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x802242C8: jr          $ra
    // 0x802242CC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x802242CC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802242d0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802242d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802242D0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x802242D4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x802242D8: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // 0x802242DC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802242E0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
    // 0x802242E4: bne         $a0, $v0, L_802242F8
    if (ctx->r4 != ctx->r2) {
        // 0x802242E8: nop
    
            goto L_802242F8;
    }
    // 0x802242E8: nop

    // 0x802242EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802242F0: b           L_802242F8
    // 0x802242F4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_802242F8;
    // 0x802242F4: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_802242F8:
    // 0x802242F8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x802242FC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80224300: bne         $a0, $v0, L_80224310
    if (ctx->r4 != ctx->r2) {
        // 0x80224304: lh          $a1, 0x12($t7)
        ctx->r5 = MEM_H(ctx->r15, 0X12);
            goto L_80224310;
    }
    // 0x80224304: lh          $a1, 0x12($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X12);
    // 0x80224308: b           L_80224320
    // 0x8022430C: lh          $v0, 0xB98($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB98);
        goto L_80224320;
    // 0x8022430C: lh          $v0, 0xB98($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB98);
L_80224310:
    // 0x80224310: lh          $v0, 0xB98($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB98);
    // 0x80224314: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x80224318: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8022431C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80224320:
    // 0x80224320: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80224324: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80224328: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8022432C: andi        $a2, $a0, 0x1000
    ctx->r6 = ctx->r4 & 0X1000;
    // 0x80224330: beq         $a2, $zero, L_80224344
    if (ctx->r6 == 0) {
        // 0x80224334: andi        $a1, $a0, 0x1FFF
        ctx->r5 = ctx->r4 & 0X1FFF;
            goto L_80224344;
    }
    // 0x80224334: andi        $a1, $a0, 0x1FFF
    ctx->r5 = ctx->r4 & 0X1FFF;
    // 0x80224338: andi        $a1, $a0, 0x1FFF
    ctx->r5 = ctx->r4 & 0X1FFF;
    // 0x8022433C: b           L_80224348
    // 0x80224340: addiu       $v0, $a1, -0x2000
    ctx->r2 = ADD32(ctx->r5, -0X2000);
        goto L_80224348;
    // 0x80224340: addiu       $v0, $a1, -0x2000
    ctx->r2 = ADD32(ctx->r5, -0X2000);
L_80224344:
    // 0x80224344: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80224348:
    // 0x80224348: bgez        $v0, L_8022436C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8022434C: nop
    
            goto L_8022436C;
    }
    // 0x8022434C: nop

    // 0x80224350: beq         $a2, $zero, L_80224364
    if (ctx->r6 == 0) {
        // 0x80224354: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80224364;
    }
    // 0x80224354: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80224358: addiu       $v0, $a1, -0x2000
    ctx->r2 = ADD32(ctx->r5, -0X2000);
    // 0x8022435C: b           L_80224380
    // 0x80224360: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_80224380;
    // 0x80224360: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80224364:
    // 0x80224364: b           L_80224380
    // 0x80224368: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_80224380;
    // 0x80224368: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8022436C:
    // 0x8022436C: beq         $a2, $zero, L_8022437C
    if (ctx->r6 == 0) {
        // 0x80224370: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8022437C;
    }
    // 0x80224370: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80224374: b           L_8022437C
    // 0x80224378: addiu       $v0, $a1, -0x2000
    ctx->r2 = ADD32(ctx->r5, -0X2000);
        goto L_8022437C;
    // 0x80224378: addiu       $v0, $a1, -0x2000
    ctx->r2 = ADD32(ctx->r5, -0X2000);
L_8022437C:
    // 0x8022437C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80224380:
    // 0x80224380: lh          $t8, 0x310($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X310);
    // 0x80224384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80224388: bgez        $t8, L_80224398
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8022438C: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80224398;
    }
    // 0x8022438C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80224390: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80224394: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80224398:
    // 0x80224398: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8022439C: beq         $at, $zero, L_802243AC
    if (ctx->r1 == 0) {
            // 0x802243A0: nop

    LOOKUP_FUNC(0x802243AC)(rdram, ctx);
    return;
    }
    // 0x802243A0: nop

    // 0x802243A4: jr          $ra
    // 0x802243A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802243A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802243ac(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802243ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802243AC: jr          $ra
    // 0x802243B0: nop

    return;
    // 0x802243B0: nop

;}
RECOMP_FUNC void M10_FUN_802243b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802243B4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802243B8: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // 0x802243BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x802243C0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x802243C4: bne         $a0, $t6, L_802243D8
    if (ctx->r4 != ctx->r14) {
        // 0x802243C8: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_802243D8;
    }
    // 0x802243C8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802243CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802243D0: b           L_802243E0
    // 0x802243D4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_802243E0;
    // 0x802243D4: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_802243D8:
    // 0x802243D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802243DC: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_802243E0:
    // 0x802243E0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x802243E4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x802243E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x802243EC: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x802243F0: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x802243F4: subu        $a2, $t8, $a1
    ctx->r6 = SUB32(ctx->r24, ctx->r5);
    // 0x802243F8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802243FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80224400: andi        $t9, $a2, 0x1000
    ctx->r25 = ctx->r6 & 0X1000;
    // 0x80224404: beq         $t9, $zero, L_80224420
    if (ctx->r25 == 0) {
        // 0x80224408: andi        $v1, $a2, 0x1FFF
        ctx->r3 = ctx->r6 & 0X1FFF;
            goto L_80224420;
    }
    // 0x80224408: andi        $v1, $a2, 0x1FFF
    ctx->r3 = ctx->r6 & 0X1FFF;
    // 0x8022440C: andi        $v1, $a2, 0x1FFF
    ctx->r3 = ctx->r6 & 0X1FFF;
    // 0x80224410: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x80224414: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80224418: b           L_80224428
    // 0x8022441C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80224428;
    // 0x8022441C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80224420:
    // 0x80224420: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80224424: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80224428:
    // 0x80224428: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8022442C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80224430: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80224434: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x80224438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8022443C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80224440: slti        $at, $v1, -0xE00
    ctx->r1 = SIGNED(ctx->r3) < -0XE00 ? 1 : 0;
    // 0x80224444: bc1fl       L_80224458
    if (!c1cs) {
        // 0x80224448: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224458;
    }
    goto skip_0;
    // 0x80224448: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x8022444C: b           L_80224458
    // 0x80224450: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80224458;
    // 0x80224450: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80224454: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_80224458:
    // 0x80224458: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8022445C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80224460: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80224464: nop

    // 0x80224468: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x8022446C: beql        $t4, $zero, L_802244B8
    if (ctx->r12 == 0) {
        // 0x80224470: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_802244B8;
    }
    goto skip_1;
    // 0x80224470: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_1:
    // 0x80224474: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80224478: nop

    // 0x8022447C: bc1fl       L_80224490
    if (!c1cs) {
        // 0x80224480: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224490;
    }
    goto skip_2;
    // 0x80224480: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_2:
    // 0x80224484: b           L_80224490
    // 0x80224488: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80224490;
    // 0x80224488: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8022448C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_80224490:
    // 0x80224490: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80224494: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80224498: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8022449C: nop

    // 0x802244A0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802244A4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802244A8: andi        $a2, $a2, 0x1FFF
    ctx->r6 = ctx->r6 & 0X1FFF;
    // 0x802244AC: b           L_802244EC
    // 0x802244B0: addiu       $a2, $a2, -0x2000
    ctx->r6 = ADD32(ctx->r6, -0X2000);
        goto L_802244EC;
    // 0x802244B0: addiu       $a2, $a2, -0x2000
    ctx->r6 = ADD32(ctx->r6, -0X2000);
    // 0x802244B4: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_802244B8:
    // 0x802244B8: nop

    // 0x802244BC: bc1fl       L_802244D0
    if (!c1cs) {
        // 0x802244C0: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802244D0;
    }
    goto skip_3;
    // 0x802244C0: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_3:
    // 0x802244C4: b           L_802244D0
    // 0x802244C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_802244D0;
    // 0x802244C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x802244CC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_802244D0:
    // 0x802244D0: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x802244D4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x802244D8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x802244DC: nop

    // 0x802244E0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802244E4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802244E8: andi        $a2, $a2, 0x1FFF
    ctx->r6 = ctx->r6 & 0X1FFF;
L_802244EC:
    // 0x802244EC: bgezl       $a2, L_802245C4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x802244F0: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_802245C4;
    }
    goto skip_4;
    // 0x802244F0: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_4:
    // 0x802244F4: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x802244F8: nop

    // 0x802244FC: bc1fl       L_80224510
    if (!c1cs) {
        // 0x80224500: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224510;
    }
    goto skip_5;
    // 0x80224500: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_5:
    // 0x80224504: b           L_80224510
    // 0x80224508: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80224510;
    // 0x80224508: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8022450C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_80224510:
    // 0x80224510: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80224514: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80224518: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8022451C: nop

    // 0x80224520: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80224524: beql        $t1, $zero, L_8022457C
    if (ctx->r9 == 0) {
        // 0x80224528: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_8022457C;
    }
    goto skip_6;
    // 0x80224528: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_6:
    // 0x8022452C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80224530: nop

    // 0x80224534: bc1fl       L_80224548
    if (!c1cs) {
        // 0x80224538: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224548;
    }
    goto skip_7;
    // 0x80224538: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_7:
    // 0x8022453C: b           L_80224548
    // 0x80224540: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224548;
    // 0x80224540: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80224544: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224548:
    // 0x80224548: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8022454C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80224550: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80224554: nop

    // 0x80224558: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8022455C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80224560: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80224564: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x80224568: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x8022456C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80224570: b           L_80224678
    // 0x80224574: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_80224678;
    // 0x80224574: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80224578: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_8022457C:
    // 0x8022457C: nop

    // 0x80224580: bc1fl       L_80224594
    if (!c1cs) {
        // 0x80224584: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224594;
    }
    goto skip_8;
    // 0x80224584: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_8:
    // 0x80224588: b           L_80224594
    // 0x8022458C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224594;
    // 0x8022458C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80224590: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224594:
    // 0x80224594: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80224598: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8022459C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x802245A0: nop

    // 0x802245A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802245A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802245AC: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x802245B0: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x802245B4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802245B8: b           L_80224678
    // 0x802245BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_80224678;
    // 0x802245BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802245C0: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_802245C4:
    // 0x802245C4: nop

    // 0x802245C8: bc1fl       L_802245DC
    if (!c1cs) {
        // 0x802245CC: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802245DC;
    }
    goto skip_9;
    // 0x802245CC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_9:
    // 0x802245D0: b           L_802245DC
    // 0x802245D4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_802245DC;
    // 0x802245D4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x802245D8: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_802245DC:
    // 0x802245DC: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x802245E0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x802245E4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x802245E8: nop

    // 0x802245EC: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x802245F0: beql        $t8, $zero, L_8022463C
    if (ctx->r24 == 0) {
        // 0x802245F4: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_8022463C;
    }
    goto skip_10;
    // 0x802245F4: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_10:
    // 0x802245F8: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x802245FC: nop

    // 0x80224600: bc1fl       L_80224614
    if (!c1cs) {
        // 0x80224604: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224614;
    }
    goto skip_11;
    // 0x80224604: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_11:
    // 0x80224608: b           L_80224614
    // 0x8022460C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224614;
    // 0x8022460C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80224610: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224614:
    // 0x80224614: mul.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80224618: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8022461C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80224620: nop

    // 0x80224624: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80224628: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8022462C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80224630: b           L_80224670
    // 0x80224634: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_80224670;
    // 0x80224634: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x80224638: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_8022463C:
    // 0x8022463C: nop

    // 0x80224640: bc1fl       L_80224654
    if (!c1cs) {
        // 0x80224644: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224654;
    }
    goto skip_12;
    // 0x80224644: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_12:
    // 0x80224648: b           L_80224654
    // 0x8022464C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224654;
    // 0x8022464C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80224650: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224654:
    // 0x80224654: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80224658: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8022465C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80224660: nop

    // 0x80224664: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80224668: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8022466C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80224670:
    // 0x80224670: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80224674: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_80224678:
    // 0x80224678: beql        $at, $zero, L_8022468C
    if (ctx->r1 == 0) {
        // 0x8022467C: slti        $at, $v1, -0x600
        ctx->r1 = SIGNED(ctx->r3) < -0X600 ? 1 : 0;
            goto L_8022468C;
    }
    goto skip_13;
    // 0x8022467C: slti        $at, $v1, -0x600
    ctx->r1 = SIGNED(ctx->r3) < -0X600 ? 1 : 0;
    skip_13:
    // 0x80224680: b           L_80224708
    // 0x80224684: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80224708;
    // 0x80224684: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80224688: slti        $at, $v1, -0x600
    ctx->r1 = SIGNED(ctx->r3) < -0X600 ? 1 : 0;
L_8022468C:
    // 0x8022468C: beq         $at, $zero, L_8022469C
    if (ctx->r1 == 0) {
        // 0x80224690: negu        $t1, $a2
        ctx->r9 = SUB32(0, ctx->r6);
            goto L_8022469C;
    }
    // 0x80224690: negu        $t1, $a2
    ctx->r9 = SUB32(0, ctx->r6);
    // 0x80224694: b           L_80224708
    // 0x80224698: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80224708;
    // 0x80224698: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8022469C:
    // 0x8022469C: bgez        $t1, L_802246AC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x802246A0: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_802246AC;
    }
    // 0x802246A0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x802246A4: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x802246A8: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_802246AC:
    // 0x802246AC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x802246B0: beql        $at, $zero, L_802246C4
    if (ctx->r1 == 0) {
        // 0x802246B4: slti        $at, $v1, 0xE01
        ctx->r1 = SIGNED(ctx->r3) < 0XE01 ? 1 : 0;
            goto L_802246C4;
    }
    goto skip_14;
    // 0x802246B4: slti        $at, $v1, 0xE01
    ctx->r1 = SIGNED(ctx->r3) < 0XE01 ? 1 : 0;
    skip_14:
    // 0x802246B8: b           L_80224708
    // 0x802246BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80224708;
    // 0x802246BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802246C0: slti        $at, $v1, 0xE01
    ctx->r1 = SIGNED(ctx->r3) < 0XE01 ? 1 : 0;
L_802246C4:
    // 0x802246C4: bnel        $at, $zero, L_802246D8
    if (ctx->r1 != 0) {
        // 0x802246C8: slti        $at, $v1, 0x601
        ctx->r1 = SIGNED(ctx->r3) < 0X601 ? 1 : 0;
            goto L_802246D8;
    }
    goto skip_15;
    // 0x802246C8: slti        $at, $v1, 0x601
    ctx->r1 = SIGNED(ctx->r3) < 0X601 ? 1 : 0;
    skip_15:
    // 0x802246CC: b           L_80224708
    // 0x802246D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80224708;
    // 0x802246D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x802246D4: slti        $at, $v1, 0x601
    ctx->r1 = SIGNED(ctx->r3) < 0X601 ? 1 : 0;
L_802246D8:
    // 0x802246D8: bne         $at, $zero, L_802246E8
    if (ctx->r1 != 0) {
        // 0x802246DC: nop
    
            goto L_802246E8;
    }
    // 0x802246DC: nop

    // 0x802246E0: b           L_80224708
    // 0x802246E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80224708;
    // 0x802246E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_802246E8:
    // 0x802246E8: bgez        $a2, L_802246F8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x802246EC: sra         $t3, $a2, 1
        ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
            goto L_802246F8;
    }
    // 0x802246EC: sra         $t3, $a2, 1
    ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
    // 0x802246F0: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x802246F4: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_802246F8:
    // 0x802246F8: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x802246FC: beql        $at, $zero, L_8022470C
    if (ctx->r1 == 0) {
        // 0x80224700: lhu         $v0, 0x36($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X36);
            goto L_8022470C;
    }
    goto skip_16;
    // 0x80224700: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
    skip_16:
    // 0x80224704: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80224708:
    // 0x80224708: lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X36);
L_8022470C:
    // 0x8022470C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x80224710: beq         $v0, $at, L_80224724
    if (ctx->r2 == ctx->r1) {
        // 0x80224714: addiu       $at, $zero, 0xF6
        ctx->r1 = ADD32(0, 0XF6);
            goto L_80224724;
    }
    // 0x80224714: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80224718: beq         $v0, $at, L_80224724
    if (ctx->r2 == ctx->r1) {
        // 0x8022471C: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80224724;
    }
    // 0x8022471C: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80224720: bne         $v0, $at, L_80224744
    if (ctx->r2 != ctx->r1) {
        // 0x80224724: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_80224744;
    }
L_80224724:
    // 0x80224724: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80224728: bne         $at, $zero, L_80224738
    if (ctx->r1 != 0) {
        // 0x8022472C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80224738;
    }
    // 0x8022472C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80224730: jr          $ra
    // 0x80224734: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80224734: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80224738:
    // 0x80224738: blez        $v0, L_80224744
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8022473C: nop
    
            goto L_80224744;
    }
    // 0x8022473C: nop

    // 0x80224740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80224744:
    // 0x80224744: jr          $ra
    // 0x80224748: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80224748: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8022474c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8022474c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022474C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80224750: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // 0x80224754: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x80224758: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8022475C: bne         $a0, $t6, L_80224770
    if (ctx->r4 != ctx->r14) {
        // 0x80224760: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_80224770;
    }
    // 0x80224760: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80224764: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80224768: b           L_80224778
    // 0x8022476C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80224778;
    // 0x8022476C: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_80224770:
    // 0x80224770: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80224774: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80224778:
    // 0x80224778: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8022477C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80224780: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80224784: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80224788: lh          $a1, 0x12($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X12);
    // 0x8022478C: subu        $a3, $a1, $a2
    ctx->r7 = SUB32(ctx->r5, ctx->r6);
    // 0x80224790: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80224794: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80224798: andi        $t8, $a3, 0x1000
    ctx->r24 = ctx->r7 & 0X1000;
    // 0x8022479C: beq         $t8, $zero, L_802247B8
    if (ctx->r24 == 0) {
        // 0x802247A0: andi        $a0, $a3, 0x1FFF
        ctx->r4 = ctx->r7 & 0X1FFF;
            goto L_802247B8;
    }
    // 0x802247A0: andi        $a0, $a3, 0x1FFF
    ctx->r4 = ctx->r7 & 0X1FFF;
    // 0x802247A4: andi        $a0, $a3, 0x1FFF
    ctx->r4 = ctx->r7 & 0X1FFF;
    // 0x802247A8: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x802247AC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802247B0: b           L_802247C0
    // 0x802247B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_802247C0;
    // 0x802247B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_802247B8:
    // 0x802247B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802247BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_802247C0:
    // 0x802247C0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x802247C4: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x802247C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x802247CC: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x802247D0: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x802247D4: nop

    // 0x802247D8: bc1fl       L_802247EC
    if (!c1cs) {
        // 0x802247DC: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802247EC;
    }
    goto skip_0;
    // 0x802247DC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x802247E0: b           L_802247EC
    // 0x802247E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_802247EC;
    // 0x802247E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x802247E8: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_802247EC:
    // 0x802247EC: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x802247F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x802247F4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x802247F8: nop

    // 0x802247FC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80224800: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80224804: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x80224808: beql        $t3, $zero, L_80224854
    if (ctx->r11 == 0) {
        // 0x8022480C: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_80224854;
    }
    goto skip_1;
    // 0x8022480C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_1:
    // 0x80224810: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80224814: nop

    // 0x80224818: bc1fl       L_8022482C
    if (!c1cs) {
        // 0x8022481C: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_8022482C;
    }
    goto skip_2;
    // 0x8022481C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_2:
    // 0x80224820: b           L_8022482C
    // 0x80224824: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8022482C;
    // 0x80224824: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80224828: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_8022482C:
    // 0x8022482C: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80224830: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80224834: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80224838: nop

    // 0x8022483C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80224840: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80224844: andi        $a3, $a3, 0x1FFF
    ctx->r7 = ctx->r7 & 0X1FFF;
    // 0x80224848: b           L_80224888
    // 0x8022484C: addiu       $a3, $a3, -0x2000
    ctx->r7 = ADD32(ctx->r7, -0X2000);
        goto L_80224888;
    // 0x8022484C: addiu       $a3, $a3, -0x2000
    ctx->r7 = ADD32(ctx->r7, -0X2000);
    // 0x80224850: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_80224854:
    // 0x80224854: nop

    // 0x80224858: bc1fl       L_8022486C
    if (!c1cs) {
        // 0x8022485C: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_8022486C;
    }
    goto skip_3;
    // 0x8022485C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_3:
    // 0x80224860: b           L_8022486C
    // 0x80224864: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8022486C;
    // 0x80224864: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80224868: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_8022486C:
    // 0x8022486C: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80224870: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80224874: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80224878: nop

    // 0x8022487C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80224880: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80224884: andi        $a3, $a3, 0x1FFF
    ctx->r7 = ctx->r7 & 0X1FFF;
L_80224888:
    // 0x80224888: bgezl       $a3, L_80224968
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8022488C: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_80224968;
    }
    goto skip_4;
    // 0x8022488C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_4:
    // 0x80224890: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80224894: nop

    // 0x80224898: bc1fl       L_802248AC
    if (!c1cs) {
        // 0x8022489C: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802248AC;
    }
    goto skip_5;
    // 0x8022489C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_5:
    // 0x802248A0: b           L_802248AC
    // 0x802248A4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_802248AC;
    // 0x802248A4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x802248A8: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_802248AC:
    // 0x802248AC: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x802248B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x802248B4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x802248B8: nop

    // 0x802248BC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x802248C0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x802248C4: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x802248C8: beql        $t0, $zero, L_80224920
    if (ctx->r8 == 0) {
        // 0x802248CC: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_80224920;
    }
    goto skip_6;
    // 0x802248CC: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_6:
    // 0x802248D0: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x802248D4: nop

    // 0x802248D8: bc1fl       L_802248EC
    if (!c1cs) {
        // 0x802248DC: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802248EC;
    }
    goto skip_7;
    // 0x802248DC: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_7:
    // 0x802248E0: b           L_802248EC
    // 0x802248E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_802248EC;
    // 0x802248E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x802248E8: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_802248EC:
    // 0x802248EC: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x802248F0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x802248F4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x802248F8: nop

    // 0x802248FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80224900: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80224904: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80224908: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x8022490C: negu        $a3, $v0
    ctx->r7 = SUB32(0, ctx->r2);
    // 0x80224910: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80224914: b           L_80224A24
    // 0x80224918: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
        goto L_80224A24;
    // 0x80224918: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8022491C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_80224920:
    // 0x80224920: nop

    // 0x80224924: bc1fl       L_80224938
    if (!c1cs) {
        // 0x80224928: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224938;
    }
    goto skip_8;
    // 0x80224928: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_8:
    // 0x8022492C: b           L_80224938
    // 0x80224930: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224938;
    // 0x80224930: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80224934: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224938:
    // 0x80224938: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8022493C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80224940: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80224944: nop

    // 0x80224948: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8022494C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80224950: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80224954: negu        $a3, $v0
    ctx->r7 = SUB32(0, ctx->r2);
    // 0x80224958: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8022495C: b           L_80224A24
    // 0x80224960: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
        goto L_80224A24;
    // 0x80224960: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80224964: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_80224968:
    // 0x80224968: nop

    // 0x8022496C: bc1fl       L_80224980
    if (!c1cs) {
        // 0x80224970: lwc1        $f14, 0x10($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224980;
    }
    goto skip_9;
    // 0x80224970: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    skip_9:
    // 0x80224974: b           L_80224980
    // 0x80224978: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80224980;
    // 0x80224978: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8022497C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
L_80224980:
    // 0x80224980: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80224984: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80224988: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8022498C: nop

    // 0x80224990: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80224994: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80224998: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x8022499C: beql        $t7, $zero, L_802249E8
    if (ctx->r15 == 0) {
        // 0x802249A0: c.lt.d      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
            goto L_802249E8;
    }
    goto skip_10;
    // 0x802249A0: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    skip_10:
    // 0x802249A4: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x802249A8: nop

    // 0x802249AC: bc1fl       L_802249C0
    if (!c1cs) {
        // 0x802249B0: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_802249C0;
    }
    goto skip_11;
    // 0x802249B0: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_11:
    // 0x802249B4: b           L_802249C0
    // 0x802249B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_802249C0;
    // 0x802249B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x802249BC: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_802249C0:
    // 0x802249C0: mul.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x802249C4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x802249C8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x802249CC: nop

    // 0x802249D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802249D4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802249D8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x802249DC: b           L_80224A1C
    // 0x802249E0: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_80224A1C;
    // 0x802249E0: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x802249E4: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
L_802249E8:
    // 0x802249E8: nop

    // 0x802249EC: bc1fl       L_80224A00
    if (!c1cs) {
        // 0x802249F0: lwc1        $f12, 0x10($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80224A00;
    }
    goto skip_12;
    // 0x802249F0: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    skip_12:
    // 0x802249F4: b           L_80224A00
    // 0x802249F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80224A00;
    // 0x802249F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x802249FC: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
L_80224A00:
    // 0x80224A00: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80224A04: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80224A08: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80224A0C: nop

    // 0x80224A10: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80224A14: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80224A18: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
L_80224A1C:
    // 0x80224A1C: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80224A20: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
L_80224A24:
    // 0x80224A24: negu        $t0, $a3
    ctx->r8 = SUB32(0, ctx->r7);
    // 0x80224A28: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80224A2C: beql        $at, $zero, L_80224A50
    if (ctx->r1 == 0) {
        // 0x80224A30: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80224A50;
    }
    goto skip_13;
    // 0x80224A30: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    skip_13:
    // 0x80224A34: addu        $t1, $a1, $a3
    ctx->r9 = ADD32(ctx->r5, ctx->r7);
    // 0x80224A38: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80224A3C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80224A40: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x80224A44: b           L_80224A78
    // 0x80224A48: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
        goto L_80224A78;
    // 0x80224A48: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    // 0x80224A4C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
L_80224A50:
    // 0x80224A50: beql        $at, $zero, L_80224A74
    if (ctx->r1 == 0) {
        // 0x80224A54: andi        $t9, $a2, 0x1FFF
        ctx->r25 = ctx->r6 & 0X1FFF;
            goto L_80224A74;
    }
    goto skip_14;
    // 0x80224A54: andi        $t9, $a2, 0x1FFF
    ctx->r25 = ctx->r6 & 0X1FFF;
    skip_14:
    // 0x80224A58: subu        $t5, $a1, $a3
    ctx->r13 = SUB32(ctx->r5, ctx->r7);
    // 0x80224A5C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80224A60: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80224A64: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x80224A68: b           L_80224A78
    // 0x80224A6C: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
        goto L_80224A78;
    // 0x80224A6C: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x80224A70: andi        $t9, $a2, 0x1FFF
    ctx->r25 = ctx->r6 & 0X1FFF;
L_80224A74:
    // 0x80224A74: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
L_80224A78:
    // 0x80224A78: div         $zero, $a0, $a3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r7)));
    // 0x80224A7C: mflo        $v0
    ctx->r2 = lo;
    // 0x80224A80: bne         $a3, $zero, L_80224A8C
    if (ctx->r7 != 0) {
        // 0x80224A84: nop
    
            goto L_80224A8C;
    }
    // 0x80224A84: nop

    // 0x80224A88: break       7
    do_break(2149730952);
L_80224A8C:
    // 0x80224A8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80224A90: bne         $a3, $at, L_80224AA4
    if (ctx->r7 != ctx->r1) {
        // 0x80224A94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80224AA4;
    }
    // 0x80224A94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80224A98: bne         $a0, $at, L_80224AA4
    if (ctx->r4 != ctx->r1) {
        // 0x80224A9C: nop
    
            goto L_80224AA4;
    }
    // 0x80224A9C: nop

    // 0x80224AA0: break       6
    do_break(2149730976);
L_80224AA4:
    // 0x80224AA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80224AA8: bgez        $v0, L_80224ABC
    if (SIGNED(ctx->r2) >= 0) {
            // 0x80224AAC: nop

    LOOKUP_FUNC(0x80224ABC)(rdram, ctx);
    return;
    }
    // 0x80224AAC: nop

    // 0x80224AB0: negu        $a3, $v0
    ctx->r7 = SUB32(0, ctx->r2);
    // 0x80224AB4: jr          $ra
    // 0x80224AB8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    return;
    // 0x80224AB8: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80224abc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80224abc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224ABC: jr          $ra
    // 0x80224AC0: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    return;
    // 0x80224AC0: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80224ac4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80224ac4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224AC4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80224AC8: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x80224ACC: lw          $v0, 0xDC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80224ad0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80224ad0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80224AD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80224AD8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80224ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80224AE0: beq         $a0, $v0, L_80224AF0
    if (ctx->r4 == ctx->r2) {
        // 0x80224AE4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80224AF0;
    }
    // 0x80224AE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80224AE8: b           L_80224AF8
    // 0x80224AEC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
        goto L_80224AF8;
    // 0x80224AEC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
L_80224AF0:
    // 0x80224AF0: lw          $t6, 0xEC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XEC);
    // 0x80224AF4: lw          $v1, 0x5C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X5C);
L_80224AF8:
    // 0x80224AF8: bne         $a2, $v0, L_80224B08
    if (ctx->r6 != ctx->r2) {
        // 0x80224AFC: addiu       $a0, $zero, 0x1000
        ctx->r4 = ADD32(0, 0X1000);
            goto L_80224B08;
    }
    // 0x80224AFC: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x80224B00: b           L_80224B08
    // 0x80224B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80224B08;
    // 0x80224B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80224B08:
    // 0x80224B08: beq         $a1, $zero, L_80224B18
    if (ctx->r5 == 0) {
        // 0x80224B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80224B18;
    }
    // 0x80224B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80224B10: b           L_80224B18
    // 0x80224B14: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
        goto L_80224B18;
    // 0x80224B14: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_80224B18:
    // 0x80224B18: lh          $t7, 0xB98($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XB98);
    // 0x80224B1C: lbu         $t9, 0x9C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X9C);
    // 0x80224B20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80224B24: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80224B28: addu        $a1, $t8, $a0
    ctx->r5 = ADD32(ctx->r24, ctx->r4);
    // 0x80224B2C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224B30: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224B34: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x80224B38: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224B3C: bne         $t9, $at, L_80224B4C
    if (ctx->r25 != ctx->r1) {
        // 0x80224B40: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80224B4C;
    }
    // 0x80224B40: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224B44: b           L_80224B54
    // 0x80224B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80224B54;
    // 0x80224B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80224B4C:
    // 0x80224B4C: jal         0x8022474C
    // 0x80224B50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8022474C)(rdram, ctx);
        goto after_0;
    // 0x80224B50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_80224B54:
    // 0x80224B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80224B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80224B5C: jr          $ra
    // 0x80224B60: nop

    return;
    // 0x80224B60: nop

;}
RECOMP_FUNC void M10_FUN_80224b64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224B64: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80224B68: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80224B6C: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80224b70(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80224b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80224B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80224B78: beql        $a0, $v0, L_80224B8C
    if (ctx->r4 == ctx->r2) {
        // 0x80224B7C: lw          $t6, 0xEC($a2)
        ctx->r14 = MEM_W(ctx->r6, 0XEC);
            goto L_80224B8C;
    }
    goto skip_0;
    // 0x80224B7C: lw          $t6, 0xEC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XEC);
    skip_0:
    // 0x80224B80: b           L_80224B90
    // 0x80224B84: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
        goto L_80224B90;
    // 0x80224B84: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80224B88: lw          $t6, 0xEC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XEC);
L_80224B8C:
    // 0x80224B8C: lw          $v1, 0x5C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X5C);
L_80224B90:
    // 0x80224B90: bnel        $a0, $v0, L_80224BA4
    if (ctx->r4 != ctx->r2) {
        // 0x80224B94: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_80224BA4;
    }
    goto skip_1;
    // 0x80224B94: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    skip_1:
    // 0x80224B98: b           L_80224BA4
    // 0x80224B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80224BA4;
    // 0x80224B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80224BA0: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_80224BA4:
    // 0x80224BA4: lh          $t7, 0xB98($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XB98);
    // 0x80224BA8: lbu         $t8, 0x9C($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X9C);
    // 0x80224BAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80224BB0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x80224BB4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224BB8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224BBC: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x80224BC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224BC4: bne         $t8, $at, L_80224BD4
    if (ctx->r24 != ctx->r1) {
        // 0x80224BC8: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80224BD4;
    }
    // 0x80224BC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224BCC: b           L_80224BDC
    // 0x80224BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80224BDC;
    // 0x80224BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80224BD4:
    // 0x80224BD4: jal         0x802243B4
    // 0x80224BD8: nop

    LOOKUP_FUNC(0x802243B4)(rdram, ctx);
        goto after_0;
    // 0x80224BD8: nop

    after_0:
L_80224BDC:
    // 0x80224BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80224BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80224BE4: jr          $ra
    // 0x80224BE8: nop

    return;
    // 0x80224BE8: nop

;}
RECOMP_FUNC void M10_FUN_80224bec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224BEC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80224BF0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80224BF4: lw          $t7, -0x4334($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4334);
    // 0x80224BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80224BFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80224C00: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80224C04: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80224C08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80224C0C: bne         $a0, $t7, L_80224C20
    if (ctx->r4 != ctx->r15) {
        // 0x80224C10: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_80224C20;
    }
    // 0x80224C10: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80224C14: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80224C18: b           L_80224C28
    // 0x80224C1C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_80224C28;
    // 0x80224C1C: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_80224C20:
    // 0x80224C20: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80224C24: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_80224C28:
    // 0x80224C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80224C2C: jal         0x80224B64
    // 0x80224C30: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80224B64)(rdram, ctx);
        goto after_0;
    // 0x80224C30: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x80224C34: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80224C38: beq         $at, $zero, L_80224D90
    if (ctx->r1 == 0) {
        // 0x80224C3C: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_80224D90;
    }
    // 0x80224C3C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80224C40: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80224C44: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80224C48: addu        $at, $at, $t8
    gpr jr_addend_80224C50 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80224C4C: lw          $t8, -0x1058($at)
    ctx->r24 = ADD32(ctx->r1, -0X1058);
    // 0x80224C50: jr          $t8
    // 0x80224C54: nop

    switch (jr_addend_80224C50 >> 2) {
        case 0: goto L_80224D90; break;
        case 1: goto L_80224C58; break;
        case 2: goto L_80224D08; break;
        case 3: goto L_80224D78; break;
        case 4: goto L_80224CB8; break;
        case 5: goto L_80224D40; break;
        case 6: goto L_80224D78; break;
        default: switch_error(__func__, 0x80224C50, 0x8023EFA8);
    }
    // 0x80224C54: nop

L_80224C58:
    // 0x80224C58: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80224C5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80224C60: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80224C64: sll         $t0, $t9, 9
    ctx->r8 = S32(ctx->r25 << 9);
    // 0x80224C68: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80224C6C: bne         $t1, $at, L_80224C7C
    if (ctx->r9 != ctx->r1) {
        // 0x80224C70: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80224C7C;
    }
    // 0x80224C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224C74: b           L_80224C80
    // 0x80224C78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80224C80;
    // 0x80224C78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80224C7C:
    // 0x80224C7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80224C80:
    // 0x80224C80: jal         0x802256E4
    // 0x80224C84: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_1;
    // 0x80224C84: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_1:
    // 0x80224C88: lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X36);
    // 0x80224C8C: lhu         $t2, 0x32($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X32);
    // 0x80224C90: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x80224C94: bne         $a0, $v1, L_80224CA4
    if (ctx->r4 != ctx->r3) {
        // 0x80224C98: xori        $t3, $t2, 0x10
        ctx->r11 = ctx->r10 ^ 0X10;
            goto L_80224CA4;
    }
    // 0x80224C98: xori        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 ^ 0X10;
    // 0x80224C9C: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    // 0x80224CA0: lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X36);
L_80224CA4:
    // 0x80224CA4: beq         $a0, $v1, L_80224D98
    if (ctx->r4 == ctx->r3) {
        // 0x80224CA8: lui         $at, 0x8024
        ctx->r1 = S32(0X8024 << 16);
            goto L_80224D98;
    }
    // 0x80224CA8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80224CAC: lwc1        $f4, -0x103C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X103C);
    // 0x80224CB0: b           L_80224D98
    // 0x80224CB4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
        goto L_80224D98;
    // 0x80224CB4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
L_80224CB8:
    // 0x80224CB8: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x80224CBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80224CC0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80224CC4: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x80224CC8: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80224CCC: bne         $t6, $at, L_80224CDC
    if (ctx->r14 != ctx->r1) {
        // 0x80224CD0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80224CDC;
    }
    // 0x80224CD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224CD4: b           L_80224CE0
    // 0x80224CD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80224CE0;
    // 0x80224CD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80224CDC:
    // 0x80224CDC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80224CE0:
    // 0x80224CE0: jal         0x802256E4
    // 0x80224CE4: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_2;
    // 0x80224CE4: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_2:
    // 0x80224CE8: lhu         $t7, 0x36($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X36);
    // 0x80224CEC: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x80224CF0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80224CF4: beql        $a0, $t7, L_80224D9C
    if (ctx->r4 == ctx->r15) {
        // 0x80224CF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80224D9C;
    }
    goto skip_0;
    // 0x80224CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80224CFC: lwc1        $f6, -0x1038($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1038);
    // 0x80224D00: b           L_80224D98
    // 0x80224D04: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_80224D98;
    // 0x80224D04: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_80224D08:
    // 0x80224D08: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80224D0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80224D10: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80224D14: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80224D18: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x80224D1C: bne         $t0, $at, L_80224D2C
    if (ctx->r8 != ctx->r1) {
        // 0x80224D20: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80224D2C;
    }
    // 0x80224D20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224D24: b           L_80224D30
    // 0x80224D28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80224D30;
    // 0x80224D28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80224D2C:
    // 0x80224D2C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80224D30:
    // 0x80224D30: jal         0x802256E4
    // 0x80224D34: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_3;
    // 0x80224D34: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x80224D38: b           L_80224D9C
    // 0x80224D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80224D9C;
    // 0x80224D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80224D40:
    // 0x80224D40: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x80224D44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80224D48: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80224D4C: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x80224D50: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80224D54: bne         $t3, $at, L_80224D64
    if (ctx->r11 != ctx->r1) {
        // 0x80224D58: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80224D64;
    }
    // 0x80224D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224D5C: b           L_80224D68
    // 0x80224D60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80224D68;
    // 0x80224D60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80224D64:
    // 0x80224D64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80224D68:
    // 0x80224D68: jal         0x802256E4
    // 0x80224D6C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_4;
    // 0x80224D6C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_4:
    // 0x80224D70: b           L_80224D9C
    // 0x80224D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80224D9C;
    // 0x80224D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80224D78:
    // 0x80224D78: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80224D7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80224D80: jal         0x802256E4
    // 0x80224D84: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_5;
    // 0x80224D84: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_5:
    // 0x80224D88: b           L_80224D9C
    // 0x80224D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80224D9C;
    // 0x80224D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80224D90:
    // 0x80224D90: b           L_80224DEC
    // 0x80224D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80224DEC;
    // 0x80224D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80224D98:
    // 0x80224D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80224D9C:
    // 0x80224D9C: jal         0x802237B0
    // 0x80224DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x802237B0)(rdram, ctx);
        goto after_6;
    // 0x80224DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80224DA4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80224DA8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80224DAC: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80224DB0: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x80224DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80224DB8: beq         $t4, $t6, L_80224DEC
    if (ctx->r12 == ctx->r14) {
        // 0x80224DBC: nop
    
            goto L_80224DEC;
    }
    // 0x80224DBC: nop

    // 0x80224DC0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80224DC4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80224DC8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80224DCC: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x80224DD0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80224DD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80224DD8: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80224DDC: jal         0x8013A28C
    // 0x80224DE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_7;
    // 0x80224DE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_7:
    // 0x80224DE4: b           L_80224DEC
    // 0x80224DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80224DEC;
    // 0x80224DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80224DEC:
    // 0x80224DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80224DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80224DF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80224DF8: jr          $ra
    // 0x80224DFC: nop

    return;
    // 0x80224DFC: nop

;}
RECOMP_FUNC void M10_FUN_80224e00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224E00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80224E04: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80224E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80224E0C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80224E10: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80224E14: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224E18: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224E1C: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80224E20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80224E24: sh          $a1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r5;
    // 0x80224E28: jal         0x8001EAD0
    // 0x80224E2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80224E2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80224E30: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80224E34: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80224E38: jal         0x8001EB64
    // 0x80224E3C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80224E3C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80224E40: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80224E44: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80224E48: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80224E4C: lwc1        $f4, 0xB8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x80224E50: lwc1        $f16, 0xB0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80224E54: lwc1        $f18, 0xBC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x80224E58: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80224E5C: lwc1        $f6, 0xC4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80224E60: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x80224E64: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80224E68: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80224E6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80224E70: lwc1        $f0, 0xC8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80224E74: lwc1        $f2, 0xD4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x80224E78: lwc1        $f12, 0xD0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80224E7C: beq         $a1, $zero, L_80224F4C
    if (ctx->r5 == 0) {
        // 0x80224E80: lwc1        $f14, 0xDC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XDC);
            goto L_80224F4C;
    }
    // 0x80224E80: lwc1        $f14, 0xDC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x80224E84: bnel        $a1, $at, L_80224EB4
    if (ctx->r5 != ctx->r1) {
        // 0x80224E88: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80224EB4;
    }
    goto skip_0;
    // 0x80224E88: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    skip_0:
    // 0x80224E8C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80224E90: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80224E94: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80224E98: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x80224E9C: swc1        $f8, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f8.u32l;
    // 0x80224EA0: swc1        $f10, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f10.u32l;
    // 0x80224EA4: swc1        $f4, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f4.u32l;
    // 0x80224EA8: b           L_80224F4C
    // 0x80224EAC: swc1        $f6, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f6.u32l;
        goto L_80224F4C;
    // 0x80224EAC: swc1        $f6, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f6.u32l;
    // 0x80224EB0: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
L_80224EB4:
    // 0x80224EB4: bne         $a1, $at, L_80224EF0
    if (ctx->r5 != ctx->r1) {
        // 0x80224EB8: lwc1        $f8, 0x20($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80224EF0;
    }
    // 0x80224EB8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80224EBC: swc1        $f8, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f8.u32l;
    // 0x80224EC0: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80224EC4: swc1        $f16, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f16.u32l;
    // 0x80224EC8: swc1        $f18, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f18.u32l;
    // 0x80224ECC: swc1        $f12, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f12.u32l;
    // 0x80224ED0: swc1        $f14, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f14.u32l;
    // 0x80224ED4: swc1        $f0, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f0.u32l;
    // 0x80224ED8: swc1        $f2, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f2.u32l;
    // 0x80224EDC: swc1        $f10, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f10.u32l;
    // 0x80224EE0: jal         0x802260C8
    // 0x80224EE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x802260C8)(rdram, ctx);
        goto after_2;
    // 0x80224EE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80224EE8: b           L_80224F50
    // 0x80224EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80224F50;
    // 0x80224EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80224EF0:
    // 0x80224EF0: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
    // 0x80224EF4: bnel        $a1, $at, L_80224F50
    if (ctx->r5 != ctx->r1) {
        // 0x80224EF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80224F50;
    }
    goto skip_1;
    // 0x80224EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80224EFC: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80224F00: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80224F04: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80224F08: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x80224F0C: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x80224F10: swc1        $f10, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f10.u32l;
    // 0x80224F14: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80224F18: swc1        $f8, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f8.u32l;
    // 0x80224F1C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80224F20: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x80224F24: swc1        $f4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f4.u32l;
    // 0x80224F28: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
    // 0x80224F2C: swc1        $f10, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f10.u32l;
    // 0x80224F30: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80224F34: swc1        $f6, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f6.u32l;
    // 0x80224F38: swc1        $f4, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
    // 0x80224F3C: swc1        $f8, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f8.u32l;
    // 0x80224F40: swc1        $f10, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f10.u32l;
    // 0x80224F44: jal         0x802260C8
    // 0x80224F48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x802260C8)(rdram, ctx);
        goto after_3;
    // 0x80224F48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
L_80224F4C:
    // 0x80224F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80224F50:
    // 0x80224F50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80224F54: jr          $ra
    // 0x80224F58: nop

    return;
    // 0x80224F58: nop

;}
RECOMP_FUNC void M10_FUN_80224f5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80224F5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80224F60: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80224F64: lw          $t7, -0x4334($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4334);
    // 0x80224F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80224F6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80224F70: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80224F74: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80224F78: bne         $a0, $t7, L_80224F8C
    if (ctx->r4 != ctx->r15) {
        // 0x80224F7C: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80224F8C;
    }
    // 0x80224F7C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80224F80: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80224F84: b           L_80224F90
    // 0x80224F88: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
        goto L_80224F90;
    // 0x80224F88: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80224F8C:
    // 0x80224F8C: addiu       $a2, $a2, -0x3C28
    ctx->r6 = ADD32(ctx->r6, -0X3C28);
L_80224F90:
    // 0x80224F90: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80224F94: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80224F98: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80224F9C: jal         0x80224BEC
    // 0x80224FA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80224BEC)(rdram, ctx);
        goto after_0;
    // 0x80224FA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80224FA4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80224FA8: jal         0x80010550
    // 0x80224FAC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80224FAC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80224FB0: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x80224FB4: jal         0x8022560C
    // 0x80224FB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x8022560C)(rdram, ctx);
        goto after_2;
    // 0x80224FB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80224FBC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80224FC0: beq         $a0, $v0, L_80224FE0
    if (ctx->r4 == ctx->r2) {
        // 0x80224FC4: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80224FE0;
    }
    // 0x80224FC4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80224FC8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80224FCC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80224FD0: beq         $v1, $at, L_80224FE0
    if (ctx->r3 == ctx->r1) {
        // 0x80224FD4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80224FE0;
    }
    // 0x80224FD4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80224FD8: bne         $v1, $at, L_80225124
    if (ctx->r3 != ctx->r1) {
        // 0x80224FDC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80225124;
    }
    // 0x80224FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80224FE0:
    // 0x80224FE0: lhu         $t8, 0x2C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2C);
    // 0x80224FE4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80224FE8: bne         $t8, $zero, L_80224FF8
    if (ctx->r24 != 0) {
        // 0x80224FEC: nop
    
            goto L_80224FF8;
    }
    // 0x80224FEC: nop

    // 0x80224FF0: b           L_8022517C
    // 0x80224FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8022517C;
    // 0x80224FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80224FF8:
    // 0x80224FF8: bne         $a0, $v1, L_80225034
    if (ctx->r4 != ctx->r3) {
        // 0x80224FFC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80225034;
    }
    // 0x80224FFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80225000: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x80225004: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x80225008: lw          $t0, 0x30($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X30);
    // 0x8022500C: lbu         $t6, 0x31($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X31);
    // 0x80225010: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x80225014: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80225018: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x8022501C: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80225020: andi        $t5, $t4, 0x60
    ctx->r13 = ctx->r12 & 0X60;
    // 0x80225024: andi        $t7, $t6, 0xFF9F
    ctx->r15 = ctx->r14 & 0XFF9F;
    // 0x80225028: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8022502C: b           L_8022509C
    // 0x80225030: sb          $t8, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r24;
        goto L_8022509C;
    // 0x80225030: sb          $t8, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r24;
L_80225034:
    // 0x80225034: bnel        $v1, $at, L_8022506C
    if (ctx->r3 != ctx->r1) {
        // 0x80225038: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8022506C;
    }
    goto skip_0;
    // 0x80225038: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_0:
    // 0x8022503C: lw          $t9, 0x30($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X30);
    // 0x80225040: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80225044: addiu       $t3, $zero, 0x1800
    ctx->r11 = ADD32(0, 0X1800);
    // 0x80225048: sll         $t0, $t9, 9
    ctx->r8 = S32(ctx->r25 << 9);
    // 0x8022504C: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80225050: bne         $t1, $at, L_80225060
    if (ctx->r9 != ctx->r1) {
        // 0x80225054: addiu       $t2, $zero, 0x800
        ctx->r10 = ADD32(0, 0X800);
            goto L_80225060;
    }
    // 0x80225054: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80225058: b           L_8022509C
    // 0x8022505C: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
        goto L_8022509C;
    // 0x8022505C: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
L_80225060:
    // 0x80225060: b           L_8022509C
    // 0x80225064: sh          $t3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r11;
        goto L_8022509C;
    // 0x80225064: sh          $t3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r11;
    // 0x80225068: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8022506C:
    // 0x8022506C: bnel        $v1, $at, L_802250A0
    if (ctx->r3 != ctx->r1) {
        // 0x80225070: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_802250A0;
    }
    goto skip_1;
    // 0x80225070: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80225074: lw          $t4, 0x30($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X30);
    // 0x80225078: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8022507C: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80225080: sll         $t6, $t4, 9
    ctx->r14 = S32(ctx->r12 << 9);
    // 0x80225084: srl         $t5, $t6, 30
    ctx->r13 = S32(U32(ctx->r14) >> 30);
    // 0x80225088: bne         $t5, $at, L_80225098
    if (ctx->r13 != ctx->r1) {
        // 0x8022508C: addiu       $t7, $zero, 0x1800
        ctx->r15 = ADD32(0, 0X1800);
            goto L_80225098;
    }
    // 0x8022508C: addiu       $t7, $zero, 0x1800
    ctx->r15 = ADD32(0, 0X1800);
    // 0x80225090: b           L_8022509C
    // 0x80225094: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
        goto L_8022509C;
    // 0x80225094: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
L_80225098:
    // 0x80225098: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
L_8022509C:
    // 0x8022509C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_802250A0:
    // 0x802250A0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x802250A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x802250A8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x802250AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802250B0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x802250B4: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x802250B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x802250BC: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x802250C0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x802250C4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x802250C8: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x802250CC: andi        $t6, $t4, 0x1FFF
    ctx->r14 = ctx->r12 & 0X1FFF;
    // 0x802250D0: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    // 0x802250D4: jal         0x802256E4
    // 0x802250D8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_3;
    // 0x802250D8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x802250DC: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x802250E0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x802250E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x802250E8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x802250EC: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x802250F0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x802250F4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x802250F8: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x802250FC: jal         0x8013A28C
    // 0x80225100: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_4;
    // 0x80225100: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x80225104: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80225108: jal         0x80224E00
    // 0x8022510C: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x80224E00)(rdram, ctx);
        goto after_5;
    // 0x8022510C: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_5:
    // 0x80225110: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80225114: jal         0x80010550
    // 0x80225118: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x80225118: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8022511C: b           L_8022517C
    // 0x80225120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8022517C;
    // 0x80225120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80225124:
    // 0x80225124: jal         0x80224AC4
    // 0x80225128: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x80224AC4)(rdram, ctx);
        goto after_7;
    // 0x80225128: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8022512C: bne         $v0, $zero, L_80225178
    if (ctx->r2 != 0) {
        // 0x80225130: sh          $v0, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r2;
            goto L_80225178;
    }
    // 0x80225130: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x80225134: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80225138: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8022513C: jal         0x802256E4
    // 0x80225140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x802256E4)(rdram, ctx);
        goto after_8;
    // 0x80225140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80225144: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80225148: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8022514C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80225150: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80225154: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80225158: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8022515C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80225160: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80225164: jal         0x8013A28C
    // 0x80225168: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_9;
    // 0x80225168: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x8022516C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80225170: jal         0x80010550
    // 0x80225174: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_10;
    // 0x80225174: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
L_80225178:
    // 0x80225178: lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X2A);
L_8022517C:
    // 0x8022517C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225180: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80225184: jr          $ra
    // 0x80225188: nop

    return;
    // 0x80225188: nop

;}
RECOMP_FUNC void M10_FUN_8022518c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8022518C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80225190: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80225194(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80225194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80225198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8022519C: bne         $a0, $t6, L_802251B0
    if (ctx->r4 != ctx->r14) {
        // 0x802251A0: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_802251B0;
    }
    // 0x802251A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802251A4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802251A8: b           L_802251B4
    // 0x802251AC: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
        goto L_802251B4;
    // 0x802251AC: addiu       $v1, $v1, -0x3FC4
    ctx->r3 = ADD32(ctx->r3, -0X3FC4);
L_802251B0:
    // 0x802251B0: addiu       $v1, $v1, -0x3C28
    ctx->r3 = ADD32(ctx->r3, -0X3C28);
L_802251B4:
    // 0x802251B4: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x802251B8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x802251BC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x802251C0: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x802251C4: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x802251C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x802251CC: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x802251D0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x802251D4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x802251D8: lbu         $t0, 0x328($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X328);
    // 0x802251DC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x802251E0: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x802251E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x802251E8: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x802251EC: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x802251F0: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x802251F4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x802251F8: beq         $at, $zero, L_802253A4
    if (ctx->r1 == 0) {
        // 0x802251FC: cvt.s.d     $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
            goto L_802253A4;
    }
    // 0x802251FC: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80225200: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80225204: addu        $at, $at, $t0
    gpr jr_addend_8022520C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80225208: lw          $t0, -0x1034($at)
    ctx->r8 = ADD32(ctx->r1, -0X1034);
    // 0x8022520C: jr          $t0
    // 0x80225210: nop

    switch (jr_addend_8022520C >> 2) {
        case 0: goto L_80225214; break;
        case 1: goto L_80225264; break;
        case 2: goto L_802252C4; break;
        case 3: goto L_802253A8; break;
        case 4: goto L_802253A8; break;
        default: switch_error(__func__, 0x8022520C, 0x8023EFCC);
    }
    // 0x80225210: nop

L_80225214:
    // 0x80225214: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80225218: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8022521C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80225220: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80225224: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80225228: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8022522C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80225230: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80225234: nop

    // 0x80225238: bc1fl       L_802253AC
    if (!c1cs) {
        // 0x8022523C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802253AC;
    }
    goto skip_0;
    // 0x8022523C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80225240: sb          $zero, 0x329($v1)
    MEM_B(0X329, ctx->r3) = 0;
    // 0x80225244: jal         0x8001EF38
    // 0x80225248: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x80225248: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8022524C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80225250: lbu         $t1, 0x328($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X328);
    // 0x80225254: sh          $v0, 0x32A($v1)
    MEM_H(0X32A, ctx->r3) = ctx->r2;
    // 0x80225258: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8022525C: b           L_802253A8
    // 0x80225260: sb          $t2, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r10;
        goto L_802253A8;
    // 0x80225260: sb          $t2, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r10;
L_80225264:
    // 0x80225264: lbu         $t3, 0x329($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X329);
    // 0x80225268: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8022526C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80225270: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80225274: beq         $at, $zero, L_802252BC
    if (ctx->r1 == 0) {
        // 0x80225278: sb          $t4, 0x329($v1)
        MEM_B(0X329, ctx->r3) = ctx->r12;
            goto L_802252BC;
    }
    // 0x80225278: sb          $t4, 0x329($v1)
    MEM_B(0X329, ctx->r3) = ctx->r12;
    // 0x8022527C: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80225280: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80225284: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80225288: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8022528C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80225290: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80225294: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80225298: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8022529C: nop

    // 0x802252A0: bc1fl       L_802253AC
    if (!c1cs) {
        // 0x802252A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802253AC;
    }
    goto skip_1;
    // 0x802252A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x802252A8: lbu         $t6, 0x328($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X328);
    // 0x802252AC: sb          $zero, 0x329($v1)
    MEM_B(0X329, ctx->r3) = 0;
    // 0x802252B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x802252B4: b           L_802253A8
    // 0x802252B8: sb          $t7, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r15;
        goto L_802253A8;
    // 0x802252B8: sb          $t7, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r15;
L_802252BC:
    // 0x802252BC: b           L_802253A8
    // 0x802252C0: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
        goto L_802253A8;
    // 0x802252C0: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
L_802252C4:
    // 0x802252C4: lbu         $t8, 0x329($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X329);
    // 0x802252C8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x802252CC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x802252D0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x802252D4: beq         $at, $zero, L_8022539C
    if (ctx->r1 == 0) {
        // 0x802252D8: sb          $t9, 0x329($v1)
        MEM_B(0X329, ctx->r3) = ctx->r25;
            goto L_8022539C;
    }
    // 0x802252D8: sb          $t9, 0x329($v1)
    MEM_B(0X329, ctx->r3) = ctx->r25;
    // 0x802252DC: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x802252E0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x802252E4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x802252E8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x802252EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x802252F0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x802252F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x802252F8: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x802252FC: nop

    // 0x80225300: bc1fl       L_802253AC
    if (!c1cs) {
        // 0x80225304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802253AC;
    }
    goto skip_2;
    // 0x80225304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80225308: jal         0x8001EF38
    // 0x8022530C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8022530C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80225310: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80225314: lh          $t1, 0x32A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X32A);
    // 0x80225318: subu        $a1, $v0, $t1
    ctx->r5 = SUB32(ctx->r2, ctx->r9);
    // 0x8022531C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80225320: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80225324: andi        $a3, $a1, 0x1000
    ctx->r7 = ctx->r5 & 0X1000;
    // 0x80225328: beq         $a3, $zero, L_8022533C
    if (ctx->r7 == 0) {
        // 0x8022532C: andi        $a0, $a1, 0x1FFF
        ctx->r4 = ctx->r5 & 0X1FFF;
            goto L_8022533C;
    }
    // 0x8022532C: andi        $a0, $a1, 0x1FFF
    ctx->r4 = ctx->r5 & 0X1FFF;
    // 0x80225330: andi        $a0, $a1, 0x1FFF
    ctx->r4 = ctx->r5 & 0X1FFF;
    // 0x80225334: b           L_80225340
    // 0x80225338: addiu       $a2, $a0, -0x2000
    ctx->r6 = ADD32(ctx->r4, -0X2000);
        goto L_80225340;
    // 0x80225338: addiu       $a2, $a0, -0x2000
    ctx->r6 = ADD32(ctx->r4, -0X2000);
L_8022533C:
    // 0x8022533C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80225340:
    // 0x80225340: bgez        $a2, L_80225364
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80225344: nop
    
            goto L_80225364;
    }
    // 0x80225344: nop

    // 0x80225348: beq         $a3, $zero, L_8022535C
    if (ctx->r7 == 0) {
        // 0x8022534C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8022535C;
    }
    // 0x8022534C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80225350: addiu       $a1, $a0, -0x2000
    ctx->r5 = ADD32(ctx->r4, -0X2000);
    // 0x80225354: b           L_80225378
    // 0x80225358: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
        goto L_80225378;
    // 0x80225358: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
L_8022535C:
    // 0x8022535C: b           L_80225378
    // 0x80225360: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
        goto L_80225378;
    // 0x80225360: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
L_80225364:
    // 0x80225364: beq         $a3, $zero, L_80225374
    if (ctx->r7 == 0) {
        // 0x80225368: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80225374;
    }
    // 0x80225368: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8022536C: b           L_80225374
    // 0x80225370: addiu       $a1, $a0, -0x2000
    ctx->r5 = ADD32(ctx->r4, -0X2000);
        goto L_80225374;
    // 0x80225370: addiu       $a1, $a0, -0x2000
    ctx->r5 = ADD32(ctx->r4, -0X2000);
L_80225374:
    // 0x80225374: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80225378:
    // 0x80225378: slti        $at, $a0, 0x300
    ctx->r1 = SIGNED(ctx->r4) < 0X300 ? 1 : 0;
    // 0x8022537C: beql        $at, $zero, L_802253AC
    if (ctx->r1 == 0) {
        // 0x80225380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802253AC;
    }
    goto skip_3;
    // 0x80225380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80225384: lbu         $t2, 0x328($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X328);
    // 0x80225388: sb          $zero, 0x329($v1)
    MEM_B(0X329, ctx->r3) = 0;
    // 0x8022538C: sh          $v0, 0x32A($v1)
    MEM_H(0X32A, ctx->r3) = ctx->r2;
    // 0x80225390: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80225394: b           L_802253A8
    // 0x80225398: sb          $t3, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r11;
        goto L_802253A8;
    // 0x80225398: sb          $t3, 0x328($v1)
    MEM_B(0X328, ctx->r3) = ctx->r11;
L_8022539C:
    // 0x8022539C: b           L_802253A8
    // 0x802253A0: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
        goto L_802253A8;
    // 0x802253A0: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
L_802253A4:
    // 0x802253A4: sb          $zero, 0x328($v1)
    MEM_B(0X328, ctx->r3) = 0;
L_802253A8:
    // 0x802253A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802253AC:
    // 0x802253AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802253B0: jr          $ra
    // 0x802253B4: nop

    return;
    // 0x802253B4: nop

;}
RECOMP_FUNC void M10_FUN_802253b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802253B8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x802253BC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x802253C0: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x802253C4: bnel        $a0, $t6, L_802253E8
    if (ctx->r4 != ctx->r14) {
        // 0x802253C8: lhu         $v0, 0x2C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X2C);
            goto L_802253E8;
    }
    goto skip_0;
    // 0x802253C8: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    skip_0:
    // 0x802253CC: lhu         $t7, 0x2C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2C);
    // 0x802253D0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x802253D4: beql        $t7, $at, L_802253E8
    if (ctx->r15 == ctx->r1) {
        // 0x802253D8: lhu         $v0, 0x2C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X2C);
            goto L_802253E8;
    }
    goto skip_1;
    // 0x802253D8: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    skip_1:
    // 0x802253DC: jr          $ra
    // 0x802253E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x802253E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802253E4: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
L_802253E8:
    // 0x802253E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802253EC: beq         $v0, $at, L_802253FC
    if (ctx->r2 == ctx->r1) {
        // 0x802253F0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_802253FC;
    }
    // 0x802253F0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x802253F4: bnel        $v0, $at, L_80225408
    if (ctx->r2 != ctx->r1) {
        // 0x802253F8: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_80225408;
    }
    goto skip_2;
    // 0x802253F8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    skip_2:
L_802253FC:
    // 0x802253FC: jr          $ra
    // 0x80225400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80225400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80225404: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80225408:
    // 0x80225408: jr          $ra
    // 0x8022540C: nop

    return;
    // 0x8022540C: nop

;}
RECOMP_FUNC void M10_FUN_80225410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80225414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80225418: jal         0x802253B8
    // 0x8022541C: nop

    LOOKUP_FUNC(0x802253B8)(rdram, ctx);
        goto after_0;
    // 0x8022541C: nop

    after_0:
    // 0x80225420: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80225424: bne         $t6, $zero, L_8022543C
    if (ctx->r14 != 0) {
        // 0x80225428: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_8022543C;
    }
    // 0x80225428: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8022542C: jal         0x80151870
    // 0x80225430: nop

    LOOKUP_FUNC(0x80151870)(rdram, ctx);
        goto after_1;
    // 0x80225430: nop

    after_1:
    // 0x80225434: b           L_80225440
    // 0x80225438: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80225440;
    // 0x80225438: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8022543C:
    // 0x8022543C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80225440:
    // 0x80225440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80225448: jr          $ra
    // 0x8022544C: nop

    return;
    // 0x8022544C: nop

;}
RECOMP_FUNC void M10_FUN_80225450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80225450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80225454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80225458: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8022545C: jal         0x802253B8
    // 0x80225460: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x802253B8)(rdram, ctx);
        goto after_0;
    // 0x80225460: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80225464: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80225468: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8022546C: bne         $t6, $zero, L_802254E4
    if (ctx->r14 != 0) {
        // 0x80225470: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_802254E4;
    }
    // 0x80225470: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80225474: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x80225478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8022547C: bne         $t7, $at, L_80225494
    if (ctx->r15 != ctx->r1) {
        // 0x80225480: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80225494;
    }
    // 0x80225480: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80225484: jal         0x80002B44
    // 0x80225488: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002B44)(rdram, ctx);
        goto after_1;
    // 0x80225488: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x8022548C: b           L_802254A0
    // 0x80225490: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_802254A0;
    // 0x80225490: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80225494:
    // 0x80225494: jal         0x80002BAC
    // 0x80225498: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_2;
    // 0x80225498: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x8022549C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_802254A0:
    // 0x802254A0: beql        $v0, $zero, L_802254E8
    if (ctx->r2 == 0) {
        // 0x802254A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_802254E8;
    }
    goto skip_0;
    // 0x802254A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x802254A8: jal         0x80002A94
    // 0x802254AC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002A94)(rdram, ctx);
        goto after_3;
    // 0x802254AC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_3:
    // 0x802254B0: bne         $v0, $zero, L_802254E4
    if (ctx->r2 != 0) {
        // 0x802254B4: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_802254E4;
    }
    // 0x802254B4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x802254B8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x802254BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802254C0: bne         $t8, $at, L_802254D8
    if (ctx->r24 != ctx->r1) {
        // 0x802254C4: nop
    
            goto L_802254D8;
    }
    // 0x802254C4: nop

    // 0x802254C8: jal         0x80002B44
    // 0x802254CC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002B44)(rdram, ctx);
        goto after_4;
    // 0x802254CC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x802254D0: b           L_802254E4
    // 0x802254D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_802254E4;
    // 0x802254D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_802254D8:
    // 0x802254D8: jal         0x80002BAC
    // 0x802254DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_5;
    // 0x802254DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x802254E0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_802254E4:
    // 0x802254E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802254E8:
    // 0x802254E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802254EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x802254F0: jr          $ra
    // 0x802254F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x802254F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802254f8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802254f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802254F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802254FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80225500: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80225504: jal         0x802253B8
    // 0x80225508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x802253B8)(rdram, ctx);
        goto after_0;
    // 0x80225508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8022550C: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80225510: bne         $t6, $zero, L_8022552C
    if (ctx->r14 != 0) {
        // 0x80225514: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_8022552C;
    }
    // 0x80225514: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80225518: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    // 0x8022551C: jal         0x801518D4
    // 0x80225520: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_1;
    // 0x80225520: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    after_1:
    // 0x80225524: b           L_80225530
    // 0x80225528: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80225530;
    // 0x80225528: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8022552C:
    // 0x8022552C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80225530:
    // 0x80225530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80225534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80225538: jr          $ra
    // 0x8022553C: nop

    return;
    // 0x8022553C: nop

;}
