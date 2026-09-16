#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M23_FUN_801c7100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C7104: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C7108: or          $v1, $t6, $t7
    ctx->r3 = ctx->r14 | ctx->r15;
    // 0x801C710C: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x801C7110: andi        $t0, $a1, 0x100
    ctx->r8 = ctx->r5 & 0X100;
    // 0x801C7114: or          $a3, $t8, $t9
    ctx->r7 = ctx->r24 | ctx->r25;
    // 0x801C7118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C711C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C7120: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x801C7124: beq         $t0, $zero, L_801C715C
    if (ctx->r8 == 0) {
        // 0x801C7128: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801C715C;
    }
    // 0x801C7128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C712C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C7130: addiu       $v1, $v1, -0x240
    ctx->r3 = ADD32(ctx->r3, -0X240);
    // 0x801C7134: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C7138: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801C713C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C7140: bne         $v0, $at, L_801C7150
    if (ctx->r2 != ctx->r1) {
        // 0x801C7144: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_801C7150;
    }
    // 0x801C7144: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x801C7148: b           L_801C71D4
    // 0x801C714C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C71D4;
    // 0x801C714C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C7150:
    // 0x801C7150: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801C7154: b           L_801C71D4
    // 0x801C7158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_801C71D4;
    // 0x801C7158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801C715C:
    // 0x801C715C: andi        $t2, $a1, 0x200
    ctx->r10 = ctx->r5 & 0X200;
    // 0x801C7160: beq         $t2, $zero, L_801C7194
    if (ctx->r10 == 0) {
        // 0x801C7164: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C7194;
    }
    // 0x801C7164: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C7168: addiu       $v1, $v1, -0x240
    ctx->r3 = ADD32(ctx->r3, -0X240);
    // 0x801C716C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C7170: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801C7174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C7178: bne         $v0, $zero, L_801C7188
    if (ctx->r2 != 0) {
        // 0x801C717C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_801C7188;
    }
    // 0x801C717C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801C7180: b           L_801C71D4
    // 0x801C7184: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
        goto L_801C71D4;
    // 0x801C7184: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_801C7188:
    // 0x801C7188: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x801C718C: b           L_801C71D4
    // 0x801C7190: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_801C71D4;
    // 0x801C7190: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801C7194:
    // 0x801C7194: andi        $t5, $a3, 0x8000
    ctx->r13 = ctx->r7 & 0X8000;
    // 0x801C7198: beq         $t5, $zero, L_801C71D4
    if (ctx->r13 == 0) {
        // 0x801C719C: nop
    
            goto L_801C71D4;
    }
    // 0x801C719C: nop

    // 0x801C71A0: jal         0x80020744
    // 0x801C71A4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801C71A4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_0:
    // 0x801C71A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801C71AC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801C71B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801C71B4: jal         0x80020718
    // 0x801C71B8: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801C71B8: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
    after_1:
    // 0x801C71BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C71C0: addiu       $a1, $a1, 0x72F8
    ctx->r5 = ADD32(ctx->r5, 0X72F8);
    // 0x801C71C4: jal         0x800058DC
    // 0x801C71C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C71C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801C71CC: b           L_801C7258
    // 0x801C71D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C7258;
    // 0x801C71D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C71D4:
    // 0x801C71D4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C71D8: beq         $a2, $zero, L_801C7230
    if (ctx->r6 == 0) {
        // 0x801C71DC: addiu       $v1, $v1, -0x240
        ctx->r3 = ADD32(ctx->r3, -0X240);
            goto L_801C7230;
    }
    // 0x801C71DC: addiu       $v1, $v1, -0x240
    ctx->r3 = ADD32(ctx->r3, -0X240);
    // 0x801C71E0: jal         0x80020744
    // 0x801C71E4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x801C71E4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_3:
    // 0x801C71E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C71EC: addiu       $v1, $v1, -0x240
    ctx->r3 = ADD32(ctx->r3, -0X240);
    // 0x801C71F0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x801C71F4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C71F8: lw          $t9, -0x34FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X34FC);
    // 0x801C71FC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C7200: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C7204: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x801C7208: lbu         $a2, -0x2F1C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2F1C);
    // 0x801C720C: lw          $a0, -0x260($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260);
    // 0x801C7210: jalr        $t9
    // 0x801C7214: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x801C7214: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
    after_4:
    // 0x801C7218: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C721C: addiu       $a1, $a1, 0x7264
    ctx->r5 = ADD32(ctx->r5, 0X7264);
    // 0x801C7220: jal         0x800058DC
    // 0x801C7224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C7224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x801C7228: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C722C: addiu       $v1, $v1, -0x240
    ctx->r3 = ADD32(ctx->r3, -0X240);
L_801C7230:
    // 0x801C7230: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801C7234: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C7238: addiu       $a3, $a3, -0xD0C
    ctx->r7 = ADD32(ctx->r7, -0XD0C);
    // 0x801C723C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801C7240: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C7244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C7248: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C724C: jal         0x8001B204
    // 0x801C7250: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C7250: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    after_6:
    // 0x801C7254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C7258:
    // 0x801C7258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C725C: jr          $ra
    // 0x801C7260: nop

    return;
    // 0x801C7260: nop

;}
RECOMP_FUNC void M23_FUN_801c7264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7264: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C7268: addiu       $a3, $a3, -0x260
    ctx->r7 = ADD32(ctx->r7, -0X260);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c726c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c726c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C726C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C7270: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801C7274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C7278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C727C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C7280: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801C7284: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
    // 0x801C7288: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C728C: lbu         $v0, 0xB($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB);
    // 0x801C7290: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C7294: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C7298: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x801C729C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C72A0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801C72A4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801C72A8: bnel        $at, $zero, L_801C72E8
    if (ctx->r1 != 0) {
        // 0x801C72AC: sb          $v0, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r2;
            goto L_801C72E8;
    }
    goto skip_0;
    // 0x801C72AC: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    skip_0:
    // 0x801C72B0: sb          $zero, 0xB($v1)
    MEM_B(0XB, ctx->r3) = 0;
    // 0x801C72B4: lbu         $t7, -0x240($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X240);
    // 0x801C72B8: lw          $t9, -0x3500($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3500);
    // 0x801C72BC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801C72C0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x801C72C4: jalr        $t9
    // 0x801C72C8: lbu         $a2, -0x2F1C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2F1C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801C72C8: lbu         $a2, -0x2F1C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2F1C);
    after_0:
    // 0x801C72CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C72D0: addiu       $a1, $a1, 0x70E8
    ctx->r5 = ADD32(ctx->r5, 0X70E8);
    // 0x801C72D4: jal         0x800058DC
    // 0x801C72D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C72D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C72DC: b           L_801C72EC
    // 0x801C72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C72EC;
    // 0x801C72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C72E4: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
L_801C72E8:
    // 0x801C72E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C72EC:
    // 0x801C72EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C72F0: jr          $ra
    // 0x801C72F4: nop

    return;
    // 0x801C72F4: nop

;}
RECOMP_FUNC void M23_FUN_801c72f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C72F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C72FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C7300: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C7304: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C7308: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C730C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C7310: blez        $v0, L_801C7324
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801C7314: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_801C7324;
    }
    // 0x801C7314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C7318: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801C731C: b           L_801C7354
    // 0x801C7320: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
        goto L_801C7354;
    // 0x801C7320: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
L_801C7324:
    // 0x801C7324: lbu         $t7, -0x240($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X240);
    // 0x801C7328: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C732C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C7330: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801C7334: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801C7338: lhu         $t9, -0x2F2C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2F2C);
    // 0x801C733C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x801C7340: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C7344: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801C7348: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x801C734C: jal         0x8012FE50
    // 0x801C7350: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C7350: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    after_0:
L_801C7354:
    // 0x801C7354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C7358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C735C: jr          $ra
    // 0x801C7360: nop

    return;
    // 0x801C7360: nop

