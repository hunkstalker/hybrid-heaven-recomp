#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8014418c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014418C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80144190: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80144194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80144198: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014419C: addiu       $t7, $t7, 0x151C
    ctx->r15 = ADD32(ctx->r15, 0X151C);
    // 0x801441A0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801441A4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x801441A8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801441AC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801441B0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801441B4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801441B8: addiu       $s0, $s0, -0x13AE
    ctx->r16 = ADD32(ctx->r16, -0X13AE);
    // 0x801441BC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801441C0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801441C4: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x801441C8: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x801441CC: addiu       $t4, $zero, 0x9E
    ctx->r12 = ADD32(0, 0X9E);
    // 0x801441D0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801441D4: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x801441D8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x801441DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801441E0: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    // 0x801441E4: subu        $a2, $t2, $t3
    ctx->r6 = SUB32(ctx->r10, ctx->r11);
    // 0x801441E8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801441EC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801441F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801441F4: jal         0x80144A4C
    // 0x801441F8: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_0;
    // 0x801441F8: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_0:
    // 0x801441FC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80144200: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80144204: addiu       $t7, $zero, 0x9E
    ctx->r15 = ADD32(0, 0X9E);
    // 0x80144208: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014420C: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80144210: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144214: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144218: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8014421C: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x80144220: jal         0x80144A4C
    // 0x80144224: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80144224: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x80144228: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8014422C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80144230: addiu       $t0, $zero, 0x9E
    ctx->r8 = ADD32(0, 0X9E);
    // 0x80144234: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80144238: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    // 0x8014423C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144240: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144244: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80144248: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x8014424C: jal         0x80144A4C
    // 0x80144250: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_2;
    // 0x80144250: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_2:
    // 0x80144254: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80144258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014425C: slti        $at, $t1, 0x2E
    ctx->r1 = SIGNED(ctx->r9) < 0X2E ? 1 : 0;
    // 0x80144260: bne         $at, $zero, L_80144278
    if (ctx->r1 != 0) {
        // 0x80144264: nop
    
            goto L_80144278;
    }
    // 0x80144264: nop

    // 0x80144268: jal         0x801444B0
    // 0x8014426C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801444B0)(rdram, ctx);
        goto after_3;
    // 0x8014426C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80144270: b           L_80144278
    // 0x80144274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80144278;
    // 0x80144274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80144278:
    // 0x80144278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014427C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80144280: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80144284: jr          $ra
    // 0x80144288: nop

    return;
    // 0x80144288: nop

;}
RECOMP_FUNC void M7_FUN_8014428c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014428C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80144290: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80144294: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80144298: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8014429C: addiu       $t7, $t7, 0x1528
    ctx->r15 = ADD32(ctx->r15, 0X1528);
    // 0x801442A0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801442A4: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x801442A8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801442AC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801442B0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801442B4: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801442B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801442BC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801442C0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801442C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801442C8: sh          $t0, -0x13AE($at)
    MEM_H(-0X13AE, ctx->r1) = ctx->r8;
    // 0x801442CC: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x801442D0: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x801442D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801442D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801442DC: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x801442E0: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x801442E4: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x801442E8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801442EC: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    // 0x801442F0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801442F4: lbu         $t4, 0x6($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6);
    // 0x801442F8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801442FC: lbu         $t5, 0x7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7);
    // 0x80144300: jal         0x8014456C
    // 0x80144304: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_0;
    // 0x80144304: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80144308: addiu       $t6, $zero, 0x9E
    ctx->r14 = ADD32(0, 0X9E);
    // 0x8014430C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80144310: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80144314: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x80144318: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8014431C: jal         0x80144A4C
    // 0x80144320: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80144320: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x80144324: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x80144328: lbu         $a3, 0x8($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X8);
    // 0x8014432C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80144330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80144334: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x80144338: lh          $a1, 0x3C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3C);
    // 0x8014433C: lh          $a2, 0x3E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3E);
    // 0x80144340: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80144344: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x80144348: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8014434C: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80144350: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80144354: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80144358: jal         0x8014456C
    // 0x8014435C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_2;
    // 0x8014435C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_2:
    // 0x80144360: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x80144364: lbu         $a3, 0x10($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X10);
    // 0x80144368: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8014436C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80144370: lbu         $t3, 0x13($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X13);
    // 0x80144374: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x80144378: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x8014437C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80144380: lhu         $t4, 0x14($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X14);
    // 0x80144384: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80144388: lbu         $t5, 0x16($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X16);
    // 0x8014438C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80144390: lbu         $t6, 0x17($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17);
    // 0x80144394: jal         0x8014456C
    // 0x80144398: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8014456C)(rdram, ctx);
        goto after_3;
    // 0x80144398: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_3:
    // 0x8014439C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801443A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801443A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801443A8: jr          $ra
    // 0x801443AC: nop

    return;
    // 0x801443AC: nop

;}
RECOMP_FUNC void M7_FUN_801443b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801443B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801443B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801443B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801443BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801443C0: addiu       $t7, $t7, 0x1534
    ctx->r15 = ADD32(ctx->r15, 0X1534);
    // 0x801443C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801443C8: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x801443CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801443D0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801443D4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801443D8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801443DC: addiu       $s0, $s0, -0x13AE
    ctx->r16 = ADD32(ctx->r16, -0X13AE);
    // 0x801443E0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801443E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801443E8: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x801443EC: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x801443F0: addiu       $t4, $zero, 0x9E
    ctx->r12 = ADD32(0, 0X9E);
    // 0x801443F4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801443F8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x801443FC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80144400: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80144404: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    // 0x80144408: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8014440C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144410: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144414: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80144418: jal         0x80144A4C
    // 0x8014441C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_0;
    // 0x8014441C: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_0:
    // 0x80144420: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80144424: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80144428: addiu       $t7, $zero, 0x9E
    ctx->r15 = ADD32(0, 0X9E);
    // 0x8014442C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80144430: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80144434: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144438: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8014443C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80144440: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x80144444: jal         0x80144A4C
    // 0x80144448: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_1;
    // 0x80144448: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_1:
    // 0x8014444C: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80144450: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80144454: addiu       $t0, $zero, 0x9E
    ctx->r8 = ADD32(0, 0X9E);
    // 0x80144458: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8014445C: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80144460: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144464: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144468: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8014446C: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x80144470: jal         0x80144A4C
    // 0x80144474: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    LOOKUP_FUNC(0x80144A4C)(rdram, ctx);
        goto after_2;
    // 0x80144474: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    after_2:
    // 0x80144478: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8014447C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144480: slti        $at, $t1, 0x2E
    ctx->r1 = SIGNED(ctx->r9) < 0X2E ? 1 : 0;
    // 0x80144484: bne         $at, $zero, L_8014449C
    if (ctx->r1 != 0) {
        // 0x80144488: nop
    
            goto L_8014449C;
    }
    // 0x80144488: nop

    // 0x8014448C: jal         0x801444B0
    // 0x80144490: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801444B0)(rdram, ctx);
        goto after_3;
    // 0x80144490: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80144494: b           L_8014449C
    // 0x80144498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014449C;
    // 0x80144498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014449C:
    // 0x8014449C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801444A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801444A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801444A8: jr          $ra
    // 0x801444AC: nop

    return;
    // 0x801444AC: nop

;}
RECOMP_FUNC void M7_FUN_801444b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801444B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801444B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801444B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801444BC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801444C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801444C4: addiu       $a1, $a1, -0x9DC
    ctx->r5 = ADD32(ctx->r5, -0X9DC);
    // 0x801444C8: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x801444CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801444D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801444D4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801444D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801444DC: jal         0x8001A804
    // 0x801444E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x801444E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801444E4: lbu         $s0, 0x33($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X33);
    // 0x801444E8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801444EC: addiu       $a3, $a3, -0x9CC
    ctx->r7 = ADD32(ctx->r7, -0X9CC);
    // 0x801444F0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x801444F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801444F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801444FC: jal         0x8001B204
    // 0x80144500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80144500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80144504: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80144508: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014450C: addiu       $a3, $a3, -0x9C8
    ctx->r7 = ADD32(ctx->r7, -0X9C8);
    // 0x80144510: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144518: jal         0x8001B204
    // 0x8014451C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x8014451C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80144520: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x80144524: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144528: addiu       $a3, $a3, -0x9C4
    ctx->r7 = ADD32(ctx->r7, -0X9C4);
    // 0x8014452C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144534: jal         0x8001B204
    // 0x80144538: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x80144538: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8014453C: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    // 0x80144540: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144544: addiu       $a3, $a3, -0x9C0
    ctx->r7 = ADD32(ctx->r7, -0X9C0);
    // 0x80144548: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014454C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144550: jal         0x8001B204
    // 0x80144554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x80144554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80144558: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8014455C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80144560: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80144564: jr          $ra
    // 0x80144568: nop

    return;
    // 0x80144568: nop

;}
RECOMP_FUNC void M7_FUN_8014456c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014456C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80144570: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80144574: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80144578: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8014457C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80144580: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80144584: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80144588: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8014458C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80144590: addiu       $t7, $t7, 0x1540
    ctx->r15 = ADD32(ctx->r15, 0X1540);
    // 0x80144594: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80144598: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8014459C: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x801445A0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801445A4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801445A8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801445AC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801445B0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801445B4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801445B8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801445BC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801445C0: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801445C4: addiu       $t2, $t2, 0x1560
    ctx->r10 = ADD32(ctx->r10, 0X1560);
    // 0x801445C8: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801445CC: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801445D0: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801445D4: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x801445D8: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x801445DC: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x801445E0: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x801445E4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801445E8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801445EC: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x801445F0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x801445F4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801445F8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801445FC: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80144600: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80144604: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80144608: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x8014460C: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80144610: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80144614: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x80144618: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    // 0x8014461C: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80144620: sw          $t3, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r11;
    // 0x80144624: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80144628: sw          $t4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r12;
    // 0x8014462C: andi        $s0, $a3, 0xFF
    ctx->r16 = ctx->r7 & 0XFF;
    // 0x80144630: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80144634: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80144638: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x8014463C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80144640: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x80144644: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80144648: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014464C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80144650: addiu       $t5, $zero, 0x6E
    ctx->r13 = ADD32(0, 0X6E);
    // 0x80144654: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80144658: addiu       $a1, $a1, -0x9BC
    ctx->r5 = ADD32(ctx->r5, -0X9BC);
    // 0x8014465C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80144660: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80144664: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80144668: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8014466C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80144670: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80144674: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80144678: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8014467C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80144680: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80144684: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80144688: lh          $a2, 0xA6($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XA6);
    // 0x8014468C: jal         0x8001A804
    // 0x80144690: lbu         $a0, 0xA3($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0XA3);
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80144690: lbu         $a0, 0xA3($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0XA3);
    after_0:
    // 0x80144694: sltiu       $at, $s0, 0x5
    ctx->r1 = ctx->r16 < 0X5 ? 1 : 0;
    // 0x80144698: lbu         $v0, 0xA3($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA3);
    // 0x8014469C: beq         $at, $zero, L_80144A38
    if (ctx->r1 == 0) {
        // 0x801446A0: lh          $v1, 0xA6($sp)
        ctx->r3 = MEM_H(ctx->r29, 0XA6);
            goto L_80144A38;
    }
    // 0x801446A0: lh          $v1, 0xA6($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XA6);
    // 0x801446A4: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x801446A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801446AC: addu        $at, $at, $t4
    gpr jr_addend_801446B4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801446B0: lw          $t4, -0x7DC($at)
    ctx->r12 = ADD32(ctx->r1, -0X7DC);
    // 0x801446B4: jr          $t4
    // 0x801446B8: nop

    switch (jr_addend_801446B4 >> 2) {
        case 0: goto L_801446BC; break;
        case 1: goto L_80144730; break;
        case 2: goto L_801448CC; break;
        case 3: goto L_80144940; break;
        case 4: goto L_801449C0; break;
        default: switch_error(__func__, 0x801446B4, 0x8018F824);
    }
    // 0x801446B8: nop

L_801446BC:
    // 0x801446BC: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x801446C0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801446C4: addiu       $a3, $a3, -0x980
    ctx->r7 = ADD32(ctx->r7, -0X980);
    // 0x801446C8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801446CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801446D0: jal         0x8001B204
    // 0x801446D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801446D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801446D8: lh          $v1, 0xA6($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XA6);
    // 0x801446DC: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x801446E0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801446E4: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x801446E8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801446EC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x801446F0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801446F4: addiu       $a3, $a3, -0x97C
    ctx->r7 = ADD32(ctx->r7, -0X97C);
    // 0x801446F8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801446FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80144700: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144704: jal         0x8001B204
    // 0x80144708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x80144708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8014470C: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x80144710: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144714: addiu       $a3, $a3, -0x964
    ctx->r7 = ADD32(ctx->r7, -0X964);
    // 0x80144718: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014471C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144720: jal         0x8001B204
    // 0x80144724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x80144724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80144728: b           L_80144A3C
    // 0x8014472C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80144A3C;
    // 0x8014472C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80144730:
    // 0x80144730: lbu         $t5, 0xB3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XB3);
    // 0x80144734: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80144738: lbu         $t0, 0xBF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XBF);
    // 0x8014473C: bne         $t5, $at, L_80144780
    if (ctx->r13 != ctx->r1) {
        // 0x80144740: sll         $s0, $v0, 2
        ctx->r16 = S32(ctx->r2 << 2);
            goto L_80144780;
    }
    // 0x80144740: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80144744: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80144748: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8014474C: addiu       $a2, $s1, -0x2
    ctx->r6 = ADD32(ctx->r17, -0X2);
    // 0x80144750: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144754: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80144758: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8014475C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144760: addiu       $a3, $a3, -0x960
    ctx->r7 = ADD32(ctx->r7, -0X960);
    // 0x80144764: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80144768: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8014476C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144770: jal         0x8001B204
    // 0x80144774: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x80144774: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80144778: b           L_801447CC
    // 0x8014477C: lbu         $v0, 0xC3($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XC3);
        goto L_801447CC;
    // 0x8014477C: lbu         $v0, 0xC3($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XC3);
L_80144780:
    // 0x80144780: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144784: addu        $t6, $sp, $t0
    ctx->r14 = ADD32(ctx->r29, ctx->r8);
    // 0x80144788: lbu         $t6, 0x80($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X80);
    // 0x8014478C: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80144790: addu        $t7, $sp, $t0
    ctx->r15 = ADD32(ctx->r29, ctx->r8);
    // 0x80144794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80144798: lbu         $t7, 0x60($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X60);
    // 0x8014479C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801447A0: addiu       $a2, $s1, -0x2
    ctx->r6 = ADD32(ctx->r17, -0X2);
    // 0x801447A4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801447A8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801447AC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801447B0: addiu       $a3, $a3, -0x944
    ctx->r7 = ADD32(ctx->r7, -0X944);
    // 0x801447B4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801447B8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801447BC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801447C0: jal         0x8001B204
    // 0x801447C4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801447C4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_5:
    // 0x801447C8: lbu         $v0, 0xC3($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XC3);
L_801447CC:
    // 0x801447CC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x801447D0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801447D4: beq         $v0, $zero, L_801447FC
    if (ctx->r2 == 0) {
        // 0x801447D8: lh          $a1, 0x56($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X56);
            goto L_801447FC;
    }
    // 0x801447D8: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    // 0x801447DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801447E0: beq         $v0, $at, L_80144828
    if (ctx->r2 == ctx->r1) {
        // 0x801447E4: addiu       $a0, $s0, 0x1
        ctx->r4 = ADD32(ctx->r16, 0X1);
            goto L_80144828;
    }
    // 0x801447E4: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x801447E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801447EC: beq         $v0, $at, L_8014485C
    if (ctx->r2 == ctx->r1) {
        // 0x801447F0: addiu       $a0, $s0, 0x1
        ctx->r4 = ADD32(ctx->r16, 0X1);
            goto L_8014485C;
    }
    // 0x801447F0: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x801447F4: b           L_8014488C
    // 0x801447F8: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
        goto L_8014488C;
    // 0x801447F8: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
L_801447FC:
    // 0x801447FC: lbu         $t8, 0xB7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XB7);
    // 0x80144800: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x80144804: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144808: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014480C: addiu       $a3, $a3, -0x924
    ctx->r7 = ADD32(ctx->r7, -0X924);
    // 0x80144810: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144818: jal         0x8001B204
    // 0x8014481C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x8014481C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x80144820: b           L_8014488C
    // 0x80144824: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
        goto L_8014488C;
    // 0x80144824: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
L_80144828:
    // 0x80144828: lbu         $t9, 0xB7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XB7);
    // 0x8014482C: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x80144830: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144834: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144838: addiu       $a3, $a3, -0x904
    ctx->r7 = ADD32(ctx->r7, -0X904);
    // 0x8014483C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144840: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144844: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    // 0x80144848: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014484C: jal         0x8001B204
    // 0x80144850: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x80144850: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_7:
    // 0x80144854: b           L_8014488C
    // 0x80144858: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
        goto L_8014488C;
    // 0x80144858: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
L_8014485C:
    // 0x8014485C: lbu         $t1, 0xB7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XB7);
    // 0x80144860: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x80144864: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144868: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014486C: addiu       $a3, $a3, -0x8E4
    ctx->r7 = ADD32(ctx->r7, -0X8E4);
    // 0x80144870: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144874: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144878: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    // 0x8014487C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144880: jal         0x8001B204
    // 0x80144884: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x80144884: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_8:
    // 0x80144888: lhu         $v0, 0xBA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XBA);
