#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801f8efc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8EFC: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F8F00: lw          $v0, -0x45B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X45B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f8f04(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f8f04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8F04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8F08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8F0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F8F10: beq         $v0, $zero, L_801F8F3C
    if (ctx->r2 == 0) {
        // 0x801F8F14: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801F8F3C;
    }
    // 0x801F8F14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F8F18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F8F1C: beq         $v0, $at, L_801F9004
    if (ctx->r2 == ctx->r1) {
        // 0x801F8F20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801F9004;
    }
    // 0x801F8F20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F8F24: beq         $v0, $at, L_801F9044
    if (ctx->r2 == ctx->r1) {
        // 0x801F8F28: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801F9044;
    }
    // 0x801F8F28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801F8F2C: beq         $v0, $at, L_801F9084
    if (ctx->r2 == ctx->r1) {
        // 0x801F8F30: nop
    
            goto L_801F9084;
    }
    // 0x801F8F30: nop

    // 0x801F8F34: b           L_801F90C0
    // 0x801F8F38: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F90C0;
    // 0x801F8F38: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F8F3C:
    // 0x801F8F3C: lui         $a1, 0x226
    ctx->r5 = S32(0X226 << 16);
    // 0x801F8F40: ori         $a1, $a1, 0xD79F
    ctx->r5 = ctx->r5 | 0XD79F;
    // 0x801F8F44: jal         0x801C0B8C
    // 0x801F8F48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F8F48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F8F4C: beq         $v0, $zero, L_801F90BC
    if (ctx->r2 == 0) {
        // 0x801F8F50: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F90BC;
    }
    // 0x801F8F50: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F8F54: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F8F58: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8F5C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8F60: lwc1        $f4, -0x2C08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C08);
    // 0x801F8F64: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8F68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F8F6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8F70: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8F74: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F8F78: ori         $a1, $a1, 0x28
    ctx->r5 = ctx->r5 | 0X28;
    // 0x801F8F7C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8F80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F8F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8F88: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8F90: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F8F94: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F8F98: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F8F9C: addiu       $t1, $zero, 0x1B8E
    ctx->r9 = ADD32(0, 0X1B8E);
    // 0x801F8FA0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8FA4: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F8FA8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F8FAC: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801F8FB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F8FB4: lwc1        $f8, -0x2C04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C04);
    // 0x801F8FB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8FBC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F8FC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F8FC4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F8FC8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F8FCC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8FD0: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801F8FD4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F8FD8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F8FDC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F8FE0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F8FE4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F8FE8: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F8FEC: jal         0x801CC470
    // 0x801F8FF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F8FF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F8FF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F8FF8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F8FFC: b           L_801F90BC
    // 0x801F9000: sw          $t7, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r15;
        goto L_801F90BC;
    // 0x801F9000: sw          $t7, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r15;
L_801F9004:
    // 0x801F9004: jal         0x801D0408
    // 0x801F9008: nop

    LOOKUP_FUNC(0x801D0408)(rdram, ctx);
        goto after_2;
    // 0x801F9008: nop

    after_2:
    // 0x801F900C: beq         $v0, $zero, L_801F90BC
    if (ctx->r2 == 0) {
        // 0x801F9010: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801F90BC;
    }
    // 0x801F9010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F9014: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9018: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F901C: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F9020: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x801F9024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F902C: jal         0x801CC470
    // 0x801F9030: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_3;
    // 0x801F9030: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801F9034: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801F9038: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F903C: b           L_801F90BC
    // 0x801F9040: sw          $t8, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r24;
        goto L_801F90BC;
    // 0x801F9040: sw          $t8, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r24;
L_801F9044:
    // 0x801F9044: jal         0x801D0408
    // 0x801F9048: nop

    LOOKUP_FUNC(0x801D0408)(rdram, ctx);
        goto after_4;
    // 0x801F9048: nop

    after_4:
    // 0x801F904C: beq         $v0, $zero, L_801F90BC
    if (ctx->r2 == 0) {
        // 0x801F9050: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801F90BC;
    }
    // 0x801F9050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F9054: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9058: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F905C: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F9060: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x801F9064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F906C: jal         0x801CC470
    // 0x801F9070: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_5;
    // 0x801F9070: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801F9074: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801F9078: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F907C: b           L_801F90BC
    // 0x801F9080: sw          $t9, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r25;
        goto L_801F90BC;
    // 0x801F9080: sw          $t9, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r25;
