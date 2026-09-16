#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80124ed8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80124ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80124EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80124EE0: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80124EE4: bne         $at, $zero, L_80124F00
    if (ctx->r1 != 0) {
        // 0x80124EE8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80124F00;
    }
    // 0x80124EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80124EEC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80124EF0: beq         $v0, $at, L_80124FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80124EF4: nop
    
            goto L_80124FC0;
    }
    // 0x80124EF4: nop

    // 0x80124EF8: b           L_80124FE8
    // 0x80124EFC: nop

        goto L_80124FE8;
    // 0x80124EFC: nop

L_80124F00:
    // 0x80124F00: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80124F04: bne         $at, $zero, L_80124F30
    if (ctx->r1 != 0) {
        // 0x80124F08: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80124F30;
    }
    // 0x80124F08: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80124F0C: addiu       $t6, $v0, -0x64
    ctx->r14 = ADD32(ctx->r2, -0X64);
    // 0x80124F10: sltiu       $at, $t6, 0x1C
    ctx->r1 = ctx->r14 < 0X1C ? 1 : 0;
    // 0x80124F14: beq         $at, $zero, L_80124FE8
    if (ctx->r1 == 0) {
        // 0x80124F18: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80124FE8;
    }
    // 0x80124F18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80124F1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80124F20: addu        $at, $at, $t6
    gpr jr_addend_80124F28 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80124F24: lw          $t6, -0x37E4($at)
    ctx->r14 = ADD32(ctx->r1, -0X37E4);
    // 0x80124F28: jr          $t6
    // 0x80124F2C: nop

    switch (jr_addend_80124F28 >> 2) {
        case 0: goto L_80124F68; break;
        case 1: goto L_80124F68; break;
        case 2: goto L_80124F68; break;
        case 3: goto L_80124F68; break;
        case 4: goto L_80124F68; break;
        case 5: goto L_80124F68; break;
        case 6: goto L_80124F68; break;
        case 7: goto L_80124F68; break;
        case 8: goto L_80124F68; break;
        case 9: goto L_80124F68; break;
        case 10: goto L_80124F68; break;
        case 11: goto L_80124F68; break;
        case 12: goto L_80124F68; break;
        case 13: goto L_80124F68; break;
        case 14: goto L_80124F68; break;
        case 15: goto L_80124F68; break;
        case 16: goto L_80124F68; break;
        case 17: goto L_80124F68; break;
        case 18: goto L_80124F68; break;
        case 19: goto L_80124F68; break;
        case 20: goto L_80124F68; break;
        case 21: goto L_80124F68; break;
        case 22: goto L_80124F68; break;
        case 23: goto L_80124F68; break;
        case 24: goto L_80124F68; break;
        case 25: goto L_80124F68; break;
        case 26: goto L_80124F68; break;
        case 27: goto L_80124F68; break;
        default: switch_error(__func__, 0x80124F28, 0x8018C81C);
    }
    // 0x80124F2C: nop

L_80124F30:
    // 0x80124F30: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80124F34: beq         $at, $zero, L_80124FE8
    if (ctx->r1 == 0) {
        // 0x80124F38: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80124FE8;
    }
    // 0x80124F38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80124F3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80124F40: addu        $at, $at, $t7
    gpr jr_addend_80124F48 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80124F44: lw          $t7, -0x3774($at)
    ctx->r15 = ADD32(ctx->r1, -0X3774);
    // 0x80124F48: jr          $t7
    // 0x80124F4C: nop

    switch (jr_addend_80124F48 >> 2) {
        case 0: goto L_80124F68; break;
        case 1: goto L_80124F68; break;
        case 2: goto L_80124F68; break;
        case 3: goto L_80124FE8; break;
        case 4: goto L_80124FE8; break;
        case 5: goto L_80124FE8; break;
        case 6: goto L_80124F68; break;
        case 7: goto L_80124F68; break;
        case 8: goto L_80124F50; break;
        case 9: goto L_80124FE8; break;
        case 10: goto L_80124FE8; break;
        case 11: goto L_80124FE8; break;
        case 12: goto L_80124FE8; break;
        case 13: goto L_80124FE8; break;
        case 14: goto L_80124FE8; break;
        case 15: goto L_80124F90; break;
        case 16: goto L_80124FD0; break;
        default: switch_error(__func__, 0x80124F48, 0x8018C88C);
    }
    // 0x80124F4C: nop

L_80124F50:
    // 0x80124F50: jal         0x80125808
    // 0x80124F54: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_0;
    // 0x80124F54: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x80124F58: jal         0x80125808
    // 0x80124F5C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_1;
    // 0x80124F5C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_1:
    // 0x80124F60: b           L_801251B0
    // 0x80124F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80124F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80124F68:
    // 0x80124F68: jal         0x80125808
    // 0x80124F6C: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_2;
    // 0x80124F6C: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    after_2:
    // 0x80124F70: jal         0x80125808
    // 0x80124F74: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_3;
    // 0x80124F74: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_3:
    // 0x80124F78: jal         0x80125808
    // 0x80124F7C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_4;
    // 0x80124F7C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_4:
    // 0x80124F80: jal         0x80125808
    // 0x80124F84: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_5;
    // 0x80124F84: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_5:
    // 0x80124F88: b           L_801251B0
    // 0x80124F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80124F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80124F90:
    // 0x80124F90: jal         0x80125808
    // 0x80124F94: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_6;
    // 0x80124F94: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    after_6:
    // 0x80124F98: jal         0x80125808
    // 0x80124F9C: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_7;
    // 0x80124F9C: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    after_7:
    // 0x80124FA0: jal         0x80125808
    // 0x80124FA4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_8;
    // 0x80124FA4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_8:
    // 0x80124FA8: jal         0x80125808
    // 0x80124FAC: addiu       $a0, $zero, 0xF4
    ctx->r4 = ADD32(0, 0XF4);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_9;
    // 0x80124FAC: addiu       $a0, $zero, 0xF4
    ctx->r4 = ADD32(0, 0XF4);
    after_9:
    // 0x80124FB0: jal         0x80125808
    // 0x80124FB4: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_10;
    // 0x80124FB4: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_10:
    // 0x80124FB8: b           L_801251B0
    // 0x80124FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80124FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80124FC0:
    // 0x80124FC0: jal         0x80125808
    // 0x80124FC4: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_11;
    // 0x80124FC4: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_11:
    // 0x80124FC8: b           L_801251B0
    // 0x80124FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80124FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80124FD0:
    // 0x80124FD0: jal         0x80125808
    // 0x80124FD4: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_12;
    // 0x80124FD4: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    after_12:
    // 0x80124FD8: jal         0x80125808
    // 0x80124FDC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_13;
    // 0x80124FDC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_13:
    // 0x80124FE0: b           L_801251B0
    // 0x80124FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80124FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80124FE8:
    // 0x80124FE8: jal         0x80125808
    // 0x80124FEC: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_14;
    // 0x80124FEC: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_14:
    // 0x80124FF0: jal         0x80125808
    // 0x80124FF4: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_15;
    // 0x80124FF4: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_15:
    // 0x80124FF8: jal         0x80125808
    // 0x80124FFC: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_16;
    // 0x80124FFC: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    after_16:
    // 0x80125000: jal         0x80125808
    // 0x80125004: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_17;
    // 0x80125004: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_17:
    // 0x80125008: jal         0x80125808
    // 0x8012500C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_18;
    // 0x8012500C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    after_18:
    // 0x80125010: jal         0x80125808
    // 0x80125014: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_19;
    // 0x80125014: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    after_19:
    // 0x80125018: jal         0x80125808
    // 0x8012501C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_20;
    // 0x8012501C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_20:
    // 0x80125020: jal         0x80125808
    // 0x80125024: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_21;
    // 0x80125024: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_21:
    // 0x80125028: jal         0x80125808
    // 0x8012502C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_22;
    // 0x8012502C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_22:
    // 0x80125030: jal         0x80125808
    // 0x80125034: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_23;
    // 0x80125034: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    after_23:
    // 0x80125038: jal         0x80125808
    // 0x8012503C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_24;
    // 0x8012503C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_24:
    // 0x80125040: jal         0x80125808
    // 0x80125044: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_25;
    // 0x80125044: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_25:
    // 0x80125048: jal         0x80125808
    // 0x8012504C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_26;
    // 0x8012504C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_26:
    // 0x80125050: jal         0x80125808
    // 0x80125054: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_27;
    // 0x80125054: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_27:
    // 0x80125058: jal         0x80125808
    // 0x8012505C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_28;
    // 0x8012505C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    after_28:
    // 0x80125060: jal         0x80125808
    // 0x80125064: addiu       $a0, $zero, 0x1AE
    ctx->r4 = ADD32(0, 0X1AE);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_29;
    // 0x80125064: addiu       $a0, $zero, 0x1AE
    ctx->r4 = ADD32(0, 0X1AE);
    after_29:
    // 0x80125068: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8012506C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80125070: lhu         $t8, 0x2C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2C);
    // 0x80125074: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80125078: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8012507C: bne         $t8, $at, L_801250D4
    if (ctx->r24 != ctx->r1) {
        // 0x80125080: addiu       $v0, $v0, -0x2284
        ctx->r2 = ADD32(ctx->r2, -0X2284);
            goto L_801250D4;
    }
    // 0x80125080: addiu       $v0, $v0, -0x2284
    ctx->r2 = ADD32(ctx->r2, -0X2284);
    // 0x80125084: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x80125088: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8012508C: bne         $a0, $zero, L_8012509C
    if (ctx->r4 != 0) {
        // 0x80125090: nop
    
            goto L_8012509C;
    }
    // 0x80125090: nop

    // 0x80125094: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x80125098: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
L_8012509C:
    // 0x8012509C: jal         0x801276CC
    // 0x801250A0: nop

    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_30;
    // 0x801250A0: nop

    after_30:
    // 0x801250A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801250A8: addiu       $v0, $v0, -0x2284
    ctx->r2 = ADD32(ctx->r2, -0X2284);
    // 0x801250AC: lhu         $a0, 0x12($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X12);
    // 0x801250B0: addiu       $t0, $zero, 0x11C
    ctx->r8 = ADD32(0, 0X11C);
    // 0x801250B4: bne         $a0, $zero, L_801250C4
    if (ctx->r4 != 0) {
        // 0x801250B8: nop
    
            goto L_801250C4;
    }
    // 0x801250B8: nop

    // 0x801250BC: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x801250C0: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
L_801250C4:
    // 0x801250C4: jal         0x801276CC
    // 0x801250C8: nop

    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_31;
    // 0x801250C8: nop

    after_31:
    // 0x801250CC: b           L_801251B0
    // 0x801250D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x801250D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801250D4:
    // 0x801250D4: lbu         $v0, 0xF7($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF7);
    // 0x801250D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801250DC: beql        $v0, $zero, L_80125108
    if (ctx->r2 == 0) {
        // 0x801250E0: lbu         $t1, 0xF4($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0XF4);
            goto L_80125108;
    }
    goto skip_0;
    // 0x801250E0: lbu         $t1, 0xF4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF4);
    skip_0:
    // 0x801250E4: beq         $v0, $at, L_80125130
    if (ctx->r2 == ctx->r1) {
        // 0x801250E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80125130;
    }
    // 0x801250E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801250EC: beq         $v0, $at, L_8012515C
    if (ctx->r2 == ctx->r1) {
        // 0x801250F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8012515C;
    }
    // 0x801250F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801250F4: beql        $v0, $at, L_8012518C
    if (ctx->r2 == ctx->r1) {
        // 0x801250F8: lbu         $t4, 0xF4($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0XF4);
            goto L_8012518C;
    }
    goto skip_1;
    // 0x801250F8: lbu         $t4, 0xF4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF4);
    skip_1:
    // 0x801250FC: b           L_801251B0
    // 0x80125100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80125100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80125104: lbu         $t1, 0xF4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF4);
L_80125108:
    // 0x80125108: beq         $t1, $zero, L_80125120
    if (ctx->r9 == 0) {
        // 0x8012510C: nop
    
            goto L_80125120;
    }
    // 0x8012510C: nop

    // 0x80125110: jal         0x801276CC
    // 0x80125114: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_32;
    // 0x80125114: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    after_32:
    // 0x80125118: b           L_801251B0
    // 0x8012511C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x8012511C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125120:
    // 0x80125120: jal         0x801276CC
    // 0x80125124: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_33;
    // 0x80125124: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_33:
    // 0x80125128: b           L_801251B0
    // 0x8012512C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x8012512C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125130:
    // 0x80125130: lbu         $t2, 0xF4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF4);
    // 0x80125134: beq         $t2, $zero, L_8012514C
    if (ctx->r10 == 0) {
        // 0x80125138: nop
    
            goto L_8012514C;
    }
    // 0x80125138: nop

    // 0x8012513C: jal         0x801276CC
    // 0x80125140: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_34;
    // 0x80125140: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_34:
    // 0x80125144: b           L_801251B0
    // 0x80125148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80125148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012514C:
    // 0x8012514C: jal         0x801276CC
    // 0x80125150: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_35;
    // 0x80125150: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_35:
    // 0x80125154: b           L_801251B0
    // 0x80125158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80125158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012515C:
    // 0x8012515C: lbu         $t3, 0xF4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF4);
    // 0x80125160: beq         $t3, $zero, L_80125178
    if (ctx->r11 == 0) {
        // 0x80125164: nop
    
            goto L_80125178;
    }
    // 0x80125164: nop

    // 0x80125168: jal         0x801276CC
    // 0x8012516C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_36;
    // 0x8012516C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_36:
    // 0x80125170: b           L_801251B0
    // 0x80125174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80125174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125178:
    // 0x80125178: jal         0x801276CC
    // 0x8012517C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_37;
    // 0x8012517C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_37:
    // 0x80125180: b           L_801251B0
    // 0x80125184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x80125184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80125188: lbu         $t4, 0xF4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF4);
L_8012518C:
    // 0x8012518C: beq         $t4, $zero, L_801251A4
    if (ctx->r12 == 0) {
        // 0x80125190: nop
    
            goto L_801251A4;
    }
    // 0x80125190: nop

    // 0x80125194: jal         0x801276CC
    // 0x80125198: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_38;
    // 0x80125198: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_38:
    // 0x8012519C: b           L_801251B0
    // 0x801251A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801251B0;
    // 0x801251A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801251A4:
    // 0x801251A4: jal         0x801276CC
    // 0x801251A8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x801276CC)(rdram, ctx);
        goto after_39;
    // 0x801251A8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_39:
    // 0x801251AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801251B0:
    // 0x801251B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801251B4: jr          $ra
    // 0x801251B8: nop

    return;
    // 0x801251B8: nop

;}
RECOMP_FUNC void M7_FUN_801251bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801251BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801251C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801251C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801251C8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x801251CC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801251D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801251D4: lhu         $t8, 0x5940($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X5940);
    // 0x801251D8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801251DC: addiu       $t6, $t6, -0xE60
    ctx->r14 = ADD32(ctx->r14, -0XE60);
    // 0x801251E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801251E4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801251E8: sw          $t6, -0x6B90($at)
    MEM_W(-0X6B90, ctx->r1) = ctx->r14;
    // 0x801251EC: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x801251F0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801251F4: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x801251F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801251FC: bne         $at, $zero, L_80125218
    if (ctx->r1 != 0) {
        // 0x80125200: sh          $t8, 0x2C($v1)
        MEM_H(0X2C, ctx->r3) = ctx->r24;
            goto L_80125218;
    }
    // 0x80125200: sh          $t8, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r24;
    // 0x80125204: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80125208: beq         $v0, $at, L_80125590
    if (ctx->r2 == ctx->r1) {
        // 0x8012520C: nop
    
            goto L_80125590;
    }
    // 0x8012520C: nop

    // 0x80125210: b           L_801255B8
    // 0x80125214: nop

        goto L_801255B8;
    // 0x80125214: nop

L_80125218:
    // 0x80125218: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8012521C: bne         $at, $zero, L_80125248
    if (ctx->r1 != 0) {
        // 0x80125220: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80125248;
    }
    // 0x80125220: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80125224: addiu       $t9, $v0, -0x64
    ctx->r25 = ADD32(ctx->r2, -0X64);
    // 0x80125228: sltiu       $at, $t9, 0x1C
    ctx->r1 = ctx->r25 < 0X1C ? 1 : 0;
    // 0x8012522C: beq         $at, $zero, L_801255B8
    if (ctx->r1 == 0) {
        // 0x80125230: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801255B8;
    }
    // 0x80125230: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80125234: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80125238: addu        $at, $at, $t9
    gpr jr_addend_80125240 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8012523C: lw          $t9, -0x3730($at)
    ctx->r25 = ADD32(ctx->r1, -0X3730);
    // 0x80125240: jr          $t9
    // 0x80125244: nop

    switch (jr_addend_80125240 >> 2) {
        case 0: goto L_801252F0; break;
        case 1: goto L_80125308; break;
        case 2: goto L_80125320; break;
        case 3: goto L_80125338; break;
        case 4: goto L_80125350; break;
        case 5: goto L_80125368; break;
        case 6: goto L_80125380; break;
        case 7: goto L_80125398; break;
        case 8: goto L_801253B0; break;
        case 9: goto L_801253C8; break;
        case 10: goto L_801253E0; break;
        case 11: goto L_801253F8; break;
        case 12: goto L_80125410; break;
        case 13: goto L_80125428; break;
        case 14: goto L_80125440; break;
        case 15: goto L_80125458; break;
        case 16: goto L_80125470; break;
        case 17: goto L_80125488; break;
        case 18: goto L_801254A0; break;
        case 19: goto L_801254B8; break;
        case 20: goto L_801254D0; break;
        case 21: goto L_801254E8; break;
        case 22: goto L_80125500; break;
        case 23: goto L_80125518; break;
        case 24: goto L_80125530; break;
        case 25: goto L_80125548; break;
        case 26: goto L_80125560; break;
        case 27: goto L_80125578; break;
        default: switch_error(__func__, 0x80125240, 0x8018C8D0);
    }
    // 0x80125244: nop

L_80125248:
    // 0x80125248: sltiu       $at, $t0, 0x11
    ctx->r1 = ctx->r8 < 0X11 ? 1 : 0;
    // 0x8012524C: beq         $at, $zero, L_801255B8
    if (ctx->r1 == 0) {
        // 0x80125250: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_801255B8;
    }
    // 0x80125250: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80125254: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80125258: addu        $at, $at, $t0
    gpr jr_addend_80125260 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8012525C: lw          $t0, -0x36C0($at)
    ctx->r8 = ADD32(ctx->r1, -0X36C0);
    // 0x80125260: jr          $t0
    // 0x80125264: nop

    switch (jr_addend_80125260 >> 2) {
        case 0: goto L_80125268; break;
        case 1: goto L_80125268; break;
        case 2: goto L_80125268; break;
        case 3: goto L_801255B8; break;
        case 4: goto L_80125290; break;
        case 5: goto L_80125290; break;
        case 6: goto L_80125268; break;
        case 7: goto L_80125268; break;
        case 8: goto L_80125280; break;
        case 9: goto L_80125290; break;
        case 10: goto L_80125290; break;
        case 11: goto L_801255B8; break;
        case 12: goto L_801255B8; break;
        case 13: goto L_801255B8; break;
        case 14: goto L_80125290; break;
        case 15: goto L_80125280; break;
        case 16: goto L_80125280; break;
        default: switch_error(__func__, 0x80125260, 0x8018C940);
    }
    // 0x80125264: nop