L_8014488C:
    // 0x8014488C: addiu       $a2, $s1, 0x16
    ctx->r6 = ADD32(ctx->r17, 0X16);
    // 0x80144890: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144894: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x80144898: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014489C: sra         $t2, $v0, 6
    ctx->r10 = S32(SIGNED(ctx->r2) >> 6);
    // 0x801448A0: andi        $t3, $v0, 0x3F
    ctx->r11 = ctx->r2 & 0X3F;
    // 0x801448A4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801448A8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801448AC: addiu       $a3, $a3, -0x8C4
    ctx->r7 = ADD32(ctx->r7, -0X8C4);
    // 0x801448B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801448B4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801448B8: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    // 0x801448BC: jal         0x8001B204
    // 0x801448C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801448C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x801448C4: b           L_80144A3C
    // 0x801448C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80144A3C;
    // 0x801448C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801448CC:
    // 0x801448CC: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x801448D0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801448D4: addiu       $a3, $a3, -0x8A8
    ctx->r7 = ADD32(ctx->r7, -0X8A8);
    // 0x801448D8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801448DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801448E0: jal         0x8001B204
    // 0x801448E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801448E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x801448E8: lh          $v1, 0xA6($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XA6);
    // 0x801448EC: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x801448F0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801448F4: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x801448F8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801448FC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80144900: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144904: addiu       $a3, $a3, -0x8A4
    ctx->r7 = ADD32(ctx->r7, -0X8A4);
    // 0x80144908: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014490C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80144910: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144914: jal         0x8001B204
    // 0x80144918: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x80144918: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x8014491C: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x80144920: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144924: addiu       $a3, $a3, -0x888
    ctx->r7 = ADD32(ctx->r7, -0X888);
    // 0x80144928: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014492C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144930: jal         0x8001B204
    // 0x80144934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x80144934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80144938: b           L_80144A3C
    // 0x8014493C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80144A3C;
    // 0x8014493C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80144940:
    // 0x80144940: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80144944: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80144948: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x8014494C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144950: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80144954: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80144958: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014495C: addiu       $a3, $a3, -0x884
    ctx->r7 = ADD32(ctx->r7, -0X884);
    // 0x80144960: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80144964: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80144968: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8014496C: jal         0x8001B204
    // 0x80144970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x80144970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80144974: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    // 0x80144978: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8014497C: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80144980: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144984: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80144988: addiu       $a3, $a3, -0x87C
    ctx->r7 = ADD32(ctx->r7, -0X87C);
    // 0x8014498C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144990: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144994: jal         0x8001B204
    // 0x80144998: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x80144998: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x8014499C: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x801449A0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801449A4: addiu       $a3, $a3, -0x85C
    ctx->r7 = ADD32(ctx->r7, -0X85C);
    // 0x801449A8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801449AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801449B0: jal         0x8001B204
    // 0x801449B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801449B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x801449B8: b           L_80144A3C
    // 0x801449BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80144A3C;
    // 0x801449BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801449C0:
    // 0x801449C0: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x801449C4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801449C8: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x801449CC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801449D0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801449D4: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x801449D8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801449DC: addiu       $a3, $a3, -0x858
    ctx->r7 = ADD32(ctx->r7, -0X858);
    // 0x801449E0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801449E4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801449E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801449EC: jal         0x8001B204
    // 0x801449F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x801449F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x801449F4: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    // 0x801449F8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801449FC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80144A00: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144A04: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80144A08: addiu       $a3, $a3, -0x850
    ctx->r7 = ADD32(ctx->r7, -0X850);
    // 0x80144A0C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144A10: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144A14: jal         0x8001B204
    // 0x80144A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x80144A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80144A1C: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // 0x80144A20: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80144A24: addiu       $a3, $a3, -0x830
    ctx->r7 = ADD32(ctx->r7, -0X830);
    // 0x80144A28: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80144A30: jal         0x8001B204
    // 0x80144A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_18;
    // 0x80144A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_80144A38:
    // 0x80144A38: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80144A3C:
    // 0x80144A3C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80144A40: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80144A44: jr          $ra
    // 0x80144A48: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80144A48: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80144a4c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80144a4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144A4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80144A50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80144A54: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80144A58: sll         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6 << 16);
    // 0x80144A5C: sll         $s2, $a3, 16
    ctx->r18 = S32(ctx->r7 << 16);
    // 0x80144A60: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80144A64: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80144A68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80144A6C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80144A70: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80144A74: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80144A78: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80144A7C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80144A80: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80144A84: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x80144A88: beq         $at, $zero, L_80144A9C
    if (ctx->r1 == 0) {
        // 0x80144A8C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80144A9C;
    }
    // 0x80144A8C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80144A90: subu        $v0, $s1, $s2
    ctx->r2 = SUB32(ctx->r17, ctx->r18);
    // 0x80144A94: addiu       $v0, $v0, 0x23
    ctx->r2 = ADD32(ctx->r2, 0X23);
    // 0x80144A98: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80144A9C:
    // 0x80144A9C: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x80144AA0: addu        $t6, $s0, $v0
    ctx->r14 = ADD32(ctx->r16, ctx->r2);
    // 0x80144AA4: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    // 0x80144AA8: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80144AAC: beq         $at, $zero, L_80144AB8
    if (ctx->r1 == 0) {
        // 0x80144AB0: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_80144AB8;
    }
    // 0x80144AB0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80144AB4: subu        $v0, $t3, $s0
    ctx->r2 = SUB32(ctx->r11, ctx->r16);
L_80144AB8:
    // 0x80144AB8: bgtz        $v0, L_80144AC8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80144ABC: addiu       $a1, $a1, -0x82C
        ctx->r5 = ADD32(ctx->r5, -0X82C);
            goto L_80144AC8;
    }
    // 0x80144ABC: addiu       $a1, $a1, -0x82C
    ctx->r5 = ADD32(ctx->r5, -0X82C);
    // 0x80144AC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144AC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80144AC8:
    // 0x80144AC8: lh          $a2, 0x56($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X56);
    // 0x80144ACC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80144AD0: jal         0x8001A804
    // 0x80144AD4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x80144AD4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80144AD8: addiu       $t1, $s2, 0x2
    ctx->r9 = ADD32(ctx->r18, 0X2);
    // 0x80144ADC: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80144AE0: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x80144AE4: beq         $at, $zero, L_80144AF4
    if (ctx->r1 == 0) {
        // 0x80144AE8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80144AF4;
    }
    // 0x80144AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80144AEC: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x80144AF0: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_80144AF4:
    // 0x80144AF4: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x80144AF8: addiu       $t0, $s1, 0xA
    ctx->r8 = ADD32(ctx->r17, 0XA);
    // 0x80144AFC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80144B00: beq         $at, $zero, L_80144B10
    if (ctx->r1 == 0) {
        // 0x80144B04: lbu         $v0, 0x53($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X53);
            goto L_80144B10;
    }
    // 0x80144B04: lbu         $v0, 0x53($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X53);
    // 0x80144B08: subu        $v1, $t0, $t3
    ctx->r3 = SUB32(ctx->r8, ctx->r11);
    // 0x80144B0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80144B10:
    // 0x80144B10: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    // 0x80144B14: addiu       $a2, $s1, -0x2
    ctx->r6 = ADD32(ctx->r17, -0X2);
    // 0x80144B18: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144B1C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80144B20: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80144B24: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80144B28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80144B2C: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    // 0x80144B30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80144B34: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80144B38: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80144B3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80144B40: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144B44: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80144B48: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80144B4C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80144B50: jal         0x8001B194
    // 0x80144B54: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B194)(rdram, ctx);
        goto after_1;
    // 0x80144B54: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_1:
    // 0x80144B58: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80144B5C: addiu       $v0, $s1, 0xC
    ctx->r2 = ADD32(ctx->r17, 0XC);
    // 0x80144B60: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80144B64: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80144B68: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80144B6C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80144B70: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x80144B74: beq         $at, $zero, L_80144B84
    if (ctx->r1 == 0) {
        // 0x80144B78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80144B84;
    }
    // 0x80144B78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80144B7C: subu        $v1, $v0, $s2
    ctx->r3 = SUB32(ctx->r2, ctx->r18);
    // 0x80144B80: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_80144B84:
    // 0x80144B84: addiu       $v0, $s0, 0xA
    ctx->r2 = ADD32(ctx->r16, 0XA);
    // 0x80144B88: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80144B8C: beq         $at, $zero, L_80144B9C
    if (ctx->r1 == 0) {
        // 0x80144B90: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80144B9C;
    }
    // 0x80144B90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80144B94: subu        $v1, $v0, $t3
    ctx->r3 = SUB32(ctx->r2, ctx->r11);
    // 0x80144B98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80144B9C:
    // 0x80144B9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80144BA0: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x80144BA4: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    // 0x80144BA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80144BAC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144BB0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144BB4: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80144BB8: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80144BBC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80144BC0: jal         0x8001B194
    // 0x80144BC4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B194)(rdram, ctx);
        goto after_2;
    // 0x80144BC4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_2:
    // 0x80144BC8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80144BCC: addiu       $v0, $s1, 0x18
    ctx->r2 = ADD32(ctx->r17, 0X18);
    // 0x80144BD0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80144BD4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80144BD8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80144BDC: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x80144BE0: beq         $at, $zero, L_80144BF0
    if (ctx->r1 == 0) {
        // 0x80144BE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80144BF0;
    }
    // 0x80144BE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80144BE8: subu        $v1, $v0, $s2
    ctx->r3 = SUB32(ctx->r2, ctx->r18);
    // 0x80144BEC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_80144BF0:
    // 0x80144BF0: addiu       $v0, $s0, 0xA
    ctx->r2 = ADD32(ctx->r16, 0XA);
    // 0x80144BF4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80144BF8: beq         $at, $zero, L_80144C08
    if (ctx->r1 == 0) {
        // 0x80144BFC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80144C08;
    }
    // 0x80144BFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80144C00: subu        $v1, $v0, $t3
    ctx->r3 = SUB32(ctx->r2, ctx->r11);
    // 0x80144C04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80144C08:
    // 0x80144C08: addiu       $a2, $s1, 0x16
    ctx->r6 = ADD32(ctx->r17, 0X16);
    // 0x80144C0C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80144C10: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80144C14: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80144C18: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80144C1C: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80144C20: jal         0x8001B194
    // 0x80144C24: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    LOOKUP_FUNC(0x8001B194)(rdram, ctx);
        goto after_3;
    // 0x80144C24: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    after_3:
    // 0x80144C28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80144C2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80144C30: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80144C34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80144C38: jr          $ra
    // 0x80144C3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80144C3C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80144c40(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80144c40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144C40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80144C44: addiu       $t6, $t6, 0x1580
    ctx->r14 = ADD32(ctx->r14, 0X1580);
    // 0x80144C48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80144C4C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80144C50: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80144C54: addiu       $a2, $a2, -0x225C
    ctx->r6 = ADD32(ctx->r6, -0X225C);
    // 0x80144C58: addiu       $a1, $a1, -0x23C0
    ctx->r5 = ADD32(ctx->r5, -0X23C0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80144c5c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80144c5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144C5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80144C60: lbu         $t2, 0x88($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X88);
    // 0x80144C64: lbu         $t3, 0x2($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X2);
    // 0x80144C68: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80144C6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80144C70: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80144C74: lhu         $t9, 0x9C($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X9C);
    // 0x80144C78: lhu         $t0, 0x0($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X0);
    // 0x80144C7C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80144C80: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80144C84: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x80144C88: lbu         $t5, 0x89($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X89);
    // 0x80144C8C: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80144C90: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80144C94: lhu         $t9, 0x4($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4);
    // 0x80144C98: lhu         $t8, 0x8A($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X8A);
    // 0x80144C9C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80144CA0: lhu         $t2, 0x4($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4);
    // 0x80144CA4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80144CA8: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x80144CAC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80144CB0: sh          $t1, 0x9C($a1)
    MEM_H(0X9C, ctx->r5) = ctx->r9;
    // 0x80144CB4: sb          $t4, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r12;
    // 0x80144CB8: sh          $t0, 0x8A($a1)
    MEM_H(0X8A, ctx->r5) = ctx->r8;
    // 0x80144CBC: sh          $t2, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r10;
    // 0x80144CC0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80144CC4: addiu       $t7, $a1, 0x9C
    ctx->r15 = ADD32(ctx->r5, 0X9C);
    // 0x80144CC8: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
L_80144CCC:
    // 0x80144CCC: lwl         $t5, 0x0($t6)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r14, 0X0);
    // 0x80144CD0: lwr         $t5, 0x3($t6)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r14, 0X3);
    // 0x80144CD4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80144CD8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80144CDC: swl         $t5, -0xC($t3)
    do_swl(rdram, -0XC, ctx->r11, ctx->r13);
    // 0x80144CE0: swr         $t5, -0x9($t3)
    do_swr(rdram, -0X9, ctx->r11, ctx->r13);
    // 0x80144CE4: lwl         $t4, -0x8($t6)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r14, -0X8);
    // 0x80144CE8: lwr         $t4, -0x5($t6)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r14, -0X5);
    // 0x80144CEC: swl         $t4, -0x8($t3)
    do_swl(rdram, -0X8, ctx->r11, ctx->r12);
    // 0x80144CF0: swr         $t4, -0x5($t3)
    do_swr(rdram, -0X5, ctx->r11, ctx->r12);
    // 0x80144CF4: lwl         $t5, -0x4($t6)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r14, -0X4);
    // 0x80144CF8: lwr         $t5, -0x1($t6)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r14, -0X1);
    // 0x80144CFC: swl         $t5, -0x4($t3)
    do_swl(rdram, -0X4, ctx->r11, ctx->r13);
    // 0x80144D00: bne         $t6, $t7, L_80144CCC
    if (ctx->r14 != ctx->r15) {
        // 0x80144D04: swr         $t5, -0x1($t3)
        do_swr(rdram, -0X1, ctx->r11, ctx->r13);
            goto L_80144CCC;
    }
    // 0x80144D04: swr         $t5, -0x1($t3)
    do_swr(rdram, -0X1, ctx->r11, ctx->r13);
    // 0x80144D08: lhu         $t5, 0x0($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X0);
    // 0x80144D0C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80144D10: addiu       $a1, $a1, 0x3CE0
    ctx->r5 = ADD32(ctx->r5, 0X3CE0);
    // 0x80144D14: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x80144D18: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80144D1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144D20: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80144D24: addiu       $t9, $t8, 0x9E
    ctx->r25 = ADD32(ctx->r24, 0X9E);
    // 0x80144D28: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80144D2C:
    // 0x80144D2C: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144D30: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80144D34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144D38: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144D3C: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    // 0x80144D40: mflo        $t0
    ctx->r8 = lo;
    // 0x80144D44: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
    // 0x80144D48: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80144D4C: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80144D50: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80144D54: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80144D58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80144D5C: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80144D60: sb          $t3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r11;
    // 0x80144D64: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80144D68: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80144D6C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80144D70: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x80144D74: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x80144D78: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80144D7C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80144D80: bne         $at, $zero, L_80144D2C
    if (ctx->r1 != 0) {
        // 0x80144D84: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_80144D2C;
    }
    // 0x80144D84: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80144D88: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144D8C: addiu       $v1, $v1, -0x1FFC
    ctx->r3 = ADD32(ctx->r3, -0X1FFC);
    // 0x80144D90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144D94:
    // 0x80144D94: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80144D98: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x80144D9C: lbu         $t3, 0x4($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X4);
    // 0x80144DA0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80144DA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144DA8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144DAC: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x80144DB0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80144DB4: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80144DB8: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80144DBC: bne         $at, $zero, L_80144D94
    if (ctx->r1 != 0) {
        // 0x80144DC0: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_80144D94;
    }
    // 0x80144DC0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80144DC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144DC8: addiu       $v1, $v1, -0x20EC
    ctx->r3 = ADD32(ctx->r3, -0X20EC);
    // 0x80144DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144DD0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80144DD4:
    // 0x80144DD4: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144DD8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80144DDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144DE0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144DE4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80144DE8: mflo        $t0
    ctx->r8 = lo;
    // 0x80144DEC: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80144DF0: lwl         $t7, 0x0($t1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r9, 0X0);
    // 0x80144DF4: lwr         $t7, 0x3($t1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r9, 0X3);
    // 0x80144DF8: swl         $t7, 0x0($t9)
    do_swl(rdram, 0X0, ctx->r25, ctx->r15);
    // 0x80144DFC: swr         $t7, 0x3($t9)
    do_swr(rdram, 0X3, ctx->r25, ctx->r15);
    // 0x80144E00: lbu         $t7, 0x4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X4);
    // 0x80144E04: sb          $t7, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r15;
    // 0x80144E08: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80144E0C: sb          $t2, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r10;
    // 0x80144E10: lbu         $t7, 0x6($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X6);
    // 0x80144E14: sb          $t7, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r15;
    // 0x80144E18: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80144E1C: addiu       $t3, $t6, 0x7
    ctx->r11 = ADD32(ctx->r14, 0X7);
    // 0x80144E20: bne         $at, $zero, L_80144DD4
    if (ctx->r1 != 0) {
        // 0x80144E24: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_80144DD4;
    }
    // 0x80144E24: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80144E28: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144E2C: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80144E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144E34:
    // 0x80144E34: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x80144E38: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x80144E3C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80144E40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144E44: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144E48: sb          $t5, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r13;
    // 0x80144E4C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80144E50: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80144E54: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80144E58: bne         $at, $zero, L_80144E34
    if (ctx->r1 != 0) {
        // 0x80144E5C: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_80144E34;
    }
    // 0x80144E5C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80144E60: jr          $ra
    // 0x80144E64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80144E64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80144e68(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80144e68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144E68: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80144E6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80144E70: addiu       $t6, $t6, -0x23C0
    ctx->r14 = ADD32(ctx->r14, -0X23C0);
    // 0x80144E74: addiu       $t0, $t7, 0x9C
    ctx->r8 = ADD32(ctx->r15, 0X9C);
L_80144E78:
    // 0x80144E78: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x80144E7C: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x80144E80: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80144E84: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80144E88: swl         $t9, -0xC($t6)
    do_swl(rdram, -0XC, ctx->r14, ctx->r25);
    // 0x80144E8C: swr         $t9, -0x9($t6)
    do_swr(rdram, -0X9, ctx->r14, ctx->r25);
    // 0x80144E90: lwl         $t8, -0x8($t7)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r15, -0X8);
    // 0x80144E94: lwr         $t8, -0x5($t7)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r15, -0X5);
    // 0x80144E98: swl         $t8, -0x8($t6)
    do_swl(rdram, -0X8, ctx->r14, ctx->r24);
    // 0x80144E9C: swr         $t8, -0x5($t6)
    do_swr(rdram, -0X5, ctx->r14, ctx->r24);
    // 0x80144EA0: lwl         $t9, -0x4($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, -0X4);
    // 0x80144EA4: lwr         $t9, -0x1($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, -0X1);
    // 0x80144EA8: swl         $t9, -0x4($t6)
    do_swl(rdram, -0X4, ctx->r14, ctx->r25);
    // 0x80144EAC: bne         $t7, $t0, L_80144E78
    if (ctx->r15 != ctx->r8) {
        // 0x80144EB0: swr         $t9, -0x1($t6)
        do_swr(rdram, -0X1, ctx->r14, ctx->r25);
            goto L_80144E78;
    }
    // 0x80144EB0: swr         $t9, -0x1($t6)
    do_swr(rdram, -0X1, ctx->r14, ctx->r25);
    // 0x80144EB4: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80144EB8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80144EBC: addiu       $a1, $a1, 0x3CE0
    ctx->r5 = ADD32(ctx->r5, 0X3CE0);
    // 0x80144EC0: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80144EC4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80144EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144ECC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80144ED0: addiu       $t2, $t1, 0x9E
    ctx->r10 = ADD32(ctx->r9, 0X9E);
    // 0x80144ED4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_80144ED8:
    // 0x80144ED8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144EDC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80144EE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144EE4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144EE8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80144EEC: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    // 0x80144EF0: mflo        $t3
    ctx->r11 = lo;
    // 0x80144EF4: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x80144EF8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80144EFC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80144F00: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80144F04: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80144F08: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80144F0C: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80144F10: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80144F14: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80144F18: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80144F1C: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x80144F20: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x80144F24: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80144F28: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80144F2C: bne         $at, $zero, L_80144ED8
    if (ctx->r1 != 0) {
        // 0x80144F30: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_80144ED8;
    }
    // 0x80144F30: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80144F34: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144F38: addiu       $v1, $v1, -0x1FFC
    ctx->r3 = ADD32(ctx->r3, -0X1FFC);
    // 0x80144F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144F40:
    // 0x80144F40: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80144F44: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80144F48: addu        $t8, $v1, $t6
    ctx->r24 = ADD32(ctx->r3, ctx->r14);
    // 0x80144F4C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80144F50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144F54: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144F58: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x80144F5C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80144F60: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80144F64: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80144F68: bne         $at, $zero, L_80144F40
    if (ctx->r1 != 0) {
        // 0x80144F6C: sw          $t1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r9;
            goto L_80144F40;
    }
    // 0x80144F6C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80144F70: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144F74: addiu       $v1, $v1, -0x20EC
    ctx->r3 = ADD32(ctx->r3, -0X20EC);
    // 0x80144F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144F7C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80144F80:
    // 0x80144F80: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144F84: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80144F88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144F8C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144F90: lwl         $t0, 0x0($t4)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r12, 0X0);
    // 0x80144F94: lwr         $t0, 0x3($t4)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r12, 0X3);
    // 0x80144F98: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80144F9C: mflo        $t2
    ctx->r10 = lo;
    // 0x80144FA0: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80144FA4: swl         $t0, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r8);
    // 0x80144FA8: swr         $t0, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r8);
    // 0x80144FAC: lbu         $t0, 0x4($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X4);
    // 0x80144FB0: sb          $t0, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r8;
    // 0x80144FB4: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x80144FB8: sb          $t5, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r13;
    // 0x80144FBC: lbu         $t0, 0x6($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X6);
    // 0x80144FC0: sb          $t0, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r8;
    // 0x80144FC4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80144FC8: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80144FCC: bne         $at, $zero, L_80144F80
    if (ctx->r1 != 0) {
        // 0x80144FD0: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_80144F80;
    }
    // 0x80144FD0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80144FD4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80144FD8: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80144FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144FE0:
    // 0x80144FE0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80144FE4: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x80144FE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80144FEC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80144FF0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80144FF4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80144FF8: sb          $t9, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r25;
    // 0x80144FFC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80145000: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80145004: bne         $at, $zero, L_80144FE0
    if (ctx->r1 != 0) {
        // 0x80145008: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_80144FE0;
    }
    // 0x80145008: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8014500C: jr          $ra
    // 0x80145010: nop

    return;
    // 0x80145010: nop

;}
RECOMP_FUNC void M7_FUN_80145014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145014: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80145018: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8014501C: addiu       $t6, $t6, -0x2322
    ctx->r14 = ADD32(ctx->r14, -0X2322);
    // 0x80145020: addiu       $t0, $t7, 0x9C
    ctx->r8 = ADD32(ctx->r15, 0X9C);
