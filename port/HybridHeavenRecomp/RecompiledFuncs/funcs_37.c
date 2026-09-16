#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M23_FUN_801c1a98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A98: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C1A9C: lbu         $t6, -0x3734($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3734);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1aa0(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1AA0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C1AA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C1AA8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C1AAC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C1AB0: bne         $t6, $at, L_801C1BCC
    if (ctx->r14 != ctx->r1) {
        // 0x801C1AB4: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_801C1BCC;
    }
    // 0x801C1AB4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801C1AB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C1ABC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C1AC0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801C1AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C1AC8: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x801C1ACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C1AD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C1AD4: lui         $at, 0x422A
    ctx->r1 = S32(0X422A << 16);
    // 0x801C1AD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C1ADC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C1AE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C1AE4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1AE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C1AEC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C1AF0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C1AF4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801C1AF8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801C1AFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C1B00: addiu       $a0, $a0, -0x13CC
    ctx->r4 = ADD32(ctx->r4, -0X13CC);
    // 0x801C1B04: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    // 0x801C1B08: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801C1B0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C1B10: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C1B14: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C1B18: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C1B1C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801C1B20: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801C1B24: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C1B28: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801C1B2C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801C1B30: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801C1B34: jal         0x8011AAF4
    // 0x801C1B38: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801C1B38: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801C1B3C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C1B40: lw          $t0, -0x374C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X374C);
    // 0x801C1B44: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C1B48: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C1B4C: bne         $t0, $zero, L_801C1B64
    if (ctx->r8 != 0) {
        // 0x801C1B50: nop
    
            goto L_801C1B64;
    }
    // 0x801C1B50: nop

    // 0x801C1B54: jal         0x80005670
    // 0x801C1B58: addiu       $a1, $a1, -0x3608
    ctx->r5 = ADD32(ctx->r5, -0X3608);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801C1B58: addiu       $a1, $a1, -0x3608
    ctx->r5 = ADD32(ctx->r5, -0X3608);
    after_1:
    // 0x801C1B5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1B60: sw          $v0, -0x374C($at)
    MEM_W(-0X374C, ctx->r1) = ctx->r2;
L_801C1B64:
    // 0x801C1B64: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C1B68: lw          $t1, -0x3748($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3748);
    // 0x801C1B6C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C1B70: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C1B74: bne         $t1, $zero, L_801C1B8C
    if (ctx->r9 != 0) {
        // 0x801C1B78: nop
    
            goto L_801C1B8C;
    }
    // 0x801C1B78: nop

    // 0x801C1B7C: jal         0x80005670
    // 0x801C1B80: addiu       $a1, $a1, -0x35E0
    ctx->r5 = ADD32(ctx->r5, -0X35E0);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801C1B80: addiu       $a1, $a1, -0x35E0
    ctx->r5 = ADD32(ctx->r5, -0X35E0);
    after_2:
    // 0x801C1B84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1B88: sw          $v0, -0x3748($at)
    MEM_W(-0X3748, ctx->r1) = ctx->r2;
L_801C1B8C:
    // 0x801C1B8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1B90: lw          $a0, -0x3754($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3754);
    // 0x801C1B94: beq         $a0, $zero, L_801C1BA4
    if (ctx->r4 == 0) {
        // 0x801C1B98: nop
    
            goto L_801C1BA4;
    }
    // 0x801C1B98: nop

    // 0x801C1B9C: jal         0x80005700
    // 0x801C1BA0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C1BA0: nop

    after_3:
L_801C1BA4:
    // 0x801C1BA4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1BA8: lw          $a0, -0x3750($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3750);
    // 0x801C1BAC: beq         $a0, $zero, L_801C1BBC
    if (ctx->r4 == 0) {
        // 0x801C1BB0: nop
    
            goto L_801C1BBC;
    }
    // 0x801C1BB0: nop

    // 0x801C1BB4: jal         0x80005700
    // 0x801C1BB8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C1BB8: nop

    after_4:
L_801C1BBC:
    // 0x801C1BBC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1BC0: addiu       $a1, $a1, 0x1BDC
    ctx->r5 = ADD32(ctx->r5, 0X1BDC);
    // 0x801C1BC4: jal         0x800058DC
    // 0x801C1BC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C1BC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
L_801C1BCC:
    // 0x801C1BCC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C1BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801C1BD4: jr          $ra
    // 0x801C1BD8: nop

    return;
    // 0x801C1BD8: nop

;}
RECOMP_FUNC void M23_FUN_801c1bdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C1BE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1BEC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1BF0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1BF4: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    // 0x801C1BF8: jal         0x800058DC
    // 0x801C1BFC: addiu       $a1, $a1, 0x28E4
    ctx->r5 = ADD32(ctx->r5, 0X28E4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1BFC: addiu       $a1, $a1, 0x28E4
    ctx->r5 = ADD32(ctx->r5, 0X28E4);
    after_0:
    // 0x801C1C00: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C1C04: lw          $a0, -0x2F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2F8);
    // 0x801C1C08: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801C1C0C: jal         0x801C1040
    // 0x801C1C10: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801C1040)(rdram, ctx);
        goto after_1;
    // 0x801C1C10: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x801C1C14: jal         0x801C125C
    // 0x801C1C18: addiu       $a0, $zero, -0x64
    ctx->r4 = ADD32(0, -0X64);
    LOOKUP_FUNC(0x801C125C)(rdram, ctx);
        goto after_2;
    // 0x801C1C18: addiu       $a0, $zero, -0x64
    ctx->r4 = ADD32(0, -0X64);
    after_2:
    // 0x801C1C1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1C20: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1C24: sh          $zero, -0x3730($at)
    MEM_H(-0X3730, ctx->r1) = 0;
    // 0x801C1C28: addiu       $a1, $a1, 0x1C44
    ctx->r5 = ADD32(ctx->r5, 0X1C44);
    // 0x801C1C2C: jal         0x800058DC
    // 0x801C1C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C1C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801C1C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1C3C: jr          $ra
    // 0x801C1C40: nop

    return;
    // 0x801C1C40: nop

;}
RECOMP_FUNC void M23_FUN_801c1c44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1C44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C1C48: addiu       $v0, $v0, -0x3730
    ctx->r2 = ADD32(ctx->r2, -0X3730);
    // 0x801C1C4C: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1c50(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1C54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C1C58: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801C1C5C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801C1C60: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x801C1C64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C1C68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C1C6C: bne         $at, $zero, L_801C1D6C
    if (ctx->r1 != 0) {
        // 0x801C1C70: sh          $t7, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r15;
            goto L_801C1D6C;
    }
    // 0x801C1C70: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x801C1C74: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C1C78: lbu         $a2, -0x373C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X373C);
    // 0x801C1C7C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1C80: addiu       $a3, $a3, -0x1394
    ctx->r7 = ADD32(ctx->r7, -0X1394);
    // 0x801C1C84: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C1C88: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C1C8C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C1C90: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C1C94: addiu       $a2, $a2, 0x76
    ctx->r6 = ADD32(ctx->r6, 0X76);
    // 0x801C1C98: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C1C9C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C1CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C1CA4: jal         0x8001B204
    // 0x801C1CA8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C1CA8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_0:
    // 0x801C1CAC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1CB0: addiu       $a3, $a3, -0x1384
    ctx->r7 = ADD32(ctx->r7, -0X1384);
    // 0x801C1CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C1CB8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1CBC: jal         0x8001B204
    // 0x801C1CC0: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C1CC0: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_1:
    // 0x801C1CC4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1CC8: addiu       $a3, $a3, -0x1374
    ctx->r7 = ADD32(ctx->r7, -0X1374);
    // 0x801C1CCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C1CD0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1CD4: jal         0x8001B204
    // 0x801C1CD8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C1CD8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x801C1CDC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1CE0: addiu       $a3, $a3, -0x1364
    ctx->r7 = ADD32(ctx->r7, -0X1364);
    // 0x801C1CE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C1CE8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1CEC: jal         0x8001B204
    // 0x801C1CF0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C1CF0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_3:
    // 0x801C1CF4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1CF8: addiu       $a3, $a3, -0x1354
    ctx->r7 = ADD32(ctx->r7, -0X1354);
    // 0x801C1CFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C1D00: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1D04: jal         0x8001B204
    // 0x801C1D08: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C1D08: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_4:
    // 0x801C1D0C: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x801C1D10: lhu         $t9, 0x7754($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7754);
    // 0x801C1D14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C1D18: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C1D1C: bne         $t9, $at, L_801C1D44
    if (ctx->r25 != ctx->r1) {
        // 0x801C1D20: addiu       $a1, $zero, 0x7D0
        ctx->r5 = ADD32(0, 0X7D0);
            goto L_801C1D44;
    }
    // 0x801C1D20: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1D24: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1D28: addiu       $a3, $a3, -0x1344
    ctx->r7 = ADD32(ctx->r7, -0X1344);
    // 0x801C1D2C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C1D30: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C1D34: jal         0x8001B204
    // 0x801C1D38: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C1D38: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_5:
    // 0x801C1D3C: b           L_801C1D5C
    // 0x801C1D40: nop

        goto L_801C1D5C;
    // 0x801C1D40: nop

L_801C1D44:
    // 0x801C1D44: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1D48: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801C1D4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C1D50: addiu       $a3, $a3, -0x1334
    ctx->r7 = ADD32(ctx->r7, -0X1334);
    // 0x801C1D54: jal         0x8001B204
    // 0x801C1D58: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C1D58: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_6:
L_801C1D5C:
    // 0x801C1D5C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1D60: addiu       $a1, $a1, 0x1D7C
    ctx->r5 = ADD32(ctx->r5, 0X1D7C);
    // 0x801C1D64: jal         0x800058DC
    // 0x801C1D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C1D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
L_801C1D6C:
    // 0x801C1D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1D74: jr          $ra
    // 0x801C1D78: nop

    return;
    // 0x801C1D78: nop

