#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_80236c68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80236C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80236C70: beq         $a0, $zero, L_80236C8C
    if (ctx->r4 == 0) {
        // 0x80236C74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80236C8C;
    }
    // 0x80236C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236C78: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80236C7C: jal         0x800058DC
    // 0x80236C80: addiu       $a1, $a1, 0x7880
    ctx->r5 = ADD32(ctx->r5, 0X7880);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80236C80: addiu       $a1, $a1, 0x7880
    ctx->r5 = ADD32(ctx->r5, 0X7880);
    after_0:
    // 0x80236C84: b           L_80236C8C
    // 0x80236C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80236C8C;
    // 0x80236C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80236C8C:
    // 0x80236C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80236C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80236C94: jr          $ra
    // 0x80236C98: nop

    return;
    // 0x80236C98: nop

;}
RECOMP_FUNC void M10_FUN_80236c9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236C9C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80236CA0: lbu         $t6, -0x43F6($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X43F6);
    // 0x80236CA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236CA8: beq         $t6, $zero, L_80236CB8
    if (ctx->r14 == 0) {
            // 0x80236CAC: nop

    LOOKUP_FUNC(0x80236CB8)(rdram, ctx);
    return;
    }
    // 0x80236CAC: nop

    // 0x80236CB0: jr          $ra
    // 0x80236CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80236CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236cb8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236cb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236CB8: jr          $ra
    // 0x80236CBC: nop

    return;
    // 0x80236CBC: nop

;}
RECOMP_FUNC void M10_FUN_80236cc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236CC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80236CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80236CC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80236CCC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80236CD0: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x80236CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80236CD8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80236CDC: lw          $a1, 0x9C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X9C);
    // 0x80236CE0: lw          $a3, 0x90($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X90);
    // 0x80236CE4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80236CE8: jal         0x8001F74C
    // 0x80236CEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80236CEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80236CF0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80236CF4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80236CF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80236CFC: sh          $zero, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = 0;
    // 0x80236D00: lhu         $v1, 0x30($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X30);
    // 0x80236D04: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x80236D08: andi        $a0, $v1, 0x2
    ctx->r4 = ctx->r3 & 0X2;
    // 0x80236D0C: beq         $a0, $zero, L_80236DF0
    if (ctx->r4 == 0) {
        // 0x80236D10: andi        $t7, $v1, 0x4
        ctx->r15 = ctx->r3 & 0X4;
            goto L_80236DF0;
    }
    // 0x80236D10: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x80236D14: lbu         $v0, 0x74($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X74);
    // 0x80236D18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80236D1C: beq         $v0, $zero, L_80236D34
    if (ctx->r2 == 0) {
        // 0x80236D20: nop
    
            goto L_80236D34;
    }
    // 0x80236D20: nop

    // 0x80236D24: beq         $v0, $at, L_80236D34
    if (ctx->r2 == ctx->r1) {
        // 0x80236D28: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80236D34;
    }
    // 0x80236D28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80236D2C: bne         $v0, $at, L_80236DF0
    if (ctx->r2 != ctx->r1) {
        // 0x80236D30: nop
    
            goto L_80236DF0;
    }
    // 0x80236D30: nop

L_80236D34:
    // 0x80236D34: jal         0x802363D8
    // 0x80236D38: nop

    LOOKUP_FUNC(0x802363D8)(rdram, ctx);
        goto after_1;
    // 0x80236D38: nop

    after_1:
    // 0x80236D3C: beq         $v0, $zero, L_80236FF0
    if (ctx->r2 == 0) {
        // 0x80236D40: lui         $a0, 0xF00
        ctx->r4 = S32(0XF00 << 16);
            goto L_80236FF0;
    }
    // 0x80236D40: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x80236D44: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80236D48: lbu         $a3, -0x33E0($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X33E0);
    // 0x80236D4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80236D50: jal         0x80002364
    // 0x80236D54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_2;
    // 0x80236D54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80236D58: jal         0x80116E80
    // 0x80236D5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x80236D5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x80236D60: jal         0x80376B2C
    // 0x80236D64: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80376B2C)(rdram, ctx);
        goto after_4;
    // 0x80236D64: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80236D68: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80236D6C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236D70: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80236D74: sw          $s0, -0x1C48($at)
    MEM_W(-0X1C48, ctx->r1) = ctx->r16;
    // 0x80236D78: sw          $zero, 0x720($v0)
    MEM_W(0X720, ctx->r2) = 0;
    // 0x80236D7C: sw          $zero, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = 0;
    // 0x80236D80: jal         0x80020744
    // 0x80236D84: addiu       $a0, $zero, 0x275
    ctx->r4 = ADD32(0, 0X275);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_5;
    // 0x80236D84: addiu       $a0, $zero, 0x275
    ctx->r4 = ADD32(0, 0X275);
    after_5:
    // 0x80236D88: jal         0x80147598
    // 0x80236D8C: nop

    LOOKUP_FUNC(0x80147598)(rdram, ctx);
        goto after_6;
    // 0x80236D8C: nop

    after_6:
    // 0x80236D90: beq         $v0, $zero, L_80236DB4
    if (ctx->r2 == 0) {
        // 0x80236D94: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80236DB4;
    }
    // 0x80236D94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80236D98: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236D9C: sb          $zero, -0x43F6($at)
    MEM_B(-0X43F6, ctx->r1) = 0;
    // 0x80236DA0: addiu       $a1, $a1, -0x48FC
    ctx->r5 = ADD32(ctx->r5, -0X48FC);
    // 0x80236DA4: jal         0x800058DC
    // 0x80236DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80236DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80236DAC: b           L_80236FF4
    // 0x80236DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80236DB4:
    // 0x80236DB4: jal         0x80236C9C
    // 0x80236DB8: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_8;
    // 0x80236DB8: nop

    after_8:
    // 0x80236DBC: beq         $v0, $zero, L_80236DDC
    if (ctx->r2 == 0) {
        // 0x80236DC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80236DDC;
    }
    // 0x80236DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236DC4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236DC8: addiu       $a1, $a1, -0x48FC
    ctx->r5 = ADD32(ctx->r5, -0X48FC);
    // 0x80236DCC: jal         0x800058DC
    // 0x80236DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x80236DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80236DD4: b           L_80236FF4
    // 0x80236DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80236DDC:
    // 0x80236DDC: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80236DE0: jal         0x800058DC
    // 0x80236DE4: addiu       $a1, $a1, 0x7004
    ctx->r5 = ADD32(ctx->r5, 0X7004);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x80236DE4: addiu       $a1, $a1, 0x7004
    ctx->r5 = ADD32(ctx->r5, 0X7004);
    after_10:
    // 0x80236DE8: b           L_80236FF4
    // 0x80236DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80236DF0:
    // 0x80236DF0: beq         $t7, $zero, L_80236EF8
    if (ctx->r15 == 0) {
        // 0x80236DF4: nop
    
            goto L_80236EF8;
    }
    // 0x80236DF4: nop

    // 0x80236DF8: lbu         $v1, 0x31($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X31);
    // 0x80236DFC: srl         $v1, $v1, 7
    ctx->r3 = S32(U32(ctx->r3) >> 7);
    // 0x80236E00: beq         $v1, $zero, L_80236EF8
    if (ctx->r3 == 0) {
        // 0x80236E04: nop
    
            goto L_80236EF8;
    }
    // 0x80236E04: nop

    // 0x80236E08: lbu         $v0, 0x74($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X74);
    // 0x80236E0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80236E10: beql        $v0, $zero, L_80236E2C
    if (ctx->r2 == 0) {
        // 0x80236E14: lbu         $t8, 0x2D8($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X2D8);
            goto L_80236E2C;
    }
    goto skip_0;
    // 0x80236E14: lbu         $t8, 0x2D8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2D8);
    skip_0:
    // 0x80236E18: beq         $v0, $at, L_80236E28
    if (ctx->r2 == ctx->r1) {
        // 0x80236E1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80236E28;
    }
    // 0x80236E1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80236E20: bne         $v0, $at, L_80236EF8
    if (ctx->r2 != ctx->r1) {
        // 0x80236E24: nop
    
            goto L_80236EF8;
    }
    // 0x80236E24: nop

L_80236E28:
    // 0x80236E28: lbu         $t8, 0x2D8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2D8);
L_80236E2C:
    // 0x80236E2C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80236E30: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80236E34: beq         $t8, $at, L_80236E70
    if (ctx->r24 == ctx->r1) {
        // 0x80236E38: nop
    
            goto L_80236E70;
    }
    // 0x80236E38: nop

    // 0x80236E3C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80236E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80236E44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80236E48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80236E4C: srl         $v0, $v0, 28
    ctx->r2 = S32(U32(ctx->r2) >> 28);
    // 0x80236E50: beq         $a0, $v0, L_80236E70
    if (ctx->r4 == ctx->r2) {
        // 0x80236E54: nop
    
            goto L_80236E70;
    }
    // 0x80236E54: nop

    // 0x80236E58: beq         $v0, $at, L_80236E70
    if (ctx->r2 == ctx->r1) {
        // 0x80236E5C: nop
    
            goto L_80236E70;
    }
    // 0x80236E5C: nop

    // 0x80236E60: lbu         $t9, 0x33($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X33);
    // 0x80236E64: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80236E68: bne         $a0, $t0, L_80236E8C
    if (ctx->r4 != ctx->r8) {
        // 0x80236E6C: nop
    
            goto L_80236E8C;
    }
    // 0x80236E6C: nop

L_80236E70:
    // 0x80236E70: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236E74: sb          $t1, 0x2D8($a2)
    MEM_B(0X2D8, ctx->r6) = ctx->r9;
    // 0x80236E78: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    // 0x80236E7C: jal         0x800058DC
    // 0x80236E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80236E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80236E84: b           L_80236EEC
    // 0x80236E88: nop

        goto L_80236EEC;
    // 0x80236E88: nop

L_80236E8C:
    // 0x80236E8C: beq         $v1, $zero, L_80236EC0
    if (ctx->r3 == 0) {
        // 0x80236E90: lui         $t2, 0x8039
        ctx->r10 = S32(0X8039 << 16);
            goto L_80236EC0;
    }
    // 0x80236E90: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80236E94: addiu       $t2, $t2, -0x3290
    ctx->r10 = ADD32(ctx->r10, -0X3290);
    // 0x80236E98: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
    // 0x80236E9C: sb          $zero, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = 0;
    // 0x80236EA0: jal         0x80020744
    // 0x80236EA4: addiu       $a0, $zero, 0x277
    ctx->r4 = ADD32(0, 0X277);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_12;
    // 0x80236EA4: addiu       $a0, $zero, 0x277
    ctx->r4 = ADD32(0, 0X277);
    after_12:
    // 0x80236EA8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236EAC: addiu       $a1, $a1, -0x782C
    ctx->r5 = ADD32(ctx->r5, -0X782C);
    // 0x80236EB0: jal         0x800058DC
    // 0x80236EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x80236EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80236EB8: b           L_80236EEC
    // 0x80236EBC: nop

        goto L_80236EEC;
    // 0x80236EBC: nop

L_80236EC0:
    // 0x80236EC0: lhu         $t3, 0x30($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X30);
    // 0x80236EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236EC8: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80236ECC: bne         $t4, $zero, L_80236EEC
    if (ctx->r12 != 0) {
        // 0x80236ED0: nop
    
            goto L_80236EEC;
    }
    // 0x80236ED0: nop

    // 0x80236ED4: lbu         $t5, 0x31($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X31);
    // 0x80236ED8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236EDC: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    // 0x80236EE0: andi        $t6, $t5, 0xFFF8
    ctx->r14 = ctx->r13 & 0XFFF8;
    // 0x80236EE4: jal         0x800058DC
    // 0x80236EE8: sb          $t6, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80236EE8: sb          $t6, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r14;
    after_14:
L_80236EEC:
    // 0x80236EEC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236EF0: b           L_80236FF0
    // 0x80236EF4: sw          $s0, -0x1C48($at)
    MEM_W(-0X1C48, ctx->r1) = ctx->r16;
        goto L_80236FF0;
    // 0x80236EF4: sw          $s0, -0x1C48($at)
    MEM_W(-0X1C48, ctx->r1) = ctx->r16;
L_80236EF8:
    // 0x80236EF8: beql        $a0, $zero, L_80236F30
    if (ctx->r4 == 0) {
        // 0x80236EFC: lb          $t0, 0x31($a1)
        ctx->r8 = MEM_B(ctx->r5, 0X31);
            goto L_80236F30;
    }
    goto skip_1;
    // 0x80236EFC: lb          $t0, 0x31($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X31);
    skip_1:
    // 0x80236F00: lbu         $t7, 0x74($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X74);
    // 0x80236F04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80236F08: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80236F0C: bne         $t7, $at, L_80236F2C
    if (ctx->r15 != ctx->r1) {
        // 0x80236F10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80236F2C;
    }
    // 0x80236F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236F14: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236F18: sh          $t8, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r24;
    // 0x80236F1C: jal         0x800058DC
    // 0x80236F20: addiu       $a1, $a1, -0x6180
    ctx->r5 = ADD32(ctx->r5, -0X6180);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x80236F20: addiu       $a1, $a1, -0x6180
    ctx->r5 = ADD32(ctx->r5, -0X6180);
    after_15:
    // 0x80236F24: b           L_80236FF4
    // 0x80236F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80236F2C:
    // 0x80236F2C: lb          $t0, 0x31($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X31);
L_80236F30:
    // 0x80236F30: bgezl       $t0, L_80236FC8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80236F34: lhu         $t6, 0x30($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0X30);
            goto L_80236FC8;
    }
    goto skip_2;
    // 0x80236F34: lhu         $t6, 0x30($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X30);
    skip_2:
    // 0x80236F38: lbu         $t1, 0x2D8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X2D8);
    // 0x80236F3C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80236F40: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80236F44: beq         $t1, $at, L_80236F80
    if (ctx->r9 == ctx->r1) {
        // 0x80236F48: lui         $a1, 0x8024
        ctx->r5 = S32(0X8024 << 16);
            goto L_80236F80;
    }
    // 0x80236F48: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236F4C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80236F50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80236F54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80236F58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80236F5C: srl         $v0, $v0, 28
    ctx->r2 = S32(U32(ctx->r2) >> 28);
    // 0x80236F60: beql        $a0, $v0, L_80236F84
    if (ctx->r4 == ctx->r2) {
        // 0x80236F64: sb          $t4, 0x2D8($a2)
        MEM_B(0X2D8, ctx->r6) = ctx->r12;
            goto L_80236F84;
    }
    goto skip_3;
    // 0x80236F64: sb          $t4, 0x2D8($a2)
    MEM_B(0X2D8, ctx->r6) = ctx->r12;
    skip_3:
    // 0x80236F68: beql        $v0, $at, L_80236F84
    if (ctx->r2 == ctx->r1) {
        // 0x80236F6C: sb          $t4, 0x2D8($a2)
        MEM_B(0X2D8, ctx->r6) = ctx->r12;
            goto L_80236F84;
    }
    goto skip_4;
    // 0x80236F6C: sb          $t4, 0x2D8($a2)
    MEM_B(0X2D8, ctx->r6) = ctx->r12;
    skip_4:
    // 0x80236F70: lbu         $t2, 0x33($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X33);
    // 0x80236F74: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80236F78: bnel        $a0, $t3, L_80236F9C
    if (ctx->r4 != ctx->r11) {
        // 0x80236F7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80236F9C;
    }
    goto skip_5;
    // 0x80236F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
L_80236F80:
    // 0x80236F80: sb          $t4, 0x2D8($a2)
    MEM_B(0X2D8, ctx->r6) = ctx->r12;
L_80236F84:
    // 0x80236F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236F88: jal         0x800058DC
    // 0x80236F8C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80236F8C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_16:
    // 0x80236F90: b           L_80236FF4
    // 0x80236F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80236F9C:
    // 0x80236F9C: jal         0x8022ABD8
    // 0x80236FA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x8022ABD8)(rdram, ctx);
        goto after_17;
    // 0x80236FA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x80236FA4: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80236FA8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236FAC: sh          $t5, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r13;
    // 0x80236FB0: addiu       $a1, $a1, -0x65A4
    ctx->r5 = ADD32(ctx->r5, -0X65A4);
    // 0x80236FB4: jal         0x800058DC
    // 0x80236FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x80236FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80236FBC: b           L_80236FF4
    // 0x80236FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80236FF4;
    // 0x80236FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236FC4: lhu         $t6, 0x30($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X30);
L_80236FC8:
    // 0x80236FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236FCC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80236FD0: bnel        $t7, $zero, L_80236FF4
    if (ctx->r15 != 0) {
        // 0x80236FD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80236FF4;
    }
    goto skip_6;
    // 0x80236FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80236FD8: lbu         $t8, 0x31($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31);
    // 0x80236FDC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236FE0: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    // 0x80236FE4: andi        $t9, $t8, 0xFFF8
    ctx->r25 = ctx->r24 & 0XFFF8;
    // 0x80236FE8: jal         0x800058DC
    // 0x80236FEC: sb          $t9, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x80236FEC: sb          $t9, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r25;
    after_19:
L_80236FF0:
    // 0x80236FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80236FF4:
    // 0x80236FF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80236FF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80236FFC: jr          $ra
    // 0x80237000: nop

    return;
    // 0x80237000: nop

;}
RECOMP_FUNC void M10_FUN_80237004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237004: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80237008: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8023700C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80237010: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80237014: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80237018: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8023701C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80237020: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80237024: jal         0x80234450
    // 0x80237028: sb          $zero, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = 0;
    LOOKUP_FUNC(0x80234450)(rdram, ctx);
        goto after_0;
    // 0x80237028: sb          $zero, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = 0;
    after_0:
    // 0x8023702C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80237030: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80237034: lbu         $t6, 0x1030($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1030);
    // 0x80237038: bnel        $t6, $zero, L_8023704C
    if (ctx->r14 != 0) {
        // 0x8023703C: lw          $a0, 0xEC($v0)
        ctx->r4 = MEM_W(ctx->r2, 0XEC);
            goto L_8023704C;
    }
    goto skip_0;
    // 0x8023703C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    skip_0:
    // 0x80237040: b           L_8023704C
    // 0x80237044: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
        goto L_8023704C;
    // 0x80237044: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    // 0x80237048: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
L_8023704C:
    // 0x8023704C: jal         0x802242D0
    // 0x80237050: nop

    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_1;
    // 0x80237050: nop

    after_1:
    // 0x80237054: sb          $v0, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r2;
    // 0x80237058: jal         0x80234CE8
    // 0x8023705C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80234CE8)(rdram, ctx);
        goto after_2;
    // 0x8023705C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80237060: sb          $v0, 0xA9($s1)
    MEM_B(0XA9, ctx->r17) = ctx->r2;
    // 0x80237064: addiu       $s0, $sp, 0x5F
    ctx->r16 = ADD32(ctx->r29, 0X5F);
    // 0x80237068: addiu       $t7, $zero, 0x72
    ctx->r15 = ADD32(0, 0X72);
    // 0x8023706C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80237070: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80237074: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80237078: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8023707C: addiu       $t2, $zero, 0x220
    ctx->r10 = ADD32(0, 0X220);
    // 0x80237080: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x80237084: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80237088: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8023708C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80237090: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80237094: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80237098: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023709C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x802370A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x802370A4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x802370A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802370AC: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x802370B0: jal         0x80146208
    // 0x802370B4: addiu       $a3, $zero, 0x85
    ctx->r7 = ADD32(0, 0X85);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x802370B4: addiu       $a3, $zero, 0x85
    ctx->r7 = ADD32(0, 0X85);
    after_3:
    // 0x802370B8: addiu       $t4, $zero, 0x72
    ctx->r12 = ADD32(0, 0X72);
    // 0x802370BC: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x802370C0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x802370C4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x802370C8: addiu       $t8, $zero, 0x220
    ctx->r24 = ADD32(0, 0X220);
    // 0x802370CC: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x802370D0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x802370D4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x802370D8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x802370DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x802370E0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x802370E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x802370E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802370EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x802370F0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x802370F4: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    // 0x802370F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x802370FC: jal         0x80146208
    // 0x80237100: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x80237100: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x80237104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80237108: jal         0x80234828
    // 0x8023710C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80234828)(rdram, ctx);
        goto after_5;
    // 0x8023710C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x80237110: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80237114: sb          $t0, 0xA4($s1)
    MEM_B(0XA4, ctx->r17) = ctx->r8;
    // 0x80237118: jal         0x80006214
    // 0x8023711C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x8023711C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80237120: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80237124: lb          $t1, 0xA4($s1)
    ctx->r9 = MEM_B(ctx->r17, 0XA4);
    // 0x80237128: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023712C: addiu       $s2, $zero, 0x8C
    ctx->r18 = ADD32(0, 0X8C);
    // 0x80237130: blezl       $t1, L_80237190
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80237134: lb          $s0, 0x57($sp)
        ctx->r16 = MEM_B(ctx->r29, 0X57);
            goto L_80237190;
    }
    goto skip_1;
    // 0x80237134: lb          $s0, 0x57($sp)
    ctx->r16 = MEM_B(ctx->r29, 0X57);
    skip_1:
L_80237138:
    // 0x80237138: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023713C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80237140: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80237144: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80237148: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8023714C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80237150: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80237154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80237158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8023715C: mflo        $a3
    ctx->r7 = lo;
    // 0x80237160: addiu       $a3, $a3, -0x46
    ctx->r7 = ADD32(ctx->r7, -0X46);
    // 0x80237164: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80237168: jal         0x8023448C
    // 0x8023716C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_7;
    // 0x8023716C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_7:
    // 0x80237170: lb          $t4, 0xA4($s1)
    ctx->r12 = MEM_B(ctx->r17, 0XA4);
    // 0x80237174: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80237178: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8023717C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80237180: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80237184: bne         $at, $zero, L_80237138
    if (ctx->r1 != 0) {
        // 0x80237188: nop
    
            goto L_80237138;
    }
    // 0x80237188: nop

    // 0x8023718C: lb          $s0, 0x57($sp)
    ctx->r16 = MEM_B(ctx->r29, 0X57);
L_80237190:
    // 0x80237190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80237194: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80237198: addu        $t5, $s3, $s0
    ctx->r13 = ADD32(ctx->r19, ctx->r16);
    // 0x8023719C: jal         0x80234D70
    // 0x802371A0: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80234D70)(rdram, ctx);
        goto after_8;
    // 0x802371A0: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_8:
    // 0x802371A4: addu        $t6, $s0, $s3
    ctx->r14 = ADD32(ctx->r16, ctx->r19);
    // 0x802371A8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802371AC: sw          $t6, 0x86C($at)
    MEM_W(0X86C, ctx->r1) = ctx->r14;
    // 0x802371B0: jal         0x80006214
    // 0x802371B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_9;
    // 0x802371B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x802371B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x802371BC: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x802371C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x802371C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802371C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x802371CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x802371D0: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    // 0x802371D4: jal         0x802345B0
    // 0x802371D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_10;
    // 0x802371D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x802371DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x802371E0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x802371E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x802371E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x802371EC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x802371F0: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x802371F4: jal         0x802345B0
    // 0x802371F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_11;
    // 0x802371F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x802371FC: lb          $s0, 0x57($sp)
    ctx->r16 = MEM_B(ctx->r29, 0X57);
    // 0x80237200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80237204: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80237208: addu        $t9, $s3, $s0
    ctx->r25 = ADD32(ctx->r19, ctx->r16);
    // 0x8023720C: jal         0x80234DD4
    // 0x80237210: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x80234DD4)(rdram, ctx);
        goto after_12;
    // 0x80237210: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_12:
    // 0x80237214: addu        $t0, $s0, $s3
    ctx->r8 = ADD32(ctx->r16, ctx->r19);
    // 0x80237218: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023721C: sw          $t0, 0x870($at)
    MEM_W(0X870, ctx->r1) = ctx->r8;
    // 0x80237220: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237224: sb          $zero, 0xA2($s1)
    MEM_B(0XA2, ctx->r17) = 0;
    // 0x80237228: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    // 0x8023722C: jal         0x800058DC
    // 0x80237230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x80237230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80237234: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80237238: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8023723C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80237240: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80237244: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80237248: jr          $ra
    // 0x8023724C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8023724C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80237250(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80237250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237250: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80237254: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80237258: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8023725C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80237260: lb          $v0, 0xA2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA2);
    // 0x80237264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80237268: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x8023726C: bne         $v0, $zero, L_802373C0
    if (ctx->r2 != 0) {
        // 0x80237270: lw          $a2, 0x98($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X98);
            goto L_802373C0;
    }
    // 0x80237270: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x80237274: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80237278: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x8023727C: beq         $t6, $zero, L_802372C0
    if (ctx->r14 == 0) {
        // 0x80237280: andi        $t1, $v0, 0x100
        ctx->r9 = ctx->r2 & 0X100;
            goto L_802372C0;
    }
    // 0x80237280: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x80237284: lbu         $t7, 0xA9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XA9);
    // 0x80237288: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8023728C: beq         $t8, $zero, L_802372C0
    if (ctx->r24 == 0) {
        // 0x80237290: nop
    
            goto L_802372C0;
    }
    // 0x80237290: nop

    // 0x80237294: jal         0x80020744
    // 0x80237298: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80237298: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_0:
    // 0x8023729C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x802372A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x802372A4: sb          $t9, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r25;
    // 0x802372A8: sb          $t0, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r8;
    // 0x802372AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x802372B0: jal         0x8023644C
    // 0x802372B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023644C)(rdram, ctx);
        goto after_1;
    // 0x802372B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802372B8: b           L_802373A0
    // 0x802372BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_802373A0;
    // 0x802372BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_802372C0:
    // 0x802372C0: bnel        $t1, $zero, L_802372DC
    if (ctx->r9 != 0) {
        // 0x802372C4: lbu         $t4, 0xA9($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0XA9);
            goto L_802372DC;
    }
    goto skip_0;
    // 0x802372C4: lbu         $t4, 0xA9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA9);
    skip_0:
    // 0x802372C8: lhu         $t2, 0x4($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4);
    // 0x802372CC: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x802372D0: beql        $t3, $zero, L_80237310
    if (ctx->r11 == 0) {
        // 0x802372D4: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_80237310;
    }
    goto skip_1;
    // 0x802372D4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_1:
    // 0x802372D8: lbu         $t4, 0xA9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA9);
