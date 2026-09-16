#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80127924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80127928: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012792C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80127930: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80127934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80127938: jal         0x80005F6C
    // 0x8012793C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x8012793C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80127940: jal         0x80006214
    // 0x80127944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80127944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80127948: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8012794C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80127950: addiu       $t6, $t6, -0x4898
    ctx->r14 = ADD32(ctx->r14, -0X4898);
    // 0x80127954: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80127958: addiu       $t9, $zero, -0x3
    ctx->r25 = ADD32(0, -0X3);
    // 0x8012795C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80127960: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80127964: addiu       $a1, $a1, 0x798C
    ctx->r5 = ADD32(ctx->r5, 0X798C);
    // 0x80127968: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x8012796C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80127970: sw          $t9, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r25;
    // 0x80127974: jal         0x800058DC
    // 0x80127978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80127978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8012797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80127980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80127984: jr          $ra
    // 0x80127988: nop

    return;
    // 0x80127988: nop

;}
RECOMP_FUNC void M7_FUN_8012798c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012798C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80127990: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80127994: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80127998: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8012799C: lw          $ra, 0xE8($v1)
    ctx->r31 = MEM_W(ctx->r3, 0XE8);
    // 0x801279A0: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x801279A4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x801279A8: beq         $ra, $zero, L_80127D5C
    if (ctx->r31 == 0) {
        // 0x801279AC: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80127D5C;
    }
    // 0x801279AC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801279B0: addiu       $v0, $v0, -0x32A8
    ctx->r2 = ADD32(ctx->r2, -0X32A8);
    // 0x801279B4: lb          $t6, 0xF26($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XF26);
    // 0x801279B8: lb          $t8, 0xF27($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XF27);
    // 0x801279BC: lbu         $a1, 0xF20($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XF20);
    // 0x801279C0: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x801279C4: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x801279C8: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x801279CC: sb          $t8, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r24;
    // 0x801279D0: lb          $t6, 0xF28($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XF28);
    // 0x801279D4: lb          $t8, 0xF2C($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XF2C);
    // 0x801279D8: lbu         $a2, 0xF21($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0XF21);
    // 0x801279DC: lbu         $a3, 0xF22($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0XF22);
    // 0x801279E0: lbu         $t0, 0xF23($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF23);
    // 0x801279E4: lbu         $t1, 0xF24($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF24);
    // 0x801279E8: lbu         $t2, 0xF25($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF25);
    // 0x801279EC: lbu         $t3, 0xF29($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF29);
    // 0x801279F0: lbu         $t4, 0xF2A($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF2A);
    // 0x801279F4: lbu         $t5, 0xF2B($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF2B);
    // 0x801279F8: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x801279FC: sb          $t6, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r14;
    // 0x80127A00: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80127A04: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
    // 0x80127A08: lb          $t6, 0xF2D($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XF2D);
    // 0x80127A0C: lb          $t8, 0xF2E($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XF2E);
    // 0x80127A10: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80127A14: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x80127A18: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x80127A1C: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x80127A20: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x80127A24: sb          $zero, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = 0;
    // 0x80127A28: sb          $zero, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = 0;
    // 0x80127A2C: sb          $zero, 0x23($v0)
    MEM_B(0X23, ctx->r2) = 0;
    // 0x80127A30: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80127A34: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80127A38: sb          $a1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r5;
    // 0x80127A3C: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x80127A40: sb          $a2, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r6;
    // 0x80127A44: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // 0x80127A48: sb          $a3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r7;
    // 0x80127A4C: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x80127A50: sb          $t0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r8;
    // 0x80127A54: sb          $t1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r9;
    // 0x80127A58: sb          $t1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r9;
    // 0x80127A5C: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
    // 0x80127A60: sb          $t2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r10;
    // 0x80127A64: sb          $t3, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r11;
    // 0x80127A68: sb          $t3, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r11;
    // 0x80127A6C: sb          $t4, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r12;
    // 0x80127A70: sb          $t4, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r12;
    // 0x80127A74: sb          $t5, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r13;
    // 0x80127A78: sb          $t5, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r13;
    // 0x80127A7C: sb          $t6, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r14;
    // 0x80127A80: sb          $t8, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r24;
    // 0x80127A84: lh          $a0, -0x6CB4($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X6CB4);
    // 0x80127A88: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80127A8C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80127A90: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80127A94: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80127A98: addiu       $t8, $t7, 0xF50
    ctx->r24 = ADD32(ctx->r15, 0XF50);
    // 0x80127A9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80127AA0: sw          $t8, -0x32B8($at)
    MEM_W(-0X32B8, ctx->r1) = ctx->r24;
    // 0x80127AA4: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x80127AA8: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80127AAC: addiu       $t7, $t6, 0xF90
    ctx->r15 = ADD32(ctx->r14, 0XF90);
    // 0x80127AB0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80127AB4: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x80127AB8: sw          $t7, -0x32B4($at)
    MEM_W(-0X32B4, ctx->r1) = ctx->r15;
    // 0x80127ABC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80127AC0: addiu       $t6, $t9, 0xFB0
    ctx->r14 = ADD32(ctx->r25, 0XFB0);
    // 0x80127AC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80127AC8: sw          $t6, -0x32B0($at)
    MEM_W(-0X32B0, ctx->r1) = ctx->r14;
    // 0x80127ACC: lhu         $t7, 0x168($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X168);
    // 0x80127AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80127AD4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80127AD8: bne         $t7, $at, L_80127BA8
    if (ctx->r15 != ctx->r1) {
        // 0x80127ADC: sw          $t7, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r15;
            goto L_80127BA8;
    }
    // 0x80127ADC: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80127AE0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80127AE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80127AE8: lui         $at, 0xC25C
    ctx->r1 = S32(0XC25C << 16);
    // 0x80127AEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80127AF0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80127AF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80127AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80127AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80127B00: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80127B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80127B08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80127B0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80127B10: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80127B14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80127B18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80127B1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80127B20: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80127B24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80127B28: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80127B2C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80127B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80127B34: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80127B38: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80127B3C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80127B40: addiu       $t2, $t2, -0x32B0
    ctx->r10 = ADD32(ctx->r10, -0X32B0);
    // 0x80127B44: addiu       $t1, $t1, -0x32B4
    ctx->r9 = ADD32(ctx->r9, -0X32B4);
    // 0x80127B48: addiu       $t0, $t0, -0x32B8
    ctx->r8 = ADD32(ctx->r8, -0X32B8);
    // 0x80127B4C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80127B50: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80127B54: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80127B58: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80127B5C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80127B60: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80127B64: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80127B68: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80127B6C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80127B70: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80127B74: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80127B78: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80127B7C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80127B80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80127B84: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80127B88: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80127B8C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80127B90: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80127B94: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80127B98: jal         0x80030388
    // 0x80127B9C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80030388)(rdram, ctx);
        goto after_0;
    // 0x80127B9C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80127BA0: b           L_80127D60
    // 0x80127BA4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80127D60;
    // 0x80127BA4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80127BA8:
    // 0x80127BA8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80127BAC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80127BB0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80127BB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80127BB8: addiu       $t2, $t2, -0x32B0
    ctx->r10 = ADD32(ctx->r10, -0X32B0);
    // 0x80127BBC: addiu       $t1, $t1, -0x32B4
    ctx->r9 = ADD32(ctx->r9, -0X32B4);
    // 0x80127BC0: bne         $t7, $at, L_80127C94
    if (ctx->r15 != ctx->r1) {
        // 0x80127BC4: addiu       $t0, $t0, -0x32B8
        ctx->r8 = ADD32(ctx->r8, -0X32B8);
            goto L_80127C94;
    }
    // 0x80127BC4: addiu       $t0, $t0, -0x32B8
    ctx->r8 = ADD32(ctx->r8, -0X32B8);
    // 0x80127BC8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80127BCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80127BD0: lb          $t8, 0xF2F($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XF2F);
    // 0x80127BD4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80127BD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80127BDC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80127BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80127BE4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80127BE8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80127BEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80127BF0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80127BF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80127BF8: lb          $t9, 0xF30($v1)
    ctx->r25 = MEM_B(ctx->r3, 0XF30);
    // 0x80127BFC: lb          $t6, 0xF31($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XF31);
    // 0x80127C00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80127C04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80127C08: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80127C0C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80127C10: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80127C14: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80127C18: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80127C1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80127C20: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80127C24: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80127C28: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80127C2C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80127C30: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80127C34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80127C38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80127C3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80127C40: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80127C44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80127C48: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80127C4C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80127C50: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80127C54: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80127C58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80127C5C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80127C60: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80127C64: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80127C68: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80127C6C: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x80127C70: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80127C74: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80127C78: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80127C7C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80127C80: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80127C84: jal         0x80030388
    // 0x80127C88: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80030388)(rdram, ctx);
        goto after_1;
    // 0x80127C88: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80127C8C: b           L_80127D60
    // 0x80127C90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80127D60;
    // 0x80127C90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80127C94:
    // 0x80127C94: lw          $v0, 0x2C($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X2C);
    // 0x80127C98: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80127C9C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80127CA0: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80127CA4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80127CA8: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x80127CAC: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80127CB0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80127CB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80127CB8: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x80127CBC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80127CC0: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80127CC4: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80127CC8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80127CCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80127CD0: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80127CD4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80127CD8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80127CDC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80127CE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80127CE4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80127CE8: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80127CEC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80127CF0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80127CF4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80127CF8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80127CFC: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80127D00: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80127D04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80127D08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80127D0C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80127D10: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80127D14: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80127D18: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80127D1C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80127D20: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80127D24: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80127D28: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80127D2C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80127D30: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80127D34: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80127D38: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80127D3C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80127D40: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80127D44: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80127D48: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80127D4C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80127D50: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80127D54: jal         0x80030388
    // 0x80127D58: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80030388)(rdram, ctx);
        goto after_2;
    // 0x80127D58: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    after_2:
L_80127D5C:
    // 0x80127D5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80127D60:
    // 0x80127D60: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80127D64: jr          $ra
    // 0x80127D68: nop

    return;
    // 0x80127D68: nop

;}
RECOMP_FUNC void M7_FUN_80127d6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127D6C: nop

;}
RECOMP_FUNC void M7_FUN_80127d70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127D70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80127D74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80127D78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80127D7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80127D80: addiu       $t6, $zero, 0xF8
    ctx->r14 = ADD32(0, 0XF8);
    // 0x80127D84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80127D88: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    // 0x80127D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80127D90: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80127D94: jal         0x8012C89C
    // 0x80127D98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80127D98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80127D9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80127DA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80127DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80127DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80127DAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80127DB0: jal         0x8012D814
    // 0x80127DB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_1;
    // 0x80127DB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80127DB8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80127DBC: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x80127DC0: ori         $t8, $t8, 0x12
    ctx->r24 = ctx->r24 | 0X12;
    // 0x80127DC4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80127DC8: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80127DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80127DD0: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x80127DD4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80127DD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80127DDC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80127DE0: jal         0x8012F41C
    // 0x80127DE4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8012F41C)(rdram, ctx);
        goto after_2;
    // 0x80127DE4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80127DE8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80127DEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80127DF0: or          $t2, $v0, $at
    ctx->r10 = ctx->r2 | ctx->r1;
    // 0x80127DF4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80127DF8: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80127DFC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80127E00: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80127E04: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80127E08: ori         $t7, $t7, 0x300
    ctx->r15 = ctx->r15 | 0X300;
    // 0x80127E0C: sw          $t3, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r11;
    // 0x80127E10: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80127E14: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80127E18: addiu       $a1, $a1, 0x7E3C
    ctx->r5 = ADD32(ctx->r5, 0X7E3C);
    // 0x80127E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80127E20: jal         0x800058DC
    // 0x80127E24: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80127E24: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    after_3:
    // 0x80127E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80127E2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80127E30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80127E34: jr          $ra
    // 0x80127E38: nop

    return;
    // 0x80127E38: nop

;}
RECOMP_FUNC void M7_FUN_80127e3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127E3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80127E40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80127E44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80127E48: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80127E4C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80127E50: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80127E54: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80127E58: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80127E5C: bgez        $t6, L_80127E78
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80127E60: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_80127E78;
    }
    // 0x80127E60: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80127E64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80127E68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80127E6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80127E70: nop

    // 0x80127E74: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_80127E78:
    // 0x80127E78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80127E7C: ldc1        $f10, -0x33D8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X33D8);
    // 0x80127E80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80127E84: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80127E88: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x80127E8C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80127E90: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80127E94: nop

    // 0x80127E98: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x80127E9C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80127EA0: nop

    // 0x80127EA4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80127EA8: beql        $t8, $zero, L_80127EFC
    if (ctx->r24 == 0) {
        // 0x80127EAC: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_80127EFC;
    }
    goto skip_0;
    // 0x80127EAC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80127EB0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80127EB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80127EB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80127EBC: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x80127EC0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80127EC4: nop

    // 0x80127EC8: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80127ECC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80127ED0: nop

    // 0x80127ED4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80127ED8: bne         $t8, $zero, L_80127EF0
    if (ctx->r24 != 0) {
        // 0x80127EDC: nop
    
            goto L_80127EF0;
    }
    // 0x80127EDC: nop

    // 0x80127EE0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80127EE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80127EE8: b           L_80127F08
    // 0x80127EEC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80127F08;
    // 0x80127EEC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80127EF0:
    // 0x80127EF0: b           L_80127F08
    // 0x80127EF4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80127F08;
    // 0x80127EF4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80127EF8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_80127EFC:
    // 0x80127EFC: nop

    // 0x80127F00: bltz        $t8, L_80127EF0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80127F04: nop
    
            goto L_80127EF0;
    }
    // 0x80127F04: nop

L_80127F08:
    // 0x80127F08: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80127F0C: sb          $t8, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r24;
    // 0x80127F10: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80127F14: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80127F18: jal         0x8012F41C
    // 0x80127F1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012F41C)(rdram, ctx);
        goto after_0;
    // 0x80127F1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80127F20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80127F24: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80127F28: lbu         $t0, 0x90($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X90);
    // 0x80127F2C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80127F30: bgez        $t0, L_80127F48
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80127F34: cvt.d.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
            goto L_80127F48;
    }
    // 0x80127F34: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x80127F38: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80127F3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80127F40: nop

    // 0x80127F44: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_80127F48:
    // 0x80127F48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80127F4C: ldc1        $f10, -0x33D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X33D0);
    // 0x80127F50: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80127F54: nop

    // 0x80127F58: bc1fl       L_80127F6C
    if (!c1cs) {
        // 0x80127F5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80127F6C;
    }
    goto skip_1;
    // 0x80127F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80127F60: jal         0x80005700
    // 0x80127F64: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80127F64: nop

    after_1:
    // 0x80127F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80127F6C:
    // 0x80127F6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80127F70: jr          $ra
    // 0x80127F74: nop

    return;
    // 0x80127F74: nop

;}
RECOMP_FUNC void M7_FUN_80127f78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80127F7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80127F80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80127F84: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80127F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80127F8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80127F90: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80127F94: bne         $v0, $zero, L_80128018
    if (ctx->r2 != 0) {
        // 0x80127F98: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80128018;
    }
    // 0x80127F98: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80127F9C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80127FA0: jal         0x8012C89C
    // 0x80127FA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80127FA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80127FA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80127FAC: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x80127FB0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80127FB4: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80127FB8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80127FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80127FC0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80127FC4: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x80127FC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80127FCC: jal         0x8012D814
    // 0x80127FD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_1;
    // 0x80127FD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80127FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80127FD8: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
    // 0x80127FDC: ori         $t0, $t0, 0x100
    ctx->r8 = ctx->r8 | 0X100;
    // 0x80127FE0: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x80127FE4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80127FE8: addiu       $t3, $t3, -0x4C20
    ctx->r11 = ADD32(ctx->r11, -0X4C20);
    // 0x80127FEC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80127FF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80127FF4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80127FF8: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80127FFC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80128000: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80128004: addiu       $a1, $a1, -0x7FD8
    ctx->r5 = ADD32(ctx->r5, -0X7FD8);
    // 0x80128008: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8012800C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80128010: jal         0x800058DC
    // 0x80128014: sw          $t4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80128014: sw          $t4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r12;
    after_2:
L_80128018:
    // 0x80128018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012801C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80128020: jr          $ra
    // 0x80128024: nop

    return;
    // 0x80128024: nop

;}
RECOMP_FUNC void M7_FUN_80128028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012802C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80128030: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80128034: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80128038: bne         $t7, $zero, L_8012805C
    if (ctx->r15 != 0) {
        // 0x8012803C: nop
    
            goto L_8012805C;
    }
    // 0x8012803C: nop

    // 0x80128040: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80128044: lbu         $t0, 0x93($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X93);
    // 0x80128048: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8012804C: lbu         $t9, 0x4B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4B);
    // 0x80128050: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80128054: beql        $at, $zero, L_80128070
    if (ctx->r1 == 0) {
        // 0x80128058: lbu         $t1, 0x48($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X48);
            goto L_80128070;
    }
    goto skip_0;
    // 0x80128058: lbu         $t1, 0x48($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X48);
    skip_0:
L_8012805C:
    // 0x8012805C: jal         0x80005700
    // 0x80128060: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80128060: nop

    after_0:
    // 0x80128064: b           L_801280C8
    // 0x80128068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801280C8;
    // 0x80128068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012806C: lbu         $t1, 0x48($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X48);
L_80128070:
    // 0x80128070: lbu         $t2, 0x90($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X90);
    // 0x80128074: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80128078: sb          $t3, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r11;
    // 0x8012807C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80128080: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x80128084: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80128088: lbu         $t5, 0x49($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X49);
    // 0x8012808C: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80128090: sb          $t7, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r15;
    // 0x80128094: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80128098: lbu         $t0, 0x92($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X92);
    // 0x8012809C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801280A0: lbu         $t9, 0x4A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4A);
    // 0x801280A4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x801280A8: sb          $t1, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r9;
    // 0x801280AC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801280B0: lbu         $t4, 0x93($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X93);
    // 0x801280B4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801280B8: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x801280BC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x801280C0: sb          $t5, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r13;
    // 0x801280C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801280C8:
    // 0x801280C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801280CC: jr          $ra
    // 0x801280D0: nop

    return;
    // 0x801280D0: nop

;}
RECOMP_FUNC void M7_FUN_801280d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801280D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801280D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801280DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801280E0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801280E4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801280E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801280EC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801280F0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801280F4: bne         $v0, $zero, L_801281F4
    if (ctx->r2 != 0) {
        // 0x801280F8: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801281F4;
    }
    // 0x801280F8: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801280FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80128100: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80128104: jal         0x8012C89C
    // 0x80128108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80128108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x8012810C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80128110: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80128114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8012811C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80128120: jal         0x8012D814
    // 0x80128124: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_1;
    // 0x80128124: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80128128: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8012812C: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x80128130: ori         $t8, $t8, 0x300
    ctx->r24 = ctx->r24 | 0X300;
    // 0x80128134: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80128138: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8012813C: addiu       $t1, $t1, -0x4B08
    ctx->r9 = ADD32(ctx->r9, -0X4B08);
    // 0x80128140: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x80128144: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80128148: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8012814C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80128150: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80128154: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    // 0x80128158: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8012815C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128160: jal         0x8012C6B4
    // 0x80128164: sb          $t4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r12;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80128164: sb          $t4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r12;
    after_2:
    // 0x80128168: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8012816C: addiu       $t7, $v0, 0xE0
    ctx->r15 = ADD32(ctx->r2, 0XE0);
    // 0x80128170: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80128174: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80128178: jal         0x8012C6B4
    // 0x8012817C: sb          $t7, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x8012817C: sb          $t7, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r15;
    after_3:
    // 0x80128180: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80128184: addiu       $t0, $v0, 0xE0
    ctx->r8 = ADD32(ctx->r2, 0XE0);
    // 0x80128188: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8012818C: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80128190: jal         0x8012C6B4
    // 0x80128194: sb          $t0, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80128194: sb          $t0, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r8;
    after_4:
    // 0x80128198: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8012819C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x801281A0: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801281A4: jal         0x8012C6B4
    // 0x801281A8: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801281A8: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    after_5:
    // 0x801281AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801281B0: addiu       $t4, $v0, 0xE0
    ctx->r12 = ADD32(ctx->r2, 0XE0);
    // 0x801281B4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x801281B8: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x801281BC: jal         0x8012C6B4
    // 0x801281C0: sb          $t4, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r12;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801281C0: sb          $t4, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r12;
    after_6:
    // 0x801281C4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801281C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x801281CC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801281D0: jal         0x8012C6B4
    // 0x801281D4: sb          $v0, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x801281D4: sb          $v0, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r2;
    after_7:
    // 0x801281D8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801281DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801281E0: addiu       $a1, $a1, -0x7DF8
    ctx->r5 = ADD32(ctx->r5, -0X7DF8);
    // 0x801281E4: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x801281E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801281EC: jal         0x800058DC
    // 0x801281F0: sb          $v0, 0x4E($t0)
    MEM_B(0X4E, ctx->r8) = ctx->r2;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801281F0: sb          $v0, 0x4E($t0)
    MEM_B(0X4E, ctx->r8) = ctx->r2;
    after_8:
L_801281F4:
    // 0x801281F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801281F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801281FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80128200: jr          $ra
    // 0x80128204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80128204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80128208(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80128208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012820C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80128210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80128214: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80128218: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8012821C: beql        $t7, $zero, L_80128230
    if (ctx->r15 == 0) {
        // 0x80128220: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80128230;
    }
    goto skip_0;
    // 0x80128220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80128224: jal         0x80005700
    // 0x80128228: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80128228: nop

    after_0:
    // 0x8012822C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80128230:
    // 0x80128230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80128234: jr          $ra
    // 0x80128238: nop

    return;
    // 0x80128238: nop

;}
RECOMP_FUNC void M7_FUN_8012823c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012823C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80128240: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80128244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80128248: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012824C: addiu       $t6, $zero, 0xF8
    ctx->r14 = ADD32(0, 0XF8);
    // 0x80128250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80128254: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    // 0x80128258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8012825C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80128260: jal         0x8012C89C
    // 0x80128264: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80128264: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80128268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012826C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80128270: jal         0x8012D844
    // 0x80128274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x80128274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80128278: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8012827C: lui         $t7, 0x6
    ctx->r15 = S32(0X6 << 16);
    // 0x80128280: ori         $t7, $t7, 0xF
    ctx->r15 = ctx->r15 | 0XF;
    // 0x80128284: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80128288: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x8012828C: jal         0x8000C3B0
    // 0x80128290: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_2;
    // 0x80128290: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x80128294: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80128298: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8012829C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801282A0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801282A4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x801282A8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801282AC: sw          $v0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r2;
    // 0x801282B0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801282B4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801282B8: sb          $t3, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r11;
    // 0x801282BC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801282C0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801282C4: sb          $v1, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r3;
    // 0x801282C8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801282CC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801282D0: sb          $zero, 0x49($t9)
    MEM_B(0X49, ctx->r25) = 0;
    // 0x801282D4: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801282D8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801282DC: sb          $v1, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r3;
    // 0x801282E0: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x801282E4: ori         $t4, $t2, 0x20
    ctx->r12 = ctx->r10 | 0X20;
    // 0x801282E8: jal         0x8012C6B4
    // 0x801282EC: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801282EC: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    after_3:
    // 0x801282F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801282F4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801282F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801282FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80128300: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80128304: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128308: ldc1        $f18, -0x33C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X33C8);
    // 0x8012830C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128310: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80128314: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80128318: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8012831C: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80128320: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80128324: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80128328: lwc1        $f8, -0x33C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X33C0);
    // 0x8012832C: jal         0x8012C6B4
    // 0x80128330: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80128330: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80128334: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80128338: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8012833C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80128340: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80128344: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80128348: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012834C: ldc1        $f8, -0x33B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X33B8);
    // 0x80128350: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80128354: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80128358: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8012835C: addiu       $a1, $a1, -0x7C54
    ctx->r5 = ADD32(ctx->r5, -0X7C54);
    // 0x80128360: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80128364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128368: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8012836C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128370: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80128374: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80128378: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8012837C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128380: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x80128384: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80128388: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8012838C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80128390: jal         0x800058DC
    // 0x80128394: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80128394: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    after_5:
    // 0x80128398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012839C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801283A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801283A4: jr          $ra
    // 0x801283A8: nop

    return;
    // 0x801283A8: nop

;}
RECOMP_FUNC void M7_FUN_801283ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801283AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801283B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801283B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801283B8: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801283BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801283C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801283C4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801283C8: bgez        $t6, L_801283E0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801283CC: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801283E0;
    }
    // 0x801283CC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801283D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801283D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801283D8: nop

    // 0x801283DC: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801283E0:
    // 0x801283E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801283E4: ldc1        $f10, -0x33B0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X33B0);
    // 0x801283E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801283EC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801283F0: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x801283F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801283F8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801283FC: nop

    // 0x80128400: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x80128404: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80128408: nop

    // 0x8012840C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80128410: beql        $t8, $zero, L_80128464
    if (ctx->r24 == 0) {
        // 0x80128414: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_80128464;
    }
    goto skip_0;
    // 0x80128414: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80128418: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8012841C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80128420: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80128424: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x80128428: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8012842C: nop

    // 0x80128430: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80128434: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80128438: nop

    // 0x8012843C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80128440: bne         $t8, $zero, L_80128458
    if (ctx->r24 != 0) {
        // 0x80128444: nop
    
            goto L_80128458;
    }
    // 0x80128444: nop

    // 0x80128448: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8012844C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80128450: b           L_80128470
    // 0x80128454: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80128470;
    // 0x80128454: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80128458:
    // 0x80128458: b           L_80128470
    // 0x8012845C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80128470;
    // 0x8012845C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80128460: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_80128464:
    // 0x80128464: nop

    // 0x80128468: bltz        $t8, L_80128458
    if (SIGNED(ctx->r24) < 0) {
        // 0x8012846C: nop
    
            goto L_80128458;
    }
    // 0x8012846C: nop

L_80128470:
    // 0x80128470: sb          $t8, 0x90($a2)
    MEM_B(0X90, ctx->r6) = ctx->r24;
    // 0x80128474: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80128478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8012847C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80128480: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80128484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80128488: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012848C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80128490: sb          $t8, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r24;
    // 0x80128494: lwc1        $f0, 0x94($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128498: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8012849C: nop

    // 0x801284A0: bc1fl       L_801284C0
    if (!c1cs) {
        // 0x801284A4: lw          $t3, 0x24($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X24);
            goto L_801284C0;
    }
    goto skip_1;
    // 0x801284A4: lw          $t3, 0x24($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X24);
    skip_1:
    // 0x801284A8: ldc1        $f6, -0x33A8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X33A8);
    // 0x801284AC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801284B0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x801284B4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801284B8: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
    // 0x801284BC: lw          $t3, 0x24($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X24);
L_801284C0:
    // 0x801284C0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801284C4: lbu         $v1, 0x4A($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4A);
    // 0x801284C8: beq         $v1, $zero, L_801284D4
    if (ctx->r3 == 0) {
        // 0x801284CC: addiu       $t4, $v1, -0x5
        ctx->r12 = ADD32(ctx->r3, -0X5);
            goto L_801284D4;
    }
    // 0x801284CC: addiu       $t4, $v1, -0x5
    ctx->r12 = ADD32(ctx->r3, -0X5);
    // 0x801284D0: sb          $t4, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r12;
L_801284D4:
    // 0x801284D4: lh          $t5, 0x92($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X92);
    // 0x801284D8: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x801284DC: sh          $t6, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r14;
    // 0x801284E0: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
    // 0x801284E4: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
    // 0x801284E8: beq         $at, $zero, L_801284F8
    if (ctx->r1 == 0) {
        // 0x801284EC: addiu       $t7, $v0, -0x168
        ctx->r15 = ADD32(ctx->r2, -0X168);
            goto L_801284F8;
    }
    // 0x801284EC: addiu       $t7, $v0, -0x168
    ctx->r15 = ADD32(ctx->r2, -0X168);
    // 0x801284F0: sh          $t7, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r15;
    // 0x801284F4: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
L_801284F8:
    // 0x801284F8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801284FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128500: ldc1        $f8, -0x33A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X33A0);
    // 0x80128504: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80128508: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8012850C: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80128510: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80128514: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80128518: nop

    // 0x8012851C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80128520: jal         0x8001EAD0
    // 0x80128524: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80128524: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80128528: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012852C: ldc1        $f16, -0x3398($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3398);
    // 0x80128530: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80128534: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80128538: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8012853C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128540: ldc1        $f8, -0x3390($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3390);
    // 0x80128544: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128548: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8012854C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128550: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80128554: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80128558: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8012855C: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80128560: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x80128564: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80128568: swc1        $f8, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f8.u32l;
    // 0x8012856C: lh          $t2, 0x92($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X92);
    // 0x80128570: ldc1        $f16, -0x3388($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3388);
    // 0x80128574: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80128578: nop

    // 0x8012857C: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x80128580: div.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x80128584: trunc.w.d   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80128588: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8012858C: nop

    // 0x80128590: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80128594: jal         0x8001EB64
    // 0x80128598: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80128598: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8012859C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801285A0: ldc1        $f8, -0x3380($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3380);
    // 0x801285A4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801285A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801285AC: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801285B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801285B4: ldc1        $f16, -0x3378($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3378);
    // 0x801285B8: lwc1        $f18, 0x94($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X94);
    // 0x801285BC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801285C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801285C4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801285C8: add.d       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f16.d + ctx->f10.d;
    // 0x801285CC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801285D0: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801285D4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801285D8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x801285DC: swc1        $f16, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f16.u32l;
    // 0x801285E0: lbu         $t7, 0x90($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X90);
    // 0x801285E4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801285E8: bgez        $t7, L_80128600
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801285EC: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_80128600;
    }
    // 0x801285EC: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x801285F0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801285F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801285F8: nop

    // 0x801285FC: add.d       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f18.d + ctx->f8.d;
L_80128600:
    // 0x80128600: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128604: ldc1        $f6, -0x3370($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3370);
    // 0x80128608: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8012860C: nop

    // 0x80128610: bc1fl       L_80128624
    if (!c1cs) {
        // 0x80128614: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80128624;
    }
    goto skip_2;
    // 0x80128614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80128618: jal         0x80005700
    // 0x8012861C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x8012861C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80128620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80128624:
    // 0x80128624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80128628: jr          $ra
    // 0x8012862C: nop

    return;
    // 0x8012862C: nop

;}
RECOMP_FUNC void M7_FUN_80128630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80128634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80128638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8012863C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80128640: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80128644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80128648: addiu       $t7, $zero, 0xF8
    ctx->r15 = ADD32(0, 0XF8);
    // 0x8012864C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80128650: bne         $v0, $zero, L_80128700
    if (ctx->r2 != 0) {
        // 0x80128654: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80128700;
    }
    // 0x80128654: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80128658: sb          $t7, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r15;
    // 0x8012865C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80128660: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80128664: jal         0x8012C89C
    // 0x80128668: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80128668: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x8012866C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80128674: jal         0x8012D844
    // 0x80128678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x80128678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8012867C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80128680: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x80128684: ori         $t8, $t8, 0xF
    ctx->r24 = ctx->r24 | 0XF;
    // 0x80128688: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8012868C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x80128690: jal         0x8000C3B0
    // 0x80128694: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_2;
    // 0x80128694: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x80128698: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8012869C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801286A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801286A4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801286A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801286AC: addiu       $a1, $a1, -0x78EC
    ctx->r5 = ADD32(ctx->r5, -0X78EC);
    // 0x801286B0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801286B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801286B8: sw          $v0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r2;
    // 0x801286BC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801286C0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801286C4: sb          $t3, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r11;
    // 0x801286C8: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x801286CC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x801286D0: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x801286D4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801286D8: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801286DC: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x801286E0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801286E4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801286E8: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801286EC: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801286F0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801286F4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801286F8: jal         0x800058DC
    // 0x801286FC: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801286FC: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    after_3:
L_80128700:
    // 0x80128700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80128704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80128708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012870C: jr          $ra
    // 0x80128710: nop

    return;
    // 0x80128710: nop

;}
RECOMP_FUNC void M7_FUN_80128714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80128718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012871C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80128720: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80128724: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80128728: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8012872C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80128730: bgez        $t6, L_80128748
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80128734: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_80128748;
    }
    // 0x80128734: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80128738: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8012873C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80128740: nop

    // 0x80128744: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_80128748:
    // 0x80128748: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012874C: ldc1        $f10, -0x3368($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3368);
    // 0x80128750: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80128754: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80128758: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x8012875C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80128760: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80128764: nop

    // 0x80128768: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8012876C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80128770: nop

    // 0x80128774: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80128778: beql        $t8, $zero, L_801287CC
    if (ctx->r24 == 0) {
        // 0x8012877C: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_801287CC;
    }
    goto skip_0;
    // 0x8012877C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80128780: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80128784: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80128788: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8012878C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x80128790: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80128794: nop

    // 0x80128798: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8012879C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801287A0: nop

    // 0x801287A4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801287A8: bne         $t8, $zero, L_801287C0
    if (ctx->r24 != 0) {
        // 0x801287AC: nop
    
            goto L_801287C0;
    }
    // 0x801287AC: nop

    // 0x801287B0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x801287B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801287B8: b           L_801287D8
    // 0x801287BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801287D8;
    // 0x801287BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801287C0:
    // 0x801287C0: b           L_801287D8
    // 0x801287C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801287D8;
    // 0x801287C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801287C8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_801287CC:
    // 0x801287CC: nop

    // 0x801287D0: bltz        $t8, L_801287C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x801287D4: nop
    
            goto L_801287C0;
    }
    // 0x801287D4: nop

L_801287D8:
    // 0x801287D8: sb          $t8, 0x90($a2)
    MEM_B(0X90, ctx->r6) = ctx->r24;
    // 0x801287DC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801287E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801287E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801287E8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801287EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801287F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801287F4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801287F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801287FC: sb          $t8, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r24;
    // 0x80128800: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128804: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80128808: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8012880C: nop

    // 0x80128810: bc1fl       L_8012882C
    if (!c1cs) {
        // 0x80128814: lh          $t3, 0x92($a2)
        ctx->r11 = MEM_H(ctx->r6, 0X92);
            goto L_8012882C;
    }
    goto skip_1;
    // 0x80128814: lh          $t3, 0x92($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X92);
    skip_1:
    // 0x80128818: ldc1        $f6, -0x3360($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3360);
    // 0x8012881C: add.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d + ctx->f6.d;
    // 0x80128820: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128824: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
    // 0x80128828: lh          $t3, 0x92($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X92);
L_8012882C:
    // 0x8012882C: addiu       $t4, $t3, 0x5
    ctx->r12 = ADD32(ctx->r11, 0X5);
    // 0x80128830: sh          $t4, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r12;
    // 0x80128834: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
    // 0x80128838: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
    // 0x8012883C: beq         $at, $zero, L_8012884C
    if (ctx->r1 == 0) {
        // 0x80128840: addiu       $t5, $v0, -0x168
        ctx->r13 = ADD32(ctx->r2, -0X168);
            goto L_8012884C;
    }
    // 0x80128840: addiu       $t5, $v0, -0x168
    ctx->r13 = ADD32(ctx->r2, -0X168);
    // 0x80128844: sh          $t5, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r13;
    // 0x80128848: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
L_8012884C:
    // 0x8012884C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80128850: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128854: ldc1        $f8, -0x3358($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3358);
    // 0x80128858: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012885C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80128860: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80128864: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80128868: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8012886C: nop

    // 0x80128870: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80128874: jal         0x8001EAD0
    // 0x80128878: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80128878: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8012887C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128880: ldc1        $f16, -0x3350($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3350);
    // 0x80128884: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80128888: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8012888C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80128890: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128894: ldc1        $f8, -0x3348($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3348);
    // 0x80128898: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8012889C: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x801288A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801288A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801288A8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801288AC: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801288B0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801288B4: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x801288B8: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801288BC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801288C0: add.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d + ctx->f18.d;
    // 0x801288C4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801288C8: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x801288CC: lh          $t0, 0x92($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X92);
    // 0x801288D0: ldc1        $f4, -0x3340($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3340);
    // 0x801288D4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x801288D8: nop

    // 0x801288DC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801288E0: div.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x801288E4: trunc.w.d   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x801288E8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801288EC: nop

    // 0x801288F0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801288F4: jal         0x8001EB64
    // 0x801288F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801288F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801288FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128900: ldc1        $f16, -0x3338($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3338);
    // 0x80128904: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80128908: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8012890C: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80128910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128914: ldc1        $f4, -0x3330($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3330);
    // 0x80128918: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8012891C: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128920: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80128924: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80128928: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8012892C: add.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d + ctx->f8.d;
    // 0x80128930: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80128934: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80128938: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8012893C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80128940: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80128944: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128948: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x8012894C: lbu         $t3, 0x90($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X90);
    // 0x80128950: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80128954: bgez        $t3, L_8012896C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80128958: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_8012896C;
    }
    // 0x80128958: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012895C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80128960: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80128964: nop

    // 0x80128968: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_8012896C:
    // 0x8012896C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128970: ldc1        $f6, -0x3328($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3328);
    // 0x80128974: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80128978: nop

    // 0x8012897C: bc1fl       L_80128990
    if (!c1cs) {
        // 0x80128980: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80128990;
    }
    goto skip_2;
    // 0x80128980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80128984: jal         0x80005700
    // 0x80128988: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80128988: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8012898C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80128990:
    // 0x80128990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80128994: jr          $ra
    // 0x80128998: nop

    return;
    // 0x80128998: nop

;}
RECOMP_FUNC void M7_FUN_8012899c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012899C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801289A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801289A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801289A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801289AC: addiu       $t6, $zero, 0xF8
    ctx->r14 = ADD32(0, 0XF8);
    // 0x801289B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801289B4: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    // 0x801289B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801289BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801289C0: jal         0x8012C89C
    // 0x801289C4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x801289C4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x801289C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801289CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801289D0: jal         0x8012D844
    // 0x801289D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801289D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801289D8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801289DC: lui         $t7, 0x6
    ctx->r15 = S32(0X6 << 16);
    // 0x801289E0: ori         $t7, $t7, 0xF
    ctx->r15 = ctx->r15 | 0XF;
    // 0x801289E4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801289E8: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x801289EC: jal         0x8000C3B0
    // 0x801289F0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_2;
    // 0x801289F0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x801289F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801289F8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801289FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80128A00: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80128A04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80128A08: addiu       $a1, $a1, -0x7570
    ctx->r5 = ADD32(ctx->r5, -0X7570);
    // 0x80128A0C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80128A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128A14: sw          $v0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r2;
    // 0x80128A18: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80128A1C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80128A20: sb          $t2, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r10;
    // 0x80128A24: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80128A28: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128A2C: sb          $zero, 0x48($t6)
    MEM_B(0X48, ctx->r14) = 0;
    // 0x80128A30: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80128A34: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80128A38: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x80128A3C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80128A40: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80128A44: sb          $zero, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = 0;
    // 0x80128A48: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80128A4C: ori         $t3, $t1, 0x20
    ctx->r11 = ctx->r9 | 0X20;
    // 0x80128A50: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x80128A54: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80128A58: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80128A5C: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80128A60: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80128A64: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128A68: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80128A6C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80128A70: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80128A74: jal         0x800058DC
    // 0x80128A78: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80128A78: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    after_3:
    // 0x80128A7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80128A80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80128A84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80128A88: jr          $ra
    // 0x80128A8C: nop

    return;
    // 0x80128A8C: nop

