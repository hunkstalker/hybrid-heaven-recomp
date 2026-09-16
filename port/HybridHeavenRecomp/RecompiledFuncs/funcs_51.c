#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801cfe84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE84: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFE88: jr          $ra
    // 0x801CFE8C: addiu       $v0, $v0, 0x12B0
    ctx->r2 = ADD32(ctx->r2, 0X12B0);
    return;
    // 0x801CFE8C: addiu       $v0, $v0, 0x12B0
    ctx->r2 = ADD32(ctx->r2, 0X12B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfe90(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfe90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CFE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CFE98: jal         0x80006214
    // 0x801CFE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CFE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CFEA0: jal         0x801C354C
    // 0x801CFEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801CFEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801CFEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CFEAC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CFEB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFEB4: sw          $t6, -0x510C($at)
    MEM_W(-0X510C, ctx->r1) = ctx->r14;
    // 0x801CFEB8: jr          $ra
    // 0x801CFEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CFEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfec0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfec0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFEC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFEC4: sw          $a0, 0x12C0($at)
    MEM_W(0X12C0, ctx->r1) = ctx->r4;
    // 0x801CFEC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFECC: sw          $zero, -0x50E8($at)
    MEM_W(-0X50E8, ctx->r1) = 0;
    // 0x801CFED0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFED4: sw          $zero, -0x50E4($at)
    MEM_W(-0X50E4, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfed8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfed8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFED8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CFEDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFEE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CFEE4: sw          $t6, -0x50C0($at)
    MEM_W(-0X50C0, ctx->r1) = ctx->r14;
    // 0x801CFEE8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CFEEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CFEF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CFEF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFEF8: addiu       $t7, $t7, -0xDC
    ctx->r15 = ADD32(ctx->r15, -0XDC);
    // 0x801CFEFC: sw          $zero, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = 0;
    // 0x801CFF00: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CFF04: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801CFF08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CFF0C: jal         0x8013B570
    // 0x801CFF10: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801CFF10: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801CFF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CFF18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CFF1C: jr          $ra
    // 0x801CFF20: nop

    return;
    // 0x801CFF20: nop

;}
RECOMP_FUNC void M24_FUN_801cff24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFF24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CFF28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CFF2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CFF30: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CFF34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CFF38: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFF3C: beq         $t6, $zero, L_801D0024
    if (ctx->r14 == 0) {
        // 0x801CFF40: nop
    
            goto L_801D0024;
    }
    // 0x801CFF40: nop

    // 0x801CFF44: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801CFF48: jal         0x8012D844
    // 0x801CFF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801CFF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CFF50: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CFF54: lw          $t7, -0x50BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50BC);
    // 0x801CFF58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CFF5C: beq         $t7, $zero, L_801D0010
    if (ctx->r15 == 0) {
        // 0x801CFF60: nop
    
            goto L_801D0010;
    }
    // 0x801CFF60: nop

    // 0x801CFF64: jal         0x80006214
    // 0x801CFF68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CFF68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CFF6C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801CFF70: addiu       $v1, $v1, 0x1CF0
    ctx->r3 = ADD32(ctx->r3, 0X1CF0);
    // 0x801CFF74: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801CFF78: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801CFF7C: addiu       $v0, $v0, -0x2578
    ctx->r2 = ADD32(ctx->r2, -0X2578);
    // 0x801CFF80: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x801CFF84: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801CFF88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CFF8C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CFF90: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x801CFF94: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
    // 0x801CFF98: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801CFF9C: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x801CFFA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801CFFA4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801CFFA8: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801CFFAC: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x801CFFB0: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801CFFB4: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x801CFFB8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CFFBC: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801CFFC0: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x801CFFC4: sh          $t1, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r9;
    // 0x801CFFC8: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801CFFCC: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801CFFD0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801CFFD4: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801CFFD8: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x801CFFDC: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
    // 0x801CFFE0: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801CFFE4: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x801CFFE8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CFFEC: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801CFFF0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801CFFF4: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x801CFFF8: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801CFFFC: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801D0000: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801D0004: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D0008: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x801D000C: sh          $t5, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r13;
L_801D0010:
    // 0x801D0010: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0014: jal         0x800058DC
    // 0x801D0018: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D0018: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_2:
    // 0x801D001C: b           L_801D0030
    // 0x801D0020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D0030;
    // 0x801D0020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0024:
    // 0x801D0024: jal         0x800058DC
    // 0x801D0028: addiu       $a1, $a1, -0xDC
    ctx->r5 = ADD32(ctx->r5, -0XDC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D0028: addiu       $a1, $a1, -0xDC
    ctx->r5 = ADD32(ctx->r5, -0XDC);
    after_3:
    // 0x801D002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0030:
    // 0x801D0030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0034: jr          $ra
    // 0x801D0038: nop

    return;
    // 0x801D0038: nop

;}
RECOMP_FUNC void M24_FUN_801d003c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0048: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D004C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D0050: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0054: beq         $t6, $zero, L_801D0194
    if (ctx->r14 == 0) {
        // 0x801D0058: nop
    
            goto L_801D0194;
    }
    // 0x801D0058: nop

    // 0x801D005C: lw          $t7, -0x50C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50C8);
    // 0x801D0060: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D0064: addiu       $a2, $a2, -0x50E0
    ctx->r6 = ADD32(ctx->r6, -0X50E0);
    // 0x801D0068: beq         $t7, $zero, L_801D0168
    if (ctx->r15 == 0) {
        // 0x801D006C: nop
    
            goto L_801D0168;
    }
    // 0x801D006C: nop

    // 0x801D0070: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D0074: jal         0x80005FAC
    // 0x801D0078: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D0078: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D007C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D0080: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D0084: lw          $t9, 0x10E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D0088: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D008C: addiu       $v1, $v1, -0x50CC
    ctx->r3 = ADD32(ctx->r3, -0X50CC);
    // 0x801D0090: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D0094: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D0098: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D009C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D00A0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D00A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D00A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D00AC: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D00B0: lw          $t4, 0x10E0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D00B4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D00B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D00BC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D00C0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D00C4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D00C8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D00CC: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D00D0: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D00D4: lw          $t9, 0x10E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D00D8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D00DC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D00E0: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D00E4: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D00E8: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D00EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D00F0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D00F4: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D00F8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D00FC: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D0100: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D0104: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D0108: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D010C: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D0110: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D0114: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D0118: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D011C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D0120: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D0124: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D0128: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D012C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D0130: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D0134: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D0138: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D013C: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D0140: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D0144: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D0148: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D014C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D0150: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D0154: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D0158: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D015C: lw          $t1, -0x50C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X50C4);
    // 0x801D0160: b           L_801D017C
    // 0x801D0164: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D017C;
    // 0x801D0164: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D0168:
    // 0x801D0168: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D016C: addiu       $v1, $v1, -0x50CC
    ctx->r3 = ADD32(ctx->r3, -0X50CC);
    // 0x801D0170: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D0174: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0178: sw          $zero, -0x50C4($at)
    MEM_W(-0X50C4, ctx->r1) = 0;
L_801D017C:
    // 0x801D017C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0180: addiu       $a1, $a1, 0x1B4
    ctx->r5 = ADD32(ctx->r5, 0X1B4);
    // 0x801D0184: jal         0x800058DC
    // 0x801D0188: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D0188: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D018C: b           L_801D01A8
    // 0x801D0190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D01A8;
    // 0x801D0190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0194:
    // 0x801D0194: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0198: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    // 0x801D019C: jal         0x800058DC
    // 0x801D01A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D01A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D01A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D01A8:
    // 0x801D01A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D01AC: jr          $ra
    // 0x801D01B0: nop

    return;
    // 0x801D01B0: nop

;}
RECOMP_FUNC void M24_FUN_801d01b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D01B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D01B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D01BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D01C0: jal         0x801CC540
    // 0x801D01C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D01C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D01C8: beq         $v0, $zero, L_801D01E8
    if (ctx->r2 == 0) {
        // 0x801D01CC: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D01E8;
    }
    // 0x801D01CC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D01D0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D01D4: addiu       $a1, $a1, 0x1B4
    ctx->r5 = ADD32(ctx->r5, 0X1B4);
    // 0x801D01D8: jal         0x800058DC
    // 0x801D01DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D01DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D01E0: b           L_801D03D4
    // 0x801D01E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D03D4;
    // 0x801D01E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D01E8:
    // 0x801D01E8: lw          $t6, -0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50E8);
    // 0x801D01EC: beq         $t6, $zero, L_801D0244
    if (ctx->r14 == 0) {
        // 0x801D01F0: nop
    
            goto L_801D0244;
    }
    // 0x801D01F0: nop

    // 0x801D01F4: jal         0x80006214
    // 0x801D01F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D01F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D01FC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0200: lw          $t7, -0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50E8);
    // 0x801D0204: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D0208: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D020C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D0210: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D0214: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D0218: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D021C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D0220: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D0224: jal         0x8013A28C
    // 0x801D0228: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D0228: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D022C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D0230: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D0234: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0238: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D023C: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D0240: sw          $zero, -0x50E8($at)
    MEM_W(-0X50E8, ctx->r1) = 0;
L_801D0244:
    // 0x801D0244: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0248: lw          $v0, -0x50E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50E4);
    // 0x801D024C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D0250: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D0254: beq         $v0, $zero, L_801D0320
    if (ctx->r2 == 0) {
        // 0x801D0258: nop
    
            goto L_801D0320;
    }
    // 0x801D0258: nop

    // 0x801D025C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D0260: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D0264: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D0268: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D026C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D0270: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D0274: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D0278: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D027C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D0280: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D0284: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D0288: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D028C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D0290: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D0294: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D0298: nop

    // 0x801D029C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D02A0: beql        $t4, $zero, L_801D02F0
    if (ctx->r12 == 0) {
        // 0x801D02A4: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D02F0;
    }
    goto skip_0;
    // 0x801D02A4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D02A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D02AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D02B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D02B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D02B8: nop

    // 0x801D02BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D02C0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D02C4: nop

    // 0x801D02C8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D02CC: bne         $t4, $zero, L_801D02E4
    if (ctx->r12 != 0) {
        // 0x801D02D0: nop
    
            goto L_801D02E4;
    }
    // 0x801D02D0: nop

    // 0x801D02D4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D02D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D02DC: b           L_801D02FC
    // 0x801D02E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D02FC;
    // 0x801D02E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D02E4:
    // 0x801D02E4: b           L_801D02FC
    // 0x801D02E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D02FC;
    // 0x801D02E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D02EC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D02F0:
    // 0x801D02F0: nop

    // 0x801D02F4: bltz        $t4, L_801D02E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D02F8: nop
    
            goto L_801D02E4;
    }
    // 0x801D02F8: nop

