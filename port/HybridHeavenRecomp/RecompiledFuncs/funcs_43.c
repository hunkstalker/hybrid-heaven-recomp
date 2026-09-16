#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c11b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C11B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C11B4: addiu       $v0, $v0, -0x7268
    ctx->r2 = ADD32(ctx->r2, -0X7268);
    // 0x801C11B8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C11BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c11c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c11c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C11C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C11C4: sw          $zero, -0x726C($at)
    MEM_W(-0X726C, ctx->r1) = 0;
    // 0x801C11C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C11CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C11D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C11D4: jal         0x801C0C08
    // 0x801C11D8: sw          $t7, -0x7270($at)
    MEM_W(-0X7270, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C11D8: sw          $t7, -0x7270($at)
    MEM_W(-0X7270, ctx->r1) = ctx->r15;
    after_0:
    // 0x801C11DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C11E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C11E4: sw          $v0, -0x7260($at)
    MEM_W(-0X7260, ctx->r1) = ctx->r2;
    // 0x801C11E8: sw          $v1, -0x725C($at)
    MEM_W(-0X725C, ctx->r1) = ctx->r3;
    // 0x801C11EC: jr          $ra
    // 0x801C11F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C11F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c11f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c11f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C11F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C11F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C11FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1200: jal         0x801C0A68
    // 0x801C1204: sw          $zero, -0x7270($at)
    MEM_W(-0X7270, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0A68)(rdram, ctx);
        goto after_0;
    // 0x801C1204: sw          $zero, -0x7270($at)
    MEM_W(-0X7270, ctx->r1) = 0;
    after_0:
    // 0x801C1208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C120C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801C1210: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x801C1214: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1218: sw          $t6, -0x7260($at)
    MEM_W(-0X7260, ctx->r1) = ctx->r14;
    // 0x801C121C: sw          $t7, -0x725C($at)
    MEM_W(-0X725C, ctx->r1) = ctx->r15;
    // 0x801C1220: jr          $ra
    // 0x801C1224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C1224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1228(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1228: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C122C: jr          $ra
    // 0x801C1230: lw          $v0, -0x7270($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7270);
    return;
    // 0x801C1230: lw          $v0, -0x7270($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7270);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1234(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C123C: jal         0x801C1228
    // 0x801C1240: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x801C1228)(rdram, ctx);
        goto after_0;
    // 0x801C1240: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x801C1244: beq         $v0, $zero, L_801C1270
    if (ctx->r2 == 0) {
        // 0x801C1248: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_801C1270;
    }
    // 0x801C1248: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801C124C: jal         0x801C1284
    // 0x801C1250: nop

    LOOKUP_FUNC(0x801C1284)(rdram, ctx);
        goto after_1;
    // 0x801C1250: nop

    after_1:
    // 0x801C1254: beq         $v0, $zero, L_801C1264
    if (ctx->r2 == 0) {
        // 0x801C1258: nop
    
            goto L_801C1264;
    }
    // 0x801C1258: nop

    // 0x801C125C: b           L_801C1270
    // 0x801C1260: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801C1270;
    // 0x801C1260: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801C1264:
    // 0x801C1264: jal         0x801C133C
    // 0x801C1268: nop

    LOOKUP_FUNC(0x801C133C)(rdram, ctx);
        goto after_2;
    // 0x801C1268: nop

    after_2:
    // 0x801C126C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801C1270:
    // 0x801C1270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1274: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1278: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801C127C: jr          $ra
    // 0x801C1280: nop

    return;
    // 0x801C1280: nop

;}
RECOMP_FUNC void M24_FUN_801c1284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1284: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1288: lw          $t6, -0x7270($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7270);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c128c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c128c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C128C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1294: beq         $t6, $zero, L_801C132C
    if (ctx->r14 == 0) {
        // 0x801C1298: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C132C;
    }
    // 0x801C1298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C129C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801C12A0: lhu         $t8, -0x6B8A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6B8A);
    // 0x801C12A4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C12A8: addiu       $v0, $v0, -0x7268
    ctx->r2 = ADD32(ctx->r2, -0X7268);
    // 0x801C12AC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C12B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C12B4: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x801C12B8: beq         $t9, $zero, L_801C12E8
    if (ctx->r25 == 0) {
        // 0x801C12BC: sw          $t7, -0x726C($at)
        MEM_W(-0X726C, ctx->r1) = ctx->r15;
            goto L_801C12E8;
    }
    // 0x801C12BC: sw          $t7, -0x726C($at)
    MEM_W(-0X726C, ctx->r1) = ctx->r15;
    // 0x801C12C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C12C4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C12C8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801C12CC: addiu       $a3, $a3, -0x3190
    ctx->r7 = ADD32(ctx->r7, -0X3190);
    // 0x801C12D0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801C12D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801C12D8: jal         0x8001B204
    // 0x801C12DC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C12DC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x801C12E0: b           L_801C1304
    // 0x801C12E4: nop

        goto L_801C1304;
    // 0x801C12E4: nop

L_801C12E8:
    // 0x801C12E8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C12EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C12F0: addiu       $a3, $a3, -0x3170
    ctx->r7 = ADD32(ctx->r7, -0X3170);
    // 0x801C12F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801C12F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801C12FC: jal         0x8001B204
    // 0x801C1300: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C1300: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
L_801C1304:
    // 0x801C1304: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1308: lw          $v0, -0x7268($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7268);
    // 0x801C130C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801C1310: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C1314: beql        $v0, $zero, L_801C1330
    if (ctx->r2 == 0) {
        // 0x801C1318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C1330;
    }
    goto skip_0;
    // 0x801C1318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C131C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1320: lw          $v0, -0x726C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X726C);
    // 0x801C1324: b           L_801C132C
    // 0x801C1328: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_801C132C;
    // 0x801C1328: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_801C132C:
    // 0x801C132C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1330:
    // 0x801C1330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1334: jr          $ra
    // 0x801C1338: nop

    return;
    // 0x801C1338: nop