L_801F9084:
    // 0x801F9084: jal         0x801D0408
    // 0x801F9088: nop

    LOOKUP_FUNC(0x801D0408)(rdram, ctx);
        goto after_6;
    // 0x801F9088: nop

    after_6:
    // 0x801F908C: beq         $v0, $zero, L_801F90BC
    if (ctx->r2 == 0) {
        // 0x801F9090: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801F90BC;
    }
    // 0x801F9090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F9094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F9098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F909C: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F90A0: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x801F90A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F90A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F90AC: jal         0x801CC470
    // 0x801F90B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_7;
    // 0x801F90B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801F90B4: b           L_801F90C0
    // 0x801F90B8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801F90C0;
    // 0x801F90B8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F90BC:
    // 0x801F90BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F90C0:
    // 0x801F90C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F90C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F90C8: jr          $ra
    // 0x801F90CC: nop

    return;
    // 0x801F90CC: nop

;}
RECOMP_FUNC void M25_FUN_801f90d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F90D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F90D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F90D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F90DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F90E0: jal         0x801BF6B0
    // 0x801F90E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F90E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F90E8: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F90EC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801F90F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F90F4: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x801F90F8: bne         $at, $zero, L_801F9108
    if (ctx->r1 != 0) {
        // 0x801F90FC: nop
    
            goto L_801F9108;
    }
    // 0x801F90FC: nop

    // 0x801F9100: b           L_801F9108
    // 0x801F9104: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F9108;
    // 0x801F9104: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F9108:
    // 0x801F9108: jr          $ra
    // 0x801F910C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F910C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9110(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9114: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F911C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9120: lui         $a1, 0x31A
    ctx->r5 = S32(0X31A << 16);
    // 0x801F9124: ori         $a1, $a1, 0xFB9F
    ctx->r5 = ctx->r5 | 0XFB9F;
    // 0x801F9128: jal         0x801C0B8C
    // 0x801F912C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F912C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9130: beq         $v0, $zero, L_801F9140
    if (ctx->r2 == 0) {
        // 0x801F9134: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F9140;
    }
    // 0x801F9134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9138: b           L_801F9144
    // 0x801F913C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F9144;
    // 0x801F913C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F9140:
    // 0x801F9140: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F9144:
    // 0x801F9144: jr          $ra
    // 0x801F9148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F9148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f914c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f914c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F914C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F915C: jal         0x801BF6B0
    // 0x801F9160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_0;
    // 0x801F9160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801F9164: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801F9168: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801F916C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9170: slti        $at, $t6, 0xE
    ctx->r1 = SIGNED(ctx->r14) < 0XE ? 1 : 0;
    // 0x801F9174: bne         $at, $zero, L_801F9184
    if (ctx->r1 != 0) {
        // 0x801F9178: nop
    
            goto L_801F9184;
    }
    // 0x801F9178: nop

    // 0x801F917C: b           L_801F9184
    // 0x801F9180: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9184;
    // 0x801F9180: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9184:
    // 0x801F9184: jr          $ra
    // 0x801F9188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F9188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f918c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f918c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F918C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F9190: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F9194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F9198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F919C: lui         $a1, 0x3CA
    ctx->r5 = S32(0X3CA << 16);
    // 0x801F91A0: ori         $a1, $a1, 0x757F
    ctx->r5 = ctx->r5 | 0X757F;
    // 0x801F91A4: jal         0x801C0B8C
    // 0x801F91A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F91A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F91AC: beq         $v0, $zero, L_801F925C
    if (ctx->r2 == 0) {
        // 0x801F91B0: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F925C;
    }
    // 0x801F91B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F91B4: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F91B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F91BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F91C0: lwc1        $f4, -0x2C00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C00);
    // 0x801F91C4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F91C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F91CC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x801F91D0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F91D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F91D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F91DC: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F91E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F91E4: lui         $a1, 0x190
    ctx->r5 = S32(0X190 << 16);
    // 0x801F91E8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F91EC: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x801F91F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F91F4: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F91F8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F91FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9200: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801F9204: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F9208: addiu       $t1, $zero, 0x1A22
    ctx->r9 = ADD32(0, 0X1A22);
    // 0x801F920C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F9210: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F9214: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F9218: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801F921C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F9220: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9224: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F9228: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F922C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9230: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801F9234: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F9238: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F923C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F9240: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F9244: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F9248: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F924C: jal         0x801CC470
    // 0x801F9250: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F9250: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F9254: b           L_801F9260
    // 0x801F9258: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F9260;
    // 0x801F9258: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F925C:
    // 0x801F925C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9260:
    // 0x801F9260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F9264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F9268: jr          $ra
    // 0x801F926C: nop

    return;
    // 0x801F926C: nop

