#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801e61f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E61F8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E61FC: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E6200: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6204: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6208: beq         $t6, $zero, L_801E6218
    if (ctx->r14 == 0) {
            // 0x801E620C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801E6218)(rdram, ctx);
    return;
    }
    // 0x801E620C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801E6210: jr          $ra
    // 0x801E6214: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801E6214: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6218(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6218: jr          $ra
    // 0x801E621C: nop

    return;
    // 0x801E621C: nop

;}
RECOMP_FUNC void M25_FUN_801e6220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6220: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E6224: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E6228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E622C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E6230: lui         $a1, 0x430
    ctx->r5 = S32(0X430 << 16);
    // 0x801E6234: ori         $a1, $a1, 0xB160
    ctx->r5 = ctx->r5 | 0XB160;
    // 0x801E6238: jal         0x801C0B8C
    // 0x801E623C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E623C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6240: beq         $v0, $zero, L_801E628C
    if (ctx->r2 == 0) {
        // 0x801E6244: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801E628C;
    }
    // 0x801E6244: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E6248: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E624C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E6250: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E6254: bne         $t6, $zero, L_801E628C
    if (ctx->r14 != 0) {
        // 0x801E6258: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801E628C;
    }
    // 0x801E6258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E625C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E6260: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E6264: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E6268: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E626C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E6270: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E6274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E6278: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E627C: jal         0x8038C97C
    // 0x801E6280: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E6280: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E6284: b           L_801E6290
    // 0x801E6288: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801E6290;
    // 0x801E6288: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E628C:
    // 0x801E628C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E6290:
    // 0x801E6290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E6294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E6298: jr          $ra
    // 0x801E629C: nop

    return;
    // 0x801E629C: nop

;}
RECOMP_FUNC void M25_FUN_801e62a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E62A0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E62A4: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E62A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E62AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E62B0: beq         $t6, $zero, L_801E62C0
    if (ctx->r14 == 0) {
            // 0x801E62B4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801E62C0)(rdram, ctx);
    return;
    }
    // 0x801E62B4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E62B8: jr          $ra
    // 0x801E62BC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801E62BC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e62c0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e62c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E62C0: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E62C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801E62C8: jr          $ra
    // 0x801E62CC: nop

    return;
    // 0x801E62CC: nop

;}
RECOMP_FUNC void M25_FUN_801e62d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E62D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E62D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E62D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E62DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E62E0: lui         $a1, 0x6CB
    ctx->r5 = S32(0X6CB << 16);
    // 0x801E62E4: ori         $a1, $a1, 0xB50
    ctx->r5 = ctx->r5 | 0XB50;
    // 0x801E62E8: jal         0x801C0B8C
    // 0x801E62EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E62EC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E62F0: beq         $v0, $zero, L_801E6328
    if (ctx->r2 == 0) {
        // 0x801E62F4: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801E6328;
    }
    // 0x801E62F4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E62F8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801E62FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E6300: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801E6304: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E6308: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E630C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E6310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E6314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E6318: jal         0x8038C97C
    // 0x801E631C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E631C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E6320: b           L_801E632C
    // 0x801E6324: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801E632C;
    // 0x801E6324: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E6328:
    // 0x801E6328: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E632C:
    // 0x801E632C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E6330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E6334: jr          $ra
    // 0x801E6338: nop

    return;
    // 0x801E6338: nop

;}
RECOMP_FUNC void M25_FUN_801e633c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E633C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E6340: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6344(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E6348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E634C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E6350: beq         $t6, $zero, L_801E6360
    if (ctx->r14 == 0) {
        // 0x801E6354: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801E6360;
    }
    // 0x801E6354: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E6358: b           L_801E63B4
    // 0x801E635C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801E63B4;
    // 0x801E635C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E6360:
    // 0x801E6360: lui         $a1, 0x6F5
    ctx->r5 = S32(0X6F5 << 16);
    // 0x801E6364: ori         $a1, $a1, 0xC4D0
    ctx->r5 = ctx->r5 | 0XC4D0;
    // 0x801E6368: jal         0x801C0B8C
    // 0x801E636C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E636C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6370: beq         $v0, $zero, L_801E63B0
    if (ctx->r2 == 0) {
        // 0x801E6374: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_801E63B0;
    }
    // 0x801E6374: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E6378: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E637C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E6380: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E6384: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E6388: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E638C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E6390: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E6394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E6398: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E639C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E63A0: jal         0x8038C97C
    // 0x801E63A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E63A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E63A8: b           L_801E63B4
    // 0x801E63AC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801E63B4;
    // 0x801E63AC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801E63B0:
    // 0x801E63B0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E63B4:
    // 0x801E63B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E63B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E63BC: jr          $ra
    // 0x801E63C0: nop

    return;
    // 0x801E63C0: nop

;}
RECOMP_FUNC void M25_FUN_801e63c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E63C4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E63C8: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E63CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E63D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E63D4: beq         $t6, $zero, L_801E63E4
    if (ctx->r14 == 0) {
            // 0x801E63D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801E63E4)(rdram, ctx);
    return;
    }
    // 0x801E63D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E63DC: jr          $ra
    // 0x801E63E0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x801E63E0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e63e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e63e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E63E4: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E63E8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x801E63EC: jr          $ra
    // 0x801E63F0: nop

    return;
    // 0x801E63F0: nop

;}
RECOMP_FUNC void M25_FUN_801e63f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E63F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E63F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E63FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E6400: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E6404: lui         $a1, 0x93B
    ctx->r5 = S32(0X93B << 16);
    // 0x801E6408: ori         $a1, $a1, 0xE43F
    ctx->r5 = ctx->r5 | 0XE43F;
    // 0x801E640C: jal         0x801C0B8C
    // 0x801E6410: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6410: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6414: beq         $v0, $zero, L_801E644C
    if (ctx->r2 == 0) {
        // 0x801E6418: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801E644C;
    }
    // 0x801E6418: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E641C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801E6420: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E6424: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801E6428: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E642C: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E6430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E6434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E6438: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E643C: jal         0x8038C97C
    // 0x801E6440: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E6440: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E6444: b           L_801E6450
    // 0x801E6448: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801E6450;
    // 0x801E6448: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801E644C:
    // 0x801E644C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E6450:
    // 0x801E6450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E6454: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E6458: jr          $ra
    // 0x801E645C: nop

    return;
    // 0x801E645C: nop

;}
RECOMP_FUNC void M25_FUN_801e6460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6460: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E6464: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E6468: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E646C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6470: beq         $t6, $zero, L_801E6480
    if (ctx->r14 == 0) {
            // 0x801E6474: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x801E6480)(rdram, ctx);
    return;
    }
    // 0x801E6474: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801E6478: jr          $ra
    // 0x801E647C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801E647C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6480(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6480: jr          $ra
    // 0x801E6484: nop

    return;
    // 0x801E6484: nop

