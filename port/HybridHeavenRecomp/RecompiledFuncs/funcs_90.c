#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801feae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEAE0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801FEAE4: lbu         $t0, 0x7B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7B);
    // 0x801FEAE8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x801FEAEC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x801FEAF0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801FEAF4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FEAF8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FEAFC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801FEB00: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x801FEB04: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x801FEB08: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801FEB0C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801FEB10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FEB14: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801FEB18: sh          $a2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r6;
    // 0x801FEB1C: sh          $a3, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r7;
    // 0x801FEB20: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x801FEB24: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x801FEB28: sh          $t9, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r25;
    // 0x801FEB2C: bne         $t0, $zero, L_801FEB54
    if (ctx->r8 != 0) {
        // 0x801FEB30: sh          $t8, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r24;
            goto L_801FEB54;
    }
    // 0x801FEB30: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x801FEB34: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801FEB38: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x801FEB3C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FEB40: sb          $t1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r9;
    // 0x801FEB44: sb          $t2, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r10;
    // 0x801FEB48: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x801FEB4C: b           L_801FEBC4
    // 0x801FEB50: sb          $t3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r11;
        goto L_801FEBC4;
    // 0x801FEB50: sb          $t3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r11;
L_801FEB54:
    // 0x801FEB54: lbu         $v0, 0x7B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7B);
    // 0x801FEB58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FEB5C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801FEB60: bne         $v0, $at, L_801FEB80
    if (ctx->r2 != ctx->r1) {
        // 0x801FEB64: addiu       $t5, $zero, 0x30
        ctx->r13 = ADD32(0, 0X30);
            goto L_801FEB80;
    }
    // 0x801FEB64: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x801FEB68: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801FEB6C: sb          $zero, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = 0;
    // 0x801FEB70: sb          $t4, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r12;
    // 0x801FEB74: sb          $t5, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r13;
    // 0x801FEB78: b           L_801FEBC4
    // 0x801FEB7C: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
        goto L_801FEBC4;
    // 0x801FEB7C: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
L_801FEB80:
    // 0x801FEB80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801FEB84: bne         $v0, $at, L_801FEBAC
    if (ctx->r2 != ctx->r1) {
        // 0x801FEB88: addiu       $t0, $zero, 0xFF
        ctx->r8 = ADD32(0, 0XFF);
            goto L_801FEBAC;
    }
    // 0x801FEB88: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801FEB8C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801FEB90: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x801FEB94: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801FEB98: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x801FEB9C: sb          $t7, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r15;
    // 0x801FEBA0: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x801FEBA4: b           L_801FEBC4
    // 0x801FEBA8: sb          $t9, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r25;
        goto L_801FEBC4;
    // 0x801FEBA8: sb          $t9, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r25;
L_801FEBAC:
    // 0x801FEBAC: addiu       $t1, $zero, 0x90
    ctx->r9 = ADD32(0, 0X90);
    // 0x801FEBB0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801FEBB4: sb          $t0, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r8;
    // 0x801FEBB8: sb          $t1, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r9;
    // 0x801FEBBC: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
    // 0x801FEBC0: sb          $t2, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r10;
L_801FEBC4:
    // 0x801FEBC4: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    // 0x801FEBC8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801FEBCC: lw          $t7, 0x2570($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2570);
    // 0x801FEBD0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FEBD4: ori         $t6, $t5, 0x46
    ctx->r14 = ctx->r13 | 0X46;
    // 0x801FEBD8: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    // 0x801FEBDC: sb          $zero, 0x31($sp)
    MEM_B(0X31, ctx->r29) = 0;
    // 0x801FEBE0: sb          $zero, 0x32($sp)
    MEM_B(0X32, ctx->r29) = 0;
    // 0x801FEBE4: sb          $t3, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r11;
    // 0x801FEBE8: sh          $t6, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r14;
    // 0x801FEBEC: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x801FEBF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801FEBF4: lbu         $t4, 0x67($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X67);
    // 0x801FEBF8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801FEBFC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x801FEC00: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801FEC04: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801FEC08: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
    // 0x801FEC0C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801FEC10: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x801FEC14: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801FEC18: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801FEC1C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x801FEC20: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801FEC24: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x801FEC28: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    // 0x801FEC2C: sh          $t3, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r11;
    // 0x801FEC30: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x801FEC34: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x801FEC38: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x801FEC3C: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x801FEC40: jal         0x80146088
    // 0x801FEC44: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x801FEC44: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_0:
    // 0x801FEC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FEC4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801FEC50: jr          $ra
    // 0x801FEC54: nop

    return;
    // 0x801FEC54: nop

;}
RECOMP_FUNC void M9_FUN_801fec58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEC58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801FEC5C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801FEC60: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x801FEC64: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801FEC68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801FEC6C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801FEC70: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801FEC74: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801FEC78: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801FEC7C: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
    // 0x801FEC80: slti        $at, $s0, 0x3E8
    ctx->r1 = SIGNED(ctx->r16) < 0X3E8 ? 1 : 0;
    // 0x801FEC84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801FEC88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801FEC8C: bne         $at, $zero, L_801FED18
    if (ctx->r1 != 0) {
        // 0x801FEC90: sb          $zero, 0x90($a0)
        MEM_B(0X90, ctx->r4) = 0;
            goto L_801FED18;
    }
    // 0x801FEC90: sb          $zero, 0x90($a0)
    MEM_B(0X90, ctx->r4) = 0;
    // 0x801FEC94: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x801FEC98: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x801FEC9C: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x801FECA0: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x801FECA4: mflo        $v1
    ctx->r3 = lo;
    // 0x801FECA8: addiu       $a2, $a2, -0x24
    ctx->r6 = ADD32(ctx->r6, -0X24);
    // 0x801FECAC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FECB0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x801FECB4: addiu       $t7, $sp, 0x37
    ctx->r15 = ADD32(ctx->r29, 0X37);
    // 0x801FECB8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FECBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FECC0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FECC4: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x801FECC8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801FECCC: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x801FECD0: jal         0x801FEAE0
    // 0x801FECD4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801FEAE0)(rdram, ctx);
        goto after_0;
    // 0x801FECD4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FECD8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801FECDC: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x801FECE0: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801FECE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801FECE8: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x801FECEC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801FECF0: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
    // 0x801FECF4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801FECF8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801FECFC: bgezl       $s0, L_801FED0C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x801FED00: lbu         $t1, 0x90($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X90);
            goto L_801FED0C;
    }
    goto skip_0;
    // 0x801FED00: lbu         $t1, 0x90($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X90);
    skip_0:
    // 0x801FED04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FED08: lbu         $t1, 0x90($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X90);
L_801FED0C:
    // 0x801FED0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801FED10: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801FED14: sb          $t2, 0x90($s1)
    MEM_B(0X90, ctx->r17) = ctx->r10;
L_801FED18:
    // 0x801FED18: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x801FED1C: beq         $at, $zero, L_801FED28
    if (ctx->r1 == 0) {
        // 0x801FED20: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801FED28;
    }
    // 0x801FED20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FED24: beq         $t0, $zero, L_801FEDB4
    if (ctx->r8 == 0) {
        // 0x801FED28: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801FEDB4;
    }
L_801FED28:
    // 0x801FED28: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801FED2C: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x801FED30: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x801FED34: lbu         $t5, 0x4B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4B);
    // 0x801FED38: mflo        $v1
    ctx->r3 = lo;
    // 0x801FED3C: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    // 0x801FED40: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FED44: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801FED48: addiu       $t4, $sp, 0x37
    ctx->r12 = ADD32(ctx->r29, 0X37);
    // 0x801FED4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801FED50: sb          $t0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r8;
    // 0x801FED54: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801FED58: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801FED5C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FED60: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x801FED64: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801FED68: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x801FED6C: jal         0x801FEAE0
    // 0x801FED70: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x801FEAE0)(rdram, ctx);
        goto after_1;
    // 0x801FED70: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_1:
    // 0x801FED74: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801FED78: lbu         $t0, 0x36($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X36);
    // 0x801FED7C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801FED80: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801FED84: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801FED88: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801FED8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801FED90: subu        $s0, $s0, $t6
    ctx->r16 = SUB32(ctx->r16, ctx->r14);
    // 0x801FED94: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801FED98: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801FED9C: bgezl       $s0, L_801FEDAC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x801FEDA0: lbu         $t7, 0x90($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X90);
            goto L_801FEDAC;
    }
    goto skip_1;
    // 0x801FEDA0: lbu         $t7, 0x90($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X90);
    skip_1:
    // 0x801FEDA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FEDA8: lbu         $t7, 0x90($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X90);
L_801FEDAC:
    // 0x801FEDAC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801FEDB0: sb          $t8, 0x90($s1)
    MEM_B(0X90, ctx->r17) = ctx->r24;
L_801FEDB4:
    // 0x801FEDB4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x801FEDB8: beq         $at, $zero, L_801FEDC4
    if (ctx->r1 == 0) {
        // 0x801FEDBC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801FEDC4;
    }
    // 0x801FEDBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FEDC0: beq         $t0, $zero, L_801FEE3C
    if (ctx->r8 == 0) {
        // 0x801FEDC4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801FEE3C;
    }
L_801FEDC4:
    // 0x801FEDC4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801FEDC8: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x801FEDCC: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x801FEDD0: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x801FEDD4: mflo        $v1
    ctx->r3 = lo;
    // 0x801FEDD8: addiu       $a2, $a2, -0xC
    ctx->r6 = ADD32(ctx->r6, -0XC);
    // 0x801FEDDC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801FEDE0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x801FEDE4: addiu       $t1, $sp, 0x37
    ctx->r9 = ADD32(ctx->r29, 0X37);
    // 0x801FEDE8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801FEDEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801FEDF0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801FEDF4: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x801FEDF8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801FEDFC: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x801FEE00: jal         0x801FEAE0
    // 0x801FEE04: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x801FEAE0)(rdram, ctx);
        goto after_2;
    // 0x801FEE04: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_2:
    // 0x801FEE08: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801FEE0C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x801FEE10: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x801FEE14: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801FEE18: subu        $s0, $s0, $t3
    ctx->r16 = SUB32(ctx->r16, ctx->r11);
    // 0x801FEE1C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801FEE20: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801FEE24: bgezl       $s0, L_801FEE34
    if (SIGNED(ctx->r16) >= 0) {
        // 0x801FEE28: lbu         $t4, 0x90($s1)
        ctx->r12 = MEM_BU(ctx->r17, 0X90);
            goto L_801FEE34;
    }
    goto skip_2;
    // 0x801FEE28: lbu         $t4, 0x90($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X90);
    skip_2:
    // 0x801FEE2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801FEE30: lbu         $t4, 0x90($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X90);