L_80145024:
    // 0x80145024: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x80145028: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x8014502C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80145030: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80145034: swl         $t9, -0xC($t6)
    do_swl(rdram, -0XC, ctx->r14, ctx->r25);
    // 0x80145038: swr         $t9, -0x9($t6)
    do_swr(rdram, -0X9, ctx->r14, ctx->r25);
    // 0x8014503C: lwl         $t8, -0x8($t7)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r15, -0X8);
    // 0x80145040: lwr         $t8, -0x5($t7)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r15, -0X5);
    // 0x80145044: swl         $t8, -0x8($t6)
    do_swl(rdram, -0X8, ctx->r14, ctx->r24);
    // 0x80145048: swr         $t8, -0x5($t6)
    do_swr(rdram, -0X5, ctx->r14, ctx->r24);
    // 0x8014504C: lwl         $t9, -0x4($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, -0X4);
    // 0x80145050: lwr         $t9, -0x1($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, -0X1);
    // 0x80145054: swl         $t9, -0x4($t6)
    do_swl(rdram, -0X4, ctx->r14, ctx->r25);
    // 0x80145058: bne         $t7, $t0, L_80145024
    if (ctx->r15 != ctx->r8) {
        // 0x8014505C: swr         $t9, -0x1($t6)
        do_swr(rdram, -0X1, ctx->r14, ctx->r25);
            goto L_80145024;
    }
    // 0x8014505C: swr         $t9, -0x1($t6)
    do_swr(rdram, -0X1, ctx->r14, ctx->r25);
    // 0x80145060: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80145064: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80145068: addiu       $a1, $a1, 0x3CE0
    ctx->r5 = ADD32(ctx->r5, 0X3CE0);
    // 0x8014506C: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80145070: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80145074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80145078: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8014507C: addiu       $t2, $t1, 0x9E
    ctx->r10 = ADD32(ctx->r9, 0X9E);
    // 0x80145080: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_80145084:
    // 0x80145084: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80145088: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8014508C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80145090: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80145094: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80145098: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    // 0x8014509C: mflo        $t3
    ctx->r11 = lo;
    // 0x801450A0: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x801450A4: sb          $t5, 0x204($v1)
    MEM_B(0X204, ctx->r3) = ctx->r13;
    // 0x801450A8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801450AC: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x801450B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801450B4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x801450B8: sh          $t8, 0x206($v1)
    MEM_H(0X206, ctx->r3) = ctx->r24;
    // 0x801450BC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801450C0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801450C4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801450C8: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x801450CC: sb          $t3, 0x208($v1)
    MEM_B(0X208, ctx->r3) = ctx->r11;
    // 0x801450D0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x801450D4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801450D8: bne         $at, $zero, L_80145084
    if (ctx->r1 != 0) {
        // 0x801450DC: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_80145084;
    }
    // 0x801450DC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801450E0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801450E4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801450E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801450EC:
    // 0x801450EC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801450F0: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x801450F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801450F8: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x801450FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80145100: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80145104: sb          $t7, 0xB20($t6)
    MEM_B(0XB20, ctx->r14) = ctx->r15;
    // 0x80145108: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8014510C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80145110: bne         $at, $zero, L_801450EC
    if (ctx->r1 != 0) {
        // 0x80145114: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_801450EC;
    }
    // 0x80145114: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80145118: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8014511C: addiu       $v1, $v1, -0x20D4
    ctx->r3 = ADD32(ctx->r3, -0X20D4);
    // 0x80145120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80145124: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80145128:
    // 0x80145128: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014512C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80145130: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80145134: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80145138: lwl         $t5, 0x0($t3)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r11, 0X0);
    // 0x8014513C: lwr         $t5, 0x3($t3)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r11, 0X3);
    // 0x80145140: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80145144: mflo        $t1
    ctx->r9 = lo;
    // 0x80145148: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8014514C: swl         $t5, 0x0($t2)
    do_swl(rdram, 0X0, ctx->r10, ctx->r13);
    // 0x80145150: swr         $t5, 0x3($t2)
    do_swr(rdram, 0X3, ctx->r10, ctx->r13);
    // 0x80145154: lbu         $t5, 0x4($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X4);
    // 0x80145158: sb          $t5, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r13;
    // 0x8014515C: lbu         $t4, 0x5($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X5);
    // 0x80145160: sb          $t4, 0x5($t2)
    MEM_B(0X5, ctx->r10) = ctx->r12;
    // 0x80145164: lbu         $t5, 0x6($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X6);
    // 0x80145168: sb          $t5, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r13;
    // 0x8014516C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80145170: addiu       $t7, $t0, 0x7
    ctx->r15 = ADD32(ctx->r8, 0X7);
    // 0x80145174: bne         $at, $zero, L_80145128
    if (ctx->r1 != 0) {
        // 0x80145178: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_80145128;
    }
    // 0x80145178: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8014517C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80145180: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80145184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80145188:
    // 0x80145188: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8014518C: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80145190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80145194: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80145198: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8014519C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801451A0: sb          $t8, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r24;
    // 0x801451A4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x801451A8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801451AC: bne         $at, $zero, L_80145188
    if (ctx->r1 != 0) {
        // 0x801451B0: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_80145188;
    }
    // 0x801451B0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801451B4: jr          $ra
    // 0x801451B8: nop

    return;
    // 0x801451B8: nop

;}
RECOMP_FUNC void M7_FUN_801451bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801451BC: nop

;}
RECOMP_FUNC void M7_FUN_801451c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801451C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801451C4: lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2A);
    // 0x801451C8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801451CC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801451D0: bne         $v0, $at, L_80145218
    if (ctx->r2 != ctx->r1) {
            // 0x801451D4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x80145218)(rdram, ctx);
    return;
    }
    // 0x801451D4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801451D8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801451DC: addiu       $t7, $t7, 0x19E8
    ctx->r15 = ADD32(ctx->r15, 0X19E8);
    // 0x801451E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801451E4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x801451E8: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x801451EC: sb          $t8, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r24;
    // 0x801451F0: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801451F4: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x801451F8: sb          $t0, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r8;
    // 0x801451FC: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x80145200: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x80145204: sb          $t2, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = ctx->r10;
    // 0x80145208: lw          $t5, 0x30($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X30);
    // 0x8014520C: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x80145210: jr          $ra
    // 0x80145214: sb          $t4, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r12;
    return;
    // 0x80145214: sb          $t4, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r12;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80145218(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80145218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145218: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8014521C: bne         $v0, $at, L_80145260
    if (ctx->r2 != ctx->r1) {
        // 0x80145220: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_80145260;
    }
    // 0x80145220: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80145224: addiu       $t7, $t7, 0x19E8
    ctx->r15 = ADD32(ctx->r15, 0X19E8);
    // 0x80145228: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8014522C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80145230: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80145234: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x80145238: sb          $t8, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r24;
    // 0x8014523C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x80145240: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80145244: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    // 0x80145248: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x8014524C: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x80145250: sb          $t2, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r10;
    // 0x80145254: lw          $t5, 0x30($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X30);
    // 0x80145258: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x8014525C: sb          $t4, 0xB($t5)
    MEM_B(0XB, ctx->r13) = ctx->r12;
L_80145260:
    // 0x80145260: jr          $ra
    // 0x80145264: nop

    return;
    // 0x80145264: nop

;}
RECOMP_FUNC void M7_FUN_80145268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145268: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8014526C: lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2A);
    // 0x80145270: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80145274: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80145278: bne         $v0, $at, L_801452C0
    if (ctx->r2 != ctx->r1) {
            // 0x8014527C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    LOOKUP_FUNC(0x801452C0)(rdram, ctx);
    return;
    }
    // 0x8014527C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80145280: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80145284: addiu       $t7, $t7, 0x19E8
    ctx->r15 = ADD32(ctx->r15, 0X19E8);
    // 0x80145288: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8014528C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80145290: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x80145294: sb          $t8, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r24;
    // 0x80145298: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8014529C: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x801452A0: sb          $t0, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r8;
    // 0x801452A4: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x801452A8: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x801452AC: sb          $t2, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r10;
    // 0x801452B0: lw          $t5, 0x30($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X30);
    // 0x801452B4: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x801452B8: jr          $ra
    // 0x801452BC: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    return;
    // 0x801452BC: sb          $t4, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r12;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801452c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801452c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801452C0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801452C4: bne         $v0, $at, L_80145308
    if (ctx->r2 != ctx->r1) {
        // 0x801452C8: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_80145308;
    }
    // 0x801452C8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801452CC: addiu       $t7, $t7, 0x19E8
    ctx->r15 = ADD32(ctx->r15, 0X19E8);
    // 0x801452D0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801452D4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801452D8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x801452DC: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x801452E0: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x801452E4: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801452E8: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x801452EC: sb          $t0, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r8;
    // 0x801452F0: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x801452F4: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x801452F8: sb          $t2, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r10;
    // 0x801452FC: lw          $t5, 0x30($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X30);
    // 0x80145300: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x80145304: sb          $t4, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r12;
L_80145308:
    // 0x80145308: jr          $ra
    // 0x8014530C: nop

    return;
    // 0x8014530C: nop

;}
RECOMP_FUNC void M7_FUN_80145310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014531C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80145320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80145324: jal         0x801451C0
    // 0x80145328: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80145328: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014532C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80145330: jal         0x80145268
    // 0x80145334: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x80145268)(rdram, ctx);
        goto after_1;
    // 0x80145334: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x80145338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014533C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145340: jr          $ra
    // 0x80145344: nop

    return;
    // 0x80145344: nop

;}
RECOMP_FUNC void M7_FUN_80145348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014534C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145350: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80145354: jal         0x80006214
    // 0x80145358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x80145358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014535C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80145360: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80145364: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80145368: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8014536C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80145370: lw          $a0, -0x2578($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2578);
    // 0x80145374: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80145378: jal         0x80145310
    // 0x8014537C: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x8014537C: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x80145380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145388: jr          $ra
    // 0x8014538C: nop

    return;
    // 0x8014538C: nop

;}
RECOMP_FUNC void M7_FUN_80145390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145390: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80145394: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80145398: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014539C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801453A0: addiu       $v1, $v1, -0x1378
    ctx->r3 = ADD32(ctx->r3, -0X1378);
    // 0x801453A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801453A8:
    // 0x801453A8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x801453AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801453B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801453B4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x801453B8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x801453BC: bne         $at, $zero, L_801453A8
    if (ctx->r1 != 0) {
        // 0x801453C0: sh          $a0, 0x0($t7)
        MEM_H(0X0, ctx->r15) = ctx->r4;
            goto L_801453A8;
    }
    // 0x801453C0: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x801453C4: jr          $ra
    // 0x801453C8: nop

    return;
    // 0x801453C8: nop

;}
RECOMP_FUNC void M7_FUN_801453cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801453CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801453D0: lbu         $t7, 0x53($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X53);
    // 0x801453D4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801453D8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801453DC: addiu       $t2, $t2, 0x19E8
    ctx->r10 = ADD32(ctx->r10, 0X19E8);
    // 0x801453E0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801453E4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801453E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801453EC: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x801453F0: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x801453F4: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x801453F8: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x801453FC: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80145400: sb          $t6, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r14;
    // 0x80145404: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x80145408: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x8014540C: sb          $t7, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r15;
    // 0x80145410: sb          $t9, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r25;
    // 0x80145414: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80145418: addu        $t1, $t2, $t7
    ctx->r9 = ADD32(ctx->r10, ctx->r15);
    // 0x8014541C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80145420: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x80145424: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x80145428: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x8014542C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80145430: sb          $t8, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r24;
    // 0x80145434: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80145438: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014543C: addiu       $t8, $t8, -0x1378
    ctx->r24 = ADD32(ctx->r24, -0X1378);
    // 0x80145440: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x80145444: lbu         $t6, 0x2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2);
    // 0x80145448: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x8014544C: sb          $t9, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r25;
    // 0x80145450: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x80145454: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80145458: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8014545C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80145460: sb          $t6, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r14;
    // 0x80145464: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x80145468: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
    // 0x8014546C: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80145470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80145474: lbu         $ra, 0x2($v0)
    ctx->r31 = MEM_BU(ctx->r2, 0X2);
    // 0x80145478: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8014547C: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x80145480: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80145484: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x80145488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014548C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80145490: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80145494: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80145498: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
    // 0x8014549C: sb          $ra, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r31;
    // 0x801454A0: lbu         $s1, 0x0($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0X0);
    // 0x801454A4: lbu         $s2, 0x1($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X1);
    // 0x801454A8: lbu         $s3, 0x2($t0)
    ctx->r19 = MEM_BU(ctx->r8, 0X2);
    // 0x801454AC: lh          $a0, 0x0($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X0);
    // 0x801454B0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801454B4: sb          $a3, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r7;
    // 0x801454B8: sb          $t4, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r12;
    // 0x801454BC: jal         0x8001EAD0
    // 0x801454C0: sb          $t5, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801454C0: sb          $t5, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r13;
    after_0:
    // 0x801454C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801454C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801454CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801454D0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801454D4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801454D8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801454DC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801454E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801454E4: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
    // 0x801454E8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801454EC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801454F0: lbu         $v1, 0x3C($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3C);
    // 0x801454F4: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x801454F8: lbu         $a1, 0x3A($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3A);
    // 0x801454FC: lbu         $a2, 0x57($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X57);
    // 0x80145500: lbu         $a3, 0x4F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X4F);
    // 0x80145504: lbu         $t0, 0x36($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X36);
    // 0x80145508: lbu         $t1, 0x35($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X35);
    // 0x8014550C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80145510: lbu         $t2, 0x34($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X34);
    // 0x80145514: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80145518: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x8014551C: lbu         $t5, 0x3E($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3E);
    // 0x80145520: bne         $v0, $at, L_801459BC
    if (ctx->r2 != ctx->r1) {
        // 0x80145524: lbu         $ra, 0x3D($sp)
        ctx->r31 = MEM_BU(ctx->r29, 0X3D);
            goto L_801459BC;
    }
    // 0x80145524: lbu         $ra, 0x3D($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X3D);
    // 0x80145528: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x8014552C: beq         $v0, $a3, L_80145774
    if (ctx->r2 == ctx->r7) {
        // 0x80145530: subu        $t9, $v1, $t4
        ctx->r25 = SUB32(ctx->r3, ctx->r12);
            goto L_80145774;
    }
    // 0x80145530: subu        $t9, $v1, $t4
    ctx->r25 = SUB32(ctx->r3, ctx->r12);
    // 0x80145534: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80145538: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8014553C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145540: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80145544: subu        $t9, $a0, $t5
    ctx->r25 = SUB32(ctx->r4, ctx->r13);
    // 0x80145548: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014554C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80145550: bgezl       $t4, L_80145568
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80145554: add.s       $f18, $f6, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
            goto L_80145568;
    }
    goto skip_0;
    // 0x80145554: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    skip_0:
    // 0x80145558: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014555C: nop

    // 0x80145560: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80145564: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