;}
RECOMP_FUNC void M25_FUN_801e6488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6488: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E648C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6490: jr          $ra
    // 0x801E6494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801E6494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6498(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6498: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E649C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E64A0: jr          $ra
    // 0x801E64A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E64A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e64a8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e64a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E64A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E64AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E64B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E64B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E64B8: lui         $a1, 0x139
    ctx->r5 = S32(0X139 << 16);
    // 0x801E64BC: ori         $a1, $a1, 0x9170
    ctx->r5 = ctx->r5 | 0X9170;
    // 0x801E64C0: jal         0x801C0B8C
    // 0x801E64C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E64C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E64C8: beq         $v0, $zero, L_801E64D8
    if (ctx->r2 == 0) {
        // 0x801E64CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E64D8;
    }
    // 0x801E64CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E64D0: b           L_801E64DC
    // 0x801E64D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E64DC;
    // 0x801E64D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E64D8:
    // 0x801E64D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E64DC:
    // 0x801E64DC: jr          $ra
    // 0x801E64E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E64E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e64e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e64e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E64E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E64E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E64EC: jr          $ra
    // 0x801E64F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E64F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e64f4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e64f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E64F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E64F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E64FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6504: lui         $a1, 0x46D
    ctx->r5 = S32(0X46D << 16);
    // 0x801E6508: ori         $a1, $a1, 0xBA60
    ctx->r5 = ctx->r5 | 0XBA60;
    // 0x801E650C: jal         0x801C0B8C
    // 0x801E6510: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6510: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6514: beq         $v0, $zero, L_801E6524
    if (ctx->r2 == 0) {
        // 0x801E6518: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E6524;
    }
    // 0x801E6518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E651C: b           L_801E6528
    // 0x801E6520: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E6528;
    // 0x801E6520: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E6524:
    // 0x801E6524: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E6528:
    // 0x801E6528: jr          $ra
    // 0x801E652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6530(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6530: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6534: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6538: jr          $ra
    // 0x801E653C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801E653C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6540(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6544: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E654C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6550: lui         $a1, 0x751
    ctx->r5 = S32(0X751 << 16);
    // 0x801E6554: ori         $a1, $a1, 0x5250
    ctx->r5 = ctx->r5 | 0X5250;
    // 0x801E6558: jal         0x801C0B8C
    // 0x801E655C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E655C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6560: beq         $v0, $zero, L_801E6570
    if (ctx->r2 == 0) {
        // 0x801E6564: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E6570;
    }
    // 0x801E6564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6568: b           L_801E6574
    // 0x801E656C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801E6574;
    // 0x801E656C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E6570:
    // 0x801E6570: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E6574:
    // 0x801E6574: jr          $ra
    // 0x801E6578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E6578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e657c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e657c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E657C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6580: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6584: jr          $ra
    // 0x801E6588: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801E6588: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e658c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e658c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E658C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6590: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6594: jr          $ra
    // 0x801E6598: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801E6598: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e659c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e659c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E659C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E65A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E65A4: jr          $ra
    // 0x801E65A8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801E65A8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e65ac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e65ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E65AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E65B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E65B4: jr          $ra
    // 0x801E65B8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801E65B8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e65bc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e65bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E65BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E65C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E65C4: jr          $ra
    // 0x801E65C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x801E65C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e65cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e65cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E65CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E65D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E65D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E65D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E65DC: lui         $a1, 0x7
    ctx->r5 = S32(0X7 << 16);
    // 0x801E65E0: ori         $a1, $a1, 0xA120
    ctx->r5 = ctx->r5 | 0XA120;
    // 0x801E65E4: jal         0x801C0B8C
    // 0x801E65E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E65E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E65EC: beql        $v0, $zero, L_801E6608
    if (ctx->r2 == 0) {
        // 0x801E65F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801E6608;
    }
    goto skip_0;
    // 0x801E65F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801E65F4: jal         0x8038D28C
    // 0x801E65F8: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E65F8: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    after_1:
    // 0x801E65FC: b           L_801E6608
    // 0x801E6600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E6608;
    // 0x801E6600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E6604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E6608:
    // 0x801E6608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E660C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6610: jr          $ra
    // 0x801E6614: nop

    return;
    // 0x801E6614: nop

;}
RECOMP_FUNC void M25_FUN_801e6618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6618: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E661C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6620: jr          $ra
    // 0x801E6624: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E6624: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6628(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6628: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E662C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6630: jr          $ra
    // 0x801E6634: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E6634: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6638(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E663C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6648: lui         $a1, 0x35
    ctx->r5 = S32(0X35 << 16);
    // 0x801E664C: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    // 0x801E6650: jal         0x801C0B8C
    // 0x801E6654: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6654: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6658: beql        $v0, $zero, L_801E6674
    if (ctx->r2 == 0) {
        // 0x801E665C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801E6674;
    }
    goto skip_0;
    // 0x801E665C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801E6660: jal         0x8038D28C
    // 0x801E6664: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6664: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    after_1:
    // 0x801E6668: b           L_801E6674
    // 0x801E666C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E6674;
    // 0x801E666C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801E6670: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E6674:
    // 0x801E6674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E667C: jr          $ra
    // 0x801E6680: nop

    return;
    // 0x801E6680: nop

;}
RECOMP_FUNC void M25_FUN_801e6684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E668C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6694: lui         $a1, 0x139
    ctx->r5 = S32(0X139 << 16);
    // 0x801E6698: ori         $a1, $a1, 0x9170
    ctx->r5 = ctx->r5 | 0X9170;
    // 0x801E669C: jal         0x801C0B8C
    // 0x801E66A0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E66A0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E66A4: beql        $v0, $zero, L_801E66E0
    if (ctx->r2 == 0) {
        // 0x801E66A8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801E66E0;
    }
    goto skip_0;
    // 0x801E66A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801E66AC: jal         0x8038D2D4
    // 0x801E66B0: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    LOOKUP_FUNC(0x8038D2D4)(rdram, ctx);
        goto after_1;
    // 0x801E66B0: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    after_1:
    // 0x801E66B4: bnel        $v0, $zero, L_801E66E0
    if (ctx->r2 != 0) {
        // 0x801E66B8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801E66E0;
    }
    goto skip_1;
    // 0x801E66B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_1:
    // 0x801E66BC: jal         0x8038D2B0
    // 0x801E66C0: addiu       $a0, $zero, 0x609
    ctx->r4 = ADD32(0, 0X609);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_2;
    // 0x801E66C0: addiu       $a0, $zero, 0x609
    ctx->r4 = ADD32(0, 0X609);
    after_2:
    // 0x801E66C4: jal         0x8038D2B0
    // 0x801E66C8: addiu       $a0, $zero, 0x60A
    ctx->r4 = ADD32(0, 0X60A);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_3;
    // 0x801E66C8: addiu       $a0, $zero, 0x60A
    ctx->r4 = ADD32(0, 0X60A);
    after_3:
    // 0x801E66CC: jal         0x8038D2B0
    // 0x801E66D0: addiu       $a0, $zero, 0x60B
    ctx->r4 = ADD32(0, 0X60B);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_4;
    // 0x801E66D0: addiu       $a0, $zero, 0x60B
    ctx->r4 = ADD32(0, 0X60B);
    after_4:
    // 0x801E66D4: b           L_801E66E0
    // 0x801E66D8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801E66E0;
    // 0x801E66D8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801E66DC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E66E0:
    // 0x801E66E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E66E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E66E8: jr          $ra
    // 0x801E66EC: nop

    return;
    // 0x801E66EC: nop