L_801FEE34:
    // 0x801FEE34: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801FEE38: sb          $t5, 0x90($s1)
    MEM_B(0X90, ctx->r17) = ctx->r13;
L_801FEE3C:
    // 0x801FEE3C: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x801FEE40: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x801FEE44: addiu       $t7, $sp, 0x37
    ctx->r15 = ADD32(ctx->r29, 0X37);
    // 0x801FEE48: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801FEE4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801FEE50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801FEE54: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x801FEE58: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x801FEE5C: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x801FEE60: jal         0x801FEAE0
    // 0x801FEE64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801FEAE0)(rdram, ctx);
        goto after_3;
    // 0x801FEE64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_3:
    // 0x801FEE68: jal         0x80006214
    // 0x801FEE6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801FEE6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801FEE70: lbu         $t9, 0x90($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X90);
    // 0x801FEE74: sb          $v0, 0xAB($s1)
    MEM_B(0XAB, ctx->r17) = ctx->r2;
    // 0x801FEE78: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801FEE7C: sb          $t1, 0x90($s1)
    MEM_B(0X90, ctx->r17) = ctx->r9;
    // 0x801FEE80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801FEE84: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801FEE88: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801FEE8C: jr          $ra
    // 0x801FEE90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801FEE90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fee94(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fee94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEE94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FEE98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FEE9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FEEA0: lbu         $v0, 0x98($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X98);
    // 0x801FEEA4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801FEEA8: bne         $v0, $zero, L_801FEF10
    if (ctx->r2 != 0) {
        // 0x801FEEAC: sb          $t6, 0x98($a0)
        MEM_B(0X98, ctx->r4) = ctx->r14;
            goto L_801FEF10;
    }
    // 0x801FEEAC: sb          $t6, 0x98($a0)
    MEM_B(0X98, ctx->r4) = ctx->r14;
    // 0x801FEEB0: lbu         $t7, 0x96($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X96);
    // 0x801FEEB4: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x801FEEB8: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x801FEEBC: bne         $t7, $zero, L_801FEED4
    if (ctx->r15 != 0) {
        // 0x801FEEC0: addiu       $t1, $zero, 0x64
        ctx->r9 = ADD32(0, 0X64);
            goto L_801FEED4;
    }
    // 0x801FEEC0: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x801FEEC4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801FEEC8: sh          $t8, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r24;
    // 0x801FEECC: b           L_801FEEDC
    // 0x801FEED0: sh          $t9, 0xA6($a0)
    MEM_H(0XA6, ctx->r4) = ctx->r25;
        goto L_801FEEDC;
    // 0x801FEED0: sh          $t9, 0xA6($a0)
    MEM_H(0XA6, ctx->r4) = ctx->r25;
L_801FEED4:
    // 0x801FEED4: sh          $t0, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r8;
    // 0x801FEED8: sh          $t1, 0xA6($a0)
    MEM_H(0XA6, ctx->r4) = ctx->r9;
L_801FEEDC:
    // 0x801FEEDC: lbu         $t2, 0x97($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X97);
    // 0x801FEEE0: lh          $a1, 0x94($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X94);
    // 0x801FEEE4: lh          $a2, 0xA4($a0)
    ctx->r6 = MEM_H(ctx->r4, 0XA4);
    // 0x801FEEE8: lh          $a3, 0xA6($a0)
    ctx->r7 = MEM_H(ctx->r4, 0XA6);
    // 0x801FEEEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801FEEF0: jal         0x801FEC58
    // 0x801FEEF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x801FEC58)(rdram, ctx);
        goto after_0;
    // 0x801FEEF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x801FEEF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801FEEFC: addiu       $t3, $zero, -0x14
    ctx->r11 = ADD32(0, -0X14);
    // 0x801FEF00: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FEF04: addiu       $a1, $a1, -0x10E0
    ctx->r5 = ADD32(ctx->r5, -0X10E0);
    // 0x801FEF08: jal         0x800058DC
    // 0x801FEF0C: sh          $t3, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FEF0C: sh          $t3, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r11;
    after_1:
L_801FEF10:
    // 0x801FEF10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FEF14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FEF18: jr          $ra
    // 0x801FEF1C: nop

    return;
    // 0x801FEF1C: nop

;}
RECOMP_FUNC void M9_FUN_801fef20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FEF20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FEF24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FEF28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FEF2C: lbu         $v0, 0x97($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X97);
    // 0x801FEF30: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x801FEF34: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801FEF38: beq         $v1, $v0, L_801FEF50
    if (ctx->r3 == ctx->r2) {
        // 0x801FEF3C: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_801FEF50;
    }
    // 0x801FEF3C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FEF40: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FEF44: ldc1        $f4, -0x6CC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6CC0);
    // 0x801FEF48: b           L_801FEF58
    // 0x801FEF4C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
        goto L_801FEF58;
    // 0x801FEF4C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_801FEF50:
    // 0x801FEF50: ldc1        $f6, -0x6CB8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6CB8);
    // 0x801FEF54: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
L_801FEF58:
    // 0x801FEF58: bne         $v1, $v0, L_801FEF68
    if (ctx->r3 != ctx->r2) {
        // 0x801FEF5C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_801FEF68;
    }
    // 0x801FEF5C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x801FEF60: b           L_801FEF68
    // 0x801FEF64: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
        goto L_801FEF68;
    // 0x801FEF64: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_801FEF68:
    // 0x801FEF68: lh          $v1, 0xB0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XB0);
    // 0x801FEF6C: bgez        $v1, L_801FEF80
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801FEF70: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_801FEF80;
    }
    // 0x801FEF70: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801FEF74: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x801FEF78: b           L_801FF158
    // 0x801FEF7C: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
        goto L_801FF158;
    // 0x801FEF7C: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
L_801FEF80:
    // 0x801FEF80: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x801FEF84: beq         $v0, $zero, L_801FF150
    if (ctx->r2 == 0) {
        // 0x801FEF88: sh          $t7, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r15;
            goto L_801FF150;
    }
    // 0x801FEF88: sh          $t7, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r15;
    // 0x801FEF8C: lbu         $t0, 0x90($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X90);
    // 0x801FEF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801FEF94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FEF98: blez        $t0, L_801FF158
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801FEF9C: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_801FF158;
    }
    // 0x801FEF9C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FEFA0: ldc1        $f14, -0x6CB0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X6CB0);
    // 0x801FEFA4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801FEFA8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801FEFAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FEFB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801FEFB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801FEFB8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801FEFBC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801FEFC0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x801FEFC4: lbu         $t8, 0x96($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X96);
L_801FEFC8:
    // 0x801FEFC8: subu        $t6, $t0, $a1
    ctx->r14 = SUB32(ctx->r8, ctx->r5);
    // 0x801FEFCC: beq         $t8, $zero, L_801FF05C
    if (ctx->r24 == 0) {
        // 0x801FEFD0: nop
    
            goto L_801FF05C;
    }
    // 0x801FEFD0: nop

    // 0x801FEFD4: lh          $t4, 0xB0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XB0);
    // 0x801FEFD8: subu        $t8, $t0, $a1
    ctx->r24 = SUB32(ctx->r8, ctx->r5);
    // 0x801FEFDC: lh          $t6, 0xA4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA4);
    // 0x801FEFE0: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FEFE4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x801FEFE8: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x801FEFEC: mflo        $t5
    ctx->r13 = lo;
    // 0x801FEFF0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801FEFF4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801FEFF8: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FEFFC: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801FF000: mflo        $t9
    ctx->r25 = lo;
    // 0x801FF004: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x801FF008: addiu       $t5, $t4, 0xC
    ctx->r13 = ADD32(ctx->r12, 0XC);
    // 0x801FF00C: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x801FF010: lh          $v1, 0xB0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XB0);
    // 0x801FF014: lh          $t7, 0xA6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA6);
    // 0x801FF018: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801FF01C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801FF020: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FF024: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FF028: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801FF02C: mflo        $t9
    ctx->r25 = lo;
    // 0x801FF030: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x801FF034: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801FF038: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801FF03C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801FF040: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801FF044: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801FF048: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801FF04C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801FF050: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x801FF054: b           L_801FF0E0
    // 0x801FF058: sh          $t5, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r13;
        goto L_801FF0E0;
    // 0x801FF058: sh          $t5, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r13;
L_801FF05C:
    // 0x801FF05C: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FF060: lh          $t7, 0xB0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XB0);
    // 0x801FF064: lh          $t4, 0xA4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XA4);
    // 0x801FF068: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x801FF06C: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x801FF070: mflo        $t8
    ctx->r24 = lo;
    // 0x801FF074: subu        $t5, $t4, $t8
    ctx->r13 = SUB32(ctx->r12, ctx->r24);
    // 0x801FF078: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801FF07C: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FF080: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801FF084: mflo        $t9
    ctx->r25 = lo;
    // 0x801FF088: subu        $t6, $t5, $t9
    ctx->r14 = SUB32(ctx->r13, ctx->r25);
    // 0x801FF08C: addiu       $t4, $t6, 0xC
    ctx->r12 = ADD32(ctx->r14, 0XC);
    // 0x801FF090: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x801FF094: lh          $v1, 0xB0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XB0);
    // 0x801FF098: lh          $t5, 0xA6($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XA6);
    // 0x801FF09C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801FF0A0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x801FF0A4: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FF0A8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801FF0AC: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801FF0B0: mflo        $t9
    ctx->r25 = lo;
    // 0x801FF0B4: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x801FF0B8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801FF0BC: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x801FF0C0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801FF0C4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801FF0C8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801FF0CC: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801FF0D0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801FF0D4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801FF0D8: nop

    // 0x801FF0DC: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
L_801FF0E0:
    // 0x801FF0E0: lh          $t9, 0xB0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB0);
    // 0x801FF0E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801FF0E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801FF0EC: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801FF0F0: lw          $t4, 0x30($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X30);
    // 0x801FF0F4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801FF0F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801FF0FC: mflo        $t6
    ctx->r14 = lo;
    // 0x801FF100: subu        $t8, $t3, $t6
    ctx->r24 = SUB32(ctx->r11, ctx->r14);
    // 0x801FF104: sb          $t8, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r24;
    // 0x801FF108: lh          $t5, 0xB0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XB0);
    // 0x801FF10C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801FF110: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801FF114: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801FF118: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x801FF11C: mul.d       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x801FF120: sub.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d - ctx->f6.d;
    // 0x801FF124: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x801FF128: swc1        $f0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f0.u32l;
    // 0x801FF12C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801FF130: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801FF134: swc1        $f0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f0.u32l;
    // 0x801FF138: lbu         $t0, 0x90($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X90);
    // 0x801FF13C: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801FF140: bnel        $at, $zero, L_801FEFC8
    if (ctx->r1 != 0) {
        // 0x801FF144: lbu         $t8, 0x96($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X96);
            goto L_801FEFC8;
    }
    goto skip_0;
    // 0x801FF144: lbu         $t8, 0x96($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X96);
    skip_0:
    // 0x801FF148: b           L_801FF15C
    // 0x801FF14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801FF15C;
    // 0x801FF14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FF150:
    // 0x801FF150: jal         0x80005700
    // 0x801FF154: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FF154: nop

    after_0:
L_801FF158:
    // 0x801FF158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FF15C:
    // 0x801FF15C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FF160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FF164: jr          $ra
    // 0x801FF168: nop

    return;
    // 0x801FF168: nop

;}
RECOMP_FUNC void M9_FUN_801ff16c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF16C: nop

    // 0x801FF170: nop

    // 0x801FF174: nop

    // 0x801FF178: nop

    // 0x801FF17C: nop

;}
RECOMP_FUNC void M9_FUN_801ff180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FF184: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801FF188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FF18C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801FF190: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801FF194: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801FF198: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801FF19C: addiu       $t6, $t6, 0x7710
    ctx->r14 = ADD32(ctx->r14, 0X7710);
    // 0x801FF1A0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801FF1A4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FF1A8: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x801FF1AC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FF1B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801FF1B4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FF1B8: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FF1BC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FF1C0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801FF1C4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FF1C8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FF1CC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801FF1D0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FF1D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FF1D8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801FF1DC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FF1E0: jal         0x8012C4D0
    // 0x801FF1E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FF1E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FF1E8: beql        $v0, $zero, L_801FF250
    if (ctx->r2 == 0) {
        // 0x801FF1EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FF250;
    }
    goto skip_0;
    // 0x801FF1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801FF1F0: sb          $zero, 0x9E($v0)
    MEM_B(0X9E, ctx->r2) = 0;
    // 0x801FF1F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FF1F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801FF1FC: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801FF200: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FF204: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801FF208: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801FF20C: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801FF210: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x801FF214: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801FF218: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801FF21C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801FF220: sh          $t0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r8;
    // 0x801FF224: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x801FF228: sb          $t1, 0x9F($v0)
    MEM_B(0X9F, ctx->r2) = ctx->r9;
    // 0x801FF22C: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x801FF230: sh          $t2, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r10;
    // 0x801FF234: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x801FF238: sh          $zero, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = 0;
    // 0x801FF23C: sh          $zero, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = 0;
    // 0x801FF240: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x801FF244: b           L_801FF250
    // 0x801FF248: sw          $t3, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r11;
        goto L_801FF250;
    // 0x801FF248: sw          $t3, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r11;
    // 0x801FF24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FF250:
    // 0x801FF250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FF254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FF258: jr          $ra
    // 0x801FF25C: nop

    return;
    // 0x801FF25C: nop

;}
RECOMP_FUNC void M9_FUN_801ff260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FF264: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801FF268: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FF26C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801FF270: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801FF274: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801FF278: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801FF27C: addiu       $t6, $t6, 0x7738
    ctx->r14 = ADD32(ctx->r14, 0X7738);
    // 0x801FF280: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801FF284: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FF288: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x801FF28C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FF290: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801FF294: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FF298: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FF29C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FF2A0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801FF2A4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FF2A8: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FF2AC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801FF2B0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FF2B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FF2B8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801FF2BC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FF2C0: jal         0x8012C4D0
    // 0x801FF2C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FF2C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FF2C8: beql        $v0, $zero, L_801FF338
    if (ctx->r2 == 0) {
        // 0x801FF2CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FF338;
    }
    goto skip_0;
    // 0x801FF2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801FF2D0: sb          $zero, 0x9E($v0)
    MEM_B(0X9E, ctx->r2) = 0;
    // 0x801FF2D4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801FF2D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801FF2DC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801FF2E0: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801FF2E4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801FF2E8: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801FF2EC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801FF2F0: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801FF2F4: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x801FF2F8: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801FF2FC: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801FF300: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801FF304: sh          $t0, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r8;
    // 0x801FF308: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x801FF30C: sb          $t1, 0x9F($v0)
    MEM_B(0X9F, ctx->r2) = ctx->r9;
    // 0x801FF310: lhu         $t2, 0x42($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X42);
    // 0x801FF314: sh          $zero, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = 0;
    // 0x801FF318: sh          $t2, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = ctx->r10;
    // 0x801FF31C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x801FF320: sh          $t4, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = ctx->r12;
    // 0x801FF324: sh          $zero, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = 0;
    // 0x801FF328: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x801FF32C: b           L_801FF338
    // 0x801FF330: sw          $t3, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r11;
        goto L_801FF338;
    // 0x801FF330: sw          $t3, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r11;
    // 0x801FF334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FF338:
    // 0x801FF338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FF33C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FF340: jr          $ra
    // 0x801FF344: nop

    return;
    // 0x801FF344: nop

;}
RECOMP_FUNC void M9_FUN_801ff348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF350: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FF354: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x801FF358: bnel        $t7, $zero, L_801FF36C
    if (ctx->r15 != 0) {
        // 0x801FF35C: lbu         $t8, 0x9E($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X9E);
            goto L_801FF36C;
    }
    goto skip_0;
    // 0x801FF35C: lbu         $t8, 0x9E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9E);
    skip_0:
    // 0x801FF360: b           L_801FF3C0
    // 0x801FF364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801FF3C0;
    // 0x801FF364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FF368: lbu         $t8, 0x9E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9E);
L_801FF36C:
    // 0x801FF36C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801FF370: beql        $t8, $zero, L_801FF384
    if (ctx->r24 == 0) {
        // 0x801FF374: lw          $v0, 0xA4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XA4);
            goto L_801FF384;
    }
    goto skip_1;
    // 0x801FF374: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    skip_1:
    // 0x801FF378: b           L_801FF3C0
    // 0x801FF37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801FF3C0;
    // 0x801FF37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FF380: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
L_801FF384:
    // 0x801FF384: sb          $t9, 0x9E($a0)
    MEM_B(0X9E, ctx->r4) = ctx->r25;
    // 0x801FF388: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // 0x801FF38C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801FF390: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FF394: ori         $t1, $t0, 0xC
    ctx->r9 = ctx->r8 | 0XC;
    // 0x801FF398: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801FF39C: lhu         $t2, 0xA0($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XA0);
    // 0x801FF3A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801FF3A4: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x801FF3A8: lw          $v1, 0x7948($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7948);
    // 0x801FF3AC: beql        $v1, $zero, L_801FF3C0
    if (ctx->r3 == 0) {
        // 0x801FF3B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801FF3C0;
    }
    goto skip_2;
    // 0x801FF3B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801FF3B4: jalr        $v1
    // 0x801FF3B8: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x801FF3B8: nop

    after_0:
    // 0x801FF3BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FF3C0:
    // 0x801FF3C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF3C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF3C8: jr          $ra
    // 0x801FF3CC: nop

    return;
    // 0x801FF3CC: nop

;}
RECOMP_FUNC void M9_FUN_801ff3d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF3D0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FF3D4: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x801FF3D8: bnel        $t7, $zero, L_801FF3EC
    if (ctx->r15 != 0) {
        // 0x801FF3DC: lbu         $t8, 0x9E($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X9E);
            goto L_801FF3EC;
    }
    goto skip_0;
    // 0x801FF3DC: lbu         $t8, 0x9E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9E);
    skip_0:
    // 0x801FF3E0: jr          $ra
    // 0x801FF3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801FF3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FF3E8: lbu         $t8, 0x9E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9E);
L_801FF3EC:
    // 0x801FF3EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801FF3F0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801FF3F4: beql        $t8, $at, L_801FF408
    if (ctx->r24 == ctx->r1) {
        // 0x801FF3F8: lw          $v1, 0xA4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0XA4);
            goto L_801FF408;
    }
    goto skip_1;
    // 0x801FF3F8: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    skip_1:
    // 0x801FF3FC: jr          $ra
    // 0x801FF400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801FF400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FF404: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
L_801FF408:
    // 0x801FF408: sb          $t9, 0x9E($a0)
    MEM_B(0X9E, ctx->r4) = ctx->r25;
    // 0x801FF40C: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // 0x801FF410: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801FF414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801FF418: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x801FF41C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801FF420: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    // 0x801FF424: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x801FF428: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x801FF42C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x801FF430: jr          $ra
    // 0x801FF434: nop

    return;
    // 0x801FF434: nop

;}
RECOMP_FUNC void M9_FUN_801ff438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801FF43C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FF440: beq         $a0, $zero, L_801FF4B4
    if (ctx->r4 == 0) {
        // 0x801FF444: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_801FF4B4;
    }
    // 0x801FF444: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801FF448: lbu         $t6, 0x9F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9F);
    // 0x801FF44C: jal         0x80005700
    // 0x801FF450: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801FF450: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    after_0:
    // 0x801FF454: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801FF458: addiu       $t7, $t7, 0x7724
    ctx->r15 = ADD32(ctx->r15, 0X7724);
    // 0x801FF45C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FF460: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FF464: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801FF468: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801FF46C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FF470: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FF474: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FF478: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801FF47C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FF480: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FF484: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x801FF488: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FF48C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FF490: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FF494: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801FF498: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FF49C: jal         0x8012C4D0
    // 0x801FF4A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x801FF4A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x801FF4A4: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x801FF4A8: sb          $t1, 0x9F($v0)
    MEM_B(0X9F, ctx->r2) = ctx->r9;
    // 0x801FF4AC: b           L_801FF4B8
    // 0x801FF4B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FF4B8;
    // 0x801FF4B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FF4B4:
    // 0x801FF4B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FF4B8:
    // 0x801FF4B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FF4BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801FF4C0: jr          $ra
    // 0x801FF4C4: nop

    return;
    // 0x801FF4C4: nop

;}
RECOMP_FUNC void M9_FUN_801ff4c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF4C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF4CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF4D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FF4D4: lbu         $t6, 0x9F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9F);
    // 0x801FF4D8: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x801FF4DC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF4E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801FF4E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801FF4E8: lhu         $t8, 0x774C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X774C);
    // 0x801FF4EC: bnel        $t8, $zero, L_801FF508
    if (ctx->r24 != 0) {
        // 0x801FF4F0: lhu         $t9, 0xA8($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0XA8);
            goto L_801FF508;
    }
    goto skip_0;
    // 0x801FF4F0: lhu         $t9, 0xA8($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XA8);
    skip_0:
    // 0x801FF4F4: jal         0x800058DC
    // 0x801FF4F8: addiu       $a1, $a1, -0xA78
    ctx->r5 = ADD32(ctx->r5, -0XA78);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FF4F8: addiu       $a1, $a1, -0xA78
    ctx->r5 = ADD32(ctx->r5, -0XA78);
    after_0:
    // 0x801FF4FC: b           L_801FF520
    // 0x801FF500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FF520;
    // 0x801FF500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF504: lhu         $t9, 0xA8($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XA8);