;}
RECOMP_FUNC void M25_FUN_801f9270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F9274: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F9278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F927C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F9280: lui         $a1, 0x40F
    ctx->r5 = S32(0X40F << 16);
    // 0x801F9284: ori         $a1, $a1, 0x1FA0
    ctx->r5 = ctx->r5 | 0X1FA0;
    // 0x801F9288: jal         0x801C0B8C
    // 0x801F928C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F928C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9290: beq         $v0, $zero, L_801F9340
    if (ctx->r2 == 0) {
        // 0x801F9294: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F9340;
    }
    // 0x801F9294: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F9298: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F929C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F92A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F92A4: lwc1        $f4, -0x2BFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BFC);
    // 0x801F92A8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F92AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F92B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F92B4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F92B8: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F92BC: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x801F92C0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F92C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F92C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F92CC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F92D0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // 0x801F92D4: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F92D8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F92DC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F92E0: addiu       $t1, $zero, 0x1B60
    ctx->r9 = ADD32(0, 0X1B60);
    // 0x801F92E4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F92E8: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F92EC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F92F0: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801F92F4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F92F8: lwc1        $f8, -0x2BF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BF8);
    // 0x801F92FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F9300: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F9308: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F930C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F9310: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9314: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801F9318: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F931C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F9320: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F9324: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F9328: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F932C: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F9330: jal         0x801CC470
    // 0x801F9334: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F9334: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F9338: b           L_801F9344
    // 0x801F933C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F9344;
    // 0x801F933C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F9340:
    // 0x801F9340: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F9344:
    // 0x801F9344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F9348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F934C: jr          $ra
    // 0x801F9350: nop

    return;
    // 0x801F9350: nop

;}
RECOMP_FUNC void M25_FUN_801f9354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F9358: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F935C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F9360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F9364: lui         $a1, 0x422
    ctx->r5 = S32(0X422 << 16);
    // 0x801F9368: ori         $a1, $a1, 0x738A
    ctx->r5 = ctx->r5 | 0X738A;
    // 0x801F936C: jal         0x801C0B8C
    // 0x801F9370: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9370: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9374: beq         $v0, $zero, L_801F9424
    if (ctx->r2 == 0) {
        // 0x801F9378: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F9424;
    }
    // 0x801F9378: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F937C: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F9380: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F9384: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9388: lwc1        $f4, -0x2BF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BF4);
    // 0x801F938C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9390: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F9394: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9398: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F939C: lui         $a1, 0x348
    ctx->r5 = S32(0X348 << 16);
    // 0x801F93A0: ori         $a1, $a1, 0x8B
    ctx->r5 = ctx->r5 | 0X8B;
    // 0x801F93A4: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F93A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F93AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F93B0: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F93B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F93B8: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F93BC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801F93C0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F93C4: addiu       $t1, $zero, 0x1B60
    ctx->r9 = ADD32(0, 0X1B60);
    // 0x801F93C8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F93CC: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801F93D0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F93D4: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x801F93D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F93DC: lwc1        $f8, -0x2BF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BF0);
    // 0x801F93E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F93E4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F93E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F93EC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F93F0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F93F4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F93F8: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801F93FC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F9400: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F9404: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F9408: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F940C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F9410: sh          $t1, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r9;
    // 0x801F9414: jal         0x801CC470
    // 0x801F9418: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F9418: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F941C: b           L_801F9428
    // 0x801F9420: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801F9428;
    // 0x801F9420: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F9424:
    // 0x801F9424: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F9428:
    // 0x801F9428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F942C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F9430: jr          $ra
    // 0x801F9434: nop

    return;
    // 0x801F9434: nop

;}
RECOMP_FUNC void M25_FUN_801f9438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F943C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9444: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9448: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801F944C: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801F9450: jal         0x801C0B8C
    // 0x801F9454: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9454: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9458: beq         $v0, $zero, L_801F9488
    if (ctx->r2 == 0) {
        // 0x801F945C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801F9488;
    }
    // 0x801F945C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801F9460: lw          $t6, -0x54EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54EC);
    // 0x801F9464: lui         $at, 0x45A0
    ctx->r1 = S32(0X45A0 << 16);
    // 0x801F9468: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F946C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9470: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x801F9474: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F9478: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F947C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9480: b           L_801F948C
    // 0x801F9484: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
        goto L_801F948C;
    // 0x801F9484: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
L_801F9488:
    // 0x801F9488: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801F948C:
    // 0x801F948C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9494: jr          $ra
    // 0x801F9498: nop

    return;
    // 0x801F9498: nop