L_80125268:
    // 0x80125268: jal         0x800044BC
    // 0x8012526C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_0;
    // 0x8012526C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x80125270: jal         0x800044BC
    // 0x80125274: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_1;
    // 0x80125274: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80125278: b           L_801256B8
    // 0x8012527C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012527C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125280:
    // 0x80125280: jal         0x800044BC
    // 0x80125284: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_2;
    // 0x80125284: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x80125288: b           L_801256B8
    // 0x8012528C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012528C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125290:
    // 0x80125290: jal         0x800044BC
    // 0x80125294: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_3;
    // 0x80125294: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x80125298: jal         0x800044BC
    // 0x8012529C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_4;
    // 0x8012529C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x801252A0: jal         0x800044BC
    // 0x801252A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_5;
    // 0x801252A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_5:
    // 0x801252A8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801252AC: lhu         $t1, -0x440C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X440C);
    // 0x801252B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801252B4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x801252B8: mflo        $t2
    ctx->r10 = lo;
    // 0x801252BC: addiu       $t3, $t2, -0xE
    ctx->r11 = ADD32(ctx->r10, -0XE);
    // 0x801252C0: sltiu       $at, $t3, 0x8
    ctx->r1 = ctx->r11 < 0X8 ? 1 : 0;
    // 0x801252C4: beq         $at, $zero, L_801256B4
    if (ctx->r1 == 0) {
        // 0x801252C8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801256B4;
    }
    // 0x801252C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801252CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801252D0: addu        $at, $at, $t3
    gpr jr_addend_801252D8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801252D4: lw          $t3, -0x367C($at)
    ctx->r11 = ADD32(ctx->r1, -0X367C);
    // 0x801252D8: jr          $t3
    // 0x801252DC: nop

    switch (jr_addend_801252D8 >> 2) {
        case 0: goto L_801252E0; break;
        case 1: goto L_801252E0; break;
        case 2: goto L_801252E0; break;
        case 3: goto L_801252E0; break;
        case 4: goto L_801252E0; break;
        case 5: goto L_801256B4; break;
        case 6: goto L_801256B4; break;
        case 7: goto L_801252E0; break;
        default: switch_error(__func__, 0x801252D8, 0x8018C984);
    }
    // 0x801252DC: nop

L_801252E0:
    // 0x801252E0: jal         0x800044BC
    // 0x801252E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_6;
    // 0x801252E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_6:
    // 0x801252E8: b           L_801256B8
    // 0x801252EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801252EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801252F0:
    // 0x801252F0: jal         0x800044BC
    // 0x801252F4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_7;
    // 0x801252F4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_7:
    // 0x801252F8: jal         0x800044BC
    // 0x801252FC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_8;
    // 0x801252FC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_8:
    // 0x80125300: b           L_801256B8
    // 0x80125304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125308:
    // 0x80125308: jal         0x800044BC
    // 0x8012530C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_9;
    // 0x8012530C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_9:
    // 0x80125310: jal         0x800044BC
    // 0x80125314: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_10;
    // 0x80125314: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_10:
    // 0x80125318: b           L_801256B8
    // 0x8012531C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012531C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125320:
    // 0x80125320: jal         0x800044BC
    // 0x80125324: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_11;
    // 0x80125324: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_11:
    // 0x80125328: jal         0x800044BC
    // 0x8012532C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_12;
    // 0x8012532C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_12:
    // 0x80125330: b           L_801256B8
    // 0x80125334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125338:
    // 0x80125338: jal         0x800044BC
    // 0x8012533C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_13;
    // 0x8012533C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_13:
    // 0x80125340: jal         0x800044BC
    // 0x80125344: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_14;
    // 0x80125344: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_14:
    // 0x80125348: b           L_801256B8
    // 0x8012534C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012534C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125350:
    // 0x80125350: jal         0x800044BC
    // 0x80125354: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_15;
    // 0x80125354: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_15:
    // 0x80125358: jal         0x800044BC
    // 0x8012535C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_16;
    // 0x8012535C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_16:
    // 0x80125360: b           L_801256B8
    // 0x80125364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125368:
    // 0x80125368: jal         0x800044BC
    // 0x8012536C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_17;
    // 0x8012536C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_17:
    // 0x80125370: jal         0x800044BC
    // 0x80125374: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_18;
    // 0x80125374: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_18:
    // 0x80125378: b           L_801256B8
    // 0x8012537C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012537C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125380:
    // 0x80125380: jal         0x800044BC
    // 0x80125384: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_19;
    // 0x80125384: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_19:
    // 0x80125388: jal         0x800044BC
    // 0x8012538C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_20;
    // 0x8012538C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_20:
    // 0x80125390: b           L_801256B8
    // 0x80125394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125398:
    // 0x80125398: jal         0x800044BC
    // 0x8012539C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_21;
    // 0x8012539C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_21:
    // 0x801253A0: jal         0x800044BC
    // 0x801253A4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_22;
    // 0x801253A4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_22:
    // 0x801253A8: b           L_801256B8
    // 0x801253AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801253AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801253B0:
    // 0x801253B0: jal         0x800044BC
    // 0x801253B4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_23;
    // 0x801253B4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_23:
    // 0x801253B8: jal         0x800044BC
    // 0x801253BC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_24;
    // 0x801253BC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_24:
    // 0x801253C0: b           L_801256B8
    // 0x801253C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801253C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801253C8:
    // 0x801253C8: jal         0x800044BC
    // 0x801253CC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_25;
    // 0x801253CC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_25:
    // 0x801253D0: jal         0x800044BC
    // 0x801253D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_26;
    // 0x801253D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_26:
    // 0x801253D8: b           L_801256B8
    // 0x801253DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801253DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801253E0:
    // 0x801253E0: jal         0x800044BC
    // 0x801253E4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_27;
    // 0x801253E4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_27:
    // 0x801253E8: jal         0x800044BC
    // 0x801253EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_28;
    // 0x801253EC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_28:
    // 0x801253F0: b           L_801256B8
    // 0x801253F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801253F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801253F8:
    // 0x801253F8: jal         0x800044BC
    // 0x801253FC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_29;
    // 0x801253FC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_29:
    // 0x80125400: jal         0x800044BC
    // 0x80125404: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_30;
    // 0x80125404: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_30:
    // 0x80125408: b           L_801256B8
    // 0x8012540C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012540C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125410:
    // 0x80125410: jal         0x800044BC
    // 0x80125414: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_31;
    // 0x80125414: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_31:
    // 0x80125418: jal         0x800044BC
    // 0x8012541C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_32;
    // 0x8012541C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_32:
    // 0x80125420: b           L_801256B8
    // 0x80125424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125428:
    // 0x80125428: jal         0x800044BC
    // 0x8012542C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_33;
    // 0x8012542C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_33:
    // 0x80125430: jal         0x800044BC
    // 0x80125434: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_34;
    // 0x80125434: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_34:
    // 0x80125438: b           L_801256B8
    // 0x8012543C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012543C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125440:
    // 0x80125440: jal         0x800044BC
    // 0x80125444: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_35;
    // 0x80125444: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_35:
    // 0x80125448: jal         0x800044BC
    // 0x8012544C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_36;
    // 0x8012544C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_36:
    // 0x80125450: b           L_801256B8
    // 0x80125454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125458:
    // 0x80125458: jal         0x800044BC
    // 0x8012545C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_37;
    // 0x8012545C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_37:
    // 0x80125460: jal         0x800044BC
    // 0x80125464: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_38;
    // 0x80125464: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_38:
    // 0x80125468: b           L_801256B8
    // 0x8012546C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012546C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125470:
    // 0x80125470: jal         0x800044BC
    // 0x80125474: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_39;
    // 0x80125474: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_39:
    // 0x80125478: jal         0x800044BC
    // 0x8012547C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_40;
    // 0x8012547C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_40:
    // 0x80125480: b           L_801256B8
    // 0x80125484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125488:
    // 0x80125488: jal         0x800044BC
    // 0x8012548C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_41;
    // 0x8012548C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_41:
    // 0x80125490: jal         0x800044BC
    // 0x80125494: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_42;
    // 0x80125494: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_42:
    // 0x80125498: b           L_801256B8
    // 0x8012549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801254A0:
    // 0x801254A0: jal         0x800044BC
    // 0x801254A4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_43;
    // 0x801254A4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_43:
    // 0x801254A8: jal         0x800044BC
    // 0x801254AC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_44;
    // 0x801254AC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_44:
    // 0x801254B0: b           L_801256B8
    // 0x801254B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801254B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801254B8:
    // 0x801254B8: jal         0x800044BC
    // 0x801254BC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_45;
    // 0x801254BC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_45:
    // 0x801254C0: jal         0x800044BC
    // 0x801254C4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_46;
    // 0x801254C4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_46:
    // 0x801254C8: b           L_801256B8
    // 0x801254CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801254CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801254D0:
    // 0x801254D0: jal         0x800044BC
    // 0x801254D4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_47;
    // 0x801254D4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_47:
    // 0x801254D8: jal         0x800044BC
    // 0x801254DC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_48;
    // 0x801254DC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_48:
    // 0x801254E0: b           L_801256B8
    // 0x801254E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801254E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801254E8:
    // 0x801254E8: jal         0x800044BC
    // 0x801254EC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_49;
    // 0x801254EC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_49:
    // 0x801254F0: jal         0x800044BC
    // 0x801254F4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_50;
    // 0x801254F4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_50:
    // 0x801254F8: b           L_801256B8
    // 0x801254FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801254FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125500:
    // 0x80125500: jal         0x800044BC
    // 0x80125504: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_51;
    // 0x80125504: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_51:
    // 0x80125508: jal         0x800044BC
    // 0x8012550C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_52;
    // 0x8012550C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_52:
    // 0x80125510: b           L_801256B8
    // 0x80125514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125518:
    // 0x80125518: jal         0x800044BC
    // 0x8012551C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_53;
    // 0x8012551C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_53:
    // 0x80125520: jal         0x800044BC
    // 0x80125524: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_54;
    // 0x80125524: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_54:
    // 0x80125528: b           L_801256B8
    // 0x8012552C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012552C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125530:
    // 0x80125530: jal         0x800044BC
    // 0x80125534: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_55;
    // 0x80125534: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_55:
    // 0x80125538: jal         0x800044BC
    // 0x8012553C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_56;
    // 0x8012553C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_56:
    // 0x80125540: b           L_801256B8
    // 0x80125544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125548:
    // 0x80125548: jal         0x800044BC
    // 0x8012554C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_57;
    // 0x8012554C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_57:
    // 0x80125550: jal         0x800044BC
    // 0x80125554: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_58;
    // 0x80125554: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_58:
    // 0x80125558: b           L_801256B8
    // 0x8012555C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012555C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125560:
    // 0x80125560: jal         0x800044BC
    // 0x80125564: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_59;
    // 0x80125564: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_59:
    // 0x80125568: jal         0x800044BC
    // 0x8012556C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_60;
    // 0x8012556C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_60:
    // 0x80125570: b           L_801256B8
    // 0x80125574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125578:
    // 0x80125578: jal         0x800044BC
    // 0x8012557C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_61;
    // 0x8012557C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_61:
    // 0x80125580: jal         0x800044BC
    // 0x80125584: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_62;
    // 0x80125584: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_62:
    // 0x80125588: b           L_801256B8
    // 0x8012558C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x8012558C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80125590:
    // 0x80125590: jal         0x800044BC
    // 0x80125594: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_63;
    // 0x80125594: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_63:
    // 0x80125598: jal         0x800044BC
    // 0x8012559C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_64;
    // 0x8012559C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_64:
    // 0x801255A0: jal         0x800044BC
    // 0x801255A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_65;
    // 0x801255A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_65:
    // 0x801255A8: jal         0x800044BC
    // 0x801255AC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_66;
    // 0x801255AC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_66:
    // 0x801255B0: b           L_801256B8
    // 0x801255B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801255B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801255B8:
    // 0x801255B8: jal         0x80126930
    // 0x801255BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_67;
    // 0x801255BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_67:
    // 0x801255C0: jal         0x800044BC
    // 0x801255C4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_68;
    // 0x801255C4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_68:
    // 0x801255C8: jal         0x800044BC
    // 0x801255CC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_69;
    // 0x801255CC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_69:
    // 0x801255D0: jal         0x800044BC
    // 0x801255D4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_70;
    // 0x801255D4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_70:
    // 0x801255D8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801255DC: lhu         $t4, -0x440C($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X440C);
    // 0x801255E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801255E4: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x801255E8: mflo        $t5
    ctx->r13 = lo;
    // 0x801255EC: sltiu       $at, $t5, 0xB
    ctx->r1 = ctx->r13 < 0XB ? 1 : 0;
    // 0x801255F0: beq         $at, $zero, L_801256B4
    if (ctx->r1 == 0) {
        // 0x801255F4: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_801256B4;
    }
    // 0x801255F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801255F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801255FC: addu        $at, $at, $t5
    gpr jr_addend_80125604 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80125600: lw          $t5, -0x365C($at)
    ctx->r13 = ADD32(ctx->r1, -0X365C);
    // 0x80125604: jr          $t5
    // 0x80125608: nop

    switch (jr_addend_80125604 >> 2) {
        case 0: goto L_8012560C; break;
        case 1: goto L_8012561C; break;
        case 2: goto L_8012562C; break;
        case 3: goto L_8012563C; break;
        case 4: goto L_8012564C; break;
        case 5: goto L_8012565C; break;
        case 6: goto L_8012566C; break;
        case 7: goto L_8012567C; break;
        case 8: goto L_8012568C; break;
        case 9: goto L_8012569C; break;
        case 10: goto L_801256AC; break;
        default: switch_error(__func__, 0x80125604, 0x8018C9A4);
    }
    // 0x80125608: nop

L_8012560C:
    // 0x8012560C: jal         0x800044BC
    // 0x80125610: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_71;
    // 0x80125610: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_71:
    // 0x80125614: b           L_801256B8
    // 0x80125618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012561C:
    // 0x8012561C: jal         0x800044BC
    // 0x80125620: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_72;
    // 0x80125620: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_72:
    // 0x80125624: b           L_801256B8
    // 0x80125628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012562C:
    // 0x8012562C: jal         0x800044BC
    // 0x80125630: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_73;
    // 0x80125630: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_73:
    // 0x80125634: b           L_801256B8
    // 0x80125638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012563C:
    // 0x8012563C: jal         0x800044BC
    // 0x80125640: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_74;
    // 0x80125640: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_74:
    // 0x80125644: b           L_801256B8
    // 0x80125648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012564C:
    // 0x8012564C: jal         0x800044BC
    // 0x80125650: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_75;
    // 0x80125650: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_75:
    // 0x80125654: b           L_801256B8
    // 0x80125658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012565C:
    // 0x8012565C: jal         0x800044BC
    // 0x80125660: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_76;
    // 0x80125660: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_76:
    // 0x80125664: b           L_801256B8
    // 0x80125668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012566C:
    // 0x8012566C: jal         0x800044BC
    // 0x80125670: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_77;
    // 0x80125670: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_77:
    // 0x80125674: b           L_801256B8
    // 0x80125678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012567C:
    // 0x8012567C: jal         0x800044BC
    // 0x80125680: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_78;
    // 0x80125680: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_78:
    // 0x80125684: b           L_801256B8
    // 0x80125688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012568C:
    // 0x8012568C: jal         0x800044BC
    // 0x80125690: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_79;
    // 0x80125690: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_79:
    // 0x80125694: b           L_801256B8
    // 0x80125698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x80125698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012569C:
    // 0x8012569C: jal         0x800044BC
    // 0x801256A0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_80;
    // 0x801256A0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_80:
    // 0x801256A4: b           L_801256B8
    // 0x801256A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801256B8;
    // 0x801256A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801256AC:
    // 0x801256AC: jal         0x800044BC
    // 0x801256B0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    LOOKUP_FUNC(0x800044BC)(rdram, ctx);
        goto after_81;
    // 0x801256B0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_81:
L_801256B4:
    // 0x801256B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801256B8:
    // 0x801256B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801256BC: jr          $ra
    // 0x801256C0: nop

    return;
    // 0x801256C0: nop

;}
RECOMP_FUNC void M7_FUN_801256c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801256C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801256C8: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801256cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801256cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801256CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801256D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801256D4: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x801256D8: bne         $at, $zero, L_80125704
    if (ctx->r1 != 0) {
        // 0x801256DC: addiu       $t7, $v0, -0x4
        ctx->r15 = ADD32(ctx->r2, -0X4);
            goto L_80125704;
    }
    // 0x801256DC: addiu       $t7, $v0, -0x4
    ctx->r15 = ADD32(ctx->r2, -0X4);
    // 0x801256E0: addiu       $t6, $v0, -0x64
    ctx->r14 = ADD32(ctx->r2, -0X64);
    // 0x801256E4: sltiu       $at, $t6, 0x1C
    ctx->r1 = ctx->r14 < 0X1C ? 1 : 0;
    // 0x801256E8: beq         $at, $zero, L_80125758
    if (ctx->r1 == 0) {
        // 0x801256EC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80125758;
    }
    // 0x801256EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801256F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801256F4: addu        $at, $at, $t6
    gpr jr_addend_801256FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801256F8: lw          $t6, -0x3630($at)
    ctx->r14 = ADD32(ctx->r1, -0X3630);
    // 0x801256FC: jr          $t6
    // 0x80125700: nop

    switch (jr_addend_801256FC >> 2) {
        case 0: goto L_80125724; break;
        case 1: goto L_80125724; break;
        case 2: goto L_80125724; break;
        case 3: goto L_80125724; break;
        case 4: goto L_80125724; break;
        case 5: goto L_80125724; break;
        case 6: goto L_80125724; break;
        case 7: goto L_80125724; break;
        case 8: goto L_80125724; break;
        case 9: goto L_80125724; break;
        case 10: goto L_80125724; break;
        case 11: goto L_80125724; break;
        case 12: goto L_80125724; break;
        case 13: goto L_80125724; break;
        case 14: goto L_80125724; break;
        case 15: goto L_80125724; break;
        case 16: goto L_80125724; break;
        case 17: goto L_80125724; break;
        case 18: goto L_80125724; break;
        case 19: goto L_80125724; break;
        case 20: goto L_80125724; break;
        case 21: goto L_80125724; break;
        case 22: goto L_80125724; break;
        case 23: goto L_80125724; break;
        case 24: goto L_80125724; break;
        case 25: goto L_80125724; break;
        case 26: goto L_80125724; break;
        case 27: goto L_80125724; break;
        default: switch_error(__func__, 0x801256FC, 0x8018C9D0);
    }
    // 0x80125700: nop

L_80125704:
    // 0x80125704: sltiu       $at, $t7, 0xE
    ctx->r1 = ctx->r15 < 0XE ? 1 : 0;
    // 0x80125708: beq         $at, $zero, L_80125758
    if (ctx->r1 == 0) {
        // 0x8012570C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80125758;
    }
    // 0x8012570C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80125710: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80125714: addu        $at, $at, $t7
    gpr jr_addend_8012571C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80125718: lw          $t7, -0x35C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X35C0);
    // 0x8012571C: jr          $t7
    // 0x80125720: nop

    switch (jr_addend_8012571C >> 2) {
        case 0: goto L_8012573C; break;
        case 1: goto L_8012573C; break;
        case 2: goto L_80125758; break;
        case 3: goto L_80125758; break;
        case 4: goto L_80125758; break;
        case 5: goto L_80125758; break;
        case 6: goto L_8012573C; break;
        case 7: goto L_8012573C; break;
        case 8: goto L_80125758; break;
        case 9: goto L_80125758; break;
        case 10: goto L_80125758; break;
        case 11: goto L_8012573C; break;
        case 12: goto L_80125758; break;
        case 13: goto L_8012573C; break;
        default: switch_error(__func__, 0x8012571C, 0x8018CA40);
    }
    // 0x80125720: nop

L_80125724:
    // 0x80125724: jal         0x80016E40
    // 0x80125728: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    LOOKUP_FUNC(0x80016E40)(rdram, ctx);
        goto after_0;
    // 0x80125728: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_0:
    // 0x8012572C: jal         0x80004484
    // 0x80125730: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x80004484)(rdram, ctx);
        goto after_1;
    // 0x80125730: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x80125734: b           L_80125764
    // 0x80125738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80125764;
    // 0x80125738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012573C:
    // 0x8012573C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80125740: jal         0x80016E40
    // 0x80125744: ori         $a0, $a0, 0xA000
    ctx->r4 = ctx->r4 | 0XA000;
    LOOKUP_FUNC(0x80016E40)(rdram, ctx);
        goto after_2;
    // 0x80125744: ori         $a0, $a0, 0xA000
    ctx->r4 = ctx->r4 | 0XA000;
    after_2:
    // 0x80125748: jal         0x80004484
    // 0x8012574C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x80004484)(rdram, ctx);
        goto after_3;
    // 0x8012574C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_3:
    // 0x80125750: b           L_80125764
    // 0x80125754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80125764;
    // 0x80125754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80125758:
    // 0x80125758: b           L_80125764
    // 0x8012575C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80125764;
    // 0x8012575C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80125764:
    // 0x80125764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80125768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012576C: jr          $ra
    // 0x80125770: nop

    return;
    // 0x80125770: nop