L_80145568:
    // 0x80145568: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014556C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145570: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145574: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145578: nop

    // 0x8014557C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80145580: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145584: nop

    // 0x80145588: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8014558C: beql        $t7, $zero, L_801455DC
    if (ctx->r15 == 0) {
        // 0x80145590: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_801455DC;
    }
    goto skip_1;
    // 0x80145590: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80145594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145598: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014559C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801455A0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801455A4: nop

    // 0x801455A8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801455AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801455B0: nop

    // 0x801455B4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801455B8: bne         $t7, $zero, L_801455D0
    if (ctx->r15 != 0) {
        // 0x801455BC: nop
    
            goto L_801455D0;
    }
    // 0x801455BC: nop

    // 0x801455C0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801455C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801455C8: b           L_801455E8
    // 0x801455CC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801455E8;
    // 0x801455CC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801455D0:
    // 0x801455D0: b           L_801455E8
    // 0x801455D4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801455E8;
    // 0x801455D4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801455D8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_801455DC:
    // 0x801455DC: nop

    // 0x801455E0: bltz        $t7, L_801455D0
    if (SIGNED(ctx->r15) < 0) {
        // 0x801455E4: nop
    
            goto L_801455D0;
    }
    // 0x801455E4: nop

L_801455E8:
    // 0x801455E8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801455EC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801455F0: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x801455F4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801455F8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801455FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145600: subu        $t9, $a1, $ra
    ctx->r25 = SUB32(ctx->r5, ctx->r31);
    // 0x80145604: sb          $t7, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r15;
    // 0x80145608: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014560C: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145610: bgezl       $t5, L_80145628
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80145614: add.s       $f8, $f6, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80145628;
    }
    goto skip_2;
    // 0x80145614: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    skip_2:
    // 0x80145618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014561C: nop

    // 0x80145620: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80145624: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
L_80145628:
    // 0x80145628: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014562C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145630: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145634: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145638: nop

    // 0x8014563C: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80145640: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145644: nop

    // 0x80145648: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8014564C: beql        $t7, $zero, L_8014569C
    if (ctx->r15 == 0) {
        // 0x80145650: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_8014569C;
    }
    goto skip_3;
    // 0x80145650: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x80145654: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014565C: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80145660: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145664: nop

    // 0x80145668: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8014566C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145670: nop

    // 0x80145674: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145678: bne         $t7, $zero, L_80145690
    if (ctx->r15 != 0) {
        // 0x8014567C: nop
    
            goto L_80145690;
    }
    // 0x8014567C: nop

    // 0x80145680: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80145684: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145688: b           L_801456A8
    // 0x8014568C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801456A8;
    // 0x8014568C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145690:
    // 0x80145690: b           L_801456A8
    // 0x80145694: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801456A8;
    // 0x80145694: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145698: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_8014569C:
    // 0x8014569C: nop

    // 0x801456A0: bltz        $t7, L_80145690
    if (SIGNED(ctx->r15) < 0) {
        // 0x801456A4: nop
    
            goto L_80145690;
    }
    // 0x801456A4: nop

L_801456A8:
    // 0x801456A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801456AC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801456B0: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x801456B4: mtc1        $ra, $f18
    ctx->f18.u32l = ctx->r31;
    // 0x801456B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801456BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801456C0: sb          $t7, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r15;
    // 0x801456C4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801456C8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801456CC: bgezl       $ra, L_801456E4
    if (SIGNED(ctx->r31) >= 0) {
        // 0x801456D0: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_801456E4;
    }
    goto skip_4;
    // 0x801456D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    skip_4:
    // 0x801456D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801456D8: nop

    // 0x801456DC: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801456E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
L_801456E4:
    // 0x801456E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801456E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801456EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801456F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801456F4: nop

    // 0x801456F8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801456FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145700: nop

    // 0x80145704: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145708: beql        $t7, $zero, L_80145758
    if (ctx->r15 == 0) {
        // 0x8014570C: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80145758;
    }
    goto skip_5;
    // 0x8014570C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_5:
    // 0x80145710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145714: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145718: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8014571C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145720: nop

    // 0x80145724: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80145728: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8014572C: nop

    // 0x80145730: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145734: bne         $t7, $zero, L_8014574C
    if (ctx->r15 != 0) {
        // 0x80145738: nop
    
            goto L_8014574C;
    }
    // 0x80145738: nop

    // 0x8014573C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80145740: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145744: b           L_80145764
    // 0x80145748: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145764;
    // 0x80145748: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8014574C:
    // 0x8014574C: b           L_80145764
    // 0x80145750: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145764;
    // 0x80145750: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145754: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80145758:
    // 0x80145758: nop

    // 0x8014575C: bltz        $t7, L_8014574C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145760: nop
    
            goto L_8014574C;
    }
    // 0x80145760: nop

L_80145764:
    // 0x80145764: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145768: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8014576C: sb          $t7, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r15;
    // 0x80145770: nop

L_80145774:
    // 0x80145774: beq         $v0, $a2, L_80145E58
    if (ctx->r2 == ctx->r6) {
        // 0x80145778: subu        $t9, $t0, $s1
        ctx->r25 = SUB32(ctx->r8, ctx->r17);
            goto L_80145E58;
    }
    // 0x80145778: subu        $t9, $t0, $s1
    ctx->r25 = SUB32(ctx->r8, ctx->r17);
    // 0x8014577C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80145780: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80145784: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145788: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014578C: subu        $t9, $t1, $s2
    ctx->r25 = SUB32(ctx->r9, ctx->r18);
    // 0x80145790: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80145794: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145798: bgezl       $s1, L_801457B0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8014579C: add.s       $f18, $f6, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
            goto L_801457B0;
    }
    goto skip_6;
    // 0x8014579C: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    skip_6:
    // 0x801457A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801457A4: nop

    // 0x801457A8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801457AC: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
L_801457B0:
    // 0x801457B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801457B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801457B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801457BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801457C0: nop

    // 0x801457C4: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801457C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801457CC: nop

    // 0x801457D0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801457D4: beql        $t7, $zero, L_80145824
    if (ctx->r15 == 0) {
        // 0x801457D8: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80145824;
    }
    goto skip_7;
    // 0x801457D8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_7:
    // 0x801457DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801457E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801457E4: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801457E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801457EC: nop

    // 0x801457F0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801457F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801457F8: nop

    // 0x801457FC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145800: bne         $t7, $zero, L_80145818
    if (ctx->r15 != 0) {
        // 0x80145804: nop
    
            goto L_80145818;
    }
    // 0x80145804: nop

    // 0x80145808: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8014580C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145810: b           L_80145830
    // 0x80145814: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145830;
    // 0x80145814: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145818:
    // 0x80145818: b           L_80145830
    // 0x8014581C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145830;
    // 0x8014581C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145820: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80145824:
    // 0x80145824: nop

    // 0x80145828: bltz        $t7, L_80145818
    if (SIGNED(ctx->r15) < 0) {
        // 0x8014582C: nop
    
            goto L_80145818;
    }
    // 0x8014582C: nop

L_80145830:
    // 0x80145830: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145834: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80145838: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x8014583C: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80145840: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80145844: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145848: subu        $t9, $t2, $s3
    ctx->r25 = SUB32(ctx->r10, ctx->r19);
    // 0x8014584C: sb          $t7, 0x4C($t8)
    MEM_B(0X4C, ctx->r24) = ctx->r15;
    // 0x80145850: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145854: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80145858: bgezl       $s2, L_80145870
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8014585C: add.s       $f8, $f6, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80145870;
    }
    goto skip_8;
    // 0x8014585C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    skip_8:
    // 0x80145860: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145864: nop

    // 0x80145868: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8014586C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
L_80145870:
    // 0x80145870: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145874: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145878: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8014587C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145880: nop

    // 0x80145884: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80145888: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8014588C: nop

    // 0x80145890: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145894: beql        $t7, $zero, L_801458E4
    if (ctx->r15 == 0) {
        // 0x80145898: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_801458E4;
    }
    goto skip_9;
    // 0x80145898: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_9:
    // 0x8014589C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801458A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801458A4: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801458A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801458AC: nop

    // 0x801458B0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801458B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801458B8: nop

    // 0x801458BC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801458C0: bne         $t7, $zero, L_801458D8
    if (ctx->r15 != 0) {
        // 0x801458C4: nop
    
            goto L_801458D8;
    }
    // 0x801458C4: nop

    // 0x801458C8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801458CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801458D0: b           L_801458F0
    // 0x801458D4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801458F0;
    // 0x801458D4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801458D8:
    // 0x801458D8: b           L_801458F0
    // 0x801458DC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801458F0;
    // 0x801458DC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801458E0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_801458E4:
    // 0x801458E4: nop

    // 0x801458E8: bltz        $t7, L_801458D8
    if (SIGNED(ctx->r15) < 0) {
        // 0x801458EC: nop
    
            goto L_801458D8;
    }
    // 0x801458EC: nop

L_801458F0:
    // 0x801458F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801458F4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801458F8: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x801458FC: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x80145900: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145904: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145908: sb          $t7, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r15;
    // 0x8014590C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80145910: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145914: bgezl       $s3, L_8014592C
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80145918: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_8014592C;
    }
    goto skip_10;
    // 0x80145918: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    skip_10:
    // 0x8014591C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145920: nop

    // 0x80145924: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80145928: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
L_8014592C:
    // 0x8014592C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145930: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145934: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8014593C: nop

    // 0x80145940: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80145944: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145948: nop

    // 0x8014594C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145950: beql        $t7, $zero, L_801459A0
    if (ctx->r15 == 0) {
        // 0x80145954: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_801459A0;
    }
    goto skip_11;
    // 0x80145954: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_11:
    // 0x80145958: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014595C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145960: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80145964: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145968: nop

    // 0x8014596C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80145970: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145974: nop

    // 0x80145978: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8014597C: bne         $t7, $zero, L_80145994
    if (ctx->r15 != 0) {
        // 0x80145980: nop
    
            goto L_80145994;
    }
    // 0x80145980: nop

    // 0x80145984: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80145988: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8014598C: b           L_801459AC
    // 0x80145990: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801459AC;
    // 0x80145990: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145994:
    // 0x80145994: b           L_801459AC
    // 0x80145998: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801459AC;
    // 0x80145998: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8014599C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_801459A0:
    // 0x801459A0: nop

    // 0x801459A4: bltz        $t7, L_80145994
    if (SIGNED(ctx->r15) < 0) {
        // 0x801459A8: nop
    
            goto L_80145994;
    }
    // 0x801459A8: nop

L_801459AC:
    // 0x801459AC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x801459B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801459B4: b           L_80145E58
    // 0x801459B8: sb          $t7, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r15;
        goto L_80145E58;
    // 0x801459B8: sb          $t7, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r15;
L_801459BC:
    // 0x801459BC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801459C0: bne         $v0, $at, L_80145E58
    if (ctx->r2 != ctx->r1) {
        // 0x801459C4: addiu       $v0, $zero, 0x22
        ctx->r2 = ADD32(0, 0X22);
            goto L_80145E58;
    }
    // 0x801459C4: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x801459C8: beq         $v0, $a3, L_80145C10
    if (ctx->r2 == ctx->r7) {
        // 0x801459CC: subu        $t9, $v1, $t4
        ctx->r25 = SUB32(ctx->r3, ctx->r12);
            goto L_80145C10;
    }
    // 0x801459CC: subu        $t9, $v1, $t4
    ctx->r25 = SUB32(ctx->r3, ctx->r12);
    // 0x801459D0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801459D4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801459D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801459DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801459E0: subu        $t9, $a0, $t5
    ctx->r25 = SUB32(ctx->r4, ctx->r13);
    // 0x801459E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801459E8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801459EC: bgezl       $t4, L_80145A04
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801459F0: add.s       $f18, $f6, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
            goto L_80145A04;
    }
    goto skip_12;
    // 0x801459F0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    skip_12:
    // 0x801459F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801459F8: nop

    // 0x801459FC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80145A00: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
L_80145A04:
    // 0x80145A04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145A08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145A0C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145A10: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145A14: nop

    // 0x80145A18: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80145A1C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145A20: nop

    // 0x80145A24: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145A28: beql        $t7, $zero, L_80145A78
    if (ctx->r15 == 0) {
        // 0x80145A2C: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80145A78;
    }
    goto skip_13;
    // 0x80145A2C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_13:
    // 0x80145A30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145A34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145A38: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80145A3C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145A40: nop

    // 0x80145A44: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80145A48: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145A4C: nop

    // 0x80145A50: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145A54: bne         $t7, $zero, L_80145A6C
    if (ctx->r15 != 0) {
        // 0x80145A58: nop
    
            goto L_80145A6C;
    }
    // 0x80145A58: nop

    // 0x80145A5C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80145A60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145A64: b           L_80145A84
    // 0x80145A68: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145A84;
    // 0x80145A68: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145A6C:
    // 0x80145A6C: b           L_80145A84
    // 0x80145A70: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145A84;
    // 0x80145A70: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145A74: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80145A78:
    // 0x80145A78: nop

    // 0x80145A7C: bltz        $t7, L_80145A6C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145A80: nop
    
            goto L_80145A6C;
    }
    // 0x80145A80: nop

L_80145A84:
    // 0x80145A84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145A88: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80145A8C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145A90: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80145A94: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80145A98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145A9C: subu        $t9, $a1, $ra
    ctx->r25 = SUB32(ctx->r5, ctx->r31);
    // 0x80145AA0: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x80145AA4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145AA8: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145AAC: bgezl       $t5, L_80145AC4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80145AB0: add.s       $f8, $f6, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80145AC4;
    }
    goto skip_14;
    // 0x80145AB0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    skip_14:
    // 0x80145AB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145AB8: nop

    // 0x80145ABC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80145AC0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
L_80145AC4:
    // 0x80145AC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145AC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145ACC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145AD0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145AD4: nop

    // 0x80145AD8: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80145ADC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145AE0: nop

    // 0x80145AE4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145AE8: beql        $t7, $zero, L_80145B38
    if (ctx->r15 == 0) {
        // 0x80145AEC: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80145B38;
    }
    goto skip_15;
    // 0x80145AEC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_15:
    // 0x80145AF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145AF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145AF8: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80145AFC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145B00: nop

    // 0x80145B04: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80145B08: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145B0C: nop

    // 0x80145B10: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145B14: bne         $t7, $zero, L_80145B2C
    if (ctx->r15 != 0) {
        // 0x80145B18: nop
    
            goto L_80145B2C;
    }
    // 0x80145B18: nop

    // 0x80145B1C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80145B20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145B24: b           L_80145B44
    // 0x80145B28: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145B44;
    // 0x80145B28: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145B2C:
    // 0x80145B2C: b           L_80145B44
    // 0x80145B30: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145B44;
    // 0x80145B30: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145B34: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80145B38:
    // 0x80145B38: nop

    // 0x80145B3C: bltz        $t7, L_80145B2C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145B40: nop
    
            goto L_80145B2C;
    }
    // 0x80145B40: nop

L_80145B44:
    // 0x80145B44: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145B48: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80145B4C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145B50: mtc1        $ra, $f18
    ctx->f18.u32l = ctx->r31;
    // 0x80145B54: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145B58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145B5C: sb          $t7, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r15;
    // 0x80145B60: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80145B64: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80145B68: bgezl       $ra, L_80145B80
    if (SIGNED(ctx->r31) >= 0) {
        // 0x80145B6C: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_80145B80;
    }
    goto skip_16;
    // 0x80145B6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    skip_16:
    // 0x80145B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145B74: nop

    // 0x80145B78: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80145B7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
L_80145B80:
    // 0x80145B80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145B84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145B88: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145B8C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145B90: nop

    // 0x80145B94: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80145B98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145B9C: nop

    // 0x80145BA0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145BA4: beql        $t7, $zero, L_80145BF4
    if (ctx->r15 == 0) {
        // 0x80145BA8: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80145BF4;
    }
    goto skip_17;
    // 0x80145BA8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_17:
    // 0x80145BAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145BB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145BB4: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80145BB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145BBC: nop

    // 0x80145BC0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80145BC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145BC8: nop

    // 0x80145BCC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145BD0: bne         $t7, $zero, L_80145BE8
    if (ctx->r15 != 0) {
        // 0x80145BD4: nop
    
            goto L_80145BE8;
    }
    // 0x80145BD4: nop

    // 0x80145BD8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80145BDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145BE0: b           L_80145C00
    // 0x80145BE4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145C00;
    // 0x80145BE4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145BE8:
    // 0x80145BE8: b           L_80145C00
    // 0x80145BEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145C00;
    // 0x80145BEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145BF0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80145BF4:
    // 0x80145BF4: nop

    // 0x80145BF8: bltz        $t7, L_80145BE8
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145BFC: nop
    
            goto L_80145BE8;
    }
    // 0x80145BFC: nop

L_80145C00:
    // 0x80145C00: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145C04: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145C08: sb          $t7, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r15;
    // 0x80145C0C: nop

L_80145C10:
    // 0x80145C10: beq         $v0, $a2, L_80145E58
    if (ctx->r2 == ctx->r6) {
        // 0x80145C14: subu        $t9, $t0, $s1
        ctx->r25 = SUB32(ctx->r8, ctx->r17);
            goto L_80145E58;
    }
    // 0x80145C14: subu        $t9, $t0, $s1
    ctx->r25 = SUB32(ctx->r8, ctx->r17);
    // 0x80145C18: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80145C1C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80145C20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145C24: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80145C28: subu        $t9, $t1, $s2
    ctx->r25 = SUB32(ctx->r9, ctx->r18);
    // 0x80145C2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80145C30: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145C34: bgezl       $s1, L_80145C4C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80145C38: add.s       $f18, $f6, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
            goto L_80145C4C;
    }
    goto skip_18;
    // 0x80145C38: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    skip_18:
    // 0x80145C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145C40: nop

    // 0x80145C44: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80145C48: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