;}
RECOMP_FUNC void M23_FUN_801c1d7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D7C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C1D80: lbu         $t6, -0x3734($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3734);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1d84(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1d84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1D8C: bne         $t6, $zero, L_801C1DA8
    if (ctx->r14 != 0) {
        // 0x801C1D90: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C1DA8;
    }
    // 0x801C1D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C1D94: addiu       $t7, $zero, 0x384
    ctx->r15 = ADD32(0, 0X384);
    // 0x801C1D98: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1D9C: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C1DA0: jal         0x800058DC
    // 0x801C1DA4: addiu       $a1, $a1, 0x1DB8
    ctx->r5 = ADD32(ctx->r5, 0X1DB8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C1DA4: addiu       $a1, $a1, 0x1DB8
    ctx->r5 = ADD32(ctx->r5, 0X1DB8);
    after_0:
L_801C1DA8:
    // 0x801C1DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1DB0: jr          $ra
    // 0x801C1DB4: nop

    return;
    // 0x801C1DB4: nop

;}
RECOMP_FUNC void M23_FUN_801c1db8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1DB8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C1DBC: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c1dc0(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c1dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1DC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C1DC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C1DCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C1DD0: bne         $t6, $zero, L_801C203C
    if (ctx->r14 != 0) {
        // 0x801C1DD4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801C203C;
    }
    // 0x801C1DD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C1DD8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801C1DDC: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x801C1DE0: lhu         $t7, 0x1C6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1C6);
    // 0x801C1DE4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801C1DE8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x801C1DEC: bne         $v0, $t8, L_801C1E28
    if (ctx->r2 != ctx->r24) {
        // 0x801C1DF0: nop
    
            goto L_801C1E28;
    }
    // 0x801C1DF0: nop

    // 0x801C1DF4: lhu         $t9, 0x1E6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1E6);
    // 0x801C1DF8: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x801C1DFC: bne         $v0, $t0, L_801C1E28
    if (ctx->r2 != ctx->r8) {
        // 0x801C1E00: nop
    
            goto L_801C1E28;
    }
    // 0x801C1E00: nop

    // 0x801C1E04: lhu         $t1, 0x206($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X206);
    // 0x801C1E08: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801C1E0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801C1E10: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x801C1E14: bne         $v0, $t2, L_801C1E28
    if (ctx->r2 != ctx->r10) {
        // 0x801C1E18: addiu       $a2, $zero, 0x14
        ctx->r6 = ADD32(0, 0X14);
            goto L_801C1E28;
    }
    // 0x801C1E18: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801C1E1C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1E20: jal         0x8001B204
    // 0x801C1E24: addiu       $a3, $a3, -0x1314
    ctx->r7 = ADD32(ctx->r7, -0X1314);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C1E24: addiu       $a3, $a3, -0x1314
    ctx->r7 = ADD32(ctx->r7, -0X1314);
    after_0:
L_801C1E28:
    // 0x801C1E28: jal         0x801C1340
    // 0x801C1E2C: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C1E2C: nop

    after_1:
    // 0x801C1E30: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x801C1E34: beq         $t3, $zero, L_801C1E68
    if (ctx->r11 == 0) {
        // 0x801C1E38: lui         $s0, 0x801D
        ctx->r16 = S32(0X801D << 16);
            goto L_801C1E68;
    }
    // 0x801C1E38: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C1E3C: addiu       $s0, $s0, -0x373C
    ctx->r16 = ADD32(ctx->r16, -0X373C);
    // 0x801C1E40: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x801C1E44: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801C1E48: bne         $v0, $zero, L_801C1E58
    if (ctx->r2 != 0) {
        // 0x801C1E4C: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_801C1E58;
    }
    // 0x801C1E4C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x801C1E50: b           L_801C1E5C
    // 0x801C1E54: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_801C1E5C;
    // 0x801C1E54: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_801C1E58:
    // 0x801C1E58: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_801C1E5C:
    // 0x801C1E5C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801C1E60: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x801C1E64: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
L_801C1E68:
    // 0x801C1E68: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C1E6C: jal         0x801C1340
    // 0x801C1E70: addiu       $s0, $s0, -0x373C
    ctx->r16 = ADD32(ctx->r16, -0X373C);
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_2;
    // 0x801C1E70: addiu       $s0, $s0, -0x373C
    ctx->r16 = ADD32(ctx->r16, -0X373C);
    after_2:
    // 0x801C1E74: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x801C1E78: beq         $t8, $zero, L_801C1EA8
    if (ctx->r24 == 0) {
        // 0x801C1E7C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C1EA8;
    }
    // 0x801C1E7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C1E80: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x801C1E84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C1E88: bne         $v0, $at, L_801C1E98
    if (ctx->r2 != ctx->r1) {
        // 0x801C1E8C: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_801C1E98;
    }
    // 0x801C1E8C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801C1E90: b           L_801C1E9C
    // 0x801C1E94: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_801C1E9C;
    // 0x801C1E94: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_801C1E98:
    // 0x801C1E98: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_801C1E9C:
    // 0x801C1E9C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801C1EA0: addiu       $t0, $zero, 0x384
    ctx->r8 = ADD32(0, 0X384);
    // 0x801C1EA4: sh          $t0, 0x3C($t1)
    MEM_H(0X3C, ctx->r9) = ctx->r8;
L_801C1EA8:
    // 0x801C1EA8: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x801C1EAC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1EB0: addiu       $a3, $a3, -0x1304
    ctx->r7 = ADD32(ctx->r7, -0X1304);
    // 0x801C1EB4: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C1EB8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C1EBC: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C1EC0: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C1EC4: addiu       $a2, $a2, 0x76
    ctx->r6 = ADD32(ctx->r6, 0X76);
    // 0x801C1EC8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C1ECC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C1ED0: jal         0x8001B204
    // 0x801C1ED4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C1ED4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_3:
    // 0x801C1ED8: jal         0x801C1334
    // 0x801C1EDC: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_4;
    // 0x801C1EDC: nop

    after_4:
    // 0x801C1EE0: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C1EE4: beql        $t2, $zero, L_801C2008
    if (ctx->r10 == 0) {
        // 0x801C1EE8: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_801C2008;
    }
    goto skip_0;
    // 0x801C1EE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x801C1EEC: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x801C1EF0: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x801C1EF4: beq         $at, $zero, L_801C2000
    if (ctx->r1 == 0) {
        // 0x801C1EF8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801C2000;
    }
    // 0x801C1EF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801C1EFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C1F00: addu        $at, $at, $t3
    gpr jr_addend_801C1F08 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801C1F04: lw          $t3, -0xD9C($at)
    ctx->r11 = ADD32(ctx->r1, -0XD9C);
    // 0x801C1F08: jr          $t3
    // 0x801C1F0C: nop

    switch (jr_addend_801C1F08 >> 2) {
        case 0: goto L_801C1F10; break;
        case 1: goto L_801C1F30; break;
        case 2: goto L_801C1F58; break;
        case 3: goto L_801C1F70; break;
        case 4: goto L_801C1F88; break;
        case 5: goto L_801C1FB4; break;
        default: switch_error(__func__, 0x801C1F08, 0x801CF264);
    }
    // 0x801C1F0C: nop

L_801C1F10:
    // 0x801C1F10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C1F14: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F18: sb          $zero, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = 0;
    // 0x801C1F1C: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    // 0x801C1F20: jal         0x800058DC
    // 0x801C1F24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C1F24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x801C1F28: b           L_801C2008
    // 0x801C1F2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1F2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C1F30:
    // 0x801C1F30: jal         0x800023A8
    // 0x801C1F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_6;
    // 0x801C1F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801C1F38: jal         0x80020718
    // 0x801C1F3C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_7;
    // 0x801C1F3C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_7:
    // 0x801C1F40: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F44: addiu       $a1, $a1, 0x3CDC
    ctx->r5 = ADD32(ctx->r5, 0X3CDC);
    // 0x801C1F48: jal         0x800058DC
    // 0x801C1F4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C1F4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x801C1F50: b           L_801C2008
    // 0x801C1F54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1F54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C1F58:
    // 0x801C1F58: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F5C: addiu       $a1, $a1, 0x40F8
    ctx->r5 = ADD32(ctx->r5, 0X40F8);
    // 0x801C1F60: jal         0x800058DC
    // 0x801C1F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C1F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x801C1F68: b           L_801C2008
    // 0x801C1F6C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1F6C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C1F70:
    // 0x801C1F70: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F74: addiu       $a1, $a1, 0x4960
    ctx->r5 = ADD32(ctx->r5, 0X4960);
    // 0x801C1F78: jal         0x800058DC
    // 0x801C1F7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C1F7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x801C1F80: b           L_801C2008
    // 0x801C1F84: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1F84: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C1F88:
    // 0x801C1F88: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x801C1F8C: lhu         $t4, 0x7754($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7754);
    // 0x801C1F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C1F94: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1F98: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x801C1F9C: beql        $t5, $zero, L_801C2008
    if (ctx->r13 == 0) {
        // 0x801C1FA0: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_801C2008;
    }
    goto skip_1;
    // 0x801C1FA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x801C1FA4: jal         0x800058DC
    // 0x801C1FA8: addiu       $a1, $a1, 0x5108
    ctx->r5 = ADD32(ctx->r5, 0X5108);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801C1FA8: addiu       $a1, $a1, 0x5108
    ctx->r5 = ADD32(ctx->r5, 0X5108);
    after_11:
    // 0x801C1FAC: b           L_801C2008
    // 0x801C1FB0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1FB0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C1FB4:
    // 0x801C1FB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801C1FB8:
    // 0x801C1FB8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C1FBC: addiu       $a3, $a3, -0x12F4
    ctx->r7 = ADD32(ctx->r7, -0X12F4);
    // 0x801C1FC0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801C1FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C1FC8: jal         0x8001B204
    // 0x801C1FCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801C1FCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x801C1FD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C1FD4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801C1FD8: bne         $s0, $at, L_801C1FB8
    if (ctx->r16 != ctx->r1) {
        // 0x801C1FDC: nop
    
            goto L_801C1FB8;
    }
    // 0x801C1FDC: nop

    // 0x801C1FE0: jal         0x801BF1A0
    // 0x801C1FE4: nop

    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_13;
    // 0x801C1FE4: nop

    after_13:
    // 0x801C1FE8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C1FEC: addiu       $a1, $a1, 0x2050
    ctx->r5 = ADD32(ctx->r5, 0X2050);
    // 0x801C1FF0: jal         0x800058DC
    // 0x801C1FF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x801C1FF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x801C1FF8: b           L_801C2008
    // 0x801C1FFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
        goto L_801C2008;
    // 0x801C1FFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C2000:
    // 0x801C2000: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x801C2004: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801C2008:
    // 0x801C2008: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801C200C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C2010: lhu         $v0, 0x3C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X3C);
    // 0x801C2014: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801C2018: bne         $v0, $zero, L_801C203C
    if (ctx->r2 != 0) {
        // 0x801C201C: sh          $t6, 0x3C($a1)
        MEM_H(0X3C, ctx->r5) = ctx->r14;
            goto L_801C203C;
    }
    // 0x801C201C: sh          $t6, 0x3C($a1)
    MEM_H(0X3C, ctx->r5) = ctx->r14;
    // 0x801C2020: jal         0x80020718
    // 0x801C2024: addiu       $s0, $s0, 0x2050
    ctx->r16 = ADD32(ctx->r16, 0X2050);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_15;
    // 0x801C2024: addiu       $s0, $s0, 0x2050
    ctx->r16 = ADD32(ctx->r16, 0X2050);
    after_15:
    // 0x801C2028: jal         0x801C5A00
    // 0x801C202C: nop

    LOOKUP_FUNC(0x801C5A00)(rdram, ctx);
        goto after_16;
    // 0x801C202C: nop

    after_16:
    // 0x801C2030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C2034: jal         0x800058DC
    // 0x801C2038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x801C2038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
L_801C203C:
    // 0x801C203C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2040: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C2048: jr          $ra
    // 0x801C204C: nop

    return;
    // 0x801C204C: nop

;}
RECOMP_FUNC void M23_FUN_801c2050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2050: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C2054: jr          $ra
    // 0x801C2058: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C2058: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c205c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c205c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C205C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801C2060: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C2064: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801C2068: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801C206C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C2070: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801C2074: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801C2078: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801C207C: jal         0x80006214
    // 0x801C2080: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C2080: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x801C2084: andi        $s3, $v0, 0xFF
    ctx->r19 = ctx->r2 & 0XFF;
    // 0x801C2088: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C208C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C2090: addiu       $s1, $sp, 0x5B
    ctx->r17 = ADD32(ctx->r29, 0X5B);
L_801C2094:
    // 0x801C2094: sll         $a3, $v1, 6
    ctx->r7 = S32(ctx->r3 << 6);
    // 0x801C2098: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801C209C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C20A0: addiu       $t6, $zero, 0xBC
    ctx->r14 = ADD32(0, 0XBC);
    // 0x801C20A4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801C20A8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801C20AC: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801C20B0: addiu       $t0, $v1, 0x15
    ctx->r8 = ADD32(ctx->r3, 0X15);
    // 0x801C20B4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801C20B8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801C20BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C20C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C20C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C20C8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C20CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C20D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C20D4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C20D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C20DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C20E0: jal         0x80146208
    // 0x801C20E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x801C20E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_1:
    // 0x801C20E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C20EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C20F0: jal         0x80145348
    // 0x801C20F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x801C20F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801C20F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C20FC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C2100: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801C2104: bne         $at, $zero, L_801C2094
    if (ctx->r1 != 0) {
        // 0x801C2108: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_801C2094;
    }
    // 0x801C2108: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C210C: sll         $a3, $v1, 6
    ctx->r7 = S32(ctx->r3 << 6);
    // 0x801C2110: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801C2114: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C2118: addiu       $t1, $zero, 0xBC
    ctx->r9 = ADD32(0, 0XBC);
    // 0x801C211C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801C2120: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801C2124: addiu       $t4, $zero, 0x228
    ctx->r12 = ADD32(0, 0X228);
    // 0x801C2128: addiu       $t5, $v1, 0x15
    ctx->r13 = ADD32(ctx->r3, 0X15);
    // 0x801C212C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801C2130: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801C2134: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801C2138: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801C213C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C2140: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C2144: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2148: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C214C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C2150: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C2154: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C2158: jal         0x80146208
    // 0x801C215C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x801C215C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_3:
    // 0x801C2160: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C2168: jal         0x80145348
    // 0x801C216C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x801C216C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801C2170: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x801C2174: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x801C2178: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801C217C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2180: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2184: jal         0x80006214
    // 0x801C2188: sw          $t8, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801C2188: sw          $t8, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r24;
    after_5:
    // 0x801C218C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x801C2190: andi        $s3, $v0, 0xFF
    ctx->r19 = ctx->r2 & 0XFF;
    // 0x801C2194: blez        $t9, L_801C21D8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x801C2198: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801C21D8;
    }
    // 0x801C2198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C219C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x801C21A0: addiu       $s3, $zero, 0x100
    ctx->r19 = ADD32(0, 0X100);
    // 0x801C21A4: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
L_801C21A8:
    // 0x801C21A8: addu        $v0, $s4, $t0
    ctx->r2 = ADD32(ctx->r20, ctx->r8);
    // 0x801C21AC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C21B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C21B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C21B8: sh          $s3, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r19;
    // 0x801C21BC: jal         0x801C1040
    // 0x801C21C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    LOOKUP_FUNC(0x801C1040)(rdram, ctx);
        goto after_6;
    // 0x801C21C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_6:
    // 0x801C21C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C21C8: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C21CC: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x801C21D0: bnel        $at, $zero, L_801C21A8
    if (ctx->r1 != 0) {
        // 0x801C21D4: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_801C21A8;
    }
    goto skip_0;
    // 0x801C21D4: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    skip_0:
L_801C21D8:
    // 0x801C21D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C21DC: sh          $zero, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = 0;
    // 0x801C21E0: addiu       $a1, $a1, 0x220C
    ctx->r5 = ADD32(ctx->r5, 0X220C);
    // 0x801C21E4: jal         0x800058DC
    // 0x801C21E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C21E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x801C21EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C21F0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801C21F4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801C21F8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801C21FC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801C2200: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801C2204: jr          $ra
    // 0x801C2208: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801C2208: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c220c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c220c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C220C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2210: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C2214: lw          $a3, -0x2F8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2F8);
    // 0x801C2218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C221C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2220: lhu         $v1, 0x3C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C2224: lw          $t6, 0x30($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X30);
    // 0x801C2228: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x801C222C: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x801C2230: bne         $at, $zero, L_801C2268
    if (ctx->r1 != 0) {
        // 0x801C2234: lbu         $v0, 0xB($t6)
        ctx->r2 = MEM_BU(ctx->r14, 0XB);
            goto L_801C2268;
    }
    // 0x801C2234: lbu         $v0, 0xB($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XB);
    // 0x801C2238: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x801C223C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C2240: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801C2244: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801C2248: bne         $at, $zero, L_801C2254
    if (ctx->r1 != 0) {
        // 0x801C224C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801C2254;
    }
    // 0x801C224C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801C2250: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_801C2254:
    // 0x801C2254: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x801C2258: jal         0x801C1040
    // 0x801C225C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    LOOKUP_FUNC(0x801C1040)(rdram, ctx);
        goto after_0;
    // 0x801C225C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_0:
    // 0x801C2260: b           L_801C2274
    // 0x801C2264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C2274;
    // 0x801C2264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2268:
    // 0x801C2268: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x801C226C: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C2270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2274:
    // 0x801C2274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2278: jr          $ra
    // 0x801C227C: nop

    return;
    // 0x801C227C: nop

;}
RECOMP_FUNC void M23_FUN_801c2280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2280: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801C2284: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C2288: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x801C228C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801C2290: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C2294: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x801C2298: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x801C229C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801C22A0: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801C22A4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801C22A8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801C22AC: jal         0x80006214
    // 0x801C22B0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C22B0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_0:
    // 0x801C22B4: andi        $s6, $v0, 0xFF
    ctx->r22 = ctx->r2 & 0XFF;
    // 0x801C22B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801C22BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C22C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C22C4: addiu       $s5, $sp, 0x6F
    ctx->r21 = ADD32(ctx->r29, 0X6F);