;}
RECOMP_FUNC void M7_FUN_80128a90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80128A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80128A98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80128A9C: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80128AA0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80128AA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80128AA8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80128AAC: bgez        $t6, L_80128AC4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80128AB0: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_80128AC4;
    }
    // 0x80128AB0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80128AB4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80128AB8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80128ABC: nop

    // 0x80128AC0: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_80128AC4:
    // 0x80128AC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128AC8: ldc1        $f10, -0x3320($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3320);
    // 0x80128ACC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80128AD0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80128AD4: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x80128AD8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80128ADC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80128AE0: nop

    // 0x80128AE4: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x80128AE8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80128AEC: nop

    // 0x80128AF0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80128AF4: beql        $t8, $zero, L_80128B48
    if (ctx->r24 == 0) {
        // 0x80128AF8: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_80128B48;
    }
    goto skip_0;
    // 0x80128AF8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80128AFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80128B00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80128B04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80128B08: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x80128B0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80128B10: nop

    // 0x80128B14: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80128B18: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80128B1C: nop

    // 0x80128B20: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80128B24: bne         $t8, $zero, L_80128B3C
    if (ctx->r24 != 0) {
        // 0x80128B28: nop
    
            goto L_80128B3C;
    }
    // 0x80128B28: nop

    // 0x80128B2C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80128B30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80128B34: b           L_80128B54
    // 0x80128B38: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80128B54;
    // 0x80128B38: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80128B3C:
    // 0x80128B3C: b           L_80128B54
    // 0x80128B40: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80128B54;
    // 0x80128B40: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80128B44: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_80128B48:
    // 0x80128B48: nop

    // 0x80128B4C: bltz        $t8, L_80128B3C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80128B50: nop
    
            goto L_80128B3C;
    }
    // 0x80128B50: nop

L_80128B54:
    // 0x80128B54: sb          $t8, 0x90($a2)
    MEM_B(0X90, ctx->r6) = ctx->r24;
    // 0x80128B58: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80128B5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80128B60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128B64: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80128B68: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80128B6C: sb          $t8, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r24;
    // 0x80128B70: lwc1        $f4, 0x94($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128B74: ldc1        $f8, -0x3318($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3318);
    // 0x80128B78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128B7C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80128B80: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80128B84: nop

    // 0x80128B88: bc1fl       L_80128BA4
    if (!c1cs) {
        // 0x80128B8C: lh          $t3, 0x92($a2)
        ctx->r11 = MEM_H(ctx->r6, 0X92);
            goto L_80128BA4;
    }
    goto skip_1;
    // 0x80128B8C: lh          $t3, 0x92($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X92);
    skip_1:
    // 0x80128B90: ldc1        $f6, -0x3310($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3310);
    // 0x80128B94: add.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d + ctx->f6.d;
    // 0x80128B98: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128B9C: swc1        $f16, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f16.u32l;
    // 0x80128BA0: lh          $t3, 0x92($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X92);
L_80128BA4:
    // 0x80128BA4: addiu       $t4, $t3, 0x14
    ctx->r12 = ADD32(ctx->r11, 0X14);
    // 0x80128BA8: sh          $t4, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r12;
    // 0x80128BAC: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
    // 0x80128BB0: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
    // 0x80128BB4: beq         $at, $zero, L_80128BC4
    if (ctx->r1 == 0) {
        // 0x80128BB8: addiu       $t5, $v0, -0x168
        ctx->r13 = ADD32(ctx->r2, -0X168);
            goto L_80128BC4;
    }
    // 0x80128BB8: addiu       $t5, $v0, -0x168
    ctx->r13 = ADD32(ctx->r2, -0X168);
    // 0x80128BBC: sh          $t5, 0x92($a2)
    MEM_H(0X92, ctx->r6) = ctx->r13;
    // 0x80128BC0: lh          $v0, 0x92($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X92);
L_80128BC4:
    // 0x80128BC4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80128BC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128BCC: ldc1        $f8, -0x3308($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3308);
    // 0x80128BD0: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80128BD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80128BD8: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80128BDC: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80128BE0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80128BE4: nop

    // 0x80128BE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80128BEC: jal         0x8001EAD0
    // 0x80128BF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80128BF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80128BF4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80128BF8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80128BFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80128C00: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80128C04: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80128C08: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80128C0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128C10: ldc1        $f8, -0x3300($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3300);
    // 0x80128C14: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80128C18: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128C1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128C20: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80128C24: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80128C28: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80128C2C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80128C30: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80128C34: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80128C38: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80128C3C: add.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d + ctx->f18.d;
    // 0x80128C40: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128C44: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80128C48: lh          $t0, 0x92($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X92);
    // 0x80128C4C: ldc1        $f4, -0x32F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32F8);
    // 0x80128C50: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80128C54: nop

    // 0x80128C58: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80128C5C: div.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x80128C60: trunc.w.d   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80128C64: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80128C68: nop

    // 0x80128C6C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80128C70: jal         0x8001EB64
    // 0x80128C74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80128C74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80128C78: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80128C7C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80128C80: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80128C84: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80128C88: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80128C8C: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80128C90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128C94: ldc1        $f4, -0x32F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X32F0);
    // 0x80128C98: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80128C9C: lwc1        $f10, 0x94($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X94);
    // 0x80128CA0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80128CA4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80128CA8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80128CAC: add.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d + ctx->f8.d;
    // 0x80128CB0: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80128CB4: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80128CB8: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80128CBC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80128CC0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80128CC4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80128CC8: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x80128CCC: lbu         $t3, 0x90($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X90);
    // 0x80128CD0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80128CD4: bgez        $t3, L_80128CEC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80128CD8: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_80128CEC;
    }
    // 0x80128CD8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80128CDC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80128CE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80128CE4: nop

    // 0x80128CE8: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_80128CEC:
    // 0x80128CEC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128CF0: ldc1        $f6, -0x32E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X32E8);
    // 0x80128CF4: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80128CF8: nop

    // 0x80128CFC: bc1fl       L_80128D10
    if (!c1cs) {
        // 0x80128D00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80128D10;
    }
    goto skip_2;
    // 0x80128D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80128D04: jal         0x80005700
    // 0x80128D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80128D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80128D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80128D10:
    // 0x80128D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80128D14: jr          $ra
    // 0x80128D18: nop

    return;
    // 0x80128D18: nop

;}
RECOMP_FUNC void M7_FUN_80128d1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80128D20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80128D24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80128D28: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80128D2C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80128D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80128D34: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80128D38: bne         $v0, $zero, L_80128DF8
    if (ctx->r2 != 0) {
        // 0x80128D3C: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80128DF8;
    }
    // 0x80128D3C: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80128D40: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80128D44: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80128D48: jal         0x8012C89C
    // 0x80128D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80128D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80128D50: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80128D54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80128D58: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80128D5C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80128D60: addiu       $t0, $t0, -0x4AA8
    ctx->r8 = ADD32(ctx->r8, -0X4AA8);
    // 0x80128D64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80128D68: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80128D6C: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80128D70: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80128D74: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x80128D78: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x80128D7C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80128D80: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80128D84: addiu       $v1, $zero, 0x50
    ctx->r3 = ADD32(0, 0X50);
    // 0x80128D88: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80128D8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80128D90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80128D94: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    // 0x80128D98: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x80128D9C: addiu       $a1, $a1, -0x71F4
    ctx->r5 = ADD32(ctx->r5, -0X71F4);
    // 0x80128DA0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128DA4: sb          $t4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r12;
    // 0x80128DA8: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80128DAC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80128DB0: sb          $t7, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r15;
    // 0x80128DB4: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80128DB8: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80128DBC: sb          $v1, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r3;
    // 0x80128DC0: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x80128DC4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80128DC8: sb          $zero, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = 0;
    // 0x80128DCC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80128DD0: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80128DD4: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80128DD8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80128DDC: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80128DE0: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x80128DE4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80128DE8: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80128DEC: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80128DF0: jal         0x800058DC
    // 0x80128DF4: sb          $v1, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80128DF4: sb          $v1, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r3;
    after_1:
L_80128DF8:
    // 0x80128DF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80128DFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80128E00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80128E04: jr          $ra
    // 0x80128E08: nop

    return;
    // 0x80128E08: nop

;}
RECOMP_FUNC void M7_FUN_80128e0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80128E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80128E14: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80128E18: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128E1C: ldc1        $f0, -0x32E0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X32E0);
    // 0x80128E20: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80128E24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128E28: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80128E2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80128E30: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80128E34: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80128E38: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80128E3C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80128E40: lwc1        $f16, -0x32D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X32D8);
    // 0x80128E44: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80128E48: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x80128E4C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80128E50: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80128E54: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80128E58: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80128E5C: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80128E60: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80128E64: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80128E68: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80128E6C: lw          $a2, 0x30($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X30);
    // 0x80128E70: lbu         $v1, 0x4B($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4B);
    // 0x80128E74: beq         $v1, $zero, L_80128E8C
    if (ctx->r3 == 0) {
        // 0x80128E78: addiu       $t1, $v1, -0xF
        ctx->r9 = ADD32(ctx->r3, -0XF);
            goto L_80128E8C;
    }
    // 0x80128E78: addiu       $t1, $v1, -0xF
    ctx->r9 = ADD32(ctx->r3, -0XF);
    // 0x80128E7C: sb          $t1, 0x4B($a2)
    MEM_B(0X4B, ctx->r6) = ctx->r9;
    // 0x80128E80: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x80128E84: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80128E88: lbu         $v1, 0x4B($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X4B);
L_80128E8C:
    // 0x80128E8C: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    // 0x80128E90: beql        $at, $zero, L_80128EA4
    if (ctx->r1 == 0) {
        // 0x80128E94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80128EA4;
    }
    goto skip_0;
    // 0x80128E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80128E98: jal         0x80005700
    // 0x80128E9C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80128E9C: nop

    after_0:
    // 0x80128EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80128EA4:
    // 0x80128EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80128EA8: jr          $ra
    // 0x80128EAC: nop

    return;
    // 0x80128EAC: nop

;}
RECOMP_FUNC void M7_FUN_80128eb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80128EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80128EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80128EB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80128EBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80128EC0: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80128EC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80128EC8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80128ECC: bne         $v0, $zero, L_8012902C
    if (ctx->r2 != 0) {
        // 0x80128ED0: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_8012902C;
    }
    // 0x80128ED0: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80128ED4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80128ED8: addiu       $t7, $zero, 0xF8
    ctx->r15 = ADD32(0, 0XF8);
    // 0x80128EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80128EE0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80128EE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80128EE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80128EEC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80128EF0: jal         0x8012C89C
    // 0x80128EF4: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_0;
    // 0x80128EF4: sb          $t7, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r15;
    after_0:
    // 0x80128EF8: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80128EFC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80128F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128F04: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x80128F08: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x80128F0C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80128F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80128F14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80128F18: jal         0x8012D814
    // 0x80128F1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_1;
    // 0x80128F1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80128F20: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80128F24: lui         $t4, 0x6
    ctx->r12 = S32(0X6 << 16);
    // 0x80128F28: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x80128F2C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80128F30: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80128F34: addiu       $t8, $t8, -0x4C20
    ctx->r24 = ADD32(ctx->r24, -0X4C20);
    // 0x80128F38: sw          $t4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r12;
    // 0x80128F3C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80128F40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80128F44: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80128F48: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80128F4C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80128F50: ori         $t2, $t2, 0x500
    ctx->r10 = ctx->r10 | 0X500;
    // 0x80128F54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80128F58: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80128F5C: sw          $t9, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r25;
    // 0x80128F60: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80128F64: jal         0x8012C6B4
    // 0x80128F68: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80128F68: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    after_2:
    // 0x80128F6C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80128F70: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80128F74: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80128F78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80128F7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80128F80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128F84: ldc1        $f12, -0x32D0($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X32D0);
    // 0x80128F88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80128F8C: lwc1        $f0, 0x9C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80128F90: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80128F94: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128F98: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x80128F9C: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80128FA0: div.d       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x80128FA4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80128FA8: bc1t        L_80128FB8
    if (c1cs) {
        // 0x80128FAC: swc1        $f18, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
            goto L_80128FB8;
    }
    // 0x80128FAC: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80128FB0: b           L_80128FC0
    // 0x80128FB4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_80128FC0;
    // 0x80128FB4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80128FB8:
    // 0x80128FB8: lwc1        $f4, -0x32C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32C8);
    // 0x80128FBC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_80128FC0:
    // 0x80128FC0: jal         0x8012C6B4
    // 0x80128FC4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80128FC4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_3:
    // 0x80128FC8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80128FCC: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80128FD0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80128FD4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80128FD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80128FDC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80128FE0: ldc1        $f12, -0x32C0($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X32C0);
    // 0x80128FE4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80128FE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80128FEC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80128FF0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    // 0x80128FF4: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x80128FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80128FFC: div.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f12.d);
    // 0x80129000: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80129004: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80129008: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8012900C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80129010: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80129014: swc1        $f14, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f14.u32l;
    // 0x80129018: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8012901C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80129020: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x80129024: jal         0x800058DC
    // 0x80129028: swc1        $f14, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f14.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80129028: swc1        $f14, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f14.u32l;
    after_4:
L_8012902C:
    // 0x8012902C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80129030: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80129034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80129038: jr          $ra
    // 0x8012903C: nop

    return;
    // 0x8012903C: nop

;}
RECOMP_FUNC void M7_FUN_80129040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80129044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80129048: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8012904C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80129050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80129054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80129058: lwc1        $f0, 0x94($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X94);
    // 0x8012905C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80129060: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80129064: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80129068: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012906C: bc1fl       L_8012908C
    if (!c1cs) {
        // 0x80129070: lw          $t6, 0x24($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X24);
            goto L_8012908C;
    }
    goto skip_0;
    // 0x80129070: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x80129074: ldc1        $f8, -0x32B8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X32B8);
    // 0x80129078: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8012907C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80129080: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80129084: swc1        $f16, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f16.u32l;
    // 0x80129088: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
L_8012908C:
    // 0x8012908C: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80129090: lbu         $v1, 0x4A($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4A);
    // 0x80129094: beq         $v1, $zero, L_801290A0
    if (ctx->r3 == 0) {
        // 0x80129098: addiu       $t7, $v1, -0x5
        ctx->r15 = ADD32(ctx->r3, -0X5);
            goto L_801290A0;
    }
    // 0x80129098: addiu       $t7, $v1, -0x5
    ctx->r15 = ADD32(ctx->r3, -0X5);
    // 0x8012909C: sb          $t7, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r15;
L_801290A0:
    // 0x801290A0: lh          $t8, 0x92($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X92);
    // 0x801290A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801290A8: ldc1        $f2, -0x32B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X32B0);
    // 0x801290AC: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x801290B0: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
    // 0x801290B4: lh          $t0, 0x92($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X92);
    // 0x801290B8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801290BC: nop

    // 0x801290C0: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801290C4: div.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x801290C8: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801290CC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801290D0: nop

    // 0x801290D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801290D8: jal         0x8001EAD0
    // 0x801290DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801290DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801290E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801290E4: ldc1        $f2, -0x32A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X32A8);
    // 0x801290E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801290EC: ldc1        $f12, -0x32A0($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X32A0);
    // 0x801290F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801290F4: ldc1        $f14, -0x3298($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3298);
    // 0x801290F8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801290FC: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80129100: mul.d       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f14.d, ctx->f18.d);
    // 0x80129104: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80129108: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8012910C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80129110: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129114: add.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f12.d + ctx->f4.d;
    // 0x80129118: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8012911C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80129120: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
    // 0x80129124: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80129128: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8012912C: nop

    // 0x80129130: bc1tl       L_80129204
    if (c1cs) {
        // 0x80129134: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_80129204;
    }
    goto skip_1;
    // 0x80129134: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80129138: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8012913C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80129140: lbu         $t5, 0x4B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4B);
    // 0x80129144: addiu       $t6, $t5, -0x10
    ctx->r14 = ADD32(ctx->r13, -0X10);
    // 0x80129148: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x8012914C: lh          $t7, 0x92($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X92);
    // 0x80129150: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80129154: nop

    // 0x80129158: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x8012915C: div.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f2.d);
    // 0x80129160: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80129164: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80129168: nop

    // 0x8012916C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80129170: jal         0x8001EAD0
    // 0x80129174: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80129174: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80129178: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012917C: ldc1        $f2, -0x3290($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3290);
    // 0x80129180: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129184: ldc1        $f14, -0x3288($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3288);
    // 0x80129188: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012918C: ldc1        $f18, -0x3280($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3280);
    // 0x80129190: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80129194: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80129198: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8012919C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801291A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801291A4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801291A8: add.d       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f2.d + ctx->f16.d;
    // 0x801291AC: mul.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x801291B0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801291B4: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x801291B8: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801291BC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801291C0: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801291C4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801291C8: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x801291CC: add.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f10.d + ctx->f2.d;
    // 0x801291D0: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801291D4: swc1        $f18, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f18.u32l;
    // 0x801291D8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801291DC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801291E0: lbu         $t5, 0x4B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4B);
    // 0x801291E4: slti        $at, $t5, 0x80
    ctx->r1 = SIGNED(ctx->r13) < 0X80 ? 1 : 0;
    // 0x801291E8: beql        $at, $zero, L_801293B8
    if (ctx->r1 == 0) {
        // 0x801291EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801293B8;
    }
    goto skip_2;
    // 0x801291EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801291F0: jal         0x80005700
    // 0x801291F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801291F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801291F8: b           L_801293B8
    // 0x801291FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801293B8;
    // 0x801291FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80129200: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_80129204:
    // 0x80129204: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80129208: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x8012920C: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x80129210: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80129214: bgez        $t7, L_8012922C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80129218: cvt.d.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
            goto L_8012922C;
    }
    // 0x80129218: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x8012921C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80129220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80129224: nop

    // 0x80129228: add.d       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f16.d + ctx->f8.d;
L_8012922C:
    // 0x8012922C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129230: ldc1        $f10, -0x3278($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3278);
    // 0x80129234: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80129238: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8012923C: sub.d       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f16.d - ctx->f10.d;
    // 0x80129240: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80129244: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80129248: nop

    // 0x8012924C: cvt.w.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_D(ctx->f6.d);
    // 0x80129250: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80129254: nop

    // 0x80129258: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8012925C: beql        $t9, $zero, L_801292B0
    if (ctx->r25 == 0) {
        // 0x80129260: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_801292B0;
    }
    goto skip_3;
    // 0x80129260: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x80129264: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80129268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8012926C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80129270: sub.d       $f18, $f6, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f6.d - ctx->f18.d;
    // 0x80129274: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80129278: nop

    // 0x8012927C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80129280: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80129284: nop

    // 0x80129288: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8012928C: bne         $t9, $zero, L_801292A4
    if (ctx->r25 != 0) {
        // 0x80129290: nop
    
            goto L_801292A4;
    }
    // 0x80129290: nop

    // 0x80129294: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80129298: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012929C: b           L_801292BC
    // 0x801292A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801292BC;
    // 0x801292A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801292A4:
    // 0x801292A4: b           L_801292BC
    // 0x801292A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801292BC;
    // 0x801292A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801292AC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_801292B0:
    // 0x801292B0: nop

    // 0x801292B4: bltz        $t9, L_801292A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801292B8: nop
    
            goto L_801292A4;
    }
    // 0x801292B8: nop

L_801292BC:
    // 0x801292BC: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x801292C0: lh          $t0, 0x92($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X92);
    // 0x801292C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801292C8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801292CC: nop

    // 0x801292D0: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801292D4: div.d       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x801292D8: trunc.w.d   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x801292DC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801292E0: nop

    // 0x801292E4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801292E8: jal         0x8001EAD0
    // 0x801292EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801292EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x801292F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801292F4: ldc1        $f2, -0x3270($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3270);
    // 0x801292F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801292FC: ldc1        $f12, -0x3268($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X3268);
    // 0x80129300: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129304: ldc1        $f14, -0x3260($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3260);
    // 0x80129308: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8012930C: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80129310: mul.d       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f14.d, ctx->f4.d);
    // 0x80129314: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80129318: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8012931C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129320: add.d       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f12.d + ctx->f8.d;
    // 0x80129324: mul.d       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80129328: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8012932C: swc1        $f6, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f6.u32l;
    // 0x80129330: lh          $t4, 0x92($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X92);
    // 0x80129334: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80129338: nop

    // 0x8012933C: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x80129340: div.d       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x80129344: trunc.w.d   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80129348: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8012934C: nop

    // 0x80129350: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80129354: jal         0x8001EB64
    // 0x80129358: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80129358: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x8012935C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129360: ldc1        $f12, -0x3258($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X3258);
    // 0x80129364: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129368: ldc1        $f14, -0x3250($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3250);
    // 0x8012936C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80129370: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80129374: mul.d       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f14.d, ctx->f4.d);
    // 0x80129378: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8012937C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80129380: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80129384: add.d       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f12.d + ctx->f8.d;
    // 0x80129388: mul.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x8012938C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80129390: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
    // 0x80129394: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80129398: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8012939C: lbu         $t0, 0x4B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4B);
    // 0x801293A0: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x801293A4: beql        $at, $zero, L_801293B8
    if (ctx->r1 == 0) {
        // 0x801293A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801293B8;
    }
    goto skip_4;
    // 0x801293A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801293AC: jal         0x80005700
    // 0x801293B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x801293B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801293B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801293B8:
    // 0x801293B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801293BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801293C0: jr          $ra
    // 0x801293C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801293C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801293c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801293c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801293C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801293CC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801293D0: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801293D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801293D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801293DC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801293E0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801293E4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801293E8: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801293EC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801293F0: bc1t        L_80129400
    if (c1cs) {
        // 0x801293F4: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80129400;
    }
    // 0x801293F4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801293F8: b           L_80129400
    // 0x801293FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80129400;
    // 0x801293FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80129400:
    // 0x80129400: lhu         $t7, 0x30($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X30);
    // 0x80129404: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80129408: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8012940C: bnel        $t8, $zero, L_80129548
    if (ctx->r24 != 0) {
        // 0x80129410: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80129548;
    }
    goto skip_0;
    // 0x80129410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80129414: lhu         $t9, 0xBA0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XBA0);
    // 0x80129418: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x8012941C: sh          $t0, 0xBA0($v1)
    MEM_H(0XBA0, ctx->r3) = ctx->r8;
    // 0x80129420: lhu         $t1, 0xC($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XC);
    // 0x80129424: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80129428: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8012942C: bne         $at, $zero, L_80129444
    if (ctx->r1 != 0) {
        // 0x80129430: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80129444;
    }
    // 0x80129430: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80129434: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80129438: mfhi        $t2
    ctx->r10 = hi;
    // 0x8012943C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80129440: sh          $t3, 0xBA0($v1)
    MEM_H(0XBA0, ctx->r3) = ctx->r11;