L_80145C4C:
    // 0x80145C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145C50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145C54: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145C58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145C5C: nop

    // 0x80145C60: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80145C64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145C68: nop

    // 0x80145C6C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145C70: beql        $t7, $zero, L_80145CC0
    if (ctx->r15 == 0) {
        // 0x80145C74: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80145CC0;
    }
    goto skip_19;
    // 0x80145C74: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_19:
    // 0x80145C78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145C7C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145C80: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80145C84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145C88: nop

    // 0x80145C8C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80145C90: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145C94: nop

    // 0x80145C98: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145C9C: bne         $t7, $zero, L_80145CB4
    if (ctx->r15 != 0) {
        // 0x80145CA0: nop
    
            goto L_80145CB4;
    }
    // 0x80145CA0: nop

    // 0x80145CA4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80145CA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145CAC: b           L_80145CCC
    // 0x80145CB0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145CCC;
    // 0x80145CB0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145CB4:
    // 0x80145CB4: b           L_80145CCC
    // 0x80145CB8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145CCC;
    // 0x80145CB8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145CBC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80145CC0:
    // 0x80145CC0: nop

    // 0x80145CC4: bltz        $t7, L_80145CB4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145CC8: nop
    
            goto L_80145CB4;
    }
    // 0x80145CC8: nop

L_80145CCC:
    // 0x80145CCC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145CD0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80145CD4: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145CD8: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80145CDC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80145CE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145CE4: subu        $t9, $t2, $s3
    ctx->r25 = SUB32(ctx->r10, ctx->r19);
    // 0x80145CE8: sb          $t7, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r15;
    // 0x80145CEC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145CF0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80145CF4: bgezl       $s2, L_80145D0C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80145CF8: add.s       $f8, $f6, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80145D0C;
    }
    goto skip_20;
    // 0x80145CF8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    skip_20:
    // 0x80145CFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145D00: nop

    // 0x80145D04: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80145D08: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
L_80145D0C:
    // 0x80145D0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145D10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145D14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145D18: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145D1C: nop

    // 0x80145D20: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80145D24: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145D28: nop

    // 0x80145D2C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145D30: beql        $t7, $zero, L_80145D80
    if (ctx->r15 == 0) {
        // 0x80145D34: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80145D80;
    }
    goto skip_21;
    // 0x80145D34: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_21:
    // 0x80145D38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145D3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145D40: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80145D44: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145D48: nop

    // 0x80145D4C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80145D50: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145D54: nop

    // 0x80145D58: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145D5C: bne         $t7, $zero, L_80145D74
    if (ctx->r15 != 0) {
        // 0x80145D60: nop
    
            goto L_80145D74;
    }
    // 0x80145D60: nop

    // 0x80145D64: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80145D68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145D6C: b           L_80145D8C
    // 0x80145D70: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145D8C;
    // 0x80145D70: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145D74:
    // 0x80145D74: b           L_80145D8C
    // 0x80145D78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145D8C;
    // 0x80145D78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145D7C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80145D80:
    // 0x80145D80: nop

    // 0x80145D84: bltz        $t7, L_80145D74
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145D88: nop
    
            goto L_80145D74;
    }
    // 0x80145D88: nop

L_80145D8C:
    // 0x80145D8C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145D90: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80145D94: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145D98: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x80145D9C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80145DA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80145DA4: sb          $t7, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r15;
    // 0x80145DA8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80145DAC: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80145DB0: bgezl       $s3, L_80145DC8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80145DB4: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_80145DC8;
    }
    goto skip_22;
    // 0x80145DB4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    skip_22:
    // 0x80145DB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145DBC: nop

    // 0x80145DC0: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80145DC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
L_80145DC8:
    // 0x80145DC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145DCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145DD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80145DD4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145DD8: nop

    // 0x80145DDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80145DE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145DE4: nop

    // 0x80145DE8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145DEC: beql        $t7, $zero, L_80145E3C
    if (ctx->r15 == 0) {
        // 0x80145DF0: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80145E3C;
    }
    goto skip_23;
    // 0x80145DF0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_23:
    // 0x80145DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145DF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80145DFC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80145E00: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80145E04: nop

    // 0x80145E08: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80145E0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80145E10: nop

    // 0x80145E14: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80145E18: bne         $t7, $zero, L_80145E30
    if (ctx->r15 != 0) {
        // 0x80145E1C: nop
    
            goto L_80145E30;
    }
    // 0x80145E1C: nop

    // 0x80145E20: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80145E24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145E28: b           L_80145E48
    // 0x80145E2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80145E48;
    // 0x80145E2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80145E30:
    // 0x80145E30: b           L_80145E48
    // 0x80145E34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80145E48;
    // 0x80145E34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80145E38: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80145E3C:
    // 0x80145E3C: nop

    // 0x80145E40: bltz        $t7, L_80145E30
    if (SIGNED(ctx->r15) < 0) {
        // 0x80145E44: nop
    
            goto L_80145E30;
    }
    // 0x80145E44: nop

L_80145E48:
    // 0x80145E48: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80145E4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145E50: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x80145E54: nop

L_80145E58:
    // 0x80145E58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80145E5C: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80145E60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80145E64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80145E68: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80145E6C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80145E70: jr          $ra
    // 0x80145E74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80145E74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80145e78(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80145e78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145E7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80145E80: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80145E84: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80145E88: addiu       $t7, $t7, -0x1378
    ctx->r15 = ADD32(ctx->r15, -0X1378);
    // 0x80145E8C: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80145E90: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80145E94: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80145E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80145E9C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80145EA0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80145EA4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80145EA8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80145EAC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80145EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145EB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80145EB8: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x80145EBC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80145EC0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80145EC4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80145EC8: jal         0x8001EAD0
    // 0x80145ECC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80145ECC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80145ED0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80145ED4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80145ED8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80145EDC: lhu         $v0, 0x2A($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2A);
    // 0x80145EE0: bne         $v0, $at, L_80145FA8
    if (ctx->r2 != ctx->r1) {
        // 0x80145EE4: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_80145FA8;
    }
    // 0x80145EE4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80145EE8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80145EEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80145EF0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80145EF4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80145EF8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80145EFC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80145F00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80145F04: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80145F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80145F0C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80145F10: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80145F14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145F18: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80145F1C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80145F20: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80145F24: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80145F28: nop

    // 0x80145F2C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80145F30: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80145F34: nop

    // 0x80145F38: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80145F3C: beql        $t3, $zero, L_80145F8C
    if (ctx->r11 == 0) {
        // 0x80145F40: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_80145F8C;
    }
    goto skip_0;
    // 0x80145F40: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80145F44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80145F48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80145F4C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80145F50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80145F54: nop

    // 0x80145F58: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80145F5C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80145F60: nop

    // 0x80145F64: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80145F68: bne         $t3, $zero, L_80145F80
    if (ctx->r11 != 0) {
        // 0x80145F6C: nop
    
            goto L_80145F80;
    }
    // 0x80145F6C: nop

    // 0x80145F70: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80145F74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80145F78: b           L_80145F98
    // 0x80145F7C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80145F98;
    // 0x80145F7C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80145F80:
    // 0x80145F80: b           L_80145F98
    // 0x80145F84: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80145F98;
    // 0x80145F84: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80145F88: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_80145F8C:
    // 0x80145F8C: nop

    // 0x80145F90: bltz        $t3, L_80145F80
    if (SIGNED(ctx->r11) < 0) {
        // 0x80145F94: nop
    
            goto L_80145F80;
    }
    // 0x80145F94: nop

L_80145F98:
    // 0x80145F98: lw          $t4, 0x30($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X30);
    // 0x80145F9C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80145FA0: b           L_80146074
    // 0x80145FA4: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
        goto L_80146074;
    // 0x80145FA4: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
L_80145FA8:
    // 0x80145FA8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80145FAC: bne         $v0, $at, L_80146074
    if (ctx->r2 != ctx->r1) {
        // 0x80145FB0: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_80146074;
    }
    // 0x80145FB0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80145FB4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80145FB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80145FBC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80145FC0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80145FC4: add.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d + ctx->f16.d;
    // 0x80145FC8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80145FCC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80145FD0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80145FD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80145FD8: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80145FDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80145FE0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80145FE4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80145FE8: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80145FEC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80145FF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80145FF4: nop

    // 0x80145FF8: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80145FFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80146000: nop

    // 0x80146004: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80146008: beql        $t6, $zero, L_80146058
    if (ctx->r14 == 0) {
        // 0x8014600C: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_80146058;
    }
    goto skip_1;
    // 0x8014600C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80146010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80146014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80146018: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8014601C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80146020: nop

    // 0x80146024: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80146028: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8014602C: nop

    // 0x80146030: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80146034: bne         $t6, $zero, L_8014604C
    if (ctx->r14 != 0) {
        // 0x80146038: nop
    
            goto L_8014604C;
    }
    // 0x80146038: nop

    // 0x8014603C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80146040: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80146044: b           L_80146064
    // 0x80146048: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80146064;
    // 0x80146048: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8014604C:
    // 0x8014604C: b           L_80146064
    // 0x80146050: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80146064;
    // 0x80146050: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80146054: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_80146058:
    // 0x80146058: nop

    // 0x8014605C: bltz        $t6, L_8014604C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80146060: nop
    
            goto L_8014604C;
    }
    // 0x80146060: nop

L_80146064:
    // 0x80146064: lw          $t7, 0x30($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X30);
    // 0x80146068: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8014606C: sb          $t6, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r14;
    // 0x80146070: nop

L_80146074:
    // 0x80146074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146078: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8014607C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146080: jr          $ra
    // 0x80146084: nop

    return;
    // 0x80146084: nop

;}
RECOMP_FUNC void M7_FUN_80146088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014608C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146090: jal         0x80005E44
    // 0x80146094: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80146094: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80146098: beq         $v0, $zero, L_801460B4
    if (ctx->r2 == 0) {
        // 0x8014609C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_801460B4;
    }
    // 0x8014609C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801460A0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x801460A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801460A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801460AC: b           L_801460B8
    // 0x801460B0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801460B8;
    // 0x801460B0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801460B4:
    // 0x801460B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801460B8:
    // 0x801460B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801460BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801460C0: jr          $ra
    // 0x801460C4: nop

    return;
    // 0x801460C4: nop

;}
RECOMP_FUNC void M7_FUN_801460c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801460C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801460CC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x801460D0: lh          $t6, 0x62($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X62);
    // 0x801460D4: lh          $t7, 0x6A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6A);
    // 0x801460D8: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x801460DC: lbu         $t9, 0x77($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X77);
    // 0x801460E0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801460E4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x801460E8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x801460EC: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x801460F0: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x801460F4: lbu         $t0, 0x7B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7B);
    // 0x801460F8: lbu         $t1, 0x7F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7F);
    // 0x801460FC: lbu         $t2, 0x83($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X83);
    // 0x80146100: lbu         $t3, 0x8B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X8B);
    // 0x80146104: lbu         $t4, 0x8F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X8F);
    // 0x80146108: lbu         $t6, 0x97($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X97);
    // 0x8014610C: lbu         $t5, 0x93($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X93);
    // 0x80146110: lhu         $t7, 0x72($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X72);
    // 0x80146114: lhu         $t8, 0x86($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X86);
    // 0x80146118: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8014611C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80146120: sb          $t9, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r25;
    // 0x80146124: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x80146128: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8014612C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146130: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80146134: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80146138: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x8014613C: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80146140: sb          $t0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r8;
    // 0x80146144: sb          $t1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r9;
    // 0x80146148: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    // 0x8014614C: sb          $t3, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r11;
    // 0x80146150: sb          $t4, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r12;
    // 0x80146154: sb          $t6, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r14;
    // 0x80146158: sb          $t5, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r13;
    // 0x8014615C: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x80146160: jal         0x80146088
    // 0x80146164: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80146164: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    after_0:
    // 0x80146168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014616C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80146170: jr          $ra
    // 0x80146174: nop

    return;
    // 0x80146174: nop

;}
RECOMP_FUNC void M7_FUN_80146178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146178: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8014617C: lhu         $t3, 0x72($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X72);
    // 0x80146180: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80146184: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80146188: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8014618C: lh          $t6, 0x62($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X62);
    // 0x80146190: lh          $t7, 0x6A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6A);
    // 0x80146194: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80146198: lbu         $t9, 0x77($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X77);
    // 0x8014619C: lbu         $t0, 0x7B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7B);
    // 0x801461A0: lbu         $t1, 0x7F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7F);
    // 0x801461A4: lbu         $t2, 0x83($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X83);
    // 0x801461A8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801461AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801461B0: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x801461B4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801461B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801461BC: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x801461C0: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x801461C4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x801461C8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x801461CC: sh          $t4, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r12;
    // 0x801461D0: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x801461D4: sw          $t5, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r13;
    // 0x801461D8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x801461DC: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x801461E0: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x801461E4: sb          $t9, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r25;
    // 0x801461E8: sb          $t0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r8;
    // 0x801461EC: sb          $t1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r9;
    // 0x801461F0: jal         0x80146088
    // 0x801461F4: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x801461F4: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    after_0:
    // 0x801461F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801461FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80146200: jr          $ra
    // 0x80146204: nop

    return;
    // 0x80146204: nop

;}
RECOMP_FUNC void M7_FUN_80146208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146208: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8014620C: lhu         $v0, 0x92($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X92);
    // 0x80146210: lh          $t7, 0x7E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7E);
    // 0x80146214: lh          $t8, 0x82($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X82);
    // 0x80146218: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8014621C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80146220: lh          $t6, 0x7A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7A);
    // 0x80146224: lbu         $t2, 0x8F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X8F);
    // 0x80146228: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8014622C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80146230: lw          $v1, 0x1CEC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1CEC);
    // 0x80146234: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80146238: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8014623C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80146240: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80146244: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80146248: ori         $t3, $a2, 0x4
    ctx->r11 = ctx->r6 | 0X4;
    // 0x8014624C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146250: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80146254: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80146258: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8014625C: sh          $a3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r7;
    // 0x80146260: sb          $t1, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r9;
    // 0x80146264: sb          $t0, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r8;
    // 0x80146268: sb          $t9, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r25;
    // 0x8014626C: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x80146270: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x80146274: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x80146278: sh          $t7, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r15;
    // 0x8014627C: sh          $t8, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r24;
    // 0x80146280: sh          $t8, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r24;
    // 0x80146284: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x80146288: sb          $t2, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r10;
    // 0x8014628C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80146290: lhu         $t0, 0x96($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X96);
    // 0x80146294: addiu       $at, $zero, 0x209
    ctx->r1 = ADD32(0, 0X209);
    // 0x80146298: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8014629C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801462A0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801462A4: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
    // 0x801462A8: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x801462AC: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x801462B0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801462B4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801462B8: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x801462BC: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
    // 0x801462C0: bne         $v0, $at, L_80146324
    if (ctx->r2 != ctx->r1) {
        // 0x801462C4: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_80146324;
    }
    // 0x801462C4: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x801462C8: lhu         $v0, 0x96($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X96);
    // 0x801462CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801462D0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x801462D4: beq         $v0, $zero, L_80146308
    if (ctx->r2 == 0) {
        // 0x801462D8: addiu       $t0, $zero, 0x20
        ctx->r8 = ADD32(0, 0X20);
            goto L_80146308;
    }
    // 0x801462D8: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x801462DC: beq         $v0, $at, L_801462F8
    if (ctx->r2 == ctx->r1) {
        // 0x801462E0: addiu       $t4, $zero, 0x20
        ctx->r12 = ADD32(0, 0X20);
            goto L_801462F8;
    }
    // 0x801462E0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801462E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801462E8: beq         $v0, $at, L_80146314
    if (ctx->r2 == ctx->r1) {
        // 0x801462EC: addiu       $t9, $zero, 0x58
        ctx->r25 = ADD32(0, 0X58);
            goto L_80146314;
    }
    // 0x801462EC: addiu       $t9, $zero, 0x58
    ctx->r25 = ADD32(0, 0X58);
    // 0x801462F0: b           L_8014642C
    // 0x801462F4: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
        goto L_8014642C;
    // 0x801462F4: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_801462F8:
    // 0x801462F8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x801462FC: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80146300: b           L_80146428
    // 0x80146304: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
        goto L_80146428;
    // 0x80146304: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_80146308:
    // 0x80146308: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8014630C: b           L_80146428
    // 0x80146310: sh          $t0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r8;
        goto L_80146428;
    // 0x80146310: sh          $t0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r8;
L_80146314:
    // 0x80146314: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80146318: sh          $t1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r9;
    // 0x8014631C: b           L_80146428
    // 0x80146320: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
        goto L_80146428;
    // 0x80146320: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
L_80146324:
    // 0x80146324: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    // 0x80146328: bnel        $v0, $at, L_80146374
    if (ctx->r2 != ctx->r1) {
        // 0x8014632C: addiu       $at, $zero, 0x21D
        ctx->r1 = ADD32(0, 0X21D);
            goto L_80146374;
    }
    goto skip_0;
    // 0x8014632C: addiu       $at, $zero, 0x21D
    ctx->r1 = ADD32(0, 0X21D);
    skip_0:
    // 0x80146330: lhu         $v0, 0x96($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X96);
    // 0x80146334: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80146338: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8014633C: beq         $v0, $zero, L_80146354
    if (ctx->r2 == 0) {
        // 0x80146340: addiu       $t3, $zero, 0x20
        ctx->r11 = ADD32(0, 0X20);
            goto L_80146354;
    }
    // 0x80146340: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80146344: beq         $v0, $at, L_80146360
    if (ctx->r2 == ctx->r1) {
        // 0x80146348: addiu       $t7, $zero, 0x38
        ctx->r15 = ADD32(0, 0X38);
            goto L_80146360;
    }
    // 0x80146348: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x8014634C: b           L_8014642C
    // 0x80146350: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
        goto L_8014642C;
    // 0x80146350: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_80146354:
    // 0x80146354: sh          $t2, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r10;
    // 0x80146358: b           L_80146428
    // 0x8014635C: sh          $t3, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r11;
        goto L_80146428;
    // 0x8014635C: sh          $t3, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r11;
L_80146360:
    // 0x80146360: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80146364: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
    // 0x80146368: b           L_80146428
    // 0x8014636C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
        goto L_80146428;
    // 0x8014636C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80146370: addiu       $at, $zero, 0x21D
    ctx->r1 = ADD32(0, 0X21D);