L_801C22C8:
    // 0x801C22C8: sll         $s2, $v1, 5
    ctx->r18 = S32(ctx->r3 << 5);
    // 0x801C22CC: addiu       $s2, $s2, 0x38
    ctx->r18 = ADD32(ctx->r18, 0X38);
    // 0x801C22D0: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801C22D4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801C22D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C22DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C22E0:
    // 0x801C22E0: sll         $a3, $v0, 6
    ctx->r7 = S32(ctx->r2 << 6);
    // 0x801C22E4: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801C22E8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C22EC: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x801C22F0: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801C22F4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801C22F8: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801C22FC: addiu       $t0, $s1, 0x9
    ctx->r8 = ADD32(ctx->r17, 0X9);
    // 0x801C2300: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801C2304: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801C2308: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x801C230C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801C2310: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801C2314: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C2318: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C231C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801C2320: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C2324: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x801C2328: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C232C: jal         0x80146208
    // 0x801C2330: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x801C2330: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x801C2334: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C2338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C233C: jal         0x80145348
    // 0x801C2340: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x801C2340: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_2:
    // 0x801C2344: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C2348: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C234C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801C2350: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C2354: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801C2358: bne         $at, $zero, L_801C22E0
    if (ctx->r1 != 0) {
        // 0x801C235C: andi        $s1, $s1, 0xFF
        ctx->r17 = ctx->r17 & 0XFF;
            goto L_801C22E0;
    }
    // 0x801C235C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C2360: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x801C2364: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x801C2368: slti        $at, $s4, 0x3
    ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x801C236C: bne         $at, $zero, L_801C22C8
    if (ctx->r1 != 0) {
        // 0x801C2370: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_801C22C8;
    }
    // 0x801C2370: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x801C2374: sll         $t1, $s6, 2
    ctx->r9 = S32(ctx->r22 << 2);
    // 0x801C2378: addu        $t2, $s7, $t1
    ctx->r10 = ADD32(ctx->r23, ctx->r9);
    // 0x801C237C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C2380: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2384: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C2388: jal         0x80006214
    // 0x801C238C: sw          $t3, -0x300($at)
    MEM_W(-0X300, ctx->r1) = ctx->r11;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801C238C: sw          $t3, -0x300($at)
    MEM_W(-0X300, ctx->r1) = ctx->r11;
    after_3:
    // 0x801C2390: andi        $s6, $v0, 0xFF
    ctx->r22 = ctx->r2 & 0XFF;
    // 0x801C2394: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801C2398: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801C239C:
    // 0x801C239C: sll         $a3, $v1, 5
    ctx->r7 = S32(ctx->r3 << 5);
    // 0x801C23A0: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801C23A4: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C23A8: addiu       $t4, $zero, 0x48
    ctx->r12 = ADD32(0, 0X48);
    // 0x801C23AC: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x801C23B0: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x801C23B4: addiu       $t7, $zero, 0x228
    ctx->r15 = ADD32(0, 0X228);
    // 0x801C23B8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801C23BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801C23C0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801C23C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C23C8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C23CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C23D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801C23D4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C23D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C23DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C23E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C23E4: jal         0x80146208
    // 0x801C23E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801C23E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x801C23EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C23F0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801C23F4: jal         0x80145348
    // 0x801C23F8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_5;
    // 0x801C23F8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_5:
    // 0x801C23FC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x801C2400: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x801C2404: slti        $at, $s4, 0x8
    ctx->r1 = SIGNED(ctx->r20) < 0X8 ? 1 : 0;
    // 0x801C2408: bne         $at, $zero, L_801C239C
    if (ctx->r1 != 0) {
        // 0x801C240C: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_801C239C;
    }
    // 0x801C240C: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x801C2410: sll         $a3, $v1, 5
    ctx->r7 = S32(ctx->r3 << 5);
    // 0x801C2414: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801C2418: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C241C: addiu       $t8, $zero, 0x48
    ctx->r24 = ADD32(0, 0X48);
    // 0x801C2420: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801C2424: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x801C2428: addiu       $t1, $zero, 0x228
    ctx->r9 = ADD32(0, 0X228);
    // 0x801C242C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801C2430: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801C2434: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801C2438: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C243C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C2440: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C2444: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801C2448: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C244C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C2450: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C2454: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C2458: jal         0x80146208
    // 0x801C245C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x801C245C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x801C2460: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C2464: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801C2468: jal         0x80145348
    // 0x801C246C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_7;
    // 0x801C246C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_7:
    // 0x801C2470: sll         $t2, $s6, 2
    ctx->r10 = S32(ctx->r22 << 2);
    // 0x801C2474: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x801C2478: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C247C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C2484: jal         0x80006214
    // 0x801C2488: sw          $t4, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_8;
    // 0x801C2488: sw          $t4, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r12;
    after_8:
    // 0x801C248C: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x801C2490: andi        $s6, $v0, 0xFF
    ctx->r22 = ctx->r2 & 0XFF;
    // 0x801C2494: blez        $t5, L_801C24D8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x801C2498: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_801C24D8;
    }
    // 0x801C2498: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801C249C: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x801C24A0: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
    // 0x801C24A4: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
L_801C24A8:
    // 0x801C24A8: addu        $v0, $s7, $t6
    ctx->r2 = ADD32(ctx->r23, ctx->r14);
    // 0x801C24AC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C24B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C24B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C24B8: sh          $s1, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r17;
    // 0x801C24BC: jal         0x801C1040
    // 0x801C24C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    LOOKUP_FUNC(0x801C1040)(rdram, ctx);
        goto after_9;
    // 0x801C24C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_9:
    // 0x801C24C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x801C24C8: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x801C24CC: slt         $at, $s4, $s0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x801C24D0: bnel        $at, $zero, L_801C24A8
    if (ctx->r1 != 0) {
        // 0x801C24D4: sll         $t6, $s4, 2
        ctx->r14 = S32(ctx->r20 << 2);
            goto L_801C24A8;
    }
    goto skip_0;
    // 0x801C24D4: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    skip_0:
L_801C24D8:
    // 0x801C24D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C24DC: sh          $zero, 0x3C($s3)
    MEM_H(0X3C, ctx->r19) = 0;
    // 0x801C24E0: addiu       $a1, $a1, 0x2518
    ctx->r5 = ADD32(ctx->r5, 0X2518);
    // 0x801C24E4: jal         0x800058DC
    // 0x801C24E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C24E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x801C24EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C24F0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801C24F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801C24F8: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x801C24FC: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x801C2500: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x801C2504: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x801C2508: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x801C250C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x801C2510: jr          $ra
    // 0x801C2514: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801C2514: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2518(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C251C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C2520: lw          $a3, -0x2FC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2FC);
    // 0x801C2524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2528: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C252C: lhu         $v1, 0x3C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C2530: lw          $t6, 0x30($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X30);
    // 0x801C2534: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x801C2538: slti        $at, $v1, 0xB5
    ctx->r1 = SIGNED(ctx->r3) < 0XB5 ? 1 : 0;
    // 0x801C253C: bne         $at, $zero, L_801C2574
    if (ctx->r1 != 0) {
        // 0x801C2540: lbu         $v0, 0xB($t6)
        ctx->r2 = MEM_BU(ctx->r14, 0XB);
            goto L_801C2574;
    }
    // 0x801C2540: lbu         $v0, 0xB($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XB);
    // 0x801C2544: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x801C2548: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C254C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801C2550: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801C2554: bne         $at, $zero, L_801C2560
    if (ctx->r1 != 0) {
        // 0x801C2558: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801C2560;
    }
    // 0x801C2558: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801C255C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_801C2560:
    // 0x801C2560: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x801C2564: jal         0x801C1040
    // 0x801C2568: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    LOOKUP_FUNC(0x801C1040)(rdram, ctx);
        goto after_0;
    // 0x801C2568: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_0:
    // 0x801C256C: b           L_801C2580
    // 0x801C2570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C2580;
    // 0x801C2570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2574:
    // 0x801C2574: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x801C2578: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C257C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C2580:
    // 0x801C2580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2584: jr          $ra
    // 0x801C2588: nop

    return;
    // 0x801C2588: nop

;}
RECOMP_FUNC void M23_FUN_801c258c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C258C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C2590: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C2594: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C2598: lw          $s0, -0x2FC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2FC);
    // 0x801C259C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801C25A0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C25A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C25A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801C25AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C25B0: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x801C25B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C25B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801C25BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C25C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C25C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C25C8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801C25CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C25D0: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x801C25D4: jal         0x801453CC
    // 0x801C25D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x801C25D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C25DC: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C25E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C25E4:
    // 0x801C25E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C25E8: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x801C25EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C25F0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801C25F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C25F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C25FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C2608: jal         0x801453CC
    // 0x801C260C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_1;
    // 0x801C260C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_1:
    // 0x801C2610: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C2614: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C2618: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x801C261C: bne         $at, $zero, L_801C25E4
    if (ctx->r1 != 0) {
        // 0x801C2620: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801C25E4;
    }
    // 0x801C2620: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C2624: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C2628: lw          $a0, -0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X300);
    // 0x801C262C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x801C2630: jal         0x801C10DC
    // 0x801C2634: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x801C10DC)(rdram, ctx);
        goto after_2;
    // 0x801C2634: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x801C2638: lhu         $t2, 0x3C($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X3C);
    // 0x801C263C: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    // 0x801C2640: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801C2644: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801C2648: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x801C264C: bne         $at, $zero, L_801C266C
    if (ctx->r1 != 0) {
        // 0x801C2650: sh          $t3, 0x3C($s2)
        MEM_H(0X3C, ctx->r18) = ctx->r11;
            goto L_801C266C;
    }
    // 0x801C2650: sh          $t3, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r11;
    // 0x801C2654: jal         0x80145390
    // 0x801C2658: sh          $zero, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = 0;
    LOOKUP_FUNC(0x80145390)(rdram, ctx);
        goto after_3;
    // 0x801C2658: sh          $zero, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = 0;
    after_3:
    // 0x801C265C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2660: addiu       $a1, $a1, 0x2684
    ctx->r5 = ADD32(ctx->r5, 0X2684);
    // 0x801C2664: jal         0x800058DC
    // 0x801C2668: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2668: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_801C266C:
    // 0x801C266C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C2670: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C2674: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2678: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801C267C: jr          $ra
    // 0x801C2680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C2680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2684(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2684: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C2688: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C268C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C2690: lw          $s0, -0x2FC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2FC);
    // 0x801C2694: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C2698: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801C269C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C26A0: addiu       $t6, $zero, 0x1D
    ctx->r14 = ADD32(0, 0X1D);
    // 0x801C26A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C26A8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801C26AC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C26B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C26B4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C26B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C26BC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801C26C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C26C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C26C8: jal         0x801453CC
    // 0x801C26CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x801C26CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C26D0: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C26D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C26D8:
    // 0x801C26D8: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x801C26DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C26E0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x801C26E4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801C26E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C26EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C26F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C26F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C26F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C26FC: jal         0x801453CC
    // 0x801C2700: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_1;
    // 0x801C2700: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801C2704: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C2708: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C270C: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x801C2710: bne         $at, $zero, L_801C26D8
    if (ctx->r1 != 0) {
        // 0x801C2714: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801C26D8;
    }
    // 0x801C2714: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C2718: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C271C: lw          $s0, -0x300($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X300);
    // 0x801C2720: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x801C2724: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x801C2728: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x801C272C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C2730: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C2734: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C2738: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801C273C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C2740: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C2744: jal         0x801453CC
    // 0x801C2748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_2;
    // 0x801C2748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801C274C: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C2750: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C2754:
    // 0x801C2754: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x801C2758: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x801C275C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x801C2760: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801C2764: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801C2768: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C276C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C2770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C2778: jal         0x801453CC
    // 0x801C277C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_3;
    // 0x801C277C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801C2780: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C2784: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C2788: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
    // 0x801C278C: bne         $at, $zero, L_801C2754
    if (ctx->r1 != 0) {
        // 0x801C2790: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801C2754;
    }
    // 0x801C2790: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C2794: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801C2798: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C279C: lhu         $t8, 0x3C($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C27A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801C27A4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801C27A8: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x801C27AC: bne         $at, $zero, L_801C27BC
    if (ctx->r1 != 0) {
        // 0x801C27B0: sh          $t9, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r25;
            goto L_801C27BC;
    }
    // 0x801C27B0: sh          $t9, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r25;
    // 0x801C27B4: jal         0x800058DC
    // 0x801C27B8: addiu       $a1, $a1, 0x27D0
    ctx->r5 = ADD32(ctx->r5, 0X27D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C27B8: addiu       $a1, $a1, 0x27D0
    ctx->r5 = ADD32(ctx->r5, 0X27D0);
    after_4:
L_801C27BC:
    // 0x801C27BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C27C0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C27C4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C27C8: jr          $ra
    // 0x801C27CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C27CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c27d0(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c27d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C27D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C27D4: jr          $ra
    // 0x801C27D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C27D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c27dc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c27dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C27DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C27E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C27E4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C27E8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801C27EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C27F0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C27F4: addiu       $a1, $a1, 0x28E4
    ctx->r5 = ADD32(ctx->r5, 0X28E4);
    // 0x801C27F8: lh          $a2, 0x2($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X2);
    // 0x801C27FC: slti        $at, $a2, 0x15
    ctx->r1 = SIGNED(ctx->r6) < 0X15 ? 1 : 0;
    // 0x801C2800: bne         $at, $zero, L_801C2814
    if (ctx->r1 != 0) {
        // 0x801C2804: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_801C2814;
    }
    // 0x801C2804: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x801C2808: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C280C: b           L_801C282C
    // 0x801C2810: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_801C282C;
    // 0x801C2810: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_801C2814:
    // 0x801C2814: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801C2818: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    // 0x801C281C: jal         0x800058DC
    // 0x801C2820: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C2820: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801C2824: lh          $a2, 0x1A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1A);
    // 0x801C2828: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_801C282C:
    // 0x801C282C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x801C2830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2834: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_801C2838:
    // 0x801C2838: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C283C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x801C2840: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x801C2844: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C2848: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801C284C: sh          $v1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r3;
    // 0x801C2850: lw          $t1, -0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, -0XC);
    // 0x801C2854: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C2858: sh          $v1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r3;
    // 0x801C285C: lw          $t3, -0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X8);
    // 0x801C2860: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C2864: sh          $v1, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r3;
    // 0x801C2868: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x801C286C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C2870: sh          $v1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r3;
    // 0x801C2874: bne         $at, $zero, L_801C2838
    if (ctx->r1 != 0) {
        // 0x801C2878: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_801C2838;
    }
    // 0x801C2878: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x801C287C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C2880: addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // 0x801C2884: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801C2888: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C288C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C2890: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801C2894: sh          $v1, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r3;
L_801C2898:
    // 0x801C2898: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C289C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801C28A0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801C28A4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C28A8: sh          $v1, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r3;
    // 0x801C28AC: lw          $t2, -0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, -0XC);
    // 0x801C28B0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C28B4: sh          $v1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r3;
    // 0x801C28B8: lw          $t4, -0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X8);
    // 0x801C28BC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C28C0: sh          $v1, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r3;
    // 0x801C28C4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x801C28C8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C28CC: bne         $a0, $a1, L_801C2898
    if (ctx->r4 != ctx->r5) {
        // 0x801C28D0: sh          $v1, 0x2($t7)
        MEM_H(0X2, ctx->r15) = ctx->r3;
            goto L_801C2898;
    }
    // 0x801C28D0: sh          $v1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r3;
    // 0x801C28D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C28D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C28DC: jr          $ra
    // 0x801C28E0: nop

    return;
    // 0x801C28E0: nop

;}
RECOMP_FUNC void M23_FUN_801c28e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C28E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C28E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C28EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801C28F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C28F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C28F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C28FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C2900: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x801C2904: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801C2908: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x801C290C: addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    // 0x801C2910: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x801C2914: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C2918:
    // 0x801C2918: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801C291C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2920: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x801C2924: lw          $t8, -0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X10);
    // 0x801C2928: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C292C: sh          $v1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r3;
    // 0x801C2930: lw          $t0, -0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, -0XC);
    // 0x801C2934: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2938: sh          $a1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r5;
    // 0x801C293C: lw          $t2, -0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, -0XC);
    // 0x801C2940: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C2944: sh          $v1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r3;
    // 0x801C2948: lw          $t4, -0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X8);
    // 0x801C294C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2950: sh          $a2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r6;
    // 0x801C2954: lw          $t6, -0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X8);
    // 0x801C2958: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C295C: sh          $v1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r3;
    // 0x801C2960: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x801C2964: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C2968: sh          $a3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r7;
    // 0x801C296C: lw          $t0, -0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X4);
    // 0x801C2970: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2974: sh          $v1, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r3;
    // 0x801C2978: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x801C297C: slti        $at, $v1, 0x74
    ctx->r1 = SIGNED(ctx->r3) < 0X74 ? 1 : 0;
    // 0x801C2980: bnel        $at, $zero, L_801C2918
    if (ctx->r1 != 0) {
        // 0x801C2984: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C2918;
    }
    goto skip_0;
    // 0x801C2984: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801C2988: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x801C298C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