L_802372DC:
    // 0x802372DC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x802372E0: beql        $t5, $zero, L_80237310
    if (ctx->r13 == 0) {
        // 0x802372E4: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_80237310;
    }
    goto skip_2;
    // 0x802372E4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_2:
    // 0x802372E8: jal         0x80020744
    // 0x802372EC: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x802372EC: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x802372F0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x802372F4: sb          $t6, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r14;
    // 0x802372F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x802372FC: jal         0x802364E8
    // 0x80237300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802364E8)(rdram, ctx);
        goto after_3;
    // 0x80237300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80237304: b           L_802373A0
    // 0x80237308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_802373A0;
    // 0x80237308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023730C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_80237310:
    // 0x80237310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237314: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80237318: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x8023731C: beq         $t8, $zero, L_80237358
    if (ctx->r24 == 0) {
        // 0x80237320: nop
    
            goto L_80237358;
    }
    // 0x80237320: nop

    // 0x80237324: lw          $t9, 0x38($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X38);
    // 0x80237328: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8023732C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80237330: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80237334: beql        $t0, $zero, L_80237348
    if (ctx->r8 == 0) {
        // 0x80237338: sh          $t2, 0x44($a2)
        MEM_H(0X44, ctx->r6) = ctx->r10;
            goto L_80237348;
    }
    goto skip_3;
    // 0x80237338: sh          $t2, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r10;
    skip_3:
    // 0x8023733C: b           L_80237348
    // 0x80237340: sh          $t1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r9;
        goto L_80237348;
    // 0x80237340: sh          $t1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r9;
    // 0x80237344: sh          $t2, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r10;
L_80237348:
    // 0x80237348: jal         0x800058DC
    // 0x8023734C: addiu       $a1, $a1, -0x604C
    ctx->r5 = ADD32(ctx->r5, -0X604C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8023734C: addiu       $a1, $a1, -0x604C
    ctx->r5 = ADD32(ctx->r5, -0X604C);
    after_4:
    // 0x80237350: b           L_802373A0
    // 0x80237354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_802373A0;
    // 0x80237354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237358:
    // 0x80237358: jal         0x80234D2C
    // 0x8023735C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80234D2C)(rdram, ctx);
        goto after_5;
    // 0x8023735C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80237360: beq         $v0, $zero, L_8023739C
    if (ctx->r2 == 0) {
        // 0x80237364: lui         $t3, 0x8024
        ctx->r11 = S32(0X8024 << 16);
            goto L_8023739C;
    }
    // 0x80237364: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80237368: lw          $t3, 0x86C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X86C);
    // 0x8023736C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80237370: addiu       $t4, $zero, 0x1B
    ctx->r12 = ADD32(0, 0X1B);
    // 0x80237374: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80237378: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8023737C: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x80237380: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80237384: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80237388: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8023738C: lbu         $a2, -0x33E0($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X33E0);
    // 0x80237390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80237394: jal         0x801453CC
    // 0x80237398: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_6;
    // 0x80237398: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
L_8023739C:
    // 0x8023739C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_802373A0:
    // 0x802373A0: jal         0x80234828
    // 0x802373A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80234828)(rdram, ctx);
        goto after_7;
    // 0x802373A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x802373A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x802373AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802373B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x802373B4: jal         0x801470E8
    // 0x802373B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_8;
    // 0x802373B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x802373BC: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_802373C0:
    // 0x802373C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802373C4: bne         $v0, $at, L_80237414
    if (ctx->r2 != ctx->r1) {
        // 0x802373C8: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80237414;
    }
    // 0x802373C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x802373CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802373D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x802373D4: jal         0x801470E8
    // 0x802373D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_9;
    // 0x802373D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x802373DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802373E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x802373E4: jal         0x80235394
    // 0x802373E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_10;
    // 0x802373E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x802373EC: lb          $t7, 0xA2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA2);
    // 0x802373F0: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x802373F4: addiu       $a1, $a1, 0x748C
    ctx->r5 = ADD32(ctx->r5, 0X748C);
    // 0x802373F8: bne         $t7, $zero, L_80237478
    if (ctx->r15 != 0) {
        // 0x802373FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237478;
    }
    // 0x802373FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237400: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
    // 0x80237404: jal         0x800058DC
    // 0x80237408: sb          $zero, 0xAB($s0)
    MEM_B(0XAB, ctx->r16) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80237408: sb          $zero, 0xAB($s0)
    MEM_B(0XAB, ctx->r16) = 0;
    after_11:
    // 0x8023740C: b           L_8023747C
    // 0x80237410: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8023747C;
    // 0x80237410: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80237414:
    // 0x80237414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80237418: bne         $v0, $at, L_80237478
    if (ctx->r2 != ctx->r1) {
        // 0x8023741C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80237478;
    }
    // 0x8023741C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80237420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80237424: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80237428: jal         0x801470E8
    // 0x8023742C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801470E8)(rdram, ctx);
        goto after_12;
    // 0x8023742C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80237430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237434: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80237438: jal         0x80235394
    // 0x8023743C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_13;
    // 0x8023743C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80237440: lb          $t8, 0xA2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XA2);
    // 0x80237444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237448: bnel        $t8, $zero, L_8023747C
    if (ctx->r24 != 0) {
        // 0x8023744C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8023747C;
    }
    goto skip_4;
    // 0x8023744C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80237450: lb          $t9, 0xA3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA3);
    // 0x80237454: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237458: addiu       $a1, $a1, 0x78DC
    ctx->r5 = ADD32(ctx->r5, 0X78DC);
    // 0x8023745C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80237460: bgez        $t0, L_80237470
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80237464: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80237470;
    }
    // 0x80237464: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80237468: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8023746C: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80237470:
    // 0x80237470: jal         0x800058DC
    // 0x80237474: sb          $t1, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80237474: sb          $t1, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r9;
    after_14:
L_80237478:
    // 0x80237478: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8023747C:
    // 0x8023747C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80237480: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80237484: jr          $ra
    // 0x80237488: nop

    return;
    // 0x80237488: nop

;}
RECOMP_FUNC void M10_FUN_8023748c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023748C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80237490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80237494: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80237498: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023749C: lb          $v0, 0xA2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA2);
    // 0x802374A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802374A4: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x802374A8: bnel        $v0, $zero, L_80237590
    if (ctx->r2 != 0) {
        // 0x802374AC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80237590;
    }
    goto skip_0;
    // 0x802374AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x802374B0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x802374B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802374B8: bnel        $t6, $zero, L_80237590
    if (ctx->r14 != 0) {
        // 0x802374BC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80237590;
    }
    goto skip_1;
    // 0x802374BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x802374C0: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x802374C4: jal         0x80147148
    // 0x802374C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_0;
    // 0x802374C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x802374CC: jal         0x80235D48
    // 0x802374D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80235D48)(rdram, ctx);
        goto after_1;
    // 0x802374D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802374D4: bne         $v0, $zero, L_80237578
    if (ctx->r2 != 0) {
        // 0x802374D8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80237578;
    }
    // 0x802374D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x802374DC: lhu         $t7, 0xC($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XC);
    // 0x802374E0: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x802374E4: bne         $t8, $zero, L_802374FC
    if (ctx->r24 != 0) {
        // 0x802374E8: nop
    
            goto L_802374FC;
    }
    // 0x802374E8: nop

    // 0x802374EC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x802374F0: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x802374F4: beq         $t9, $zero, L_80237524
    if (ctx->r25 == 0) {
        // 0x802374F8: andi        $t1, $v0, 0x8000
        ctx->r9 = ctx->r2 & 0X8000;
            goto L_80237524;
    }
    // 0x802374F8: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
L_802374FC:
    // 0x802374FC: jal         0x80020744
    // 0x80237500: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80237500: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x80237504: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80237508: sb          $t0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r8;
    // 0x8023750C: sb          $zero, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = 0;
    // 0x80237510: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237514: jal         0x80236408
    // 0x80237518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236408)(rdram, ctx);
        goto after_3;
    // 0x80237518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8023751C: b           L_8023757C
    // 0x80237520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8023757C;
    // 0x80237520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237524:
    // 0x80237524: beql        $t1, $zero, L_8023757C
    if (ctx->r9 == 0) {
        // 0x80237528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8023757C;
    }
    goto skip_2;
    // 0x80237528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8023752C: jal         0x80020744
    // 0x80237530: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x80237530: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_4:
    // 0x80237534: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x80237538: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8023753C: sb          $t2, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r10;
    // 0x80237540: beq         $v0, $zero, L_80237564
    if (ctx->r2 == 0) {
        // 0x80237544: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80237564;
    }
    // 0x80237544: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237548: beq         $v0, $at, L_8023756C
    if (ctx->r2 == ctx->r1) {
        // 0x8023754C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8023756C;
    }
    // 0x8023754C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80237550: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80237554: beql        $v0, $v1, L_80237578
    if (ctx->r2 == ctx->r3) {
        // 0x80237558: sb          $v1, 0xAA($s0)
        MEM_B(0XAA, ctx->r16) = ctx->r3;
            goto L_80237578;
    }
    goto skip_3;
    // 0x80237558: sb          $v1, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = ctx->r3;
    skip_3:
    // 0x8023755C: b           L_8023757C
    // 0x80237560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8023757C;
    // 0x80237560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237564:
    // 0x80237564: b           L_80237578
    // 0x80237568: sb          $zero, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = 0;
        goto L_80237578;
    // 0x80237568: sb          $zero, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = 0;
L_8023756C:
    // 0x8023756C: b           L_80237578
    // 0x80237570: sb          $t3, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = ctx->r11;
        goto L_80237578;
    // 0x80237570: sb          $t3, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = ctx->r11;
    // 0x80237574: sb          $v1, 0xAA($s0)
    MEM_B(0XAA, ctx->r16) = ctx->r3;
L_80237578:
    // 0x80237578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8023757C:
    // 0x8023757C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237580: jal         0x80234724
    // 0x80237584: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_5;
    // 0x80237584: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_5:
    // 0x80237588: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
    // 0x8023758C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80237590:
    // 0x80237590: bne         $v0, $at, L_802375C8
    if (ctx->r2 != ctx->r1) {
        // 0x80237594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802375C8;
    }
    // 0x80237594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8023759C: jal         0x80235394
    // 0x802375A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_6;
    // 0x802375A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x802375A4: lb          $t4, 0xA2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XA2);
    // 0x802375A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802375AC: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x802375B0: bnel        $t4, $zero, L_80237620
    if (ctx->r12 != 0) {
        // 0x802375B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237620;
    }
    goto skip_4;
    // 0x802375B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x802375B8: jal         0x800058DC
    // 0x802375BC: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x802375BC: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    after_7:
    // 0x802375C0: b           L_80237620
    // 0x802375C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80237620;
    // 0x802375C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802375C8:
    // 0x802375C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802375CC: bnel        $v0, $at, L_80237620
    if (ctx->r2 != ctx->r1) {
        // 0x802375D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237620;
    }
    goto skip_5;
    // 0x802375D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x802375D4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x802375D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802375DC: bnel        $t5, $zero, L_80237620
    if (ctx->r13 != 0) {
        // 0x802375E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237620;
    }
    goto skip_6;
    // 0x802375E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x802375E4: jal         0x80147148
    // 0x802375E8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x80147148)(rdram, ctx);
        goto after_8;
    // 0x802375E8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_8:
    // 0x802375EC: jal         0x80236BC8
    // 0x802375F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80236BC8)(rdram, ctx);
        goto after_9;
    // 0x802375F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x802375F4: jal         0x80236A3C
    // 0x802375F8: nop

    LOOKUP_FUNC(0x80236A3C)(rdram, ctx);
        goto after_10;
    // 0x802375F8: nop

    after_10:
    // 0x802375FC: jal         0x80236BD8
    // 0x80237600: nop

    LOOKUP_FUNC(0x80236BD8)(rdram, ctx);
        goto after_11;
    // 0x80237600: nop

    after_11:
    // 0x80237604: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237608: addiu       $a1, $a1, 0x7630
    ctx->r5 = ADD32(ctx->r5, 0X7630);
    // 0x8023760C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237610: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80237614: jal         0x80148FC4
    // 0x80237618: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_12;
    // 0x80237618: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8023761C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80237620:
    // 0x80237620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80237624: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80237628: jr          $ra
    // 0x8023762C: nop

    return;
    // 0x8023762C: nop

;}
RECOMP_FUNC void M10_FUN_80237630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80237634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80237638: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023763C: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x80237640: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80237644: addiu       $a1, $a1, 0x1D78
    ctx->r5 = ADD32(ctx->r5, 0X1D78);
    // 0x80237648: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8023764C: lw          $t7, 0x9C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C);
    // 0x80237650: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80237654: jal         0x80005670
    // 0x80237658: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x80237658: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8023765C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80237660: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237664: addiu       $a1, $a1, 0x7694
    ctx->r5 = ADD32(ctx->r5, 0X7694);
    // 0x80237668: lb          $t8, 0xAA($a0)
    ctx->r24 = MEM_B(ctx->r4, 0XAA);
    // 0x8023766C: sb          $t8, 0x91($v0)
    MEM_B(0X91, ctx->r2) = ctx->r24;
    // 0x80237670: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80237674: sw          $t9, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r25;
    // 0x80237678: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8023767C: jal         0x800058DC
    // 0x80237680: sw          $t0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80237680: sw          $t0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r8;
    after_1:
    // 0x80237684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80237688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023768C: jr          $ra
    // 0x80237690: nop

    return;
    // 0x80237690: nop

;}
RECOMP_FUNC void M10_FUN_80237694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237694: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80237698: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8023769C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802376A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802376A4: lb          $t6, 0xAB($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XAB);
    // 0x802376A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802376AC: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x802376B0: beq         $t6, $zero, L_802376FC
    if (ctx->r14 == 0) {
        // 0x802376B4: lui         $t7, 0x8039
        ctx->r15 = S32(0X8039 << 16);
            goto L_802376FC;
    }
    // 0x802376B4: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x802376B8: addiu       $t7, $t7, -0x3290
    ctx->r15 = ADD32(ctx->r15, -0X3290);
    // 0x802376BC: sw          $t7, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r15;
    // 0x802376C0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x802376C4: jal         0x80376CCC
    // 0x802376C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80376CCC)(rdram, ctx);
        goto after_0;
    // 0x802376C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x802376CC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x802376D0: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x802376D4: addiu       $a1, $a1, 0x7768
    ctx->r5 = ADD32(ctx->r5, 0X7768);
    // 0x802376D8: lbu         $t8, 0x31($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31);
    // 0x802376DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802376E0: andi        $t1, $t8, 0xFFF8
    ctx->r9 = ctx->r24 & 0XFFF8;
    // 0x802376E4: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x802376E8: sb          $t1, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r9;
    // 0x802376EC: jal         0x800058DC
    // 0x802376F0: sb          $t2, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x802376F0: sb          $t2, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r10;
    after_1:
    // 0x802376F4: b           L_80237758
    // 0x802376F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80237758;
    // 0x802376F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802376FC:
    // 0x802376FC: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80237700: bnel        $t3, $zero, L_80237758
    if (ctx->r11 != 0) {
        // 0x80237704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237758;
    }
    goto skip_0;
    // 0x80237704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80237708: jal         0x80236A48
    // 0x8023770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236A48)(rdram, ctx);
        goto after_2;
    // 0x8023770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80237710: beql        $v0, $zero, L_80237758
    if (ctx->r2 == 0) {
        // 0x80237714: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237758;
    }
    goto skip_1;
    // 0x80237714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80237718: jal         0x80236BC8
    // 0x8023771C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80236BC8)(rdram, ctx);
        goto after_3;
    // 0x8023771C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80237720: jal         0x80236C9C
    // 0x80237724: sb          $zero, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = 0;
    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_4;
    // 0x80237724: sb          $zero, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = 0;
    after_4:
    // 0x80237728: beq         $v0, $zero, L_80237748
    if (ctx->r2 == 0) {
        // 0x8023772C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237748;
    }
    // 0x8023772C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237730: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80237734: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x80237738: jal         0x800058DC
    // 0x8023773C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8023773C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80237740: b           L_80237758
    // 0x80237744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80237758;
    // 0x80237744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80237748:
    // 0x80237748: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x8023774C: jal         0x800058DC
    // 0x80237750: addiu       $a1, $a1, 0x748C
    ctx->r5 = ADD32(ctx->r5, 0X748C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80237750: addiu       $a1, $a1, 0x748C
    ctx->r5 = ADD32(ctx->r5, 0X748C);
    after_6:
    // 0x80237754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80237758:
    // 0x80237758: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8023775C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80237760: jr          $ra
    // 0x80237764: nop

    return;
    // 0x80237764: nop

;}
RECOMP_FUNC void M10_FUN_80237768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023776C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80237770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80237774: jal         0x80148E80
    // 0x80237778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80148E80)(rdram, ctx);
        goto after_0;
    // 0x80237778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8023777C: beql        $v0, $zero, L_802377C0
    if (ctx->r2 == 0) {
        // 0x80237780: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802377C0;
    }
    goto skip_0;
    // 0x80237780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80237784: jal         0x80236A48
    // 0x80237788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80236A48)(rdram, ctx);
        goto after_1;
    // 0x80237788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8023778C: beql        $v0, $zero, L_802377C0
    if (ctx->r2 == 0) {
        // 0x80237790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802377C0;
    }
    goto skip_1;
    // 0x80237790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80237794: jal         0x80236BC8
    // 0x80237798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80236BC8)(rdram, ctx);
        goto after_2;
    // 0x80237798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8023779C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x802377A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x802377A4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802377A8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x802377AC: bnel        $t7, $zero, L_802377C0
    if (ctx->r15 != 0) {
        // 0x802377B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_802377C0;
    }
    goto skip_2;
    // 0x802377B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x802377B4: jal         0x800058DC
    // 0x802377B8: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x802377B8: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    after_3:
    // 0x802377BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802377C0:
    // 0x802377C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802377C4: jr          $ra
    // 0x802377C8: nop

    return;
    // 0x802377C8: nop

;}
RECOMP_FUNC void M10_FUN_802377cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802377CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x802377D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x802377D4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x802377D8: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x802377DC: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x802377E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x802377E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x802377E8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x802377EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x802377F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x802377F4: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x802377F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x802377FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80237800: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80237804: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80237808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8023780C: jal         0x80146178
    // 0x80237810: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_0;
    // 0x80237810: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80237814: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237818: addiu       $a1, $a1, 0x7834
    ctx->r5 = ADD32(ctx->r5, 0X7834);
    // 0x8023781C: jal         0x800058DC
    // 0x80237820: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80237820: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80237824: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80237828: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8023782C: jr          $ra
    // 0x80237830: nop

    return;
    // 0x80237830: nop

;}
RECOMP_FUNC void M10_FUN_80237834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237834: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80237838: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8023783C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237840: ldc1        $f4, 0x5A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X5A0);
    // 0x80237844: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x80237848: lbu         $v0, 0xB($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB);
    // 0x8023784C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80237850: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80237854: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80237858: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8023785C: nop

    // 0x80237860: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80237864: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80237868: nop

    // 0x8023786C: bc1f        L_80237878
    if (!c1cs) {
        // 0x80237870: nop
    
            goto L_80237878;
    }
    // 0x80237870: nop

    // 0x80237874: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
L_80237878:
    // 0x80237878: jr          $ra
    // 0x8023787C: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    return;
    // 0x8023787C: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80237880(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80237880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80237884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80237888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023788C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80237890: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237894: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x80237898: lbu         $v0, 0xB($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB);
    // 0x8023789C: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x802378A0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802378A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802378A8: bgezl       $v0, L_802378C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x802378AC: sb          $v0, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r2;
            goto L_802378C4;
    }
    goto skip_0;
    // 0x802378AC: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    skip_0:
    // 0x802378B0: jal         0x80005700
    // 0x802378B4: sw          $zero, -0x1C40($at)
    MEM_W(-0X1C40, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x802378B4: sw          $zero, -0x1C40($at)
    MEM_W(-0X1C40, ctx->r1) = 0;
    after_0:
    // 0x802378B8: b           L_802378C8
    // 0x802378BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802378C8;
    // 0x802378BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802378C0: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
L_802378C4:
    // 0x802378C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802378C8:
    // 0x802378C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802378CC: jr          $ra
    // 0x802378D0: nop

    return;
    // 0x802378D0: nop

;}
RECOMP_FUNC void M10_FUN_802378d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802378D4: jr          $ra
    // 0x802378D8: nop

    return;
    // 0x802378D8: nop

;}
RECOMP_FUNC void M10_FUN_802378dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802378DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x802378E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802378E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802378E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x802378EC: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x802378F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802378F4: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x802378F8: bnel        $t6, $zero, L_80237A90
    if (ctx->r14 != 0) {
        // 0x802378FC: lb          $v0, 0xA2($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XA2);
            goto L_80237A90;
    }
    goto skip_0;
    // 0x802378FC: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
    skip_0:
    // 0x80237900: jal         0x80235D48
    // 0x80237904: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80235D48)(rdram, ctx);
        goto after_0;
    // 0x80237904: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80237908: bne         $v0, $zero, L_80237A8C
    if (ctx->r2 != 0) {
        // 0x8023790C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80237A8C;
    }
    // 0x8023790C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80237910: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80237914: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80237918: bne         $t7, $zero, L_80237934
    if (ctx->r15 != 0) {
        // 0x8023791C: nop
    
            goto L_80237934;
    }
    // 0x8023791C: nop

    // 0x80237920: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80237924: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80237928: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x8023792C: beq         $t8, $zero, L_80237958
    if (ctx->r24 == 0) {
        // 0x80237930: nop
    
            goto L_80237958;
    }
    // 0x80237930: nop