;}
RECOMP_FUNC void M7_FUN_80125774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80125774: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80125778: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8012577C: lbu         $t6, 0x42A0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X42A0);
    // 0x80125780: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80125784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80125788: beql        $t6, $zero, L_8012579C
    if (ctx->r14 == 0) {
        // 0x8012578C: sb          $t7, 0x42A0($v1)
        MEM_B(0X42A0, ctx->r3) = ctx->r15;
            goto L_8012579C;
    }
    goto skip_0;
    // 0x8012578C: sb          $t7, 0x42A0($v1)
    MEM_B(0X42A0, ctx->r3) = ctx->r15;
    skip_0:
    // 0x80125790: jr          $ra
    // 0x80125794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80125794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125798: sb          $t7, 0x42A0($v1)
    MEM_B(0X42A0, ctx->r3) = ctx->r15;
L_8012579C:
    // 0x8012579C: sw          $zero, 0x42A4($v1)
    MEM_W(0X42A4, ctx->r3) = 0;
    // 0x801257A0: sw          $zero, 0x42A8($v1)
    MEM_W(0X42A8, ctx->r3) = 0;
    // 0x801257A4: sb          $zero, 0x42AD($v1)
    MEM_B(0X42AD, ctx->r3) = 0;
    // 0x801257A8: sw          $zero, 0x42B0($v1)
    MEM_W(0X42B0, ctx->r3) = 0;
    // 0x801257AC: sw          $zero, 0x42B4($v1)
    MEM_W(0X42B4, ctx->r3) = 0;
    // 0x801257B0: sw          $zero, 0x42B8($v1)
    MEM_W(0X42B8, ctx->r3) = 0;
    // 0x801257B4: sw          $zero, 0x42BC($v1)
    MEM_W(0X42BC, ctx->r3) = 0;
    // 0x801257B8: sw          $zero, 0x42C4($v1)
    MEM_W(0X42C4, ctx->r3) = 0;
    // 0x801257BC: sw          $a0, 0x42CC($v1)
    MEM_W(0X42CC, ctx->r3) = ctx->r4;
    // 0x801257C0: sb          $zero, 0x42AC($v1)
    MEM_B(0X42AC, ctx->r3) = 0;
    // 0x801257C4: sb          $zero, 0x42EC($v1)
    MEM_B(0X42EC, ctx->r3) = 0;
    // 0x801257C8: sb          $zero, 0x42C1($v1)
    MEM_B(0X42C1, ctx->r3) = 0;
    // 0x801257CC: sb          $zero, 0x42C0($v1)
    MEM_B(0X42C0, ctx->r3) = 0;
    // 0x801257D0: sb          $zero, 0x42C8($v1)
    MEM_B(0X42C8, ctx->r3) = 0;
    // 0x801257D4: jr          $ra
    // 0x801257D8: nop

    return;
    // 0x801257D8: nop

;}
RECOMP_FUNC void M7_FUN_801257dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801257DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801257E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801257E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801257E8: sb          $zero, -0x2AB0($at)
    MEM_B(-0X2AB0, ctx->r1) = 0;
    // 0x801257EC: jal         0x80125774
    // 0x801257F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80125774)(rdram, ctx);
        goto after_0;
    // 0x801257F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801257F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801257F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801257FC: sb          $zero, -0x2AB0($at)
    MEM_B(-0X2AB0, ctx->r1) = 0;
    // 0x80125800: jr          $ra
    // 0x80125804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80125804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80125808(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80125808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80125808: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8012580C: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80125810: lbu         $t6, 0x42A0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X42A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80125814(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80125814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80125814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80125818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012581C: beq         $t6, $zero, L_80125910
    if (ctx->r14 == 0) {
        // 0x80125820: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80125910;
    }
    // 0x80125820: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80125824: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x80125828: bne         $v0, $zero, L_80125838
    if (ctx->r2 != 0) {
        // 0x8012582C: slti        $at, $v0, 0x271
        ctx->r1 = SIGNED(ctx->r2) < 0X271 ? 1 : 0;
            goto L_80125838;
    }
    // 0x8012582C: slti        $at, $v0, 0x271
    ctx->r1 = SIGNED(ctx->r2) < 0X271 ? 1 : 0;
    // 0x80125830: b           L_80125958
    // 0x80125834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80125958;
    // 0x80125834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80125838:
    // 0x80125838: bnel        $at, $zero, L_8012584C
    if (ctx->r1 != 0) {
        // 0x8012583C: lbu         $v0, 0x42C0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X42C0);
            goto L_8012584C;
    }
    goto skip_0;
    // 0x8012583C: lbu         $v0, 0x42C0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X42C0);
    skip_0:
    // 0x80125840: b           L_80125958
    // 0x80125844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80125958;
    // 0x80125844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125848: lbu         $v0, 0x42C0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X42C0);
L_8012584C:
    // 0x8012584C: bnel        $v0, $zero, L_80125888
    if (ctx->r2 != 0) {
        // 0x80125850: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80125888;
    }
    goto skip_1;
    // 0x80125850: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x80125854: jal         0x80017064
    // 0x80125858: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x80125858: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x8012585C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80125860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80125864: beq         $v0, $at, L_80125874
    if (ctx->r2 == ctx->r1) {
        // 0x80125868: addiu       $v1, $v1, -0x6D50
        ctx->r3 = ADD32(ctx->r3, -0X6D50);
            goto L_80125874;
    }
    // 0x80125868: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8012586C: b           L_80125958
    // 0x80125870: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80125958;
    // 0x80125870: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80125874:
    // 0x80125874: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80125878: sw          $zero, 0x42A8($v1)
    MEM_W(0X42A8, ctx->r3) = 0;
    // 0x8012587C: sb          $t7, 0x42C0($v1)
    MEM_B(0X42C0, ctx->r3) = ctx->r15;
    // 0x80125880: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x80125884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80125888:
    // 0x80125888: bnel        $v0, $at, L_801258E8
    if (ctx->r2 != ctx->r1) {
        // 0x8012588C: lhu         $a0, 0x1A($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X1A);
            goto L_801258E8;
    }
    goto skip_2;
    // 0x8012588C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    skip_2:
    // 0x80125890: lbu         $t8, 0x42FF($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X42FF);
    // 0x80125894: beq         $t8, $zero, L_801258B4
    if (ctx->r24 == 0) {
        // 0x80125898: nop
    
            goto L_801258B4;
    }
    // 0x80125898: nop

    // 0x8012589C: jal         0x800044FC
    // 0x801258A0: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x800044FC)(rdram, ctx);
        goto after_1;
    // 0x801258A0: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x801258A4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801258A8: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x801258AC: b           L_801258C8
    // 0x801258B0: sw          $v0, 0x42C4($v1)
    MEM_W(0X42C4, ctx->r3) = ctx->r2;
        goto L_801258C8;
    // 0x801258B0: sw          $v0, 0x42C4($v1)
    MEM_W(0X42C4, ctx->r3) = ctx->r2;
L_801258B4:
    // 0x801258B4: jal         0x80004560
    // 0x801258B8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80004560)(rdram, ctx);
        goto after_2;
    // 0x801258B8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_2:
    // 0x801258BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801258C0: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x801258C4: sw          $v0, 0x42C4($v1)
    MEM_W(0X42C4, ctx->r3) = ctx->r2;
L_801258C8:
    // 0x801258C8: lw          $t9, 0x42C4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X42C4);
    // 0x801258CC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801258D0: bnel        $t9, $zero, L_801258E4
    if (ctx->r25 != 0) {
        // 0x801258D4: sb          $t0, 0x42C0($v1)
        MEM_B(0X42C0, ctx->r3) = ctx->r8;
            goto L_801258E4;
    }
    goto skip_3;
    // 0x801258D4: sb          $t0, 0x42C0($v1)
    MEM_B(0X42C0, ctx->r3) = ctx->r8;
    skip_3:
    // 0x801258D8: b           L_80125958
    // 0x801258DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80125958;
    // 0x801258DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801258E0: sb          $t0, 0x42C0($v1)
    MEM_B(0X42C0, ctx->r3) = ctx->r8;
L_801258E4:
    // 0x801258E4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
L_801258E8:
    // 0x801258E8: jal         0x80004BB0
    // 0x801258EC: lw          $a1, 0x42C4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X42C4);
    LOOKUP_FUNC(0x80004BB0)(rdram, ctx);
        goto after_3;
    // 0x801258EC: lw          $a1, 0x42C4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X42C4);
    after_3:
    // 0x801258F0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801258F4: beq         $v0, $zero, L_80125908
    if (ctx->r2 == 0) {
        // 0x801258F8: addiu       $v1, $v1, -0x6D50
        ctx->r3 = ADD32(ctx->r3, -0X6D50);
            goto L_80125908;
    }
    // 0x801258F8: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x801258FC: sb          $zero, 0x42C0($v1)
    MEM_B(0X42C0, ctx->r3) = 0;
    // 0x80125900: b           L_80125958
    // 0x80125904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80125958;
    // 0x80125904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80125908:
    // 0x80125908: b           L_80125958
    // 0x8012590C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80125958;
    // 0x8012590C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80125910:
    // 0x80125910: jal         0x80017064
    // 0x80125914: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_4;
    // 0x80125914: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_4:
    // 0x80125918: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8012591C: nop

    // 0x80125920: lhu         $t1, 0x1A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X1A);
    // 0x80125924: beql        $t1, $zero, L_80125958
    if (ctx->r9 == 0) {
        // 0x80125928: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80125958;
    }
    goto skip_4;
    // 0x80125928: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_4:
    // 0x8012592C: jal         0x800045E8
    // 0x80125930: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x800045E8)(rdram, ctx);
        goto after_5;
    // 0x80125930: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_5:
    // 0x80125934: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80125938: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8012593C: sw          $v0, 0x42C4($v1)
    MEM_W(0X42C4, ctx->r3) = ctx->r2;
    // 0x80125940: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80125944: jal         0x80004ADC
    // 0x80125948: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80004ADC)(rdram, ctx);
        goto after_6;
    // 0x80125948: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8012594C: b           L_80125958
    // 0x80125950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80125958;
    // 0x80125950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80125954: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80125958:
    // 0x80125958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012595C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80125960: jr          $ra
    // 0x80125964: nop

    return;
    // 0x80125964: nop

;}
RECOMP_FUNC void M7_FUN_80125968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80125968: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8012596C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80125970: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80125974: lbu         $t7, -0x2A8F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2A8F);
    // 0x80125978: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8012597C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80125980: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80125984: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80125988: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8012598C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80125990: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80125994: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80125998: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8012599C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801259A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801259A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801259A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801259AC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801259B0: bne         $t7, $zero, L_801259E4
    if (ctx->r15 != 0) {
        // 0x801259B4: lw          $v0, 0x5490($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X5490);
            goto L_801259E4;
    }
    // 0x801259B4: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
    // 0x801259B8: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x801259BC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801259C0: sw          $zero, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = 0;
    // 0x801259C4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801259C8: lbu         $t8, -0x2AB0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2AB0);
    // 0x801259CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801259D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801259D4: beql        $t8, $zero, L_801259F0
    if (ctx->r24 == 0) {
        // 0x801259D8: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_801259F0;
    }
    goto skip_0;
    // 0x801259D8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x801259DC: b           L_801259EC
    // 0x801259E0: sb          $t9, -0x2A8F($at)
    MEM_B(-0X2A8F, ctx->r1) = ctx->r25;
        goto L_801259EC;
    // 0x801259E0: sb          $t9, -0x2A8F($at)
    MEM_B(-0X2A8F, ctx->r1) = ctx->r25;
L_801259E4:
    // 0x801259E4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x801259E8: lw          $s0, -0x2AAC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2AAC);
L_801259EC:
    // 0x801259EC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_801259F0:
    // 0x801259F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801259F4: lui         $s7, 0x8003
    ctx->r23 = S32(0X8003 << 16);
    // 0x801259F8: beq         $v1, $at, L_80126160
    if (ctx->r3 == ctx->r1) {
        // 0x801259FC: addiu       $s7, $s7, 0x7744
        ctx->r23 = ADD32(ctx->r23, 0X7744);
            goto L_80126160;
    }
    // 0x801259FC: addiu       $s7, $s7, 0x7744
    ctx->r23 = ADD32(ctx->r23, 0X7744);
    // 0x80125A00: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80125A04: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80125A08: addiu       $s6, $zero, 0x1D
    ctx->r22 = ADD32(0, 0X1D);
    // 0x80125A0C: addiu       $s5, $zero, 0x1F
    ctx->r21 = ADD32(0, 0X1F);
    // 0x80125A10: addiu       $s4, $zero, 0x1E
    ctx->r20 = ADD32(0, 0X1E);
    // 0x80125A14: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
    // 0x80125A18: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x80125A1C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
L_80125A20:
    // 0x80125A20: sltiu       $at, $t0, 0x15
    ctx->r1 = ctx->r8 < 0X15 ? 1 : 0;
    // 0x80125A24: beq         $at, $zero, L_80126148
    if (ctx->r1 == 0) {
        // 0x80125A28: sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
            goto L_80126148;
    }
    // 0x80125A28: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80125A2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80125A30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80125A34: addu        $at, $at, $t0
    gpr jr_addend_80125A3C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80125A38: lw          $t0, -0x3588($at)
    ctx->r8 = ADD32(ctx->r1, -0X3588);
    // 0x80125A3C: jr          $t0
    // 0x80125A40: nop

    switch (jr_addend_80125A3C >> 2) {
        case 0: goto L_80125AA0; break;
        case 1: goto L_80126148; break;
        case 2: goto L_80125BEC; break;
        case 3: goto L_80125D2C; break;
        case 4: goto L_80125D58; break;
        case 5: goto L_80125D84; break;
        case 6: goto L_80125DBC; break;
        case 7: goto L_80125DE8; break;
        case 8: goto L_80125E20; break;
        case 9: goto L_80125A80; break;
        case 10: goto L_80125FF0; break;
        case 11: goto L_80126090; break;
        case 12: goto L_80125EB4; break;
        case 13: goto L_80125E58; break;
        case 14: goto L_80125A44; break;
        case 15: goto L_801260EC; break;
        case 16: goto L_80125B7C; break;
        case 17: goto L_801260B0; break;
        case 18: goto L_80125F34; break;
        case 19: goto L_80125CC8; break;
        case 20: goto L_80125C4C; break;
        default: switch_error(__func__, 0x80125A3C, 0x8018CA78);
    }
    // 0x80125A40: nop