;}
RECOMP_FUNC void M23_FUN_801c7364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7364: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x801C7368: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801C736C: addiu       $v0, $v0, 0x4F40
    ctx->r2 = ADD32(ctx->r2, 0X4F40);
    // 0x801C7370: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C7374: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801C7378: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801C737C: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x801C7380: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801C7384: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801C7388: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801C738C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801C7390: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801C7394: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801C7398: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801C739C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801C73A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801C73A4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801C73A8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801C73AC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801C73B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801C73B4: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x801C73B8: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801C73BC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x801C73C0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C73C4: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x801C73C8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x801C73CC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x801C73D0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x801C73D4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801C73D8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801C73DC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801C73E0: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x801C73E4: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x801C73E8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801C73EC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801C73F0: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x801C73F4: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x801C73F8: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x801C73FC: ori         $a0, $a0, 0xF0F
    ctx->r4 = ctx->r4 | 0XF0F;
    // 0x801C7400: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
    // 0x801C7404: sh          $t2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r10;
    // 0x801C7408: sh          $t1, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r9;
    // 0x801C740C: lbu         $a3, 0x90($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7410: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801C7414: jal         0x80002364
    // 0x801C7418: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x801C7418: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x801C741C: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x801C7420: ori         $a0, $a0, 0xEF1F
    ctx->r4 = ctx->r4 | 0XEF1F;
    // 0x801C7424: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801C7428: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801C742C: jal         0x80002364
    // 0x801C7430: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_1;
    // 0x801C7430: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x801C7434: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7438: jal         0x80005E44
    // 0x801C743C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801C743C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801C7440: jal         0x80006214
    // 0x801C7444: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801C7444: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x801C7448: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C744C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C7450: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C7454: jal         0x8012C89C
    // 0x801C7458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801C7458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801C745C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801C7460: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7464: lwc1        $f0, -0xC60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC60);
    // 0x801C7468: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801C746C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C7470: addiu       $t6, $t6, -0x3288
    ctx->r14 = ADD32(ctx->r14, -0X3288);
    // 0x801C7474: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801C7478: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C747C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801C7480: ori         $t5, $t4, 0x300
    ctx->r13 = ctx->r12 | 0X300;
    // 0x801C7484: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x801C7488: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x801C748C: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x801C7490: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C7494: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C7498: addiu       $v1, $v1, -0x3098
    ctx->r3 = ADD32(ctx->r3, -0X3098);
    // 0x801C749C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x801C74A0: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x801C74A4: lbu         $t0, 0x90($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X90);
    // 0x801C74A8: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801C74AC: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C74B0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C74B4: mflo        $t1
    ctx->r9 = lo;
    // 0x801C74B8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801C74BC: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C74C0: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x801C74C4: lbu         $t5, 0x90($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X90);
    // 0x801C74C8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x801C74CC: multu       $t5, $s6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C74D0: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C74D4: mflo        $t6
    ctx->r14 = lo;
    // 0x801C74D8: addu        $t8, $v1, $t6
    ctx->r24 = ADD32(ctx->r3, ctx->r14);
    // 0x801C74DC: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801C74E0: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801C74E4: lbu         $t0, 0x90($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X90);
    // 0x801C74E8: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801C74EC: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C74F0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C74F4: mflo        $t1
    ctx->r9 = lo;
    // 0x801C74F8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801C74FC: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801C7500: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801C7504: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x801C7508: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C750C: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801C7510: addiu       $t5, $t5, -0x3080
    ctx->r13 = ADD32(ctx->r13, -0X3080);
    // 0x801C7514: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x801C7518: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x801C751C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801C7520: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801C7524: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x801C7528: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x801C752C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C7530: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x801C7534: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x801C7538: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C753C: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
    // 0x801C7540: lbu         $t3, 0x90($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7544: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x801C7548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C754C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C7550: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801C7554: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x801C7558: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x801C755C: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x801C7560: jal         0x80147250
    // 0x801C7564: lbu         $a3, 0x2($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X2);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_5;
    // 0x801C7564: lbu         $a3, 0x2($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X2);
    after_5:
    // 0x801C7568: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801C756C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801C7570: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C7574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C7578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C757C: jal         0x801472C0
    // 0x801C7580: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_6;
    // 0x801C7580: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801C7584: lbu         $t9, 0x90($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7588: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C758C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7590: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801C7594: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801C7598: lui         $s7, 0x801D
    ctx->r23 = S32(0X801D << 16);
    // 0x801C759C: sw          $t7, -0x280($at)
    MEM_W(-0X280, ctx->r1) = ctx->r15;
    // 0x801C75A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C75A4: addiu       $s7, $s7, -0x3200
    ctx->r23 = ADD32(ctx->r23, -0X3200);
    // 0x801C75A8: or          $s7, $s7, $at
    ctx->r23 = ctx->r23 | ctx->r1;
    // 0x801C75AC: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801C75B0: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801C75B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C75B8: ldc1        $f22, -0xC58($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0XC58);
    // 0x801C75BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801C75C0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801C75C4: lui         $fp, 0x4
    ctx->r30 = S32(0X4 << 16);
    // 0x801C75C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801C75CC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801C75D0: sb          $s3, 0x81($sp)
    MEM_B(0X81, ctx->r29) = ctx->r19;
    // 0x801C75D4: ori         $fp, $fp, 0x300
    ctx->r30 = ctx->r30 | 0X300;
    // 0x801C75D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_801C75DC:
    // 0x801C75DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C75E0: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x801C75E4: jal         0x80005FAC
    // 0x801C75E8: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_7;
    // 0x801C75E8: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_7:
    // 0x801C75EC: jal         0x80006214
    // 0x801C75F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_8;
    // 0x801C75F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x801C75F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C75F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C75FC: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C7600: jal         0x8012C89C
    // 0x801C7604: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_9;
    // 0x801C7604: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x801C7608: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x801C760C: addu        $v0, $s5, $t1
    ctx->r2 = ADD32(ctx->r21, ctx->r9);
    // 0x801C7610: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C7614: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C7618: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C761C: lw          $a0, 0x30($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X30);
    // 0x801C7620: addiu       $t8, $t8, -0x303C
    ctx->r24 = ADD32(ctx->r24, -0X303C);
    // 0x801C7624: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801C7628: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x801C762C: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C7630: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x801C7634: or          $t4, $t3, $fp
    ctx->r12 = ctx->r11 | ctx->r30;
    // 0x801C7638: sw          $t4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r12;
    // 0x801C763C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C7640: mflo        $s1
    ctx->r17 = lo;
    // 0x801C7644: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
    // 0x801C7648: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C764C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C7650: addiu       $t4, $t4, -0x3078
    ctx->r12 = ADD32(ctx->r12, -0X3078);
    // 0x801C7654: sw          $s7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r23;
    // 0x801C7658: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801C765C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C7660: addu        $v1, $s1, $t4
    ctx->r3 = ADD32(ctx->r17, ctx->r12);
    // 0x801C7664: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801C7668: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C766C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7670: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x801C7674: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C7678: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C767C: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801C7680: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C7684: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x801C7688: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C768C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C7690: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C7694: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C7698: sub.d       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f10.d = ctx->f8.d - ctx->f22.d;
    // 0x801C769C: mul.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x801C76A0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801C76A4: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x801C76A8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C76AC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801C76B0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C76B4: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x801C76B8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C76BC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C76C0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C76C4: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x801C76C8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C76CC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C76D0: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C76D4: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x801C76D8: jal         0x80005FAC
    // 0x801C76DC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_10;
    // 0x801C76DC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_10:
    // 0x801C76E0: jal         0x80006214
    // 0x801C76E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_11;
    // 0x801C76E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_11:
    // 0x801C76E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C76EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C76F0: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C76F4: jal         0x8012C89C
    // 0x801C76F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_12;
    // 0x801C76F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x801C76FC: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x801C7700: addu        $v0, $s5, $t1
    ctx->r2 = ADD32(ctx->r21, ctx->r9);
    // 0x801C7704: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C7708: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C770C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801C7710: lw          $a0, 0x30($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X30);
    // 0x801C7714: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x801C7718: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801C771C: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x801C7720: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C7724: or          $t4, $t3, $fp
    ctx->r12 = ctx->r11 | ctx->r30;
    // 0x801C7728: sw          $t4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r12;
    // 0x801C772C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C7730: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C7734: addiu       $t3, $t3, -0x3000
    ctx->r11 = ADD32(ctx->r11, -0X3000);
    // 0x801C7738: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C773C: addu        $v1, $s1, $t3
    ctx->r3 = ADD32(ctx->r17, ctx->r11);
    // 0x801C7740: sw          $s7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r23;
    // 0x801C7744: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801C7748: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C774C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801C7750: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C7754: swc1        $f16, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f16.u32l;
    // 0x801C7758: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C775C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C7760: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801C7764: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C7768: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x801C776C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801C7770: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C7774: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801C7778: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C777C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801C7780: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C7784: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801C7788: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C778C: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
    // 0x801C7790: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C7794: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7798: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C779C: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x801C77A0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C77A4: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C77A8: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C77AC: bne         $at, $zero, L_801C75DC
    if (ctx->r1 != 0) {
        // 0x801C77B0: swc1        $f18, 0x20($t7)
        MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
            goto L_801C75DC;
    }
    // 0x801C77B0: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
    // 0x801C77B4: lbu         $t0, 0x81($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X81);
    // 0x801C77B8: lbu         $t4, 0x90($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X90);
    // 0x801C77BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C77C0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C77C4: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x801C77C8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C77CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C77D0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801C77D4: sw          $t3, -0x278($at)
    MEM_W(-0X278, ctx->r1) = ctx->r11;
    // 0x801C77D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C77DC: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C77E0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801C77E4: sb          $s3, 0x81($sp)
    MEM_B(0X81, ctx->r29) = ctx->r19;
    // 0x801C77E8: addiu       $s1, $s1, -0x2F9C
    ctx->r17 = ADD32(ctx->r17, -0X2F9C);
    // 0x801C77EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C77F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801C77F4:
    // 0x801C77F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C77F8: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x801C77FC: jal         0x80005FAC
    // 0x801C7800: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_13;
    // 0x801C7800: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_13:
    // 0x801C7804: jal         0x80006214
    // 0x801C7808: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_14;
    // 0x801C7808: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x801C780C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7810: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C7814: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C7818: jal         0x8012C89C
    // 0x801C781C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_15;
    // 0x801C781C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_15:
    // 0x801C7820: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x801C7824: addu        $v0, $s5, $t6
    ctx->r2 = ADD32(ctx->r21, ctx->r14);
    // 0x801C7828: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C782C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C7830: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C7834: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x801C7838: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801C783C: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x801C7840: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801C7844: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801C7848: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C784C: or          $t7, $t9, $fp
    ctx->r15 = ctx->r25 | ctx->r30;
    // 0x801C7850: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x801C7854: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C7858: mflo        $t2
    ctx->r10 = lo;
    // 0x801C785C: addu        $v1, $s1, $t2
    ctx->r3 = ADD32(ctx->r17, ctx->r10);
    // 0x801C7860: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C7864: sll         $t7, $s0, 12
    ctx->r15 = S32(ctx->r16 << 12);
    // 0x801C7868: andi        $t0, $t7, 0x1FFF
    ctx->r8 = ctx->r15 & 0X1FFF;
    // 0x801C786C: sw          $s7, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r23;
    // 0x801C7870: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801C7874: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C7878: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x801C787C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801C7880: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C7884: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x801C7888: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C788C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C7890: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801C7894: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C7898: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x801C789C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C78A0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C78A4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801C78A8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C78AC: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x801C78B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C78B4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C78B8: sh          $t0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r8;
    // 0x801C78BC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C78C0: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C78C4: swc1        $f22, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f22.u32l;
    // 0x801C78C8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C78CC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C78D0: swc1        $f22, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f22.u32l;
    // 0x801C78D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C78D8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C78DC: bne         $at, $zero, L_801C77F4
    if (ctx->r1 != 0) {
        // 0x801C78E0: swc1        $f22, 0x20($t9)
        MEM_W(0X20, ctx->r25) = ctx->f22.u32l;
            goto L_801C77F4;
    }
    // 0x801C78E0: swc1        $f22, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f22.u32l;
    // 0x801C78E4: lbu         $t7, 0x81($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X81);
    // 0x801C78E8: lbu         $t4, 0x90($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X90);
    // 0x801C78EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C78F0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x801C78F4: addu        $t0, $s5, $t1
    ctx->r8 = ADD32(ctx->r21, ctx->r9);
    // 0x801C78F8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C78FC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801C7900: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801C7904: sw          $t2, -0x270($at)
    MEM_W(-0X270, ctx->r1) = ctx->r10;
    // 0x801C7908: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x801C790C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7910: jal         0x80005FAC
    // 0x801C7914: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_16;
    // 0x801C7914: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_16:
    // 0x801C7918: jal         0x80006214
    // 0x801C791C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_17;
    // 0x801C791C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x801C7920: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7924: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C7928: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C792C: jal         0x8012C89C
    // 0x801C7930: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_18;
    // 0x801C7930: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_18:
    // 0x801C7934: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x801C7938: addu        $v0, $s5, $t5
    ctx->r2 = ADD32(ctx->r21, ctx->r13);
    // 0x801C793C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C7940: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801C7944: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C7948: lw          $a0, 0x30($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X30);
    // 0x801C794C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801C7950: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801C7954: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801C7958: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x801C795C: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x801C7960: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C7964: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x801C7968: sw          $s7, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r23;
    // 0x801C796C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C7970: lw          $t4, 0x30($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X30);
    // 0x801C7974: swc1        $f20, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f20.u32l;
    // 0x801C7978: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C797C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801C7980: lw          $a0, 0x30($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X30);
    // 0x801C7984: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801C7988: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x801C798C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C7990: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C7994: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801C7998: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C799C: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C79A0: swc1        $f22, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f22.u32l;
    // 0x801C79A4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C79A8: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C79AC: swc1        $f22, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f22.u32l;
    // 0x801C79B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C79B4: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C79B8: swc1        $f22, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f22.u32l;
    // 0x801C79BC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C79C0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x801C79C4: jal         0x80147250
    // 0x801C79C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_19;
    // 0x801C79C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_19:
    // 0x801C79CC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x801C79D0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801C79D4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x801C79D8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C79DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C79E0: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x801C79E4: jal         0x801472C0
    // 0x801C79E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_20;
    // 0x801C79E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_20:
    // 0x801C79EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801C79F0: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C79F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C79F8: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x801C79FC: jal         0x80005FAC
    // 0x801C7A00: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_21;
    // 0x801C7A00: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_21:
    // 0x801C7A04: jal         0x80006214
    // 0x801C7A08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_22;
    // 0x801C7A08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_22:
    // 0x801C7A0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7A10: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C7A14: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C7A18: jal         0x8012C89C
    // 0x801C7A1C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_23;
    // 0x801C7A1C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_23:
    // 0x801C7A20: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x801C7A24: addu        $v0, $s5, $t3
    ctx->r2 = ADD32(ctx->r21, ctx->r11);
    // 0x801C7A28: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C7A30: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801C7A34: lw          $a0, 0x30($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X30);
    // 0x801C7A38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801C7A3C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C7A40: or          $t8, $t6, $fp
    ctx->r24 = ctx->r14 | ctx->r30;
    // 0x801C7A44: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x801C7A48: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A4C: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C7A50: sw          $s7, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r23;
    // 0x801C7A54: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A58: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C7A5C: swc1        $f20, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f20.u32l;
    // 0x801C7A60: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A64: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801C7A68: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    // 0x801C7A6C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801C7A70: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x801C7A74: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A78: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C7A7C: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x801C7A80: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A84: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C7A88: swc1        $f22, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f22.u32l;
    // 0x801C7A8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A90: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C7A94: swc1        $f22, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f22.u32l;
    // 0x801C7A98: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C7A9C: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x801C7AA0: swc1        $f22, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f22.u32l;
    // 0x801C7AA4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C7AA8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x801C7AAC: jal         0x80147250
    // 0x801C7AB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_24;
    // 0x801C7AB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_24:
    // 0x801C7AB4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x801C7AB8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801C7ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C7AC0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C7AC4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C7AC8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801C7ACC: jal         0x801472C0
    // 0x801C7AD0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_25;
    // 0x801C7AD0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_25:
    // 0x801C7AD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801C7AD8: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C7ADC: sb          $s3, 0x81($sp)
    MEM_B(0X81, ctx->r29) = ctx->r19;
    // 0x801C7AE0: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x801C7AE4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7AE8: jal         0x80005FAC
    // 0x801C7AEC: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_26;
    // 0x801C7AEC: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_26:
    // 0x801C7AF0: jal         0x80006214
    // 0x801C7AF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_27;
    // 0x801C7AF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x801C7AF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7AFC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801C7B00: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C7B04: jal         0x8012C89C
    // 0x801C7B08: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_28;
    // 0x801C7B08: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_28:
    // 0x801C7B0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801C7B10: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
    // 0x801C7B14: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801C7B18: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    // 0x801C7B1C: jal         0x8012D918
    // 0x801C7B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_29;
    // 0x801C7B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_29:
    // 0x801C7B24: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x801C7B28: addu        $v0, $s5, $t2
    ctx->r2 = ADD32(ctx->r21, ctx->r10);
    // 0x801C7B2C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B30: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C7B34: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801C7B38: lw          $a0, 0x30($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X30);
    // 0x801C7B3C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801C7B40: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x801C7B44: or          $t6, $t5, $fp
    ctx->r14 = ctx->r13 | ctx->r30;
    // 0x801C7B48: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x801C7B4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B50: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C7B54: sw          $s7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r23;
    // 0x801C7B58: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B5C: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x801C7B60: swc1        $f20, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f20.u32l;
    // 0x801C7B64: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B68: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C7B6C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    // 0x801C7B70: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801C7B74: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x801C7B78: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B7C: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x801C7B80: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    // 0x801C7B84: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B88: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C7B8C: swc1        $f22, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f22.u32l;
    // 0x801C7B90: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C7B94: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C7B98: swc1        $f22, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f22.u32l;
    // 0x801C7B9C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C7BA0: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C7BA4: swc1        $f22, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f22.u32l;
    // 0x801C7BA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C7BAC: jal         0x80147250
    // 0x801C7BB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_30;
    // 0x801C7BB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_30:
    // 0x801C7BB4: lbu         $t4, 0x90($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7BB8: lbu         $t0, 0x81($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X81);
    // 0x801C7BBC: lbu         $t2, 0x81($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X81);
    // 0x801C7BC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7BC4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801C7BC8: sb          $t0, -0x25C($at)
    MEM_B(-0X25C, ctx->r1) = ctx->r8;
    // 0x801C7BCC: lbu         $t8, 0x90($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7BD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C7BD4: addu        $t5, $s5, $t3
    ctx->r13 = ADD32(ctx->r21, ctx->r11);
    // 0x801C7BD8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C7BDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7BE0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C7BE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801C7BE8: sw          $t6, -0x268($at)
    MEM_W(-0X268, ctx->r1) = ctx->r14;
    // 0x801C7BEC: lbu         $t1, 0x90($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X90);
    // 0x801C7BF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7BF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C7BF8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801C7BFC: sb          $t7, -0x25A($at)
    MEM_B(-0X25A, ctx->r1) = ctx->r15;
    // 0x801C7C00: jal         0x801C5F04
    // 0x801C7C04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801C5F04)(rdram, ctx);
        goto after_31;
    // 0x801C7C04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
    // 0x801C7C08: jal         0x801C5DAC
    // 0x801C7C0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801C5DAC)(rdram, ctx);
        goto after_32;
    // 0x801C7C0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x801C7C10: jal         0x801C63CC
    // 0x801C7C14: lbu         $a0, 0x90($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X90);
    LOOKUP_FUNC(0x801C63CC)(rdram, ctx);
        goto after_33;
    // 0x801C7C14: lbu         $a0, 0x90($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X90);
    after_33:
    // 0x801C7C18: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C7C1C: addiu       $a1, $a1, 0x7C64
    ctx->r5 = ADD32(ctx->r5, 0X7C64);
    // 0x801C7C20: jal         0x800058DC
    // 0x801C7C24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_34;
    // 0x801C7C24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_34:
    // 0x801C7C28: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801C7C2C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801C7C30: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801C7C34: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801C7C38: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801C7C3C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801C7C40: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801C7C44: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801C7C48: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801C7C4C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801C7C50: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801C7C54: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801C7C58: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801C7C5C: jr          $ra
    // 0x801C7C60: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x801C7C60: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c7c64(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c7c64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7C64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C7C68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C7C6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C7C70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C7C74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C7C78: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C7C7C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C7C80: addiu       $a1, $a1, -0x280
    ctx->r5 = ADD32(ctx->r5, -0X280);
    // 0x801C7C84: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C7C88: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801C7C8C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C7C90: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C7C94: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x801C7C98: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801C7C9C: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
    // 0x801C7CA0: addiu       $t1, $t0, -0x155
    ctx->r9 = ADD32(ctx->r8, -0X155);
    // 0x801C7CA4: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x801C7CA8: lbu         $s0, 0x90($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X90);
    // 0x801C7CAC: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x801C7CB0: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x801C7CB4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C7CB8: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801C7CBC: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x801C7CC0: slti        $at, $v1, -0x1000
    ctx->r1 = SIGNED(ctx->r3) < -0X1000 ? 1 : 0;
    // 0x801C7CC4: beq         $at, $zero, L_801C7D40
    if (ctx->r1 == 0) {
        // 0x801C7CC8: nop
    
            goto L_801C7D40;
    }
    // 0x801C7CC8: nop

    // 0x801C7CCC: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
    // 0x801C7CD0: jal         0x80152C68
    // 0x801C7CD4: lbu         $a0, 0x90($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X90);
    LOOKUP_FUNC(0x80152C68)(rdram, ctx);
        goto after_0;
    // 0x801C7CD4: lbu         $a0, 0x90($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X90);
    after_0:
    // 0x801C7CD8: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
    // 0x801C7CDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7CE0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C7CE4: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x801C7CE8: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x801C7CEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C7CF0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801C7CF4: lwc1        $f4, -0x3098($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x801C7CF8: addiu       $a3, $a3, -0xD00
    ctx->r7 = ADD32(ctx->r7, -0XD00);
    // 0x801C7CFC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801C7D00: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801C7D04: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x801C7D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C7D0C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801C7D10: nop

    // 0x801C7D14: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C7D18: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C7D1C: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801C7D20: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C7D24: jal         0x8001B204
    // 0x801C7D28: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C7D28: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x801C7D2C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C7D30: addiu       $a1, $a1, 0x7D5C
    ctx->r5 = ADD32(ctx->r5, 0X7D5C);
    // 0x801C7D34: jal         0x800058DC
    // 0x801C7D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C7D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801C7D3C: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7D40:
    // 0x801C7D40: jal         0x801C63CC
    // 0x801C7D44: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x801C63CC)(rdram, ctx);
        goto after_3;
    // 0x801C7D44: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_3:
    // 0x801C7D48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C7D4C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C7D50: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C7D54: jr          $ra
    // 0x801C7D58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C7D58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c7d5c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c7d5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7D5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C7D60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C7D64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C7D68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C7D6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C7D70: lbu         $s0, 0x90($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X90);
    // 0x801C7D74: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x801C7D78: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x801C7D7C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C7D80: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x801C7D84: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x801C7D88: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x801C7D8C: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x801C7D90: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801C7D94: lw          $t4, -0x248($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X248);
    // 0x801C7D98: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801C7D9C: lhu         $t9, 0x1C8($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1C8);
    // 0x801C7DA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C7DA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C7DA8: lhu         $a2, 0x1D0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X1D0);
    // 0x801C7DAC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801C7DB0: sb          $t2, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r10;
    // 0x801C7DB4: bne         $t4, $zero, L_801C7F20
    if (ctx->r12 != 0) {
        // 0x801C7DB8: sh          $t9, 0x2C($sp)
        MEM_H(0X2C, ctx->r29) = ctx->r25;
            goto L_801C7F20;
    }
    // 0x801C7DB8: sh          $t9, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r25;
    // 0x801C7DBC: andi        $t5, $a2, 0x800
    ctx->r13 = ctx->r6 & 0X800;
    // 0x801C7DC0: beq         $t5, $zero, L_801C7DF0
    if (ctx->r13 == 0) {
        // 0x801C7DC4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801C7DF0;
    }
    // 0x801C7DC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801C7DC8: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C7DCC: addiu       $t1, $t1, -0x25A
    ctx->r9 = ADD32(ctx->r9, -0X25A);
    // 0x801C7DD0: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7DD4: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7DD8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x801C7DDC: bne         $at, $zero, L_801C7DF0
    if (ctx->r1 != 0) {
        // 0x801C7DE0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_801C7DF0;
    }
    // 0x801C7DE0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x801C7DE4: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x801C7DE8: b           L_801C7F20
    // 0x801C7DEC: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7DEC: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7DF0:
    // 0x801C7DF0: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C7DF4: andi        $t7, $a0, 0x400
    ctx->r15 = ctx->r4 & 0X400;
    // 0x801C7DF8: beq         $t7, $zero, L_801C7E20
    if (ctx->r15 == 0) {
        // 0x801C7DFC: addiu       $t1, $t1, -0x25A
        ctx->r9 = ADD32(ctx->r9, -0X25A);
            goto L_801C7E20;
    }
    // 0x801C7DFC: addiu       $t1, $t1, -0x25A
    ctx->r9 = ADD32(ctx->r9, -0X25A);
    // 0x801C7E00: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7E04: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7E08: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x801C7E0C: beq         $at, $zero, L_801C7E20
    if (ctx->r1 == 0) {
        // 0x801C7E10: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_801C7E20;
    }
    // 0x801C7E10: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801C7E14: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x801C7E18: b           L_801C7F20
    // 0x801C7E1C: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7E1C: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7E20:
    // 0x801C7E20: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x801C7E24: andi        $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 & 0X8000;
    // 0x801C7E28: beq         $a1, $zero, L_801C7E4C
    if (ctx->r5 == 0) {
        // 0x801C7E2C: addu        $v0, $t1, $s0
        ctx->r2 = ADD32(ctx->r9, ctx->r16);
            goto L_801C7E4C;
    }
    // 0x801C7E2C: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7E30: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7E34: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x801C7E38: beq         $at, $zero, L_801C7E4C
    if (ctx->r1 == 0) {
        // 0x801C7E3C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_801C7E4C;
    }
    // 0x801C7E3C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801C7E40: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801C7E44: b           L_801C7F20
    // 0x801C7E48: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7E48: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7E4C:
    // 0x801C7E4C: andi        $t2, $a0, 0x100
    ctx->r10 = ctx->r4 & 0X100;
    // 0x801C7E50: beq         $t2, $zero, L_801C7E74
    if (ctx->r10 == 0) {
        // 0x801C7E54: addu        $v0, $t1, $s0
        ctx->r2 = ADD32(ctx->r9, ctx->r16);
            goto L_801C7E74;
    }
    // 0x801C7E54: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7E58: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7E5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C7E60: bne         $v1, $at, L_801C7E74
    if (ctx->r3 != ctx->r1) {
        // 0x801C7E64: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_801C7E74;
    }
    // 0x801C7E64: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x801C7E68: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x801C7E6C: b           L_801C7F20
    // 0x801C7E70: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7E70: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7E74:
    // 0x801C7E74: andi        $t4, $a0, 0x200
    ctx->r12 = ctx->r4 & 0X200;
    // 0x801C7E78: beq         $t4, $zero, L_801C7E9C
    if (ctx->r12 == 0) {
        // 0x801C7E7C: addu        $v0, $t1, $s0
        ctx->r2 = ADD32(ctx->r9, ctx->r16);
            goto L_801C7E9C;
    }
    // 0x801C7E7C: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7E80: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7E84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C7E88: bne         $v1, $at, L_801C7E9C
    if (ctx->r3 != ctx->r1) {
        // 0x801C7E8C: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_801C7E9C;
    }
    // 0x801C7E8C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x801C7E90: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x801C7E94: b           L_801C7F20
    // 0x801C7E98: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7E98: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7E9C:
    // 0x801C7E9C: beq         $a1, $zero, L_801C7F18
    if (ctx->r5 == 0) {
        // 0x801C7EA0: addu        $t6, $t1, $s0
        ctx->r14 = ADD32(ctx->r9, ctx->r16);
            goto L_801C7F18;
    }
    // 0x801C7EA0: addu        $t6, $t1, $s0
    ctx->r14 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7EA4: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x801C7EA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C7EAC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x801C7EB0: bnel        $t7, $at, L_801C7F1C
    if (ctx->r15 != ctx->r1) {
        // 0x801C7EB4: sb          $zero, 0x2A($sp)
        MEM_B(0X2A, ctx->r29) = 0;
            goto L_801C7F1C;
    }
    goto skip_0;
    // 0x801C7EB4: sb          $zero, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = 0;
    skip_0:
    // 0x801C7EB8: sh          $a2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r6;
    // 0x801C7EBC: jal         0x801C5AD4
    // 0x801C7EC0: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_0;
    // 0x801C7EC0: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    after_0:
    // 0x801C7EC4: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C7EC8: bne         $v0, $zero, L_801C7F18
    if (ctx->r2 != 0) {
        // 0x801C7ECC: lbu         $t0, 0x2B($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X2B);
            goto L_801C7F18;
    }
    // 0x801C7ECC: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C7ED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C7ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C7ED8: sh          $a2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r6;
    // 0x801C7EDC: jal         0x801C5D64
    // 0x801C7EE0: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801C5D64)(rdram, ctx);
        goto after_1;
    // 0x801C7EE0: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    after_1:
    // 0x801C7EE4: lbu         $t9, 0x90($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X90);
    // 0x801C7EE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7EEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C7EF0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801C7EF4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801C7EF8: sw          $t8, -0x248($at)
    MEM_W(-0X248, ctx->r1) = ctx->r24;
    // 0x801C7EFC: lbu         $t3, 0x90($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X90);
    // 0x801C7F00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7F04: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C7F08: sb          $t3, -0x2F30($at)
    MEM_B(-0X2F30, ctx->r1) = ctx->r11;
    // 0x801C7F0C: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C7F10: b           L_801C7F20
    // 0x801C7F14: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
        goto L_801C7F20;
    // 0x801C7F14: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7F18:
    // 0x801C7F18: sb          $zero, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = 0;
L_801C7F1C:
    // 0x801C7F1C: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7F20:
    // 0x801C7F20: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C7F24: addiu       $t1, $t1, -0x25A
    ctx->r9 = ADD32(ctx->r9, -0X25A);
    // 0x801C7F28: addu        $t4, $t1, $s0
    ctx->r12 = ADD32(ctx->r9, ctx->r16);
    // 0x801C7F2C: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x801C7F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C7F34: bne         $t5, $at, L_801C7FA0
    if (ctx->r13 != ctx->r1) {
        // 0x801C7F38: andi        $t6, $a2, 0x100
        ctx->r14 = ctx->r6 & 0X100;
            goto L_801C7FA0;
    }
    // 0x801C7F38: andi        $t6, $a2, 0x100
    ctx->r14 = ctx->r6 & 0X100;
    // 0x801C7F3C: beq         $t6, $zero, L_801C7F68
    if (ctx->r14 == 0) {
        // 0x801C7F40: andi        $a1, $a2, 0x200
        ctx->r5 = ctx->r6 & 0X200;
            goto L_801C7F68;
    }
    // 0x801C7F40: andi        $a1, $a2, 0x200
    ctx->r5 = ctx->r6 & 0X200;
    // 0x801C7F44: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C7F48: addiu       $t7, $t7, -0x2F38
    ctx->r15 = ADD32(ctx->r15, -0X2F38);
    // 0x801C7F4C: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x801C7F50: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7F54: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x801C7F58: beq         $at, $zero, L_801C7F68
    if (ctx->r1 == 0) {
        // 0x801C7F5C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_801C7F68;
    }
    // 0x801C7F5C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801C7F60: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801C7F64: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