L_801D02FC:
    // 0x801D02FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D0300: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D0304: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D0308: jal         0x80011140
    // 0x801D030C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D030C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D0310: beq         $v0, $zero, L_801D0398
    if (ctx->r2 == 0) {
        // 0x801D0314: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D0398;
    }
    // 0x801D0314: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0318: b           L_801D0398
    // 0x801D031C: sw          $zero, -0x50E4($at)
    MEM_W(-0X50E4, ctx->r1) = 0;
        goto L_801D0398;
    // 0x801D031C: sw          $zero, -0x50E4($at)
    MEM_W(-0X50E4, ctx->r1) = 0;
L_801D0320:
    // 0x801D0320: jal         0x80010550
    // 0x801D0324: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D0324: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D0328: beq         $v0, $zero, L_801D0340
    if (ctx->r2 == 0) {
        // 0x801D032C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D0340;
    }
    // 0x801D032C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0330: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D0334: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0338: b           L_801D0344
    // 0x801D033C: sw          $t5, -0x50C0($at)
    MEM_W(-0X50C0, ctx->r1) = ctx->r13;
        goto L_801D0344;
    // 0x801D033C: sw          $t5, -0x50C0($at)
    MEM_W(-0X50C0, ctx->r1) = ctx->r13;
L_801D0340:
    // 0x801D0340: sw          $zero, -0x50C0($at)
    MEM_W(-0X50C0, ctx->r1) = 0;
L_801D0344:
    // 0x801D0344: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D0348: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D034C: addiu       $t6, $t6, 0x12D8
    ctx->r14 = ADD32(ctx->r14, 0X12D8);
    // 0x801D0350: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D0354: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D0358: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D035C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D0360: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D0364: addiu       $t2, $t2, 0x12C8
    ctx->r10 = ADD32(ctx->r10, 0X12C8);
    // 0x801D0368: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D036C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D0370: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D0374: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D0378: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D037C: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D0380: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D0384: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D0388: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D038C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D0390: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D0394: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D0398:
    // 0x801D0398: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D039C: lw          $t7, -0x50C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50C8);
    // 0x801D03A0: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D03A4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D03A8: beq         $t7, $zero, L_801D03BC
    if (ctx->r15 == 0) {
        // 0x801D03AC: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801D03BC;
    }
    // 0x801D03AC: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D03B0: lw          $t8, -0x50C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X50C4);
    // 0x801D03B4: lw          $t6, -0x50CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50CC);
    // 0x801D03B8: sb          $t8, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r24;
L_801D03BC:
    // 0x801D03BC: lw          $t9, -0x5100($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5100);
    // 0x801D03C0: beql        $t9, $zero, L_801D03D4
    if (ctx->r25 == 0) {
        // 0x801D03C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D03D4;
    }
    goto skip_1;
    // 0x801D03C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D03C8: jal         0x801D0528
    // 0x801D03CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D0528)(rdram, ctx);
        goto after_6;
    // 0x801D03CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801D03D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D03D4:
    // 0x801D03D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D03D8: jr          $ra
    // 0x801D03DC: nop

    return;
    // 0x801D03DC: nop