L_80129444:
    // 0x80129444: jal         0x8012C6B4
    // 0x80129448: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80129448: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_0:
    // 0x8012944C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80129450: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80129454: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80129458: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012945C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80129460: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80129464: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80129468: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8012946C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80129470: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80129474: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80129478: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8012947C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80129480: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80129484: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x80129488: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8012948C: lhu         $a3, 0xBA0($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0XBA0);
    // 0x80129490: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80129494: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80129498: jal         0x8013A334
    // 0x8012949C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x8012949C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801294A0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801294A4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x801294A8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801294AC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801294B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801294B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801294B8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801294BC: jal         0x8012A0F0
    // 0x801294C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012A0F0)(rdram, ctx);
        goto after_2;
    // 0x801294C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x801294C4: beq         $v0, $zero, L_80129544
    if (ctx->r2 == 0) {
        // 0x801294C8: lwc1        $f0, 0x4C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80129544;
    }
    // 0x801294C8: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801294CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801294D0: nop

    // 0x801294D4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801294D8: nop

    // 0x801294DC: bc1tl       L_80129518
    if (c1cs) {
        // 0x801294E0: lw          $t1, 0x24($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X24);
            goto L_80129518;
    }
    goto skip_1;
    // 0x801294E0: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    skip_1:
    // 0x801294E4: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801294E8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801294EC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801294F0: sb          $v1, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r3;
    // 0x801294F4: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801294F8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801294FC: sb          $v1, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r3;
    // 0x80129500: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80129504: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80129508: sb          $v1, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r3;
    // 0x8012950C: b           L_80129544
    // 0x80129510: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
        goto L_80129544;
    // 0x80129510: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80129514: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
L_80129518:
    // 0x80129518: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8012951C: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x80129520: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80129524: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x80129528: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x8012952C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80129530: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x80129534: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80129538: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8012953C: sb          $t5, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r13;
    // 0x80129540: swc1        $f2, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f2.u32l;
L_80129544:
    // 0x80129544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80129548:
    // 0x80129548: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8012954C: jr          $ra
    // 0x80129550: nop

    return;
    // 0x80129550: nop

;}
RECOMP_FUNC void M7_FUN_80129554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129554: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80129558: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8012955C: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x80129560: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80129564: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80129568: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8012956C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80129570: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80129574: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80129578: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8012957C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80129580: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80129584: lw          $s5, 0x5C($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X5C);
    // 0x80129588: addiu       $fp, $fp, -0x4410
    ctx->r30 = ADD32(ctx->r30, -0X4410);
    // 0x8012958C: lhu         $v0, 0xB9A($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0XB9A);
    // 0x80129590: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x80129594: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80129598: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8012959C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x801295A0: beq         $at, $zero, L_80129BE0
    if (ctx->r1 == 0) {
        // 0x801295A4: sw          $t6, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r14;
            goto L_80129BE0;
    }
    // 0x801295A4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x801295A8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801295AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801295B0: addu        $at, $at, $t7
    gpr jr_addend_801295B8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801295B4: lw          $t7, -0x3248($at)
    ctx->r15 = ADD32(ctx->r1, -0X3248);
    // 0x801295B8: jr          $t7
    // 0x801295BC: nop

    switch (jr_addend_801295B8 >> 2) {
        case 0: goto L_801295C0; break;
        case 1: goto L_801295E0; break;
        case 2: goto L_801296F4; break;
        case 3: goto L_80129B24; break;
        case 4: goto L_80129BD8; break;
        default: switch_error(__func__, 0x801295B8, 0x8018CDB8);
    }
    // 0x801295BC: nop

L_801295C0:
    // 0x801295C0: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x801295C4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801295C8: sh          $t8, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r24;
    // 0x801295CC: sh          $t9, 0xB9A($fp)
    MEM_H(0XB9A, ctx->r30) = ctx->r25;
    // 0x801295D0: jal         0x80020744
    // 0x801295D4: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801295D4: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x801295D8: b           L_80129BE4
    // 0x801295DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80129BE4;
    // 0x801295DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801295E0:
    // 0x801295E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801295E4: jal         0x801293C8
    // 0x801295E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801293C8)(rdram, ctx);
        goto after_1;
    // 0x801295E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x801295EC: lhu         $v1, 0xB9C($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XB9C);
    // 0x801295F0: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x801295F4: beq         $v1, $zero, L_80129604
    if (ctx->r3 == 0) {
        // 0x801295F8: sh          $t2, 0xB9C($fp)
        MEM_H(0XB9C, ctx->r30) = ctx->r10;
            goto L_80129604;
    }
    // 0x801295F8: sh          $t2, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r10;
    // 0x801295FC: b           L_80129BE4
    // 0x80129600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80129BE4;
    // 0x80129600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80129604:
    // 0x80129604: jal         0x80020744
    // 0x80129608: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80129608: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_2:
    // 0x8012960C: addiu       $t3, $zero, 0x5F
    ctx->r11 = ADD32(0, 0X5F);
    // 0x80129610: sh          $t3, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r11;
    // 0x80129614: sh          $zero, 0xB9E($fp)
    MEM_H(0XB9E, ctx->r30) = 0;
    // 0x80129618: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8012961C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80129620: ori         $a1, $a1, 0x900
    ctx->r5 = ctx->r5 | 0X900;
    // 0x80129624: jal         0x800062F8
    // 0x80129628: lw          $a0, -0x2578($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2578);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_3;
    // 0x80129628: lw          $a0, -0x2578($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2578);
    after_3:
    // 0x8012962C: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x80129630: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80129634: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80129638: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8012963C: bne         $at, $zero, L_801296E4
    if (ctx->r1 != 0) {
        // 0x80129640: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801296E4;
    }
    // 0x80129640: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80129644: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80129648: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8012964C: addiu       $t0, $t0, -0x5018
    ctx->r8 = ADD32(ctx->r8, -0X5018);
    // 0x80129650: addiu       $s6, $s6, -0x2578
    ctx->r22 = ADD32(ctx->r22, -0X2578);
    // 0x80129654: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x80129658: lui         $t1, 0x4000
    ctx->r9 = S32(0X4000 << 16);
L_8012965C:
    // 0x8012965C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80129660: addu        $v1, $s6, $a1
    ctx->r3 = ADD32(ctx->r22, ctx->r5);
    // 0x80129664: bgezl       $t4, L_80129678
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80129668: lw          $t5, 0x0($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X0);
            goto L_80129678;
    }
    goto skip_0;
    // 0x80129668: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8012966C: b           L_801296D4
    // 0x80129670: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
        goto L_801296D4;
    // 0x80129670: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x80129674: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
L_80129678:
    // 0x80129678: or          $t8, $t0, $t1
    ctx->r24 = ctx->r8 | ctx->r9;
    // 0x8012967C: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x80129680: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80129684: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x80129688: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8012968C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80129690: lw          $t2, 0x2C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X2C);
    // 0x80129694: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
    // 0x80129698: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8012969C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801296A0: sb          $zero, 0x4A($t4)
    MEM_B(0X4A, ctx->r12) = 0;
    // 0x801296A4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801296A8: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801296AC: lbu         $a0, 0x4A($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4A);
    // 0x801296B0: sb          $a0, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r4;
    // 0x801296B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801296B8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801296BC: sb          $a0, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r4;
    // 0x801296C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801296C4: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801296C8: sb          $s4, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r20;
    // 0x801296CC: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x801296D0: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
L_801296D4:
    // 0x801296D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801296D8: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801296DC: bne         $at, $zero, L_8012965C
    if (ctx->r1 != 0) {
        // 0x801296E0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8012965C;
    }
    // 0x801296E0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_801296E4:
    // 0x801296E4: lhu         $t2, 0xB9A($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0XB9A);
    // 0x801296E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801296EC: b           L_80129BE0
    // 0x801296F0: sh          $t3, 0xB9A($fp)
    MEM_H(0XB9A, ctx->r30) = ctx->r11;
        goto L_80129BE0;
    // 0x801296F0: sh          $t3, 0xB9A($fp)
    MEM_H(0XB9A, ctx->r30) = ctx->r11;
L_801296F4:
    // 0x801296F4: lhu         $t4, 0xB9E($fp)
    ctx->r12 = MEM_HU(ctx->r30, 0XB9E);
    // 0x801296F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801296FC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80129700: addiu       $t5, $t4, 0x3
    ctx->r13 = ADD32(ctx->r12, 0X3);
    // 0x80129704: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80129708: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8012970C: sh          $t5, 0xB9E($fp)
    MEM_H(0XB9E, ctx->r30) = ctx->r13;
    // 0x80129710: bgez        $t6, L_80129728
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80129714: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80129728;
    }
    // 0x80129714: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80129718: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012971C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80129720: nop

    // 0x80129724: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80129728:
    // 0x80129728: lui         $at, 0x3F90
    ctx->r1 = S32(0X3F90 << 16);
    // 0x8012972C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80129730: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80129734: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80129738: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8012973C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80129740: jal         0x801293C8
    // 0x80129744: nop

    LOOKUP_FUNC(0x801293C8)(rdram, ctx);
        goto after_4;
    // 0x80129744: nop

    after_4:
    // 0x80129748: lhu         $t7, 0xB9E($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0XB9E);
    // 0x8012974C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80129750: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80129754: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80129758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012975C: bgez        $t7, L_80129770
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80129760: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80129770;
    }
    // 0x80129760: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80129764: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80129768: nop

    // 0x8012976C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80129770:
    // 0x80129770: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80129774: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80129778: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8012977C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80129780: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80129784: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80129788: jal         0x801293C8
    // 0x8012978C: nop

    LOOKUP_FUNC(0x801293C8)(rdram, ctx);
        goto after_5;
    // 0x8012978C: nop

    after_5:
    // 0x80129790: jal         0x8012C6B4
    // 0x80129794: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80129794: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_6:
    // 0x80129798: lhu         $t9, 0xB9E($fp)
    ctx->r25 = MEM_HU(ctx->r30, 0XB9E);
    // 0x8012979C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801297A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801297A4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801297A8: nop

    // 0x801297AC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801297B0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801297B4: bgezl       $t9, L_801297CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801297B8: lui         $at, 0x3FF8
        ctx->r1 = S32(0X3FF8 << 16);
            goto L_801297CC;
    }
    goto skip_1;
    // 0x801297B8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    skip_1:
    // 0x801297BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801297C0: nop

    // 0x801297C4: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801297C8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
L_801297CC:
    // 0x801297CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801297D0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801297D4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x801297D8: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801297DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801297E0: add.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f16.d + ctx->f8.d;
    // 0x801297E4: trunc.w.d   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801297E8: mfc1        $s3, $f18
    ctx->r19 = (int32_t)ctx->f18.u32l;
    // 0x801297EC: jal         0x8012C6B4
    // 0x801297F0: nop

    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x801297F0: nop

    after_7:
    // 0x801297F4: lhu         $t2, 0xB9E($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0XB9E);
    // 0x801297F8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801297FC: jal         0x8012C6B4
    // 0x80129800: addu        $s0, $v0, $t2
    ctx->r16 = ADD32(ctx->r2, ctx->r10);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80129800: addu        $s0, $v0, $t2
    ctx->r16 = ADD32(ctx->r2, ctx->r10);
    after_8:
    // 0x80129804: lhu         $t3, 0xB9E($fp)
    ctx->r11 = MEM_HU(ctx->r30, 0XB9E);
    // 0x80129808: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8012980C: beq         $at, $zero, L_80129818
    if (ctx->r1 == 0) {
        // 0x80129810: addu        $a0, $v0, $t3
        ctx->r4 = ADD32(ctx->r2, ctx->r11);
            goto L_80129818;
    }
    // 0x80129810: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x80129814: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_80129818:
    // 0x80129818: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8012981C: beq         $at, $zero, L_80129828
    if (ctx->r1 == 0) {
        // 0x80129820: lui         $t3, 0x8009
        ctx->r11 = S32(0X8009 << 16);
            goto L_80129828;
    }
    // 0x80129820: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80129824: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80129828:
    // 0x80129828: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8012982C: beq         $at, $zero, L_80129838
    if (ctx->r1 == 0) {
        // 0x80129830: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80129838;
    }
    // 0x80129830: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80129834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80129838:
    // 0x80129838: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x8012983C: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80129840: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80129844: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80129848: bne         $at, $zero, L_801298A8
    if (ctx->r1 != 0) {
        // 0x8012984C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801298A8;
    }
    // 0x8012984C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80129850: addiu       $s6, $s6, -0x2578
    ctx->r22 = ADD32(ctx->r22, -0X2578);
L_80129854:
    // 0x80129854: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80129858: addu        $v1, $s6, $a1
    ctx->r3 = ADD32(ctx->r22, ctx->r5);
    // 0x8012985C: bgezl       $t4, L_80129870
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80129860: lw          $t5, 0x0($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X0);
            goto L_80129870;
    }
    goto skip_2;
    // 0x80129860: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x80129864: b           L_80129898
    // 0x80129868: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
        goto L_80129898;
    // 0x80129868: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8012986C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
L_80129870:
    // 0x80129870: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80129874: sb          $s3, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r19;
    // 0x80129878: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8012987C: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x80129880: sb          $s0, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r16;
    // 0x80129884: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80129888: lw          $t2, 0x2C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X2C);
    // 0x8012988C: sb          $a0, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r4;
    // 0x80129890: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x80129894: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
L_80129898:
    // 0x80129898: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8012989C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801298A0: bne         $at, $zero, L_80129854
    if (ctx->r1 != 0) {
        // 0x801298A4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80129854;
    }
    // 0x801298A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_801298A8:
    // 0x801298A8: lw          $t3, -0x2578($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2578);
    // 0x801298AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801298B0: ldc1        $f0, -0x3230($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X3230);
    // 0x801298B4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801298B8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x801298BC: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x801298C0: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801298C4: addiu       $s6, $s6, -0x2578
    ctx->r22 = ADD32(ctx->r22, -0X2578);
    // 0x801298C8: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x801298CC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801298D0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x801298D4: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x801298D8: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x801298DC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x801298E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801298E4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801298E8: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x801298EC: lw          $t4, -0x2578($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2578);
    // 0x801298F0: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801298F4: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801298F8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801298FC: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x80129900: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80129904: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80129908: lhu         $v1, 0xB9C($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XB9C);
    // 0x8012990C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80129910: beq         $v1, $zero, L_80129920
    if (ctx->r3 == 0) {
        // 0x80129914: sh          $t5, 0xB9C($fp)
        MEM_H(0XB9C, ctx->r30) = ctx->r13;
            goto L_80129920;
    }
    // 0x80129914: sh          $t5, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r13;
    // 0x80129918: b           L_80129BE4
    // 0x8012991C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80129BE4;
    // 0x8012991C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80129920:
    // 0x80129920: jal         0x8013A334
    // 0x80129924: sh          $t6, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r14;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_9;
    // 0x80129924: sh          $t6, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r14;
    after_9:
    // 0x80129928: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012992C: lwc1        $f16, -0x3228($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3228);
    // 0x80129930: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80129934: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80129938: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8012993C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80129940: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80129944: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80129948: jal         0x8012A0F0
    // 0x8012994C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012A0F0)(rdram, ctx);
        goto after_10;
    // 0x8012994C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80129950: beq         $v0, $zero, L_801299B8
    if (ctx->r2 == 0) {
        // 0x80129954: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_801299B8;
    }
    // 0x80129954: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80129958: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8012995C: sb          $zero, 0x90($v0)
    MEM_B(0X90, ctx->r2) = 0;
    // 0x80129960: sb          $v1, 0x91($v0)
    MEM_B(0X91, ctx->r2) = ctx->r3;
    // 0x80129964: sb          $v1, 0x92($v0)
    MEM_B(0X92, ctx->r2) = ctx->r3;
    // 0x80129968: sb          $t9, 0x93($v0)
    MEM_B(0X93, ctx->r2) = ctx->r25;
    // 0x8012996C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80129970: lwc1        $f8, -0x3224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3224);
    // 0x80129974: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80129978: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8012997C: sh          $t8, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r24;
    // 0x80129980: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x80129984: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129988: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x8012998C: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x80129990: sb          $s4, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r20;
    // 0x80129994: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80129998: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8012999C: sb          $s4, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r20;
    // 0x801299A0: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801299A4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801299A8: sb          $s4, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r20;
    // 0x801299AC: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801299B0: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x801299B4: sb          $t9, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r25;
L_801299B8:
    // 0x801299B8: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x801299BC: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x801299C0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x801299C4: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x801299C8: bne         $at, $zero, L_80129AA8
    if (ctx->r1 != 0) {
        // 0x801299CC: lw          $s2, 0x70($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X70);
            goto L_80129AA8;
    }
    // 0x801299CC: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x801299D0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_801299D4:
    // 0x801299D4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x801299D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801299DC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x801299E0: bltz        $t3, L_80129A98
    if (SIGNED(ctx->r11) < 0) {
        // 0x801299E4: lwc1        $f6, 0x90($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
            goto L_80129A98;
    }
    // 0x801299E4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801299E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801299EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801299F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801299F4: lwc1        $f10, -0x3220($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3220);
    // 0x801299F8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801299FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80129A00: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80129A04: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80129A08: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80129A0C: jal         0x8012A0F0
    // 0x80129A10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012A0F0)(rdram, ctx);
        goto after_11;
    // 0x80129A10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80129A14: beq         $v0, $zero, L_80129A94
    if (ctx->r2 == 0) {
        // 0x80129A18: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80129A94;
    }
    // 0x80129A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80129A1C: sb          $zero, 0x90($v0)
    MEM_B(0X90, ctx->r2) = 0;
    // 0x80129A20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80129A24: jal         0x8012C6B4
    // 0x80129A28: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80129A28: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    after_12:
    // 0x80129A2C: addiu       $t5, $v0, 0x2
    ctx->r13 = ADD32(ctx->r2, 0X2);
    // 0x80129A30: sb          $t5, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r13;
    // 0x80129A34: jal         0x8012C6B4
    // 0x80129A38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80129A38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80129A3C: addiu       $t6, $v0, 0x2
    ctx->r14 = ADD32(ctx->r2, 0X2);
    // 0x80129A40: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80129A44: sb          $t6, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r14;
    // 0x80129A48: sb          $t7, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r15;
    // 0x80129A4C: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80129A50: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80129A54: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80129A58: jal         0x8013A334
    // 0x80129A5C: andi        $a3, $s1, 0xFFFF
    ctx->r7 = ctx->r17 & 0XFFFF;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_14;
    // 0x80129A5C: andi        $a3, $s1, 0xFFFF
    ctx->r7 = ctx->r17 & 0XFFFF;
    after_14:
    // 0x80129A60: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80129A64: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80129A68: sb          $s4, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r20;
    // 0x80129A6C: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80129A70: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129A74: sb          $s4, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r20;
    // 0x80129A78: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80129A7C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80129A80: sb          $s4, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r20;
    // 0x80129A84: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80129A88: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80129A8C: sb          $s4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r20;
    // 0x80129A90: sh          $s3, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r19;