L_801C2990:
    // 0x801C2990: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C2994: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801C2998: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C299C: sh          $v1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r3;
    // 0x801C29A0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x801C29A4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x801C29A8: slti        $at, $v1, 0x138
    ctx->r1 = SIGNED(ctx->r3) < 0X138 ? 1 : 0;
    // 0x801C29AC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C29B0: bne         $at, $zero, L_801C2990
    if (ctx->r1 != 0) {
        // 0x801C29B4: sh          $a0, 0x2($t5)
        MEM_H(0X2, ctx->r13) = ctx->r4;
            goto L_801C2990;
    }
    // 0x801C29B4: sh          $a0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r4;
    // 0x801C29B8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C29BC: lw          $s1, -0x2FC($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X2FC);
    // 0x801C29C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801C29C4:
    // 0x801C29C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C29C8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x801C29CC: jal         0x80145310
    // 0x801C29D0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x801C29D0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x801C29D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C29D8: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x801C29DC: bne         $at, $zero, L_801C29C4
    if (ctx->r1 != 0) {
        // 0x801C29E0: lw          $s1, 0x10($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X10);
            goto L_801C29C4;
    }
    // 0x801C29E0: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C29E4: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C29E8: lw          $s1, -0x300($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X300);
    // 0x801C29EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C29F0: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_801C29F4:
    // 0x801C29F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C29F8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x801C29FC: jal         0x80145310
    // 0x801C2A00: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x801C2A00: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x801C2A04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C2A08: bne         $s0, $s2, L_801C29F4
    if (ctx->r16 != ctx->r18) {
        // 0x801C2A0C: lw          $s1, 0x10($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X10);
            goto L_801C29F4;
    }
    // 0x801C2A0C: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C2A10: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2A14: addiu       $a1, $a1, 0x2A38
    ctx->r5 = ADD32(ctx->r5, 0X2A38);
    // 0x801C2A18: jal         0x800058DC
    // 0x801C2A1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C2A1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801C2A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C2A24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2A28: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2A2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C2A30: jr          $ra
    // 0x801C2A34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C2A34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2a38(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2a38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2A38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C2A3C: jr          $ra
    // 0x801C2A40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C2A40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2a44(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2a44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2A44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C2A48: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801C2A4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C2A50: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C2A54: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C2A58: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x801C2A5C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801C2A60: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C2A64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C2A68: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801C2A6C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C2A70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C2A74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x801C2A78: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801C2A7C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x801C2A80: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C2A84: jal         0x80005E44
    // 0x801C2A88: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C2A88: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    after_0:
    // 0x801C2A8C: jal         0x80006214
    // 0x801C2A90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C2A90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C2A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2A9C: addiu       $a2, $zero, 0x228
    ctx->r6 = ADD32(0, 0X228);
    // 0x801C2AA0: jal         0x8012C89C
    // 0x801C2AA4: addiu       $a3, $zero, 0x2B
    ctx->r7 = ADD32(0, 0X2B);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C2AA4: addiu       $a3, $zero, 0x2B
    ctx->r7 = ADD32(0, 0X2B);
    after_2:
    // 0x801C2AA8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AAC: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801C2AB0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2AB4: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x801C2AB8: jal         0x8000C3B0
    // 0x801C2ABC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_3;
    // 0x801C2ABC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x801C2AC0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2AC8: lwc1        $f2, -0xD84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XD84);
    // 0x801C2ACC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C2AD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C2AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2AD8: sw          $v0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r2;
    // 0x801C2ADC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AE0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C2AE4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2AE8: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801C2AEC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AF0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2AF4: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x801C2AF8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AFC: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801C2B00: swc1        $f0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f0.u32l;
    // 0x801C2B04: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B08: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C2B0C: swc1        $f2, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f2.u32l;
    // 0x801C2B10: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B14: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C2B18: swc1        $f2, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f2.u32l;
    // 0x801C2B1C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B20: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2B24: swc1        $f2, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f2.u32l;
    // 0x801C2B28: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B2C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2B30: jal         0x80005E44
    // 0x801C2B34: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_4;
    // 0x801C2B34: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    after_4:
    // 0x801C2B38: jal         0x80006214
    // 0x801C2B3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801C2B3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801C2B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C2B48: addiu       $a2, $zero, 0x228
    ctx->r6 = ADD32(0, 0X228);
    // 0x801C2B4C: jal         0x8012C89C
    // 0x801C2B50: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x801C2B50: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    after_6:
    // 0x801C2B54: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x801C2B58: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801C2B5C: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801C2B60: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x801C2B64: jal         0x8000C3B0
    // 0x801C2B68: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_7;
    // 0x801C2B68: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x801C2B6C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C2B70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2B74: lwc1        $f0, -0xD80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XD80);
    // 0x801C2B78: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C2B7C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801C2B80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C2B84: sw          $v0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r2;
    // 0x801C2B88: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x801C2B8C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801C2B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C2B94: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C2B98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C2B9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2BA0: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x801C2BA4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2BAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C2BB0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C2BB4: addiu       $t5, $zero, 0x1800
    ctx->r13 = ADD32(0, 0X1800);
    // 0x801C2BB8: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801C2BBC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BC0: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C2BC4: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801C2BC8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BCC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C2BD0: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801C2BD4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BD8: lwc1        $f10, -0xD7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XD7C);
    // 0x801C2BDC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C2BE0: swc1        $f10, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f10.u32l;
    // 0x801C2BE4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BE8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C2BEC: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x801C2BF0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C2BF4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2BF8: jal         0x80005E44
    // 0x801C2BFC: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_8;
    // 0x801C2BFC: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    after_8:
    // 0x801C2C00: jal         0x80006214
    // 0x801C2C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_9;
    // 0x801C2C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x801C2C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2C0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C2C10: addiu       $a2, $zero, 0x228
    ctx->r6 = ADD32(0, 0X228);
    // 0x801C2C14: jal         0x8012C89C
    // 0x801C2C18: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_10;
    // 0x801C2C18: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    after_10:
    // 0x801C2C1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2C20: addiu       $a1, $zero, 0x228
    ctx->r5 = ADD32(0, 0X228);
    // 0x801C2C24: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x801C2C28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801C2C2C: jal         0x8012D918
    // 0x801C2C30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_11;
    // 0x801C2C30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x801C2C34: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801C2C38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2C3C: lwc1        $f0, -0xD78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XD78);
    // 0x801C2C40: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C2C44: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C2C48: addiu       $t1, $t1, -0x3728
    ctx->r9 = ADD32(ctx->r9, -0X3728);
    // 0x801C2C4C: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801C2C50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C2C54: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x801C2C58: ori         $t9, $t8, 0x4100
    ctx->r25 = ctx->r24 | 0X4100;
    // 0x801C2C5C: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801C2C60: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x801C2C64: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801C2C68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C2C6C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C2C70: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x801C2C74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C2C78: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
    // 0x801C2C7C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x801C2C80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C2C84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2C88: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801C2C8C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C2C90: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2C94: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x801C2C98: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801C2C9C: addiu       $a1, $a1, 0x2D78
    ctx->r5 = ADD32(ctx->r5, 0X2D78);
    // 0x801C2CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2CA4: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C2CA8: addiu       $t7, $zero, 0x1800
    ctx->r15 = ADD32(0, 0X1800);
    // 0x801C2CAC: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x801C2CB0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x801C2CB4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C2CB8: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x801C2CBC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801C2CC0: addiu       $t9, $zero, 0x90
    ctx->r25 = ADD32(0, 0X90);
    // 0x801C2CC4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C2CC8: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x801C2CCC: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801C2CD0: lwc1        $f6, -0xD74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XD74);
    // 0x801C2CD4: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C2CD8: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801C2CDC: swc1        $f6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f6.u32l;
    // 0x801C2CE0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x801C2CE4: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801C2CE8: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x801C2CEC: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801C2CF0: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x801C2CF4: lw          $t8, 0x30($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X30);
    // 0x801C2CF8: sh          $t7, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r15;
    // 0x801C2CFC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D00: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C2D04: sb          $t9, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r25;
    // 0x801C2D08: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D0C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C2D10: sb          $t2, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r10;
    // 0x801C2D14: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D18: lw          $t7, 0x30($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X30);
    // 0x801C2D1C: sb          $t5, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r13;
    // 0x801C2D20: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D24: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x801C2D28: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C2D2C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D30: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x801C2D34: sb          $zero, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = 0;
    // 0x801C2D38: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D3C: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x801C2D40: sb          $zero, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = 0;
    // 0x801C2D44: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D48: lw          $t0, 0x30($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X30);
    // 0x801C2D4C: sb          $v1, 0x4E($t0)
    MEM_B(0X4E, ctx->r8) = ctx->r3;
    // 0x801C2D50: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801C2D54: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C2D58: sb          $v1, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r3;
    // 0x801C2D5C: jal         0x800058DC
    // 0x801C2D60: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x801C2D60: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    after_12:
    // 0x801C2D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C2D68: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2D6C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C2D70: jr          $ra
    // 0x801C2D74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C2D74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2d78(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2d78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2D78: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C2D7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C2D80: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801C2D84: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801C2D88: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801C2D8C: mfhi        $t9
    ctx->r25 = hi;
    // 0x801C2D90: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C2D94: bne         $t9, $zero, L_801C2DB0
    if (ctx->r25 != 0) {
        // 0x801C2D98: nop
    
            goto L_801C2DB0;
    }
    // 0x801C2D98: nop

    // 0x801C2D9C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x801C2DA0: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C2DA4: lbu         $t1, 0x4D($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4D);
    // 0x801C2DA8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801C2DAC: sb          $t2, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r10;
L_801C2DB0:
    // 0x801C2DB0: jr          $ra
    // 0x801C2DB4: nop

    return;
    // 0x801C2DB4: nop

;}
RECOMP_FUNC void M23_FUN_801c2db8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2DB8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x801C2DBC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801C2DC0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C2DC4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801C2DC8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801C2DCC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801C2DD0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801C2DD4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801C2DD8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801C2DDC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801C2DE0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801C2DE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C2DE8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801C2DEC: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x801C2DF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801C2DF4: addiu       $s7, $sp, 0xE8
    ctx->r23 = ADD32(ctx->r29, 0XE8);
    // 0x801C2DF8: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C2DFC: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x801C2E00: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C2E04: addiu       $fp, $sp, 0x5C
    ctx->r30 = ADD32(ctx->r29, 0X5C);
    // 0x801C2E08: addiu       $t9, $t9, -0x35B8
    ctx->r25 = ADD32(ctx->r25, -0X35B8);
    // 0x801C2E0C: sw          $t7, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r15;
    // 0x801C2E10: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801C2E14: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C2E18: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x801C2E1C: sw          $t8, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r24;
    // 0x801C2E20: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C2E24: addiu       $t3, $t9, 0x84
    ctx->r11 = ADD32(ctx->r25, 0X84);
    // 0x801C2E28: or          $t2, $fp, $zero
    ctx->r10 = ctx->r30 | 0;
    // 0x801C2E2C: sw          $t7, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r15;
L_801C2E30:
    // 0x801C2E30: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C2E34: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801C2E38: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x801C2E3C: sw          $t1, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r9;
    // 0x801C2E40: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x801C2E44: sw          $t0, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r8;
    // 0x801C2E48: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x801C2E4C: bne         $t9, $t3, L_801C2E30
    if (ctx->r25 != ctx->r11) {
        // 0x801C2E50: sw          $t1, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r9;
            goto L_801C2E30;
    }
    // 0x801C2E50: sw          $t1, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r9;
    // 0x801C2E54: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C2E58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2E5C: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x801C2E60: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801C2E64: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C2E68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C2E6C: jal         0x80126A0C
    // 0x801C2E70: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x801C2E70: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    after_0:
    // 0x801C2E74: beq         $v0, $zero, L_801C2FA8
    if (ctx->r2 == 0) {
        // 0x801C2E78: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801C2FA8;
    }
    // 0x801C2E78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C2E7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C2E80: lwc1        $f20, -0xD70($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0XD70);
    // 0x801C2E84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C2E88: addiu       $s5, $zero, 0x800
    ctx->r21 = ADD32(0, 0X800);
    // 0x801C2E8C: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x801C2E90: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