;}
RECOMP_FUNC void M24_FUN_801d03e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D03E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D03E4: jr          $ra
    // 0x801D03E8: sw          $a0, -0x50C8($at)
    MEM_W(-0X50C8, ctx->r1) = ctx->r4;
    return;
    // 0x801D03E8: sw          $a0, -0x50C8($at)
    MEM_W(-0X50C8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d03ec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d03ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D03EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D03F0: jr          $ra
    // 0x801D03F4: sw          $a0, -0x50C4($at)
    MEM_W(-0X50C4, ctx->r1) = ctx->r4;
    return;
    // 0x801D03F4: sw          $a0, -0x50C4($at)
    MEM_W(-0X50C4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d03f8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d03f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D03F8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D03FC: lw          $v0, -0x50E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50E4);
    // 0x801D0400: jr          $ra
    // 0x801D0404: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D0404: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0408(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0408: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D040C: lw          $t6, -0x50E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50E4);
    // 0x801D0410: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0414: beq         $t6, $zero, L_801D0424
    if (ctx->r14 == 0) {
            // 0x801D0418: nop

    LOOKUP_FUNC(0x801D0424)(rdram, ctx);
    return;
    }
    // 0x801D0418: nop

    // 0x801D041C: jr          $ra
    // 0x801D0420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D0420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0424(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0424: lw          $t7, -0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50E8);
    // 0x801D0428: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D042C: beq         $t7, $zero, L_801D043C
    if (ctx->r15 == 0) {
            // 0x801D0430: nop

    LOOKUP_FUNC(0x801D043C)(rdram, ctx);
    return;
    }
    // 0x801D0430: nop

    // 0x801D0434: jr          $ra
    // 0x801D0438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D0438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d043c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d043c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D043C: lw          $v0, -0x50C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50C0);
    // 0x801D0440: jr          $ra
    // 0x801D0444: nop

    return;
    // 0x801D0444: nop

;}
RECOMP_FUNC void M24_FUN_801d0448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0448: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D044C: jr          $ra
    // 0x801D0450: addiu       $v0, $v0, 0x12C8
    ctx->r2 = ADD32(ctx->r2, 0X12C8);
    return;
    // 0x801D0450: addiu       $v0, $v0, 0x12C8
    ctx->r2 = ADD32(ctx->r2, 0X12C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0454(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0454: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D0458: addiu       $v1, $v1, 0x12D8
    ctx->r3 = ADD32(ctx->r3, 0X12D8);
    // 0x801D045C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D0460: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D0464: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D0468: beql        $a0, $t6, L_801D047C
    if (ctx->r4 == ctx->r14) {
        // 0x801D046C: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D047C;
    }
    goto skip_0;
    // 0x801D046C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D0470: jr          $ra
    // 0x801D0474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D0474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D0478: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D047C:
    // 0x801D047C: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D0480: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D0484: jr          $ra
    // 0x801D0488: nop

    return;
    // 0x801D0488: nop

;}
RECOMP_FUNC void M24_FUN_801d048c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D048C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0490: jr          $ra
    // 0x801D0494: sw          $a0, -0x50BC($at)
    MEM_W(-0X50BC, ctx->r1) = ctx->r4;
    return;
    // 0x801D0494: sw          $a0, -0x50BC($at)
    MEM_W(-0X50BC, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0498(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0498: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D049C: addiu       $v0, $v0, -0x5100
    ctx->r2 = ADD32(ctx->r2, -0X5100);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d04a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d04a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D04A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D04A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D04A8: beq         $a0, $zero, L_801D04D4
    if (ctx->r4 == 0) {
        // 0x801D04AC: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D04D4;
    }
    // 0x801D04AC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D04B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D04B4: jal         0x801C0B2C
    // 0x801D04B8: sw          $zero, -0x50D0($at)
    MEM_W(-0X50D0, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D04B8: sw          $zero, -0x50D0($at)
    MEM_W(-0X50D0, ctx->r1) = 0;
    after_0:
    // 0x801D04BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D04C0: sw          $v0, 0x12E8($at)
    MEM_W(0X12E8, ctx->r1) = ctx->r2;
    // 0x801D04C4: sw          $v1, 0x12EC($at)
    MEM_W(0X12EC, ctx->r1) = ctx->r3;
    // 0x801D04C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D04CC: b           L_801D04E8
    // 0x801D04D0: sw          $zero, 0x12F0($at)
    MEM_W(0X12F0, ctx->r1) = 0;
        goto L_801D04E8;
    // 0x801D04D0: sw          $zero, 0x12F0($at)
    MEM_W(0X12F0, ctx->r1) = 0;
L_801D04D4:
    // 0x801D04D4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D04D8: lw          $a0, 0x12C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12C0);
    // 0x801D04DC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D04E0: jal         0x8012D844
    // 0x801D04E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D04E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D04E8:
    // 0x801D04E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D04EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D04F0: jr          $ra
    // 0x801D04F4: nop

    return;
    // 0x801D04F4: nop

;}
RECOMP_FUNC void M24_FUN_801d04f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D04F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D04FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0500: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0504: jal         0x80006214
    // 0x801D0508: lw          $a0, 0x12C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12C0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D0508: lw          $a0, 0x12C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12C0);
    after_0:
    // 0x801D050C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801D0510: lw          $t6, -0x252C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X252C);
    // 0x801D0514: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x801D0518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D051C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0520: jr          $ra
    // 0x801D0524: nop

    return;
    // 0x801D0524: nop

;}
RECOMP_FUNC void M24_FUN_801d0528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D052C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0530: jal         0x801C0B2C
    // 0x801D0534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D0534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D0538: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D053C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0540: lw          $t7, 0x12EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X12EC);
    // 0x801D0544: lw          $t6, 0x12E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X12E8);
    // 0x801D0548: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D054C: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D0550: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D0554: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D0558: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D055C: jal         0x80034C24
    // 0x801D0560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D0560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D0564: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0568: ldc1        $f4, -0x2BA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BA0);
    // 0x801D056C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0570: addiu       $a3, $a3, 0x12F0
    ctx->r7 = ADD32(ctx->r7, 0X12F0);
    // 0x801D0574: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D0578: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D057C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D0580: addiu       $t1, $t1, -0x50B8
    ctx->r9 = ADD32(ctx->r9, -0X50B8);
    // 0x801D0584: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D0588: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D058C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D0590: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D0594: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D0598: nop

    // 0x801D059C: bc1fl       L_801D067C
    if (!c1cs) {
        // 0x801D05A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D067C;
    }
    goto skip_0;
    // 0x801D05A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D05A4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D05A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D05AC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D05B0: beq         $v0, $zero, L_801D05D4
    if (ctx->r2 == 0) {
        // 0x801D05B4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D05D4;
    }
    // 0x801D05B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D05B8: beq         $v0, $at, L_801D05F0
    if (ctx->r2 == ctx->r1) {
        // 0x801D05BC: addiu       $a1, $zero, 0x57
        ctx->r5 = ADD32(0, 0X57);
            goto L_801D05F0;
    }
    // 0x801D05BC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D05C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D05C4: beq         $v0, $at, L_801D0610
    if (ctx->r2 == ctx->r1) {
        // 0x801D05C8: addiu       $a1, $zero, 0x57
        ctx->r5 = ADD32(0, 0X57);
            goto L_801D0610;
    }
    // 0x801D05C8: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D05CC: b           L_801D0630
    // 0x801D05D0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D0630;
    // 0x801D05D0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D05D4:
    // 0x801D05D4: jal         0x8012D844
    // 0x801D05D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D05D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D05DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D05E0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D05E4: addiu       $a3, $a3, 0x12F0
    ctx->r7 = ADD32(ctx->r7, 0X12F0);
    // 0x801D05E8: b           L_801D062C
    // 0x801D05EC: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
        goto L_801D062C;
    // 0x801D05EC: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
L_801D05F0:
    // 0x801D05F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D05F4: jal         0x8012D844
    // 0x801D05F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D05F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D05FC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0600: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0604: addiu       $a3, $a3, 0x12F0
    ctx->r7 = ADD32(ctx->r7, 0X12F0);
    // 0x801D0608: b           L_801D062C
    // 0x801D060C: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
        goto L_801D062C;
    // 0x801D060C: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
L_801D0610:
    // 0x801D0610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D0614: jal         0x8012D844
    // 0x801D0618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D0618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D061C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0620: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0624: addiu       $a3, $a3, 0x12F0
    ctx->r7 = ADD32(ctx->r7, 0X12F0);
    // 0x801D0628: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
L_801D062C:
    // 0x801D062C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D0630:
    // 0x801D0630: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D0634: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D0638: bne         $at, $zero, L_801D0664
    if (ctx->r1 != 0) {
        // 0x801D063C: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D0664;
    }
    // 0x801D063C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D0640: jal         0x801C0B2C
    // 0x801D0644: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D0644: nop

    after_5:
    // 0x801D0648: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D064C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0650: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0654: addiu       $a3, $a3, 0x12F0
    ctx->r7 = ADD32(ctx->r7, 0X12F0);
    // 0x801D0658: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x801D065C: sw          $v0, 0x12E8($at)
    MEM_W(0X12E8, ctx->r1) = ctx->r2;
    // 0x801D0660: sw          $v1, 0x12EC($at)
    MEM_W(0X12EC, ctx->r1) = ctx->r3;
L_801D0664:
    // 0x801D0664: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D0668: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D066C: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D0670: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D0674: nop

    // 0x801D0678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D067C:
    // 0x801D067C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D0680: jr          $ra
    // 0x801D0684: nop

    return;
    // 0x801D0684: nop

;}
RECOMP_FUNC void M24_FUN_801d0688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0688: nop

    // 0x801D068C: nop

;}
RECOMP_FUNC void M24_FUN_801d0690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0690: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0694: sw          $a0, 0x1300($at)
    MEM_W(0X1300, ctx->r1) = ctx->r4;
    // 0x801D0698: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D069C: sw          $zero, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = 0;
    // 0x801D06A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D06A4: sw          $zero, -0x5024($at)
    MEM_W(-0X5024, ctx->r1) = 0;
    // 0x801D06A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D06AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D06B0: sw          $t6, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d06b4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d06b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D06B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D06B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D06BC: sw          $zero, -0x5014($at)
    MEM_W(-0X5014, ctx->r1) = 0;
    // 0x801D06C0: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D06C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D06C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D06CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D06D0: addiu       $t7, $t7, 0x700
    ctx->r15 = ADD32(ctx->r15, 0X700);
    // 0x801D06D4: sw          $zero, -0x5040($at)
    MEM_W(-0X5040, ctx->r1) = 0;
    // 0x801D06D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D06DC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D06E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D06E4: jal         0x8013B570
    // 0x801D06E8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D06E8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D06EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D06F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801D06F4: sh          $zero, -0x3876($at)
    MEM_H(-0X3876, ctx->r1) = 0;
    // 0x801D06F8: jr          $ra
    // 0x801D06FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801D06FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0700(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0708: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D070C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D0710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D0714: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0718: beq         $t6, $zero, L_801D0800
    if (ctx->r14 == 0) {
        // 0x801D071C: nop
    
            goto L_801D0800;
    }
    // 0x801D071C: nop

    // 0x801D0720: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D0724: jal         0x8012D844
    // 0x801D0728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D0728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D072C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0730: lw          $t7, -0x5018($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5018);
    // 0x801D0734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0738: beq         $t7, $zero, L_801D07EC
    if (ctx->r15 == 0) {
        // 0x801D073C: nop
    
            goto L_801D07EC;
    }
    // 0x801D073C: nop

    // 0x801D0740: jal         0x80006214
    // 0x801D0744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D0744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D0748: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801D074C: addiu       $v1, $v1, 0x1CF0
    ctx->r3 = ADD32(ctx->r3, 0X1CF0);
    // 0x801D0750: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801D0754: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801D0758: addiu       $v0, $v0, -0x2578
    ctx->r2 = ADD32(ctx->r2, -0X2578);
    // 0x801D075C: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x801D0760: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801D0764: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0768: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801D076C: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x801D0770: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
    // 0x801D0774: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801D0778: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x801D077C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801D0780: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D0784: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801D0788: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x801D078C: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801D0790: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x801D0794: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D0798: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801D079C: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x801D07A0: sh          $t1, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r9;
    // 0x801D07A4: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801D07A8: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801D07AC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D07B0: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801D07B4: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x801D07B8: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
    // 0x801D07BC: lw          $t8, 0x158($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X158);
    // 0x801D07C0: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x801D07C4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D07C8: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801D07CC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801D07D0: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x801D07D4: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x801D07D8: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801D07DC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801D07E0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D07E4: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x801D07E8: sh          $t5, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r13;