L_80125A44:
    // 0x80125A44: jal         0x80016F90
    // 0x80125A48: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x80125A48: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x80125A4C: jal         0x80017014
    // 0x80125A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80125A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80125A54: bnel        $v0, $zero, L_80126150
    if (ctx->r2 != 0) {
        // 0x80125A58: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_1;
    // 0x80125A58: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x80125A5C: jal         0x80125808
    // 0x80125A60: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_2;
    // 0x80125A60: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_2:
    // 0x80125A64: bnel        $v0, $zero, L_80126150
    if (ctx->r2 != 0) {
        // 0x80125A68: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_2;
    // 0x80125A68: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x80125A6C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80125A70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80125A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125A78: b           L_8012616C
    // 0x80125A7C: sw          $t1, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r9;
        goto L_8012616C;
    // 0x80125A7C: sw          $t1, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r9;
L_80125A80:
    // 0x80125A80: lhu         $t2, 0x4E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X4E);
    // 0x80125A84: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x80125A88: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80125A8C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80125A90: bne         $t4, $zero, L_80125AA0
    if (ctx->r12 != 0) {
        // 0x80125A94: nop
    
            goto L_80125AA0;
    }
    // 0x80125A94: nop

    // 0x80125A98: b           L_8012614C
    // 0x80125A9C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_8012614C;
    // 0x80125A9C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80125AA0:
    // 0x80125AA0: jal         0x80016F90
    // 0x80125AA4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_3;
    // 0x80125AA4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_3:
    // 0x80125AA8: jal         0x80017014
    // 0x80125AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_4;
    // 0x80125AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80125AB0: bne         $v0, $zero, L_8012614C
    if (ctx->r2 != 0) {
        // 0x80125AB4: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8012614C;
    }
    // 0x80125AB4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80125AB8: lbu         $v0, -0x2AA4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2AA4);
    // 0x80125ABC: bnel        $v0, $zero, L_80125B20
    if (ctx->r2 != 0) {
        // 0x80125AC0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80125B20;
    }
    goto skip_3;
    // 0x80125AC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_3:
    // 0x80125AC4: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80125AC8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80125ACC: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80125AD0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80125AD4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80125AD8: lw          $t7, 0x1CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1CEC);
    // 0x80125ADC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80125AE0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80125AE4: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80125AE8: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80125AEC: jal         0x80125808
    // 0x80125AF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_5;
    // 0x80125AF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_5:
    // 0x80125AF4: bne         $v0, $zero, L_80125B10
    if (ctx->r2 != 0) {
        // 0x80125AF8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80125B10;
    }
    // 0x80125AF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80125AFC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80125B00: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80125B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125B08: b           L_8012616C
    // 0x80125B0C: sw          $t9, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r25;
        goto L_8012616C;
    // 0x80125B0C: sw          $t9, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r25;
L_80125B10:
    // 0x80125B10: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80125B14: sb          $t0, -0x2AA4($at)
    MEM_B(-0X2AA4, ctx->r1) = ctx->r8;
    // 0x80125B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80125B1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80125B20:
    // 0x80125B20: bnel        $v0, $at, L_80126150
    if (ctx->r2 != ctx->r1) {
        // 0x80125B24: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_4;
    // 0x80125B24: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_4:
    // 0x80125B28: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80125B2C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80125B30: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80125B34: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80125B38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80125B3C: lw          $t3, 0x1CEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1CEC);
    // 0x80125B40: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80125B44: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80125B48: lhu         $a0, 0x2($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X2);
    // 0x80125B4C: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80125B50: jal         0x80125808
    // 0x80125B54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_6;
    // 0x80125B54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_6:
    // 0x80125B58: bne         $v0, $zero, L_80125B74
    if (ctx->r2 != 0) {
        // 0x80125B5C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80125B74;
    }
    // 0x80125B5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80125B60: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80125B64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80125B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80125B6C: b           L_8012616C
    // 0x80125B70: sw          $t5, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r13;
        goto L_8012616C;
    // 0x80125B70: sw          $t5, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r13;
L_80125B74:
    // 0x80125B74: b           L_8012614C
    // 0x80125B78: sb          $zero, -0x2AA4($at)
    MEM_B(-0X2AA4, ctx->r1) = 0;
        goto L_8012614C;
    // 0x80125B78: sb          $zero, -0x2AA4($at)
    MEM_B(-0X2AA4, ctx->r1) = 0;
L_80125B7C:
    // 0x80125B7C: jal         0x8012FF4C
    // 0x80125B80: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_7;
    // 0x80125B80: nop

    after_7:
    // 0x80125B84: beq         $s2, $v0, L_80125BE4
    if (ctx->r18 == ctx->r2) {
        // 0x80125B88: nop
    
            goto L_80125BE4;
    }
    // 0x80125B88: nop

    // 0x80125B8C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80125B90: lbu         $t0, 0x0($s7)
    ctx->r8 = MEM_BU(ctx->r23, 0X0);
    // 0x80125B94: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80125B98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80125B9C: nop

    // 0x80125BA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80125BA4: swc1        $f6, 0x198($s1)
    MEM_W(0X198, ctx->r17) = ctx->f6.u32l;
    // 0x80125BA8: lh          $t7, -0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X4);
    // 0x80125BAC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80125BB0: nop

    // 0x80125BB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80125BB8: swc1        $f10, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->f10.u32l;
    // 0x80125BBC: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x80125BC0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80125BC4: nop

    // 0x80125BC8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80125BCC: swc1        $f18, 0x1A0($s1)
    MEM_W(0X1A0, ctx->r17) = ctx->f18.u32l;
    // 0x80125BD0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80125BD4: beq         $t0, $zero, L_8012614C
    if (ctx->r8 == 0) {
        // 0x80125BD8: sh          $t9, 0x32($s1)
        MEM_H(0X32, ctx->r17) = ctx->r25;
            goto L_8012614C;
    }
    // 0x80125BD8: sh          $t9, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r25;
    // 0x80125BDC: b           L_80126150
    // 0x80125BE0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
        goto L_80126150;
    // 0x80125BE0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
L_80125BE4:
    // 0x80125BE4: b           L_8012614C
    // 0x80125BE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8012614C;
    // 0x80125BE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80125BEC:
    // 0x80125BEC: jal         0x8012FF4C
    // 0x80125BF0: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_8;
    // 0x80125BF0: nop

    after_8:
    // 0x80125BF4: beq         $s2, $v0, L_80125C44
    if (ctx->r18 == ctx->r2) {
        // 0x80125BF8: nop
    
            goto L_80125C44;
    }
    // 0x80125BF8: nop

    // 0x80125BFC: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80125C00: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125C04: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80125C08: nop

    // 0x80125C0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80125C10: swc1        $f6, 0x198($s1)
    MEM_W(0X198, ctx->r17) = ctx->f6.u32l;
    // 0x80125C14: lh          $t2, -0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X2);
    // 0x80125C18: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80125C1C: nop

    // 0x80125C20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80125C24: swc1        $f10, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->f10.u32l;
    // 0x80125C28: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80125C2C: sh          $zero, 0x32($s1)
    MEM_H(0X32, ctx->r17) = 0;
    // 0x80125C30: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80125C34: nop

    // 0x80125C38: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80125C3C: b           L_8012614C
    // 0x80125C40: swc1        $f18, 0x1A0($s1)
    MEM_W(0X1A0, ctx->r17) = ctx->f18.u32l;
        goto L_8012614C;
    // 0x80125C40: swc1        $f18, 0x1A0($s1)
    MEM_W(0X1A0, ctx->r17) = ctx->f18.u32l;
L_80125C44:
    // 0x80125C44: b           L_8012614C
    // 0x80125C48: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
        goto L_8012614C;
    // 0x80125C48: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_80125C4C:
    // 0x80125C4C: jal         0x8012FF4C
    // 0x80125C50: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_9;
    // 0x80125C50: nop

    after_9:
    // 0x80125C54: beq         $s2, $v0, L_80125CC0
    if (ctx->r18 == ctx->r2) {
        // 0x80125C58: nop
    
            goto L_80125CC0;
    }
    // 0x80125C58: nop

    // 0x80125C5C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80125C60: lbu         $t8, 0x0($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X0);
    // 0x80125C64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80125C68: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80125C6C: nop

    // 0x80125C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80125C74: swc1        $f6, 0x111C($s1)
    MEM_W(0X111C, ctx->r17) = ctx->f6.u32l;
    // 0x80125C78: lh          $t5, -0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X4);
    // 0x80125C7C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80125C80: nop

    // 0x80125C84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80125C88: swc1        $f10, 0x1120($s1)
    MEM_W(0X1120, ctx->r17) = ctx->f10.u32l;
    // 0x80125C8C: lh          $t6, -0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X2);
    // 0x80125C90: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80125C94: nop

    // 0x80125C98: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80125C9C: swc1        $f18, 0x1124($s1)
    MEM_W(0X1124, ctx->r17) = ctx->f18.u32l;
    // 0x80125CA0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80125CA4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80125CA8: nop

    // 0x80125CAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80125CB0: beq         $t8, $zero, L_8012614C
    if (ctx->r24 == 0) {
        // 0x80125CB4: swc1        $f6, 0x1128($s1)
        MEM_W(0X1128, ctx->r17) = ctx->f6.u32l;
            goto L_8012614C;
    }
    // 0x80125CB4: swc1        $f6, 0x1128($s1)
    MEM_W(0X1128, ctx->r17) = ctx->f6.u32l;
    // 0x80125CB8: b           L_80126150
    // 0x80125CBC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
        goto L_80126150;
    // 0x80125CBC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
L_80125CC0:
    // 0x80125CC0: b           L_8012614C
    // 0x80125CC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8012614C;
    // 0x80125CC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80125CC8:
    // 0x80125CC8: jal         0x8012FF4C
    // 0x80125CCC: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_10;
    // 0x80125CCC: nop

    after_10:
    // 0x80125CD0: beq         $s2, $v0, L_80125D24
    if (ctx->r18 == ctx->r2) {
        // 0x80125CD4: nop
    
            goto L_80125D24;
    }
    // 0x80125CD4: nop

    // 0x80125CD8: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x80125CDC: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125CE0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80125CE4: nop

    // 0x80125CE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80125CEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80125CF0: swc1        $f10, 0x111C($s1)
    MEM_W(0X111C, ctx->r17) = ctx->f10.u32l;
    // 0x80125CF4: lh          $t0, -0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, -0X2);
    // 0x80125CF8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80125CFC: nop

    // 0x80125D00: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80125D04: swc1        $f18, 0x1120($s1)
    MEM_W(0X1120, ctx->r17) = ctx->f18.u32l;
    // 0x80125D08: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80125D0C: swc1        $f8, 0x1128($s1)
    MEM_W(0X1128, ctx->r17) = ctx->f8.u32l;
    // 0x80125D10: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80125D14: nop

    // 0x80125D18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80125D1C: b           L_8012614C
    // 0x80125D20: swc1        $f6, 0x1124($s1)
    MEM_W(0X1124, ctx->r17) = ctx->f6.u32l;
        goto L_8012614C;
    // 0x80125D20: swc1        $f6, 0x1124($s1)
    MEM_W(0X1124, ctx->r17) = ctx->f6.u32l;
L_80125D24:
    // 0x80125D24: b           L_8012614C
    // 0x80125D28: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
        goto L_8012614C;
    // 0x80125D28: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_80125D2C:
    // 0x80125D2C: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80125D30: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125D34: sb          $t5, 0xF20($s1)
    MEM_B(0XF20, ctx->r17) = ctx->r13;
    // 0x80125D38: lh          $t6, -0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X2);
    // 0x80125D3C: sb          $t6, 0xF21($s1)
    MEM_B(0XF21, ctx->r17) = ctx->r14;
    // 0x80125D40: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80125D44: sb          $t5, 0xF36($s1)
    MEM_B(0XF36, ctx->r17) = ctx->r13;
    // 0x80125D48: sb          $t6, 0xF37($s1)
    MEM_B(0XF37, ctx->r17) = ctx->r14;
    // 0x80125D4C: sb          $t7, 0xF22($s1)
    MEM_B(0XF22, ctx->r17) = ctx->r15;
    // 0x80125D50: b           L_8012614C
    // 0x80125D54: sb          $t7, 0xF38($s1)
    MEM_B(0XF38, ctx->r17) = ctx->r15;
        goto L_8012614C;
    // 0x80125D54: sb          $t7, 0xF38($s1)
    MEM_B(0XF38, ctx->r17) = ctx->r15;
L_80125D58:
    // 0x80125D58: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80125D5C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125D60: sb          $t1, 0xF23($s1)
    MEM_B(0XF23, ctx->r17) = ctx->r9;
    // 0x80125D64: lh          $t2, -0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X2);
    // 0x80125D68: sb          $t2, 0xF24($s1)
    MEM_B(0XF24, ctx->r17) = ctx->r10;
    // 0x80125D6C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80125D70: sb          $t1, 0xF39($s1)
    MEM_B(0XF39, ctx->r17) = ctx->r9;
    // 0x80125D74: sb          $t2, 0xF3A($s1)
    MEM_B(0XF3A, ctx->r17) = ctx->r10;
    // 0x80125D78: sb          $t3, 0xF25($s1)
    MEM_B(0XF25, ctx->r17) = ctx->r11;
    // 0x80125D7C: b           L_8012614C
    // 0x80125D80: sb          $t3, 0xF3B($s1)
    MEM_B(0XF3B, ctx->r17) = ctx->r11;
        goto L_8012614C;
    // 0x80125D80: sb          $t3, 0xF3B($s1)
    MEM_B(0XF3B, ctx->r17) = ctx->r11;
L_80125D84:
    // 0x80125D84: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80125D88: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125D8C: sb          $t4, 0xF26($s1)
    MEM_B(0XF26, ctx->r17) = ctx->r12;
    // 0x80125D90: lh          $t5, -0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X2);
    // 0x80125D94: lb          $t7, 0xF26($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XF26);
    // 0x80125D98: sb          $t5, 0xF27($s1)
    MEM_B(0XF27, ctx->r17) = ctx->r13;
    // 0x80125D9C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80125DA0: lb          $t8, 0xF27($s1)
    ctx->r24 = MEM_B(ctx->r17, 0XF27);
    // 0x80125DA4: sb          $t7, 0xF3C($s1)
    MEM_B(0XF3C, ctx->r17) = ctx->r15;
    // 0x80125DA8: sb          $t6, 0xF28($s1)
    MEM_B(0XF28, ctx->r17) = ctx->r14;
    // 0x80125DAC: lb          $t9, 0xF28($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XF28);
    // 0x80125DB0: sb          $t8, 0xF3D($s1)
    MEM_B(0XF3D, ctx->r17) = ctx->r24;
    // 0x80125DB4: b           L_8012614C
    // 0x80125DB8: sb          $t9, 0xF3E($s1)
    MEM_B(0XF3E, ctx->r17) = ctx->r25;
        goto L_8012614C;
    // 0x80125DB8: sb          $t9, 0xF3E($s1)
    MEM_B(0XF3E, ctx->r17) = ctx->r25;
L_80125DBC:
    // 0x80125DBC: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x80125DC0: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125DC4: sb          $t3, 0xF29($s1)
    MEM_B(0XF29, ctx->r17) = ctx->r11;
    // 0x80125DC8: lh          $t4, -0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X2);
    // 0x80125DCC: sb          $t4, 0xF2A($s1)
    MEM_B(0XF2A, ctx->r17) = ctx->r12;
    // 0x80125DD0: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80125DD4: sb          $t3, 0xF3F($s1)
    MEM_B(0XF3F, ctx->r17) = ctx->r11;
    // 0x80125DD8: sb          $t4, 0xF40($s1)
    MEM_B(0XF40, ctx->r17) = ctx->r12;
    // 0x80125DDC: sb          $t5, 0xF2B($s1)
    MEM_B(0XF2B, ctx->r17) = ctx->r13;
    // 0x80125DE0: b           L_8012614C
    // 0x80125DE4: sb          $t5, 0xF41($s1)
    MEM_B(0XF41, ctx->r17) = ctx->r13;
        goto L_8012614C;
    // 0x80125DE4: sb          $t5, 0xF41($s1)
    MEM_B(0XF41, ctx->r17) = ctx->r13;
L_80125DE8:
    // 0x80125DE8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80125DEC: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80125DF0: sb          $t6, 0xF2C($s1)
    MEM_B(0XF2C, ctx->r17) = ctx->r14;
    // 0x80125DF4: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x80125DF8: lb          $t9, 0xF2C($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XF2C);
    // 0x80125DFC: sb          $t7, 0xF2D($s1)
    MEM_B(0XF2D, ctx->r17) = ctx->r15;
    // 0x80125E00: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80125E04: lb          $t0, 0xF2D($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XF2D);
    // 0x80125E08: sb          $t9, 0xF42($s1)
    MEM_B(0XF42, ctx->r17) = ctx->r25;
    // 0x80125E0C: sb          $t8, 0xF2E($s1)
    MEM_B(0XF2E, ctx->r17) = ctx->r24;
    // 0x80125E10: lb          $t1, 0xF2E($s1)
    ctx->r9 = MEM_B(ctx->r17, 0XF2E);
    // 0x80125E14: sb          $t0, 0xF43($s1)
    MEM_B(0XF43, ctx->r17) = ctx->r8;
    // 0x80125E18: b           L_8012614C
    // 0x80125E1C: sb          $t1, 0xF44($s1)
    MEM_B(0XF44, ctx->r17) = ctx->r9;
        goto L_8012614C;
    // 0x80125E1C: sb          $t1, 0xF44($s1)
    MEM_B(0XF44, ctx->r17) = ctx->r9;
L_80125E20:
    // 0x80125E20: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80125E24: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80125E28: sb          $t6, 0xF32($s1)
    MEM_B(0XF32, ctx->r17) = ctx->r14;
    // 0x80125E2C: lh          $t7, -0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X4);
    // 0x80125E30: sb          $t7, 0xF33($s1)
    MEM_B(0XF33, ctx->r17) = ctx->r15;
    // 0x80125E34: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x80125E38: sb          $t8, 0xF34($s1)
    MEM_B(0XF34, ctx->r17) = ctx->r24;
    // 0x80125E3C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80125E40: sb          $t6, 0xF45($s1)
    MEM_B(0XF45, ctx->r17) = ctx->r14;
    // 0x80125E44: sb          $t7, 0xF46($s1)
    MEM_B(0XF46, ctx->r17) = ctx->r15;
    // 0x80125E48: sb          $t8, 0xF47($s1)
    MEM_B(0XF47, ctx->r17) = ctx->r24;
    // 0x80125E4C: sb          $t9, 0xF35($s1)
    MEM_B(0XF35, ctx->r17) = ctx->r25;
    // 0x80125E50: b           L_8012614C
    // 0x80125E54: sb          $t9, 0xF48($s1)
    MEM_B(0XF48, ctx->r17) = ctx->r25;
        goto L_8012614C;
    // 0x80125E54: sb          $t9, 0xF48($s1)
    MEM_B(0XF48, ctx->r17) = ctx->r25;
L_80125E58:
    // 0x80125E58: jal         0x8012FF4C
    // 0x80125E5C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_11;
    // 0x80125E5C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_11:
    // 0x80125E60: beql        $s3, $v0, L_80126150
    if (ctx->r19 == ctx->r2) {
        // 0x80125E64: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_5;
    // 0x80125E64: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x80125E68: jal         0x8012FF4C
    // 0x80125E6C: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_12;
    // 0x80125E6C: nop

    after_12:
    // 0x80125E70: beql        $s2, $v0, L_80126150
    if (ctx->r18 == ctx->r2) {
        // 0x80125E74: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_6;
    // 0x80125E74: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_6:
    // 0x80125E78: jal         0x8012FF4C
    // 0x80125E7C: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_13;
    // 0x80125E7C: nop

    after_13:
    // 0x80125E80: beql        $s4, $v0, L_80126150
    if (ctx->r20 == ctx->r2) {
        // 0x80125E84: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_7;
    // 0x80125E84: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_7:
    // 0x80125E88: jal         0x8012FF4C
    // 0x80125E8C: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_14;
    // 0x80125E8C: nop

    after_14:
    // 0x80125E90: beql        $s5, $v0, L_80126150
    if (ctx->r21 == ctx->r2) {
        // 0x80125E94: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_8;
    // 0x80125E94: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_8:
    // 0x80125E98: jal         0x8012FF4C
    // 0x80125E9C: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_15;
    // 0x80125E9C: nop

    after_15:
    // 0x80125EA0: beql        $s6, $v0, L_80126150
    if (ctx->r22 == ctx->r2) {
        // 0x80125EA4: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_9;
    // 0x80125EA4: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_9:
    // 0x80125EA8: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80125EAC: b           L_8012614C
    // 0x80125EB0: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
        goto L_8012614C;
    // 0x80125EB0: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
L_80125EB4:
    // 0x80125EB4: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80125EB8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80125EBC: beql        $t1, $zero, L_80126150
    if (ctx->r9 == 0) {
        // 0x80125EC0: lh          $v1, 0x2($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X2);
            goto L_80126150;
    }
    goto skip_10;
    // 0x80125EC0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    skip_10:
L_80125EC4:
    // 0x80125EC4: jal         0x8012FF4C
    // 0x80125EC8: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_16;
    // 0x80125EC8: nop

    after_16:
    // 0x80125ECC: beql        $s3, $v0, L_80125F20
    if (ctx->r19 == ctx->r2) {
        // 0x80125ED0: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80125F20;
    }
    goto skip_11;
    // 0x80125ED0: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_11:
    // 0x80125ED4: jal         0x8012FF4C
    // 0x80125ED8: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_17;
    // 0x80125ED8: nop

    after_17:
    // 0x80125EDC: beql        $s2, $v0, L_80125F20
    if (ctx->r18 == ctx->r2) {
        // 0x80125EE0: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80125F20;
    }
    goto skip_12;
    // 0x80125EE0: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_12:
    // 0x80125EE4: jal         0x8012FF4C
    // 0x80125EE8: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_18;
    // 0x80125EE8: nop

    after_18:
    // 0x80125EEC: beql        $s4, $v0, L_80125F20
    if (ctx->r20 == ctx->r2) {
        // 0x80125EF0: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80125F20;
    }
    goto skip_13;
    // 0x80125EF0: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_13:
    // 0x80125EF4: jal         0x8012FF4C
    // 0x80125EF8: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_19;
    // 0x80125EF8: nop

    after_19:
    // 0x80125EFC: beql        $s5, $v0, L_80125F20
    if (ctx->r21 == ctx->r2) {
        // 0x80125F00: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80125F20;
    }
    goto skip_14;
    // 0x80125F00: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_14:
    // 0x80125F04: jal         0x8012FF4C
    // 0x80125F08: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_20;
    // 0x80125F08: nop

    after_20:
    // 0x80125F0C: beql        $s6, $v0, L_80125F20
    if (ctx->r22 == ctx->r2) {
        // 0x80125F10: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80125F20;
    }
    goto skip_15;
    // 0x80125F10: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_15:
    // 0x80125F14: jal         0x80020718
    // 0x80125F18: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_21;
    // 0x80125F18: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_21:
    // 0x80125F1C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
L_80125F20:
    // 0x80125F20: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80125F24: bne         $t2, $zero, L_80125EC4
    if (ctx->r10 != 0) {
        // 0x80125F28: nop
    
            goto L_80125EC4;
    }
    // 0x80125F28: nop

    // 0x80125F2C: b           L_80126150
    // 0x80125F30: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
        goto L_80126150;
    // 0x80125F30: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
L_80125F34:
    // 0x80125F34: jal         0x80151B98
    // 0x80125F38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80151B98)(rdram, ctx);
        goto after_22;
    // 0x80125F38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x80125F3C: jal         0x80151C08
    // 0x80125F40: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    LOOKUP_FUNC(0x80151C08)(rdram, ctx);
        goto after_23;
    // 0x80125F40: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    after_23:
    // 0x80125F44: jal         0x80151C40
    // 0x80125F48: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    LOOKUP_FUNC(0x80151C40)(rdram, ctx);
        goto after_24;
    // 0x80125F48: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    after_24:
    // 0x80125F4C: jal         0x80151C34
    // 0x80125F50: nop

    LOOKUP_FUNC(0x80151C34)(rdram, ctx);
        goto after_25;
    // 0x80125F50: nop

    after_25:
    // 0x80125F54: beq         $v0, $zero, L_80125F90
    if (ctx->r2 == 0) {
        // 0x80125F58: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80125F90;
    }
    // 0x80125F58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80125F5C: beq         $v0, $at, L_80125F78
    if (ctx->r2 == ctx->r1) {
        // 0x80125F60: addiu       $t3, $zero, 0x555
        ctx->r11 = ADD32(0, 0X555);
            goto L_80125F78;
    }
    // 0x80125F60: addiu       $t3, $zero, 0x555
    ctx->r11 = ADD32(0, 0X555);
    // 0x80125F64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80125F68: beq         $v0, $at, L_80125F90
    if (ctx->r2 == ctx->r1) {
        // 0x80125F6C: nop
    
            goto L_80125F90;
    }
    // 0x80125F6C: nop

    // 0x80125F70: b           L_80125F98
    // 0x80125F74: nop

        goto L_80125F98;
    // 0x80125F74: nop

L_80125F78:
    // 0x80125F78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80125F7C: sh          $t3, -0x23C0($at)
    MEM_H(-0X23C0, ctx->r1) = ctx->r11;
    // 0x80125F80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80125F84: addiu       $t4, $zero, 0x555
    ctx->r12 = ADD32(0, 0X555);
    // 0x80125F88: b           L_80125F98
    // 0x80125F8C: sh          $t4, -0x23BE($at)
    MEM_H(-0X23BE, ctx->r1) = ctx->r12;
        goto L_80125F98;
    // 0x80125F8C: sh          $t4, -0x23BE($at)
    MEM_H(-0X23BE, ctx->r1) = ctx->r12;
L_80125F90:
    // 0x80125F90: jal         0x80152608
    // 0x80125F94: nop

    LOOKUP_FUNC(0x80152608)(rdram, ctx);
        goto after_26;
    // 0x80125F94: nop

    after_26:
L_80125F98:
    // 0x80125F98: jal         0x80151BFC
    // 0x80125F9C: nop

    LOOKUP_FUNC(0x80151BFC)(rdram, ctx);
        goto after_27;
    // 0x80125F9C: nop

    after_27:
    // 0x80125FA0: bne         $v0, $zero, L_80125FE8
    if (ctx->r2 != 0) {
        // 0x80125FA4: nop
    
            goto L_80125FE8;
    }
    // 0x80125FA4: nop

    // 0x80125FA8: lhu         $t5, 0x2C($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X2C);
    // 0x80125FAC: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x80125FB0: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x80125FB4: beq         $at, $zero, L_80125FE8
    if (ctx->r1 == 0) {
        // 0x80125FB8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80125FE8;
    }
    // 0x80125FB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80125FBC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80125FC0: addu        $at, $at, $t6
    gpr jr_addend_80125FC8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80125FC4: lw          $t6, -0x3534($at)
    ctx->r14 = ADD32(ctx->r1, -0X3534);
    // 0x80125FC8: jr          $t6
    // 0x80125FCC: nop

    switch (jr_addend_80125FC8 >> 2) {
        case 0: goto L_80125FD0; break;
        case 1: goto L_80125FE0; break;
        case 2: goto L_80125FE8; break;
        case 3: goto L_80125FE8; break;
        case 4: goto L_80125FE8; break;
        case 5: goto L_80125FE8; break;
        case 6: goto L_80125FE0; break;
        case 7: goto L_80125FE0; break;
        case 8: goto L_80125FE8; break;
        case 9: goto L_80125FE8; break;
        case 10: goto L_80125FE8; break;
        case 11: goto L_80125FE0; break;
        default: switch_error(__func__, 0x80125FC8, 0x8018CACC);
    }
    // 0x80125FCC: nop

L_80125FD0:
    // 0x80125FD0: jal         0x80020718
    // 0x80125FD4: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_28;
    // 0x80125FD4: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_28:
    // 0x80125FD8: b           L_8012614C
    // 0x80125FDC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8012614C;
    // 0x80125FDC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80125FE0:
    // 0x80125FE0: jal         0x80020718
    // 0x80125FE4: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_29;
    // 0x80125FE4: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    after_29:
L_80125FE8:
    // 0x80125FE8: b           L_8012614C
    // 0x80125FEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8012614C;
    // 0x80125FEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80125FF0:
    // 0x80125FF0: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80125FF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80125FF8: addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
    // 0x80125FFC: sb          $t7, 0x2AD($s1)
    MEM_B(0X2AD, ctx->r17) = ctx->r15;
    // 0x80126000: lh          $t8, -0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, -0XE);
    // 0x80126004: sb          $t8, 0x2AE($s1)
    MEM_B(0X2AE, ctx->r17) = ctx->r24;
    // 0x80126008: lh          $t9, -0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, -0XC);
    // 0x8012600C: sb          $t9, 0x2B5($s1)
    MEM_B(0X2B5, ctx->r17) = ctx->r25;
    // 0x80126010: lh          $t0, -0xA($s0)
    ctx->r8 = MEM_H(ctx->r16, -0XA);
    // 0x80126014: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80126018: nop

    // 0x8012601C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80126020: swc1        $f16, 0x2C0($s1)
    MEM_W(0X2C0, ctx->r17) = ctx->f16.u32l;
    // 0x80126024: lh          $t1, -0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, -0X8);
    // 0x80126028: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8012602C: nop

    // 0x80126030: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80126034: swc1        $f4, 0x2CC($s1)
    MEM_W(0X2CC, ctx->r17) = ctx->f4.u32l;
    // 0x80126038: lh          $t2, -0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X6);
    // 0x8012603C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80126040: nop

    // 0x80126044: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80126048: swc1        $f8, 0x2D8($s1)
    MEM_W(0X2D8, ctx->r17) = ctx->f8.u32l;
    // 0x8012604C: lh          $t3, -0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X4);
    // 0x80126050: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80126054: nop

    // 0x80126058: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8012605C: swc1        $f16, 0x2E8($s1)
    MEM_W(0X2E8, ctx->r17) = ctx->f16.u32l;
    // 0x80126060: lh          $t4, -0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X2);
    // 0x80126064: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80126068: nop

    // 0x8012606C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80126070: swc1        $f4, 0x2F4($s1)
    MEM_W(0X2F4, ctx->r17) = ctx->f4.u32l;
    // 0x80126074: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80126078: sb          $t6, 0x298($s1)
    MEM_B(0X298, ctx->r17) = ctx->r14;
    // 0x8012607C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80126080: nop

    // 0x80126084: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80126088: b           L_8012614C
    // 0x8012608C: swc1        $f8, 0x300($s1)
    MEM_W(0X300, ctx->r17) = ctx->f8.u32l;
        goto L_8012614C;
    // 0x8012608C: swc1        $f8, 0x300($s1)
    MEM_W(0X300, ctx->r17) = ctx->f8.u32l;
L_80126090:
    // 0x80126090: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80126094: jal         0x801BF610
    // 0x80126098: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    LOOKUP_FUNC(0x801BF610)(rdram, ctx);
        goto after_30;
    // 0x80126098: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_30:
    // 0x8012609C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x801260A0: jal         0x801BF61C
    // 0x801260A4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    LOOKUP_FUNC(0x801BF61C)(rdram, ctx);
        goto after_31;
    // 0x801260A4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_31:
    // 0x801260A8: b           L_80126150
    // 0x801260AC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
        goto L_80126150;
    // 0x801260AC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
L_801260B0:
    // 0x801260B0: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x801260B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801260B8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801260BC: nop

    // 0x801260C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801260C4: swc1        $f16, 0x29C($s1)
    MEM_W(0X29C, ctx->r17) = ctx->f16.u32l;
    // 0x801260C8: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x801260CC: lwc1        $f6, 0x29C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
    // 0x801260D0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801260D4: swc1        $f6, 0x2A4($s1)
    MEM_W(0X2A4, ctx->r17) = ctx->f6.u32l;
    // 0x801260D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801260DC: swc1        $f4, 0x2A0($s1)
    MEM_W(0X2A0, ctx->r17) = ctx->f4.u32l;
    // 0x801260E0: lwc1        $f8, 0x2A0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2A0);
    // 0x801260E4: b           L_8012614C
    // 0x801260E8: swc1        $f8, 0x2A8($s1)
    MEM_W(0X2A8, ctx->r17) = ctx->f8.u32l;
        goto L_8012614C;
    // 0x801260E8: swc1        $f8, 0x2A8($s1)
    MEM_W(0X2A8, ctx->r17) = ctx->f8.u32l;
L_801260EC:
    // 0x801260EC: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x801260F0: beql        $v0, $zero, L_80126134
    if (ctx->r2 == 0) {
        // 0x801260F4: lwc1        $f6, 0x29C($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
            goto L_80126134;
    }
    goto skip_16;
    // 0x801260F4: lwc1        $f6, 0x29C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
    skip_16:
    // 0x801260F8: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x801260FC: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x80126100: beql        $t0, $zero, L_80126134
    if (ctx->r8 == 0) {
        // 0x80126104: lwc1        $f6, 0x29C($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
            goto L_80126134;
    }
    goto skip_17;
    // 0x80126104: lwc1        $f6, 0x29C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
    skip_17:
    // 0x80126108: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x8012610C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80126110: nop

    // 0x80126114: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80126118: swc1        $f16, 0x29C($s1)
    MEM_W(0X29C, ctx->r17) = ctx->f16.u32l;
    // 0x8012611C: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x80126120: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80126124: nop

    // 0x80126128: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8012612C: swc1        $f4, 0x2A0($s1)
    MEM_W(0X2A0, ctx->r17) = ctx->f4.u32l;
    // 0x80126130: lwc1        $f6, 0x29C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X29C);
L_80126134:
    // 0x80126134: lwc1        $f8, 0x2A0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2A0);
    // 0x80126138: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8012613C: swc1        $f6, 0x2A4($s1)
    MEM_W(0X2A4, ctx->r17) = ctx->f6.u32l;
    // 0x80126140: b           L_8012614C
    // 0x80126144: swc1        $f8, 0x2A8($s1)
    MEM_W(0X2A8, ctx->r17) = ctx->f8.u32l;
        goto L_8012614C;
    // 0x80126144: swc1        $f8, 0x2A8($s1)
    MEM_W(0X2A8, ctx->r17) = ctx->f8.u32l;
L_80126148:
    // 0x80126148: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8012614C:
    // 0x8012614C: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
L_80126150:
    // 0x80126150: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80126154: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80126158: bnel        $v1, $at, L_80125A20
    if (ctx->r3 != ctx->r1) {
        // 0x8012615C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80125A20;
    }
    goto skip_18;
    // 0x8012615C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    skip_18:
L_80126160:
    // 0x80126160: jal         0x801257DC
    // 0x80126164: nop

    LOOKUP_FUNC(0x801257DC)(rdram, ctx);
        goto after_32;
    // 0x80126164: nop

    after_32:
    // 0x80126168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8012616C:
    // 0x8012616C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80126170: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80126174: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80126178: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8012617C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80126180: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80126184: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80126188: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8012618C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80126190: jr          $ra
    // 0x80126194: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80126194: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126198(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126198: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8012619C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801261A0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801261A4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801261A8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801261AC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801261B0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801261B4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801261B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801261BC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x801261C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801261C4: andi        $s3, $a1, 0xFFFF
    ctx->r19 = ctx->r5 & 0XFFFF;
    // 0x801261C8: beq         $v0, $zero, L_801262B0
    if (ctx->r2 == 0) {
        // 0x801261CC: lui         $s5, 0x8017
        ctx->r21 = S32(0X8017 << 16);
            goto L_801262B0;
    }
    // 0x801261CC: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x801261D0: lui         $s2, 0x8003
    ctx->r18 = S32(0X8003 << 16);
    // 0x801261D4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801261D8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x801261DC: addiu       $s2, $s2, 0x7744
    ctx->r18 = ADD32(ctx->r18, 0X7744);
    // 0x801261E0: addiu       $s5, $s5, 0x60C0
    ctx->r21 = ADD32(ctx->r21, 0X60C0);
    // 0x801261E4: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x801261E8: lhu         $t6, 0x1E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1E);
L_801261EC:
    // 0x801261EC: bnel        $t6, $zero, L_801262A4
    if (ctx->r14 != 0) {
        // 0x801261F0: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_801262A4;
    }
    goto skip_0;
    // 0x801261F0: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_0:
    // 0x801261F4: lhu         $t7, 0x1C($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1C);
    // 0x801261F8: and         $t8, $t7, $s3
    ctx->r24 = ctx->r15 & ctx->r19;
    // 0x801261FC: beql        $t8, $zero, L_801262A4
    if (ctx->r24 == 0) {
        // 0x80126200: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_801262A4;
    }
    goto skip_1;
    // 0x80126200: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_1:
    // 0x80126204: bne         $s4, $v0, L_80126220
    if (ctx->r20 != ctx->r2) {
        // 0x80126208: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80126220;
    }
    // 0x80126208: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8012620C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80126210: beql        $t9, $zero, L_801262A4
    if (ctx->r25 == 0) {
        // 0x80126214: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_801262A4;
    }
    goto skip_2;
    // 0x80126214: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_2:
    // 0x80126218: b           L_801262A4
    // 0x8012621C: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
        goto L_801262A4;
    // 0x8012621C: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
L_80126220:
    // 0x80126220: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80126224: lw          $t2, -0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X4);
    // 0x80126228: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x8012622C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80126230: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80126234: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80126238: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8012623C: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x80126240: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80126244: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80126248: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8012624C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80126250: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80126254: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80126258: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x8012625C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80126260: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x80126264: jal         0x8012C4D0
    // 0x80126268: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x80126268: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_0:
    // 0x8012626C: beq         $v0, $zero, L_80126298
    if (ctx->r2 == 0) {
        // 0x80126270: nop
    
            goto L_80126298;
    }
    // 0x80126270: nop

    // 0x80126274: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x80126278: sw          $s0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r16;
    // 0x8012627C: sh          $t6, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r14;
    // 0x80126280: lhu         $t7, 0x104($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X104);
    // 0x80126284: sb          $t7, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r15;
    // 0x80126288: lhu         $t8, 0x104($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X104);
    // 0x8012628C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80126290: b           L_801262A0
    // 0x80126294: sh          $t9, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r25;
        goto L_801262A0;
    // 0x80126294: sh          $t9, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r25;
L_80126298:
    // 0x80126298: jal         0x8012C778
    // 0x8012629C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C778)(rdram, ctx);
        goto after_1;
    // 0x8012629C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_801262A0:
    // 0x801262A0: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
L_801262A4:
    // 0x801262A4: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x801262A8: bnel        $v0, $zero, L_801261EC
    if (ctx->r2 != 0) {
        // 0x801262AC: lhu         $t6, 0x1E($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X1E);
            goto L_801261EC;
    }
    goto skip_3;
    // 0x801262AC: lhu         $t6, 0x1E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1E);
    skip_3:
L_801262B0:
    // 0x801262B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801262B4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801262B8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801262BC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801262C0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801262C4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801262C8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801262CC: jr          $ra
    // 0x801262D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801262D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801262d4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801262d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801262D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801262D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801262DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801262E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801262E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801262E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x801262EC: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
    // 0x801262F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801262F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801262F8: beql        $v0, $zero, L_80126354
    if (ctx->r2 == 0) {
        // 0x801262FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80126354;
    }
    goto skip_0;
    // 0x801262FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80126300: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80126304: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x80126308: beql        $a0, $zero, L_80126320
    if (ctx->r4 == 0) {
        // 0x8012630C: lhu         $a0, 0x8($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X8);
            goto L_80126320;
    }
    goto skip_1;
    // 0x8012630C: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    skip_1:
    // 0x80126310: jal         0x80126198
    // 0x80126314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80126198)(rdram, ctx);
        goto after_0;
    // 0x80126314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80126318: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8012631C: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
L_80126320:
    // 0x80126320: beql        $a0, $zero, L_80126354
    if (ctx->r4 == 0) {
        // 0x80126324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80126354;
    }
    goto skip_2;
    // 0x80126324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80126328: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8012632C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80126330: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126334: and         $a2, $a2, $at
    ctx->r6 = ctx->r6 & ctx->r1;
    // 0x80126338: jal         0x80005204
    // 0x8012633C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8012633C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80126340: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80126344: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x80126348: jal         0x80126198
    // 0x8012634C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    LOOKUP_FUNC(0x80126198)(rdram, ctx);
        goto after_2;
    // 0x8012634C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    after_2:
    // 0x80126350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80126354:
    // 0x80126354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80126358: jr          $ra
    // 0x8012635C: nop

    return;
    // 0x8012635C: nop

;}
RECOMP_FUNC void M7_FUN_80126360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126360: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80126364: jr          $ra
    // 0x80126368: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    return;
    // 0x80126368: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012636c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012636c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012636C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80126370: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x80126374: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80126378: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8012637C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80126380: lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X2C);
    // 0x80126384: beql        $a2, $zero, L_80126430
    if (ctx->r6 == 0) {
        // 0x80126388: lw          $t2, 0x38($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X38);
            goto L_80126430;
    }
    goto skip_0;
    // 0x80126388: lw          $t2, 0x38($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x8012638C: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80126390: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80126394: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80126398: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x8012639C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801263A0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801263A4: nop

    // 0x801263A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801263AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801263B0: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801263B4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801263B8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x801263BC: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x801263C0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801263C4: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x801263C8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801263CC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801263D0: nop

    // 0x801263D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801263D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801263DC: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801263E0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801263E4: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x801263E8: lw          $t4, 0x38($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X38);
    // 0x801263EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801263F0: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x801263F4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801263F8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801263FC: nop

    // 0x80126400: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80126404: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80126408: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8012640C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80126410: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x80126414: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80126418: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8012641C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80126420: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80126424: jr          $ra
    // 0x80126428: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    return;
    // 0x80126428: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x8012642C: lw          $t2, 0x38($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X38);
L_80126430:
    // 0x80126430: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80126434: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80126438: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x8012643C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80126440: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x80126444: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80126448: nop

    // 0x8012644C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80126450: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80126454: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80126458: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8012645C: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80126460: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x80126464: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80126468: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x8012646C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80126470: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80126474: nop

    // 0x80126478: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8012647C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80126480: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80126484: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80126488: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x8012648C: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x80126490: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80126494: lh          $t9, 0xA($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XA);
    // 0x80126498: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8012649C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801264A0: nop

    // 0x801264A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801264A8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801264AC: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801264B0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801264B4: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x801264B8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801264BC: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x801264C0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801264C4: lh          $t4, 0xC($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XC);
    // 0x801264C8: sh          $t4, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r12;
    // 0x801264CC: jr          $ra
    // 0x801264D0: nop

    return;
    // 0x801264D0: nop

;}
RECOMP_FUNC void M7_FUN_801264d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801264D4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x801264D8: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x801264DC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801264E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801264E4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801264E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801264EC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801264F0: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x801264F4: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x801264F8: beql        $a0, $zero, L_80126538
    if (ctx->r4 == 0) {
        // 0x801264FC: lw          $t5, 0x30($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X30);
            goto L_80126538;
    }
    goto skip_0;
    // 0x801264FC: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x80126500: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80126504: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80126508: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8012650C: swc1        $f14, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f14.u32l;
    // 0x80126510: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80126514: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80126518: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012651C: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x80126520: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80126524: lhu         $t2, 0x16($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X16);
    // 0x80126528: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8012652C: jr          $ra
    // 0x80126530: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    return;
    // 0x80126530: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x80126534: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
L_80126538:
    // 0x80126538: swc1        $f12, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f12.u32l;
    // 0x8012653C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80126540: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80126544: swc1        $f14, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f14.u32l;
    // 0x80126548: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8012654C: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80126550: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80126554: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x80126558: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8012655C: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80126560: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80126564: sh          $t0, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r8;
    // 0x80126568: jr          $ra
    // 0x8012656C: nop

    return;
    // 0x8012656C: nop

;}
RECOMP_FUNC void M7_FUN_80126570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80126574: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80126578: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8012657C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80126580: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80126584: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80126588: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8012658C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80126590: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80126594: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80126598: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8012659C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801265A0: beq         $v0, $zero, L_80126694
    if (ctx->r2 == 0) {
        // 0x801265A4: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_80126694;
    }
    // 0x801265A4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801265A8: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x801265AC: lui         $s2, 0x8003
    ctx->r18 = S32(0X8003 << 16);
    // 0x801265B0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801265B4: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x801265B8: addiu       $s2, $s2, 0x7744
    ctx->r18 = ADD32(ctx->r18, 0X7744);
    // 0x801265BC: addiu       $s5, $s5, 0x60C0
    ctx->r21 = ADD32(ctx->r21, 0X60C0);
    // 0x801265C0: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x801265C4: lhu         $t6, 0x1E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1E);
L_801265C8:
    // 0x801265C8: and         $t7, $t6, $s3
    ctx->r15 = ctx->r14 & ctx->r19;
    // 0x801265CC: beql        $t7, $zero, L_80126688
    if (ctx->r15 == 0) {
        // 0x801265D0: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_80126688;
    }
    goto skip_0;
    // 0x801265D0: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_0:
    // 0x801265D4: lhu         $t8, 0x1C($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1C);
    // 0x801265D8: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
    // 0x801265DC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x801265E0: beql        $t0, $zero, L_80126688
    if (ctx->r8 == 0) {
        // 0x801265E4: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_80126688;
    }
    goto skip_1;
    // 0x801265E4: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_1:
    // 0x801265E8: bne         $s4, $v0, L_80126604
    if (ctx->r20 != ctx->r2) {
        // 0x801265EC: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80126604;
    }
    // 0x801265EC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801265F0: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
    // 0x801265F4: beql        $t1, $zero, L_80126688
    if (ctx->r9 == 0) {
        // 0x801265F8: lhu         $v0, 0x20($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X20);
            goto L_80126688;
    }
    goto skip_2;
    // 0x801265F8: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    skip_2:
    // 0x801265FC: b           L_80126688
    // 0x80126600: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
        goto L_80126688;
    // 0x80126600: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
L_80126604:
    // 0x80126604: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x80126608: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x8012660C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80126610: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80126614: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80126618: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8012661C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80126620: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x80126624: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80126628: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012662C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80126630: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80126634: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80126638: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8012663C: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x80126640: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80126644: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    // 0x80126648: jal         0x8012C4D0
    // 0x8012664C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8012664C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80126650: beq         $v0, $zero, L_8012667C
    if (ctx->r2 == 0) {
        // 0x80126654: nop
    
            goto L_8012667C;
    }
    // 0x80126654: nop

    // 0x80126658: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x8012665C: sw          $s0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r16;
    // 0x80126660: sh          $t8, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r24;
    // 0x80126664: lhu         $t9, 0x104($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X104);
    // 0x80126668: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
    // 0x8012666C: lhu         $t0, 0x104($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X104);
    // 0x80126670: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80126674: b           L_80126684
    // 0x80126678: sh          $t1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r9;
        goto L_80126684;
    // 0x80126678: sh          $t1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r9;
L_8012667C:
    // 0x8012667C: jal         0x8012C778
    // 0x80126680: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C778)(rdram, ctx);
        goto after_1;
    // 0x80126680: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80126684:
    // 0x80126684: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
L_80126688:
    // 0x80126688: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8012668C: bnel        $v0, $zero, L_801265C8
    if (ctx->r2 != 0) {
        // 0x80126690: lhu         $t6, 0x1E($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X1E);
            goto L_801265C8;
    }
    goto skip_3;
    // 0x80126690: lhu         $t6, 0x1E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1E);
    skip_3:
L_80126694:
    // 0x80126694: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80126698: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8012669C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801266A0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801266A4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801266A8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801266AC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801266B0: jr          $ra
    // 0x801266B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801266B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801266b8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801266b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801266B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801266BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801266C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801266C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801266C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801266CC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x801266D0: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
    // 0x801266D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801266D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801266DC: beql        $v0, $zero, L_80126738
    if (ctx->r2 == 0) {
        // 0x801266E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80126738;
    }
    goto skip_0;
    // 0x801266E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801266E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801266E8: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x801266EC: beql        $a0, $zero, L_80126704
    if (ctx->r4 == 0) {
        // 0x801266F0: lhu         $a0, 0x8($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X8);
            goto L_80126704;
    }
    goto skip_1;
    // 0x801266F0: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    skip_1:
    // 0x801266F4: jal         0x80126570
    // 0x801266F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80126570)(rdram, ctx);
        goto after_0;
    // 0x801266F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801266FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80126700: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
L_80126704:
    // 0x80126704: beql        $a0, $zero, L_80126738
    if (ctx->r4 == 0) {
        // 0x80126708: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80126738;
    }
    goto skip_2;
    // 0x80126708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8012670C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80126710: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80126714: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126718: and         $a2, $a2, $at
    ctx->r6 = ctx->r6 & ctx->r1;
    // 0x8012671C: jal         0x80005204
    // 0x80126720: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x80126720: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80126724: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80126728: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x8012672C: jal         0x80126570
    // 0x80126730: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    LOOKUP_FUNC(0x80126570)(rdram, ctx);
        goto after_2;
    // 0x80126730: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    after_2:
    // 0x80126734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80126738:
    // 0x80126738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8012673C: jr          $ra
    // 0x80126740: nop

    return;
    // 0x80126740: nop

;}
RECOMP_FUNC void M7_FUN_80126744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126744: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126748: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8012674C: lbu         $t6, 0x181($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X181);
    // 0x80126750: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80126754: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80126758: beql        $t6, $zero, L_8012676C
    if (ctx->r14 == 0) {
        // 0x8012675C: sb          $zero, 0x182($v0)
        MEM_B(0X182, ctx->r2) = 0;
            goto L_8012676C;
    }
    goto skip_0;
    // 0x8012675C: sb          $zero, 0x182($v0)
    MEM_B(0X182, ctx->r2) = 0;
    skip_0:
    // 0x80126760: b           L_8012676C
    // 0x80126764: sb          $t7, 0x182($v0)
    MEM_B(0X182, ctx->r2) = ctx->r15;
        goto L_8012676C;
    // 0x80126764: sb          $t7, 0x182($v0)
    MEM_B(0X182, ctx->r2) = ctx->r15;
    // 0x80126768: sb          $zero, 0x182($v0)
    MEM_B(0X182, ctx->r2) = 0;
L_8012676C:
    // 0x8012676C: lbu         $t8, 0x186($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X186);
    // 0x80126770: sb          $zero, 0x181($v0)
    MEM_B(0X181, ctx->r2) = 0;
    // 0x80126774: beql        $t8, $zero, L_80126788
    if (ctx->r24 == 0) {
        // 0x80126778: sb          $zero, 0x187($v0)
        MEM_B(0X187, ctx->r2) = 0;
            goto L_80126788;
    }
    goto skip_1;
    // 0x80126778: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
    skip_1:
    // 0x8012677C: b           L_8012678C
    // 0x80126780: sb          $t9, 0x187($v0)
    MEM_B(0X187, ctx->r2) = ctx->r25;
        goto L_8012678C;
    // 0x80126780: sb          $t9, 0x187($v0)
    MEM_B(0X187, ctx->r2) = ctx->r25;
    // 0x80126784: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
L_80126788:
    // 0x80126788: sh          $zero, 0x184($v0)
    MEM_H(0X184, ctx->r2) = 0;
L_8012678C:
    // 0x8012678C: jr          $ra
    // 0x80126790: sb          $zero, 0x186($v0)
    MEM_B(0X186, ctx->r2) = 0;
    return;
    // 0x80126790: sb          $zero, 0x186($v0)
    MEM_B(0X186, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126794(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126794: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126798: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8012679C: sb          $zero, 0x181($v0)
    MEM_B(0X181, ctx->r2) = 0;
    // 0x801267A0: sb          $zero, 0x182($v0)
    MEM_B(0X182, ctx->r2) = 0;
    // 0x801267A4: sh          $zero, 0x184($v0)
    MEM_H(0X184, ctx->r2) = 0;
    // 0x801267A8: sb          $zero, 0x186($v0)
    MEM_B(0X186, ctx->r2) = 0;
    // 0x801267AC: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
    // 0x801267B0: jr          $ra
    // 0x801267B4: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    return;
    // 0x801267B4: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801267b8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801267b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801267B8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801267BC: lbu         $t6, -0x2AB0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2AB0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801267c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801267c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801267C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801267C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801267C8: bne         $t6, $zero, L_801267D8
    if (ctx->r14 != 0) {
        // 0x801267CC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801267D8;
    }
    // 0x801267CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801267D0: jal         0x80125774
    // 0x801267D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80125774)(rdram, ctx);
        goto after_0;
    // 0x801267D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_801267D8:
    // 0x801267D8: jal         0x80125808
    // 0x801267DC: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_1;
    // 0x801267DC: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x801267E0: bne         $v0, $zero, L_801267F0
    if (ctx->r2 != 0) {
        // 0x801267E4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801267F0;
    }
    // 0x801267E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801267E8: b           L_80126810
    // 0x801267EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126810;
    // 0x801267EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801267F0:
    // 0x801267F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801267F4: bne         $v1, $at, L_80126804
    if (ctx->r3 != ctx->r1) {
        // 0x801267F8: nop
    
            goto L_80126804;
    }
    // 0x801267F8: nop

    // 0x801267FC: jal         0x80017594
    // 0x80126800: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80017594)(rdram, ctx);
        goto after_2;
    // 0x80126800: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_2:
L_80126804:
    // 0x80126804: jal         0x801257DC
    // 0x80126808: nop

    LOOKUP_FUNC(0x801257DC)(rdram, ctx);
        goto after_3;
    // 0x80126808: nop

    after_3:
    // 0x8012680C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80126810:
    // 0x80126810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80126814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126818: jr          $ra
    // 0x8012681C: nop

    return;
    // 0x8012681C: nop

;}
RECOMP_FUNC void M7_FUN_80126820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126820: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126824: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80126828: lbu         $t6, 0x182($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X182);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012682c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012682c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012682C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80126830: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80126834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8012683C: bne         $t6, $zero, L_80126854
    if (ctx->r14 != 0) {
        // 0x80126840: sh          $a1, 0x1114($v0)
        MEM_H(0X1114, ctx->r2) = ctx->r5;
            goto L_80126854;
    }
    // 0x80126840: sh          $a1, 0x1114($v0)
    MEM_H(0X1114, ctx->r2) = ctx->r5;
    // 0x80126844: lbu         $t7, 0x187($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X187);
    // 0x80126848: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8012684C: beql        $t7, $zero, L_80126860
    if (ctx->r15 == 0) {
        // 0x80126850: sb          $v1, 0x182($v0)
        MEM_B(0X182, ctx->r2) = ctx->r3;
            goto L_80126860;
    }
    goto skip_0;
    // 0x80126850: sb          $v1, 0x182($v0)
    MEM_B(0X182, ctx->r2) = ctx->r3;
    skip_0:
L_80126854:
    // 0x80126854: b           L_80126870
    // 0x80126858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126870;
    // 0x80126858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8012685C: sb          $v1, 0x182($v0)
    MEM_B(0X182, ctx->r2) = ctx->r3;
L_80126860:
    // 0x80126860: sb          $v1, 0x181($v0)
    MEM_B(0X181, ctx->r2) = ctx->r3;
    // 0x80126864: jal         0x801266B8
    // 0x80126868: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    LOOKUP_FUNC(0x801266B8)(rdram, ctx);
        goto after_0;
    // 0x80126868: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    after_0:
    // 0x8012686C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80126870:
    // 0x80126870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80126874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126878: jr          $ra
    // 0x8012687C: nop

    return;
    // 0x8012687C: nop

;}
RECOMP_FUNC void M7_FUN_80126880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126880: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126884: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126888: lbu         $t6, 0x182($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X182);
    // 0x8012688C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80126890: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126894: bne         $t6, $zero, L_801268B0
    if (ctx->r14 != 0) {
        // 0x80126898: nop
    
            goto L_801268B0;
    }
    // 0x80126898: nop

    // 0x8012689C: lbu         $t7, 0x187($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X187);
    // 0x801268A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801268A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801268A8: beql        $t7, $zero, L_801268BC
    if (ctx->r15 == 0) {
        // 0x801268AC: sb          $a1, 0x187($v1)
        MEM_B(0X187, ctx->r3) = ctx->r5;
            goto L_801268BC;
    }
    goto skip_0;
    // 0x801268AC: sb          $a1, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r5;
    skip_0:
L_801268B0:
    // 0x801268B0: jr          $ra
    // 0x801268B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801268B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801268B8: sb          $a1, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r5;
L_801268BC:
    // 0x801268BC: sb          $a1, 0x186($v1)
    MEM_B(0X186, ctx->r3) = ctx->r5;
    // 0x801268C0: sh          $a0, 0x184($v1)
    MEM_H(0X184, ctx->r3) = ctx->r4;
    // 0x801268C4: jr          $ra
    // 0x801268C8: nop

    return;
    // 0x801268C8: nop

;}
RECOMP_FUNC void M7_FUN_801268cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801268CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801268D0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801268D4: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x801268D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801268DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801268E0: beq         $a0, $zero, L_801268EC
    if (ctx->r4 == 0) {
        // 0x801268E4: sh          $t6, 0x3A2($v0)
        MEM_H(0X3A2, ctx->r2) = ctx->r14;
            goto L_801268EC;
    }
    // 0x801268E4: sh          $t6, 0x3A2($v0)
    MEM_H(0X3A2, ctx->r2) = ctx->r14;
    // 0x801268E8: sh          $a0, 0x3A2($v0)
    MEM_H(0X3A2, ctx->r2) = ctx->r4;
L_801268EC:
    // 0x801268EC: jr          $ra
    // 0x801268F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801268F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801268f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801268f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801268F4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801268F8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801268FC: lhu         $t6, 0x18E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X18E);
    // 0x80126900: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80126904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80126908: bne         $t6, $zero, L_80126924
    if (ctx->r14 != 0) {
            // 0x8012690C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80126924)(rdram, ctx);
    return;
    }
    // 0x8012690C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126910: sh          $a0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r4;
    // 0x80126914: sh          $a0, 0x190($v1)
    MEM_H(0X190, ctx->r3) = ctx->r4;
    // 0x80126918: sh          $a0, 0x192($v1)
    MEM_H(0X192, ctx->r3) = ctx->r4;
    // 0x8012691C: jr          $ra
    // 0x80126920: sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
    return;
    // 0x80126920: sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126924(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126928: jr          $ra
    // 0x8012692C: nop

    return;
    // 0x8012692C: nop

;}
RECOMP_FUNC void M7_FUN_80126930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126930: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80126934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80126938: sb          $a0, -0x4070($at)
    MEM_B(-0X4070, ctx->r1) = ctx->r4;
    // 0x8012693C: jr          $ra
    // 0x80126940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80126940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126944(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126944: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126948: jr          $ra
    // 0x8012694C: lbu         $v0, -0x4070($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4070);
    return;
    // 0x8012694C: lbu         $v0, -0x4070($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4070);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126950(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126950: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126954: jr          $ra
    // 0x80126958: lbu         $v0, -0x428E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X428E);
    return;
    // 0x80126958: lbu         $v0, -0x428E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X428E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8012695c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8012695c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8012695C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80126960: jr          $ra
    // 0x80126964: lbu         $v0, -0x4289($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4289);
    return;
    // 0x80126964: lbu         $v0, -0x4289($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4289);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126968(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8012696C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126970: jal         0x80020EA0
    // 0x80126974: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80020EA0)(rdram, ctx);
        goto after_0;
    // 0x80126974: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80126978: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012697C: sh          $v0, -0x4402($at)
    MEM_H(-0X4402, ctx->r1) = ctx->r2;
    // 0x80126980: jal         0x80020EA0
    // 0x80126984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020EA0)(rdram, ctx);
        goto after_1;
    // 0x80126984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80126988: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012698C: sh          $v0, -0x4400($at)
    MEM_H(-0X4400, ctx->r1) = ctx->r2;
    // 0x80126990: jal         0x80020EA0
    // 0x80126994: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80020EA0)(rdram, ctx);
        goto after_2;
    // 0x80126994: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80126998: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8012699C: sh          $v0, -0x43FE($at)
    MEM_H(-0X43FE, ctx->r1) = ctx->r2;
    // 0x801269A0: jal         0x80020EA0
    // 0x801269A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80020EA0)(rdram, ctx);
        goto after_3;
    // 0x801269A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x801269A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801269AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801269B0: sh          $v0, -0x43FC($at)
    MEM_H(-0X43FC, ctx->r1) = ctx->r2;
    // 0x801269B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801269B8: jr          $ra
    // 0x801269BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801269BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801269c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801269c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801269C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801269C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801269C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801269CC: jal         0x800208C4
    // 0x801269D0: lhu         $a0, -0x4402($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4402);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801269D0: lhu         $a0, -0x4402($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4402);
    after_0:
    // 0x801269D4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801269D8: jal         0x800208C4
    // 0x801269DC: lhu         $a0, -0x4400($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4400);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801269DC: lhu         $a0, -0x4400($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4400);
    after_1:
    // 0x801269E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801269E4: jal         0x800208C4
    // 0x801269E8: lhu         $a0, -0x43FE($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X43FE);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801269E8: lhu         $a0, -0x43FE($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X43FE);
    after_2:
    // 0x801269EC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801269F0: jal         0x800208C4
    // 0x801269F4: lhu         $a0, -0x43FC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X43FC);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_3;
    // 0x801269F4: lhu         $a0, -0x43FC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X43FC);
    after_3:
    // 0x801269F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801269FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126A04: jr          $ra
    // 0x80126A08: nop

    return;
    // 0x80126A08: nop

;}
RECOMP_FUNC void M7_FUN_80126a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126A0C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126A10: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126A14: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80126a18(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80126a18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80126A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80126A24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80126A28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80126A2C: beq         $v0, $zero, L_80126A48
    if (ctx->r2 == 0) {
        // 0x80126A30: andi        $a3, $a2, 0xFF
        ctx->r7 = ctx->r6 & 0XFF;
            goto L_80126A48;
    }
    // 0x80126A30: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
    // 0x80126A34: beql        $a0, $v0, L_80126A48
    if (ctx->r4 == ctx->r2) {
        // 0x80126A38: sw          $zero, 0x188($v1)
        MEM_W(0X188, ctx->r3) = 0;
            goto L_80126A48;
    }
    goto skip_0;
    // 0x80126A38: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    skip_0:
    // 0x80126A3C: b           L_80126B04
    // 0x80126A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126B04;
    // 0x80126A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126A44: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
L_80126A48:
    // 0x80126A48: lbu         $t7, 0x181($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X181);
    // 0x80126A4C: beq         $t7, $zero, L_80126A5C
    if (ctx->r15 == 0) {
        // 0x80126A50: nop
    
            goto L_80126A5C;
    }
    // 0x80126A50: nop

    // 0x80126A54: b           L_80126B04
    // 0x80126A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126B04;
    // 0x80126A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126A5C:
    // 0x80126A5C: beq         $a3, $zero, L_80126A8C
    if (ctx->r7 == 0) {
        // 0x80126A60: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_80126A8C;
    }
    // 0x80126A60: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80126A64: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80126A68: addiu       $a2, $a2, -0x6D50
    ctx->r6 = ADD32(ctx->r6, -0X6D50);
    // 0x80126A6C: lw          $t8, 0x42D0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X42D0);
    // 0x80126A70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80126A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126A78: sltiu       $at, $t8, 0x3001
    ctx->r1 = ctx->r24 < 0X3001 ? 1 : 0;
    // 0x80126A7C: bne         $at, $zero, L_80126AB0
    if (ctx->r1 != 0) {
        // 0x80126A80: nop
    
            goto L_80126AB0;
    }
    // 0x80126A80: nop

    // 0x80126A84: b           L_80126B04
    // 0x80126A88: sb          $t9, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r25;
        goto L_80126B04;
    // 0x80126A88: sb          $t9, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r25;
L_80126A8C:
    // 0x80126A8C: addiu       $a2, $a2, -0x6D50
    ctx->r6 = ADD32(ctx->r6, -0X6D50);
    // 0x80126A90: lw          $t0, 0x42D0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X42D0);
    // 0x80126A94: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80126A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126A9C: sltiu       $at, $t0, 0x3001
    ctx->r1 = ctx->r8 < 0X3001 ? 1 : 0;
    // 0x80126AA0: bne         $at, $zero, L_80126AB0
    if (ctx->r1 != 0) {
        // 0x80126AA4: nop
    
            goto L_80126AB0;
    }
    // 0x80126AA4: nop

    // 0x80126AA8: b           L_80126B04
    // 0x80126AAC: sb          $t1, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r9;
        goto L_80126B04;
    // 0x80126AAC: sb          $t1, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r9;
L_80126AB0:
    // 0x80126AB0: beq         $a3, $zero, L_80126AC0
    if (ctx->r7 == 0) {
        // 0x80126AB4: addiu       $a1, $zero, 0x3000
        ctx->r5 = ADD32(0, 0X3000);
            goto L_80126AC0;
    }
    // 0x80126AB4: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    // 0x80126AB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80126ABC: sb          $t2, 0x42FF($a2)
    MEM_B(0X42FF, ctx->r6) = ctx->r10;
L_80126AC0:
    // 0x80126AC0: jal         0x801267B8
    // 0x80126AC4: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_0;
    // 0x80126AC4: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    after_0:
    // 0x80126AC8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126ACC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80126AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80126AD4: addiu       $a2, $a2, -0x6D50
    ctx->r6 = ADD32(ctx->r6, -0X6D50);
    // 0x80126AD8: beq         $v0, $at, L_80126AFC
    if (ctx->r2 == ctx->r1) {
        // 0x80126ADC: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_80126AFC;
    }
    // 0x80126ADC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126AE0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80126AE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80126AE8: sb          $t3, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r11;
    // 0x80126AEC: sb          $zero, 0x42FF($a2)
    MEM_B(0X42FF, ctx->r6) = 0;
    // 0x80126AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126AF4: b           L_80126B04
    // 0x80126AF8: sw          $t4, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r12;
        goto L_80126B04;
    // 0x80126AF8: sw          $t4, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r12;
L_80126AFC:
    // 0x80126AFC: sb          $zero, 0x42FF($a2)
    MEM_B(0X42FF, ctx->r6) = 0;
    // 0x80126B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80126B04:
    // 0x80126B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80126B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126B0C: jr          $ra
    // 0x80126B10: nop

    return;
    // 0x80126B10: nop

;}
RECOMP_FUNC void M7_FUN_80126b14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126B14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80126B18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80126B1C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80126B20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80126B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80126B28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80126B2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80126B30: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126B34: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126B38: sh          $a3, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r7;
    // 0x80126B3C: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // 0x80126B40: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80126B44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80126B48: beql        $v0, $zero, L_80126B68
    if (ctx->r2 == 0) {
        // 0x80126B4C: lhu         $t6, 0x36($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X36);
            goto L_80126B68;
    }
    goto skip_0;
    // 0x80126B4C: lhu         $t6, 0x36($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X36);
    skip_0:
    // 0x80126B50: beql        $a0, $v0, L_80126B64
    if (ctx->r4 == ctx->r2) {
        // 0x80126B54: sw          $zero, 0x188($v1)
        MEM_W(0X188, ctx->r3) = 0;
            goto L_80126B64;
    }
    goto skip_1;
    // 0x80126B54: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    skip_1:
    // 0x80126B58: b           L_80126CAC
    // 0x80126B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126CAC;
    // 0x80126B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126B60: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
L_80126B64:
    // 0x80126B64: lhu         $t6, 0x36($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X36);
L_80126B68:
    // 0x80126B68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80126B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126B70: bnel        $t6, $zero, L_80126B94
    if (ctx->r14 != 0) {
        // 0x80126B74: lbu         $t0, 0x181($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X181);
            goto L_80126B94;
    }
    goto skip_2;
    // 0x80126B74: lbu         $t0, 0x181($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X181);
    skip_2:
    // 0x80126B78: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80126B7C: sw          $t7, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r15;
    // 0x80126B80: sh          $a2, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r6;
    // 0x80126B84: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x80126B88: b           L_80126CAC
    // 0x80126B8C: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
        goto L_80126CAC;
    // 0x80126B8C: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80126B90: lbu         $t0, 0x181($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X181);
L_80126B94:
    // 0x80126B94: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80126B98: beq         $t0, $zero, L_80126BA8
    if (ctx->r8 == 0) {
        // 0x80126B9C: nop
    
            goto L_80126BA8;
    }
    // 0x80126B9C: nop

    // 0x80126BA0: b           L_80126CAC
    // 0x80126BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126CAC;
    // 0x80126BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126BA8:
    // 0x80126BA8: lw          $t1, -0x2A80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2A80);
    // 0x80126BAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80126BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126BB4: sltiu       $at, $t1, 0x3001
    ctx->r1 = ctx->r9 < 0X3001 ? 1 : 0;
    // 0x80126BB8: bnel        $at, $zero, L_80126BCC
    if (ctx->r1 != 0) {
        // 0x80126BBC: lw          $t3, 0x8C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X8C);
            goto L_80126BCC;
    }
    goto skip_3;
    // 0x80126BBC: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
    skip_3:
    // 0x80126BC0: b           L_80126CAC
    // 0x80126BC4: sb          $t2, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r10;
        goto L_80126CAC;
    // 0x80126BC4: sb          $t2, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r10;
    // 0x80126BC8: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
L_80126BCC:
    // 0x80126BCC: sh          $a2, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r6;
    // 0x80126BD0: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x80126BD4: bne         $t3, $zero, L_80126C38
    if (ctx->r11 != 0) {
        // 0x80126BD8: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_80126C38;
    }
    // 0x80126BD8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80126BDC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80126BE0: lw          $t5, 0x1CEC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1CEC);
    // 0x80126BE4: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126BE8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126BEC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80126BF0: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    // 0x80126BF4: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80126BF8: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126BFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126C00: beql        $a0, $zero, L_80126C3C
    if (ctx->r4 == 0) {
        // 0x80126C04: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80126C3C;
    }
    goto skip_4;
    // 0x80126C04: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80126C08: jal         0x801267B8
    // 0x80126C0C: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_0;
    // 0x80126C0C: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    after_0:
    // 0x80126C10: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126C14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80126C18: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126C1C: beq         $v0, $at, L_80126C38
    if (ctx->r2 == ctx->r1) {
        // 0x80126C20: lhu         $a3, 0x2E($sp)
        ctx->r7 = MEM_HU(ctx->r29, 0X2E);
            goto L_80126C38;
    }
    // 0x80126C20: lhu         $a3, 0x2E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X2E);
    // 0x80126C24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80126C28: sb          $t7, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r15;
    // 0x80126C2C: sw          $s0, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r16;
    // 0x80126C30: b           L_80126CAC
    // 0x80126C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126CAC;
    // 0x80126C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126C38:
    // 0x80126C38: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80126C3C:
    // 0x80126C3C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80126C40: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80126C44: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80126C48: sw          $t8, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r24;
    // 0x80126C4C: lw          $t0, 0x1CEC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1CEC);
    // 0x80126C50: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126C54: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126C58: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80126C5C: lhu         $a0, 0x2($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2);
    // 0x80126C60: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126C64: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126C68: beql        $a0, $zero, L_80126CA0
    if (ctx->r4 == 0) {
        // 0x80126C6C: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_80126CA0;
    }
    goto skip_5;
    // 0x80126C6C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_5:
    // 0x80126C70: jal         0x801267B8
    // 0x80126C74: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_1;
    // 0x80126C74: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    after_1:
    // 0x80126C78: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80126C80: beq         $v0, $at, L_80126C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80126C84: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_80126C9C;
    }
    // 0x80126C84: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126C88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80126C8C: sb          $t2, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r10;
    // 0x80126C90: sw          $s0, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r16;
    // 0x80126C94: b           L_80126CAC
    // 0x80126C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126CAC;
    // 0x80126C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126C9C:
    // 0x80126C9C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