L_801C7F68:
    // 0x801C7F68: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C7F6C: addiu       $t8, $t8, -0x2F38
    ctx->r24 = ADD32(ctx->r24, -0X2F38);
    // 0x801C7F70: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x801C7F74: beq         $a1, $zero, L_801C7FB0
    if (ctx->r5 == 0) {
        // 0x801C7F78: lb          $v1, 0x0($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X0);
            goto L_801C7FB0;
    }
    // 0x801C7F78: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x801C7F7C: slti        $at, $v1, -0x9
    ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
    // 0x801C7F80: bne         $at, $zero, L_801C7FB0
    if (ctx->r1 != 0) {
        // 0x801C7F84: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_801C7FB0;
    }
    // 0x801C7F84: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x801C7F88: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x801C7F8C: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
    // 0x801C7F90: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C7F94: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x801C7F98: b           L_801C7FB0
    // 0x801C7F9C: lb          $v1, -0x2F38($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2F38);
        goto L_801C7FB0;
    // 0x801C7F9C: lb          $v1, -0x2F38($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2F38);
L_801C7FA0:
    // 0x801C7FA0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C7FA4: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x801C7FA8: lb          $v1, -0x2F38($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2F38);
    // 0x801C7FAC: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
L_801C7FB0:
    // 0x801C7FB0: blez        $v1, L_801C8010
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801C7FB4: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_801C8010;
    }
    // 0x801C7FB4: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x801C7FB8: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x801C7FBC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801C7FC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C7FC4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801C7FC8: lwc1        $f4, -0x3098($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x801C7FCC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801C7FD0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C7FD4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801C7FD8: addiu       $a3, $a3, -0xCF4
    ctx->r7 = ADD32(ctx->r7, -0XCF4);
    // 0x801C7FDC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C7FE0: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    // 0x801C7FE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801C7FE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C7FEC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801C7FF0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C7FF4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C7FF8: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801C7FFC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C8000: jal         0x8001B204
    // 0x801C8004: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C8004: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_2:
    // 0x801C8008: b           L_801C8064
    // 0x801C800C: nop

        goto L_801C8064;
    // 0x801C800C: nop

L_801C8010:
    // 0x801C8010: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x801C8014: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x801C8018: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801C801C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8020: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801C8024: lwc1        $f8, -0x3098($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x801C8028: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801C802C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C8030: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C8034: addiu       $a3, $a3, -0xCEC
    ctx->r7 = ADD32(ctx->r7, -0XCEC);
    // 0x801C8038: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C803C: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    // 0x801C8040: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801C8044: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C8048: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801C804C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C8050: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C8054: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801C8058: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C805C: jal         0x8001B204
    // 0x801C8060: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C8060: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
L_801C8064:
    // 0x801C8064: jal         0x801C5F04
    // 0x801C8068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C5F04)(rdram, ctx);
        goto after_4;
    // 0x801C8068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801C806C: lbu         $t7, 0x2A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2A);
    // 0x801C8070: beql        $t7, $zero, L_801C80D0
    if (ctx->r15 == 0) {
        // 0x801C8074: lbu         $t3, 0x90($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X90);
            goto L_801C80D0;
    }
    goto skip_1;
    // 0x801C8074: lbu         $t3, 0x90($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X90);
    skip_1:
    // 0x801C8078: jal         0x801C5DAC
    // 0x801C807C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C5DAC)(rdram, ctx);
        goto after_5;
    // 0x801C807C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801C8080: lbu         $t9, 0x90($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X90);
    // 0x801C8084: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801C8088: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801C808C: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801C8090: lw          $t2, -0x248($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X248);
    // 0x801C8094: beq         $t2, $zero, L_801C80BC
    if (ctx->r10 == 0) {
        // 0x801C8098: nop
    
            goto L_801C80BC;
    }
    // 0x801C8098: nop

    // 0x801C809C: jal         0x80020744
    // 0x801C80A0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_6;
    // 0x801C80A0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_6:
    // 0x801C80A4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C80A8: addiu       $a1, $a1, -0x7EC4
    ctx->r5 = ADD32(ctx->r5, -0X7EC4);
    // 0x801C80AC: jal         0x800058DC
    // 0x801C80B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C80B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801C80B4: b           L_801C812C
    // 0x801C80B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C812C;
    // 0x801C80B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C80BC:
    // 0x801C80BC: jal         0x80020744
    // 0x801C80C0: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_8;
    // 0x801C80C0: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_8:
    // 0x801C80C4: b           L_801C812C
    // 0x801C80C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C812C;
    // 0x801C80C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C80CC: lbu         $t3, 0x90($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X90);
L_801C80D0:
    // 0x801C80D0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C80D4: lhu         $t5, 0x2C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2C);
    // 0x801C80D8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801C80DC: lb          $t4, -0x25A($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X25A);
    // 0x801C80E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C80E4: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801C80E8: bnel        $t4, $at, L_801C812C
    if (ctx->r12 != ctx->r1) {
        // 0x801C80EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C812C;
    }
    goto skip_2;
    // 0x801C80EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801C80F0: beq         $t6, $zero, L_801C8128
    if (ctx->r14 == 0) {
        // 0x801C80F4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801C8128;
    }
    // 0x801C80F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C80F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C80FC: sw          $t7, -0x2F34($at)
    MEM_W(-0X2F34, ctx->r1) = ctx->r15;
    // 0x801C8100: jal         0x80020744
    // 0x801C8104: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_9;
    // 0x801C8104: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_9:
    // 0x801C8108: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801C810C: sh          $t9, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r25;
    // 0x801C8110: jal         0x80020718
    // 0x801C8114: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_10;
    // 0x801C8114: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_10:
    // 0x801C8118: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C811C: addiu       $a1, $a1, -0x7E38
    ctx->r5 = ADD32(ctx->r5, -0X7E38);
    // 0x801C8120: jal         0x800058DC
    // 0x801C8124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801C8124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
L_801C8128:
    // 0x801C8128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C812C:
    // 0x801C812C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8130: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C8134: jr          $ra
    // 0x801C8138: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C8138: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c813c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c813c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C813C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C8140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C8148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C814C: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C8150: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C8154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8158: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x801C815C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801C8160: lhu         $v0, -0x6B88($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6B88);
    // 0x801C8164: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x801C8168: beql        $t8, $zero, L_801C81B8
    if (ctx->r24 == 0) {
        // 0x801C816C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C81B8;
    }
    goto skip_0;
    // 0x801C816C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801C8170: jal         0x801C5B38
    // 0x801C8174: nop

    LOOKUP_FUNC(0x801C5B38)(rdram, ctx);
        goto after_0;
    // 0x801C8174: nop

    after_0:
    // 0x801C8178: bne         $v0, $zero, L_801C81B4
    if (ctx->r2 != 0) {
        // 0x801C817C: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801C81B4;
    }
    // 0x801C817C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8180: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C818C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801C8190: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801C8194: jal         0x801C5D64
    // 0x801C8198: sw          $zero, -0x248($at)
    MEM_W(-0X248, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C5D64)(rdram, ctx);
        goto after_1;
    // 0x801C8198: sw          $zero, -0x248($at)
    MEM_W(-0X248, ctx->r1) = 0;
    after_1:
    // 0x801C819C: jal         0x801C5F04
    // 0x801C81A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C5F04)(rdram, ctx);
        goto after_2;
    // 0x801C81A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801C81A4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C81A8: addiu       $a1, $a1, 0x7D5C
    ctx->r5 = ADD32(ctx->r5, 0X7D5C);
    // 0x801C81AC: jal         0x800058DC
    // 0x801C81B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C81B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801C81B4:
    // 0x801C81B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C81B8:
    // 0x801C81B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C81BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C81C0: jr          $ra
    // 0x801C81C4: nop

    return;
    // 0x801C81C4: nop

;}
RECOMP_FUNC void M23_FUN_801c81c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C81C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C81CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C81D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C81D4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C81D8: addiu       $t7, $zero, 0xBE
    ctx->r15 = ADD32(0, 0XBE);
    // 0x801C81DC: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801C81E0: blez        $v0, L_801C81F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801C81E4: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_801C81F4;
    }
    // 0x801C81E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C81E8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801C81EC: b           L_801C8210
    // 0x801C81F0: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
        goto L_801C8210;
    // 0x801C81F0: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
L_801C81F4:
    // 0x801C81F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C81F8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C81FC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x801C8200: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x801C8204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C8208: jal         0x8012FE50
    // 0x801C820C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C820C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_801C8210:
    // 0x801C8210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C8218: jr          $ra
    // 0x801C821C: nop

    return;
    // 0x801C821C: nop

;}
RECOMP_FUNC void M23_FUN_801c8220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8220: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x801C8224: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C8228: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C822C: addiu       $t7, $t7, -0x2E60
    ctx->r15 = ADD32(ctx->r15, -0X2E60);
    // 0x801C8230: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C8234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C8238: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C823C: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x801C8240: addiu       $t0, $t7, 0x6C
    ctx->r8 = ADD32(ctx->r15, 0X6C);
    // 0x801C8244: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_801C8248:
    // 0x801C8248: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C824C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801C8250: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801C8254: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801C8258: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801C825C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801C8260: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801C8264: bne         $t7, $t0, L_801C8248
    if (ctx->r15 != ctx->r8) {
        // 0x801C8268: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801C8248;
    }
    // 0x801C8268: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801C826C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C8270: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8274: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801C8278: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x801C827C: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
    // 0x801C8280: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
    // 0x801C8284: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x801C8288: lbu         $a1, -0x258($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X258);
    // 0x801C828C: jal         0x80152980
    // 0x801C8290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80152980)(rdram, ctx);
        goto after_0;
    // 0x801C8290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C8294: lbu         $t1, 0x90($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X90);
    // 0x801C8298: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801C829C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801C82A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801C82A4: lw          $t4, 0x1CEC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1CEC);
    // 0x801C82A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C82AC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801C82B0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801C82B4: sh          $v0, -0x254($at)
    MEM_H(-0X254, ctx->r1) = ctx->r2;
    // 0x801C82B8: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x801C82BC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801C82C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C82C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C82C8: jal         0x80126A0C
    // 0x801C82CC: lhu         $a1, 0x0($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x801C82CC: lhu         $a1, 0x0($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X0);
    after_1:
    // 0x801C82D0: beq         $v0, $zero, L_801C8314
    if (ctx->r2 == 0) {
        // 0x801C82D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C8314;
    }
    // 0x801C82D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C82D8: lbu         $s0, 0x90($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X90);
    // 0x801C82DC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C82E0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C82E4: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x801C82E8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801C82EC: lhu         $t6, -0x2F40($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2F40);
    // 0x801C82F0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C82F4: addiu       $t0, $t0, -0x7CD8
    ctx->r8 = ADD32(ctx->r8, -0X7CD8);
    // 0x801C82F8: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // 0x801C82FC: lbu         $a3, -0x2F3C($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X2F3C);
    // 0x801C8300: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C8304: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C8308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C830C: jal         0x8013B268
    // 0x801C8310: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8013B268)(rdram, ctx);
        goto after_2;
    // 0x801C8310: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
L_801C8314:
    // 0x801C8314: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C8318: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C831C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C8320: jr          $ra
    // 0x801C8324: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x801C8324: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c8328(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c8328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8328: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C832C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C8330: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C8334: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C8338: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C833C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8344: addiu       $a1, $a1, -0x2EC4
    ctx->r5 = ADD32(ctx->r5, -0X2EC4);
    // 0x801C8348: jal         0x80005670
    // 0x801C834C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C834C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801C8350: beql        $v0, $zero, L_801C8364
    if (ctx->r2 == 0) {
        // 0x801C8354: lw          $t8, 0x24($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X24);
            goto L_801C8364;
    }
    goto skip_0;
    // 0x801C8354: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801C8358: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801C835C: sb          $t7, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r15;
    // 0x801C8360: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
L_801C8364:
    // 0x801C8364: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C8368: addiu       $v0, $v0, -0x2F6C
    ctx->r2 = ADD32(ctx->r2, -0X2F6C);
    // 0x801C836C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C8370: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C8374: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801C8378: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801C837C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C8380: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C8384: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801C8388: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801C838C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8390: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C8394: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801C8398: lbu         $a2, 0x90($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X90);
    // 0x801C839C: bne         $a2, $zero, L_801C83B4
    if (ctx->r6 != 0) {
        // 0x801C83A0: nop
    
            goto L_801C83B4;
    }
    // 0x801C83A0: nop

    // 0x801C83A4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801C83A8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C83AC: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801C83B0: lbu         $a2, 0x90($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X90);
L_801C83B4:
    // 0x801C83B4: jal         0x801C5AD4
    // 0x801C83B8: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_1;
    // 0x801C83B8: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_1:
    // 0x801C83BC: beq         $v0, $zero, L_801C83FC
    if (ctx->r2 == 0) {
        // 0x801C83C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C83FC;
    }
    // 0x801C83C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C83C4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C83C8: addiu       $a1, $a1, -0x33C0
    ctx->r5 = ADD32(ctx->r5, -0X33C0);
    // 0x801C83CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C83D0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x801C83D4: jal         0x8014753C
    // 0x801C83D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014753C)(rdram, ctx);
        goto after_2;
    // 0x801C83D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801C83DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C83E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C83E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C83E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C83EC: jal         0x80147370
    // 0x801C83F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_3;
    // 0x801C83F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x801C83F4: b           L_801C8430
    // 0x801C83F8: sh          $zero, 0x98($s0)
    MEM_H(0X98, ctx->r16) = 0;
        goto L_801C8430;
    // 0x801C83F8: sh          $zero, 0x98($s0)
    MEM_H(0X98, ctx->r16) = 0;
L_801C83FC:
    // 0x801C83FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8400: addiu       $a1, $a1, -0x3358
    ctx->r5 = ADD32(ctx->r5, -0X3358);
    // 0x801C8404: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8408: jal         0x8014753C
    // 0x801C840C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    LOOKUP_FUNC(0x8014753C)(rdram, ctx);
        goto after_4;
    // 0x801C840C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    after_4:
    // 0x801C8410: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801C8414: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C8418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C841C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C8424: jal         0x80147370
    // 0x801C8428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_5;
    // 0x801C8428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801C842C: sh          $zero, 0x98($s0)
    MEM_H(0X98, ctx->r16) = 0;
L_801C8430:
    // 0x801C8430: lh          $v0, 0x98($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X98);
    // 0x801C8434: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x801C8438: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801C843C: sh          $v0, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r2;
    // 0x801C8440: sh          $v0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r2;
    // 0x801C8444: sh          $v0, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r2;
    // 0x801C8448: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801C844C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C8450: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8454: lwc1        $f10, 0x50($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X50);
    // 0x801C8458: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C845C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8460: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C8464: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801C8468: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C846C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C8470: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x801C8474: lw          $t1, 0x28C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28C);
    // 0x801C8478: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801C847C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C8480: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C8484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8488: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C848C: swc1        $f4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f4.u32l;
    // 0x801C8490: lbu         $t3, 0x90($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8494: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801C8498: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x801C849C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C84A0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801C84A4: lw          $t6, 0x28C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28C);
    // 0x801C84A8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C84AC: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x801C84B0: lbu         $a2, 0x90($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X90);
    // 0x801C84B4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x801C84B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801C84BC: lhu         $t9, -0x254($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X254);
    // 0x801C84C0: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x801C84C4: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x801C84C8: bne         $t9, $at, L_801C84DC
    if (ctx->r25 != ctx->r1) {
        // 0x801C84CC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801C84DC;
    }
    // 0x801C84CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C84D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C84D4: b           L_801C84E8
    // 0x801C84D8: lw          $t2, 0x28C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28C);
        goto L_801C84E8;
    // 0x801C84D8: lw          $t2, 0x28C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28C);
L_801C84DC:
    // 0x801C84DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C84E0: nop

    // 0x801C84E4: lw          $t2, 0x28C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28C);
L_801C84E8:
    // 0x801C84E8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801C84EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C84F0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C84F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C84F8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801C84FC: swc1        $f0, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f0.u32l;
    // 0x801C8500: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C8508: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801C850C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C8510: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x801C8514: lw          $t7, 0x28C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28C);
    // 0x801C8518: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C851C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8520: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C8524: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8528: addiu       $a1, $a1, -0x7A98
    ctx->r5 = ADD32(ctx->r5, -0X7A98);
    // 0x801C852C: swc1        $f16, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f16.u32l;
    // 0x801C8530: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8534: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C8538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C853C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801C8540: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x801C8544: lw          $t2, 0x28C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28C);
    // 0x801C8548: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C854C: jal         0x800058DC
    // 0x801C8550: swc1        $f8, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C8550: swc1        $f8, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f8.u32l;
    after_6:
    // 0x801C8554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C8558: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C855C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C8560: jr          $ra
    // 0x801C8564: nop

    return;
    // 0x801C8564: nop

;}
RECOMP_FUNC void M23_FUN_801c8568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8568: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801C856C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C8570: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C8574: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801C8578: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C857C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801C8580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8584: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x801C8588: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C858C: lhu         $t8, -0x6B80($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6B80);
    // 0x801C8590: sb          $zero, 0x45($sp)
    MEM_B(0X45, ctx->r29) = 0;
    // 0x801C8594: jal         0x801C5B38
    // 0x801C8598: sh          $t8, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C5B38)(rdram, ctx);
        goto after_0;
    // 0x801C8598: sh          $t8, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r24;
    after_0:
    // 0x801C859C: bnel        $v0, $zero, L_801C8694
    if (ctx->r2 != 0) {
        // 0x801C85A0: lbu         $t9, 0x90($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X90);
            goto L_801C8694;
    }
    goto skip_0;
    // 0x801C85A0: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    skip_0:
    // 0x801C85A4: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801C85A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C85AC: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x801C85B0: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x801C85B4: jal         0x80152C04
    // 0x801C85B8: lhu         $a0, -0x254($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X254);
    LOOKUP_FUNC(0x80152C04)(rdram, ctx);
        goto after_1;
    // 0x801C85B8: lhu         $a0, -0x254($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X254);
    after_1:
    // 0x801C85BC: lbu         $v1, 0x90($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X90);
    // 0x801C85C0: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801C85C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C85C8: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x801C85CC: lb          $t2, -0x25A($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X25A);
    // 0x801C85D0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801C85D4: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x801C85D8: bne         $t2, $at, L_801C8640
    if (ctx->r10 != ctx->r1) {
        // 0x801C85DC: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_801C8640;
    }
    // 0x801C85DC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801C85E0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x801C85E4: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x801C85E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801C85EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C85F0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801C85F4: lwc1        $f4, -0x3098($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x801C85F8: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    // 0x801C85FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C8600: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801C8604: addiu       $t5, $zero, 0xDD
    ctx->r13 = ADD32(0, 0XDD);
    // 0x801C8608: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C860C: addiu       $a3, $a3, -0xCC0
    ctx->r7 = ADD32(ctx->r7, -0XCC0);
    // 0x801C8610: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801C8614: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C8618: addiu       $a2, $zero, 0x91
    ctx->r6 = ADD32(0, 0X91);
    // 0x801C861C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C8620: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C8624: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801C8628: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C862C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C8630: jal         0x8001B204
    // 0x801C8634: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C8634: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x801C8638: b           L_801C8694
    // 0x801C863C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
        goto L_801C8694;
    // 0x801C863C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