L_80237934:
    // 0x80237934: jal         0x80020744
    // 0x80237938: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80237938: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x8023793C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80237940: sb          $t9, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r25;
    // 0x80237944: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237948: jal         0x80236408
    // 0x8023794C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236408)(rdram, ctx);
        goto after_2;
    // 0x8023794C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80237950: b           L_80237A80
    // 0x80237954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237A80;
    // 0x80237954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237958:
    // 0x80237958: bne         $t0, $zero, L_80237968
    if (ctx->r8 != 0) {
        // 0x8023795C: andi        $t1, $a0, 0x8000
        ctx->r9 = ctx->r4 & 0X8000;
            goto L_80237968;
    }
    // 0x8023795C: andi        $t1, $a0, 0x8000
    ctx->r9 = ctx->r4 & 0X8000;
    // 0x80237960: beql        $t1, $zero, L_80237A80
    if (ctx->r9 == 0) {
        // 0x80237964: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237A80;
    }
    goto skip_1;
    // 0x80237964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80237968:
    // 0x80237968: jal         0x80020744
    // 0x8023796C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x8023796C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_3:
    // 0x80237970: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80237974: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80237978: sb          $t2, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r10;
    // 0x8023797C: sb          $t3, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r11;
    // 0x80237980: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237984: sb          $zero, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = 0;
    // 0x80237988: jal         0x80236374
    // 0x8023798C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236374)(rdram, ctx);
        goto after_4;
    // 0x8023798C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80237990: beq         $v0, $zero, L_802379A8
    if (ctx->r2 == 0) {
        // 0x80237994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802379A8;
    }
    // 0x80237994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237998: jal         0x802366A0
    // 0x8023799C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802366A0)(rdram, ctx);
        goto after_5;
    // 0x8023799C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x802379A0: b           L_80237A64
    // 0x802379A4: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x802379A4: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_802379A8:
    // 0x802379A8: jal         0x8023639C
    // 0x802379AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023639C)(rdram, ctx);
        goto after_6;
    // 0x802379AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x802379B0: beql        $v0, $zero, L_80237A00
    if (ctx->r2 == 0) {
        // 0x802379B4: lb          $v0, 0xA5($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XA5);
            goto L_80237A00;
    }
    goto skip_2;
    // 0x802379B4: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    skip_2:
    // 0x802379B8: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x802379BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802379C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802379C4: beq         $v0, $zero, L_802379DC
    if (ctx->r2 == 0) {
        // 0x802379C8: nop
    
            goto L_802379DC;
    }
    // 0x802379C8: nop

    // 0x802379CC: beq         $v0, $at, L_802379EC
    if (ctx->r2 == ctx->r1) {
        // 0x802379D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802379EC;
    }
    // 0x802379D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802379D4: b           L_80237A64
    // 0x802379D8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x802379D8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_802379DC:
    // 0x802379DC: jal         0x80236640
    // 0x802379E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80236640)(rdram, ctx);
        goto after_7;
    // 0x802379E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x802379E4: b           L_80237A64
    // 0x802379E8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x802379E8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_802379EC:
    // 0x802379EC: jal         0x802366A0
    // 0x802379F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802366A0)(rdram, ctx);
        goto after_8;
    // 0x802379F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x802379F4: b           L_80237A64
    // 0x802379F8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x802379F8: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
    // 0x802379FC: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
L_80237A00:
    // 0x80237A00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237A08: beq         $v0, $zero, L_80237A2C
    if (ctx->r2 == 0) {
        // 0x80237A0C: nop
    
            goto L_80237A2C;
    }
    // 0x80237A0C: nop

    // 0x80237A10: beq         $v0, $at, L_80237A3C
    if (ctx->r2 == ctx->r1) {
        // 0x80237A14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237A3C;
    }
    // 0x80237A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237A18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80237A1C: beq         $v0, $at, L_80237A4C
    if (ctx->r2 == ctx->r1) {
        // 0x80237A20: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80237A4C;
    }
    // 0x80237A20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80237A24: b           L_80237A64
    // 0x80237A28: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x80237A28: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_80237A2C:
    // 0x80237A2C: jal         0x802365E0
    // 0x80237A30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802365E0)(rdram, ctx);
        goto after_9;
    // 0x80237A30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80237A34: b           L_80237A64
    // 0x80237A38: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x80237A38: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_80237A3C:
    // 0x80237A3C: jal         0x80236640
    // 0x80237A40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80236640)(rdram, ctx);
        goto after_10;
    // 0x80237A40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80237A44: b           L_80237A64
    // 0x80237A48: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
        goto L_80237A64;
    // 0x80237A48: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_80237A4C:
    // 0x80237A4C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237A50: sb          $t4, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = ctx->r12;
    // 0x80237A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237A58: jal         0x80236700
    // 0x80237A5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80236700)(rdram, ctx);
        goto after_11;
    // 0x80237A5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x80237A60: lbu         $t5, 0xA7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA7);
L_80237A64:
    // 0x80237A64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80237A68: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80237A6C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80237A70: mflo        $t7
    ctx->r15 = lo;
    // 0x80237A74: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80237A78: sb          $t8, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r24;
    // 0x80237A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237A80:
    // 0x80237A80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237A84: jal         0x80234724
    // 0x80237A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_12;
    // 0x80237A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_80237A8C:
    // 0x80237A8C: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_80237A90:
    // 0x80237A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237A98: bne         $v0, $at, L_80237ACC
    if (ctx->r2 != ctx->r1) {
        // 0x80237A9C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80237ACC;
    }
    // 0x80237A9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237AA0: jal         0x80235394
    // 0x80237AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_13;
    // 0x80237AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80237AA8: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
    // 0x80237AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237AB0: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237AB4: bnel        $t9, $zero, L_80237B6C
    if (ctx->r25 != 0) {
        // 0x80237AB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237B6C;
    }
    goto skip_3;
    // 0x80237AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80237ABC: jal         0x800058DC
    // 0x80237AC0: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80237AC0: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
    after_14:
    // 0x80237AC4: b           L_80237B6C
    // 0x80237AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80237B6C;
    // 0x80237AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80237ACC:
    // 0x80237ACC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80237AD0: bnel        $v0, $at, L_80237B6C
    if (ctx->r2 != ctx->r1) {
        // 0x80237AD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237B6C;
    }
    goto skip_4;
    // 0x80237AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80237AD8: lb          $t0, 0xA5($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XA5);
    // 0x80237ADC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80237AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237AE4: bne         $t0, $at, L_80237B04
    if (ctx->r8 != ctx->r1) {
        // 0x80237AE8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80237B04;
    }
    // 0x80237AE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237AF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80237AF4: jal         0x80235394
    // 0x80237AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_15;
    // 0x80237AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80237AFC: b           L_80237B10
    // 0x80237B00: lb          $t1, 0xA2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA2);
        goto L_80237B10;
    // 0x80237B00: lb          $t1, 0xA2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA2);
L_80237B04:
    // 0x80237B04: jal         0x80235394
    // 0x80237B08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_16;
    // 0x80237B08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_16:
    // 0x80237B0C: lb          $t1, 0xA2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA2);
L_80237B10:
    // 0x80237B10: bnel        $t1, $zero, L_80237B6C
    if (ctx->r9 != 0) {
        // 0x80237B14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80237B6C;
    }
    goto skip_5;
    // 0x80237B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80237B18: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x80237B1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80237B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237B24: bne         $v0, $at, L_80237B44
    if (ctx->r2 != ctx->r1) {
        // 0x80237B28: sb          $v0, 0xA6($s0)
        MEM_B(0XA6, ctx->r16) = ctx->r2;
            goto L_80237B44;
    }
    // 0x80237B28: sb          $v0, 0xA6($s0)
    MEM_B(0XA6, ctx->r16) = ctx->r2;
    // 0x80237B2C: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237B30: addiu       $a1, $a1, 0x7EC8
    ctx->r5 = ADD32(ctx->r5, 0X7EC8);
    // 0x80237B34: jal         0x800058DC
    // 0x80237B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x80237B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80237B3C: b           L_80237B68
    // 0x80237B40: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
        goto L_80237B68;
    // 0x80237B40: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
L_80237B44:
    // 0x80237B44: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237B48: jal         0x800058DC
    // 0x80237B4C: addiu       $a1, $a1, 0x7B7C
    ctx->r5 = ADD32(ctx->r5, 0X7B7C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x80237B4C: addiu       $a1, $a1, 0x7B7C
    ctx->r5 = ADD32(ctx->r5, 0X7B7C);
    after_18:
    // 0x80237B50: lb          $t2, 0xA3($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA3);
    // 0x80237B54: bgez        $t2, L_80237B64
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80237B58: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80237B64;
    }
    // 0x80237B58: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80237B5C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80237B60: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80237B64:
    // 0x80237B64: sb          $t3, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r11;
L_80237B68:
    // 0x80237B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80237B6C:
    // 0x80237B6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80237B70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80237B74: jr          $ra
    // 0x80237B78: nop

    return;
    // 0x80237B78: nop

;}
RECOMP_FUNC void M10_FUN_80237b7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237B7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80237B80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80237B84: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80237B88: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80237B8C: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x80237B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80237B94: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80237B98: bnel        $t6, $zero, L_80237D9C
    if (ctx->r14 != 0) {
        // 0x80237B9C: lb          $v0, 0xA2($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XA2);
            goto L_80237D9C;
    }
    goto skip_0;
    // 0x80237B9C: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
    skip_0:
    // 0x80237BA0: jal         0x80235EB4
    // 0x80237BA4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80235EB4)(rdram, ctx);
        goto after_0;
    // 0x80237BA4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x80237BA8: bne         $v0, $zero, L_80237D98
    if (ctx->r2 != 0) {
        // 0x80237BAC: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80237D98;
    }
    // 0x80237BAC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80237BB0: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80237BB4: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80237BB8: bne         $t7, $zero, L_80237BD4
    if (ctx->r15 != 0) {
        // 0x80237BBC: nop
    
            goto L_80237BD4;
    }
    // 0x80237BBC: nop

    // 0x80237BC0: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80237BC4: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x80237BC8: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x80237BCC: beq         $t8, $zero, L_80237C64
    if (ctx->r24 == 0) {
        // 0x80237BD0: nop
    
            goto L_80237C64;
    }
    // 0x80237BD0: nop

L_80237BD4:
    // 0x80237BD4: jal         0x80020744
    // 0x80237BD8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80237BD8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x80237BDC: lb          $t0, 0xA1($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XA1);
    // 0x80237BE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80237BE4: sb          $t9, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r25;
    // 0x80237BE8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80237BEC: sb          $t1, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r9;
    // 0x80237BF0: lb          $t2, 0xA1($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA1);
    // 0x80237BF4: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80237BF8: bne         $t2, $zero, L_80237C34
    if (ctx->r10 != 0) {
        // 0x80237BFC: nop
    
            goto L_80237C34;
    }
    // 0x80237BFC: nop

    // 0x80237C00: lbu         $t3, -0x1C5C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1C5C);
    // 0x80237C04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237C0C: bne         $t3, $zero, L_80237C24
    if (ctx->r11 != 0) {
        // 0x80237C10: nop
    
            goto L_80237C24;
    }
    // 0x80237C10: nop

    // 0x80237C14: jal         0x802364E8
    // 0x80237C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802364E8)(rdram, ctx);
        goto after_2;
    // 0x80237C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80237C1C: b           L_80237D8C
    // 0x80237C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237D8C;
    // 0x80237C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237C24:
    // 0x80237C24: jal         0x8023648C
    // 0x80237C28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8023648C)(rdram, ctx);
        goto after_3;
    // 0x80237C28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80237C2C: b           L_80237D8C
    // 0x80237C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237D8C;
    // 0x80237C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237C34:
    // 0x80237C34: jal         0x802362B8
    // 0x80237C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802362B8)(rdram, ctx);
        goto after_4;
    // 0x80237C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80237C3C: sb          $v0, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r2;
    // 0x80237C40: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80237C44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80237C48: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80237C54: jal         0x80234ED4
    // 0x80237C58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_5;
    // 0x80237C58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80237C5C: b           L_80237D8C
    // 0x80237C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237D8C;
    // 0x80237C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237C64:
    // 0x80237C64: beq         $t5, $zero, L_80237CC8
    if (ctx->r13 == 0) {
        // 0x80237C68: andi        $t2, $a0, 0x8000
        ctx->r10 = ctx->r4 & 0X8000;
            goto L_80237CC8;
    }
    // 0x80237C68: andi        $t2, $a0, 0x8000
    ctx->r10 = ctx->r4 & 0X8000;
    // 0x80237C6C: lb          $t6, 0xA1($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XA1);
    // 0x80237C70: lb          $t7, 0xA0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA0);
    // 0x80237C74: beql        $t6, $t7, L_80237D8C
    if (ctx->r14 == ctx->r15) {
        // 0x80237C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237D8C;
    }
    goto skip_1;
    // 0x80237C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80237C7C: jal         0x80020744
    // 0x80237C80: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_6;
    // 0x80237C80: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_6:
    // 0x80237C84: lb          $t9, 0xA1($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA1);
    // 0x80237C88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80237C8C: sb          $t8, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r24;
    // 0x80237C90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80237C94: sb          $t0, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r8;
    // 0x80237C98: jal         0x802362B8
    // 0x80237C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802362B8)(rdram, ctx);
        goto after_7;
    // 0x80237C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80237CA0: sb          $v0, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r2;
    // 0x80237CA4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80237CA8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80237CAC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80237CB8: jal         0x80234ED4
    // 0x80237CBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_8;
    // 0x80237CBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80237CC0: b           L_80237D8C
    // 0x80237CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237D8C;
    // 0x80237CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237CC8:
    // 0x80237CC8: beql        $t2, $zero, L_80237D8C
    if (ctx->r10 == 0) {
        // 0x80237CCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237D8C;
    }
    goto skip_2;
    // 0x80237CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80237CD0: lb          $t3, 0xA5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA5);
    // 0x80237CD4: lb          $t4, 0xA4($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XA4);
    // 0x80237CD8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80237CDC: beql        $at, $zero, L_80237D8C
    if (ctx->r1 == 0) {
        // 0x80237CE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237D8C;
    }
    goto skip_3;
    // 0x80237CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80237CE4: jal         0x80020744
    // 0x80237CE8: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_9;
    // 0x80237CE8: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_9:
    // 0x80237CEC: lb          $v1, 0xA5($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XA5);
    // 0x80237CF0: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80237CF4: addiu       $t6, $t6, 0x828
    ctx->r14 = ADD32(ctx->r14, 0X828);
    // 0x80237CF8: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80237CFC: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80237D00: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80237D04: sh          $zero, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = 0;
    // 0x80237D08: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80237D0C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80237D10: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80237D14: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80237D18: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80237D1C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80237D20: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80237D24: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80237D28: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80237D2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80237D30: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80237D34: addiu       $a3, $a3, 0x570
    ctx->r7 = ADD32(ctx->r7, 0X570);
    // 0x80237D38: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80237D3C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80237D40: jal         0x8001B204
    // 0x80237D44: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x80237D44: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_10:
    // 0x80237D48: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80237D4C: lbu         $t0, -0x1C5C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1C5C);
    // 0x80237D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237D54: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80237D58: bne         $t0, $zero, L_80237D78
    if (ctx->r8 != 0) {
        // 0x80237D5C: nop
    
            goto L_80237D78;
    }
    // 0x80237D5C: nop

    // 0x80237D60: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80237D64: addiu       $a1, $a1, -0x6430
    ctx->r5 = ADD32(ctx->r5, -0X6430);
    // 0x80237D68: jal         0x800058DC
    // 0x80237D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80237D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80237D70: b           L_80237EB8
    // 0x80237D74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80237EB8;
    // 0x80237D74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80237D78:
    // 0x80237D78: jal         0x800058DC
    // 0x80237D7C: addiu       $a1, $a1, -0x630C
    ctx->r5 = ADD32(ctx->r5, -0X630C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x80237D7C: addiu       $a1, $a1, -0x630C
    ctx->r5 = ADD32(ctx->r5, -0X630C);
    after_12:
    // 0x80237D80: b           L_80237EB8
    // 0x80237D84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80237EB8;
    // 0x80237D84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80237D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237D8C:
    // 0x80237D8C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237D90: jal         0x80234724
    // 0x80237D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_13;
    // 0x80237D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_80237D98:
    // 0x80237D98: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_80237D9C:
    // 0x80237D9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237DA0: bnel        $v0, $at, L_80237E6C
    if (ctx->r2 != ctx->r1) {
        // 0x80237DA4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80237E6C;
    }
    goto skip_4;
    // 0x80237DA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_4:
    // 0x80237DA8: lb          $t1, 0xA1($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA1);
    // 0x80237DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80237DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237DB4: bne         $t1, $zero, L_80237DD0
    if (ctx->r9 != 0) {
        // 0x80237DB8: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80237DD0;
    }
    // 0x80237DB8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237DC0: jal         0x80235394
    // 0x80237DC4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_14;
    // 0x80237DC4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_14:
    // 0x80237DC8: b           L_80237DDC
    // 0x80237DCC: lb          $t2, 0xA2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA2);
        goto L_80237DDC;
    // 0x80237DCC: lb          $t2, 0xA2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA2);
L_80237DD0:
    // 0x80237DD0: jal         0x80235394
    // 0x80237DD4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_15;
    // 0x80237DD4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_15:
    // 0x80237DD8: lb          $t2, 0xA2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA2);
L_80237DDC:
    // 0x80237DDC: bnel        $t2, $zero, L_80237EB8
    if (ctx->r10 != 0) {
        // 0x80237DE0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80237EB8;
    }
    goto skip_5;
    // 0x80237DE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80237DE4: lb          $t3, 0xA1($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA1);
    // 0x80237DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237DEC: bnel        $t3, $zero, L_80237E40
    if (ctx->r11 != 0) {
        // 0x80237DF0: lb          $t6, 0xA3($s0)
        ctx->r14 = MEM_B(ctx->r16, 0XA3);
            goto L_80237E40;
    }
    goto skip_6;
    // 0x80237DF0: lb          $t6, 0xA3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XA3);
    skip_6:
    // 0x80237DF4: lb          $t4, 0xA6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XA6);
    // 0x80237DF8: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80237DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237E00: sb          $t4, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r12;
    // 0x80237E04: lbu         $t5, -0x1C5C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1C5C);
    // 0x80237E08: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80237E0C: bne         $t5, $zero, L_80237E2C
    if (ctx->r13 != 0) {
        // 0x80237E10: nop
    
            goto L_80237E2C;
    }
    // 0x80237E10: nop

    // 0x80237E14: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237E18: addiu       $a1, $a1, 0x78DC
    ctx->r5 = ADD32(ctx->r5, 0X78DC);
    // 0x80237E1C: jal         0x800058DC
    // 0x80237E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80237E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80237E24: b           L_80237EB8
    // 0x80237E28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80237EB8;
    // 0x80237E28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80237E2C:
    // 0x80237E2C: jal         0x800058DC
    // 0x80237E30: addiu       $a1, $a1, -0x7DAC
    ctx->r5 = ADD32(ctx->r5, -0X7DAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x80237E30: addiu       $a1, $a1, -0x7DAC
    ctx->r5 = ADD32(ctx->r5, -0X7DAC);
    after_17:
    // 0x80237E34: b           L_80237EB8
    // 0x80237E38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80237EB8;
    // 0x80237E38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80237E3C: lb          $t6, 0xA3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XA3);
L_80237E40:
    // 0x80237E40: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237E44: addiu       $a1, $a1, 0x7B7C
    ctx->r5 = ADD32(ctx->r5, 0X7B7C);
    // 0x80237E48: bgez        $t6, L_80237E58
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80237E4C: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80237E58;
    }
    // 0x80237E4C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80237E50: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80237E54: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80237E58:
    // 0x80237E58: jal         0x800058DC
    // 0x80237E5C: sb          $t7, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x80237E5C: sb          $t7, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r15;
    after_18:
    // 0x80237E60: b           L_80237EB8
    // 0x80237E64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80237EB8;
    // 0x80237E64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80237E68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80237E6C:
    // 0x80237E6C: bne         $v0, $at, L_80237EB4
    if (ctx->r2 != ctx->r1) {
        // 0x80237E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237EB4;
    }
    // 0x80237E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237E74: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80237E78: jal         0x80235394
    // 0x80237E7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_19;
    // 0x80237E7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_19:
    // 0x80237E80: lb          $t8, 0xA2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XA2);
    // 0x80237E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237E88: bnel        $t8, $zero, L_80237EB8
    if (ctx->r24 != 0) {
        // 0x80237E8C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80237EB8;
    }
    goto skip_7;
    // 0x80237E8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80237E90: lb          $t9, 0xA3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA3);
    // 0x80237E94: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80237E98: addiu       $a1, $a1, 0x7B7C
    ctx->r5 = ADD32(ctx->r5, 0X7B7C);
    // 0x80237E9C: bgez        $t9, L_80237EAC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80237EA0: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_80237EAC;
    }
    // 0x80237EA0: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80237EA4: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80237EA8: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80237EAC:
    // 0x80237EAC: jal         0x800058DC
    // 0x80237EB0: sb          $t0, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_20;
    // 0x80237EB0: sb          $t0, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r8;
    after_20:
L_80237EB4:
    // 0x80237EB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80237EB8:
    // 0x80237EB8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80237EBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80237EC0: jr          $ra
    // 0x80237EC4: nop

    return;
    // 0x80237EC4: nop

;}
RECOMP_FUNC void M10_FUN_80237ec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80237EC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80237ECC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80237ED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80237ED4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80237ED8: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x80237EDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80237EE0: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80237EE4: bnel        $t6, $zero, L_80237FE8
    if (ctx->r14 != 0) {
        // 0x80237EE8: lb          $v0, 0xA2($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XA2);
            goto L_80237FE8;
    }
    goto skip_0;
    // 0x80237EE8: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
    skip_0:
    // 0x80237EEC: jal         0x80235D48
    // 0x80237EF0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80235D48)(rdram, ctx);
        goto after_0;
    // 0x80237EF0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80237EF4: bne         $v0, $zero, L_80237FE4
    if (ctx->r2 != 0) {
        // 0x80237EF8: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80237FE4;
    }
    // 0x80237EF8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80237EFC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237F00: sb          $zero, -0x1C58($at)
    MEM_B(-0X1C58, ctx->r1) = 0;
    // 0x80237F04: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80237F08: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80237F0C: bne         $t7, $zero, L_80237F28
    if (ctx->r15 != 0) {
        // 0x80237F10: nop
    
            goto L_80237F28;
    }
    // 0x80237F10: nop

    // 0x80237F14: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80237F18: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80237F1C: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x80237F20: beq         $t8, $zero, L_80237F4C
    if (ctx->r24 == 0) {
        // 0x80237F24: nop
    
            goto L_80237F4C;
    }
    // 0x80237F24: nop