L_80129A94:
    // 0x80129A94: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
L_80129A98:
    // 0x80129A98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80129A9C: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80129AA0: bne         $at, $zero, L_801299D4
    if (ctx->r1 != 0) {
        // 0x80129AA4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801299D4;
    }
    // 0x80129AA4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80129AA8:
    // 0x80129AA8: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80129AAC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80129AB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80129AB4: jal         0x8013A334
    // 0x80129AB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_15;
    // 0x80129AB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x80129ABC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80129AC0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80129AC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80129AC8:
    // 0x80129AC8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80129ACC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80129AD0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80129AD4: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80129AD8: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80129ADC: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80129AE0: jal         0x8012A0F0
    // 0x80129AE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8012A0F0)(rdram, ctx);
        goto after_16;
    // 0x80129AE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80129AE8: beq         $v0, $zero, L_80129AF8
    if (ctx->r2 == 0) {
        // 0x80129AEC: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_80129AF8;
    }
    // 0x80129AEC: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x80129AF0: addiu       $t2, $t9, 0x1C
    ctx->r10 = ADD32(ctx->r25, 0X1C);
    // 0x80129AF4: sh          $t2, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r10;
L_80129AF8:
    // 0x80129AF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80129AFC: bnel        $s1, $s0, L_80129AC8
    if (ctx->r17 != ctx->r16) {
        // 0x80129B00: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80129AC8;
    }
    goto skip_3;
    // 0x80129B00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_3:
    // 0x80129B04: jal         0x80020744
    // 0x80129B08: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_17;
    // 0x80129B08: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    after_17:
    // 0x80129B0C: lw          $t3, 0x24($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X24);
    // 0x80129B10: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80129B14: sb          $s4, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r20;
    // 0x80129B18: lhu         $t5, 0xB9A($fp)
    ctx->r13 = MEM_HU(ctx->r30, 0XB9A);
    // 0x80129B1C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80129B20: sh          $t6, 0xB9A($fp)
    MEM_H(0XB9A, ctx->r30) = ctx->r14;
L_80129B24:
    // 0x80129B24: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x80129B28: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80129B2C: addiu       $s6, $s6, -0x2578
    ctx->r22 = ADD32(ctx->r22, -0X2578);
    // 0x80129B30: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80129B34: lbu         $v0, 0x4B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4B);
    // 0x80129B38: beq         $v0, $zero, L_80129B50
    if (ctx->r2 == 0) {
        // 0x80129B3C: addiu       $t8, $v0, -0x5
        ctx->r24 = ADD32(ctx->r2, -0X5);
            goto L_80129B50;
    }
    // 0x80129B3C: addiu       $t8, $v0, -0x5
    ctx->r24 = ADD32(ctx->r2, -0X5);
    // 0x80129B40: sb          $t8, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r24;
    // 0x80129B44: lw          $t9, 0x24($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X24);
    // 0x80129B48: lw          $t2, 0x2C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X2C);
    // 0x80129B4C: lbu         $v0, 0x4B($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X4B);
L_80129B50:
    // 0x80129B50: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x80129B54: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80129B58: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80129B5C: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x80129B60: bne         $at, $zero, L_80129BA8
    if (ctx->r1 != 0) {
        // 0x80129B64: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80129BA8;
    }
    // 0x80129B64: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80129B68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80129B6C:
    // 0x80129B6C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80129B70: addu        $t4, $s6, $a1
    ctx->r12 = ADD32(ctx->r22, ctx->r5);
    // 0x80129B74: bgezl       $t3, L_80129B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80129B78: lw          $t5, 0x0($t4)
        ctx->r13 = MEM_W(ctx->r12, 0X0);
            goto L_80129B88;
    }
    goto skip_4;
    // 0x80129B78: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    skip_4:
    // 0x80129B7C: b           L_80129B98
    // 0x80129B80: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
        goto L_80129B98;
    // 0x80129B80: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80129B84: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
L_80129B88:
    // 0x80129B88: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80129B8C: sb          $v1, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r3;
    // 0x80129B90: lhu         $a2, 0xC($s5)
    ctx->r6 = MEM_HU(ctx->r21, 0XC);
    // 0x80129B94: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
L_80129B98:
    // 0x80129B98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80129B9C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80129BA0: bne         $at, $zero, L_80129B6C
    if (ctx->r1 != 0) {
        // 0x80129BA4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80129B6C;
    }
    // 0x80129BA4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80129BA8:
    // 0x80129BA8: lhu         $v1, 0xB9C($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XB9C);
    // 0x80129BAC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80129BB0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80129BB4: beq         $v1, $zero, L_80129BC4
    if (ctx->r3 == 0) {
        // 0x80129BB8: sh          $t7, 0xB9C($fp)
        MEM_H(0XB9C, ctx->r30) = ctx->r15;
            goto L_80129BC4;
    }
    // 0x80129BB8: sh          $t7, 0xB9C($fp)
    MEM_H(0XB9C, ctx->r30) = ctx->r15;
    // 0x80129BBC: b           L_80129BE4
    // 0x80129BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80129BE4;
    // 0x80129BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80129BC4:
    // 0x80129BC4: lw          $t8, -0x2578($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2578);
    // 0x80129BC8: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x80129BCC: lhu         $t9, 0xB9A($fp)
    ctx->r25 = MEM_HU(ctx->r30, 0XB9A);
    // 0x80129BD0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80129BD4: sh          $t2, 0xB9A($fp)
    MEM_H(0XB9A, ctx->r30) = ctx->r10;
L_80129BD8:
    // 0x80129BD8: b           L_80129BE4
    // 0x80129BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80129BE4;
    // 0x80129BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80129BE0:
    // 0x80129BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80129BE4:
    // 0x80129BE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80129BE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80129BEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80129BF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80129BF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80129BF8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80129BFC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80129C00: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80129C04: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80129C08: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80129C0C: jr          $ra
    // 0x80129C10: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80129C10: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80129c14(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80129c14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129C14: nop

    // 0x80129C18: nop

    // 0x80129C1C: nop

;}
RECOMP_FUNC void M7_FUN_80129c20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129C20: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80129C24: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80129C28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80129C2C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80129C30: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80129C34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80129C38: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80129C3C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80129C40: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80129C44: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
    // 0x80129C48: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80129C4C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80129C50: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80129C54: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80129C58: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80129C5C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80129C60: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80129C64: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80129C68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80129C6C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80129C70: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80129C74: addiu       $t0, $t0, 0x5D98
    ctx->r8 = ADD32(ctx->r8, 0X5D98);
    // 0x80129C78: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x80129C7C: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x80129C80: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80129C84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80129C88: jal         0x80005E44
    // 0x80129C8C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80129C8C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_0:
    // 0x80129C90: bne         $v0, $zero, L_80129CA8
    if (ctx->r2 != 0) {
        // 0x80129C94: nop
    
            goto L_80129CA8;
    }
    // 0x80129C94: nop

    // 0x80129C98: jal         0x80005700
    // 0x80129C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80129C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80129CA0: b           L_80129E54
    // 0x80129CA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80129E54;
    // 0x80129CA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80129CA8:
    // 0x80129CA8: jal         0x80006214
    // 0x80129CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80129CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80129CB0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80129CB4: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80129CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80129CBC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80129CC4: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x80129CC8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80129CCC: lwc1        $f6, 0x9C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80129CD0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80129CD4: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x80129CD8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80129CDC: lwc1        $f8, 0xA0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80129CE0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80129CE4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x80129CE8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80129CEC: lwc1        $f10, 0xA4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80129CF0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80129CF4: swc1        $f10, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f10.u32l;
    // 0x80129CF8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80129CFC: lwc1        $f16, 0xA4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80129D00: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80129D04: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x80129D08: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80129D0C: lwc1        $f18, 0xA4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80129D10: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129D14: swc1        $f18, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f18.u32l;
    // 0x80129D18: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80129D1C: lbu         $t4, 0xA8($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA8);
    // 0x80129D20: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80129D24: sb          $t4, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r12;
    // 0x80129D28: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80129D2C: lbu         $t7, 0xA9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA9);
    // 0x80129D30: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80129D34: sb          $t7, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r15;
    // 0x80129D38: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80129D3C: lbu         $t0, 0xAA($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XAA);
    // 0x80129D40: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80129D44: sb          $t0, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r8;
    // 0x80129D48: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80129D4C: lbu         $t3, 0xAB($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XAB);
    // 0x80129D50: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80129D54: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
    // 0x80129D58: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80129D5C: lbu         $t6, 0xAC($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAC);
    // 0x80129D60: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80129D64: sb          $t6, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r14;
    // 0x80129D68: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80129D6C: lbu         $t9, 0xAD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XAD);
    // 0x80129D70: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80129D74: sb          $t9, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r25;
    // 0x80129D78: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80129D7C: lbu         $t2, 0xAE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XAE);
    // 0x80129D80: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x80129D84: sb          $t2, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r10;
    // 0x80129D88: lhu         $a3, 0x4($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X4);
    // 0x80129D8C: jal         0x8012C89C
    // 0x80129D90: lhu         $a2, 0x2($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80129D90: lhu         $a2, 0x2($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X2);
    after_3:
    // 0x80129D94: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x80129D98: beql        $v0, $zero, L_80129DF4
    if (ctx->r2 == 0) {
        // 0x80129D9C: lhu         $a1, 0xA($s2)
        ctx->r5 = MEM_HU(ctx->r18, 0XA);
            goto L_80129DF4;
    }
    goto skip_0;
    // 0x80129D9C: lhu         $a1, 0xA($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XA);
    skip_0:
    // 0x80129DA0: lbu         $t4, 0x91($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X91);
    // 0x80129DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80129DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80129DAC: andi        $t8, $t4, 0x1
    ctx->r24 = ctx->r12 & 0X1;
    // 0x80129DB0: beq         $t8, $zero, L_80129DE0
    if (ctx->r24 == 0) {
        // 0x80129DB4: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80129DE0;
    }
    // 0x80129DB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80129DB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80129DBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80129DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80129DC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80129DC8: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    // 0x80129DCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80129DD0: jal         0x8012D8C8
    // 0x80129DD4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_4;
    // 0x80129DD4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x80129DD8: b           L_80129DF4
    // 0x80129DDC: lhu         $a1, 0xA($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XA);
        goto L_80129DF4;
    // 0x80129DDC: lhu         $a1, 0xA($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XA);
L_80129DE0:
    // 0x80129DE0: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    // 0x80129DE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80129DE8: jal         0x8012D8C8
    // 0x80129DEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_5;
    // 0x80129DEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80129DF0: lhu         $a1, 0xA($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XA);
L_80129DF4:
    // 0x80129DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80129DF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80129DFC: beql        $a1, $zero, L_80129E14
    if (ctx->r5 == 0) {
        // 0x80129E00: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_80129E14;
    }
    goto skip_1;
    // 0x80129E00: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80129E04: lhu         $a2, 0xC($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0XC);
    // 0x80129E08: jal         0x8012D918
    // 0x80129E0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_6;
    // 0x80129E0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80129E10: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_80129E14:
    // 0x80129E14: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x80129E18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80129E1C: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x80129E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80129E24: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x80129E28: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80129E2C: lw          $t0, 0x18($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X18);
    // 0x80129E30: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80129E34: or          $t5, $t0, $at
    ctx->r13 = ctx->r8 | ctx->r1;
    // 0x80129E38: jal         0x8001F74C
    // 0x80129E3C: sw          $t5, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r13;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_7;
    // 0x80129E3C: sw          $t5, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r13;
    after_7:
    // 0x80129E40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80129E44: addiu       $a1, $a1, -0x6198
    ctx->r5 = ADD32(ctx->r5, -0X6198);
    // 0x80129E48: jal         0x800058DC
    // 0x80129E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80129E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80129E50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80129E54:
    // 0x80129E54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80129E58: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80129E5C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80129E60: jr          $ra
    // 0x80129E64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80129E64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80129e68(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80129e68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129E68: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80129E6C: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80129e70(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80129e70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80129E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80129E78: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80129E7C: beql        $t7, $zero, L_80129EA0
    if (ctx->r15 == 0) {
        // 0x80129E80: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80129EA0;
    }
    goto skip_0;
    // 0x80129E80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80129E84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80129E88: jal         0x8001F74C
    // 0x80129E8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80129E8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80129E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80129E94: b           L_80129EB0
    // 0x80129E98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_80129EB0;
    // 0x80129E98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80129E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80129EA0:
    // 0x80129EA0: jal         0x8001F75C
    // 0x80129EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_1;
    // 0x80129EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80129EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80129EAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80129EB0:
    // 0x80129EB0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80129EB4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80129EB8: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80129EBC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80129EC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80129EC4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80129EC8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80129ECC: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80129ED0: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80129ED4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80129ED8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80129EDC: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80129EE0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80129EE4: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80129EE8: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80129EEC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80129EF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80129EF4: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80129EF8: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80129EFC: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80129F00: lh          $t2, 0x92($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X92);
    // 0x80129F04: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80129F08: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    // 0x80129F0C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80129F10: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80129F14: lbu         $v1, 0x4B($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4B);
    // 0x80129F18: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80129F1C: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x80129F20: beql        $at, $zero, L_80129F30
    if (ctx->r1 == 0) {
        // 0x80129F24: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_80129F30;
    }
    goto skip_1;
    // 0x80129F24: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    skip_1:
    // 0x80129F28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80129F2C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
L_80129F30:
    // 0x80129F30: bnel        $at, $zero, L_80129F40
    if (ctx->r1 != 0) {
        // 0x80129F34: sb          $v1, 0x4B($v0)
        MEM_B(0X4B, ctx->r2) = ctx->r3;
            goto L_80129F40;
    }
    goto skip_2;
    // 0x80129F34: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
    skip_2:
    // 0x80129F38: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80129F3C: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
L_80129F40:
    // 0x80129F40: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x80129F44: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80129F48: bne         $t4, $zero, L_80129F58
    if (ctx->r12 != 0) {
        // 0x80129F4C: nop
    
            goto L_80129F58;
    }
    // 0x80129F4C: nop

    // 0x80129F50: bnel        $v1, $zero, L_80129F64
    if (ctx->r3 != 0) {
        // 0x80129F54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80129F64;
    }
    goto skip_3;
    // 0x80129F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_80129F58:
    // 0x80129F58: jal         0x80005700
    // 0x80129F5C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80129F5C: nop

    after_2:
    // 0x80129F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80129F64:
    // 0x80129F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80129F68: jr          $ra
    // 0x80129F6C: nop

    return;
    // 0x80129F6C: nop

;}
RECOMP_FUNC void M7_FUN_80129f70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129F70: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80129F74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129F78: sb          $v0, 0x5D78($at)
    MEM_B(0X5D78, ctx->r1) = ctx->r2;
    // 0x80129F7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129F80: sb          $v0, 0x5D7C($at)
    MEM_B(0X5D7C, ctx->r1) = ctx->r2;
    // 0x80129F84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129F88: sb          $v0, 0x5D80($at)
    MEM_B(0X5D80, ctx->r1) = ctx->r2;
    // 0x80129F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129F90: sb          $v0, 0x5D84($at)
    MEM_B(0X5D84, ctx->r1) = ctx->r2;
    // 0x80129F94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129F98: sb          $v0, 0x5D88($at)
    MEM_B(0X5D88, ctx->r1) = ctx->r2;
    // 0x80129F9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129FA0: sb          $v0, 0x5D8C($at)
    MEM_B(0X5D8C, ctx->r1) = ctx->r2;
    // 0x80129FA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129FA8: sb          $v0, 0x5D90($at)
    MEM_B(0X5D90, ctx->r1) = ctx->r2;
    // 0x80129FAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80129FB0: jr          $ra
    // 0x80129FB4: sb          $zero, 0x5D94($at)
    MEM_B(0X5D94, ctx->r1) = 0;
    return;
    // 0x80129FB4: sb          $zero, 0x5D94($at)
    MEM_B(0X5D94, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80129fb8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80129fb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80129FB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80129FBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80129FC0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80129FC4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80129FC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80129FCC: jal         0x80005C70
    // 0x80129FD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005C70)(rdram, ctx);
        goto after_0;
    // 0x80129FD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80129FD4: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80129FD8: beq         $at, $zero, L_80129FE8
    if (ctx->r1 == 0) {
        // 0x80129FDC: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_80129FE8;
    }
    // 0x80129FDC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80129FE0: b           L_8012A0D8
    // 0x80129FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012A0D8;
    // 0x80129FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80129FE8:
    // 0x80129FE8: addiu       $t6, $t6, 0x5C40
    ctx->r14 = ADD32(ctx->r14, 0X5C40);
    // 0x80129FEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80129FF0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80129FF4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80129FF8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80129FFC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8012A000: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A004: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x8012A008: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8012A00C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8012A010: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A014: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8012A018: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8012A01C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A020: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8012A024: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8012A028: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8012A02C: jal         0x8012C4D0
    // 0x8012A030: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x8012A030: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x8012A034: beq         $v0, $zero, L_8012A0D4
    if (ctx->r2 == 0) {
        // 0x8012A038: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8012A0D4;
    }
    // 0x8012A038: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012A03C: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x8012A040: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012A044: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x8012A048: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8012A04C: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x8012A050: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8012A054: swc1        $f10, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f10.u32l;
    // 0x8012A058: lb          $t0, 0x63($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X63);
    // 0x8012A05C: sh          $t0, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r8;
    // 0x8012A060: lbu         $t1, 0x6F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X6F);
    // 0x8012A064: sb          $t1, 0x91($v0)
    MEM_B(0X91, ctx->r2) = ctx->r9;
    // 0x8012A068: lbu         $t2, 0x6B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6B);
    // 0x8012A06C: sh          $zero, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = 0;
    // 0x8012A070: sb          $t2, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r10;
    // 0x8012A074: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8012A078: swc1        $f16, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->f16.u32l;
    // 0x8012A07C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012A080: swc1        $f18, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f18.u32l;
    // 0x8012A084: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8012A088: swc1        $f4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f4.u32l;
    // 0x8012A08C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8012A090: swc1        $f6, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f6.u32l;
    // 0x8012A094: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x8012A098: sb          $t3, 0xA8($v0)
    MEM_B(0XA8, ctx->r2) = ctx->r11;
    // 0x8012A09C: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x8012A0A0: sb          $t4, 0xA9($v0)
    MEM_B(0XA9, ctx->r2) = ctx->r12;
    // 0x8012A0A4: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x8012A0A8: sb          $t5, 0xAA($v0)
    MEM_B(0XAA, ctx->r2) = ctx->r13;
    // 0x8012A0AC: lbu         $t6, 0x53($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X53);
    // 0x8012A0B0: sb          $t6, 0xAC($v0)
    MEM_B(0XAC, ctx->r2) = ctx->r14;
    // 0x8012A0B4: lbu         $t7, 0x57($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X57);
    // 0x8012A0B8: sb          $t7, 0xAD($v0)
    MEM_B(0XAD, ctx->r2) = ctx->r15;
    // 0x8012A0BC: lbu         $t8, 0x5B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5B);
    // 0x8012A0C0: sb          $t8, 0xAE($v0)
    MEM_B(0XAE, ctx->r2) = ctx->r24;
    // 0x8012A0C4: lbu         $t9, 0x5F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X5F);
    // 0x8012A0C8: sb          $t9, 0xAB($v0)
    MEM_B(0XAB, ctx->r2) = ctx->r25;
    // 0x8012A0CC: b           L_8012A0D8
    // 0x8012A0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012A0D8;
    // 0x8012A0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012A0D4:
    // 0x8012A0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012A0D8:
    // 0x8012A0D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8012A0DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012A0E0: jr          $ra
    // 0x8012A0E4: nop

    return;
    // 0x8012A0E4: nop

;}
RECOMP_FUNC void M7_FUN_8012a0e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A0E8: nop

    // 0x8012A0EC: nop