;}
RECOMP_FUNC void M24_FUN_801c133c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C133C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1344: jal         0x801C0C08
    // 0x801C1348: nop

    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C1348: nop

    after_0:
    // 0x801C134C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1350: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C1354: lw          $t7, -0x725C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X725C);
    // 0x801C1358: lw          $t6, -0x7260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7260);
    // 0x801C135C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C1360: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C1364: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x801C1368: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C136C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C1370: jal         0x80026F58
    // 0x801C1374: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C1374: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_1:
    // 0x801C1378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C137C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C1380: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C1384: jal         0x80026E58
    // 0x801C1388: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C1388: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C138C: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x801C1390: bgtz        $a0, L_801C13A8
    if (SIGNED(ctx->r4) > 0) {
        // 0x801C1394: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C13A8;
    }
    // 0x801C1394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1398: lui         $at, 0x98
    ctx->r1 = S32(0X98 << 16);
    // 0x801C139C: ori         $at, $at, 0x9680
    ctx->r1 = ctx->r1 | 0X9680;
    // 0x801C13A0: sltu        $a0, $v1, $at
    ctx->r4 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x801C13A4: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_801C13A8:
    // 0x801C13A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801C13AC: jr          $ra
    // 0x801C13B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C13B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c13b4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c13b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C13B4: nop

    // 0x801C13B8: nop

    // 0x801C13BC: nop

;}
RECOMP_FUNC void M24_FUN_801c13c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C13C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C13C4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C13C8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C13CC: addiu       $v0, $v0, -0x141C
    ctx->r2 = ADD32(ctx->r2, -0X141C);
    // 0x801C13D0: addiu       $v1, $v1, -0x143C
    ctx->r3 = ADD32(ctx->r3, -0X143C);
    // 0x801C13D4: sw          $zero, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = 0;
L_801C13D8:
    // 0x801C13D8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C13DC: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C13E0: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C13E4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C13E8: bne         $v1, $v0, L_801C13D8
    if (ctx->r3 != ctx->r2) {
        // 0x801C13EC: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_801C13D8;
    }
    // 0x801C13EC: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C13F0: jr          $ra
    // 0x801C13F4: nop

    return;
    // 0x801C13F4: nop

;}
RECOMP_FUNC void M24_FUN_801c13f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C13F8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C13FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1400: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801C1404: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C1408: jr          $ra
    // 0x801C140C: sw          $t6, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->r14;
    return;
    // 0x801C140C: sw          $t6, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1410(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1410: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C1414: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1418: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801C141C: jr          $ra
    // 0x801C1420: sw          $zero, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = 0;
    return;
    // 0x801C1420: sw          $zero, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1424(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1424: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C1428: addiu       $t7, $t7, -0x1440
    ctx->r15 = ADD32(ctx->r15, -0X1440);
    // 0x801C142C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C1430: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C1434: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801C1438: beq         $v1, $zero, L_801C1444
    if (ctx->r3 == 0) {
        // 0x801C143C: nop
    
            goto L_801C1444;
    }
    // 0x801C143C: nop

    // 0x801C1440: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801C1444:
    // 0x801C1444: jr          $ra
    // 0x801C1448: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801C1448: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c144c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c144c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C144C: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C1450: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801C1454: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C1458: addiu       $a2, $a2, -0x1440
    ctx->r6 = ADD32(ctx->r6, -0X1440);
    // 0x801C145C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801C1460:
    // 0x801C1460: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x801C1464: beq         $t6, $zero, L_801C1478
    if (ctx->r14 == 0) {
        // 0x801C1468: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_801C1478;
    }
    // 0x801C1468: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x801C146C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x801C1470: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C1474: and         $v1, $v1, $t9
    ctx->r3 = ctx->r3 & ctx->r25;
L_801C1478:
    // 0x801C1478: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801C147C: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x801C1480: bne         $at, $zero, L_801C1460
    if (ctx->r1 != 0) {
        // 0x801C1484: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_801C1460;
    }
    // 0x801C1484: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x801C1488: beq         $v1, $zero, L_801C1510
    if (ctx->r3 == 0) {
        // 0x801C148C: andi        $t0, $a0, 0x1
        ctx->r8 = ctx->r4 & 0X1;
            goto L_801C1510;
    }
    // 0x801C148C: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x801C1490: beq         $t0, $zero, L_801C14A0
    if (ctx->r8 == 0) {
        // 0x801C1494: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801C14A0;
    }
    // 0x801C1494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C1498: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C149C: sw          $zero, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = 0;
L_801C14A0:
    // 0x801C14A0: srl         $v0, $a0, 1
    ctx->r2 = S32(U32(ctx->r4) >> 1);
    // 0x801C14A4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_801C14A8:
    // 0x801C14A8: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x801C14AC: beq         $t1, $zero, L_801C14C0
    if (ctx->r9 == 0) {
        // 0x801C14B0: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_801C14C0;
    }
    // 0x801C14B0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x801C14B4: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x801C14B8: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x801C14BC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_801C14C0:
    // 0x801C14C0: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x801C14C4: beq         $t4, $zero, L_801C14D8
    if (ctx->r12 == 0) {
        // 0x801C14C8: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_801C14D8;
    }
    // 0x801C14C8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x801C14CC: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x801C14D0: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x801C14D4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_801C14D8:
    // 0x801C14D8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801C14DC: beq         $t7, $zero, L_801C14F0
    if (ctx->r15 == 0) {
        // 0x801C14E0: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_801C14F0;
    }
    // 0x801C14E0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x801C14E4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801C14E8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x801C14EC: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
L_801C14F0:
    // 0x801C14F0: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x801C14F4: beq         $t0, $zero, L_801C1504
    if (ctx->r8 == 0) {
        // 0x801C14F8: sll         $t1, $a1, 2
        ctx->r9 = S32(ctx->r5 << 2);
            goto L_801C1504;
    }
    // 0x801C14F8: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x801C14FC: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x801C1500: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
L_801C1504:
    // 0x801C1504: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801C1508: bne         $a1, $a0, L_801C14A8
    if (ctx->r5 != ctx->r4) {
        // 0x801C150C: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_801C14A8;
    }
    // 0x801C150C: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