L_801C8640:
    // 0x801C8640: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801C8644: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C8648: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C864C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801C8650: lwc1        $f8, -0x3098($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x801C8654: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C8658: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x801C865C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C8660: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C8664: addiu       $a3, $a3, -0xCB8
    ctx->r7 = ADD32(ctx->r7, -0XCB8);
    // 0x801C8668: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C866C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801C8670: addiu       $a2, $zero, 0x91
    ctx->r6 = ADD32(0, 0X91);
    // 0x801C8674: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C8678: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C867C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C8680: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x801C8684: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C8688: jal         0x8001B204
    // 0x801C868C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C868C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x801C8690: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
L_801C8694:
    // 0x801C8694: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C8698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C869C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801C86A0: lb          $t1, -0x25A($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X25A);
    // 0x801C86A4: bnel        $t1, $at, L_801C8750
    if (ctx->r9 != ctx->r1) {
        // 0x801C86A8: lbu         $t5, 0x45($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X45);
            goto L_801C8750;
    }
    goto skip_1;
    // 0x801C86A8: lbu         $t5, 0x45($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X45);
    skip_1:
    // 0x801C86AC: jal         0x801C5AB0
    // 0x801C86B0: nop

    LOOKUP_FUNC(0x801C5AB0)(rdram, ctx);
        goto after_4;
    // 0x801C86B0: nop

    after_4:
    // 0x801C86B4: bne         $v0, $zero, L_801C874C
    if (ctx->r2 != 0) {
        // 0x801C86B8: lhu         $a1, 0x46($sp)
        ctx->r5 = MEM_HU(ctx->r29, 0X46);
            goto L_801C874C;
    }
    // 0x801C86B8: lhu         $a1, 0x46($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X46);
    // 0x801C86BC: andi        $t2, $a1, 0x200
    ctx->r10 = ctx->r5 & 0X200;
    // 0x801C86C0: beq         $t2, $zero, L_801C8708
    if (ctx->r10 == 0) {
        // 0x801C86C4: andi        $t8, $a1, 0x100
        ctx->r24 = ctx->r5 & 0X100;
            goto L_801C8708;
    }
    // 0x801C86C4: andi        $t8, $a1, 0x100
    ctx->r24 = ctx->r5 & 0X100;
    // 0x801C86C8: lbu         $v1, 0x90($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X90);
    // 0x801C86CC: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C86D0: addiu       $t3, $t3, -0x258
    ctx->r11 = ADD32(ctx->r11, -0X258);
    // 0x801C86D4: addu        $a0, $v1, $t3
    ctx->r4 = ADD32(ctx->r3, ctx->r11);
    // 0x801C86D8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x801C86DC: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C86E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C86E4: bne         $v0, $zero, L_801C8700
    if (ctx->r2 != 0) {
        // 0x801C86E8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801C8700;
    }
    // 0x801C86E8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801C86EC: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x801C86F0: lbu         $t4, -0x250($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X250);
    // 0x801C86F4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x801C86F8: b           L_801C8704
    // 0x801C86FC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_801C8704;
    // 0x801C86FC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_801C8700:
    // 0x801C8700: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_801C8704:
    // 0x801C8704: sb          $t7, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r15;
L_801C8708:
    // 0x801C8708: beq         $t8, $zero, L_801C874C
    if (ctx->r24 == 0) {
        // 0x801C870C: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801C874C;
    }
    // 0x801C870C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C8710: lbu         $v1, 0x90($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X90);
    // 0x801C8714: addiu       $t9, $t9, -0x258
    ctx->r25 = ADD32(ctx->r25, -0X258);
    // 0x801C8718: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C871C: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x801C8720: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x801C8724: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x801C8728: lbu         $t3, -0x250($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X250);
    // 0x801C872C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C8730: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801C8734: bne         $t2, $t3, L_801C8744
    if (ctx->r10 != ctx->r11) {
        // 0x801C8738: sb          $t1, 0x45($sp)
        MEM_B(0X45, ctx->r29) = ctx->r9;
            goto L_801C8744;
    }
    // 0x801C8738: sb          $t1, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r9;
    // 0x801C873C: b           L_801C874C
    // 0x801C8740: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_801C874C;
    // 0x801C8740: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_801C8744:
    // 0x801C8744: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801C8748: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_801C874C:
    // 0x801C874C: lbu         $t5, 0x45($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X45);
L_801C8750:
    // 0x801C8750: beq         $t5, $zero, L_801C87F4
    if (ctx->r13 == 0) {
        // 0x801C8754: nop
    
            goto L_801C87F4;
    }
    // 0x801C8754: nop

    // 0x801C8758: jal         0x80020744
    // 0x801C875C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_5;
    // 0x801C875C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_5:
    // 0x801C8760: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C8764: addiu       $t6, $t6, -0x2EEC
    ctx->r14 = ADD32(ctx->r14, -0X2EEC);
    // 0x801C8768: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801C876C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801C8770: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801C8774: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801C8778: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C877C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C8780: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801C8784: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801C8788: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801C878C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C8790: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801C8794: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C8798: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C879C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C87A0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801C87A4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801C87A8: jal         0x8012C4D0
    // 0x801C87AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_6;
    // 0x801C87AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x801C87B0: beql        $v0, $zero, L_801C87C4
    if (ctx->r2 == 0) {
        // 0x801C87B4: lw          $t2, 0x8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X8);
            goto L_801C87C4;
    }
    goto skip_2;
    // 0x801C87B4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x801C87B8: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x801C87BC: sb          $t1, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r9;
    // 0x801C87C0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
L_801C87C4:
    // 0x801C87C4: beq         $t2, $zero, L_801C87DC
    if (ctx->r10 == 0) {
        // 0x801C87C8: nop
    
            goto L_801C87DC;
    }
    // 0x801C87C8: nop

    // 0x801C87CC: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801C87D0: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x801C87D4: jal         0x80005700
    // 0x801C87D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_7;
    // 0x801C87D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_7:
L_801C87DC:
    // 0x801C87DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801C87E0: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801C87E4: jal         0x800058DC
    // 0x801C87E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C87E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801C87EC: b           L_801C895C
    // 0x801C87F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801C895C;
    // 0x801C87F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801C87F4:
    // 0x801C87F4: jal         0x801C5AD4
    // 0x801C87F8: lbu         $a0, 0x90($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X90);
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_9;
    // 0x801C87F8: lbu         $a0, 0x90($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X90);
    after_9:
    // 0x801C87FC: beq         $v0, $zero, L_801C88F0
    if (ctx->r2 == 0) {
        // 0x801C8800: lw          $t1, 0x4C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4C);
            goto L_801C88F0;
    }
    // 0x801C8800: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x801C8804: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x801C8808: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801C880C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8810: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801C8814: addiu       $a1, $a1, -0x33C0
    ctx->r5 = ADD32(ctx->r5, -0X33C0);
    // 0x801C8818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C881C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C8820: lbu         $v0, 0x4B($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4B);
    // 0x801C8824: bne         $v0, $at, L_801C883C
    if (ctx->r2 != ctx->r1) {
        // 0x801C8828: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801C883C;
    }
    // 0x801C8828: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C882C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x801C8830: jal         0x8014753C
    // 0x801C8834: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8014753C)(rdram, ctx);
        goto after_10;
    // 0x801C8834: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    after_10:
    // 0x801C8838: lh          $v0, 0x36($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X36);
L_801C883C:
    // 0x801C883C: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x801C8840: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C8844: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801C8848: bgez        $v0, L_801C8854
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801C884C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C8854;
    }
    // 0x801C884C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8854:
    // 0x801C8854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C885C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C8860: jal         0x80147370
    // 0x801C8864: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_11;
    // 0x801C8864: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_11:
    // 0x801C8868: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801C886C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801C8870: lh          $t7, 0x94($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X94);
    // 0x801C8874: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x801C8878: lh          $t9, 0x96($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X96);
    // 0x801C887C: lh          $t2, 0x98($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X98);
    // 0x801C8880: mfhi        $v1
    ctx->r3 = hi;
    // 0x801C8884: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801C8888: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801C888C: addiu       $t8, $t7, 0x32
    ctx->r24 = ADD32(ctx->r15, 0X32);
    // 0x801C8890: addiu       $t1, $t9, 0x64
    ctx->r9 = ADD32(ctx->r25, 0X64);
    // 0x801C8894: addiu       $t3, $t2, 0x96
    ctx->r11 = ADD32(ctx->r10, 0X96);
    // 0x801C8898: sh          $t8, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r24;
    // 0x801C889C: sh          $t1, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r9;
    // 0x801C88A0: sh          $t3, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r11;
    // 0x801C88A4: beq         $v1, $zero, L_801C8958
    if (ctx->r3 == 0) {
        // 0x801C88A8: sh          $t4, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r12;
            goto L_801C8958;
    }
    // 0x801C88A8: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x801C88AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C88B0: addiu       $a1, $a1, -0x2ED8
    ctx->r5 = ADD32(ctx->r5, -0X2ED8);
    // 0x801C88B4: jal         0x80005670
    // 0x801C88B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_12;
    // 0x801C88B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801C88BC: beql        $v0, $zero, L_801C895C
    if (ctx->r2 == 0) {
        // 0x801C88C0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801C895C;
    }
    goto skip_3;
    // 0x801C88C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x801C88C4: lh          $t5, 0x94($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X94);
    // 0x801C88C8: sh          $t5, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r13;
    // 0x801C88CC: lh          $t6, 0x96($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X96);
    // 0x801C88D0: sh          $t6, 0x96($v0)
    MEM_H(0X96, ctx->r2) = ctx->r14;
    // 0x801C88D4: lh          $t7, 0x98($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X98);
    // 0x801C88D8: sh          $t7, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r15;
    // 0x801C88DC: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801C88E0: sb          $t8, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r24;
    // 0x801C88E4: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x801C88E8: b           L_801C8958
    // 0x801C88EC: sw          $t9, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r25;
        goto L_801C8958;
    // 0x801C88EC: sw          $t9, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r25;
L_801C88F0:
    // 0x801C88F0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801C88F4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801C88F8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C88FC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C8900: addiu       $a1, $a1, -0x3358
    ctx->r5 = ADD32(ctx->r5, -0X3358);
    // 0x801C8904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8908: lbu         $v0, 0x4B($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X4B);
    // 0x801C890C: bne         $v0, $at, L_801C8928
    if (ctx->r2 != ctx->r1) {
        // 0x801C8910: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801C8928;
    }
    // 0x801C8910: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8914: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x801C8918: jal         0x8014753C
    // 0x801C891C: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8014753C)(rdram, ctx);
        goto after_13;
    // 0x801C891C: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    after_13:
    // 0x801C8920: b           L_801C8934
    // 0x801C8924: lh          $v0, 0x34($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X34);
        goto L_801C8934;
    // 0x801C8924: lh          $v0, 0x34($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X34);
L_801C8928:
    // 0x801C8928: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801C892C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C8930: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_801C8934:
    // 0x801C8934: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801C8938: bne         $at, $zero, L_801C8944
    if (ctx->r1 != 0) {
        // 0x801C893C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C8944;
    }
    // 0x801C893C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8940: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_801C8944:
    // 0x801C8944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C894C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C8950: jal         0x80147370
    // 0x801C8954: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_14;
    // 0x801C8954: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_14:
L_801C8958:
    // 0x801C8958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801C895C:
    // 0x801C895C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C8960: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801C8964: jr          $ra
    // 0x801C8968: nop

    return;
    // 0x801C8968: nop

;}
RECOMP_FUNC void M23_FUN_801c896c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C896C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C8970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8974: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C8978: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C897C: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C8980: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C8984: addiu       $t8, $t8, -0x2E88
    ctx->r24 = ADD32(ctx->r24, -0X2E88);
    // 0x801C8988: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801C898C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C8990: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C8994: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C8998: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C899C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x801C89A0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C89A4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801C89A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C89AC: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x801C89B0: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801C89B4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x801C89B8: ori         $t2, $t2, 0x8FF
    ctx->r10 = ctx->r10 | 0X8FF;
    // 0x801C89BC: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x801C89C0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801C89C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C89C8: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
    // 0x801C89CC: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801C89D0: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x801C89D4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801C89D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C89DC: jal         0x80005E44
    // 0x801C89E0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C89E0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801C89E4: jal         0x80006214
    // 0x801C89E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C89E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C89EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C89F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C89F4: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C89F8: jal         0x8012C89C
    // 0x801C89FC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C89FC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_2:
    // 0x801C8A00: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8A08: lwc1        $f0, -0xC50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC50);
    // 0x801C8A0C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801C8A10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801C8A14: addiu       $t6, $t6, -0x4808
    ctx->r14 = ADD32(ctx->r14, -0X4808);
    // 0x801C8A18: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801C8A1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8A20: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801C8A24: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x801C8A28: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x801C8A2C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A30: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801C8A34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801C8A38: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8A3C: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x801C8A40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C8A44: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x801C8A48: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A4C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801C8A50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C8A54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8A58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C8A5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8A60: sb          $zero, 0x48($t1)
    MEM_B(0X48, ctx->r9) = 0;
    // 0x801C8A64: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A68: addiu       $a1, $a1, -0x74E0
    ctx->r5 = ADD32(ctx->r5, -0X74E0);
    // 0x801C8A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8A70: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C8A74: sb          $t2, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r10;
    // 0x801C8A78: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A7C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C8A80: sb          $zero, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = 0;
    // 0x801C8A84: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A88: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x801C8A8C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C8A90: sb          $t8, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r24;
    // 0x801C8A94: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C8A98: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8A9C: swc1        $f10, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f10.u32l;
    // 0x801C8AA0: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C8AA4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AA8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801C8AAC: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x801C8AB0: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x801C8AB4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AB8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C8ABC: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x801C8AC0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AC4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8AC8: sh          $t6, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r14;
    // 0x801C8ACC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AD0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C8AD4: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x801C8AD8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C8ADC: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C8AE0: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x801C8AE4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AE8: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C8AEC: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x801C8AF0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C8AF4: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C8AF8: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x801C8AFC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C8B00: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C8B04: jal         0x800058DC
    // 0x801C8B08: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C8B08: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    after_3:
    // 0x801C8B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8B10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C8B14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C8B18: jr          $ra
    // 0x801C8B1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C8B1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c8b20(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c8b20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8B20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C8B24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8B28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C8B2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C8B30: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C8B34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8B38: ldc1        $f8, -0xC48($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XC48);
    // 0x801C8B3C: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801C8B40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8B44: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C8B48: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8B4C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C8B50: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801C8B54: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801C8B58: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x801C8B5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C8B60: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8B64: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C8B68: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801C8B6C: lh          $t9, 0x94($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X94);
    // 0x801C8B70: lh          $t1, 0x96($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X96);
    // 0x801C8B74: lh          $t3, 0x98($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X98);
    // 0x801C8B78: addiu       $t0, $t9, 0x64
    ctx->r8 = ADD32(ctx->r25, 0X64);
    // 0x801C8B7C: addiu       $t2, $t1, 0x96
    ctx->r10 = ADD32(ctx->r9, 0X96);
    // 0x801C8B80: addiu       $t4, $t3, 0xC8
    ctx->r12 = ADD32(ctx->r11, 0XC8);
    // 0x801C8B84: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
    // 0x801C8B88: sh          $t2, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r10;
    // 0x801C8B8C: sh          $t4, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r12;
    // 0x801C8B90: jal         0x8001EAD0
    // 0x801C8B94: lh          $a0, 0x94($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X94);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801C8B94: lh          $a0, 0x94($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X94);
    after_0:
    // 0x801C8B98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C8B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C8BA0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C8BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C8BA8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801C8BAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C8BB0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C8BB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C8BB8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801C8BBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C8BC0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801C8BC4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801C8BC8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x801C8BCC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C8BD0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C8BD4: nop

    // 0x801C8BD8: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x801C8BDC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C8BE0: nop

    // 0x801C8BE4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C8BE8: beql        $t6, $zero, L_801C8C3C
    if (ctx->r14 == 0) {
        // 0x801C8BEC: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801C8C3C;
    }
    goto skip_0;
    // 0x801C8BEC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801C8BF0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C8BF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C8BF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C8BFC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x801C8C00: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C8C04: nop

    // 0x801C8C08: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x801C8C0C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C8C10: nop

    // 0x801C8C14: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C8C18: bne         $t6, $zero, L_801C8C30
    if (ctx->r14 != 0) {
        // 0x801C8C1C: nop
    
            goto L_801C8C30;
    }
    // 0x801C8C1C: nop

    // 0x801C8C20: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801C8C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C8C28: b           L_801C8C48
    // 0x801C8C2C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C8C48;
    // 0x801C8C2C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C8C30:
    // 0x801C8C30: b           L_801C8C48
    // 0x801C8C34: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C8C48;
    // 0x801C8C34: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C8C38: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801C8C3C:
    // 0x801C8C3C: nop

    // 0x801C8C40: bltz        $t6, L_801C8C30
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C8C44: nop
    
            goto L_801C8C30;
    }
    // 0x801C8C44: nop

L_801C8C48:
    // 0x801C8C48: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C8C4C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C8C50: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8C54: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x801C8C58: jal         0x8001EAD0
    // 0x801C8C5C: lh          $a0, 0x96($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X96);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801C8C5C: lh          $a0, 0x96($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X96);
    after_1:
    // 0x801C8C60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C8C64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C8C68: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C8C6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C8C70: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801C8C74: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C8C78: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C8C7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C8C80: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801C8C84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C8C88: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801C8C8C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801C8C90: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C8C94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C8C98: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C8C9C: nop

    // 0x801C8CA0: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x801C8CA4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C8CA8: nop

    // 0x801C8CAC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C8CB0: beql        $t0, $zero, L_801C8D04
    if (ctx->r8 == 0) {
        // 0x801C8CB4: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_801C8D04;
    }
    goto skip_1;
    // 0x801C8CB4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801C8CB8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C8CBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C8CC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C8CC4: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x801C8CC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C8CCC: nop

    // 0x801C8CD0: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x801C8CD4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C8CD8: nop

    // 0x801C8CDC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C8CE0: bne         $t0, $zero, L_801C8CF8
    if (ctx->r8 != 0) {
        // 0x801C8CE4: nop
    
            goto L_801C8CF8;
    }
    // 0x801C8CE4: nop

    // 0x801C8CE8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801C8CEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C8CF0: b           L_801C8D10
    // 0x801C8CF4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C8D10;
    // 0x801C8CF4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C8CF8:
    // 0x801C8CF8: b           L_801C8D10
    // 0x801C8CFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C8D10;
    // 0x801C8CFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C8D00: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_801C8D04:
    // 0x801C8D04: nop

    // 0x801C8D08: bltz        $t0, L_801C8CF8
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C8D0C: nop
    
            goto L_801C8CF8;
    }
    // 0x801C8D0C: nop

L_801C8D10:
    // 0x801C8D10: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C8D14: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C8D18: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C8D1C: sb          $t0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r8;
    // 0x801C8D20: jal         0x8001EAD0
    // 0x801C8D24: lh          $a0, 0x98($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X98);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801C8D24: lh          $a0, 0x98($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X98);
    after_2:
    // 0x801C8D28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C8D2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C8D30: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C8D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C8D38: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801C8D3C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C8D40: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C8D44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C8D48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801C8D4C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C8D50: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801C8D54: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C8D58: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C8D5C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C8D60: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C8D64: nop

    // 0x801C8D68: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x801C8D6C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C8D70: nop

    // 0x801C8D74: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C8D78: beql        $t4, $zero, L_801C8DCC
    if (ctx->r12 == 0) {
        // 0x801C8D7C: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_801C8DCC;
    }
    goto skip_2;
    // 0x801C8D7C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x801C8D80: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C8D84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C8D88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C8D8C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x801C8D90: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C8D94: nop

    // 0x801C8D98: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x801C8D9C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C8DA0: nop

    // 0x801C8DA4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C8DA8: bne         $t4, $zero, L_801C8DC0
    if (ctx->r12 != 0) {
        // 0x801C8DAC: nop
    
            goto L_801C8DC0;
    }
    // 0x801C8DAC: nop

    // 0x801C8DB0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801C8DB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C8DB8: b           L_801C8DD8
    // 0x801C8DBC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C8DD8;
    // 0x801C8DBC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C8DC0:
    // 0x801C8DC0: b           L_801C8DD8
    // 0x801C8DC4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C8DD8;
    // 0x801C8DC4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C8DC8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_801C8DCC:
    // 0x801C8DCC: nop

    // 0x801C8DD0: bltz        $t4, L_801C8DC0
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C8DD4: nop
    
            goto L_801C8DC0;
    }
    // 0x801C8DD4: nop

