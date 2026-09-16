#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_800200b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800200B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800200B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800200B8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800200BC: addiu       $s4, $s4, 0x7954
    ctx->r20 = ADD32(ctx->r20, 0X7954);
    // 0x800200C0: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800200C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800200C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800200CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800200D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800200D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800200D8: beq         $t6, $zero, L_80020110
    if (ctx->r14 == 0) {
        // 0x800200DC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80020110;
    }
    // 0x800200DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800200E0: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800200E4: addiu       $s1, $s1, 0x6950
    ctx->r17 = ADD32(ctx->r17, 0X6950);
    // 0x800200E8: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x800200EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800200F0:
    // 0x800200F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800200F4: jal         0x800266B0
    // 0x800200F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x800200F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800200FC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80020100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020104: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x80020108: bnel        $at, $zero, L_800200F0
    if (ctx->r1 != 0) {
        // 0x8002010C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800200F0;
    }
    goto skip_0;
    // 0x8002010C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80020110:
    // 0x80020110: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80020114: addiu       $s2, $s2, 0x6020
    ctx->r18 = ADD32(ctx->r18, 0X6020);
    // 0x80020118: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x8002011C: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80020120: addiu       $s3, $s3, 0x7950
    ctx->r19 = ADD32(ctx->r19, 0X7950);
    // 0x80020124: beq         $s0, $zero, L_80020190
    if (ctx->r16 == 0) {
        // 0x80020128: nop
    
            goto L_80020190;
    }
    // 0x80020128: nop

L_8002012C:
    // 0x8002012C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80020130: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80020134: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020138: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8002013C: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x80020140: beq         $at, $zero, L_80020188
    if (ctx->r1 == 0) {
        // 0x80020144: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80020188;
    }
    // 0x80020144: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80020148: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x8002014C: bne         $s0, $t1, L_80020158
    if (ctx->r16 != ctx->r9) {
        // 0x80020150: nop
    
            goto L_80020158;
    }
    // 0x80020150: nop

    // 0x80020154: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80020158:
    // 0x80020158: jal         0x80026890
    // 0x8002015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_1;
    // 0x8002015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80020160: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80020164: beql        $a1, $zero, L_80020180
    if (ctx->r5 == 0) {
        // 0x80020168: sw          $s0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r16;
            goto L_80020180;
    }
    goto skip_1;
    // 0x80020168: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    skip_1:
    // 0x8002016C: jal         0x800268C0
    // 0x80020170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_2;
    // 0x80020170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80020174: b           L_80020188
    // 0x80020178: nop

        goto L_80020188;
    // 0x80020178: nop

    // 0x8002017C: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
L_80020180:
    // 0x80020180: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80020184: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80020188:
    // 0x80020188: bne         $s1, $zero, L_8002012C
    if (ctx->r17 != 0) {
        // 0x8002018C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8002012C;
    }
    // 0x8002018C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80020190:
    // 0x80020190: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80020194: addiu       $s3, $s3, 0x7950
    ctx->r19 = ADD32(ctx->r19, 0X7950);
    // 0x80020198: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8002019C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800201A0: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800201A4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800201A8: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800201AC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800201B0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800201B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800201B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800201BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800201C0: jr          $ra
    // 0x800201C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800201C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800201C8: nop

    // 0x800201CC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800201d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800201d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800201D0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800201D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800201D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800201DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800201E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800201E4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800201E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800201EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800201F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800201F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800201F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800201FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020200: lui         $s6, 0x10
    ctx->r22 = S32(0X10 << 16);
    // 0x80020204: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80020208:
    // 0x80020208: bnel        $s0, $s6, L_80020208
    if (ctx->r16 != ctx->r22) {
        // 0x8002020C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80020208;
    }
    goto skip_0;
    // 0x8002020C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80020210: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80020214: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80020218: lui         $a2, 0x3
    ctx->r6 = S32(0X3 << 16);
    // 0x8002021C: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x80020220: addiu       $a1, $a1, 0x6AB0
    ctx->r5 = ADD32(ctx->r5, 0X6AB0);
    // 0x80020224: jal         0x800305D0
    // 0x80020228: addiu       $a0, $a0, 0x6A88
    ctx->r4 = ADD32(ctx->r4, 0X6A88);
    LOOKUP_FUNC(0x800305D0)(rdram, ctx);
        goto after_0;
    // 0x80020228: addiu       $a0, $a0, 0x6A88
    ctx->r4 = ADD32(ctx->r4, 0X6A88);
    after_0:
    // 0x8002022C: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80020230: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80020234: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80020238: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8002023C: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x80020240: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80020244: addiu       $s7, $s7, 0x1520
    ctx->r23 = ADD32(ctx->r23, 0X1520);
    // 0x80020248: addiu       $fp, $fp, 0x6AB0
    ctx->r30 = ADD32(ctx->r30, 0X6AB0);
    // 0x8002024C: addiu       $s2, $s2, 0x6A98
    ctx->r18 = ADD32(ctx->r18, 0X6A98);
    // 0x80020250: addiu       $s5, $s5, 0x7960
    ctx->r21 = ADD32(ctx->r21, 0X7960);
    // 0x80020254: addiu       $s4, $s4, 0x7978
    ctx->r20 = ADD32(ctx->r20, 0X7978);
    // 0x80020258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002025C:
    // 0x8002025C: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x80020260: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80020264: addu        $a1, $s7, $s3
    ctx->r5 = ADD32(ctx->r23, ctx->r19);
    // 0x80020268: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // 0x8002026C: subu        $s1, $t6, $a3
    ctx->r17 = SUB32(ctx->r14, ctx->r7);
    // 0x80020270: beq         $s1, $zero, L_800202C0
    if (ctx->r17 == 0) {
        // 0x80020274: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_800202C0;
    }
    // 0x80020274: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80020278: andi        $a0, $s1, 0x3
    ctx->r4 = ctx->r17 & 0X3;
    // 0x8002027C: beq         $a0, $zero, L_8002029C
    if (ctx->r4 == 0) {
        // 0x80020280: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8002029C;
    }
    // 0x80020280: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80020284: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
L_80020288:
    // 0x80020288: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002028C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80020290: bne         $v1, $s0, L_80020288
    if (ctx->r3 != ctx->r16) {
        // 0x80020294: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80020288;
    }
    // 0x80020294: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020298: beq         $s0, $s1, L_800202BC
    if (ctx->r16 == ctx->r17) {
        // 0x8002029C: addu        $v0, $a1, $s0
        ctx->r2 = ADD32(ctx->r5, ctx->r16);
            goto L_800202BC;
    }
L_8002029C:
    // 0x8002029C: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
L_800202A0:
    // 0x800202A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800202A4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800202A8: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800202AC: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800202B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800202B4: bne         $s0, $s1, L_800202A0
    if (ctx->r16 != ctx->r17) {
        // 0x800202B8: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800202A0;
    }
    // 0x800202B8: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
L_800202BC:
    // 0x800202BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800202C0:
    // 0x800202C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800202C4: jal         0x80001FE8
    // 0x800202C8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_1;
    // 0x800202C8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x800202CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800202D0: sltu        $at, $s2, $fp
    ctx->r1 = ctx->r18 < ctx->r30 ? 1 : 0;
    // 0x800202D4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800202D8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800202DC: bne         $at, $zero, L_8002025C
    if (ctx->r1 != 0) {
        // 0x800202E0: addu        $s3, $s3, $s1
        ctx->r19 = ADD32(ctx->r19, ctx->r17);
            goto L_8002025C;
    }
    // 0x800202E0: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
    // 0x800202E4: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x800202E8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800202EC: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800202F0: addiu       $s3, $s3, 0x79A8
    ctx->r19 = ADD32(ctx->r19, 0X79A8);
    // 0x800202F4: addiu       $s1, $s1, 0x7990
    ctx->r17 = ADD32(ctx->r17, 0X7990);
    // 0x800202F8: addiu       $s2, $s2, 0x6A98
    ctx->r18 = ADD32(ctx->r18, 0X6A98);
L_800202FC:
    // 0x800202FC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80020300: jal         0x80028694
    // 0x80020304: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x80028694)(rdram, ctx);
        goto after_2;
    // 0x80020304: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80020308: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002030C: bne         $s1, $s3, L_800202FC
    if (ctx->r17 != ctx->r19) {
        // 0x80020310: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800202FC;
    }
    // 0x80020310: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80020314: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80020318: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8002031C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80020320: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80020324: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80020328: addiu       $t0, $t0, 0x6A88
    ctx->r8 = ADD32(ctx->r8, 0X6A88);
    // 0x8002032C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80020330: addiu       $t2, $t2, 0x79C0
    ctx->r10 = ADD32(ctx->r10, 0X79C0);
    // 0x80020334: ori         $t3, $zero, 0xAC44
    ctx->r11 = 0 | 0XAC44;
    // 0x80020338: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002033C: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x80020340: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80020344: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x80020348: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x8002034C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x80020350: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x80020354: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x80020358: sb          $t1, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r9;
    // 0x8002035C: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x80020360: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x80020364: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x80020368: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8002036C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80020370: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80020374: jal         0x8001F8A0
    // 0x80020378: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    LOOKUP_FUNC(0x8001F8A0)(rdram, ctx);
        goto after_3;
    // 0x80020378: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_3:
    // 0x8002037C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80020380: jal         0x800203C4
    // 0x80020384: addiu       $a0, $a0, 0x6A70
    ctx->r4 = ADD32(ctx->r4, 0X6A70);
    LOOKUP_FUNC(0x800203C4)(rdram, ctx);
        goto after_4;
    // 0x80020384: addiu       $a0, $a0, 0x6A70
    ctx->r4 = ADD32(ctx->r4, 0X6A70);
    after_4:
    // 0x80020388: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8002038C:
    // 0x8002038C: bnel        $s0, $s6, L_8002038C
    if (ctx->r16 != ctx->r22) {
        // 0x80020390: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8002038C;
    }
    goto skip_1;
    // 0x80020390: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80020394: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80020398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002039C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800203A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800203A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800203A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800203AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800203B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800203B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800203B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800203BC: jr          $ra
    // 0x800203C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800203C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800203c4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800203c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800203C4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800203C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800203CC: sb          $t6, -0x4550($at)
    MEM_B(-0X4550, ctx->r1) = ctx->r14;
    // 0x800203D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800203D4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800203D8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800203DC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800203E0: addiu       $a3, $a3, -0x44DE
    ctx->r7 = ADD32(ctx->r7, -0X44DE);
    // 0x800203E4: addiu       $a2, $a2, -0x454B
    ctx->r6 = ADD32(ctx->r6, -0X454B);
    // 0x800203E8: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x800203EC: addiu       $v0, $v0, -0x44DF
    ctx->r2 = ADD32(ctx->r2, -0X44DF);
    // 0x800203F0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800203F4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800203F8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800203FC: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80020400: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80020404: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020408: andi        $t1, $zero, 0xFF
    ctx->r9 = 0 & 0XFF;
    // 0x8002040C: addiu       $t0, $t0, -0x454A
    ctx->r8 = ADD32(ctx->r8, -0X454A);
    // 0x80020410: sh          $t1, -0x454E($at)
    MEM_H(-0X454E, ctx->r1) = ctx->r9;
    // 0x80020414: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80020418: lb          $t2, 0x0($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X0);
    // 0x8002041C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020420: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020428: sb          $t2, -0x4549($at)
    MEM_B(-0X4549, ctx->r1) = ctx->r10;
    // 0x8002042C: lui         $t3, 0x8002
    ctx->r11 = S32(0X8002 << 16);
    // 0x80020430: addiu       $t3, $t3, 0x460
    ctx->r11 = ADD32(ctx->r11, 0X460);
    // 0x80020434: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80020438: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8002043C: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x80020440: sw          $a0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r4;
    // 0x80020444: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80020448: jal         0x80032A60
    // 0x8002044C: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    LOOKUP_FUNC(0x80032A60)(rdram, ctx);
        goto after_0;
    // 0x8002044C: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    after_0:
    // 0x80020450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020458: jr          $ra
    // 0x8002045C: nop

    return;
    // 0x8002045C: nop

;}
RECOMP_FUNC void FUN_80020460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020460: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020464: lbu         $v0, -0x4550($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4550);
    // 0x80020468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020470: beq         $v0, $zero, L_800204A4
    if (ctx->r2 == 0) {
        // 0x80020474: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_800204A4;
    }
    // 0x80020474: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80020478: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002047C: bnel        $v0, $at, L_80020498
    if (ctx->r2 != ctx->r1) {
        // 0x80020480: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80020498;
    }
    goto skip_0;
    // 0x80020480: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x80020484: jal         0x8002059C
    // 0x80020488: nop

    LOOKUP_FUNC(0x8002059C)(rdram, ctx);
        goto after_0;
    // 0x80020488: nop

    after_0:
    // 0x8002048C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020490: lbu         $v0, -0x4550($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4550);
    // 0x80020494: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
L_80020498:
    // 0x80020498: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002049C: b           L_80020588
    // 0x800204A0: sb          $t6, -0x4550($at)
    MEM_B(-0X4550, ctx->r1) = ctx->r14;
        goto L_80020588;
    // 0x800204A0: sb          $t6, -0x4550($at)
    MEM_B(-0X4550, ctx->r1) = ctx->r14;
L_800204A4:
    // 0x800204A4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800204A8: lhu         $t7, -0x44B4($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X44B4);
    // 0x800204AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800204B0: addiu       $v0, $v0, -0x4250
    ctx->r2 = ADD32(ctx->r2, -0X4250);
    // 0x800204B4: beq         $t7, $zero, L_800204CC
    if (ctx->r15 == 0) {
        // 0x800204B8: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_800204CC;
    }
    // 0x800204B8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800204BC: jal         0x80022044
    // 0x800204C0: nop

    LOOKUP_FUNC(0x80022044)(rdram, ctx);
        goto after_1;
    // 0x800204C0: nop

    after_1:
    // 0x800204C4: b           L_80020524
    // 0x800204C8: nop

        goto L_80020524;
    // 0x800204C8: nop

L_800204CC:
    // 0x800204CC: addiu       $a0, $a0, -0x424D
    ctx->r4 = ADD32(ctx->r4, -0X424D);
    // 0x800204D0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
L_800204D4:
    // 0x800204D4: beq         $v1, $zero, L_80020518
    if (ctx->r3 == 0) {
        // 0x800204D8: slti        $at, $v1, 0xF0
        ctx->r1 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
            goto L_80020518;
    }
    // 0x800204D8: slti        $at, $v1, 0xF0
    ctx->r1 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // 0x800204DC: beq         $at, $zero, L_800204FC
    if (ctx->r1 == 0) {
        // 0x800204E0: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800204FC;
    }
    // 0x800204E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800204E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800204E8: sw          $v1, -0x44B8($at)
    MEM_W(-0X44B8, ctx->r1) = ctx->r3;
    // 0x800204EC: jal         0x80021EB8
    // 0x800204F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80021EB8)(rdram, ctx);
        goto after_2;
    // 0x800204F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800204F4: b           L_80020510
    // 0x800204F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80020510;
    // 0x800204F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800204FC:
    // 0x800204FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80020500: andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // 0x80020504: jal         0x80022778
    // 0x80020508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80022778)(rdram, ctx);
        goto after_3;
    // 0x80020508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8002050C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80020510:
    // 0x80020510: b           L_80020524
    // 0x80020514: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80020524;
    // 0x80020514: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80020518:
    // 0x80020518: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002051C: bnel        $v0, $a0, L_800204D4
    if (ctx->r2 != ctx->r4) {
        // 0x80020520: lbu         $v1, 0x0($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X0);
            goto L_800204D4;
    }
    goto skip_1;
    // 0x80020520: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    skip_1:
L_80020524:
    // 0x80020524: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80020528: lbu         $t8, -0x424D($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X424D);
    // 0x8002052C: beq         $t8, $zero, L_8002053C
    if (ctx->r24 == 0) {
        // 0x80020530: nop
    
            goto L_8002053C;
    }
    // 0x80020530: nop

    // 0x80020534: jal         0x800211B4
    // 0x80020538: nop

    LOOKUP_FUNC(0x800211B4)(rdram, ctx);
        goto after_4;
    // 0x80020538: nop

    after_4:
L_8002053C:
    // 0x8002053C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80020540: lbu         $t9, -0x4230($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4230);
    // 0x80020544: beq         $t9, $zero, L_80020554
    if (ctx->r25 == 0) {
        // 0x80020548: nop
    
            goto L_80020554;
    }
    // 0x80020548: nop

    // 0x8002054C: jal         0x800213DC
    // 0x80020550: nop

    LOOKUP_FUNC(0x800213DC)(rdram, ctx);
        goto after_5;
    // 0x80020550: nop

    after_5:
L_80020554:
    // 0x80020554: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80020558: lbu         $t0, -0x454F($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X454F);
    // 0x8002055C: bne         $t0, $zero, L_8002056C
    if (ctx->r8 != 0) {
        // 0x80020560: nop
    
            goto L_8002056C;
    }
    // 0x80020560: nop

    // 0x80020564: jal         0x80020F60
    // 0x80020568: nop

    LOOKUP_FUNC(0x80020F60)(rdram, ctx);
        goto after_6;
    // 0x80020568: nop

    after_6:
L_8002056C:
    // 0x8002056C: jal         0x80022DC0
    // 0x80020570: nop

    LOOKUP_FUNC(0x80022DC0)(rdram, ctx);
        goto after_7;
    // 0x80020570: nop

    after_7:
    // 0x80020574: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020578: addiu       $v0, $v0, -0x454E
    ctx->r2 = ADD32(ctx->r2, -0X454E);
    // 0x8002057C: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80020580: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80020584: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_80020588:
    // 0x80020588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002058C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020590: addiu       $v0, $zero, 0x1388
    ctx->r2 = ADD32(0, 0X1388);
    // 0x80020594: jr          $ra
    // 0x80020598: nop

    return;
    // 0x80020598: nop

;}
RECOMP_FUNC void FUN_8002059c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002059C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800205A0: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800205A4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800205A8: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800205AC: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800205B0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800205B4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800205B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800205BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800205C0: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800205C4: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800205C8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800205CC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800205D0: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x800205D4: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x800205D8: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x800205DC: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x800205E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800205E4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800205E8: addiu       $s7, $s7, 0x62A0
    ctx->r23 = ADD32(ctx->r23, 0X62A0);
    // 0x800205EC: addiu       $s5, $s5, 0x6A98
    ctx->r21 = ADD32(ctx->r21, 0X6A98);
    // 0x800205F0: addiu       $s3, $s3, -0x6710
    ctx->r19 = ADD32(ctx->r19, -0X6710);
    // 0x800205F4: addiu       $s2, $s2, 0x5520
    ctx->r18 = ADD32(ctx->r18, 0X5520);
    // 0x800205F8: addiu       $s1, $s1, -0x4420
    ctx->r17 = ADD32(ctx->r17, -0X4420);
    // 0x800205FC: addiu       $s0, $s0, -0x425C
    ctx->r16 = ADD32(ctx->r16, -0X425C);
    // 0x80020600: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x80020604: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80020608:
    // 0x80020608: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002060C: sh          $t6, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r14;
    // 0x80020610: sh          $zero, 0x72($sp)
    MEM_H(0X72, ctx->r29) = 0;
    // 0x80020614: sb          $zero, 0x74($sp)
    MEM_B(0X74, ctx->r29) = 0;
    // 0x80020618: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8002061C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80020620: jal         0x800288C8
    // 0x80020624: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800288C8)(rdram, ctx);
        goto after_0;
    // 0x80020624: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x80020628: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x8002062C: sb          $zero, 0xD($s2)
    MEM_B(0XD, ctx->r18) = 0;
    // 0x80020630: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80020634: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80020638: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002063C: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x80020640: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x80020644: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80020648: lbu         $t9, 0xC($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XC);
    // 0x8002064C: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x80020650: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80020654: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80020658: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002065C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80020660: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x80020664: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80020668: lw          $t1, 0xC($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XC);
    // 0x8002066C: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80020670: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80020674: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x80020678: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x8002067C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80020680: swc1        $f20, 0xB0($t3)
    MEM_W(0XB0, ctx->r11) = ctx->f20.u32l;
    // 0x80020684: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80020688: sh          $zero, 0xB4($t4)
    MEM_H(0XB4, ctx->r12) = 0;
    // 0x8002068C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80020690: sh          $zero, 0xB6($t5)
    MEM_H(0XB6, ctx->r13) = 0;
    // 0x80020694: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80020698: sb          $s6, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r22;
    // 0x8002069C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800206A0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800206A4: lw          $a2, 0x14($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X14);
    // 0x800206A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800206AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800206B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800206B4: jal         0x80033D20
    // 0x800206B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x80033D20)(rdram, ctx);
        goto after_1;
    // 0x800206B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800206BC: addiu       $s2, $s2, 0xD8
    ctx->r18 = ADD32(ctx->r18, 0XD8);
    // 0x800206C0: bne         $s2, $s7, L_80020608
    if (ctx->r18 != ctx->r23) {
        // 0x800206C4: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_80020608;
    }
    // 0x800206C4: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800206C8: jal         0x80022528
    // 0x800206CC: nop

    LOOKUP_FUNC(0x80022528)(rdram, ctx);
        goto after_2;
    // 0x800206CC: nop

    after_2:
    // 0x800206D0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800206D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800206D8: jal         0x80030930
    // 0x800206DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80030930)(rdram, ctx);
        goto after_3;
    // 0x800206DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800206E0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800206E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800206E8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800206EC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800206F0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800206F4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800206F8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800206FC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80020700: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80020704: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80020708: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8002070C: sw          $v0, -0x41F8($at)
    MEM_W(-0X41F8, ctx->r1) = ctx->r2;
    // 0x80020710: jr          $ra
    // 0x80020714: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80020714: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80020718(rdram, ctx);
;}
RECOMP_FUNC void FUN_80020718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020724: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002072C: jal         0x800207D0
    // 0x80020730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_0;
    // 0x80020730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80020734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002073C: jr          $ra
    // 0x80020740: nop

    return;
    // 0x80020740: nop

;}
RECOMP_FUNC void FUN_80020744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002074C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020750: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020758: jal         0x800207D0
    // 0x8002075C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_0;
    // 0x8002075C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80020760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020768: jr          $ra
    // 0x8002076C: nop

    return;
    // 0x8002076C: nop

;}
RECOMP_FUNC void FUN_80020770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002077C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020780: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80020784: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020788: jal         0x800207D0
    // 0x8002078C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_0;
    // 0x8002078C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80020790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020798: jr          $ra
    // 0x8002079C: nop

    return;
    // 0x8002079C: nop

;}
RECOMP_FUNC void FUN_800207a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800207A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800207A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800207A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800207AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800207B0: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x800207B4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800207B8: jal         0x800207D0
    // 0x800207BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_0;
    // 0x800207BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800207C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800207C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800207C8: jr          $ra
    // 0x800207CC: nop

    return;
    // 0x800207CC: nop

;}
RECOMP_FUNC void FUN_800207d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800207D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800207D4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800207D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800207DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800207E0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800207E4: beq         $a0, $zero, L_800208BC
    if (ctx->r4 == 0) {
        // 0x800207E8: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_800208BC;
    }
    // 0x800207E8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800207EC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800207F0: addiu       $t1, $t1, -0x454F
    ctx->r9 = ADD32(ctx->r9, -0X454F);
    // 0x800207F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800207F8: beq         $a1, $zero, L_8002080C
    if (ctx->r5 == 0) {
        // 0x800207FC: sb          $t6, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r14;
            goto L_8002080C;
    }
    // 0x800207FC: sb          $t6, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r14;
    // 0x80020800: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80020804: bne         $at, $zero, L_80020814
    if (ctx->r1 != 0) {
        // 0x80020808: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80020814;
    }
    // 0x80020808: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002080C:
    // 0x8002080C: b           L_8002081C
    // 0x80020810: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_8002081C;
    // 0x80020810: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80020814:
    // 0x80020814: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80020818: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
L_8002081C:
    // 0x8002081C: beq         $a2, $zero, L_8002082C
    if (ctx->r6 == 0) {
        // 0x80020820: lui         $t2, 0x800D
        ctx->r10 = S32(0X800D << 16);
            goto L_8002082C;
    }
    // 0x80020820: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80020824: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x80020828: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
L_8002082C:
    // 0x8002082C: addiu       $t2, $t2, -0x44DE
    ctx->r10 = ADD32(ctx->r10, -0X44DE);
    // 0x80020830: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x80020834: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80020838: beq         $at, $zero, L_800208B8
    if (ctx->r1 == 0) {
        // 0x8002083C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800208B8;
    }
    // 0x8002083C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80020840: beql        $v0, $zero, L_80020888
    if (ctx->r2 == 0) {
        // 0x80020844: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_80020888;
    }
    goto skip_0;
    // 0x80020844: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    skip_0:
    // 0x80020848: blez        $a1, L_80020884
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002084C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80020884;
    }
    // 0x8002084C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020850: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80020854: addiu       $t0, $t0, -0x44D8
    ctx->r8 = ADD32(ctx->r8, -0X44D8);
    // 0x80020858: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8002085C:
    // 0x8002085C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80020860: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80020864: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80020868: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x8002086C: bne         $a3, $t3, L_8002087C
    if (ctx->r7 != ctx->r11) {
        // 0x80020870: nop
    
            goto L_8002087C;
    }
    // 0x80020870: nop

    // 0x80020874: jr          $ra
    // 0x80020878: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    return;
    // 0x80020878: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_8002087C:
    // 0x8002087C: bne         $at, $zero, L_8002085C
    if (ctx->r1 != 0) {
        // 0x80020880: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8002085C;
    }
    // 0x80020880: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80020884:
    // 0x80020884: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
L_80020888:
    // 0x80020888: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002088C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80020890: sw          $v1, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->r3;
    // 0x80020894: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80020898: slti        $at, $a0, 0x607
    ctx->r1 = SIGNED(ctx->r4) < 0X607 ? 1 : 0;
    // 0x8002089C: bne         $at, $zero, L_800208B8
    if (ctx->r1 != 0) {
        // 0x800208A0: sb          $t5, 0x0($t2)
        MEM_B(0X0, ctx->r10) = ctx->r13;
            goto L_800208B8;
    }
    // 0x800208A0: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x800208A4: slti        $at, $a0, 0x634
    ctx->r1 = SIGNED(ctx->r4) < 0X634 ? 1 : 0;
    // 0x800208A8: beq         $at, $zero, L_800208B8
    if (ctx->r1 == 0) {
        // 0x800208AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800208B8;
    }
    // 0x800208AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800208B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800208B4: sb          $t6, -0x4428($at)
    MEM_B(-0X4428, ctx->r1) = ctx->r14;
L_800208B8:
    // 0x800208B8: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_800208BC:
    // 0x800208BC: jr          $ra
    // 0x800208C0: nop

    return;
    // 0x800208C0: nop

;}
RECOMP_FUNC void FUN_800208c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800208C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800208C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800208CC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800208D0: beq         $a0, $zero, L_8002095C
    if (ctx->r4 == 0) {
        // 0x800208D4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002095C;
    }
    // 0x800208D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800208D8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800208DC: addiu       $a3, $a3, -0x454F
    ctx->r7 = ADD32(ctx->r7, -0X454F);
    // 0x800208E0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800208E4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800208E8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800208EC: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x800208F0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800208F4: lbu         $v0, 0x3032($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3032);
    // 0x800208F8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800208FC: addiu       $v1, $v1, -0x4258
    ctx->r3 = ADD32(ctx->r3, -0X4258);
    // 0x80020900: beq         $v0, $zero, L_80020928
    if (ctx->r2 == 0) {
        // 0x80020904: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80020928;
    }
    // 0x80020904: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020908: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002090C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80020910: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x80020914: sb          $a0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r4;
    // 0x80020918: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002091C: sb          $a0, -0x4254($at)
    MEM_B(-0X4254, ctx->r1) = ctx->r4;
    // 0x80020920: b           L_8002095C
    // 0x80020924: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
        goto L_8002095C;
    // 0x80020924: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_80020928:
    // 0x80020928: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002092C: addiu       $v1, $v1, -0x4258
    ctx->r3 = ADD32(ctx->r3, -0X4258);
    // 0x80020930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020934:
    // 0x80020934: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80020938: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002093C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80020940: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80020944: bne         $at, $zero, L_80020934
    if (ctx->r1 != 0) {
        // 0x80020948: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_80020934;
    }
    // 0x80020948: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8002094C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80020950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020954: jal         0x800207D0
    // 0x80020958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_0;
    // 0x80020958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8002095C:
    // 0x8002095C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020964: jr          $ra
    // 0x80020968: nop

    return;
    // 0x80020968: nop