L_801C1510:
    // 0x801C1510: jr          $ra
    // 0x801C1514: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801C1514: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1518(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1518: nop

    // 0x801C151C: nop

;}
RECOMP_FUNC void M24_FUN_801c1520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1520: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1524: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1528: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C152C: sw          $zero, -0x7250($at)
    MEM_W(-0X7250, ctx->r1) = 0;
    // 0x801C1530: addiu       $a0, $a0, -0x1290
    ctx->r4 = ADD32(ctx->r4, -0X1290);
    // 0x801C1534: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x801C1538: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801C153C:
    // 0x801C153C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x801C1540: sw          $v0, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r2;
    // 0x801C1544: sw          $v0, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r2;
    // 0x801C1548: sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // 0x801C154C: sw          $v0, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r2;
    // 0x801C1550: sw          $v0, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r2;
    // 0x801C1554: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C1558: sw          $v0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r2;
    // 0x801C155C: sw          $v0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r2;
    // 0x801C1560: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C1564: sw          $v0, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r2;
    // 0x801C1568: sw          $v0, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r2;
    // 0x801C156C: bne         $v1, $a0, L_801C153C
    if (ctx->r3 != ctx->r4) {
        // 0x801C1570: sw          $zero, -0x28($v1)
        MEM_W(-0X28, ctx->r3) = 0;
            goto L_801C153C;
    }
    // 0x801C1570: sw          $zero, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = 0;
    // 0x801C1574: jr          $ra
    // 0x801C1578: nop

    return;
    // 0x801C1578: nop

;}
RECOMP_FUNC void M24_FUN_801c157c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C157C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1580(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1584: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1588: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1590: addiu       $v0, $v0, -0x1410
    ctx->r2 = ADD32(ctx->r2, -0X1410);
    // 0x801C1594: addiu       $a0, $a0, -0x1290
    ctx->r4 = ADD32(ctx->r4, -0X1290);
    // 0x801C1598: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C159C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C15A0:
    // 0x801C15A0: bnel        $v1, $t6, L_801C15D0
    if (ctx->r3 != ctx->r14) {
        // 0x801C15A4: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_801C15D0;
    }
    goto skip_0;
    // 0x801C15A4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    skip_0:
    // 0x801C15A8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C15AC: addiu       $v1, $v1, -0x7250
    ctx->r3 = ADD32(ctx->r3, -0X7250);
    // 0x801C15B0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801C15B4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x801C15B8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801C15BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801C15C0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801C15C4: b           L_801C15D8
    // 0x801C15C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_801C15D8;
    // 0x801C15C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C15CC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_801C15D0:
    // 0x801C15D0: bnel        $v0, $a0, L_801C15A0
    if (ctx->r2 != ctx->r4) {
        // 0x801C15D4: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C15A0;
    }
    goto skip_1;
    // 0x801C15D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_801C15D8:
    // 0x801C15D8: jal         0x801C1834
    // 0x801C15DC: nop

    LOOKUP_FUNC(0x801C1834)(rdram, ctx);
        goto after_0;
    // 0x801C15DC: nop

    after_0:
    // 0x801C15E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C15E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C15E8: jr          $ra
    // 0x801C15EC: nop

    return;
    // 0x801C15EC: nop

;}
RECOMP_FUNC void M24_FUN_801c15f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C15F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C15F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C15F8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C15FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1600: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1604: addiu       $v0, $v0, -0x1410
    ctx->r2 = ADD32(ctx->r2, -0X1410);
    // 0x801C1608: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C160C:
    // 0x801C160C: bnel        $a0, $t6, L_801C164C
    if (ctx->r4 != ctx->r14) {
        // 0x801C1610: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_801C164C;
    }
    goto skip_0;
    // 0x801C1610: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    skip_0:
    // 0x801C1614: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x801C1618: bnel        $a1, $t7, L_801C164C
    if (ctx->r5 != ctx->r15) {
        // 0x801C161C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_801C164C;
    }
    goto skip_1;
    // 0x801C161C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    skip_1:
    // 0x801C1620: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1624: addiu       $a0, $a0, -0x7250
    ctx->r4 = ADD32(ctx->r4, -0X7250);
    // 0x801C1628: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801C162C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C1630: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801C1634: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801C1638: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x801C163C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801C1640: b           L_801C1654
    // 0x801C1644: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_801C1654;
    // 0x801C1644: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801C1648: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_801C164C:
    // 0x801C164C: bnel        $v0, $v1, L_801C160C
    if (ctx->r2 != ctx->r3) {
        // 0x801C1650: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C160C;
    }
    goto skip_2;
    // 0x801C1650: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_2:
L_801C1654:
    // 0x801C1654: jal         0x801C1834
    // 0x801C1658: nop

    LOOKUP_FUNC(0x801C1834)(rdram, ctx);
        goto after_0;
    // 0x801C1658: nop

    after_0:
    // 0x801C165C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1664: jr          $ra
    // 0x801C1668: nop

    return;
    // 0x801C1668: nop

;}
RECOMP_FUNC void M24_FUN_801c166c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C166C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1670: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1674: addiu       $v0, $v0, -0x1290
    ctx->r2 = ADD32(ctx->r2, -0X1290);
    // 0x801C1678: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x801C167C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1680:
    // 0x801C1680: bnel        $a0, $t6, L_801C16A0
    if (ctx->r4 != ctx->r14) {
        // 0x801C1684: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C16A0;
    }
    goto skip_0;
    // 0x801C1684: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801C1688: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C168C: bne         $a1, $t7, L_801C169C
    if (ctx->r5 != ctx->r15) {
        // 0x801C1690: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801C169C;
    }
    // 0x801C1690: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C1694: jr          $ra
    // 0x801C1698: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    return;
    // 0x801C1698: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