L_801D07EC:
    // 0x801D07EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D07F0: jal         0x800058DC
    // 0x801D07F4: addiu       $a1, $a1, 0x818
    ctx->r5 = ADD32(ctx->r5, 0X818);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D07F4: addiu       $a1, $a1, 0x818
    ctx->r5 = ADD32(ctx->r5, 0X818);
    after_2:
    // 0x801D07F8: b           L_801D080C
    // 0x801D07FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D080C;
    // 0x801D07FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0800:
    // 0x801D0800: jal         0x800058DC
    // 0x801D0804: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D0804: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
    after_3:
    // 0x801D0808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D080C:
    // 0x801D080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0810: jr          $ra
    // 0x801D0814: nop

    return;
    // 0x801D0814: nop

;}
RECOMP_FUNC void M24_FUN_801d0818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D081C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D0820: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D0824: jal         0x801CC540
    // 0x801D0828: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D0828: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D082C: beq         $v0, $zero, L_801D084C
    if (ctx->r2 == 0) {
        // 0x801D0830: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D084C;
    }
    // 0x801D0830: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0834: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0838: addiu       $a1, $a1, 0x818
    ctx->r5 = ADD32(ctx->r5, 0X818);
    // 0x801D083C: jal         0x800058DC
    // 0x801D0840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D0840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D0844: b           L_801D0A18
    // 0x801D0848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D0A18;
    // 0x801D0848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D084C:
    // 0x801D084C: lw          $t6, -0x5028($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5028);
    // 0x801D0850: beq         $t6, $zero, L_801D08A8
    if (ctx->r14 == 0) {
        // 0x801D0854: nop
    
            goto L_801D08A8;
    }
    // 0x801D0854: nop

    // 0x801D0858: jal         0x80006214
    // 0x801D085C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D085C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D0860: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0864: lw          $t7, -0x5028($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5028);
    // 0x801D0868: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D086C: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D0870: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D0874: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D0878: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D087C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D0880: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D0884: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D0888: jal         0x8013A28C
    // 0x801D088C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D088C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D0890: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D0894: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D0898: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D089C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D08A0: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D08A4: sw          $zero, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = 0;