L_80126CA0:
    // 0x80126CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126CA4: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x80126CA8: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
L_80126CAC:
    // 0x80126CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80126CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80126CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80126CB8: jr          $ra
    // 0x80126CBC: nop

    return;
    // 0x80126CBC: nop

;}
RECOMP_FUNC void M7_FUN_80126cc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80126CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126CC8: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80126CCC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126CD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80126CD4: lhu         $t7, 0x1E($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1E);
    // 0x80126CD8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80126CDC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126CE0: bnel        $t7, $zero, L_80126CF4
    if (ctx->r15 != 0) {
        // 0x80126CE4: lw          $v0, 0x188($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X188);
            goto L_80126CF4;
    }
    goto skip_0;
    // 0x80126CE4: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    skip_0:
    // 0x80126CE8: b           L_80126E78
    // 0x80126CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80126E78;
    // 0x80126CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126CF0: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
L_80126CF4:
    // 0x80126CF4: beql        $v0, $zero, L_80126D14
    if (ctx->r2 == 0) {
        // 0x80126CF8: lhu         $t8, 0x36($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X36);
            goto L_80126D14;
    }
    goto skip_1;
    // 0x80126CF8: lhu         $t8, 0x36($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X36);
    skip_1:
    // 0x80126CFC: beql        $a2, $v0, L_80126D10
    if (ctx->r6 == ctx->r2) {
        // 0x80126D00: sw          $zero, 0x188($v1)
        MEM_W(0X188, ctx->r3) = 0;
            goto L_80126D10;
    }
    goto skip_2;
    // 0x80126D00: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    skip_2:
    // 0x80126D04: b           L_80126E78
    // 0x80126D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126E78;
    // 0x80126D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126D0C: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