L_801C169C:
    // 0x801C169C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801C16A0:
    // 0x801C16A0: bnel        $v1, $v0, L_801C1680
    if (ctx->r3 != ctx->r2) {
        // 0x801C16A4: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1680;
    }
    goto skip_1;
    // 0x801C16A4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801C16A8: jr          $ra
    // 0x801C16AC: nop

    return;
    // 0x801C16AC: nop

;}
RECOMP_FUNC void M24_FUN_801c16b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C16B0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C16B4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C16B8: addiu       $v0, $v0, -0x1290
    ctx->r2 = ADD32(ctx->r2, -0X1290);
    // 0x801C16BC: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x801C16C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C16C4:
    // 0x801C16C4: bnel        $a0, $t6, L_801C16E4
    if (ctx->r4 != ctx->r14) {
        // 0x801C16C8: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C16E4;
    }
    goto skip_0;
    // 0x801C16C8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801C16CC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C16D0: bnel        $a1, $t7, L_801C16E4
    if (ctx->r5 != ctx->r15) {
        // 0x801C16D4: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C16E4;
    }
    goto skip_1;
    // 0x801C16D4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_1:
    // 0x801C16D8: jr          $ra
    // 0x801C16DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    return;
    // 0x801C16DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801C16E0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801C16E4:
    // 0x801C16E4: bnel        $v1, $v0, L_801C16C4
    if (ctx->r3 != ctx->r2) {
        // 0x801C16E8: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C16C4;
    }
    goto skip_2;
    // 0x801C16E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x801C16EC: jr          $ra
    // 0x801C16F0: nop

    return;
    // 0x801C16F0: nop

;}
RECOMP_FUNC void M24_FUN_801c16f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C16F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C16F8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C16FC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C1708: addiu       $a1, $a1, -0x1290
    ctx->r5 = ADD32(ctx->r5, -0X1290);
    // 0x801C170C: addiu       $v0, $v0, -0x1410
    ctx->r2 = ADD32(ctx->r2, -0X1410);
    // 0x801C1710: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C1714: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C1718:
    // 0x801C1718: beql        $v1, $t6, L_801C1738
    if (ctx->r3 == ctx->r14) {
        // 0x801C171C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_801C1738;
    }
    goto skip_0;
    // 0x801C171C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    skip_0:
    // 0x801C1720: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x801C1724: beql        $v1, $t7, L_801C1738
    if (ctx->r3 == ctx->r15) {
        // 0x801C1728: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_801C1738;
    }
    goto skip_1;
    // 0x801C1728: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    skip_1:
    // 0x801C172C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x801C1730: and         $a0, $a0, $t8
    ctx->r4 = ctx->r4 & ctx->r24;
    // 0x801C1734: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_801C1738:
    // 0x801C1738: bnel        $v0, $a1, L_801C1718
    if (ctx->r2 != ctx->r5) {
        // 0x801C173C: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C1718;
    }
    goto skip_2;
    // 0x801C173C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x801C1740: jal         0x801C1834
    // 0x801C1744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C1834)(rdram, ctx);
        goto after_0;
    // 0x801C1744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801C1748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C174C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801C1750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1754: jr          $ra
    // 0x801C1758: nop

    return;
    // 0x801C1758: nop

;}
RECOMP_FUNC void M24_FUN_801c175c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C175C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1760: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x801C1764: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C1768: beq         $t6, $zero, L_801C1778
    if (ctx->r14 == 0) {
            // 0x801C176C: nop

    LOOKUP_FUNC(0x801C1778)(rdram, ctx);
    return;
    }
    // 0x801C176C: nop

    // 0x801C1770: jr          $ra
    // 0x801C1774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1778(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1778: jr          $ra
    // 0x801C177C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801C177C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1780(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1780: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1784: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1788: addiu       $v0, $v0, -0x1290
    ctx->r2 = ADD32(ctx->r2, -0X1290);
    // 0x801C178C: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x801C1790: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1794:
    // 0x801C1794: bnel        $a0, $t6, L_801C17B4
    if (ctx->r4 != ctx->r14) {
        // 0x801C1798: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_801C17B4;
    }
    goto skip_0;
    // 0x801C1798: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x801C179C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C17A0: bnel        $a1, $t7, L_801C17B4
    if (ctx->r5 != ctx->r15) {
        // 0x801C17A4: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_801C17B4;
    }
    goto skip_1;
    // 0x801C17A4: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x801C17A8: jr          $ra
    // 0x801C17AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C17AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C17B0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_801C17B4:
    // 0x801C17B4: bnel        $a0, $t8, L_801C17D4
    if (ctx->r4 != ctx->r24) {
        // 0x801C17B8: lw          $t0, 0x18($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X18);
            goto L_801C17D4;
    }
    goto skip_2;
    // 0x801C17B8: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x801C17BC: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x801C17C0: bnel        $a1, $t9, L_801C17D4
    if (ctx->r5 != ctx->r25) {
        // 0x801C17C4: lw          $t0, 0x18($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X18);
            goto L_801C17D4;
    }
    goto skip_3;
    // 0x801C17C4: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    skip_3:
    // 0x801C17C8: jr          $ra
    // 0x801C17CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C17CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C17D0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
L_801C17D4:
    // 0x801C17D4: bnel        $a0, $t0, L_801C17F4
    if (ctx->r4 != ctx->r8) {
        // 0x801C17D8: lw          $t2, 0x24($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X24);
            goto L_801C17F4;
    }
    goto skip_4;
    // 0x801C17D8: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    skip_4:
    // 0x801C17DC: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x801C17E0: bnel        $a1, $t1, L_801C17F4
    if (ctx->r5 != ctx->r9) {
        // 0x801C17E4: lw          $t2, 0x24($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X24);
            goto L_801C17F4;
    }
    goto skip_5;
    // 0x801C17E4: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    skip_5:
    // 0x801C17E8: jr          $ra
    // 0x801C17EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C17EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C17F0: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