L_801D08A8:
    // 0x801D08A8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D08AC: lw          $v0, -0x5024($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5024);
    // 0x801D08B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D08B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D08B8: beq         $v0, $zero, L_801D0984
    if (ctx->r2 == 0) {
        // 0x801D08BC: nop
    
            goto L_801D0984;
    }
    // 0x801D08BC: nop

    // 0x801D08C0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D08C4: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D08C8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D08CC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D08D0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D08D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D08D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D08DC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D08E0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D08E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D08E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D08EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D08F0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D08F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D08F8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D08FC: nop

    // 0x801D0900: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D0904: beql        $t4, $zero, L_801D0954
    if (ctx->r12 == 0) {
        // 0x801D0908: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D0954;
    }
    goto skip_0;
    // 0x801D0908: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D090C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D0910: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D0914: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D0918: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D091C: nop

    // 0x801D0920: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D0924: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D0928: nop

    // 0x801D092C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D0930: bne         $t4, $zero, L_801D0948
    if (ctx->r12 != 0) {
        // 0x801D0934: nop
    
            goto L_801D0948;
    }
    // 0x801D0934: nop

    // 0x801D0938: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D093C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D0940: b           L_801D0960
    // 0x801D0944: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D0960;
    // 0x801D0944: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D0948:
    // 0x801D0948: b           L_801D0960
    // 0x801D094C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D0960;
    // 0x801D094C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D0950: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D0954:
    // 0x801D0954: nop

    // 0x801D0958: bltz        $t4, L_801D0948
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D095C: nop
    
            goto L_801D0948;
    }
    // 0x801D095C: nop

L_801D0960:
    // 0x801D0960: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D0964: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D0968: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D096C: jal         0x80011140
    // 0x801D0970: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D0970: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D0974: beq         $v0, $zero, L_801D09D0
    if (ctx->r2 == 0) {
        // 0x801D0978: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D09D0;
    }
    // 0x801D0978: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D097C: b           L_801D09D0
    // 0x801D0980: sw          $zero, -0x5024($at)
    MEM_W(-0X5024, ctx->r1) = 0;
        goto L_801D09D0;
    // 0x801D0980: sw          $zero, -0x5024($at)
    MEM_W(-0X5024, ctx->r1) = 0;
L_801D0984:
    // 0x801D0984: jal         0x80010550
    // 0x801D0988: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D0988: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D098C: beq         $v0, $zero, L_801D09A4
    if (ctx->r2 == 0) {
        // 0x801D0990: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D09A4;
    }
    // 0x801D0990: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0994: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D0998: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D099C: b           L_801D09AC
    // 0x801D09A0: sw          $t5, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = ctx->r13;
        goto L_801D09AC;
    // 0x801D09A0: sw          $t5, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = ctx->r13;
L_801D09A4:
    // 0x801D09A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D09A8: sw          $zero, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = 0;
L_801D09AC:
    // 0x801D09AC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D09B0: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x801D09B4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D09B8: addiu       $t6, $t6, 0x1308
    ctx->r14 = ADD32(ctx->r14, 0X1308);
    // 0x801D09BC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D09C0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801D09C4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801D09C8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801D09CC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_801D09D0:
    // 0x801D09D0: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801D09D4: lw          $t0, -0x5014($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5014);
    // 0x801D09D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D09DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801D09E0: beq         $t0, $zero, L_801D09FC
    if (ctx->r8 == 0) {
        // 0x801D09E4: nop
    
            goto L_801D09FC;
    }
    // 0x801D09E4: nop

    // 0x801D09E8: jal         0x80129554
    // 0x801D09EC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80129554)(rdram, ctx);
        goto after_6;
    // 0x801D09EC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x801D09F0: beq         $v0, $zero, L_801D09FC
    if (ctx->r2 == 0) {
        // 0x801D09F4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D09FC;
    }
    // 0x801D09F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D09F8: sw          $zero, -0x5014($at)
    MEM_W(-0X5014, ctx->r1) = 0;
L_801D09FC:
    // 0x801D09FC: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D0A00: lw          $t1, -0x5040($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5040);
    // 0x801D0A04: beql        $t1, $zero, L_801D0A18
    if (ctx->r9 == 0) {
        // 0x801D0A08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D0A18;
    }
    goto skip_1;
    // 0x801D0A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D0A0C: jal         0x801D0B64
    // 0x801D0A10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D0B64)(rdram, ctx);
        goto after_7;
    // 0x801D0A10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x801D0A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D0A18:
    // 0x801D0A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D0A1C: jr          $ra
    // 0x801D0A20: nop

    return;
    // 0x801D0A20: nop

;}
RECOMP_FUNC void M24_FUN_801d0a24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A24: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0A28: lw          $v0, -0x5024($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5024);
    // 0x801D0A2C: jr          $ra
    // 0x801D0A30: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D0A30: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0a34(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0a34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A34: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0A38: lw          $t6, -0x5024($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5024);
    // 0x801D0A3C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0A40: beq         $t6, $zero, L_801D0A50
    if (ctx->r14 == 0) {
            // 0x801D0A44: nop

    LOOKUP_FUNC(0x801D0A50)(rdram, ctx);
    return;
    }
    // 0x801D0A44: nop

    // 0x801D0A48: jr          $ra
    // 0x801D0A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D0A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0a50(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0a50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A50: lw          $v0, -0x501C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X501C);
    // 0x801D0A54: jr          $ra
    // 0x801D0A58: nop

    return;
    // 0x801D0A58: nop