L_80126D10:
    // 0x80126D10: lhu         $t8, 0x36($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X36);
L_80126D14:
    // 0x80126D14: bnel        $t8, $zero, L_80126D44
    if (ctx->r24 != 0) {
        // 0x80126D18: lbu         $t3, 0x181($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X181);
            goto L_80126D44;
    }
    goto skip_3;
    // 0x80126D18: lbu         $t3, 0x181($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X181);
    skip_3:
    // 0x80126D1C: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    // 0x80126D20: lw          $t1, 0x38($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X38);
    // 0x80126D24: sw          $a3, 0x8C($a2)
    MEM_W(0X8C, ctx->r6) = ctx->r7;
    // 0x80126D28: ori         $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 | 0X8000;
    // 0x80126D2C: sw          $t0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r8;
    // 0x80126D30: lhu         $t2, 0x1E($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1E);
    // 0x80126D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126D38: b           L_80126E78
    // 0x80126D3C: sh          $t2, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r10;
        goto L_80126E78;
    // 0x80126D3C: sh          $t2, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r10;
    // 0x80126D40: lbu         $t3, 0x181($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X181);
L_80126D44:
    // 0x80126D44: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80126D48: beq         $t3, $zero, L_80126D58
    if (ctx->r11 == 0) {
        // 0x80126D4C: nop
    
            goto L_80126D58;
    }
    // 0x80126D4C: nop

    // 0x80126D50: b           L_80126E78
    // 0x80126D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126E78;
    // 0x80126D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126D58:
    // 0x80126D58: lw          $t4, -0x2A80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2A80);
    // 0x80126D5C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80126D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80126D64: sltiu       $at, $t4, 0x3001
    ctx->r1 = ctx->r12 < 0X3001 ? 1 : 0;
    // 0x80126D68: bnel        $at, $zero, L_80126D7C
    if (ctx->r1 != 0) {
        // 0x80126D6C: lw          $t6, 0x38($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X38);
            goto L_80126D7C;
    }
    goto skip_4;
    // 0x80126D6C: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    skip_4:
    // 0x80126D70: b           L_80126E78
    // 0x80126D74: sb          $t5, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r13;
        goto L_80126E78;
    // 0x80126D74: sb          $t5, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r13;
    // 0x80126D78: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