;}
RECOMP_FUNC void M25_FUN_801e66f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E66F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E66F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E66F8: jr          $ra
    // 0x801E66FC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x801E66FC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6700(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E670C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6710: lui         $a1, 0x2CA
    ctx->r5 = S32(0X2CA << 16);
    // 0x801E6714: ori         $a1, $a1, 0x1C80
    ctx->r5 = ctx->r5 | 0X1C80;
    // 0x801E6718: jal         0x801C0B8C
    // 0x801E671C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E671C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6720: beql        $v0, $zero, L_801E673C
    if (ctx->r2 == 0) {
        // 0x801E6724: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_801E673C;
    }
    goto skip_0;
    // 0x801E6724: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_0:
    // 0x801E6728: jal         0x8038D28C
    // 0x801E672C: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E672C: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    after_1:
    // 0x801E6730: b           L_801E673C
    // 0x801E6734: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E673C;
    // 0x801E6734: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801E6738: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E673C:
    // 0x801E673C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6744: jr          $ra
    // 0x801E6748: nop

    return;
    // 0x801E6748: nop

;}
RECOMP_FUNC void M25_FUN_801e674c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E674C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6750: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6754: jr          $ra
    // 0x801E6758: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x801E6758: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e675c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e675c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E676C: lui         $a1, 0x307
    ctx->r5 = S32(0X307 << 16);
    // 0x801E6770: ori         $a1, $a1, 0x2580
    ctx->r5 = ctx->r5 | 0X2580;
    // 0x801E6774: jal         0x801C0B8C
    // 0x801E6778: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6778: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E677C: beql        $v0, $zero, L_801E6798
    if (ctx->r2 == 0) {
        // 0x801E6780: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_801E6798;
    }
    goto skip_0;
    // 0x801E6780: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_0:
    // 0x801E6784: jal         0x8038D28C
    // 0x801E6788: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6788: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    after_1:
    // 0x801E678C: b           L_801E6798
    // 0x801E6790: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801E6798;
    // 0x801E6790: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801E6794: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E6798:
    // 0x801E6798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E679C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E67A0: jr          $ra
    // 0x801E67A4: nop

    return;
    // 0x801E67A4: nop

;}
RECOMP_FUNC void M25_FUN_801e67a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E67A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E67AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E67B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E67B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E67B8: jal         0x8038D2D4
    // 0x801E67BC: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    LOOKUP_FUNC(0x8038D2D4)(rdram, ctx);
        goto after_0;
    // 0x801E67BC: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    after_0:
    // 0x801E67C0: bnel        $v0, $zero, L_801E67DC
    if (ctx->r2 != 0) {
        // 0x801E67C4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_801E67DC;
    }
    goto skip_0;
    // 0x801E67C4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_0:
    // 0x801E67C8: jal         0x8038D28C
    // 0x801E67CC: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E67CC: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    after_1:
    // 0x801E67D0: b           L_801E67DC
    // 0x801E67D4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801E67DC;
    // 0x801E67D4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801E67D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E67DC:
    // 0x801E67DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E67E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E67E4: jr          $ra
    // 0x801E67E8: nop

    return;
    // 0x801E67E8: nop

;}
RECOMP_FUNC void M25_FUN_801e67ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E67EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E67F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E67F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E67F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E67FC: lui         $a1, 0x3B6
    ctx->r5 = S32(0X3B6 << 16);
    // 0x801E6800: ori         $a1, $a1, 0x9F60
    ctx->r5 = ctx->r5 | 0X9F60;
    // 0x801E6804: jal         0x801C0B8C
    // 0x801E6808: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6808: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E680C: beql        $v0, $zero, L_801E6828
    if (ctx->r2 == 0) {
        // 0x801E6810: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_801E6828;
    }
    goto skip_0;
    // 0x801E6810: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_0:
    // 0x801E6814: jal         0x8038D28C
    // 0x801E6818: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6818: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    after_1:
    // 0x801E681C: b           L_801E6828
    // 0x801E6820: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801E6828;
    // 0x801E6820: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E6824: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E6828:
    // 0x801E6828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E682C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6830: jr          $ra
    // 0x801E6834: nop

    return;
    // 0x801E6834: nop

;}
RECOMP_FUNC void M25_FUN_801e6838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E683C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6840: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6848: jal         0x8038D2D4
    // 0x801E684C: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    LOOKUP_FUNC(0x8038D2D4)(rdram, ctx);
        goto after_0;
    // 0x801E684C: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    after_0:
    // 0x801E6850: bnel        $v0, $zero, L_801E686C
    if (ctx->r2 != 0) {
        // 0x801E6854: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_801E686C;
    }
    goto skip_0;
    // 0x801E6854: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    skip_0:
    // 0x801E6858: jal         0x8038D28C
    // 0x801E685C: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E685C: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    after_1:
    // 0x801E6860: b           L_801E686C
    // 0x801E6864: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801E686C;
    // 0x801E6864: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801E6868: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E686C:
    // 0x801E686C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6874: jr          $ra
    // 0x801E6878: nop

    return;
    // 0x801E6878: nop