L_801C2E94:
    // 0x801C2E94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2E98: jal         0x80005E44
    // 0x801C2E9C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801C2E9C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_1:
    // 0x801C2EA0: jal         0x80006214
    // 0x801C2EA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801C2EA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x801C2EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C2EB0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801C2EB4: jal         0x8012C89C
    // 0x801C2EB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801C2EB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_3:
    // 0x801C2EBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C2EC0: addiu       $a1, $zero, 0x228
    ctx->r5 = ADD32(0, 0X228);
    // 0x801C2EC4: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    // 0x801C2EC8: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    // 0x801C2ECC: jal         0x8012D918
    // 0x801C2ED0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_4;
    // 0x801C2ED0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x801C2ED4: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x801C2ED8: addu        $s0, $s6, $t4
    ctx->r16 = ADD32(ctx->r22, ctx->r12);
    // 0x801C2EDC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C2EE0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C2EE4: sw          $s3, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r19;
    // 0x801C2EE8: jal         0x8000C3B0
    // 0x801C2EEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_5;
    // 0x801C2EEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x801C2EF0: multu       $s1, $s4
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C2EF4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C2EF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801C2EFC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C2F00: sw          $v0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r2;
    // 0x801C2F04: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F08: mflo        $t3
    ctx->r11 = lo;
    // 0x801C2F0C: addu        $v1, $fp, $t3
    ctx->r3 = ADD32(ctx->r30, ctx->r11);
    // 0x801C2F10: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801C2F14: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801C2F18: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x801C2F1C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F20: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C2F24: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2F28: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801C2F2C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F30: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C2F34: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2F38: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x801C2F3C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F40: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C2F44: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2F48: swc1        $f10, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f10.u32l;
    // 0x801C2F4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F50: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801C2F54: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x801C2F58: swc1        $f16, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f16.u32l;
    // 0x801C2F5C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F60: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801C2F64: swc1        $f20, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f20.u32l;
    // 0x801C2F68: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2F6C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2F70: sh          $s5, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r21;
    // 0x801C2F74: jal         0x801451C0
    // 0x801C2F78: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_6;
    // 0x801C2F78: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801C2F7C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C2F80: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C2F84: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x801C2F88: bne         $at, $zero, L_801C2E94
    if (ctx->r1 != 0) {
        // 0x801C2F8C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_801C2E94;
    }
    // 0x801C2F8C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x801C2F90: jal         0x80145390
    // 0x801C2F94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80145390)(rdram, ctx);
        goto after_7;
    // 0x801C2F94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x801C2F98: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2F9C: addiu       $a1, $a1, 0x2FDC
    ctx->r5 = ADD32(ctx->r5, 0X2FDC);
    // 0x801C2FA0: jal         0x800058DC
    // 0x801C2FA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C2FA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
L_801C2FA8:
    // 0x801C2FA8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C2FAC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801C2FB0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C2FB4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2FB8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801C2FBC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801C2FC0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801C2FC4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801C2FC8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801C2FCC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801C2FD0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801C2FD4: jr          $ra
    // 0x801C2FD8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x801C2FD8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c2fdc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c2fdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2FDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C2FE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C2FE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C2FE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801C2FEC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801C2FF0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C2FF4: addiu       $t6, $zero, 0x21
    ctx->r14 = ADD32(0, 0X21);
    // 0x801C2FF8: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x801C2FFC: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x801C3000: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C3004: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C3008: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C300C: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    // 0x801C3010: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C3014: jal         0x801453CC
    // 0x801C3018: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x801C3018: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x801C301C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x801C3020: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x801C3024: jal         0x80145E78
    // 0x801C3028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_1;
    // 0x801C3028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801C302C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801C3030: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801C3034: jal         0x80145E78
    // 0x801C3038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_2;
    // 0x801C3038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x801C303C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801C3040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3044: jal         0x80145E78
    // 0x801C3048: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_3;
    // 0x801C3048: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x801C304C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x801C3050: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x801C3054: jal         0x80145E78
    // 0x801C3058: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_4;
    // 0x801C3058: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x801C305C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x801C3060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3064: jal         0x80145E78
    // 0x801C3068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_5;
    // 0x801C3068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x801C306C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x801C3070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3074: jal         0x80145E78
    // 0x801C3078: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145E78)(rdram, ctx);
        goto after_6;
    // 0x801C3078: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x801C307C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3080: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C3084: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C3088: jr          $ra
    // 0x801C308C: nop

    return;
    // 0x801C308C: nop

;}
RECOMP_FUNC void M23_FUN_801c3090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3090: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801C3094: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801C3098: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C309C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801C30A0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801C30A4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801C30A8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801C30AC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801C30B0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801C30B4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801C30B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801C30BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C30C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801C30C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801C30C8: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x801C30CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801C30D0: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x801C30D4: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801C30D8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x801C30DC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C30E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C30E4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801C30E8: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x801C30EC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801C30F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C30F4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801C30F8: sw          $t8, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r24;
    // 0x801C30FC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C3100: addiu       $s4, $s4, -0x4410
    ctx->r20 = ADD32(ctx->r20, -0X4410);
    // 0x801C3104: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C3108: sw          $t7, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r15;
    // 0x801C310C: lwc1        $f20, -0xD6C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0XD6C);
    // 0x801C3110: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C3114: addiu       $s7, $zero, 0x15
    ctx->r23 = ADD32(0, 0X15);
    // 0x801C3118: addiu       $fp, $zero, 0xA0
    ctx->r30 = ADD32(0, 0XA0);
L_801C311C:
    // 0x801C311C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C3120: jal         0x80005E44
    // 0x801C3124: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C3124: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_0:
    // 0x801C3128: jal         0x80006214
    // 0x801C312C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C312C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x801C3130: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C3134: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801C3138: addiu       $a2, $zero, 0x228
    ctx->r6 = ADD32(0, 0X228);
    // 0x801C313C: jal         0x8012C89C
    // 0x801C3140: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C3140: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    after_2:
    // 0x801C3144: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x801C3148: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
    // 0x801C314C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C3150: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C3154: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
    // 0x801C3158: jal         0x8000C3B0
    // 0x801C315C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_3;
    // 0x801C315C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x801C3160: multu       $s2, $fp
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C3164: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C3168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C316C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C3170: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C3174: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x801C3178: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x801C317C: sw          $v0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r2;
    // 0x801C3180: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C3184: mflo        $t6
    ctx->r14 = lo;
    // 0x801C3188: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C318C: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x801C3190: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C3194: swc1        $f22, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f22.u32l;
    // 0x801C3198: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C319C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C31A0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C31A4: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801C31A8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C31AC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C31B0: swc1        $f22, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f22.u32l;
    // 0x801C31B4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C31B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C31BC: swc1        $f20, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f20.u32l;
    // 0x801C31C0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C31C4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C31C8: swc1        $f20, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f20.u32l;
    // 0x801C31CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C31D0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C31D4: swc1        $f20, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f20.u32l;
    // 0x801C31D8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C31DC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C31E0: sh          $zero, 0x10($t9)
    MEM_H(0X10, ctx->r25) = 0;
    // 0x801C31E4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C31E8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C31EC: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801C31F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C31F4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C31F8: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x801C31FC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C3200: lbu         $t4, 0xF32($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0XF32);
    // 0x801C3204: addiu       $t3, $zero, 0x61
    ctx->r11 = ADD32(0, 0X61);
    // 0x801C3208: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C320C: sb          $t4, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r12;
    // 0x801C3210: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C3214: lbu         $t7, 0xF33($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0XF33);
    // 0x801C3218: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C321C: sb          $t7, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r15;
    // 0x801C3220: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C3224: lbu         $t0, 0xF34($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0XF34);
    // 0x801C3228: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C322C: sb          $t0, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r8;
    // 0x801C3230: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C3234: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C3238: bne         $at, $zero, L_801C311C
    if (ctx->r1 != 0) {
        // 0x801C323C: sb          $t3, 0x4F($t4)
        MEM_B(0X4F, ctx->r12) = ctx->r11;
            goto L_801C311C;
    }
    // 0x801C323C: sb          $t3, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r11;
    // 0x801C3240: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3244: addiu       $a1, $a1, 0x3288
    ctx->r5 = ADD32(ctx->r5, 0X3288);
    // 0x801C3248: jal         0x800058DC
    // 0x801C324C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C324C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801C3250: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C3254: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801C3258: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801C325C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C3260: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3264: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801C3268: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801C326C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801C3270: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801C3274: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801C3278: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801C327C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801C3280: jr          $ra
    // 0x801C3284: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801C3284: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c3288(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c3288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3288: addiu       $t6, $zero, 0xAA
    ctx->r14 = ADD32(0, 0XAA);
    // 0x801C328C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C3290: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C3294: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801C3298: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x801C329C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C32A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C32A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C32A8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_801C32AC:
    // 0x801C32AC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801C32B0: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x801C32B4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801C32B8: addiu       $t0, $zero, -0x136
    ctx->r8 = ADD32(0, -0X136);
    // 0x801C32BC: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x801C32C0: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801C32C4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x801C32C8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x801C32CC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801C32D0: lw          $a0, 0x30($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X30);
    // 0x801C32D4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801C32D8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801C32DC: nop

    // 0x801C32E0: bc1fl       L_801C3304
    if (!c1cs) {
        // 0x801C32E4: lh          $t2, 0x12($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X12);
            goto L_801C3304;
    }
    goto skip_0;
    // 0x801C32E4: lh          $t2, 0x12($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X12);
    skip_0:
    // 0x801C32E8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801C32EC: nop

    // 0x801C32F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801C32F4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x801C32F8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801C32FC: lw          $a0, 0x30($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X30);
    // 0x801C3300: lh          $t2, 0x12($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X12);
L_801C3304:
    // 0x801C3304: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C3308: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801C330C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801C3310: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801C3314: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3318: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x801C331C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C3320: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801C3324: bne         $at, $zero, L_801C32AC
    if (ctx->r1 != 0) {
        // 0x801C3328: sh          $t4, 0x12($a0)
        MEM_H(0X12, ctx->r4) = ctx->r12;
            goto L_801C32AC;
    }
    // 0x801C3328: sh          $t4, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r12;
    // 0x801C332C: jr          $ra
    // 0x801C3330: nop

    return;
    // 0x801C3330: nop

;}
RECOMP_FUNC void M23_FUN_801c3334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3334: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C3338: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C333C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801C3340: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801C3344: jal         0x80116E80
    // 0x801C3348: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x801C3348: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x801C334C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x801C3350: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x801C3354: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C3358: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C335C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C3360: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C3364: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801C3368: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x801C336C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C3370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C3374: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3378: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C337C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C3380: jal         0x80146178
    // 0x801C3384: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_1;
    // 0x801C3384: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_1:
    // 0x801C3388: jal         0x80006214
    // 0x801C338C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801C338C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x801C3390: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801C3394: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801C3398: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x801C339C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801C33A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C33A4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C33A8: sh          $t9, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r25;
    // 0x801C33AC: addiu       $a1, $a1, 0x33C8
    ctx->r5 = ADD32(ctx->r5, 0X33C8);
    // 0x801C33B0: jal         0x800058DC
    // 0x801C33B4: sw          $a0, -0x375C($at)
    MEM_W(-0X375C, ctx->r1) = ctx->r4;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C33B4: sw          $a0, -0x375C($at)
    MEM_W(-0X375C, ctx->r1) = ctx->r4;
    after_3:
    // 0x801C33B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C33BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801C33C0: jr          $ra
    // 0x801C33C4: nop

    return;
    // 0x801C33C4: nop

;}
RECOMP_FUNC void M23_FUN_801c33c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C33C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C33CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C33D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C33D4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801C33D8: jal         0x801C1088
    // 0x801C33DC: lb          $a1, 0x90($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X90);
    LOOKUP_FUNC(0x801C1088)(rdram, ctx);
        goto after_0;
    // 0x801C33DC: lb          $a1, 0x90($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X90);
    after_0:
    // 0x801C33E0: beq         $v0, $zero, L_801C33F8
    if (ctx->r2 == 0) {
        // 0x801C33E4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801C33F8;
    }
    // 0x801C33E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C33E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C33EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C33F0: b           L_801C3400
    // 0x801C33F4: sb          $t6, -0x3734($at)
    MEM_B(-0X3734, ctx->r1) = ctx->r14;
        goto L_801C3400;
    // 0x801C33F4: sb          $t6, -0x3734($at)
    MEM_B(-0X3734, ctx->r1) = ctx->r14;
L_801C33F8:
    // 0x801C33F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C33FC: sb          $t7, -0x3734($at)
    MEM_B(-0X3734, ctx->r1) = ctx->r15;
L_801C3400:
    // 0x801C3400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3408: jr          $ra
    // 0x801C340C: nop

    return;
    // 0x801C340C: nop

;}
RECOMP_FUNC void M23_FUN_801c3410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3418: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801C341C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3420: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801C3424: jal         0x801C1088
    // 0x801C3428: lb          $a1, 0x90($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X90);
    LOOKUP_FUNC(0x801C1088)(rdram, ctx);
        goto after_0;
    // 0x801C3428: lb          $a1, 0x90($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X90);
    after_0:
    // 0x801C342C: beq         $v0, $zero, L_801C3454
    if (ctx->r2 == 0) {
        // 0x801C3430: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801C3454;
    }
    // 0x801C3430: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C3434: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3438: sb          $zero, -0x3734($at)
    MEM_B(-0X3734, ctx->r1) = 0;
    // 0x801C343C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3440: sw          $zero, -0x375C($at)
    MEM_W(-0X375C, ctx->r1) = 0;
    // 0x801C3444: jal         0x80005700
    // 0x801C3448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C3448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C344C: b           L_801C3460
    // 0x801C3450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3460;
    // 0x801C3450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3454:
    // 0x801C3454: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3458: sb          $t7, -0x3734($at)
    MEM_B(-0X3734, ctx->r1) = ctx->r15;
    // 0x801C345C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3460:
    // 0x801C3460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3464: jr          $ra
    // 0x801C3468: nop

    return;
    // 0x801C3468: nop