;}
RECOMP_FUNC void FUN_8002096c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002096C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80020970: addiu       $a3, $a3, -0x44E0
    ctx->r7 = ADD32(ctx->r7, -0X44E0);
    // 0x80020974: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80020978: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002097C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80020980: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020984: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80020988: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002098C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80020990: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020994: beq         $at, $zero, L_800209DC
    if (ctx->r1 == 0) {
        // 0x80020998: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_800209DC;
    }
    // 0x80020998: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8002099C: beq         $a0, $zero, L_800209DC
    if (ctx->r4 == 0) {
        // 0x800209A0: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_800209DC;
    }
    // 0x800209A0: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800209A4: beq         $at, $zero, L_800209DC
    if (ctx->r1 == 0) {
        // 0x800209A8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800209DC;
    }
    // 0x800209A8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800209AC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800209B0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800209B4: addiu       $t7, $t7, -0x4510
    ctx->r15 = ADD32(ctx->r15, -0X4510);
    // 0x800209B8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800209BC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800209C0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800209C4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800209C8: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    // 0x800209CC: sb          $a1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r5;
    // 0x800209D0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x800209D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800209D8: sb          $zero, -0x454F($at)
    MEM_B(-0X454F, ctx->r1) = 0;
L_800209DC:
    // 0x800209DC: jr          $ra
    // 0x800209E0: nop

    return;
    // 0x800209E0: nop

;}
RECOMP_FUNC void FUN_800209e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800209E4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800209E8: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x800209EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800209F0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800209F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800209F8: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800209FC: lbu         $v1, 0xB8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB8);
    // 0x80020A00: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80020A04: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x80020A08: beq         $v1, $zero, L_80020A64
    if (ctx->r3 == 0) {
        // 0x80020A0C: subu        $t1, $t1, $a2
        ctx->r9 = SUB32(ctx->r9, ctx->r6);
            goto L_80020A64;
    }
    // 0x80020A0C: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x80020A10: bne         $a1, $zero, L_80020A24
    if (ctx->r5 != 0) {
        // 0x80020A14: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_80020A24;
    }
    // 0x80020A14: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80020A18: lb          $a0, 0xBB($v0)
    ctx->r4 = MEM_B(ctx->r2, 0XBB);
    // 0x80020A1C: b           L_80020A28
    // 0x80020A20: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
        goto L_80020A28;
    // 0x80020A20: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
L_80020A24:
    // 0x80020A24: lb          $a0, 0xBB($v0)
    ctx->r4 = MEM_B(ctx->r2, 0XBB);
L_80020A28:
    // 0x80020A28: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80020A2C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80020A30: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80020A34: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80020A38: lh          $t8, -0x450E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X450E);
    // 0x80020A3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80020A40: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020A44: mflo        $t9
    ctx->r25 = lo;
    // 0x80020A48: nop

    // 0x80020A4C: nop

    // 0x80020A50: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80020A54: mflo        $t0
    ctx->r8 = lo;
    // 0x80020A58: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
    // 0x80020A5C: jr          $ra
    // 0x80020A60: nop

    return;
    // 0x80020A60: nop

L_80020A64:
    // 0x80020A64: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80020A68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020A6C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80020A70: lh          $v0, -0x450E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X450E);
    // 0x80020A74: jr          $ra
    // 0x80020A78: nop

    return;
    // 0x80020A78: nop

;}
RECOMP_FUNC void FUN_80020a7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80020A80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80020A84: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80020A88: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80020A8C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80020A90: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80020A94: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80020A98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80020A9C: addiu       $t7, $t7, -0x4510
    ctx->r15 = ADD32(ctx->r15, -0X4510);
    // 0x80020AA0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80020AA4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80020AA8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80020AAC: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x80020AB0: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80020AB4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80020AB8: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80020ABC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80020AC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80020AC4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80020AC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80020ACC: lbu         $s3, 0x4($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X4);
    // 0x80020AD0: addiu       $s5, $s5, 0x62A0
    ctx->r21 = ADD32(ctx->r21, 0X62A0);
    // 0x80020AD4: addiu       $s2, $s2, -0x425C
    ctx->r18 = ADD32(ctx->r18, -0X425C);
    // 0x80020AD8: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x80020ADC: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80020AE0:
    // 0x80020AE0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80020AE4: lhu         $t1, 0x0($s6)
    ctx->r9 = MEM_HU(ctx->r22, 0X0);
    // 0x80020AE8: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x80020AEC: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x80020AF0: bne         $t0, $t1, L_80020B60
    if (ctx->r8 != ctx->r9) {
        // 0x80020AF4: andi        $a1, $s3, 0xFF
        ctx->r5 = ctx->r19 & 0XFF;
            goto L_80020B60;
    }
    // 0x80020AF4: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80020AF8: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80020AFC: addiu       $t3, $t3, 0x7E00
    ctx->r11 = ADD32(ctx->r11, 0X7E00);
    // 0x80020B00: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80020B04: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80020B08: jal         0x800209E4
    // 0x80020B0C: sll         $s4, $s3, 1
    ctx->r20 = S32(ctx->r19 << 1);
    LOOKUP_FUNC(0x800209E4)(rdram, ctx);
        goto after_0;
    // 0x80020B0C: sll         $s4, $s3, 1
    ctx->r20 = S32(ctx->r19 << 1);
    after_0:
    // 0x80020B10: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80020B14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020B18: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80020B1C: beql        $at, $zero, L_80020B30
    if (ctx->r1 == 0) {
        // 0x80020B20: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_80020B30;
    }
    goto skip_0;
    // 0x80020B20: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x80020B24: b           L_80020B40
    // 0x80020B28: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80020B40;
    // 0x80020B28: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80020B2C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80020B30:
    // 0x80020B30: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80020B34: beql        $at, $zero, L_80020B44
    if (ctx->r1 == 0) {
        // 0x80020B38: lw          $t4, 0x0($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X0);
            goto L_80020B44;
    }
    goto skip_1;
    // 0x80020B38: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x80020B3C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80020B40:
    // 0x80020B40: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_80020B44:
    // 0x80020B44: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x80020B48: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80020B4C: addu        $v0, $t4, $s4
    ctx->r2 = ADD32(ctx->r12, ctx->r20);
    // 0x80020B50: lh          $t7, 0xA2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA2);
    // 0x80020B54: beql        $t6, $t7, L_80020B64
    if (ctx->r14 == ctx->r15) {
        // 0x80020B58: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_80020B64;
    }
    goto skip_2;
    // 0x80020B58: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
    skip_2:
    // 0x80020B5C: sh          $v1, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = ctx->r3;
L_80020B60:
    // 0x80020B60: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
L_80020B64:
    // 0x80020B64: bnel        $s1, $s5, L_80020AE0
    if (ctx->r17 != ctx->r21) {
        // 0x80020B68: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80020AE0;
    }
    goto skip_3;
    // 0x80020B68: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_3:
    // 0x80020B6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80020B70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80020B74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80020B78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80020B7C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80020B80: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80020B84: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80020B88: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80020B8C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80020B90: jr          $ra
    // 0x80020B94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80020B94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80020B98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80020B9C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80020BA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020BA4: slti        $at, $a1, 0x15
    ctx->r1 = SIGNED(ctx->r5) < 0X15 ? 1 : 0;
    // 0x80020BA8: bne         $at, $zero, L_80020BB4
    if (ctx->r1 != 0) {
        // 0x80020BAC: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_80020BB4;
    }
    // 0x80020BAC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80020BB0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80020BB4:
    // 0x80020BB4: bgtz        $a0, L_80020BD0
    if (SIGNED(ctx->r4) > 0) {
        // 0x80020BB8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_80020BD0;
    }
    // 0x80020BB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020BBC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020BC0: addiu       $v0, $v0, -0x4530
    ctx->r2 = ADD32(ctx->r2, -0X4530);
    // 0x80020BC4: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x80020BC8: jr          $ra
    // 0x80020BCC: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    return;
    // 0x80020BCC: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
L_80020BD0:
    // 0x80020BD0: addiu       $v0, $v0, -0x4530
    ctx->r2 = ADD32(ctx->r2, -0X4530);
    // 0x80020BD4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80020BD8: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x80020BDC: jr          $ra
    // 0x80020BE0: nop

    return;
    // 0x80020BE0: nop

    // 0x80020BE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020BE8: addiu       $v0, $v0, -0x4530
    ctx->r2 = ADD32(ctx->r2, -0X4530);
    // 0x80020BEC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80020BF0: jr          $ra
    // 0x80020BF4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x80020BF4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80020bf8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80020bf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020C04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020C08: jal         0x80020C20
    // 0x80020C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80020C20)(rdram, ctx);
        goto after_0;
    // 0x80020C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80020C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020C18: jr          $ra
    // 0x80020C1C: nop

    return;
    // 0x80020C1C: nop

;}
RECOMP_FUNC void FUN_80020c20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020C24: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80020C28: slti        $at, $a0, 0x300
    ctx->r1 = SIGNED(ctx->r4) < 0X300 ? 1 : 0;
    // 0x80020C2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80020C30: bne         $at, $zero, L_80020D24
    if (ctx->r1 != 0) {
        // 0x80020C34: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80020D24;
    }
    // 0x80020C34: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80020C38: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80020C3C: addiu       $t1, $t1, -0x454F
    ctx->r9 = ADD32(ctx->r9, -0X454F);
    // 0x80020C40: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80020C44: sb          $t6, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r14;
    // 0x80020C48: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80020C4C: lbu         $t7, -0x4470($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4470);
    // 0x80020C50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80020C54: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x80020C58: beq         $at, $zero, L_80020D20
    if (ctx->r1 == 0) {
        // 0x80020C5C: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80020D20;
    }
    // 0x80020C5C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80020C60: bne         $at, $zero, L_80020CCC
    if (ctx->r1 != 0) {
        // 0x80020C64: or          $t0, $t7, $zero
        ctx->r8 = ctx->r15 | 0;
            goto L_80020CCC;
    }
    // 0x80020C64: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x80020C68: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80020C6C: lbu         $a2, -0x446F($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X446F);
    // 0x80020C70: blez        $t7, L_80020CCC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80020C74: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80020CCC;
    }
    // 0x80020C74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020C78: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80020C7C: addiu       $t2, $t2, -0x4468
    ctx->r10 = ADD32(ctx->r10, -0X4468);
    // 0x80020C80: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
L_80020C84:
    // 0x80020C84: addu        $a1, $t2, $t8
    ctx->r5 = ADD32(ctx->r10, ctx->r24);
    // 0x80020C88: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x80020C8C: bnel        $v0, $t9, L_80020CA4
    if (ctx->r2 != ctx->r25) {
        // 0x80020C90: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020CA4;
    }
    goto skip_0;
    // 0x80020C90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80020C94: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80020C98: b           L_80020CCC
    // 0x80020C9C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
        goto L_80020CCC;
    // 0x80020C9C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80020CA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80020CA4:
    // 0x80020CA4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80020CA8: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80020CAC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80020CB0: bne         $at, $zero, L_80020CBC
    if (ctx->r1 != 0) {
        // 0x80020CB4: lbu         $a1, -0x4470($a1)
        ctx->r5 = MEM_BU(ctx->r5, -0X4470);
            goto L_80020CBC;
    }
    // 0x80020CB4: lbu         $a1, -0x4470($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X4470);
    // 0x80020CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80020CBC:
    // 0x80020CBC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80020CC0: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80020CC4: bnel        $at, $zero, L_80020C84
    if (ctx->r1 != 0) {
        // 0x80020CC8: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80020C84;
    }
    goto skip_1;
    // 0x80020CC8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    skip_1:
L_80020CCC:
    // 0x80020CCC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80020CD0: lbu         $t3, -0x446F($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X446F);
    // 0x80020CD4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80020CD8: addiu       $t2, $t2, -0x4468
    ctx->r10 = ADD32(ctx->r10, -0X4468);
    // 0x80020CDC: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    // 0x80020CE0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80020CE4: bne         $at, $zero, L_80020CF0
    if (ctx->r1 != 0) {
        // 0x80020CE8: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_80020CF0;
    }
    // 0x80020CE8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80020CEC: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
L_80020CF0:
    // 0x80020CF0: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x80020CF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020CF8: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80020CFC: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x80020D00: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x80020D04: mflo        $t6
    ctx->r14 = lo;
    // 0x80020D08: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x80020D0C: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    // 0x80020D10: lbu         $t7, -0x4470($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4470);
    // 0x80020D14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020D18: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80020D1C: sb          $t8, -0x4470($at)
    MEM_B(-0X4470, ctx->r1) = ctx->r24;
L_80020D20:
    // 0x80020D20: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_80020D24:
    // 0x80020D24: jr          $ra
    // 0x80020D28: nop

    return;
    // 0x80020D28: nop

    // 0x80020D2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020D30: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80020D34: jr          $ra
    // 0x80020D38: sb          $zero, -0x4470($at)
    MEM_B(-0X4470, ctx->r1) = 0;
    return;
    // 0x80020D38: sb          $zero, -0x4470($at)
    MEM_B(-0X4470, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80020d3c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80020d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80020D40: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80020D44: jr          $ra
    // 0x80020D48: lbu         $v0, -0x4470($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4470);
    return;
    // 0x80020D48: lbu         $v0, -0x4470($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4470);
    // 0x80020D4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80020D50: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80020D54: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80020D58: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80020D5C: lbu         $t6, -0x4470($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4470);
    // 0x80020D60: lbu         $t7, -0x4428($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4428);
    // 0x80020D64: jr          $ra
    // 0x80020D68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x80020D68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80020D6C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80020D70: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80020D74: lhu         $t7, -0x453E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X453E);
    // 0x80020D78: lhu         $t6, -0x4542($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4542);
    // 0x80020D7C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80020D80: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80020D84: bne         $v1, $zero, L_80020DA4
    if (ctx->r3 != 0) {
        // 0x80020D88: nop
    
            goto L_80020DA4;
    }
    // 0x80020D88: nop

    // 0x80020D8C: lw          $v0, 0x5520($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5520);
    // 0x80020D90: beq         $v0, $zero, L_80020DA4
    if (ctx->r2 == 0) {
        // 0x80020D94: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_80020DA4;
    }
    // 0x80020D94: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80020D98: beq         $at, $zero, L_80020DA4
    if (ctx->r1 == 0) {
        // 0x80020D9C: nop
    
            goto L_80020DA4;
    }
    // 0x80020D9C: nop

    // 0x80020DA0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80020DA4:
    // 0x80020DA4: jr          $ra
    // 0x80020DA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020DA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80020dac(rdram, ctx);
;}
RECOMP_FUNC void FUN_80020dac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020DAC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80020DB0: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80020DB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020DB8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80020DBC: addiu       $v0, $v0, 0x62A0
    ctx->r2 = ADD32(ctx->r2, 0X62A0);
    // 0x80020DC0: addiu       $a2, $a2, 0x5520
    ctx->r6 = ADD32(ctx->r6, 0X5520);
    // 0x80020DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80020DC8:
    // 0x80020DC8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80020DCC: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x80020DD0: bne         $v1, $t7, L_80020DF8
    if (ctx->r3 != ctx->r15) {
        // 0x80020DD4: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_80020DF8;
    }
    // 0x80020DD4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80020DD8: lw          $t8, -0x425C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X425C);
    // 0x80020DDC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80020DE0: lh          $v0, 0xB4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0XB4);
    // 0x80020DE4: bne         $v0, $zero, L_80020DF0
    if (ctx->r2 != 0) {
        // 0x80020DE8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80020DF0;
    }
    // 0x80020DE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020DEC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80020DF0:
    // 0x80020DF0: jr          $ra
    // 0x80020DF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020DF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020DF8:
    // 0x80020DF8: lw          $t0, 0xD8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XD8);
    // 0x80020DFC: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80020E00: bne         $v1, $t1, L_80020E28
    if (ctx->r3 != ctx->r9) {
        // 0x80020E04: lui         $t2, 0x800D
        ctx->r10 = S32(0X800D << 16);
            goto L_80020E28;
    }
    // 0x80020E04: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80020E08: lw          $t2, -0x425C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X425C);
    // 0x80020E0C: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x80020E10: lh          $v1, 0x18C($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X18C);
    // 0x80020E14: bne         $v1, $zero, L_80020E20
    if (ctx->r3 != 0) {
        // 0x80020E18: nop
    
            goto L_80020E20;
    }
    // 0x80020E18: nop

    // 0x80020E1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80020E20:
    // 0x80020E20: jr          $ra
    // 0x80020E24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020E24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020E28:
    // 0x80020E28: lw          $t4, 0x1B0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X1B0);
    // 0x80020E2C: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x80020E30: bne         $v1, $t5, L_80020E58
    if (ctx->r3 != ctx->r13) {
        // 0x80020E34: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_80020E58;
    }
    // 0x80020E34: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80020E38: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x80020E3C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80020E40: lh          $v1, 0x264($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X264);
    // 0x80020E44: bne         $v1, $zero, L_80020E50
    if (ctx->r3 != 0) {
        // 0x80020E48: nop
    
            goto L_80020E50;
    }
    // 0x80020E48: nop

    // 0x80020E4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80020E50:
    // 0x80020E50: jr          $ra
    // 0x80020E54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020E54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020E58:
    // 0x80020E58: lw          $t8, 0x288($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X288);
    // 0x80020E5C: addiu       $a2, $a2, 0x360
    ctx->r6 = ADD32(ctx->r6, 0X360);
    // 0x80020E60: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x80020E64: bne         $v1, $t9, L_80020E8C
    if (ctx->r3 != ctx->r25) {
        // 0x80020E68: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_80020E8C;
    }
    // 0x80020E68: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80020E6C: lw          $t0, -0x425C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X425C);
    // 0x80020E70: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x80020E74: lh          $v1, 0x33C($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X33C);
    // 0x80020E78: bne         $v1, $zero, L_80020E84
    if (ctx->r3 != 0) {
        // 0x80020E7C: nop
    
            goto L_80020E84;
    }
    // 0x80020E7C: nop

    // 0x80020E80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80020E84:
    // 0x80020E84: jr          $ra
    // 0x80020E88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020E88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020E8C:
    // 0x80020E8C: bne         $a2, $v0, L_80020DC8
    if (ctx->r6 != ctx->r2) {
        // 0x80020E90: addiu       $a1, $a1, 0x360
        ctx->r5 = ADD32(ctx->r5, 0X360);
            goto L_80020DC8;
    }
    // 0x80020E90: addiu       $a1, $a1, 0x360
    ctx->r5 = ADD32(ctx->r5, 0X360);
    // 0x80020E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020E98: jr          $ra
    // 0x80020E9C: nop

    return;
    // 0x80020E9C: nop

;}
RECOMP_FUNC void FUN_80020ea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EA0: bne         $a0, $zero, L_80020EBC
    if (ctx->r4 != 0) {
        // 0x80020EA4: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_80020EBC;
    }
    // 0x80020EA4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80020EA8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80020EAC: lw          $v0, 0x5520($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5520);
    // 0x80020EB0: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80020EB4: jr          $ra
    // 0x80020EB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80020EB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80020EBC:
    // 0x80020EBC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80020EC0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80020EC4: lbu         $v1, -0x4254($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4254);
    // 0x80020EC8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80020ECC: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80020ED0: bne         $v1, $zero, L_80020EE0
    if (ctx->r3 != 0) {
        // 0x80020ED4: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80020EE0;
    }
    // 0x80020ED4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80020ED8: jr          $ra
    // 0x80020EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80020EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020EE0:
    // 0x80020EE0: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80020EE4: addiu       $v0, $v0, 0x62A0
    ctx->r2 = ADD32(ctx->r2, 0X62A0);
    // 0x80020EE8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_80020EEC:
    // 0x80020EEC: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x80020EF0: bnel        $t7, $a1, L_80020F04
    if (ctx->r15 != ctx->r5) {
        // 0x80020EF4: lw          $t8, 0xD8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XD8);
            goto L_80020F04;
    }
    goto skip_0;
    // 0x80020EF4: lw          $t8, 0xD8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XD8);
    skip_0:
    // 0x80020EF8: jr          $ra
    // 0x80020EFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020EFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80020F00: lw          $t8, 0xD8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XD8);
L_80020F04:
    // 0x80020F04: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x80020F08: bnel        $t9, $a1, L_80020F1C
    if (ctx->r25 != ctx->r5) {
        // 0x80020F0C: lw          $t0, 0x1B0($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1B0);
            goto L_80020F1C;
    }
    goto skip_1;
    // 0x80020F0C: lw          $t0, 0x1B0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1B0);
    skip_1:
    // 0x80020F10: jr          $ra
    // 0x80020F14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020F14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80020F18: lw          $t0, 0x1B0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1B0);
L_80020F1C:
    // 0x80020F1C: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80020F20: bnel        $t1, $a1, L_80020F34
    if (ctx->r9 != ctx->r5) {
        // 0x80020F24: lw          $t2, 0x288($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X288);
            goto L_80020F34;
    }
    goto skip_2;
    // 0x80020F24: lw          $t2, 0x288($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X288);
    skip_2:
    // 0x80020F28: jr          $ra
    // 0x80020F2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020F2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80020F30: lw          $t2, 0x288($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X288);
L_80020F34:
    // 0x80020F34: addiu       $a0, $a0, 0x360
    ctx->r4 = ADD32(ctx->r4, 0X360);
    // 0x80020F38: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x80020F3C: bne         $t3, $a1, L_80020F4C
    if (ctx->r11 != ctx->r5) {
        // 0x80020F40: nop
    
            goto L_80020F4C;
    }
    // 0x80020F40: nop

    // 0x80020F44: jr          $ra
    // 0x80020F48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80020F48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020F4C:
    // 0x80020F4C: bnel        $a0, $v0, L_80020EEC
    if (ctx->r4 != ctx->r2) {
        // 0x80020F50: lw          $t6, 0x0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X0);
            goto L_80020EEC;
    }
    goto skip_3;
    // 0x80020F50: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x80020F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020F58: jr          $ra
    // 0x80020F5C: nop

    return;
    // 0x80020F5C: nop

;}
RECOMP_FUNC void FUN_80020f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80020F64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80020F68: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80020F6C: addiu       $s2, $s2, -0x44DE
    ctx->r18 = ADD32(ctx->r18, -0X44DE);
    // 0x80020F70: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x80020F74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80020F78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80020F7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80020F80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80020F84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80020F88: beq         $a0, $zero, L_80021038
    if (ctx->r4 == 0) {
        // 0x80020F8C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80021038;
    }
    // 0x80020F8C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80020F90: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80020F94: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80020F98: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80020F9C: addiu       $s1, $s1, -0x44B8
    ctx->r17 = ADD32(ctx->r17, -0X44B8);
    // 0x80020FA0: addiu       $s3, $s3, 0x7E0C
    ctx->r19 = ADD32(ctx->r19, 0X7E0C);
    // 0x80020FA4: addiu       $s0, $s0, -0x44D8
    ctx->r16 = ADD32(ctx->r16, -0X44D8);
    // 0x80020FA8: ori         $s4, $zero, 0x8000
    ctx->r20 = 0 | 0X8000;
    // 0x80020FAC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80020FB0:
    // 0x80020FB0: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x80020FB4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80020FB8: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80020FBC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80020FC0: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80020FC4: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    // 0x80020FC8: beq         $at, $zero, L_80021004
    if (ctx->r1 == 0) {
        // 0x80020FCC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80021004;
    }
    // 0x80020FCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80020FD0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80020FD4: beq         $at, $zero, L_80020FF4
    if (ctx->r1 == 0) {
        // 0x80020FD8: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80020FF4;
    }
    // 0x80020FD8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80020FDC: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80020FE0: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80020FE4: jalr        $t9
    // 0x80020FE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80020FE8: nop

    after_0:
    // 0x80020FEC: b           L_8002102C
    // 0x80020FF0: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
        goto L_8002102C;
    // 0x80020FF0: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
L_80020FF4:
    // 0x80020FF4: jal         0x80021EB8
    // 0x80020FF8: nop

    LOOKUP_FUNC(0x80021EB8)(rdram, ctx);
        goto after_1;
    // 0x80020FF8: nop

    after_1:
    // 0x80020FFC: b           L_8002102C
    // 0x80021000: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
        goto L_8002102C;
    // 0x80021000: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
L_80021004:
    // 0x80021004: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80021008: beq         $at, $zero, L_80021020
    if (ctx->r1 == 0) {
        // 0x8002100C: nop
    
            goto L_80021020;
    }
    // 0x8002100C: nop

    // 0x80021010: jal         0x80021968
    // 0x80021014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80021968)(rdram, ctx);
        goto after_2;
    // 0x80021014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80021018: b           L_8002102C
    // 0x8002101C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
        goto L_8002102C;
    // 0x8002101C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
L_80021020:
    // 0x80021020: jal         0x80022C8C
    // 0x80021024: nop

    LOOKUP_FUNC(0x80022C8C)(rdram, ctx);
        goto after_3;
    // 0x80021024: nop

    after_3:
    // 0x80021028: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
L_8002102C:
    // 0x8002102C: bnel        $a0, $zero, L_80020FB0
    if (ctx->r4 != 0) {
        // 0x80021030: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80020FB0;
    }
    goto skip_0;
    // 0x80021030: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80021034: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80021038:
    // 0x80021038: jal         0x80021094
    // 0x8002103C: nop

    LOOKUP_FUNC(0x80021094)(rdram, ctx);
        goto after_4;
    // 0x8002103C: nop

    after_4:
    // 0x80021040: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80021044: addiu       $s0, $s0, -0x44E0
    ctx->r16 = ADD32(ctx->r16, -0X44E0);
    // 0x80021048: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8002104C: beql        $t0, $zero, L_80021078
    if (ctx->r8 == 0) {
        // 0x80021050: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80021078;
    }
    goto skip_1;
    // 0x80021050: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_80021054:
    // 0x80021054: jal         0x80020A7C
    // 0x80021058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80020A7C)(rdram, ctx);
        goto after_5;
    // 0x80021058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8002105C: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80021060: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80021064: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80021068: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8002106C: bne         $t3, $zero, L_80021054
    if (ctx->r11 != 0) {
        // 0x80021070: sb          $t2, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r10;
            goto L_80021054;
    }
    // 0x80021070: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x80021074: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80021078:
    // 0x80021078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002107C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021080: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021084: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80021088: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002108C: jr          $ra
    // 0x80021090: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80021090: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80021094(rdram, ctx);