;}
RECOMP_FUNC void M25_FUN_801e687c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E687C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6884: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E688C: jal         0x8038D2D4
    // 0x801E6890: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    LOOKUP_FUNC(0x8038D2D4)(rdram, ctx);
        goto after_0;
    // 0x801E6890: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    after_0:
    // 0x801E6894: bne         $v0, $zero, L_801E68A4
    if (ctx->r2 != 0) {
        // 0x801E6898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E68A4;
    }
    // 0x801E6898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E689C: b           L_801E68A8
    // 0x801E68A0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801E68A8;
    // 0x801E68A0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E68A4:
    // 0x801E68A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801E68A8:
    // 0x801E68A8: jr          $ra
    // 0x801E68AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E68AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e68b0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e68b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E68B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E68B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E68B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E68BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E68C0: lui         $a1, 0x430
    ctx->r5 = S32(0X430 << 16);
    // 0x801E68C4: ori         $a1, $a1, 0xB160
    ctx->r5 = ctx->r5 | 0XB160;
    // 0x801E68C8: jal         0x801C0B8C
    // 0x801E68CC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E68CC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E68D0: beql        $v0, $zero, L_801E68EC
    if (ctx->r2 == 0) {
        // 0x801E68D4: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801E68EC;
    }
    goto skip_0;
    // 0x801E68D4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_0:
    // 0x801E68D8: jal         0x8038D28C
    // 0x801E68DC: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E68DC: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    after_1:
    // 0x801E68E0: b           L_801E68EC
    // 0x801E68E4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801E68EC;
    // 0x801E68E4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x801E68E8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E68EC:
    // 0x801E68EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E68F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E68F4: jr          $ra
    // 0x801E68F8: nop

    return;
    // 0x801E68F8: nop

;}
RECOMP_FUNC void M25_FUN_801e68fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E68FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6908: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E690C: lui         $a1, 0x46D
    ctx->r5 = S32(0X46D << 16);
    // 0x801E6910: ori         $a1, $a1, 0xBA60
    ctx->r5 = ctx->r5 | 0XBA60;
    // 0x801E6914: jal         0x801C0B8C
    // 0x801E6918: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6918: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E691C: beql        $v0, $zero, L_801E6940
    if (ctx->r2 == 0) {
        // 0x801E6920: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_801E6940;
    }
    goto skip_0;
    // 0x801E6920: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    skip_0:
    // 0x801E6924: jal         0x8038D2B0
    // 0x801E6928: addiu       $a0, $zero, 0x60C
    ctx->r4 = ADD32(0, 0X60C);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_1;
    // 0x801E6928: addiu       $a0, $zero, 0x60C
    ctx->r4 = ADD32(0, 0X60C);
    after_1:
    // 0x801E692C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6930: sw          $zero, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = 0;
    // 0x801E6934: b           L_801E6940
    // 0x801E6938: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801E6940;
    // 0x801E6938: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801E693C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801E6940:
    // 0x801E6940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6948: jr          $ra
    // 0x801E694C: nop

    return;
    // 0x801E694C: nop