L_801FF508:
    // 0x801FF508: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF50C: addiu       $a1, $a1, -0xAD4
    ctx->r5 = ADD32(ctx->r5, -0XAD4);
    // 0x801FF510: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x801FF514: jal         0x800058DC
    // 0x801FF518: sh          $t0, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FF518: sh          $t0, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r8;
    after_1:
    // 0x801FF51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FF520:
    // 0x801FF520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF524: jr          $ra
    // 0x801FF528: nop

    return;
    // 0x801FF528: nop

;}
RECOMP_FUNC void M9_FUN_801ff52c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF52C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF534: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FF538: lbu         $t6, 0x9F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9F);
    // 0x801FF53C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801FF540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FF544: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801FF548: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801FF54C: lhu         $a1, 0x774C($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X774C);
    // 0x801FF550: jal         0x80126A0C
    // 0x801FF554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x801FF554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801FF558: beq         $v0, $zero, L_801FF578
    if (ctx->r2 == 0) {
        // 0x801FF55C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801FF578;
    }
    // 0x801FF55C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801FF560: lhu         $t8, 0xA8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FF564: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF568: addiu       $a1, $a1, -0xA78
    ctx->r5 = ADD32(ctx->r5, -0XA78);
    // 0x801FF56C: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x801FF570: jal         0x800058DC
    // 0x801FF574: sh          $t9, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FF574: sh          $t9, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r25;
    after_1:
L_801FF578:
    // 0x801FF578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF57C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF580: jr          $ra
    // 0x801FF584: nop

    return;
    // 0x801FF584: nop

;}
RECOMP_FUNC void M9_FUN_801ff588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF590: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FF594: lhu         $t6, 0xA0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA0);
    // 0x801FF598: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF59C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FF5A0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FF5A4: lw          $v0, 0x77A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X77A8);
    // 0x801FF5A8: beql        $v0, $zero, L_801FF5C0
    if (ctx->r2 == 0) {
        // 0x801FF5AC: lbu         $t8, 0x9F($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X9F);
            goto L_801FF5C0;
    }
    goto skip_0;
    // 0x801FF5AC: lbu         $t8, 0x9F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9F);
    skip_0:
    // 0x801FF5B0: jalr        $v0
    // 0x801FF5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801FF5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801FF5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801FF5BC: lbu         $t8, 0x9F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9F);
L_801FF5C0:
    // 0x801FF5C0: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF5C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801FF5C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801FF5CC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x801FF5D0: lw          $v0, 0x77B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X77B8);
    // 0x801FF5D4: beql        $v0, $zero, L_801FF5EC
    if (ctx->r2 == 0) {
        // 0x801FF5D8: lhu         $t0, 0xA8($a0)
        ctx->r8 = MEM_HU(ctx->r4, 0XA8);
            goto L_801FF5EC;
    }
    goto skip_1;
    // 0x801FF5D8: lhu         $t0, 0xA8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XA8);
    skip_1:
    // 0x801FF5DC: jalr        $v0
    // 0x801FF5E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x801FF5E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801FF5E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801FF5E8: lhu         $t0, 0xA8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XA8);
L_801FF5EC:
    // 0x801FF5EC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF5F0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801FF5F4: beq         $t1, $zero, L_801FF610
    if (ctx->r9 == 0) {
        // 0x801FF5F8: nop
    
            goto L_801FF610;
    }
    // 0x801FF5F8: nop

    // 0x801FF5FC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF600: jal         0x800058DC
    // 0x801FF604: addiu       $a1, $a1, -0x8C4
    ctx->r5 = ADD32(ctx->r5, -0X8C4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FF604: addiu       $a1, $a1, -0x8C4
    ctx->r5 = ADD32(ctx->r5, -0X8C4);
    after_2:
    // 0x801FF608: b           L_801FF61C
    // 0x801FF60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801FF61C;
    // 0x801FF60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FF610:
    // 0x801FF610: jal         0x800058DC
    // 0x801FF614: addiu       $a1, $a1, -0x9D8
    ctx->r5 = ADD32(ctx->r5, -0X9D8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801FF614: addiu       $a1, $a1, -0x9D8
    ctx->r5 = ADD32(ctx->r5, -0X9D8);
    after_3:
    // 0x801FF618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801FF61C:
    // 0x801FF61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF620: jr          $ra
    // 0x801FF624: nop

    return;
    // 0x801FF624: nop

;}
RECOMP_FUNC void M9_FUN_801ff628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FF62C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FF630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FF634: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801FF638: lhu         $t6, 0xA0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA0);
    // 0x801FF63C: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FF644: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FF648: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FF64C: lw          $v0, 0x7870($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7870);
    // 0x801FF650: beql        $v0, $zero, L_801FF664
    if (ctx->r2 == 0) {
        // 0x801FF654: lhu         $t8, 0xA8($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0XA8);
            goto L_801FF664;
    }
    goto skip_0;
    // 0x801FF654: lhu         $t8, 0xA8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XA8);
    skip_0:
    // 0x801FF658: jalr        $v0
    // 0x801FF65C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801FF65C: nop

    after_0:
    // 0x801FF660: lhu         $t8, 0xA8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XA8);
L_801FF664:
    // 0x801FF664: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x801FF668: bnel        $t9, $zero, L_801FF69C
    if (ctx->r25 != 0) {
        // 0x801FF66C: lw          $t2, 0x74($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X74);
            goto L_801FF69C;
    }
    goto skip_1;
    // 0x801FF66C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    skip_1:
    // 0x801FF670: lbu         $t0, 0x9F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9F);
    // 0x801FF674: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FF67C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801FF680: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801FF684: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x801FF688: beql        $v0, $zero, L_801FF69C
    if (ctx->r2 == 0) {
        // 0x801FF68C: lw          $t2, 0x74($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X74);
            goto L_801FF69C;
    }
    goto skip_2;
    // 0x801FF68C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    skip_2:
    // 0x801FF690: jalr        $v0
    // 0x801FF694: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x801FF694: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801FF698: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
L_801FF69C:
    // 0x801FF69C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x801FF6A0: beql        $t2, $zero, L_801FF72C
    if (ctx->r10 == 0) {
        // 0x801FF6A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FF72C;
    }
    goto skip_3;
    // 0x801FF6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801FF6A8: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FF6AC: jal         0x801C3D20
    // 0x801FF6B0: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    LOOKUP_FUNC(0x801C3D20)(rdram, ctx);
        goto after_2;
    // 0x801FF6B0: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    after_2:
    // 0x801FF6B4: beq         $v0, $zero, L_801FF718
    if (ctx->r2 == 0) {
        // 0x801FF6B8: lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
            goto L_801FF718;
    }
    // 0x801FF6B8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801FF6BC: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801FF6C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801FF6C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FF6C8: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FF6CC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801FF6D0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801FF6D4: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x801FF6D8: lwc1        $f0, 0x8($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801FF6DC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x801FF6E0: nop

    // 0x801FF6E4: bc1fl       L_801FF71C
    if (!c1cs) {
        // 0x801FF6E8: lw          $t7, 0x2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF71C;
    }
    goto skip_4;
    // 0x801FF6E8: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    skip_4:
    // 0x801FF6EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FF6F0: nop

    // 0x801FF6F4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x801FF6F8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801FF6FC: nop

    // 0x801FF700: bc1fl       L_801FF71C
    if (!c1cs) {
        // 0x801FF704: lw          $t7, 0x2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF71C;
    }
    goto skip_5;
    // 0x801FF704: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    skip_5:
    // 0x801FF708: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x801FF70C: ori         $t6, $t5, 0x800
    ctx->r14 = ctx->r13 | 0X800;
    // 0x801FF710: b           L_801FF728
    // 0x801FF714: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
        goto L_801FF728;
    // 0x801FF714: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
L_801FF718:
    // 0x801FF718: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
L_801FF71C:
    // 0x801FF71C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x801FF720: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x801FF724: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
L_801FF728:
    // 0x801FF728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FF72C:
    // 0x801FF72C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FF730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FF734: jr          $ra
    // 0x801FF738: nop

    return;
    // 0x801FF738: nop

;}
RECOMP_FUNC void M9_FUN_801ff73c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF73C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FF740: jr          $ra
    // 0x801FF744: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801FF744: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ff748(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ff748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF74C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FF750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF754: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF758: sh          $zero, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = 0;
    // 0x801FF75C: jal         0x800058DC
    // 0x801FF760: addiu       $a1, $a1, -0x88C
    ctx->r5 = ADD32(ctx->r5, -0X88C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FF760: addiu       $a1, $a1, -0x88C
    ctx->r5 = ADD32(ctx->r5, -0X88C);
    after_0:
    // 0x801FF764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF76C: jr          $ra
    // 0x801FF770: nop

    return;
    // 0x801FF770: nop

;}
RECOMP_FUNC void M9_FUN_801ff774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF77C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FF780: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FF784: lh          $v0, 0xA2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XA2);
    // 0x801FF788: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801FF78C: slti        $v1, $v0, 0x4
    ctx->r3 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801FF790: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801FF794: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801FF798: beq         $v1, $zero, L_801FF7CC
    if (ctx->r3 == 0) {
        // 0x801FF79C: sh          $t6, 0xA2($a0)
        MEM_H(0XA2, ctx->r4) = ctx->r14;
            goto L_801FF7CC;
    }
    // 0x801FF79C: sh          $t6, 0xA2($a0)
    MEM_H(0XA2, ctx->r4) = ctx->r14;
    // 0x801FF7A0: lbu         $t7, 0x9F($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9F);
    // 0x801FF7A4: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x801FF7A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801FF7AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801FF7B0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x801FF7B4: jal         0x80126E88
    // 0x801FF7B8: lhu         $a0, 0x774C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X774C);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x801FF7B8: lhu         $a0, 0x774C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X774C);
    after_0:
    // 0x801FF7BC: beq         $v0, $zero, L_801FF7CC
    if (ctx->r2 == 0) {
        // 0x801FF7C0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801FF7CC;
    }
    // 0x801FF7C0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801FF7C4: jal         0x80005700
    // 0x801FF7C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FF7C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_801FF7CC:
    // 0x801FF7CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF7D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF7D4: jr          $ra
    // 0x801FF7D8: nop

    return;
    // 0x801FF7D8: nop