;}
RECOMP_FUNC void M25_FUN_801f949c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F949C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F94A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F94A4: jr          $ra
    // 0x801F94A8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801F94A8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f94ac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f94ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F94AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F94B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F94B4: jr          $ra
    // 0x801F94B8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801F94B8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f94bc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f94bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F94BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F94C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F94C4: jr          $ra
    // 0x801F94C8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801F94C8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f94cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f94cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F94CC: addiu       $sp, $sp, -0x210
    ctx->r29 = ADD32(ctx->r29, -0X210);
    // 0x801F94D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F94D4: sw          $a0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r4;
    // 0x801F94D8: sw          $a1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r5;
    // 0x801F94DC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801F94E0: jal         0x801BF628
    // 0x801F94E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801F94E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801F94E8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801F94EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F94F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F94F4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801F94F8: bne         $at, $zero, L_801F9508
    if (ctx->r1 != 0) {
        // 0x801F94FC: nop
    
            goto L_801F9508;
    }
    // 0x801F94FC: nop

    // 0x801F9500: b           L_801F9508
    // 0x801F9504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F9508;
    // 0x801F9504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F9508:
    // 0x801F9508: jr          $ra
    // 0x801F950C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    return;
    // 0x801F950C: addiu       $sp, $sp, 0x210
    ctx->r29 = ADD32(ctx->r29, 0X210);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9510(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9510: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801F9514: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9518(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F951C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F9520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F9524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F9528: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F952C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9530: lui         $at, 0xC0B0
    ctx->r1 = S32(0XC0B0 << 16);
    // 0x801F9534: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F9538: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801F953C: lw          $v0, 0x24($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X24);
    // 0x801F9540: beql        $v0, $zero, L_801F95E8
    if (ctx->r2 == 0) {
        // 0x801F9544: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801F95E8;
    }
    goto skip_0;
    // 0x801F9544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801F9548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F954C: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801F9550: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F9554: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9558: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801F955C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801F9560: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F9564: ori         $a1, $a1, 0x18
    ctx->r5 = ctx->r5 | 0X18;
    // 0x801F9568: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801F956C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F9570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9574: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F9578: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F957C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F9580: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x801F9584: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F9588: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F958C: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801F9590: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801F9594: lwc1        $f8, -0x2BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BEC);
    // 0x801F9598: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F959C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F95A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F95A4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801F95A8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F95AC: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F95B0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F95B4: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801F95B8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801F95BC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F95C0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F95C4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F95C8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F95CC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F95D0: sh          $t3, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r11;
    // 0x801F95D4: jal         0x801CC470
    // 0x801F95D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_0;
    // 0x801F95D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801F95DC: b           L_801F95E8
    // 0x801F95E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F95E8;
    // 0x801F95E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F95E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F95E8:
    // 0x801F95E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F95EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F95F0: jr          $ra
    // 0x801F95F4: nop

    return;
    // 0x801F95F4: nop

;}
RECOMP_FUNC void M25_FUN_801f95f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F95F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F95FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F9600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F9604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F9608: lui         $a1, 0x2F
    ctx->r5 = S32(0X2F << 16);
    // 0x801F960C: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    // 0x801F9610: jal         0x801C0B8C
    // 0x801F9614: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9614: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9618: beq         $v0, $zero, L_801F9648
    if (ctx->r2 == 0) {
        // 0x801F961C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801F9648;
    }
    // 0x801F961C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F9620: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F9624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9628: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801F962C: ori         $a1, $a1, 0x18
    ctx->r5 = ctx->r5 | 0X18;
    // 0x801F9630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9634: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x801F9638: jal         0x801CC470
    // 0x801F963C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F963C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F9640: b           L_801F964C
    // 0x801F9644: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F964C;
    // 0x801F9644: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F9648:
    // 0x801F9648: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F964C:
    // 0x801F964C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F9650: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F9654: jr          $ra
    // 0x801F9658: nop

    return;
    // 0x801F9658: nop

;}
RECOMP_FUNC void M25_FUN_801f965c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F965C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F9660: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F9664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F9668: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F966C: lui         $a1, 0xC7
    ctx->r5 = S32(0XC7 << 16);
    // 0x801F9670: ori         $a1, $a1, 0xE3DF
    ctx->r5 = ctx->r5 | 0XE3DF;
    // 0x801F9674: jal         0x801C0B8C
    // 0x801F9678: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9678: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F967C: beq         $v0, $zero, L_801F973C
    if (ctx->r2 == 0) {
        // 0x801F9680: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801F973C;
    }
    // 0x801F9680: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801F9684: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801F9688: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F968C: lui         $at, 0xC0B0
    ctx->r1 = S32(0XC0B0 << 16);
    // 0x801F9690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9694: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F9698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F969C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F96A0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F96A4: lui         $a1, 0x2A8
    ctx->r5 = S32(0X2A8 << 16);
    // 0x801F96A8: ori         $a1, $a1, 0x1A
    ctx->r5 = ctx->r5 | 0X1A;
    // 0x801F96AC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801F96B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F96B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F96B8: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F96BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F96C0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F96C4: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801F96C8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801F96CC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801F96D0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801F96D4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801F96D8: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x801F96DC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F96E0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F96E4: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x801F96E8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F96EC: lwc1        $f8, -0x2BE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BE8);
    // 0x801F96F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F96F4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801F96F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F96FC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801F9700: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801F9704: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801F9708: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F970C: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801F9710: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801F9714: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801F9718: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801F971C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801F9720: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x801F9724: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9728: sh          $t4, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r12;
    // 0x801F972C: jal         0x801CC470
    // 0x801F9730: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_1;
    // 0x801F9730: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F9734: b           L_801F9740
    // 0x801F9738: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F9740;
    // 0x801F9738: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F973C:
    // 0x801F973C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F9740:
    // 0x801F9740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F9744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F9748: jr          $ra
    // 0x801F974C: nop

    return;
    // 0x801F974C: nop