;}
RECOMP_FUNC void M7_FUN_8012a0f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A0F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8012A0F4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8012A0F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8012A0FC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8012A100: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8012A104: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8012A108: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8012A10C: beq         $at, $zero, L_8012A54C
    if (ctx->r1 == 0) {
        // 0x8012A110: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8012A54C;
    }
    // 0x8012A110: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8012A114: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8012A118: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012A11C: addu        $at, $at, $t6
    gpr jr_addend_8012A124 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8012A120: lw          $t6, -0x3168($at)
    ctx->r14 = ADD32(ctx->r1, -0X3168);
    // 0x8012A124: jr          $t6
    // 0x8012A128: nop

    switch (jr_addend_8012A124 >> 2) {
        case 0: goto L_8012A12C; break;
        case 1: goto L_8012A1B0; break;
        case 2: goto L_8012A234; break;
        case 3: goto L_8012A2B8; break;
        case 4: goto L_8012A33C; break;
        case 5: goto L_8012A3C0; break;
        case 6: goto L_8012A444; break;
        case 7: goto L_8012A4C8; break;
        default: switch_error(__func__, 0x8012A124, 0x8018CE98);
    }
    // 0x8012A128: nop

L_8012A12C:
    // 0x8012A12C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8012A130: addiu       $t7, $t7, 0x5BA0
    ctx->r15 = ADD32(ctx->r15, 0X5BA0);
    // 0x8012A134: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012A138: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A13C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8012A140: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8012A144: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8012A148: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A14C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8012A150: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8012A154: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A158: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8012A15C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8012A160: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A164: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012A168: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8012A16C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A170: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A174: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8012A178: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8012A17C: jal         0x8012C5F0
    // 0x8012A180: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_0;
    // 0x8012A180: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x8012A184: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A188: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A188: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A18C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A190: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A194: jal         0x800062F8
    // 0x8012A198: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_1;
    // 0x8012A198: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_1:
    // 0x8012A19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A1A0: jal         0x8012C71C
    // 0x8012A1A4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_2;
    // 0x8012A1A4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8012A1A8: b           L_8012A550
    // 0x8012A1AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A1AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A1B0:
    // 0x8012A1B0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8012A1B4: addiu       $t1, $t1, 0x5BB4
    ctx->r9 = ADD32(ctx->r9, 0X5BB4);
    // 0x8012A1B8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8012A1BC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A1C0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8012A1C4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8012A1C8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8012A1CC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A1D0: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8012A1D4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8012A1D8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A1DC: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8012A1E0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8012A1E4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A1E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8012A1EC: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8012A1F0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A1F4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A1F8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8012A1FC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8012A200: jal         0x8012C5F0
    // 0x8012A204: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_3;
    // 0x8012A204: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_3:
    // 0x8012A208: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A20C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A20C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A210: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A214: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A218: jal         0x800062F8
    // 0x8012A21C: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_4;
    // 0x8012A21C: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_4:
    // 0x8012A220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A224: jal         0x8012C71C
    // 0x8012A228: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_5;
    // 0x8012A228: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x8012A22C: b           L_8012A550
    // 0x8012A230: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A230: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A234:
    // 0x8012A234: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8012A238: addiu       $t5, $t5, 0x5BC8
    ctx->r13 = ADD32(ctx->r13, 0X5BC8);
    // 0x8012A23C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012A240: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A244: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8012A248: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8012A24C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012A250: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A254: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8012A258: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012A25C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A260: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8012A264: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012A268: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A26C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012A270: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012A274: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A278: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A27C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012A280: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8012A284: jal         0x8012C5F0
    // 0x8012A288: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_6;
    // 0x8012A288: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_6:
    // 0x8012A28C: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A290: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A290: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A294: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A298: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A29C: jal         0x800062F8
    // 0x8012A2A0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_7;
    // 0x8012A2A0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_7:
    // 0x8012A2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A2A8: jal         0x8012C71C
    // 0x8012A2AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_8;
    // 0x8012A2AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x8012A2B0: b           L_8012A550
    // 0x8012A2B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A2B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A2B8:
    // 0x8012A2B8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8012A2BC: addiu       $t9, $t9, 0x5BDC
    ctx->r25 = ADD32(ctx->r25, 0X5BDC);
    // 0x8012A2C0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8012A2C4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A2C8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8012A2CC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8012A2D0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8012A2D4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A2D8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8012A2DC: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8012A2E0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A2E4: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8012A2E8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8012A2EC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A2F0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8012A2F4: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8012A2F8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A2FC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A300: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8012A304: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8012A308: jal         0x8012C5F0
    // 0x8012A30C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_9;
    // 0x8012A30C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_9:
    // 0x8012A310: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A314: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A314: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A318: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A31C: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A320: jal         0x800062F8
    // 0x8012A324: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_10;
    // 0x8012A324: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_10:
    // 0x8012A328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A32C: jal         0x8012C71C
    // 0x8012A330: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_11;
    // 0x8012A330: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x8012A334: b           L_8012A550
    // 0x8012A338: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A338: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A33C:
    // 0x8012A33C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8012A340: addiu       $t3, $t3, 0x5BF0
    ctx->r11 = ADD32(ctx->r11, 0X5BF0);
    // 0x8012A344: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8012A348: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A34C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8012A350: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8012A354: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8012A358: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A35C: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8012A360: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8012A364: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A368: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8012A36C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8012A370: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A374: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8012A378: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x8012A37C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A380: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A384: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8012A388: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8012A38C: jal         0x8012C5F0
    // 0x8012A390: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_12;
    // 0x8012A390: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x8012A394: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A398: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A398: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A39C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A3A0: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A3A4: jal         0x800062F8
    // 0x8012A3A8: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_13;
    // 0x8012A3A8: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_13:
    // 0x8012A3AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A3B0: jal         0x8012C71C
    // 0x8012A3B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_14;
    // 0x8012A3B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_14:
    // 0x8012A3B8: b           L_8012A550
    // 0x8012A3BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A3BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A3C0:
    // 0x8012A3C0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8012A3C4: addiu       $t7, $t7, 0x5C04
    ctx->r15 = ADD32(ctx->r15, 0X5C04);
    // 0x8012A3C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8012A3CC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A3D0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8012A3D4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8012A3D8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8012A3DC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A3E0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8012A3E4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8012A3E8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A3EC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8012A3F0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8012A3F4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A3F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8012A3FC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8012A400: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A404: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A408: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8012A40C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8012A410: jal         0x8012C5F0
    // 0x8012A414: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_15;
    // 0x8012A414: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_15:
    // 0x8012A418: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A41C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A41C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A420: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A424: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A428: jal         0x800062F8
    // 0x8012A42C: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_16;
    // 0x8012A42C: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_16:
    // 0x8012A430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A434: jal         0x8012C71C
    // 0x8012A438: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_17;
    // 0x8012A438: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_17:
    // 0x8012A43C: b           L_8012A550
    // 0x8012A440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A444:
    // 0x8012A444: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8012A448: addiu       $t1, $t1, 0x5C18
    ctx->r9 = ADD32(ctx->r9, 0X5C18);
    // 0x8012A44C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8012A450: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A454: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8012A458: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8012A45C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8012A460: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A464: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8012A468: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8012A46C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A470: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8012A474: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8012A478: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A47C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8012A480: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8012A484: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A488: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A48C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8012A490: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8012A494: jal         0x8012C5F0
    // 0x8012A498: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_18;
    // 0x8012A498: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_18:
    // 0x8012A49C: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A4A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A4A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A4A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A4A8: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A4AC: jal         0x800062F8
    // 0x8012A4B0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_19;
    // 0x8012A4B0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_19:
    // 0x8012A4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A4B8: jal         0x8012C71C
    // 0x8012A4BC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_20;
    // 0x8012A4BC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_20:
    // 0x8012A4C0: b           L_8012A550
    // 0x8012A4C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A4C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A4C8:
    // 0x8012A4C8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8012A4CC: addiu       $t5, $t5, 0x5C2C
    ctx->r13 = ADD32(ctx->r13, 0X5C2C);
    // 0x8012A4D0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8012A4D4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8012A4D8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8012A4DC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8012A4E0: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8012A4E4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012A4E8: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8012A4EC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8012A4F0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012A4F4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8012A4F8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8012A4FC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8012A500: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8012A504: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8012A508: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8012A50C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012A510: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8012A514: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8012A518: jal         0x8012C5F0
    // 0x8012A51C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C5F0)(rdram, ctx);
        goto after_21;
    // 0x8012A51C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_21:
    // 0x8012A520: beq         $v0, $zero, L_8012A54C
    if (ctx->r2 == 0) {
        // 0x8012A524: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8012A54C;
    }
    // 0x8012A524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8012A528: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8012A52C: ori         $a1, $a1, 0x300
    ctx->r5 = ctx->r5 | 0X300;
    // 0x8012A530: jal         0x800062F8
    // 0x8012A534: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_22;
    // 0x8012A534: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_22:
    // 0x8012A538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8012A53C: jal         0x8012C71C
    // 0x8012A540: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8012C71C)(rdram, ctx);
        goto after_23;
    // 0x8012A540: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_23:
    // 0x8012A544: b           L_8012A550
    // 0x8012A548: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8012A550;
    // 0x8012A548: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8012A54C:
    // 0x8012A54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012A550:
    // 0x8012A550: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8012A554: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8012A558: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8012A55C: jr          $ra
    // 0x8012A560: nop

    return;
    // 0x8012A560: nop

;}
RECOMP_FUNC void M7_FUN_8012a564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A564: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012A568: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8012A56C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012A570: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012A574: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8012A578: beq         $v1, $zero, L_8012A5D4
    if (ctx->r3 == 0) {
            // 0x8012A57C: nop

    LOOKUP_FUNC(0x8012A5D4)(rdram, ctx);
    return;
    }
    // 0x8012A57C: nop

    // 0x8012A580: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8012A584: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A588: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A58C: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A590: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8012A594: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8012A598: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012A59C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012A5A0: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012A5A4: nop

    // 0x8012A5A8: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8012A5AC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8012A5B0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012A5B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8012A5B8: nop

    // 0x8012A5BC: bc1f        L_8012A5CC
    if (!c1cs) {
            // 0x8012A5C0: nop

    LOOKUP_FUNC(0x8012A5CC)(rdram, ctx);
    return;
    }
    // 0x8012A5C0: nop

    // 0x8012A5C4: jr          $ra
    // 0x8012A5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012A5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a5cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a5cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A5CC: jr          $ra
    // 0x8012A5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8012A5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a5d4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a5d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A5D4: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x8012A5D8: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8012A5DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012A5E0: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x8012A5E4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A5E8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A5EC: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8012A5F0: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8012A5F4: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8012A5F8: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8012A5FC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012A600: nop

    // 0x8012A604: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8012A608: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8012A60C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012A610: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8012A614: nop

    // 0x8012A618: bc1f        L_8012A628
    if (!c1cs) {
            // 0x8012A61C: nop

    LOOKUP_FUNC(0x8012A628)(rdram, ctx);
    return;
    }
    // 0x8012A61C: nop

    // 0x8012A620: jr          $ra
    // 0x8012A624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012A624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a628(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A628: jr          $ra
    // 0x8012A62C: nop

    return;
    // 0x8012A62C: nop

;}
RECOMP_FUNC void M7_FUN_8012a630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A630: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8012A634: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012A638: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012A63C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8012A640: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012A644: beq         $v1, $zero, L_8012A6B8
    if (ctx->r3 == 0) {
            // 0x8012A648: nop

    LOOKUP_FUNC(0x8012A6B8)(rdram, ctx);
    return;
    }
    // 0x8012A648: nop

    // 0x8012A64C: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8012A650: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A654: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012A658: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A65C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A660: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8012A664: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8012A668: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8012A66C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012A670: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012A674: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012A678: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8012A67C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8012A680: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8012A684: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012A688: nop

    // 0x8012A68C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8012A690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012A694: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8012A698: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8012A69C: nop

    // 0x8012A6A0: bc1f        L_8012A6B0
    if (!c1cs) {
            // 0x8012A6A4: nop

    LOOKUP_FUNC(0x8012A6B0)(rdram, ctx);
    return;
    }
    // 0x8012A6A4: nop

    // 0x8012A6A8: jr          $ra
    // 0x8012A6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012A6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a6b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A6B0: jr          $ra
    // 0x8012A6B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8012A6B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a6b8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a6b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A6B8: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x8012A6BC: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8012A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012A6C4: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x8012A6C8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A6CC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8012A6D0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8012A6D4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8012A6D8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A6DC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012A6E0: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8012A6E4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012A6E8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012A6EC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8012A6F0: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8012A6F4: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8012A6F8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012A6FC: nop

    // 0x8012A700: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8012A704: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012A708: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8012A70C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8012A710: nop

    // 0x8012A714: bc1f        L_8012A724
    if (!c1cs) {
            // 0x8012A718: nop

    LOOKUP_FUNC(0x8012A724)(rdram, ctx);
    return;
    }
    // 0x8012A718: nop

    // 0x8012A71C: jr          $ra
    // 0x8012A720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012A720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a724(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A724: jr          $ra
    // 0x8012A728: nop

    return;
    // 0x8012A728: nop

;}
RECOMP_FUNC void M7_FUN_8012a72c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A72C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012A730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012A734: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012A738: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8012A73C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8012A740: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A744: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x8012A748: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012A74C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012A750: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A754: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A758: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012A75C: jal         0x8001EF38
    // 0x8012A760: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8012A760: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8012A764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012A768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012A76C: jr          $ra
    // 0x8012A770: nop

    return;
    // 0x8012A770: nop

;}
RECOMP_FUNC void M7_FUN_8012a774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A774: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8012A778: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8012A77C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012A780: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8012A784: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8012A788: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A78C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8012A790: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8012A794: lh          $v0, 0x12($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X12);
    // 0x8012A798: subu        $a3, $v0, $a1
    ctx->r7 = SUB32(ctx->r2, ctx->r5);
    // 0x8012A79C: bgez        $a3, L_8012A7AC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8012A7A0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8012A7AC;
    }
    // 0x8012A7A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8012A7A4: b           L_8012A7AC
    // 0x8012A7A8: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
        goto L_8012A7AC;
    // 0x8012A7A8: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
L_8012A7AC:
    // 0x8012A7AC: andi        $t7, $a0, 0x1FFF
    ctx->r15 = ctx->r4 & 0X1FFF;
    // 0x8012A7B0: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8012A7B4: bne         $at, $zero, L_8012A7C8
    if (ctx->r1 != 0) {
            // 0x8012A7B8: subu        $t8, $a1, $v0
    ctx->r24 = SUB32(ctx->r5, ctx->r2);
    LOOKUP_FUNC(0x8012A7C8)(rdram, ctx);
    return;
    }
    // 0x8012A7B8: subu        $t8, $a1, $v0
    ctx->r24 = SUB32(ctx->r5, ctx->r2);
    // 0x8012A7BC: sh          $a1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r5;
    // 0x8012A7C0: jr          $ra
    // 0x8012A7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8012A7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a7c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a7c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A7C8: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x8012A7CC: slti        $at, $t9, 0x1000
    ctx->r1 = SIGNED(ctx->r25) < 0X1000 ? 1 : 0;
    // 0x8012A7D0: bne         $at, $zero, L_8012A7E4
    if (ctx->r1 != 0) {
        // 0x8012A7D4: addu        $t1, $v0, $a2
        ctx->r9 = ADD32(ctx->r2, ctx->r6);
            goto L_8012A7E4;
    }
    // 0x8012A7D4: addu        $t1, $v0, $a2
    ctx->r9 = ADD32(ctx->r2, ctx->r6);
    // 0x8012A7D8: subu        $t0, $v0, $a2
    ctx->r8 = SUB32(ctx->r2, ctx->r6);
    // 0x8012A7DC: b           L_8012A7E8
    // 0x8012A7E0: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
        goto L_8012A7E8;
    // 0x8012A7E0: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
L_8012A7E4:
    // 0x8012A7E4: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
L_8012A7E8:
    // 0x8012A7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012A7EC: jr          $ra
    // 0x8012A7F0: nop

    return;
    // 0x8012A7F0: nop

;}
RECOMP_FUNC void M7_FUN_8012a7f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A7F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8012A7F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012A7FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8012A800: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8012A804: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8012A808: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8012A80C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012A810: beq         $v0, $zero, L_8012A824
    if (ctx->r2 == 0) {
        // 0x8012A814: addiu       $a1, $v0, 0x4
        ctx->r5 = ADD32(ctx->r2, 0X4);
            goto L_8012A824;
    }
    // 0x8012A814: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8012A818: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x8012A81C: b           L_8012A834
    // 0x8012A820: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
        goto L_8012A834;
    // 0x8012A820: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
L_8012A824:
    // 0x8012A824: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8012A828: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8012A82C: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x8012A830: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
L_8012A834:
    // 0x8012A834: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012A838: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012A83C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012A840: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8012A844: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8012A848: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8012A84C: jal         0x8001EF38
    // 0x8012A850: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8012A850: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_0:
    // 0x8012A854: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8012A858: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x8012A85C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8012A860: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8012A864: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8012A868: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8012A86C: subu        $v1, $v0, $a1
    ctx->r3 = SUB32(ctx->r2, ctx->r5);
    // 0x8012A870: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012A874: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8012A878: andi        $t6, $v1, 0x1000
    ctx->r14 = ctx->r3 & 0X1000;
    // 0x8012A87C: beq         $t6, $zero, L_8012A898
    if (ctx->r14 == 0) {
        // 0x8012A880: cvt.d.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
            goto L_8012A898;
    }
    // 0x8012A880: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8012A884: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012A888: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x8012A88C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012A890: b           L_8012A8A4
    // 0x8012A894: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8012A8A4;
    // 0x8012A894: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8012A898:
    // 0x8012A898: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012A89C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012A8A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8012A8A4:
    // 0x8012A8A4: bgez        $v1, L_8012A8B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8012A8A8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8012A8B4;
    }
    // 0x8012A8A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8012A8AC: b           L_8012A8B4
    // 0x8012A8B0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8012A8B4;
    // 0x8012A8B0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8012A8B4:
    // 0x8012A8B4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8012A8B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012A8BC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012A8C0: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8012A8C4: nop

    // 0x8012A8C8: bc1f        L_8012A8D8
    if (!c1cs) {
        // 0x8012A8CC: nop
    
            goto L_8012A8D8;
    }
    // 0x8012A8CC: nop

    // 0x8012A8D0: b           L_8012A93C
    // 0x8012A8D4: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
        goto L_8012A93C;
    // 0x8012A8D4: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
L_8012A8D8:
    // 0x8012A8D8: bltzl       $v1, L_8012A914
    if (SIGNED(ctx->r3) < 0) {
        // 0x8012A8DC: mtc1        $a1, $f18
        ctx->f18.u32l = ctx->r5;
            goto L_8012A914;
    }
    goto skip_0;
    // 0x8012A8DC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    skip_0:
    // 0x8012A8E0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8012A8E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8012A8E8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8012A8EC: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x8012A8F0: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012A8F4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8012A8F8: nop

    // 0x8012A8FC: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8012A900: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8012A904: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x8012A908: b           L_8012A93C
    // 0x8012A90C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
        goto L_8012A93C;
    // 0x8012A90C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8012A910: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
L_8012A914:
    // 0x8012A914: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8012A918: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012A91C: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x8012A920: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8012A924: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8012A928: nop

    // 0x8012A92C: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8012A930: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8012A934: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8012A938: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
L_8012A93C:
    // 0x8012A93C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012A940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8012A944: jr          $ra
    // 0x8012A948: nop

    return;
    // 0x8012A948: nop