;}
RECOMP_FUNC void FUN_80021094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021094: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80021098: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002109C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800210A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800210A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800210A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800210AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800210B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800210B4: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800210B8: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800210BC: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800210C0: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800210C4: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x800210C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800210CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800210D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800210D4: addiu       $fp, $fp, -0x44B8
    ctx->r30 = ADD32(ctx->r30, -0X44B8);
    // 0x800210D8: addiu       $s6, $s6, -0x446F
    ctx->r22 = ADD32(ctx->r22, -0X446F);
    // 0x800210DC: addiu       $s5, $s5, -0x4468
    ctx->r21 = ADD32(ctx->r21, -0X4468);
    // 0x800210E0: addiu       $s4, $s4, -0x4470
    ctx->r20 = ADD32(ctx->r20, -0X4470);
    // 0x800210E4: addiu       $s3, $s3, -0x4428
    ctx->r19 = ADD32(ctx->r19, -0X4428);
    // 0x800210E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800210EC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800210F0:
    // 0x800210F0: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x800210F4: addu        $s2, $s4, $s1
    ctx->r18 = ADD32(ctx->r20, ctx->r17);
    // 0x800210F8: bnel        $t6, $zero, L_8002117C
    if (ctx->r14 != 0) {
        // 0x800210FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002117C;
    }
    goto skip_0;
    // 0x800210FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80021100: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80021104: addu        $s0, $s6, $s1
    ctx->r16 = ADD32(ctx->r22, ctx->r17);
    // 0x80021108: beql        $v0, $zero, L_8002117C
    if (ctx->r2 == 0) {
        // 0x8002110C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002117C;
    }
    goto skip_1;
    // 0x8002110C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80021110: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80021114: sll         $t7, $s1, 6
    ctx->r15 = S32(ctx->r17 << 6);
    // 0x80021118: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8002111C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80021120: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80021124: lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2);
    // 0x80021128: beq         $a1, $zero, L_80021138
    if (ctx->r5 == 0) {
        // 0x8002112C: addiu       $t0, $a1, -0x1
        ctx->r8 = ADD32(ctx->r5, -0X1);
            goto L_80021138;
    }
    // 0x8002112C: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x80021130: b           L_80021178
    // 0x80021134: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
        goto L_80021178;
    // 0x80021134: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
L_80021138:
    // 0x80021138: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x8002113C: beql        $a1, $zero, L_8002115C
    if (ctx->r5 == 0) {
        // 0x80021140: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_8002115C;
    }
    goto skip_2;
    // 0x80021140: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x80021144: sw          $a1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r5;
    // 0x80021148: jal         0x80021968
    // 0x8002114C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80021968)(rdram, ctx);
        goto after_0;
    // 0x8002114C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80021150: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80021154: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80021158: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_8002115C:
    // 0x8002115C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80021160: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80021164: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80021168: sb          $t1, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r9;
    // 0x8002116C: bne         $at, $zero, L_80021178
    if (ctx->r1 != 0) {
        // 0x80021170: sb          $t2, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r10;
            goto L_80021178;
    }
    // 0x80021170: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x80021174: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80021178:
    // 0x80021178: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8002117C:
    // 0x8002117C: bne         $s1, $s7, L_800210F0
    if (ctx->r17 != ctx->r23) {
        // 0x80021180: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800210F0;
    }
    // 0x80021180: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80021184: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80021188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002118C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021190: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021194: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80021198: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002119C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800211A0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800211A4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800211A8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800211AC: jr          $ra
    // 0x800211B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800211B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800211b4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800211b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800211B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800211B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800211BC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800211C0: addiu       $s2, $s2, -0x424D
    ctx->r18 = ADD32(ctx->r18, -0X424D);
    // 0x800211C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800211C8: lbu         $ra, 0x0($s2)
    ctx->r31 = MEM_BU(ctx->r18, 0X0);
    // 0x800211CC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800211D0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800211D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800211D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800211DC: beq         $ra, $zero, L_800213B8
    if (ctx->r31 == 0) {
        // 0x800211E0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800213B8;
    }
    // 0x800211E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800211E4: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800211E8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800211EC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800211F0: addiu       $s1, $s1, -0x4528
    ctx->r17 = ADD32(ctx->r17, -0X4528);
    // 0x800211F4: addiu       $s3, $s3, -0x44B8
    ctx->r19 = ADD32(ctx->r19, -0X44B8);
    // 0x800211F8: addiu       $s4, $s4, -0x4248
    ctx->r20 = ADD32(ctx->r20, -0X4248);
    // 0x800211FC: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x80021200: addiu       $t6, $ra, -0x1
    ctx->r14 = ADD32(ctx->r31, -0X1);
L_80021204:
    // 0x80021204: andi        $ra, $t6, 0xFF
    ctx->r31 = ctx->r14 & 0XFF;
    // 0x80021208: multu       $ra, $s5
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002120C: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    // 0x80021210: mflo        $t7
    ctx->r15 = lo;
    // 0x80021214: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x80021218: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
    // 0x8002121C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80021220: sra         $v0, $t4, 3
    ctx->r2 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80021224: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80021228: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002122C: sra         $a2, $v0, 3
    ctx->r6 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80021230: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80021234: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80021238: sra         $t5, $a2, 3
    ctx->r13 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002123C: sll         $t5, $t5, 16
    ctx->r13 = S32(ctx->r13 << 16);
    // 0x80021240: lbu         $t1, 0x2($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X2);
    // 0x80021244: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80021248: andi        $t0, $v0, 0x3FFF
    ctx->r8 = ctx->r2 & 0X3FFF;
    // 0x8002124C: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x80021250: andi        $t5, $t5, 0x7F
    ctx->r13 = ctx->r13 & 0X7F;
    // 0x80021254: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80021258: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8002125C: sll         $a1, $t5, 16
    ctx->r5 = S32(ctx->r13 << 16);
    // 0x80021260: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80021264: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80021268: beq         $t1, $zero, L_800212B0
    if (ctx->r9 == 0) {
        // 0x8002126C: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_800212B0;
    }
    // 0x8002126C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80021270: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80021274: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80021278: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002127C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80021280: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80021284: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80021288: beql        $at, $zero, L_800212B8
    if (ctx->r1 == 0) {
        // 0x8002128C: lbu         $a2, 0x3($t3)
        ctx->r6 = MEM_BU(ctx->r11, 0X3);
            goto L_800212B8;
    }
    goto skip_0;
    // 0x8002128C: lbu         $a2, 0x3($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X3);
    skip_0:
    // 0x80021290: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
L_80021294:
    // 0x80021294: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80021298: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002129C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800212A0: bnel        $at, $zero, L_80021294
    if (ctx->r1 != 0) {
        // 0x800212A4: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80021294;
    }
    goto skip_1;
    // 0x800212A4: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    skip_1:
    // 0x800212A8: b           L_800212B8
    // 0x800212AC: lbu         $a2, 0x3($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X3);
        goto L_800212B8;
    // 0x800212AC: lbu         $a2, 0x3($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X3);
L_800212B0:
    // 0x800212B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800212B4: lbu         $a2, 0x3($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X3);
L_800212B8:
    // 0x800212B8: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x800212BC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800212C0: beq         $a2, $zero, L_800212F0
    if (ctx->r6 == 0) {
        // 0x800212C4: slt         $at, $a2, $t7
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_800212F0;
    }
    // 0x800212C4: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800212C8: beq         $at, $zero, L_800212F4
    if (ctx->r1 == 0) {
        // 0x800212CC: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800212F4;
    }
    // 0x800212CC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800212D0: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
L_800212D4:
    // 0x800212D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800212D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800212DC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800212E0: bnel        $at, $zero, L_800212D4
    if (ctx->r1 != 0) {
        // 0x800212E4: sra         $a0, $a0, 1
        ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800212D4;
    }
    goto skip_2;
    // 0x800212E4: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    skip_2:
    // 0x800212E8: b           L_800212F8
    // 0x800212EC: lbu         $a2, 0x4($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X4);
        goto L_800212F8;
    // 0x800212EC: lbu         $a2, 0x4($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X4);
L_800212F0:
    // 0x800212F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800212F4:
    // 0x800212F4: lbu         $a2, 0x4($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X4);
L_800212F8:
    // 0x800212F8: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x800212FC: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80021300: beq         $a2, $zero, L_80021338
    if (ctx->r6 == 0) {
        // 0x80021304: andi        $t7, $t4, 0x2
        ctx->r15 = ctx->r12 & 0X2;
            goto L_80021338;
    }
    // 0x80021304: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80021308: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002130C: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80021310: beq         $at, $zero, L_8002133C
    if (ctx->r1 == 0) {
        // 0x80021314: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8002133C;
    }
    // 0x80021314: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80021318: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
L_8002131C:
    // 0x8002131C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80021320: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80021324: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80021328: bnel        $at, $zero, L_8002131C
    if (ctx->r1 != 0) {
        // 0x8002132C: sra         $a1, $a1, 1
        ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8002131C;
    }
    goto skip_3;
    // 0x8002132C: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    skip_3:
    // 0x80021330: b           L_8002133C
    // 0x80021334: nop

        goto L_8002133C;
    // 0x80021334: nop

L_80021338:
    // 0x80021338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8002133C:
    // 0x8002133C: beq         $t6, $zero, L_80021350
    if (ctx->r14 == 0) {
        // 0x80021340: andi        $t8, $t4, 0x4
        ctx->r24 = ctx->r12 & 0X4;
            goto L_80021350;
    }
    // 0x80021340: andi        $t8, $t4, 0x4
    ctx->r24 = ctx->r12 & 0X4;
    // 0x80021344: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80021348: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8002134C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80021350:
    // 0x80021350: beq         $t7, $zero, L_80021364
    if (ctx->r15 == 0) {
        // 0x80021354: nop
    
            goto L_80021364;
    }
    // 0x80021354: nop

    // 0x80021358: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8002135C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80021360: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_80021364:
    // 0x80021364: beql        $t8, $zero, L_8002137C
    if (ctx->r24 == 0) {
        // 0x80021368: lhu         $t9, 0x8($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X8);
            goto L_8002137C;
    }
    goto skip_4;
    // 0x80021368: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
    skip_4:
    // 0x8002136C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80021370: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80021374: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80021378: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
L_8002137C:
    // 0x8002137C: lhu         $t7, 0x0($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X0);
    // 0x80021380: sh          $v1, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r3;
    // 0x80021384: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80021388: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002138C: andi        $t6, $t8, 0x7FFF
    ctx->r14 = ctx->r24 & 0X7FFF;
    // 0x80021390: sltiu       $at, $t6, 0x100
    ctx->r1 = ctx->r14 < 0X100 ? 1 : 0;
    // 0x80021394: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80021398: sh          $a0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r4;
    // 0x8002139C: bne         $at, $zero, L_800213B0
    if (ctx->r1 != 0) {
        // 0x800213A0: sh          $a1, 0x10($s1)
        MEM_H(0X10, ctx->r17) = ctx->r5;
            goto L_800213B0;
    }
    // 0x800213A0: sh          $a1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r5;
    // 0x800213A4: jal         0x80021968
    // 0x800213A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80021968)(rdram, ctx);
        goto after_0;
    // 0x800213A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800213AC: lbu         $ra, 0x0($s2)
    ctx->r31 = MEM_BU(ctx->r18, 0X0);
L_800213B0:
    // 0x800213B0: bnel        $ra, $zero, L_80021204
    if (ctx->r31 != 0) {
        // 0x800213B4: addiu       $t6, $ra, -0x1
        ctx->r14 = ADD32(ctx->r31, -0X1);
            goto L_80021204;
    }
    goto skip_5;
    // 0x800213B4: addiu       $t6, $ra, -0x1
    ctx->r14 = ADD32(ctx->r31, -0X1);
    skip_5:
L_800213B8:
    // 0x800213B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800213BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800213C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800213C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800213C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800213CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800213D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800213D4: jr          $ra
    // 0x800213D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800213D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800213dc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800213dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800213DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800213E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800213E4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800213E8: addiu       $s0, $s0, -0x4230
    ctx->r16 = ADD32(ctx->r16, -0X4230);
    // 0x800213EC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800213F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800213F4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800213F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800213FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021400: beq         $v0, $zero, L_800214F8
    if (ctx->r2 == 0) {
        // 0x80021404: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800214F8;
    }
    // 0x80021404: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021408: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8002140C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80021410: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80021414: addiu       $s1, $s1, -0x4228
    ctx->r17 = ADD32(ctx->r17, -0X4228);
    // 0x80021418: addiu       $s3, $s3, -0x44B8
    ctx->r19 = ADD32(ctx->r19, -0X44B8);
    // 0x8002141C: addiu       $s4, $s4, 0x7E0C
    ctx->r20 = ADD32(ctx->r20, 0X7E0C);
    // 0x80021420: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x80021424: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
L_80021428:
    // 0x80021428: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x8002142C: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021430: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80021434: mflo        $t7
    ctx->r15 = lo;
    // 0x80021438: addu        $v1, $s1, $t7
    ctx->r3 = ADD32(ctx->r17, ctx->r15);
    // 0x8002143C: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80021440: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80021444: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80021448: beq         $at, $zero, L_800214F0
    if (ctx->r1 == 0) {
        // 0x8002144C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800214F0;
    }
    // 0x8002144C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80021450: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80021454: addu        $at, $at, $t8
    gpr jr_addend_8002145C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80021458: lw          $t8, -0x2E00($at)
    ctx->r24 = ADD32(ctx->r1, -0X2E00);
    // 0x8002145C: jr          $t8
    // 0x80021460: nop

    switch (jr_addend_8002145C >> 2) {
        case 0: goto L_80021464; break;
        case 1: goto L_800214B4; break;
        case 2: goto L_800214C4; break;
        case 3: goto L_800214D4; break;
        case 4: goto L_800214E4; break;
        default: switch_error(__func__, 0x8002145C, 0x8004D200);
    }
    // 0x80021460: nop

L_80021464:
    // 0x80021464: sltiu       $at, $a1, 0x100
    ctx->r1 = ctx->r5 < 0X100 ? 1 : 0;
    // 0x80021468: beq         $at, $zero, L_800214A4
    if (ctx->r1 == 0) {
        // 0x8002146C: sw          $a1, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r5;
            goto L_800214A4;
    }
    // 0x8002146C: sw          $a1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r5;
    // 0x80021470: sltiu       $at, $a1, 0x10
    ctx->r1 = ctx->r5 < 0X10 ? 1 : 0;
    // 0x80021474: beq         $at, $zero, L_80021494
    if (ctx->r1 == 0) {
        // 0x80021478: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80021494;
    }
    // 0x80021478: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8002147C: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x80021480: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x80021484: jalr        $t9
    // 0x80021488: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80021488: nop

    after_0:
    // 0x8002148C: b           L_800214AC
    // 0x80021490: nop

        goto L_800214AC;
    // 0x80021490: nop

L_80021494:
    // 0x80021494: jal         0x80021EB8
    // 0x80021498: nop

    LOOKUP_FUNC(0x80021EB8)(rdram, ctx);
        goto after_1;
    // 0x80021498: nop

    after_1:
    // 0x8002149C: b           L_800214AC
    // 0x800214A0: nop

        goto L_800214AC;
    // 0x800214A0: nop

L_800214A4:
    // 0x800214A4: jal         0x80021968
    // 0x800214A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80021968)(rdram, ctx);
        goto after_2;
    // 0x800214A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_800214AC:
    // 0x800214AC: b           L_800214F0
    // 0x800214B0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_800214F0;
    // 0x800214B0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800214B4:
    // 0x800214B4: jal         0x80021518
    // 0x800214B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80021518)(rdram, ctx);
        goto after_3;
    // 0x800214B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800214BC: b           L_800214F0
    // 0x800214C0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_800214F0;
    // 0x800214C0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800214C4:
    // 0x800214C4: jal         0x80021824
    // 0x800214C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80021824)(rdram, ctx);
        goto after_4;
    // 0x800214C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800214CC: b           L_800214F0
    // 0x800214D0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_800214F0;
    // 0x800214D0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800214D4:
    // 0x800214D4: jal         0x80021824
    // 0x800214D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80021824)(rdram, ctx);
        goto after_5;
    // 0x800214D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800214DC: b           L_800214F0
    // 0x800214E0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_800214F0;
    // 0x800214E0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800214E4:
    // 0x800214E4: jal         0x80021824
    // 0x800214E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80021824)(rdram, ctx);
        goto after_6;
    // 0x800214E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x800214EC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800214F0:
    // 0x800214F0: bnel        $v0, $zero, L_80021428
    if (ctx->r2 != 0) {
        // 0x800214F4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80021428;
    }
    goto skip_0;
    // 0x800214F4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    skip_0:
L_800214F8:
    // 0x800214F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800214FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021500: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021504: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021508: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002150C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80021510: jr          $ra
    // 0x80021514: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80021514: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80021518(rdram, ctx);
;}
RECOMP_FUNC void FUN_80021518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021518: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8002151C: addiu       $t0, $t0, -0x4230
    ctx->r8 = ADD32(ctx->r8, -0X4230);
    // 0x80021520: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80021524: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80021528: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002152C: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021530: addiu       $a3, $a3, -0x4228
    ctx->r7 = ADD32(ctx->r7, -0X4228);
    // 0x80021534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021538: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002153C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021540: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80021544: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80021548: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002154C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80021550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80021554: mflo        $t7
    ctx->r15 = lo;
    // 0x80021558: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8002155C: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x80021560: addiu       $t2, $t2, 0x5520
    ctx->r10 = ADD32(ctx->r10, 0X5520);
    // 0x80021564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80021568: beq         $t9, $zero, L_800217A8
    if (ctx->r25 == 0) {
        // 0x8002156C: lui         $t3, 0x801B
        ctx->r11 = S32(0X801B << 16);
            goto L_800217A8;
    }
    // 0x8002156C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80021570: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80021574: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80021578: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8002157C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80021580: addiu       $v1, $v1, -0x425C
    ctx->r3 = ADD32(ctx->r3, -0X425C);
    // 0x80021584: addiu       $t5, $t5, 0x6888
    ctx->r13 = ADD32(ctx->r13, 0X6888);
    // 0x80021588: addiu       $a2, $a2, 0x57A8
    ctx->r6 = ADD32(ctx->r6, 0X57A8);
    // 0x8002158C: addiu       $t4, $t4, 0x56D0
    ctx->r12 = ADD32(ctx->r12, 0X56D0);
    // 0x80021590: addiu       $t3, $t3, 0x55F8
    ctx->r11 = ADD32(ctx->r11, 0X55F8);
    // 0x80021594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80021598: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8002159C:
    // 0x8002159C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800215A0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800215A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800215A8: addiu       $t2, $t2, 0x360
    ctx->r10 = ADD32(ctx->r10, 0X360);
    // 0x800215AC: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x800215B0: bnel        $s2, $t7, L_80021620
    if (ctx->r18 != ctx->r15) {
        // 0x800215B4: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_80021620;
    }
    goto skip_0;
    // 0x800215B4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    skip_0:
    // 0x800215B8: sb          $a0, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r4;
    // 0x800215BC: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x800215C0: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800215C4: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800215C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800215CC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800215D0: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x800215D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800215D8: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x800215DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800215E0: sb          $t9, 0xBF($t6)
    MEM_B(0XBF, ctx->r14) = ctx->r25;
    // 0x800215E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800215E8: bne         $t7, $zero, L_800215F4
    if (ctx->r15 != 0) {
        // 0x800215EC: nop
    
            goto L_800215F4;
    }
    // 0x800215EC: nop

    // 0x800215F0: break       7
    do_break(2147620336);
L_800215F4:
    // 0x800215F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800215F8: bne         $t7, $at, L_8002160C
    if (ctx->r15 != ctx->r1) {
        // 0x800215FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002160C;
    }
    // 0x800215FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021600: bne         $t8, $at, L_8002160C
    if (ctx->r24 != ctx->r1) {
        // 0x80021604: nop
    
            goto L_8002160C;
    }
    // 0x80021604: nop

    // 0x80021608: break       6
    do_break(2147620360);
L_8002160C:
    // 0x8002160C: lbu         $t8, 0xBF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XBF);
    // 0x80021610: bnel        $t8, $zero, L_80021620
    if (ctx->r24 != 0) {
        // 0x80021614: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_80021620;
    }
    goto skip_1;
    // 0x80021614: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    skip_1:
    // 0x80021618: sb          $a1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r5;
    // 0x8002161C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80021620:
    // 0x80021620: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80021624: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80021628: addiu       $t3, $t3, 0x360
    ctx->r11 = ADD32(ctx->r11, 0X360);
    // 0x8002162C: andi        $t9, $t7, 0x7FFF
    ctx->r25 = ctx->r15 & 0X7FFF;
    // 0x80021630: bnel        $s2, $t9, L_800216A0
    if (ctx->r18 != ctx->r25) {
        // 0x80021634: sw          $t4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r12;
            goto L_800216A0;
    }
    goto skip_2;
    // 0x80021634: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    skip_2:
    // 0x80021638: sb          $a0, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r4;
    // 0x8002163C: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80021640: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021644: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80021648: mflo        $t8
    ctx->r24 = lo;
    // 0x8002164C: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80021650: lbu         $t9, 0x3($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X3);
    // 0x80021654: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80021658: div         $zero, $t6, $t9
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r25)));
    // 0x8002165C: mflo        $t8
    ctx->r24 = lo;
    // 0x80021660: sb          $t8, 0xBF($t7)
    MEM_B(0XBF, ctx->r15) = ctx->r24;
    // 0x80021664: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80021668: bne         $t9, $zero, L_80021674
    if (ctx->r25 != 0) {
        // 0x8002166C: nop
    
            goto L_80021674;
    }
    // 0x8002166C: nop

    // 0x80021670: break       7
    do_break(2147620464);
L_80021674:
    // 0x80021674: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021678: bne         $t9, $at, L_8002168C
    if (ctx->r25 != ctx->r1) {
        // 0x8002167C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002168C;
    }
    // 0x8002167C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021680: bne         $t6, $at, L_8002168C
    if (ctx->r14 != ctx->r1) {
        // 0x80021684: nop
    
            goto L_8002168C;
    }
    // 0x80021684: nop

    // 0x80021688: break       6
    do_break(2147620488);
L_8002168C:
    // 0x8002168C: lbu         $t6, 0xBF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XBF);
    // 0x80021690: bnel        $t6, $zero, L_800216A0
    if (ctx->r14 != 0) {
        // 0x80021694: sw          $t4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r12;
            goto L_800216A0;
    }
    goto skip_3;
    // 0x80021694: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    skip_3:
    // 0x80021698: sb          $a1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r5;
    // 0x8002169C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800216A0:
    // 0x800216A0: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800216A4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800216A8: andi        $t8, $t9, 0x7FFF
    ctx->r24 = ctx->r25 & 0X7FFF;
    // 0x800216AC: bnel        $s2, $t8, L_8002171C
    if (ctx->r18 != ctx->r24) {
        // 0x800216B0: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_8002171C;
    }
    goto skip_4;
    // 0x800216B0: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    skip_4:
    // 0x800216B4: sb          $a0, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r4;
    // 0x800216B8: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800216BC: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800216C0: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800216C4: mflo        $t6
    ctx->r14 = lo;
    // 0x800216C8: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800216CC: lbu         $t8, 0x3($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X3);
    // 0x800216D0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800216D4: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x800216D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800216DC: sb          $t6, 0xBF($t9)
    MEM_B(0XBF, ctx->r25) = ctx->r14;
    // 0x800216E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800216E4: bne         $t8, $zero, L_800216F0
    if (ctx->r24 != 0) {
        // 0x800216E8: nop
    
            goto L_800216F0;
    }
    // 0x800216E8: nop

    // 0x800216EC: break       7
    do_break(2147620588);
L_800216F0:
    // 0x800216F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800216F4: bne         $t8, $at, L_80021708
    if (ctx->r24 != ctx->r1) {
        // 0x800216F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021708;
    }
    // 0x800216F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800216FC: bne         $t7, $at, L_80021708
    if (ctx->r15 != ctx->r1) {
        // 0x80021700: nop
    
            goto L_80021708;
    }
    // 0x80021700: nop

    // 0x80021704: break       6
    do_break(2147620612);
L_80021708:
    // 0x80021708: lbu         $t7, 0xBF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XBF);
    // 0x8002170C: bnel        $t7, $zero, L_8002171C
    if (ctx->r15 != 0) {
        // 0x80021710: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_8002171C;
    }
    goto skip_5;
    // 0x80021710: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    skip_5:
    // 0x80021714: sb          $a1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r5;
    // 0x80021718: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_8002171C:
    // 0x8002171C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80021720: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80021724: addiu       $a2, $a2, 0x360
    ctx->r6 = ADD32(ctx->r6, 0X360);
    // 0x80021728: andi        $t6, $t8, 0x7FFF
    ctx->r14 = ctx->r24 & 0X7FFF;
    // 0x8002172C: bne         $s2, $t6, L_80021798
    if (ctx->r18 != ctx->r14) {
        // 0x80021730: nop
    
            goto L_80021798;
    }
    // 0x80021730: nop

    // 0x80021734: sb          $a0, 0xBE($v0)
    MEM_B(0XBE, ctx->r2) = ctx->r4;
    // 0x80021738: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8002173C: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021740: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80021744: mflo        $t7
    ctx->r15 = lo;
    // 0x80021748: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8002174C: lbu         $t6, 0x3($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X3);
    // 0x80021750: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80021754: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x80021758: mflo        $t7
    ctx->r15 = lo;
    // 0x8002175C: sb          $t7, 0xBF($t8)
    MEM_B(0XBF, ctx->r24) = ctx->r15;
    // 0x80021760: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80021764: bne         $t6, $zero, L_80021770
    if (ctx->r14 != 0) {
        // 0x80021768: nop
    
            goto L_80021770;
    }
    // 0x80021768: nop

    // 0x8002176C: break       7
    do_break(2147620716);
L_80021770:
    // 0x80021770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021774: bne         $t6, $at, L_80021788
    if (ctx->r14 != ctx->r1) {
        // 0x80021778: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021788;
    }
    // 0x80021778: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002177C: bne         $t9, $at, L_80021788
    if (ctx->r25 != ctx->r1) {
        // 0x80021780: nop
    
            goto L_80021788;
    }
    // 0x80021780: nop

    // 0x80021784: break       6
    do_break(2147620740);
L_80021788:
    // 0x80021788: lbu         $t9, 0xBF($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XBF);
    // 0x8002178C: bne         $t9, $zero, L_80021798
    if (ctx->r25 != 0) {
        // 0x80021790: nop
    
            goto L_80021798;
    }
    // 0x80021790: nop

    // 0x80021794: sb          $a1, 0xBF($v0)
    MEM_B(0XBF, ctx->r2) = ctx->r5;
L_80021798:
    // 0x80021798: bne         $a2, $t5, L_8002159C
    if (ctx->r6 != ctx->r13) {
        // 0x8002179C: addiu       $t4, $t4, 0x360
        ctx->r12 = ADD32(ctx->r12, 0X360);
            goto L_8002159C;
    }
    // 0x8002179C: addiu       $t4, $t4, 0x360
    ctx->r12 = ADD32(ctx->r12, 0X360);
    // 0x800217A0: b           L_8002180C
    // 0x800217A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8002180C;
    // 0x800217A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800217A8:
    // 0x800217A8: sltiu       $at, $s2, 0x100
    ctx->r1 = ctx->r18 < 0X100 ? 1 : 0;
    // 0x800217AC: beq         $at, $zero, L_800217D8
    if (ctx->r1 == 0) {
        // 0x800217B0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800217D8;
    }
    // 0x800217B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800217B4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800217B8: lw          $t6, 0x5520($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5520);
    // 0x800217BC: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x800217C0: bnel        $s2, $t7, L_8002180C
    if (ctx->r18 != ctx->r15) {
        // 0x800217C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002180C;
    }
    goto skip_6;
    // 0x800217C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x800217C8: jal         0x80022694
    // 0x800217CC: nop

    LOOKUP_FUNC(0x80022694)(rdram, ctx);
        goto after_0;
    // 0x800217CC: nop

    after_0:
    // 0x800217D0: b           L_8002180C
    // 0x800217D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8002180C;
    // 0x800217D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800217D8:
    // 0x800217D8: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x800217DC: addiu       $s0, $s0, 0x5520
    ctx->r16 = ADD32(ctx->r16, 0X5520);
    // 0x800217E0: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
L_800217E4:
    // 0x800217E4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800217E8: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800217EC: bnel        $s2, $t9, L_80021800
    if (ctx->r18 != ctx->r25) {
        // 0x800217F0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80021800;
    }
    goto skip_7;
    // 0x800217F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800217F4: jal         0x80022874
    // 0x800217F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80022874)(rdram, ctx);
        goto after_1;
    // 0x800217F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800217FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80021800:
    // 0x80021800: bne         $s1, $s3, L_800217E4
    if (ctx->r17 != ctx->r19) {
        // 0x80021804: addiu       $s0, $s0, 0xD8
        ctx->r16 = ADD32(ctx->r16, 0XD8);
            goto L_800217E4;
    }
    // 0x80021804: addiu       $s0, $s0, 0xD8
    ctx->r16 = ADD32(ctx->r16, 0XD8);
    // 0x80021808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002180C:
    // 0x8002180C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80021810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80021814: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80021818: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002181C: jr          $ra
    // 0x80021820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80021820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80021824(rdram, ctx);