;}
RECOMP_FUNC void M9_FUN_801ff7dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF7DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FF7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FF7E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FF7E8: jal         0x801C3D90
    // 0x801FF7EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3D90)(rdram, ctx);
        goto after_0;
    // 0x801FF7EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801FF7F0: beq         $v0, $zero, L_801FF82C
    if (ctx->r2 == 0) {
        // 0x801FF7F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801FF82C;
    }
    // 0x801FF7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801FF7F8: lhu         $t6, 0xA0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA0);
    // 0x801FF7FC: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF800: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FF804: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FF808: lw          $v0, 0x793C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X793C);
    // 0x801FF80C: beq         $v0, $zero, L_801FF820
    if (ctx->r2 == 0) {
        // 0x801FF810: nop
    
            goto L_801FF820;
    }
    // 0x801FF810: nop

    // 0x801FF814: jalr        $v0
    // 0x801FF818: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x801FF818: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801FF81C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_801FF820:
    // 0x801FF820: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FF824: jal         0x800058DC
    // 0x801FF828: addiu       $a1, $a1, -0x7C4
    ctx->r5 = ADD32(ctx->r5, -0X7C4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801FF828: addiu       $a1, $a1, -0x7C4
    ctx->r5 = ADD32(ctx->r5, -0X7C4);
    after_2:
L_801FF82C:
    // 0x801FF82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FF830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FF834: jr          $ra
    // 0x801FF838: nop

    return;
    // 0x801FF838: nop

;}
RECOMP_FUNC void M9_FUN_801ff83c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF83C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FF840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FF844: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FF848: lhu         $t6, 0xA0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA0);
    // 0x801FF84C: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801FF850: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FF854: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801FF858: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801FF85C: lw          $v0, 0x7954($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7954);
    // 0x801FF860: beql        $v0, $zero, L_801FF874
    if (ctx->r2 == 0) {
        // 0x801FF864: lw          $t8, 0x74($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X74);
            goto L_801FF874;
    }
    goto skip_0;
    // 0x801FF864: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x801FF868: jalr        $v0
    // 0x801FF86C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801FF86C: nop

    after_0:
    // 0x801FF870: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
L_801FF874:
    // 0x801FF874: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x801FF878: beql        $t8, $zero, L_801FF9B0
    if (ctx->r24 == 0) {
        // 0x801FF87C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801FF9B0;
    }
    goto skip_1;
    // 0x801FF87C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801FF880: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FF884: jal         0x801C3D20
    // 0x801FF888: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    LOOKUP_FUNC(0x801C3D20)(rdram, ctx);
        goto after_1;
    // 0x801FF888: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    after_1:
    // 0x801FF88C: beq         $v0, $zero, L_801FF8DC
    if (ctx->r2 == 0) {
        // 0x801FF890: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_801FF8DC;
    }
    // 0x801FF890: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801FF894: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x801FF898: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801FF89C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801FF8A0: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FF8A4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801FF8A8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801FF8AC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801FF8B0: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801FF8B4: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x801FF8B8: nop

    // 0x801FF8BC: bc1f        L_801FF8DC
    if (!c1cs) {
        // 0x801FF8C0: nop
    
            goto L_801FF8DC;
    }
    // 0x801FF8C0: nop

    // 0x801FF8C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FF8C8: nop

    // 0x801FF8CC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801FF8D0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x801FF8D4: nop

    // 0x801FF8D8: bc1t        L_801FF97C
    if (c1cs) {
        // 0x801FF8DC: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_801FF97C;
    }
L_801FF8DC:
    // 0x801FF8DC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801FF8E0: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x801FF8E4: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FF8E8: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FF8EC: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801FF8F0: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801FF8F4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801FF8F8: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801FF8FC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801FF900: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801FF904: nop

    // 0x801FF908: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801FF90C: jal         0x8002FC20
    // 0x801FF910: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801FF910: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801FF914: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801FF918: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801FF91C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FF920: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801FF924: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x801FF928: nop

    // 0x801FF92C: bc1fl       L_801FF9A0
    if (!c1cs) {
        // 0x801FF930: lw          $t6, 0x2C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF9A0;
    }
    goto skip_2;
    // 0x801FF930: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x801FF934: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801FF938: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FF93C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801FF940: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801FF944: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801FF948: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801FF94C: lwc1        $f2, 0x34($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X34);
    // 0x801FF950: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x801FF954: nop

    // 0x801FF958: bc1fl       L_801FF9A0
    if (!c1cs) {
        // 0x801FF95C: lw          $t6, 0x2C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF9A0;
    }
    goto skip_3;
    // 0x801FF95C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    skip_3:
    // 0x801FF960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801FF964: nop

    // 0x801FF968: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801FF96C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801FF970: nop

    // 0x801FF974: bc1fl       L_801FF9A0
    if (!c1cs) {
        // 0x801FF978: lw          $t6, 0x2C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF9A0;
    }
    goto skip_4;
    // 0x801FF978: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    skip_4:
L_801FF97C:
    // 0x801FF97C: jal         0x80126944
    // 0x801FF980: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_3;
    // 0x801FF980: nop

    after_3:
    // 0x801FF984: bnel        $v0, $zero, L_801FF9A0
    if (ctx->r2 != 0) {
        // 0x801FF988: lw          $t6, 0x2C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X2C);
            goto L_801FF9A0;
    }
    goto skip_5;
    // 0x801FF988: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    skip_5:
    // 0x801FF98C: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x801FF990: ori         $t5, $t4, 0x800
    ctx->r13 = ctx->r12 | 0X800;
    // 0x801FF994: b           L_801FF9AC
    // 0x801FF998: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
        goto L_801FF9AC;
    // 0x801FF998: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x801FF99C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
L_801FF9A0:
    // 0x801FF9A0: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x801FF9A4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x801FF9A8: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
L_801FF9AC:
    // 0x801FF9AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801FF9B0:
    // 0x801FF9B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FF9B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801FF9B8: jr          $ra
    // 0x801FF9BC: nop

    return;
    // 0x801FF9BC: nop