;}
RECOMP_FUNC void M7_FUN_8012a94c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A94C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012A950: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012a954(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012a954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012A958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012A95C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012A960: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A964: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x8012A968: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8012A96C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8012A970: jal         0x8012A7F4
    // 0x8012A974: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x8012A7F4)(rdram, ctx);
        goto after_0;
    // 0x8012A974: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x8012A978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012A97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012A980: jr          $ra
    // 0x8012A984: nop

    return;
    // 0x8012A984: nop

;}
RECOMP_FUNC void M7_FUN_8012a988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012A988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012A98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012A990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8012A994: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012A998: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8012A99C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8012A9A0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8012A9A4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8012A9A8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8012A9AC: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8012A9B0: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8012A9B4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8012A9B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8012A9BC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012A9C0: jal         0x8001EF38
    // 0x8012A9C4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8012A9C4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8012A9C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8012A9CC: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x8012A9D0: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8012A9D4: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x8012A9D8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8012A9DC: andi        $t1, $a1, 0x1FFF
    ctx->r9 = ctx->r5 & 0X1FFF;
    // 0x8012A9E0: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8012A9E4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8012A9E8: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x8012A9EC: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x8012A9F0: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8012A9F4: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8012A9F8: subu        $a0, $t1, $a3
    ctx->r4 = SUB32(ctx->r9, ctx->r7);
    // 0x8012A9FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012AA00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8012AA04: andi        $t2, $a0, 0x1000
    ctx->r10 = ctx->r4 & 0X1000;
    // 0x8012AA08: beql        $t2, $zero, L_8012AA28
    if (ctx->r10 == 0) {
        // 0x8012AA0C: andi        $a0, $a0, 0x1FFF
        ctx->r4 = ctx->r4 & 0X1FFF;
            goto L_8012AA28;
    }
    goto skip_0;
    // 0x8012AA0C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    skip_0:
    // 0x8012AA10: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x8012AA14: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x8012AA18: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012AA1C: b           L_8012AA30
    // 0x8012AA20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8012AA30;
    // 0x8012AA20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8012AA24: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
L_8012AA28:
    // 0x8012AA28: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012AA2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8012AA30:
    // 0x8012AA30: bgez        $a0, L_8012AA40
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8012AA34: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8012AA40;
    }
    // 0x8012AA34: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8012AA38: b           L_8012AA40
    // 0x8012AA3C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_8012AA40;
    // 0x8012AA3C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_8012AA40:
    // 0x8012AA40: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8012AA44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012AA48: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012AA4C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8012AA50: nop

    // 0x8012AA54: bc1f        L_8012AA64
    if (!c1cs) {
        // 0x8012AA58: nop
    
            goto L_8012AA64;
    }
    // 0x8012AA58: nop

    // 0x8012AA5C: b           L_8012AAD8
    // 0x8012AA60: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
        goto L_8012AAD8;
    // 0x8012AA60: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
L_8012AA64:
    // 0x8012AA64: bltzl       $a0, L_8012AAA8
    if (SIGNED(ctx->r4) < 0) {
        // 0x8012AA68: mtc1        $a3, $f18
        ctx->f18.u32l = ctx->r7;
            goto L_8012AAA8;
    }
    goto skip_1;
    // 0x8012AA68: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    skip_1:
    // 0x8012AA6C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8012AA70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8012AA74: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8012AA78: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x8012AA7C: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8012AA80: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8012AA84: nop

    // 0x8012AA88: sh          $t5, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r13;
    // 0x8012AA8C: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x8012AA90: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8012AA94: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
    // 0x8012AA98: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8012AA9C: b           L_8012AAD8
    // 0x8012AAA0: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
        goto L_8012AAD8;
    // 0x8012AAA0: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x8012AAA4: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
L_8012AAA8:
    // 0x8012AAA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8012AAAC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8012AAB0: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x8012AAB4: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8012AAB8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8012AABC: nop

    // 0x8012AAC0: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x8012AAC4: lw          $t2, 0x24($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X24);
    // 0x8012AAC8: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8012AACC: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x8012AAD0: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8012AAD4: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
L_8012AAD8:
    // 0x8012AAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012AADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012AAE0: jr          $ra
    // 0x8012AAE4: nop

    return;
    // 0x8012AAE4: nop

;}
RECOMP_FUNC void M7_FUN_8012aae8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012AAE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8012AAEC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8012AAF0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8012AAF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8012AAF8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8012AAFC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8012AB00: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x8012AB04: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8012AB08: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x8012AB0C: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    // 0x8012AB10: beq         $v0, $zero, L_8012AB24
    if (ctx->r2 == 0) {
        // 0x8012AB14: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_8012AB24;
    }
    // 0x8012AB14: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8012AB18: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8012AB1C: b           L_8012AB34
    // 0x8012AB20: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
        goto L_8012AB34;
    // 0x8012AB20: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
L_8012AB24:
    // 0x8012AB24: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
    // 0x8012AB28: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8012AB2C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8012AB30: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
L_8012AB34:
    // 0x8012AB34: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8012AB38: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012AB3C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8012AB40: sub.s       $f2, $f22, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x8012AB44: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8012AB48: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8012AB4C: sub.s       $f14, $f24, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8012AB50: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012AB54: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8012AB58: sub.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8012AB5C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8012AB60: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8012AB64: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8012AB68: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8012AB6C: jal         0x8002FC20
    // 0x8012AB70: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8012AB70: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_0:
    // 0x8012AB74: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8012AB78: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8012AB7C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8012AB80: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8012AB84: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8012AB88: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8012AB8C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8012AB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012AB94: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x8012AB98: nop

    // 0x8012AB9C: bc1fl       L_8012ABB8
    if (!c1cs) {
        // 0x8012ABA0: lwc1        $f10, 0x0($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8012ABB8;
    }
    goto skip_0;
    // 0x8012ABA0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8012ABA4: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8012ABA8: swc1        $f12, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
    // 0x8012ABAC: b           L_8012ACC4
    // 0x8012ABB0: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
        goto L_8012ACC4;
    // 0x8012ABB0: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x8012ABB4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
L_8012ABB8:
    // 0x8012ABB8: mtc1        $zero, $f15
    ctx->f_odd[(15 - 1) * 2] = 0;
    // 0x8012ABBC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8012ABC0: sub.s       $f18, $f22, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8012ABC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012ABC8: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8012ABCC: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8012ABD0: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8012ABD4: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012ABD8: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8012ABDC: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8012ABE0: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8012ABE4: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x8012ABE8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8012ABEC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8012ABF0: sub.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8012ABF4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8012ABF8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8012ABFC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8012AC00: swc1        $f18, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f18.u32l;
    // 0x8012AC04: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8012AC08: cvt.d.s     $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f18.d = CVT_D_S(ctx->f22.fl);
    // 0x8012AC0C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8012AC10: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8012AC14: sub.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8012AC18: sub.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d - ctx->f10.d;
    // 0x8012AC1C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8012AC20: mul.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8012AC24: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x8012AC28: nop

    // 0x8012AC2C: bc1tl       L_8012ACA8
    if (c1cs) {
        // 0x8012AC30: swc1        $f22, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
            goto L_8012ACA8;
    }
    goto skip_1;
    // 0x8012AC30: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    skip_1:
    // 0x8012AC34: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012AC38: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8012AC3C: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x8012AC40: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8012AC44: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8012AC48: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8012AC4C: sub.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8012AC50: sub.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d - ctx->f8.d;
    // 0x8012AC54: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8012AC58: mul.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x8012AC5C: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x8012AC60: nop

    // 0x8012AC64: bc1tl       L_8012ACA8
    if (c1cs) {
        // 0x8012AC68: swc1        $f22, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
            goto L_8012ACA8;
    }
    goto skip_2;
    // 0x8012AC68: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    skip_2:
    // 0x8012AC6C: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8012AC70: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8012AC74: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8012AC78: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8012AC7C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8012AC80: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x8012AC84: sub.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8012AC88: sub.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d - ctx->f6.d;
    // 0x8012AC8C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8012AC90: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8012AC94: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x8012AC98: nop

    // 0x8012AC9C: bc1fl       L_8012ACC4
    if (!c1cs) {
        // 0x8012ACA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8012ACC4;
    }
    goto skip_3;
    // 0x8012ACA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8012ACA4: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
L_8012ACA8:
    // 0x8012ACA8: swc1        $f24, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f24.u32l;
    // 0x8012ACAC: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x8012ACB0: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8012ACB4: swc1        $f12, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
    // 0x8012ACB8: b           L_8012ACC4
    // 0x8012ACBC: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
        goto L_8012ACC4;
    // 0x8012ACBC: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x8012ACC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012ACC4:
    // 0x8012ACC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8012ACC8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8012ACCC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8012ACD0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8012ACD4: jr          $ra
    // 0x8012ACD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8012ACD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012acdc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012acdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012ACDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012ACE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8012ACE4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8012ACE8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8012ACEC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8012ACF0: lw          $a2, 0x24($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X24);
    // 0x8012ACF4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8012ACF8: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8012ACFC: beq         $v0, $zero, L_8012AD0C
    if (ctx->r2 == 0) {
        // 0x8012AD00: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_8012AD0C;
    }
    // 0x8012AD00: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8012AD04: b           L_8012AD18
    // 0x8012AD08: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
        goto L_8012AD18;
    // 0x8012AD08: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
L_8012AD0C:
    // 0x8012AD0C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x8012AD10: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8012AD14: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
L_8012AD18:
    // 0x8012AD18: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012AD1C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8012AD20: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8012AD24: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8012AD28: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8012AD2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8012AD30: sub.s       $f2, $f20, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x8012AD34: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8012AD38: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8012AD3C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012AD40: jal         0x8002FC20
    // 0x8012AD44: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8012AD44: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8012AD48: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012AD4C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8012AD50: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8012AD54: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8012AD58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8012AD5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8012AD60: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8012AD64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012AD68: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8012AD6C: nop

    // 0x8012AD70: bc1fl       L_8012AD88
    if (!c1cs) {
        // 0x8012AD74: lwc1        $f6, 0x0($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8012AD88;
    }
    goto skip_0;
    // 0x8012AD74: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8012AD78: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8012AD7C: b           L_8012AE40
    // 0x8012AD80: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
        goto L_8012AE40;
    // 0x8012AD80: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x8012AD84: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
L_8012AD88:
    // 0x8012AD88: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8012AD8C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8012AD90: sub.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x8012AD94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012AD98: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8012AD9C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8012ADA0: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8012ADA4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012ADA8: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8012ADAC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8012ADB0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8012ADB4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8012ADB8: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8012ADBC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8012ADC0: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x8012ADC4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8012ADC8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8012ADCC: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8012ADD0: sub.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8012ADD4: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x8012ADD8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8012ADDC: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8012ADE0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8012ADE4: nop

    // 0x8012ADE8: bc1tl       L_8012AE2C
    if (c1cs) {
        // 0x8012ADEC: swc1        $f20, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
            goto L_8012AE2C;
    }
    goto skip_1;
    // 0x8012ADEC: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    skip_1:
    // 0x8012ADF0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012ADF4: lwc1        $f10, 0x48($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8012ADF8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8012ADFC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8012AE00: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8012AE04: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x8012AE08: sub.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8012AE0C: sub.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d - ctx->f4.d;
    // 0x8012AE10: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8012AE14: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8012AE18: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8012AE1C: nop

    // 0x8012AE20: bc1fl       L_8012AE40
    if (!c1cs) {
        // 0x8012AE24: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8012AE40;
    }
    goto skip_2;
    // 0x8012AE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8012AE28: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
L_8012AE2C:
    // 0x8012AE2C: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    // 0x8012AE30: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8012AE34: b           L_8012AE40
    // 0x8012AE38: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
        goto L_8012AE40;
    // 0x8012AE38: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x8012AE3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012AE40:
    // 0x8012AE40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8012AE44: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8012AE48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012AE4C: jr          $ra
    // 0x8012AE50: nop

    return;
    // 0x8012AE50: nop

;}
RECOMP_FUNC void M7_FUN_8012ae54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012AE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012AE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012AE5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8012AE60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8012AE64: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8012AE68: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8012AE6C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012AE70: beq         $v0, $zero, L_8012AE80
    if (ctx->r2 == 0) {
        // 0x8012AE74: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8012AE80;
    }
    // 0x8012AE74: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8012AE78: b           L_8012AE8C
    // 0x8012AE7C: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
        goto L_8012AE8C;
    // 0x8012AE7C: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
L_8012AE80:
    // 0x8012AE80: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8012AE84: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8012AE88: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
L_8012AE8C:
    // 0x8012AE8C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8012AE90: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8012AE94: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8012AE98: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8012AE9C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8012AEA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8012AEA4: nop

    // 0x8012AEA8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012AEAC: jal         0x8002FC20
    // 0x8012AEB0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8012AEB0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x8012AEB4: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8012AEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012AEBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012AEC0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8012AEC4: nop

    // 0x8012AEC8: bc1f        L_8012AED8
    if (!c1cs) {
        // 0x8012AECC: nop
    
            goto L_8012AED8;
    }
    // 0x8012AECC: nop

    // 0x8012AED0: b           L_8012AED8
    // 0x8012AED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8012AED8;
    // 0x8012AED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012AED8:
    // 0x8012AED8: jr          $ra
    // 0x8012AEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8012AEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012aee0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012aee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012AEE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8012AEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012AEE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8012AEEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8012AEF0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8012AEF4: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8012AEF8: beql        $v1, $zero, L_8012AF14
    if (ctx->r3 == 0) {
        // 0x8012AEFC: lw          $t8, 0x30($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X30);
            goto L_8012AF14;
    }
    goto skip_0;
    // 0x8012AEFC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8012AF00: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
    // 0x8012AF04: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8012AF08: b           L_8012AF24
    // 0x8012AF0C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
        goto L_8012AF24;
    // 0x8012AF0C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012AF10: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
L_8012AF14:
    // 0x8012AF14: lh          $t9, 0x12($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X12);
    // 0x8012AF18: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8012AF1C: nop

    // 0x8012AF20: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
L_8012AF24:
    // 0x8012AF24: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8012AF28: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8012AF2C: nop

    // 0x8012AF30: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012AF34: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8012AF38: jal         0x8001EAD0
    // 0x8012AF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8012AF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012AF40: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8012AF44: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8012AF48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8012AF4C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8012AF50: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8012AF54: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8012AF58: jal         0x8001EB64
    // 0x8012AF5C: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8012AF5C: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    after_1:
    // 0x8012AF60: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8012AF64: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8012AF68: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8012AF6C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8012AF70: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8012AF74: swc1        $f16, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f16.u32l;
    // 0x8012AF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012AF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8012AF80: jr          $ra
    // 0x8012AF84: nop

    return;
    // 0x8012AF84: nop

;}
RECOMP_FUNC void M7_FUN_8012af88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012AF88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8012AF8C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012AF90: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8012AF94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012AF98: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8012AF9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8012AFA0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8012AFA4: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8012AFA8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012AFAC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8012AFB0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012AFB4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8012AFB8: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012AFBC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012AFC0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8012AFC4: sub.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8012AFC8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8012AFCC: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8012AFD0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8012AFD4: nop

    // 0x8012AFD8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8012AFDC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8012AFE0: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8012AFE4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012AFE8: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8012AFEC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8012AFF0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012AFF4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8012AFF8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012AFFC: bc1f        L_8012B00C
    if (!c1cs) {
        // 0x8012B000: nop
    
            goto L_8012B00C;
    }
    // 0x8012B000: nop

    // 0x8012B004: b           L_8012B1D4
    // 0x8012B008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012B1D4;
    // 0x8012B008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012B00C:
    // 0x8012B00C: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8012B010: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012B014: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x8012B018: jal         0x8001EF38
    // 0x8012B01C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8012B01C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8012B020: andi        $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 & 0X1000;
    // 0x8012B024: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8012B028: beq         $t7, $zero, L_8012B04C
    if (ctx->r15 == 0) {
        // 0x8012B02C: lwc1        $f14, 0x18($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8012B04C;
    }
    // 0x8012B02C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8012B030: jal         0x8001EF38
    // 0x8012B034: nop

    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8012B034: nop

    after_1:
    // 0x8012B038: andi        $a0, $v0, 0x1FFF
    ctx->r4 = ctx->r2 & 0X1FFF;
    // 0x8012B03C: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x8012B040: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012B044: b           L_8012B060
    // 0x8012B048: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_8012B060;
    // 0x8012B048: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8012B04C:
    // 0x8012B04C: jal         0x8001EF38
    // 0x8012B050: nop

    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8012B050: nop

    after_2:
    // 0x8012B054: andi        $a0, $v0, 0x1FFF
    ctx->r4 = ctx->r2 & 0X1FFF;
    // 0x8012B058: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012B05C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8012B060:
    // 0x8012B060: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8012B064: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x8012B068: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012B06C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012B070: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8012B074: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012B078: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012B07C: sh          $a0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r4;
    // 0x8012B080: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012B084: jal         0x8001EF38
    // 0x8012B088: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x8012B088: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    after_3:
    // 0x8012B08C: lh          $a0, 0x24($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X24);
    // 0x8012B090: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8012B094: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8012B098: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x8012B09C: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x8012B0A0: beq         $t2, $zero, L_8012B0F4
    if (ctx->r10 == 0) {
        // 0x8012B0A4: nop
    
            goto L_8012B0F4;
    }
    // 0x8012B0A4: nop

    // 0x8012B0A8: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x8012B0AC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012B0B0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012B0B4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8012B0B8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012B0BC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012B0C0: sh          $a0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r4;
    // 0x8012B0C4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8012B0C8: jal         0x8001EF38
    // 0x8012B0CC: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x8012B0CC: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    after_4:
    // 0x8012B0D0: lh          $a0, 0x24($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X24);
    // 0x8012B0D4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8012B0D8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B0DC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8012B0E0: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012B0E4: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x8012B0E8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B0EC: b           L_8012B138
    // 0x8012B0F0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8012B138;
    // 0x8012B0F0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8012B0F4:
    // 0x8012B0F4: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x8012B0F8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8012B0FC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8012B100: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8012B104: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8012B108: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8012B10C: sh          $a0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r4;
    // 0x8012B110: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012B114: jal         0x8001EF38
    // 0x8012B118: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x8012B118: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_5:
    // 0x8012B11C: lh          $a0, 0x24($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X24);
    // 0x8012B120: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8012B124: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B128: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8012B12C: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012B130: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B134: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8012B138:
    // 0x8012B138: bgez        $v1, L_8012B148
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8012B13C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8012B148;
    }
    // 0x8012B13C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8012B140: b           L_8012B148
    // 0x8012B144: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8012B148;
    // 0x8012B144: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8012B148:
    // 0x8012B148: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8012B14C: bne         $at, $zero, L_8012B15C
    if (ctx->r1 != 0) {
        // 0x8012B150: lbu         $t5, 0x43($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X43);
            goto L_8012B15C;
    }
    // 0x8012B150: lbu         $t5, 0x43($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X43);
    // 0x8012B154: b           L_8012B1D4
    // 0x8012B158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012B1D4;
    // 0x8012B158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012B15C:
    // 0x8012B15C: bne         $t5, $zero, L_8012B1D0
    if (ctx->r13 != 0) {
        // 0x8012B160: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_8012B1D0;
    }
    // 0x8012B160: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8012B164: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8012B168: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8012B16C: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x8012B170: subu        $v1, $t8, $a0
    ctx->r3 = SUB32(ctx->r24, ctx->r4);
    // 0x8012B174: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x8012B178: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B17C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8012B180: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
    // 0x8012B184: beql        $t9, $zero, L_8012B1A4
    if (ctx->r25 == 0) {
        // 0x8012B188: andi        $v1, $v1, 0x1FFF
        ctx->r3 = ctx->r3 & 0X1FFF;
            goto L_8012B1A4;
    }
    goto skip_0;
    // 0x8012B188: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    skip_0:
    // 0x8012B18C: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8012B190: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x8012B194: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B198: b           L_8012B1AC
    // 0x8012B19C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8012B1AC;
    // 0x8012B19C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8012B1A0: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
L_8012B1A4:
    // 0x8012B1A4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8012B1A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8012B1AC:
    // 0x8012B1AC: bgez        $v1, L_8012B1BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8012B1B0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8012B1BC;
    }
    // 0x8012B1B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8012B1B4: b           L_8012B1BC
    // 0x8012B1B8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8012B1BC;
    // 0x8012B1B8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8012B1BC:
    // 0x8012B1BC: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x8012B1C0: bnel        $at, $zero, L_8012B1D4
    if (ctx->r1 != 0) {
        // 0x8012B1C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8012B1D4;
    }
    goto skip_1;
    // 0x8012B1C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8012B1C8: b           L_8012B1D4
    // 0x8012B1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8012B1D4;
    // 0x8012B1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8012B1D0:
    // 0x8012B1D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012B1D4:
    // 0x8012B1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012B1D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012B1DC: jr          $ra
    // 0x8012B1E0: nop

    return;
    // 0x8012B1E0: nop