;}
RECOMP_FUNC void M25_FUN_801e6950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6950: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801E6954: lw          $t6, -0x4CF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6958(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E695C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6960: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x801E6964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6968: beq         $at, $zero, L_801E6B80
    if (ctx->r1 == 0) {
        // 0x801E696C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801E6B80;
    }
    // 0x801E696C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6970: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E6974: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6978: addu        $at, $at, $t6
    gpr jr_addend_801E6980 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801E697C: lw          $t6, -0x3FF8($at)
    ctx->r14 = ADD32(ctx->r1, -0X3FF8);
    // 0x801E6980: jr          $t6
    // 0x801E6984: nop

    switch (jr_addend_801E6980 >> 2) {
        case 0: goto L_801E6988; break;
        case 1: goto L_801E69B0; break;
        case 2: goto L_801E69D8; break;
        case 3: goto L_801E6A00; break;
        case 4: goto L_801E6A28; break;
        case 5: goto L_801E6A50; break;
        case 6: goto L_801E6A78; break;
        case 7: goto L_801E6AA0; break;
        case 8: goto L_801E6AC8; break;
        case 9: goto L_801E6AF0; break;
        case 10: goto L_801E6B18; break;
        case 11: goto L_801E6B40; break;
        case 12: goto L_801E6B68; break;
        default: switch_error(__func__, 0x801E6980, 0x801FC008);
    }
    // 0x801E6984: nop

L_801E6988:
    // 0x801E6988: jal         0x8038D308
    // 0x801E698C: addiu       $a0, $zero, 0x60C
    ctx->r4 = ADD32(0, 0X60C);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_0;
    // 0x801E698C: addiu       $a0, $zero, 0x60C
    ctx->r4 = ADD32(0, 0X60C);
    after_0:
    // 0x801E6990: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6994: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_0;
    // 0x801E6994: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_0:
    // 0x801E6998: jal         0x8038D2B0
    // 0x801E699C: addiu       $a0, $zero, 0x60D
    ctx->r4 = ADD32(0, 0X60D);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_1;
    // 0x801E699C: addiu       $a0, $zero, 0x60D
    ctx->r4 = ADD32(0, 0X60D);
    after_1:
    // 0x801E69A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E69A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E69A8: b           L_801E6B80
    // 0x801E69AC: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
        goto L_801E6B80;
    // 0x801E69AC: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
L_801E69B0:
    // 0x801E69B0: jal         0x8038D308
    // 0x801E69B4: addiu       $a0, $zero, 0x60D
    ctx->r4 = ADD32(0, 0X60D);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_2;
    // 0x801E69B4: addiu       $a0, $zero, 0x60D
    ctx->r4 = ADD32(0, 0X60D);
    after_2:
    // 0x801E69B8: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E69BC: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_1;
    // 0x801E69BC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_1:
    // 0x801E69C0: jal         0x8038D2B0
    // 0x801E69C4: addiu       $a0, $zero, 0x60E
    ctx->r4 = ADD32(0, 0X60E);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_3;
    // 0x801E69C4: addiu       $a0, $zero, 0x60E
    ctx->r4 = ADD32(0, 0X60E);
    after_3:
    // 0x801E69C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E69CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E69D0: b           L_801E6B80
    // 0x801E69D4: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
        goto L_801E6B80;
    // 0x801E69D4: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
L_801E69D8:
    // 0x801E69D8: jal         0x8038D308
    // 0x801E69DC: addiu       $a0, $zero, 0x60E
    ctx->r4 = ADD32(0, 0X60E);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_4;
    // 0x801E69DC: addiu       $a0, $zero, 0x60E
    ctx->r4 = ADD32(0, 0X60E);
    after_4:
    // 0x801E69E0: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E69E4: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_2;
    // 0x801E69E4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_2:
    // 0x801E69E8: jal         0x8038D2B0
    // 0x801E69EC: addiu       $a0, $zero, 0x60F
    ctx->r4 = ADD32(0, 0X60F);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_5;
    // 0x801E69EC: addiu       $a0, $zero, 0x60F
    ctx->r4 = ADD32(0, 0X60F);
    after_5:
    // 0x801E69F0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801E69F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E69F8: b           L_801E6B80
    // 0x801E69FC: sw          $t9, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r25;
        goto L_801E6B80;
    // 0x801E69FC: sw          $t9, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r25;
L_801E6A00:
    // 0x801E6A00: jal         0x8038D308
    // 0x801E6A04: addiu       $a0, $zero, 0x60F
    ctx->r4 = ADD32(0, 0X60F);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_6;
    // 0x801E6A04: addiu       $a0, $zero, 0x60F
    ctx->r4 = ADD32(0, 0X60F);
    after_6:
    // 0x801E6A08: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6A0C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_3;
    // 0x801E6A0C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_3:
    // 0x801E6A10: jal         0x8038D2B0
    // 0x801E6A14: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_7;
    // 0x801E6A14: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    after_7:
    // 0x801E6A18: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801E6A1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6A20: b           L_801E6B80
    // 0x801E6A24: sw          $t0, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r8;
        goto L_801E6B80;
    // 0x801E6A24: sw          $t0, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r8;
L_801E6A28:
    // 0x801E6A28: jal         0x8038D308
    // 0x801E6A2C: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_8;
    // 0x801E6A2C: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    after_8:
    // 0x801E6A30: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6A34: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_4;
    // 0x801E6A34: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_4:
    // 0x801E6A38: jal         0x8038D2B0
    // 0x801E6A3C: addiu       $a0, $zero, 0x611
    ctx->r4 = ADD32(0, 0X611);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_9;
    // 0x801E6A3C: addiu       $a0, $zero, 0x611
    ctx->r4 = ADD32(0, 0X611);
    after_9:
    // 0x801E6A40: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801E6A44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6A48: b           L_801E6B80
    // 0x801E6A4C: sw          $t1, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r9;
        goto L_801E6B80;
    // 0x801E6A4C: sw          $t1, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r9;
L_801E6A50:
    // 0x801E6A50: jal         0x8038D308
    // 0x801E6A54: addiu       $a0, $zero, 0x611
    ctx->r4 = ADD32(0, 0X611);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_10;
    // 0x801E6A54: addiu       $a0, $zero, 0x611
    ctx->r4 = ADD32(0, 0X611);
    after_10:
    // 0x801E6A58: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6A5C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_5;
    // 0x801E6A5C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_5:
    // 0x801E6A60: jal         0x8038D2B0
    // 0x801E6A64: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_11;
    // 0x801E6A64: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    after_11:
    // 0x801E6A68: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801E6A6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6A70: b           L_801E6B80
    // 0x801E6A74: sw          $t2, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r10;
        goto L_801E6B80;
    // 0x801E6A74: sw          $t2, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r10;
L_801E6A78:
    // 0x801E6A78: jal         0x8038D308
    // 0x801E6A7C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_12;
    // 0x801E6A7C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    after_12:
    // 0x801E6A80: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6A84: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_6;
    // 0x801E6A84: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_6:
    // 0x801E6A88: jal         0x8038D2B0
    // 0x801E6A8C: addiu       $a0, $zero, 0x613
    ctx->r4 = ADD32(0, 0X613);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_13;
    // 0x801E6A8C: addiu       $a0, $zero, 0x613
    ctx->r4 = ADD32(0, 0X613);
    after_13:
    // 0x801E6A90: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801E6A94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6A98: b           L_801E6B80
    // 0x801E6A9C: sw          $t3, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r11;
        goto L_801E6B80;
    // 0x801E6A9C: sw          $t3, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r11;
L_801E6AA0:
    // 0x801E6AA0: jal         0x8038D308
    // 0x801E6AA4: addiu       $a0, $zero, 0x613
    ctx->r4 = ADD32(0, 0X613);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_14;
    // 0x801E6AA4: addiu       $a0, $zero, 0x613
    ctx->r4 = ADD32(0, 0X613);
    after_14:
    // 0x801E6AA8: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6AAC: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_7;
    // 0x801E6AAC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_7:
    // 0x801E6AB0: jal         0x8038D2B0
    // 0x801E6AB4: addiu       $a0, $zero, 0x614
    ctx->r4 = ADD32(0, 0X614);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_15;
    // 0x801E6AB4: addiu       $a0, $zero, 0x614
    ctx->r4 = ADD32(0, 0X614);
    after_15:
    // 0x801E6AB8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x801E6ABC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6AC0: b           L_801E6B80
    // 0x801E6AC4: sw          $t4, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r12;
        goto L_801E6B80;
    // 0x801E6AC4: sw          $t4, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r12;
L_801E6AC8:
    // 0x801E6AC8: jal         0x8038D308
    // 0x801E6ACC: addiu       $a0, $zero, 0x614
    ctx->r4 = ADD32(0, 0X614);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_16;
    // 0x801E6ACC: addiu       $a0, $zero, 0x614
    ctx->r4 = ADD32(0, 0X614);
    after_16:
    // 0x801E6AD0: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6AD4: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_8;
    // 0x801E6AD4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_8:
    // 0x801E6AD8: jal         0x8038D2B0
    // 0x801E6ADC: addiu       $a0, $zero, 0x615
    ctx->r4 = ADD32(0, 0X615);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_17;
    // 0x801E6ADC: addiu       $a0, $zero, 0x615
    ctx->r4 = ADD32(0, 0X615);
    after_17:
    // 0x801E6AE0: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x801E6AE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6AE8: b           L_801E6B80
    // 0x801E6AEC: sw          $t5, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r13;
        goto L_801E6B80;
    // 0x801E6AEC: sw          $t5, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r13;
L_801E6AF0:
    // 0x801E6AF0: jal         0x8038D308
    // 0x801E6AF4: addiu       $a0, $zero, 0x615
    ctx->r4 = ADD32(0, 0X615);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_18;
    // 0x801E6AF4: addiu       $a0, $zero, 0x615
    ctx->r4 = ADD32(0, 0X615);
    after_18:
    // 0x801E6AF8: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6AFC: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_9;
    // 0x801E6AFC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_9:
    // 0x801E6B00: jal         0x8038D2B0
    // 0x801E6B04: addiu       $a0, $zero, 0x616
    ctx->r4 = ADD32(0, 0X616);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_19;
    // 0x801E6B04: addiu       $a0, $zero, 0x616
    ctx->r4 = ADD32(0, 0X616);
    after_19:
    // 0x801E6B08: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801E6B0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6B10: b           L_801E6B80
    // 0x801E6B14: sw          $t6, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r14;
        goto L_801E6B80;
    // 0x801E6B14: sw          $t6, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r14;
L_801E6B18:
    // 0x801E6B18: jal         0x8038D308
    // 0x801E6B1C: addiu       $a0, $zero, 0x616
    ctx->r4 = ADD32(0, 0X616);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_20;
    // 0x801E6B1C: addiu       $a0, $zero, 0x616
    ctx->r4 = ADD32(0, 0X616);
    after_20:
    // 0x801E6B20: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6B24: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_10;
    // 0x801E6B24: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_10:
    // 0x801E6B28: jal         0x8038D2B0
    // 0x801E6B2C: addiu       $a0, $zero, 0x617
    ctx->r4 = ADD32(0, 0X617);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_21;
    // 0x801E6B2C: addiu       $a0, $zero, 0x617
    ctx->r4 = ADD32(0, 0X617);
    after_21:
    // 0x801E6B30: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x801E6B34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6B38: b           L_801E6B80
    // 0x801E6B3C: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
        goto L_801E6B80;
    // 0x801E6B3C: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
L_801E6B40:
    // 0x801E6B40: jal         0x8038D308
    // 0x801E6B44: addiu       $a0, $zero, 0x617
    ctx->r4 = ADD32(0, 0X617);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_22;
    // 0x801E6B44: addiu       $a0, $zero, 0x617
    ctx->r4 = ADD32(0, 0X617);
    after_22:
    // 0x801E6B48: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6B4C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_11;
    // 0x801E6B4C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_11:
    // 0x801E6B50: jal         0x8038D2B0
    // 0x801E6B54: addiu       $a0, $zero, 0x618
    ctx->r4 = ADD32(0, 0X618);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_23;
    // 0x801E6B54: addiu       $a0, $zero, 0x618
    ctx->r4 = ADD32(0, 0X618);
    after_23:
    // 0x801E6B58: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x801E6B5C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6B60: b           L_801E6B80
    // 0x801E6B64: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
        goto L_801E6B80;
    // 0x801E6B64: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
L_801E6B68:
    // 0x801E6B68: jal         0x8038D308
    // 0x801E6B6C: addiu       $a0, $zero, 0x618
    ctx->r4 = ADD32(0, 0X618);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_24;
    // 0x801E6B6C: addiu       $a0, $zero, 0x618
    ctx->r4 = ADD32(0, 0X618);
    after_24:
    // 0x801E6B70: bnel        $v0, $zero, L_801E6B84
    if (ctx->r2 != 0) {
        // 0x801E6B74: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801E6B84;
    }
    goto skip_12;
    // 0x801E6B74: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_12:
    // 0x801E6B78: b           L_801E6B84
    // 0x801E6B7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801E6B84;
    // 0x801E6B7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801E6B80:
    // 0x801E6B80: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801E6B84:
    // 0x801E6B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6B8C: jr          $ra
    // 0x801E6B90: nop

    return;
    // 0x801E6B90: nop

;}
RECOMP_FUNC void M25_FUN_801e6b94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6B98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6BA4: lui         $a1, 0x6CB
    ctx->r5 = S32(0X6CB << 16);
    // 0x801E6BA8: ori         $a1, $a1, 0xB50
    ctx->r5 = ctx->r5 | 0XB50;
    // 0x801E6BAC: jal         0x801C0B8C
    // 0x801E6BB0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6BB0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6BB4: beql        $v0, $zero, L_801E6BD0
    if (ctx->r2 == 0) {
        // 0x801E6BB8: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_801E6BD0;
    }
    goto skip_0;
    // 0x801E6BB8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    skip_0:
    // 0x801E6BBC: jal         0x8038D28C
    // 0x801E6BC0: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6BC0: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_1:
    // 0x801E6BC4: b           L_801E6BD0
    // 0x801E6BC8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801E6BD0;
    // 0x801E6BC8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x801E6BCC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801E6BD0:
    // 0x801E6BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6BD8: jr          $ra
    // 0x801E6BDC: nop

    return;
    // 0x801E6BDC: nop