L_801C17F4:
    // 0x801C17F4: bnel        $a0, $t2, L_801C1814
    if (ctx->r4 != ctx->r10) {
        // 0x801C17F8: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_801C1814;
    }
    goto skip_6;
    // 0x801C17F8: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_6:
    // 0x801C17FC: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x801C1800: bnel        $a1, $t3, L_801C1814
    if (ctx->r5 != ctx->r11) {
        // 0x801C1804: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_801C1814;
    }
    goto skip_7;
    // 0x801C1804: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_7:
    // 0x801C1808: jr          $ra
    // 0x801C180C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C180C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1810: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_801C1814:
    // 0x801C1814: bnel        $v1, $v0, L_801C1794
    if (ctx->r3 != ctx->r2) {
        // 0x801C1818: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1794;
    }
    goto skip_8;
    // 0x801C1818: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_8:
    // 0x801C181C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C1820: jr          $ra
    // 0x801C1824: nop

    return;
    // 0x801C1824: nop

;}
RECOMP_FUNC void M24_FUN_801c1828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1828: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C182C: jr          $ra
    // 0x801C1830: lw          $v0, -0x7250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7250);
    return;
    // 0x801C1830: lw          $v0, -0x7250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7250);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1834(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1834: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1838: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C183C: addiu       $a0, $a0, -0x1290
    ctx->r4 = ADD32(ctx->r4, -0X1290);
    // 0x801C1840: addiu       $v1, $v1, -0x1410
    ctx->r3 = ADD32(ctx->r3, -0X1410);
    // 0x801C1844: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_801C1848:
    // 0x801C1848: bnel        $v1, $a0, L_801C1848
    if (ctx->r3 != ctx->r4) {
        // 0x801C184C: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_801C1848;
    }
    goto skip_0;
    // 0x801C184C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_0:
    // 0x801C1850: jr          $ra
    // 0x801C1854: nop

    return;
    // 0x801C1854: nop

;}
RECOMP_FUNC void M24_FUN_801c1858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1858: nop

    // 0x801C185C: nop

;}
RECOMP_FUNC void M24_FUN_801c1860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1860: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1864: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1868: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C186C: sw          $zero, -0x7240($at)
    MEM_W(-0X7240, ctx->r1) = 0;
    // 0x801C1870: addiu       $a0, $a0, -0x1090
    ctx->r4 = ADD32(ctx->r4, -0X1090);
    // 0x801C1874: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1878: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801C187C:
    // 0x801C187C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x801C1880: sw          $v0, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r2;
    // 0x801C1884: sw          $v0, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r2;
    // 0x801C1888: sw          $v0, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->r2;
    // 0x801C188C: sw          $zero, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = 0;
    // 0x801C1890: sw          $v0, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r2;
    // 0x801C1894: sw          $v0, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r2;
    // 0x801C1898: sw          $v0, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r2;
    // 0x801C189C: sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // 0x801C18A0: sw          $v0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r2;
    // 0x801C18A4: sw          $v0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r2;
    // 0x801C18A8: sw          $v0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r2;
    // 0x801C18AC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C18B0: sw          $v0, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r2;
    // 0x801C18B4: sw          $v0, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r2;
    // 0x801C18B8: sw          $v0, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r2;
    // 0x801C18BC: bne         $v1, $a0, L_801C187C
    if (ctx->r3 != ctx->r4) {
        // 0x801C18C0: sw          $zero, -0x34($v1)
        MEM_W(-0X34, ctx->r3) = 0;
            goto L_801C187C;
    }
    // 0x801C18C0: sw          $zero, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = 0;
    // 0x801C18C4: jr          $ra
    // 0x801C18C8: nop

    return;
    // 0x801C18C8: nop

;}
RECOMP_FUNC void M24_FUN_801c18cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C18CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C18D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C18D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C18D8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801C18DC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801C18E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C18E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C18E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C18EC: blez        $a0, L_801C1948
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801C18F0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_801C1948;
    }
    // 0x801C18F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C18F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C18F8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801C18FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C1900: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801C1904: addiu       $s0, $s0, -0x1290
    ctx->r16 = ADD32(ctx->r16, -0X1290);
    // 0x801C1908: addu        $s3, $t6, $a1
    ctx->r19 = ADD32(ctx->r14, ctx->r5);
    // 0x801C190C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_801C1910:
    // 0x801C1910: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C1914: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801C1918: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x801C191C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x801C1920: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x801C1924: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x801C1928: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x801C192C: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x801C1930: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x801C1934: jal         0x801C1CF0
    // 0x801C1938: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    LOOKUP_FUNC(0x801C1CF0)(rdram, ctx);
        goto after_0;
    // 0x801C1938: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x801C193C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801C1940: bne         $s1, $s3, L_801C1910
    if (ctx->r17 != ctx->r19) {
        // 0x801C1944: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_801C1910;
    }
    // 0x801C1944: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_801C1948:
    // 0x801C1948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C194C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1950: sw          $s4, -0x7240($at)
    MEM_W(-0X7240, ctx->r1) = ctx->r20;
    // 0x801C1954: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C1958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C195C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1960: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C1964: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C1968: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C196C: jr          $ra
    // 0x801C1970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1974(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C197C: jal         0x801C1860
    // 0x801C1980: nop

    LOOKUP_FUNC(0x801C1860)(rdram, ctx);
        goto after_0;
    // 0x801C1980: nop

    after_0:
    // 0x801C1984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C198C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1990: jr          $ra
    // 0x801C1994: nop

    return;
    // 0x801C1994: nop

;}
RECOMP_FUNC void M24_FUN_801c1998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1998: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C199C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801C19A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C19A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C19A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801C19AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C19B0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801C19B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C19B8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801C19BC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801C19C0: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x801C19C4: blez        $a0, L_801C1A10
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801C19C8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801C1A10;
    }
    // 0x801C19C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C19CC: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801C19D0: addiu       $s0, $s0, -0x1290
    ctx->r16 = ADD32(ctx->r16, -0X1290);
    // 0x801C19D4: addiu       $s3, $zero, -0x4
    ctx->r19 = ADD32(0, -0X4);
    // 0x801C19D8: addiu       $t7, $s1, 0x3
    ctx->r15 = ADD32(ctx->r17, 0X3);