;}
RECOMP_FUNC void M7_FUN_8012b1e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012B1E4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8012B1E8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8012B1EC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8012B1F0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8012B1F4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8012B1F8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8012B1FC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8012B200: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8012B204: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8012B208: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8012B20C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8012B210: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8012B214: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8012B218: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8012B21C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8012B220: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8012B224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8012B228: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8012B22C: beq         $t7, $zero, L_8012B784
    if (ctx->r15 == 0) {
        // 0x8012B230: addiu       $s1, $s1, 0x6020
        ctx->r17 = ADD32(ctx->r17, 0X6020);
            goto L_8012B784;
    }
    // 0x8012B230: addiu       $s1, $s1, 0x6020
    ctx->r17 = ADD32(ctx->r17, 0X6020);
    // 0x8012B234: lw          $t8, 0x54($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X54);
    // 0x8012B238: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012B23C: beq         $a1, $zero, L_8012B260
    if (ctx->r5 == 0) {
        // 0x8012B240: sw          $t8, -0x36E8($at)
        MEM_W(-0X36E8, ctx->r1) = ctx->r24;
            goto L_8012B260;
    }
    // 0x8012B240: sw          $t8, -0x36E8($at)
    MEM_W(-0X36E8, ctx->r1) = ctx->r24;
    // 0x8012B244: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8012B248: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8012B24C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8012B250: addiu       $a3, $a3, -0x37A8
    ctx->r7 = ADD32(ctx->r7, -0X37A8);
    // 0x8012B254: addiu       $t0, $t0, -0x3768
    ctx->r8 = ADD32(ctx->r8, -0X3768);
    // 0x8012B258: b           L_8012B278
    // 0x8012B25C: addiu       $t1, $t1, -0x3728
    ctx->r9 = ADD32(ctx->r9, -0X3728);
        goto L_8012B278;
    // 0x8012B25C: addiu       $t1, $t1, -0x3728
    ctx->r9 = ADD32(ctx->r9, -0X3728);
L_8012B260:
    // 0x8012B260: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8012B264: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8012B268: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8012B26C: addiu       $a3, $a3, -0x3868
    ctx->r7 = ADD32(ctx->r7, -0X3868);
    // 0x8012B270: addiu       $t0, $t0, -0x3828
    ctx->r8 = ADD32(ctx->r8, -0X3828);
    // 0x8012B274: addiu       $t1, $t1, -0x37E8
    ctx->r9 = ADD32(ctx->r9, -0X37E8);
L_8012B278:
    // 0x8012B278: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8012B27C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8012B280: beql        $v1, $zero, L_8012B788
    if (ctx->r3 == 0) {
        // 0x8012B284: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8012B788;
    }
    goto skip_0;
    // 0x8012B284: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8012B288: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8012B28C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8012B290: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8012B294: beq         $v0, $zero, L_8012B2AC
    if (ctx->r2 == 0) {
        // 0x8012B298: addiu       $s2, $v0, 0x4
        ctx->r18 = ADD32(ctx->r2, 0X4);
            goto L_8012B2AC;
    }
    // 0x8012B298: addiu       $s2, $v0, 0x4
    ctx->r18 = ADD32(ctx->r2, 0X4);
    // 0x8012B29C: addiu       $s3, $v0, 0x8
    ctx->r19 = ADD32(ctx->r2, 0X8);
    // 0x8012B2A0: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
    // 0x8012B2A4: b           L_8012B2C0
    // 0x8012B2A8: addiu       $s5, $v0, 0x12
    ctx->r21 = ADD32(ctx->r2, 0X12);
        goto L_8012B2C0;
    // 0x8012B2A8: addiu       $s5, $v0, 0x12
    ctx->r21 = ADD32(ctx->r2, 0X12);
L_8012B2AC:
    // 0x8012B2AC: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8012B2B0: addiu       $s2, $v0, 0x4
    ctx->r18 = ADD32(ctx->r2, 0X4);
    // 0x8012B2B4: addiu       $s3, $v0, 0x8
    ctx->r19 = ADD32(ctx->r2, 0X8);
    // 0x8012B2B8: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
    // 0x8012B2BC: addiu       $s5, $v0, 0x12
    ctx->r21 = ADD32(ctx->r2, 0X12);
L_8012B2C0:
    // 0x8012B2C0: lhu         $t9, 0x6020($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X6020);
    // 0x8012B2C4: addiu       $fp, $zero, 0x400
    ctx->r30 = ADD32(0, 0X400);
    // 0x8012B2C8: addiu       $s7, $zero, 0x200
    ctx->r23 = ADD32(0, 0X200);
    // 0x8012B2CC: beq         $t9, $zero, L_8012B784
    if (ctx->r25 == 0) {
        // 0x8012B2D0: addiu       $s6, $zero, 0x100
        ctx->r22 = ADD32(0, 0X100);
            goto L_8012B784;
    }
    // 0x8012B2D0: addiu       $s6, $zero, 0x100
    ctx->r22 = ADD32(0, 0X100);
    // 0x8012B2D4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8012B2D8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8012B2DC: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
L_8012B2E0:
    // 0x8012B2E0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8012B2E4: lw          $t2, -0x36E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X36E8);
    // 0x8012B2E8: slti        $at, $v1, 0x81
    ctx->r1 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
    // 0x8012B2EC: and         $t3, $v1, $t2
    ctx->r11 = ctx->r3 & ctx->r10;
    // 0x8012B2F0: beql        $t3, $zero, L_8012B774
    if (ctx->r11 == 0) {
        // 0x8012B2F4: lhu         $v1, 0x4($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X4);
            goto L_8012B774;
    }
    goto skip_1;
    // 0x8012B2F4: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    skip_1:
    // 0x8012B2F8: bne         $at, $zero, L_8012B320
    if (ctx->r1 != 0) {
        // 0x8012B2FC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8012B320;
    }
    // 0x8012B2FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8012B300: beql        $v1, $s6, L_8012B614
    if (ctx->r3 == ctx->r22) {
        // 0x8012B304: swc1        $f22, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
            goto L_8012B614;
    }
    goto skip_2;
    // 0x8012B304: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    skip_2:
    // 0x8012B308: beql        $v1, $s7, L_8012B684
    if (ctx->r3 == ctx->r23) {
        // 0x8012B30C: swc1        $f22, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
            goto L_8012B684;
    }
    goto skip_3;
    // 0x8012B30C: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    skip_3:
    // 0x8012B310: beql        $v1, $fp, L_8012B6D0
    if (ctx->r3 == ctx->r30) {
        // 0x8012B314: swc1        $f22, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
            goto L_8012B6D0;
    }
    goto skip_4;
    // 0x8012B314: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    skip_4:
    // 0x8012B318: b           L_8012B6F0
    // 0x8012B31C: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
        goto L_8012B6F0;
    // 0x8012B31C: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
L_8012B320:
    // 0x8012B320: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x8012B324: bne         $at, $zero, L_8012B33C
    if (ctx->r1 != 0) {
        // 0x8012B328: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8012B33C;
    }
    // 0x8012B328: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8012B32C: beql        $v0, $at, L_8012B5A4
    if (ctx->r2 == ctx->r1) {
        // 0x8012B330: lbu         $t3, 0x4C($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X4C);
            goto L_8012B5A4;
    }
    goto skip_5;
    // 0x8012B330: lbu         $t3, 0x4C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4C);
    skip_5:
    // 0x8012B334: b           L_8012B6F0
    // 0x8012B338: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
        goto L_8012B6F0;
    // 0x8012B338: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
L_8012B33C:
    // 0x8012B33C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x8012B340: bne         $at, $zero, L_8012B35C
    if (ctx->r1 != 0) {
        // 0x8012B344: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_8012B35C;
    }
    // 0x8012B344: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8012B348: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8012B34C: beql        $v0, $at, L_8012B530
    if (ctx->r2 == ctx->r1) {
        // 0x8012B350: lbu         $t7, 0x4C($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X4C);
            goto L_8012B530;
    }
    goto skip_6;
    // 0x8012B350: lbu         $t7, 0x4C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4C);
    skip_6:
    // 0x8012B354: b           L_8012B6F0
    // 0x8012B358: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
        goto L_8012B6F0;
    // 0x8012B358: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
L_8012B35C:
    // 0x8012B35C: sltiu       $at, $t4, 0x20
    ctx->r1 = ctx->r12 < 0X20 ? 1 : 0;
    // 0x8012B360: beq         $at, $zero, L_8012B6EC
    if (ctx->r1 == 0) {
        // 0x8012B364: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8012B6EC;
    }
    // 0x8012B364: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8012B368: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012B36C: addu        $at, $at, $t4
    gpr jr_addend_8012B374 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8012B370: lw          $t4, -0x3148($at)
    ctx->r12 = ADD32(ctx->r1, -0X3148);
    // 0x8012B374: jr          $t4
    // 0x8012B378: nop

    switch (jr_addend_8012B374 >> 2) {
        case 0: goto L_8012B37C; break;
        case 1: goto L_8012B3A0; break;
        case 2: goto L_8012B6EC; break;
        case 3: goto L_8012B3E8; break;
        case 4: goto L_8012B6EC; break;
        case 5: goto L_8012B6EC; break;
        case 6: goto L_8012B6EC; break;
        case 7: goto L_8012B430; break;
        case 8: goto L_8012B6EC; break;
        case 9: goto L_8012B6EC; break;
        case 10: goto L_8012B6EC; break;
        case 11: goto L_8012B6EC; break;
        case 12: goto L_8012B6EC; break;
        case 13: goto L_8012B6EC; break;
        case 14: goto L_8012B6EC; break;
        case 15: goto L_8012B474; break;
        case 16: goto L_8012B6EC; break;
        case 17: goto L_8012B6EC; break;
        case 18: goto L_8012B6EC; break;
        case 19: goto L_8012B6EC; break;
        case 20: goto L_8012B6EC; break;
        case 21: goto L_8012B6EC; break;
        case 22: goto L_8012B6EC; break;
        case 23: goto L_8012B6EC; break;
        case 24: goto L_8012B6EC; break;
        case 25: goto L_8012B6EC; break;
        case 26: goto L_8012B6EC; break;
        case 27: goto L_8012B6EC; break;
        case 28: goto L_8012B6EC; break;
        case 29: goto L_8012B6EC; break;
        case 30: goto L_8012B6EC; break;
        case 31: goto L_8012B4BC; break;
        default: switch_error(__func__, 0x8012B374, 0x8018CEB8);
    }
    // 0x8012B378: nop

L_8012B37C:
    // 0x8012B37C: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x8012B380: lb          $t6, 0x50($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X50);
    // 0x8012B384: lb          $t5, 0x4F($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B388: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8012B38C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8012B390: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012B394: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012B398: b           L_8012B6EC
    // 0x8012B39C: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
        goto L_8012B6EC;
    // 0x8012B39C: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
L_8012B3A0:
    // 0x8012B3A0: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x8012B3A4: lb          $t7, 0x4F($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B3A8: lbu         $t9, 0x4E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4E);
    // 0x8012B3AC: lb          $t8, 0x50($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X50);
    // 0x8012B3B0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8012B3B4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8012B3B8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8012B3BC: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B3C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012B3C4: bgez        $t9, L_8012B3DC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8012B3C8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8012B3DC;
    }
    // 0x8012B3C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B3CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B3D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012B3D4: nop

    // 0x8012B3D8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012B3DC:
    // 0x8012B3DC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8012B3E0: b           L_8012B6EC
    // 0x8012B3E4: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
        goto L_8012B6EC;
    // 0x8012B3E4: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
L_8012B3E8:
    // 0x8012B3E8: lbu         $t2, 0x4C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4C);
    // 0x8012B3EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B3F0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8012B3F4: bgez        $t2, L_8012B408
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8012B3F8: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8012B408;
    }
    // 0x8012B3F8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B3FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012B400: nop

    // 0x8012B404: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8012B408:
    // 0x8012B408: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x8012B40C: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x8012B410: lb          $t4, 0x50($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X50);
    // 0x8012B414: lb          $t3, 0x4F($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B418: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8012B41C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8012B420: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B424: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012B428: b           L_8012B6EC
    // 0x8012B42C: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
        goto L_8012B6EC;
    // 0x8012B42C: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
L_8012B430:
    // 0x8012B430: lbu         $t5, 0x4C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X4C);
    // 0x8012B434: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B438: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8012B43C: bgez        $t5, L_8012B450
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8012B440: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8012B450;
    }
    // 0x8012B440: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012B444: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8012B448: nop

    // 0x8012B44C: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8012B450:
    // 0x8012B450: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8012B454: lb          $t7, 0x50($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X50);
    // 0x8012B458: lb          $t6, 0x4F($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B45C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8012B460: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8012B464: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B468: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012B46C: b           L_8012B6EC
    // 0x8012B470: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
        goto L_8012B6EC;
    // 0x8012B470: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
L_8012B474:
    // 0x8012B474: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x8012B478: lb          $t8, 0x4F($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B47C: lbu         $t2, 0x4E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4E);
    // 0x8012B480: lb          $t9, 0x50($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X50);
    // 0x8012B484: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8012B488: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8012B48C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8012B490: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012B494: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012B498: bgez        $t2, L_8012B4B0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8012B49C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8012B4B0;
    }
    // 0x8012B49C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B4A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B4A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012B4A8: nop

    // 0x8012B4AC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8012B4B0:
    // 0x8012B4B0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8012B4B4: b           L_8012B6EC
    // 0x8012B4B8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
        goto L_8012B6EC;
    // 0x8012B4B8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
L_8012B4BC:
    // 0x8012B4BC: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x8012B4C0: lbu         $t4, 0x4D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4D);
    // 0x8012B4C4: lb          $t3, 0x4F($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B4C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B4CC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8012B4D0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8012B4D4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B4D8: bgez        $t4, L_8012B4EC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8012B4DC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8012B4EC;
    }
    // 0x8012B4DC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B4E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012B4E4: nop

    // 0x8012B4E8: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8012B4EC:
    // 0x8012B4EC: div.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8012B4F0: lb          $t5, 0x50($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X50);
    // 0x8012B4F4: lbu         $t6, 0x4E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4E);
    // 0x8012B4F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B4FC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8012B500: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8012B504: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B508: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B50C: bgez        $t6, L_8012B520
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8012B510: add.s       $f20, $f6, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_8012B520;
    }
    // 0x8012B510: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8012B514: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012B518: nop

    // 0x8012B51C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8012B520:
    // 0x8012B520: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8012B524: b           L_8012B6EC
    // 0x8012B528: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
        goto L_8012B6EC;
    // 0x8012B528: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8012B52C: lbu         $t7, 0x4C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4C);
L_8012B530:
    // 0x8012B530: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B534: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8012B538: bgez        $t7, L_8012B54C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8012B53C: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8012B54C;
    }
    // 0x8012B53C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B540: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012B544: nop

    // 0x8012B548: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_8012B54C:
    // 0x8012B54C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8012B550: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B554: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x8012B558: lbu         $t9, 0x4D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4D);
    // 0x8012B55C: lb          $t8, 0x4F($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B560: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8012B564: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8012B568: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B56C: bgez        $t9, L_8012B580
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8012B570: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8012B580;
    }
    // 0x8012B570: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012B574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012B578: nop

    // 0x8012B57C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8012B580:
    // 0x8012B580: div.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8012B584: lb          $t2, 0x50($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X50);
    // 0x8012B588: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8012B58C: nop

    // 0x8012B590: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012B594: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8012B598: b           L_8012B6EC
    // 0x8012B59C: add.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f16.fl;
        goto L_8012B6EC;
    // 0x8012B59C: add.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8012B5A0: lbu         $t3, 0x4C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4C);
L_8012B5A4:
    // 0x8012B5A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B5A8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8012B5AC: bgez        $t3, L_8012B5C0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8012B5B0: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8012B5C0;
    }
    // 0x8012B5B0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B5B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012B5B8: nop

    // 0x8012B5BC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8012B5C0:
    // 0x8012B5C0: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x8012B5C4: lbu         $t5, 0x4D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X4D);
    // 0x8012B5C8: lb          $t4, 0x4F($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B5CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B5D0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8012B5D4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8012B5D8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B5DC: bgez        $t5, L_8012B5F0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8012B5E0: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8012B5F0;
    }
    // 0x8012B5E0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B5E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012B5E8: nop

    // 0x8012B5EC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8012B5F0:
    // 0x8012B5F0: div.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8012B5F4: lb          $t6, 0x50($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X50);
    // 0x8012B5F8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8012B5FC: nop

    // 0x8012B600: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B604: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8012B608: b           L_8012B6EC
    // 0x8012B60C: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_8012B6EC;
    // 0x8012B60C: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8012B610: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
L_8012B614:
    // 0x8012B614: lbu         $t8, 0x4D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4D);
    // 0x8012B618: lb          $t7, 0x4F($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B61C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B620: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8012B624: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8012B628: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012B62C: bgez        $t8, L_8012B640
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8012B630: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8012B640;
    }
    // 0x8012B630: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012B634: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012B638: nop

    // 0x8012B63C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8012B640:
    // 0x8012B640: div.s       $f18, $f6, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8012B644: lb          $t9, 0x50($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X50);
    // 0x8012B648: lbu         $t2, 0x4E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4E);
    // 0x8012B64C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B650: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8012B654: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8012B658: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012B65C: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8012B660: bgez        $t2, L_8012B674
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8012B664: add.s       $f20, $f10, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f18.fl;
            goto L_8012B674;
    }
    // 0x8012B664: add.s       $f20, $f10, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8012B668: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8012B66C: nop

    // 0x8012B670: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8012B674:
    // 0x8012B674: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8012B678: b           L_8012B6EC
    // 0x8012B67C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
        goto L_8012B6EC;
    // 0x8012B67C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8012B680: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
L_8012B684:
    // 0x8012B684: lbu         $t4, 0x4D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4D);
    // 0x8012B688: lb          $t3, 0x4F($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B68C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8012B690: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8012B694: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8012B698: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B69C: bgez        $t4, L_8012B6B0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8012B6A0: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8012B6B0;
    }
    // 0x8012B6A0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012B6A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8012B6A8: nop

    // 0x8012B6AC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8012B6B0:
    // 0x8012B6B0: lb          $t5, 0x50($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X50);
    // 0x8012B6B4: add.s       $f20, $f16, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8012B6B8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8012B6BC: nop

    // 0x8012B6C0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012B6C4: b           L_8012B6EC
    // 0x8012B6C8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
        goto L_8012B6EC;
    // 0x8012B6C8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8012B6CC: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
L_8012B6D0:
    // 0x8012B6D0: lb          $t7, 0x50($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X50);
    // 0x8012B6D4: lb          $t6, 0x4F($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X4F);
    // 0x8012B6D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8012B6DC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8012B6E0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8012B6E4: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012B6E8: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
L_8012B6EC:
    // 0x8012B6EC: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
L_8012B6F0:
    // 0x8012B6F0: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8012B6F4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8012B6F8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8012B6FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8012B700: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8012B704: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x8012B708: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8012B70C: jal         0x80130C40
    // 0x8012B710: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_0;
    // 0x8012B710: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_0:
    // 0x8012B714: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8012B718: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8012B71C: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B720: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8012B724: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8012B728: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8012B72C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8012B730: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8012B734: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x8012B738: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x8012B73C: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8012B740: lhu         $t3, 0x2($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B744: add.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8012B748: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8012B74C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8012B750: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8012B754: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8012B758: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8012B75C: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
    // 0x8012B760: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8012B764: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8012B768: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8012B76C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x8012B770: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
L_8012B774:
    // 0x8012B774: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8012B778: bne         $v1, $zero, L_8012B2E0
    if (ctx->r3 != 0) {
        // 0x8012B77C: nop
    
            goto L_8012B2E0;
    }
    // 0x8012B77C: nop

    // 0x8012B780: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
L_8012B784:
    // 0x8012B784: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8012B788:
    // 0x8012B788: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8012B78C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8012B790: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8012B794: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8012B798: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8012B79C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8012B7A0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8012B7A4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8012B7A8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8012B7AC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8012B7B0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8012B7B4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8012B7B8: jr          $ra
    // 0x8012B7BC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8012B7BC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012b7c0(rdram, ctx);
;}