L_801C8DD8:
    // 0x801C8DD8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C8DDC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C8DE0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C8DE4: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C8DE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C8DEC: sb          $t4, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r12;
    // 0x801C8DF0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C8DF4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801C8DF8: nop

    // 0x801C8DFC: bc1fl       L_801C8E10
    if (!c1cs) {
        // 0x801C8E00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C8E10;
    }
    goto skip_3;
    // 0x801C8E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801C8E04: jal         0x80005700
    // 0x801C8E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C8E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801C8E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C8E10:
    // 0x801C8E10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C8E14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C8E18: jr          $ra
    // 0x801C8E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C8E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c8e20(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c8e20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8E20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C8E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8E28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C8E2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C8E30: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C8E34: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C8E38: addiu       $t8, $t8, -0x2E88
    ctx->r24 = ADD32(ctx->r24, -0X2E88);
    // 0x801C8E3C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801C8E40: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C8E44: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C8E48: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C8E4C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C8E50: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x801C8E54: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C8E58: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x801C8E5C: ori         $t2, $t2, 0x901
    ctx->r10 = ctx->r10 | 0X901;
    // 0x801C8E60: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x801C8E64: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801C8E68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C8E6C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x801C8E70: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801C8E74: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
    // 0x801C8E78: jal         0x80005E44
    // 0x801C8E7C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C8E7C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_0:
    // 0x801C8E80: jal         0x80006214
    // 0x801C8E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C8E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C8E88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8E90: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C8E94: jal         0x8012C89C
    // 0x801C8E98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C8E98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801C8E9C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C8EA0: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C8EA4: addiu       $t6, $t6, -0x3198
    ctx->r14 = ADD32(ctx->r14, -0X3198);
    // 0x801C8EA8: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801C8EAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8EB0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801C8EB4: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801C8EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8EBC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801C8EC0: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x801C8EC4: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x801C8EC8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C8ECC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8ED0: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x801C8ED4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C8ED8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8EDC: sb          $zero, 0x48($t1)
    MEM_B(0X48, ctx->r9) = 0;
    // 0x801C8EE0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8EE4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8EE8: sb          $zero, 0x49($t3)
    MEM_B(0X49, ctx->r11) = 0;
    // 0x801C8EEC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C8EF0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C8EF4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x801C8EF8: ori         $t4, $t4, 0x8FF
    ctx->r12 = ctx->r12 | 0X8FF;
    // 0x801C8EFC: sb          $zero, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = 0;
    // 0x801C8F00: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C8F04: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C8F08: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x801C8F0C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8F10: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C8F14: sh          $zero, 0x10($t9)
    MEM_H(0X10, ctx->r25) = 0;
    // 0x801C8F18: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C8F1C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8F20: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801C8F24: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8F28: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8F2C: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x801C8F30: jal         0x80005E44
    // 0x801C8F34: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_3;
    // 0x801C8F34: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_3:
    // 0x801C8F38: jal         0x80006214
    // 0x801C8F3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801C8F3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801C8F40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8F44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C8F48: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C8F4C: jal         0x8012C89C
    // 0x801C8F50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x801C8F50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x801C8F54: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x801C8F58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8F5C: ldc1        $f0, -0xC40($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XC40);
    // 0x801C8F60: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801C8F64: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801C8F68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C8F6C: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801C8F70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8F74: lwc1        $f14, -0xC38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0XC38);
    // 0x801C8F78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8F7C: lwc1        $f16, -0xC34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XC34);
    // 0x801C8F80: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x801C8F84: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x801C8F88: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x801C8F8C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C8F90: addiu       $t7, $t7, -0x3130
    ctx->r15 = ADD32(ctx->r15, -0X3130);
    // 0x801C8F94: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8F98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8F9C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x801C8FA0: sw          $t9, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r25;
    // 0x801C8FA4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8FA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C8FAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801C8FB0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8FB4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8FB8: addiu       $a1, $a1, -0x6F64
    ctx->r5 = ADD32(ctx->r5, -0X6F64);
    // 0x801C8FBC: swc1        $f2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f2.u32l;
    // 0x801C8FC0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C8FC4: lwc1        $f4, -0xC30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XC30);
    // 0x801C8FC8: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x801C8FCC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C8FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8FD8: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x801C8FDC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C8FE0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C8FE4: swc1        $f12, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f12.u32l;
    // 0x801C8FE8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8FEC: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C8FF0: swc1        $f14, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f14.u32l;
    // 0x801C8FF4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C8FF8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C8FFC: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x801C9000: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C9004: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9008: swc1        $f14, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f14.u32l;
    // 0x801C900C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C9010: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C9014: swc1        $f2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f2.u32l;
    // 0x801C9018: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C901C: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C9020: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801C9024: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C9028: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C902C: swc1        $f12, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f12.u32l;
    // 0x801C9030: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C9034: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x801C9038: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C903C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9040: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x801C9044: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C9048: add.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f10.d + ctx->f0.d;
    // 0x801C904C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801C9050: swc1        $f4, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f4.u32l;
    // 0x801C9054: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C9058: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C905C: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x801C9060: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9064: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C9068: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C906C: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C9070: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801C9074: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C9078: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x801C907C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801C9080: jal         0x800058DC
    // 0x801C9084: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C9084: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    after_6:
    // 0x801C9088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C908C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C9090: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C9094: jr          $ra
    // 0x801C9098: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C9098: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c909c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c909c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C909C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C90A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C90A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C90A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C90AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C90B0: jal         0x8012C6B4
    // 0x801C90B4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801C90B4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x801C90B8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C90BC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x801C90C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C90C4: jal         0x8012C6B4
    // 0x801C90C8: sb          $v0, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801C90C8: sb          $v0, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r2;
    after_1:
    // 0x801C90CC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C90D0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x801C90D4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C90D8: jal         0x8012C6B4
    // 0x801C90DC: sb          $v0, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801C90DC: sb          $v0, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r2;
    after_2:
    // 0x801C90E0: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x801C90E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C90E8: lwc1        $f2, -0xC2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XC2C);
    // 0x801C90EC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C90F0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801C90F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C90F8: sb          $v0, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r2;
    // 0x801C90FC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C9100: lw          $a0, 0x30($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X30);
    // 0x801C9104: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801C9108: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x801C910C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x801C9110: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9114: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x801C9118: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C911C: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x801C9120: lwc1        $f0, 0x8($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801C9124: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C9128: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801C912C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x801C9130: bc1f        L_801C9140
    if (!c1cs) {
        // 0x801C9134: swc1        $f10, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
            goto L_801C9140;
    }
    // 0x801C9134: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x801C9138: jal         0x80005700
    // 0x801C913C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C913C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_801C9140:
    // 0x801C9140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C9148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C914C: jr          $ra
    // 0x801C9150: nop

    return;
    // 0x801C9150: nop

;}
RECOMP_FUNC void M23_FUN_801c9154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9154: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C9158: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801C915C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C9160: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801C9164: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C9168: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C916C: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x801C9170: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x801C9174: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C9178: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C917C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C9180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C9184: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801C9188: addiu       $s5, $s5, -0x2E9C
    ctx->r21 = ADD32(ctx->r21, -0X2E9C);
    // 0x801C918C: addiu       $s4, $s4, -0x290
    ctx->r20 = ADD32(ctx->r20, -0X290);
    // 0x801C9190: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C9194: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801C9198: addu        $s2, $s4, $s1
    ctx->r18 = ADD32(ctx->r20, ctx->r17);
L_801C919C:
    // 0x801C919C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x801C91A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C91A4: bnel        $t6, $zero, L_801C91FC
    if (ctx->r14 != 0) {
        // 0x801C91A8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801C91FC;
    }
    goto skip_0;
    // 0x801C91A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x801C91AC: jal         0x80005670
    // 0x801C91B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C91B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x801C91B4: beq         $v0, $zero, L_801C91F4
    if (ctx->r2 == 0) {
        // 0x801C91B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801C91F4;
    }
    // 0x801C91B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801C91BC: sb          $s1, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r17;
    // 0x801C91C0: jal         0x8012C6B4
    // 0x801C91C4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801C91C4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x801C91C8: addiu       $t7, $v0, 0xA
    ctx->r15 = ADD32(ctx->r2, 0XA);
    // 0x801C91CC: sb          $t7, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r15;
    // 0x801C91D0: jal         0x8012C6B4
    // 0x801C91D4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801C91D4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_2:
    // 0x801C91D8: sh          $v0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r2;
    // 0x801C91DC: jal         0x8012C6B4
    // 0x801C91E0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801C91E0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_3:
    // 0x801C91E4: sh          $v0, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r2;
    // 0x801C91E8: jal         0x8012C6B4
    // 0x801C91EC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801C91EC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_4:
    // 0x801C91F0: sh          $v0, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r2;
L_801C91F4:
    // 0x801C91F4: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x801C91F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801C91FC:
    // 0x801C91FC: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C9200: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x801C9204: bnel        $at, $zero, L_801C919C
    if (ctx->r1 != 0) {
        // 0x801C9208: addu        $s2, $s4, $s1
        ctx->r18 = ADD32(ctx->r20, ctx->r17);
            goto L_801C919C;
    }
    goto skip_1;
    // 0x801C9208: addu        $s2, $s4, $s1
    ctx->r18 = ADD32(ctx->r20, ctx->r17);
    skip_1:
    // 0x801C920C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C9210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C9214: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9218: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C921C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C9220: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C9224: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801C9228: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801C922C: jr          $ra
    // 0x801C9230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C9230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9234(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C9238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C923C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C9240: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C9244: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801C9248: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801C924C: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C9250: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9254: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9258: addiu       $a3, $a3, -0x2F0
    ctx->r7 = ADD32(ctx->r7, -0X2F0);
    // 0x801C925C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801C9260: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C9264: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801C9268: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C926C: addiu       $t0, $t0, -0x2C0
    ctx->r8 = ADD32(ctx->r8, -0X2C0);
    // 0x801C9270: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9274: mflo        $t7
    ctx->r15 = lo;
    // 0x801C9278: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x801C927C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x801C9280: lbu         $v1, 0x90($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X90);
    // 0x801C9284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C928C: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C9290: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801C9294: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x801C9298: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x801C929C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C92A0: addiu       $a1, $a1, -0x6CD8
    ctx->r5 = ADD32(ctx->r5, -0X6CD8);
    // 0x801C92A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C92A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C92AC: mflo        $t1
    ctx->r9 = lo;
    // 0x801C92B0: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x801C92B4: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x801C92B8: lbu         $t3, 0x90($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X90);
    // 0x801C92BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C92C0: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C92C4: mflo        $t4
    ctx->r12 = lo;
    // 0x801C92C8: addu        $a2, $a3, $t4
    ctx->r6 = ADD32(ctx->r7, ctx->r12);
    // 0x801C92CC: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801C92D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C92D4: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x801C92D8: lbu         $t5, 0x90($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X90);
    // 0x801C92DC: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C92E0: mflo        $t6
    ctx->r14 = lo;
    // 0x801C92E4: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801C92E8: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x801C92EC: lbu         $t8, 0x90($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X90);
    // 0x801C92F0: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C92F4: mflo        $t9
    ctx->r25 = lo;
    // 0x801C92F8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x801C92FC: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x801C9300: lbu         $t2, 0x90($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X90);
    // 0x801C9304: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C9308: mflo        $t3
    ctx->r11 = lo;
    // 0x801C930C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801C9310: jal         0x800058DC
    // 0x801C9314: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C9314: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    after_0:
    // 0x801C9318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C931C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9320: jr          $ra
    // 0x801C9324: nop

    return;
    // 0x801C9324: nop

;}
RECOMP_FUNC void M23_FUN_801c9328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9328: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C932C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C9330: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C9334: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C9338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C933C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801C9340: lbu         $v0, 0x90($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X90);
    // 0x801C9344: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C9348: lbu         $t0, 0x91($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X91);
    // 0x801C934C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C9350: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x801C9354: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801C9358: addiu       $t7, $t7, -0x2F60
    ctx->r15 = ADD32(ctx->r15, -0X2F60);
    // 0x801C935C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C9360: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C9364: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x801C9368: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x801C936C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801C9370: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x801C9374: addiu       $t9, $t9, -0x2C0
    ctx->r25 = ADD32(ctx->r25, -0X2C0);
    // 0x801C9378: addiu       $t8, $t8, -0x2F0
    ctx->r24 = ADD32(ctx->r24, -0X2F0);
    // 0x801C937C: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x801C9380: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
    // 0x801C9384: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x801C9388: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x801C938C: bgez        $t0, L_801C93A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C9390: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C93A4;
    }
    // 0x801C9390: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C9394: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C9398: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C939C: nop

    // 0x801C93A0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801C93A4:
    // 0x801C93A4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801C93A8: jal         0x801C5C70
    // 0x801C93AC: nop

    LOOKUP_FUNC(0x801C5C70)(rdram, ctx);
        goto after_0;
    // 0x801C93AC: nop

    after_0:
    // 0x801C93B0: lbu         $t1, 0x90($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X90);
    // 0x801C93B4: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C93B8: addiu       $t3, $t3, -0x2F0
    ctx->r11 = ADD32(ctx->r11, -0X2F0);
    // 0x801C93BC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801C93C0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801C93C4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801C93C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C93CC: addiu       $a0, $a0, -0x2F6C
    ctx->r4 = ADD32(ctx->r4, -0X2F6C);
    // 0x801C93D0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x801C93D4: jal         0x801C5CC8
    // 0x801C93D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C5CC8)(rdram, ctx);
        goto after_1;
    // 0x801C93D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x801C93DC: lb          $t4, 0x8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X8);
    // 0x801C93E0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C93E4: addiu       $t0, $t0, -0x2F0
    ctx->r8 = ADD32(ctx->r8, -0X2F0);
    // 0x801C93E8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x801C93EC: sb          $t5, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r13;
    // 0x801C93F0: lb          $t6, 0x9($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X9);
    // 0x801C93F4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C93F8: addiu       $a0, $a0, -0x2F6C
    ctx->r4 = ADD32(ctx->r4, -0X2F6C);
    // 0x801C93FC: sb          $t6, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r14;
    // 0x801C9400: lb          $t7, 0xA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA);
    // 0x801C9404: sb          $t7, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r15;
    // 0x801C9408: lbu         $t8, 0x90($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X90);
    // 0x801C940C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C9410: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801C9414: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801C9418: jal         0x801476E0
    // 0x801C941C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    LOOKUP_FUNC(0x801476E0)(rdram, ctx);
        goto after_2;
    // 0x801C941C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x801C9420: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x801C9424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9428: lh          $t1, 0x94($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X94);
    // 0x801C942C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9430: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C9434: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801C9438: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C943C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C9440: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C9444: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x801C9448: swc1        $f2, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f2.u32l;
    // 0x801C944C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801C9450: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9454: nop

    // 0x801C9458: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C945C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9460: nop

    // 0x801C9464: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9468: beql        $t3, $zero, L_801C94B8
    if (ctx->r11 == 0) {
        // 0x801C946C: mfc1        $t3, $f4
        ctx->r11 = (int32_t)ctx->f4.u32l;
            goto L_801C94B8;
    }
    goto skip_0;
    // 0x801C946C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801C9470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C9474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9478: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C947C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C9480: nop

    // 0x801C9484: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C9488: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C948C: nop

    // 0x801C9490: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801C9494: bne         $t3, $zero, L_801C94AC
    if (ctx->r11 != 0) {
        // 0x801C9498: nop
    
            goto L_801C94AC;
    }
    // 0x801C9498: nop

    // 0x801C949C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801C94A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C94A4: b           L_801C94C4
    // 0x801C94A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801C94C4;
    // 0x801C94A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801C94AC:
    // 0x801C94AC: b           L_801C94C4
    // 0x801C94B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801C94C4;
    // 0x801C94B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801C94B4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
L_801C94B8:
    // 0x801C94B8: nop

    // 0x801C94BC: bltz        $t3, L_801C94AC
    if (SIGNED(ctx->r11) < 0) {
        // 0x801C94C0: nop
    
            goto L_801C94AC;
    }
    // 0x801C94C0: nop

L_801C94C4:
    // 0x801C94C4: sb          $t3, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r11;
    // 0x801C94C8: lh          $t4, 0x96($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X96);
    // 0x801C94CC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801C94D0: lwc1        $f6, 0x9C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x801C94D4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801C94D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C94DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C94E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C94E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C94E8: addiu       $a1, $a1, -0x6988
    ctx->r5 = ADD32(ctx->r5, -0X6988);
    // 0x801C94EC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801C94F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C94F4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C94F8: nop

    // 0x801C94FC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C9500: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C9504: nop

    // 0x801C9508: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C950C: beql        $t6, $zero, L_801C955C
    if (ctx->r14 == 0) {
        // 0x801C9510: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_801C955C;
    }
    goto skip_1;
    // 0x801C9510: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x801C9514: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C9518: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C951C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801C9520: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C9524: nop

    // 0x801C9528: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C952C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C9530: nop

    // 0x801C9534: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C9538: bne         $t6, $zero, L_801C9550
    if (ctx->r14 != 0) {
        // 0x801C953C: nop
    
            goto L_801C9550;
    }
    // 0x801C953C: nop

    // 0x801C9540: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x801C9544: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9548: b           L_801C9568
    // 0x801C954C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C9568;
    // 0x801C954C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C9550:
    // 0x801C9550: b           L_801C9568
    // 0x801C9554: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C9568;
    // 0x801C9554: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C9558: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_801C955C:
    // 0x801C955C: nop

    // 0x801C9560: bltz        $t6, L_801C9550
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C9564: nop
    
            goto L_801C9550;
    }
    // 0x801C9564: nop

L_801C9568:
    // 0x801C9568: sb          $t6, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r14;
    // 0x801C956C: lh          $t7, 0x98($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X98);
    // 0x801C9570: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C9574: lwc1        $f4, 0x9C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x801C9578: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801C957C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C9580: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9584: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C9588: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C958C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C9590: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C9594: nop

    // 0x801C9598: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C959C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C95A0: nop

    // 0x801C95A4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C95A8: beql        $t9, $zero, L_801C95F8
    if (ctx->r25 == 0) {
        // 0x801C95AC: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_801C95F8;
    }
    goto skip_2;
    // 0x801C95AC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801C95B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C95B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C95B8: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C95BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C95C0: nop

    // 0x801C95C4: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C95C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C95CC: nop

    // 0x801C95D0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C95D4: bne         $t9, $zero, L_801C95EC
    if (ctx->r25 != 0) {
        // 0x801C95D8: nop
    
            goto L_801C95EC;
    }
    // 0x801C95D8: nop

    // 0x801C95DC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x801C95E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C95E4: b           L_801C9604
    // 0x801C95E8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801C9604;
    // 0x801C95E8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801C95EC:
    // 0x801C95EC: b           L_801C9604
    // 0x801C95F0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801C9604;
    // 0x801C95F0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C95F4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_801C95F8:
    // 0x801C95F8: nop

    // 0x801C95FC: bltz        $t9, L_801C95EC
    if (SIGNED(ctx->r25) < 0) {
        // 0x801C9600: nop
    
            goto L_801C95EC;
    }
    // 0x801C9600: nop