;}
RECOMP_FUNC void FUN_80021824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021824: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80021828: lbu         $t6, -0x4230($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4230);
    // 0x8002182C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80021830: addiu       $t8, $t8, -0x4228
    ctx->r24 = ADD32(ctx->r24, -0X4228);
    // 0x80021834: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80021838: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8002183C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80021840: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80021844: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80021848: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8002184C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80021850: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80021854: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80021858: lh          $a2, 0x4($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X4);
    // 0x8002185C: addiu       $t4, $t4, -0x425C
    ctx->r12 = ADD32(ctx->r12, -0X425C);
    // 0x80021860: addiu       $t5, $t5, 0x6378
    ctx->r13 = ADD32(ctx->r13, 0X6378);
    // 0x80021864: addiu       $t3, $t3, 0x55F8
    ctx->r11 = ADD32(ctx->r11, 0X55F8);
    // 0x80021868: addiu       $t0, $t0, 0x5520
    ctx->r8 = ADD32(ctx->r8, 0X5520);
L_8002186C:
    // 0x8002186C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x80021870: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80021874: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80021878: sll         $a3, $a0, 1
    ctx->r7 = S32(ctx->r4 << 1);
    // 0x8002187C: andi        $t6, $t9, 0x7FFF
    ctx->r14 = ctx->r25 & 0X7FFF;
    // 0x80021880: bne         $a1, $t6, L_800218E0
    if (ctx->r5 != ctx->r14) {
        // 0x80021884: addu        $t7, $v1, $a3
        ctx->r15 = ADD32(ctx->r3, ctx->r7);
            goto L_800218E0;
    }
    // 0x80021884: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80021888: lh          $t1, 0xC6($t7)
    ctx->r9 = MEM_H(ctx->r15, 0XC6);
    // 0x8002188C: beq         $a2, $t1, L_800218E0
    if (ctx->r6 == ctx->r9) {
        // 0x80021890: subu        $t2, $a2, $t1
        ctx->r10 = SUB32(ctx->r6, ctx->r9);
            goto L_800218E0;
    }
    // 0x80021890: subu        $t2, $a2, $t1
    ctx->r10 = SUB32(ctx->r6, ctx->r9);
    // 0x80021894: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x80021898: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x8002189C: sb          $v0, 0xD2($t8)
    MEM_B(0XD2, ctx->r24) = ctx->r2;
    // 0x800218A0: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800218A4: bne         $v0, $zero, L_800218B0
    if (ctx->r2 != 0) {
        // 0x800218A8: nop
    
            goto L_800218B0;
    }
    // 0x800218A8: nop

    // 0x800218AC: break       7
    do_break(2147621036);
L_800218B0:
    // 0x800218B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800218B4: bne         $v0, $at, L_800218C8
    if (ctx->r2 != ctx->r1) {
        // 0x800218B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800218C8;
    }
    // 0x800218B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800218BC: bne         $t2, $at, L_800218C8
    if (ctx->r10 != ctx->r1) {
        // 0x800218C0: nop
    
            goto L_800218C8;
    }
    // 0x800218C0: nop

    // 0x800218C4: break       6
    do_break(2147621060);
L_800218C8:
    // 0x800218C8: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x800218CC: sh          $a2, 0xC0($t6)
    MEM_H(0XC0, ctx->r14) = ctx->r6;
    // 0x800218D0: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800218D4: mflo        $t2
    ctx->r10 = lo;
    // 0x800218D8: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800218DC: sh          $t2, 0xCC($t8)
    MEM_H(0XCC, ctx->r24) = ctx->r10;
L_800218E0:
    // 0x800218E0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800218E4: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800218E8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800218EC: addiu       $t3, $t3, 0x1B0
    ctx->r11 = ADD32(ctx->r11, 0X1B0);
    // 0x800218F0: andi        $t6, $t9, 0x7FFF
    ctx->r14 = ctx->r25 & 0X7FFF;
    // 0x800218F4: bne         $a1, $t6, L_80021958
    if (ctx->r5 != ctx->r14) {
        // 0x800218F8: sll         $a3, $a0, 1
        ctx->r7 = S32(ctx->r4 << 1);
            goto L_80021958;
    }
    // 0x800218F8: sll         $a3, $a0, 1
    ctx->r7 = S32(ctx->r4 << 1);
    // 0x800218FC: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80021900: lh          $t1, 0xC6($t7)
    ctx->r9 = MEM_H(ctx->r15, 0XC6);
    // 0x80021904: beq         $a2, $t1, L_80021958
    if (ctx->r6 == ctx->r9) {
        // 0x80021908: subu        $t2, $a2, $t1
        ctx->r10 = SUB32(ctx->r6, ctx->r9);
            goto L_80021958;
    }
    // 0x80021908: subu        $t2, $a2, $t1
    ctx->r10 = SUB32(ctx->r6, ctx->r9);
    // 0x8002190C: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x80021910: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x80021914: sb          $v0, 0xD2($t8)
    MEM_B(0XD2, ctx->r24) = ctx->r2;
    // 0x80021918: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8002191C: bne         $v0, $zero, L_80021928
    if (ctx->r2 != 0) {
        // 0x80021920: nop
    
            goto L_80021928;
    }
    // 0x80021920: nop

    // 0x80021924: break       7
    do_break(2147621156);
L_80021928:
    // 0x80021928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002192C: bne         $v0, $at, L_80021940
    if (ctx->r2 != ctx->r1) {
        // 0x80021930: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021940;
    }
    // 0x80021930: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021934: bne         $t2, $at, L_80021940
    if (ctx->r10 != ctx->r1) {
        // 0x80021938: nop
    
            goto L_80021940;
    }
    // 0x80021938: nop

    // 0x8002193C: break       6
    do_break(2147621180);
L_80021940:
    // 0x80021940: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80021944: sh          $a2, 0xC0($t6)
    MEM_H(0XC0, ctx->r14) = ctx->r6;
    // 0x80021948: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002194C: mflo        $t2
    ctx->r10 = lo;
    // 0x80021950: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80021954: sh          $t2, 0xCC($t8)
    MEM_H(0XCC, ctx->r24) = ctx->r10;
L_80021958:
    // 0x80021958: bne         $t3, $t5, L_8002186C
    if (ctx->r11 != ctx->r13) {
        // 0x8002195C: addiu       $t0, $t0, 0x1B0
        ctx->r8 = ADD32(ctx->r8, 0X1B0);
            goto L_8002186C;
    }
    // 0x8002195C: addiu       $t0, $t0, 0x1B0
    ctx->r8 = ADD32(ctx->r8, 0X1B0);
    // 0x80021960: jr          $ra
    // 0x80021964: nop

    return;
    // 0x80021964: nop

;}
RECOMP_FUNC void FUN_80021968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021968: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002196C: lw          $v0, -0x44B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44B8);
    // 0x80021970: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80021974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021978: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x8002197C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80021980: slti        $at, $a1, 0x634
    ctx->r1 = SIGNED(ctx->r5) < 0X634 ? 1 : 0;
    // 0x80021984: bne         $at, $zero, L_8002199C
    if (ctx->r1 != 0) {
        // 0x80021988: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_8002199C;
    }
    // 0x80021988: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002198C: jal         0x80021C10
    // 0x80021990: nop

    LOOKUP_FUNC(0x80021C10)(rdram, ctx);
        goto after_0;
    // 0x80021990: nop

    after_0:
    // 0x80021994: b           L_80021C04
    // 0x80021998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80021C04;
    // 0x80021998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002199C:
    // 0x8002199C: slti        $at, $a1, 0x607
    ctx->r1 = SIGNED(ctx->r5) < 0X607 ? 1 : 0;
    // 0x800219A0: bne         $at, $zero, L_800219B0
    if (ctx->r1 != 0) {
        // 0x800219A4: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_800219B0;
    }
    // 0x800219A4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800219A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800219AC: sb          $t6, -0x4428($at)
    MEM_B(-0X4428, ctx->r1) = ctx->r14;
L_800219B0:
    // 0x800219B0: slti        $at, $a1, 0x300
    ctx->r1 = SIGNED(ctx->r5) < 0X300 ? 1 : 0;
    // 0x800219B4: bne         $at, $zero, L_80021AC4
    if (ctx->r1 != 0) {
        // 0x800219B8: slti        $at, $a1, 0x634
        ctx->r1 = SIGNED(ctx->r5) < 0X634 ? 1 : 0;
            goto L_80021AC4;
    }
    // 0x800219B8: slti        $at, $a1, 0x634
    ctx->r1 = SIGNED(ctx->r5) < 0X634 ? 1 : 0;
    // 0x800219BC: beq         $at, $zero, L_80021C00
    if (ctx->r1 == 0) {
        // 0x800219C0: sra         $t7, $a1, 8
        ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80021C00;
    }
    // 0x800219C0: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800219C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800219C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800219CC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800219D0: lw          $v0, 0x79A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X79A4);
    // 0x800219D4: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x800219D8: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800219DC: addu        $t1, $v0, $t2
    ctx->r9 = ADD32(ctx->r2, ctx->r10);
    // 0x800219E0: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x800219E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800219E8: addiu       $t0, $t0, -0x4528
    ctx->r8 = ADD32(ctx->r8, -0X4528);
    // 0x800219EC: sb          $t4, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r12;
    // 0x800219F0: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x800219F4: sb          $t5, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r13;
    // 0x800219F8: lbu         $a3, 0x1($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X1);
    // 0x800219FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80021A00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80021A04: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x80021A08: sra         $a3, $a3, 4
    ctx->r7 = S32(SIGNED(ctx->r7) >> 4);
    // 0x80021A0C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80021A10: sb          $t6, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r14;
    // 0x80021A14: bne         $a3, $zero, L_80021A70
    if (ctx->r7 != 0) {
        // 0x80021A18: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80021A70;
    }
    // 0x80021A18: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80021A1C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80021A20: addiu       $v1, $v1, 0x5958
    ctx->r3 = ADD32(ctx->r3, 0X5958);
    // 0x80021A24: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_80021A28:
    // 0x80021A28: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80021A2C: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x80021A30: bnel        $a0, $t8, L_80021A48
    if (ctx->r4 != ctx->r24) {
        // 0x80021A34: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80021A48;
    }
    goto skip_0;
    // 0x80021A34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80021A38: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x80021A3C: b           L_80021A50
    // 0x80021A40: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
        goto L_80021A50;
    // 0x80021A40: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80021A44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80021A48:
    // 0x80021A48: bne         $v0, $a1, L_80021A28
    if (ctx->r2 != ctx->r5) {
        // 0x80021A4C: addiu       $v1, $v1, 0xD8
        ctx->r3 = ADD32(ctx->r3, 0XD8);
            goto L_80021A28;
    }
    // 0x80021A4C: addiu       $v1, $v1, 0xD8
    ctx->r3 = ADD32(ctx->r3, 0XD8);
L_80021A50:
    // 0x80021A50: bne         $a2, $zero, L_80021A70
    if (ctx->r6 != 0) {
        // 0x80021A54: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80021A70;
    }
    // 0x80021A54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80021A58: jal         0x80021D50
    // 0x80021A5C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80021D50)(rdram, ctx);
        goto after_1;
    // 0x80021A5C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_1:
    // 0x80021A60: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80021A64: addiu       $t0, $t0, -0x4528
    ctx->r8 = ADD32(ctx->r8, -0X4528);
    // 0x80021A68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80021A6C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_80021A70:
    // 0x80021A70: sll         $t2, $a3, 3
    ctx->r10 = S32(ctx->r7 << 3);
    // 0x80021A74: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x80021A78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80021A7C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80021A80: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x80021A84: addiu       $v1, $v1, 0x5520
    ctx->r3 = ADD32(ctx->r3, 0X5520);
    // 0x80021A88: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80021A8C: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80021A90: lbu         $t4, 0x4($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X4);
    // 0x80021A94: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
    // 0x80021A98: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80021A9C: addiu       $v0, $v0, -0x44B0
    ctx->r2 = ADD32(ctx->r2, -0X44B0);
    // 0x80021AA0: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80021AA4: bne         $at, $zero, L_80021C00
    if (ctx->r1 != 0) {
        // 0x80021AA8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80021C00;
    }
    // 0x80021AA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80021AAC: sb          $a3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r7;
    // 0x80021AB0: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
    // 0x80021AB4: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x80021AB8: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x80021ABC: b           L_80021BEC
    // 0x80021AC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80021BEC;
    // 0x80021AC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80021AC4:
    // 0x80021AC4: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80021AC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80021ACC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80021AD0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80021AD4: lw          $v0, 0x79A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X79A4);
    // 0x80021AD8: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x80021ADC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80021AE0: addu        $t1, $v0, $t3
    ctx->r9 = ADD32(ctx->r2, ctx->r11);
    // 0x80021AE4: lbu         $a3, 0x0($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X0);
    // 0x80021AE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80021AEC: addiu       $t0, $t0, -0x4528
    ctx->r8 = ADD32(ctx->r8, -0X4528);
    // 0x80021AF0: sra         $t4, $a3, 5
    ctx->r12 = S32(SIGNED(ctx->r7) >> 5);
    // 0x80021AF4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80021AF8: andi        $t9, $a3, 0x1F
    ctx->r25 = ctx->r7 & 0X1F;
    // 0x80021AFC: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80021B00: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
    // 0x80021B04: lbu         $a3, 0x1($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X1);
    // 0x80021B08: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80021B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80021B10: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x80021B14: sra         $a3, $a3, 4
    ctx->r7 = S32(SIGNED(ctx->r7) >> 4);
    // 0x80021B18: sb          $t6, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r14;
    // 0x80021B1C: bne         $t7, $at, L_80021BE0
    if (ctx->r15 != ctx->r1) {
        // 0x80021B20: andi        $a3, $a3, 0xFF
        ctx->r7 = ctx->r7 & 0XFF;
            goto L_80021BE0;
    }
    // 0x80021B20: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80021B24: bne         $a3, $zero, L_80021B88
    if (ctx->r7 != 0) {
        // 0x80021B28: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80021B88;
    }
    // 0x80021B28: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80021B2C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80021B30: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80021B34: addiu       $v1, $v1, 0x60F0
    ctx->r3 = ADD32(ctx->r3, 0X60F0);
    // 0x80021B38: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80021B3C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80021B40:
    // 0x80021B40: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80021B44: andi        $t2, $t8, 0x7FFF
    ctx->r10 = ctx->r24 & 0X7FFF;
    // 0x80021B48: bnel        $a0, $t2, L_80021B60
    if (ctx->r4 != ctx->r10) {
        // 0x80021B4C: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80021B60;
    }
    goto skip_1;
    // 0x80021B4C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    skip_1:
    // 0x80021B50: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x80021B54: b           L_80021B68
    // 0x80021B58: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
        goto L_80021B68;
    // 0x80021B58: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80021B5C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80021B60:
    // 0x80021B60: bne         $v0, $a1, L_80021B40
    if (ctx->r2 != ctx->r5) {
        // 0x80021B64: addiu       $v1, $v1, -0x1B0
        ctx->r3 = ADD32(ctx->r3, -0X1B0);
            goto L_80021B40;
    }
    // 0x80021B64: addiu       $v1, $v1, -0x1B0
    ctx->r3 = ADD32(ctx->r3, -0X1B0);
L_80021B68:
    // 0x80021B68: bne         $a2, $zero, L_80021B88
    if (ctx->r6 != 0) {
        // 0x80021B6C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80021B88;
    }
    // 0x80021B6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80021B70: jal         0x80021D50
    // 0x80021B74: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80021D50)(rdram, ctx);
        goto after_2;
    // 0x80021B74: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x80021B78: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80021B7C: addiu       $t0, $t0, -0x4528
    ctx->r8 = ADD32(ctx->r8, -0X4528);
    // 0x80021B80: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80021B84: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_80021B88:
    // 0x80021B88: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x80021B8C: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x80021B90: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80021B94: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80021B98: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x80021B9C: addiu       $v1, $v1, 0x5520
    ctx->r3 = ADD32(ctx->r3, 0X5520);
    // 0x80021BA0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80021BA4: addu        $t9, $v1, $t3
    ctx->r25 = ADD32(ctx->r3, ctx->r11);
    // 0x80021BA8: lbu         $t4, 0x4($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X4);
    // 0x80021BAC: lbu         $v0, 0x2($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X2);
    // 0x80021BB0: sll         $t5, $a3, 3
    ctx->r13 = S32(ctx->r7 << 3);
    // 0x80021BB4: subu        $t5, $t5, $a3
    ctx->r13 = SUB32(ctx->r13, ctx->r7);
    // 0x80021BB8: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80021BBC: bne         $at, $zero, L_80021C00
    if (ctx->r1 != 0) {
        // 0x80021BC0: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80021C00;
    }
    // 0x80021BC0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80021BC4: subu        $t5, $t5, $a3
    ctx->r13 = SUB32(ctx->r13, ctx->r7);
    // 0x80021BC8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80021BCC: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80021BD0: lbu         $t7, 0xDC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XDC);
    // 0x80021BD4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80021BD8: bnel        $at, $zero, L_80021C04
    if (ctx->r1 != 0) {
        // 0x80021BDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021C04;
    }
    goto skip_2;
    // 0x80021BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80021BE0:
    // 0x80021BE0: sb          $a3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r7;
    // 0x80021BE4: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x80021BE8: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
L_80021BEC:
    // 0x80021BEC: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80021BF0: sb          $t2, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r10;
    // 0x80021BF4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x80021BF8: jal         0x80022214
    // 0x80021BFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x80022214)(rdram, ctx);
        goto after_3;
    // 0x80021BFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
L_80021C00:
    // 0x80021C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021C04:
    // 0x80021C04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80021C08: jr          $ra
    // 0x80021C0C: nop

    return;
    // 0x80021C0C: nop

;}
RECOMP_FUNC void FUN_80021c10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80021C14: lw          $v0, -0x44B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44B8);
    // 0x80021C18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80021C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021C20: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80021C24: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80021C28: slti        $at, $v0, 0x6CF
    ctx->r1 = SIGNED(ctx->r2) < 0X6CF ? 1 : 0;
    // 0x80021C2C: beq         $at, $zero, L_80021D38
    if (ctx->r1 == 0) {
        // 0x80021C30: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80021D38;
    }
    // 0x80021C30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80021C34: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80021C38: addiu       $t7, $t7, 0x28F8
    ctx->r15 = ADD32(ctx->r15, 0X28F8);
    // 0x80021C3C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80021C40: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x80021C44: lbu         $a2, -0x319F($t1)
    ctx->r6 = MEM_BU(ctx->r9, -0X319F);
    // 0x80021C48: lbu         $t9, -0x31A0($t1)
    ctx->r25 = MEM_BU(ctx->r9, -0X31A0);
    // 0x80021C4C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80021C50: sra         $a2, $a2, 4
    ctx->r6 = S32(SIGNED(ctx->r6) >> 4);
    // 0x80021C54: addiu       $a3, $a3, -0x4528
    ctx->r7 = ADD32(ctx->r7, -0X4528);
    // 0x80021C58: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    // 0x80021C5C: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80021C60: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80021C64: sb          $t9, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r25;
    // 0x80021C68: andi        $t3, $t9, 0x1F
    ctx->r11 = ctx->r25 & 0X1F;
    // 0x80021C6C: sb          $t3, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r11;
    // 0x80021C70: bne         $t2, $a2, L_80021CD4
    if (ctx->r10 != ctx->r6) {
        // 0x80021C74: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80021CD4;
    }
    // 0x80021C74: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80021C78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80021C7C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80021C80: addiu       $v1, $v1, 0x62A0
    ctx->r3 = ADD32(ctx->r3, 0X62A0);
    // 0x80021C84: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80021C88: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80021C8C:
    // 0x80021C8C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80021C90: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x80021C94: bnel        $a0, $t5, L_80021CAC
    if (ctx->r4 != ctx->r13) {
        // 0x80021C98: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80021CAC;
    }
    goto skip_0;
    // 0x80021C98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80021C9C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x80021CA0: b           L_80021CB4
    // 0x80021CA4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
        goto L_80021CB4;
    // 0x80021CA4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80021CA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80021CAC:
    // 0x80021CAC: bne         $v0, $a1, L_80021C8C
    if (ctx->r2 != ctx->r5) {
        // 0x80021CB0: addiu       $v1, $v1, 0xD8
        ctx->r3 = ADD32(ctx->r3, 0XD8);
            goto L_80021C8C;
    }
    // 0x80021CB0: addiu       $v1, $v1, 0xD8
    ctx->r3 = ADD32(ctx->r3, 0XD8);
L_80021CB4:
    // 0x80021CB4: bne         $t2, $t0, L_80021CD4
    if (ctx->r10 != ctx->r8) {
        // 0x80021CB8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80021CD4;
    }
    // 0x80021CB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021CBC: jal         0x80021D50
    // 0x80021CC0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80021D50)(rdram, ctx);
        goto after_0;
    // 0x80021CC0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x80021CC4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80021CC8: addiu       $a3, $a3, -0x4528
    ctx->r7 = ADD32(ctx->r7, -0X4528);
    // 0x80021CCC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80021CD0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_80021CD4:
    // 0x80021CD4: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x80021CD8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80021CDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80021CE0: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80021CE4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80021CE8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80021CEC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80021CF0: lbu         $t8, 0x5524($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5524);
    // 0x80021CF4: lbu         $t6, 0x2($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2);
    // 0x80021CF8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80021CFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80021D00: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80021D04: bne         $at, $zero, L_80021D38
    if (ctx->r1 != 0) {
        // 0x80021D08: addiu       $t3, $t3, -0x44B0
        ctx->r11 = ADD32(ctx->r11, -0X44B0);
            goto L_80021D38;
    }
    // 0x80021D08: addiu       $t3, $t3, -0x44B0
    ctx->r11 = ADD32(ctx->r11, -0X44B0);
    // 0x80021D0C: lw          $t4, -0x319C($t1)
    ctx->r12 = MEM_W(ctx->r9, -0X319C);
    // 0x80021D10: sb          $a2, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r6;
    // 0x80021D14: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
    // 0x80021D18: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
    // 0x80021D1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021D20: sw          $t4, -0x44B0($at)
    MEM_W(-0X44B0, ctx->r1) = ctx->r12;
    // 0x80021D24: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x80021D28: sb          $zero, 0x4($a3)
    MEM_B(0X4, ctx->r7) = 0;
    // 0x80021D2C: sb          $zero, 0x5($a3)
    MEM_B(0X5, ctx->r7) = 0;
    // 0x80021D30: jal         0x80022214
    // 0x80021D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80022214)(rdram, ctx);
        goto after_1;
    // 0x80021D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_80021D38:
    // 0x80021D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80021D40: jr          $ra
    // 0x80021D44: nop

    return;
    // 0x80021D44: nop

    // 0x80021D48: jr          $ra
    // 0x80021D4C: nop

    return;
    // 0x80021D4C: nop

;}
RECOMP_FUNC void FUN_80021d50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021D50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80021D54: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021D58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021D5C: bne         $a0, $at, L_80021DBC
    if (ctx->r4 != ctx->r1) {
        // 0x80021D60: addiu       $v1, $zero, 0x5
        ctx->r3 = ADD32(0, 0X5);
            goto L_80021DBC;
    }
    // 0x80021D60: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80021D64: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80021D68: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021D6C: lbu         $v0, 0x595C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X595C);
    // 0x80021D70: addiu       $t1, $t1, 0x5520
    ctx->r9 = ADD32(ctx->r9, 0X5520);
    // 0x80021D74: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80021D78: addiu       $t2, $zero, 0xD8
    ctx->r10 = ADD32(0, 0XD8);
L_80021D7C:
    // 0x80021D7C: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021D80: mflo        $t6
    ctx->r14 = lo;
    // 0x80021D84: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80021D88: lbu         $a1, 0x4($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X4);
    // 0x80021D8C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80021D90: bnel        $at, $zero, L_80021DA4
    if (ctx->r1 != 0) {
        // 0x80021D94: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80021DA4;
    }
    goto skip_0;
    // 0x80021D94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80021D98: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80021D9C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80021DA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80021DA4:
    // 0x80021DA4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021DA8: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x80021DAC: bne         $at, $zero, L_80021D7C
    if (ctx->r1 != 0) {
        // 0x80021DB0: nop
    
            goto L_80021D7C;
    }
    // 0x80021DB0: nop

    // 0x80021DB4: jr          $ra
    // 0x80021DB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80021DB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80021DBC:
    // 0x80021DBC: bne         $a0, $zero, L_80021E20
    if (ctx->r4 != 0) {
        // 0x80021DC0: addiu       $v1, $zero, 0xE
        ctx->r3 = ADD32(0, 0XE);
            goto L_80021E20;
    }
    // 0x80021DC0: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x80021DC4: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80021DC8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021DCC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80021DD0: lbu         $v0, 0x62A4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X62A4);
    // 0x80021DD4: addiu       $t1, $t1, 0x5520
    ctx->r9 = ADD32(ctx->r9, 0X5520);
    // 0x80021DD8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80021DDC: addiu       $t2, $zero, 0xD8
    ctx->r10 = ADD32(0, 0XD8);
L_80021DE0:
    // 0x80021DE0: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021DE4: mflo        $t8
    ctx->r24 = lo;
    // 0x80021DE8: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80021DEC: lbu         $a1, 0x4($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X4);
    // 0x80021DF0: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80021DF4: bnel        $at, $zero, L_80021E08
    if (ctx->r1 != 0) {
        // 0x80021DF8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80021E08;
    }
    goto skip_1;
    // 0x80021DF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x80021DFC: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80021E00: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80021E04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80021E08:
    // 0x80021E08: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021E0C: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x80021E10: bne         $at, $zero, L_80021DE0
    if (ctx->r1 != 0) {
        // 0x80021E14: nop
    
            goto L_80021DE0;
    }
    // 0x80021E14: nop

    // 0x80021E18: jr          $ra
    // 0x80021E1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80021E1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80021E20:
    // 0x80021E20: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021E24: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80021E28: addiu       $t1, $t1, 0x5520
    ctx->r9 = ADD32(ctx->r9, 0X5520);
    // 0x80021E2C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80021E30: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80021E34: addiu       $t3, $zero, 0xD8
    ctx->r11 = ADD32(0, 0XD8);
    // 0x80021E38: addiu       $t2, $zero, 0xD8
    ctx->r10 = ADD32(0, 0XD8);
L_80021E3C:
    // 0x80021E3C: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021E40: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80021E44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80021E48: mflo        $t4
    ctx->r12 = lo;
    // 0x80021E4C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80021E50: lbu         $t6, 0x4($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4);
    // 0x80021E54: multu       $a2, $t3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021E58: mflo        $t7
    ctx->r15 = lo;
    // 0x80021E5C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80021E60: lbu         $t9, 0xDC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XDC);
    // 0x80021E64: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80021E68: beq         $at, $zero, L_80021E78
    if (ctx->r1 == 0) {
        // 0x80021E6C: nop
    
            goto L_80021E78;
    }
    // 0x80021E6C: nop

    // 0x80021E70: addiu       $a3, $a0, 0x1
    ctx->r7 = ADD32(ctx->r4, 0X1);
    // 0x80021E74: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_80021E78:
    // 0x80021E78: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021E7C: mflo        $t4
    ctx->r12 = lo;
    // 0x80021E80: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80021E84: lbu         $t0, 0x4($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X4);
    // 0x80021E88: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80021E8C: bnel        $at, $zero, L_80021EA0
    if (ctx->r1 != 0) {
        // 0x80021E90: addiu       $a0, $a2, -0x2
        ctx->r4 = ADD32(ctx->r6, -0X2);
            goto L_80021EA0;
    }
    goto skip_2;
    // 0x80021E90: addiu       $a0, $a2, -0x2
    ctx->r4 = ADD32(ctx->r6, -0X2);
    skip_2:
    // 0x80021E94: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80021E98: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80021E9C: addiu       $a0, $a2, -0x2
    ctx->r4 = ADD32(ctx->r6, -0X2);