L_801C19DC:
    // 0x801C19DC: and         $s1, $t7, $s3
    ctx->r17 = ctx->r15 & ctx->r19;
    // 0x801C19E0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801C19E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801C19E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801C19EC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801C19F0: jal         0x801C1CF0
    // 0x801C19F4: sw          $a2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r6;
    LOOKUP_FUNC(0x801C1CF0)(rdram, ctx);
        goto after_0;
    // 0x801C19F4: sw          $a2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r6;
    after_0:
    // 0x801C19F8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801C19FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C1A00: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x801C1A04: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801C1A08: bnel        $at, $zero, L_801C19DC
    if (ctx->r1 != 0) {
        // 0x801C1A0C: addiu       $t7, $s1, 0x3
        ctx->r15 = ADD32(ctx->r17, 0X3);
            goto L_801C19DC;
    }
    goto skip_0;
    // 0x801C1A0C: addiu       $t7, $s1, 0x3
    ctx->r15 = ADD32(ctx->r17, 0X3);
    skip_0:
L_801C1A10:
    // 0x801C1A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C1A14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C1A18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C1A1C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1A20: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801C1A24: jr          $ra
    // 0x801C1A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C1A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1a2c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1a2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A2C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1A30: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1A34: addiu       $v0, $v0, -0x1090
    ctx->r2 = ADD32(ctx->r2, -0X1090);
    // 0x801C1A38: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1A3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1A40:
    // 0x801C1A40: bnel        $a0, $t6, L_801C1A60
    if (ctx->r4 != ctx->r14) {
        // 0x801C1A44: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801C1A60;
    }
    goto skip_0;
    // 0x801C1A44: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x801C1A48: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C1A4C: bne         $a1, $t7, L_801C1A5C
    if (ctx->r5 != ctx->r15) {
        // 0x801C1A50: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801C1A5C;
    }
    // 0x801C1A50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C1A54: jr          $ra
    // 0x801C1A58: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    return;
    // 0x801C1A58: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
L_801C1A5C:
    // 0x801C1A5C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_801C1A60:
    // 0x801C1A60: bnel        $v1, $v0, L_801C1A40
    if (ctx->r3 != ctx->r2) {
        // 0x801C1A64: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1A40;
    }
    goto skip_1;
    // 0x801C1A64: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801C1A68: jr          $ra
    // 0x801C1A6C: nop

    return;
    // 0x801C1A6C: nop

;}
RECOMP_FUNC void M24_FUN_801c1a70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1A70: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1A74: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1A78: addiu       $v0, $v0, -0x1090
    ctx->r2 = ADD32(ctx->r2, -0X1090);
    // 0x801C1A7C: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1A80: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1A84:
    // 0x801C1A84: bnel        $a0, $t6, L_801C1AA4
    if (ctx->r4 != ctx->r14) {
        // 0x801C1A88: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801C1AA4;
    }
    goto skip_0;
    // 0x801C1A88: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x801C1A8C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C1A90: bnel        $a1, $t7, L_801C1AA4
    if (ctx->r5 != ctx->r15) {
        // 0x801C1A94: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801C1AA4;
    }
    goto skip_1;
    // 0x801C1A94: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_1:
    // 0x801C1A98: jr          $ra
    // 0x801C1A9C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    return;
    // 0x801C1A9C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801C1AA0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_801C1AA4:
    // 0x801C1AA4: bnel        $v1, $v0, L_801C1A84
    if (ctx->r3 != ctx->r2) {
        // 0x801C1AA8: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1A84;
    }
    goto skip_2;
    // 0x801C1AA8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x801C1AAC: jr          $ra
    // 0x801C1AB0: nop

    return;
    // 0x801C1AB0: nop

;}
RECOMP_FUNC void M24_FUN_801c1ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1AB8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1ABC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C1AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1AC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C1AC8: addiu       $a1, $a1, -0x1090
    ctx->r5 = ADD32(ctx->r5, -0X1090);
    // 0x801C1ACC: addiu       $v0, $v0, -0x1290
    ctx->r2 = ADD32(ctx->r2, -0X1290);
    // 0x801C1AD0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C1AD4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C1AD8:
    // 0x801C1AD8: beql        $v1, $t6, L_801C1AF8
    if (ctx->r3 == ctx->r14) {
        // 0x801C1ADC: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_801C1AF8;
    }
    goto skip_0;
    // 0x801C1ADC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    skip_0:
    // 0x801C1AE0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x801C1AE4: beql        $v1, $t7, L_801C1AF8
    if (ctx->r3 == ctx->r15) {
        // 0x801C1AE8: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_801C1AF8;
    }
    goto skip_1;
    // 0x801C1AE8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    skip_1:
    // 0x801C1AEC: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x801C1AF0: and         $a0, $a0, $t8
    ctx->r4 = ctx->r4 & ctx->r24;
    // 0x801C1AF4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_801C1AF8:
    // 0x801C1AF8: bnel        $v0, $a1, L_801C1AD8
    if (ctx->r2 != ctx->r5) {
        // 0x801C1AFC: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C1AD8;
    }
    goto skip_2;
    // 0x801C1AFC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x801C1B00: jal         0x801C1D3C
    // 0x801C1B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C1D3C)(rdram, ctx);
        goto after_0;
    // 0x801C1B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801C1B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1B0C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801C1B10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1B14: jr          $ra
    // 0x801C1B18: nop

    return;
    // 0x801C1B18: nop