;}
RECOMP_FUNC void M25_FUN_801e6be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6BEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6BF0: jal         0x8038D2D4
    // 0x801E6BF4: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    LOOKUP_FUNC(0x8038D2D4)(rdram, ctx);
        goto after_0;
    // 0x801E6BF4: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_0:
    // 0x801E6BF8: bnel        $v0, $zero, L_801E6C1C
    if (ctx->r2 != 0) {
        // 0x801E6BFC: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_801E6C1C;
    }
    goto skip_0;
    // 0x801E6BFC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    skip_0:
    // 0x801E6C00: jal         0x8038D28C
    // 0x801E6C04: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6C04: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    after_1:
    // 0x801E6C08: jal         0x8038D2B0
    // 0x801E6C0C: addiu       $a0, $zero, 0x619
    ctx->r4 = ADD32(0, 0X619);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_2;
    // 0x801E6C0C: addiu       $a0, $zero, 0x619
    ctx->r4 = ADD32(0, 0X619);
    after_2:
    // 0x801E6C10: b           L_801E6C1C
    // 0x801E6C14: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_801E6C1C;
    // 0x801E6C14: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x801E6C18: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801E6C1C:
    // 0x801E6C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6C24: jr          $ra
    // 0x801E6C28: nop

    return;
    // 0x801E6C28: nop

;}
RECOMP_FUNC void M25_FUN_801e6c2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6C30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6C3C: lui         $a1, 0x72B
    ctx->r5 = S32(0X72B << 16);
    // 0x801E6C40: ori         $a1, $a1, 0x2CB0
    ctx->r5 = ctx->r5 | 0X2CB0;
    // 0x801E6C44: jal         0x801C0B8C
    // 0x801E6C48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6C48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6C4C: beq         $v0, $zero, L_801E6C5C
    if (ctx->r2 == 0) {
        // 0x801E6C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E6C5C;
    }
    // 0x801E6C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6C54: b           L_801E6C60
    // 0x801E6C58: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801E6C60;
    // 0x801E6C58: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801E6C5C:
    // 0x801E6C5C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801E6C60:
    // 0x801E6C60: jr          $ra
    // 0x801E6C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801E6C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6c68(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6c68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6C68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6C6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6C70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6C74: sw          $zero, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = 0;
    // 0x801E6C78: jr          $ra
    // 0x801E6C7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801E6C7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6c80(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6c80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6C80: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801E6C84: lw          $t6, -0x4CF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6c88(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e6c88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6C90: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x801E6C94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6C98: beq         $at, $zero, L_801E6EB0
    if (ctx->r1 == 0) {
        // 0x801E6C9C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801E6EB0;
    }
    // 0x801E6C9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6CA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E6CA4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6CA8: addu        $at, $at, $t6
    gpr jr_addend_801E6CB0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801E6CAC: lw          $t6, -0x3FC4($at)
    ctx->r14 = ADD32(ctx->r1, -0X3FC4);
    // 0x801E6CB0: jr          $t6
    // 0x801E6CB4: nop

    switch (jr_addend_801E6CB0 >> 2) {
        case 0: goto L_801E6CB8; break;
        case 1: goto L_801E6CE0; break;
        case 2: goto L_801E6D08; break;
        case 3: goto L_801E6D30; break;
        case 4: goto L_801E6D58; break;
        case 5: goto L_801E6D80; break;
        case 6: goto L_801E6DA8; break;
        case 7: goto L_801E6DD0; break;
        case 8: goto L_801E6DF8; break;
        case 9: goto L_801E6E20; break;
        case 10: goto L_801E6E48; break;
        case 11: goto L_801E6E70; break;
        case 12: goto L_801E6E98; break;
        default: switch_error(__func__, 0x801E6CB0, 0x801FC03C);
    }
    // 0x801E6CB4: nop

