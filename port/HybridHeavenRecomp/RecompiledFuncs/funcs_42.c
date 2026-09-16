#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c00fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C00FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C0100: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0104: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C0108: lw          $t7, -0x72FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X72FC);
    // 0x801C010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C0110: lw          $t9, 0x1E8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1E8);
    // 0x801C0114: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801C0118: lw          $t8, 0x1EC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1EC);
    // 0x801C011C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x801C0120: lw          $t9, 0x1F0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1F0);
    // 0x801C0124: jr          $ra
    // 0x801C0128: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    return;
    // 0x801C0128: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c012c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c012c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C012C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C0130: lbu         $v1, -0x42B3($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X42B3);
    // 0x801C0134: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0138: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C013C: andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // 0x801C0140: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801C0144: beq         $v1, $zero, L_801C0158
    if (ctx->r3 == 0) {
        // 0x801C0148: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C0158;
    }
    // 0x801C0148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C014C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801C0150: lh          $v1, -0x6CAC($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X6CAC);
    // 0x801C0154: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
L_801C0158:
    // 0x801C0158: lw          $t6, -0x7300($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7300);
    // 0x801C015C: beq         $t6, $zero, L_801C0184
    if (ctx->r14 == 0) {
            // 0x801C0160: nop

    LOOKUP_FUNC(0x801C0184)(rdram, ctx);
    return;
    }
    // 0x801C0160: nop

    // 0x801C0164: beq         $v1, $zero, L_801C0184
    if (ctx->r3 == 0) {
            // 0x801C0168: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801C0184)(rdram, ctx);
    return;
    }
    // 0x801C0168: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x801C016C: lhu         $t7, -0x6B88($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6B88);
    // 0x801C0170: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x801C0174: beq         $t8, $zero, L_801C0184
    if (ctx->r24 == 0) {
            // 0x801C0178: nop

    LOOKUP_FUNC(0x801C0184)(rdram, ctx);
    return;
    }
    // 0x801C0178: nop

    // 0x801C017C: jr          $ra
    // 0x801C0180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C0180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0184(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0184: sw          $v1, -0x7300($at)
    MEM_W(-0X7300, ctx->r1) = ctx->r3;
    // 0x801C0188: jr          $ra
    // 0x801C018C: nop

    return;
    // 0x801C018C: nop

;}
RECOMP_FUNC void M24_FUN_801c0190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0190: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0194: lw          $v0, -0x731C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X731C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0198(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C019C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801C01A0: bne         $v0, $at, L_801C01B0
    if (ctx->r2 != ctx->r1) {
        // 0x801C01A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801C01B0;
    }
    // 0x801C01A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C01A8: b           L_801C01E0
    // 0x801C01AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C01E0;
    // 0x801C01AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C01B0:
    // 0x801C01B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801C01B4: bne         $v0, $at, L_801C01C4
    if (ctx->r2 != ctx->r1) {
        // 0x801C01B8: nop
    
            goto L_801C01C4;
    }
    // 0x801C01B8: nop

    // 0x801C01BC: b           L_801C01E0
    // 0x801C01C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C01E0;
    // 0x801C01C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C01C4:
    // 0x801C01C4: jal         0x801C01F0
    // 0x801C01C8: nop

    LOOKUP_FUNC(0x801C01F0)(rdram, ctx);
        goto after_0;
    // 0x801C01C8: nop

    after_0:
    // 0x801C01CC: beql        $v0, $zero, L_801C01E0
    if (ctx->r2 == 0) {
        // 0x801C01D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C01E0;
    }
    goto skip_0;
    // 0x801C01D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801C01D4: b           L_801C01E0
    // 0x801C01D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C01E0;
    // 0x801C01D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C01DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C01E0:
    // 0x801C01E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C01E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C01E8: jr          $ra
    // 0x801C01EC: nop

    return;
    // 0x801C01EC: nop

;}
RECOMP_FUNC void M24_FUN_801c01f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C01F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C01F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C01F8: jal         0x801D1B04
    // 0x801C01FC: nop

    LOOKUP_FUNC(0x801D1B04)(rdram, ctx);
        goto after_0;
    // 0x801C01FC: nop

    after_0:
    // 0x801C0200: beq         $v0, $zero, L_801C0210
    if (ctx->r2 == 0) {
        // 0x801C0204: nop
    
            goto L_801C0210;
    }
    // 0x801C0204: nop

    // 0x801C0208: b           L_801C0244
    // 0x801C020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C0244;
    // 0x801C020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C0210:
    // 0x801C0210: jal         0x801D0AF8
    // 0x801C0214: nop

    LOOKUP_FUNC(0x801D0AF8)(rdram, ctx);
        goto after_1;
    // 0x801C0214: nop

    after_1:
    // 0x801C0218: beq         $v0, $zero, L_801C0228
    if (ctx->r2 == 0) {
        // 0x801C021C: nop
    
            goto L_801C0228;
    }
    // 0x801C021C: nop

    // 0x801C0220: b           L_801C0244
    // 0x801C0224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C0244;
    // 0x801C0224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C0228:
    // 0x801C0228: jal         0x801D6A1C
    // 0x801C022C: nop

    LOOKUP_FUNC(0x801D6A1C)(rdram, ctx);
        goto after_2;
    // 0x801C022C: nop

    after_2:
    // 0x801C0230: beql        $v0, $zero, L_801C0244
    if (ctx->r2 == 0) {
        // 0x801C0234: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C0244;
    }
    goto skip_0;
    // 0x801C0234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C0238: b           L_801C0244
    // 0x801C023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C0244;
    // 0x801C023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C0240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C0244:
    // 0x801C0244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C024C: jr          $ra
    // 0x801C0250: nop

    return;
    // 0x801C0250: nop

;}
RECOMP_FUNC void M24_FUN_801c0254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C025C: jal         0x801BFF20
    // 0x801C0260: nop

    LOOKUP_FUNC(0x801BFF20)(rdram, ctx);
        goto after_0;
    // 0x801C0260: nop

    after_0:
    // 0x801C0264: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0268: lw          $t7, -0x17D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17D8);
    // 0x801C026C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C0270: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0274: beq         $t7, $zero, L_801C02D0
    if (ctx->r15 == 0) {
        // 0x801C0278: sw          $t6, -0x7308($at)
        MEM_W(-0X7308, ctx->r1) = ctx->r14;
            goto L_801C02D0;
    }
    // 0x801C0278: sw          $t6, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r14;
    // 0x801C027C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C0280: lw          $t8, -0x731C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X731C);
    // 0x801C0284: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C0288: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C028C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C0290: lw          $t1, -0x7318($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7318);
    // 0x801C0294: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801C0298: lw          $t0, -0x7400($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7400);
    // 0x801C029C: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C02A0: lw          $t5, -0x7310($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7310);
    // 0x801C02A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801C02A8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801C02AC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C02B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C02B4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801C02B8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C02BC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x801C02C0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801C02C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C02C8: b           L_801C02EC
    // 0x801C02CC: sw          $t8, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r24;
        goto L_801C02EC;
    // 0x801C02CC: sw          $t8, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r24;
L_801C02D0:
    // 0x801C02D0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C02D4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C02D8: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801C02DC: jal         0x801C2090
    // 0x801C02E0: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2090)(rdram, ctx);
        goto after_1;
    // 0x801C02E0: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_1:
    // 0x801C02E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C02E8: sw          $v0, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r2;