L_80021EA0:
    // 0x80021EA0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021EA4: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80021EA8: beq         $at, $zero, L_80021E3C
    if (ctx->r1 == 0) {
        // 0x80021EAC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80021E3C;
    }
    // 0x80021EAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80021EB0: jr          $ra
    // 0x80021EB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80021EB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80021eb8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80021eb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021EB8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80021EBC: lw          $a2, -0x44B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44B8);
    // 0x80021EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021EC8: andi        $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 & 0X7FFF;
    // 0x80021ECC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80021ED0: slti        $at, $a2, 0xC0
    ctx->r1 = SIGNED(ctx->r6) < 0XC0 ? 1 : 0;
    // 0x80021ED4: beq         $at, $zero, L_80021FD4
    if (ctx->r1 == 0) {
        // 0x80021ED8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80021FD4;
    }
    // 0x80021ED8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80021EDC: slti        $at, $a2, 0x93
    ctx->r1 = SIGNED(ctx->r6) < 0X93 ? 1 : 0;
    // 0x80021EE0: beq         $at, $zero, L_80022034
    if (ctx->r1 == 0) {
        // 0x80021EE4: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_80022034;
    }
    // 0x80021EE4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80021EE8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021EEC: addiu       $t7, $t7, 0x3070
    ctx->r15 = ADD32(ctx->r15, 0X3070);
    // 0x80021EF0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80021EF4: lbu         $t8, -0x3D($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X3D);
    // 0x80021EF8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80021EFC: addiu       $v1, $v0, -0x40
    ctx->r3 = ADD32(ctx->r2, -0X40);
    // 0x80021F00: bnel        $t8, $zero, L_80021F48
    if (ctx->r24 != 0) {
        // 0x80021F04: lbu         $t0, 0x3($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X3);
            goto L_80021F48;
    }
    goto skip_0;
    // 0x80021F04: lbu         $t0, 0x3($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3);
    skip_0:
    // 0x80021F08: lhu         $t9, -0x453E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X453E);
    // 0x80021F0C: beql        $t9, $zero, L_80021F30
    if (ctx->r25 == 0) {
        // 0x80021F10: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80021F30;
    }
    goto skip_1;
    // 0x80021F10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80021F14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021F18: jal         0x80022528
    // 0x80021F1C: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80022528)(rdram, ctx);
        goto after_0;
    // 0x80021F1C: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    after_0:
    // 0x80021F20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021F24: b           L_80021F9C
    // 0x80021F28: lhu         $a2, 0x26($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X26);
        goto L_80021F9C;
    // 0x80021F28: lhu         $a2, 0x26($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X26);
    // 0x80021F2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_80021F30:
    // 0x80021F30: jal         0x80022694
    // 0x80021F34: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80022694)(rdram, ctx);
        goto after_1;
    // 0x80021F34: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    after_1:
    // 0x80021F38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021F3C: b           L_80021F9C
    // 0x80021F40: lhu         $a2, 0x26($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X26);
        goto L_80021F9C;
    // 0x80021F40: lhu         $a2, 0x26($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X26);
    // 0x80021F44: lbu         $t0, 0x3($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3);
L_80021F48:
    // 0x80021F48: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80021F4C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80021F50: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80021F54: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80021F58: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80021F5C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80021F60: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80021F64: lw          $t2, 0x5520($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5520);
    // 0x80021F68: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x80021F6C: beql        $a1, $t3, L_80022038
    if (ctx->r5 == ctx->r11) {
        // 0x80021F70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022038;
    }
    goto skip_2;
    // 0x80021F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80021F74: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x80021F78: jal         0x800227EC
    // 0x80021F7C: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800227EC)(rdram, ctx);
        goto after_2;
    // 0x80021F7C: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    after_2:
    // 0x80021F80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80021F84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021F88: lhu         $a2, 0x26($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X26);
    // 0x80021F8C: sb          $t4, -0x44B2($at)
    MEM_B(-0X44B2, ctx->r1) = ctx->r12;
    // 0x80021F90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021F94: b           L_80022034
    // 0x80021F98: sh          $a2, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = ctx->r6;
        goto L_80022034;
    // 0x80021F98: sh          $a2, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = ctx->r6;
L_80021F9C:
    // 0x80021F9C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80021FA0: lbu         $t5, -0x44DF($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X44DF);
    // 0x80021FA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021FA8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80021FAC: beq         $t5, $a1, L_80021FC4
    if (ctx->r13 == ctx->r5) {
        // 0x80021FB0: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_80021FC4;
    }
    // 0x80021FB0: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x80021FB4: sh          $a2, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = ctx->r6;
    // 0x80021FB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80021FBC: b           L_80022034
    // 0x80021FC0: sb          $t6, -0x44B2($at)
    MEM_B(-0X44B2, ctx->r1) = ctx->r14;
        goto L_80022034;
    // 0x80021FC0: sb          $t6, -0x44B2($at)
    MEM_B(-0X44B2, ctx->r1) = ctx->r14;
L_80021FC4:
    // 0x80021FC4: jal         0x80022128
    // 0x80021FC8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80022128)(rdram, ctx);
        goto after_3;
    // 0x80021FC8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80021FCC: b           L_80022038
    // 0x80021FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80022038;
    // 0x80021FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021FD4:
    // 0x80021FD4: slti        $at, $a1, 0xC1
    ctx->r1 = SIGNED(ctx->r5) < 0XC1 ? 1 : 0;
    // 0x80021FD8: beq         $at, $zero, L_80022034
    if (ctx->r1 == 0) {
        // 0x80021FDC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_80022034;
    }
    // 0x80021FDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80021FE0: addiu       $a2, $a1, -0xC0
    ctx->r6 = ADD32(ctx->r5, -0XC0);
    // 0x80021FE4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80021FE8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80021FEC: addiu       $v0, $v0, -0x4528
    ctx->r2 = ADD32(ctx->r2, -0X4528);
    // 0x80021FF0: addiu       $t8, $t8, 0x327C
    ctx->r24 = ADD32(ctx->r24, 0X327C);
    // 0x80021FF4: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x80021FF8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80021FFC: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80022000: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80022004: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80022008: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8002200C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80022010: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80022014: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    // 0x80022018: sb          $t3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r11;
    // 0x8002201C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80022020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022024: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80022028: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x8002202C: jal         0x80022214
    // 0x80022030: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    LOOKUP_FUNC(0x80022214)(rdram, ctx);
        goto after_4;
    // 0x80022030: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    after_4:
L_80022034:
    // 0x80022034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80022038:
    // 0x80022038: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002203C: jr          $ra
    // 0x80022040: nop

    return;
    // 0x80022040: nop

;}
RECOMP_FUNC void FUN_80022044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022044: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022048: addiu       $v0, $v0, -0x44B2
    ctx->r2 = ADD32(ctx->r2, -0X44B2);
    // 0x8002204C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80022050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022058: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8002205C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80022060: bne         $t8, $zero, L_80022118
    if (ctx->r24 != 0) {
        // 0x80022064: sb          $t7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r15;
            goto L_80022118;
    }
    // 0x80022064: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80022068: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002206C: lbu         $t9, -0x23E8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X23E8);
    // 0x80022070: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022074: beq         $t9, $zero, L_80022084
    if (ctx->r25 == 0) {
        // 0x80022078: nop
    
            goto L_80022084;
    }
    // 0x80022078: nop

    // 0x8002207C: b           L_80022118
    // 0x80022080: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
        goto L_80022118;
    // 0x80022080: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80022084:
    // 0x80022084: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022088: lhu         $v1, -0x44B4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X44B4);
    // 0x8002208C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80022090: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80022094: addiu       $a0, $v1, -0x10
    ctx->r4 = ADD32(ctx->r3, -0X10);
    // 0x80022098: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8002209C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800220A0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800220A4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800220A8: lbu         $t0, 0x3072($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3072);
    // 0x800220AC: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800220B0: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800220B4: lw          $a3, 0x79E8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X79E8);
    // 0x800220B8: lw          $t2, 0x7BF4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7BF4);
    // 0x800220BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800220C0: sb          $v1, -0x44DF($at)
    MEM_B(-0X44DF, ctx->r1) = ctx->r3;
    // 0x800220C4: beq         $t0, $zero, L_800220F0
    if (ctx->r8 == 0) {
        // 0x800220C8: subu        $a2, $t2, $a3
        ctx->r6 = SUB32(ctx->r10, ctx->r7);
            goto L_800220F0;
    }
    // 0x800220C8: subu        $a2, $t2, $a3
    ctx->r6 = SUB32(ctx->r10, ctx->r7);
    // 0x800220CC: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x800220D0: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x800220D4: addiu       $t5, $t5, -0x7A00
    ctx->r13 = ADD32(ctx->r13, -0X7A00);
    // 0x800220D8: addiu       $t4, $t3, -0x1000
    ctx->r12 = ADD32(ctx->r11, -0X1000);
    // 0x800220DC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800220E0: jal         0x80003824
    // 0x800220E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80003824)(rdram, ctx);
        goto after_0;
    // 0x800220E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800220E8: b           L_80022100
    // 0x800220EC: nop

        goto L_80022100;
    // 0x800220EC: nop

L_800220F0:
    // 0x800220F0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800220F4: addiu       $a1, $a1, 0x6600
    ctx->r5 = ADD32(ctx->r5, 0X6600);
    // 0x800220F8: jal         0x80003824
    // 0x800220FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80003824)(rdram, ctx);
        goto after_1;
    // 0x800220FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_80022100:
    // 0x80022100: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022104: lhu         $a0, -0x44B4($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X44B4);
    // 0x80022108: jal         0x80022128
    // 0x8002210C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80022128)(rdram, ctx);
        goto after_2;
    // 0x8002210C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80022110: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022114: sh          $zero, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = 0;
L_80022118:
    // 0x80022118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002211C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022120: jr          $ra
    // 0x80022124: nop

    return;
    // 0x80022124: nop

;}
RECOMP_FUNC void FUN_80022128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002212C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022130: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80022134: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80022138: addiu       $t8, $t8, 0x3070
    ctx->r24 = ADD32(ctx->r24, 0X3070);
    // 0x8002213C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80022140: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80022144: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80022148: addiu       $a2, $a2, -0x4528
    ctx->r6 = ADD32(ctx->r6, -0X4528);
    // 0x8002214C: lbu         $v1, -0x3E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X3E);
    // 0x80022150: lbu         $t9, -0x40($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X40);
    // 0x80022154: lbu         $t0, -0x3F($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X3F);
    // 0x80022158: lbu         $t1, -0x3D($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X3D);
    // 0x8002215C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80022160: addiu       $t2, $t2, -0x44B0
    ctx->r10 = ADD32(ctx->r10, -0X44B0);
    // 0x80022164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002216C: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x80022170: sb          $v1, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r3;
    // 0x80022174: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80022178: sb          $t0, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r8;
    // 0x8002217C: beq         $v1, $zero, L_800221A0
    if (ctx->r3 == 0) {
        // 0x80022180: sb          $t1, 0x1($a2)
        MEM_B(0X1, ctx->r6) = ctx->r9;
            goto L_800221A0;
    }
    // 0x80022180: sb          $t1, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r9;
    // 0x80022184: lbu         $t3, -0x3E($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X3E);
    // 0x80022188: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8002218C: addiu       $t6, $t6, -0x7A00
    ctx->r14 = ADD32(ctx->r14, -0X7A00);
    // 0x80022190: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80022194: addiu       $t5, $t4, -0x1000
    ctx->r13 = ADD32(ctx->r12, -0X1000);
    // 0x80022198: b           L_800221A8
    // 0x8002219C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
        goto L_800221A8;
    // 0x8002219C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
L_800221A0:
    // 0x800221A0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800221A4: addiu       $a0, $a0, 0x6600
    ctx->r4 = ADD32(ctx->r4, 0X6600);
L_800221A8:
    // 0x800221A8: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x800221AC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800221B0: addiu       $v0, $t7, -0x44B0
    ctx->r2 = ADD32(ctx->r15, -0X44B0);
    // 0x800221B4: blez        $a3, L_800221E4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800221B8: addiu       $t2, $zero, 0x1E
        ctx->r10 = ADD32(0, 0X1E);
            goto L_800221E4;
    }
    // 0x800221B8: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x800221BC: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800221C0: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    // 0x800221C4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800221C8:
    // 0x800221C8: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x800221CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800221D0: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800221D4: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800221D8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800221DC: bne         $at, $zero, L_800221C8
    if (ctx->r1 != 0) {
        // 0x800221E0: sw          $t0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r8;
            goto L_800221C8;
    }
    // 0x800221E0: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
L_800221E4:
    // 0x800221E4: lhu         $t1, 0x1A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X1A);
    // 0x800221E8: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x800221EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800221F0: sw          $t1, -0x44B8($at)
    MEM_W(-0X44B8, ctx->r1) = ctx->r9;
    // 0x800221F4: sb          $t2, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r10;
    // 0x800221F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800221FC: jal         0x80022214
    // 0x80022200: sb          $t3, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r11;
    LOOKUP_FUNC(0x80022214)(rdram, ctx);
        goto after_0;
    // 0x80022200: sb          $t3, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r11;
    after_0:
    // 0x80022204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002220C: jr          $ra
    // 0x80022210: nop

    return;
    // 0x80022210: nop

;}
RECOMP_FUNC void FUN_80022214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022214: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80022218: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002221C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80022220: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80022224: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80022228: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002222C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80022230: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80022234: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022238: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002223C: bne         $a0, $zero, L_80022258
    if (ctx->r4 != 0) {
        // 0x80022240: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022258;
    }
    // 0x80022240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022244: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x80022248: addiu       $s5, $s5, -0x4528
    ctx->r21 = ADD32(ctx->r21, -0X4528);
    // 0x8002224C: sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // 0x80022250: sh          $zero, 0xE($s5)
    MEM_H(0XE, ctx->r21) = 0;
    // 0x80022254: sh          $zero, 0x10($s5)
    MEM_H(0X10, ctx->r21) = 0;
L_80022258:
    // 0x80022258: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8002225C: lw          $a2, -0x44B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44B8);
    // 0x80022260: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x80022264: addiu       $s5, $s5, -0x4528
    ctx->r21 = ADD32(ctx->r21, -0X4528);
    // 0x80022268: andi        $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 & 0X7FFF;
    // 0x8002226C: sltiu       $at, $a2, 0x100
    ctx->r1 = ctx->r6 < 0X100 ? 1 : 0;
    // 0x80022270: beq         $at, $zero, L_80022280
    if (ctx->r1 == 0) {
        // 0x80022274: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80022280;
    }
    // 0x80022274: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80022278: b           L_80022280
    // 0x8002227C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80022280;
    // 0x8002227C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80022280:
    // 0x80022280: lbu         $t6, 0x0($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X0);
    // 0x80022284: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x80022288: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002228C: blez        $t6, L_800224BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80022290: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800224BC;
    }
    // 0x80022290: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80022294: lui         $fp, 0x8005
    ctx->r30 = S32(0X8005 << 16);
    // 0x80022298: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8002229C: addiu       $s3, $s3, -0x4522
    ctx->r19 = ADD32(ctx->r19, -0X4522);
    // 0x800222A0: addiu       $fp, $fp, -0x6710
    ctx->r30 = ADD32(ctx->r30, -0X6710);
    // 0x800222A4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800222A8: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
L_800222AC:
    // 0x800222AC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800222B0: addiu       $t9, $t9, 0x5520
    ctx->r25 = ADD32(ctx->r25, 0X5520);
    // 0x800222B4: addu        $s0, $t7, $s6
    ctx->r16 = ADD32(ctx->r15, ctx->r22);
    // 0x800222B8: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x800222BC: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x800222C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800222C4: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x800222C8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800222CC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800222D0: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800222D4: beq         $at, $zero, L_80022378
    if (ctx->r1 == 0) {
        // 0x800222D8: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80022378;
    }
    // 0x800222D8: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800222DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800222E0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800222E4: lbu         $v0, -0x4530($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4530);
    // 0x800222E8: lbu         $t1, 0x10($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X10);
    // 0x800222EC: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x800222F0: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800222F4: beq         $t1, $v0, L_80022320
    if (ctx->r9 == ctx->r2) {
        // 0x800222F8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80022320;
    }
    // 0x800222F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800222FC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80022300: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x80022304: addiu       $t3, $t3, -0x4420
    ctx->r11 = ADD32(ctx->r11, -0X4420);
    // 0x80022308: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x8002230C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80022310: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80022314: jal         0x80030770
    // 0x80022318: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x80030770)(rdram, ctx);
        goto after_0;
    // 0x80022318: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_0:
    // 0x8002231C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80022320:
    // 0x80022320: lbu         $t4, 0x5($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X5);
    // 0x80022324: bnel        $t4, $zero, L_80022338
    if (ctx->r12 != 0) {
        // 0x80022328: lbu         $t5, 0xE($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0XE);
            goto L_80022338;
    }
    goto skip_0;
    // 0x80022328: lbu         $t5, 0xE($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XE);
    skip_0:
    // 0x8002232C: beql        $t0, $zero, L_80022384
    if (ctx->r8 == 0) {
        // 0x80022330: lbu         $t1, 0x4($s5)
        ctx->r9 = MEM_BU(ctx->r21, 0X4);
            goto L_80022384;
    }
    goto skip_1;
    // 0x80022330: lbu         $t1, 0x4($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X4);
    skip_1:
    // 0x80022334: lbu         $t5, 0xE($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XE);
L_80022338:
    // 0x80022338: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8002233C: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80022340: beq         $t5, $zero, L_80022380
    if (ctx->r13 == 0) {
        // 0x80022344: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80022380;
    }
    // 0x80022344: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80022348: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8002234C: addiu       $t7, $t7, -0x4420
    ctx->r15 = ADD32(ctx->r15, -0X4420);
    // 0x80022350: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80022354: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80022358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002235C: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    // 0x80022360: jal         0x80026950
    // 0x80022364: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80026950)(rdram, ctx);
        goto after_1;
    // 0x80022364: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_1:
    // 0x80022368: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002236C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80022370: b           L_80022380
    // 0x80022374: sb          $t8, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r24;
        goto L_80022380;
    // 0x80022374: sb          $t8, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r24;
L_80022378:
    // 0x80022378: sb          $zero, 0xE($s1)
    MEM_B(0XE, ctx->r17) = 0;
    // 0x8002237C: sb          $zero, 0xF($s1)
    MEM_B(0XF, ctx->r17) = 0;
L_80022380:
    // 0x80022380: lbu         $t1, 0x4($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X4);
L_80022384:
    // 0x80022384: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80022388: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8002238C: sb          $t1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r9;
    // 0x80022390: lw          $t2, -0x44B8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X44B8);
    // 0x80022394: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80022398: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8002239C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800223A0: lbu         $t3, 0x2($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X2);
    // 0x800223A4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800223A8: addiu       $a0, $a0, -0x4528
    ctx->r4 = ADD32(ctx->r4, -0X4528);
    // 0x800223AC: sb          $t3, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r11;
    // 0x800223B0: lbu         $t4, 0x3($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X3);
    // 0x800223B4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800223B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800223BC: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
    // 0x800223C0: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x800223C4: sh          $zero, 0x30($s1)
    MEM_H(0X30, ctx->r17) = 0;
    // 0x800223C8: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    // 0x800223CC: sh          $zero, 0x42($s1)
    MEM_H(0X42, ctx->r17) = 0;
    // 0x800223D0: lh          $t1, 0x30($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X30);
    // 0x800223D4: lh          $t2, 0x34($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X34);
    // 0x800223D8: lh          $t3, 0x42($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X42);
    // 0x800223DC: sh          $t6, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r14;
    // 0x800223E0: sh          $t7, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r15;
    // 0x800223E4: sb          $t9, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r25;
    // 0x800223E8: sb          $t9, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r25;
    // 0x800223EC: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
    // 0x800223F0: sh          $t1, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r9;
    // 0x800223F4: sh          $t2, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r10;
    // 0x800223F8: sh          $t3, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r11;
    // 0x800223FC: sh          $zero, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = 0;
    // 0x80022400: lh          $t4, 0x8A($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X8A);
    // 0x80022404: andi        $t6, $zero, 0xFF
    ctx->r14 = 0 & 0XFF;
    // 0x80022408: sb          $zero, 0x92($s2)
    MEM_B(0X92, ctx->r18) = 0;
    // 0x8002240C: sh          $zero, 0x38($s2)
    MEM_H(0X38, ctx->r18) = 0;
    // 0x80022410: sh          $t6, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = ctx->r14;
    // 0x80022414: sb          $zero, 0x9E($s2)
    MEM_B(0X9E, ctx->r18) = 0;
    // 0x80022418: sb          $zero, 0x1D($s2)
    MEM_B(0X1D, ctx->r18) = 0;
    // 0x8002241C: sb          $zero, 0x47($s2)
    MEM_B(0X47, ctx->r18) = 0;
    // 0x80022420: sb          $zero, 0x5B($s2)
    MEM_B(0X5B, ctx->r18) = 0;
    // 0x80022424: sh          $zero, 0x58($s2)
    MEM_H(0X58, ctx->r18) = 0;
    // 0x80022428: sb          $t4, 0x7D($s2)
    MEM_B(0X7D, ctx->r18) = ctx->r12;
L_8002242C:
    // 0x8002242C: lh          $v1, 0xC($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XC);
    // 0x80022430: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80022434: sltu        $at, $a0, $s3
    ctx->r1 = ctx->r4 < ctx->r19 ? 1 : 0;
    // 0x80022438: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002243C: sh          $v1, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r3;
    // 0x80022440: bne         $at, $zero, L_8002242C
    if (ctx->r1 != 0) {
        // 0x80022444: sh          $v1, 0xA0($v0)
        MEM_H(0XA0, ctx->r2) = ctx->r3;
            goto L_8002242C;
    }
    // 0x80022444: sh          $v1, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r3;
    // 0x80022448: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_8002244C:
    // 0x8002244C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022450: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80022454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80022458: sb          $zero, 0xB7($v1)
    MEM_B(0XB7, ctx->r3) = 0;
    // 0x8002245C: bne         $at, $zero, L_8002244C
    if (ctx->r1 != 0) {
        // 0x80022460: sb          $zero, 0xBA($v1)
        MEM_B(0XBA, ctx->r3) = 0;
            goto L_8002244C;
    }
    // 0x80022460: sb          $zero, 0xBA($v1)
    MEM_B(0XBA, ctx->r3) = 0;
    // 0x80022464: sb          $zero, 0xBE($s2)
    MEM_B(0XBE, ctx->r18) = 0;
    // 0x80022468: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002246C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80022470: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80022474:
    // 0x80022474: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022478: sh          $zero, 0xC6($v0)
    MEM_H(0XC6, ctx->r2) = 0;
    // 0x8002247C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80022480: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80022484: bne         $s0, $s4, L_80022474
    if (ctx->r16 != ctx->r20) {
        // 0x80022488: sb          $zero, 0xD1($v1)
        MEM_B(0XD1, ctx->r3) = 0;
            goto L_80022474;
    }
    // 0x80022488: sb          $zero, 0xD1($v1)
    MEM_B(0XD1, ctx->r3) = 0;
    // 0x8002248C: lbu         $t7, 0x5($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X5);
    // 0x80022490: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80022494: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80022498: sb          $t7, 0xD5($s2)
    MEM_B(0XD5, ctx->r18) = ctx->r15;
    // 0x8002249C: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x800224A0: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800224A4: bnel        $at, $zero, L_800222AC
    if (ctx->r1 != 0) {
        // 0x800224A8: lbu         $t7, 0x1($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X1);
            goto L_800222AC;
    }
    goto skip_2;
    // 0x800224A8: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    skip_2:
    // 0x800224AC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800224B0: lw          $a2, -0x44B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44B8);
    // 0x800224B4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800224B8: andi        $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 & 0X7FFF;
L_800224BC:
    // 0x800224BC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800224C0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800224C4: addiu       $a0, $a0, -0x453C
    ctx->r4 = ADD32(ctx->r4, -0X453C);
    // 0x800224C8: addiu       $v1, $v1, -0x4538
    ctx->r3 = ADD32(ctx->r3, -0X4538);
    // 0x800224CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800224D0:
    // 0x800224D0: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x800224D4: sll         $t1, $s6, 2
    ctx->r9 = S32(ctx->r22 << 2);
    // 0x800224D8: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x800224DC: bnel        $a2, $t9, L_800224F0
    if (ctx->r6 != ctx->r25) {
        // 0x800224E0: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800224F0;
    }
    goto skip_3;
    // 0x800224E0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_3:
    // 0x800224E4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800224E8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800224EC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800224F0:
    // 0x800224F0: bne         $s6, $a1, L_800224D0
    if (ctx->r22 != ctx->r5) {
        // 0x800224F4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800224D0;
    }
    // 0x800224F4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800224F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800224FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022500: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80022504: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80022508: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002250C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80022510: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80022514: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80022518: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002251C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80022520: jr          $ra
    // 0x80022524: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80022524: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022528(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002252C: sb          $zero, -0x424D($at)
    MEM_B(-0X424D, ctx->r1) = 0;
    // 0x80022530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022538: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002253C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022540: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022544: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80022548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002254C: sb          $zero, -0x4230($at)
    MEM_B(-0X4230, ctx->r1) = 0;
    // 0x80022550: addiu       $a1, $a1, -0x4427
    ctx->r5 = ADD32(ctx->r5, -0X4427);
    // 0x80022554: addiu       $v0, $v0, -0x4428
    ctx->r2 = ADD32(ctx->r2, -0X4428);
    // 0x80022558: addiu       $a0, $a0, -0x446F
    ctx->r4 = ADD32(ctx->r4, -0X446F);
    // 0x8002255C: addiu       $v1, $v1, -0x4470
    ctx->r3 = ADD32(ctx->r3, -0X4470);
L_80022560:
    // 0x80022560: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022564: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80022568: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002256C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022570: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80022574: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
    // 0x80022578: bne         $at, $zero, L_80022560
    if (ctx->r1 != 0) {
        // 0x8002257C: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80022560;
    }
    // 0x8002257C: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80022580: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022584: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022588: addiu       $v0, $v0, -0x4530
    ctx->r2 = ADD32(ctx->r2, -0X4530);
    // 0x8002258C: sb          $zero, -0x44E0($at)
    MEM_B(-0X44E0, ctx->r1) = 0;
    // 0x80022590: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80022594: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80022598: lui         $ra, 0x800D
    ctx->r31 = S32(0X800D << 16);
    // 0x8002259C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800225A0: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x800225A4: addiu       $v1, $v1, 0x5520
    ctx->r3 = ADD32(ctx->r3, 0X5520);
    // 0x800225A8: addiu       $a3, $a3, -0x425C
    ctx->r7 = ADD32(ctx->r7, -0X425C);
    // 0x800225AC: lhu         $ra, -0x453E($ra)
    ctx->r31 = MEM_HU(ctx->r31, -0X453E);
    // 0x800225B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800225B4: addiu       $t5, $zero, 0x214
    ctx->r13 = ADD32(0, 0X214);
    // 0x800225B8: addiu       $t4, $zero, 0x213
    ctx->r12 = ADD32(0, 0X213);
    // 0x800225BC: addiu       $t3, $zero, 0x12A
    ctx->r11 = ADD32(0, 0X12A);
    // 0x800225C0: addiu       $t2, $zero, 0x125
    ctx->r10 = ADD32(0, 0X125);
    // 0x800225C4: addiu       $t1, $zero, 0x122
    ctx->r9 = ADD32(0, 0X122);
    // 0x800225C8: addiu       $t0, $zero, 0x11E
    ctx->r8 = ADD32(0, 0X11E);
    // 0x800225CC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800225D0: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