L_801E6CB8:
    // 0x801E6CB8: jal         0x8038D308
    // 0x801E6CBC: addiu       $a0, $zero, 0x619
    ctx->r4 = ADD32(0, 0X619);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_0;
    // 0x801E6CBC: addiu       $a0, $zero, 0x619
    ctx->r4 = ADD32(0, 0X619);
    after_0:
    // 0x801E6CC0: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6CC4: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_0;
    // 0x801E6CC4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_0:
    // 0x801E6CC8: jal         0x8038D2B0
    // 0x801E6CCC: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_1;
    // 0x801E6CCC: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_1:
    // 0x801E6CD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E6CD4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6CD8: b           L_801E6EB0
    // 0x801E6CDC: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
        goto L_801E6EB0;
    // 0x801E6CDC: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
L_801E6CE0:
    // 0x801E6CE0: jal         0x8038D308
    // 0x801E6CE4: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_2;
    // 0x801E6CE4: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_2:
    // 0x801E6CE8: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6CEC: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_1;
    // 0x801E6CEC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_1:
    // 0x801E6CF0: jal         0x8038D2B0
    // 0x801E6CF4: addiu       $a0, $zero, 0x61D
    ctx->r4 = ADD32(0, 0X61D);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_3;
    // 0x801E6CF4: addiu       $a0, $zero, 0x61D
    ctx->r4 = ADD32(0, 0X61D);
    after_3:
    // 0x801E6CF8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E6CFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6D00: b           L_801E6EB0
    // 0x801E6D04: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
        goto L_801E6EB0;
    // 0x801E6D04: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
L_801E6D08:
    // 0x801E6D08: jal         0x8038D308
    // 0x801E6D0C: addiu       $a0, $zero, 0x61D
    ctx->r4 = ADD32(0, 0X61D);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_4;
    // 0x801E6D0C: addiu       $a0, $zero, 0x61D
    ctx->r4 = ADD32(0, 0X61D);
    after_4:
    // 0x801E6D10: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6D14: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_2;
    // 0x801E6D14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_2:
    // 0x801E6D18: jal         0x8038D2B0
    // 0x801E6D1C: addiu       $a0, $zero, 0x61E
    ctx->r4 = ADD32(0, 0X61E);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_5;
    // 0x801E6D1C: addiu       $a0, $zero, 0x61E
    ctx->r4 = ADD32(0, 0X61E);
    after_5:
    // 0x801E6D20: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801E6D24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6D28: b           L_801E6EB0
    // 0x801E6D2C: sw          $t9, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r25;
        goto L_801E6EB0;
    // 0x801E6D2C: sw          $t9, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r25;
L_801E6D30:
    // 0x801E6D30: jal         0x8038D308
    // 0x801E6D34: addiu       $a0, $zero, 0x61E
    ctx->r4 = ADD32(0, 0X61E);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_6;
    // 0x801E6D34: addiu       $a0, $zero, 0x61E
    ctx->r4 = ADD32(0, 0X61E);
    after_6:
    // 0x801E6D38: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6D3C: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_3;
    // 0x801E6D3C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_3:
    // 0x801E6D40: jal         0x8038D2B0
    // 0x801E6D44: addiu       $a0, $zero, 0x61F
    ctx->r4 = ADD32(0, 0X61F);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_7;
    // 0x801E6D44: addiu       $a0, $zero, 0x61F
    ctx->r4 = ADD32(0, 0X61F);
    after_7:
    // 0x801E6D48: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801E6D4C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6D50: b           L_801E6EB0
    // 0x801E6D54: sw          $t0, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r8;
        goto L_801E6EB0;
    // 0x801E6D54: sw          $t0, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r8;
L_801E6D58:
    // 0x801E6D58: jal         0x8038D308
    // 0x801E6D5C: addiu       $a0, $zero, 0x61F
    ctx->r4 = ADD32(0, 0X61F);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_8;
    // 0x801E6D5C: addiu       $a0, $zero, 0x61F
    ctx->r4 = ADD32(0, 0X61F);
    after_8:
    // 0x801E6D60: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6D64: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_4;
    // 0x801E6D64: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_4:
    // 0x801E6D68: jal         0x8038D2B0
    // 0x801E6D6C: addiu       $a0, $zero, 0x620
    ctx->r4 = ADD32(0, 0X620);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_9;
    // 0x801E6D6C: addiu       $a0, $zero, 0x620
    ctx->r4 = ADD32(0, 0X620);
    after_9:
    // 0x801E6D70: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801E6D74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6D78: b           L_801E6EB0
    // 0x801E6D7C: sw          $t1, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r9;
        goto L_801E6EB0;
    // 0x801E6D7C: sw          $t1, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r9;
L_801E6D80:
    // 0x801E6D80: jal         0x8038D308
    // 0x801E6D84: addiu       $a0, $zero, 0x620
    ctx->r4 = ADD32(0, 0X620);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_10;
    // 0x801E6D84: addiu       $a0, $zero, 0x620
    ctx->r4 = ADD32(0, 0X620);
    after_10:
    // 0x801E6D88: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6D8C: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_5;
    // 0x801E6D8C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_5:
    // 0x801E6D90: jal         0x8038D2B0
    // 0x801E6D94: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_11;
    // 0x801E6D94: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_11:
    // 0x801E6D98: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801E6D9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6DA0: b           L_801E6EB0
    // 0x801E6DA4: sw          $t2, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r10;
        goto L_801E6EB0;
    // 0x801E6DA4: sw          $t2, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r10;
L_801E6DA8:
    // 0x801E6DA8: jal         0x8038D308
    // 0x801E6DAC: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_12;
    // 0x801E6DAC: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_12:
    // 0x801E6DB0: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6DB4: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_6;
    // 0x801E6DB4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_6:
    // 0x801E6DB8: jal         0x8038D2B0
    // 0x801E6DBC: addiu       $a0, $zero, 0x622
    ctx->r4 = ADD32(0, 0X622);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_13;
    // 0x801E6DBC: addiu       $a0, $zero, 0x622
    ctx->r4 = ADD32(0, 0X622);
    after_13:
    // 0x801E6DC0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801E6DC4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6DC8: b           L_801E6EB0
    // 0x801E6DCC: sw          $t3, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r11;
        goto L_801E6EB0;
    // 0x801E6DCC: sw          $t3, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r11;