L_801C02EC:
    // 0x801C02EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C02F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C02F4: jr          $ra
    // 0x801C02F8: nop

    return;
    // 0x801C02F8: nop

;}
RECOMP_FUNC void M24_FUN_801c02fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C02FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0304: jal         0x8012FF4C
    // 0x801C0308: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_0;
    // 0x801C0308: nop

    after_0:
    // 0x801C030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0310: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801C0314: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0318: jr          $ra
    // 0x801C031C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C031C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0320(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0320: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C0324: lbu         $v0, -0x40C3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X40C3);
    // 0x801C0328: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801C032C: jr          $ra
    // 0x801C0330: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801C0330: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0334(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0334: xori        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 ^ 0X4;
    // 0x801C0338: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C033C: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C0340: xori        $v0, $a0, 0xB
        ctx->r2 = ctx->r4 ^ 0XB;
            goto L_801C0394;
    }
    // 0x801C0340: xori        $v0, $a0, 0xB
    ctx->r2 = ctx->r4 ^ 0XB;
    // 0x801C0344: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0348: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C034C: xori        $v0, $a0, 0xC
        ctx->r2 = ctx->r4 ^ 0XC;
            goto L_801C0394;
    }
    // 0x801C034C: xori        $v0, $a0, 0xC
    ctx->r2 = ctx->r4 ^ 0XC;
    // 0x801C0350: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0354: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C0358: xori        $v0, $a0, 0xE
        ctx->r2 = ctx->r4 ^ 0XE;
            goto L_801C0394;
    }
    // 0x801C0358: xori        $v0, $a0, 0xE
    ctx->r2 = ctx->r4 ^ 0XE;
    // 0x801C035C: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0360: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C0364: xori        $v0, $a0, 0xF
        ctx->r2 = ctx->r4 ^ 0XF;
            goto L_801C0394;
    }
    // 0x801C0364: xori        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 ^ 0XF;
    // 0x801C0368: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C036C: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C0370: xori        $v0, $a0, 0x10
        ctx->r2 = ctx->r4 ^ 0X10;
            goto L_801C0394;
    }
    // 0x801C0370: xori        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 ^ 0X10;
    // 0x801C0374: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0378: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C037C: xori        $v0, $a0, 0x9
        ctx->r2 = ctx->r4 ^ 0X9;
            goto L_801C0394;
    }
    // 0x801C037C: xori        $v0, $a0, 0x9
    ctx->r2 = ctx->r4 ^ 0X9;
    // 0x801C0380: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C0384: bne         $v1, $zero, L_801C0394
    if (ctx->r3 != 0) {
        // 0x801C0388: nop
    
            goto L_801C0394;
    }
    // 0x801C0388: nop

    // 0x801C038C: xori        $v1, $a0, 0xA
    ctx->r3 = ctx->r4 ^ 0XA;
    // 0x801C0390: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
L_801C0394:
    // 0x801C0394: jr          $ra
    // 0x801C0398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801C0398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c039c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c039c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C039C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801C03A0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x801C03A4: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x801C03A8: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x801C03AC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801C03B0: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801C03B4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x801C03B8: addiu       $v1, $zero, 0x17
    ctx->r3 = ADD32(0, 0X17);
    // 0x801C03BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801C03C0:
    // 0x801C03C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801C03C4: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x801C03C8: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x801C03CC: beq         $at, $zero, L_801C0430
    if (ctx->r1 == 0) {
        // 0x801C03D0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801C0430;
    }
    // 0x801C03D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801C03D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C03D8: addu        $at, $at, $t7
    gpr jr_addend_801C03E0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801C03DC: lw          $t7, -0x323C($at)
    ctx->r15 = ADD32(ctx->r1, -0X323C);
    // 0x801C03E0: jr          $t7
    // 0x801C03E4: nop

    switch (jr_addend_801C03E0 >> 2) {
        case 0: goto L_801C03E8; break;
        case 1: goto L_801C0430; break;
        case 2: goto L_801C0430; break;
        case 3: goto L_801C0430; break;
        case 4: goto L_801C0430; break;
        case 5: goto L_801C0418; break;
        case 6: goto L_801C0430; break;
        case 7: goto L_801C03F0; break;
        case 8: goto L_801C03F8; break;
        case 9: goto L_801C0430; break;
        case 10: goto L_801C0400; break;
        case 11: goto L_801C0408; break;
        case 12: goto L_801C0410; break;
        case 13: goto L_801C0430; break;
        case 14: goto L_801C0430; break;
        case 15: goto L_801C0430; break;
        case 16: goto L_801C0430; break;
        case 17: goto L_801C0420; break;
        case 18: goto L_801C0428; break;
        default: switch_error(__func__, 0x801C03E0, 0x801DCDC4);
    }
    // 0x801C03E4: nop

L_801C03E8:
    // 0x801C03E8: b           L_801C03C0
    // 0x801C03EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_801C03C0;
    // 0x801C03EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_801C03F0:
    // 0x801C03F0: b           L_801C03C0
    // 0x801C03F4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
        goto L_801C03C0;
    // 0x801C03F4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_801C03F8:
    // 0x801C03F8: b           L_801C03C0
    // 0x801C03FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_801C03C0;
    // 0x801C03FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_801C0400:
    // 0x801C0400: b           L_801C03C0
    // 0x801C0404: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
        goto L_801C03C0;
    // 0x801C0404: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_801C0408:
    // 0x801C0408: b           L_801C03C0
    // 0x801C040C: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
        goto L_801C03C0;
    // 0x801C040C: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
L_801C0410:
    // 0x801C0410: b           L_801C03C0
    // 0x801C0414: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
        goto L_801C03C0;
    // 0x801C0414: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_801C0418:
    // 0x801C0418: b           L_801C03C0
    // 0x801C041C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_801C03C0;
    // 0x801C041C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_801C0420:
    // 0x801C0420: b           L_801C03C0
    // 0x801C0424: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
        goto L_801C03C0;
    // 0x801C0424: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_801C0428:
    // 0x801C0428: b           L_801C03C0
    // 0x801C042C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
        goto L_801C03C0;
    // 0x801C042C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_801C0430:
    // 0x801C0430: jr          $ra
    // 0x801C0434: nop

    return;
    // 0x801C0434: nop

;}
RECOMP_FUNC void M24_FUN_801c0438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C043C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0440: jal         0x80020744
    // 0x801C0444: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801C0444: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801C0448: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801C044C: jal         0x800023EC
    // 0x801C0450: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_1;
    // 0x801C0450: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_1:
    // 0x801C0454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C045C: jr          $ra
    // 0x801C0460: nop

    return;
    // 0x801C0460: nop