;}
RECOMP_FUNC void M24_FUN_801d0a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A5C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0A60: jr          $ra
    // 0x801D0A64: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    return;
    // 0x801D0A64: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0a68(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0a68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0A6C: jr          $ra
    // 0x801D0A70: sw          $a0, -0x5018($at)
    MEM_W(-0X5018, ctx->r1) = ctx->r4;
    return;
    // 0x801D0A70: sw          $a0, -0x5018($at)
    MEM_W(-0X5018, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0a74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A74: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0A78: lw          $t6, -0x5018($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5018);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0a7c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0a7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0A84: beq         $t6, $zero, L_801D0ADC
    if (ctx->r14 == 0) {
        // 0x801D0A88: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801D0ADC;
    }
    // 0x801D0A88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D0A8C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0A90: jal         0x80006214
    // 0x801D0A94: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D0A94: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    after_0:
    // 0x801D0A98: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801D0A9C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801D0AA0: addiu       $v0, $v0, -0x2578
    ctx->r2 = ADD32(ctx->r2, -0X2578);
    // 0x801D0AA4: beql        $t7, $zero, L_801D0ACC
    if (ctx->r15 == 0) {
        // 0x801D0AA8: lw          $t0, 0x30($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X30);
            goto L_801D0ACC;
    }
    goto skip_0;
    // 0x801D0AA8: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x801D0AAC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801D0AB0: addiu       $v0, $v0, -0x2578
    ctx->r2 = ADD32(ctx->r2, -0X2578);
    // 0x801D0AB4: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x801D0AB8: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x801D0ABC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x801D0AC0: b           L_801D0ADC
    // 0x801D0AC4: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
        goto L_801D0ADC;
    // 0x801D0AC4: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x801D0AC8: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
L_801D0ACC:
    // 0x801D0ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801D0AD0: sb          $v1, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r3;
    // 0x801D0AD4: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x801D0AD8: sb          $v1, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r3;
L_801D0ADC:
    // 0x801D0ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D0AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0AE4: jr          $ra
    // 0x801D0AE8: nop

    return;
    // 0x801D0AE8: nop

;}
RECOMP_FUNC void M24_FUN_801d0aec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0AEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0AF0: jr          $ra
    // 0x801D0AF4: sw          $a0, -0x5014($at)
    MEM_W(-0X5014, ctx->r1) = ctx->r4;
    return;
    // 0x801D0AF4: sw          $a0, -0x5014($at)
    MEM_W(-0X5014, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0af8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0AF8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0AFC: jr          $ra
    // 0x801D0B00: lw          $v0, -0x5014($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5014);
    return;
    // 0x801D0B00: lw          $v0, -0x5014($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5014);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0b04(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0B04: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D0B08: addiu       $v0, $v0, -0x5040
    ctx->r2 = ADD32(ctx->r2, -0X5040);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d0b0c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d0b0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0B14: beq         $a0, $zero, L_801D0B40
    if (ctx->r4 == 0) {
        // 0x801D0B18: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D0B40;
    }
    // 0x801D0B18: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D0B1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0B20: jal         0x801C0B2C
    // 0x801D0B24: sw          $zero, -0x5020($at)
    MEM_W(-0X5020, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D0B24: sw          $zero, -0x5020($at)
    MEM_W(-0X5020, ctx->r1) = 0;
    after_0:
    // 0x801D0B28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0B2C: sw          $v0, 0x1318($at)
    MEM_W(0X1318, ctx->r1) = ctx->r2;
    // 0x801D0B30: sw          $v1, 0x131C($at)
    MEM_W(0X131C, ctx->r1) = ctx->r3;
    // 0x801D0B34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0B38: b           L_801D0B54
    // 0x801D0B3C: sw          $zero, 0x1320($at)
    MEM_W(0X1320, ctx->r1) = 0;
        goto L_801D0B54;
    // 0x801D0B3C: sw          $zero, 0x1320($at)
    MEM_W(0X1320, ctx->r1) = 0;
L_801D0B40:
    // 0x801D0B40: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0B44: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    // 0x801D0B48: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D0B4C: jal         0x8012D844
    // 0x801D0B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D0B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D0B54:
    // 0x801D0B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D0B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0B5C: jr          $ra
    // 0x801D0B60: nop

    return;
    // 0x801D0B60: nop

;}
RECOMP_FUNC void M24_FUN_801d0b64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0B64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D0B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0B6C: jal         0x801C0B2C
    // 0x801D0B70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D0B70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D0B74: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0B78: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0B7C: lw          $t7, 0x131C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X131C);
    // 0x801D0B80: lw          $t6, 0x1318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1318);
    // 0x801D0B84: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D0B88: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D0B8C: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D0B90: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D0B94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0B98: jal         0x80034C24
    // 0x801D0B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D0B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D0BA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0BA4: ldc1        $f4, -0x2B90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2B90);
    // 0x801D0BA8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0BAC: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, 0X1320);
    // 0x801D0BB0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D0BB4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D0BB8: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D0BBC: addiu       $t1, $t1, -0x5010
    ctx->r9 = ADD32(ctx->r9, -0X5010);
    // 0x801D0BC0: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D0BC4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D0BC8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D0BCC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D0BD0: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D0BD4: nop

    // 0x801D0BD8: bc1fl       L_801D0CB8
    if (!c1cs) {
        // 0x801D0BDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D0CB8;
    }
    goto skip_0;
    // 0x801D0BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D0BE0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D0BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D0BE8: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D0BEC: beq         $v0, $zero, L_801D0C10
    if (ctx->r2 == 0) {
        // 0x801D0BF0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D0C10;
    }
    // 0x801D0BF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D0BF4: beq         $v0, $at, L_801D0C2C
    if (ctx->r2 == ctx->r1) {
        // 0x801D0BF8: addiu       $a1, $zero, 0x57
        ctx->r5 = ADD32(0, 0X57);
            goto L_801D0C2C;
    }
    // 0x801D0BF8: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D0BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D0C00: beq         $v0, $at, L_801D0C4C
    if (ctx->r2 == ctx->r1) {
        // 0x801D0C04: addiu       $a1, $zero, 0x57
        ctx->r5 = ADD32(0, 0X57);
            goto L_801D0C4C;
    }
    // 0x801D0C04: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x801D0C08: b           L_801D0C6C
    // 0x801D0C0C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D0C6C;
    // 0x801D0C0C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D0C10:
    // 0x801D0C10: jal         0x8012D844
    // 0x801D0C14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D0C14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D0C18: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0C1C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0C20: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, 0X1320);
    // 0x801D0C24: b           L_801D0C68
    // 0x801D0C28: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
        goto L_801D0C68;
    // 0x801D0C28: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
L_801D0C2C:
    // 0x801D0C2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D0C30: jal         0x8012D844
    // 0x801D0C34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D0C34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D0C38: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0C3C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0C40: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, 0X1320);
    // 0x801D0C44: b           L_801D0C68
    // 0x801D0C48: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
        goto L_801D0C68;
    // 0x801D0C48: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
L_801D0C4C:
    // 0x801D0C4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D0C50: jal         0x8012D844
    // 0x801D0C54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D0C54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D0C58: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0C5C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0C60: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, 0X1320);
    // 0x801D0C64: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
L_801D0C68:
    // 0x801D0C68: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D0C6C:
    // 0x801D0C6C: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D0C70: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D0C74: bne         $at, $zero, L_801D0CA0
    if (ctx->r1 != 0) {
        // 0x801D0C78: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D0CA0;
    }
    // 0x801D0C78: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D0C7C: jal         0x801C0B2C
    // 0x801D0C80: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D0C80: nop

    after_5:
    // 0x801D0C84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0C88: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D0C8C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D0C90: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, 0X1320);
    // 0x801D0C94: lw          $a0, 0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1320);
    // 0x801D0C98: sw          $v0, 0x1318($at)
    MEM_W(0X1318, ctx->r1) = ctx->r2;
    // 0x801D0C9C: sw          $v1, 0x131C($at)
    MEM_W(0X131C, ctx->r1) = ctx->r3;
L_801D0CA0:
    // 0x801D0CA0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D0CA4: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D0CA8: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D0CAC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D0CB0: nop

    // 0x801D0CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0CB8:
    // 0x801D0CB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D0CBC: jr          $ra
    // 0x801D0CC0: nop

    return;
    // 0x801D0CC0: nop

;}
RECOMP_FUNC void M24_FUN_801d0cc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0CC4: nop

    // 0x801D0CC8: nop

    // 0x801D0CCC: nop

;}
RECOMP_FUNC void M24_FUN_801d0cd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0CD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801D0CD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0CD8: sw          $a0, 0x1330($at)
    MEM_W(0X1330, ctx->r1) = ctx->r4;
    // 0x801D0CDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0CE0: sw          $zero, -0x4F7C($at)
    MEM_W(-0X4F7C, ctx->r1) = 0;
    // 0x801D0CE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0CE8: sw          $zero, -0x4F78($at)
    MEM_W(-0X4F78, ctx->r1) = 0;
    // 0x801D0CEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0CF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D0CF4: sw          $t6, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r14;
    // 0x801D0CF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801D0CFC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801D0D00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0D04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D0D08: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x801D0D0C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801D0D10: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x801D0D14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D0D18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801D0D1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801D0D20: sw          $zero, 0x1334($at)
    MEM_W(0X1334, ctx->r1) = 0;
    // 0x801D0D24: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801D0D28: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801D0D2C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801D0D30: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801D0D34: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801D0D38: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801D0D3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D0D40: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D0D44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801D0D48: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801D0D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D0D50: jal         0x801CC654
    // 0x801D0D54: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    LOOKUP_FUNC(0x801CC654)(rdram, ctx);
        goto after_0;
    // 0x801D0D54: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_0:
    // 0x801D0D58: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801D0D5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0D60: addiu       $t4, $t4, 0xD90
    ctx->r12 = ADD32(ctx->r12, 0XD90);
    // 0x801D0D64: sw          $v0, -0x4F50($at)
    MEM_W(-0X4F50, ctx->r1) = ctx->r2;
    // 0x801D0D68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801D0D6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801D0D70: addiu       $a1, $zero, 0x141
    ctx->r5 = ADD32(0, 0X141);
    // 0x801D0D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D0D78: jal         0x8013B570
    // 0x801D0D7C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x801D0D7C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801D0D80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801D0D84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801D0D88: jr          $ra
    // 0x801D0D8C: nop

    return;
    // 0x801D0D8C: nop