;}
RECOMP_FUNC void M24_FUN_801c1b1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C1B20: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1B24: lw          $t6, -0x7240($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7240);
    // 0x801C1B28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801C1B2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C1B30: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801C1B34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C1B38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C1B3C: bne         $t6, $zero, L_801C1B4C
    if (ctx->r14 != 0) {
        // 0x801C1B40: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_801C1B4C;
    }
    // 0x801C1B40: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x801C1B44: b           L_801C1B9C
    // 0x801C1B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C1B9C;
    // 0x801C1B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C1B4C:
    // 0x801C1B4C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801C1B50: lui         $s3, 0x801E
    ctx->r19 = S32(0X801E << 16);
    // 0x801C1B54: addiu       $s3, $s3, -0x1090
    ctx->r19 = ADD32(ctx->r19, -0X1090);
    // 0x801C1B58: addiu       $s0, $s0, -0x1290
    ctx->r16 = ADD32(ctx->r16, -0X1290);
    // 0x801C1B5C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x801C1B60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_801C1B64:
    // 0x801C1B64: beql        $s1, $a0, L_801C1B88
    if (ctx->r17 == ctx->r4) {
        // 0x801C1B68: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_801C1B88;
    }
    goto skip_0;
    // 0x801C1B68: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x801C1B6C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801C1B70: beql        $s1, $a1, L_801C1B88
    if (ctx->r17 == ctx->r5) {
        // 0x801C1B74: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_801C1B88;
    }
    goto skip_1;
    // 0x801C1B74: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_1:
    // 0x801C1B78: jal         0x801C1C90
    // 0x801C1B7C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(0x801C1C90)(rdram, ctx);
        goto after_0;
    // 0x801C1B7C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_0:
    // 0x801C1B80: and         $s2, $s2, $v0
    ctx->r18 = ctx->r18 & ctx->r2;
    // 0x801C1B84: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_801C1B88:
    // 0x801C1B88: bnel        $s0, $s3, L_801C1B64
    if (ctx->r16 != ctx->r19) {
        // 0x801C1B8C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_801C1B64;
    }
    goto skip_2;
    // 0x801C1B8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x801C1B90: jal         0x801C1D3C
    // 0x801C1B94: nop

    LOOKUP_FUNC(0x801C1D3C)(rdram, ctx);
        goto after_1;
    // 0x801C1B94: nop

    after_1:
    // 0x801C1B98: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801C1B9C:
    // 0x801C1B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801C1BA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C1BA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C1BA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1BAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801C1BB0: jr          $ra
    // 0x801C1BB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C1BB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1bb8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1bb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1BB8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1BBC: lw          $t6, -0x7240($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7240);
    // 0x801C1BC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C1BC4: beq         $t6, $zero, L_801C1BD4
    if (ctx->r14 == 0) {
            // 0x801C1BC8: nop

    LOOKUP_FUNC(0x801C1BD4)(rdram, ctx);
    return;
    }
    // 0x801C1BC8: nop

    // 0x801C1BCC: jr          $ra
    // 0x801C1BD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1BD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1bd4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1bd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1BD4: jr          $ra
    // 0x801C1BD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801C1BD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1bdc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1bdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1BDC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1BE0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1BE4: addiu       $v0, $v0, -0x1090
    ctx->r2 = ADD32(ctx->r2, -0X1090);
    // 0x801C1BE8: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1BEC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801C1BF0:
    // 0x801C1BF0: bnel        $a0, $t6, L_801C1C10
    if (ctx->r4 != ctx->r14) {
        // 0x801C1BF4: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_801C1C10;
    }
    goto skip_0;
    // 0x801C1BF4: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x801C1BF8: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C1BFC: bnel        $a1, $t7, L_801C1C10
    if (ctx->r5 != ctx->r15) {
        // 0x801C1C00: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_801C1C10;
    }
    goto skip_1;
    // 0x801C1C00: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_1:
    // 0x801C1C04: jr          $ra
    // 0x801C1C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1C0C: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_801C1C10:
    // 0x801C1C10: bnel        $a0, $t8, L_801C1C30
    if (ctx->r4 != ctx->r24) {
        // 0x801C1C14: lw          $t0, 0x20($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X20);
            goto L_801C1C30;
    }
    goto skip_2;
    // 0x801C1C14: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    skip_2:
    // 0x801C1C18: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x801C1C1C: bnel        $a1, $t9, L_801C1C30
    if (ctx->r5 != ctx->r25) {
        // 0x801C1C20: lw          $t0, 0x20($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X20);
            goto L_801C1C30;
    }
    goto skip_3;
    // 0x801C1C20: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    skip_3:
    // 0x801C1C24: jr          $ra
    // 0x801C1C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1C2C: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
L_801C1C30:
    // 0x801C1C30: bnel        $a0, $t0, L_801C1C50
    if (ctx->r4 != ctx->r8) {
        // 0x801C1C34: lw          $t2, 0x30($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X30);
            goto L_801C1C50;
    }
    goto skip_4;
    // 0x801C1C34: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    skip_4:
    // 0x801C1C38: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x801C1C3C: bnel        $a1, $t1, L_801C1C50
    if (ctx->r5 != ctx->r9) {
        // 0x801C1C40: lw          $t2, 0x30($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X30);
            goto L_801C1C50;
    }
    goto skip_5;
    // 0x801C1C40: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    skip_5:
    // 0x801C1C44: jr          $ra
    // 0x801C1C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1C4C: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
L_801C1C50:
    // 0x801C1C50: bnel        $a0, $t2, L_801C1C70
    if (ctx->r4 != ctx->r10) {
        // 0x801C1C54: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_801C1C70;
    }
    goto skip_6;
    // 0x801C1C54: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    skip_6:
    // 0x801C1C58: lw          $t3, 0x34($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X34);
    // 0x801C1C5C: bnel        $a1, $t3, L_801C1C70
    if (ctx->r5 != ctx->r11) {
        // 0x801C1C60: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_801C1C70;
    }
    goto skip_7;
    // 0x801C1C60: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    skip_7:
    // 0x801C1C64: jr          $ra
    // 0x801C1C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C1C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C1C6C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_801C1C70:
    // 0x801C1C70: bnel        $v1, $v0, L_801C1BF0
    if (ctx->r3 != ctx->r2) {
        // 0x801C1C74: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801C1BF0;
    }
    goto skip_8;
    // 0x801C1C74: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_8:
    // 0x801C1C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C1C7C: jr          $ra
    // 0x801C1C80: nop

    return;
    // 0x801C1C80: nop