L_80146374:
    // 0x80146374: bnel        $v0, $at, L_801463E0
    if (ctx->r2 != ctx->r1) {
        // 0x80146378: addiu       $at, $zero, 0x21E
        ctx->r1 = ADD32(0, 0X21E);
            goto L_801463E0;
    }
    goto skip_1;
    // 0x80146378: addiu       $at, $zero, 0x21E
    ctx->r1 = ADD32(0, 0X21E);
    skip_1:
    // 0x8014637C: lhu         $v0, 0x96($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X96);
    // 0x80146380: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80146384: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80146388: beq         $v0, $at, L_801463B0
    if (ctx->r2 == ctx->r1) {
        // 0x8014638C: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_801463B0;
    }
    // 0x8014638C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80146390: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80146394: beq         $v0, $at, L_801463BC
    if (ctx->r2 == ctx->r1) {
        // 0x80146398: addiu       $t6, $zero, 0x58
        ctx->r14 = ADD32(0, 0X58);
            goto L_801463BC;
    }
    // 0x80146398: addiu       $t6, $zero, 0x58
    ctx->r14 = ADD32(0, 0X58);
    // 0x8014639C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801463A0: beq         $v0, $at, L_801463CC
    if (ctx->r2 == ctx->r1) {
        // 0x801463A4: addiu       $t9, $zero, 0x20
        ctx->r25 = ADD32(0, 0X20);
            goto L_801463CC;
    }
    // 0x801463A4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x801463A8: b           L_8014642C
    // 0x801463AC: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
        goto L_8014642C;
    // 0x801463AC: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_801463B0:
    // 0x801463B0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x801463B4: b           L_80146428
    // 0x801463B8: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
        goto L_80146428;
    // 0x801463B8: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
L_801463BC:
    // 0x801463BC: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x801463C0: sh          $t0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r8;
    // 0x801463C4: b           L_80146428
    // 0x801463C8: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
        goto L_80146428;
    // 0x801463C8: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
L_801463CC:
    // 0x801463CC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801463D0: sh          $t1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r9;
    // 0x801463D4: b           L_80146428
    // 0x801463D8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
        goto L_80146428;
    // 0x801463D8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x801463DC: addiu       $at, $zero, 0x21E
    ctx->r1 = ADD32(0, 0X21E);
L_801463E0:
    // 0x801463E0: bne         $v0, $at, L_80146404
    if (ctx->r2 != ctx->r1) {
        // 0x801463E4: lhu         $t2, 0x96($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X96);
            goto L_80146404;
    }
    // 0x801463E4: lhu         $t2, 0x96($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X96);
    // 0x801463E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801463EC: bne         $t2, $at, L_80146428
    if (ctx->r10 != ctx->r1) {
        // 0x801463F0: addiu       $t3, $zero, 0x100
        ctx->r11 = ADD32(0, 0X100);
            goto L_80146428;
    }
    // 0x801463F0: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x801463F4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801463F8: sh          $t7, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r15;
    // 0x801463FC: b           L_80146428
    // 0x80146400: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
        goto L_80146428;
    // 0x80146400: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
L_80146404:
    // 0x80146404: addiu       $at, $zero, 0x220
    ctx->r1 = ADD32(0, 0X220);
    // 0x80146408: bne         $v0, $at, L_80146428
    if (ctx->r2 != ctx->r1) {
        // 0x8014640C: lhu         $t8, 0x96($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X96);
            goto L_80146428;
    }
    // 0x8014640C: lhu         $t8, 0x96($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X96);
    // 0x80146410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80146414: bne         $t8, $at, L_80146428
    if (ctx->r24 != ctx->r1) {
        // 0x80146418: addiu       $t4, $zero, 0x80
        ctx->r12 = ADD32(0, 0X80);
            goto L_80146428;
    }
    // 0x80146418: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8014641C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80146420: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80146424: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_80146428:
    // 0x80146428: lhu         $t6, 0x86($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X86);
L_8014642C:
    // 0x8014642C: lhu         $t0, 0x8A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X8A);
    // 0x80146430: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x80146434: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80146438: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8014643C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80146440: sh          $t6, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r14;
    // 0x80146444: jal         0x80146088
    // 0x80146448: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80146448: sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014644C: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x80146450: jal         0x80006214
    // 0x80146454: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80146454: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80146458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014645C: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x80146460: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80146464: jr          $ra
    // 0x80146468: nop

    return;
    // 0x80146468: nop

;}
RECOMP_FUNC void M7_FUN_8014646c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014646C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80146470: lh          $t6, 0x6A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6A);
    // 0x80146474: lh          $t7, 0x6E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6E);
    // 0x80146478: lhu         $t5, 0x86($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X86);
    // 0x8014647C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80146480: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80146484: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x80146488: sh          $t6, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r14;
    // 0x8014648C: lhu         $t3, 0x5E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X5E);
    // 0x80146490: addiu       $t0, $t0, 0x1CF0
    ctx->r8 = ADD32(ctx->r8, 0X1CF0);
    // 0x80146494: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x80146498: sh          $t7, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r15;
    // 0x8014649C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801464A0: lbu         $t2, 0x83($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X83);
    // 0x801464A4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x801464A8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x801464AC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801464B0: lw          $v0, -0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, -0X4);
    // 0x801464B4: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801464B8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801464BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801464C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801464C4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801464C8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801464CC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801464D0: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x801464D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801464D8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801464DC: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x801464E0: sh          $a2, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r6;
    // 0x801464E4: sb          $t1, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r9;
    // 0x801464E8: sb          $t9, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r25;
    // 0x801464EC: sb          $t8, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r24;
    // 0x801464F0: sh          $t4, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r12;
    // 0x801464F4: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x801464F8: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    // 0x801464FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80146500: lhu         $t2, 0x8A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X8A);
    // 0x80146504: lhu         $t6, 0x8E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X8E);
    // 0x80146508: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8014650C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80146510: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80146514: sh          $t9, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r25;
    // 0x80146518: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8014651C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80146520: lw          $v1, -0x4($t8)
    ctx->r3 = MEM_W(ctx->r24, -0X4);
    // 0x80146524: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80146528: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8014652C: lhu         $t3, 0x92($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X92);
    // 0x80146530: lh          $t8, 0x76($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X76);
    // 0x80146534: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80146538: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8014653C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80146540: lh          $t7, 0x72($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X72);
    // 0x80146544: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x80146548: lhu         $t9, 0x7A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X7A);
    // 0x8014654C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80146550: sh          $t2, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r10;
    // 0x80146554: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80146558: lhu         $t2, 0x7E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X7E);
    // 0x8014655C: addiu       $a1, $a1, 0x1A84
    ctx->r5 = ADD32(ctx->r5, 0X1A84);
    // 0x80146560: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80146564: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80146568: addiu       $t3, $sp, 0x1C
    ctx->r11 = ADD32(ctx->r29, 0X1C);
    // 0x8014656C: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    // 0x80146570: sh          $t8, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r24;
    // 0x80146574: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
    // 0x80146578: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    // 0x8014657C: sh          $t2, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r10;
    // 0x80146580: jal         0x80005E44
    // 0x80146584: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80146584: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_0:
    // 0x80146588: jal         0x80006214
    // 0x8014658C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8014658C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80146590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80146598: jr          $ra
    // 0x8014659C: nop

    return;
    // 0x8014659C: nop

;}
RECOMP_FUNC void M7_FUN_801465a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801465A0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801465A4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801465A8: sll         $s7, $a3, 16
    ctx->r23 = S32(ctx->r7 << 16);
    // 0x801465AC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801465B0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801465B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801465B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801465BC: andi        $s3, $a2, 0xFFFF
    ctx->r19 = ctx->r6 & 0XFFFF;
    // 0x801465C0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x801465C4: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x801465C8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801465CC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801465D0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801465D4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801465D8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801465DC: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801465E0: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801465E4: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801465E8: sb          $zero, 0x76($sp)
    MEM_B(0X76, ctx->r29) = 0;
    // 0x801465EC: jal         0x80006214
    // 0x801465F0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801465F0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_0:
    // 0x801465F4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801465F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801465FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80146600: lh          $fp, 0x8A($sp)
    ctx->r30 = MEM_H(ctx->r29, 0X8A);
    // 0x80146604: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_80146608:
    // 0x80146608: div         $zero, $s3, $s4
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r20)));
    // 0x8014660C: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80146610: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80146614: mfhi        $t7
    ctx->r15 = hi;
    // 0x80146618: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8014661C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80146620: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80146624: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80146628: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8014662C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80146630: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80146634: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80146638: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8014663C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80146640: subu        $a3, $s7, $t8
    ctx->r7 = SUB32(ctx->r23, ctx->r24);
    // 0x80146644: bne         $s4, $zero, L_80146650
    if (ctx->r20 != 0) {
        // 0x80146648: nop
    
            goto L_80146650;
    }
    // 0x80146648: nop

    // 0x8014664C: break       7
    do_break(2148820556);
L_80146650:
    // 0x80146650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80146654: bne         $s4, $at, L_80146668
    if (ctx->r20 != ctx->r1) {
        // 0x80146658: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80146668;
    }
    // 0x80146658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8014665C: bne         $s2, $at, L_80146668
    if (ctx->r18 != ctx->r1) {
        // 0x80146660: nop
    
            goto L_80146668;
    }
    // 0x80146660: nop

    // 0x80146664: break       6
    do_break(2148820580);
L_80146668:
    // 0x80146668: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8014666C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80146670: addiu       $t4, $zero, 0x209
    ctx->r12 = ADD32(0, 0X209);
    // 0x80146674: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80146678: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8014667C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80146680: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80146684: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80146688: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8014668C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80146690: sb          $v1, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r3;
    // 0x80146694: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80146698: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8014669C: addiu       $a1, $sp, 0x76
    ctx->r5 = ADD32(ctx->r29, 0X76);
    // 0x801466A0: jal         0x80146208
    // 0x801466A4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x801466A4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    after_1:
    // 0x801466A8: div         $zero, $s2, $s4
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r20)));
    // 0x801466AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801466B0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801466B4: mflo        $s3
    ctx->r19 = lo;
    // 0x801466B8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x801466BC: lbu         $v1, 0x75($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X75);
    // 0x801466C0: bne         $s4, $zero, L_801466CC
    if (ctx->r20 != 0) {
        // 0x801466C4: nop
    
            goto L_801466CC;
    }
    // 0x801466C4: nop

    // 0x801466C8: break       7
    do_break(2148820680);
L_801466CC:
    // 0x801466CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801466D0: bne         $s4, $at, L_801466E4
    if (ctx->r20 != ctx->r1) {
        // 0x801466D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801466E4;
    }
    // 0x801466D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801466D8: bne         $s2, $at, L_801466E4
    if (ctx->r18 != ctx->r1) {
        // 0x801466DC: nop
    
            goto L_801466E4;
    }
    // 0x801466DC: nop

    // 0x801466E0: break       6
    do_break(2148820704);
L_801466E4:
    // 0x801466E4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801466E8: bne         $at, $zero, L_80146608
    if (ctx->r1 != 0) {
        // 0x801466EC: andi        $s3, $s3, 0xFFFF
        ctx->r19 = ctx->r19 & 0XFFFF;
            goto L_80146608;
    }
    // 0x801466EC: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x801466F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801466F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801466F8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801466FC: addiu       $v0, $sp, 0x6F
    ctx->r2 = ADD32(ctx->r29, 0X6F);
L_80146700:
    // 0x80146700: negu        $t6, $s1
    ctx->r14 = SUB32(0, ctx->r17);
    // 0x80146704: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80146708: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8014670C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80146710: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80146714: bne         $t8, $zero, L_80146740
    if (ctx->r24 != 0) {
        // 0x80146718: slti        $at, $s0, 0x3
        ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_80146740;
    }
    // 0x80146718: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8014671C: bne         $s6, $zero, L_80146740
    if (ctx->r22 != 0) {
        // 0x80146720: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80146740;
    }
    // 0x80146720: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80146724: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80146728: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8014672C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80146730: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80146734: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80146738: b           L_80146744
    // 0x8014673C: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
        goto L_80146744;
    // 0x8014673C: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
L_80146740:
    // 0x80146740: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80146744:
    // 0x80146744: bne         $at, $zero, L_80146700
    if (ctx->r1 != 0) {
        // 0x80146748: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80146700;
    }
    // 0x80146748: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8014674C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80146750: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80146754: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80146758: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8014675C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80146760: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80146764: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80146768: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8014676C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80146770: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80146774: jr          $ra
    // 0x80146778: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80146778: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014677c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014677c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014677C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80146780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80146784: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80146788: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8014678C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80146790: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80146794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80146798: addu        $a3, $a0, $t6
    ctx->r7 = ADD32(ctx->r4, ctx->r14);
    // 0x8014679C: addiu       $t1, $sp, 0x14
    ctx->r9 = ADD32(ctx->r29, 0X14);
    // 0x801467A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801467A4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801467A8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_801467AC:
    // 0x801467AC: div         $zero, $a2, $t2
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r10)));
    // 0x801467B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801467B4: mfhi        $t7
    ctx->r15 = hi;
    // 0x801467B8: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x801467BC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x801467C0: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x801467C4: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x801467C8: bne         $t2, $zero, L_801467D4
    if (ctx->r10 != 0) {
        // 0x801467CC: nop
    
            goto L_801467D4;
    }
    // 0x801467CC: nop

    // 0x801467D0: break       7
    do_break(2148820944);
L_801467D4:
    // 0x801467D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801467D8: bne         $t2, $at, L_801467EC
    if (ctx->r10 != ctx->r1) {
        // 0x801467DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801467EC;
    }
    // 0x801467DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801467E0: bne         $a1, $at, L_801467EC
    if (ctx->r5 != ctx->r1) {
        // 0x801467E4: nop
    
            goto L_801467EC;
    }
    // 0x801467E4: nop

    // 0x801467E8: break       6
    do_break(2148820968);
L_801467EC:
    // 0x801467EC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801467F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801467F4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801467F8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801467FC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80146800: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80146804: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80146808: mflo        $a2
    ctx->r6 = lo;
    // 0x8014680C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80146810: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80146814: bne         $at, $zero, L_801467AC
    if (ctx->r1 != 0) {
        // 0x80146818: sh          $t9, 0x2E($t6)
        MEM_H(0X2E, ctx->r14) = ctx->r25;
            goto L_801467AC;
    }
    // 0x80146818: sh          $t9, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r25;
    // 0x8014681C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80146820: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80146824: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80146828: addiu       $a0, $sp, 0x17
    ctx->r4 = ADD32(ctx->r29, 0X17);
L_8014682C:
    // 0x8014682C: negu        $t7, $t0
    ctx->r15 = SUB32(0, ctx->r8);
    // 0x80146830: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80146834: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
    // 0x80146838: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8014683C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80146840: bne         $t3, $zero, L_8014686C
    if (ctx->r11 != 0) {
        // 0x80146844: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_8014686C;
    }
    // 0x80146844: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80146848: bne         $v0, $zero, L_8014686C
    if (ctx->r2 != 0) {
        // 0x8014684C: slti        $at, $t0, 0x3
        ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
            goto L_8014686C;
    }
    // 0x8014684C: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80146850: beq         $at, $zero, L_8014686C
    if (ctx->r1 == 0) {
        // 0x80146854: sll         $t4, $t0, 2
        ctx->r12 = S32(ctx->r8 << 2);
            goto L_8014686C;
    }
    // 0x80146854: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80146858: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8014685C: addu        $t9, $a3, $t5
    ctx->r25 = ADD32(ctx->r7, ctx->r13);
    // 0x80146860: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x80146864: b           L_80146880
    // 0x80146868: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
        goto L_80146880;
    // 0x80146868: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
L_8014686C:
    // 0x8014686C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80146870: addu        $t3, $a3, $t8
    ctx->r11 = ADD32(ctx->r7, ctx->r24);
    // 0x80146874: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80146878: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8014687C: sb          $a1, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r5;
L_80146880:
    // 0x80146880: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80146884: bne         $at, $zero, L_8014682C
    if (ctx->r1 != 0) {
        // 0x80146888: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8014682C;
    }
    // 0x80146888: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8014688C: jr          $ra
    // 0x80146890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80146890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80146894(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80146894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146894: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80146898: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8014689C: lw          $t6, 0x2510($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2510);
    // 0x801468A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801468A4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x801468A8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801468AC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x801468B0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801468B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801468B8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x801468BC: lhu         $a3, 0x2($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X2);
    // 0x801468C0: lwc1        $f8, -0x670($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X670);
    // 0x801468C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801468C8: lb          $a1, 0xA7($sp)
    ctx->r5 = MEM_B(ctx->r29, 0XA7);
    // 0x801468CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801468D0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801468D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801468D8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801468DC: addiu       $t8, $zero, 0x30F
    ctx->r24 = ADD32(0, 0X30F);
    // 0x801468E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801468E4: sh          $t7, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r15;
    // 0x801468E8: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x801468EC: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x801468F0: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x801468F4: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x801468F8: sh          $v1, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r3;
    // 0x801468FC: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80146900: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80146904: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80146908: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x8014690C: beq         $a1, $at, L_80146928
    if (ctx->r5 == ctx->r1) {
        // 0x80146910: swc1        $f6, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
            goto L_80146928;
    }
    // 0x80146910: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80146914: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80146918: beq         $a1, $at, L_80146948
    if (ctx->r5 == ctx->r1) {
        // 0x8014691C: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_80146948;
    }
    // 0x8014691C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80146920: b           L_80146964
    // 0x80146924: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
        goto L_80146964;
    // 0x80146924: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
L_80146928:
    // 0x80146928: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014692C: lwc1        $f0, -0x66C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X66C);
    // 0x80146930: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80146934: addiu       $t9, $t9, 0x1720
    ctx->r25 = ADD32(ctx->r25, 0X1720);
    // 0x80146938: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8014693C: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80146940: b           L_80146960
    // 0x80146944: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
        goto L_80146960;
    // 0x80146944: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80146948:
    // 0x80146948: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014694C: lwc1        $f0, -0x668($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X668);
    // 0x80146950: addiu       $t0, $t0, 0x1880
    ctx->r8 = ADD32(ctx->r8, 0X1880);
    // 0x80146954: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80146958: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8014695C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80146960:
    // 0x80146960: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