L_80237F28:
    // 0x80237F28: jal         0x80020744
    // 0x80237F2C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80237F2C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x80237F30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80237F34: sb          $t9, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r25;
    // 0x80237F38: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80237F3C: jal         0x802364E8
    // 0x80237F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x802364E8)(rdram, ctx);
        goto after_2;
    // 0x80237F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80237F44: b           L_80237FD8
    // 0x80237F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237FD8;
    // 0x80237F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237F4C:
    // 0x80237F4C: bne         $t0, $zero, L_80237F5C
    if (ctx->r8 != 0) {
        // 0x80237F50: andi        $t1, $a0, 0x8000
        ctx->r9 = ctx->r4 & 0X8000;
            goto L_80237F5C;
    }
    // 0x80237F50: andi        $t1, $a0, 0x8000
    ctx->r9 = ctx->r4 & 0X8000;
    // 0x80237F54: beql        $t1, $zero, L_80237FD8
    if (ctx->r9 == 0) {
        // 0x80237F58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80237FD8;
    }
    goto skip_1;
    // 0x80237F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80237F5C:
    // 0x80237F5C: jal         0x80020744
    // 0x80237F60: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80237F60: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_3:
    // 0x80237F64: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x80237F68: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80237F6C: sb          $t2, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r10;
    // 0x80237F70: beq         $v0, $zero, L_80237F8C
    if (ctx->r2 == 0) {
        // 0x80237F74: sb          $zero, 0xA1($s0)
        MEM_B(0XA1, ctx->r16) = 0;
            goto L_80237F8C;
    }
    // 0x80237F74: sb          $zero, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = 0;
    // 0x80237F78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237F7C: beq         $v0, $at, L_80237FB4
    if (ctx->r2 == ctx->r1) {
        // 0x80237F80: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_80237FB4;
    }
    // 0x80237F80: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80237F84: b           L_80237FD8
    // 0x80237F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237FD8;
    // 0x80237F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237F8C:
    // 0x80237F8C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237F90: sb          $zero, -0x1C54($at)
    MEM_B(-0X1C54, ctx->r1) = 0;
    // 0x80237F94: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80237F98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80237F9C: sb          $t3, -0x1C58($at)
    MEM_B(-0X1C58, ctx->r1) = ctx->r11;
    // 0x80237FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237FA4: jal         0x8023648C
    // 0x80237FA8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x8023648C)(rdram, ctx);
        goto after_4;
    // 0x80237FA8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80237FAC: b           L_80237FD8
    // 0x80237FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80237FD8;
    // 0x80237FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237FB4:
    // 0x80237FB4: sb          $t4, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r12;
    // 0x80237FB8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80237FBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80237FC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80237FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80237FCC: jal         0x80234ED4
    // 0x80237FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_5;
    // 0x80237FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80237FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80237FD8:
    // 0x80237FD8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80237FDC: jal         0x80234724
    // 0x80237FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_6;
    // 0x80237FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80237FE4:
    // 0x80237FE4: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_80237FE8:
    // 0x80237FE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80237FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80237FF0: bne         $v0, $at, L_80238034
    if (ctx->r2 != ctx->r1) {
        // 0x80237FF4: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_80238034;
    }
    // 0x80237FF4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80237FF8: jal         0x80235394
    // 0x80237FFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_7;
    // 0x80237FFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80238000: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80238004: sb          $t6, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r14;
    // 0x80238008: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023800C: sb          $zero, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = 0;
    // 0x80238010: lb          $t7, 0xA2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA2);
    // 0x80238014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238018: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x8023801C: bnel        $t7, $zero, L_802380DC
    if (ctx->r15 != 0) {
        // 0x80238020: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_802380DC;
    }
    goto skip_2;
    // 0x80238020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80238024: jal         0x800058DC
    // 0x80238028: addiu       $a1, $a1, 0x78DC
    ctx->r5 = ADD32(ctx->r5, 0X78DC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80238028: addiu       $a1, $a1, 0x78DC
    ctx->r5 = ADD32(ctx->r5, 0X78DC);
    after_8:
    // 0x8023802C: b           L_802380DC
    // 0x80238030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802380DC;
    // 0x80238030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80238034:
    // 0x80238034: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80238038: bnel        $v0, $at, L_802380DC
    if (ctx->r2 != ctx->r1) {
        // 0x8023803C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_802380DC;
    }
    goto skip_3;
    // 0x8023803C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80238040: lb          $t8, 0xA5($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XA5);
    // 0x80238044: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80238048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023804C: bne         $t8, $zero, L_80238068
    if (ctx->r24 != 0) {
        // 0x80238050: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_80238068;
    }
    // 0x80238050: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80238054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238058: jal         0x80235394
    // 0x8023805C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_9;
    // 0x8023805C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80238060: b           L_80238074
    // 0x80238064: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
        goto L_80238074;
    // 0x80238064: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
L_80238068:
    // 0x80238068: jal         0x80235394
    // 0x8023806C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_10;
    // 0x8023806C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80238070: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
L_80238074:
    // 0x80238074: bnel        $t9, $zero, L_802380DC
    if (ctx->r25 != 0) {
        // 0x80238078: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_802380DC;
    }
    goto skip_4;
    // 0x80238078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8023807C: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x80238080: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80238084: addiu       $a1, $a1, -0x7DAC
    ctx->r5 = ADD32(ctx->r5, -0X7DAC);
    // 0x80238088: beq         $v0, $zero, L_802380A4
    if (ctx->r2 == 0) {
        // 0x8023808C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802380A4;
    }
    // 0x8023808C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80238094: beq         $v0, $at, L_802380B4
    if (ctx->r2 == ctx->r1) {
        // 0x80238098: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_802380B4;
    }
    // 0x80238098: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8023809C: b           L_802380DC
    // 0x802380A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802380DC;
    // 0x802380A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802380A4:
    // 0x802380A4: jal         0x800058DC
    // 0x802380A8: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x802380A8: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
    after_11:
    // 0x802380AC: b           L_802380DC
    // 0x802380B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802380DC;
    // 0x802380B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802380B4:
    // 0x802380B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x802380B8: sb          $t1, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r9;
    // 0x802380BC: lb          $t2, 0xA0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA0);
    // 0x802380C0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802380C4: sb          $t0, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r8;
    // 0x802380C8: addiu       $a1, $a1, -0x7F14
    ctx->r5 = ADD32(ctx->r5, -0X7F14);
    // 0x802380CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802380D0: jal         0x800058DC
    // 0x802380D4: sb          $t2, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x802380D4: sb          $t2, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r10;
    after_12:
    // 0x802380D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802380DC:
    // 0x802380DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802380E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x802380E4: jr          $ra
    // 0x802380E8: nop

    return;
    // 0x802380E8: nop

;}
RECOMP_FUNC void M10_FUN_802380ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802380EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x802380F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x802380F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x802380F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x802380FC: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x80238100: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80238104: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80238108: bnel        $t6, $zero, L_80238208
    if (ctx->r14 != 0) {
        // 0x8023810C: lb          $t9, 0xA2($s0)
        ctx->r25 = MEM_B(ctx->r16, 0XA2);
            goto L_80238208;
    }
    goto skip_0;
    // 0x8023810C: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
    skip_0:
    // 0x80238110: jal         0x80235EB4
    // 0x80238114: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80235EB4)(rdram, ctx);
        goto after_0;
    // 0x80238114: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x80238118: bne         $v0, $zero, L_80238204
    if (ctx->r2 != 0) {
        // 0x8023811C: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80238204;
    }
    // 0x8023811C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80238120: lhu         $t7, 0xC($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XC);
    // 0x80238124: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80238128: bne         $t8, $zero, L_80238140
    if (ctx->r24 != 0) {
        // 0x8023812C: nop
    
            goto L_80238140;
    }
    // 0x8023812C: nop

    // 0x80238130: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80238134: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x80238138: beq         $t9, $zero, L_80238164
    if (ctx->r25 == 0) {
        // 0x8023813C: andi        $t1, $v0, 0x8000
        ctx->r9 = ctx->r2 & 0X8000;
            goto L_80238164;
    }
    // 0x8023813C: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
L_80238140:
    // 0x80238140: jal         0x80020744
    // 0x80238144: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80238144: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x80238148: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8023814C: sb          $t0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r8;
    // 0x80238150: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80238154: jal         0x80236700
    // 0x80238158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236700)(rdram, ctx);
        goto after_2;
    // 0x80238158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8023815C: b           L_802381F8
    // 0x80238160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_802381F8;
    // 0x80238160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80238164:
    // 0x80238164: beql        $t1, $zero, L_802381F8
    if (ctx->r9 == 0) {
        // 0x80238168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802381F8;
    }
    goto skip_1;
    // 0x80238168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8023816C: lb          $t2, 0xA5($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA5);
    // 0x80238170: lb          $t3, 0xA4($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA4);
    // 0x80238174: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80238178: beql        $at, $zero, L_802381F8
    if (ctx->r1 == 0) {
        // 0x8023817C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802381F8;
    }
    goto skip_2;
    // 0x8023817C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80238180: jal         0x80020744
    // 0x80238184: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80238184: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_3:
    // 0x80238188: lb          $v1, 0xA5($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XA5);
    // 0x8023818C: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80238190: addiu       $t5, $t5, 0x828
    ctx->r13 = ADD32(ctx->r13, 0X828);
    // 0x80238194: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80238198: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8023819C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x802381A0: sh          $zero, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = 0;
    // 0x802381A4: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x802381A8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x802381AC: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x802381B0: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x802381B4: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x802381B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x802381BC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x802381C0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x802381C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x802381C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x802381CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802381D0: addiu       $a3, $a3, 0x578
    ctx->r7 = ADD32(ctx->r7, 0X578);
    // 0x802381D4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x802381D8: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x802381DC: jal         0x8001B204
    // 0x802381E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x802381E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_4:
    // 0x802381E4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802381E8: addiu       $a1, $a1, -0x6204
    ctx->r5 = ADD32(ctx->r5, -0X6204);
    // 0x802381EC: jal         0x800058DC
    // 0x802381F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x802381F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x802381F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_802381F8:
    // 0x802381F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x802381FC: jal         0x80234724
    // 0x80238200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_6;
    // 0x80238200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_80238204:
    // 0x80238204: lb          $t9, 0xA2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA2);
L_80238208:
    // 0x80238208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023820C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238210: bne         $t9, $at, L_80238240
    if (ctx->r25 != ctx->r1) {
        // 0x80238214: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80238240;
    }
    // 0x80238214: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80238218: jal         0x80235394
    // 0x8023821C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_7;
    // 0x8023821C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80238220: lb          $t1, 0xA2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA2);
    // 0x80238224: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80238228: sb          $t0, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r8;
    // 0x8023822C: bne         $t1, $zero, L_80238240
    if (ctx->r9 != 0) {
        // 0x80238230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80238240;
    }
    // 0x80238230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238234: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80238238: jal         0x800058DC
    // 0x8023823C: addiu       $a1, $a1, 0x7EC8
    ctx->r5 = ADD32(ctx->r5, 0X7EC8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8023823C: addiu       $a1, $a1, 0x7EC8
    ctx->r5 = ADD32(ctx->r5, 0X7EC8);
    after_8:
L_80238240:
    // 0x80238240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80238244: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80238248: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8023824C: jr          $ra
    // 0x80238250: nop

    return;
    // 0x80238250: nop

;}
RECOMP_FUNC void M10_FUN_80238254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80238254: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80238258: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8023825C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80238260: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80238264: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x80238268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8023826C: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80238270: bnel        $t6, $zero, L_802383E0
    if (ctx->r14 != 0) {
        // 0x80238274: lb          $v0, 0xA2($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XA2);
            goto L_802383E0;
    }
    goto skip_0;
    // 0x80238274: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
    skip_0:
    // 0x80238278: jal         0x80235D48
    // 0x8023827C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80235D48)(rdram, ctx);
        goto after_0;
    // 0x8023827C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80238280: bne         $v0, $zero, L_802383DC
    if (ctx->r2 != 0) {
        // 0x80238284: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_802383DC;
    }
    // 0x80238284: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80238288: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x8023828C: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80238290: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x80238294: bne         $t7, $zero, L_802382B0
    if (ctx->r15 != 0) {
        // 0x80238298: nop
    
            goto L_802382B0;
    }
    // 0x80238298: nop

    // 0x8023829C: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x802382A0: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x802382A4: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x802382A8: beq         $t8, $zero, L_802382E4
    if (ctx->r24 == 0) {
        // 0x802382AC: nop
    
            goto L_802382E4;
    }
    // 0x802382AC: nop

L_802382B0:
    // 0x802382B0: lbu         $t9, -0x1C5C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1C5C);
    // 0x802382B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802382B8: beq         $t9, $at, L_802383A4
    if (ctx->r25 == ctx->r1) {
        // 0x802382BC: nop
    
            goto L_802383A4;
    }
    // 0x802382BC: nop

    // 0x802382C0: jal         0x80020744
    // 0x802382C4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x802382C4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x802382C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x802382CC: sb          $t0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r8;
    // 0x802382D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802382D4: jal         0x80236700
    // 0x802382D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236700)(rdram, ctx);
        goto after_2;
    // 0x802382D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x802382DC: b           L_802383A4
    // 0x802382E0: nop

        goto L_802383A4;
    // 0x802382E0: nop

L_802382E4:
    // 0x802382E4: bne         $t1, $zero, L_802382F4
    if (ctx->r9 != 0) {
        // 0x802382E8: andi        $t2, $a0, 0x8000
        ctx->r10 = ctx->r4 & 0X8000;
            goto L_802382F4;
    }
    // 0x802382E8: andi        $t2, $a0, 0x8000
    ctx->r10 = ctx->r4 & 0X8000;
    // 0x802382EC: beql        $t2, $zero, L_80238378
    if (ctx->r10 == 0) {
        // 0x802382F0: andi        $t0, $a0, 0x8000
        ctx->r8 = ctx->r4 & 0X8000;
            goto L_80238378;
    }
    goto skip_1;
    // 0x802382F0: andi        $t0, $a0, 0x8000
    ctx->r8 = ctx->r4 & 0X8000;
    skip_1:
L_802382F4:
    // 0x802382F4: lb          $t3, 0xA5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA5);
    // 0x802382F8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x802382FC: beql        $at, $zero, L_80238378
    if (ctx->r1 == 0) {
        // 0x80238300: andi        $t0, $a0, 0x8000
        ctx->r8 = ctx->r4 & 0X8000;
            goto L_80238378;
    }
    goto skip_2;
    // 0x80238300: andi        $t0, $a0, 0x8000
    ctx->r8 = ctx->r4 & 0X8000;
    skip_2:
    // 0x80238304: jal         0x80020744
    // 0x80238308: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80238308: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_3:
    // 0x8023830C: lb          $v0, 0xA5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA5);
    // 0x80238310: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80238314: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80238318: sb          $t4, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r12;
    // 0x8023831C: beq         $v0, $zero, L_80238338
    if (ctx->r2 == 0) {
        // 0x80238320: sb          $t5, 0xA1($s0)
        MEM_B(0XA1, ctx->r16) = ctx->r13;
            goto L_80238338;
    }
    // 0x80238320: sb          $t5, 0xA1($s0)
    MEM_B(0XA1, ctx->r16) = ctx->r13;
    // 0x80238324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80238328: beq         $v0, $at, L_8023834C
    if (ctx->r2 == ctx->r1) {
        // 0x8023832C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8023834C;
    }
    // 0x8023832C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238330: b           L_80238358
    // 0x80238334: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
        goto L_80238358;
    // 0x80238334: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
L_80238338:
    // 0x80238338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023833C: jal         0x802365E0
    // 0x80238340: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x802365E0)(rdram, ctx);
        goto after_4;
    // 0x80238340: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80238344: b           L_80238358
    // 0x80238348: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
        goto L_80238358;
    // 0x80238348: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
L_8023834C:
    // 0x8023834C: jal         0x80236640
    // 0x80238350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80236640)(rdram, ctx);
        goto after_5;
    // 0x80238350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80238354: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
L_80238358:
    // 0x80238358: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8023835C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80238360: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80238364: mflo        $t8
    ctx->r24 = lo;
    // 0x80238368: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8023836C: b           L_802383A4
    // 0x80238370: sb          $t9, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r25;
        goto L_802383A4;
    // 0x80238370: sb          $t9, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r25;
    // 0x80238374: andi        $t0, $a0, 0x8000
    ctx->r8 = ctx->r4 & 0X8000;
L_80238378:
    // 0x80238378: beq         $t0, $zero, L_802383A4
    if (ctx->r8 == 0) {
        // 0x8023837C: nop
    
            goto L_802383A4;
    }
    // 0x8023837C: nop

    // 0x80238380: lb          $t1, 0xA5($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA5);
    // 0x80238384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80238388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023838C: bne         $t1, $at, L_802383A4
    if (ctx->r9 != ctx->r1) {
        // 0x80238390: lui         $a1, 0x8024
        ctx->r5 = S32(0X8024 << 16);
            goto L_802383A4;
    }
    // 0x80238390: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80238394: jal         0x800058DC
    // 0x80238398: addiu       $a1, $a1, -0x6374
    ctx->r5 = ADD32(ctx->r5, -0X6374);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80238398: addiu       $a1, $a1, -0x6374
    ctx->r5 = ADD32(ctx->r5, -0X6374);
    after_6:
    // 0x8023839C: b           L_80238474
    // 0x802383A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80238474;
    // 0x802383A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802383A4:
    // 0x802383A4: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x802383A8: lbu         $t2, -0x1C5C($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1C5C);
    // 0x802383AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802383B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802383B4: bne         $t2, $at, L_802383D4
    if (ctx->r10 != ctx->r1) {
        // 0x802383B8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_802383D4;
    }
    // 0x802383B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802383BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802383C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802383C4: jal         0x80234724
    // 0x802383C8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_7;
    // 0x802383C8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_7:
    // 0x802383CC: b           L_802383E0
    // 0x802383D0: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
        goto L_802383E0;
    // 0x802383D0: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_802383D4:
    // 0x802383D4: jal         0x80234724
    // 0x802383D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80234724)(rdram, ctx);
        goto after_8;
    // 0x802383D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_802383DC:
    // 0x802383DC: lb          $v0, 0xA2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA2);
L_802383E0:
    // 0x802383E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802383E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802383E8: bne         $v0, $at, L_8023841C
    if (ctx->r2 != ctx->r1) {
        // 0x802383EC: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8023841C;
    }
    // 0x802383EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x802383F0: jal         0x80235394
    // 0x802383F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_9;
    // 0x802383F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x802383F8: lb          $t3, 0xA2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA2);
    // 0x802383FC: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
    // 0x80238400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238404: bne         $t3, $zero, L_80238470
    if (ctx->r11 != 0) {
        // 0x80238408: lui         $a1, 0x8023
        ctx->r5 = S32(0X8023 << 16);
            goto L_80238470;
    }
    // 0x80238408: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x8023840C: jal         0x800058DC
    // 0x80238410: addiu       $a1, $a1, 0x7EC8
    ctx->r5 = ADD32(ctx->r5, 0X7EC8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x80238410: addiu       $a1, $a1, 0x7EC8
    ctx->r5 = ADD32(ctx->r5, 0X7EC8);
    after_10:
    // 0x80238414: b           L_80238474
    // 0x80238418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80238474;
    // 0x80238418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023841C:
    // 0x8023841C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80238420: bne         $v0, $at, L_80238470
    if (ctx->r2 != ctx->r1) {
        // 0x80238424: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80238470;
    }
    // 0x80238424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80238428: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8023842C: jal         0x80235394
    // 0x80238430: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80235394)(rdram, ctx);
        goto after_11;
    // 0x80238430: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x80238434: lb          $t4, 0xA2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XA2);
    // 0x80238438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023843C: lui         $a1, 0x8023
    ctx->r5 = S32(0X8023 << 16);
    // 0x80238440: bnel        $t4, $zero, L_80238474
    if (ctx->r12 != 0) {
        // 0x80238444: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80238474;
    }
    goto skip_3;
    // 0x80238444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80238448: lb          $t5, 0xA5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XA5);
    // 0x8023844C: addiu       $a1, $a1, 0x7B7C
    ctx->r5 = ADD32(ctx->r5, 0X7B7C);
    // 0x80238450: jal         0x800058DC
    // 0x80238454: sb          $t5, 0xA6($s0)
    MEM_B(0XA6, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x80238454: sb          $t5, 0xA6($s0)
    MEM_B(0XA6, ctx->r16) = ctx->r13;
    after_12:
    // 0x80238458: lb          $t6, 0xA3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XA3);
    // 0x8023845C: bgez        $t6, L_8023846C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80238460: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8023846C;
    }
    // 0x80238460: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80238464: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80238468: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8023846C:
    // 0x8023846C: sb          $t7, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r15;
L_80238470:
    // 0x80238470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80238474:
    // 0x80238474: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80238478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023847C: jr          $ra
    // 0x80238480: nop

    return;
    // 0x80238480: nop

;}
RECOMP_FUNC void M10_FUN_80238484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80238484: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80238488: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8023848C: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80238490: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80238494: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80238498: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8023849C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x802384A0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x802384A4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x802384A8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x802384AC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x802384B0: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x802384B4: lw          $t6, 0xDC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XDC);
    // 0x802384B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x802384BC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x802384C0: bne         $t6, $a2, L_802384D4
    if (ctx->r14 != ctx->r6) {
        // 0x802384C4: lui         $a0, 0xF00
        ctx->r4 = S32(0XF00 << 16);
            goto L_802384D4;
    }
    // 0x802384C4: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x802384C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802384CC: b           L_802384DC
    // 0x802384D0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_802384DC;
    // 0x802384D0: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_802384D4:
    // 0x802384D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802384D8: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_802384DC:
    // 0x802384DC: sw          $v0, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->r2;
    // 0x802384E0: lw          $t7, 0xDC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XDC);
    // 0x802384E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x802384E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x802384EC: bne         $t7, $a2, L_802384FC
    if (ctx->r15 != ctx->r6) {
        // 0x802384F0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_802384FC;
    }
    // 0x802384F0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802384F4: b           L_80238504
    // 0x802384F8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_80238504;
    // 0x802384F8: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_802384FC:
    // 0x802384FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80238500: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_80238504:
    // 0x80238504: sw          $v0, 0x9C($s3)
    MEM_W(0X9C, ctx->r19) = ctx->r2;
    // 0x80238508: lw          $v1, 0x5C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X5C);
    // 0x8023850C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80238510: addiu       $t8, $t8, -0x1AE8
    ctx->r24 = ADD32(ctx->r24, -0X1AE8);
    // 0x80238514: sw          $v1, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->r3;
    // 0x80238518: lwr         $t1, 0x2($t8)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r24, 0X2);
    // 0x8023851C: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x80238520: lw          $t2, 0xDC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XDC);
    // 0x80238524: swr         $t1, 0x2($s6)
    do_swr(rdram, 0X2, ctx->r22, ctx->r9);
    // 0x80238528: lw          $t3, 0xC($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XC);
    // 0x8023852C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80238530: bne         $t2, $t3, L_80238544
    if (ctx->r10 != ctx->r11) {
        // 0x80238534: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_80238544;
    }
    // 0x80238534: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80238538: addiu       $t4, $t4, -0x4374
    ctx->r12 = ADD32(ctx->r12, -0X4374);
    // 0x8023853C: b           L_80238550
    // 0x80238540: sw          $t4, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r12;
        goto L_80238550;
    // 0x80238540: sw          $t4, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r12;
L_80238544:
    // 0x80238544: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80238548: addiu       $t5, $t5, -0x4354
    ctx->r13 = ADD32(ctx->r13, -0X4354);
    // 0x8023854C: sw          $t5, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r13;
L_80238550:
    // 0x80238550: jal         0x80002364
    // 0x80238554: lbu         $a3, 0x1030($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X1030);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x80238554: lbu         $a3, 0x1030($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X1030);
    after_0:
    // 0x80238558: jal         0x80116E80
    // 0x8023855C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x8023855C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80238560: jal         0x80376B2C
    // 0x80238564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80376B2C)(rdram, ctx);
        goto after_2;
    // 0x80238564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80238568: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8023856C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80238570: jal         0x80234450
    // 0x80238574: sb          $t6, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80234450)(rdram, ctx);
        goto after_3;
    // 0x80238574: sb          $t6, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = ctx->r14;
    after_3:
    // 0x80238578: addiu       $s0, $sp, 0x72
    ctx->r16 = ADD32(ctx->r29, 0X72);
    // 0x8023857C: addiu       $t7, $zero, 0x72
    ctx->r15 = ADD32(0, 0X72);
    // 0x80238580: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80238584: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80238588: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8023858C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80238590: addiu       $t3, $zero, 0x220
    ctx->r11 = ADD32(0, 0X220);
    // 0x80238594: addiu       $t4, $zero, 0x15
    ctx->r12 = ADD32(0, 0X15);
    // 0x80238598: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8023859C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x802385A0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x802385A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x802385A8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x802385AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x802385B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x802385B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x802385B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x802385BC: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x802385C0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x802385C4: jal         0x80146208
    // 0x802385C8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x802385C8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x802385CC: addiu       $t5, $zero, 0x72
    ctx->r13 = ADD32(0, 0X72);
    // 0x802385D0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x802385D4: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x802385D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x802385DC: addiu       $t9, $zero, 0x220
    ctx->r25 = ADD32(0, 0X220);
    // 0x802385E0: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x802385E4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x802385E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x802385EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x802385F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x802385F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x802385F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x802385FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238600: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80238604: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80238608: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    // 0x8023860C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80238610: jal         0x80146208
    // 0x80238614: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x80238614: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x80238618: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8023861C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80238620: jal         0x80145310
    // 0x80238624: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_6;
    // 0x80238624: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x80238628: lw          $a0, 0x4($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X4);
    // 0x8023862C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80238630: jal         0x80145310
    // 0x80238634: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_7;
    // 0x80238634: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x80238638: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8023863C: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80238640: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80238644: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    // 0x80238648: lbu         $t3, -0x1C54($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1C54);
    // 0x8023864C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80238650: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80238654: bnel        $at, $zero, L_80238668
    if (ctx->r1 != 0) {
        // 0x80238658: sb          $t5, 0xA4($s3)
        MEM_B(0XA4, ctx->r19) = ctx->r13;
            goto L_80238668;
    }
    goto skip_0;
    // 0x80238658: sb          $t5, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r13;
    skip_0:
    // 0x8023865C: b           L_80238668
    // 0x80238660: sb          $t4, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r12;
        goto L_80238668;
    // 0x80238660: sb          $t4, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r12;
    // 0x80238664: sb          $t5, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r13;