;}
RECOMP_FUNC void M24_FUN_801d0d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0D98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0D9C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D0DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D0DA4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0DA8: beq         $t6, $zero, L_801D0DE4
    if (ctx->r14 == 0) {
        // 0x801D0DAC: nop
    
            goto L_801D0DE4;
    }
    // 0x801D0DAC: nop

    // 0x801D0DB0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D0DB4: jal         0x8012D844
    // 0x801D0DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D0DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D0DBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0DC0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D0DC4: jal         0x8012D894
    // 0x801D0DC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x801D0DC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x801D0DCC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D0DD4: jal         0x800058DC
    // 0x801D0DD8: addiu       $a1, $a1, 0xDFC
    ctx->r5 = ADD32(ctx->r5, 0XDFC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D0DD8: addiu       $a1, $a1, 0xDFC
    ctx->r5 = ADD32(ctx->r5, 0XDFC);
    after_2:
    // 0x801D0DDC: b           L_801D0DF0
    // 0x801D0DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D0DF0;
    // 0x801D0DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0DE4:
    // 0x801D0DE4: jal         0x800058DC
    // 0x801D0DE8: addiu       $a1, $a1, 0xD90
    ctx->r5 = ADD32(ctx->r5, 0XD90);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801D0DE8: addiu       $a1, $a1, 0xD90
    ctx->r5 = ADD32(ctx->r5, 0XD90);
    after_3:
    // 0x801D0DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0DF0:
    // 0x801D0DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0DF4: jr          $ra
    // 0x801D0DF8: nop

    return;
    // 0x801D0DF8: nop

;}
RECOMP_FUNC void M24_FUN_801d0dfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D0E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D0E04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D0E08: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D0E0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D0E10: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0E14: beq         $t6, $zero, L_801D0F54
    if (ctx->r14 == 0) {
        // 0x801D0E18: nop
    
            goto L_801D0F54;
    }
    // 0x801D0E18: nop

    // 0x801D0E1C: lw          $t7, -0x4F60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F60);
    // 0x801D0E20: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D0E24: addiu       $a2, $a2, -0x4F74
    ctx->r6 = ADD32(ctx->r6, -0X4F74);
    // 0x801D0E28: beq         $t7, $zero, L_801D0F28
    if (ctx->r15 == 0) {
        // 0x801D0E2C: nop
    
            goto L_801D0F28;
    }
    // 0x801D0E2C: nop

    // 0x801D0E30: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D0E34: jal         0x80005FAC
    // 0x801D0E38: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D0E38: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D0E3C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D0E40: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D0E44: lw          $t9, 0x984($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X984);
    // 0x801D0E48: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D0E4C: addiu       $v1, $v1, -0x4F64
    ctx->r3 = ADD32(ctx->r3, -0X4F64);
    // 0x801D0E50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D0E54: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D0E58: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D0E5C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D0E60: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D0E64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D0E68: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801D0E6C: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D0E70: lw          $t4, 0x984($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X984);
    // 0x801D0E74: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D0E78: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D0E7C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D0E80: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D0E84: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D0E88: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D0E8C: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D0E90: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D0E94: lw          $t9, 0x984($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X984);
    // 0x801D0E98: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D0E9C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D0EA0: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D0EA4: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D0EA8: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D0EAC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EB0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D0EB4: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D0EB8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EBC: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D0EC0: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D0EC4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EC8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D0ECC: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D0ED0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D0ED4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D0ED8: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D0EDC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EE0: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D0EE4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D0EE8: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D0EEC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EF0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D0EF4: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D0EF8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D0EFC: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D0F00: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D0F04: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D0F08: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D0F0C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D0F10: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D0F14: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D0F18: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D0F1C: lw          $t1, -0x4F5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4F5C);
    // 0x801D0F20: b           L_801D0F3C
    // 0x801D0F24: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D0F3C;
    // 0x801D0F24: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D0F28:
    // 0x801D0F28: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D0F2C: addiu       $v1, $v1, -0x4F64
    ctx->r3 = ADD32(ctx->r3, -0X4F64);
    // 0x801D0F30: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D0F34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0F38: sw          $zero, -0x4F5C($at)
    MEM_W(-0X4F5C, ctx->r1) = 0;
L_801D0F3C:
    // 0x801D0F3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0F40: addiu       $a1, $a1, 0xF74
    ctx->r5 = ADD32(ctx->r5, 0XF74);
    // 0x801D0F44: jal         0x800058DC
    // 0x801D0F48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D0F48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D0F4C: b           L_801D0F68
    // 0x801D0F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D0F68;
    // 0x801D0F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0F54:
    // 0x801D0F54: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0F58: addiu       $a1, $a1, 0xDFC
    ctx->r5 = ADD32(ctx->r5, 0XDFC);
    // 0x801D0F5C: jal         0x800058DC
    // 0x801D0F60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D0F60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D0F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D0F68:
    // 0x801D0F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D0F6C: jr          $ra
    // 0x801D0F70: nop

    return;
    // 0x801D0F70: nop

;}
RECOMP_FUNC void M24_FUN_801d0f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D0F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D0F78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D0F7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D0F80: jal         0x801CC540
    // 0x801D0F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D0F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D0F88: beq         $v0, $zero, L_801D0FA8
    if (ctx->r2 == 0) {
        // 0x801D0F8C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D0FA8;
    }
    // 0x801D0F8C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D0F90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D0F94: addiu       $a1, $a1, 0xF74
    ctx->r5 = ADD32(ctx->r5, 0XF74);
    // 0x801D0F98: jal         0x800058DC
    // 0x801D0F9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D0F9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D0FA0: b           L_801D11A0
    // 0x801D0FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D11A0;
    // 0x801D0FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D0FA8:
    // 0x801D0FA8: lw          $t6, -0x4F7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F7C);
    // 0x801D0FAC: beq         $t6, $zero, L_801D1004
    if (ctx->r14 == 0) {
        // 0x801D0FB0: nop
    
            goto L_801D1004;
    }
    // 0x801D0FB0: nop

    // 0x801D0FB4: jal         0x80006214
    // 0x801D0FB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D0FB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D0FBC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D0FC0: lw          $t7, -0x4F7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F7C);
    // 0x801D0FC4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D0FC8: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D0FCC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D0FD0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D0FD4: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D0FD8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D0FDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D0FE0: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D0FE4: jal         0x8013A28C
    // 0x801D0FE8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D0FE8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D0FEC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D0FF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D0FF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D0FF8: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D0FFC: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D1000: sw          $zero, -0x4F7C($at)
    MEM_W(-0X4F7C, ctx->r1) = 0;