L_80146964:
    // 0x80146964: ori         $t1, $t1, 0x900
    ctx->r9 = ctx->r9 | 0X900;
    // 0x80146968: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8014696C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80146970: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x80146974: sh          $a3, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r7;
    // 0x80146978: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8014697C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80146980: sh          $t2, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r10;
    // 0x80146984: sh          $t3, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r11;
    // 0x80146988: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8014698C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80146990: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80146994: jal         0x80146088
    // 0x80146998: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80146998: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014699C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x801469A0: jal         0x80006214
    // 0x801469A4: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801469A4: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    after_1:
    // 0x801469A8: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
    // 0x801469AC: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x801469B0: bnel        $v1, $zero, L_80146A8C
    if (ctx->r3 != 0) {
        // 0x801469B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146A8C;
    }
    goto skip_0;
    // 0x801469B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801469B8: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x801469BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801469C0: addiu       $v0, $v0, -0x2578
    ctx->r2 = ADD32(ctx->r2, -0X2578);
    // 0x801469C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801469C8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x801469CC: lw          $t0, -0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X4);
    // 0x801469D0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801469D4: addiu       $t5, $t5, 0x16C0
    ctx->r13 = ADD32(ctx->r13, 0X16C0);
    // 0x801469D8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801469DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801469E0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801469E4: sw          $t6, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r14;
    // 0x801469E8: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    // 0x801469EC: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x801469F0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801469F4: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x801469F8: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x801469FC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80146A00: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80146A04: sb          $zero, 0x48($t7)
    MEM_B(0X48, ctx->r15) = 0;
    // 0x80146A08: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80146A0C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80146A10: addu        $t6, $v0, $t0
    ctx->r14 = ADD32(ctx->r2, ctx->r8);
    // 0x80146A14: lw          $t1, -0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, -0X4);
    // 0x80146A18: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80146A1C: sb          $t8, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r24;
    // 0x80146A20: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x80146A24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80146A28: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80146A2C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80146A30: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x80146A34: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80146A38: sb          $t3, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r11;
    // 0x80146A3C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80146A40: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80146A44: addu        $t8, $v0, $t1
    ctx->r24 = ADD32(ctx->r2, ctx->r9);
    // 0x80146A48: lw          $t2, -0x4($t8)
    ctx->r10 = MEM_W(ctx->r24, -0X4);
    // 0x80146A4C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x80146A50: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80146A54: sb          $zero, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = 0;
    // 0x80146A58: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80146A5C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80146A60: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x80146A64: lw          $t0, -0x4($t3)
    ctx->r8 = MEM_W(ctx->r11, -0X4);
    // 0x80146A68: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x80146A6C: sb          $t5, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r13;
    // 0x80146A70: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80146A74: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80146A78: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x80146A7C: lw          $t7, -0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, -0X4);
    // 0x80146A80: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80146A84: sb          $t1, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r9;
    // 0x80146A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146A8C:
    // 0x80146A8C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80146A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80146A94: jr          $ra
    // 0x80146A98: nop

    return;
    // 0x80146A98: nop

;}
RECOMP_FUNC void M7_FUN_80146a9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146A9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80146AA0: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x80146AA4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80146AA8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80146AAC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80146AB0: addiu       $t7, $t7, -0x13A0
    ctx->r15 = ADD32(ctx->r15, -0X13A0);
    // 0x80146AB4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80146AB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80146ABC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80146AC0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80146AC4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80146AC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80146ACC: sub.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80146AD0: div.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80146AD4: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80146AD8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80146ADC: jr          $ra
    // 0x80146AE0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    return;
    // 0x80146AE0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80146ae4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80146ae4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146AE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80146AE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80146AEC: jr          $ra
    // 0x80146AF0: sb          $a0, 0x19E4($at)
    MEM_B(0X19E4, ctx->r1) = ctx->r4;
    return;
    // 0x80146AF0: sb          $a0, 0x19E4($at)
    MEM_B(0X19E4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80146af4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80146af4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146AF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80146AF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80146AFC: jr          $ra
    // 0x80146B00: sb          $a0, 0x19E0($at)
    MEM_B(0X19E0, ctx->r1) = ctx->r4;
    return;
    // 0x80146B00: sb          $a0, 0x19E0($at)
    MEM_B(0X19E0, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80146b04(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80146b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146B0C: jal         0x80020744
    // 0x80146B10: addiu       $a0, $zero, 0x648
    ctx->r4 = ADD32(0, 0X648);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80146B10: addiu       $a0, $zero, 0x648
    ctx->r4 = ADD32(0, 0X648);
    after_0:
    // 0x80146B14: jal         0x80146AE4
    // 0x80146B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80146AE4)(rdram, ctx);
        goto after_1;
    // 0x80146B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80146B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146B24: jr          $ra
    // 0x80146B28: nop

    return;
    // 0x80146B28: nop

;}
RECOMP_FUNC void M7_FUN_80146b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146B2C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80146B30: lbu         $t6, 0x19E4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X19E4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80146b34(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80146b34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146B38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80146B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146B40: beq         $v1, $t6, L_80146BD0
    if (ctx->r3 == ctx->r14) {
        // 0x80146B44: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80146BD0;
    }
    // 0x80146B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80146B48: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80146B4C: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x80146B50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80146B54: beq         $v0, $at, L_80146B64
    if (ctx->r2 == ctx->r1) {
        // 0x80146B58: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80146B64;
    }
    // 0x80146B58: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80146B5C: bnel        $v0, $at, L_80146BD4
    if (ctx->r2 != ctx->r1) {
        // 0x80146B60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146BD4;
    }
    goto skip_0;
    // 0x80146B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80146B64:
    // 0x80146B64: jal         0x80126944
    // 0x80146B68: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x80146B68: nop

    after_0:
    // 0x80146B6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80146B70: bnel        $v0, $v1, L_80146BD4
    if (ctx->r2 != ctx->r3) {
        // 0x80146B74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146BD4;
    }
    goto skip_1;
    // 0x80146B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80146B78: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x80146B7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80146B80: bne         $v1, $v0, L_80146BAC
    if (ctx->r3 != ctx->r2) {
        // 0x80146B84: nop
    
            goto L_80146BAC;
    }
    // 0x80146B84: nop

    // 0x80146B88: lbu         $t7, 0x19E0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X19E0);
    // 0x80146B8C: bne         $t7, $zero, L_80146BAC
    if (ctx->r15 != 0) {
        // 0x80146B90: nop
    
            goto L_80146BAC;
    }
    // 0x80146B90: nop

    // 0x80146B94: jal         0x80020744
    // 0x80146B98: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80146B98: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    after_1:
    // 0x80146B9C: jal         0x80146AF4
    // 0x80146BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80146AF4)(rdram, ctx);
        goto after_2;
    // 0x80146BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80146BA4: b           L_80146BD4
    // 0x80146BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80146BD4;
    // 0x80146BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146BAC:
    // 0x80146BAC: bne         $v0, $zero, L_80146BD0
    if (ctx->r2 != 0) {
        // 0x80146BB0: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_80146BD0;
    }
    // 0x80146BB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80146BB4: lbu         $t8, 0x19E0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X19E0);
    // 0x80146BB8: bnel        $v1, $t8, L_80146BD4
    if (ctx->r3 != ctx->r24) {
        // 0x80146BBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146BD4;
    }
    goto skip_2;
    // 0x80146BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80146BC0: jal         0x80020744
    // 0x80146BC4: addiu       $a0, $zero, 0x648
    ctx->r4 = ADD32(0, 0X648);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80146BC4: addiu       $a0, $zero, 0x648
    ctx->r4 = ADD32(0, 0X648);
    after_3:
    // 0x80146BC8: jal         0x80146AF4
    // 0x80146BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80146AF4)(rdram, ctx);
        goto after_4;
    // 0x80146BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
L_80146BD0:
    // 0x80146BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146BD4:
    // 0x80146BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146BD8: jr          $ra
    // 0x80146BDC: nop

    return;
    // 0x80146BDC: nop

;}
RECOMP_FUNC void M7_FUN_80146be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80146BE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80146BE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80146BEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80146BF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80146BF4: slti        $at, $a0, 0x800
    ctx->r1 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x80146BF8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80146BFC: bne         $at, $zero, L_80146C18
    if (ctx->r1 != 0) {
        // 0x80146C00: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80146C18;
    }
    // 0x80146C00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80146C04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80146C08: jal         0x801451C0
    // 0x80146C0C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80146C0C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x80146C10: b           L_80146C70
    // 0x80146C14: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_80146C70;
    // 0x80146C14: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80146C18:
    // 0x80146C18: slti        $at, $a0, 0x400
    ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
    // 0x80146C1C: bne         $at, $zero, L_80146C48
    if (ctx->r1 != 0) {
        // 0x80146C20: slti        $at, $a0, 0x800
        ctx->r1 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
            goto L_80146C48;
    }
    // 0x80146C20: slti        $at, $a0, 0x800
    ctx->r1 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x80146C24: beq         $at, $zero, L_80146C48
    if (ctx->r1 == 0) {
        // 0x80146C28: nop
    
            goto L_80146C48;
    }
    // 0x80146C28: nop

    // 0x80146C2C: jal         0x80146B2C
    // 0x80146C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80146B2C)(rdram, ctx);
        goto after_1;
    // 0x80146C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80146C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80146C38: jal         0x801451C0
    // 0x80146C3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x80146C3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80146C40: b           L_80146C70
    // 0x80146C44: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_80146C70;
    // 0x80146C44: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80146C48:
    // 0x80146C48: bltz        $a0, L_80146C6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80146C4C: slti        $at, $a0, 0x400
        ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
            goto L_80146C6C;
    }
    // 0x80146C4C: slti        $at, $a0, 0x400
    ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
    // 0x80146C50: beql        $at, $zero, L_80146C70
    if (ctx->r1 == 0) {
        // 0x80146C54: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80146C70;
    }
    goto skip_0;
    // 0x80146C54: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x80146C58: jal         0x80146B2C
    // 0x80146C5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80146B2C)(rdram, ctx);
        goto after_3;
    // 0x80146C5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80146C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80146C64: jal         0x801451C0
    // 0x80146C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_4;
    // 0x80146C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_80146C6C:
    // 0x80146C6C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80146C70:
    // 0x80146C70: lbu         $t6, 0x48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X48);
    // 0x80146C74: bgez        $t6, L_80146C84
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80146C78: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80146C84;
    }
    // 0x80146C78: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80146C7C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80146C80: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80146C84:
    // 0x80146C84: sb          $t7, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r15;
    // 0x80146C88: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80146C8C: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x80146C90: bgez        $t8, L_80146CA0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80146C94: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80146CA0;
    }
    // 0x80146C94: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80146C98: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80146C9C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80146CA0:
    // 0x80146CA0: sb          $t9, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r25;
    // 0x80146CA4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80146CA8: lbu         $t0, 0x4A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4A);
    // 0x80146CAC: bgez        $t0, L_80146CBC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80146CB0: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80146CBC;
    }
    // 0x80146CB0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80146CB4: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80146CB8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80146CBC:
    // 0x80146CBC: sb          $t1, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r9;
    // 0x80146CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80146CC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80146CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146CCC: jr          $ra
    // 0x80146CD0: nop

    return;
    // 0x80146CD0: nop

;}
RECOMP_FUNC void M7_FUN_80146cd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146CD4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80146CD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80146CDC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80146CE0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80146CE4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80146CE8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80146CEC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80146CF0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80146CF4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80146CF8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80146CFC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80146D00: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80146D04: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80146D08: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80146D0C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80146D10: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80146D14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80146D18: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80146D1C: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80146D20: addiu       $t6, $t6, 0x1A94
    ctx->r14 = ADD32(ctx->r14, 0X1A94);
    // 0x80146D24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80146D28: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x80146D2C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80146D30: addiu       $t0, $t0, 0x1A98
    ctx->r8 = ADD32(ctx->r8, 0X1A98);
    // 0x80146D34: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80146D38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80146D3C: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x80146D40: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80146D44: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80146D48: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80146D4C: subu        $s2, $t3, $s2
    ctx->r18 = SUB32(ctx->r11, ctx->r18);
    // 0x80146D50: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80146D54: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x80146D58: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80146D5C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80146D60: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80146D64: bne         $a1, $zero, L_80146D78
    if (ctx->r5 != 0) {
        // 0x80146D68: sw          $t2, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r10;
            goto L_80146D78;
    }
    // 0x80146D68: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80146D6C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80146D70: b           L_80146D80
    // 0x80146D74: addiu       $s0, $s0, 0x17A0
    ctx->r16 = ADD32(ctx->r16, 0X17A0);
        goto L_80146D80;
    // 0x80146D74: addiu       $s0, $s0, 0x17A0
    ctx->r16 = ADD32(ctx->r16, 0X17A0);
L_80146D78:
    // 0x80146D78: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80146D7C: addiu       $s0, $s0, 0x1900
    ctx->r16 = ADD32(ctx->r16, 0X1900);
L_80146D80:
    // 0x80146D80: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80146D84: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80146D88: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80146D8C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80146D90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80146D94: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80146D98: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80146D9C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80146DA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80146DA4: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80146DA8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80146DAC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80146DB0: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80146DB4: addiu       $s4, $zero, 0x2A
    ctx->r20 = ADD32(0, 0X2A);
L_80146DB8:
    // 0x80146DB8: slti        $at, $s2, 0x800
    ctx->r1 = SIGNED(ctx->r18) < 0X800 ? 1 : 0;
    // 0x80146DBC: bne         $at, $zero, L_80146E1C
    if (ctx->r1 != 0) {
        // 0x80146DC0: sll         $t4, $s1, 1
        ctx->r12 = S32(ctx->r17 << 1);
            goto L_80146E1C;
    }
    // 0x80146DC0: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80146DC4: addiu       $t5, $sp, 0x7C
    ctx->r13 = ADD32(ctx->r29, 0X7C);
    // 0x80146DC8: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80146DCC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x80146DD0: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x80146DD4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80146DD8: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146DDC: addiu       $s2, $s2, -0x800
    ctx->r18 = ADD32(ctx->r18, -0X800);
    // 0x80146DE0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80146DE4: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80146DE8: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80146DEC: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80146DF0: mflo        $t7
    ctx->r15 = lo;
    // 0x80146DF4: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x80146DF8: lb          $t1, 0x1($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X1);
    // 0x80146DFC: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80146E00: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146E04: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80146E08: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80146E0C: mflo        $t2
    ctx->r10 = lo;
    // 0x80146E10: sh          $t2, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r10;
    // 0x80146E14: b           L_801470A0
    // 0x80146E18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_801470A0;
    // 0x80146E18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80146E1C:
    // 0x80146E1C: bgezl       $s2, L_80146E2C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80146E20: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_80146E2C;
    }
    goto skip_0;
    // 0x80146E20: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    skip_0:
    // 0x80146E24: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80146E28: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
L_80146E2C:
    // 0x80146E2C: jal         0x8001EAD0
    // 0x80146E30: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80146E30: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80146E34: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80146E38: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80146E3C: jal         0x8001EB64
    // 0x80146E40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80146E40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x80146E44: beq         $s1, $zero, L_80146E6C
    if (ctx->r17 == 0) {
        // 0x80146E48: addiu       $s2, $s2, -0x800
        ctx->r18 = ADD32(ctx->r18, -0X800);
            goto L_80146E6C;
    }
    // 0x80146E48: addiu       $s2, $s2, -0x800
    ctx->r18 = ADD32(ctx->r18, -0X800);
    // 0x80146E4C: beql        $s1, $s6, L_80146EFC
    if (ctx->r17 == ctx->r22) {
        // 0x80146E50: div.s       $f2, $f20, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
            goto L_80146EFC;
    }
    goto skip_1;
    // 0x80146E50: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    skip_1:
    // 0x80146E54: beql        $s1, $s7, L_80146F80
    if (ctx->r17 == ctx->r23) {
        // 0x80146E58: div.s       $f2, $f20, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
            goto L_80146F80;
    }
    goto skip_2;
    // 0x80146E58: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    skip_2:
    // 0x80146E5C: beql        $s1, $fp, L_80147014
    if (ctx->r17 == ctx->r30) {
        // 0x80146E60: div.s       $f2, $f20, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
            goto L_80147014;
    }
    goto skip_3;
    // 0x80146E60: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    skip_3:
    // 0x80146E64: b           L_80147098
    // 0x80146E68: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
        goto L_80147098;
    // 0x80146E68: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