;}
RECOMP_FUNC void M23_FUN_801c346c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C346C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C3470: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801C3474: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801C3478: addiu       $s1, $sp, 0x4F
    ctx->r17 = ADD32(ctx->r29, 0X4F);
    // 0x801C347C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801C3480: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C3484: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801C3488: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x801C348C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C3490: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801C3494: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C3498: addiu       $t0, $zero, 0x228
    ctx->r8 = ADD32(0, 0X228);
    // 0x801C349C: addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
    // 0x801C34A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C34A4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801C34A8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801C34AC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801C34B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C34B4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C34B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C34BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C34C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C34C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C34C8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C34CC: jal         0x80146208
    // 0x801C34D0: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x801C34D0: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    after_0:
    // 0x801C34D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C34D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C34DC: jal         0x80145348
    // 0x801C34E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_1;
    // 0x801C34E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x801C34E4: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x801C34E8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C34EC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x801C34F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801C34F4: addiu       $t6, $zero, 0x228
    ctx->r14 = ADD32(0, 0X228);
    // 0x801C34F8: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801C34FC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801C3500: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801C3504: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801C3508: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C350C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C3510: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C3514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C351C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3520: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801C3524: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3528: jal         0x80146208
    // 0x801C352C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x801C352C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x801C3530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3534: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3538: jal         0x80145348
    // 0x801C353C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x801C353C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_3:
    // 0x801C3540: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x801C3544: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C3548: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x801C354C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C3550: addiu       $t2, $zero, 0x228
    ctx->r10 = ADD32(0, 0X228);
    // 0x801C3554: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x801C3558: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801C355C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801C3560: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801C3564: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801C3568: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801C356C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C3570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3574: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C3578: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C357C: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801C3580: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3584: jal         0x80146208
    // 0x801C3588: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801C3588: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x801C358C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3590: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3594: jal         0x80145348
    // 0x801C3598: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_5;
    // 0x801C3598: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_5:
    // 0x801C359C: addiu       $t4, $zero, 0x70
    ctx->r12 = ADD32(0, 0X70);
    // 0x801C35A0: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C35A4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x801C35A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801C35AC: addiu       $t8, $zero, 0x228
    ctx->r24 = ADD32(0, 0X228);
    // 0x801C35B0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801C35B4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801C35B8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801C35BC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801C35C0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801C35C4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801C35C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C35CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C35D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C35D4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C35D8: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801C35DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C35E0: jal         0x80146208
    // 0x801C35E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x801C35E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x801C35E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C35EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C35F0: jal         0x80145348
    // 0x801C35F4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_7;
    // 0x801C35F4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_7:
    // 0x801C35F8: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801C35FC: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801C3600: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801C3604: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C3608: addiu       $t4, $zero, 0x228
    ctx->r12 = ADD32(0, 0X228);
    // 0x801C360C: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x801C3610: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801C3614: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801C3618: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801C361C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801C3620: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801C3624: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C3628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C362C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C3630: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3634: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801C3638: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C363C: jal         0x80146208
    // 0x801C3640: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x801C3640: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_8:
    // 0x801C3644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C364C: jal         0x80145348
    // 0x801C3650: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_9;
    // 0x801C3650: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_9:
    // 0x801C3654: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x801C3658: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C365C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801C3660: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C3664: addiu       $t0, $zero, 0x228
    ctx->r8 = ADD32(0, 0X228);
    // 0x801C3668: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x801C366C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801C3670: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801C3674: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801C3678: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C367C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C3680: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C3684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3688: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C368C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3690: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801C3694: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3698: jal         0x80146208
    // 0x801C369C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x801C369C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_10:
    // 0x801C36A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C36A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C36A8: jal         0x80145348
    // 0x801C36AC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_11;
    // 0x801C36AC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_11:
    // 0x801C36B0: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801C36B4: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C36B8: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x801C36BC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801C36C0: addiu       $t6, $zero, 0x228
    ctx->r14 = ADD32(0, 0X228);
    // 0x801C36C4: addiu       $t7, $zero, 0x27
    ctx->r15 = ADD32(0, 0X27);
    // 0x801C36C8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801C36CC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801C36D0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801C36D4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C36D8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C36DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C36E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C36E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C36E8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C36EC: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C36F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C36F4: jal         0x80146208
    // 0x801C36F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_12;
    // 0x801C36F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_12:
    // 0x801C36FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3700: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3704: jal         0x80145348
    // 0x801C3708: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_13;
    // 0x801C3708: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_13:
    // 0x801C370C: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x801C3710: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C3714: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x801C3718: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C371C: addiu       $t2, $zero, 0x228
    ctx->r10 = ADD32(0, 0X228);
    // 0x801C3720: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x801C3724: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801C3728: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801C372C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801C3730: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801C3734: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801C3738: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C373C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3740: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C3744: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3748: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C374C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3750: jal         0x80146208
    // 0x801C3754: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_14;
    // 0x801C3754: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_14:
    // 0x801C3758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C375C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3760: jal         0x80145348
    // 0x801C3764: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_15;
    // 0x801C3764: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_15:
    // 0x801C3768: addiu       $t4, $zero, 0x60
    ctx->r12 = ADD32(0, 0X60);
    // 0x801C376C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801C3770: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x801C3774: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801C3778: addiu       $t8, $zero, 0x228
    ctx->r24 = ADD32(0, 0X228);
    // 0x801C377C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801C3780: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801C3784: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801C3788: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801C378C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801C3790: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801C3794: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C3798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C379C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C37A0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C37A4: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C37A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C37AC: jal         0x80146208
    // 0x801C37B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_16;
    // 0x801C37B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_16:
    // 0x801C37B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C37B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C37BC: jal         0x80145348
    // 0x801C37C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_17;
    // 0x801C37C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_17:
    // 0x801C37C4: addiu       $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
    // 0x801C37C8: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801C37CC: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801C37D0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C37D4: addiu       $t4, $zero, 0x228
    ctx->r12 = ADD32(0, 0X228);
    // 0x801C37D8: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x801C37DC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801C37E0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801C37E4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801C37E8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801C37EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801C37F0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C37F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C37F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C37FC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3800: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C3804: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3808: jal         0x80146208
    // 0x801C380C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_18;
    // 0x801C380C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_18:
    // 0x801C3810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3814: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3818: jal         0x80145348
    // 0x801C381C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_19;
    // 0x801C381C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_19:
    // 0x801C3820: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x801C3824: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C3828: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801C382C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C3830: addiu       $t0, $zero, 0x228
    ctx->r8 = ADD32(0, 0X228);
    // 0x801C3834: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x801C3838: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801C383C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801C3840: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801C3844: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C3848: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C384C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C3850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3854: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C3858: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C385C: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C3860: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3864: jal         0x80146208
    // 0x801C3868: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_20;
    // 0x801C3868: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_20:
    // 0x801C386C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3870: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C3874: jal         0x80145348
    // 0x801C3878: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_21;
    // 0x801C3878: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_21:
    // 0x801C387C: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
    // 0x801C3880: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C3884: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x801C3888: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801C388C: addiu       $t6, $zero, 0x228
    ctx->r14 = ADD32(0, 0X228);
    // 0x801C3890: addiu       $t7, $zero, 0x29
    ctx->r15 = ADD32(0, 0X29);
    // 0x801C3894: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801C3898: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801C389C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801C38A0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C38A4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C38A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C38AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C38B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C38B4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C38B8: addiu       $a3, $zero, 0xA3
    ctx->r7 = ADD32(0, 0XA3);
    // 0x801C38BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C38C0: jal         0x80146208
    // 0x801C38C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_22;
    // 0x801C38C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_22:
    // 0x801C38C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C38CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C38D0: jal         0x80145348
    // 0x801C38D4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_23;
    // 0x801C38D4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_23:
    // 0x801C38D8: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
    // 0x801C38DC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_801C38E0:
    // 0x801C38E0: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x801C38E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C38E8: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x801C38EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801C38F0: sh          $v0, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r2;
    // 0x801C38F4: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x801C38F8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801C38FC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801C3900: slti        $at, $t4, 0xC
    ctx->r1 = SIGNED(ctx->r12) < 0XC ? 1 : 0;
    // 0x801C3904: bne         $at, $zero, L_801C38E0
    if (ctx->r1 != 0) {
        // 0x801C3908: sb          $t3, 0x4F($sp)
        MEM_B(0X4F, ctx->r29) = ctx->r11;
            goto L_801C38E0;
    }
    // 0x801C3908: sb          $t3, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r11;
    // 0x801C390C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3910: addiu       $a1, $a1, 0x3934
    ctx->r5 = ADD32(ctx->r5, 0X3934);
    // 0x801C3914: jal         0x800058DC
    // 0x801C3918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_24;
    // 0x801C3918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x801C391C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801C3920: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801C3924: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801C3928: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801C392C: jr          $ra
    // 0x801C3930: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801C3930: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c3934(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c3934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3938: jr          $ra
    // 0x801C393C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C393C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c3940(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c3940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3940: andi        $a2, $zero, 0xFF
    ctx->r6 = 0 & 0XFF;
    // 0x801C3944: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C3948: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c394c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c394c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C394C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3950: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C3954: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C3958: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C395C: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C3960: addiu       $v0, $v0, -0x3738
    ctx->r2 = ADD32(ctx->r2, -0X3738);
    // 0x801C3964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C396C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C3970: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C3974: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C3978: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x801C397C: addiu       $a3, $a3, -0x12F0
    ctx->r7 = ADD32(ctx->r7, -0X12F0);
    // 0x801C3980: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C3984: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C3988: jal         0x8001B204
    // 0x801C398C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C398C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801C3990: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C3994: addiu       $a3, $a3, -0x12E0
    ctx->r7 = ADD32(ctx->r7, -0X12E0);
    // 0x801C3998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C399C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C39A0: jal         0x8001B204
    // 0x801C39A4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C39A4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_1:
    // 0x801C39A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C39AC: addiu       $a3, $a3, -0x12D4
    ctx->r7 = ADD32(ctx->r7, -0X12D4);
    // 0x801C39B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C39B4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C39B8: jal         0x8001B204
    // 0x801C39BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C39BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_2:
    // 0x801C39C0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C39C4: addiu       $a3, $a3, -0x12C8
    ctx->r7 = ADD32(ctx->r7, -0X12C8);
    // 0x801C39C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C39CC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C39D0: jal         0x8001B204
    // 0x801C39D4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C39D4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_3:
    // 0x801C39D8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C39DC: addiu       $a3, $a3, -0x12BC
    ctx->r7 = ADD32(ctx->r7, -0X12BC);
    // 0x801C39E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C39E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C39E8: jal         0x8001B204
    // 0x801C39EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C39EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801C39F0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C39F4: addiu       $a3, $a3, -0x12B8
    ctx->r7 = ADD32(ctx->r7, -0X12B8);
    // 0x801C39F8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C39FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3A00: jal         0x8001B204
    // 0x801C3A04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C3A04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801C3A08: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C3A0C: addiu       $a3, $a3, -0x12B4
    ctx->r7 = ADD32(ctx->r7, -0X12B4);
    // 0x801C3A10: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C3A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3A18: jal         0x8001B204
    // 0x801C3A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C3A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x801C3A20: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3A24: addiu       $a1, $a1, 0x3A40
    ctx->r5 = ADD32(ctx->r5, 0X3A40);
    // 0x801C3A28: jal         0x800058DC
    // 0x801C3A2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C3A2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x801C3A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3A38: jr          $ra
    // 0x801C3A3C: nop

    return;
    // 0x801C3A3C: nop

;}
RECOMP_FUNC void M23_FUN_801c3a40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3A4C: jal         0x801C1340
    // 0x801C3A50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C3A50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C3A54: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C3A58: beq         $t6, $zero, L_801C3A80
    if (ctx->r14 == 0) {
        // 0x801C3A5C: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C3A80;
    }
    // 0x801C3A5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C3A60: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C3A64: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C3A68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801C3A6C: bne         $v0, $zero, L_801C3A7C
    if (ctx->r2 != 0) {
        // 0x801C3A70: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C3A7C;
    }
    // 0x801C3A70: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C3A74: b           L_801C3A80
    // 0x801C3A78: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801C3A80;
    // 0x801C3A78: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C3A7C:
    // 0x801C3A7C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801C3A80:
    // 0x801C3A80: jal         0x801C1340
    // 0x801C3A84: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C3A84: nop

    after_1:
    // 0x801C3A88: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C3A8C: beq         $t9, $zero, L_801C3AB8
    if (ctx->r25 == 0) {
        // 0x801C3A90: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C3AB8;
    }
    // 0x801C3A90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C3A94: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C3A98: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C3A9C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C3AA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3AA4: bne         $v0, $at, L_801C3AB4
    if (ctx->r2 != ctx->r1) {
        // 0x801C3AA8: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801C3AB4;
    }
    // 0x801C3AA8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801C3AAC: b           L_801C3AB8
    // 0x801C3AB0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C3AB8;
    // 0x801C3AB0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C3AB4:
    // 0x801C3AB4: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801C3AB8:
    // 0x801C3AB8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C3ABC: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C3AC0: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C3AC4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C3AC8: addiu       $a3, $a3, -0x12B0
    ctx->r7 = ADD32(ctx->r7, -0X12B0);
    // 0x801C3ACC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C3AD0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C3AD4: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C3AD8: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C3ADC: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C3AE0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C3AE4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C3AE8: jal         0x8001B204
    // 0x801C3AEC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C3AEC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_2:
    // 0x801C3AF0: jal         0x801C1334
    // 0x801C3AF4: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C3AF4: nop

    after_3:
    // 0x801C3AF8: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C3AFC: beq         $t1, $zero, L_801C3B10
    if (ctx->r9 == 0) {
        // 0x801C3B00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C3B10;
    }
    // 0x801C3B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C3B04: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3B08: jal         0x800058DC
    // 0x801C3B0C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3B0C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_4:
L_801C3B10:
    // 0x801C3B10: jal         0x801C1334
    // 0x801C3B14: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C3B14: nop

    after_5:
    // 0x801C3B18: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C3B1C: beq         $t2, $zero, L_801C3B94
    if (ctx->r10 == 0) {
        // 0x801C3B20: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C3B94;
    }
    // 0x801C3B20: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C3B24: lbu         $v0, -0x3738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3738);
    // 0x801C3B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C3B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C3B30: beq         $v0, $zero, L_801C3B54
    if (ctx->r2 == 0) {
        // 0x801C3B34: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_801C3B54;
    }
    // 0x801C3B34: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801C3B38: beq         $v0, $at, L_801C3B74
    if (ctx->r2 == ctx->r1) {
        // 0x801C3B3C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C3B74;
    }
    // 0x801C3B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C3B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3B44: beq         $v0, $at, L_801C3B88
    if (ctx->r2 == ctx->r1) {
        // 0x801C3B48: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C3B88;
    }
    // 0x801C3B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C3B4C: b           L_801C3B98
    // 0x801C3B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3B98;
    // 0x801C3B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3B54:
    // 0x801C3B54: jal         0x80005670
    // 0x801C3B58: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_6;
    // 0x801C3B58: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_6:
    // 0x801C3B5C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3B60: addiu       $a1, $a1, 0x3BA4
    ctx->r5 = ADD32(ctx->r5, 0X3BA4);
    // 0x801C3B64: jal         0x800058DC
    // 0x801C3B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C3B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x801C3B6C: b           L_801C3B98
    // 0x801C3B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3B98;
    // 0x801C3B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3B74:
    // 0x801C3B74: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3B78: jal         0x800058DC
    // 0x801C3B7C: addiu       $a1, $a1, 0x4C7C
    ctx->r5 = ADD32(ctx->r5, 0X4C7C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C3B7C: addiu       $a1, $a1, 0x4C7C
    ctx->r5 = ADD32(ctx->r5, 0X4C7C);
    after_8:
    // 0x801C3B80: b           L_801C3B98
    // 0x801C3B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C3B98;
    // 0x801C3B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3B88:
    // 0x801C3B88: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3B8C: jal         0x800058DC
    // 0x801C3B90: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C3B90: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_9:
L_801C3B94:
    // 0x801C3B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3B98:
    // 0x801C3B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3B9C: jr          $ra
    // 0x801C3BA0: nop

    return;
    // 0x801C3BA0: nop

;}
RECOMP_FUNC void M23_FUN_801c3ba4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3BB0: jal         0x8013E770
    // 0x801C3BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013E770)(rdram, ctx);
        goto after_0;
    // 0x801C3BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C3BB8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3BBC: addiu       $a1, $a1, 0x3BD8
    ctx->r5 = ADD32(ctx->r5, 0X3BD8);
    // 0x801C3BC0: jal         0x800058DC
    // 0x801C3BC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C3BC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C3BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3BD0: jr          $ra
    // 0x801C3BD4: nop

    return;
    // 0x801C3BD4: nop

;}
RECOMP_FUNC void M23_FUN_801c3bd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3BE4: jal         0x8013E794
    // 0x801C3BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013E794)(rdram, ctx);
        goto after_0;
    // 0x801C3BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C3BEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C3BF0: bne         $v0, $at, L_801C3C04
    if (ctx->r2 != ctx->r1) {
        // 0x801C3BF4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C3C04;
    }
    // 0x801C3BF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C3BF8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3BFC: jal         0x800058DC
    // 0x801C3C00: addiu       $a1, $a1, 0x3C14
    ctx->r5 = ADD32(ctx->r5, 0X3C14);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C3C00: addiu       $a1, $a1, 0x3C14
    ctx->r5 = ADD32(ctx->r5, 0X3C14);
    after_1:
L_801C3C04:
    // 0x801C3C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3C0C: jr          $ra
    // 0x801C3C10: nop

    return;
    // 0x801C3C10: nop

;}
RECOMP_FUNC void M23_FUN_801c3c14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C3C18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C3C1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C3C20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C3C24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3C28: jal         0x800023A8
    // 0x801C3C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_0;
    // 0x801C3C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801C3C30: jal         0x80020718
    // 0x801C3C34: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801C3C34: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x801C3C38: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C3C3C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C3C40: addiu       $t6, $zero, 0x104
    ctx->r14 = ADD32(0, 0X104);
    // 0x801C3C44: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x801C3C48: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x801C3C4C: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x801C3C50: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x801C3C54: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x801C3C58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C3C5C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C3C60: jal         0x8012FE50
    // 0x801C3C64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x801C3C64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801C3C68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C3C6C: sh          $zero, 0x3A2($s0)
    MEM_H(0X3A2, ctx->r16) = 0;
    // 0x801C3C70: jal         0x80133830
    // 0x801C3C74: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x80133830)(rdram, ctx);
        goto after_3;
    // 0x801C3C74: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    after_3:
    // 0x801C3C78: jal         0x80133950
    // 0x801C3C7C: nop

    LOOKUP_FUNC(0x80133950)(rdram, ctx);
        goto after_4;
    // 0x801C3C7C: nop

    after_4:
    // 0x801C3C80: jal         0x80133A70
    // 0x801C3C84: nop

    LOOKUP_FUNC(0x80133A70)(rdram, ctx);
        goto after_5;
    // 0x801C3C84: nop

    after_5:
    // 0x801C3C88: jal         0x8014AC60
    // 0x801C3C8C: nop

    LOOKUP_FUNC(0x8014AC60)(rdram, ctx);
        goto after_6;
    // 0x801C3C8C: nop

    after_6:
    // 0x801C3C90: sh          $zero, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = 0;
    // 0x801C3C94: jal         0x8012FFCC
    // 0x801C3C98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8012FFCC)(rdram, ctx);
        goto after_7;
    // 0x801C3C98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x801C3C9C: jal         0x801C1308
    // 0x801C3CA0: nop

    LOOKUP_FUNC(0x801C1308)(rdram, ctx);
        goto after_8;
    // 0x801C3CA0: nop

    after_8:
    // 0x801C3CA4: jal         0x80152240
    // 0x801C3CA8: nop

    LOOKUP_FUNC(0x80152240)(rdram, ctx);
        goto after_9;
    // 0x801C3CA8: nop

    after_9:
    // 0x801C3CAC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3CB0: addiu       $a1, $a1, 0x3CD0
    ctx->r5 = ADD32(ctx->r5, 0X3CD0);
    // 0x801C3CB4: jal         0x800058DC
    // 0x801C3CB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C3CB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x801C3CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C3CC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C3CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C3CC8: jr          $ra
    // 0x801C3CCC: nop

    return;
    // 0x801C3CCC: nop

;}
RECOMP_FUNC void M23_FUN_801c3cd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3CD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3CD4: jr          $ra
    // 0x801C3CD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C3CD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c3cdc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c3cdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3CE8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C3CEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C3CF0: jal         0x80005700
    // 0x801C3CF4: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C3CF4: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    after_0:
    // 0x801C3CF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C3CFC: jal         0x80005700
    // 0x801C3D00: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C3D00: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    after_1:
    // 0x801C3D04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3D08: sw          $zero, -0x3758($at)
    MEM_W(-0X3758, ctx->r1) = 0;
    // 0x801C3D0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3D10: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801C3D14: sw          $zero, -0x3748($at)
    MEM_W(-0X3748, ctx->r1) = 0;
    // 0x801C3D18: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    // 0x801C3D1C: jal         0x80005670
    // 0x801C3D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801C3D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C3D24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C3D28: jal         0x80152240
    // 0x801C3D2C: sw          $v0, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = ctx->r2;
    LOOKUP_FUNC(0x80152240)(rdram, ctx);
        goto after_3;
    // 0x801C3D2C: sw          $v0, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = ctx->r2;
    after_3:
    // 0x801C3D30: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3D34: addiu       $a1, $a1, 0x3D50
    ctx->r5 = ADD32(ctx->r5, 0X3D50);
    // 0x801C3D38: jal         0x800058DC
    // 0x801C3D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801C3D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3D48: jr          $ra
    // 0x801C3D4C: nop

    return;
    // 0x801C3D4C: nop

;}
RECOMP_FUNC void M23_FUN_801c3d50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3D5C: jal         0x8013E7C0
    // 0x801C3D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013E7C0)(rdram, ctx);
        goto after_0;
    // 0x801C3D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C3D64: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3D68: addiu       $a1, $a1, 0x3D84
    ctx->r5 = ADD32(ctx->r5, 0X3D84);
    // 0x801C3D6C: jal         0x800058DC
    // 0x801C3D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C3D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C3D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3D7C: jr          $ra
    // 0x801C3D80: nop

    return;
    // 0x801C3D80: nop

;}
RECOMP_FUNC void M23_FUN_801c3d84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C3D88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C3D8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C3D90: jal         0x8013E850
    // 0x801C3D94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013E850)(rdram, ctx);
        goto after_0;
    // 0x801C3D94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C3D98: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801C3D9C: beq         $t6, $zero, L_801C3E14
    if (ctx->r14 == 0) {
        // 0x801C3DA0: sb          $v0, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r2;
            goto L_801C3E14;
    }
    // 0x801C3DA0: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x801C3DA4: jal         0x80142570
    // 0x801C3DA8: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801C3DA8: nop

    after_1:
    // 0x801C3DAC: jal         0x800179B0
    // 0x801C3DB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x801C3DB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C3DB4: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x801C3DB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C3DBC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801C3DC0: bnel        $v1, $at, L_801C3DE8
    if (ctx->r3 != ctx->r1) {
        // 0x801C3DC4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C3DE8;
    }
    goto skip_0;
    // 0x801C3DC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x801C3DC8: jal         0x801C11BC
    // 0x801C3DCC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801C11BC)(rdram, ctx);
        goto after_3;
    // 0x801C3DCC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x801C3DD0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3DD4: addiu       $a1, $a1, 0x3E24
    ctx->r5 = ADD32(ctx->r5, 0X3E24);
    // 0x801C3DD8: jal         0x800058DC
    // 0x801C3DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x801C3DE0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801C3DE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801C3DE8:
    // 0x801C3DE8: bne         $v1, $at, L_801C3E14
    if (ctx->r3 != ctx->r1) {
        // 0x801C3DEC: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_801C3E14;
    }
    // 0x801C3DEC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801C3DF0: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C3DF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C3DF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C3DFC: jal         0x8012FE50
    // 0x801C3E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_5;
    // 0x801C3E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801C3E04: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3E08: addiu       $a1, $a1, 0x40EC
    ctx->r5 = ADD32(ctx->r5, 0X40EC);
    // 0x801C3E0C: jal         0x800058DC
    // 0x801C3E10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C3E10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
L_801C3E14:
    // 0x801C3E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C3E18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C3E1C: jr          $ra
    // 0x801C3E20: nop

    return;
    // 0x801C3E20: nop

;}
RECOMP_FUNC void M23_FUN_801c3e24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3E24: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C3E28: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C3E2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C3E30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C3E34: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801C3E38: addiu       $t7, $t7, -0x352C
    ctx->r15 = ADD32(ctx->r15, -0X352C);
    // 0x801C3E3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C3E40: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x801C3E44: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801C3E48: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801C3E4C: lwr         $t9, 0xA($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0XA);
    // 0x801C3E50: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801C3E54: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C3E58: swr         $t9, 0xA($t6)
    do_swr(rdram, 0XA, ctx->r14, ctx->r25);
    // 0x801C3E5C: lbu         $t1, -0x3734($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X3734);
    // 0x801C3E60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C3E64: bnel        $t1, $at, L_801C3F3C
    if (ctx->r9 != ctx->r1) {
        // 0x801C3E68: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801C3F3C;
    }
    goto skip_0;
    // 0x801C3E68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801C3E6C: jal         0x8013EA54
    // 0x801C3E70: nop

    LOOKUP_FUNC(0x8013EA54)(rdram, ctx);
        goto after_0;
    // 0x801C3E70: nop

    after_0:
    // 0x801C3E74: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801C3E78: bne         $v0, $at, L_801C3EAC
    if (ctx->r2 != ctx->r1) {
        // 0x801C3E7C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_801C3EAC;
    }
    // 0x801C3E7C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x801C3E80: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // 0x801C3E84: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C3E88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C3E8C: jal         0x8012FE50
    // 0x801C3E90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x801C3E90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801C3E94: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3E98: addiu       $a1, $a1, 0x40EC
    ctx->r5 = ADD32(ctx->r5, 0X40EC);
    // 0x801C3E9C: jal         0x800058DC
    // 0x801C3EA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C3EA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x801C3EA4: b           L_801C3F3C
    // 0x801C3EA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801C3F3C;
    // 0x801C3EA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801C3EAC:
    // 0x801C3EAC: jal         0x8013EA54
    // 0x801C3EB0: nop

    LOOKUP_FUNC(0x8013EA54)(rdram, ctx);
        goto after_3;
    // 0x801C3EB0: nop

    after_3:
    // 0x801C3EB4: addu        $v1, $sp, $v0
    ctx->r3 = ADD32(ctx->r29, ctx->r2);
    // 0x801C3EB8: lbu         $v1, 0x3F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3F);
    // 0x801C3EBC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C3EC0: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x801C3EC4: beq         $v1, $zero, L_801C3F28
    if (ctx->r3 == 0) {
        // 0x801C3EC8: addiu       $a2, $zero, 0x66
        ctx->r6 = ADD32(0, 0X66);
            goto L_801C3F28;
    }
    // 0x801C3EC8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C3ECC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x801C3ED0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801C3ED4: addiu       $t6, $v1, 0x1A
    ctx->r14 = ADD32(ctx->r3, 0X1A);
    // 0x801C3ED8: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x801C3EDC: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x801C3EE0: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x801C3EE4: addiu       $t5, $zero, 0x228
    ctx->r13 = ADD32(0, 0X228);
    // 0x801C3EE8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x801C3EEC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C3EF0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C3EF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C3EF8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C3EFC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x801C3F00: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C3F04: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C3F08: jal         0x80146208
    // 0x801C3F0C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x801C3F0C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_4:
    // 0x801C3F10: jal         0x80006214
    // 0x801C3F14: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801C3F14: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x801C3F18: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x801C3F1C: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x801C3F20: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C3F24: sh          $t7, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r15;