;}
RECOMP_FUNC void M24_FUN_801c0464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0464: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801C0468: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801C046C: lui         $s6, 0x801E
    ctx->r22 = S32(0X801E << 16);
    // 0x801C0470: addiu       $s6, $s6, -0x731C
    ctx->r22 = ADD32(ctx->r22, -0X731C);
    // 0x801C0474: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x801C0478: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x801C047C: lui         $s7, 0x801E
    ctx->r23 = S32(0X801E << 16);
    // 0x801C0480: addiu       $s7, $s7, -0x7318
    ctx->r23 = ADD32(ctx->r23, -0X7318);
    // 0x801C0484: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C0488: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C048C: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x801C0490: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C0494: lw          $t8, -0x738C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X738C);
    // 0x801C0498: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801C049C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C04A0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x801C04A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801C04A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801C04AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801C04B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801C04B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801C04B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C04BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801C04C0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801C04C4: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x801C04C8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C04CC: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x801C04D0: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x801C04D4: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x801C04D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C04DC: beq         $a2, $zero, L_801C0610
    if (ctx->r6 == 0) {
        // 0x801C04E0: nop
    
            goto L_801C0610;
    }
    // 0x801C04E0: nop

    // 0x801C04E4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C04E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C04EC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801C04F0: beq         $v1, $zero, L_801C0608
    if (ctx->r3 == 0) {
        // 0x801C04F4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801C0608;
    }
    // 0x801C04F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801C04F8: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C04FC: addiu       $t4, $t4, -0x72FC
    ctx->r12 = ADD32(ctx->r12, -0X72FC);
    // 0x801C0500: addu        $s5, $a3, $t4
    ctx->r21 = ADD32(ctx->r7, ctx->r12);
    // 0x801C0504: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C0508: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x801C050C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
L_801C0510:
    // 0x801C0510: lhu         $a0, 0x4($fp)
    ctx->r4 = MEM_HU(ctx->r30, 0X4);
    // 0x801C0514: lw          $a1, 0x8($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X8);
    // 0x801C0518: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x801C051C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C0520: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801C0524: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x801C0528: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C052C: jalr        $t9
    // 0x801C0530: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801C0530: nop

    after_0:
    // 0x801C0534: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C0538: lw          $t0, -0x17D8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X17D8);
    // 0x801C053C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801C0540: beql        $t0, $zero, L_801C055C
    if (ctx->r8 == 0) {
        // 0x801C0544: lw          $a0, 0x0($s6)
        ctx->r4 = MEM_W(ctx->r22, 0X0);
            goto L_801C055C;
    }
    goto skip_0;
    // 0x801C0544: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    skip_0:
    // 0x801C0548: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x801C054C: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x801C0550: b           L_801C05BC
    // 0x801C0554: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
        goto L_801C05BC;
    // 0x801C0554: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x801C0558: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
L_801C055C:
    // 0x801C055C: jal         0x801C2024
    // 0x801C0560: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    LOOKUP_FUNC(0x801C2024)(rdram, ctx);
        goto after_1;
    // 0x801C0560: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    after_1:
    // 0x801C0564: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C0568: beq         $v0, $at, L_801C05BC
    if (ctx->r2 == ctx->r1) {
        // 0x801C056C: addiu       $a0, $sp, 0x68
        ctx->r4 = ADD32(ctx->r29, 0X68);
            goto L_801C05BC;
    }
    // 0x801C056C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801C0570: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x801C0574: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x801C0578: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x801C057C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801C0580: jal         0x801C20C4
    // 0x801C0584: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    LOOKUP_FUNC(0x801C20C4)(rdram, ctx);
        goto after_2;
    // 0x801C0584: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_2:
    // 0x801C0588: beq         $v0, $zero, L_801C05B0
    if (ctx->r2 == 0) {
        // 0x801C058C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801C05B0;
    }
    // 0x801C058C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C0590: jal         0x801C1780
    // 0x801C0594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C1780)(rdram, ctx);
        goto after_3;
    // 0x801C0594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x801C0598: bne         $v0, $zero, L_801C05BC
    if (ctx->r2 != 0) {
        // 0x801C059C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801C05BC;
    }
    // 0x801C059C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C05A0: jal         0x801C157C
    // 0x801C05A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C157C)(rdram, ctx);
        goto after_4;
    // 0x801C05A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x801C05A8: b           L_801C05C0
    // 0x801C05AC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_801C05C0;
    // 0x801C05AC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_801C05B0:
    // 0x801C05B0: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801C05B4: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x801C05B8: sw          $s2, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r18;
L_801C05BC:
    // 0x801C05BC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_801C05C0:
    // 0x801C05C0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C05C4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x801C05C8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C05CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C05D0: lw          $t7, -0x738C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X738C);
    // 0x801C05D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C05D8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x801C05DC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801C05E0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801C05E4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x801C05E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C05EC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801C05F0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C05F4: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x801C05F8: addu        $t5, $t4, $s4
    ctx->r13 = ADD32(ctx->r12, ctx->r20);
    // 0x801C05FC: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x801C0600: bnel        $v0, $zero, L_801C0510
    if (ctx->r2 != 0) {
        // 0x801C0604: lw          $t5, 0x0($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X0);
            goto L_801C0510;
    }
    goto skip_1;
    // 0x801C0604: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    skip_1:
L_801C0608:
    // 0x801C0608: b           L_801C0610
    // 0x801C060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C0610;
    // 0x801C060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C0610:
    // 0x801C0610: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801C0614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C0618: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801C061C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801C0620: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801C0624: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801C0628: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801C062C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801C0630: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x801C0634: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x801C0638: jr          $ra
    // 0x801C063C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801C063C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0640(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0640: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C0644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0648: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C064C: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x801C0650: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C0654: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C0658: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C065C: lw          $t8, -0x72FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X72FC);
    // 0x801C0660: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801C0664: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801C0668: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801C066C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x801C0670: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x801C0674: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x801C0678: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x801C067C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x801C0680: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801C0684: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x801C0688: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801C068C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801C0690: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801C0694: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x801C0698: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C069C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C06A0: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x801C06A4: jal         0x801BF7A0
    // 0x801C06A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801BF7A0)(rdram, ctx);
        goto after_0;
    // 0x801C06A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x801C06AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C06B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C06B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C06B8: jr          $ra
    // 0x801C06BC: nop

    return;
    // 0x801C06BC: nop

;}
RECOMP_FUNC void M24_FUN_801c06c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C06C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C06C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C06C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C06CC: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x801C06D0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C06D4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C06D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C06DC: lw          $t8, -0x72FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X72FC);
    // 0x801C06E0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801C06E4: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801C06E8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801C06EC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x801C06F0: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x801C06F4: lui         $t1, 0x8001
    ctx->r9 = S32(0X8001 << 16);
    // 0x801C06F8: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x801C06FC: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x801C0700: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801C0704: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x801C0708: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801C070C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801C0710: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801C0714: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x801C0718: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C071C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C0720: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x801C0724: jal         0x801BF7A0
    // 0x801C0728: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801BF7A0)(rdram, ctx);
        goto after_0;
    // 0x801C0728: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x801C072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C0734: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C0738: jr          $ra
    // 0x801C073C: nop

    return;
    // 0x801C073C: nop

;}
RECOMP_FUNC void M24_FUN_801c0740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0740: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C0744: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C0748: jr          $ra
    // 0x801C074C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C074C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0750(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0750: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C0754: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C0758: jr          $ra
    // 0x801C075C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C075C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0760(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C0768: jal         0x801C0438
    // 0x801C076C: nop

    LOOKUP_FUNC(0x801C0438)(rdram, ctx);
        goto after_0;
    // 0x801C076C: nop

    after_0:
    // 0x801C0770: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C0774: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C0778: addiu       $t6, $zero, 0x73
    ctx->r14 = ADD32(0, 0X73);
    // 0x801C077C: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x801C0780: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x801C0784: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C0788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C078C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801C0790: jal         0x8012FE50
    // 0x801C0794: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x801C0794: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801C0798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C079C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C07A0: jr          $ra
    // 0x801C07A4: nop

    return;
    // 0x801C07A4: nop