L_801C9604:
    // 0x801C9604: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C9608: sb          $t9, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r25;
    // 0x801C960C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_801C9610:
    // 0x801C9610: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x801C9614: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x801C9618: addu        $t1, $s1, $v0
    ctx->r9 = ADD32(ctx->r17, ctx->r2);
    // 0x801C961C: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x801C9620: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C9624: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801C9628: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801C962C: sb          $v1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r3;
    // 0x801C9630: bne         $at, $zero, L_801C9610
    if (ctx->r1 != 0) {
        // 0x801C9634: sb          $v1, 0x0($t2)
        MEM_B(0X0, ctx->r10) = ctx->r3;
            goto L_801C9610;
    }
    // 0x801C9634: sb          $v1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r3;
    // 0x801C9638: lwc1        $f18, 0x9C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x801C963C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C9640: ldc1        $f4, -0xC28($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XC28);
    // 0x801C9644: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801C9648: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x801C964C: nop

    // 0x801C9650: bc1fl       L_801C9664
    if (!c1cs) {
        // 0x801C9654: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C9664;
    }
    goto skip_3;
    // 0x801C9654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x801C9658: jal         0x800058DC
    // 0x801C965C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C965C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x801C9660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C9664:
    // 0x801C9664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C9668: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C966C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C9670: jr          $ra
    // 0x801C9674: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801C9674: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9678(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C967C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801C9684: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C9688: lh          $t9, 0x94($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X94);
    // 0x801C968C: lwc1        $f4, 0x9C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x801C9690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C9694: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C9698: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C969C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C96A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C96A4: addiu       $t8, $t8, -0x2F60
    ctx->r24 = ADD32(ctx->r24, -0X2F60);
    // 0x801C96A8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801C96AC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801C96B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801C96B4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x801C96B8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801C96BC: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x801C96C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C96C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C96C8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C96CC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C96D0: nop

    // 0x801C96D4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C96D8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C96DC: nop

    // 0x801C96E0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801C96E4: beql        $t1, $zero, L_801C9734
    if (ctx->r9 == 0) {
        // 0x801C96E8: mfc1        $t1, $f16
        ctx->r9 = (int32_t)ctx->f16.u32l;
            goto L_801C9734;
    }
    goto skip_0;
    // 0x801C96E8: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801C96EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C96F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C96F4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C96F8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C96FC: nop

    // 0x801C9700: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C9704: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C9708: nop

    // 0x801C970C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801C9710: bne         $t1, $zero, L_801C9728
    if (ctx->r9 != 0) {
        // 0x801C9714: nop
    
            goto L_801C9728;
    }
    // 0x801C9714: nop

    // 0x801C9718: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801C971C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9720: b           L_801C9740
    // 0x801C9724: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801C9740;
    // 0x801C9724: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801C9728:
    // 0x801C9728: b           L_801C9740
    // 0x801C972C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801C9740;
    // 0x801C972C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801C9730: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
L_801C9734:
    // 0x801C9734: nop

    // 0x801C9738: bltz        $t1, L_801C9728
    if (SIGNED(ctx->r9) < 0) {
        // 0x801C973C: nop
    
            goto L_801C9728;
    }
    // 0x801C973C: nop

L_801C9740:
    // 0x801C9740: sb          $t1, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r9;
    // 0x801C9744: lh          $t2, 0x96($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X96);
    // 0x801C9748: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C974C: lwc1        $f18, 0x9C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x801C9750: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801C9754: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C9758: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C975C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C9760: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801C9764: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C9768: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C976C: nop

    // 0x801C9770: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C9774: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C9778: nop

    // 0x801C977C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C9780: beql        $t4, $zero, L_801C97D0
    if (ctx->r12 == 0) {
        // 0x801C9784: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_801C97D0;
    }
    goto skip_1;
    // 0x801C9784: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801C9788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C978C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C9790: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C9794: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C9798: nop

    // 0x801C979C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C97A0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C97A4: nop

    // 0x801C97A8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C97AC: bne         $t4, $zero, L_801C97C4
    if (ctx->r12 != 0) {
        // 0x801C97B0: nop
    
            goto L_801C97C4;
    }
    // 0x801C97B0: nop

    // 0x801C97B4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801C97B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C97BC: b           L_801C97DC
    // 0x801C97C0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C97DC;
    // 0x801C97C0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C97C4:
    // 0x801C97C4: b           L_801C97DC
    // 0x801C97C8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C97DC;
    // 0x801C97C8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C97CC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_801C97D0:
    // 0x801C97D0: nop

    // 0x801C97D4: bltz        $t4, L_801C97C4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C97D8: nop
    
            goto L_801C97C4;
    }
    // 0x801C97D8: nop

L_801C97DC:
    // 0x801C97DC: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x801C97E0: lh          $t5, 0x98($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X98);
    // 0x801C97E4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C97E8: lwc1        $f16, 0x9C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x801C97EC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801C97F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C97F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C97F8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C97FC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801C9800: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C9804: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C9808: nop

    // 0x801C980C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C9810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C9814: nop

    // 0x801C9818: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C981C: beql        $t7, $zero, L_801C986C
    if (ctx->r15 == 0) {
        // 0x801C9820: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_801C986C;
    }
    goto skip_2;
    // 0x801C9820: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801C9824: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9828: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C982C: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801C9830: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C9834: nop

    // 0x801C9838: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C983C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C9840: nop

    // 0x801C9844: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C9848: bne         $t7, $zero, L_801C9860
    if (ctx->r15 != 0) {
        // 0x801C984C: nop
    
            goto L_801C9860;
    }
    // 0x801C984C: nop

    // 0x801C9850: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801C9854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9858: b           L_801C9878
    // 0x801C985C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801C9878;
    // 0x801C985C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801C9860:
    // 0x801C9860: b           L_801C9878
    // 0x801C9864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801C9878;
    // 0x801C9864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C9868: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_801C986C:
    // 0x801C986C: nop

    // 0x801C9870: bltz        $t7, L_801C9860
    if (SIGNED(ctx->r15) < 0) {
        // 0x801C9874: nop
    
            goto L_801C9860;
    }
    // 0x801C9874: nop

L_801C9878:
    // 0x801C9878: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C987C: sb          $t7, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r15;
    // 0x801C9880: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_801C9884:
    // 0x801C9884: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x801C9888: lbu         $v1, 0x0($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X0);
    // 0x801C988C: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x801C9890: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x801C9894: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C9898: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801C989C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801C98A0: sb          $v1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r3;
    // 0x801C98A4: bne         $at, $zero, L_801C9884
    if (ctx->r1 != 0) {
        // 0x801C98A8: sb          $v1, 0x0($t0)
        MEM_B(0X0, ctx->r8) = ctx->r3;
            goto L_801C9884;
    }
    // 0x801C98A8: sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
    // 0x801C98AC: lwc1        $f10, 0x9C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x801C98B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C98B4: ldc1        $f16, -0xC20($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0XC20);
    // 0x801C98B8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C98BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C98C0: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x801C98C4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801C98C8: swc1        $f4, 0x9C($a1)
    MEM_W(0X9C, ctx->r5) = ctx->f4.u32l;
    // 0x801C98CC: lwc1        $f8, 0x9C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x801C98D0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801C98D4: nop

    // 0x801C98D8: bc1fl       L_801C98FC
    if (!c1cs) {
        // 0x801C98DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C98FC;
    }
    goto skip_3;
    // 0x801C98DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801C98E0: lbu         $t1, 0x90($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X90);
    // 0x801C98E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C98E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801C98EC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801C98F0: jal         0x80005700
    // 0x801C98F4: sb          $zero, -0x290($at)
    MEM_B(-0X290, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C98F4: sb          $zero, -0x290($at)
    MEM_B(-0X290, ctx->r1) = 0;
    after_0:
    // 0x801C98F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C98FC:
    // 0x801C98FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C9900: jr          $ra
    // 0x801C9904: nop

    return;
    // 0x801C9904: nop

;}
RECOMP_FUNC void M23_FUN_801c9908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9908: nop

    // 0x801C990C: nop

;}
RECOMP_FUNC void M23_FUN_801c9910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9910: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C9914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C9918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C991C: lh          $t6, 0x26($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X26);
    // 0x801C9920: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801C9924: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C9928: addiu       $t7, $t6, 0x78
    ctx->r15 = ADD32(ctx->r14, 0X78);
    // 0x801C992C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C9930: nop

    // 0x801C9934: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C9938: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x801C993C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801C9940: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801C9944: nop

    // 0x801C9948: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C994C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C9950: slti        $at, $a2, -0x14
    ctx->r1 = SIGNED(ctx->r6) < -0X14 ? 1 : 0;
    // 0x801C9954: beql        $at, $zero, L_801C9994
    if (ctx->r1 == 0) {
        // 0x801C9958: slti        $at, $a2, 0xF0
        ctx->r1 = SIGNED(ctx->r6) < 0XF0 ? 1 : 0;
            goto L_801C9994;
    }
    goto skip_0;
    // 0x801C9958: slti        $at, $a2, 0xF0
    ctx->r1 = SIGNED(ctx->r6) < 0XF0 ? 1 : 0;
    skip_0:
    // 0x801C995C: lbu         $t9, 0x2A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2A);
    // 0x801C9960: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C9964: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C9968: bne         $t9, $at, L_801C9A10
    if (ctx->r25 != ctx->r1) {
        // 0x801C996C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801C9A10;
    }
    // 0x801C996C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C9970: sb          $t0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r8;
    // 0x801C9974: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9978: addiu       $a3, $a3, -0xC10
    ctx->r7 = ADD32(ctx->r7, -0XC10);
    // 0x801C997C: lbu         $a0, 0x22($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X22);
    // 0x801C9980: jal         0x8001B204
    // 0x801C9984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C9984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801C9988: b           L_801C9A14
    // 0x801C998C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C9A14;
    // 0x801C998C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C9990: slti        $at, $a2, 0xF0
    ctx->r1 = SIGNED(ctx->r6) < 0XF0 ? 1 : 0;
L_801C9994:
    // 0x801C9994: beql        $at, $zero, L_801C9A14
    if (ctx->r1 == 0) {
        // 0x801C9998: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C9A14;
    }
    goto skip_1;
    // 0x801C9998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801C999C: lbu         $t1, 0x2A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2A);
    // 0x801C99A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C99A4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x801C99A8: bnel        $t1, $zero, L_801C99DC
    if (ctx->r9 != 0) {
        // 0x801C99AC: slti        $at, $a2, 0x8
        ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
            goto L_801C99DC;
    }
    goto skip_2;
    // 0x801C99AC: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    skip_2:
    // 0x801C99B0: lbu         $t3, 0x28($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X28);
    // 0x801C99B4: sb          $t2, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r10;
    // 0x801C99B8: lbu         $a0, 0x22($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X22);
    // 0x801C99BC: lh          $a1, 0x24($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X24);
    // 0x801C99C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C99C4: lbu         $t4, 0x29($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X29);
    // 0x801C99C8: sh          $a2, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r6;
    // 0x801C99CC: jal         0x8001B204
    // 0x801C99D0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C99D0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x801C99D4: lh          $a2, 0x2C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2C);
    // 0x801C99D8: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
L_801C99DC:
    // 0x801C99DC: beq         $at, $zero, L_801C99EC
    if (ctx->r1 == 0) {
        // 0x801C99E0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_801C99EC;
    }
    // 0x801C99E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C99E4: addiu       $a3, $a2, -0x8
    ctx->r7 = ADD32(ctx->r6, -0X8);
    // 0x801C99E8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_801C99EC:
    // 0x801C99EC: addiu       $t5, $a2, 0xD
    ctx->r13 = ADD32(ctx->r6, 0XD);
    // 0x801C99F0: slti        $at, $t5, 0xEF
    ctx->r1 = SIGNED(ctx->r13) < 0XEF ? 1 : 0;
    // 0x801C99F4: bnel        $at, $zero, L_801C9A08
    if (ctx->r1 != 0) {
        // 0x801C99F8: lbu         $a0, 0x22($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X22);
            goto L_801C9A08;
    }
    goto skip_3;
    // 0x801C99F8: lbu         $a0, 0x22($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X22);
    skip_3:
    // 0x801C99FC: addiu       $a3, $a2, -0xE1
    ctx->r7 = ADD32(ctx->r6, -0XE1);
    // 0x801C9A00: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801C9A04: lbu         $a0, 0x22($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X22);
L_801C9A08:
    // 0x801C9A08: jal         0x8001B194
    // 0x801C9A0C: lh          $a1, 0x24($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X24);
    LOOKUP_FUNC(0x8001B194)(rdram, ctx);
        goto after_2;
    // 0x801C9A0C: lh          $a1, 0x24($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X24);
    after_2:
L_801C9A10:
    // 0x801C9A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C9A14:
    // 0x801C9A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C9A18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C9A1C: jr          $ra
    // 0x801C9A20: nop

    return;
    // 0x801C9A20: nop

;}
RECOMP_FUNC void M23_FUN_801c9a24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9A24: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801C9A28: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C9A2C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801C9A30: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801C9A34: jal         0x80116E80
    // 0x801C9A38: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x801C9A38: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x801C9A3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9A40: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x801C9A44: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x801C9A48: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801C9A4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C9A50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9A54: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801C9A58: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801C9A5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C9A60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C9A64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C9A68: addiu       $a1, $a1, -0xC0C
    ctx->r5 = ADD32(ctx->r5, -0XC0C);
    // 0x801C9A6C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C9A70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801C9A74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801C9A78: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C9A7C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C9A80: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C9A84: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801C9A88: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801C9A8C: jal         0x8001A804
    // 0x801C9A90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x801C9A90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_1:
    // 0x801C9A94: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9A98: addiu       $a1, $a1, -0x654C
    ctx->r5 = ADD32(ctx->r5, -0X654C);
    // 0x801C9A9C: jal         0x800058DC
    // 0x801C9AA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C9AA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x801C9AA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801C9AA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801C9AAC: jr          $ra
    // 0x801C9AB0: nop

    return;
    // 0x801C9AB0: nop

;}
RECOMP_FUNC void M23_FUN_801c9ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9AB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C9AB8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C9ABC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801C9AC0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801C9AC4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C9AC8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801C9ACC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801C9AD0: jal         0x80006214
    // 0x801C9AD4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C9AD4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_0:
    // 0x801C9AD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C9ADC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C9AE0: addiu       $s1, $sp, 0x53
    ctx->r17 = ADD32(ctx->r29, 0X53);
L_801C9AE4:
    // 0x801C9AE4: sll         $a3, $v1, 6
    ctx->r7 = S32(ctx->r3 << 6);
    // 0x801C9AE8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801C9AEC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C9AF0: addiu       $t6, $zero, 0xC4
    ctx->r14 = ADD32(0, 0XC4);
    // 0x801C9AF4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801C9AF8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x801C9AFC: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801C9B00: addiu       $t0, $v1, 0x15
    ctx->r8 = ADD32(ctx->r3, 0X15);
    // 0x801C9B04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801C9B08: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801C9B0C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801C9B10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C9B14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C9B18: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C9B1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C9B20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C9B24: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C9B28: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C9B2C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C9B30: jal         0x80146208
    // 0x801C9B34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x801C9B34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_1:
    // 0x801C9B38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C9B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C9B40: jal         0x80145348
    // 0x801C9B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x801C9B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801C9B48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C9B4C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C9B50: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801C9B54: bne         $at, $zero, L_801C9AE4
    if (ctx->r1 != 0) {
        // 0x801C9B58: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_801C9AE4;
    }
    // 0x801C9B58: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801C9B5C: sll         $a3, $v1, 6
    ctx->r7 = S32(ctx->r3 << 6);
    // 0x801C9B60: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801C9B64: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801C9B68: addiu       $t1, $zero, 0xC4
    ctx->r9 = ADD32(0, 0XC4);
    // 0x801C9B6C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801C9B70: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801C9B74: addiu       $t4, $zero, 0x228
    ctx->r12 = ADD32(0, 0X228);
    // 0x801C9B78: addiu       $t5, $v1, 0x15
    ctx->r13 = ADD32(ctx->r3, 0X15);
    // 0x801C9B7C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801C9B80: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801C9B84: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801C9B88: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801C9B8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C9B90: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C9B94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C9B98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801C9B9C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C9BA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C9BA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C9BA8: jal         0x80146208
    // 0x801C9BAC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x801C9BAC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_3:
    // 0x801C9BB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C9BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C9BB8: jal         0x80145348
    // 0x801C9BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x801C9BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801C9BC0: jal         0x80006214
    // 0x801C9BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801C9BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x801C9BC8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801C9BCC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801C9BD0: blez        $t6, L_801C9C0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801C9BD4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801C9C0C;
    }
    // 0x801C9BD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C9BD8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801C9BDC: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
L_801C9BE0:
    // 0x801C9BE0: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801C9BE4: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x801C9BE8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C9BEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C9BF0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C9BF4: sh          $v1, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r3;
    // 0x801C9BF8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C9BFC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801C9C00: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C9C04: bne         $at, $zero, L_801C9BE0
    if (ctx->r1 != 0) {
        // 0x801C9C08: sb          $zero, 0xB($t0)
        MEM_B(0XB, ctx->r8) = 0;
            goto L_801C9BE0;
    }
    // 0x801C9C08: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
L_801C9C0C:
    // 0x801C9C0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C9C10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C9C14: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9C18: addiu       $a1, $a1, -0x63BC
    ctx->r5 = ADD32(ctx->r5, -0X63BC);
    // 0x801C9C1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801C9C20: jal         0x800058DC
    // 0x801C9C24: swc1        $f4, -0x230($at)
    MEM_W(-0X230, ctx->r1) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C9C24: swc1        $f4, -0x230($at)
    MEM_W(-0X230, ctx->r1) = ctx->f4.u32l;
    after_6:
    // 0x801C9C28: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801C9C2C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801C9C30: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801C9C34: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x801C9C38: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x801C9C3C: jr          $ra
    // 0x801C9C40: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801C9C40: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9c44(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9c44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C9C48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C9C4C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C9C50: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801C9C54: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C9C58: addiu       $s1, $s1, -0x22C
    ctx->r17 = ADD32(ctx->r17, -0X22C);
    // 0x801C9C5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801C9C60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C9C64: addiu       $t6, $t6, -0x2DC8
    ctx->r14 = ADD32(ctx->r14, -0X2DC8);
    // 0x801C9C68: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801C9C6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C9C70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C9C74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C9C78: addiu       $s2, $s2, -0x230
    ctx->r18 = ADD32(ctx->r18, -0X230);
    // 0x801C9C7C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801C9C80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C9C84: addiu       $s3, $zero, 0x64
    ctx->r19 = ADD32(0, 0X64);