L_800225D4:
    // 0x800225D4: beq         $ra, $zero, L_8002262C
    if (ctx->r31 == 0) {
        // 0x800225D8: nop
    
            goto L_8002262C;
    }
    // 0x800225D8: nop

    // 0x800225DC: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800225E0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800225E4: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x800225E8: beql        $v0, $t0, L_80022640
    if (ctx->r2 == ctx->r8) {
        // 0x800225EC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_0;
    // 0x800225EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800225F0: beql        $v0, $t1, L_80022640
    if (ctx->r2 == ctx->r9) {
        // 0x800225F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_1;
    // 0x800225F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x800225F8: beql        $v0, $t2, L_80022640
    if (ctx->r2 == ctx->r10) {
        // 0x800225FC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_2;
    // 0x800225FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x80022600: beql        $v0, $t3, L_80022640
    if (ctx->r2 == ctx->r11) {
        // 0x80022604: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_3;
    // 0x80022604: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
    // 0x80022608: beql        $v0, $t4, L_80022640
    if (ctx->r2 == ctx->r12) {
        // 0x8002260C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_4;
    // 0x8002260C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
    // 0x80022610: beql        $v0, $t5, L_80022640
    if (ctx->r2 == ctx->r13) {
        // 0x80022614: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022640;
    }
    goto skip_5;
    // 0x80022614: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_5:
    // 0x80022618: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002261C: mflo        $t8
    ctx->r24 = lo;
    // 0x80022620: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80022624: b           L_8002263C
    // 0x80022628: sw          $a2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r6;
        goto L_8002263C;
    // 0x80022628: sw          $a2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r6;
L_8002262C:
    // 0x8002262C: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022630: mflo        $t6
    ctx->r14 = lo;
    // 0x80022634: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80022638: sw          $a2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r6;
L_8002263C:
    // 0x8002263C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80022640:
    // 0x80022640: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x80022644: bne         $at, $zero, L_800225D4
    if (ctx->r1 != 0) {
        // 0x80022648: nop
    
            goto L_800225D4;
    }
    // 0x80022648: nop

    // 0x8002264C: jal         0x80022694
    // 0x80022650: nop

    LOOKUP_FUNC(0x80022694)(rdram, ctx);
        goto after_0;
    // 0x80022650: nop

    after_0:
    // 0x80022654: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022658: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002265C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022660: addiu       $a0, $a0, -0x4536
    ctx->r4 = ADD32(ctx->r4, -0X4536);
    // 0x80022664: addiu       $v1, $v1, -0x4538
    ctx->r3 = ADD32(ctx->r3, -0X4538);
    // 0x80022668: addiu       $v0, $v0, -0x453C
    ctx->r2 = ADD32(ctx->r2, -0X453C);
L_8002266C:
    // 0x8002266C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80022670: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022674: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
    // 0x80022678: bne         $v1, $a0, L_8002266C
    if (ctx->r3 != ctx->r4) {
        // 0x8002267C: sh          $zero, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = 0;
            goto L_8002266C;
    }
    // 0x8002267C: sh          $zero, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = 0;
    // 0x80022680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022684: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022688: sh          $zero, -0x453E($at)
    MEM_H(-0X453E, ctx->r1) = 0;
    // 0x8002268C: jr          $ra
    // 0x80022690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80022690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022694(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022694: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022698: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002269C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800226A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800226A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800226A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800226AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800226B0: addiu       $v1, $v1, -0x424D
    ctx->r3 = ADD32(ctx->r3, -0X424D);
    // 0x800226B4: addiu       $v0, $v0, -0x4250
    ctx->r2 = ADD32(ctx->r2, -0X4250);
L_800226B8:
    // 0x800226B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800226BC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800226C0: bne         $at, $zero, L_800226B8
    if (ctx->r1 != 0) {
        // 0x800226C4: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_800226B8;
    }
    // 0x800226C4: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800226C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800226CC: sh          $zero, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = 0;
    // 0x800226D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800226D4: sb          $zero, -0x44B2($at)
    MEM_B(-0X44B2, ctx->r1) = 0;
    // 0x800226D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800226DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800226E0: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x800226E4: addiu       $v0, $v0, -0x4536
    ctx->r2 = ADD32(ctx->r2, -0X4536);
    // 0x800226E8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800226EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800226F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800226F4: sb          $zero, -0x4534($at)
    MEM_B(-0X4534, ctx->r1) = 0;
    // 0x800226F8: addiu       $v1, $v1, -0x4532
    ctx->r3 = ADD32(ctx->r3, -0X4532);
    // 0x800226FC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022700: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80022704: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022708: addiu       $a0, $a0, -0x454A
    ctx->r4 = ADD32(ctx->r4, -0X454A);
    // 0x8002270C: sb          $zero, -0x4533($at)
    MEM_B(-0X4533, ctx->r1) = 0;
    // 0x80022710: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80022714: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x80022718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002271C: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80022720: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x80022724: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80022728: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x8002272C: sb          $t8, -0x4549($at)
    MEM_B(-0X4549, ctx->r1) = ctx->r24;
L_80022730:
    // 0x80022730: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80022734: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80022738: sltiu       $at, $v0, 0x10
    ctx->r1 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8002273C: bne         $at, $zero, L_80022754
    if (ctx->r1 != 0) {
        // 0x80022740: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_80022754;
    }
    // 0x80022740: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80022744: beql        $at, $zero, L_80022758
    if (ctx->r1 == 0) {
        // 0x80022748: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022758;
    }
    goto skip_0;
    // 0x80022748: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8002274C: jal         0x80022874
    // 0x80022750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80022874)(rdram, ctx);
        goto after_0;
    // 0x80022750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80022754:
    // 0x80022754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80022758:
    // 0x80022758: bne         $s0, $s2, L_80022730
    if (ctx->r16 != ctx->r18) {
        // 0x8002275C: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_80022730;
    }
    // 0x8002275C: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
    // 0x80022760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022768: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002276C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80022770: jr          $ra
    // 0x80022774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022778(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002277C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022780: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80022784: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80022788: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8002278C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022790: addiu       $a1, $a1, 0x6600
    ctx->r5 = ADD32(ctx->r5, 0X6600);
    // 0x80022794: addiu       $v0, $v0, 0x5520
    ctx->r2 = ADD32(ctx->r2, 0X5520);
    // 0x80022798: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_8002279C:
    // 0x8002279C: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x800227A0: sltiu       $at, $v1, 0x10
    ctx->r1 = ctx->r3 < 0X10 ? 1 : 0;
    // 0x800227A4: bne         $at, $zero, L_800227D0
    if (ctx->r1 != 0) {
        // 0x800227A8: sltiu       $at, $v1, 0x100
        ctx->r1 = ctx->r3 < 0X100 ? 1 : 0;
            goto L_800227D0;
    }
    // 0x800227A8: sltiu       $at, $v1, 0x100
    ctx->r1 = ctx->r3 < 0X100 ? 1 : 0;
    // 0x800227AC: beql        $at, $zero, L_800227D4
    if (ctx->r1 == 0) {
        // 0x800227B0: addiu       $v0, $v0, 0xD8
        ctx->r2 = ADD32(ctx->r2, 0XD8);
            goto L_800227D4;
    }
    goto skip_0;
    // 0x800227B0: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    skip_0:
    // 0x800227B4: lbu         $t6, 0xD5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD5);
    // 0x800227B8: bne         $a0, $t6, L_800227D0
    if (ctx->r4 != ctx->r14) {
        // 0x800227BC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800227D0;
    }
    // 0x800227BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800227C0: jal         0x80022C8C
    // 0x800227C4: sw          $v1, -0x44B8($at)
    MEM_W(-0X44B8, ctx->r1) = ctx->r3;
    LOOKUP_FUNC(0x80022C8C)(rdram, ctx);
        goto after_0;
    // 0x800227C4: sw          $v1, -0x44B8($at)
    MEM_W(-0X44B8, ctx->r1) = ctx->r3;
    after_0:
    // 0x800227C8: b           L_800227E0
    // 0x800227CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800227E0;
    // 0x800227CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800227D0:
    // 0x800227D0: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
L_800227D4:
    // 0x800227D4: bnel        $v0, $a1, L_8002279C
    if (ctx->r2 != ctx->r5) {
        // 0x800227D8: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_8002279C;
    }
    goto skip_1;
    // 0x800227D8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800227DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800227E0:
    // 0x800227E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800227E4: jr          $ra
    // 0x800227E8: nop

    return;
    // 0x800227E8: nop

;}
RECOMP_FUNC void FUN_800227ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800227EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800227F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800227F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800227F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800227FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80022800: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80022804: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x80022808: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002280C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80022810: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x80022814: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80022818: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
L_8002281C:
    // 0x8002281C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80022820: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80022824: sltiu       $at, $v0, 0x10
    ctx->r1 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x80022828: bne         $at, $zero, L_8002284C
    if (ctx->r1 != 0) {
        // 0x8002282C: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_8002284C;
    }
    // 0x8002282C: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80022830: beql        $at, $zero, L_80022850
    if (ctx->r1 == 0) {
        // 0x80022834: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022850;
    }
    goto skip_0;
    // 0x80022834: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80022838: lbu         $t6, 0xD5($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XD5);
    // 0x8002283C: bnel        $s2, $t6, L_80022850
    if (ctx->r18 != ctx->r14) {
        // 0x80022840: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022850;
    }
    goto skip_1;
    // 0x80022840: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80022844: jal         0x80022874
    // 0x80022848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80022874)(rdram, ctx);
        goto after_0;
    // 0x80022848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_8002284C:
    // 0x8002284C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80022850:
    // 0x80022850: bne         $s0, $s3, L_8002281C
    if (ctx->r16 != ctx->r19) {
        // 0x80022854: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_8002281C;
    }
    // 0x80022854: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
    // 0x80022858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002285C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80022860: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80022864: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022868: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002286C: jr          $ra
    // 0x80022870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022874(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022874: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80022878: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8002287C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80022880: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80022884: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80022888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002288C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022890: addiu       $t8, $t8, 0x5520
    ctx->r24 = ADD32(ctx->r24, 0X5520);
    // 0x80022894: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80022898: addiu       $v0, $v0, -0x425C
    ctx->r2 = ADD32(ctx->r2, -0X425C);
    // 0x8002289C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800228A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800228A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800228A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800228AC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800228B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800228B4: sb          $zero, 0x4($t1)
    MEM_B(0X4, ctx->r9) = 0;
    // 0x800228B8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800228BC: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x800228C0: beql        $at, $zero, L_80022924
    if (ctx->r1 == 0) {
        // 0x800228C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022924;
    }
    goto skip_0;
    // 0x800228C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800228C8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800228CC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800228D0: lbu         $t3, 0xE($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XE);
    // 0x800228D4: beql        $t3, $zero, L_80022924
    if (ctx->r11 == 0) {
        // 0x800228D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022924;
    }
    goto skip_1;
    // 0x800228D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800228DC: sb          $t4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r12;
    // 0x800228E0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800228E4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800228E8: addiu       $t9, $t9, -0x4420
    ctx->r25 = ADD32(ctx->r25, -0X4420);
    // 0x800228EC: sh          $zero, 0xB4($t5)
    MEM_H(0XB4, ctx->r13) = 0;
    // 0x800228F0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800228F4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800228F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800228FC: sh          $zero, 0xB6($t6)
    MEM_H(0XB6, ctx->r14) = 0;
    // 0x80022900: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80022904: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80022908: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    // 0x8002290C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80022910: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80022914: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80022918: jal         0x80026950
    // 0x8002291C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    LOOKUP_FUNC(0x80026950)(rdram, ctx);
        goto after_0;
    // 0x8002291C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80022920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80022924:
    // 0x80022924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022928: jr          $ra
    // 0x8002292C: nop

    return;
    // 0x8002292C: nop

;}
RECOMP_FUNC void FUN_80022930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022930: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022934: lbu         $t6, -0x4549($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4549);
    // 0x80022938: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8002293C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80022940: beq         $t6, $at, L_8002294C
    if (ctx->r14 == ctx->r1) {
        // 0x80022944: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8002294C;
    }
    // 0x80022944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022948: sb          $t7, -0x454A($at)
    MEM_B(-0X454A, ctx->r1) = ctx->r15;
L_8002294C:
    // 0x8002294C: jr          $ra
    // 0x80022950: nop

    return;
    // 0x80022950: nop

;}
RECOMP_FUNC void FUN_80022954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022954: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022958: lbu         $t6, -0x4549($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4549);
    // 0x8002295C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80022960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022964: beq         $t6, $zero, L_80022970
    if (ctx->r14 == 0) {
        // 0x80022968: nop
    
            goto L_80022970;
    }
    // 0x80022968: nop

    // 0x8002296C: sb          $t7, -0x454A($at)
    MEM_B(-0X454A, ctx->r1) = ctx->r15;
L_80022970:
    // 0x80022970: jr          $ra
    // 0x80022974: nop

    return;
    // 0x80022974: nop

;}
RECOMP_FUNC void FUN_80022978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022978: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002297C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80022980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022984: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80022988: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002298C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80022990: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80022994: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80022998: beq         $t6, $zero, L_800229E0
    if (ctx->r14 == 0) {
        // 0x8002299C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800229E0;
    }
    // 0x8002299C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800229A0: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x800229A4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800229A8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800229AC: addiu       $s2, $s2, -0x425C
    ctx->r18 = ADD32(ctx->r18, -0X425C);
    // 0x800229B0: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x800229B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800229B8: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800229BC:
    // 0x800229BC: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x800229C0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800229C4: beql        $t8, $zero, L_800229D8
    if (ctx->r24 == 0) {
        // 0x800229C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800229D8;
    }
    goto skip_0;
    // 0x800229C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800229CC: jal         0x80022A84
    // 0x800229D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x800229D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800229D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800229D8:
    // 0x800229D8: bne         $s0, $s3, L_800229BC
    if (ctx->r16 != ctx->r19) {
        // 0x800229DC: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_800229BC;
    }
    // 0x800229DC: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
L_800229E0:
    // 0x800229E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800229E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800229E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800229EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800229F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800229F4: jr          $ra
    // 0x800229F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800229F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800229fc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800229fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800229FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022A00: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80022A04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022A08: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80022A0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022A10: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80022A14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80022A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80022A1C: bne         $t6, $zero, L_80022A68
    if (ctx->r14 != 0) {
        // 0x80022A20: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80022A68;
    }
    // 0x80022A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80022A24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022A28: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80022A2C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80022A30: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80022A34: addiu       $s2, $s2, -0x425C
    ctx->r18 = ADD32(ctx->r18, -0X425C);
    // 0x80022A38: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x80022A3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80022A40: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_80022A44:
    // 0x80022A44: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x80022A48: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80022A4C: beql        $t9, $zero, L_80022A60
    if (ctx->r25 == 0) {
        // 0x80022A50: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022A60;
    }
    goto skip_0;
    // 0x80022A50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80022A54: jal         0x80022A84
    // 0x80022A58: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x80022A58: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80022A5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80022A60:
    // 0x80022A60: bne         $s0, $s3, L_80022A44
    if (ctx->r16 != ctx->r19) {
        // 0x80022A64: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_80022A44;
    }
    // 0x80022A64: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
L_80022A68:
    // 0x80022A68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022A6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80022A70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80022A74: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022A78: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80022A7C: jr          $ra
    // 0x80022A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022a84(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022a84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022A84: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80022A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022A8C: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x80022A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022A94: beq         $at, $zero, L_80022B5C
    if (ctx->r1 == 0) {
        // 0x80022A98: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80022B5C;
    }
    // 0x80022A98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022A9C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80022AA0: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80022AA4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80022AA8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80022AAC: sll         $t1, $a3, 3
    ctx->r9 = S32(ctx->r7 << 3);
    // 0x80022AB0: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x80022AB4: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x80022AB8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80022ABC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80022AC0: sb          $t7, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r15;
    // 0x80022AC4: lbu         $t8, -0x4548($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4548);
    // 0x80022AC8: addiu       $t2, $t2, -0x4420
    ctx->r10 = ADD32(ctx->r10, -0X4420);
    // 0x80022ACC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80022AD0: beql        $t8, $zero, L_80022AE4
    if (ctx->r24 == 0) {
        // 0x80022AD4: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_80022AE4;
    }
    goto skip_0;
    // 0x80022AD4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80022AD8: b           L_80022B48
    // 0x80022ADC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_80022B48;
    // 0x80022ADC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x80022AE0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_80022AE4:
    // 0x80022AE4: lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X58);
    // 0x80022AE8: lh          $t9, 0xAC($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XAC);
    // 0x80022AEC: lh          $a0, 0xCA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XCA);
    // 0x80022AF0: sra         $v0, $v0, 8
    ctx->r2 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80022AF4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80022AF8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022AFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022B00: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80022B04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022B08: beq         $a0, $zero, L_80022B2C
    if (ctx->r4 == 0) {
        // 0x80022B0C: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80022B2C;
    }
    // 0x80022B0C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022B10: bgez        $a0, L_80022B20
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80022B14: sra         $t0, $a0, 8
        ctx->r8 = S32(SIGNED(ctx->r4) >> 8);
            goto L_80022B20;
    }
    // 0x80022B14: sra         $t0, $a0, 8
    ctx->r8 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80022B18: addiu       $at, $a0, 0xFF
    ctx->r1 = ADD32(ctx->r4, 0XFF);
    // 0x80022B1C: sra         $t0, $at, 8
    ctx->r8 = S32(SIGNED(ctx->r1) >> 8);
L_80022B20:
    // 0x80022B20: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80022B24: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022B28: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80022B2C:
    // 0x80022B2C: bgez        $v0, L_80022B3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80022B30: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80022B3C;
    }
    // 0x80022B30: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80022B34: b           L_80022B48
    // 0x80022B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80022B48;
    // 0x80022B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022B3C:
    // 0x80022B3C: bne         $at, $zero, L_80022B48
    if (ctx->r1 != 0) {
        // 0x80022B40: nop
    
            goto L_80022B48;
    }
    // 0x80022B40: nop

    // 0x80022B44: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80022B48:
    // 0x80022B48: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80022B4C: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80022B50: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80022B54: jal         0x8002B380
    // 0x80022B58: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x8002B380)(rdram, ctx);
        goto after_0;
    // 0x80022B58: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_0:
L_80022B5C:
    // 0x80022B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022B64: jr          $ra
    // 0x80022B68: nop

    return;
    // 0x80022B68: nop

;}
RECOMP_FUNC void FUN_80022b6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022B6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022B70: lw          $v0, -0x44B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44B8);
    // 0x80022B74: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80022B78: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022B7C: beq         $v0, $at, L_80022BAC
    if (ctx->r2 == ctx->r1) {
        // 0x80022B80: addiu       $v1, $v1, -0x4544
        ctx->r3 = ADD32(ctx->r3, -0X4544);
            goto L_80022BAC;
    }
    // 0x80022B80: addiu       $v1, $v1, -0x4544
    ctx->r3 = ADD32(ctx->r3, -0X4544);
    // 0x80022B84: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x80022B88: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80022B8C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80022B90: bne         $t6, $zero, L_80022BA0
    if (ctx->r14 != 0) {
        // 0x80022B94: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80022BA0;
    }
    // 0x80022B94: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80022B98: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80022B9C: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
L_80022BA0:
    // 0x80022BA0: lhu         $t9, 0x7E3A($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7E3A);
    // 0x80022BA4: jr          $ra
    // 0x80022BA8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x80022BA8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_80022BAC:
    // 0x80022BAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022BB0: addiu       $v1, $v1, -0x4540
    ctx->r3 = ADD32(ctx->r3, -0X4540);
    // 0x80022BB4: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x80022BB8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80022BBC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80022BC0: bne         $t0, $zero, L_80022BD0
    if (ctx->r8 != 0) {
        // 0x80022BC4: addu        $t3, $t3, $t2
        ctx->r11 = ADD32(ctx->r11, ctx->r10);
            goto L_80022BD0;
    }
    // 0x80022BC4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80022BC8: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80022BCC: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
L_80022BD0:
    // 0x80022BD0: lhu         $t3, 0x7E3A($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7E3A);
    // 0x80022BD4: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x80022BD8: jr          $ra
    // 0x80022BDC: nop

    return;
    // 0x80022BDC: nop

    // 0x80022BE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022BE4: addiu       $v0, $v0, -0x4540
    ctx->r2 = ADD32(ctx->r2, -0X4540);
    // 0x80022BE8: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x80022BEC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80022BF0: addiu       $t8, $zero, 0x199
    ctx->r24 = ADD32(0, 0X199);
    // 0x80022BF4: bne         $t6, $zero, L_80022C00
    if (ctx->r14 != 0) {
        // 0x80022BF8: nop
    
            goto L_80022C00;
    }
    // 0x80022BF8: nop

    // 0x80022BFC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
L_80022C00:
    // 0x80022C00: jr          $ra
    // 0x80022C04: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80022C04: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80022C08: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022C0C: lhu         $t6, -0x4536($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4536);
    // 0x80022C10: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80022C14: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80022C18: beq         $at, $zero, L_80022C24
    if (ctx->r1 == 0) {
        // 0x80022C1C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80022C24;
    }
    // 0x80022C1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022C20: sb          $t7, -0x4534($at)
    MEM_B(-0X4534, ctx->r1) = ctx->r15;
L_80022C24:
    // 0x80022C24: jr          $ra
    // 0x80022C28: nop

    return;
    // 0x80022C28: nop

    // 0x80022C2C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022C30: addiu       $v0, $v0, -0x4536
    ctx->r2 = ADD32(ctx->r2, -0X4536);
    // 0x80022C34: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80022C38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022C3C: jr          $ra
    // 0x80022C40: sb          $zero, -0x4534($at)
    MEM_B(-0X4534, ctx->r1) = 0;
    return;
    // 0x80022C40: sb          $zero, -0x4534($at)
    MEM_B(-0X4534, ctx->r1) = 0;
    // 0x80022C44: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022C48: lbu         $t6, -0x4532($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4532);
    // 0x80022C4C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80022C50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022C54: bne         $t6, $zero, L_80022C60
    if (ctx->r14 != 0) {
        // 0x80022C58: nop
    
            goto L_80022C60;
    }
    // 0x80022C58: nop

    // 0x80022C5C: sb          $t7, -0x4533($at)
    MEM_B(-0X4533, ctx->r1) = ctx->r15;
L_80022C60:
    // 0x80022C60: jr          $ra
    // 0x80022C64: nop

    return;
    // 0x80022C64: nop

    // 0x80022C68: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022C6C: lbu         $t6, -0x4532($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4532);
    // 0x80022C70: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80022C74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022C78: beq         $t6, $zero, L_80022C84
    if (ctx->r14 == 0) {
        // 0x80022C7C: nop
    
            goto L_80022C84;
    }
    // 0x80022C7C: nop

    // 0x80022C80: sb          $t7, -0x4533($at)
    MEM_B(-0X4533, ctx->r1) = ctx->r15;
L_80022C84:
    // 0x80022C84: jr          $ra
    // 0x80022C88: nop

    return;
    // 0x80022C88: nop

;}
RECOMP_FUNC void FUN_80022c8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022C8C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80022C90: addiu       $a1, $a1, -0x44B8
    ctx->r5 = ADD32(ctx->r5, -0X44B8);
    // 0x80022C94: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80022C98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022C9C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022CA0: andi        $v0, $t6, 0x7FFF
    ctx->r2 = ctx->r14 & 0X7FFF;
    // 0x80022CA4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80022CA8: addiu       $v1, $v1, -0x4536
    ctx->r3 = ADD32(ctx->r3, -0X4536);
    // 0x80022CAC: addiu       $a0, $a0, -0x4538
    ctx->r4 = ADD32(ctx->r4, -0X4538);
    // 0x80022CB0: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
L_80022CB4:
    // 0x80022CB4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80022CB8: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80022CBC: beq         $v0, $t8, L_80022D18
    if (ctx->r2 == ctx->r24) {
        // 0x80022CC0: nop
    
            goto L_80022D18;
    }
    // 0x80022CC0: nop

    // 0x80022CC4: bnel        $at, $zero, L_80022CB4
    if (ctx->r1 != 0) {
        // 0x80022CC8: lhu         $t8, 0x0($a0)
        ctx->r24 = MEM_HU(ctx->r4, 0X0);
            goto L_80022CB4;
    }
    goto skip_0;
    // 0x80022CC8: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    skip_0:
    // 0x80022CCC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022CD0: addiu       $a0, $a0, -0x4538
    ctx->r4 = ADD32(ctx->r4, -0X4538);
    // 0x80022CD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80022CD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80022CDC:
    // 0x80022CDC: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80022CE0: bne         $t9, $zero, L_80022D0C
    if (ctx->r25 != 0) {
        // 0x80022CE4: lui         $t1, 0x800D
        ctx->r9 = S32(0X800D << 16);
            goto L_80022D0C;
    }
    // 0x80022CE4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80022CE8: addiu       $t1, $t1, -0x453C
    ctx->r9 = ADD32(ctx->r9, -0X453C);
    // 0x80022CEC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80022CF0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80022CF4: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x80022CF8: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80022CFC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80022D00: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x80022D04: jr          $ra
    // 0x80022D08: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    return;
    // 0x80022D08: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
L_80022D0C:
    // 0x80022D0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80022D10: bne         $v1, $a1, L_80022CDC
    if (ctx->r3 != ctx->r5) {
        // 0x80022D14: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80022CDC;
    }
    // 0x80022D14: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_80022D18:
    // 0x80022D18: jr          $ra
    // 0x80022D1C: nop

    return;
    // 0x80022D1C: nop