;}
RECOMP_FUNC void M25_FUN_801f9750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F975C: jal         0x801D0A34
    // 0x801F9760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801D0A34)(rdram, ctx);
        goto after_0;
    // 0x801F9760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F9764: beql        $v0, $zero, L_801F9788
    if (ctx->r2 == 0) {
        // 0x801F9768: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801F9788;
    }
    goto skip_0;
    // 0x801F9768: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801F976C: jal         0x801D0A74
    // 0x801F9770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0A74)(rdram, ctx);
        goto after_1;
    // 0x801F9770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801F9774: jal         0x801D0AEC
    // 0x801F9778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0AEC)(rdram, ctx);
        goto after_2;
    // 0x801F9778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801F977C: b           L_801F9788
    // 0x801F9780: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F9788;
    // 0x801F9780: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801F9784: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F9788:
    // 0x801F9788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F978C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9790: jr          $ra
    // 0x801F9794: nop

    return;
    // 0x801F9794: nop

;}
RECOMP_FUNC void M25_FUN_801f9798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F979C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F97A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F97A4: jal         0x801D0AF8
    // 0x801F97A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801D0AF8)(rdram, ctx);
        goto after_0;
    // 0x801F97A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F97AC: bne         $v0, $zero, L_801F97BC
    if (ctx->r2 != 0) {
        // 0x801F97B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F97BC;
    }
    // 0x801F97B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F97B4: b           L_801F97C0
    // 0x801F97B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F97C0;
    // 0x801F97B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F97BC:
    // 0x801F97BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F97C0:
    // 0x801F97C0: jr          $ra
    // 0x801F97C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F97C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f97c8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f97c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F97C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F97CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F97D0: jr          $ra
    // 0x801F97D4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F97D4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f97d8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f97d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F97D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F97DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F97E0: jr          $ra
    // 0x801F97E4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F97E4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f97e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f97e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F97E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F97EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F97F0: jr          $ra
    // 0x801F97F4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801F97F4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f97f8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f97f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F97F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F97FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9800: jr          $ra
    // 0x801F9804: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801F9804: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9808(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9808: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F980C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9810: jr          $ra
    // 0x801F9814: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x801F9814: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9818(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9818: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F981C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9820: jr          $ra
    // 0x801F9824: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801F9824: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9828(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9828: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F982C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9830: jr          $ra
    // 0x801F9834: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x801F9834: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9838(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9838: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F983C: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9840(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F9844: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F9848: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F984C: beq         $t6, $zero, L_801F985C
    if (ctx->r14 == 0) {
        // 0x801F9850: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801F985C;
    }
    // 0x801F9850: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F9854: b           L_801F98B0
    // 0x801F9858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801F98B0;
    // 0x801F9858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F985C:
    // 0x801F985C: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x801F9860: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x801F9864: jal         0x801C0B8C
    // 0x801F9868: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9868: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F986C: beq         $v0, $zero, L_801F98AC
    if (ctx->r2 == 0) {
        // 0x801F9870: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_801F98AC;
    }
    // 0x801F9870: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F9874: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F9878: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801F987C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801F9880: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F9884: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801F9888: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F988C: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801F9890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F9894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F989C: jal         0x8038C97C
    // 0x801F98A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801F98A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801F98A4: b           L_801F98B0
    // 0x801F98A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F98B0;
    // 0x801F98A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F98AC:
    // 0x801F98AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F98B0:
    // 0x801F98B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F98B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F98B8: jr          $ra
    // 0x801F98BC: nop

    return;
    // 0x801F98BC: nop

;}
RECOMP_FUNC void M25_FUN_801f98c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F98C0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F98C4: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801F98C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F98CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F98D0: beq         $t6, $zero, L_801F98E0
    if (ctx->r14 == 0) {
            // 0x801F98D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801F98E0)(rdram, ctx);
    return;
    }
    // 0x801F98D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F98D8: jr          $ra
    // 0x801F98DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F98DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f98e0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f98e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F98E0: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F98E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801F98E8: jr          $ra
    // 0x801F98EC: nop

    return;
    // 0x801F98EC: nop