L_80238668:
    // 0x80238668: lb          $s4, 0xA4($s3)
    ctx->r20 = MEM_B(ctx->r19, 0XA4);
    // 0x8023866C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238670: negu        $at, $s4
    ctx->r1 = SUB32(0, ctx->r20);
    // 0x80238674: sll         $s4, $at, 3
    ctx->r20 = S32(ctx->r1 << 3);
    // 0x80238678: addu        $s4, $s4, $at
    ctx->r20 = ADD32(ctx->r20, ctx->r1);
    // 0x8023867C: addiu       $s4, $s4, 0x9
    ctx->r20 = ADD32(ctx->r20, 0X9);
    // 0x80238680: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80238684: jal         0x80006214
    // 0x80238688: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_8;
    // 0x80238688: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    after_8:
    // 0x8023868C: sb          $v0, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r2;
    // 0x80238690: lb          $t6, 0xA4($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XA4);
    // 0x80238694: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80238698: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023869C: blez        $t6, L_802386F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x802386A0: addiu       $s2, $zero, 0x12
        ctx->r18 = ADD32(0, 0X12);
            goto L_802386F4;
    }
    // 0x802386A0: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
L_802386A4:
    // 0x802386A4: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802386A8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x802386AC: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x802386B0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x802386B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x802386B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x802386BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x802386C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x802386C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802386C8: mflo        $t7
    ctx->r15 = lo;
    // 0x802386CC: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x802386D0: jal         0x8023448C
    // 0x802386D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_9;
    // 0x802386D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_9:
    // 0x802386D8: lb          $t2, 0xA4($s3)
    ctx->r10 = MEM_B(ctx->r19, 0XA4);
    // 0x802386DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x802386E0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x802386E4: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x802386E8: bne         $at, $zero, L_802386A4
    if (ctx->r1 != 0) {
        // 0x802386EC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_802386A4;
    }
    // 0x802386EC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x802386F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_802386F4:
    // 0x802386F4: lbu         $t3, 0x71($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X71);
    // 0x802386F8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802386FC: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
    // 0x80238700: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80238704: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x80238708: sw          $t5, 0x86C($at)
    MEM_W(0X86C, ctx->r1) = ctx->r13;
    // 0x8023870C: jal         0x80006214
    // 0x80238710: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x80238710: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80238714: sb          $v0, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r2;
    // 0x80238718: lb          $t6, 0xA4($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XA4);
    // 0x8023871C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80238720: blezl       $t6, L_80238774
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80238724: lbu         $t3, 0x71($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X71);
            goto L_80238774;
    }
    goto skip_1;
    // 0x80238724: lbu         $t3, 0x71($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X71);
    skip_1:
L_80238728:
    // 0x80238728: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023872C: addu        $t7, $s6, $s1
    ctx->r15 = ADD32(ctx->r22, ctx->r17);
    // 0x80238730: lbu         $a2, 0x0($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X0);
    // 0x80238734: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80238738: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8023873C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238740: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80238744: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80238748: mflo        $t8
    ctx->r24 = lo;
    // 0x8023874C: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x80238750: jal         0x802345B0
    // 0x80238754: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_11;
    // 0x80238754: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_11:
    // 0x80238758: lb          $t2, 0xA4($s3)
    ctx->r10 = MEM_B(ctx->r19, 0XA4);
    // 0x8023875C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80238760: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x80238764: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80238768: bne         $at, $zero, L_80238728
    if (ctx->r1 != 0) {
        // 0x8023876C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80238728;
    }
    // 0x8023876C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80238770: lbu         $t3, 0x71($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X71);
L_80238774:
    // 0x80238774: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80238778: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8023877C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80238780: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x80238784: sw          $t5, 0x870($at)
    MEM_W(0X870, ctx->r1) = ctx->r13;
    // 0x80238788: lb          $t6, 0xA4($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XA4);
    // 0x8023878C: sb          $zero, 0xA2($s3)
    MEM_B(0XA2, ctx->r19) = 0;
    // 0x80238790: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80238794: jal         0x80235B40
    // 0x80238798: sb          $t7, 0xA5($s3)
    MEM_B(0XA5, ctx->r19) = ctx->r15;
    LOOKUP_FUNC(0x80235B40)(rdram, ctx);
        goto after_12;
    // 0x80238798: sb          $t7, 0xA5($s3)
    MEM_B(0XA5, ctx->r19) = ctx->r15;
    after_12:
    // 0x8023879C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802387A0: addiu       $a1, $a1, -0x7DAC
    ctx->r5 = ADD32(ctx->r5, -0X7DAC);
    // 0x802387A4: jal         0x800058DC
    // 0x802387A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x802387A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x802387AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x802387B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x802387B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x802387B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x802387BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x802387C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x802387C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x802387C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x802387CC: jr          $ra
    // 0x802387D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x802387D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802387d4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802387d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802387D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x802387D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x802387DC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x802387E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x802387E4: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
    // 0x802387E8: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x802387EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802387F0: addiu       $a1, $sp, 0x4B
    ctx->r5 = ADD32(ctx->r29, 0X4B);
    // 0x802387F4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x802387F8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x802387FC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80238800: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x80238804: bne         $t7, $zero, L_80238844
    if (ctx->r15 != 0) {
        // 0x80238808: addiu       $t8, $zero, 0x7A
        ctx->r24 = ADD32(0, 0X7A);
            goto L_80238844;
    }
    // 0x80238808: addiu       $t8, $zero, 0x7A
    ctx->r24 = ADD32(0, 0X7A);
    // 0x8023880C: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80238810: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80238814: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80238818: addiu       $t2, $zero, 0x220
    ctx->r10 = ADD32(0, 0X220);
    // 0x8023881C: addiu       $t3, $zero, 0x16
    ctx->r11 = ADD32(0, 0X16);
    // 0x80238820: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80238824: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80238828: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8023882C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80238830: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80238834: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80238838: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023883C: jal         0x80146208
    // 0x80238840: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x80238840: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
L_80238844:
    // 0x80238844: lhu         $t4, 0xAC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XAC);
    // 0x80238848: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x8023884C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80238850: slti        $at, $t4, 0x11
    ctx->r1 = SIGNED(ctx->r12) < 0X11 ? 1 : 0;
    // 0x80238854: beq         $at, $zero, L_80238884
    if (ctx->r1 == 0) {
        // 0x80238858: addiu       $a3, $zero, 0xB
        ctx->r7 = ADD32(0, 0XB);
            goto L_80238884;
    }
    // 0x80238858: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x8023885C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80238860: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80238864: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80238868: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8023886C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80238870: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80238874: jal         0x801453CC
    // 0x80238878: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_1;
    // 0x80238878: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x8023887C: b           L_80238918
    // 0x80238880: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80238918;
    // 0x80238880: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80238884:
    // 0x80238884: jal         0x80020744
    // 0x80238888: addiu       $a0, $zero, 0x276
    ctx->r4 = ADD32(0, 0X276);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80238888: addiu       $a0, $zero, 0x276
    ctx->r4 = ADD32(0, 0X276);
    after_2:
    // 0x8023888C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80238890: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80238894: lbu         $t8, 0x1030($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1030);
    // 0x80238898: bnel        $t8, $zero, L_802388AC
    if (ctx->r24 != 0) {
        // 0x8023889C: lw          $a0, 0xDC($v0)
        ctx->r4 = MEM_W(ctx->r2, 0XDC);
            goto L_802388AC;
    }
    goto skip_0;
    // 0x8023889C: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    skip_0:
    // 0x802388A0: b           L_802388AC
    // 0x802388A4: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
        goto L_802388AC;
    // 0x802388A4: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    // 0x802388A8: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
L_802388AC:
    // 0x802388AC: jal         0x802242D0
    // 0x802388B0: nop

    LOOKUP_FUNC(0x802242D0)(rdram, ctx);
        goto after_3;
    // 0x802388B0: nop

    after_3:
    // 0x802388B4: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x802388B8: bne         $t9, $zero, L_802388F8
    if (ctx->r25 != 0) {
        // 0x802388BC: sb          $v0, 0xA8($s0)
        MEM_B(0XA8, ctx->r16) = ctx->r2;
            goto L_802388F8;
    }
    // 0x802388BC: sb          $v0, 0xA8($s0)
    MEM_B(0XA8, ctx->r16) = ctx->r2;
    // 0x802388C0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x802388C4: lw          $t1, 0x38($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X38);
    // 0x802388C8: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x802388CC: bnel        $t2, $zero, L_802388FC
    if (ctx->r10 != 0) {
        // 0x802388D0: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_802388FC;
    }
    goto skip_1;
    // 0x802388D0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x802388D4: jal         0x80236348
    // 0x802388D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_4;
    // 0x802388D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x802388DC: bne         $v0, $zero, L_802388F8
    if (ctx->r2 != 0) {
        // 0x802388E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_802388F8;
    }
    // 0x802388E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802388E4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802388E8: jal         0x800058DC
    // 0x802388EC: addiu       $a1, $a1, -0x6FB8
    ctx->r5 = ADD32(ctx->r5, -0X6FB8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x802388EC: addiu       $a1, $a1, -0x6FB8
    ctx->r5 = ADD32(ctx->r5, -0X6FB8);
    after_5:
    // 0x802388F0: b           L_80238918
    // 0x802388F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80238918;
    // 0x802388F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_802388F8:
    // 0x802388F8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
L_802388FC:
    // 0x802388FC: jal         0x80006088
    // 0x80238900: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_6;
    // 0x80238900: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_6:
    // 0x80238904: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80238908: addiu       $a1, $a1, -0x76D8
    ctx->r5 = ADD32(ctx->r5, -0X76D8);
    // 0x8023890C: jal         0x800058DC
    // 0x80238910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80238910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80238914: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80238918:
    // 0x80238918: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8023891C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80238920: jr          $ra
    // 0x80238924: nop

    return;
    // 0x80238924: nop

;}
RECOMP_FUNC void M10_FUN_80238928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80238928: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8023892C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80238930: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80238934: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80238938: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8023893C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80238940: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80238944: sb          $zero, 0x59($sp)
    MEM_B(0X59, ctx->r29) = 0;
    // 0x80238948: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x8023894C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80238950: addiu       $t6, $t6, -0x4410
    ctx->r14 = ADD32(ctx->r14, -0X4410);
    // 0x80238954: addiu       $t7, $t6, 0x44C
    ctx->r15 = ADD32(ctx->r14, 0X44C);
    // 0x80238958: bne         $v0, $t7, L_80238968
    if (ctx->r2 != ctx->r15) {
        // 0x8023895C: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_80238968;
    }
    // 0x8023895C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80238960: b           L_80238970
    // 0x80238964: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
        goto L_80238970;
    // 0x80238964: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
L_80238968:
    // 0x80238968: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8023896C: sb          $t8, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r24;
L_80238970:
    // 0x80238970: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238974: jal         0x80006214
    // 0x80238978: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x80238978: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_0:
    // 0x8023897C: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x80238980: jal         0x80236348
    // 0x80238984: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_1;
    // 0x80238984: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80238988: beq         $v0, $zero, L_80238A38
    if (ctx->r2 == 0) {
        // 0x8023898C: addiu       $s0, $sp, 0x59
        ctx->r16 = ADD32(ctx->r29, 0X59);
            goto L_80238A38;
    }
    // 0x8023898C: addiu       $s0, $sp, 0x59
    ctx->r16 = ADD32(ctx->r29, 0X59);
    // 0x80238990: addiu       $t9, $zero, 0x7E
    ctx->r25 = ADD32(0, 0X7E);
    // 0x80238994: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80238998: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8023899C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x802389A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x802389A4: addiu       $t4, $zero, 0x209
    ctx->r12 = ADD32(0, 0X209);
    // 0x802389A8: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x802389AC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x802389B0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x802389B4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x802389B8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x802389BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x802389C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x802389C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x802389C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x802389CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x802389D0: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x802389D4: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x802389D8: jal         0x80146208
    // 0x802389DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x802389DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x802389E0: addiu       $t6, $zero, 0x7E
    ctx->r14 = ADD32(0, 0X7E);
    // 0x802389E4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x802389E8: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x802389EC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x802389F0: addiu       $t0, $zero, 0x209
    ctx->r8 = ADD32(0, 0X209);
    // 0x802389F4: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x802389F8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x802389FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80238A00: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80238A04: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80238A08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80238A0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80238A10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238A14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80238A18: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80238A1C: addiu       $a3, $zero, 0xA8
    ctx->r7 = ADD32(0, 0XA8);
    // 0x80238A20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80238A24: jal         0x80146208
    // 0x80238A28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x80238A28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x80238A2C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80238A30: b           L_80238B2C
    // 0x80238A34: sb          $t2, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r10;
        goto L_80238B2C;
    // 0x80238A34: sb          $t2, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r10;
L_80238A38:
    // 0x80238A38: addiu       $s0, $sp, 0x59
    ctx->r16 = ADD32(ctx->r29, 0X59);
    // 0x80238A3C: addiu       $t3, $zero, 0x90
    ctx->r11 = ADD32(0, 0X90);
    // 0x80238A40: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80238A44: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80238A48: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80238A4C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80238A50: addiu       $t8, $zero, 0x209
    ctx->r24 = ADD32(0, 0X209);
    // 0x80238A54: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80238A58: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80238A5C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80238A60: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80238A64: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80238A68: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80238A6C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80238A70: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80238A74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80238A78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238A7C: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x80238A80: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80238A84: jal         0x80146208
    // 0x80238A88: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x80238A88: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x80238A8C: addiu       $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
    // 0x80238A90: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80238A94: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80238A98: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80238A9C: addiu       $t4, $zero, 0x209
    ctx->r12 = ADD32(0, 0X209);
    // 0x80238AA0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80238AA4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80238AA8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80238AAC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80238AB0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80238AB4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80238AB8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80238ABC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238AC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80238AC4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80238AC8: addiu       $a3, $zero, 0xA8
    ctx->r7 = ADD32(0, 0XA8);
    // 0x80238ACC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80238AD0: jal         0x80146208
    // 0x80238AD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x80238AD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x80238AD8: addiu       $t6, $zero, 0x7E
    ctx->r14 = ADD32(0, 0X7E);
    // 0x80238ADC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80238AE0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80238AE4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80238AE8: addiu       $t0, $zero, 0x209
    ctx->r8 = ADD32(0, 0X209);
    // 0x80238AEC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80238AF0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80238AF4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80238AF8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80238AFC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80238B00: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80238B04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80238B08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238B0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80238B10: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80238B14: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    // 0x80238B18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80238B1C: jal         0x80146208
    // 0x80238B20: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x80238B20: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x80238B24: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80238B28: sb          $t2, 0xA4($s3)
    MEM_B(0XA4, ctx->r19) = ctx->r10;
L_80238B2C:
    // 0x80238B2C: lb          $v0, 0xA4($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XA4);
    // 0x80238B30: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x80238B34: addiu       $s2, $s2, 0x7E0
    ctx->r18 = ADD32(ctx->r18, 0X7E0);
    // 0x80238B38: blez        $v0, L_80238B90
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80238B3C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80238B90;
    }
    // 0x80238B3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80238B40: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80238B44:
    // 0x80238B44: bnel        $s0, $s1, L_80238B6C
    if (ctx->r16 != ctx->r17) {
        // 0x80238B48: addu        $t5, $s2, $s0
        ctx->r13 = ADD32(ctx->r18, ctx->r16);
            goto L_80238B6C;
    }
    goto skip_0;
    // 0x80238B48: addu        $t5, $s2, $s0
    ctx->r13 = ADD32(ctx->r18, ctx->r16);
    skip_0:
    // 0x80238B4C: jal         0x80226980
    // 0x80238B50: lbu         $a0, 0x4F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4F);
    LOOKUP_FUNC(0x80226980)(rdram, ctx);
        goto after_7;
    // 0x80238B50: lbu         $a0, 0x4F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4F);
    after_7:
    // 0x80238B54: beq         $v0, $zero, L_80238B68
    if (ctx->r2 == 0) {
        // 0x80238B58: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80238B68;
    }
    // 0x80238B58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80238B5C: addu        $t4, $s2, $s0
    ctx->r12 = ADD32(ctx->r18, ctx->r16);
    // 0x80238B60: b           L_80238B70
    // 0x80238B64: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_80238B70;
    // 0x80238B64: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
L_80238B68:
    // 0x80238B68: addu        $t5, $s2, $s0
    ctx->r13 = ADD32(ctx->r18, ctx->r16);
L_80238B6C:
    // 0x80238B6C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
L_80238B70:
    // 0x80238B70: lb          $v0, 0xA4($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XA4);
    // 0x80238B74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80238B78: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80238B7C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80238B80: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80238B84: bne         $at, $zero, L_80238B44
    if (ctx->r1 != 0) {
        // 0x80238B88: nop
    
            goto L_80238B44;
    }
    // 0x80238B88: nop

    // 0x80238B8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80238B90:
    // 0x80238B90: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x80238B94: blez        $v0, L_80238C0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80238B98: addiu       $s2, $s2, 0x7E0
        ctx->r18 = ADD32(ctx->r18, 0X7E0);
            goto L_80238C0C;
    }
    // 0x80238B98: addiu       $s2, $s2, 0x7E0
    ctx->r18 = ADD32(ctx->r18, 0X7E0);
    // 0x80238B9C: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x80238BA0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80238BA4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80238BA8: addu        $s1, $t6, $t8
    ctx->r17 = ADD32(ctx->r14, ctx->r24);
    // 0x80238BAC: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
L_80238BB0:
    // 0x80238BB0: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80238BB4: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80238BB8: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x80238BBC: beq         $t0, $zero, L_80238BE4
    if (ctx->r8 == 0) {
        // 0x80238BC0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80238BE4;
    }
    // 0x80238BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80238BC4: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80238BC8: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80238BCC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80238BD0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80238BD4: jal         0x80145310
    // 0x80238BD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_8;
    // 0x80238BD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x80238BDC: b           L_80238BF4
    // 0x80238BE0: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
        goto L_80238BF4;
    // 0x80238BE0: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
L_80238BE4:
    // 0x80238BE4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80238BE8: jal         0x80145310
    // 0x80238BEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_9;
    // 0x80238BEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x80238BF0: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
L_80238BF4:
    // 0x80238BF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80238BF8: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80238BFC: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80238C00: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80238C04: bnel        $at, $zero, L_80238BB0
    if (ctx->r1 != 0) {
        // 0x80238C08: addu        $t9, $s2, $s0
        ctx->r25 = ADD32(ctx->r18, ctx->r16);
            goto L_80238BB0;
    }
    goto skip_1;
    // 0x80238C08: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    skip_1:
L_80238C0C:
    // 0x80238C0C: jal         0x80006214
    // 0x80238C10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x80238C10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80238C14: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x80238C18: jal         0x80236348
    // 0x80238C1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_11;
    // 0x80238C1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80238C20: beq         $v0, $zero, L_80238C80
    if (ctx->r2 == 0) {
        // 0x80238C24: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80238C80;
    }
    // 0x80238C24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238C28: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80238C2C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80238C30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80238C34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80238C38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238C3C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80238C44: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    // 0x80238C48: jal         0x8023448C
    // 0x80238C4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_12;
    // 0x80238C4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80238C50: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80238C54: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80238C58: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80238C5C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80238C60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238C64: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80238C6C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80238C70: jal         0x8023448C
    // 0x80238C74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_13;
    // 0x80238C74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80238C78: b           L_80238D04
    // 0x80238C7C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
        goto L_80238D04;
    // 0x80238C7C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_80238C80:
    // 0x80238C80: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80238C84: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80238C88: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80238C8C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80238C90: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80238C94: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80238C98: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238C9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80238CA0: jal         0x8023448C
    // 0x80238CA4: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_14;
    // 0x80238CA4: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    after_14:
    // 0x80238CA8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80238CAC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80238CB0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80238CB4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80238CB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80238CBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80238CC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238CC4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238CC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80238CCC: jal         0x8023448C
    // 0x80238CD0: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_15;
    // 0x80238CD0: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    after_15:
    // 0x80238CD4: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x80238CD8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80238CDC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80238CE0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80238CE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80238CE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80238CEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238CF0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238CF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80238CF8: jal         0x8023448C
    // 0x80238CFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_16;
    // 0x80238CFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x80238D00: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_80238D04:
    // 0x80238D04: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    // 0x80238D08: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x80238D0C: lw          $t0, 0x38($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X38);
    // 0x80238D10: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80238D14: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80238D18: beq         $t1, $zero, L_80238D30
    if (ctx->r9 == 0) {
        // 0x80238D1C: nop
    
            goto L_80238D30;
    }
    // 0x80238D1C: nop

    // 0x80238D20: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x80238D24: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
    // 0x80238D28: b           L_80238D30
    // 0x80238D2C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
        goto L_80238D30;
    // 0x80238D2C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80238D30:
    // 0x80238D30: jal         0x80236348
    // 0x80238D34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_17;
    // 0x80238D34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x80238D38: beq         $v0, $zero, L_80238D88
    if (ctx->r2 == 0) {
        // 0x80238D3C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80238D88;
    }
    // 0x80238D3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238D40: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80238D44: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80238D48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238D4C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238D50: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80238D54: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    // 0x80238D58: jal         0x802345B0
    // 0x80238D5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_18;
    // 0x80238D5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80238D60: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80238D64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80238D68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238D6C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238D70: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80238D74: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80238D78: jal         0x802345B0
    // 0x80238D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_19;
    // 0x80238D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
    // 0x80238D80: b           L_80238DF4
    // 0x80238D84: lh          $t0, 0x5A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5A);
        goto L_80238DF4;
    // 0x80238D84: lh          $t0, 0x5A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5A);
L_80238D88:
    // 0x80238D88: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80238D8C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80238D90: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80238D94: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80238D98: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238D9C: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x80238DA0: jal         0x802345B0
    // 0x80238DA4: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_20;
    // 0x80238DA4: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    after_20:
    // 0x80238DA8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80238DAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80238DB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80238DB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80238DB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238DBC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238DC0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x80238DC4: jal         0x802345B0
    // 0x80238DC8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_21;
    // 0x80238DC8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    after_21:
    // 0x80238DCC: addiu       $t8, $zero, -0x14
    ctx->r24 = ADD32(0, -0X14);
    // 0x80238DD0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80238DD4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80238DD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80238DDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80238DE0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80238DE4: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x80238DE8: jal         0x802345B0
    // 0x80238DEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_22;
    // 0x80238DEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
    // 0x80238DF0: lh          $t0, 0x5A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5A);
L_80238DF4:
    // 0x80238DF4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80238DF8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80238DFC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80238E00: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80238E04: sw          $t3, 0x86C($at)
    MEM_W(0X86C, ctx->r1) = ctx->r11;
    // 0x80238E08: lb          $t4, 0xA4($s3)
    ctx->r12 = MEM_B(ctx->r19, 0XA4);
    // 0x80238E0C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80238E10: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80238E14: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80238E18: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80238E1C: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x80238E20: sw          $t6, 0x870($at)
    MEM_W(0X870, ctx->r1) = ctx->r14;
    // 0x80238E24: sb          $zero, 0xA2($s3)
    MEM_B(0XA2, ctx->r19) = 0;
    // 0x80238E28: sb          $t8, 0xA5($s3)
    MEM_B(0XA5, ctx->r19) = ctx->r24;
    // 0x80238E2C: jal         0x80235C1C
    // 0x80238E30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80235C1C)(rdram, ctx);
        goto after_23;
    // 0x80238E30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_23:
    // 0x80238E34: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80238E38: addiu       $a1, $a1, -0x71A0
    ctx->r5 = ADD32(ctx->r5, -0X71A0);
    // 0x80238E3C: jal         0x800058DC
    // 0x80238E40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_24;
    // 0x80238E40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_24:
    // 0x80238E44: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80238E48: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80238E4C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80238E50: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80238E54: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80238E58: jr          $ra
    // 0x80238E5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80238E5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80238e60(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80238e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80238E60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80238E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80238E68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80238E6C: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x80238E70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80238E74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80238E78: lw          $a3, 0x94($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X94);
    // 0x80238E7C: lb          $v1, 0xA5($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XA5);
    // 0x80238E80: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80238E84: sll         $t0, $v1, 24
    ctx->r8 = S32(ctx->r3 << 24);
    // 0x80238E88: sra         $t0, $t0, 24
    ctx->r8 = S32(SIGNED(ctx->r8) >> 24);
    // 0x80238E8C: slti        $at, $a1, 0x29
    ctx->r1 = SIGNED(ctx->r5) < 0X29 ? 1 : 0;
    // 0x80238E90: bnel        $at, $zero, L_80238ED0
    if (ctx->r1 != 0) {
        // 0x80238E94: lh          $v0, 0x6($a3)
        ctx->r2 = MEM_H(ctx->r7, 0X6);
            goto L_80238ED0;
    }
    goto skip_0;
    // 0x80238E94: lh          $v0, 0x6($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X6);
    skip_0:
    // 0x80238E98: lb          $t7, 0xA4($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XA4);
    // 0x80238E9C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80238EA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80238EA4: bne         $t7, $at, L_80238ECC
    if (ctx->r15 != ctx->r1) {
        // 0x80238EA8: addiu       $a0, $a0, 0x7E0
        ctx->r4 = ADD32(ctx->r4, 0X7E0);
            goto L_80238ECC;
    }
    // 0x80238EA8: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x80238EAC: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x80238EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80238EB4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80238EB8: bnel        $t8, $zero, L_80238ED0
    if (ctx->r24 != 0) {
        // 0x80238EBC: lh          $v0, 0x6($a3)
        ctx->r2 = MEM_H(ctx->r7, 0X6);
            goto L_80238ED0;
    }
    goto skip_1;
    // 0x80238EBC: lh          $v0, 0x6($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X6);
    skip_1:
    // 0x80238EC0: sb          $v0, 0xA2($a2)
    MEM_B(0XA2, ctx->r6) = ctx->r2;
    // 0x80238EC4: b           L_80238F40
    // 0x80238EC8: sb          $t9, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r25;
        goto L_80238F40;
    // 0x80238EC8: sb          $t9, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r25;