L_80126D7C:
    // 0x80126D7C: lw          $t8, 0x8C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8C);
    // 0x80126D80: lhu         $t7, 0x1E($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1E);
    // 0x80126D84: bne         $t8, $zero, L_80126DFC
    if (ctx->r24 != 0) {
        // 0x80126D88: sh          $t7, 0x72($a2)
        MEM_H(0X72, ctx->r6) = ctx->r15;
            goto L_80126DFC;
    }
    // 0x80126D88: sh          $t7, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r15;
    // 0x80126D8C: lhu         $t9, 0x36($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X36);
    // 0x80126D90: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80126D94: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126D98: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80126D9C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80126DA0: lw          $t1, 0x1CEC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1CEC);
    // 0x80126DA4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126DA8: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    // 0x80126DAC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80126DB0: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x80126DB4: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126DB8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126DBC: beql        $a0, $zero, L_80126E00
    if (ctx->r4 == 0) {
        // 0x80126DC0: lhu         $t4, 0x36($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X36);
            goto L_80126E00;
    }
    goto skip_5;
    // 0x80126DC0: lhu         $t4, 0x36($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X36);
    skip_5:
    // 0x80126DC4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80126DC8: jal         0x801267B8
    // 0x80126DCC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_0;
    // 0x80126DCC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80126DD0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126DD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80126DD8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126DDC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80126DE0: beq         $v0, $at, L_80126DFC
    if (ctx->r2 == ctx->r1) {
        // 0x80126DE4: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80126DFC;
    }
    // 0x80126DE4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80126DE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80126DEC: sb          $t3, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r11;
    // 0x80126DF0: sw          $a2, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r6;
    // 0x80126DF4: b           L_80126E78
    // 0x80126DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126E78;
    // 0x80126DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126DFC:
    // 0x80126DFC: lhu         $t4, 0x36($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X36);
L_80126E00:
    // 0x80126E00: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80126E04: sw          $a3, 0x8C($a2)
    MEM_W(0X8C, ctx->r6) = ctx->r7;
    // 0x80126E08: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80126E0C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80126E10: lw          $t6, 0x1CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1CEC);
    // 0x80126E14: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126E18: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126E1C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80126E20: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    // 0x80126E24: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    // 0x80126E28: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126E2C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126E30: beql        $a0, $zero, L_80126E6C
    if (ctx->r4 == 0) {
        // 0x80126E34: lw          $t9, 0x2C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X2C);
            goto L_80126E6C;
    }
    goto skip_6;
    // 0x80126E34: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    skip_6:
    // 0x80126E38: jal         0x801267B8
    // 0x80126E3C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801267B8)(rdram, ctx);
        goto after_1;
    // 0x80126E3C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80126E40: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80126E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80126E48: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80126E4C: beq         $v0, $at, L_80126E68
    if (ctx->r2 == ctx->r1) {
        // 0x80126E50: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80126E68;
    }
    // 0x80126E50: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80126E54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80126E58: sb          $t8, 0x181($v1)
    MEM_B(0X181, ctx->r3) = ctx->r24;
    // 0x80126E5C: sw          $a2, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r6;
    // 0x80126E60: b           L_80126E78
    // 0x80126E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80126E78;
    // 0x80126E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80126E68:
    // 0x80126E68: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
L_80126E6C:
    // 0x80126E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80126E70: ori         $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 | 0X8000;
    // 0x80126E74: sw          $t0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r8;
L_80126E78:
    // 0x80126E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80126E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126E80: jr          $ra
    // 0x80126E84: nop

    return;
    // 0x80126E84: nop

;}
RECOMP_FUNC void M7_FUN_80126e88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80126E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126E90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80126E94: jal         0x8001769C
    // 0x80126E98: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8001769C)(rdram, ctx);
        goto after_0;
    // 0x80126E98: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80126E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80126EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80126EA4: jr          $ra
    // 0x80126EA8: nop

    return;
    // 0x80126EA8: nop

;}
RECOMP_FUNC void M7_FUN_80126eac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126EAC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80126EB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80126EB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80126EB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80126EBC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80126EC0: sb          $t6, -0x428A($at)
    MEM_B(-0X428A, ctx->r1) = ctx->r14;
    // 0x80126EC4: lhu         $t7, 0x36($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X36);
    // 0x80126EC8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80126ECC: jal         0x80005700
    // 0x80126ED0: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80126ED0: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80126ED4: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x80126ED8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80126EDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80126EE0: beq         $t8, $zero, L_80126F3C
    if (ctx->r24 == 0) {
        // 0x80126EE4: addiu       $t9, $t9, 0x4E80
        ctx->r25 = ADD32(ctx->r25, 0X4E80);
            goto L_80126F3C;
    }
    // 0x80126EE4: addiu       $t9, $t9, 0x4E80
    ctx->r25 = ADD32(ctx->r25, 0X4E80);
    // 0x80126EE8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80126EEC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80126EF0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80126EF4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80126EF8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80126EFC: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80126F00: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80126F04: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80126F08: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x80126F0C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80126F10: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80126F14: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80126F18: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80126F1C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80126F20: jal         0x8012C4D0
    // 0x80126F24: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x80126F24: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
    // 0x80126F28: beq         $v0, $zero, L_80126F3C
    if (ctx->r2 == 0) {
        // 0x80126F2C: lhu         $t3, 0x2A($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X2A);
            goto L_80126F3C;
    }
    // 0x80126F2C: lhu         $t3, 0x2A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2A);
    // 0x80126F30: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80126F34: sh          $t3, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r11;
    // 0x80126F38: sh          $t4, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r12;
L_80126F3C:
    // 0x80126F3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80126F40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80126F44: jr          $ra
    // 0x80126F48: nop

    return;
    // 0x80126F48: nop

;}
RECOMP_FUNC void M7_FUN_80126f4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80126F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80126F50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80126F54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80126F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80126F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80126F60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80126F64: sb          $t6, -0x428A($at)
    MEM_B(-0X428A, ctx->r1) = ctx->r14;
    // 0x80126F68: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x80126F6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80126F70: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80126F74: bne         $v0, $zero, L_80127004
    if (ctx->r2 != 0) {
        // 0x80126F78: sh          $t7, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r15;
            goto L_80127004;
    }
    // 0x80126F78: sh          $t7, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r15;
    // 0x80126F7C: lhu         $t8, 0x36($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X36);
    // 0x80126F80: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80126F84: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126F88: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80126F8C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80126F90: lw          $t0, 0x1CEC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1CEC);
    // 0x80126F94: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126F98: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80126F9C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80126FA0: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126FA4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126FA8: beql        $a0, $zero, L_80126FD8
    if (ctx->r4 == 0) {
        // 0x80126FAC: lhu         $a0, 0x2($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X2);
            goto L_80126FD8;
    }
    goto skip_0;
    // 0x80126FAC: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    skip_0:
    // 0x80126FB0: jal         0x80126E88
    // 0x80126FB4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x80126FB4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80126FB8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80126FBC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80126FC0: lhu         $t1, 0x36($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X36);
    // 0x80126FC4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80126FC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80126FCC: lw          $t3, 0x1CEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1CEC);
    // 0x80126FD0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80126FD4: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
L_80126FD8:
    // 0x80126FD8: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x80126FDC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80126FE0: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80126FE4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80126FE8: beq         $a0, $zero, L_80126FFC
    if (ctx->r4 == 0) {
        // 0x80126FEC: nop
    
            goto L_80126FFC;
    }
    // 0x80126FEC: nop

    // 0x80126FF0: jal         0x80126E88
    // 0x80126FF4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x80126FF4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80126FF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80126FFC:
    // 0x80126FFC: jal         0x80005700
    // 0x80127000: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80127000: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_80127004:
    // 0x80127004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80127008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8012700C: jr          $ra
    // 0x80127010: nop

    return;
    // 0x80127010: nop

;}
RECOMP_FUNC void M7_FUN_80127014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127014: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80127018: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8012701C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80127020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80127024: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80127028: sb          $t6, -0x428A($at)
    MEM_B(-0X428A, ctx->r1) = ctx->r14;
    // 0x8012702C: lhu         $t7, 0x36($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X36);
    // 0x80127030: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80127034: jal         0x8013B208
    // 0x80127038: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8013B208)(rdram, ctx);
        goto after_0;
    // 0x80127038: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x8012703C: jal         0x80005700
    // 0x80127040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80127040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80127044: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x80127048: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8012704C: addiu       $t9, $t9, 0x4E80
    ctx->r25 = ADD32(ctx->r25, 0X4E80);
    // 0x80127050: beql        $t8, $zero, L_801270B4
    if (ctx->r24 == 0) {
        // 0x80127054: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801270B4;
    }
    goto skip_0;
    // 0x80127054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80127058: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8012705C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80127060: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80127064: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80127068: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8012706C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80127070: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80127074: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80127078: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8012707C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x80127080: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80127084: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80127088: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8012708C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80127090: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80127094: jal         0x8012C4D0
    // 0x80127098: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_2;
    // 0x80127098: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x8012709C: beq         $v0, $zero, L_801270B0
    if (ctx->r2 == 0) {
        // 0x801270A0: lhu         $t3, 0x2A($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X2A);
            goto L_801270B0;
    }
    // 0x801270A0: lhu         $t3, 0x2A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2A);
    // 0x801270A4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801270A8: sh          $t3, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r11;
    // 0x801270AC: sh          $t4, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r12;
L_801270B0:
    // 0x801270B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801270B4:
    // 0x801270B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801270B8: jr          $ra
    // 0x801270BC: nop

    return;
    // 0x801270BC: nop