;}
RECOMP_FUNC void M24_FUN_801c07a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C07A8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C07AC: lw          $t6, -0x7304($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7304);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c07b0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c07b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C07B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C07B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C07B8: bne         $t6, $zero, L_801C07F0
    if (ctx->r14 != 0) {
        // 0x801C07BC: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801C07F0;
    }
    // 0x801C07BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C07C0: jal         0x801C0334
    // 0x801C07C4: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C0334)(rdram, ctx);
        goto after_0;
    // 0x801C07C4: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_0:
    // 0x801C07C8: beq         $v0, $zero, L_801C07F0
    if (ctx->r2 == 0) {
        // 0x801C07CC: nop
    
            goto L_801C07F0;
    }
    // 0x801C07CC: nop

    // 0x801C07D0: jal         0x801C088C
    // 0x801C07D4: nop

    LOOKUP_FUNC(0x801C088C)(rdram, ctx);
        goto after_1;
    // 0x801C07D4: nop

    after_1:
    // 0x801C07D8: jal         0x801C08F0
    // 0x801C07DC: nop

    LOOKUP_FUNC(0x801C08F0)(rdram, ctx);
        goto after_2;
    // 0x801C07DC: nop

    after_2:
    // 0x801C07E0: jal         0x801C0914
    // 0x801C07E4: nop

    LOOKUP_FUNC(0x801C0914)(rdram, ctx);
        goto after_3;
    // 0x801C07E4: nop

    after_3:
    // 0x801C07E8: b           L_801C0828
    // 0x801C07EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C0828;
    // 0x801C07EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C07F0:
    // 0x801C07F0: jal         0x801C0438
    // 0x801C07F4: nop

    LOOKUP_FUNC(0x801C0438)(rdram, ctx);
        goto after_4;
    // 0x801C07F4: nop

    after_4:
    // 0x801C07F8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C07FC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C0800: addiu       $t7, $zero, 0xC2
    ctx->r15 = ADD32(0, 0XC2);
    // 0x801C0804: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C0808: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x801C080C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C0810: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801C0814: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801C0818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C081C: jal         0x8012FE50
    // 0x801C0820: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_5;
    // 0x801C0820: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_5:
    // 0x801C0824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C0828:
    // 0x801C0828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C082C: jr          $ra
    // 0x801C0830: nop

    return;
    // 0x801C0830: nop

;}
RECOMP_FUNC void M24_FUN_801c0834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0834: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0838: lw          $t6, -0x7304($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7304);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c083c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c083c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C083C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0844: beq         $t6, $zero, L_801C0864
    if (ctx->r14 == 0) {
        // 0x801C0848: nop
    
            goto L_801C0864;
    }
    // 0x801C0848: nop

    // 0x801C084C: jal         0x801C0438
    // 0x801C0850: nop

    LOOKUP_FUNC(0x801C0438)(rdram, ctx);
        goto after_0;
    // 0x801C0850: nop

    after_0:
    // 0x801C0854: jal         0x801C08B0
    // 0x801C0858: nop

    LOOKUP_FUNC(0x801C08B0)(rdram, ctx);
        goto after_1;
    // 0x801C0858: nop

    after_1:
    // 0x801C085C: b           L_801C086C
    // 0x801C0860: nop

        goto L_801C086C;
    // 0x801C0860: nop

L_801C0864:
    // 0x801C0864: jal         0x801C088C
    // 0x801C0868: nop

    LOOKUP_FUNC(0x801C088C)(rdram, ctx);
        goto after_2;
    // 0x801C0868: nop

    after_2:
L_801C086C:
    // 0x801C086C: jal         0x801C08F0
    // 0x801C0870: nop

    LOOKUP_FUNC(0x801C08F0)(rdram, ctx);
        goto after_3;
    // 0x801C0870: nop

    after_3:
    // 0x801C0874: jal         0x801C0914
    // 0x801C0878: nop

    LOOKUP_FUNC(0x801C0914)(rdram, ctx);
        goto after_4;
    // 0x801C0878: nop

    after_4:
    // 0x801C087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C0884: jr          $ra
    // 0x801C0888: nop

    return;
    // 0x801C0888: nop