L_801E6DD0:
    // 0x801E6DD0: jal         0x8038D308
    // 0x801E6DD4: addiu       $a0, $zero, 0x622
    ctx->r4 = ADD32(0, 0X622);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_14;
    // 0x801E6DD4: addiu       $a0, $zero, 0x622
    ctx->r4 = ADD32(0, 0X622);
    after_14:
    // 0x801E6DD8: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6DDC: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_7;
    // 0x801E6DDC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_7:
    // 0x801E6DE0: jal         0x8038D2B0
    // 0x801E6DE4: addiu       $a0, $zero, 0x623
    ctx->r4 = ADD32(0, 0X623);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_15;
    // 0x801E6DE4: addiu       $a0, $zero, 0x623
    ctx->r4 = ADD32(0, 0X623);
    after_15:
    // 0x801E6DE8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x801E6DEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6DF0: b           L_801E6EB0
    // 0x801E6DF4: sw          $t4, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r12;
        goto L_801E6EB0;
    // 0x801E6DF4: sw          $t4, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r12;
L_801E6DF8:
    // 0x801E6DF8: jal         0x8038D308
    // 0x801E6DFC: addiu       $a0, $zero, 0x623
    ctx->r4 = ADD32(0, 0X623);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_16;
    // 0x801E6DFC: addiu       $a0, $zero, 0x623
    ctx->r4 = ADD32(0, 0X623);
    after_16:
    // 0x801E6E00: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6E04: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_8;
    // 0x801E6E04: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_8:
    // 0x801E6E08: jal         0x8038D2B0
    // 0x801E6E0C: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_17;
    // 0x801E6E0C: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    after_17:
    // 0x801E6E10: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x801E6E14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6E18: b           L_801E6EB0
    // 0x801E6E1C: sw          $t5, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r13;
        goto L_801E6EB0;
    // 0x801E6E1C: sw          $t5, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r13;
L_801E6E20:
    // 0x801E6E20: jal         0x8038D308
    // 0x801E6E24: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_18;
    // 0x801E6E24: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    after_18:
    // 0x801E6E28: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6E2C: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_9;
    // 0x801E6E2C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_9:
    // 0x801E6E30: jal         0x8038D2B0
    // 0x801E6E34: addiu       $a0, $zero, 0x625
    ctx->r4 = ADD32(0, 0X625);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_19;
    // 0x801E6E34: addiu       $a0, $zero, 0x625
    ctx->r4 = ADD32(0, 0X625);
    after_19:
    // 0x801E6E38: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801E6E3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6E40: b           L_801E6EB0
    // 0x801E6E44: sw          $t6, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r14;
        goto L_801E6EB0;
    // 0x801E6E44: sw          $t6, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r14;
L_801E6E48:
    // 0x801E6E48: jal         0x8038D308
    // 0x801E6E4C: addiu       $a0, $zero, 0x625
    ctx->r4 = ADD32(0, 0X625);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_20;
    // 0x801E6E4C: addiu       $a0, $zero, 0x625
    ctx->r4 = ADD32(0, 0X625);
    after_20:
    // 0x801E6E50: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6E54: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_10;
    // 0x801E6E54: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_10:
    // 0x801E6E58: jal         0x8038D2B0
    // 0x801E6E5C: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_21;
    // 0x801E6E5C: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_21:
    // 0x801E6E60: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x801E6E64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6E68: b           L_801E6EB0
    // 0x801E6E6C: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
        goto L_801E6EB0;
    // 0x801E6E6C: sw          $t7, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r15;
L_801E6E70:
    // 0x801E6E70: jal         0x8038D308
    // 0x801E6E74: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_22;
    // 0x801E6E74: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_22:
    // 0x801E6E78: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6E7C: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_11;
    // 0x801E6E7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_11:
    // 0x801E6E80: jal         0x8038D2B0
    // 0x801E6E84: addiu       $a0, $zero, 0x627
    ctx->r4 = ADD32(0, 0X627);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_23;
    // 0x801E6E84: addiu       $a0, $zero, 0x627
    ctx->r4 = ADD32(0, 0X627);
    after_23:
    // 0x801E6E88: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x801E6E8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6E90: b           L_801E6EB0
    // 0x801E6E94: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
        goto L_801E6EB0;
    // 0x801E6E94: sw          $t8, -0x4CF8($at)
    MEM_W(-0X4CF8, ctx->r1) = ctx->r24;
L_801E6E98:
    // 0x801E6E98: jal         0x8038D308
    // 0x801E6E9C: addiu       $a0, $zero, 0x627
    ctx->r4 = ADD32(0, 0X627);
    LOOKUP_FUNC(0x8038D308)(rdram, ctx);
        goto after_24;
    // 0x801E6E9C: addiu       $a0, $zero, 0x627
    ctx->r4 = ADD32(0, 0X627);
    after_24:
    // 0x801E6EA0: bnel        $v0, $zero, L_801E6EB4
    if (ctx->r2 != 0) {
        // 0x801E6EA4: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_801E6EB4;
    }
    goto skip_12;
    // 0x801E6EA4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    skip_12:
    // 0x801E6EA8: b           L_801E6EB4
    // 0x801E6EAC: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801E6EB4;
    // 0x801E6EAC: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801E6EB0:
    // 0x801E6EB0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801E6EB4:
    // 0x801E6EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6EB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6EBC: jr          $ra
    // 0x801E6EC0: nop

    return;
    // 0x801E6EC0: nop

;}
RECOMP_FUNC void M25_FUN_801e6ec4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6EC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6ED4: lui         $a1, 0x93B
    ctx->r5 = S32(0X93B << 16);
    // 0x801E6ED8: ori         $a1, $a1, 0xE43F
    ctx->r5 = ctx->r5 | 0XE43F;
    // 0x801E6EDC: jal         0x801C0B8C
    // 0x801E6EE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6EE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6EE4: beql        $v0, $zero, L_801E6F00
    if (ctx->r2 == 0) {
        // 0x801E6EE8: addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
            goto L_801E6F00;
    }
    goto skip_0;
    // 0x801E6EE8: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    skip_0:
    // 0x801E6EEC: jal         0x8038D28C
    // 0x801E6EF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801E6EF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x801E6EF4: b           L_801E6F00
    // 0x801E6EF8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_801E6F00;
    // 0x801E6EF8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801E6EFC: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801E6F00:
    // 0x801E6F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6F08: jr          $ra
    // 0x801E6F0C: nop

    return;
    // 0x801E6F0C: nop

;}
RECOMP_FUNC void M25_FUN_801e6f10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6F10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E6F14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E6F18: jr          $ra
    // 0x801E6F1C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x801E6F1C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e6f20(rdram, ctx);
;}