;}
RECOMP_FUNC void M7_FUN_801270c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801270C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801270C4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801270C8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801270CC: jal         0x801FBB20
    // 0x801270D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_0;
    // 0x801270D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x801270D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801270D8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801270DC: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x801270E0: sb          $zero, 0x1031($v0)
    MEM_B(0X1031, ctx->r2) = 0;
    // 0x801270E4: addiu       $a1, $a1, -0x3DB0
    ctx->r5 = ADD32(ctx->r5, -0X3DB0);
    // 0x801270E8: jal         0x80005670
    // 0x801270EC: lw          $a0, 0x58($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X58);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801270EC: lw          $a0, 0x58($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X58);
    after_1:
    // 0x801270F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801270F4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801270F8: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801270FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80127100: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80127104: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80127108: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8012710C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80127110: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80127114: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80127118: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8012711C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80127120: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80127124: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80127128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8012712C: addiu       $a0, $a0, -0x38CC
    ctx->r4 = ADD32(ctx->r4, -0X38CC);
    // 0x80127130: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80127134: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80127138: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8012713C: addiu       $a1, $zero, 0x674
    ctx->r5 = ADD32(0, 0X674);
    // 0x80127140: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80127144: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80127148: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8012714C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80127150: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80127154: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80127158: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8012715C: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80127160: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80127164: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80127168: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8012716C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80127170: jal         0x8011AAF4
    // 0x80127174: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x80127174: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80127178: lw          $t2, 0x54($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X54);
    // 0x8012717C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80127180: ori         $t0, $zero, 0x83E0
    ctx->r8 = 0 | 0X83E0;
    // 0x80127184: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80127188: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8012718C: ori         $t3, $t2, 0xE1
    ctx->r11 = ctx->r10 | 0XE1;
    // 0x80127190: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x80127194: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x80127198: sb          $t1, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r9;
    // 0x8012719C: sb          $v0, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r2;
    // 0x801271A0: sb          $zero, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = 0;
    // 0x801271A4: sw          $t3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r11;
    // 0x801271A8: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    // 0x801271AC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801271B0: jal         0x800058DC
    // 0x801271B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801271B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801271B8: jal         0x801C3B10
    // 0x801271BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B10)(rdram, ctx);
        goto after_4;
    // 0x801271BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801271C0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801271C4: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    // 0x801271C8: jal         0x800058DC
    // 0x801271CC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801271CC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x801271D0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801271D4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801271D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801271DC: jr          $ra
    // 0x801271E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801271E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801271e4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801271e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801271E4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801271E8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801271EC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801271F0: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801271F4: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x801271F8: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801271FC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80127200: bne         $t6, $at, L_80127290
    if (ctx->r14 != ctx->r1) {
        // 0x80127204: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80127290;
    }
    // 0x80127204: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80127208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8012720C: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x80127210: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80127214: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80127218: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8012721C: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x80127220: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80127224: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80127228: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8012722C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80127230: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80127234: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80127238: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8012723C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80127240: addiu       $a0, $a0, -0x3864
    ctx->r4 = ADD32(ctx->r4, -0X3864);
    // 0x80127244: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80127248: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8012724C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80127250: addiu       $a1, $zero, 0x69A
    ctx->r5 = ADD32(0, 0X69A);
    // 0x80127254: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80127258: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8012725C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80127260: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80127264: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80127268: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8012726C: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80127270: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80127274: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80127278: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8012727C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80127280: jal         0x8011AAF4
    // 0x80127284: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80127284: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80127288: b           L_80127314
    // 0x8012728C: lw          $t5, 0xEFC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEFC);
        goto L_80127314;
    // 0x8012728C: lw          $t5, 0xEFC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEFC);
L_80127290:
    // 0x80127290: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80127294: lw          $t2, 0xE8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE8);
    // 0x80127298: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8012729C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801272A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801272A4: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801272A8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801272AC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801272B0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801272B4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801272B8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801272BC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801272C0: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801272C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801272C8: addiu       $a0, $a0, -0x382C
    ctx->r4 = ADD32(ctx->r4, -0X382C);
    // 0x801272CC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801272D0: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801272D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801272D8: addiu       $a1, $zero, 0x69C
    ctx->r5 = ADD32(0, 0X69C);
    // 0x801272DC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801272E0: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801272E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801272E8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801272EC: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801272F0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801272F4: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801272F8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801272FC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80127300: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80127304: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80127308: jal         0x8011AAF4
    // 0x8012730C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x8012730C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80127310: lw          $t5, 0xEFC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEFC);
L_80127314:
    // 0x80127314: lw          $t6, 0xDC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XDC);
    // 0x80127318: sb          $zero, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = 0;
    // 0x8012731C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80127320: sw          $t5, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->r13;
    // 0x80127324: jal         0x801C4A5C
    // 0x80127328: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_2;
    // 0x80127328: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    after_2:
    // 0x8012732C: lw          $t8, 0xDC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDC);
    // 0x80127330: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80127334: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80127338: sb          $t7, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r15;
    // 0x8012733C: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    // 0x80127340: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80127344: addiu       $a1, $a1, 0x7374
    ctx->r5 = ADD32(ctx->r5, 0X7374);
    // 0x80127348: lbu         $t9, 0x4E($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4E);
    // 0x8012734C: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
    // 0x80127350: lw          $t1, 0xDC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XDC);
    // 0x80127354: sb          $t0, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r8;
    // 0x80127358: jal         0x800058DC
    // 0x8012735C: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8012735C: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    after_3:
    // 0x80127360: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80127364: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80127368: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8012736C: jr          $ra
    // 0x80127370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80127370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80127374(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80127374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80127378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012737C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80127380: jal         0x80126944
    // 0x80127384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x80127384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80127388: bne         $v0, $zero, L_80127420
    if (ctx->r2 != 0) {
        // 0x8012738C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80127420;
    }
    // 0x8012738C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80127390: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80127394: lhu         $v1, 0x3A4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3A4);
    // 0x80127398: beql        $v1, $zero, L_801273B4
    if (ctx->r3 == 0) {
        // 0x8012739C: lhu         $v1, 0x3A2($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X3A2);
            goto L_801273B4;
    }
    goto skip_0;
    // 0x8012739C: lhu         $v1, 0x3A2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3A2);
    skip_0:
    // 0x801273A0: jal         0x80133980
    // 0x801273A4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x801273A4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_1:
    // 0x801273A8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801273AC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801273B0: lhu         $v1, 0x3A2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3A2);
L_801273B4:
    // 0x801273B4: sh          $zero, 0x3A4($v0)
    MEM_H(0X3A4, ctx->r2) = 0;
    // 0x801273B8: beql        $v1, $zero, L_801273C8
    if (ctx->r3 == 0) {
        // 0x801273BC: lhu         $t6, 0xEF0($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0XEF0);
            goto L_801273C8;
    }
    goto skip_1;
    // 0x801273BC: lhu         $t6, 0xEF0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XEF0);
    skip_1:
    // 0x801273C0: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x801273C4: lhu         $t6, 0xEF0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XEF0);
L_801273C8:
    // 0x801273C8: lw          $a1, 0xF8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XF8);
    // 0x801273CC: sh          $zero, 0x3A2($v0)
    MEM_H(0X3A2, ctx->r2) = 0;
    // 0x801273D0: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x801273D4: bne         $a1, $zero, L_8012740C
    if (ctx->r5 != 0) {
        // 0x801273D8: sh          $t7, 0xEF0($v0)
        MEM_H(0XEF0, ctx->r2) = ctx->r15;
            goto L_8012740C;
    }
    // 0x801273D8: sh          $t7, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r15;
    // 0x801273DC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801273E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801273E4: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x801273E8: ori         $t9, $t8, 0xE0
    ctx->r25 = ctx->r24 | 0XE0;
    // 0x801273EC: jal         0x801C3B10
    // 0x801273F0: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x801C3B10)(rdram, ctx);
        goto after_2;
    // 0x801273F0: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    after_2:
    // 0x801273F4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801273F8: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801273FC: jal         0x800058DC
    // 0x80127400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80127400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80127404: b           L_80127424
    // 0x80127408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80127424;
    // 0x80127408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8012740C:
    // 0x8012740C: jal         0x800058DC
    // 0x80127410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80127410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80127414: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80127418: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8012741C: sw          $zero, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = 0;
L_80127420:
    // 0x80127420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80127424:
    // 0x80127424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80127428: jr          $ra
    // 0x8012742C: nop

    return;
    // 0x8012742C: nop

;}
RECOMP_FUNC void M7_FUN_80127430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127430: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80127434: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80127438: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x8012743C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80127440: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80127444: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80127448: beq         $t6, $zero, L_801276B8
    if (ctx->r14 == 0) {
        // 0x8012744C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_801276B8;
    }
    // 0x8012744C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80127450: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80127454: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x80127458: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012745C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80127460: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80127464: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80127468: lwc1        $f8, 0x34($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8012746C: lwc1        $f18, 0x38($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80127470: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80127474: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80127478: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8012747C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80127480: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80127484: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80127488: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8012748C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80127490: jal         0x8002FC20
    // 0x80127494: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80127494: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_0:
    // 0x80127498: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8012749C: lui         $at, 0x4035
    ctx->r1 = S32(0X4035 << 16);
    // 0x801274A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801274A4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801274A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801274AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801274B0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801274B4: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801274B8: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x801274BC: nop

    // 0x801274C0: bc1f        L_801274D0
    if (!c1cs) {
        // 0x801274C4: nop
    
            goto L_801274D0;
    }
    // 0x801274C4: nop

    // 0x801274C8: b           L_801274F4
    // 0x801274CC: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_801274F4;
    // 0x801274CC: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_801274D0:
    // 0x801274D0: ldc1        $f10, -0x3500($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3500);
    // 0x801274D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801274D8: ldc1        $f18, -0x34F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X34F8);
    // 0x801274DC: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801274E0: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x801274E4: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801274E8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x801274EC: nop

    // 0x801274F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_801274F4:
    // 0x801274F4: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801274F8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x801274FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80127500: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80127504: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80127508: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8012750C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80127510: bc1f        L_80127520
    if (!c1cs) {
        // 0x80127514: nop
    
            goto L_80127520;
    }
    // 0x80127514: nop

    // 0x80127518: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8012751C: nop

L_80127520:
    // 0x80127520: bgez        $v0, L_80127534
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80127524: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80127534;
    }
    // 0x80127524: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80127528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8012752C: nop

    // 0x80127530: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80127534:
    // 0x80127534: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80127538: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012753C: ldc1        $f18, -0x34F0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X34F0);
    // 0x80127540: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80127544: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80127548: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8012754C: nop

    // 0x80127550: bc1f        L_80127560
    if (!c1cs) {
        // 0x80127554: nop
    
            goto L_80127560;
    }
    // 0x80127554: nop

    // 0x80127558: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8012755C: nop

L_80127560:
    // 0x80127560: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x80127564: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80127568: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8012756C: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x80127570: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80127574: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80127578: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8012757C: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80127580: jal         0x8001EF38
    // 0x80127584: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x80127584: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    after_1:
    // 0x80127588: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8012758C: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x80127590: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x80127594: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80127598: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8012759C: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801275A0: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801275A4: sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // 0x801275A8: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801275AC: jal         0x8001EF38
    // 0x801275B0: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801275B0: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_2:
    // 0x801275B4: lh          $a0, 0x24($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X24);
    // 0x801275B8: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x801275BC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801275C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801275C4: andi        $t1, $v1, 0x1000
    ctx->r9 = ctx->r3 & 0X1000;
    // 0x801275C8: beq         $t1, $zero, L_801275E4
    if (ctx->r9 == 0) {
        // 0x801275CC: andi        $a0, $v1, 0x1FFF
        ctx->r4 = ctx->r3 & 0X1FFF;
            goto L_801275E4;
    }
    // 0x801275CC: andi        $a0, $v1, 0x1FFF
    ctx->r4 = ctx->r3 & 0X1FFF;
    // 0x801275D0: andi        $a0, $v1, 0x1FFF
    ctx->r4 = ctx->r3 & 0X1FFF;
    // 0x801275D4: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x801275D8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801275DC: b           L_801275EC
    // 0x801275E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_801275EC;
    // 0x801275E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801275E4:
    // 0x801275E4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801275E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801275EC:
    // 0x801275EC: jal         0x8001EAD0
    // 0x801275F0: nop

    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801275F0: nop

    after_3:
    // 0x801275F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801275F8: ldc1        $f10, -0x34E8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X34E8);
    // 0x801275FC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80127600: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x80127604: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80127608: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8012760C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80127610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80127614: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80127618: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x8012761C: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x80127620: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80127624: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80127628: nop

    // 0x8012762C: cvt.w.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_D(ctx->f6.d);
    // 0x80127630: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80127634: nop

    // 0x80127638: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8012763C: beql        $a1, $zero, L_80127690
    if (ctx->r5 == 0) {
        // 0x80127640: mfc1        $a1, $f18
        ctx->r5 = (int32_t)ctx->f18.u32l;
            goto L_80127690;
    }
    goto skip_0;
    // 0x80127640: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80127644: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80127648: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8012764C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80127650: sub.d       $f18, $f6, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f6.d - ctx->f18.d;
    // 0x80127654: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80127658: nop

    // 0x8012765C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80127660: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80127664: nop

    // 0x80127668: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8012766C: bne         $a1, $zero, L_80127684
    if (ctx->r5 != 0) {
        // 0x80127670: nop
    
            goto L_80127684;
    }
    // 0x80127670: nop

    // 0x80127674: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80127678: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8012767C: b           L_8012769C
    // 0x80127680: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8012769C;
    // 0x80127680: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80127684:
    // 0x80127684: b           L_8012769C
    // 0x80127688: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8012769C;
    // 0x80127688: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8012768C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
L_80127690:
    // 0x80127690: nop

    // 0x80127694: bltz        $a1, L_80127684
    if (SIGNED(ctx->r5) < 0) {
        // 0x80127698: nop
    
            goto L_80127684;
    }
    // 0x80127698: nop

L_8012769C:
    // 0x8012769C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801276A0: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801276A4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801276A8: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801276AC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801276B0: jal         0x800207D0
    // 0x801276B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_4;
    // 0x801276B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_4:
L_801276B8:
    // 0x801276B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801276BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801276C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801276C4: jr          $ra
    // 0x801276C8: nop

    return;
    // 0x801276C8: nop

;}
RECOMP_FUNC void M7_FUN_801276cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801276CC: andi        $a1, $a0, 0xFFF
    ctx->r5 = ctx->r4 & 0XFFF;
    // 0x801276D0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801276D4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801276D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801276DC: lw          $t7, 0x1CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1CEC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801276e0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801276e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801276E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801276E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801276E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801276EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801276F0: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x801276F4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801276F8: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x801276FC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80127700: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80127704: jal         0x80125808
    // 0x80127708: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_0;
    // 0x80127708: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8012770C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80127710: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80127714: beq         $v0, $at, L_8012772C
    if (ctx->r2 == ctx->r1) {
        // 0x80127718: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_8012772C;
    }
    // 0x80127718: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8012771C: beq         $v0, $at, L_8012772C
    if (ctx->r2 == ctx->r1) {
        // 0x80127720: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_8012772C;
    }
    // 0x80127720: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80127724: bnel        $v0, $at, L_80127740
    if (ctx->r2 != ctx->r1) {
        // 0x80127728: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_80127740;
    }
    goto skip_0;
    // 0x80127728: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    skip_0:
L_8012772C:
    // 0x8012772C: jal         0x80125808
    // 0x80127730: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_1;
    // 0x80127730: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    after_1:
    // 0x80127734: b           L_801277A4
    // 0x80127738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801277A4;
    // 0x80127738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012773C: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
L_80127740:
    // 0x80127740: beq         $v0, $at, L_80127750
    if (ctx->r2 == ctx->r1) {
        // 0x80127744: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_80127750;
    }
    // 0x80127744: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x80127748: bnel        $v0, $at, L_80127764
    if (ctx->r2 != ctx->r1) {
        // 0x8012774C: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_80127764;
    }
    goto skip_1;
    // 0x8012774C: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    skip_1:
L_80127750:
    // 0x80127750: jal         0x80125808
    // 0x80127754: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_2;
    // 0x80127754: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    after_2:
    // 0x80127758: b           L_801277A4
    // 0x8012775C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801277A4;
    // 0x8012775C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80127760: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
L_80127764:
    // 0x80127764: beq         $v0, $at, L_80127774
    if (ctx->r2 == ctx->r1) {
        // 0x80127768: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80127774;
    }
    // 0x80127768: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8012776C: bnel        $v0, $at, L_80127788
    if (ctx->r2 != ctx->r1) {
        // 0x80127770: addiu       $at, $zero, 0x141
        ctx->r1 = ADD32(0, 0X141);
            goto L_80127788;
    }
    goto skip_2;
    // 0x80127770: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    skip_2:
L_80127774:
    // 0x80127774: jal         0x80125808
    // 0x80127778: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_3;
    // 0x80127778: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    after_3:
    // 0x8012777C: b           L_801277A4
    // 0x80127780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801277A4;
    // 0x80127780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80127784: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
L_80127788:
    // 0x80127788: beq         $v0, $at, L_80127798
    if (ctx->r2 == ctx->r1) {
        // 0x8012778C: addiu       $at, $zero, 0x142
        ctx->r1 = ADD32(0, 0X142);
            goto L_80127798;
    }
    // 0x8012778C: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x80127790: bnel        $v0, $at, L_801277A4
    if (ctx->r2 != ctx->r1) {
        // 0x80127794: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801277A4;
    }
    goto skip_3;
    // 0x80127794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_80127798:
    // 0x80127798: jal         0x80125808
    // 0x8012779C: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80125808)(rdram, ctx);
        goto after_4;
    // 0x8012779C: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_4:
    // 0x801277A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801277A4:
    // 0x801277A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801277A8: jr          $ra
    // 0x801277AC: nop

    return;
    // 0x801277AC: nop

;}
RECOMP_FUNC void M7_FUN_801277b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801277B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801277B4: jr          $ra
    // 0x801277B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801277B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801277bc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801277bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801277BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801277C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801277C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801277C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801277CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801277D0: jal         0x80005F6C
    // 0x801277D4: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x801277D4: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    after_0:
    // 0x801277D8: jal         0x80006214
    // 0x801277DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801277DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801277E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801277E4: addiu       $a1, $a1, 0x7918
    ctx->r5 = ADD32(ctx->r5, 0X7918);
    // 0x801277E8: jal         0x800058DC
    // 0x801277EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801277EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801277F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801277F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801277F8: jr          $ra
    // 0x801277FC: nop

    return;
    // 0x801277FC: nop

;}
RECOMP_FUNC void M7_FUN_80127800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80127804: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80127808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8012780C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80127810: addiu       $a1, $a1, 0x4F30
    ctx->r5 = ADD32(ctx->r5, 0X4F30);
    // 0x80127814: jal         0x80005F6C
    // 0x80127818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x80127818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8012781C: jal         0x80006214
    // 0x80127820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80127820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80127824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80127828: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8012782C: lwc1        $f0, -0x33F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33F0);
    // 0x80127830: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80127834: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80127838: addiu       $t6, $zero, 0x73
    ctx->r14 = ADD32(0, 0X73);
    // 0x8012783C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80127840: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x80127844: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80127848: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8012784C: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80127850: addiu       $t9, $t9, 0x210
    ctx->r25 = ADD32(ctx->r25, 0X210);
    // 0x80127854: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80127858: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8012785C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80127860: addiu       $a1, $a1, 0x7918
    ctx->r5 = ADD32(ctx->r5, 0X7918);
    // 0x80127864: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    // 0x80127868: lh          $t2, 0x112($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X112);
    // 0x8012786C: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x80127870: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80127874: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80127878: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8012787C: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80127880: lh          $t5, 0x114($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X114);
    // 0x80127884: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80127888: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8012788C: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x80127890: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80127894: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x80127898: lh          $t8, 0x116($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X116);
    // 0x8012789C: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x801278A0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801278A4: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x801278A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801278AC: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x801278B0: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x801278B4: lh          $t1, 0x118($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X118);
    // 0x801278B8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801278BC: sh          $t1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r9;
    // 0x801278C0: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x801278C4: lh          $t4, 0x11A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X11A);
    // 0x801278C8: lw          $t7, 0x2C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X2C);
    // 0x801278CC: sh          $t4, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r12;
    // 0x801278D0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801278D4: lh          $t6, 0x11C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X11C);
    // 0x801278D8: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801278DC: sh          $t6, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r14;
    // 0x801278E0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801278E4: lw          $t2, 0x2C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X2C);
    // 0x801278E8: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x801278EC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801278F0: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801278F4: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x801278F8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801278FC: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x80127900: jal         0x800058DC
    // 0x80127904: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80127904: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    after_2:
    // 0x80127908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8012790C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80127910: jr          $ra
    // 0x80127914: nop

    return;
    // 0x80127914: nop

;}
RECOMP_FUNC void M7_FUN_80127918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80127918: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8012791C: jr          $ra
    // 0x80127920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80127920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80127924(rdram, ctx);
;}