;}
RECOMP_FUNC void M24_FUN_801c088c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C088C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0890: lw          $t6, -0x731C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X731C);
    // 0x801C0894: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C0898: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C089C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C08A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C08A4: lw          $t8, -0x36D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X36D0);
    // 0x801C08A8: jr          $ra
    // 0x801C08AC: sh          $t8, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r24;
    return;
    // 0x801C08AC: sh          $t8, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c08b0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c08b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C08B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C08B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C08B8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C08BC: jal         0x801C039C
    // 0x801C08C0: addiu       $a0, $a0, -0x731C
    ctx->r4 = ADD32(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C039C)(rdram, ctx);
        goto after_0;
    // 0x801C08C0: addiu       $a0, $a0, -0x731C
    ctx->r4 = ADD32(ctx->r4, -0X731C);
    after_0:
    // 0x801C08C4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C08C8: lw          $t6, -0x731C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X731C);
    // 0x801C08CC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C08D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C08D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C08D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C08DC: lw          $t8, -0x36D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X36D0);
    // 0x801C08E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C08E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C08E8: jr          $ra
    // 0x801C08EC: sh          $t8, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r24;
    return;
    // 0x801C08EC: sh          $t8, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c08f0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c08f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C08F0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C08F4: lw          $t6, -0x731C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X731C);
    // 0x801C08F8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C08FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C0900: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C0904: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C0908: lw          $t8, -0x32AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X32AC);
    // 0x801C090C: jr          $ra
    // 0x801C0910: sh          $t8, -0x440A($at)
    MEM_H(-0X440A, ctx->r1) = ctx->r24;
    return;
    // 0x801C0910: sh          $t8, -0x440A($at)
    MEM_H(-0X440A, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0914(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0914: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0918: lw          $t6, -0x731C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X731C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c091c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c091c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C091C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0920: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C0924: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x801C0928: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x801C092C: beq         $at, $zero, L_801C09E4
    if (ctx->r1 == 0) {
        // 0x801C0930: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801C09E4;
    }
    // 0x801C0930: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801C0934: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0938: addu        $at, $at, $t7
    gpr jr_addend_801C0940 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801C093C: lw          $t7, -0x31F0($at)
    ctx->r15 = ADD32(ctx->r1, -0X31F0);
    // 0x801C0940: jr          $t7
    // 0x801C0944: nop

    switch (jr_addend_801C0940 >> 2) {
        case 0: goto L_801C0970; break;
        case 1: goto L_801C09E4; break;
        case 2: goto L_801C09E4; break;
        case 3: goto L_801C0998; break;
        case 4: goto L_801C09BC; break;
        case 5: goto L_801C0970; break;
        case 6: goto L_801C09E4; break;
        case 7: goto L_801C0970; break;
        case 8: goto L_801C0970; break;
        case 9: goto L_801C0948; break;
        case 10: goto L_801C0970; break;
        case 11: goto L_801C0970; break;
        case 12: goto L_801C0970; break;
        case 13: goto L_801C0970; break;
        case 14: goto L_801C0948; break;
        case 15: goto L_801C0970; break;
        case 16: goto L_801C0948; break;
        case 17: goto L_801C0970; break;
        case 18: goto L_801C0970; break;
        case 19: goto L_801C0970; break;
        case 20: goto L_801C0970; break;
        case 21: goto L_801C0948; break;
        case 22: goto L_801C0948; break;
        case 23: goto L_801C0970; break;
        default: switch_error(__func__, 0x801C0940, 0x801DCE10);
    }
    // 0x801C0944: nop

L_801C0948:
    // 0x801C0948: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C094C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C0950: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C0954: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C0958: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801C095C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C0960: jal         0x8012FE50
    // 0x801C0964: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C0964: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x801C0968: b           L_801C0A08
    // 0x801C096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C0A08;
    // 0x801C096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C0970:
    // 0x801C0970: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C0974: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801C0978: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C097C: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C0980: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801C0984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C0988: jal         0x8012FE50
    // 0x801C098C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x801C098C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_1:
    // 0x801C0990: b           L_801C0A08
    // 0x801C0994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C0A08;
    // 0x801C0994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C0998:
    // 0x801C0998: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C099C: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C09A0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801C09A4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C09A8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801C09AC: jal         0x8012FE50
    // 0x801C09B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x801C09B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801C09B4: b           L_801C0A08
    // 0x801C09B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C0A08;
    // 0x801C09B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C09BC:
    // 0x801C09BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C09C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C09C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C09C8: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C09CC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x801C09D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C09D4: jal         0x8012FE50
    // 0x801C09D8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_3;
    // 0x801C09D8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_3:
    // 0x801C09DC: b           L_801C0A08
    // 0x801C09E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C0A08;
    // 0x801C09E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C09E4:
    // 0x801C09E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C09E8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801C09EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C09F0: lhu         $a1, -0x440C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X440C);
    // 0x801C09F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801C09F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C09FC: jal         0x8012FE50
    // 0x801C0A00: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_4;
    // 0x801C0A00: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_4:
    // 0x801C0A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C0A08:
    // 0x801C0A08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C0A0C: jr          $ra
    // 0x801C0A10: nop

    return;
    // 0x801C0A10: nop

;}
RECOMP_FUNC void M24_FUN_801c0a14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0A14: nop

    // 0x801C0A18: nop

    // 0x801C0A1C: nop

    // 0x801C0A20: nop

    // 0x801C0A24: nop

    // 0x801C0A28: nop

    // 0x801C0A2C: nop

;}
RECOMP_FUNC void M24_FUN_801c0a30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0A38: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801C0A3C: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x801C0A40: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0A44: sw          $t6, -0x7278($at)
    MEM_W(-0X7278, ctx->r1) = ctx->r14;
    // 0x801C0A48: jal         0x801C0C08
    // 0x801C0A4C: sw          $t7, -0x7274($at)
    MEM_W(-0X7274, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C0A4C: sw          $t7, -0x7274($at)
    MEM_W(-0X7274, ctx->r1) = ctx->r15;
    after_0:
    // 0x801C0A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0A54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0A58: sw          $v0, -0x7280($at)
    MEM_W(-0X7280, ctx->r1) = ctx->r2;
    // 0x801C0A5C: sw          $v1, -0x727C($at)
    MEM_W(-0X727C, ctx->r1) = ctx->r3;
    // 0x801C0A60: jr          $ra
    // 0x801C0A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C0A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0a68(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0a68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0A68: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0A6C: lw          $t6, -0x7270($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7270);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0a70(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0a70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0A78: beql        $t6, $zero, L_801C0AD8
    if (ctx->r14 == 0) {
        // 0x801C0A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C0AD8;
    }
    goto skip_0;
    // 0x801C0A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C0A80: jal         0x801C0C08
    // 0x801C0A84: nop

    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C0A84: nop

    after_0:
    // 0x801C0A88: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C0A8C: lw          $t9, -0x725C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X725C);
    // 0x801C0A90: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C0A94: lw          $t8, -0x7260($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7260);
    // 0x801C0A98: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C0A9C: lw          $t3, -0x7274($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7274);
    // 0x801C0AA0: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x801C0AA4: subu        $t1, $v1, $t9
    ctx->r9 = SUB32(ctx->r3, ctx->r25);
    // 0x801C0AA8: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x801C0AAC: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x801C0AB0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C0AB4: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x801C0AB8: lw          $t2, -0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7278);
    // 0x801C0ABC: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x801C0AC0: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x801C0AC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0AC8: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801C0ACC: sw          $t4, -0x7278($at)
    MEM_W(-0X7278, ctx->r1) = ctx->r12;
    // 0x801C0AD0: sw          $t5, -0x7274($at)
    MEM_W(-0X7274, ctx->r1) = ctx->r13;
    // 0x801C0AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C0AD8:
    // 0x801C0AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C0ADC: jr          $ra
    // 0x801C0AE0: nop

    return;
    // 0x801C0AE0: nop

;}
RECOMP_FUNC void M24_FUN_801c0ae4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0AE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C0AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0AEC: jal         0x801C0C08
    // 0x801C0AF0: nop

    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C0AF0: nop

    after_0:
    // 0x801C0AF4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0AF8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0AFC: lw          $t7, -0x727C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X727C);
    // 0x801C0B00: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x801C0B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0B08: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C0B0C: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801C0B10: subu        $v0, $t8, $at
    ctx->r2 = SUB32(ctx->r24, ctx->r1);
    // 0x801C0B14: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x801C0B18: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801C0B1C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801C0B20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C0B24: jr          $ra
    // 0x801C0B28: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    return;
    // 0x801C0B28: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0b2c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0B34: jal         0x801C0C08
    // 0x801C0B38: nop

    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C0B38: nop

    after_0:
    // 0x801C0B3C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0B40: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0B44: lw          $t7, -0x727C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X727C);
    // 0x801C0B48: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x801C0B4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0B50: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C0B54: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x801C0B58: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C0B5C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C0B60: jal         0x80026F58
    // 0x801C0B64: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C0B64: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_1:
    // 0x801C0B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C0B6C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C0B70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0B74: jal         0x80026E58
    // 0x801C0B78: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C0B78: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C0B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C0B84: jr          $ra
    // 0x801C0B88: nop

    return;
    // 0x801C0B88: nop

;}
RECOMP_FUNC void M24_FUN_801c0b8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C0B98: jal         0x801C0C08
    // 0x801C0B9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C0B9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C0BA0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0BA4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0BA8: lw          $t7, -0x727C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X727C);
    // 0x801C0BAC: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x801C0BB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0BB4: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C0BB8: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x801C0BBC: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C0BC0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C0BC4: jal         0x80026F58
    // 0x801C0BC8: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C0BC8: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_1:
    // 0x801C0BCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C0BD0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C0BD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0BD8: jal         0x80026E58
    // 0x801C0BDC: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C0BDC: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C0BE0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x801C0BE4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0BEC: bne         $v0, $t8, L_801C0BFC
    if (ctx->r2 != ctx->r24) {
        // 0x801C0BF0: sltu        $at, $t8, $v0
        ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
            goto L_801C0BFC;
    }
    // 0x801C0BF0: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x801C0BF4: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x801C0BF8: xori        $at, $at, 0x1
    ctx->r1 = ctx->r1 ^ 0X1;