L_80238ECC:
    // 0x80238ECC: lh          $v0, 0x6($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X6);
L_80238ED0:
    // 0x80238ED0: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80238ED4: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x80238ED8: slti        $at, $v0, -0x28
    ctx->r1 = SIGNED(ctx->r2) < -0X28 ? 1 : 0;
    // 0x80238EDC: beql        $at, $zero, L_80238F04
    if (ctx->r1 == 0) {
        // 0x80238EE0: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_80238F04;
    }
    goto skip_2;
    // 0x80238EE0: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    skip_2:
    // 0x80238EE4: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80238EE8: bnel        $t1, $zero, L_80238F04
    if (ctx->r9 != 0) {
        // 0x80238EEC: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_80238F04;
    }
    goto skip_3;
    // 0x80238EEC: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    skip_3:
    // 0x80238EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80238EF4: sb          $v0, 0xA2($a2)
    MEM_B(0XA2, ctx->r6) = ctx->r2;
    // 0x80238EF8: b           L_80238F40
    // 0x80238EFC: sb          $zero, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = 0;
        goto L_80238F40;
    // 0x80238EFC: sb          $zero, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = 0;
    // 0x80238F00: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
L_80238F04:
    // 0x80238F04: beq         $at, $zero, L_80238F28
    if (ctx->r1 == 0) {
        // 0x80238F08: slti        $at, $a1, -0x28
        ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
            goto L_80238F28;
    }
    // 0x80238F08: slti        $at, $a1, -0x28
    ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
    // 0x80238F0C: beq         $at, $zero, L_80238F40
    if (ctx->r1 == 0) {
        // 0x80238F10: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80238F40;
    }
    // 0x80238F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80238F14: beql        $v0, $v1, L_80238F2C
    if (ctx->r2 == ctx->r3) {
        // 0x80238F18: lbu         $t3, 0x1($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X1);
            goto L_80238F2C;
    }
    goto skip_4;
    // 0x80238F18: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    skip_4:
    // 0x80238F1C: lb          $t2, 0xA2($a2)
    ctx->r10 = MEM_B(ctx->r6, 0XA2);
    // 0x80238F20: bnel        $t2, $zero, L_80238F44
    if (ctx->r10 != 0) {
        // 0x80238F24: lb          $t4, 0xA2($a2)
        ctx->r12 = MEM_B(ctx->r6, 0XA2);
            goto L_80238F44;
    }
    goto skip_5;
    // 0x80238F24: lb          $t4, 0xA2($a2)
    ctx->r12 = MEM_B(ctx->r6, 0XA2);
    skip_5:
L_80238F28:
    // 0x80238F28: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
L_80238F2C:
    // 0x80238F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80238F30: bnel        $t3, $zero, L_80238F44
    if (ctx->r11 != 0) {
        // 0x80238F34: lb          $t4, 0xA2($a2)
        ctx->r12 = MEM_B(ctx->r6, 0XA2);
            goto L_80238F44;
    }
    goto skip_6;
    // 0x80238F34: lb          $t4, 0xA2($a2)
    ctx->r12 = MEM_B(ctx->r6, 0XA2);
    skip_6:
    // 0x80238F38: sb          $v0, 0xA2($a2)
    MEM_B(0XA2, ctx->r6) = ctx->r2;
    // 0x80238F3C: sb          $v0, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r2;
L_80238F40:
    // 0x80238F40: lb          $t4, 0xA2($a2)
    ctx->r12 = MEM_B(ctx->r6, 0XA2);
L_80238F44:
    // 0x80238F44: beql        $t4, $zero, L_80238F8C
    if (ctx->r12 == 0) {
        // 0x80238F48: lhu         $t7, 0x4($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X4);
            goto L_80238F8C;
    }
    goto skip_7;
    // 0x80238F48: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    skip_7:
    // 0x80238F4C: lb          $t5, 0xA5($a2)
    ctx->r13 = MEM_B(ctx->r6, 0XA5);
    // 0x80238F50: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80238F54: beql        $t5, $t0, L_80238F74
    if (ctx->r13 == ctx->r8) {
        // 0x80238F58: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80238F74;
    }
    goto skip_8;
    // 0x80238F58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_8:
    // 0x80238F5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80238F60: jal         0x80020744
    // 0x80238F64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80238F64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80238F68: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80238F6C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80238F70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80238F74:
    // 0x80238F74: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80238F78: jal         0x80235C1C
    // 0x80238F7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80235C1C)(rdram, ctx);
        goto after_1;
    // 0x80238F7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80238F80: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80238F84: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80238F88: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
L_80238F8C:
    // 0x80238F8C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80238F90: beql        $t8, $zero, L_8023903C
    if (ctx->r24 == 0) {
        // 0x80238F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023903C;
    }
    goto skip_9;
    // 0x80238F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80238F98: lb          $t9, 0xA2($a2)
    ctx->r25 = MEM_B(ctx->r6, 0XA2);
    // 0x80238F9C: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    // 0x80238FA0: beql        $t9, $zero, L_8023903C
    if (ctx->r25 == 0) {
        // 0x80238FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8023903C;
    }
    goto skip_10;
    // 0x80238FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80238FA8: jal         0x80020744
    // 0x80238FAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80238FAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80238FB0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80238FB4: lb          $t1, 0xA5($a2)
    ctx->r9 = MEM_B(ctx->r6, 0XA5);
    // 0x80238FB8: sh          $zero, 0xAC($a2)
    MEM_H(0XAC, ctx->r6) = 0;
    // 0x80238FBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80238FC0: bnel        $t1, $zero, L_80238FF4
    if (ctx->r9 != 0) {
        // 0x80238FC4: lb          $t2, 0xA5($a2)
        ctx->r10 = MEM_B(ctx->r6, 0XA5);
            goto L_80238FF4;
    }
    goto skip_11;
    // 0x80238FC4: lb          $t2, 0xA5($a2)
    ctx->r10 = MEM_B(ctx->r6, 0XA5);
    skip_11:
    // 0x80238FC8: jal         0x80236348
    // 0x80238FCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_3;
    // 0x80238FCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x80238FD0: beq         $v0, $zero, L_80238FF0
    if (ctx->r2 == 0) {
        // 0x80238FD4: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80238FF0;
    }
    // 0x80238FD4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80238FD8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80238FDC: addiu       $a1, $a1, -0x6C08
    ctx->r5 = ADD32(ctx->r5, -0X6C08);
    // 0x80238FE0: jal         0x800058DC
    // 0x80238FE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80238FE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80238FE8: b           L_8023903C
    // 0x80238FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023903C;
    // 0x80238FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80238FF0:
    // 0x80238FF0: lb          $t2, 0xA5($a2)
    ctx->r10 = MEM_B(ctx->r6, 0XA5);
L_80238FF4:
    // 0x80238FF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80238FF8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80238FFC: bne         $t2, $at, L_8023902C
    if (ctx->r10 != ctx->r1) {
        // 0x80239000: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8023902C;
    }
    // 0x80239000: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80239004: lw          $t4, 0x38($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X38);
    // 0x80239008: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023900C: addiu       $a1, $a1, -0x6FB8
    ctx->r5 = ADD32(ctx->r5, -0X6FB8);
    // 0x80239010: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80239014: bne         $t5, $zero, L_8023902C
    if (ctx->r13 != 0) {
        // 0x80239018: nop
    
            goto L_8023902C;
    }
    // 0x80239018: nop

    // 0x8023901C: jal         0x800058DC
    // 0x80239020: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80239020: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80239024: b           L_8023903C
    // 0x80239028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8023903C;
    // 0x80239028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023902C:
    // 0x8023902C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239030: jal         0x800058DC
    // 0x80239034: addiu       $a1, $a1, -0x65A4
    ctx->r5 = ADD32(ctx->r5, -0X65A4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80239034: addiu       $a1, $a1, -0x65A4
    ctx->r5 = ADD32(ctx->r5, -0X65A4);
    after_6:
    // 0x80239038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8023903C:
    // 0x8023903C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80239040: jr          $ra
    // 0x80239044: nop

    return;
    // 0x80239044: nop

;}
RECOMP_FUNC void M10_FUN_80239048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239048: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8023904C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80239050: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80239054: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80239058: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8023905C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80239060: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80239064: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80239068: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8023906C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80239070: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80239074: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80239078: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8023907C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80239080: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80239084: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80239088: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8023908C: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x80239090: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80239094: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80239098: addiu       $t6, $sp, 0x74
    ctx->r14 = ADD32(ctx->r29, 0X74);
    // 0x8023909C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x802390A0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x802390A4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x802390A8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x802390AC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x802390B0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x802390B4: jal         0x80147218
    // 0x802390B8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_0;
    // 0x802390B8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x802390BC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x802390C0: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x802390C4: lbu         $a3, 0x1030($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1030);
    // 0x802390C8: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x802390CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x802390D0: xori        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 ^ 0X1;
    // 0x802390D4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x802390D8: jal         0x80002364
    // 0x802390DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x802390DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x802390E0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802390E4: lwc1        $f26, 0x5A8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5A8);
    // 0x802390E8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802390EC: lwc1        $f24, 0x5AC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5AC);
    // 0x802390F0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802390F4: lwc1        $f22, 0x5B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5B0);
    // 0x802390F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802390FC: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x80239100: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x80239104: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x80239108: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8023910C: addiu       $s5, $s5, -0x1B98
    ctx->r21 = ADD32(ctx->r21, -0X1B98);
    // 0x80239110: addiu       $s6, $s6, -0x1B30
    ctx->r22 = ADD32(ctx->r22, -0X1B30);
    // 0x80239114: addiu       $fp, $fp, -0x1BF8
    ctx->r30 = ADD32(ctx->r30, -0X1BF8);
    // 0x80239118: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8023911C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80239120: lui         $s3, 0x4000
    ctx->r19 = S32(0X4000 << 16);
L_80239124:
    // 0x80239124: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80239128: jal         0x80005E44
    // 0x8023912C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x8023912C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x80239130: jal         0x80006214
    // 0x80239134: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80239134: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80239138: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8023913C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80239140: addiu       $a2, $zero, 0x220
    ctx->r6 = ADD32(0, 0X220);
    // 0x80239144: jal         0x8012C89C
    // 0x80239148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x80239148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8023914C: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x80239150: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80239154: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x80239158: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8023915C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80239160: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x80239164: ori         $t4, $t3, 0x300
    ctx->r12 = ctx->r11 | 0X300;
    // 0x80239168: jal         0x801302CC
    // 0x8023916C: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_5;
    // 0x8023916C: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    after_5:
    // 0x80239170: beq         $v0, $zero, L_8023919C
    if (ctx->r2 == 0) {
        // 0x80239174: addiu       $a1, $zero, 0xD
        ctx->r5 = ADD32(0, 0XD);
            goto L_8023919C;
    }
    // 0x80239174: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80239178: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8023917C: or          $t5, $s5, $s3
    ctx->r13 = ctx->r21 | ctx->r19;
    // 0x80239180: or          $t8, $s6, $s3
    ctx->r24 = ctx->r22 | ctx->r19;
    // 0x80239184: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80239188: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x8023918C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80239190: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80239194: b           L_802391AC
    // 0x80239198: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
        goto L_802391AC;
    // 0x80239198: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
L_8023919C:
    // 0x8023919C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802391A0: or          $t1, $fp, $s3
    ctx->r9 = ctx->r30 | ctx->r19;
    // 0x802391A4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x802391A8: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
L_802391AC:
    // 0x802391AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x802391B0: jal         0x80145310
    // 0x802391B4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_6;
    // 0x802391B4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_6:
    // 0x802391B8: lbu         $t4, 0x1030($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1030);
    // 0x802391BC: bnel        $s7, $t4, L_80239238
    if (ctx->r23 != ctx->r12) {
        // 0x802391C0: lw          $t4, 0x448($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X448);
            goto L_80239238;
    }
    goto skip_0;
    // 0x802391C0: lw          $t4, 0x448($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X448);
    skip_0:
    // 0x802391C4: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x802391C8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802391CC: lw          $t5, 0x2C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X2C);
    // 0x802391D0: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x802391D4: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x802391D8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x802391DC: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x802391E0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x802391E4: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x802391E8: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x802391EC: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x802391F0: sll         $t0, $s2, 10
    ctx->r8 = S32(ctx->r18 << 10);
    // 0x802391F4: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x802391F8: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x802391FC: lw          $t3, 0xE0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XE0);
    // 0x80239200: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80239204: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80239208: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x8023920C: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80239210: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    // 0x80239214: lw          $t7, 0xE0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XE0);
    // 0x80239218: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8023921C: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x80239220: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80239224: lh          $t8, 0x12($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X12);
    // 0x80239228: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x8023922C: b           L_802392C0
    // 0x80239230: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
        goto L_802392C0;
    // 0x80239230: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
    // 0x80239234: lw          $t4, 0x448($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X448);
L_80239238:
    // 0x80239238: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8023923C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80239240: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80239244: lw          $t5, 0x24($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X24);
    // 0x80239248: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x8023924C: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80239250: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x80239254: lw          $t0, 0x448($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X448);
    // 0x80239258: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8023925C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80239260: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80239264: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80239268: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8023926C: lwc1        $f18, 0x8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80239270: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80239274: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80239278: lw          $t5, 0x448($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X448);
    // 0x8023927C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80239280: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80239284: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80239288: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8023928C: sll         $t7, $s2, 10
    ctx->r15 = S32(ctx->r18 << 10);
    // 0x80239290: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x80239294: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80239298: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x8023929C: lw          $t2, 0x448($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X448);
    // 0x802392A0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802392A4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x802392A8: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x802392AC: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x802392B0: lw          $t6, 0x2C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X2C);
    // 0x802392B4: lh          $t5, 0x12($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X12);
    // 0x802392B8: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x802392BC: sh          $t9, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r25;
L_802392C0:
    // 0x802392C0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x802392C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x802392C8: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x802392CC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802392D0: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x802392D4: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x802392D8: swc1        $f22, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f22.u32l;
    // 0x802392DC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x802392E0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802392E4: swc1        $f24, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f24.u32l;
    // 0x802392E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802392EC: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x802392F0: swc1        $f26, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f26.u32l;
    // 0x802392F4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802392F8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x802392FC: sh          $zero, 0x10($t8)
    MEM_H(0X10, ctx->r24) = 0;
    // 0x80239300: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80239304: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80239308: bne         $at, $zero, L_80239124
    if (ctx->r1 != 0) {
        // 0x8023930C: sh          $zero, 0x14($t0)
        MEM_H(0X14, ctx->r8) = 0;
            goto L_80239124;
    }
    // 0x8023930C: sh          $zero, 0x14($t0)
    MEM_H(0X14, ctx->r8) = 0;
    // 0x80239310: addiu       $t1, $zero, -0x14
    ctx->r9 = ADD32(0, -0X14);
    // 0x80239314: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80239318: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8023931C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80239320: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80239324: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80239328: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8023932C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80239330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80239334: jal         0x8023448C
    // 0x80239338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_7;
    // 0x80239338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8023933C: addiu       $t4, $zero, -0x14
    ctx->r12 = ADD32(0, -0X14);
    // 0x80239340: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80239344: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80239348: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8023934C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80239350: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80239354: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80239358: jal         0x802345B0
    // 0x8023935C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_8;
    // 0x8023935C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80239360: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80239364: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80239368: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023936C: addu        $s0, $t5, $t7
    ctx->r16 = ADD32(ctx->r13, ctx->r15);
    // 0x80239370: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80239374: addiu       $v1, $v1, 0x874
    ctx->r3 = ADD32(ctx->r3, 0X874);
    // 0x80239378: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023937C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80239380: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80239384: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80239388: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023938C: sw          $t9, 0x878($at)
    MEM_W(0X878, ctx->r1) = ctx->r25;
    // 0x80239390: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80239394: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80239398: addiu       $a1, $a1, -0x6858
    ctx->r5 = ADD32(ctx->r5, -0X6858);
    // 0x8023939C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x802393A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802393A4: sw          $t1, 0x87C($at)
    MEM_W(0X87C, ctx->r1) = ctx->r9;
    // 0x802393A8: sh          $zero, 0xAC($s4)
    MEM_H(0XAC, ctx->r20) = 0;
    // 0x802393AC: sb          $t2, 0xA3($s4)
    MEM_B(0XA3, ctx->r20) = ctx->r10;
    // 0x802393B0: jal         0x800058DC
    // 0x802393B4: sb          $zero, 0xA5($s4)
    MEM_B(0XA5, ctx->r20) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x802393B4: sb          $zero, 0xA5($s4)
    MEM_B(0XA5, ctx->r20) = 0;
    after_9:
    // 0x802393B8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x802393BC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x802393C0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x802393C4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x802393C8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x802393CC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x802393D0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x802393D4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x802393D8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x802393DC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x802393E0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x802393E4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x802393E8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x802393EC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x802393F0: jr          $ra
    // 0x802393F4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x802393F4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802393f8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802393f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802393F8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x802393FC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80239400: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80239404: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80239408: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8023940C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80239410: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80239414: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80239418: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8023941C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80239420: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80239424: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80239428: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8023942C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80239430: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80239434: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80239438: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8023943C: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x80239440: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80239444: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80239448: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x8023944C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80239450: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80239454: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80239458: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8023945C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80239460: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80239464: jal         0x80147218
    // 0x80239468: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_0;
    // 0x80239468: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x8023946C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80239470: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80239474: lbu         $a3, 0x1030($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1030);
    // 0x80239478: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x8023947C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80239480: xori        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 ^ 0X1;
    // 0x80239484: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80239488: jal         0x80002364
    // 0x8023948C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x8023948C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80239490: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80239494: lwc1        $f26, 0x5B4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5B4);
    // 0x80239498: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023949C: lwc1        $f24, 0x5B8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5B8);
    // 0x802394A0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802394A4: lwc1        $f22, 0x5BC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5BC);
    // 0x802394A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x802394AC: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x802394B0: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x802394B4: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x802394B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x802394BC: addiu       $s5, $s5, -0x1B98
    ctx->r21 = ADD32(ctx->r21, -0X1B98);
    // 0x802394C0: addiu       $s6, $s6, -0x1B30
    ctx->r22 = ADD32(ctx->r22, -0X1B30);
    // 0x802394C4: addiu       $fp, $fp, -0x1BF8
    ctx->r30 = ADD32(ctx->r30, -0X1BF8);
    // 0x802394C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x802394CC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x802394D0: lui         $s3, 0x4000
    ctx->r19 = S32(0X4000 << 16);
L_802394D4:
    // 0x802394D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802394D8: jal         0x80005E44
    // 0x802394DC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x802394DC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x802394E0: jal         0x80006214
    // 0x802394E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x802394E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x802394E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802394EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x802394F0: addiu       $a2, $zero, 0x220
    ctx->r6 = ADD32(0, 0X220);
    // 0x802394F4: jal         0x8012C89C
    // 0x802394F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x802394F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x802394FC: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x80239500: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80239504: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x80239508: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8023950C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80239510: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x80239514: ori         $t4, $t3, 0x300
    ctx->r12 = ctx->r11 | 0X300;
    // 0x80239518: jal         0x801302CC
    // 0x8023951C: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_5;
    // 0x8023951C: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    after_5:
    // 0x80239520: beq         $v0, $zero, L_8023954C
    if (ctx->r2 == 0) {
        // 0x80239524: addiu       $a1, $zero, 0xD
        ctx->r5 = ADD32(0, 0XD);
            goto L_8023954C;
    }
    // 0x80239524: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80239528: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8023952C: or          $t5, $s5, $s3
    ctx->r13 = ctx->r21 | ctx->r19;
    // 0x80239530: or          $t8, $s6, $s3
    ctx->r24 = ctx->r22 | ctx->r19;
    // 0x80239534: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80239538: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x8023953C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80239540: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80239544: b           L_8023955C
    // 0x80239548: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
        goto L_8023955C;
    // 0x80239548: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
L_8023954C:
    // 0x8023954C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80239550: or          $t1, $fp, $s3
    ctx->r9 = ctx->r30 | ctx->r19;
    // 0x80239554: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80239558: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
L_8023955C:
    // 0x8023955C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80239560: jal         0x80145310
    // 0x80239564: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_6;
    // 0x80239564: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_6:
    // 0x80239568: lbu         $t4, 0x1030($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1030);
    // 0x8023956C: bnel        $s7, $t4, L_802395EC
    if (ctx->r23 != ctx->r12) {
        // 0x80239570: lw          $t6, 0x448($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X448);
            goto L_802395EC;
    }
    goto skip_0;
    // 0x80239570: lw          $t6, 0x448($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X448);
    skip_0:
    // 0x80239574: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x80239578: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8023957C: lw          $t5, 0x2C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X2C);
    // 0x80239580: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80239584: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80239588: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x8023958C: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x80239590: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80239594: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x80239598: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x8023959C: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x802395A0: sll         $t0, $s2, 12
    ctx->r8 = S32(ctx->r18 << 12);
    // 0x802395A4: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x802395A8: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x802395AC: lw          $t3, 0xE0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XE0);
    // 0x802395B0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x802395B4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x802395B8: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x802395BC: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x802395C0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    // 0x802395C4: lw          $t7, 0xE0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XE0);
    // 0x802395C8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x802395CC: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x802395D0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802395D4: lh          $t8, 0x12($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X12);
    // 0x802395D8: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x802395DC: addiu       $t1, $t2, -0x800
    ctx->r9 = ADD32(ctx->r10, -0X800);
    // 0x802395E0: b           L_80239678
    // 0x802395E4: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
        goto L_80239678;
    // 0x802395E4: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
    // 0x802395E8: lw          $t6, 0x448($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X448);
L_802395EC:
    // 0x802395EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802395F0: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x802395F4: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x802395F8: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x802395FC: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x80239600: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80239604: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x80239608: lw          $t2, 0x448($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X448);
    // 0x8023960C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80239610: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80239614: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80239618: lw          $t1, 0x24($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X24);
    // 0x8023961C: lw          $t4, 0x2C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X2C);
    // 0x80239620: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80239624: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80239628: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x8023962C: lw          $t7, 0x448($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X448);
    // 0x80239630: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80239634: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80239638: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8023963C: lw          $t8, 0x24($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X24);
    // 0x80239640: sll         $t9, $s2, 12
    ctx->r25 = S32(ctx->r18 << 12);
    // 0x80239644: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x80239648: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8023964C: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x80239650: lw          $t1, 0x448($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X448);
    // 0x80239654: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80239658: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8023965C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80239660: lw          $t6, 0x24($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X24);
    // 0x80239664: lw          $t5, 0x2C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X2C);
    // 0x80239668: lh          $t7, 0x12($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X12);
    // 0x8023966C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80239670: addiu       $t0, $t8, -0x800
    ctx->r8 = ADD32(ctx->r24, -0X800);
    // 0x80239674: sh          $t0, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r8;