;}
RECOMP_FUNC void M25_FUN_801f98f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F98F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F98F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F98F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F98FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F9900: lui         $a1, 0x497
    ctx->r5 = S32(0X497 << 16);
    // 0x801F9904: ori         $a1, $a1, 0x6F75
    ctx->r5 = ctx->r5 | 0X6F75;
    // 0x801F9908: jal         0x801C0B8C
    // 0x801F990C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F990C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9910: beq         $v0, $zero, L_801F9950
    if (ctx->r2 == 0) {
        // 0x801F9914: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_801F9950;
    }
    // 0x801F9914: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F9918: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F991C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801F9920: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F9924: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F9928: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801F992C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F9930: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801F9934: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801F9938: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801F993C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801F9940: jal         0x8038C97C
    // 0x801F9944: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801F9944: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801F9948: b           L_801F9954
    // 0x801F994C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F9954;
    // 0x801F994C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F9950:
    // 0x801F9950: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F9954:
    // 0x801F9954: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F9958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F995C: jr          $ra
    // 0x801F9960: nop

    return;
    // 0x801F9960: nop

;}
RECOMP_FUNC void M25_FUN_801f9964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9964: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F9968: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801F996C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F9970: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9974: beq         $t6, $zero, L_801F9984
    if (ctx->r14 == 0) {
            // 0x801F9978: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801F9984)(rdram, ctx);
    return;
    }
    // 0x801F9978: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F997C: jr          $ra
    // 0x801F9980: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801F9980: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9984(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9984: jr          $ra
    // 0x801F9988: nop

    return;
    // 0x801F9988: nop

;}
RECOMP_FUNC void M25_FUN_801f998c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F998C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F9990: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9994(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F9998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F999C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F99A0: beq         $t6, $zero, L_801F99B0
    if (ctx->r14 == 0) {
        // 0x801F99A4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801F99B0;
    }
    // 0x801F99A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F99A8: b           L_801F9A04
    // 0x801F99AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F9A04;
    // 0x801F99AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F99B0:
    // 0x801F99B0: lui         $a1, 0x49F
    ctx->r5 = S32(0X49F << 16);
    // 0x801F99B4: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    // 0x801F99B8: jal         0x801C0B8C
    // 0x801F99BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F99BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F99C0: beq         $v0, $zero, L_801F9A00
    if (ctx->r2 == 0) {
        // 0x801F99C4: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_801F9A00;
    }
    // 0x801F99C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F99C8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F99CC: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x801F99D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801F99D4: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F99D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801F99DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F99E0: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801F99E4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801F99E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801F99EC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801F99F0: jal         0x8038C97C
    // 0x801F99F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801F99F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801F99F8: b           L_801F9A04
    // 0x801F99FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F9A04;
    // 0x801F99FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F9A00:
    // 0x801F9A00: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F9A04:
    // 0x801F9A04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F9A08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F9A0C: jr          $ra
    // 0x801F9A10: nop

    return;
    // 0x801F9A10: nop

;}
RECOMP_FUNC void M25_FUN_801f9a14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9A14: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F9A18: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801F9A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F9A20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9A24: beq         $t6, $zero, L_801F9A34
    if (ctx->r14 == 0) {
            // 0x801F9A28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801F9A34)(rdram, ctx);
    return;
    }
    // 0x801F9A28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F9A2C: jr          $ra
    // 0x801F9A30: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801F9A30: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9a34(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9a34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9A34: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F9A38: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801F9A3C: jr          $ra
    // 0x801F9A40: nop

    return;
    // 0x801F9A40: nop

;}
RECOMP_FUNC void M25_FUN_801f9a44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9A44: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F9A48: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9a4c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9a4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9A4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F9A50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F9A54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F9A58: beq         $t6, $zero, L_801F9A68
    if (ctx->r14 == 0) {
        // 0x801F9A5C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801F9A68;
    }
    // 0x801F9A5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F9A60: b           L_801F9ABC
    // 0x801F9A64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F9ABC;
    // 0x801F9A64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F9A68:
    // 0x801F9A68: lui         $a1, 0x616
    ctx->r5 = S32(0X616 << 16);
    // 0x801F9A6C: ori         $a1, $a1, 0x6E55
    ctx->r5 = ctx->r5 | 0X6E55;
    // 0x801F9A70: jal         0x801C0B8C
    // 0x801F9A74: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9A74: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9A78: beq         $v0, $zero, L_801F9AB8
    if (ctx->r2 == 0) {
        // 0x801F9A7C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_801F9AB8;
    }
    // 0x801F9A7C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801F9A80: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801F9A84: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x801F9A88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F9A8C: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801F9A90: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801F9A94: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F9A98: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801F9A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F9AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F9AA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9AA8: jal         0x8038C97C
    // 0x801F9AAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801F9AAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801F9AB0: b           L_801F9ABC
    // 0x801F9AB4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801F9ABC;
    // 0x801F9AB4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F9AB8:
    // 0x801F9AB8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F9ABC:
    // 0x801F9ABC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F9AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F9AC4: jr          $ra
    // 0x801F9AC8: nop

    return;
    // 0x801F9AC8: nop