L_801C0BFC:
    // 0x801C0BFC: or          $v0, $at, $zero
    ctx->r2 = ctx->r1 | 0;
    // 0x801C0C00: jr          $ra
    // 0x801C0C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C0C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0c08(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C0C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0C10: jal         0x80031190
    // 0x801C0C14: nop

    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_0;
    // 0x801C0C14: nop

    after_0:
    // 0x801C0C18: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0C1C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C0C20: lw          $t7, -0x7274($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7274);
    // 0x801C0C24: lw          $t6, -0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7278);
    // 0x801C0C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0C2C: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C0C30: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x801C0C34: subu        $v0, $v0, $at
    ctx->r2 = SUB32(ctx->r2, ctx->r1);
    // 0x801C0C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C0C3C: jr          $ra
    // 0x801C0C40: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    return;
    // 0x801C0C40: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0c44(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0c44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0C48: jr          $ra
    // 0x801C0C4C: sw          $zero, -0x7258($at)
    MEM_W(-0X7258, ctx->r1) = 0;
    return;
    // 0x801C0C4C: sw          $zero, -0x7258($at)
    MEM_W(-0X7258, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0c50(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C50: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0C54: addiu       $v0, $v0, -0x7258
    ctx->r2 = ADD32(ctx->r2, -0X7258);
    // 0x801C0C58: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C0C5C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801C0C60: jr          $ra
    // 0x801C0C64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x801C0C64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0c68(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0c68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C68: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C0C6C: lw          $t6, -0x7258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7258);
    // 0x801C0C70: sltu        $v0, $t6, $a0
    ctx->r2 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x801C0C74: jr          $ra
    // 0x801C0C78: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x801C0C78: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0c7c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0c7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0C7C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C0C80: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0C84: addiu       $a0, $a0, -0x15C8
    ctx->r4 = ADD32(ctx->r4, -0X15C8);
    // 0x801C0C88: addiu       $v1, $v1, -0x17C8
    ctx->r3 = ADD32(ctx->r3, -0X17C8);
    // 0x801C0C8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801C0C90:
    // 0x801C0C90: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801C0C94: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801C0C98: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x801C0C9C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x801C0CA0: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x801C0CA4: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x801C0CA8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x801C0CAC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801C0CB0: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x801C0CB4: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
    // 0x801C0CB8: sw          $t2, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r10;
    // 0x801C0CBC: sw          $t1, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r9;
    // 0x801C0CC0: sw          $t0, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r8;
    // 0x801C0CC4: sw          $t9, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r25;
    // 0x801C0CC8: sw          $t8, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->r24;
    // 0x801C0CCC: sw          $v0, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r2;
    // 0x801C0CD0: sw          $v0, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r2;
    // 0x801C0CD4: sw          $v0, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r2;
    // 0x801C0CD8: sw          $v0, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r2;
    // 0x801C0CDC: sw          $v0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r2;
    // 0x801C0CE0: sw          $v0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r2;
    // 0x801C0CE4: sw          $v0, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r2;
    // 0x801C0CE8: sw          $v0, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r2;
    // 0x801C0CEC: sw          $t7, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r15;
    // 0x801C0CF0: bne         $v1, $a0, L_801C0C90
    if (ctx->r3 != ctx->r4) {
        // 0x801C0CF4: sw          $t6, -0x38($v1)
        MEM_W(-0X38, ctx->r3) = ctx->r14;
            goto L_801C0C90;
    }
    // 0x801C0CF4: sw          $t6, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r14;
    // 0x801C0CF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0CFC: jr          $ra
    // 0x801C0D00: sw          $zero, -0x17D0($at)
    MEM_W(-0X17D0, ctx->r1) = 0;
    return;
    // 0x801C0D00: sw          $zero, -0x17D0($at)
    MEM_W(-0X17D0, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0d04(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0d04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0D04: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C0D08: addiu       $a3, $a3, -0x17D0
    ctx->r7 = ADD32(ctx->r7, -0X17D0);
    // 0x801C0D0C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0d10(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0d10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0D10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C0D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0D18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801C0D1C: beq         $v1, $zero, L_801C0D6C
    if (ctx->r3 == 0) {
        // 0x801C0D20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C0D6C;
    }
    // 0x801C0D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C0D24: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0D28: addiu       $a0, $a0, -0x17C8
    ctx->r4 = ADD32(ctx->r4, -0X17C8);
L_801C0D2C:
    // 0x801C0D2C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801C0D30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C0D34: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801C0D38: bne         $a2, $t6, L_801C0D64
    if (ctx->r6 != ctx->r14) {
        // 0x801C0D3C: nop
    
            goto L_801C0D64;
    }
    // 0x801C0D3C: nop

    // 0x801C0D40: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x801C0D44: bne         $a1, $t7, L_801C0D64
    if (ctx->r5 != ctx->r15) {
        // 0x801C0D48: nop
    
            goto L_801C0D64;
    }
    // 0x801C0D48: nop

    // 0x801C0D4C: jal         0x80031190
    // 0x801C0D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_0;
    // 0x801C0D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801C0D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C0D58: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x801C0D5C: b           L_801C0DD4
    // 0x801C0D60: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
        goto L_801C0DD4;
    // 0x801C0D60: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_801C0D64:
    // 0x801C0D64: bne         $at, $zero, L_801C0D2C
    if (ctx->r1 != 0) {
        // 0x801C0D68: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_801C0D2C;
    }
    // 0x801C0D68: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_801C0D6C:
    // 0x801C0D6C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0D70: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C0D74: addiu       $v1, $v1, -0x15C8
    ctx->r3 = ADD32(ctx->r3, -0X15C8);
    // 0x801C0D78: addiu       $a0, $a0, -0x17C8
    ctx->r4 = ADD32(ctx->r4, -0X17C8);
    // 0x801C0D7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C0D80: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_801C0D84:
    // 0x801C0D84: bnel        $v0, $t8, L_801C0D9C
    if (ctx->r2 != ctx->r24) {
        // 0x801C0D88: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_801C0D9C;
    }
    goto skip_0;
    // 0x801C0D88: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    skip_0:
    // 0x801C0D8C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x801C0D90: beql        $v0, $t9, L_801C0DA8
    if (ctx->r2 == ctx->r25) {
        // 0x801C0D94: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_801C0DA8;
    }
    goto skip_1;
    // 0x801C0D94: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    skip_1:
    // 0x801C0D98: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_801C0D9C:
    // 0x801C0D9C: bnel        $a0, $v1, L_801C0D84
    if (ctx->r4 != ctx->r3) {
        // 0x801C0DA0: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_801C0D84;
    }
    goto skip_2;
    // 0x801C0DA0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x801C0DA4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_801C0DA8:
    // 0x801C0DA8: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x801C0DAC: jal         0x80031190
    // 0x801C0DB0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_1;
    // 0x801C0DB0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x801C0DB4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C0DB8: addiu       $a3, $a3, -0x17D0
    ctx->r7 = ADD32(ctx->r7, -0X17D0);
    // 0x801C0DBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0DC0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x801C0DC4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x801C0DC8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801C0DCC: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x801C0DD0: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
L_801C0DD4:
    // 0x801C0DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0DD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C0DDC: jr          $ra
    // 0x801C0DE0: nop

    return;
    // 0x801C0DE0: nop

;}
RECOMP_FUNC void M24_FUN_801c0de4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0DE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C0DE8: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C0DEC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0DF4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801C0DF8: addiu       $v0, $v0, -0x15C8
    ctx->r2 = ADD32(ctx->r2, -0X15C8);
    // 0x801C0DFC: addiu       $t0, $t0, -0x17C8
    ctx->r8 = ADD32(ctx->r8, -0X17C8);
    // 0x801C0E00: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_801C0E04:
    // 0x801C0E04: bnel        $a0, $t6, L_801C0E1C
    if (ctx->r4 != ctx->r14) {
        // 0x801C0E08: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_801C0E1C;
    }
    goto skip_0;
    // 0x801C0E08: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    skip_0:
    // 0x801C0E0C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x801C0E10: beq         $a1, $t7, L_801C0E24
    if (ctx->r5 == ctx->r15) {
        // 0x801C0E14: nop
    
            goto L_801C0E24;
    }
    // 0x801C0E14: nop

    // 0x801C0E18: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_801C0E1C:
    // 0x801C0E1C: bnel        $t0, $v0, L_801C0E04
    if (ctx->r8 != ctx->r2) {
        // 0x801C0E20: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_801C0E04;
    }
    goto skip_1;
    // 0x801C0E20: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_1:
L_801C0E24:
    // 0x801C0E24: jal         0x80031190
    // 0x801C0E28: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_0;
    // 0x801C0E28: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801C0E2C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0E30: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0E34: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C0E38: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x801C0E3C: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x801C0E40: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    // 0x801C0E44: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x801C0E48: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C0E4C: jal         0x80026F58
    // 0x801C0E50: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C0E50: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    after_1:
    // 0x801C0E54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C0E58: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C0E5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0E60: jal         0x80026E58
    // 0x801C0E64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C0E64: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C0E68: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801C0E6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0E70: ldc1        $f8, -0x3128($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3128);
    // 0x801C0E74: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C0E78: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801C0E7C: mul.d       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801C0E80: jal         0x80034AB8
    // 0x801C0E84: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80034AB8)(rdram, ctx);
        goto after_3;
    // 0x801C0E84: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x801C0E88: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801C0E8C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801C0E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0E94: bne         $t2, $v0, L_801C0EA4
    if (ctx->r10 != ctx->r2) {
        // 0x801C0E98: sltu        $at, $v0, $t2
        ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
            goto L_801C0EA4;
    }
    // 0x801C0E98: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x801C0E9C: sltu        $at, $t3, $v1
    ctx->r1 = ctx->r11 < ctx->r3 ? 1 : 0;
    // 0x801C0EA0: xori        $at, $at, 0x1
    ctx->r1 = ctx->r1 ^ 0X1;
L_801C0EA4:
    // 0x801C0EA4: or          $v0, $at, $zero
    ctx->r2 = ctx->r1 | 0;
    // 0x801C0EA8: jr          $ra
    // 0x801C0EAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801C0EAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0eb0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0eb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0EB0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C0EB4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0EB8: addiu       $v0, $v0, -0x15C8
    ctx->r2 = ADD32(ctx->r2, -0X15C8);
    // 0x801C0EBC: addiu       $v1, $v1, -0x17C8
    ctx->r3 = ADD32(ctx->r3, -0X17C8);
    // 0x801C0EC0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C0EC4:
    // 0x801C0EC4: bnel        $a0, $t6, L_801C0EDC
    if (ctx->r4 != ctx->r14) {
        // 0x801C0EC8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801C0EDC;
    }
    goto skip_0;
    // 0x801C0EC8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x801C0ECC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C0ED0: beq         $a1, $t7, L_801C0EE4
    if (ctx->r5 == ctx->r15) {
        // 0x801C0ED4: nop
    
            goto L_801C0EE4;
    }
    // 0x801C0ED4: nop

    // 0x801C0ED8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_801C0EDC:
    // 0x801C0EDC: bnel        $v1, $v0, L_801C0EC4
    if (ctx->r3 != ctx->r2) {
        // 0x801C0EE0: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C0EC4;
    }
    goto skip_1;
    // 0x801C0EE0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_801C0EE4:
    // 0x801C0EE4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0EE8: addiu       $a0, $a0, -0x17D0
    ctx->r4 = ADD32(ctx->r4, -0X17D0);
    // 0x801C0EEC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801C0EF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C0EF4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801C0EF8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801C0EFC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801C0F00: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801C0F04: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x801C0F08: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x801C0F0C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801C0F10: jr          $ra
    // 0x801C0F14: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    return;
    // 0x801C0F14: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0f18(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0F18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C0F1C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C0F20: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C0F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0F28: addiu       $v0, $v0, -0x15C8
    ctx->r2 = ADD32(ctx->r2, -0X15C8);
    // 0x801C0F2C: addiu       $t0, $t0, -0x17C8
    ctx->r8 = ADD32(ctx->r8, -0X17C8);
    // 0x801C0F30: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_801C0F34:
    // 0x801C0F34: bnel        $a0, $t6, L_801C0F4C
    if (ctx->r4 != ctx->r14) {
        // 0x801C0F38: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_801C0F4C;
    }
    goto skip_0;
    // 0x801C0F38: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    skip_0:
    // 0x801C0F3C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x801C0F40: beq         $a1, $t7, L_801C0F54
    if (ctx->r5 == ctx->r15) {
        // 0x801C0F44: nop
    
            goto L_801C0F54;
    }
    // 0x801C0F44: nop

    // 0x801C0F48: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_801C0F4C:
    // 0x801C0F4C: bnel        $t0, $v0, L_801C0F34
    if (ctx->r8 != ctx->r2) {
        // 0x801C0F50: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_801C0F34;
    }
    goto skip_1;
    // 0x801C0F50: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_1:
L_801C0F54:
    // 0x801C0F54: jal         0x80031190
    // 0x801C0F58: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_0;
    // 0x801C0F58: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801C0F5C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0F60: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0F64: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C0F68: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x801C0F6C: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x801C0F70: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    // 0x801C0F74: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x801C0F78: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C0F7C: jal         0x80026F58
    // 0x801C0F80: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C0F80: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    after_1:
    // 0x801C0F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C0F88: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C0F8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C0F90: jal         0x80026E58
    // 0x801C0F94: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C0F94: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C0F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C0F9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801C0FA0: jr          $ra
    // 0x801C0FA4: nop

    return;
    // 0x801C0FA4: nop

;}
RECOMP_FUNC void M24_FUN_801c0fa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0FA8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C0FAC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C0FB0: addiu       $a0, $a0, -0x1440
    ctx->r4 = ADD32(ctx->r4, -0X1440);
    // 0x801C0FB4: addiu       $v1, $v1, -0x15C0
    ctx->r3 = ADD32(ctx->r3, -0X15C0);
    // 0x801C0FB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801C0FBC:
    // 0x801C0FBC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x801C0FC0: sw          $v0, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r2;
    // 0x801C0FC4: sw          $v0, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r2;
    // 0x801C0FC8: sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // 0x801C0FCC: sw          $v0, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r2;
    // 0x801C0FD0: sw          $v0, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r2;
    // 0x801C0FD4: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C0FD8: sw          $v0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r2;
    // 0x801C0FDC: sw          $v0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r2;
    // 0x801C0FE0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C0FE4: sw          $v0, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r2;
    // 0x801C0FE8: sw          $v0, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r2;
    // 0x801C0FEC: bne         $v1, $a0, L_801C0FBC
    if (ctx->r3 != ctx->r4) {
        // 0x801C0FF0: sw          $zero, -0x28($v1)
        MEM_W(-0X28, ctx->r3) = 0;
            goto L_801C0FBC;
    }
    // 0x801C0FF0: sw          $zero, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = 0;
    // 0x801C0FF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C0FF8: jr          $ra
    // 0x801C0FFC: sw          $zero, -0x15C8($at)
    MEM_W(-0X15C8, ctx->r1) = 0;
    return;
    // 0x801C0FFC: sw          $zero, -0x15C8($at)
    MEM_W(-0X15C8, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1000(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1000: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C1004: addiu       $a3, $a3, -0x15C8
    ctx->r7 = ADD32(ctx->r7, -0X15C8);
    // 0x801C1008: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x801C100C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C1010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C1014: beq         $v1, $zero, L_801C1034
    if (ctx->r3 == 0) {
        // 0x801C1018: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801C1034;
    }
    // 0x801C1018: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C101C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1020: addiu       $a1, $a1, -0x15C0
    ctx->r5 = ADD32(ctx->r5, -0X15C0);
L_801C1024:
    // 0x801C1024: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C1028: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801C102C: bne         $at, $zero, L_801C1024
    if (ctx->r1 != 0) {
        // 0x801C1030: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_801C1024;
    }
    // 0x801C1030: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_801C1034:
    // 0x801C1034: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1038: addiu       $a1, $a1, -0x15C0
    ctx->r5 = ADD32(ctx->r5, -0X15C0);
    // 0x801C103C: addiu       $t0, $t0, -0x1440
    ctx->r8 = ADD32(ctx->r8, -0X1440);
    // 0x801C1040: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C1044: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_801C1048:
    // 0x801C1048: bnel        $v0, $t6, L_801C1060
    if (ctx->r2 != ctx->r14) {
        // 0x801C104C: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_801C1060;
    }
    goto skip_0;
    // 0x801C104C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    skip_0:
    // 0x801C1050: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801C1054: beql        $v0, $t7, L_801C106C
    if (ctx->r2 == ctx->r15) {
        // 0x801C1058: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_801C106C;
    }
    goto skip_1;
    // 0x801C1058: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    skip_1:
    // 0x801C105C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_801C1060:
    // 0x801C1060: bnel        $a1, $t0, L_801C1048
    if (ctx->r5 != ctx->r8) {
        // 0x801C1064: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_801C1048;
    }
    goto skip_2;
    // 0x801C1064: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x801C1068: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_801C106C:
    // 0x801C106C: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x801C1070: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C1074: lw          $t8, -0x7258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7258);
    // 0x801C1078: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801C107C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x801C1080: jr          $ra
    // 0x801C1084: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    return;
    // 0x801C1084: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1088(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1088: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C108C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1090: addiu       $v0, $v0, -0x1440
    ctx->r2 = ADD32(ctx->r2, -0X1440);
    // 0x801C1094: addiu       $v1, $v1, -0x15C0
    ctx->r3 = ADD32(ctx->r3, -0X15C0);
    // 0x801C1098: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C109C:
    // 0x801C109C: bnel        $a0, $t6, L_801C10B4
    if (ctx->r4 != ctx->r14) {
        // 0x801C10A0: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C10B4;
    }
    goto skip_0;
    // 0x801C10A0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801C10A4: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C10A8: beq         $a1, $t7, L_801C10BC
    if (ctx->r5 == ctx->r15) {
        // 0x801C10AC: nop
    
            goto L_801C10BC;
    }
    // 0x801C10AC: nop

    // 0x801C10B0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801C10B4:
    // 0x801C10B4: bnel        $v1, $v0, L_801C109C
    if (ctx->r3 != ctx->r2) {
        // 0x801C10B8: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C109C;
    }
    goto skip_1;
    // 0x801C10B8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_801C10BC:
    // 0x801C10BC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C10C0: lw          $t8, -0x7258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7258);
    // 0x801C10C4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x801C10C8: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    // 0x801C10CC: sltu        $v0, $a0, $a2
    ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x801C10D0: jr          $ra
    // 0x801C10D4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x801C10D4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c10d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c10d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C10D8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C10DC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C10E0: addiu       $v0, $v0, -0x1440
    ctx->r2 = ADD32(ctx->r2, -0X1440);
    // 0x801C10E4: addiu       $v1, $v1, -0x15C0
    ctx->r3 = ADD32(ctx->r3, -0X15C0);
    // 0x801C10E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C10EC:
    // 0x801C10EC: bnel        $a0, $t6, L_801C1104
    if (ctx->r4 != ctx->r14) {
        // 0x801C10F0: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C1104;
    }
    goto skip_0;
    // 0x801C10F0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801C10F4: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C10F8: beq         $a1, $t7, L_801C110C
    if (ctx->r5 == ctx->r15) {
        // 0x801C10FC: nop
    
            goto L_801C110C;
    }
    // 0x801C10FC: nop

    // 0x801C1100: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801C1104:
    // 0x801C1104: bnel        $v1, $v0, L_801C10EC
    if (ctx->r3 != ctx->r2) {
        // 0x801C1108: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C10EC;
    }
    goto skip_1;
    // 0x801C1108: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_801C110C:
    // 0x801C110C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1110: addiu       $a0, $a0, -0x15C8
    ctx->r4 = ADD32(ctx->r4, -0X15C8);
    // 0x801C1114: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801C1118: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C111C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801C1120: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801C1124: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x801C1128: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801C112C: jr          $ra
    // 0x801C1130: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x801C1130: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1134(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1134: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1138: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C113C: addiu       $v0, $v0, -0x1440
    ctx->r2 = ADD32(ctx->r2, -0X1440);
    // 0x801C1140: addiu       $v1, $v1, -0x15C0
    ctx->r3 = ADD32(ctx->r3, -0X15C0);
    // 0x801C1144: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1148:
    // 0x801C1148: bnel        $a0, $t6, L_801C1160
    if (ctx->r4 != ctx->r14) {
        // 0x801C114C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C1160;
    }
    goto skip_0;
    // 0x801C114C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801C1150: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C1154: beq         $a1, $t7, L_801C1168
    if (ctx->r5 == ctx->r15) {
        // 0x801C1158: nop
    
            goto L_801C1168;
    }
    // 0x801C1158: nop

    // 0x801C115C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801C1160:
    // 0x801C1160: bnel        $v1, $v0, L_801C1148
    if (ctx->r3 != ctx->r2) {
        // 0x801C1164: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1148;
    }
    goto skip_1;
    // 0x801C1164: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_801C1168:
    // 0x801C1168: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C116C: lw          $t8, -0x7258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7258);
    // 0x801C1170: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x801C1174: jr          $ra
    // 0x801C1178: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    return;
    // 0x801C1178: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c117c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c117c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C117C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1180: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1184: sw          $zero, -0x7270($at)
    MEM_W(-0X7270, ctx->r1) = 0;
    // 0x801C1188: addiu       $v0, $v0, -0x7268
    ctx->r2 = ADD32(ctx->r2, -0X7268);
    // 0x801C118C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C1190: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1194: sw          $zero, -0x726C($at)
    MEM_W(-0X726C, ctx->r1) = 0;
    // 0x801C1198: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C119C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801C11A0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801C11A4: sw          $t9, -0x725C($at)
    MEM_W(-0X725C, ctx->r1) = ctx->r25;
    // 0x801C11A8: jr          $ra
    // 0x801C11AC: sw          $t8, -0x7260($at)
    MEM_W(-0X7260, ctx->r1) = ctx->r24;
    return;
    // 0x801C11AC: sw          $t8, -0x7260($at)
    MEM_W(-0X7260, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c11b0(rdram, ctx);
;}