;}
RECOMP_FUNC void M9_FUN_801ff9c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FF9C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FF9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FF9C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FF9CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FF9D0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FF9D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FF9D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FF9DC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FF9E0: bne         $t7, $zero, L_801FFA9C
    if (ctx->r15 != 0) {
        // 0x801FF9E4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFA9C;
    }
    // 0x801FF9E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FF9E8: jal         0x80005E44
    // 0x801FF9EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FF9EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FF9F0: jal         0x80006214
    // 0x801FF9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FF9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FF9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FF9FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFA00: addiu       $a2, $zero, 0x20F
    ctx->r6 = ADD32(0, 0X20F);
    // 0x801FFA04: jal         0x8012C89C
    // 0x801FFA08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFA08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801FFA0C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA10: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFA14: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFA18: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFA1C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFA20: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFA24: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA28: lwc1        $f4, -0x6AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6AA4);
    // 0x801FFA2C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFA30: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFA34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFA38: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFA3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA40: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFA44: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFA48: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFA4C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA50: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFA54: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFA58: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA5C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFA60: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFA64: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFA68: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFA6C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA70: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFA74: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFA78: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFA7C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA80: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFA84: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFA88: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFA8C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFA90: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFA94: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFA98: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFA9C:
    // 0x801FFA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFAA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFAA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFAA8: jr          $ra
    // 0x801FFAAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFAAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ffab0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ffab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFAB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFAB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFAB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFABC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFAC0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFAC4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFAC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFACC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFAD0: bne         $t7, $zero, L_801FFB8C
    if (ctx->r15 != 0) {
        // 0x801FFAD4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFB8C;
    }
    // 0x801FFAD4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFAD8: jal         0x80005E44
    // 0x801FFADC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFADC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFAE0: jal         0x80006214
    // 0x801FFAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFAF0: addiu       $a2, $zero, 0x20F
    ctx->r6 = ADD32(0, 0X20F);
    // 0x801FFAF4: jal         0x8012C89C
    // 0x801FFAF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFAF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801FFAFC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB00: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFB04: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFB08: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFB0C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFB10: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFB14: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB18: lwc1        $f4, -0x6AA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6AA0);
    // 0x801FFB1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFB20: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFB24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFB28: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFB2C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB30: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFB34: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFB38: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFB3C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB40: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFB44: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFB48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB4C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFB50: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFB54: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFB58: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFB5C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB60: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFB64: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFB68: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFB6C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB70: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFB74: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFB78: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFB7C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFB80: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFB84: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFB88: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFB8C:
    // 0x801FFB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFB90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFB94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFB98: jr          $ra
    // 0x801FFB9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFB9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ffba0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ffba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFBA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFBA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFBA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFBAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFBB0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFBB4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFBB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFBBC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFBC0: bne         $t7, $zero, L_801FFC7C
    if (ctx->r15 != 0) {
        // 0x801FFBC4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFC7C;
    }
    // 0x801FFBC4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFBC8: jal         0x80005E44
    // 0x801FFBCC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFBCC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFBD0: jal         0x80006214
    // 0x801FFBD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFBD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFBDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFBE0: addiu       $a2, $zero, 0x20F
    ctx->r6 = ADD32(0, 0X20F);
    // 0x801FFBE4: jal         0x8012C89C
    // 0x801FFBE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFBE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x801FFBEC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFBF0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFBF4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFBF8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFBFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFC00: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFC04: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC08: lwc1        $f4, -0x6A9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A9C);
    // 0x801FFC0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFC10: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFC14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFC18: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFC1C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC20: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFC24: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFC28: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFC2C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC30: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFC34: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFC38: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC3C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFC40: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFC44: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFC48: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFC4C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFC54: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFC58: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFC5C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC60: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFC64: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFC68: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFC6C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFC70: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFC74: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFC78: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFC7C:
    // 0x801FFC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFC80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFC84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFC88: jr          $ra
    // 0x801FFC8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFC8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ffc90(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ffc90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFC90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFC94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFC98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFC9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFCA0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFCA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFCA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFCAC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFCB0: bne         $t7, $zero, L_801FFD6C
    if (ctx->r15 != 0) {
        // 0x801FFCB4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFD6C;
    }
    // 0x801FFCB4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFCB8: jal         0x80005E44
    // 0x801FFCBC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFCBC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFCC0: jal         0x80006214
    // 0x801FFCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFCC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFCCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFCD0: addiu       $a2, $zero, 0x20F
    ctx->r6 = ADD32(0, 0X20F);
    // 0x801FFCD4: jal         0x8012C89C
    // 0x801FFCD8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFCD8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x801FFCDC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFCE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFCE4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFCE8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFCEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFCF0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFCF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFCF8: lwc1        $f4, -0x6A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A98);
    // 0x801FFCFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFD00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFD04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFD08: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFD0C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD10: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFD14: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFD18: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFD1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD20: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFD24: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFD28: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD2C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFD30: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFD34: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFD38: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFD3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD40: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFD44: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFD48: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFD4C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD50: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFD54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFD58: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFD5C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFD60: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFD64: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFD68: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFD6C:
    // 0x801FFD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFD70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFD74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFD78: jr          $ra
    // 0x801FFD7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFD7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ffd80(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ffd80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFD80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFD84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFD88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFD8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFD90: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFD94: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFD98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFD9C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFDA0: bne         $t7, $zero, L_801FFE5C
    if (ctx->r15 != 0) {
        // 0x801FFDA4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFE5C;
    }
    // 0x801FFDA4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFDA8: jal         0x80005E44
    // 0x801FFDAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFDAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFDB0: jal         0x80006214
    // 0x801FFDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFDC0: addiu       $a2, $zero, 0x210
    ctx->r6 = ADD32(0, 0X210);
    // 0x801FFDC4: jal         0x8012C89C
    // 0x801FFDC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFDC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801FFDCC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFDD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFDD4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFDD8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFDDC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFDE0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFDE4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFDE8: lwc1        $f4, -0x6A94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A94);
    // 0x801FFDEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFDF0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFDF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFDF8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFDFC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE00: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFE04: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFE08: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFE0C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE10: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFE14: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFE18: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE1C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFE20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFE24: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFE28: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFE2C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFE34: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFE38: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFE3C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE40: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFE44: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFE48: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFE4C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFE50: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFE54: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFE58: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFE5C:
    // 0x801FFE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFE60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFE64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFE68: jr          $ra
    // 0x801FFE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801ffe70(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801ffe70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFE70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFE74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFE78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFE7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFE80: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFE84: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFE88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFE8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFE90: bne         $t7, $zero, L_801FFF4C
    if (ctx->r15 != 0) {
        // 0x801FFE94: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801FFF4C;
    }
    // 0x801FFE94: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFE98: jal         0x80005E44
    // 0x801FFE9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFE9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFEA0: jal         0x80006214
    // 0x801FFEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFEB0: addiu       $a2, $zero, 0x210
    ctx->r6 = ADD32(0, 0X210);
    // 0x801FFEB4: jal         0x8012C89C
    // 0x801FFEB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFEB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801FFEBC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFEC0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFEC4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFEC8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFECC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFED0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFED4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFED8: lwc1        $f4, -0x6A90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A90);
    // 0x801FFEDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFEE0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFEE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFEE8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFEEC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFEF0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFEF4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFEF8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFEFC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFF00: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFF04: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFF08: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFF0C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801FFF10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801FFF14: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801FFF18: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801FFF1C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFF20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FFF24: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801FFF28: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801FFF2C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801FFF30: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801FFF34: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801FFF38: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x801FFF3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFF40: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x801FFF44: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801FFF48: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_801FFF4C:
    // 0x801FFF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801FFF50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FFF54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FFF58: jr          $ra
    // 0x801FFF5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801FFF5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fff60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fff60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FFF60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801FFF64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801FFF68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FFF6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FFF70: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801FFF74: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801FFF78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FFF7C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801FFF80: bne         $t7, $zero, L_8020003C
    if (ctx->r15 != 0) {
        // 0x801FFF84: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020003C;
    }
    // 0x801FFF84: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801FFF88: jal         0x80005E44
    // 0x801FFF8C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801FFF8C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801FFF90: jal         0x80006214
    // 0x801FFF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801FFF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FFF98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FFF9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801FFFA0: addiu       $a2, $zero, 0x210
    ctx->r6 = ADD32(0, 0X210);
    // 0x801FFFA4: jal         0x8012C89C
    // 0x801FFFA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801FFFA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x801FFFAC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801FFFB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801FFFB4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x801FFFB8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801FFFBC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FFFC0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x801FFFC4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801FFFC8: lwc1        $f4, -0x6A8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A8C);
    // 0x801FFFCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801FFFD0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801FFFD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FFFD8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x801FFFDC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801FFFE0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801FFFE4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801FFFE8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801FFFEC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801FFFF0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801FFFF4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801FFFF8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801FFFFC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200000: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200004: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200008: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020000C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200010: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200014: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200018: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020001C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200020: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200024: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200028: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020002C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200030: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200034: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200038: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020003C:
    // 0x8020003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200040: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200044: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200048: jr          $ra
    // 0x8020004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200050(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200058: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020005C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200060: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200064: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020006C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200070: bne         $t7, $zero, L_8020012C
    if (ctx->r15 != 0) {
        // 0x80200074: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020012C;
    }
    // 0x80200074: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200078: jal         0x80005E44
    // 0x8020007C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020007C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200080: jal         0x80006214
    // 0x80200084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200090: addiu       $a2, $zero, 0x210
    ctx->r6 = ADD32(0, 0X210);
    // 0x80200094: jal         0x8012C89C
    // 0x80200098: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200098: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8020009C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802000A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x802000A4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x802000A8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x802000AC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802000B0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x802000B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x802000B8: lwc1        $f4, -0x6A88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A88);
    // 0x802000BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802000C0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802000C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802000C8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x802000CC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802000D0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802000D4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802000D8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802000DC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802000E0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802000E4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802000E8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802000EC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802000F0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802000F4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802000F8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802000FC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200100: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200104: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200108: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020010C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200110: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200114: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200118: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020011C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200120: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200124: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200128: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020012C:
    // 0x8020012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200130: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200134: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200138: jr          $ra
    // 0x8020013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200140(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200148: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020014C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200150: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200154: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020015C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200160: bne         $t7, $zero, L_8020021C
    if (ctx->r15 != 0) {
        // 0x80200164: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020021C;
    }
    // 0x80200164: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200168: jal         0x80005E44
    // 0x8020016C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020016C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200170: jal         0x80006214
    // 0x80200174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200180: addiu       $a2, $zero, 0x211
    ctx->r6 = ADD32(0, 0X211);
    // 0x80200184: jal         0x8012C89C
    // 0x80200188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8020018C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200190: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200194: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200198: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020019C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802001A0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x802001A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x802001A8: lwc1        $f4, -0x6A84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A84);
    // 0x802001AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802001B0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802001B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802001B8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x802001BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802001C0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802001C4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802001C8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802001CC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802001D0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802001D4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802001D8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802001DC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802001E0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802001E4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802001E8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802001EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802001F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802001F4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802001F8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802001FC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200200: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200204: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200208: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020020C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200210: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200214: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200218: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020021C:
    // 0x8020021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200220: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200224: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200228: jr          $ra
    // 0x8020022C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020022C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200230(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200238: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020023C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200240: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200244: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020024C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200250: bne         $t7, $zero, L_8020030C
    if (ctx->r15 != 0) {
        // 0x80200254: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020030C;
    }
    // 0x80200254: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200258: jal         0x80005E44
    // 0x8020025C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020025C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200260: jal         0x80006214
    // 0x80200264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020026C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200270: addiu       $a2, $zero, 0x211
    ctx->r6 = ADD32(0, 0X211);
    // 0x80200274: jal         0x8012C89C
    // 0x80200278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8020027C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200280: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200284: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200288: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020028C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200290: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200294: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200298: lwc1        $f4, -0x6A80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A80);
    // 0x8020029C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802002A0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802002A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802002A8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x802002AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802002B0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802002B4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802002B8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802002BC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802002C0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802002C4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802002C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802002CC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802002D0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802002D4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802002D8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802002DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802002E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802002E4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802002E8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802002EC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802002F0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802002F4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802002F8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802002FC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200300: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200304: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200308: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020030C:
    // 0x8020030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200310: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200314: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200318: jr          $ra
    // 0x8020031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200320(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200328: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020032C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200330: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200334: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020033C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200340: bne         $t7, $zero, L_802003FC
    if (ctx->r15 != 0) {
        // 0x80200344: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802003FC;
    }
    // 0x80200344: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200348: jal         0x80005E44
    // 0x8020034C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020034C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200350: jal         0x80006214
    // 0x80200354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020035C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200360: addiu       $a2, $zero, 0x211
    ctx->r6 = ADD32(0, 0X211);
    // 0x80200364: jal         0x8012C89C
    // 0x80200368: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200368: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8020036C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200370: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200374: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200378: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020037C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200380: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200384: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200388: lwc1        $f4, -0x6A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A7C);
    // 0x8020038C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200390: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200394: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200398: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020039C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802003A0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802003A4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802003A8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802003AC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802003B0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802003B4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802003B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802003BC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802003C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802003C4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802003C8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802003CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802003D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802003D4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802003D8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802003DC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802003E0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802003E4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802003E8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802003EC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802003F0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802003F4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802003F8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802003FC:
    // 0x802003FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200400: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200404: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200408: jr          $ra
    // 0x8020040C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020040C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200410(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200410: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200418: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020041C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200420: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200424: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020042C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200430: bne         $t7, $zero, L_802004EC
    if (ctx->r15 != 0) {
        // 0x80200434: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802004EC;
    }
    // 0x80200434: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200438: jal         0x80005E44
    // 0x8020043C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020043C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200440: jal         0x80006214
    // 0x80200444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200450: addiu       $a2, $zero, 0x211
    ctx->r6 = ADD32(0, 0X211);
    // 0x80200454: jal         0x8012C89C
    // 0x80200458: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200458: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8020045C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200460: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200464: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200468: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020046C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200470: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200474: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200478: lwc1        $f4, -0x6A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A78);
    // 0x8020047C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200480: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200484: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200488: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020048C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200490: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200494: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200498: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020049C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802004A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802004A4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802004A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802004AC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802004B0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802004B4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802004B8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802004BC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802004C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802004C4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802004C8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802004CC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802004D0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802004D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802004D8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802004DC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802004E0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802004E4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802004E8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802004EC:
    // 0x802004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802004F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802004F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802004F8: jr          $ra
    // 0x802004FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802004FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200500(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200504: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200508: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020050C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200510: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200514: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020051C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200520: bne         $t7, $zero, L_802005DC
    if (ctx->r15 != 0) {
        // 0x80200524: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802005DC;
    }
    // 0x80200524: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200528: jal         0x80005E44
    // 0x8020052C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020052C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200530: jal         0x80006214
    // 0x80200534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200540: addiu       $a2, $zero, 0x212
    ctx->r6 = ADD32(0, 0X212);
    // 0x80200544: jal         0x8012C89C
    // 0x80200548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8020054C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200550: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200554: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200558: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020055C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200560: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200564: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200568: lwc1        $f4, -0x6A74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A74);
    // 0x8020056C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200570: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200578: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020057C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200580: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200584: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200588: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020058C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200590: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200594: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200598: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020059C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802005A0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802005A4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802005A8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802005AC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802005B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802005B4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802005B8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802005BC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802005C0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802005C4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802005C8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802005CC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802005D0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802005D4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802005D8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802005DC:
    // 0x802005DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802005E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802005E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802005E8: jr          $ra
    // 0x802005EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802005EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802005f0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802005f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802005F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802005F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802005F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802005FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200600: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200604: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020060C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200610: bne         $t7, $zero, L_802006CC
    if (ctx->r15 != 0) {
        // 0x80200614: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802006CC;
    }
    // 0x80200614: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200618: jal         0x80005E44
    // 0x8020061C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020061C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200620: jal         0x80006214
    // 0x80200624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020062C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200630: addiu       $a2, $zero, 0x212
    ctx->r6 = ADD32(0, 0X212);
    // 0x80200634: jal         0x8012C89C
    // 0x80200638: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200638: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8020063C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200640: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200644: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200648: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020064C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200650: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200654: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200658: lwc1        $f4, -0x6A70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A70);
    // 0x8020065C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200660: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200668: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020066C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200670: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200674: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200678: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020067C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200680: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200684: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200688: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020068C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200690: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200694: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200698: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020069C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802006A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802006A4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802006A8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802006AC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802006B0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802006B4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802006B8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802006BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802006C0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802006C4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802006C8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802006CC:
    // 0x802006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802006D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802006D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802006D8: jr          $ra
    // 0x802006DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802006DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802006e0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802006e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802006E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802006E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802006E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802006EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802006F0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802006F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802006F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802006FC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200700: bne         $t7, $zero, L_802007BC
    if (ctx->r15 != 0) {
        // 0x80200704: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802007BC;
    }
    // 0x80200704: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200708: jal         0x80005E44
    // 0x8020070C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020070C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200710: jal         0x80006214
    // 0x80200714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200720: addiu       $a2, $zero, 0x212
    ctx->r6 = ADD32(0, 0X212);
    // 0x80200724: jal         0x8012C89C
    // 0x80200728: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200728: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8020072C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200730: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200734: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200738: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020073C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200740: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200744: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200748: lwc1        $f4, -0x6A6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A6C);
    // 0x8020074C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200750: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200754: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200758: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020075C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200760: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200764: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200768: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020076C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200770: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200774: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200778: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020077C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200780: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200784: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200788: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020078C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200790: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200794: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200798: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020079C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802007A0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802007A4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802007A8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802007AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802007B0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802007B4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802007B8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802007BC:
    // 0x802007BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802007C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802007C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802007C8: jr          $ra
    // 0x802007CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802007CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802007d0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802007d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802007D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802007D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802007D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802007DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802007E0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802007E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802007E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802007EC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802007F0: bne         $t7, $zero, L_802008AC
    if (ctx->r15 != 0) {
        // 0x802007F4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802008AC;
    }
    // 0x802007F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802007F8: jal         0x80005E44
    // 0x802007FC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802007FC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200800: jal         0x80006214
    // 0x80200804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200810: addiu       $a2, $zero, 0x213
    ctx->r6 = ADD32(0, 0X213);
    // 0x80200814: jal         0x8012C89C
    // 0x80200818: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200818: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8020081C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200820: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200824: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200828: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020082C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200830: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200834: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200838: lwc1        $f4, -0x6A68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A68);
    // 0x8020083C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200840: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200848: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020084C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200850: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200854: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200858: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020085C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200860: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200864: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200868: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020086C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200870: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200874: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200878: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020087C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200880: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200884: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200888: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020088C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200890: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200894: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200898: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020089C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802008A0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802008A4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802008A8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802008AC:
    // 0x802008AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802008B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802008B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802008B8: jr          $ra
    // 0x802008BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802008BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802008c0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802008c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802008C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802008C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802008C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802008CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802008D0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802008D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802008D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802008DC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802008E0: bne         $t7, $zero, L_8020099C
    if (ctx->r15 != 0) {
        // 0x802008E4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020099C;
    }
    // 0x802008E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802008E8: jal         0x80005E44
    // 0x802008EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802008EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x802008F0: jal         0x80006214
    // 0x802008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802008FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200900: addiu       $a2, $zero, 0x213
    ctx->r6 = ADD32(0, 0X213);
    // 0x80200904: jal         0x8012C89C
    // 0x80200908: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200908: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8020090C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200910: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200914: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200918: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020091C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200920: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200924: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200928: lwc1        $f4, -0x6A64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A64);
    // 0x8020092C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200930: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200934: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200938: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020093C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200940: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200944: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200948: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020094C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200950: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200954: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200958: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020095C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200960: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200964: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200968: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020096C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200970: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200974: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200978: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020097C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200980: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200984: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200988: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020098C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200990: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200994: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200998: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020099C:
    // 0x8020099C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802009A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802009A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802009A8: jr          $ra
    // 0x802009AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802009AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802009b0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802009b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802009B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802009B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802009B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802009BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802009C0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802009C4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802009C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802009CC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x802009D0: bne         $t7, $zero, L_80200A8C
    if (ctx->r15 != 0) {
        // 0x802009D4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200A8C;
    }
    // 0x802009D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802009D8: jal         0x80005E44
    // 0x802009DC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x802009DC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x802009E0: jal         0x80006214
    // 0x802009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x802009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x802009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x802009F0: addiu       $a2, $zero, 0x213
    ctx->r6 = ADD32(0, 0X213);
    // 0x802009F4: jal         0x8012C89C
    // 0x802009F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x802009F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x802009FC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200A00: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200A04: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200A08: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200A0C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200A10: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200A14: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200A18: lwc1        $f4, -0x6A60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A60);
    // 0x80200A1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200A20: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200A24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200A28: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200A2C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200A30: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200A34: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200A38: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200A3C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200A40: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200A44: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200A48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200A4C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200A50: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200A54: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200A58: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200A5C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200A60: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200A64: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200A68: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200A6C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200A70: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200A74: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200A78: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200A7C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200A80: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200A84: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200A88: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200A8C:
    // 0x80200A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200A90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200A94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200A98: jr          $ra
    // 0x80200A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200aa0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200AA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200AAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200AB0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200AB4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200AB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200ABC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200AC0: bne         $t7, $zero, L_80200B7C
    if (ctx->r15 != 0) {
        // 0x80200AC4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200B7C;
    }
    // 0x80200AC4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200AC8: jal         0x80005E44
    // 0x80200ACC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200ACC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200AD0: jal         0x80006214
    // 0x80200AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200AE0: addiu       $a2, $zero, 0x213
    ctx->r6 = ADD32(0, 0X213);
    // 0x80200AE4: jal         0x8012C89C
    // 0x80200AE8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200AE8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x80200AEC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200AF0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200AF4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200AF8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200AFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200B00: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200B04: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200B08: lwc1        $f4, -0x6A5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A5C);
    // 0x80200B0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200B10: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200B14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200B18: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200B1C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200B20: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200B24: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200B28: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200B2C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200B30: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200B34: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200B38: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200B3C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200B40: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200B44: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200B48: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200B4C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200B50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200B54: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200B58: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200B5C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200B60: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200B64: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200B68: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200B6C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200B70: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200B74: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200B78: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200B7C:
    // 0x80200B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200B80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200B84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200B88: jr          $ra
    // 0x80200B8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200B8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200b90(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200b90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200B90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200B94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200B98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200B9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200BA0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200BA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200BAC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200BB0: bne         $t7, $zero, L_80200C6C
    if (ctx->r15 != 0) {
        // 0x80200BB4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200C6C;
    }
    // 0x80200BB4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200BB8: jal         0x80005E44
    // 0x80200BBC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200BBC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200BC0: jal         0x80006214
    // 0x80200BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200BCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200BD0: addiu       $a2, $zero, 0x214
    ctx->r6 = ADD32(0, 0X214);
    // 0x80200BD4: jal         0x8012C89C
    // 0x80200BD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200BD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80200BDC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200BE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200BE4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200BE8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200BEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200BF0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200BF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200BF8: lwc1        $f4, -0x6A58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A58);
    // 0x80200BFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200C00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200C04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200C08: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200C0C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200C10: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200C14: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200C18: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200C1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200C20: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200C24: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200C28: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200C2C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200C30: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200C34: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200C38: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200C3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200C40: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200C44: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200C48: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200C4C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200C50: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200C54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200C58: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200C5C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200C60: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200C64: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200C68: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200C6C:
    // 0x80200C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200C70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200C74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200C78: jr          $ra
    // 0x80200C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200c80(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200c80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200C80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200C88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200C8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200C90: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200C94: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200C98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200C9C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200CA0: bne         $t7, $zero, L_80200D5C
    if (ctx->r15 != 0) {
        // 0x80200CA4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200D5C;
    }
    // 0x80200CA4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200CA8: jal         0x80005E44
    // 0x80200CAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200CAC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200CB0: jal         0x80006214
    // 0x80200CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200CC0: addiu       $a2, $zero, 0x215
    ctx->r6 = ADD32(0, 0X215);
    // 0x80200CC4: jal         0x8012C89C
    // 0x80200CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80200CCC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200CD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200CD4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200CD8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200CDC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200CE0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200CE4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200CE8: lwc1        $f4, -0x6A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A54);
    // 0x80200CEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200CF0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200CF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200CF8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200CFC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200D00: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200D04: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200D08: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200D0C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200D10: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200D14: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200D18: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200D1C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200D20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200D24: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200D28: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200D2C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200D30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200D34: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200D38: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200D3C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200D40: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200D44: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200D48: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200D4C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200D50: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200D54: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200D58: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200D5C:
    // 0x80200D5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200D60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200D64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200D68: jr          $ra
    // 0x80200D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200d70(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200d70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200D74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200D78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200D7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200D80: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200D84: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200D88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200D8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200D90: bne         $t7, $zero, L_80200E4C
    if (ctx->r15 != 0) {
        // 0x80200D94: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200E4C;
    }
    // 0x80200D94: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200D98: jal         0x80005E44
    // 0x80200D9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200D9C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200DA0: jal         0x80006214
    // 0x80200DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200DB0: addiu       $a2, $zero, 0x214
    ctx->r6 = ADD32(0, 0X214);
    // 0x80200DB4: jal         0x8012C89C
    // 0x80200DB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200DB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80200DBC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200DC0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200DC4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200DC8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200DCC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200DD0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200DD4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200DD8: lwc1        $f4, -0x6A50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A50);
    // 0x80200DDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200DE0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200DE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200DE8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200DEC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200DF0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200DF4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200DF8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200DFC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200E00: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200E04: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200E08: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200E0C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200E10: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200E14: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200E18: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200E1C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200E20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200E24: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200E28: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200E2C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200E30: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200E34: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200E38: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200E3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200E40: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200E44: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200E48: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200E4C:
    // 0x80200E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200E50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200E54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200E58: jr          $ra
    // 0x80200E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200e60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200E60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200E68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200E6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200E70: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200E74: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200E78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200E7C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200E80: bne         $t7, $zero, L_80200F3C
    if (ctx->r15 != 0) {
        // 0x80200E84: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80200F3C;
    }
    // 0x80200E84: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200E88: jal         0x80005E44
    // 0x80200E8C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200E8C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200E90: jal         0x80006214
    // 0x80200E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200EA0: addiu       $a2, $zero, 0x215
    ctx->r6 = ADD32(0, 0X215);
    // 0x80200EA4: jal         0x8012C89C
    // 0x80200EA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200EA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80200EAC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200EB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200EB4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200EB8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200EBC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200EC0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200EC4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200EC8: lwc1        $f4, -0x6A4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A4C);
    // 0x80200ECC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200ED0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200ED4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200ED8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200EDC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200EE0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200EE4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200EE8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200EEC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200EF0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200EF4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200EF8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200EFC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200F00: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200F04: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200F08: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200F0C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200F10: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80200F14: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80200F18: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x80200F1C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80200F20: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80200F24: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80200F28: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80200F2C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200F30: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80200F34: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80200F38: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_80200F3C:
    // 0x80200F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80200F40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80200F44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80200F48: jr          $ra
    // 0x80200F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80200F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80200f50(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80200f50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80200F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80200F54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80200F58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80200F5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80200F60: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80200F64: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80200F68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80200F6C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80200F70: bne         $t7, $zero, L_8020102C
    if (ctx->r15 != 0) {
        // 0x80200F74: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020102C;
    }
    // 0x80200F74: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80200F78: jal         0x80005E44
    // 0x80200F7C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80200F7C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80200F80: jal         0x80006214
    // 0x80200F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80200F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80200F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80200F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80200F90: addiu       $a2, $zero, 0x214
    ctx->r6 = ADD32(0, 0X214);
    // 0x80200F94: jal         0x8012C89C
    // 0x80200F98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80200F98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80200F9C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80200FA0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80200FA4: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80200FA8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80200FAC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80200FB0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80200FB4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80200FB8: lwc1        $f4, -0x6A48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A48);
    // 0x80200FBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80200FC0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80200FC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80200FC8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80200FCC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80200FD0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80200FD4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80200FD8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80200FDC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80200FE0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80200FE4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80200FE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80200FEC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80200FF0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80200FF4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80200FF8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80200FFC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201000: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201004: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201008: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020100C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201010: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201014: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201018: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020101C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201020: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201024: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201028: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020102C:
    // 0x8020102C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201030: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201034: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201038: jr          $ra
    // 0x8020103C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020103C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201040(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201048: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020104C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201050: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201054: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020105C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201060: bne         $t7, $zero, L_8020111C
    if (ctx->r15 != 0) {
        // 0x80201064: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020111C;
    }
    // 0x80201064: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201068: jal         0x80005E44
    // 0x8020106C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020106C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201070: jal         0x80006214
    // 0x80201074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020107C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201080: addiu       $a2, $zero, 0x215
    ctx->r6 = ADD32(0, 0X215);
    // 0x80201084: jal         0x8012C89C
    // 0x80201088: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201088: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8020108C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201090: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201094: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201098: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020109C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x802010A0: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x802010A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x802010A8: lwc1        $f4, -0x6A44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A44);
    // 0x802010AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802010B0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802010B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802010B8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x802010BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802010C0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802010C4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802010C8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802010CC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802010D0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802010D4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802010D8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802010DC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802010E0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802010E4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802010E8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802010EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802010F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802010F4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802010F8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802010FC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80201100: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80201104: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80201108: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8020110C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201110: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201114: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201118: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020111C:
    // 0x8020111C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201120: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201124: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201128: jr          $ra
    // 0x8020112C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020112C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201130(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201138: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020113C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201140: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201144: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020114C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201150: bne         $t7, $zero, L_8020120C
    if (ctx->r15 != 0) {
        // 0x80201154: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8020120C;
    }
    // 0x80201154: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201158: jal         0x80005E44
    // 0x8020115C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020115C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201160: jal         0x80006214
    // 0x80201164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201170: addiu       $a2, $zero, 0x214
    ctx->r6 = ADD32(0, 0X214);
    // 0x80201174: jal         0x8012C89C
    // 0x80201178: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201178: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8020117C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201180: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201184: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201188: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020118C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201190: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201194: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201198: lwc1        $f4, -0x6A40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A40);
    // 0x8020119C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x802011A0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x802011A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802011A8: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x802011AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802011B0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802011B4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802011B8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802011BC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802011C0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802011C4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802011C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802011CC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802011D0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802011D4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802011D8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802011DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802011E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802011E4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802011E8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802011EC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802011F0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802011F4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802011F8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802011FC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201200: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x80201204: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80201208: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_8020120C:
    // 0x8020120C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201210: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201214: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201218: jr          $ra
    // 0x8020121C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020121C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201220(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201228: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020122C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201230: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201234: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020123C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201240: bne         $t7, $zero, L_802012FC
    if (ctx->r15 != 0) {
        // 0x80201244: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802012FC;
    }
    // 0x80201244: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201248: jal         0x80005E44
    // 0x8020124C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020124C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201250: jal         0x80006214
    // 0x80201254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020125C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201260: addiu       $a2, $zero, 0x215
    ctx->r6 = ADD32(0, 0X215);
    // 0x80201264: jal         0x8012C89C
    // 0x80201268: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201268: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8020126C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201270: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201274: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201278: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020127C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201280: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201284: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201288: lwc1        $f4, -0x6A3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A3C);
    // 0x8020128C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201290: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201294: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201298: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020129C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802012A0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x802012A4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x802012A8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x802012AC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802012B0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802012B4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802012B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802012BC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802012C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802012C4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802012C8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802012CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802012D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802012D4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802012D8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802012DC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802012E0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802012E4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802012E8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802012EC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802012F0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802012F4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802012F8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802012FC:
    // 0x802012FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80201300: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80201304: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80201308: jr          $ra
    // 0x8020130C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8020130C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201310(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201318: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020131C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201320: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201324: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020132C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201330: bne         $t7, $zero, L_802013EC
    if (ctx->r15 != 0) {
        // 0x80201334: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802013EC;
    }
    // 0x80201334: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201338: jal         0x80005E44
    // 0x8020133C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020133C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201340: jal         0x80006214
    // 0x80201344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020134C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201350: addiu       $a2, $zero, 0x214
    ctx->r6 = ADD32(0, 0X214);
    // 0x80201354: jal         0x8012C89C
    // 0x80201358: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201358: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8020135C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201360: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201364: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201368: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020136C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201370: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201374: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201378: lwc1        $f4, -0x6A38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A38);
    // 0x8020137C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201380: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201388: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020138C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201390: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201394: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201398: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020139C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x802013A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x802013A4: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x802013A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x802013AC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802013B0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802013B4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802013B8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802013BC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802013C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802013C4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802013C8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802013CC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802013D0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802013D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802013D8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802013DC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802013E0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802013E4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802013E8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802013EC:
    // 0x802013EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802013F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802013F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802013F8: jr          $ra
    // 0x802013FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802013FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_80201400(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_80201400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80201400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80201404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80201408: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8020140C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201410: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201414: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020141C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201420: bne         $t7, $zero, L_802014DC
    if (ctx->r15 != 0) {
        // 0x80201424: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802014DC;
    }
    // 0x80201424: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201428: jal         0x80005E44
    // 0x8020142C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020142C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201430: jal         0x80006214
    // 0x80201434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020143C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201440: addiu       $a2, $zero, 0x215
    ctx->r6 = ADD32(0, 0X215);
    // 0x80201444: jal         0x8012C89C
    // 0x80201448: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201448: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8020144C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201450: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201454: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201458: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020145C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201460: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201464: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201468: lwc1        $f4, -0x6A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A34);
    // 0x8020146C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201470: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201474: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201478: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020147C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201480: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201484: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201488: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020148C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201490: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201494: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201498: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020149C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x802014A0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x802014A4: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x802014A8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x802014AC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802014B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802014B4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802014B8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802014BC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802014C0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802014C4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802014C8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802014CC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802014D0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802014D4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802014D8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802014DC:
    // 0x802014DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802014E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802014E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802014E8: jr          $ra
    // 0x802014EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802014EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802014f0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802014f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802014F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802014F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802014F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802014FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80201500: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x80201504: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80201508: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8020150C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201510: bne         $t7, $zero, L_802015CC
    if (ctx->r15 != 0) {
        // 0x80201514: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802015CC;
    }
    // 0x80201514: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201518: jal         0x80005E44
    // 0x8020151C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020151C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201520: jal         0x80006214
    // 0x80201524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020152C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201530: addiu       $a2, $zero, 0x216
    ctx->r6 = ADD32(0, 0X216);
    // 0x80201534: jal         0x8012C89C
    // 0x80201538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8020153C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201540: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201544: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201548: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020154C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201550: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201554: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201558: lwc1        $f4, -0x6A30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A30);
    // 0x8020155C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201560: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201568: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020156C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201570: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201574: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201578: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020157C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201580: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201584: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201588: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020158C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201590: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201594: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201598: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020159C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x802015A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x802015A4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x802015A8: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x802015AC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802015B0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802015B4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802015B8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802015BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802015C0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802015C4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802015C8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802015CC:
    // 0x802015CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802015D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802015D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802015D8: jr          $ra
    // 0x802015DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802015DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802015e0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_802015e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802015E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802015E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802015E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x802015EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x802015F0: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x802015F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x802015F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x802015FC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80201600: bne         $t7, $zero, L_802016BC
    if (ctx->r15 != 0) {
        // 0x80201604: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_802016BC;
    }
    // 0x80201604: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80201608: jal         0x80005E44
    // 0x8020160C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8020160C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80201610: jal         0x80006214
    // 0x80201614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80201614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80201618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8020161C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80201620: addiu       $a2, $zero, 0x216
    ctx->r6 = ADD32(0, 0X216);
    // 0x80201624: jal         0x8012C89C
    // 0x80201628: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80201628: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8020162C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201630: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80201634: addiu       $t8, $t8, -0x52D8
    ctx->r24 = ADD32(ctx->r24, -0X52D8);
    // 0x80201638: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8020163C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80201640: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80201644: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80201648: lwc1        $f4, -0x6A2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A2C);
    // 0x8020164C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80201650: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80201654: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80201658: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x8020165C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80201660: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80201664: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80201668: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8020166C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80201670: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80201674: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80201678: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8020167C: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80201680: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80201684: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80201688: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8020168C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80201690: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80201694: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80201698: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x8020169C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x802016A0: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x802016A4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x802016A8: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x802016AC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x802016B0: lh          $t2, 0x9C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9C);
    // 0x802016B4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x802016B8: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
L_802016BC:
    // 0x802016BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802016C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x802016C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x802016C8: jr          $ra
    // 0x802016CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x802016CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_802016d0(rdram, ctx);
;}