;}
RECOMP_FUNC void FUN_80022d20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022D24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80022D28: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x80022D2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80022D30: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80022D34: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80022D38: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80022D3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80022D40: addiu       $t8, $t8, -0x4538
    ctx->r24 = ADD32(ctx->r24, -0X4538);
    // 0x80022D44: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80022D48: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80022D4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022D50: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
    // 0x80022D54: addiu       $s1, $s1, 0x5520
    ctx->r17 = ADD32(ctx->r17, 0X5520);
    // 0x80022D58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80022D5C: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80022D60:
    // 0x80022D60: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80022D64: lhu         $t9, 0x0($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X0);
    // 0x80022D68: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80022D6C: bnel        $t9, $t1, L_80022D80
    if (ctx->r25 != ctx->r9) {
        // 0x80022D70: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022D80;
    }
    goto skip_0;
    // 0x80022D70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80022D74: jal         0x80022874
    // 0x80022D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80022874)(rdram, ctx);
        goto after_0;
    // 0x80022D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80022D7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80022D80:
    // 0x80022D80: bne         $s0, $s2, L_80022D60
    if (ctx->r16 != ctx->r18) {
        // 0x80022D84: addiu       $s1, $s1, 0xD8
        ctx->r17 = ADD32(ctx->r17, 0XD8);
            goto L_80022D60;
    }
    // 0x80022D84: addiu       $s1, $s1, 0xD8
    ctx->r17 = ADD32(ctx->r17, 0XD8);
    // 0x80022D88: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x80022D8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022D90: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80022D94: addiu       $t4, $t4, -0x453C
    ctx->r12 = ADD32(ctx->r12, -0X453C);
    // 0x80022D98: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x80022D9C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80022DA0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80022DA4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80022DA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80022DAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80022DB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022DB4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80022DB8: jr          $ra
    // 0x80022DBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022DBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80022dc0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80022dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022DC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80022DC4: addiu       $v0, $v0, -0x4428
    ctx->r2 = ADD32(ctx->r2, -0X4428);
    // 0x80022DC8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80022DCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022DD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022DD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022DD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022DDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80022DE0: bne         $t6, $at, L_80022E04
    if (ctx->r14 != ctx->r1) {
        // 0x80022DE4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022E04;
    }
    // 0x80022DE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022DE8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80022DEC: lw          $t7, 0x61C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X61C8);
    // 0x80022DF0: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x80022DF4: sltiu       $at, $t8, 0x607
    ctx->r1 = ctx->r24 < 0X607 ? 1 : 0;
    // 0x80022DF8: beq         $at, $zero, L_80022E04
    if (ctx->r1 == 0) {
        // 0x80022DFC: nop
    
            goto L_80022E04;
    }
    // 0x80022DFC: nop

    // 0x80022E00: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80022E04:
    // 0x80022E04: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022E08: addiu       $a0, $a0, -0x454A
    ctx->r4 = ADD32(ctx->r4, -0X454A);
    // 0x80022E0C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80022E10: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80022E14: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80022E18: beq         $v0, $zero, L_80022E68
    if (ctx->r2 == 0) {
        // 0x80022E1C: nop
    
            goto L_80022E68;
    }
    // 0x80022E1C: nop

    // 0x80022E20: lhu         $t9, -0x454E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X454E);
    // 0x80022E24: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022E28: addiu       $v1, $v1, -0x4549
    ctx->r3 = ADD32(ctx->r3, -0X4549);
    // 0x80022E2C: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80022E30: bne         $t0, $zero, L_80022E68
    if (ctx->r8 != 0) {
        // 0x80022E34: nop
    
            goto L_80022E68;
    }
    // 0x80022E34: nop

    // 0x80022E38: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80022E3C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80022E40: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80022E44: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80022E48: beq         $at, $zero, L_80022E68
    if (ctx->r1 == 0) {
        // 0x80022E4C: sb          $t2, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r10;
            goto L_80022E68;
    }
    // 0x80022E4C: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80022E50: bgez        $v0, L_80022E60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80022E54: addiu       $t4, $zero, 0x7F
        ctx->r12 = ADD32(0, 0X7F);
            goto L_80022E60;
    }
    // 0x80022E54: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x80022E58: b           L_80022E64
    // 0x80022E5C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
        goto L_80022E64;
    // 0x80022E5C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_80022E60:
    // 0x80022E60: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80022E64:
    // 0x80022E64: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80022E68:
    // 0x80022E68: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022E6C: addiu       $v1, $v1, -0x4540
    ctx->r3 = ADD32(ctx->r3, -0X4540);
    // 0x80022E70: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80022E74: beq         $v0, $zero, L_80022EBC
    if (ctx->r2 == 0) {
        // 0x80022E78: nop
    
            goto L_80022EBC;
    }
    // 0x80022E78: nop

    // 0x80022E7C: lbu         $t5, -0x454B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X454B);
    // 0x80022E80: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022E84: bne         $t5, $zero, L_80022EBC
    if (ctx->r13 != 0) {
        // 0x80022E88: nop
    
            goto L_80022EBC;
    }
    // 0x80022E88: nop

    // 0x80022E8C: lhu         $t6, -0x454E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X454E);
    // 0x80022E90: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80022E94: bne         $t7, $zero, L_80022EBC
    if (ctx->r15 != 0) {
        // 0x80022E98: nop
    
            goto L_80022EBC;
    }
    // 0x80022E98: nop

    // 0x80022E9C: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80022EA0: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80022EA4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80022EA8: slti        $at, $t0, 0x1000
    ctx->r1 = SIGNED(ctx->r8) < 0X1000 ? 1 : 0;
    // 0x80022EAC: beq         $at, $zero, L_80022EBC
    if (ctx->r1 == 0) {
        // 0x80022EB0: sh          $t9, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r25;
            goto L_80022EBC;
    }
    // 0x80022EB0: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80022EB4: jal         0x80022528
    // 0x80022EB8: nop

    LOOKUP_FUNC(0x80022528)(rdram, ctx);
        goto after_0;
    // 0x80022EB8: nop

    after_0:
L_80022EBC:
    // 0x80022EBC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022EC0: addiu       $v1, $v1, -0x4544
    ctx->r3 = ADD32(ctx->r3, -0X4544);
    // 0x80022EC4: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80022EC8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022ECC: lbu         $a0, -0x454B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454B);
    // 0x80022ED0: beq         $v0, $zero, L_80022F18
    if (ctx->r2 == 0) {
        // 0x80022ED4: nop
    
            goto L_80022F18;
    }
    // 0x80022ED4: nop

    // 0x80022ED8: bne         $a0, $zero, L_80022F18
    if (ctx->r4 != 0) {
        // 0x80022EDC: lui         $t1, 0x800D
        ctx->r9 = S32(0X800D << 16);
            goto L_80022F18;
    }
    // 0x80022EDC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80022EE0: lhu         $t1, -0x454E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X454E);
    // 0x80022EE4: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x80022EE8: bne         $t2, $zero, L_80022F18
    if (ctx->r10 != 0) {
        // 0x80022EEC: nop
    
            goto L_80022F18;
    }
    // 0x80022EEC: nop

    // 0x80022EF0: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x80022EF4: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80022EF8: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80022EFC: slti        $at, $t5, 0x1000
    ctx->r1 = SIGNED(ctx->r13) < 0X1000 ? 1 : 0;
    // 0x80022F00: beq         $at, $zero, L_80022F18
    if (ctx->r1 == 0) {
        // 0x80022F04: sh          $t4, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r12;
            goto L_80022F18;
    }
    // 0x80022F04: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x80022F08: jal         0x80022694
    // 0x80022F0C: nop

    LOOKUP_FUNC(0x80022694)(rdram, ctx);
        goto after_1;
    // 0x80022F0C: nop

    after_1:
    // 0x80022F10: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022F14: lbu         $a0, -0x454B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X454B);
L_80022F18:
    // 0x80022F18: bne         $a0, $zero, L_80022F90
    if (ctx->r4 != 0) {
        // 0x80022F1C: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_80022F90;
    }
    // 0x80022F1C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80022F20: lhu         $t6, -0x454E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X454E);
    // 0x80022F24: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022F28: addiu       $v1, $v1, -0x4538
    ctx->r3 = ADD32(ctx->r3, -0X4538);
    // 0x80022F2C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80022F30: bne         $t7, $zero, L_80022F90
    if (ctx->r15 != 0) {
        // 0x80022F34: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80022F90;
    }
    // 0x80022F34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80022F38: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80022F3C: addiu       $s1, $s1, -0x453C
    ctx->r17 = ADD32(ctx->r17, -0X453C);
    // 0x80022F40: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80022F44:
    // 0x80022F44: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80022F48: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80022F4C: addu        $v0, $s1, $t9
    ctx->r2 = ADD32(ctx->r17, ctx->r25);
    // 0x80022F50: beql        $t8, $zero, L_80022F88
    if (ctx->r24 == 0) {
        // 0x80022F54: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80022F88;
    }
    goto skip_0;
    // 0x80022F54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80022F58: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x80022F5C: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80022F60: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80022F64: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80022F68: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80022F6C: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x80022F70: beq         $at, $zero, L_80022F84
    if (ctx->r1 == 0) {
        // 0x80022F74: sh          $t2, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r10;
            goto L_80022F84;
    }
    // 0x80022F74: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80022F78: jal         0x80022D20
    // 0x80022F7C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80022D20)(rdram, ctx);
        goto after_2;
    // 0x80022F7C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80022F80: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80022F84:
    // 0x80022F84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80022F88:
    // 0x80022F88: bne         $s0, $s2, L_80022F44
    if (ctx->r16 != ctx->r18) {
        // 0x80022F8C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80022F44;
    }
    // 0x80022F8C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80022F90:
    // 0x80022F90: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80022F94: addiu       $v1, $v1, -0x4534
    ctx->r3 = ADD32(ctx->r3, -0X4534);
    // 0x80022F98: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80022F9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80022FA0: addiu       $a0, $a0, -0x4533
    ctx->r4 = ADD32(ctx->r4, -0X4533);
    // 0x80022FA4: beq         $v0, $zero, L_80022FEC
    if (ctx->r2 == 0) {
        // 0x80022FA8: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_80022FEC;
    }
    // 0x80022FA8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80022FAC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80022FB0: lbu         $t4, -0x454B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X454B);
    // 0x80022FB4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80022FB8: bnel        $t4, $zero, L_80022FF0
    if (ctx->r12 != 0) {
        // 0x80022FBC: lb          $v0, 0x0($a0)
        ctx->r2 = MEM_B(ctx->r4, 0X0);
            goto L_80022FF0;
    }
    goto skip_1;
    // 0x80022FBC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    skip_1:
    // 0x80022FC0: lhu         $t5, -0x454E($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X454E);
    // 0x80022FC4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80022FC8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80022FCC: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x80022FD0: bnel        $t6, $zero, L_80022FF0
    if (ctx->r14 != 0) {
        // 0x80022FD4: lb          $v0, 0x0($a0)
        ctx->r2 = MEM_B(ctx->r4, 0X0);
            goto L_80022FF0;
    }
    goto skip_2;
    // 0x80022FD4: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    skip_2:
    // 0x80022FD8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80022FDC: lhu         $t8, -0x4536($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4536);
    // 0x80022FE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80022FE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80022FE8: sh          $t9, -0x4536($at)
    MEM_H(-0X4536, ctx->r1) = ctx->r25;
L_80022FEC:
    // 0x80022FEC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
L_80022FF0:
    // 0x80022FF0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80022FF4: addiu       $s1, $s1, -0x454C
    ctx->r17 = ADD32(ctx->r17, -0X454C);
    // 0x80022FF8: beq         $v0, $zero, L_80023048
    if (ctx->r2 == 0) {
        // 0x80022FFC: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_80023048;
    }
    // 0x80022FFC: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80023000: lhu         $t0, -0x454E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X454E);
    // 0x80023004: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80023008: addiu       $v1, $v1, -0x4532
    ctx->r3 = ADD32(ctx->r3, -0X4532);
    // 0x8002300C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80023010: bnel        $t1, $zero, L_8002304C
    if (ctx->r9 != 0) {
        // 0x80023014: andi        $v0, $zero, 0xFF
        ctx->r2 = 0 & 0XFF;
            goto L_8002304C;
    }
    goto skip_3;
    // 0x80023014: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    skip_3:
    // 0x80023018: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x8002301C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80023020: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80023024: slti        $at, $t4, 0xB1
    ctx->r1 = SIGNED(ctx->r12) < 0XB1 ? 1 : 0;
    // 0x80023028: beq         $at, $zero, L_80023048
    if (ctx->r1 == 0) {
        // 0x8002302C: sb          $t3, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r11;
            goto L_80023048;
    }
    // 0x8002302C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80023030: bgez        $v0, L_80023040
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80023034: addiu       $t5, $zero, 0xB0
        ctx->r13 = ADD32(0, 0XB0);
            goto L_80023040;
    }
    // 0x80023034: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x80023038: b           L_80023044
    // 0x8002303C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_80023044;
    // 0x8002303C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_80023040:
    // 0x80023040: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80023044:
    // 0x80023044: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80023048:
    // 0x80023048: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_8002304C:
    // 0x8002304C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80023050: beq         $at, $zero, L_8002315C
    if (ctx->r1 == 0) {
        // 0x80023054: sb          $zero, 0x0($s1)
        MEM_B(0X0, ctx->r17) = 0;
            goto L_8002315C;
    }
    // 0x80023054: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80023058: addiu       $s2, $s2, -0x425C
    ctx->r18 = ADD32(ctx->r18, -0X425C);
L_8002305C:
    // 0x8002305C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80023060: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80023064: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80023068: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8002306C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80023070: addiu       $t7, $t7, 0x5520
    ctx->r15 = ADD32(ctx->r15, 0X5520);
    // 0x80023074: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80023078: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002307C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80023080: lbu         $v1, 0xF($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0XF);
    // 0x80023084: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80023088: beq         $v1, $zero, L_800230E0
    if (ctx->r3 == 0) {
        // 0x8002308C: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_800230E0;
    }
    // 0x8002308C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80023090: sb          $t9, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r25;
    // 0x80023094: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80023098: lbu         $t0, 0xF($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XF);
    // 0x8002309C: bnel        $t0, $zero, L_800230E4
    if (ctx->r8 != 0) {
        // 0x800230A0: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800230E4;
    }
    goto skip_4;
    // 0x800230A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800230A4: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x800230A8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800230AC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800230B0: beql        $t1, $zero, L_800230E4
    if (ctx->r9 == 0) {
        // 0x800230B4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800230E4;
    }
    goto skip_5;
    // 0x800230B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x800230B8: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x800230BC: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x800230C0: addiu       $t4, $t4, -0x4420
    ctx->r12 = ADD32(ctx->r12, -0X4420);
    // 0x800230C4: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x800230C8: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800230CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800230D0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800230D4: jal         0x80034EE0
    // 0x800230D8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    LOOKUP_FUNC(0x80034EE0)(rdram, ctx);
        goto after_3;
    // 0x800230D8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x800230DC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800230E0:
    // 0x800230E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800230E4:
    // 0x800230E4: beql        $v0, $zero, L_80023148
    if (ctx->r2 == 0) {
        // 0x800230E8: lbu         $t1, 0x0($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X0);
            goto L_80023148;
    }
    goto skip_6;
    // 0x800230E8: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    skip_6:
    // 0x800230EC: lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X5);
    // 0x800230F0: andi        $t6, $v0, 0x7FFF
    ctx->r14 = ctx->r2 & 0X7FFF;
    // 0x800230F4: sltiu       $at, $t6, 0x100
    ctx->r1 = ctx->r14 < 0X100 ? 1 : 0;
    // 0x800230F8: beq         $v1, $zero, L_80023108
    if (ctx->r3 == 0) {
        // 0x800230FC: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80023108;
    }
    // 0x800230FC: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80023100: b           L_80023144
    // 0x80023104: sb          $t5, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r13;
        goto L_80023144;
    // 0x80023104: sb          $t5, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r13;
L_80023108:
    // 0x80023108: beq         $at, $zero, L_8002313C
    if (ctx->r1 == 0) {
        // 0x8002310C: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8002313C;
    }
    // 0x8002310C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80023110: lbu         $t7, -0x454B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X454B);
    // 0x80023114: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80023118: bnel        $t7, $zero, L_80023148
    if (ctx->r15 != 0) {
        // 0x8002311C: lbu         $t1, 0x0($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X0);
            goto L_80023148;
    }
    goto skip_7;
    // 0x8002311C: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    skip_7:
    // 0x80023120: lhu         $t8, 0x1A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1A);
    // 0x80023124: lhu         $t9, -0x4536($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4536);
    // 0x80023128: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002312C: jal         0x80023174
    // 0x80023130: sh          $t0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x80023174)(rdram, ctx);
        goto after_4;
    // 0x80023130: sh          $t0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r8;
    after_4:
    // 0x80023134: b           L_80023148
    // 0x80023138: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
        goto L_80023148;
    // 0x80023138: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
L_8002313C:
    // 0x8002313C: jal         0x80023174
    // 0x80023140: nop

    LOOKUP_FUNC(0x80023174)(rdram, ctx);
        goto after_5;
    // 0x80023140: nop

    after_5:
L_80023144:
    // 0x80023144: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
L_80023148:
    // 0x80023148: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002314C: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x80023150: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80023154: bne         $at, $zero, L_8002305C
    if (ctx->r1 != 0) {
        // 0x80023158: sb          $t2, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r10;
            goto L_8002305C;
    }
    // 0x80023158: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
L_8002315C:
    // 0x8002315C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023164: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80023168: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002316C: jr          $ra
    // 0x80023170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80023174(rdram, ctx);
;}
RECOMP_FUNC void FUN_80023174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023174: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80023178: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8002317C: lhu         $t6, -0x454E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X454E);
    // 0x80023180: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80023184: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80023188: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8002318C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80023190: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80023194: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80023198: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002319C: bne         $t7, $zero, L_800232B0
    if (ctx->r15 != 0) {
        // 0x800231A0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800232B0;
    }
    // 0x800231A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800231A4: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800231A8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800231AC: addiu       $s1, $s1, -0x425C
    ctx->r17 = ADD32(ctx->r17, -0X425C);
    // 0x800231B0: addiu       $s5, $s5, -0x454C
    ctx->r21 = ADD32(ctx->r21, -0X454C);
    // 0x800231B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800231B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800231BC: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800231C0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800231C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800231C8:
    // 0x800231C8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800231CC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800231D0: addiu       $t9, $t9, 0x7FD0
    ctx->r25 = ADD32(ctx->r25, 0X7FD0);
    // 0x800231D4: addu        $v0, $t8, $a1
    ctx->r2 = ADD32(ctx->r24, ctx->r5);
    // 0x800231D8: lh          $v1, 0xA2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA2);
    // 0x800231DC: lh          $a0, 0xA8($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA8);
    // 0x800231E0: beq         $v1, $a0, L_800232A4
    if (ctx->r3 == ctx->r4) {
        // 0x800231E4: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800232A4;
    }
    // 0x800231E4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800231E8: beq         $at, $zero, L_80023220
    if (ctx->r1 == 0) {
        // 0x800231EC: addu        $a2, $a1, $t9
        ctx->r6 = ADD32(ctx->r5, ctx->r25);
            goto L_80023220;
    }
    // 0x800231EC: addu        $a2, $a1, $t9
    ctx->r6 = ADD32(ctx->r5, ctx->r25);
    // 0x800231F0: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x800231F4: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800231F8: sh          $t1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r9;
    // 0x800231FC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80023200: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x80023204: lh          $v1, 0xA2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA2);
    // 0x80023208: lh          $t3, 0xA8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XA8);
    // 0x8002320C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80023210: beq         $at, $zero, L_8002324C
    if (ctx->r1 == 0) {
        // 0x80023214: nop
    
            goto L_8002324C;
    }
    // 0x80023214: nop

    // 0x80023218: b           L_8002324C
    // 0x8002321C: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
        goto L_8002324C;
    // 0x8002321C: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
L_80023220:
    // 0x80023220: lh          $t4, 0x0($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X0);
    // 0x80023224: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x80023228: sh          $t5, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r13;
    // 0x8002322C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80023230: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80023234: lh          $v1, 0xA2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA2);
    // 0x80023238: lh          $t7, 0xA8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA8);
    // 0x8002323C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023240: beq         $at, $zero, L_8002324C
    if (ctx->r1 == 0) {
        // 0x80023244: nop
    
            goto L_8002324C;
    }
    // 0x80023244: nop

    // 0x80023248: sh          $v1, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r3;
L_8002324C:
    // 0x8002324C: beql        $s0, $zero, L_80023270
    if (ctx->r16 == 0) {
        // 0x80023250: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_80023270;
    }
    goto skip_0;
    // 0x80023250: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80023254: beql        $s0, $s2, L_80023284
    if (ctx->r16 == ctx->r18) {
        // 0x80023258: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_80023284;
    }
    goto skip_1;
    // 0x80023258: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x8002325C: beql        $s0, $s3, L_80023298
    if (ctx->r16 == ctx->r19) {
        // 0x80023260: lbu         $a0, 0x0($s5)
        ctx->r4 = MEM_BU(ctx->r21, 0X0);
            goto L_80023298;
    }
    goto skip_2;
    // 0x80023260: lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X0);
    skip_2:
    // 0x80023264: b           L_800232A8
    // 0x80023268: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800232A8;
    // 0x80023268: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002326C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80023270:
    // 0x80023270: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x80023274: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80023278: b           L_800232A4
    // 0x8002327C: sb          $t9, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r25;
        goto L_800232A4;
    // 0x8002327C: sb          $t9, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r25;
    // 0x80023280: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80023284:
    // 0x80023284: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
    // 0x80023288: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8002328C: b           L_800232A4
    // 0x80023290: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
        goto L_800232A4;
    // 0x80023290: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    // 0x80023294: lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X0);
L_80023298:
    // 0x80023298: jal         0x80022A84
    // 0x8002329C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_0;
    // 0x8002329C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800232A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_800232A4:
    // 0x800232A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800232A8:
    // 0x800232A8: bne         $s0, $s4, L_800231C8
    if (ctx->r16 != ctx->r20) {
        // 0x800232AC: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800231C8;
    }
    // 0x800232AC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_800232B0:
    // 0x800232B0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800232B4: addiu       $s1, $s1, -0x425C
    ctx->r17 = ADD32(ctx->r17, -0X425C);
    // 0x800232B8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800232BC: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800232C0: addiu       $s5, $s5, -0x454C
    ctx->r21 = ADD32(ctx->r21, -0X454C);
    // 0x800232C4: lhu         $t3, 0x18($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X18);
    // 0x800232C8: lhu         $t2, 0x1A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X1A);
    // 0x800232CC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800232D0: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800232D4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800232D8: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x800232DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800232E0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800232E4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800232E8: lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1A);
    // 0x800232EC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800232F0: bne         $at, $zero, L_800234C8
    if (ctx->r1 != 0) {
        // 0x800232F4: andi        $t6, $v0, 0xFF
        ctx->r14 = ctx->r2 & 0XFF;
            goto L_800234C8;
    }
    // 0x800232F4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800232F8: sh          $t6, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r14;
    // 0x800232FC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80023300: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80023304: lbu         $a0, 0xBE($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XBE);
    // 0x80023308: beq         $a0, $zero, L_80023358
    if (ctx->r4 == 0) {
        // 0x8002330C: nop
    
            goto L_80023358;
    }
    // 0x8002330C: nop

    // 0x80023310: lbu         $t7, 0xBF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XBF);
    // 0x80023314: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80023318: subu        $v0, $v0, $t7
    ctx->r2 = SUB32(ctx->r2, ctx->r15);
    // 0x8002331C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023320: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023324: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80023328: beql        $at, $zero, L_80023344
    if (ctx->r1 == 0) {
        // 0x8002332C: sb          $v0, 0xBE($v1)
        MEM_B(0XBE, ctx->r3) = ctx->r2;
            goto L_80023344;
    }
    goto skip_3;
    // 0x8002332C: sb          $v0, 0xBE($v1)
    MEM_B(0XBE, ctx->r3) = ctx->r2;
    skip_3:
    // 0x80023330: jal         0x8002622C
    // 0x80023334: nop

    LOOKUP_FUNC(0x8002622C)(rdram, ctx);
        goto after_1;
    // 0x80023334: nop

    after_1:
    // 0x80023338: b           L_80023500
    // 0x8002333C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80023500;
    // 0x8002333C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80023340: sb          $v0, 0xBE($v1)
    MEM_B(0XBE, ctx->r3) = ctx->r2;
L_80023344:
    // 0x80023344: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80023348: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x8002334C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80023350: sb          $t9, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r25;
    // 0x80023354: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80023358:
    // 0x80023358: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
L_8002335C:
    // 0x8002335C: lbu         $a0, 0xD2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XD2);
    // 0x80023360: beq         $a0, $zero, L_80023404
    if (ctx->r4 == 0) {
        // 0x80023364: addiu       $t0, $a0, -0x1
        ctx->r8 = ADD32(ctx->r4, -0X1);
            goto L_80023404;
    }
    // 0x80023364: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80023368: sb          $t0, 0xD2($v0)
    MEM_B(0XD2, ctx->r2) = ctx->r8;
    // 0x8002336C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80023370: sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16 << 1);
    // 0x80023374: addu        $t1, $v1, $s0
    ctx->r9 = ADD32(ctx->r3, ctx->r16);
    // 0x80023378: lbu         $t3, 0xD2($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0XD2);
    // 0x8002337C: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x80023380: beql        $t3, $zero, L_800233A4
    if (ctx->r11 == 0) {
        // 0x80023384: lh          $t6, 0xC0($v0)
        ctx->r14 = MEM_H(ctx->r2, 0XC0);
            goto L_800233A4;
    }
    goto skip_4;
    // 0x80023384: lh          $t6, 0xC0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC0);
    skip_4:
    // 0x80023388: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8002338C: lh          $t2, 0xC6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XC6);
    // 0x80023390: lh          $t4, 0xCC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XCC);
    // 0x80023394: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80023398: b           L_800233A8
    // 0x8002339C: sh          $t5, 0xC6($v0)
    MEM_H(0XC6, ctx->r2) = ctx->r13;
        goto L_800233A8;
    // 0x8002339C: sh          $t5, 0xC6($v0)
    MEM_H(0XC6, ctx->r2) = ctx->r13;
    // 0x800233A0: lh          $t6, 0xC0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC0);
L_800233A4:
    // 0x800233A4: sh          $t6, 0xC6($v0)
    MEM_H(0XC6, ctx->r2) = ctx->r14;
L_800233A8:
    // 0x800233A8: beql        $s0, $zero, L_800233CC
    if (ctx->r16 == 0) {
        // 0x800233AC: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_800233CC;
    }
    goto skip_5;
    // 0x800233AC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x800233B0: beql        $s0, $s2, L_800233E4
    if (ctx->r16 == ctx->r18) {
        // 0x800233B4: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_800233E4;
    }
    goto skip_6;
    // 0x800233B4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_6:
    // 0x800233B8: beq         $s0, $s3, L_800233F8
    if (ctx->r16 == ctx->r19) {
        // 0x800233BC: nop
    
            goto L_800233F8;
    }
    // 0x800233BC: nop

    // 0x800233C0: b           L_80023404
    // 0x800233C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
        goto L_80023404;
    // 0x800233C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800233C8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_800233CC:
    // 0x800233CC: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    // 0x800233D0: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800233D4: sb          $t8, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r24;
    // 0x800233D8: b           L_80023404
    // 0x800233DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
        goto L_80023404;
    // 0x800233DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800233E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_800233E4:
    // 0x800233E4: lbu         $t9, 0x6($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X6);
    // 0x800233E8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800233EC: sb          $t0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r8;
    // 0x800233F0: b           L_80023404
    // 0x800233F4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
        goto L_80023404;
    // 0x800233F4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_800233F8:
    // 0x800233F8: jal         0x80022A84
    // 0x800233FC: lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X0);
    LOOKUP_FUNC(0x80022A84)(rdram, ctx);
        goto after_2;
    // 0x800233FC: lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X0);
    after_2:
    // 0x80023400: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80023404:
    // 0x80023404: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80023408: bnel        $s0, $s4, L_8002335C
    if (ctx->r16 != ctx->r20) {
        // 0x8002340C: addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
            goto L_8002335C;
    }
    goto skip_7;
    // 0x8002340C: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    skip_7:
    // 0x80023410: lbu         $t1, 0x21($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X21);
    // 0x80023414: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80023418: sb          $t3, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r11;
    // 0x8002341C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80023420: lbu         $t4, 0x21($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X21);
    // 0x80023424: bnel        $t4, $zero, L_80023458
    if (ctx->r12 != 0) {
        // 0x80023428: lbu         $t6, 0x0($s5)
        ctx->r14 = MEM_BU(ctx->r21, 0X0);
            goto L_80023458;
    }
    goto skip_8;
    // 0x80023428: lbu         $t6, 0x0($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X0);
    skip_8:
    // 0x8002342C: jal         0x80023520
    // 0x80023430: nop

    LOOKUP_FUNC(0x80023520)(rdram, ctx);
        goto after_3;
    // 0x80023430: nop

    after_3:
    // 0x80023434: jal         0x80025500
    // 0x80023438: nop

    LOOKUP_FUNC(0x80025500)(rdram, ctx);
        goto after_4;
    // 0x80023438: nop

    after_4:
    // 0x8002343C: lbu         $t5, 0x0($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X0);
    // 0x80023440: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80023444: bnel        $at, $zero, L_80023470
    if (ctx->r1 != 0) {
        // 0x80023448: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_80023470;
    }
    goto skip_9;
    // 0x80023448: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_9:
    // 0x8002344C: b           L_80023500
    // 0x80023450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80023500;
    // 0x80023450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80023454: lbu         $t6, 0x0($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X0);