;}
RECOMP_FUNC void M25_FUN_801f9acc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9ACC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F9AD0: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801F9AD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F9AD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9ADC: beq         $t6, $zero, L_801F9AEC
    if (ctx->r14 == 0) {
            // 0x801F9AE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801F9AEC)(rdram, ctx);
    return;
    }
    // 0x801F9AE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801F9AE4: jr          $ra
    // 0x801F9AE8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801F9AE8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9aec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9aec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9AEC: jr          $ra
    // 0x801F9AF0: nop

    return;
    // 0x801F9AF0: nop

;}
RECOMP_FUNC void M25_FUN_801f9af4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9AF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F9AF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F9AFC: jr          $ra
    // 0x801F9B00: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801F9B00: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9b04(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9B10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9B14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801F9B18: jal         0x801C0B8C
    // 0x801F9B1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9B1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9B20: beql        $v0, $zero, L_801F9B44
    if (ctx->r2 == 0) {
        // 0x801F9B24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F9B44;
    }
    goto skip_0;
    // 0x801F9B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F9B28: jal         0x8038D28C
    // 0x801F9B2C: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9B2C: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_1:
    // 0x801F9B30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9B34: sw          $zero, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = 0;
    // 0x801F9B38: b           L_801F9B44
    // 0x801F9B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F9B44;
    // 0x801F9B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F9B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F9B44:
    // 0x801F9B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9B4C: jr          $ra
    // 0x801F9B50: nop

    return;
    // 0x801F9B50: nop

;}
RECOMP_FUNC void M25_FUN_801f9b54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9B54: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F9B58: lw          $v0, -0x44F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9b5c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9b5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9B68: beq         $v0, $zero, L_801F9B84
    if (ctx->r2 == 0) {
        // 0x801F9B6C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801F9B84;
    }
    // 0x801F9B6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F9B74: beq         $v0, $at, L_801F9BB4
    if (ctx->r2 == ctx->r1) {
        // 0x801F9B78: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F9BB4;
    }
    // 0x801F9B78: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F9B7C: b           L_801F9BDC
    // 0x801F9B80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F9BDC;
    // 0x801F9B80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F9B84:
    // 0x801F9B84: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x801F9B88: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x801F9B8C: jal         0x801C0B8C
    // 0x801F9B90: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9B90: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9B94: beql        $v0, $zero, L_801F9BDC
    if (ctx->r2 == 0) {
        // 0x801F9B98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801F9BDC;
    }
    goto skip_0;
    // 0x801F9B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801F9B9C: jal         0x8038D28C
    // 0x801F9BA0: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9BA0: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    after_1:
    // 0x801F9BA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F9BA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9BAC: b           L_801F9BD8
    // 0x801F9BB0: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
        goto L_801F9BD8;
    // 0x801F9BB0: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
L_801F9BB4:
    // 0x801F9BB4: lui         $a1, 0x2F
    ctx->r5 = S32(0X2F << 16);
    // 0x801F9BB8: jal         0x801C0B8C
    // 0x801F9BBC: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F9BBC: ori         $a1, $a1, 0x4D60
    ctx->r5 = ctx->r5 | 0X4D60;
    after_2:
    // 0x801F9BC0: beql        $v0, $zero, L_801F9BDC
    if (ctx->r2 == 0) {
        // 0x801F9BC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801F9BDC;
    }
    goto skip_1;
    // 0x801F9BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801F9BC8: jal         0x8038D28C
    // 0x801F9BCC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801F9BCC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_3:
    // 0x801F9BD0: b           L_801F9BDC
    // 0x801F9BD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801F9BDC;
    // 0x801F9BD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F9BD8:
    // 0x801F9BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F9BDC:
    // 0x801F9BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9BE4: jr          $ra
    // 0x801F9BE8: nop

    return;
    // 0x801F9BE8: nop

;}
RECOMP_FUNC void M25_FUN_801f9bec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9BF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9BFC: lui         $a1, 0x8A
    ctx->r5 = S32(0X8A << 16);
    // 0x801F9C00: ori         $a1, $a1, 0xDAE0
    ctx->r5 = ctx->r5 | 0XDAE0;
    // 0x801F9C04: jal         0x801C0B8C
    // 0x801F9C08: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9C08: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9C0C: beql        $v0, $zero, L_801F9C28
    if (ctx->r2 == 0) {
        // 0x801F9C10: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801F9C28;
    }
    goto skip_0;
    // 0x801F9C10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801F9C14: jal         0x8038D28C
    // 0x801F9C18: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9C18: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    after_1:
    // 0x801F9C1C: b           L_801F9C28
    // 0x801F9C20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801F9C28;
    // 0x801F9C20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801F9C24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801F9C28:
    // 0x801F9C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9C30: jr          $ra
    // 0x801F9C34: nop

    return;
    // 0x801F9C34: nop