L_80239678:
    // 0x80239678: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8023967C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80239680: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x80239684: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80239688: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x8023968C: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80239690: swc1        $f22, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f22.u32l;
    // 0x80239694: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80239698: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x8023969C: swc1        $f24, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f24.u32l;
    // 0x802396A0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x802396A4: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x802396A8: swc1        $f26, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f26.u32l;
    // 0x802396AC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x802396B0: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x802396B4: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
    // 0x802396B8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x802396BC: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x802396C0: bne         $at, $zero, L_802394D4
    if (ctx->r1 != 0) {
        // 0x802396C4: sh          $zero, 0x14($t3)
        MEM_H(0X14, ctx->r11) = 0;
            goto L_802394D4;
    }
    // 0x802396C4: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x802396C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x802396CC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x802396D0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x802396D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x802396D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802396DC: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x802396E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x802396E4: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    // 0x802396E8: jal         0x8023448C
    // 0x802396EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_7;
    // 0x802396EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x802396F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x802396F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x802396F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x802396FC: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80239700: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80239704: addiu       $a3, $zero, -0x46
    ctx->r7 = ADD32(0, -0X46);
    // 0x80239708: jal         0x802345B0
    // 0x8023970C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_8;
    // 0x8023970C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80239710: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80239714: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80239718: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023971C: addu        $s0, $t5, $t7
    ctx->r16 = ADD32(ctx->r13, ctx->r15);
    // 0x80239720: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80239724: addiu       $v1, $v1, 0x874
    ctx->r3 = ADD32(ctx->r3, 0X874);
    // 0x80239728: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023972C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80239730: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80239734: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80239738: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023973C: sw          $t8, 0x878($at)
    MEM_W(0X878, ctx->r1) = ctx->r24;
    // 0x80239740: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80239744: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80239748: addiu       $a1, $a1, -0x6704
    ctx->r5 = ADD32(ctx->r5, -0X6704);
    // 0x8023974C: lw          $t0, 0x14($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X14);
    // 0x80239750: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80239754: sw          $t0, 0x87C($at)
    MEM_W(0X87C, ctx->r1) = ctx->r8;
    // 0x80239758: sh          $zero, 0xAC($s4)
    MEM_H(0XAC, ctx->r20) = 0;
    // 0x8023975C: sb          $t3, 0xA3($s4)
    MEM_B(0XA3, ctx->r20) = ctx->r11;
    // 0x80239760: jal         0x800058DC
    // 0x80239764: sb          $zero, 0xA5($s4)
    MEM_B(0XA5, ctx->r20) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x80239764: sb          $zero, 0xA5($s4)
    MEM_B(0XA5, ctx->r20) = 0;
    after_9:
    // 0x80239768: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8023976C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80239770: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80239774: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80239778: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8023977C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80239780: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80239784: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80239788: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8023978C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80239790: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80239794: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80239798: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8023979C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x802397A0: jr          $ra
    // 0x802397A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x802397A4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802397a8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802397a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802397A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x802397AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802397B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x802397B4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x802397B8: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x802397BC: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x802397C0: addiu       $t8, $t8, -0x1AE4
    ctx->r24 = ADD32(ctx->r24, -0X1AE4);
    // 0x802397C4: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x802397C8: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x802397CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802397D0: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
    // 0x802397D4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x802397D8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x802397DC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x802397E0: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x802397E4: lbu         $t0, 0x8($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X8);
    // 0x802397E8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x802397EC: sb          $t0, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r8;
    // 0x802397F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x802397F4: jal         0x80235FF8
    // 0x802397F8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80235FF8)(rdram, ctx);
        goto after_0;
    // 0x802397F8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x802397FC: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
    // 0x80239800: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x80239804: beq         $t1, $zero, L_80239838
    if (ctx->r9 == 0) {
        // 0x80239808: andi        $t6, $v0, 0x200
        ctx->r14 = ctx->r2 & 0X200;
            goto L_80239838;
    }
    // 0x80239808: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x8023980C: lb          $t2, 0xA5($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XA5);
    // 0x80239810: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80239814: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80239818: jal         0x80020744
    // 0x8023981C: sb          $t3, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x8023981C: sb          $t3, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r11;
    after_1:
    // 0x80239820: lb          $t4, 0xA5($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XA5);
    // 0x80239824: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80239828: bgezl       $t4, L_80239858
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8023982C: lb          $t9, 0xA5($s0)
        ctx->r25 = MEM_B(ctx->r16, 0XA5);
            goto L_80239858;
    }
    goto skip_0;
    // 0x8023982C: lb          $t9, 0xA5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA5);
    skip_0:
    // 0x80239830: b           L_80239854
    // 0x80239834: sb          $t5, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r13;
        goto L_80239854;
    // 0x80239834: sb          $t5, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r13;
L_80239838:
    // 0x80239838: beql        $t6, $zero, L_80239858
    if (ctx->r14 == 0) {
        // 0x8023983C: lb          $t9, 0xA5($s0)
        ctx->r25 = MEM_B(ctx->r16, 0XA5);
            goto L_80239858;
    }
    goto skip_1;
    // 0x8023983C: lb          $t9, 0xA5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA5);
    skip_1:
    // 0x80239840: jal         0x80020744
    // 0x80239844: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80239844: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x80239848: lb          $t7, 0xA5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA5);
    // 0x8023984C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80239850: sb          $t8, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r24;
L_80239854:
    // 0x80239854: lb          $t9, 0xA5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA5);
L_80239858:
    // 0x80239858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023985C: bgez        $t9, L_80239870
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80239860: andi        $t0, $t9, 0x7
        ctx->r8 = ctx->r25 & 0X7;
            goto L_80239870;
    }
    // 0x80239860: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x80239864: beq         $t0, $zero, L_80239870
    if (ctx->r8 == 0) {
        // 0x80239868: nop
    
            goto L_80239870;
    }
    // 0x80239868: nop

    // 0x8023986C: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80239870:
    // 0x80239870: sb          $t0, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r8;
    // 0x80239874: jal         0x8023466C
    // 0x80239878: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8023466C)(rdram, ctx);
        goto after_3;
    // 0x80239878: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8023987C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80239880: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x80239884: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x80239888: beql        $t2, $zero, L_802398C8
    if (ctx->r10 == 0) {
        // 0x8023988C: andi        $t6, $v0, 0x8000
        ctx->r14 = ctx->r2 & 0X8000;
            goto L_802398C8;
    }
    goto skip_2;
    // 0x8023988C: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    skip_2:
    // 0x80239890: lbu         $t3, 0xA8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA8);
    // 0x80239894: beql        $t3, $zero, L_802398C8
    if (ctx->r11 == 0) {
        // 0x80239898: andi        $t6, $v0, 0x8000
        ctx->r14 = ctx->r2 & 0X8000;
            goto L_802398C8;
    }
    goto skip_3;
    // 0x80239898: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    skip_3:
    // 0x8023989C: jal         0x80147218
    // 0x802398A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_4;
    // 0x802398A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x802398A4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x802398A8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802398AC: sb          $t4, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r12;
    // 0x802398B0: addiu       $a1, $a1, -0x76D8
    ctx->r5 = ADD32(ctx->r5, -0X76D8);
    // 0x802398B4: jal         0x800058DC
    // 0x802398B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x802398B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x802398BC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x802398C0: lhu         $v0, 0x4($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X4);
    // 0x802398C4: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
L_802398C8:
    // 0x802398C8: beql        $t6, $zero, L_802398EC
    if (ctx->r14 == 0) {
        // 0x802398CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_802398EC;
    }
    goto skip_4;
    // 0x802398CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x802398D0: jal         0x80020744
    // 0x802398D4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_6;
    // 0x802398D4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_6:
    // 0x802398D8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802398DC: addiu       $a1, $a1, -0x65E8
    ctx->r5 = ADD32(ctx->r5, -0X65E8);
    // 0x802398E0: jal         0x800058DC
    // 0x802398E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x802398E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x802398E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_802398EC:
    // 0x802398EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x802398F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x802398F4: jr          $ra
    // 0x802398F8: nop

    return;
    // 0x802398F8: nop

;}
RECOMP_FUNC void M10_FUN_802398fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802398FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80239900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80239904: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80239908: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023990C: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80239910: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80239914: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80239918: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8023991C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80239920: jal         0x80235FF8
    // 0x80239924: sh          $t6, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80235FF8)(rdram, ctx);
        goto after_0;
    // 0x80239924: sh          $t6, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r14;
    after_0:
    // 0x80239928: lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X22);
    // 0x8023992C: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80239930: beq         $t7, $zero, L_80239964
    if (ctx->r15 == 0) {
        // 0x80239934: andi        $t2, $v0, 0x200
        ctx->r10 = ctx->r2 & 0X200;
            goto L_80239964;
    }
    // 0x80239934: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80239938: lb          $t8, 0xA5($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XA5);
    // 0x8023993C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80239940: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80239944: jal         0x80020744
    // 0x80239948: sb          $t9, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80239948: sb          $t9, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r25;
    after_1:
    // 0x8023994C: lb          $t0, 0xA5($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XA5);
    // 0x80239950: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80239954: bgezl       $t0, L_80239984
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80239958: lb          $t5, 0xA5($s0)
        ctx->r13 = MEM_B(ctx->r16, 0XA5);
            goto L_80239984;
    }
    goto skip_0;
    // 0x80239958: lb          $t5, 0xA5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XA5);
    skip_0:
    // 0x8023995C: b           L_80239980
    // 0x80239960: sb          $t1, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r9;
        goto L_80239980;
    // 0x80239960: sb          $t1, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r9;
L_80239964:
    // 0x80239964: beql        $t2, $zero, L_80239984
    if (ctx->r10 == 0) {
        // 0x80239968: lb          $t5, 0xA5($s0)
        ctx->r13 = MEM_B(ctx->r16, 0XA5);
            goto L_80239984;
    }
    goto skip_1;
    // 0x80239968: lb          $t5, 0xA5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XA5);
    skip_1:
    // 0x8023996C: jal         0x80020744
    // 0x80239970: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80239970: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x80239974: lb          $t3, 0xA5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA5);
    // 0x80239978: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8023997C: sb          $t4, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r12;
L_80239980:
    // 0x80239980: lb          $t5, 0xA5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XA5);
L_80239984:
    // 0x80239984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80239988: bgez        $t5, L_8023999C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8023998C: andi        $t6, $t5, 0x1
        ctx->r14 = ctx->r13 & 0X1;
            goto L_8023999C;
    }
    // 0x8023998C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80239990: beq         $t6, $zero, L_8023999C
    if (ctx->r14 == 0) {
        // 0x80239994: nop
    
            goto L_8023999C;
    }
    // 0x80239994: nop

    // 0x80239998: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_8023999C:
    // 0x8023999C: sb          $t6, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = ctx->r14;
    // 0x802399A0: jal         0x8023466C
    // 0x802399A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8023466C)(rdram, ctx);
        goto after_3;
    // 0x802399A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x802399A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x802399AC: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
    // 0x802399B0: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x802399B4: beql        $t8, $zero, L_802399E4
    if (ctx->r24 == 0) {
        // 0x802399B8: andi        $t0, $v0, 0x8000
        ctx->r8 = ctx->r2 & 0X8000;
            goto L_802399E4;
    }
    goto skip_2;
    // 0x802399B8: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    skip_2:
    // 0x802399BC: jal         0x80147218
    // 0x802399C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_4;
    // 0x802399C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x802399C4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802399C8: sb          $zero, 0xA5($s0)
    MEM_B(0XA5, ctx->r16) = 0;
    // 0x802399CC: addiu       $a1, $a1, -0x76D8
    ctx->r5 = ADD32(ctx->r5, -0X76D8);
    // 0x802399D0: jal         0x800058DC
    // 0x802399D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x802399D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x802399D8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x802399DC: lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X4);
    // 0x802399E0: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
L_802399E4:
    // 0x802399E4: beql        $t0, $zero, L_80239A08
    if (ctx->r8 == 0) {
        // 0x802399E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80239A08;
    }
    goto skip_3;
    // 0x802399E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x802399EC: jal         0x80020744
    // 0x802399F0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_6;
    // 0x802399F0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_6:
    // 0x802399F4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x802399F8: addiu       $a1, $a1, -0x65E8
    ctx->r5 = ADD32(ctx->r5, -0X65E8);
    // 0x802399FC: jal         0x800058DC
    // 0x80239A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80239A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80239A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80239A08:
    // 0x80239A08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80239A0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80239A10: jr          $ra
    // 0x80239A14: nop

    return;
    // 0x80239A14: nop

;}
RECOMP_FUNC void M10_FUN_80239a18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80239A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80239A24: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80239A28: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x80239A2C: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80239A30: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239A34: sw          $t6, 0x2D4($v0)
    MEM_W(0X2D4, ctx->r2) = ctx->r14;
    // 0x80239A38: lb          $t7, 0xA5($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XA5);
    // 0x80239A3C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    // 0x80239A40: sb          $t8, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r24;
    // 0x80239A44: jal         0x800058DC
    // 0x80239A48: sb          $t7, 0x2D9($v0)
    MEM_B(0X2D9, ctx->r2) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80239A48: sb          $t7, 0x2D9($v0)
    MEM_B(0X2D9, ctx->r2) = ctx->r15;
    after_0:
    // 0x80239A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80239A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80239A54: jr          $ra
    // 0x80239A58: nop

    return;
    // 0x80239A58: nop

;}
RECOMP_FUNC void M10_FUN_80239a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80239A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239A64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80239A68: lhu         $v1, 0xAC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XAC);
    // 0x80239A6C: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80239A70: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x80239A74: bnel        $at, $zero, L_80239B7C
    if (ctx->r1 != 0) {
        // 0x80239A78: andi        $t9, $v1, 0x4
        ctx->r25 = ctx->r3 & 0X4;
            goto L_80239B7C;
    }
    goto skip_0;
    // 0x80239A78: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    skip_0:
    // 0x80239A7C: lbu         $t6, 0xA5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XA5);
    // 0x80239A80: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80239A84: beq         $at, $zero, L_80239B5C
    if (ctx->r1 == 0) {
        // 0x80239A88: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80239B5C;
    }
    // 0x80239A88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80239A8C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80239A90: addu        $at, $at, $t6
    gpr jr_addend_80239A98 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80239A94: lw          $t6, 0x5C0($at)
    ctx->r14 = ADD32(ctx->r1, 0X5C0);
    // 0x80239A98: jr          $t6
    // 0x80239A9C: nop

    switch (jr_addend_80239A98 >> 2) {
        case 0: goto L_80239AA0; break;
        case 1: goto L_80239AE8; break;
        case 2: goto L_80239B10; break;
        case 3: goto L_80239B38; break;
        case 4: goto L_80239B38; break;
        default: switch_error(__func__, 0x80239A98, 0x802405C0);
    }
    // 0x80239A9C: nop

L_80239AA0:
    // 0x80239AA0: lw          $t7, 0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X38);
    // 0x80239AA4: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80239AA8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80239AAC: beql        $t8, $zero, L_80239AC0
    if (ctx->r24 == 0) {
        // 0x80239AB0: lw          $t0, 0x30($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X30);
            goto L_80239AC0;
    }
    goto skip_1;
    // 0x80239AB0: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    skip_1:
    // 0x80239AB4: b           L_80239B64
    // 0x80239AB8: sb          $t9, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r25;
        goto L_80239B64;
    // 0x80239AB8: sb          $t9, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r25;
    // 0x80239ABC: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
L_80239AC0:
    // 0x80239AC0: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80239AC4: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x80239AC8: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x80239ACC: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80239AD0: beq         $t2, $zero, L_80239AE0
    if (ctx->r10 == 0) {
        // 0x80239AD4: nop
    
            goto L_80239AE0;
    }
    // 0x80239AD4: nop

    // 0x80239AD8: b           L_80239B64
    // 0x80239ADC: sb          $t3, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r11;
        goto L_80239B64;
    // 0x80239ADC: sb          $t3, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r11;
L_80239AE0:
    // 0x80239AE0: b           L_80239B64
    // 0x80239AE4: sb          $t4, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r12;
        goto L_80239B64;
    // 0x80239AE4: sb          $t4, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r12;
L_80239AE8:
    // 0x80239AE8: lw          $t5, 0x38($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X38);
    // 0x80239AEC: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80239AF0: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80239AF4: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80239AF8: beq         $t6, $zero, L_80239B08
    if (ctx->r14 == 0) {
        // 0x80239AFC: nop
    
            goto L_80239B08;
    }
    // 0x80239AFC: nop

    // 0x80239B00: b           L_80239B64
    // 0x80239B04: sb          $t7, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r15;
        goto L_80239B64;
    // 0x80239B04: sb          $t7, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r15;
L_80239B08:
    // 0x80239B08: b           L_80239B64
    // 0x80239B0C: sb          $t8, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r24;
        goto L_80239B64;
    // 0x80239B0C: sb          $t8, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r24;
L_80239B10:
    // 0x80239B10: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x80239B14: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // 0x80239B18: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80239B1C: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80239B20: beq         $t0, $zero, L_80239B30
    if (ctx->r8 == 0) {
        // 0x80239B24: nop
    
            goto L_80239B30;
    }
    // 0x80239B24: nop

    // 0x80239B28: b           L_80239B64
    // 0x80239B2C: sb          $t1, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r9;
        goto L_80239B64;
    // 0x80239B2C: sb          $t1, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r9;
L_80239B30:
    // 0x80239B30: b           L_80239B64
    // 0x80239B34: sb          $t2, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r10;
        goto L_80239B64;
    // 0x80239B34: sb          $t2, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r10;
L_80239B38:
    // 0x80239B38: lbu         $t3, 0x2D9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2D9);
    // 0x80239B3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80239B40: addiu       $t5, $t5, 0x42A0
    ctx->r13 = ADD32(ctx->r13, 0X42A0);
    // 0x80239B44: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80239B48: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80239B4C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80239B50: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80239B54: b           L_80239B64
    // 0x80239B58: sw          $t6, 0x2D4($v0)
    MEM_W(0X2D4, ctx->r2) = ctx->r14;
        goto L_80239B64;
    // 0x80239B58: sw          $t6, 0x2D4($v0)
    MEM_W(0X2D4, ctx->r2) = ctx->r14;
L_80239B5C:
    // 0x80239B5C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80239B60: sb          $t7, 0x2D8($v0)
    MEM_B(0X2D8, ctx->r2) = ctx->r15;
L_80239B64:
    // 0x80239B64: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239B68: jal         0x800058DC
    // 0x80239B6C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80239B6C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_0:
    // 0x80239B70: b           L_80239BC4
    // 0x80239B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80239BC4;
    // 0x80239B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80239B78: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
L_80239B7C:
    // 0x80239B7C: beq         $t9, $zero, L_80239BA4
    if (ctx->r25 == 0) {
        // 0x80239B80: lui         $t6, 0x8024
        ctx->r14 = S32(0X8024 << 16);
            goto L_80239BA4;
    }
    // 0x80239B80: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80239B84: lb          $t1, 0xA5($a0)
    ctx->r9 = MEM_B(ctx->r4, 0XA5);
    // 0x80239B88: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80239B8C: lw          $t0, 0x870($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X870);
    // 0x80239B90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80239B94: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80239B98: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80239B9C: b           L_80239BC0
    // 0x80239BA0: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
        goto L_80239BC0;
    // 0x80239BA0: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
L_80239BA4:
    // 0x80239BA4: lb          $t7, 0xA5($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XA5);
    // 0x80239BA8: lw          $t6, 0x870($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X870);
    // 0x80239BAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80239BB0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80239BB4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80239BB8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80239BBC: sb          $t5, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r13;
L_80239BC0:
    // 0x80239BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239BC4:
    // 0x80239BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80239BC8: jr          $ra
    // 0x80239BCC: nop

    return;
    // 0x80239BCC: nop

;}
RECOMP_FUNC void M10_FUN_80239bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239BD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80239BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239BD8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80239BDC: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80239BE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80239BE4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239BE8: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x80239BEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80239BF0: beq         $v1, $zero, L_80239C00
    if (ctx->r3 == 0) {
        // 0x80239BF4: nop
    
            goto L_80239C00;
    }
    // 0x80239BF4: nop

    // 0x80239BF8: bne         $v1, $at, L_80239C08
    if (ctx->r3 != ctx->r1) {
        // 0x80239BFC: nop
    
            goto L_80239C08;
    }
    // 0x80239BFC: nop

L_80239C00:
    // 0x80239C00: b           L_80239C10
    // 0x80239C04: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_80239C10;
    // 0x80239C04: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80239C08:
    // 0x80239C08: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239C0C: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80239C10:
    // 0x80239C10: lhu         $t6, 0xAC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XAC);
    // 0x80239C14: lw          $v1, 0xB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XB0);
    // 0x80239C18: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x80239C1C: bnel        $at, $zero, L_80239C80
    if (ctx->r1 != 0) {
        // 0x80239C20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80239C80;
    }
    goto skip_0;
    // 0x80239C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80239C24: lb          $t8, 0xA1($a2)
    ctx->r24 = MEM_B(ctx->r6, 0XA1);
    // 0x80239C28: lb          $t7, 0xA5($a2)
    ctx->r15 = MEM_B(ctx->r6, 0XA5);
    // 0x80239C2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80239C30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80239C34: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80239C38: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x80239C3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80239C40: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80239C44: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80239C48: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80239C4C: sw          $t2, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r10;
    // 0x80239C50: lbu         $t4, 0xA($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0XA);
    // 0x80239C54: sb          $t4, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r12;
    // 0x80239C58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80239C5C: jal         0x80376BE4
    // 0x80239C60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80376BE4)(rdram, ctx);
        goto after_0;
    // 0x80239C60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80239C64: jal         0x80231CE4
    // 0x80239C68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80231CE4)(rdram, ctx);
        goto after_1;
    // 0x80239C68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80239C6C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239C70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80239C74: jal         0x800058DC
    // 0x80239C78: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80239C78: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_2:
    // 0x80239C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239C80:
    // 0x80239C80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80239C84: jr          $ra
    // 0x80239C88: nop

    return;
    // 0x80239C88: nop

;}
RECOMP_FUNC void M10_FUN_80239c8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80239C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239C94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80239C98: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80239C9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80239CA0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239CA4: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x80239CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80239CAC: beq         $v1, $zero, L_80239CBC
    if (ctx->r3 == 0) {
        // 0x80239CB0: nop
    
            goto L_80239CBC;
    }
    // 0x80239CB0: nop

    // 0x80239CB4: bne         $v1, $at, L_80239CC4
    if (ctx->r3 != ctx->r1) {
        // 0x80239CB8: nop
    
            goto L_80239CC4;
    }
    // 0x80239CB8: nop

L_80239CBC:
    // 0x80239CBC: b           L_80239CCC
    // 0x80239CC0: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_80239CCC;
    // 0x80239CC0: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80239CC4:
    // 0x80239CC4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239CC8: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80239CCC:
    // 0x80239CCC: jal         0x8013D134
    // 0x80239CD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013D134)(rdram, ctx);
        goto after_0;
    // 0x80239CD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80239CD4: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239CD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80239CDC: jal         0x800058DC
    // 0x80239CE0: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80239CE0: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_1:
    // 0x80239CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80239CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80239CEC: jr          $ra
    // 0x80239CF0: nop

    return;
    // 0x80239CF0: nop

;}
RECOMP_FUNC void M10_FUN_80239cf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80239CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239CFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80239D00: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80239D04: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80239D08: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239D0C: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x80239D10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80239D14: beq         $v1, $zero, L_80239D24
    if (ctx->r3 == 0) {
        // 0x80239D18: nop
    
            goto L_80239D24;
    }
    // 0x80239D18: nop

    // 0x80239D1C: bne         $v1, $at, L_80239D2C
    if (ctx->r3 != ctx->r1) {
        // 0x80239D20: nop
    
            goto L_80239D2C;
    }
    // 0x80239D20: nop