L_801C9C88:
    // 0x801C9C88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801C9C8C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x801C9C90: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801C9C94: jalr        $t9
    // 0x801C9C98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801C9C98: nop

    after_0:
    // 0x801C9C9C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C9CA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C9CA4: addiu       $t8, $t7, 0x2C
    ctx->r24 = ADD32(ctx->r15, 0X2C);
    // 0x801C9CA8: bne         $s0, $s3, L_801C9C88
    if (ctx->r16 != ctx->r19) {
        // 0x801C9CAC: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_801C9C88;
    }
    // 0x801C9CAC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801C9CB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C9CB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C9CB8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C9CBC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C9CC0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9CC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C9CC8: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x801C9CCC: lwc1        $f16, -0x9EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X9EC);
    // 0x801C9CD0: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C9CD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C9CD8: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801C9CDC: nop

    // 0x801C9CE0: bc1fl       L_801C9CF4
    if (!c1cs) {
        // 0x801C9CE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801C9CF4;
    }
    goto skip_0;
    // 0x801C9CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801C9CE8: jal         0x800058DC
    // 0x801C9CEC: addiu       $a1, $a1, -0x62F4
    ctx->r5 = ADD32(ctx->r5, -0X62F4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C9CEC: addiu       $a1, $a1, -0x62F4
    ctx->r5 = ADD32(ctx->r5, -0X62F4);
    after_1:
    // 0x801C9CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C9CF4:
    // 0x801C9CF4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C9CF8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C9CFC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9D00: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801C9D04: jr          $ra
    // 0x801C9D08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C9D08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9d0c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9d0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9D0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C9D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9D14: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C9D18: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C9D1C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801C9D20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9D24: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801C9D28: lbu         $v0, 0xB($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0XB);
    // 0x801C9D2C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x801C9D30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801C9D34: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801C9D38: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801C9D3C: bnel        $at, $zero, L_801C9D94
    if (ctx->r1 != 0) {
        // 0x801C9D40: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_801C9D94;
    }
    goto skip_0;
    // 0x801C9D40: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x801C9D44: sh          $t8, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r24;
    // 0x801C9D48: lbu         $t9, -0x40C3($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X40C3);
    // 0x801C9D4C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9D50: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801C9D54: bne         $t9, $zero, L_801C9D7C
    if (ctx->r25 != 0) {
        // 0x801C9D58: addiu       $a1, $a1, -0x6208
        ctx->r5 = ADD32(ctx->r5, -0X6208);
            goto L_801C9D7C;
    }
    // 0x801C9D58: addiu       $a1, $a1, -0x6208
    ctx->r5 = ADD32(ctx->r5, -0X6208);
    // 0x801C9D5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9D60: addiu       $a1, $a1, -0x60DC
    ctx->r5 = ADD32(ctx->r5, -0X60DC);
    // 0x801C9D64: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x801C9D68: jal         0x800058DC
    // 0x801C9D6C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C9D6C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C9D70: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x801C9D74: b           L_801C9D90
    // 0x801C9D78: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
        goto L_801C9D90;
    // 0x801C9D78: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_801C9D7C:
    // 0x801C9D7C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x801C9D80: jal         0x800058DC
    // 0x801C9D84: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C9D84: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x801C9D88: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x801C9D8C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_801C9D90:
    // 0x801C9D90: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
L_801C9D94:
    // 0x801C9D94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C9D98: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C9D9C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C9DA0: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x801C9DA4: sb          $v0, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r2;
    // 0x801C9DA8: addu        $v0, $a2, $t2
    ctx->r2 = ADD32(ctx->r6, ctx->r10);
    // 0x801C9DAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C9DB0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9DB4: sb          $v1, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r3;
    // 0x801C9DB8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x801C9DBC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9DC0: sb          $v1, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r3;
    // 0x801C9DC4: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x801C9DC8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9DCC: sb          $v1, 0xB($t8)
    MEM_B(0XB, ctx->r24) = ctx->r3;
    // 0x801C9DD0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x801C9DD4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C9DD8: sb          $v1, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r3;
    // 0x801C9DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C9DE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C9DE4: jr          $ra
    // 0x801C9DE8: nop

    return;
    // 0x801C9DE8: nop

;}
RECOMP_FUNC void M23_FUN_801c9dec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9DEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C9DF0: jr          $ra
    // 0x801C9DF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C9DF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9df8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9df8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9DF8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C9DFC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C9E00: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801C9E04: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801C9E08: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C9E0C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C9E10: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C9E14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C9E18: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9E1C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x801C9E20: bne         $v0, $zero, L_801C9F08
    if (ctx->r2 != 0) {
        // 0x801C9E24: lbu         $s1, 0xB($t7)
        ctx->r17 = MEM_BU(ctx->r15, 0XB);
            goto L_801C9F08;
    }
    // 0x801C9E24: lbu         $s1, 0xB($t7)
    ctx->r17 = MEM_BU(ctx->r15, 0XB);
    // 0x801C9E28: addiu       $s1, $s1, -0x6
    ctx->r17 = ADD32(ctx->r17, -0X6);
    // 0x801C9E2C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x801C9E30: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x801C9E34: bgez        $s1, L_801C9E64
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801C9E38: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_801C9E64;
    }
    // 0x801C9E38: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801C9E3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C9E40: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
    // 0x801C9E44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C9E48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C9E4C: jal         0x8012FE50
    // 0x801C9E50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C9E50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x801C9E54: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9E58: addiu       $a1, $a1, -0x6214
    ctx->r5 = ADD32(ctx->r5, -0X6214);
    // 0x801C9E5C: jal         0x800058DC
    // 0x801C9E60: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C9E60: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
L_801C9E64:
    // 0x801C9E64: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801C9E68: subu        $v0, $t2, $s1
    ctx->r2 = SUB32(ctx->r10, ctx->r17);
    // 0x801C9E6C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9E70: addiu       $t9, $zero, 0x130
    ctx->r25 = ADD32(0, 0X130);
    // 0x801C9E74: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x801C9E78: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801C9E7C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801C9E80: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801C9E84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C9E88: addiu       $a1, $a1, -0xBE4
    ctx->r5 = ADD32(ctx->r5, -0XBE4);
    // 0x801C9E8C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801C9E90: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x801C9E94: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C9E98: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801C9E9C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801C9EA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C9EA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C9EA8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C9EAC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801C9EB0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801C9EB4: jal         0x8001A804
    // 0x801C9EB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x801C9EB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x801C9EBC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9EC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C9EC4: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x801C9EC8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9ECC: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x801C9ED0: sb          $s1, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r17;
    // 0x801C9ED4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C9ED8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9EDC: sb          $s1, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r17;
    // 0x801C9EE0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x801C9EE4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C9EE8: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x801C9EEC: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x801C9EF0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C9EF4: sb          $s1, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r17;
    // 0x801C9EF8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x801C9EFC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9F00: b           L_801C9F10
    // 0x801C9F04: sb          $s1, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r17;
        goto L_801C9F10;
    // 0x801C9F04: sb          $s1, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r17;
L_801C9F08:
    // 0x801C9F08: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801C9F0C: sh          $t4, 0x3C($t5)
    MEM_H(0X3C, ctx->r13) = ctx->r12;
L_801C9F10:
    // 0x801C9F10: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C9F14: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801C9F18: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801C9F1C: jr          $ra
    // 0x801C9F20: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801C9F20: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c9f24(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c9f24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9F24: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C9F28: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C9F2C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801C9F30: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C9F34: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801C9F38: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C9F3C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9F40: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801C9F44: bne         $v0, $zero, L_801CA250
    if (ctx->r2 != 0) {
        // 0x801C9F48: lbu         $v1, 0xB($t7)
        ctx->r3 = MEM_BU(ctx->r15, 0XB);
            goto L_801CA250;
    }
    // 0x801C9F48: lbu         $v1, 0xB($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0XB);
    // 0x801C9F4C: addiu       $v1, $v1, -0x6
    ctx->r3 = ADD32(ctx->r3, -0X6);
    // 0x801C9F50: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801C9F54: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801C9F58: bgez        $v1, L_801CA1A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801C9F5C: sh          $v1, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r3;
            goto L_801CA1A4;
    }
    // 0x801C9F5C: sh          $v1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r3;
    // 0x801C9F60: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x801C9F64: jal         0x801CA530
    // 0x801C9F68: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801CA530)(rdram, ctx);
        goto after_0;
    // 0x801C9F68: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x801C9F6C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9F70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C9F74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C9F78: addiu       $a3, $a3, -0xBBC
    ctx->r7 = ADD32(ctx->r7, -0XBBC);
    // 0x801C9F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C9F80: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801C9F84: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x801C9F88: jal         0x8001B204
    // 0x801C9F8C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C9F8C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x801C9F90: jal         0x801CA630
    // 0x801C9F94: nop

    LOOKUP_FUNC(0x801CA630)(rdram, ctx);
        goto after_2;
    // 0x801C9F94: nop

    after_2:
    // 0x801C9F98: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9F9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C9FA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C9FA4: addiu       $a3, $a3, -0xBA0
    ctx->r7 = ADD32(ctx->r7, -0XBA0);
    // 0x801C9FA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C9FAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801C9FB0: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x801C9FB4: jal         0x8001B204
    // 0x801C9FB8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C9FB8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x801C9FBC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9FC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C9FC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C9FC8: addiu       $a3, $a3, -0xB80
    ctx->r7 = ADD32(ctx->r7, -0XB80);
    // 0x801C9FCC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C9FD0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801C9FD4: jal         0x8001B204
    // 0x801C9FD8: addiu       $a2, $zero, 0x47
    ctx->r6 = ADD32(0, 0X47);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C9FD8: addiu       $a2, $zero, 0x47
    ctx->r6 = ADD32(0, 0X47);
    after_4:
    // 0x801C9FDC: jal         0x801CA5AC
    // 0x801C9FE0: nop

    LOOKUP_FUNC(0x801CA5AC)(rdram, ctx);
        goto after_5;
    // 0x801C9FE0: nop

    after_5:
    // 0x801C9FE4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C9FE8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C9FEC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C9FF0: addiu       $a3, $a3, -0xB64
    ctx->r7 = ADD32(ctx->r7, -0XB64);
    // 0x801C9FF4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C9FF8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C9FFC: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x801CA000: jal         0x8001B204
    // 0x801CA004: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801CA004: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    // 0x801CA008: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801CA00C: lhu         $v1, -0x4406($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X4406);
    // 0x801CA010: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA014: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801CA018: sra         $t3, $v1, 6
    ctx->r11 = S32(SIGNED(ctx->r3) >> 6);
    // 0x801CA01C: andi        $t4, $v1, 0x3F
    ctx->r12 = ctx->r3 & 0X3F;
    // 0x801CA020: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801CA024: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801CA028: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CA02C: addiu       $a3, $a3, -0xB5C
    ctx->r7 = ADD32(ctx->r7, -0XB5C);
    // 0x801CA030: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801CA034: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA038: jal         0x8001B204
    // 0x801CA03C: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801CA03C: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    after_7:
    // 0x801CA040: jal         0x801CA590
    // 0x801CA044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_8;
    // 0x801CA044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x801CA048: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA04C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CA050: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801CA054: addiu       $a3, $a3, -0xB3C
    ctx->r7 = ADD32(ctx->r7, -0XB3C);
    // 0x801CA058: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801CA05C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA060: addiu       $a2, $zero, 0x71
    ctx->r6 = ADD32(0, 0X71);
    // 0x801CA064: jal         0x8001B204
    // 0x801CA068: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801CA068: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_9:
    // 0x801CA06C: jal         0x801CA590
    // 0x801CA070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_10;
    // 0x801CA070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x801CA074: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA078: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA07C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CA080: addiu       $a3, $a3, -0xB20
    ctx->r7 = ADD32(ctx->r7, -0XB20);
    // 0x801CA084: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801CA088: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA08C: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x801CA090: jal         0x8001B204
    // 0x801CA094: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801CA094: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_11:
    // 0x801CA098: jal         0x801CA590
    // 0x801CA09C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_12;
    // 0x801CA09C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x801CA0A0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA0A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CA0A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CA0AC: addiu       $a3, $a3, -0xB04
    ctx->r7 = ADD32(ctx->r7, -0XB04);
    // 0x801CA0B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801CA0B4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA0B8: addiu       $a2, $zero, 0x8D
    ctx->r6 = ADD32(0, 0X8D);
    // 0x801CA0BC: jal         0x8001B204
    // 0x801CA0C0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801CA0C0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_13:
    // 0x801CA0C4: jal         0x801CA590
    // 0x801CA0C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_14;
    // 0x801CA0C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x801CA0CC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA0D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CA0D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801CA0D8: addiu       $a3, $a3, -0xAE8
    ctx->r7 = ADD32(ctx->r7, -0XAE8);
    // 0x801CA0DC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801CA0E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA0E4: addiu       $a2, $zero, 0x9B
    ctx->r6 = ADD32(0, 0X9B);
    // 0x801CA0E8: jal         0x8001B204
    // 0x801CA0EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801CA0EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_15:
    // 0x801CA0F0: jal         0x801CA590
    // 0x801CA0F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_16;
    // 0x801CA0F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_16:
    // 0x801CA0F8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA0FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA100: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801CA104: addiu       $a3, $a3, -0xACC
    ctx->r7 = ADD32(ctx->r7, -0XACC);
    // 0x801CA108: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801CA10C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA110: addiu       $a2, $zero, 0xA9
    ctx->r6 = ADD32(0, 0XA9);
    // 0x801CA114: jal         0x8001B204
    // 0x801CA118: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_17;
    // 0x801CA118: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_17:
    // 0x801CA11C: jal         0x801CA590
    // 0x801CA120: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_18;
    // 0x801CA120: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_18:
    // 0x801CA124: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA128: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CA12C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CA130: addiu       $a3, $a3, -0xAB0
    ctx->r7 = ADD32(ctx->r7, -0XAB0);
    // 0x801CA134: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801CA138: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA13C: addiu       $a2, $zero, 0xB7
    ctx->r6 = ADD32(0, 0XB7);
    // 0x801CA140: jal         0x8001B204
    // 0x801CA144: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_19;
    // 0x801CA144: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_19:
    // 0x801CA148: jal         0x801CA590
    // 0x801CA14C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801CA590)(rdram, ctx);
        goto after_20;
    // 0x801CA14C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_20:
    // 0x801CA150: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA154: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CA158: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801CA15C: addiu       $a3, $a3, -0xA94
    ctx->r7 = ADD32(ctx->r7, -0XA94);
    // 0x801CA160: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801CA164: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801CA168: addiu       $a2, $zero, 0xC5
    ctx->r6 = ADD32(0, 0XC5);
    // 0x801CA16C: jal         0x8001B204
    // 0x801CA170: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_21;
    // 0x801CA170: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_21:
    // 0x801CA174: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA178: addiu       $a3, $a3, -0xA78
    ctx->r7 = ADD32(ctx->r7, -0XA78);
    // 0x801CA17C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801CA180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CA184: jal         0x8001B204
    // 0x801CA188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_22;
    // 0x801CA188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x801CA18C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x801CA190: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801CA194: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA198: addiu       $a1, $a1, -0x5D7C
    ctx->r5 = ADD32(ctx->r5, -0X5D7C);
    // 0x801CA19C: jal         0x800058DC
    // 0x801CA1A0: sh          $t2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_23;
    // 0x801CA1A0: sh          $t2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r10;
    after_23:
L_801CA1A4:
    // 0x801CA1A4: lh          $v1, 0x52($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X52);
    // 0x801CA1A8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CA1AC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA1B0: addiu       $t3, $zero, 0x130
    ctx->r11 = ADD32(0, 0X130);
    // 0x801CA1B4: addiu       $t4, $zero, 0xE0
    ctx->r12 = ADD32(0, 0XE0);
    // 0x801CA1B8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801CA1BC: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x801CA1C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801CA1C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x801CA1C8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801CA1CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CA1D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801CA1D4: addiu       $a1, $a1, -0xA74
    ctx->r5 = ADD32(ctx->r5, -0XA74);
    // 0x801CA1D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801CA1DC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CA1E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CA1E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA1E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA1EC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA1F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CA1F4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CA1F8: jal         0x8001A804
    // 0x801CA1FC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_24;
    // 0x801CA1FC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_24:
    // 0x801CA200: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CA204: lh          $v1, 0x52($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X52);
    // 0x801CA208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801CA20C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CA210: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x801CA214: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x801CA218: sb          $v1, 0xB($t8)
    MEM_B(0XB, ctx->r24) = ctx->r3;
    // 0x801CA21C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801CA220: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CA224: sb          $v1, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r3;
    // 0x801CA228: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x801CA22C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CA230: sb          $v1, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r3;
    // 0x801CA234: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x801CA238: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CA23C: sb          $v1, 0xB($t5)
    MEM_B(0XB, ctx->r13) = ctx->r3;
    // 0x801CA240: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801CA244: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA248: b           L_801CA270
    // 0x801CA24C: sb          $v1, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r3;
        goto L_801CA270;
    // 0x801CA24C: sb          $v1, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r3;
L_801CA250:
    // 0x801CA250: lhu         $t8, -0x6B88($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6B88);
    // 0x801CA254: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801CA258: andi        $t9, $t8, 0xF000
    ctx->r25 = ctx->r24 & 0XF000;
    // 0x801CA25C: beql        $t9, $zero, L_801CA270
    if (ctx->r25 == 0) {
        // 0x801CA260: sh          $t0, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r8;
            goto L_801CA270;
    }
    goto skip_0;
    // 0x801CA260: sh          $t0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r8;
    skip_0:
    // 0x801CA264: b           L_801CA270
    // 0x801CA268: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
        goto L_801CA270;
    // 0x801CA268: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x801CA26C: sh          $t0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r8;
L_801CA270:
    // 0x801CA270: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CA274: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801CA278: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801CA27C: jr          $ra
    // 0x801CA280: nop

    return;
    // 0x801CA280: nop

;}
RECOMP_FUNC void M23_FUN_801ca284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA284: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CA288: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CA28C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801CA290: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801CA294: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801CA298: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA29C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CA2A0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801CA2A4: beq         $at, $zero, L_801CA2B4
    if (ctx->r1 == 0) {
        // 0x801CA2A8: addiu       $a1, $a1, -0xA4C
        ctx->r5 = ADD32(ctx->r5, -0XA4C);
            goto L_801CA2B4;
    }
    // 0x801CA2A8: addiu       $a1, $a1, -0xA4C
    ctx->r5 = ADD32(ctx->r5, -0XA4C);
    // 0x801CA2AC: b           L_801CA2BC
    // 0x801CA2B0: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
        goto L_801CA2BC;
    // 0x801CA2B0: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
L_801CA2B4:
    // 0x801CA2B4: addiu       $t6, $v0, -0x6
    ctx->r14 = ADD32(ctx->r2, -0X6);
    // 0x801CA2B8: sh          $t6, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r14;
L_801CA2BC:
    // 0x801CA2BC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
    // 0x801CA2C0: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x801CA2C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CA2C8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CA2CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CA2D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CA2D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA2D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA2DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA2E0: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801CA2E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CA2E8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CA2EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CA2F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801CA2F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CA2F8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CA2FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801CA300: jal         0x8001A804
    // 0x801CA304: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_0;
    // 0x801CA304: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_0:
    // 0x801CA308: lhu         $t0, 0x3C($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X3C);
    // 0x801CA30C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA310: addiu       $a1, $a1, -0xA24
    ctx->r5 = ADD32(ctx->r5, -0XA24);
    // 0x801CA314: bne         $t0, $zero, L_801CA344
    if (ctx->r8 != 0) {
        // 0x801CA318: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_801CA344;
    }
    // 0x801CA318: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801CA31C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CA320: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CA324: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801CA328: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801CA32C: jal         0x8001A804
    // 0x801CA330: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_1;
    // 0x801CA330: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x801CA334: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA338: addiu       $a1, $a1, -0x5CA8
    ctx->r5 = ADD32(ctx->r5, -0X5CA8);
    // 0x801CA33C: jal         0x800058DC
    // 0x801CA340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CA340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_801CA344:
    // 0x801CA344: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CA348: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801CA34C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801CA350: jr          $ra
    // 0x801CA354: nop

    return;
    // 0x801CA354: nop