;}
RECOMP_FUNC void M24_FUN_801c1c84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1C84: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1C88: jr          $ra
    // 0x801C1C8C: lw          $v0, -0x7240($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7240);
    return;
    // 0x801C1C8C: lw          $v0, -0x7240($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7240);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1c90(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1C90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C1C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1C98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C1C9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801C1CA0: jal         0x801BF680
    // 0x801C1CA4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(0x801BF680)(rdram, ctx);
        goto after_0;
    // 0x801C1CA4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x801C1CA8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801C1CAC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801C1CB0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801C1CB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C1CB8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801C1CBC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801C1CC0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801C1CC4: lw          $v1, 0xC($t9)
    ctx->r3 = MEM_W(ctx->r25, 0XC);
    // 0x801C1CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1CCC: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x801C1CD0: xor         $v0, $a1, $v1
    ctx->r2 = ctx->r5 ^ ctx->r3;
    // 0x801C1CD4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C1CD8: bne         $v0, $zero, L_801C1CE8
    if (ctx->r2 != 0) {
        // 0x801C1CDC: nop
    
            goto L_801C1CE8;
    }
    // 0x801C1CDC: nop

    // 0x801C1CE0: xor         $v0, $a0, $v1
    ctx->r2 = ctx->r4 ^ ctx->r3;
    // 0x801C1CE4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_801C1CE8:
    // 0x801C1CE8: jr          $ra
    // 0x801C1CEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801C1CEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1cf0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1cf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1CF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C1CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1CF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C1CFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801C1D00: jal         0x801BF680
    // 0x801C1D04: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801BF680)(rdram, ctx);
        goto after_0;
    // 0x801C1D04: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x801C1D08: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801C1D0C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801C1D10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801C1D14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C1D18: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801C1D1C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801C1D20: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801C1D24: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801C1D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C1D30: slt         $v0, $t1, $t0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801C1D34: jr          $ra
    // 0x801C1D38: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x801C1D38: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1d3c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D3C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C1D40: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C1D44: addiu       $a0, $a0, -0x1090
    ctx->r4 = ADD32(ctx->r4, -0X1090);
    // 0x801C1D48: addiu       $v1, $v1, -0x1290
    ctx->r3 = ADD32(ctx->r3, -0X1290);
    // 0x801C1D4C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_801C1D50:
    // 0x801C1D50: bnel        $v1, $a0, L_801C1D50
    if (ctx->r3 != ctx->r4) {
        // 0x801C1D54: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_801C1D50;
    }
    goto skip_0;
    // 0x801C1D54: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    skip_0:
    // 0x801C1D58: jr          $ra
    // 0x801C1D5C: nop

    return;
    // 0x801C1D5C: nop

;}
RECOMP_FUNC void M24_FUN_801c1d60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1D64: sw          $zero, -0x7230($at)
    MEM_W(-0X7230, ctx->r1) = 0;
    // 0x801C1D68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1D6C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1D70: sw          $zero, -0x722C($at)
    MEM_W(-0X722C, ctx->r1) = 0;
    // 0x801C1D74: addiu       $v0, $v0, -0x7224
    ctx->r2 = ADD32(ctx->r2, -0X7224);
    // 0x801C1D78: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C1D7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1D80: sw          $zero, -0x7228($at)
    MEM_W(-0X7228, ctx->r1) = 0;
    // 0x801C1D84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1D88: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801C1D8C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801C1D90: sw          $t9, -0x721C($at)
    MEM_W(-0X721C, ctx->r1) = ctx->r25;
    // 0x801C1D94: jr          $ra
    // 0x801C1D98: sw          $t8, -0x7220($at)
    MEM_W(-0X7220, ctx->r1) = ctx->r24;
    return;
    // 0x801C1D98: sw          $t8, -0x7220($at)
    MEM_W(-0X7220, ctx->r1) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1d9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1d9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1D9C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1DA0: jr          $ra
    // 0x801C1DA4: lw          $v0, -0x7230($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7230);
    return;
    // 0x801C1DA4: lw          $v0, -0x7230($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7230);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1da8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1da8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1DA8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1DAC: lw          $t6, -0x7230($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7230);
    // 0x801C1DB0: sltu        $v0, $t6, $a0
    ctx->r2 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x801C1DB4: jr          $ra
    // 0x801C1DB8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x801C1DB8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1dbc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1dbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1DBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C1DC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1DC4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1DC8: sw          $t6, -0x722C($at)
    MEM_W(-0X722C, ctx->r1) = ctx->r14;
    // 0x801C1DCC: addiu       $v0, $v0, -0x7224
    ctx->r2 = ADD32(ctx->r2, -0X7224);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1dd0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1dd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1DD8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C1DDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1DE0: jal         0x801C0C08
    // 0x801C1DE4: sw          $zero, -0x7228($at)
    MEM_W(-0X7228, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C1DE4: sw          $zero, -0x7228($at)
    MEM_W(-0X7228, ctx->r1) = 0;
    after_0:
    // 0x801C1DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1DEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1DF0: sw          $v0, -0x7220($at)
    MEM_W(-0X7220, ctx->r1) = ctx->r2;
    // 0x801C1DF4: sw          $v1, -0x721C($at)
    MEM_W(-0X721C, ctx->r1) = ctx->r3;
    // 0x801C1DF8: jr          $ra
    // 0x801C1DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C1DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1e00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1e00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1E04: sw          $zero, -0x722C($at)
    MEM_W(-0X722C, ctx->r1) = 0;
    // 0x801C1E08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1E0C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801C1E10: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x801C1E14: sw          $t7, -0x721C($at)
    MEM_W(-0X721C, ctx->r1) = ctx->r15;
    // 0x801C1E18: jr          $ra
    // 0x801C1E1C: sw          $t6, -0x7220($at)
    MEM_W(-0X7220, ctx->r1) = ctx->r14;
    return;
    // 0x801C1E1C: sw          $t6, -0x7220($at)
    MEM_W(-0X7220, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1e20(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1e20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E20: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1E24: jr          $ra
    // 0x801C1E28: lw          $v0, -0x722C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X722C);
    return;
    // 0x801C1E28: lw          $v0, -0x722C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X722C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1e2c(rdram, ctx);
;}