L_80146E6C:
    // 0x80146E6C: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80146E70: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x80146E74: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80146E78: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80146E7C: addu        $t0, $s0, $t7
    ctx->r8 = ADD32(ctx->r16, ctx->r15);
    // 0x80146E80: add.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80146E84: div.s       $f12, $f22, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80146E88: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80146E8C: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80146E90: mul.s       $f16, $f12, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x80146E94: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80146E98: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80146E9C: div.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80146EA0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80146EA4: nop

    // 0x80146EA8: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80146EAC: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80146EB0: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x80146EB4: addu        $t5, $s0, $t2
    ctx->r13 = ADD32(ctx->r16, ctx->r10);
    // 0x80146EB8: sh          $t3, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r11;
    // 0x80146EBC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80146EC0: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80146EC4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80146EC8: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80146ECC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80146ED0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80146ED4: nop

    // 0x80146ED8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80146EDC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80146EE0: sh          $v1, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r3;
    // 0x80146EE4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80146EE8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80146EEC: addu        $t4, $s0, $t1
    ctx->r12 = ADD32(ctx->r16, ctx->r9);
    // 0x80146EF0: b           L_80147094
    // 0x80146EF4: sh          $v1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r3;
        goto L_80147094;
    // 0x80146EF4: sh          $v1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r3;
    // 0x80146EF8: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_80146EFC:
    // 0x80146EFC: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x80146F00: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80146F04: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80146F08: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80146F0C: add.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80146F10: div.s       $f12, $f22, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f8.fl);
    // 0x80146F14: mul.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80146F18: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80146F1C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80146F20: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80146F24: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x80146F28: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80146F2C: addiu       $t8, $t7, -0x2A
    ctx->r24 = ADD32(ctx->r15, -0X2A);
    // 0x80146F30: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80146F34: addu        $t4, $s0, $t1
    ctx->r12 = ADD32(ctx->r16, ctx->r9);
    // 0x80146F38: div.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80146F3C: sh          $t8, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r24;
    // 0x80146F40: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80146F44: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80146F48: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80146F4C: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x80146F50: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80146F54: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80146F58: nop

    // 0x80146F5C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80146F60: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80146F64: sh          $a0, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r4;
    // 0x80146F68: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80146F6C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80146F70: addu        $t0, $s0, $t7
    ctx->r8 = ADD32(ctx->r16, ctx->r15);
    // 0x80146F74: b           L_80147094
    // 0x80146F78: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
        goto L_80147094;
    // 0x80146F78: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
    // 0x80146F7C: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_80146F80:
    // 0x80146F80: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x80146F84: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80146F88: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80146F8C: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x80146F90: add.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80146F94: div.s       $f12, $f22, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80146F98: mul.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80146F9C: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80146FA0: mul.s       $f6, $f12, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x80146FA4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80146FA8: nop

    // 0x80146FAC: addiu       $t3, $t2, -0x2A
    ctx->r11 = ADD32(ctx->r10, -0X2A);
    // 0x80146FB0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80146FB4: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x80146FB8: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80146FBC: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80146FC0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80146FC4: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80146FC8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80146FCC: addiu       $t4, $t8, -0x2A
    ctx->r12 = ADD32(ctx->r24, -0X2A);
    // 0x80146FD0: sh          $t4, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r12;
    // 0x80146FD4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80146FD8: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80146FDC: addu        $t0, $s0, $t7
    ctx->r8 = ADD32(ctx->r16, ctx->r15);
    // 0x80146FE0: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x80146FE4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80146FE8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80146FEC: nop

    // 0x80146FF0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80146FF4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80146FF8: sh          $v1, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r3;
    // 0x80146FFC: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80147000: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80147004: addu        $t2, $s0, $t8
    ctx->r10 = ADD32(ctx->r16, ctx->r24);
    // 0x80147008: b           L_80147094
    // 0x8014700C: sh          $v1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r3;
        goto L_80147094;
    // 0x8014700C: sh          $v1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r3;
    // 0x80147010: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_80147014:
    // 0x80147014: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x80147018: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8014701C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80147020: addu        $t0, $s0, $t7
    ctx->r8 = ADD32(ctx->r16, ctx->r15);
    // 0x80147024: add.s       $f18, $f2, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80147028: div.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8014702C: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80147030: nop

    // 0x80147034: mul.s       $f8, $f12, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x80147038: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8014703C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80147040: div.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80147044: addiu       $t3, $v1, -0x2A
    ctx->r11 = ADD32(ctx->r3, -0X2A);
    // 0x80147048: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x8014704C: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80147050: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80147054: addu        $t2, $s0, $t8
    ctx->r10 = ADD32(ctx->r16, ctx->r24);
    // 0x80147058: sh          $v1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r3;
    // 0x8014705C: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80147060: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80147064: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x80147068: mul.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8014706C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80147070: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80147074: nop

    // 0x80147078: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8014707C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80147080: sh          $a0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r4;
    // 0x80147084: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80147088: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x8014708C: addu        $t0, $s0, $t3
    ctx->r8 = ADD32(ctx->r16, ctx->r11);
    // 0x80147090: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
L_80147094:
    // 0x80147094: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
L_80147098:
    // 0x80147098: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8014709C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801470A0:
    // 0x801470A0: bne         $s1, $s5, L_80146DB8
    if (ctx->r17 != ctx->r21) {
        // 0x801470A4: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_80146DB8;
    }
    // 0x801470A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801470A8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x801470AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801470B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801470B4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801470B8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x801470BC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801470C0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x801470C4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x801470C8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x801470CC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x801470D0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x801470D4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x801470D8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x801470DC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x801470E0: jr          $ra
    // 0x801470E4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801470E4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801470e8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801470e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801470E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801470EC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801470F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801470F4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801470F8: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x801470FC: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80147100: addu        $t0, $a1, $a2
    ctx->r8 = ADD32(ctx->r5, ctx->r6);
    // 0x80147104: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80147108: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8014710C: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80147110: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80147114: beq         $at, $zero, L_80147140
    if (ctx->r1 == 0) {
        // 0x80147118: sra         $v0, $v0, 24
        ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
            goto L_80147140;
    }
    // 0x80147118: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
L_8014711C:
    // 0x8014711C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80147120: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80147124: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80147128: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8014712C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80147130: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80147134: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80147138: bne         $at, $zero, L_8014711C
    if (ctx->r1 != 0) {
        // 0x8014713C: sb          $a3, 0x22($t1)
        MEM_B(0X22, ctx->r9) = ctx->r7;
            goto L_8014711C;
    }
    // 0x8014713C: sb          $a3, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r7;
L_80147140:
    // 0x80147140: jr          $ra
    // 0x80147144: nop

    return;
    // 0x80147144: nop

;}
RECOMP_FUNC void M7_FUN_80147148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147148: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8014714C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80147150: beq         $a0, $zero, L_8014716C
    if (ctx->r4 == 0) {
        // 0x80147154: sra         $a1, $a1, 24
        ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
            goto L_8014716C;
    }
    // 0x80147154: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80147158: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8014715C: sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
L_80147160:
    // 0x80147160: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x80147164: bnel        $a0, $zero, L_80147160
    if (ctx->r4 != 0) {
        // 0x80147168: sb          $v0, 0x22($a0)
        MEM_B(0X22, ctx->r4) = ctx->r2;
            goto L_80147160;
    }
    goto skip_0;
    // 0x80147168: sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
    skip_0:
L_8014716C:
    // 0x8014716C: jr          $ra
    // 0x80147170: nop

    return;
    // 0x80147170: nop

;}
RECOMP_FUNC void M7_FUN_80147174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014717C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80147180: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80147184: lbu         $t6, 0xB($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB);
    // 0x80147188: addiu       $t7, $t6, -0x14
    ctx->r15 = ADD32(ctx->r14, -0X14);
    // 0x8014718C: sb          $t7, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r15;
    // 0x80147190: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x80147194: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x80147198: beq         $a2, $zero, L_801471B8
    if (ctx->r6 == 0) {
        // 0x8014719C: lbu         $v1, 0xB($t8)
        ctx->r3 = MEM_BU(ctx->r24, 0XB);
            goto L_801471B8;
    }
    // 0x8014719C: lbu         $v1, 0xB($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0XB);
    // 0x801471A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801471A4: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    // 0x801471A8: jal         0x80147174
    // 0x801471AC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80147174)(rdram, ctx);
        goto after_0;
    // 0x801471AC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x801471B0: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x801471B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801471B8:
    // 0x801471B8: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801471BC: beql        $at, $zero, L_801471D0
    if (ctx->r1 == 0) {
        // 0x801471C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801471D0;
    }
    goto skip_0;
    // 0x801471C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801471C4: jal         0x80006088
    // 0x801471C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x801471C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x801471CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801471D0:
    // 0x801471D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801471D4: jr          $ra
    // 0x801471D8: nop

    return;
    // 0x801471D8: nop

;}
RECOMP_FUNC void M7_FUN_801471dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801471DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801471E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801471E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801471E8: beq         $a0, $zero, L_80147204
    if (ctx->r4 == 0) {
        // 0x801471EC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80147204;
    }
    // 0x801471EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_801471F0:
    // 0x801471F0: jal         0x80006088
    // 0x801471F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x801471F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801471F8: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801471FC: bne         $s0, $zero, L_801471F0
    if (ctx->r16 != 0) {
        // 0x80147200: nop
    
            goto L_801471F0;
    }
    // 0x80147200: nop

L_80147204:
    // 0x80147204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014720C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80147210: jr          $ra
    // 0x80147214: nop

    return;
    // 0x80147214: nop

;}
RECOMP_FUNC void M7_FUN_80147218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014721C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147220: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x80147224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80147228: beq         $a1, $zero, L_80147240
    if (ctx->r5 == 0) {
        // 0x8014722C: nop
    
            goto L_80147240;
    }
    // 0x8014722C: nop

    // 0x80147230: jal         0x801471DC
    // 0x80147234: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_0;
    // 0x80147234: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80147238: b           L_80147240
    // 0x8014723C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147240;
    // 0x8014723C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80147240:
    // 0x80147240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147248: jr          $ra
    // 0x8014724C: nop

    return;
    // 0x8014724C: nop

;}
RECOMP_FUNC void M7_FUN_80147250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147250: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80147254: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80147258: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8014725C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80147260: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80147264: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80147268: beq         $v0, $zero, L_80147294
    if (ctx->r2 == 0) {
            // 0x8014726C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80147294)(rdram, ctx);
    return;
    }
    // 0x8014726C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80147270: sb          $a1, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r5;
    // 0x80147274: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80147278: sb          $a2, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r6;
    // 0x8014727C: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80147280: sb          $a3, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r7;
    // 0x80147284: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80147288: lbu         $t8, 0x13($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X13);
    // 0x8014728C: jr          $ra
    // 0x80147290: sb          $t8, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r24;
    return;
    // 0x80147290: sb          $t8, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147294(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147294: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x80147298: sb          $a1, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r5;
    // 0x8014729C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801472A0: sb          $a2, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r6;
    // 0x801472A4: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x801472A8: sb          $a3, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r7;
    // 0x801472AC: lw          $t4, 0x30($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X30);
    // 0x801472B0: lbu         $t3, 0x13($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X13);
    // 0x801472B4: sb          $t3, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r11;
    // 0x801472B8: jr          $ra
    // 0x801472BC: nop

    return;
    // 0x801472BC: nop

;}
RECOMP_FUNC void M7_FUN_801472c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801472C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801472C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801472C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801472CC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x801472D0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801472D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801472D8: beq         $v0, $zero, L_80147304
    if (ctx->r2 == 0) {
            // 0x801472DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80147304)(rdram, ctx);
    return;
    }
    // 0x801472DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801472E0: sb          $a1, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r5;
    // 0x801472E4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801472E8: sb          $a2, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r6;
    // 0x801472EC: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x801472F0: sb          $a3, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r7;
    // 0x801472F4: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x801472F8: lbu         $t8, 0x13($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X13);
    // 0x801472FC: jr          $ra
    // 0x80147300: sb          $t8, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r24;
    return;
    // 0x80147300: sb          $t8, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80147304(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80147304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147304: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x80147308: sb          $a1, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r5;
    // 0x8014730C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x80147310: sb          $a2, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r6;
    // 0x80147314: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x80147318: sb          $a3, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r7;
    // 0x8014731C: lw          $t4, 0x30($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X30);
    // 0x80147320: lbu         $t3, 0x13($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X13);
    // 0x80147324: sb          $t3, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r11;
    // 0x80147328: jr          $ra
    // 0x8014732C: nop

    return;
    // 0x8014732C: nop

;}
RECOMP_FUNC void M7_FUN_80147330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147330: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80147334: lhu         $t6, -0x6B8A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B8A);
    // 0x80147338: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8014733C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80147340: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80147344: beq         $t7, $zero, L_80147368
    if (ctx->r15 == 0) {
        // 0x80147348: nop
    
            goto L_80147368;
    }
    // 0x80147348: nop

    // 0x8014734C: beq         $v0, $zero, L_80147368
    if (ctx->r2 == 0) {
        // 0x80147350: nop
    
            goto L_80147368;
    }
    // 0x80147350: nop

    // 0x80147354: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_80147358:
    // 0x80147358: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8014735C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80147360: bnel        $v0, $zero, L_80147358
    if (ctx->r2 != 0) {
        // 0x80147364: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_80147358;
    }
    goto skip_0;
    // 0x80147364: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
L_80147368:
    // 0x80147368: jr          $ra
    // 0x8014736C: nop

    return;
    // 0x8014736C: nop

;}
RECOMP_FUNC void M7_FUN_80147370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147370: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147374: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80147378: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8014737C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80147380: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80147384: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80147388: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014738C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80147390: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80147394: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80147398: lw          $s0, 0x24($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X24);
    // 0x8014739C: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x801473A0: andi        $s2, $a2, 0xFF
    ctx->r18 = ctx->r6 & 0XFF;
    // 0x801473A4: beq         $s0, $zero, L_801473D4
    if (ctx->r16 == 0) {
        // 0x801473A8: andi        $s3, $a3, 0xFF
        ctx->r19 = ctx->r7 & 0XFF;
            goto L_801473D4;
    }
    // 0x801473A8: andi        $s3, $a3, 0xFF
    ctx->r19 = ctx->r7 & 0XFF;
    // 0x801473AC: lbu         $s4, 0x4B($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0X4B);
    // 0x801473B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801473B4:
    // 0x801473B4: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x801473B8: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x801473BC: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    // 0x801473C0: jal         0x80147250
    // 0x801473C4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_0;
    // 0x801473C4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_0:
    // 0x801473C8: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801473CC: bnel        $s0, $zero, L_801473B4
    if (ctx->r16 != 0) {
        // 0x801473D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801473B4;
    }
    goto skip_0;
    // 0x801473D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_801473D4:
    // 0x801473D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801473D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801473DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801473E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801473E4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801473E8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801473EC: jr          $ra
    // 0x801473F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801473F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801473f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801473f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801473F4: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x801473F8: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801473FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80147400: beq         $a1, $zero, L_80147448
    if (ctx->r5 == 0) {
        // 0x80147404: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_80147448;
    }
    // 0x80147404: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80147408: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014740C: addiu       $a0, $a0, -0x1368
    ctx->r4 = ADD32(ctx->r4, -0X1368);
    // 0x80147410: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
L_80147414:
    // 0x80147414: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x80147418: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8014741C: bltzl       $t7, L_80147438
    if (SIGNED(ctx->r15) < 0) {
        // 0x80147420: lw          $a1, 0x10($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X10);
            goto L_80147438;
    }
    goto skip_0;
    // 0x80147420: lw          $a1, 0x10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X10);
    skip_0:
    // 0x80147424: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
    // 0x80147428: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x8014742C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80147430: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80147434: lw          $a1, 0x10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X10);
L_80147438:
    // 0x80147438: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8014743C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80147440: bnel        $a1, $zero, L_80147414
    if (ctx->r5 != 0) {
        // 0x80147444: sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6 << 2);
            goto L_80147414;
    }
    goto skip_1;
    // 0x80147444: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    skip_1:
L_80147448:
    // 0x80147448: jr          $ra
    // 0x8014744C: nop

    return;
    // 0x8014744C: nop

;}
RECOMP_FUNC void M7_FUN_80147450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147454: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80147458: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8014745C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80147460: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80147464: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80147468: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014746C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80147470: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80147474: lw          $s0, 0x24($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X24);
    // 0x80147478: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8014747C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80147480: beq         $s0, $zero, L_801474FC
    if (ctx->r16 == 0) {
        // 0x80147484: lw          $s2, 0x4($v0)
        ctx->r18 = MEM_W(ctx->r2, 0X4);
            goto L_801474FC;
    }
    // 0x80147484: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
    // 0x80147488: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8014748C: addiu       $s3, $s3, -0x1368
    ctx->r19 = ADD32(ctx->r19, -0X1368);
    // 0x80147490: lui         $s5, 0x4000
    ctx->r21 = S32(0X4000 << 16);
    // 0x80147494: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80147498: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
L_8014749C:
    // 0x8014749C: addu        $t7, $s2, $v0
    ctx->r15 = ADD32(ctx->r18, ctx->r2);
    // 0x801474A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801474A4: addu        $t9, $s3, $v0
    ctx->r25 = ADD32(ctx->r19, ctx->r2);
    // 0x801474A8: bltzl       $t8, L_801474EC
    if (SIGNED(ctx->r24) < 0) {
        // 0x801474AC: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801474EC;
    }
    goto skip_0;
    // 0x801474AC: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x801474B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801474B4: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x801474B8: bne         $s4, $s1, L_801474D8
    if (ctx->r20 != ctx->r17) {
        // 0x801474BC: sw          $t0, 0x24($t1)
        MEM_W(0X24, ctx->r9) = ctx->r8;
            goto L_801474D8;
    }
    // 0x801474BC: sw          $t0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r8;
    // 0x801474C0: jal         0x8000C3B0
    // 0x801474C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_0;
    // 0x801474C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801474C8: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x801474CC: or          $t2, $v0, $s5
    ctx->r10 = ctx->r2 | ctx->r21;
    // 0x801474D0: b           L_801474E8
    // 0x801474D4: sw          $t2, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r10;
        goto L_801474E8;
    // 0x801474D4: sw          $t2, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r10;
L_801474D8:
    // 0x801474D8: jal         0x8000C3B0
    // 0x801474DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_1;
    // 0x801474DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801474E0: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x801474E4: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_801474E8:
    // 0x801474E8: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
L_801474EC:
    // 0x801474EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801474F0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801474F4: bnel        $s0, $zero, L_8014749C
    if (ctx->r16 != 0) {
        // 0x801474F8: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_8014749C;
    }
    goto skip_1;
    // 0x801474F8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    skip_1:
L_801474FC:
    // 0x801474FC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80147500: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80147504: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80147508: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8014750C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80147510: jal         0x80147370
    // 0x80147514: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_2;
    // 0x80147514: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80147518: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8014751C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80147520: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80147524: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80147528: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8014752C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80147530: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80147534: jr          $ra
    // 0x80147538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80147538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014753c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014753c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014753C: lw          $a2, 0x24($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X24);
    // 0x80147540: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80147544: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80147548: beq         $a2, $zero, L_80147590
    if (ctx->r6 == 0) {
        // 0x8014754C: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_80147590;
    }
    // 0x8014754C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80147550: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
L_80147554:
    // 0x80147554: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80147558: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8014755C: bltzl       $t8, L_80147580
    if (SIGNED(ctx->r24) < 0) {
        // 0x80147560: lw          $a2, 0x10($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X10);
            goto L_80147580;
    }
    goto skip_0;
    // 0x80147560: lw          $a2, 0x10($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x80147564: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x80147568: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8014756C: ori         $t0, $t9, 0x100
    ctx->r8 = ctx->r25 | 0X100;
    // 0x80147570: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x80147574: lw          $t1, 0x2C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X2C);
    // 0x80147578: sw          $a1, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r5;
    // 0x8014757C: lw          $a2, 0x10($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X10);
L_80147580:
    // 0x80147580: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80147584: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80147588: bnel        $a2, $zero, L_80147554
    if (ctx->r6 != 0) {
        // 0x8014758C: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80147554;
    }
    goto skip_1;
    // 0x8014758C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    skip_1:
L_80147590:
    // 0x80147590: jr          $ra
    // 0x80147594: nop

    return;
    // 0x80147594: nop

;}