;}
RECOMP_FUNC void M25_FUN_801f9c38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9C3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9C44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9C48: lui         $a1, 0xC7
    ctx->r5 = S32(0XC7 << 16);
    // 0x801F9C4C: ori         $a1, $a1, 0xE3DF
    ctx->r5 = ctx->r5 | 0XE3DF;
    // 0x801F9C50: jal         0x801C0B8C
    // 0x801F9C54: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9C54: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9C58: beql        $v0, $zero, L_801F9C74
    if (ctx->r2 == 0) {
        // 0x801F9C5C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801F9C74;
    }
    goto skip_0;
    // 0x801F9C5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801F9C60: jal         0x8038D28C
    // 0x801F9C64: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9C64: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_1:
    // 0x801F9C68: b           L_801F9C74
    // 0x801F9C6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801F9C74;
    // 0x801F9C6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801F9C70: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801F9C74:
    // 0x801F9C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9C7C: jr          $ra
    // 0x801F9C80: nop

    return;
    // 0x801F9C80: nop

;}
RECOMP_FUNC void M25_FUN_801f9c84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9C88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9C90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9C94: lui         $a1, 0xEE
    ctx->r5 = S32(0XEE << 16);
    // 0x801F9C98: ori         $a1, $a1, 0x8A68
    ctx->r5 = ctx->r5 | 0X8A68;
    // 0x801F9C9C: jal         0x801C0B8C
    // 0x801F9CA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9CA0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9CA4: beql        $v0, $zero, L_801F9CC0
    if (ctx->r2 == 0) {
        // 0x801F9CA8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801F9CC0;
    }
    goto skip_0;
    // 0x801F9CA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801F9CAC: jal         0x8038D28C
    // 0x801F9CB0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9CB0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_1:
    // 0x801F9CB4: b           L_801F9CC0
    // 0x801F9CB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801F9CC0;
    // 0x801F9CB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801F9CBC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801F9CC0:
    // 0x801F9CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9CC8: jr          $ra
    // 0x801F9CCC: nop

    return;
    // 0x801F9CCC: nop

;}
RECOMP_FUNC void M25_FUN_801f9cd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9CD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9CE0: lui         $a1, 0xF5
    ctx->r5 = S32(0XF5 << 16);
    // 0x801F9CE4: ori         $a1, $a1, 0xAA9F
    ctx->r5 = ctx->r5 | 0XAA9F;
    // 0x801F9CE8: jal         0x801C0B8C
    // 0x801F9CEC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9CEC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9CF0: beql        $v0, $zero, L_801F9D0C
    if (ctx->r2 == 0) {
        // 0x801F9CF4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_801F9D0C;
    }
    goto skip_0;
    // 0x801F9CF4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_0:
    // 0x801F9CF8: jal         0x8038D28C
    // 0x801F9CFC: addiu       $a0, $zero, 0x1E5
    ctx->r4 = ADD32(0, 0X1E5);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9CFC: addiu       $a0, $zero, 0x1E5
    ctx->r4 = ADD32(0, 0X1E5);
    after_1:
    // 0x801F9D00: b           L_801F9D0C
    // 0x801F9D04: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F9D0C;
    // 0x801F9D04: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801F9D08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801F9D0C:
    // 0x801F9D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9D14: jr          $ra
    // 0x801F9D18: nop

    return;
    // 0x801F9D18: nop

;}
RECOMP_FUNC void M25_FUN_801f9d1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9D20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9D28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9D2C: lui         $a1, 0x165
    ctx->r5 = S32(0X165 << 16);
    // 0x801F9D30: ori         $a1, $a1, 0xE40
    ctx->r5 = ctx->r5 | 0XE40;
    // 0x801F9D34: jal         0x801C0B8C
    // 0x801F9D38: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9D38: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9D3C: beql        $v0, $zero, L_801F9D58
    if (ctx->r2 == 0) {
        // 0x801F9D40: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_801F9D58;
    }
    goto skip_0;
    // 0x801F9D40: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_0:
    // 0x801F9D44: jal         0x8038D28C
    // 0x801F9D48: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9D48: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    after_1:
    // 0x801F9D4C: b           L_801F9D58
    // 0x801F9D50: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801F9D58;
    // 0x801F9D50: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801F9D54: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F9D58:
    // 0x801F9D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9D60: jr          $ra
    // 0x801F9D64: nop

    return;
    // 0x801F9D64: nop

;}