L_801C3F28:
    // 0x801C3F28: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3F2C: addiu       $a1, $a1, 0x3F48
    ctx->r5 = ADD32(ctx->r5, 0X3F48);
    // 0x801C3F30: jal         0x800058DC
    // 0x801C3F34: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C3F34: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x801C3F38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801C3F3C:
    // 0x801C3F3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801C3F40: jr          $ra
    // 0x801C3F44: nop

    return;
    // 0x801C3F44: nop

;}
RECOMP_FUNC void M23_FUN_801c3f48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3F48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C3F4C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C3F50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C3F54: addiu       $t7, $t7, -0x3520
    ctx->r15 = ADD32(ctx->r15, -0X3520);
    // 0x801C3F58: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C3F5C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x801C3F60: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801C3F64: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801C3F68: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C3F6C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801C3F70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C3F74: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801C3F78: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801C3F7C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3F80: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x801C3F84: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801C3F88: addiu       $a1, $a1, 0x4018
    ctx->r5 = ADD32(ctx->r5, 0X4018);
    // 0x801C3F8C: lbu         $v1, 0xB($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB);
    // 0x801C3F90: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801C3F94: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801C3F98: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x801C3F9C: bnel        $at, $zero, L_801C3FCC
    if (ctx->r1 != 0) {
        // 0x801C3FA0: sb          $v1, 0xB($v0)
        MEM_B(0XB, ctx->r2) = ctx->r3;
            goto L_801C3FCC;
    }
    goto skip_0;
    // 0x801C3FA0: sb          $v1, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r3;
    skip_0:
    // 0x801C3FA4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C3FA8: sh          $t2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r10;
    // 0x801C3FAC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x801C3FB0: jal         0x800058DC
    // 0x801C3FB4: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C3FB4: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_0:
    // 0x801C3FB8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801C3FBC: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x801C3FC0: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x801C3FC4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801C3FC8: sb          $v1, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r3;
L_801C3FCC:
    // 0x801C3FCC: jal         0x8013EA54
    // 0x801C3FD0: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8013EA54)(rdram, ctx);
        goto after_1;
    // 0x801C3FD0: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_1:
    // 0x801C3FD4: addu        $a0, $sp, $v0
    ctx->r4 = ADD32(ctx->r29, ctx->r2);
    // 0x801C3FD8: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x801C3FDC: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x801C3FE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C3FE4: beq         $t0, $zero, L_801C4008
    if (ctx->r8 == 0) {
        // 0x801C3FE8: addiu       $a1, $zero, 0x7D0
        ctx->r5 = ADD32(0, 0X7D0);
            goto L_801C4008;
    }
    // 0x801C3FE8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C3FEC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C3FF0: addiu       $a3, $a3, -0x1268
    ctx->r7 = ADD32(ctx->r7, -0X1268);
    // 0x801C3FF4: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x801C3FF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801C3FFC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801C4000: jal         0x8001B204
    // 0x801C4004: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4004: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
L_801C4008:
    // 0x801C4008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C400C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801C4010: jr          $ra
    // 0x801C4014: nop

    return;
    // 0x801C4014: nop

;}
RECOMP_FUNC void M23_FUN_801c4018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C401C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4024: jal         0x801C1334
    // 0x801C4028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_0;
    // 0x801C4028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C402C: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x801C4030: beq         $t6, $zero, L_801C4048
    if (ctx->r14 == 0) {
        // 0x801C4034: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C4048;
    }
    // 0x801C4034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C4038: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C403C: jal         0x800058DC
    // 0x801C4040: addiu       $a1, $a1, 0x4074
    ctx->r5 = ADD32(ctx->r5, 0X4074);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C4040: addiu       $a1, $a1, 0x4074
    ctx->r5 = ADD32(ctx->r5, 0X4074);
    after_1:
    // 0x801C4044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_801C4048:
    // 0x801C4048: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C404C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4050: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801C4054: bne         $v0, $zero, L_801C4064
    if (ctx->r2 != 0) {
        // 0x801C4058: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_801C4064;
    }
    // 0x801C4058: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801C405C: jal         0x800058DC
    // 0x801C4060: addiu       $a1, $a1, 0x4074
    ctx->r5 = ADD32(ctx->r5, 0X4074);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C4060: addiu       $a1, $a1, 0x4074
    ctx->r5 = ADD32(ctx->r5, 0X4074);
    after_2:
L_801C4064:
    // 0x801C4064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C406C: jr          $ra
    // 0x801C4070: nop

    return;
    // 0x801C4070: nop

;}
RECOMP_FUNC void M23_FUN_801c4074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C407C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C4084: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4088: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C408C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C4090: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C4094: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801C4098: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C409C: jal         0x8012FE50
    // 0x801C40A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C40A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x801C40A4: jal         0x8014AD20
    // 0x801C40A8: nop

    LOOKUP_FUNC(0x8014AD20)(rdram, ctx);
        goto after_1;
    // 0x801C40A8: nop

    after_1:
    // 0x801C40AC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C40B0: lw          $a0, -0x3744($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3744);
    // 0x801C40B4: beq         $a0, $zero, L_801C40CC
    if (ctx->r4 == 0) {
        // 0x801C40B8: nop
    
            goto L_801C40CC;
    }
    // 0x801C40B8: nop

    // 0x801C40BC: jal         0x80005700
    // 0x801C40C0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801C40C0: nop

    after_2:
    // 0x801C40C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C40C8: sw          $zero, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = 0;
L_801C40CC:
    // 0x801C40CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C40D0: addiu       $a1, $a1, 0x40EC
    ctx->r5 = ADD32(ctx->r5, 0X40EC);
    // 0x801C40D4: jal         0x800058DC
    // 0x801C40D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C40D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801C40DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C40E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C40E4: jr          $ra
    // 0x801C40E8: nop

    return;
    // 0x801C40E8: nop

;}
RECOMP_FUNC void M23_FUN_801c40ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C40EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C40F0: jr          $ra
    // 0x801C40F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C40F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c40f8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c40f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C40F8: andi        $a2, $zero, 0xFF
    ctx->r6 = 0 & 0XFF;
    // 0x801C40FC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4100: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c4104(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c4104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4108: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C410C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C4110: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C4114: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C4118: addiu       $v0, $v0, -0x3738
    ctx->r2 = ADD32(ctx->r2, -0X3738);
    // 0x801C411C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4124: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4128: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C412C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4130: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x801C4134: addiu       $a3, $a3, -0x125C
    ctx->r7 = ADD32(ctx->r7, -0X125C);
    // 0x801C4138: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C413C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4140: jal         0x8001B204
    // 0x801C4144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C4144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801C4148: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C414C: addiu       $a3, $a3, -0x1248
    ctx->r7 = ADD32(ctx->r7, -0X1248);
    // 0x801C4150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4154: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4158: jal         0x8001B204
    // 0x801C415C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C415C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_1:
    // 0x801C4160: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4164: addiu       $a3, $a3, -0x1234
    ctx->r7 = ADD32(ctx->r7, -0X1234);
    // 0x801C4168: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C416C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4170: jal         0x8001B204
    // 0x801C4174: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4174: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_2:
    // 0x801C4178: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C417C: addiu       $a3, $a3, -0x1220
    ctx->r7 = ADD32(ctx->r7, -0X1220);
    // 0x801C4180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4184: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4188: jal         0x8001B204
    // 0x801C418C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C418C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_3:
    // 0x801C4190: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4194: addiu       $a3, $a3, -0x120C
    ctx->r7 = ADD32(ctx->r7, -0X120C);
    // 0x801C4198: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C419C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C41A0: jal         0x8001B204
    // 0x801C41A4: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C41A4: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    after_4:
    // 0x801C41A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C41AC: addiu       $a3, $a3, -0x11F8
    ctx->r7 = ADD32(ctx->r7, -0X11F8);
    // 0x801C41B0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C41B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C41B8: jal         0x8001B204
    // 0x801C41BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C41BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801C41C0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C41C4: addiu       $a3, $a3, -0x11F4
    ctx->r7 = ADD32(ctx->r7, -0X11F4);
    // 0x801C41C8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C41CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C41D0: jal         0x8001B204
    // 0x801C41D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C41D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x801C41D8: jal         0x80152240
    // 0x801C41DC: nop

    LOOKUP_FUNC(0x80152240)(rdram, ctx);
        goto after_7;
    // 0x801C41DC: nop

    after_7:
    // 0x801C41E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C41E4: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x801C41E8: jal         0x800058DC
    // 0x801C41EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C41EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x801C41F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C41F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C41F8: jr          $ra
    // 0x801C41FC: nop

    return;
    // 0x801C41FC: nop

;}
RECOMP_FUNC void M23_FUN_801c4200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4208: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C420C: jal         0x801C1340
    // 0x801C4210: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C4210: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4214: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C4218: beq         $t6, $zero, L_801C4240
    if (ctx->r14 == 0) {
        // 0x801C421C: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C4240;
    }
    // 0x801C421C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4220: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4224: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4228: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801C422C: bne         $v0, $zero, L_801C423C
    if (ctx->r2 != 0) {
        // 0x801C4230: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C423C;
    }
    // 0x801C4230: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C4234: b           L_801C4240
    // 0x801C4238: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801C4240;
    // 0x801C4238: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C423C:
    // 0x801C423C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801C4240:
    // 0x801C4240: jal         0x801C1340
    // 0x801C4244: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C4244: nop

    after_1:
    // 0x801C4248: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C424C: beq         $t9, $zero, L_801C4278
    if (ctx->r25 == 0) {
        // 0x801C4250: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C4278;
    }
    // 0x801C4250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C4254: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4258: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C425C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C4264: bne         $v0, $at, L_801C4274
    if (ctx->r2 != ctx->r1) {
        // 0x801C4268: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801C4274;
    }
    // 0x801C4268: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801C426C: b           L_801C4278
    // 0x801C4270: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C4278;
    // 0x801C4270: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C4274:
    // 0x801C4274: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801C4278:
    // 0x801C4278: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C427C: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4280: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4284: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4288: addiu       $a3, $a3, -0x11F0
    ctx->r7 = ADD32(ctx->r7, -0X11F0);
    // 0x801C428C: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4290: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C4294: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4298: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C429C: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C42A0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C42A4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C42A8: jal         0x8001B204
    // 0x801C42AC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C42AC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_2:
    // 0x801C42B0: jal         0x801C1334
    // 0x801C42B4: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C42B4: nop

    after_3:
    // 0x801C42B8: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C42BC: beq         $t1, $zero, L_801C42D0
    if (ctx->r9 == 0) {
        // 0x801C42C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C42D0;
    }
    // 0x801C42C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C42C4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C42C8: jal         0x800058DC
    // 0x801C42CC: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C42CC: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_4:
L_801C42D0:
    // 0x801C42D0: jal         0x801C1334
    // 0x801C42D4: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C42D4: nop

    after_5:
    // 0x801C42D8: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C42DC: beq         $t2, $zero, L_801C43A0
    if (ctx->r10 == 0) {
        // 0x801C42E0: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C43A0;
    }
    // 0x801C42E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C42E4: lbu         $v0, -0x3738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3738);
    // 0x801C42E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C42EC: beq         $v0, $zero, L_801C4318
    if (ctx->r2 == 0) {
        // 0x801C42F0: nop
    
            goto L_801C4318;
    }
    // 0x801C42F0: nop

    // 0x801C42F4: beq         $v0, $at, L_801C4358
    if (ctx->r2 == ctx->r1) {
        // 0x801C42F8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C4358;
    }
    // 0x801C42F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C42FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4300: beq         $v0, $at, L_801C436C
    if (ctx->r2 == ctx->r1) {
        // 0x801C4304: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801C436C;
    }
    // 0x801C4304: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C4308: beq         $v0, $at, L_801C4394
    if (ctx->r2 == ctx->r1) {
        // 0x801C430C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C4394;
    }
    // 0x801C430C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C4310: b           L_801C43A4
    // 0x801C4314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C43A4;
    // 0x801C4314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4318:
    // 0x801C4318: jal         0x800023A8
    // 0x801C431C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_6;
    // 0x801C431C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801C4320: jal         0x80020718
    // 0x801C4324: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_7;
    // 0x801C4324: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x801C4328: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801C432C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x801C4330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C4334: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C4338: jal         0x8012FE50
    // 0x801C433C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_8;
    // 0x801C433C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x801C4340: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4344: addiu       $a1, $a1, 0x43B0
    ctx->r5 = ADD32(ctx->r5, 0X43B0);
    // 0x801C4348: jal         0x800058DC
    // 0x801C434C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C434C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x801C4350: b           L_801C43A4
    // 0x801C4354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C43A4;
    // 0x801C4354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4358:
    // 0x801C4358: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C435C: jal         0x800058DC
    // 0x801C4360: addiu       $a1, $a1, 0x43BC
    ctx->r5 = ADD32(ctx->r5, 0X43BC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C4360: addiu       $a1, $a1, 0x43BC
    ctx->r5 = ADD32(ctx->r5, 0X43BC);
    after_10:
    // 0x801C4364: b           L_801C43A4
    // 0x801C4368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C43A4;
    // 0x801C4368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C436C:
    // 0x801C436C: jal         0x800023A8
    // 0x801C4370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_11;
    // 0x801C4370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x801C4374: jal         0x80020718
    // 0x801C4378: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_12;
    // 0x801C4378: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_12:
    // 0x801C437C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4380: addiu       $a1, $a1, 0x47D0
    ctx->r5 = ADD32(ctx->r5, 0X47D0);
    // 0x801C4384: jal         0x800058DC
    // 0x801C4388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x801C4388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x801C438C: b           L_801C43A4
    // 0x801C4390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C43A4;
    // 0x801C4390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4394:
    // 0x801C4394: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4398: jal         0x800058DC
    // 0x801C439C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x801C439C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_14:
L_801C43A0:
    // 0x801C43A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C43A4:
    // 0x801C43A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C43A8: jr          $ra
    // 0x801C43AC: nop

    return;
    // 0x801C43AC: nop

;}
RECOMP_FUNC void M23_FUN_801c43b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C43B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C43B4: jr          $ra
    // 0x801C43B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C43B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c43bc(rdram, ctx);
;}