L_80239D24:
    // 0x80239D24: b           L_80239D34
    // 0x80239D28: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_80239D34;
    // 0x80239D28: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80239D2C:
    // 0x80239D2C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239D30: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80239D34:
    // 0x80239D34: lhu         $t6, 0xAC($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XAC);
    // 0x80239D38: lw          $v1, 0xB0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XB0);
    // 0x80239D3C: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x80239D40: bnel        $at, $zero, L_80239DF0
    if (ctx->r1 != 0) {
        // 0x80239D44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80239DF0;
    }
    goto skip_0;
    // 0x80239D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80239D48: lb          $t8, 0xA1($a3)
    ctx->r24 = MEM_B(ctx->r7, 0XA1);
    // 0x80239D4C: lb          $t7, 0xA5($a3)
    ctx->r15 = MEM_B(ctx->r7, 0XA5);
    // 0x80239D50: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80239D54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80239D58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80239D5C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80239D60: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x80239D64: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80239D68: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80239D6C: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80239D70: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80239D74: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80239D78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80239D7C: sw          $t2, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r10;
    // 0x80239D80: lbu         $t4, 0xA($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0XA);
    // 0x80239D84: sb          $t5, 0x2D8($a0)
    MEM_B(0X2D8, ctx->r4) = ctx->r13;
    // 0x80239D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80239D8C: sb          $t4, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r12;
    // 0x80239D90: lbu         $t6, -0x1C5C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1C5C);
    // 0x80239D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80239D98: bne         $t6, $at, L_80239DB4
    if (ctx->r14 != ctx->r1) {
        // 0x80239D9C: nop
    
            goto L_80239DB4;
    }
    // 0x80239D9C: nop

    // 0x80239DA0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80239DA4: jal         0x8013CD04
    // 0x80239DA8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013CD04)(rdram, ctx);
        goto after_0;
    // 0x80239DA8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80239DAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80239DB0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_80239DB4:
    // 0x80239DB4: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80239DB8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80239DBC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80239DC0: addiu       $v0, $v0, -0x1C54
    ctx->r2 = ADD32(ctx->r2, -0X1C54);
    // 0x80239DC4: sb          $t8, -0x1C5C($at)
    MEM_B(-0X1C5C, ctx->r1) = ctx->r24;
    // 0x80239DC8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80239DCC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80239DD0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80239DD4: jal         0x80231CE4
    // 0x80239DD8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80231CE4)(rdram, ctx);
        goto after_1;
    // 0x80239DD8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    after_1:
    // 0x80239DDC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239DE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80239DE4: jal         0x800058DC
    // 0x80239DE8: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80239DE8: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_2:
    // 0x80239DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239DF0:
    // 0x80239DF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80239DF4: jr          $ra
    // 0x80239DF8: nop

    return;
    // 0x80239DF8: nop

;}
RECOMP_FUNC void M10_FUN_80239dfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80239E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239E04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80239E08: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80239E0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80239E10: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239E14: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x80239E18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80239E1C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80239E20: beq         $v1, $zero, L_80239E30
    if (ctx->r3 == 0) {
        // 0x80239E24: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80239E30;
    }
    // 0x80239E24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80239E28: bne         $v1, $at, L_80239E38
    if (ctx->r3 != ctx->r1) {
        // 0x80239E2C: nop
    
            goto L_80239E38;
    }
    // 0x80239E2C: nop

L_80239E30:
    // 0x80239E30: b           L_80239E40
    // 0x80239E34: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_80239E40;
    // 0x80239E34: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80239E38:
    // 0x80239E38: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239E3C: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80239E40:
    // 0x80239E40: lhu         $t6, 0xAC($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XAC);
    // 0x80239E44: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x80239E48: bnel        $at, $zero, L_80239E74
    if (ctx->r1 != 0) {
        // 0x80239E4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80239E74;
    }
    goto skip_0;
    // 0x80239E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80239E50: sb          $t7, 0x2D8($a0)
    MEM_B(0X2D8, ctx->r4) = ctx->r15;
    // 0x80239E54: lbu         $a1, 0xA5($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0XA5);
    // 0x80239E58: jal         0x8013CD04
    // 0x80239E5C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013CD04)(rdram, ctx);
        goto after_0;
    // 0x80239E5C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80239E60: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239E64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80239E68: jal         0x800058DC
    // 0x80239E6C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80239E6C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_1:
    // 0x80239E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239E74:
    // 0x80239E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80239E78: jr          $ra
    // 0x80239E7C: nop

    return;
    // 0x80239E7C: nop

;}
RECOMP_FUNC void M10_FUN_80239e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80239E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80239E88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80239E8C: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80239E90: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80239E94: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239E98: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x80239E9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80239EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80239EA4: beq         $v1, $zero, L_80239EB4
    if (ctx->r3 == 0) {
        // 0x80239EA8: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_80239EB4;
    }
    // 0x80239EA8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80239EAC: bne         $v1, $at, L_80239EBC
    if (ctx->r3 != ctx->r1) {
        // 0x80239EB0: nop
    
            goto L_80239EBC;
    }
    // 0x80239EB0: nop

L_80239EB4:
    // 0x80239EB4: b           L_80239EC4
    // 0x80239EB8: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
        goto L_80239EC4;
    // 0x80239EB8: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80239EBC:
    // 0x80239EBC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80239EC0: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80239EC4:
    // 0x80239EC4: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80239EC8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80239ECC: bne         $v0, $at, L_80239EF8
    if (ctx->r2 != ctx->r1) {
        // 0x80239ED0: nop
    
            goto L_80239EF8;
    }
    // 0x80239ED0: nop

    // 0x80239ED4: lbu         $a1, 0x2D9($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2D9);
    // 0x80239ED8: jal         0x8013CD04
    // 0x80239EDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013CD04)(rdram, ctx);
        goto after_0;
    // 0x80239EDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80239EE0: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80239EE8: jal         0x800058DC
    // 0x80239EEC: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80239EEC: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_1:
    // 0x80239EF0: b           L_80239F94
    // 0x80239EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80239F94;
    // 0x80239EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239EF8:
    // 0x80239EF8: beq         $a1, $v0, L_80239F48
    if (ctx->r5 == ctx->r2) {
        // 0x80239EFC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80239F48;
    }
    // 0x80239EFC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80239F00: beql        $v0, $at, L_80239F4C
    if (ctx->r2 == ctx->r1) {
        // 0x80239F04: lw          $v0, 0x98($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X98);
            goto L_80239F4C;
    }
    goto skip_0;
    // 0x80239F04: lw          $v0, 0x98($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X98);
    skip_0:
    // 0x80239F08: lbu         $t6, 0x2D9($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2D9);
    // 0x80239F0C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80239F10: addiu       $t8, $t8, 0x42A0
    ctx->r24 = ADD32(ctx->r24, 0X42A0);
    // 0x80239F14: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80239F18: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80239F1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80239F20: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80239F24: sw          $t9, 0x2D4($a0)
    MEM_W(0X2D4, ctx->r4) = ctx->r25;
    // 0x80239F28: jal         0x80231CE4
    // 0x80239F2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80231CE4)(rdram, ctx);
        goto after_2;
    // 0x80239F2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80239F30: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80239F38: jal         0x800058DC
    // 0x80239F3C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80239F3C: addiu       $a1, $a1, -0x5F64
    ctx->r5 = ADD32(ctx->r5, -0X5F64);
    after_3:
    // 0x80239F40: b           L_80239F94
    // 0x80239F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80239F94;
    // 0x80239F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239F48:
    // 0x80239F48: lw          $v0, 0x98($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X98);
L_80239F4C:
    // 0x80239F4C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80239F50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80239F54: lbu         $v1, 0x2D8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2D8);
    // 0x80239F58: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80239F5C: beq         $a1, $v1, L_80239F68
    if (ctx->r5 == ctx->r3) {
        // 0x80239F60: nop
    
            goto L_80239F68;
    }
    // 0x80239F60: nop

    // 0x80239F64: bne         $v1, $at, L_80239F84
    if (ctx->r3 != ctx->r1) {
        // 0x80239F68: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80239F84;
    }
L_80239F68:
    // 0x80239F68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80239F6C: sb          $t0, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r8;
    // 0x80239F70: lbu         $t1, 0x31($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X31);
    // 0x80239F74: andi        $t4, $t1, 0xFFF8
    ctx->r12 = ctx->r9 & 0XFFF8;
    // 0x80239F78: sb          $t4, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r12;
    // 0x80239F7C: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x80239F80: sb          $t5, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r13;
L_80239F84:
    // 0x80239F84: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239F88: jal         0x800058DC
    // 0x80239F8C: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80239F8C: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    after_4:
    // 0x80239F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80239F94:
    // 0x80239F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80239F98: jr          $ra
    // 0x80239F9C: nop

    return;
    // 0x80239F9C: nop

;}
RECOMP_FUNC void M10_FUN_80239fa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239FA0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80239FA4: lhu         $t6, 0xAC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XAC);
    // 0x80239FA8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80239FAC: jr          $ra
    // 0x80239FB0: sh          $t7, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r15;
    return;
    // 0x80239FB0: sh          $t7, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80239fb4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80239fb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80239FB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80239FB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80239FBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80239FC0: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80239FC4: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80239FC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80239FCC: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x80239FD0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80239FD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80239FD8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80239FDC: lbu         $t8, 0x22($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X22);
    // 0x80239FE0: addiu       $a1, $a1, 0x870
    ctx->r5 = ADD32(ctx->r5, 0X870);
    // 0x80239FE4: addiu       $a3, $a3, 0x86C
    ctx->r7 = ADD32(ctx->r7, 0X86C);
    // 0x80239FE8: sb          $t8, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r24;
    // 0x80239FEC: lb          $t0, 0xA4($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XA4);
    // 0x80239FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80239FF4: blez        $t0, L_8023A054
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80239FF8: nop
    
            goto L_8023A054;
    }
    // 0x80239FF8: nop

    // 0x80239FFC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_8023A000:
    // 0x8023A000: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8023A004: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8023A008: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8023A00C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8023A010: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8023A014: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x8023A018: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x8023A01C: lbu         $t4, 0xB($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XB);
    // 0x8023A020: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x8023A024: sb          $t5, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r13;
    // 0x8023A028: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8023A02C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8023A030: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8023A034: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x8023A038: lbu         $t9, 0xB($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB);
    // 0x8023A03C: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x8023A040: sb          $t0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r8;
    // 0x8023A044: lb          $t1, 0xA4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XA4);
    // 0x8023A048: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8023A04C: bnel        $at, $zero, L_8023A000
    if (ctx->r1 != 0) {
        // 0x8023A050: lw          $t1, 0x0($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X0);
            goto L_8023A000;
    }
    goto skip_0;
    // 0x8023A050: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    skip_0:
L_8023A054:
    // 0x8023A054: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8023A058: addiu       $a3, $a3, 0x86C
    ctx->r7 = ADD32(ctx->r7, 0X86C);
    // 0x8023A05C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8023A060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023A064: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023A068: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8023A06C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8023A070: lbu         $v0, 0xB($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0XB);
    // 0x8023A074: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8023A078: beql        $at, $zero, L_8023A08C
    if (ctx->r1 == 0) {
        // 0x8023A07C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8023A08C;
    }
    goto skip_1;
    // 0x8023A07C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8023A080: jal         0x800058DC
    // 0x8023A084: addiu       $a1, $a1, -0x5EAC
    ctx->r5 = ADD32(ctx->r5, -0X5EAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8023A084: addiu       $a1, $a1, -0x5EAC
    ctx->r5 = ADD32(ctx->r5, -0X5EAC);
    after_0:
    // 0x8023A088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8023A08C:
    // 0x8023A08C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8023A090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8023A094: jr          $ra
    // 0x8023A098: nop

    return;
    // 0x8023A098: nop

;}
RECOMP_FUNC void M10_FUN_8023a09c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A09C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A0A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A0A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8023A0A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023A0AC: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x8023A0B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8023A0B4: lbu         $t7, 0x31($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X31);
    // 0x8023A0B8: andi        $t0, $t7, 0xFFF8
    ctx->r8 = ctx->r15 & 0XFFF8;
    // 0x8023A0BC: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8023A0C0: sb          $t0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r8;
    // 0x8023A0C4: jal         0x80147D60
    // 0x8023A0C8: sb          $t1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r9;
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_0;
    // 0x8023A0C8: sb          $t1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r9;
    after_0:
    // 0x8023A0CC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023A0D0: addiu       $a1, $a1, -0x5F14
    ctx->r5 = ADD32(ctx->r5, -0X5F14);
    // 0x8023A0D4: jal         0x800058DC
    // 0x8023A0D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8023A0D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8023A0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023A0E4: jr          $ra
    // 0x8023A0E8: nop

    return;
    // 0x8023A0E8: nop

;}
RECOMP_FUNC void M10_FUN_8023a0ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A0F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023A0F8: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x8023A0FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023A100: lbu         $v1, 0x74($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X74);
    // 0x8023A104: beq         $v1, $zero, L_8023A11C
    if (ctx->r3 == 0) {
        // 0x8023A108: nop
    
            goto L_8023A11C;
    }
    // 0x8023A108: nop

    // 0x8023A10C: beq         $v1, $at, L_8023A11C
    if (ctx->r3 == ctx->r1) {
        // 0x8023A110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8023A11C;
    }
    // 0x8023A110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8023A114: bne         $v1, $at, L_8023A138
    if (ctx->r3 != ctx->r1) {
        // 0x8023A118: nop
    
            goto L_8023A138;
    }
    // 0x8023A118: nop

L_8023A11C:
    // 0x8023A11C: jal         0x800023EC
    // 0x8023A120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_0;
    // 0x8023A120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8023A124: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A128: sb          $zero, -0x1C60($at)
    MEM_B(-0X1C60, ctx->r1) = 0;
    // 0x8023A12C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8023A134: sw          $zero, -0x1C48($at)
    MEM_W(-0X1C48, ctx->r1) = 0;
L_8023A138:
    // 0x8023A138: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A13C: jal         0x80005700
    // 0x8023A140: sw          $zero, -0x1C44($at)
    MEM_W(-0X1C44, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8023A140: sw          $zero, -0x1C44($at)
    MEM_W(-0X1C44, ctx->r1) = 0;
    after_1:
    // 0x8023A144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023A14C: jr          $ra
    // 0x8023A150: nop

    return;
    // 0x8023A150: nop

;}
RECOMP_FUNC void M10_FUN_8023a154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A15C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8023A160: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x8023A164: lw          $v1, 0x90($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X90);
    // 0x8023A168: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8023A16C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8023A170: sb          $t6, -0x33DF($at)
    MEM_B(-0X33DF, ctx->r1) = ctx->r14;
    // 0x8023A174: lbu         $t7, 0x31($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X31);
    // 0x8023A178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023A17C: andi        $t8, $t7, 0xFFF8
    ctx->r24 = ctx->r15 & 0XFFF8;
    // 0x8023A180: sb          $t8, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r24;
    // 0x8023A184: lbu         $a1, 0x74($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X74);
    // 0x8023A188: beq         $a1, $zero, L_8023A1A0
    if (ctx->r5 == 0) {
        // 0x8023A18C: nop
    
            goto L_8023A1A0;
    }
    // 0x8023A18C: nop

    // 0x8023A190: beq         $a1, $at, L_8023A1A0
    if (ctx->r5 == ctx->r1) {
        // 0x8023A194: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8023A1A0;
    }
    // 0x8023A194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8023A198: bne         $a1, $at, L_8023A1BC
    if (ctx->r5 != ctx->r1) {
        // 0x8023A19C: nop
    
            goto L_8023A1BC;
    }
    // 0x8023A19C: nop

L_8023A1A0:
    // 0x8023A1A0: jal         0x800023EC
    // 0x8023A1A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_0;
    // 0x8023A1A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8023A1A8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A1AC: sb          $zero, -0x1C60($at)
    MEM_B(-0X1C60, ctx->r1) = 0;
    // 0x8023A1B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A1B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8023A1B8: sw          $zero, -0x1C48($at)
    MEM_W(-0X1C48, ctx->r1) = 0;
L_8023A1BC:
    // 0x8023A1BC: jal         0x80005700
    // 0x8023A1C0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8023A1C0: nop

    after_1:
    // 0x8023A1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A1C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023A1CC: jr          $ra
    // 0x8023A1D0: nop

    return;
    // 0x8023A1D0: nop

;}
RECOMP_FUNC void M10_FUN_8023a1d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A1D4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8023A1D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8023A1DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8023A1E0: beq         $t6, $zero, L_8023A1FC
    if (ctx->r14 == 0) {
        // 0x8023A1E4: nop
    
            goto L_8023A1FC;
    }
    // 0x8023A1E4: nop

    // 0x8023A1E8: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
L_8023A1EC:
    // 0x8023A1EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8023A1F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8023A1F4: bnel        $t7, $zero, L_8023A1EC
    if (ctx->r15 != 0) {
        // 0x8023A1F8: lbu         $t7, 0x1($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X1);
            goto L_8023A1EC;
    }
    goto skip_0;
    // 0x8023A1F8: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    skip_0:
L_8023A1FC:
    // 0x8023A1FC: jr          $ra
    // 0x8023A200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8023A200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a204(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A204: nop

    // 0x8023A208: nop

    // 0x8023A20C: nop

;}
RECOMP_FUNC void M10_FUN_8023a210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A210: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A214: lw          $t6, -0x1ABC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1ABC);
    // 0x8023A218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023A21C: beq         $t6, $zero, L_8023A22C
    if (ctx->r14 == 0) {
            // 0x8023A220: nop

    LOOKUP_FUNC(0x8023A22C)(rdram, ctx);
    return;
    }
    // 0x8023A220: nop

    // 0x8023A224: jr          $ra
    // 0x8023A228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8023A228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a22c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a22c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A22C: jr          $ra
    // 0x8023A230: nop

    return;
    // 0x8023A230: nop

;}
RECOMP_FUNC void M10_FUN_8023a234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A234: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A238: lw          $t6, -0x1ABC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1ABC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a23c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a23c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A23C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023A240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8023A244: bne         $t6, $zero, L_8023A2AC
    if (ctx->r14 != 0) {
        // 0x8023A248: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8023A2AC;
    }
    // 0x8023A248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023A24C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023A250: addiu       $t7, $t7, -0x1AD0
    ctx->r15 = ADD32(ctx->r15, -0X1AD0);
    // 0x8023A254: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8023A258: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8023A25C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8023A260: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8023A264: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8023A268: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8023A26C: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x8023A270: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8023A274: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8023A278: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8023A27C: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8023A280: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8023A284: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8023A288: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8023A28C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8023A290: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8023A294: jal         0x8012C4D0
    // 0x8023A298: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8023A298: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x8023A29C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A2A0: sw          $v0, -0x1ABC($at)
    MEM_W(-0X1ABC, ctx->r1) = ctx->r2;
    // 0x8023A2A4: b           L_8023A2AC
    // 0x8023A2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8023A2AC;
    // 0x8023A2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8023A2AC:
    // 0x8023A2AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8023A2B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023A2B4: jr          $ra
    // 0x8023A2B8: nop

    return;
    // 0x8023A2B8: nop

;}
RECOMP_FUNC void M10_FUN_8023a2bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A2BC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8023A2C0: lbu         $t6, -0x33E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a2c4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a2c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023A2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023A2CC: bne         $t6, $zero, L_8023A33C
    if (ctx->r14 != 0) {
        // 0x8023A2D0: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_8023A33C;
    }
    // 0x8023A2D0: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023A2D4: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023A2D8: addiu       $v1, $v1, 0x880
    ctx->r3 = ADD32(ctx->r3, 0X880);
    // 0x8023A2DC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x8023A2E0: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x8023A2E4: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    // 0x8023A2E8: addiu       $t8, $zero, 0x34
    ctx->r24 = ADD32(0, 0X34);
    // 0x8023A2EC: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x8023A2F0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A2F4: addiu       $t0, $t9, 0x64
    ctx->r8 = ADD32(ctx->r25, 0X64);
    // 0x8023A2F8: sh          $t0, 0x894($at)
    MEM_H(0X894, ctx->r1) = ctx->r8;
    // 0x8023A2FC: addiu       $t1, $zero, 0x47
    ctx->r9 = ADD32(0, 0X47);
    // 0x8023A300: jal         0x80236C9C
    // 0x8023A304: sh          $t1, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r9;
    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_0;
    // 0x8023A304: sh          $t1, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r9;
    after_0:
    // 0x8023A308: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x8023A30C: beq         $v0, $zero, L_8023A324
    if (ctx->r2 == 0) {
        // 0x8023A310: addiu       $v1, $v1, 0x880
        ctx->r3 = ADD32(ctx->r3, 0X880);
            goto L_8023A324;
    }
    // 0x8023A310: addiu       $v1, $v1, 0x880
    ctx->r3 = ADD32(ctx->r3, 0X880);
    // 0x8023A314: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8023A318: addiu       $t3, $zero, 0xC3
    ctx->r11 = ADD32(0, 0XC3);
    // 0x8023A31C: sh          $t2, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r10;
    // 0x8023A320: sh          $t3, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r11;
L_8023A324:
    // 0x8023A324: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8023A328: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8023A32C: sb          $zero, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = 0;
    // 0x8023A330: sb          $t4, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r12;
    // 0x8023A334: b           L_8023A380
    // 0x8023A338: sb          $t5, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r13;
        goto L_8023A380;
    // 0x8023A338: sb          $t5, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r13;
L_8023A33C:
    // 0x8023A33C: addiu       $v1, $v1, 0x880
    ctx->r3 = ADD32(ctx->r3, 0X880);
    // 0x8023A340: addiu       $t6, $zero, 0x105
    ctx->r14 = ADD32(0, 0X105);
    // 0x8023A344: sh          $t6, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r14;
    // 0x8023A348: lh          $t8, 0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X10);
    // 0x8023A34C: addiu       $t7, $zero, 0xA3
    ctx->r15 = ADD32(0, 0XA3);
    // 0x8023A350: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    // 0x8023A354: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023A358: addiu       $t9, $t8, -0x4B
    ctx->r25 = ADD32(ctx->r24, -0X4B);
    // 0x8023A35C: sh          $t9, 0x894($at)
    MEM_H(0X894, ctx->r1) = ctx->r25;
    // 0x8023A360: addiu       $t0, $zero, 0xAA
    ctx->r8 = ADD32(0, 0XAA);
    // 0x8023A364: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8023A368: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x8023A36C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8023A370: sh          $t0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r8;
    // 0x8023A374: sb          $t1, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r9;
    // 0x8023A378: sb          $t2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r10;
    // 0x8023A37C: sb          $t3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r11;
L_8023A380:
    // 0x8023A380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023A384: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8023A388: sb          $v0, 0x6A($v1)
    MEM_B(0X6A, ctx->r3) = ctx->r2;
    // 0x8023A38C: sb          $v0, 0x6B($v1)
    MEM_B(0X6B, ctx->r3) = ctx->r2;
    // 0x8023A390: jr          $ra
    // 0x8023A394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8023A394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a398(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A398: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023A39C: lw          $t6, 0x88C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X88C);
    // 0x8023A3A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8023A3A4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023A3A8: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8023A3AC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8023A3B0: lw          $v1, 0x98($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X98);
    // 0x8023A3B4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8023A3B8: sw          $t9, 0x2D4($v1)
    MEM_W(0X2D4, ctx->r3) = ctx->r25;
    // 0x8023A3BC: jr          $ra
    // 0x8023A3C0: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    return;
    // 0x8023A3C0: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023a3c4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023a3c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023A3C4: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8023A3C8: addiu       $a2, $a2, 0x880
    ctx->r6 = ADD32(ctx->r6, 0X880);
    // 0x8023A3CC: lbu         $v0, 0x23($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X23);
    // 0x8023A3D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8023A3D4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023A3D8: blez        $v0, L_8023A408
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8023A3DC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8023A408;
    }
    // 0x8023A3DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8023A3E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8023A3E4: addu        $t6, $a2, $v1
    ctx->r14 = ADD32(ctx->r6, ctx->r3);
L_8023A3E8:
    // 0x8023A3E8: lbu         $t7, 0x51($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X51);
    // 0x8023A3EC: beq         $a1, $t7, L_8023A408
    if (ctx->r5 == ctx->r15) {
        // 0x8023A3F0: nop
    
            goto L_8023A408;
    }
    // 0x8023A3F0: nop

    // 0x8023A3F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8023A3F8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8023A3FC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8023A400: bnel        $at, $zero, L_8023A3E8
    if (ctx->r1 != 0) {
        // 0x8023A404: addu        $t6, $a2, $v1
        ctx->r14 = ADD32(ctx->r6, ctx->r3);
            goto L_8023A3E8;
    }
    goto skip_0;
    // 0x8023A404: addu        $t6, $a2, $v1
    ctx->r14 = ADD32(ctx->r6, ctx->r3);
    skip_0:
L_8023A408:
    // 0x8023A408: bnel        $v0, $v1, L_8023A41C
    if (ctx->r2 != ctx->r3) {
        // 0x8023A40C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8023A41C;
    }
    goto skip_1;
    // 0x8023A40C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8023A410: jr          $ra
    // 0x8023A414: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8023A414: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8023A418: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8023A41C:
    // 0x8023A41C: jr          $ra
    // 0x8023A420: nop

    return;
    // 0x8023A420: nop

;}
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