L_801D1004:
    // 0x801D1004: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1008: lw          $v0, -0x4F78($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F78);
    // 0x801D100C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D1010: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D1014: beq         $v0, $zero, L_801D10E0
    if (ctx->r2 == 0) {
        // 0x801D1018: nop
    
            goto L_801D10E0;
    }
    // 0x801D1018: nop

    // 0x801D101C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D1020: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D1024: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D1028: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D102C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D1030: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1034: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1038: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D103C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D1040: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D1044: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D1048: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D104C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D1050: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D1054: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D1058: nop

    // 0x801D105C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D1060: beql        $t4, $zero, L_801D10B0
    if (ctx->r12 == 0) {
        // 0x801D1064: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D10B0;
    }
    goto skip_0;
    // 0x801D1064: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D1068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D106C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1070: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D1074: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1078: nop

    // 0x801D107C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D1080: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D1084: nop

    // 0x801D1088: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D108C: bne         $t4, $zero, L_801D10A4
    if (ctx->r12 != 0) {
        // 0x801D1090: nop
    
            goto L_801D10A4;
    }
    // 0x801D1090: nop

    // 0x801D1094: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D1098: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D109C: b           L_801D10BC
    // 0x801D10A0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D10BC;
    // 0x801D10A0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D10A4:
    // 0x801D10A4: b           L_801D10BC
    // 0x801D10A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D10BC;
    // 0x801D10A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D10AC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D10B0:
    // 0x801D10B0: nop

    // 0x801D10B4: bltz        $t4, L_801D10A4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D10B8: nop
    
            goto L_801D10A4;
    }
    // 0x801D10B8: nop

L_801D10BC:
    // 0x801D10BC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D10C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D10C4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D10C8: jal         0x80011140
    // 0x801D10CC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D10CC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D10D0: beq         $v0, $zero, L_801D1158
    if (ctx->r2 == 0) {
        // 0x801D10D4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1158;
    }
    // 0x801D10D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D10D8: b           L_801D1158
    // 0x801D10DC: sw          $zero, -0x4F78($at)
    MEM_W(-0X4F78, ctx->r1) = 0;
        goto L_801D1158;
    // 0x801D10DC: sw          $zero, -0x4F78($at)
    MEM_W(-0X4F78, ctx->r1) = 0;
L_801D10E0:
    // 0x801D10E0: jal         0x80010550
    // 0x801D10E4: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D10E4: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D10E8: beq         $v0, $zero, L_801D1100
    if (ctx->r2 == 0) {
        // 0x801D10EC: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1100;
    }
    // 0x801D10EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D10F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D10F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D10F8: b           L_801D1104
    // 0x801D10FC: sw          $t5, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r13;
        goto L_801D1104;
    // 0x801D10FC: sw          $t5, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r13;
L_801D1100:
    // 0x801D1100: sw          $zero, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = 0;
L_801D1104:
    // 0x801D1104: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D1108: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D110C: addiu       $t6, $t6, 0x1348
    ctx->r14 = ADD32(ctx->r14, 0X1348);
    // 0x801D1110: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D1114: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D1118: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D111C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D1120: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D1124: addiu       $t2, $t2, 0x1338
    ctx->r10 = ADD32(ctx->r10, 0X1338);
    // 0x801D1128: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D112C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D1130: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D1134: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D1138: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D113C: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D1140: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D1144: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D1148: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D114C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D1150: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D1154: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D1158:
    // 0x801D1158: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D115C: lw          $t7, -0x4F60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F60);
    // 0x801D1160: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D1164: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1168: beq         $t7, $zero, L_801D117C
    if (ctx->r15 == 0) {
        // 0x801D116C: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801D117C;
    }
    // 0x801D116C: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D1170: lw          $t8, -0x4F5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4F5C);
    // 0x801D1174: lw          $t6, -0x4F64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F64);
    // 0x801D1178: sb          $t8, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r24;
L_801D117C:
    // 0x801D117C: lw          $t9, 0x1334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1334);
    // 0x801D1180: beq         $t9, $zero, L_801D1190
    if (ctx->r25 == 0) {
        // 0x801D1184: nop
    
            goto L_801D1190;
    }
    // 0x801D1184: nop

    // 0x801D1188: jal         0x801D12B8
    // 0x801D118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D12B8)(rdram, ctx);
        goto after_6;
    // 0x801D118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801D1190:
    // 0x801D1190: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1194: jal         0x801CC6F4
    // 0x801D1198: lw          $a0, -0x4F50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4F50);
    LOOKUP_FUNC(0x801CC6F4)(rdram, ctx);
        goto after_7;
    // 0x801D1198: lw          $a0, -0x4F50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4F50);
    after_7:
    // 0x801D119C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D11A0:
    // 0x801D11A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D11A4: jr          $ra
    // 0x801D11A8: nop

    return;
    // 0x801D11A8: nop

;}
RECOMP_FUNC void M24_FUN_801d11ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D11AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D11B0: jr          $ra
    // 0x801D11B4: sw          $a0, -0x4F60($at)
    MEM_W(-0X4F60, ctx->r1) = ctx->r4;
    return;
    // 0x801D11B4: sw          $a0, -0x4F60($at)
    MEM_W(-0X4F60, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d11b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d11b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D11B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D11BC: jr          $ra
    // 0x801D11C0: sw          $a0, -0x4F5C($at)
    MEM_W(-0X4F5C, ctx->r1) = ctx->r4;
    return;
    // 0x801D11C0: sw          $a0, -0x4F5C($at)
    MEM_W(-0X4F5C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d11c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d11c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D11C4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D11C8: lw          $v0, -0x4F78($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F78);
    // 0x801D11CC: jr          $ra
    // 0x801D11D0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D11D0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d11d4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d11d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D11D4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D11D8: lw          $t6, -0x4F78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F78);
    // 0x801D11DC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D11E0: beq         $t6, $zero, L_801D11F0
    if (ctx->r14 == 0) {
            // 0x801D11E4: nop

    LOOKUP_FUNC(0x801D11F0)(rdram, ctx);
    return;
    }
    // 0x801D11E4: nop

    // 0x801D11E8: jr          $ra
    // 0x801D11EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D11EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d11f0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d11f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D11F0: lw          $t7, -0x4F7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F7C);
    // 0x801D11F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D11F8: beq         $t7, $zero, L_801D1208
    if (ctx->r15 == 0) {
            // 0x801D11FC: nop

    LOOKUP_FUNC(0x801D1208)(rdram, ctx);
    return;
    }
    // 0x801D11FC: nop

    // 0x801D1200: jr          $ra
    // 0x801D1204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1208(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1208: lw          $v0, -0x4F58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F58);
    // 0x801D120C: jr          $ra
    // 0x801D1210: nop

    return;
    // 0x801D1210: nop

;}
RECOMP_FUNC void M24_FUN_801d1214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1214: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1218: jr          $ra
    // 0x801D121C: addiu       $v0, $v0, 0x1338
    ctx->r2 = ADD32(ctx->r2, 0X1338);
    return;
    // 0x801D121C: addiu       $v0, $v0, 0x1338
    ctx->r2 = ADD32(ctx->r2, 0X1338);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1220(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1220: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D1224: addiu       $v1, $v1, 0x1348
    ctx->r3 = ADD32(ctx->r3, 0X1348);
    // 0x801D1228: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D122C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D1230: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D1234: beql        $a0, $t6, L_801D1248
    if (ctx->r4 == ctx->r14) {
        // 0x801D1238: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D1248;
    }
    goto skip_0;
    // 0x801D1238: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D123C: jr          $ra
    // 0x801D1240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D1244: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D1248:
    // 0x801D1248: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D124C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D1250: jr          $ra
    // 0x801D1254: nop

    return;
    // 0x801D1254: nop

;}