L_80023458:
    // 0x80023458: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8002345C: beql        $at, $zero, L_80023500
    if (ctx->r1 == 0) {
        // 0x80023460: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80023500;
    }
    goto skip_10;
    // 0x80023460: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_10:
    // 0x80023464: jal         0x80023958
    // 0x80023468: nop

    LOOKUP_FUNC(0x80023958)(rdram, ctx);
        goto after_5;
    // 0x80023468: nop

    after_5:
    // 0x8002346C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_80023470:
    // 0x80023470: lbu         $t7, 0x1D($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1D);
    // 0x80023474: beql        $t7, $zero, L_80023490
    if (ctx->r15 == 0) {
        // 0x80023478: lbu         $t8, 0x47($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X47);
            goto L_80023490;
    }
    goto skip_11;
    // 0x80023478: lbu         $t8, 0x47($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X47);
    skip_11:
    // 0x8002347C: jal         0x800244C8
    // 0x80023480: nop

    LOOKUP_FUNC(0x800244C8)(rdram, ctx);
        goto after_6;
    // 0x80023480: nop

    after_6:
    // 0x80023484: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80023488: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
    // 0x8002348C: lbu         $t8, 0x47($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X47);
L_80023490:
    // 0x80023490: beql        $t8, $zero, L_800234AC
    if (ctx->r24 == 0) {
        // 0x80023494: lbu         $t9, 0x5B($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X5B);
            goto L_800234AC;
    }
    goto skip_12;
    // 0x80023494: lbu         $t9, 0x5B($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5B);
    skip_12:
    // 0x80023498: jal         0x80024918
    // 0x8002349C: nop

    LOOKUP_FUNC(0x80024918)(rdram, ctx);
        goto after_7;
    // 0x8002349C: nop

    after_7:
    // 0x800234A0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800234A4: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
    // 0x800234A8: lbu         $t9, 0x5B($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5B);
L_800234AC:
    // 0x800234AC: beql        $t9, $zero, L_800234EC
    if (ctx->r25 == 0) {
        // 0x800234B0: lbu         $t1, 0x92($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0X92);
            goto L_800234EC;
    }
    goto skip_13;
    // 0x800234B0: lbu         $t1, 0x92($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X92);
    skip_13:
    // 0x800234B4: jal         0x80024E0C
    // 0x800234B8: nop

    LOOKUP_FUNC(0x80024E0C)(rdram, ctx);
        goto after_8;
    // 0x800234B8: nop

    after_8:
    // 0x800234BC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800234C0: b           L_800234E8
    // 0x800234C4: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
        goto L_800234E8;
    // 0x800234C4: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
L_800234C8:
    // 0x800234C8: lbu         $t0, 0x0($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X0);
    // 0x800234CC: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800234D0: beql        $at, $zero, L_80023500
    if (ctx->r1 == 0) {
        // 0x800234D4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80023500;
    }
    goto skip_14;
    // 0x800234D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x800234D8: jal         0x80023B48
    // 0x800234DC: nop

    LOOKUP_FUNC(0x80023B48)(rdram, ctx);
        goto after_9;
    // 0x800234DC: nop

    after_9:
    // 0x800234E0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800234E4: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
L_800234E8:
    // 0x800234E8: lbu         $t1, 0x92($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X92);
L_800234EC:
    // 0x800234EC: beql        $t1, $zero, L_80023500
    if (ctx->r9 == 0) {
        // 0x800234F0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80023500;
    }
    goto skip_15;
    // 0x800234F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x800234F4: jal         0x8002538C
    // 0x800234F8: nop

    LOOKUP_FUNC(0x8002538C)(rdram, ctx);
        goto after_10;
    // 0x800234F8: nop

    after_10:
    // 0x800234FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80023500:
    // 0x80023500: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023504: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023508: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002350C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80023510: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80023514: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80023518: jr          $ra
    // 0x8002351C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002351C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80023520(rdram, ctx);
;}
RECOMP_FUNC void FUN_80023520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023520: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80023524: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80023528: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8002352C: addiu       $s2, $s2, -0x425C
    ctx->r18 = ADD32(ctx->r18, -0X425C);
    // 0x80023530: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023538: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002353C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80023540: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x80023544: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x80023548: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002354C: bnel        $t6, $zero, L_80023560
    if (ctx->r14 != 0) {
        // 0x80023550: lbu         $t8, 0xE($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XE);
            goto L_80023560;
    }
    goto skip_0;
    // 0x80023550: lbu         $t8, 0xE($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XE);
    skip_0:
    // 0x80023554: b           L_800235A4
    // 0x80023558: sb          $t7, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r15;
        goto L_800235A4;
    // 0x80023558: sb          $t7, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r15;
    // 0x8002355C: lbu         $t8, 0xE($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XE);
L_80023560:
    // 0x80023560: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80023564: beql        $t8, $zero, L_800235A8
    if (ctx->r24 == 0) {
        // 0x80023568: lw          $t3, 0x8($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X8);
            goto L_800235A8;
    }
    goto skip_1;
    // 0x80023568: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x8002356C: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x80023570: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80023574: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80023578: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8002357C: sb          $zero, 0xE($t9)
    MEM_B(0XE, ctx->r25) = 0;
    // 0x80023580: lbu         $t0, -0x454C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X454C);
    // 0x80023584: addiu       $t2, $t2, -0x4420
    ctx->r10 = ADD32(ctx->r10, -0X4420);
    // 0x80023588: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x8002358C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80023590: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80023594: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80023598: jal         0x80034EE0
    // 0x8002359C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    LOOKUP_FUNC(0x80034EE0)(rdram, ctx);
        goto after_0;
    // 0x8002359C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_0:
    // 0x800235A0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_800235A4:
    // 0x800235A4: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
L_800235A8:
    // 0x800235A8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800235AC: addiu       $s1, $s1, -0x4260
    ctx->r17 = ADD32(ctx->r17, -0X4260);
    // 0x800235B0: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800235B4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800235B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800235BC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800235C0: slti        $at, $a0, 0xD0
    ctx->r1 = SIGNED(ctx->r4) < 0XD0 ? 1 : 0;
    // 0x800235C4: bne         $at, $zero, L_80023668
    if (ctx->r1 != 0) {
        // 0x800235C8: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80023668;
    }
    // 0x800235C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_800235CC:
    // 0x800235CC: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800235D0: lbu         $t5, -0x454C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X454C);
    // 0x800235D4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800235D8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800235DC: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800235E0: bne         $at, $zero, L_80023608
    if (ctx->r1 != 0) {
        // 0x800235E4: addu        $t9, $t9, $t7
        ctx->r25 = ADD32(ctx->r25, ctx->r15);
            goto L_80023608;
    }
    // 0x800235E4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800235E8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800235EC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800235F0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800235F4: lw          $t9, 0x7BD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7BD0);
    // 0x800235F8: jalr        $t9
    // 0x800235FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800235FC: nop

    after_1:
    // 0x80023600: b           L_80023618
    // 0x80023604: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
        goto L_80023618;
    // 0x80023604: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
L_80023608:
    // 0x80023608: lw          $t9, 0x7B10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B10);
    // 0x8002360C: jalr        $t9
    // 0x80023610: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80023610: nop

    after_2:
    // 0x80023614: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
L_80023618:
    // 0x80023618: beq         $s0, $at, L_80023638
    if (ctx->r16 == ctx->r1) {
        // 0x8002361C: addiu       $at, $zero, 0xF3
        ctx->r1 = ADD32(0, 0XF3);
            goto L_80023638;
    }
    // 0x8002361C: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x80023620: beq         $s0, $at, L_80023638
    if (ctx->r16 == ctx->r1) {
        // 0x80023624: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_80023638;
    }
    // 0x80023624: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80023628: beql        $s0, $at, L_80023944
    if (ctx->r16 == ctx->r1) {
        // 0x8002362C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80023944;
    }
    goto skip_2;
    // 0x8002362C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80023630: b           L_8002364C
    // 0x80023634: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_8002364C;
    // 0x80023634: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80023638:
    // 0x80023638: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002363C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80023640: b           L_80023940
    // 0x80023644: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
        goto L_80023940;
    // 0x80023644: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x80023648: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8002364C:
    // 0x8002364C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80023650: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80023654: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80023658: slti        $at, $a0, 0xD0
    ctx->r1 = SIGNED(ctx->r4) < 0XD0 ? 1 : 0;
    // 0x8002365C: beq         $at, $zero, L_800235CC
    if (ctx->r1 == 0) {
        // 0x80023660: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_800235CC;
    }
    // 0x80023660: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80023664: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80023668:
    // 0x80023668: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8002366C: slti        $at, $s0, 0x68
    ctx->r1 = SIGNED(ctx->r16) < 0X68 ? 1 : 0;
    // 0x80023670: beq         $at, $zero, L_80023684
    if (ctx->r1 == 0) {
        // 0x80023674: sw          $t2, 0x84($v1)
        MEM_W(0X84, ctx->r3) = ctx->r10;
            goto L_80023684;
    }
    // 0x80023674: sw          $t2, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r10;
    // 0x80023678: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002367C: b           L_80023690
    // 0x80023680: sb          $a0, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r4;
        goto L_80023690;
    // 0x80023680: sb          $a0, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r4;
L_80023684:
    // 0x80023684: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80023688: addiu       $t4, $s0, -0x68
    ctx->r12 = ADD32(ctx->r16, -0X68);
    // 0x8002368C: sb          $t4, 0x25($t5)
    MEM_B(0X25, ctx->r13) = ctx->r12;
L_80023690:
    // 0x80023690: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023694: lbu         $v0, 0x25($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X25);
    // 0x80023698: slti        $at, $v0, 0x48
    ctx->r1 = SIGNED(ctx->r2) < 0X48 ? 1 : 0;
    // 0x8002369C: bne         $at, $zero, L_800236E8
    if (ctx->r1 != 0) {
        // 0x800236A0: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_800236E8;
    }
    // 0x800236A0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800236A4: bnel        $v0, $at, L_800236CC
    if (ctx->r2 != ctx->r1) {
        // 0x800236A8: lbu         $t0, 0x6($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X6);
            goto L_800236CC;
    }
    goto skip_3;
    // 0x800236A8: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
    skip_3:
    // 0x800236AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800236B0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800236B4: sb          $t7, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r15;
    // 0x800236B8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800236BC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800236C0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800236C4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800236C8: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
L_800236CC:
    // 0x800236CC: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x800236D0: jal         0x80024780
    // 0x800236D4: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    LOOKUP_FUNC(0x80024780)(rdram, ctx);
        goto after_3;
    // 0x800236D4: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    after_3:
    // 0x800236D8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800236DC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800236E0: b           L_800236F4
    // 0x800236E4: sb          $t2, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r10;
        goto L_800236F4;
    // 0x800236E4: sb          $t2, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r10;
L_800236E8:
    // 0x800236E8: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x800236EC: andi        $t5, $t4, 0xFB
    ctx->r13 = ctx->r12 & 0XFB;
    // 0x800236F0: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
L_800236F4:
    // 0x800236F4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800236F8: slti        $at, $s0, 0x68
    ctx->r1 = SIGNED(ctx->r16) < 0X68 ? 1 : 0;
    // 0x800236FC: lbu         $t6, 0x25($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X25);
    // 0x80023700: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80023704: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80023708: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8002370C: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80023710: lh          $t8, 0x2C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2C);
    // 0x80023714: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80023718: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x8002371C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023720: lw          $t1, 0x28($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X28);
    // 0x80023724: lh          $t2, 0x2E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2E);
    // 0x80023728: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8002372C: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
    // 0x80023730: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023734: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    // 0x80023738: lh          $t5, 0x30($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X30);
    // 0x8002373C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80023740: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x80023744: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023748: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x8002374C: lh          $t9, 0x32($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X32);
    // 0x80023750: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80023754: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80023758: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8002375C: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x80023760: lh          $t1, 0x34($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X34);
    // 0x80023764: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80023768: beq         $at, $zero, L_8002378C
    if (ctx->r1 == 0) {
        // 0x8002376C: sw          $t2, 0x28($v1)
        MEM_W(0X28, ctx->r3) = ctx->r10;
            goto L_8002378C;
    }
    // 0x8002376C: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x80023770: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80023774: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80023778: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8002377C: sb          $t4, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r12;
    // 0x80023780: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80023784: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80023788: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_8002378C:
    // 0x8002378C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023790: lbu         $t9, 0x20($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X20);
    // 0x80023794: sb          $t9, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r25;
    // 0x80023798: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002379C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800237A0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800237A4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800237A8: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800237AC: beq         $at, $zero, L_800237CC
    if (ctx->r1 == 0) {
        // 0x800237B0: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_800237CC;
    }
    // 0x800237B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800237B4: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800237B8: sb          $a0, 0x23($t0)
    MEM_B(0X23, ctx->r8) = ctx->r4;
    // 0x800237BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800237C0: lbu         $s0, 0x0($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X0);
    // 0x800237C4: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800237C8: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_800237CC:
    // 0x800237CC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800237D0: andi        $t9, $s0, 0x7F
    ctx->r25 = ctx->r16 & 0X7F;
    // 0x800237D4: lbu         $t2, 0x23($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X23);
    // 0x800237D8: sb          $t2, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r10;
    // 0x800237DC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800237E0: lbu         $v0, 0x22($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X22);
    // 0x800237E4: bnel        $v0, $zero, L_800237FC
    if (ctx->r2 != 0) {
        // 0x800237E8: lbu         $t3, 0x21($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X21);
            goto L_800237FC;
    }
    goto skip_4;
    // 0x800237E8: lbu         $t3, 0x21($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X21);
    skip_4:
    // 0x800237EC: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
    // 0x800237F0: b           L_80023828
    // 0x800237F4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
        goto L_80023828;
    // 0x800237F4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800237F8: lbu         $t3, 0x21($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X21);
L_800237FC:
    // 0x800237FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80023800: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023804: mflo        $t4
    ctx->r12 = lo;
    // 0x80023808: sra         $t5, $t4, 7
    ctx->r13 = S32(SIGNED(ctx->r12) >> 7);
    // 0x8002380C: sb          $t5, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r13;
    // 0x80023810: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023814: lbu         $t6, 0x24($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X24);
    // 0x80023818: bnel        $t6, $zero, L_8002382C
    if (ctx->r14 != 0) {
        // 0x8002381C: sb          $t9, 0x48($v1)
        MEM_B(0X48, ctx->r3) = ctx->r25;
            goto L_8002382C;
    }
    goto skip_5;
    // 0x8002381C: sb          $t9, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r25;
    skip_5:
    // 0x80023820: sb          $t7, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r15;
    // 0x80023824: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80023828:
    // 0x80023828: sb          $t9, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r25;
L_8002382C:
    // 0x8002382C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80023830: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80023834: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80023838: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8002383C: lbu         $t1, -0x454C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X454C);
    // 0x80023840: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x80023844: beql        $at, $zero, L_80023944
    if (ctx->r1 == 0) {
        // 0x80023848: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80023944;
    }
    goto skip_6;
    // 0x80023848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8002384C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80023850: lh          $t2, 0x8A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8A);
    // 0x80023854: bne         $t2, $zero, L_80023864
    if (ctx->r10 != 0) {
        // 0x80023858: nop
    
            goto L_80023864;
    }
    // 0x80023858: nop

    // 0x8002385C: b           L_8002386C
    // 0x80023860: sb          $zero, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = 0;
        goto L_8002386C;
    // 0x80023860: sb          $zero, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = 0;
L_80023864:
    // 0x80023864: jal         0x80025768
    // 0x80023868: nop

    LOOKUP_FUNC(0x80025768)(rdram, ctx);
        goto after_4;
    // 0x80023868: nop

    after_4:
L_8002386C:
    // 0x8002386C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80023870: sh          $zero, 0x36($t3)
    MEM_H(0X36, ctx->r11) = 0;
    // 0x80023874: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80023878: lhu         $t5, 0x9A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X9A);
    // 0x8002387C: beq         $t5, $zero, L_8002388C
    if (ctx->r13 == 0) {
        // 0x80023880: nop
    
            goto L_8002388C;
    }
    // 0x80023880: nop

    // 0x80023884: jal         0x8002507C
    // 0x80023888: nop

    LOOKUP_FUNC(0x8002507C)(rdram, ctx);
        goto after_5;
    // 0x80023888: nop

    after_5:
L_8002388C:
    // 0x8002388C: jal         0x80023BF4
    // 0x80023890: nop

    LOOKUP_FUNC(0x80023BF4)(rdram, ctx);
        goto after_6;
    // 0x80023890: nop

    after_6:
    // 0x80023894: lbu         $t6, 0x2E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2E);
    // 0x80023898: bnel        $t6, $zero, L_800238FC
    if (ctx->r14 != 0) {
        // 0x8002389C: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_800238FC;
    }
    goto skip_7;
    // 0x8002389C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_7:
    // 0x800238A0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800238A4: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800238A8: jal         0x80024180
    // 0x800238AC: sh          $t7, 0xB6($t9)
    MEM_H(0XB6, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x80024180)(rdram, ctx);
        goto after_7;
    // 0x800238AC: sh          $t7, 0xB6($t9)
    MEM_H(0XB6, ctx->r25) = ctx->r15;
    after_7:
    // 0x800238B0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800238B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800238B8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800238BC: sb          $t8, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r24;
    // 0x800238C0: lbu         $t1, -0x454C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X454C);
    // 0x800238C4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800238C8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800238CC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800238D0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800238D4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800238D8: addiu       $t3, $t3, -0x4420
    ctx->r11 = ADD32(ctx->r11, -0X4420);
    // 0x800238DC: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800238E0: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x800238E4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x800238E8: jal         0x80028F60
    // 0x800238EC: lw          $a2, 0x14($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X14);
    LOOKUP_FUNC(0x80028F60)(rdram, ctx);
        goto after_8;
    // 0x800238EC: lw          $a2, 0x14($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X14);
    after_8:
    // 0x800238F0: b           L_80023944
    // 0x800238F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80023944;
    // 0x800238F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800238F8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_800238FC:
    // 0x800238FC: lbu         $t5, 0x6($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X6);
    // 0x80023900: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80023904: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
    // 0x80023908: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8002390C: lhu         $t7, 0x4C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4C);
    // 0x80023910: beql        $t7, $zero, L_8002392C
    if (ctx->r15 == 0) {
        // 0x80023914: lbu         $t9, 0x6($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X6);
            goto L_8002392C;
    }
    goto skip_8;
    // 0x80023914: lbu         $t9, 0x6($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X6);
    skip_8:
    // 0x80023918: jal         0x80024358
    // 0x8002391C: nop

    LOOKUP_FUNC(0x80024358)(rdram, ctx);
        goto after_9;
    // 0x8002391C: nop

    after_9:
    // 0x80023920: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80023924: lw          $v1, -0x425C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X425C);
    // 0x80023928: lbu         $t9, 0x6($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X6);
L_8002392C:
    // 0x8002392C: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x80023930: beql        $t8, $zero, L_80023944
    if (ctx->r24 == 0) {
        // 0x80023934: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80023944;
    }
    goto skip_9;
    // 0x80023934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80023938: jal         0x80023D04
    // 0x8002393C: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_10;
    // 0x8002393C: nop

    after_10:
L_80023940:
    // 0x80023940: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80023944:
    // 0x80023944: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023948: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002394C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80023950: jr          $ra
    // 0x80023954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80023958(rdram, ctx);
;}
RECOMP_FUNC void FUN_80023958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023958: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002395C: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023968: lbu         $t6, 0x7D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7D);
    // 0x8002396C: beql        $t6, $zero, L_80023988
    if (ctx->r14 == 0) {
        // 0x80023970: lhu         $t7, 0x9A($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X9A);
            goto L_80023988;
    }
    goto skip_0;
    // 0x80023970: lhu         $t7, 0x9A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X9A);
    skip_0:
    // 0x80023974: jal         0x800255FC
    // 0x80023978: nop

    LOOKUP_FUNC(0x800255FC)(rdram, ctx);
        goto after_0;
    // 0x80023978: nop

    after_0:
    // 0x8002397C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023980: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023984: lhu         $t7, 0x9A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X9A);
L_80023988:
    // 0x80023988: beql        $t7, $zero, L_800239A4
    if (ctx->r15 == 0) {
        // 0x8002398C: lbu         $t8, 0x6($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X6);
            goto L_800239A4;
    }
    goto skip_1;
    // 0x8002398C: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    skip_1:
    // 0x80023990: jal         0x800250D4
    // 0x80023994: nop

    LOOKUP_FUNC(0x800250D4)(rdram, ctx);
        goto after_1;
    // 0x80023994: nop

    after_1:
    // 0x80023998: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002399C: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x800239A0: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
L_800239A4:
    // 0x800239A4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800239A8: beql        $t9, $zero, L_800239C4
    if (ctx->r25 == 0) {
        // 0x800239AC: lbu         $t0, 0x22($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X22);
            goto L_800239C4;
    }
    goto skip_2;
    // 0x800239AC: lbu         $t0, 0x22($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X22);
    skip_2:
    // 0x800239B0: jal         0x80023BF4
    // 0x800239B4: nop

    LOOKUP_FUNC(0x80023BF4)(rdram, ctx);
        goto after_2;
    // 0x800239B4: nop

    after_2:
    // 0x800239B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800239BC: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x800239C0: lbu         $t0, 0x22($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X22);
L_800239C4:
    // 0x800239C4: beql        $t0, $zero, L_800239F0
    if (ctx->r8 == 0) {
        // 0x800239C8: lbu         $v1, 0x24($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X24);
            goto L_800239F0;
    }
    goto skip_3;
    // 0x800239C8: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
    skip_3:
    // 0x800239CC: lbu         $t1, 0x21($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X21);
    // 0x800239D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800239D4: bnel        $t1, $at, L_800239F0
    if (ctx->r9 != ctx->r1) {
        // 0x800239D8: lbu         $v1, 0x24($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X24);
            goto L_800239F0;
    }
    goto skip_4;
    // 0x800239D8: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
    skip_4:
    // 0x800239DC: jal         0x8002430C
    // 0x800239E0: nop

    LOOKUP_FUNC(0x8002430C)(rdram, ctx);
        goto after_3;
    // 0x800239E0: nop

    after_3:
    // 0x800239E4: b           L_80023A68
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023A68;
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800239EC: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
L_800239F0:
    // 0x800239F0: beq         $v1, $zero, L_80023A20
    if (ctx->r3 == 0) {
        // 0x800239F4: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_80023A20;
    }
    // 0x800239F4: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x800239F8: sb          $t2, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r10;
    // 0x800239FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023A00: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023A04: lbu         $t3, 0x24($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X24);
    // 0x80023A08: bnel        $t3, $zero, L_80023A24
    if (ctx->r11 != 0) {
        // 0x80023A0C: lhu         $t4, 0x4C($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X4C);
            goto L_80023A24;
    }
    goto skip_5;
    // 0x80023A0C: lhu         $t4, 0x4C($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4C);
    skip_5:
    // 0x80023A10: jal         0x800242C8
    // 0x80023A14: nop

    LOOKUP_FUNC(0x800242C8)(rdram, ctx);
        goto after_4;
    // 0x80023A14: nop

    after_4:
    // 0x80023A18: b           L_80023A68
    // 0x80023A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023A68;
    // 0x80023A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A20:
    // 0x80023A20: lhu         $t4, 0x4C($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4C);
L_80023A24:
    // 0x80023A24: beql        $t4, $zero, L_80023A40
    if (ctx->r12 == 0) {
        // 0x80023A28: lbu         $t5, 0x6($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X6);
            goto L_80023A40;
    }
    goto skip_6;
    // 0x80023A28: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    skip_6:
    // 0x80023A2C: jal         0x80024358
    // 0x80023A30: nop

    LOOKUP_FUNC(0x80024358)(rdram, ctx);
        goto after_5;
    // 0x80023A30: nop

    after_5:
    // 0x80023A34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023A38: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80023A3C: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
L_80023A40:
    // 0x80023A40: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80023A44: beq         $t6, $zero, L_80023A5C
    if (ctx->r14 == 0) {
        // 0x80023A48: nop
    
            goto L_80023A5C;
    }
    // 0x80023A48: nop

    // 0x80023A4C: jal         0x80023D04
    // 0x80023A50: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_6;
    // 0x80023A50: nop

    after_6:
    // 0x80023A54: b           L_80023A68
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023A68;
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A5C:
    // 0x80023A5C: jal         0x80023A74
    // 0x80023A60: nop

    LOOKUP_FUNC(0x80023A74)(rdram, ctx);
        goto after_7;
    // 0x80023A60: nop

    after_7:
    // 0x80023A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A68:
    // 0x80023A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023A6C: jr          $ra
    // 0x80023A70: nop

    return;
    // 0x80023A70: nop

;}
RECOMP_FUNC void FUN_80023a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A74: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80023A78: lb          $t6, -0x454A($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X454A);
    // 0x80023A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023A84: beq         $t6, $zero, L_80023A9C
    if (ctx->r14 == 0) {
        // 0x80023A88: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_80023A9C;
    }
    // 0x80023A88: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80023A8C: jal         0x80023D04
    // 0x80023A90: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_0;
    // 0x80023A90: nop

    after_0:
    // 0x80023A94: b           L_80023B3C
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023B3C;
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A9C:
    // 0x80023A9C: lhu         $t7, -0x453E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X453E);
    // 0x80023AA0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80023AA4: beq         $t7, $zero, L_80023ABC
    if (ctx->r15 == 0) {
        // 0x80023AA8: nop
    
            goto L_80023ABC;
    }
    // 0x80023AA8: nop

    // 0x80023AAC: jal         0x80023D04
    // 0x80023AB0: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_1;
    // 0x80023AB0: nop

    after_1:
    // 0x80023AB4: b           L_80023B3C
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023B3C;
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ABC:
    // 0x80023ABC: lw          $t8, -0x425C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X425C);
    // 0x80023AC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80023AC4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80023AC8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80023ACC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80023AD0: addiu       $v1, $v1, -0x4536
    ctx->r3 = ADD32(ctx->r3, -0X4536);
    // 0x80023AD4: andi        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 & 0X7FFF;
    // 0x80023AD8: sltiu       $at, $a0, 0x100
    ctx->r1 = ctx->r4 < 0X100 ? 1 : 0;
    // 0x80023ADC: beq         $at, $zero, L_80023B10
    if (ctx->r1 == 0) {
        // 0x80023AE0: addiu       $v0, $v0, -0x4538
        ctx->r2 = ADD32(ctx->r2, -0X4538);
            goto L_80023B10;
    }
    // 0x80023AE0: addiu       $v0, $v0, -0x4538
    ctx->r2 = ADD32(ctx->r2, -0X4538);
    // 0x80023AE4: lhu         $t9, -0x4542($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4542);
    // 0x80023AE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80023AEC: bne         $t9, $zero, L_80023B00
    if (ctx->r25 != 0) {
        // 0x80023AF0: nop
    
            goto L_80023B00;
    }
    // 0x80023AF0: nop

    // 0x80023AF4: lb          $t0, -0x4533($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X4533);
    // 0x80023AF8: beq         $t0, $zero, L_80023B10
    if (ctx->r8 == 0) {
        // 0x80023AFC: nop
    
            goto L_80023B10;
    }
    // 0x80023AFC: nop

L_80023B00:
    // 0x80023B00: jal         0x80023D04
    // 0x80023B04: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_2;
    // 0x80023B04: nop

    after_2:
    // 0x80023B08: b           L_80023B3C
    // 0x80023B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023B3C;
    // 0x80023B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B10:
    // 0x80023B10: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
L_80023B14:
    // 0x80023B14: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80023B18: bne         $a0, $t1, L_80023B30
    if (ctx->r4 != ctx->r9) {
        // 0x80023B1C: nop
    
            goto L_80023B30;
    }
    // 0x80023B1C: nop

    // 0x80023B20: jal         0x80023D04
    // 0x80023B24: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_3;
    // 0x80023B24: nop

    after_3:
    // 0x80023B28: b           L_80023B3C
    // 0x80023B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023B3C;
    // 0x80023B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B30:
    // 0x80023B30: bnel        $v0, $v1, L_80023B14
    if (ctx->r2 != ctx->r3) {
        // 0x80023B34: lhu         $t1, 0x0($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X0);
            goto L_80023B14;
    }
    goto skip_0;
    // 0x80023B34: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x80023B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B3C:
    // 0x80023B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023B40: jr          $ra
    // 0x80023B44: nop

    return;
    // 0x80023B44: nop

;}