;}
RECOMP_FUNC void M23_FUN_801ca358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA358: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801CA35C: lhu         $t6, -0x6B88($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6B88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca360(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CA364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CA368: andi        $t7, $t6, 0xF000
    ctx->r15 = ctx->r14 & 0XF000;
    // 0x801CA36C: beq         $t7, $zero, L_801CA384
    if (ctx->r15 == 0) {
        // 0x801CA370: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801CA384;
    }
    // 0x801CA370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CA374: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA378: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x801CA37C: jal         0x800058DC
    // 0x801CA380: addiu       $a1, $a1, -0x5C68
    ctx->r5 = ADD32(ctx->r5, -0X5C68);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801CA380: addiu       $a1, $a1, -0x5C68
    ctx->r5 = ADD32(ctx->r5, -0X5C68);
    after_0:
L_801CA384:
    // 0x801CA384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CA388: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CA38C: sh          $zero, -0x4404($at)
    MEM_H(-0X4404, ctx->r1) = 0;
    // 0x801CA390: jr          $ra
    // 0x801CA394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CA394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca398(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA398: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CA39C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801CA3A0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801CA3A4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801CA3A8: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801CA3AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CA3B0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801CA3B4: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x801CA3B8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801CA3BC: bne         $at, $zero, L_801CA3F0
    if (ctx->r1 != 0) {
        // 0x801CA3C0: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_801CA3F0;
    }
    // 0x801CA3C0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801CA3C4: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801CA3C8: jal         0x80005670
    // 0x801CA3CC: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801CA3CC: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_0:
    // 0x801CA3D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA3D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA3D8: sw          $v0, -0x2DCC($at)
    MEM_W(-0X2DCC, ctx->r1) = ctx->r2;
    // 0x801CA3DC: addiu       $a1, $a1, -0x5BA4
    ctx->r5 = ADD32(ctx->r5, -0X5BA4);
    // 0x801CA3E0: jal         0x800058DC
    // 0x801CA3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CA3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CA3E8: b           L_801CA3F8
    // 0x801CA3EC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
        goto L_801CA3F8;
    // 0x801CA3EC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
L_801CA3F0:
    // 0x801CA3F0: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // 0x801CA3F4: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
L_801CA3F8:
    // 0x801CA3F8: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x801CA3FC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801CA400: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CA404: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CA408: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CA40C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA410: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA414: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA418: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801CA41C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA420: addiu       $a1, $a1, -0xA14
    ctx->r5 = ADD32(ctx->r5, -0XA14);
    // 0x801CA424: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801CA428: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CA42C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CA430: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801CA434: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CA438: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CA43C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801CA440: jal         0x8001A804
    // 0x801CA444: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_2;
    // 0x801CA444: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x801CA448: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801CA44C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801CA450: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801CA454: jr          $ra
    // 0x801CA458: nop

    return;
    // 0x801CA458: nop

;}
RECOMP_FUNC void M23_FUN_801ca45c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA45C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CA460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CA464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CA468: jal         0x80142570
    // 0x801CA46C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x801CA46C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CA470: jal         0x8013EA94
    // 0x801CA474: nop

    LOOKUP_FUNC(0x8013EA94)(rdram, ctx);
        goto after_1;
    // 0x801CA474: nop

    after_1:
    // 0x801CA478: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CA47C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801CA480: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA484: sb          $t6, -0x4410($at)
    MEM_B(-0X4410, ctx->r1) = ctx->r14;
    // 0x801CA488: addiu       $a1, $a1, -0x5B5C
    ctx->r5 = ADD32(ctx->r5, -0X5B5C);
    // 0x801CA48C: jal         0x800058DC
    // 0x801CA490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CA490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801CA494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CA498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CA49C: jr          $ra
    // 0x801CA4A0: nop

    return;
    // 0x801CA4A0: nop

;}
RECOMP_FUNC void M23_FUN_801ca4a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA4A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CA4A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA4AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CA4B0: jal         0x8013EB2C
    // 0x801CA4B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013EB2C)(rdram, ctx);
        goto after_0;
    // 0x801CA4B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CA4B8: beql        $v0, $zero, L_801CA514
    if (ctx->r2 == 0) {
        // 0x801CA4BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CA514;
    }
    goto skip_0;
    // 0x801CA4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801CA4C0: jal         0x80142570
    // 0x801CA4C4: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801CA4C4: nop

    after_1:
    // 0x801CA4C8: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x801CA4CC: addiu       $a1, $zero, 0xC4
    ctx->r5 = ADD32(0, 0XC4);
    // 0x801CA4D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801CA4D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801CA4D8: jal         0x8012FE50
    // 0x801CA4DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x801CA4DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801CA4E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801CA4E4: lw          $a0, -0x2DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2DCC);
    // 0x801CA4E8: beq         $a0, $zero, L_801CA500
    if (ctx->r4 == 0) {
        // 0x801CA4EC: nop
    
            goto L_801CA500;
    }
    // 0x801CA4EC: nop

    // 0x801CA4F0: jal         0x80005700
    // 0x801CA4F4: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801CA4F4: nop

    after_3:
    // 0x801CA4F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA4FC: sw          $zero, -0x2DCC($at)
    MEM_W(-0X2DCC, ctx->r1) = 0;
L_801CA500:
    // 0x801CA500: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA504: addiu       $a1, $a1, -0x5AE0
    ctx->r5 = ADD32(ctx->r5, -0X5AE0);
    // 0x801CA508: jal         0x800058DC
    // 0x801CA50C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CA50C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x801CA510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CA514:
    // 0x801CA514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CA518: jr          $ra
    // 0x801CA51C: nop

    return;
    // 0x801CA51C: nop

;}
RECOMP_FUNC void M23_FUN_801ca520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA520: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CA524: jr          $ra
    // 0x801CA528: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801CA528: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca52c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca52c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA52C: nop

;}
RECOMP_FUNC void M23_FUN_801ca530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA530: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801CA534: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x801CA538: lhu         $t6, 0x9A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X9A);
    // 0x801CA53C: lhu         $t7, 0x8E($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X8E);
    // 0x801CA540: lhu         $t9, 0x90($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X90);
    // 0x801CA544: lhu         $t1, 0x92($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X92);
    // 0x801CA548: lhu         $t3, 0x94($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X94);
    // 0x801CA54C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801CA550: lhu         $t5, 0x96($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X96);
    // 0x801CA554: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801CA558: lhu         $t7, 0x98($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X98);
    // 0x801CA55C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801CA560: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801CA564: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801CA568: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801CA56C: jr          $ra
    // 0x801CA570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x801CA570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca574(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA574: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801CA578: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801CA57C: lhu         $t7, -0x225C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X225C);
    // 0x801CA580: lhu         $t6, -0x2324($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2324);
    // 0x801CA584: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801CA588: jr          $ra
    // 0x801CA58C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x801CA58C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca590(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA590: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CA594: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801CA598: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x801CA59C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801CA5A0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x801CA5A4: jr          $ra
    // 0x801CA5A8: lhu         $v0, -0x2332($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2332);
    return;
    // 0x801CA5A8: lhu         $v0, -0x2332($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2332);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca5ac(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca5ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA5AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801CA5B0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801CA5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CA5B8: addiu       $a2, $a2, 0x3CE0
    ctx->r6 = ADD32(ctx->r6, 0X3CE0);
    // 0x801CA5BC: lbu         $a1, 0x6($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6);
    // 0x801CA5C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801CA5C4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_801CA5C8:
    // 0x801CA5C8: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CA5CC: mflo        $t6
    ctx->r14 = lo;
    // 0x801CA5D0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801CA5D4: lbu         $a0, 0x4($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X4);
    // 0x801CA5D8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801CA5DC: bnel        $at, $zero, L_801CA5F0
    if (ctx->r1 != 0) {
        // 0x801CA5E0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801CA5F0;
    }
    goto skip_0;
    // 0x801CA5E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x801CA5E4: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x801CA5E8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x801CA5EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801CA5F0:
    // 0x801CA5F0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801CA5F4: slti        $at, $v1, 0x55
    ctx->r1 = SIGNED(ctx->r3) < 0X55 ? 1 : 0;
    // 0x801CA5F8: bne         $at, $zero, L_801CA5C8
    if (ctx->r1 != 0) {
        // 0x801CA5FC: nop
    
            goto L_801CA5C8;
    }
    // 0x801CA5FC: nop

    // 0x801CA600: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801CA604: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801CA608: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801CA60C: lw          $v0, 0x4140($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4140);
    // 0x801CA610: jr          $ra
    // 0x801CA614: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801CA614: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca618(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA618: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801CA61C: jr          $ra
    // 0x801CA620: lhu         $v0, -0x235A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X235A);
    return;
    // 0x801CA620: lhu         $v0, -0x235A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X235A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca624(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA624: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801CA628: jr          $ra
    // 0x801CA62C: lhu         $v0, -0x233E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X233E);
    return;
    // 0x801CA62C: lhu         $v0, -0x233E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X233E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca630(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA630: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801CA634: jr          $ra
    // 0x801CA638: lbu         $v0, -0x233A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X233A);
    return;
    // 0x801CA638: lbu         $v0, -0x233A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X233A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca63c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca63c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA63C: nop

;}
RECOMP_FUNC void M23_FUN_801ca640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA640: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801CA644: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801CA648: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x801CA64C: addiu       $t6, $t6, -0x1C7C
    ctx->r14 = ADD32(ctx->r14, -0X1C7C);
    // 0x801CA650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA654: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801CA658: addiu       $t1, $t6, 0x54
    ctx->r9 = ADD32(ctx->r14, 0X54);
    // 0x801CA65C: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
L_801CA660:
    // 0x801CA660: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CA664: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801CA668: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801CA66C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801CA670: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801CA674: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801CA678: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801CA67C: bne         $t6, $t1, L_801CA660
    if (ctx->r14 != ctx->r9) {
        // 0x801CA680: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801CA660;
    }
    // 0x801CA680: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801CA684: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801CA688: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801CA68C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x801CA690: lbu         $v1, 0x2C($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X2C);
    // 0x801CA694: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x801CA698: addu        $v0, $t0, $t3
    ctx->r2 = ADD32(ctx->r8, ctx->r11);
    // 0x801CA69C: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x801CA6A0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x801CA6A4: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x801CA6A8: lbu         $a2, 0x4($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4);
    // 0x801CA6AC: lbu         $a3, 0x5($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X5);
    // 0x801CA6B0: jal         0x8012FE50
    // 0x801CA6B4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801CA6B4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x801CA6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA6BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801CA6C0: jr          $ra
    // 0x801CA6C4: nop

    return;
    // 0x801CA6C4: nop

;}
RECOMP_FUNC void M23_FUN_801ca6c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA6C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CA6CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CA6D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801CA6D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801CA6D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CA6DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CA6E0: lh          $t6, 0x2A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2A);
    // 0x801CA6E4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801CA6E8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801CA6EC: addu        $s0, $t6, $a1
    ctx->r16 = ADD32(ctx->r14, ctx->r5);
    // 0x801CA6F0: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x801CA6F4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801CA6F8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801CA6FC: slti        $at, $s0, 0x6B
    ctx->r1 = SIGNED(ctx->r16) < 0X6B ? 1 : 0;
    // 0x801CA700: bne         $at, $zero, L_801CA714
    if (ctx->r1 != 0) {
        // 0x801CA704: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_801CA714;
    }
    // 0x801CA704: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA708: slti        $at, $s0, 0xBA
    ctx->r1 = SIGNED(ctx->r16) < 0XBA ? 1 : 0;
    // 0x801CA70C: bne         $at, $zero, L_801CA734
    if (ctx->r1 != 0) {
        // 0x801CA710: sll         $a2, $s0, 16
        ctx->r6 = S32(ctx->r16 << 16);
            goto L_801CA734;
    }
    // 0x801CA710: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
L_801CA714:
    // 0x801CA714: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801CA718: addiu       $a3, $a3, -0x9E0
    ctx->r7 = ADD32(ctx->r7, -0X9E0);
    // 0x801CA71C: lbu         $a0, 0x26($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X26);
    // 0x801CA720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CA724: jal         0x8001B204
    // 0x801CA728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801CA728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801CA72C: b           L_801CA794
    // 0x801CA730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801CA794;
    // 0x801CA730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CA734:
    // 0x801CA734: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x801CA738: lbu         $a0, 0x26($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X26);
    // 0x801CA73C: lh          $a1, 0x28($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X28);
    // 0x801CA740: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801CA744: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801CA748: addiu       $a3, $s1, 0x8
    ctx->r7 = ADD32(ctx->r17, 0X8);
    // 0x801CA74C: jal         0x8001B204
    // 0x801CA750: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801CA750: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x801CA754: slti        $at, $s0, 0x78
    ctx->r1 = SIGNED(ctx->r16) < 0X78 ? 1 : 0;
    // 0x801CA758: beq         $at, $zero, L_801CA768
    if (ctx->r1 == 0) {
        // 0x801CA75C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_801CA768;
    }
    // 0x801CA75C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CA760: addiu       $a3, $s0, -0x78
    ctx->r7 = ADD32(ctx->r16, -0X78);
    // 0x801CA764: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_801CA768:
    // 0x801CA768: addiu       $t8, $s0, 0xD
    ctx->r24 = ADD32(ctx->r16, 0XD);
    // 0x801CA76C: slti        $at, $t8, 0xBA
    ctx->r1 = SIGNED(ctx->r24) < 0XBA ? 1 : 0;
    // 0x801CA770: bne         $at, $zero, L_801CA780
    if (ctx->r1 != 0) {
        // 0x801CA774: sll         $a2, $s0, 16
        ctx->r6 = S32(ctx->r16 << 16);
            goto L_801CA780;
    }
    // 0x801CA774: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x801CA778: addiu       $a3, $s0, -0xAC
    ctx->r7 = ADD32(ctx->r16, -0XAC);
    // 0x801CA77C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_801CA780:
    // 0x801CA780: lbu         $a0, 0x26($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X26);
    // 0x801CA784: lh          $a1, 0x28($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X28);
    // 0x801CA788: jal         0x8001B194
    // 0x801CA78C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(0x8001B194)(rdram, ctx);
        goto after_2;
    // 0x801CA78C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_2:
    // 0x801CA790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CA794:
    // 0x801CA794: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA798: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801CA79C: jr          $ra
    // 0x801CA7A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801CA7A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801ca7a4(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801ca7a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA7A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801CA7A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801CA7AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801CA7B0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801CA7B4: jal         0x80126930
    // 0x801CA7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80126930)(rdram, ctx);
        goto after_0;
    // 0x801CA7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801CA7BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA7C0: sh          $zero, -0x21C($at)
    MEM_H(-0X21C, ctx->r1) = 0;
    // 0x801CA7C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA7C8: sb          $zero, -0x220($at)
    MEM_B(-0X220, ctx->r1) = 0;
    // 0x801CA7CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA7D0: sb          $zero, -0x21F($at)
    MEM_B(-0X21F, ctx->r1) = 0;
    // 0x801CA7D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801CA7D8: sb          $zero, -0x21E($at)
    MEM_B(-0X21E, ctx->r1) = 0;
    // 0x801CA7DC: jal         0x80116E80
    // 0x801CA7E0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x801CA7E0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_1:
    // 0x801CA7E4: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801CA7E8: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801CA7EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801CA7F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801CA7F4: jal         0x80002364
    // 0x801CA7F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_2;
    // 0x801CA7F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801CA7FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA800: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x801CA804: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x801CA808: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801CA80C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801CA810: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CA814: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801CA818: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CA81C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CA820: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CA824: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CA828: addiu       $a1, $a1, -0x9DC
    ctx->r5 = ADD32(ctx->r5, -0X9DC);
    // 0x801CA82C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CA830: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CA834: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CA838: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA83C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA840: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA844: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CA848: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CA84C: jal         0x8001A804
    // 0x801CA850: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_3;
    // 0x801CA850: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_3:
    // 0x801CA854: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA858: addiu       $a1, $a1, -0x578C
    ctx->r5 = ADD32(ctx->r5, -0X578C);
    // 0x801CA85C: jal         0x800058DC
    // 0x801CA860: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CA860: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x801CA864: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801CA868: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801CA86C: jr          $ra
    // 0x801CA870: nop

    return;
    // 0x801CA870: nop

;}
RECOMP_FUNC void M23_FUN_801ca874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA874: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801CA878: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801CA87C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801CA880: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801CA884: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801CA888: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA88C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801CA890: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801CA894: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CA898: addiu       $s2, $sp, 0x67
    ctx->r18 = ADD32(ctx->r29, 0X67);
    // 0x801CA89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801CA8A0:
    // 0x801CA8A0: sll         $a3, $v0, 5
    ctx->r7 = S32(ctx->r2 << 5);
    // 0x801CA8A4: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CA8A8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CA8AC: addiu       $t6, $zero, 0x56
    ctx->r14 = ADD32(0, 0X56);
    // 0x801CA8B0: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801CA8B4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x801CA8B8: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x801CA8BC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801CA8C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801CA8C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801CA8C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CA8CC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CA8D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA8D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CA8D8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CA8DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA8E0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA8E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA8E8: jal         0x80146208
    // 0x801CA8EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x801CA8EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801CA8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA8F4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801CA8F8: jal         0x80145348
    // 0x801CA8FC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_1;
    // 0x801CA8FC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x801CA900: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CA904: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CA908: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x801CA90C: bne         $at, $zero, L_801CA8A0
    if (ctx->r1 != 0) {
        // 0x801CA910: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_801CA8A0;
    }
    // 0x801CA910: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801CA914: sll         $a3, $v0, 5
    ctx->r7 = S32(ctx->r2 << 5);
    // 0x801CA918: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801CA91C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x801CA920: addiu       $t0, $zero, 0x56
    ctx->r8 = ADD32(0, 0X56);
    // 0x801CA924: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801CA928: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x801CA92C: addiu       $t3, $zero, 0x228
    ctx->r11 = ADD32(0, 0X228);
    // 0x801CA930: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801CA934: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801CA938: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801CA93C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801CA940: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801CA944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA948: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801CA94C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801CA950: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA954: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA958: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA95C: jal         0x80146208
    // 0x801CA960: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x801CA960: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x801CA964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA968: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x801CA96C: jal         0x80145348
    // 0x801CA970: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x801CA970: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x801CA974: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CA978: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_801CA97C:
    // 0x801CA97C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x801CA980: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CA984: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x801CA988: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801CA98C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801CA990: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x801CA994: bne         $at, $zero, L_801CA97C
    if (ctx->r1 != 0) {
        // 0x801CA998: sh          $v0, 0x28($t6)
        MEM_H(0X28, ctx->r14) = ctx->r2;
            goto L_801CA97C;
    }
    // 0x801CA998: sh          $v0, 0x28($t6)
    MEM_H(0X28, ctx->r14) = ctx->r2;
    // 0x801CA99C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA9A0: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
    // 0x801CA9A4: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x801CA9A8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801CA9AC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801CA9B0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801CA9B4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x801CA9B8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801CA9BC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801CA9C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801CA9C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CA9C8: addiu       $a1, $a1, -0x9B4
    ctx->r5 = ADD32(ctx->r5, -0X9B4);
    // 0x801CA9CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801CA9D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801CA9D4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801CA9D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CA9DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801CA9E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801CA9E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801CA9E8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801CA9EC: jal         0x8001A804
    // 0x801CA9F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001A804)(rdram, ctx);
        goto after_4;
    // 0x801CA9F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_4:
    // 0x801CA9F4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA9F8: addiu       $a1, $a1, -0x55E0
    ctx->r5 = ADD32(ctx->r5, -0X55E0);
    // 0x801CA9FC: jal         0x800058DC
    // 0x801CAA00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801CAA00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801CAA04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801CAA08: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801CAA0C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801CAA10: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801CAA14: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801CAA18: jr          $ra
    // 0x801CAA1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801CAA1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801caa20(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801caa20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAA20: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801CAA24: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801CAA28: lbu         $t6, 0x164($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X164);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801caa2c(rdram, ctx);
;}
