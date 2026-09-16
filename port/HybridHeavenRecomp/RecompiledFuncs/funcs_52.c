#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d1258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1258: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D125C: addiu       $v0, $v0, 0x1334
    ctx->r2 = ADD32(ctx->r2, 0X1334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1260(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D1268: beq         $a0, $zero, L_801D1294
    if (ctx->r4 == 0) {
        // 0x801D126C: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D1294;
    }
    // 0x801D126C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D1270: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1274: jal         0x801C0B2C
    // 0x801D1278: sw          $zero, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D1278: sw          $zero, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = 0;
    after_0:
    // 0x801D127C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1280: sw          $v0, 0x1358($at)
    MEM_W(0X1358, ctx->r1) = ctx->r2;
    // 0x801D1284: sw          $v1, 0x135C($at)
    MEM_W(0X135C, ctx->r1) = ctx->r3;
    // 0x801D1288: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D128C: b           L_801D12A8
    // 0x801D1290: sw          $zero, 0x1360($at)
    MEM_W(0X1360, ctx->r1) = 0;
        goto L_801D12A8;
    // 0x801D1290: sw          $zero, 0x1360($at)
    MEM_W(0X1360, ctx->r1) = 0;
L_801D1294:
    // 0x801D1294: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1298: lw          $a0, 0x1330($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1330);
    // 0x801D129C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D12A0: jal         0x8012D894
    // 0x801D12A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x801D12A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
L_801D12A8:
    // 0x801D12A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D12AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D12B0: jr          $ra
    // 0x801D12B4: nop

    return;
    // 0x801D12B4: nop

;}
RECOMP_FUNC void M24_FUN_801d12b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D12B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D12BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D12C0: jal         0x801C0B2C
    // 0x801D12C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D12C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D12C8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D12CC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D12D0: lw          $t7, 0x135C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X135C);
    // 0x801D12D4: lw          $t6, 0x1358($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1358);
    // 0x801D12D8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D12DC: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D12E0: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D12E4: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D12E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D12EC: jal         0x80034C24
    // 0x801D12F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D12F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D12F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D12F8: ldc1        $f4, -0x2B60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2B60);
    // 0x801D12FC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D1300: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, 0X1360);
    // 0x801D1304: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D1308: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D130C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D1310: addiu       $t1, $t1, -0x4F4C
    ctx->r9 = ADD32(ctx->r9, -0X4F4C);
    // 0x801D1314: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D1318: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D131C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D1320: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D1324: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D1328: nop

    // 0x801D132C: bc1fl       L_801D140C
    if (!c1cs) {
        // 0x801D1330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D140C;
    }
    goto skip_0;
    // 0x801D1330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D1334: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D1338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D133C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D1340: beq         $v0, $zero, L_801D1364
    if (ctx->r2 == 0) {
        // 0x801D1344: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_801D1364;
    }
    // 0x801D1344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801D1348: beq         $v0, $at, L_801D1380
    if (ctx->r2 == ctx->r1) {
        // 0x801D134C: addiu       $a1, $zero, 0x140
        ctx->r5 = ADD32(0, 0X140);
            goto L_801D1380;
    }
    // 0x801D134C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D1350: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D1354: beq         $v0, $at, L_801D13A0
    if (ctx->r2 == ctx->r1) {
        // 0x801D1358: addiu       $a1, $zero, 0x140
        ctx->r5 = ADD32(0, 0X140);
            goto L_801D13A0;
    }
    // 0x801D1358: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D135C: b           L_801D13C0
    // 0x801D1360: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D13C0;
    // 0x801D1360: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D1364:
    // 0x801D1364: jal         0x8012D894
    // 0x801D1368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_2;
    // 0x801D1368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D136C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1370: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D1374: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, 0X1360);
    // 0x801D1378: b           L_801D13BC
    // 0x801D137C: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
        goto L_801D13BC;
    // 0x801D137C: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
L_801D1380:
    // 0x801D1380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D1384: jal         0x8012D894
    // 0x801D1388: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_3;
    // 0x801D1388: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x801D138C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1390: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D1394: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, 0X1360);
    // 0x801D1398: b           L_801D13BC
    // 0x801D139C: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
        goto L_801D13BC;
    // 0x801D139C: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
L_801D13A0:
    // 0x801D13A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D13A4: jal         0x8012D894
    // 0x801D13A8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_4;
    // 0x801D13A8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x801D13AC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D13B0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D13B4: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, 0X1360);
    // 0x801D13B8: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
L_801D13BC:
    // 0x801D13BC: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D13C0:
    // 0x801D13C0: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D13C4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D13C8: bne         $at, $zero, L_801D13F4
    if (ctx->r1 != 0) {
        // 0x801D13CC: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D13F4;
    }
    // 0x801D13CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D13D0: jal         0x801C0B2C
    // 0x801D13D4: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D13D4: nop

    after_5:
    // 0x801D13D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D13DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D13E0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D13E4: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, 0X1360);
    // 0x801D13E8: lw          $a0, 0x1360($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1360);
    // 0x801D13EC: sw          $v0, 0x1358($at)
    MEM_W(0X1358, ctx->r1) = ctx->r2;
    // 0x801D13F0: sw          $v1, 0x135C($at)
    MEM_W(0X135C, ctx->r1) = ctx->r3;
L_801D13F4:
    // 0x801D13F4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D13F8: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D13FC: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D1400: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D1404: nop

    // 0x801D1408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D140C:
    // 0x801D140C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1410: jr          $ra
    // 0x801D1414: nop

    return;
    // 0x801D1414: nop

;}
RECOMP_FUNC void M24_FUN_801d1418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1418: nop

    // 0x801D141C: nop

;}
RECOMP_FUNC void M24_FUN_801d1420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1420: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1424: sw          $zero, -0x4EBC($at)
    MEM_W(-0X4EBC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1428(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D142C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1430: sw          $zero, -0x4EB8($at)
    MEM_W(-0X4EB8, ctx->r1) = 0;
    // 0x801D1434: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D1438: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D143C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D1440: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1444: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D1448: addiu       $t7, $t7, 0x1474
    ctx->r15 = ADD32(ctx->r15, 0X1474);
    // 0x801D144C: sw          $t6, -0x4EB4($at)
    MEM_W(-0X4EB4, ctx->r1) = ctx->r14;
    // 0x801D1450: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D1454: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x801D1458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D145C: jal         0x8013B570
    // 0x801D1460: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D1460: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D1464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D1468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D146C: jr          $ra
    // 0x801D1470: nop

    return;
    // 0x801D1470: nop

;}
RECOMP_FUNC void M24_FUN_801d1474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D147C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D1480: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D1484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D1488: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D148C: beq         $t6, $zero, L_801D14B8
    if (ctx->r14 == 0) {
        // 0x801D1490: nop
    
            goto L_801D14B8;
    }
    // 0x801D1490: nop

    // 0x801D1494: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D1498: jal         0x8012D844
    // 0x801D149C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D149C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D14A0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D14A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D14A8: jal         0x800058DC
    // 0x801D14AC: addiu       $a1, $a1, 0x14D0
    ctx->r5 = ADD32(ctx->r5, 0X14D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D14AC: addiu       $a1, $a1, 0x14D0
    ctx->r5 = ADD32(ctx->r5, 0X14D0);
    after_1:
    // 0x801D14B0: b           L_801D14C4
    // 0x801D14B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D14C4;
    // 0x801D14B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D14B8:
    // 0x801D14B8: jal         0x800058DC
    // 0x801D14BC: addiu       $a1, $a1, 0x1474
    ctx->r5 = ADD32(ctx->r5, 0X1474);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D14BC: addiu       $a1, $a1, 0x1474
    ctx->r5 = ADD32(ctx->r5, 0X1474);
    after_2:
    // 0x801D14C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D14C4:
    // 0x801D14C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D14C8: jr          $ra
    // 0x801D14CC: nop

    return;
    // 0x801D14CC: nop

;}
RECOMP_FUNC void M24_FUN_801d14d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D14D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D14D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D14D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D14DC: jal         0x801CC540
    // 0x801D14E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D14E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D14E4: beq         $v0, $zero, L_801D1504
    if (ctx->r2 == 0) {
        // 0x801D14E8: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D1504;
    }
    // 0x801D14E8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D14EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D14F0: addiu       $a1, $a1, 0x14D0
    ctx->r5 = ADD32(ctx->r5, 0X14D0);
    // 0x801D14F4: jal         0x800058DC
    // 0x801D14F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D14F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D14FC: b           L_801D16B8
    // 0x801D1500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D16B8;
    // 0x801D1500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1504:
    // 0x801D1504: lw          $t6, -0x4EBC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4EBC);
    // 0x801D1508: beq         $t6, $zero, L_801D1560
    if (ctx->r14 == 0) {
        // 0x801D150C: nop
    
            goto L_801D1560;
    }
    // 0x801D150C: nop

    // 0x801D1510: jal         0x80006214
    // 0x801D1514: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D1514: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D1518: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D151C: lw          $t7, -0x4EBC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4EBC);
    // 0x801D1520: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D1524: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D1528: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D152C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D1530: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D1534: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D1538: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D153C: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D1540: jal         0x8013A28C
    // 0x801D1544: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D1544: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D1548: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D154C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D1550: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1554: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D1558: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D155C: sw          $zero, -0x4EBC($at)
    MEM_W(-0X4EBC, ctx->r1) = 0;
L_801D1560:
    // 0x801D1560: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1564: lw          $v0, -0x4EB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4EB8);
    // 0x801D1568: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D156C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D1570: beq         $v0, $zero, L_801D163C
    if (ctx->r2 == 0) {
        // 0x801D1574: nop
    
            goto L_801D163C;
    }
    // 0x801D1574: nop

    // 0x801D1578: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D157C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D1580: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D1584: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D1588: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D158C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1590: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1594: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D1598: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D159C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D15A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D15A4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D15A8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D15AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D15B0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D15B4: nop

    // 0x801D15B8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D15BC: beql        $t4, $zero, L_801D160C
    if (ctx->r12 == 0) {
        // 0x801D15C0: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D160C;
    }
    goto skip_0;
    // 0x801D15C0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D15C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D15C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D15CC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D15D0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D15D4: nop

    // 0x801D15D8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D15DC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D15E0: nop

    // 0x801D15E4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D15E8: bne         $t4, $zero, L_801D1600
    if (ctx->r12 != 0) {
        // 0x801D15EC: nop
    
            goto L_801D1600;
    }
    // 0x801D15EC: nop

    // 0x801D15F0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D15F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D15F8: b           L_801D1618
    // 0x801D15FC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D1618;
    // 0x801D15FC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D1600:
    // 0x801D1600: b           L_801D1618
    // 0x801D1604: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D1618;
    // 0x801D1604: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D1608: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D160C:
    // 0x801D160C: nop

    // 0x801D1610: bltz        $t4, L_801D1600
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D1614: nop
    
            goto L_801D1600;
    }
    // 0x801D1614: nop

L_801D1618:
    // 0x801D1618: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D161C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D1620: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D1624: jal         0x80011140
    // 0x801D1628: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D1628: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D162C: beq         $v0, $zero, L_801D16B4
    if (ctx->r2 == 0) {
        // 0x801D1630: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D16B4;
    }
    // 0x801D1630: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1634: b           L_801D16B4
    // 0x801D1638: sw          $zero, -0x4EB8($at)
    MEM_W(-0X4EB8, ctx->r1) = 0;
        goto L_801D16B4;
    // 0x801D1638: sw          $zero, -0x4EB8($at)
    MEM_W(-0X4EB8, ctx->r1) = 0;
L_801D163C:
    // 0x801D163C: jal         0x80010550
    // 0x801D1640: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D1640: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D1644: beq         $v0, $zero, L_801D165C
    if (ctx->r2 == 0) {
        // 0x801D1648: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D165C;
    }
    // 0x801D1648: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D164C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D1650: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1654: b           L_801D1660
    // 0x801D1658: sw          $t5, -0x4EB4($at)
    MEM_W(-0X4EB4, ctx->r1) = ctx->r13;
        goto L_801D1660;
    // 0x801D1658: sw          $t5, -0x4EB4($at)
    MEM_W(-0X4EB4, ctx->r1) = ctx->r13;
L_801D165C:
    // 0x801D165C: sw          $zero, -0x4EB4($at)
    MEM_W(-0X4EB4, ctx->r1) = 0;
L_801D1660:
    // 0x801D1660: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D1664: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1668: addiu       $t6, $t6, 0x1380
    ctx->r14 = ADD32(ctx->r14, 0X1380);
    // 0x801D166C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D1670: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D1674: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D1678: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D167C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D1680: addiu       $t2, $t2, 0x1370
    ctx->r10 = ADD32(ctx->r10, 0X1370);
    // 0x801D1684: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D1688: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D168C: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D1690: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D1694: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D1698: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D169C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D16A0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D16A4: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D16A8: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D16AC: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D16B0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D16B4:
    // 0x801D16B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D16B8:
    // 0x801D16B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D16BC: jr          $ra
    // 0x801D16C0: nop

    return;
    // 0x801D16C0: nop

;}
RECOMP_FUNC void M24_FUN_801d16c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D16C4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D16C8: lw          $v0, -0x4EB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4EB8);
    // 0x801D16CC: jr          $ra
    // 0x801D16D0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D16D0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d16d4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d16d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D16D4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D16D8: lw          $t6, -0x4EB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4EB8);
    // 0x801D16DC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D16E0: beq         $t6, $zero, L_801D16F0
    if (ctx->r14 == 0) {
            // 0x801D16E4: nop

    LOOKUP_FUNC(0x801D16F0)(rdram, ctx);
    return;
    }
    // 0x801D16E4: nop

    // 0x801D16E8: jr          $ra
    // 0x801D16EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D16EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d16f0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d16f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D16F0: lw          $t7, -0x4EBC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4EBC);
    // 0x801D16F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D16F8: beq         $t7, $zero, L_801D1708
    if (ctx->r15 == 0) {
            // 0x801D16FC: nop

    LOOKUP_FUNC(0x801D1708)(rdram, ctx);
    return;
    }
    // 0x801D16FC: nop

    // 0x801D1700: jr          $ra
    // 0x801D1704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1708(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1708: lw          $v0, -0x4EB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4EB4);
    // 0x801D170C: jr          $ra
    // 0x801D1710: nop

    return;
    // 0x801D1710: nop

;}
RECOMP_FUNC void M24_FUN_801d1714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1714: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1718: jr          $ra
    // 0x801D171C: addiu       $v0, $v0, 0x1370
    ctx->r2 = ADD32(ctx->r2, 0X1370);
    return;
    // 0x801D171C: addiu       $v0, $v0, 0x1370
    ctx->r2 = ADD32(ctx->r2, 0X1370);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1720(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1720: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D1724: addiu       $v1, $v1, 0x1380
    ctx->r3 = ADD32(ctx->r3, 0X1380);
    // 0x801D1728: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D172C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D1730: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D1734: beql        $a0, $t6, L_801D1748
    if (ctx->r4 == ctx->r14) {
        // 0x801D1738: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D1748;
    }
    goto skip_0;
    // 0x801D1738: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D173C: jr          $ra
    // 0x801D1740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D1744: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D1748:
    // 0x801D1748: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D174C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D1750: jr          $ra
    // 0x801D1754: nop

    return;
    // 0x801D1754: nop

;}
RECOMP_FUNC void M24_FUN_801d1758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1758: nop

    // 0x801D175C: nop

;}
RECOMP_FUNC void M24_FUN_801d1760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1760: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1764: sw          $a0, 0x1390($at)
    MEM_W(0X1390, ctx->r1) = ctx->r4;
    // 0x801D1768: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D176C: sw          $zero, -0x4E9C($at)
    MEM_W(-0X4E9C, ctx->r1) = 0;
    // 0x801D1770: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1774: sw          $zero, -0x4E98($at)
    MEM_W(-0X4E98, ctx->r1) = 0;
    // 0x801D1778: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D177C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D1780: sw          $t6, -0x4E94($at)
    MEM_W(-0X4E94, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1784(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D1788: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D178C: sw          $zero, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = 0;
    // 0x801D1790: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D1794: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1798: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D179C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D17A0: addiu       $t7, $t7, 0x17D0
    ctx->r15 = ADD32(ctx->r15, 0X17D0);
    // 0x801D17A4: sw          $zero, -0x4E8C($at)
    MEM_W(-0X4E8C, ctx->r1) = 0;
    // 0x801D17A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D17AC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x801D17B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D17B4: jal         0x8013B570
    // 0x801D17B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D17B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D17BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D17C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801D17C4: sh          $zero, -0x3876($at)
    MEM_H(-0X3876, ctx->r1) = 0;
    // 0x801D17C8: jr          $ra
    // 0x801D17CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801D17CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d17d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d17d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D17D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D17D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D17D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D17DC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D17E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D17E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D17E8: beq         $t6, $zero, L_801D1814
    if (ctx->r14 == 0) {
        // 0x801D17EC: nop
    
            goto L_801D1814;
    }
    // 0x801D17EC: nop

    // 0x801D17F0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D17F4: jal         0x8012D844
    // 0x801D17F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D17F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D17FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D1804: jal         0x800058DC
    // 0x801D1808: addiu       $a1, $a1, 0x182C
    ctx->r5 = ADD32(ctx->r5, 0X182C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1808: addiu       $a1, $a1, 0x182C
    ctx->r5 = ADD32(ctx->r5, 0X182C);
    after_1:
    // 0x801D180C: b           L_801D1820
    // 0x801D1810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D1820;
    // 0x801D1810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1814:
    // 0x801D1814: jal         0x800058DC
    // 0x801D1818: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1818: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    after_2:
    // 0x801D181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1820:
    // 0x801D1820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D1824: jr          $ra
    // 0x801D1828: nop

    return;
    // 0x801D1828: nop

;}
RECOMP_FUNC void M24_FUN_801d182c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D182C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D1830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1834: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D1838: jal         0x801CC540
    // 0x801D183C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D183C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D1840: beq         $v0, $zero, L_801D1860
    if (ctx->r2 == 0) {
        // 0x801D1844: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D1860;
    }
    // 0x801D1844: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1848: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D184C: addiu       $a1, $a1, 0x182C
    ctx->r5 = ADD32(ctx->r5, 0X182C);
    // 0x801D1850: jal         0x800058DC
    // 0x801D1854: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1854: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D1858: b           L_801D1A58
    // 0x801D185C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D1A58;
    // 0x801D185C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1860:
    // 0x801D1860: lw          $t6, -0x4E9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4E9C);
    // 0x801D1864: beq         $t6, $zero, L_801D18BC
    if (ctx->r14 == 0) {
        // 0x801D1868: nop
    
            goto L_801D18BC;
    }
    // 0x801D1868: nop

    // 0x801D186C: jal         0x80006214
    // 0x801D1870: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D1870: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D1874: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1878: lw          $t7, -0x4E9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E9C);
    // 0x801D187C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D1880: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D1884: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D1888: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D188C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D1890: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D1894: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D1898: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D189C: jal         0x8013A28C
    // 0x801D18A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D18A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D18A4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D18A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D18AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D18B0: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D18B4: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D18B8: sw          $zero, -0x4E9C($at)
    MEM_W(-0X4E9C, ctx->r1) = 0;
L_801D18BC:
    // 0x801D18BC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D18C0: lw          $v0, -0x4E98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E98);
    // 0x801D18C4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D18C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D18CC: beq         $v0, $zero, L_801D1998
    if (ctx->r2 == 0) {
        // 0x801D18D0: nop
    
            goto L_801D1998;
    }
    // 0x801D18D0: nop

    // 0x801D18D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D18D8: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D18DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D18E0: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D18E4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D18E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D18EC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D18F0: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D18F4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D18F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D18FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D1900: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D1904: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D1908: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D190C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D1910: nop

    // 0x801D1914: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D1918: beql        $t4, $zero, L_801D1968
    if (ctx->r12 == 0) {
        // 0x801D191C: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D1968;
    }
    goto skip_0;
    // 0x801D191C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D1920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D1924: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1928: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D192C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1930: nop

    // 0x801D1934: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D1938: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D193C: nop

    // 0x801D1940: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D1944: bne         $t4, $zero, L_801D195C
    if (ctx->r12 != 0) {
        // 0x801D1948: nop
    
            goto L_801D195C;
    }
    // 0x801D1948: nop

    // 0x801D194C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D1950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1954: b           L_801D1974
    // 0x801D1958: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D1974;
    // 0x801D1958: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D195C:
    // 0x801D195C: b           L_801D1974
    // 0x801D1960: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D1974;
    // 0x801D1960: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D1964: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D1968:
    // 0x801D1968: nop

    // 0x801D196C: bltz        $t4, L_801D195C
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D1970: nop
    
            goto L_801D195C;
    }
    // 0x801D1970: nop

L_801D1974:
    // 0x801D1974: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D1978: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D197C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D1980: jal         0x80011140
    // 0x801D1984: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D1984: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D1988: beq         $v0, $zero, L_801D1A10
    if (ctx->r2 == 0) {
        // 0x801D198C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1A10;
    }
    // 0x801D198C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1990: b           L_801D1A10
    // 0x801D1994: sw          $zero, -0x4E98($at)
    MEM_W(-0X4E98, ctx->r1) = 0;
        goto L_801D1A10;
    // 0x801D1994: sw          $zero, -0x4E98($at)
    MEM_W(-0X4E98, ctx->r1) = 0;
L_801D1998:
    // 0x801D1998: jal         0x80010550
    // 0x801D199C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D199C: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D19A0: beq         $v0, $zero, L_801D19B8
    if (ctx->r2 == 0) {
        // 0x801D19A4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D19B8;
    }
    // 0x801D19A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D19A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D19AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D19B0: b           L_801D19BC
    // 0x801D19B4: sw          $t5, -0x4E94($at)
    MEM_W(-0X4E94, ctx->r1) = ctx->r13;
        goto L_801D19BC;
    // 0x801D19B4: sw          $t5, -0x4E94($at)
    MEM_W(-0X4E94, ctx->r1) = ctx->r13;
L_801D19B8:
    // 0x801D19B8: sw          $zero, -0x4E94($at)
    MEM_W(-0X4E94, ctx->r1) = 0;
L_801D19BC:
    // 0x801D19BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D19C0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D19C4: addiu       $t6, $t6, 0x13A8
    ctx->r14 = ADD32(ctx->r14, 0X13A8);
    // 0x801D19C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D19CC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D19D0: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D19D4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D19D8: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D19DC: addiu       $t2, $t2, 0x1398
    ctx->r10 = ADD32(ctx->r10, 0X1398);
    // 0x801D19E0: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D19E4: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D19E8: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D19EC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D19F0: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D19F4: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D19F8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D19FC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D1A00: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D1A04: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D1A08: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D1A0C: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D1A10:
    // 0x801D1A10: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1A14: lw          $t7, -0x4E90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E90);
    // 0x801D1A18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D1A1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801D1A20: beq         $t7, $zero, L_801D1A3C
    if (ctx->r15 == 0) {
        // 0x801D1A24: nop
    
            goto L_801D1A3C;
    }
    // 0x801D1A24: nop

    // 0x801D1A28: jal         0x80129554
    // 0x801D1A2C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x80129554)(rdram, ctx);
        goto after_6;
    // 0x801D1A2C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_6:
    // 0x801D1A30: beq         $v0, $zero, L_801D1A3C
    if (ctx->r2 == 0) {
        // 0x801D1A34: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1A3C;
    }
    // 0x801D1A34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1A38: sw          $zero, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = 0;
L_801D1A3C:
    // 0x801D1A3C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D1A40: lw          $t8, -0x4E8C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4E8C);
    // 0x801D1A44: beql        $t8, $zero, L_801D1A58
    if (ctx->r24 == 0) {
        // 0x801D1A48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D1A58;
    }
    goto skip_1;
    // 0x801D1A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D1A4C: jal         0x801D1BA0
    // 0x801D1A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D1BA0)(rdram, ctx);
        goto after_7;
    // 0x801D1A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x801D1A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1A58:
    // 0x801D1A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1A5C: jr          $ra
    // 0x801D1A60: nop

    return;
    // 0x801D1A60: nop

;}
RECOMP_FUNC void M24_FUN_801d1a64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1A64: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1A68: lw          $v0, -0x4E98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E98);
    // 0x801D1A6C: jr          $ra
    // 0x801D1A70: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D1A70: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1a74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1a74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1A74: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1A78: lw          $t6, -0x4E98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4E98);
    // 0x801D1A7C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1A80: beq         $t6, $zero, L_801D1A90
    if (ctx->r14 == 0) {
            // 0x801D1A84: nop

    LOOKUP_FUNC(0x801D1A90)(rdram, ctx);
    return;
    }
    // 0x801D1A84: nop

    // 0x801D1A88: jr          $ra
    // 0x801D1A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1a90(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1a90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1A90: lw          $t7, -0x4E9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E9C);
    // 0x801D1A94: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1A98: beq         $t7, $zero, L_801D1AA8
    if (ctx->r15 == 0) {
            // 0x801D1A9C: nop

    LOOKUP_FUNC(0x801D1AA8)(rdram, ctx);
    return;
    }
    // 0x801D1A9C: nop

    // 0x801D1AA0: jr          $ra
    // 0x801D1AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1aa8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1aa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1AA8: lw          $v0, -0x4E94($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E94);
    // 0x801D1AAC: jr          $ra
    // 0x801D1AB0: nop

    return;
    // 0x801D1AB0: nop

;}
RECOMP_FUNC void M24_FUN_801d1ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1AB4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1AB8: jr          $ra
    // 0x801D1ABC: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, 0X1398);
    return;
    // 0x801D1ABC: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, 0X1398);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1ac0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1ac0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1AC0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D1AC4: addiu       $v1, $v1, 0x13A8
    ctx->r3 = ADD32(ctx->r3, 0X13A8);
    // 0x801D1AC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D1ACC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D1AD0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D1AD4: beql        $a0, $t6, L_801D1AE8
    if (ctx->r4 == ctx->r14) {
        // 0x801D1AD8: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D1AE8;
    }
    goto skip_0;
    // 0x801D1AD8: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D1ADC: jr          $ra
    // 0x801D1AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D1AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D1AE4: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D1AE8:
    // 0x801D1AE8: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D1AEC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D1AF0: jr          $ra
    // 0x801D1AF4: nop

    return;
    // 0x801D1AF4: nop

;}
RECOMP_FUNC void M24_FUN_801d1af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1AF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1AFC: jr          $ra
    // 0x801D1B00: sw          $a0, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = ctx->r4;
    return;
    // 0x801D1B00: sw          $a0, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1b04(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1b04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1B04: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1B08: jr          $ra
    // 0x801D1B0C: lw          $v0, -0x4E90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E90);
    return;
    // 0x801D1B0C: lw          $v0, -0x4E90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1b10(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1b10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1B10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D1B14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D1B18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D1B1C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D1B20: beq         $a0, $zero, L_801D1B78
    if (ctx->r4 == 0) {
        // 0x801D1B24: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D1B78;
    }
    // 0x801D1B24: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D1B28: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1B2C: jal         0x80006214
    // 0x801D1B30: lw          $a0, 0x1390($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1390);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D1B30: lw          $a0, 0x1390($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1390);
    after_0:
    // 0x801D1B34: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D1B38: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x801D1B3C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D1B40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D1B44: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801D1B48: lw          $a0, 0x1390($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1390);
    // 0x801D1B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D1B50: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D1B54: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D1B58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801D1B5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D1B60: jal         0x801C3370
    // 0x801D1B64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D1B64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x801D1B68: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D1B6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1B70: b           L_801D1B80
    // 0x801D1B74: sw          $t9, -0x4E8C($at)
    MEM_W(-0X4E8C, ctx->r1) = ctx->r25;
        goto L_801D1B80;
    // 0x801D1B74: sw          $t9, -0x4E8C($at)
    MEM_W(-0X4E8C, ctx->r1) = ctx->r25;
L_801D1B78:
    // 0x801D1B78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1B7C: sw          $zero, -0x4E8C($at)
    MEM_W(-0X4E8C, ctx->r1) = 0;
L_801D1B80:
    // 0x801D1B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D1B84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D1B88: jr          $ra
    // 0x801D1B8C: nop

    return;
    // 0x801D1B8C: nop

;}
RECOMP_FUNC void M24_FUN_801d1b90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1B90: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1B94: lw          $v0, -0x4E8C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E8C);
    // 0x801D1B98: jr          $ra
    // 0x801D1B9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D1B9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1ba0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1ba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D1BA8: jal         0x80006214
    // 0x801D1BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D1BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D1BB0: jal         0x801C354C
    // 0x801D1BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D1BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D1BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D1BBC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D1BC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1BC4: sw          $t6, -0x4E8C($at)
    MEM_W(-0X4E8C, ctx->r1) = ctx->r14;
    // 0x801D1BC8: jr          $ra
    // 0x801D1BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D1BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1bd0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1BD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1BD4: sw          $a0, 0x13C0($at)
    MEM_W(0X13C0, ctx->r1) = ctx->r4;
    // 0x801D1BD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1BDC: sw          $zero, -0x4E68($at)
    MEM_W(-0X4E68, ctx->r1) = 0;
    // 0x801D1BE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1BE4: sw          $zero, -0x4E64($at)
    MEM_W(-0X4E64, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d1be8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d1be8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D1BEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1BF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D1BF4: sw          $t6, -0x4E40($at)
    MEM_W(-0X4E40, ctx->r1) = ctx->r14;
    // 0x801D1BF8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D1BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1C00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D1C04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1C08: addiu       $t7, $t7, 0x1C34
    ctx->r15 = ADD32(ctx->r15, 0X1C34);
    // 0x801D1C0C: sw          $zero, -0x4E80($at)
    MEM_W(-0X4E80, ctx->r1) = 0;
    // 0x801D1C10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D1C14: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D1C18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D1C1C: jal         0x8013B570
    // 0x801D1C20: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D1C20: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D1C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D1C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D1C2C: jr          $ra
    // 0x801D1C30: nop

    return;
    // 0x801D1C30: nop

;}
RECOMP_FUNC void M24_FUN_801d1c34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D1C3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D1C40: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D1C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D1C48: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1C4C: beq         $t6, $zero, L_801D1C78
    if (ctx->r14 == 0) {
        // 0x801D1C50: nop
    
            goto L_801D1C78;
    }
    // 0x801D1C50: nop

    // 0x801D1C54: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D1C58: jal         0x8012D844
    // 0x801D1C5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D1C5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D1C60: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1C64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D1C68: jal         0x800058DC
    // 0x801D1C6C: addiu       $a1, $a1, 0x1C90
    ctx->r5 = ADD32(ctx->r5, 0X1C90);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1C6C: addiu       $a1, $a1, 0x1C90
    ctx->r5 = ADD32(ctx->r5, 0X1C90);
    after_1:
    // 0x801D1C70: b           L_801D1C84
    // 0x801D1C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D1C84;
    // 0x801D1C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1C78:
    // 0x801D1C78: jal         0x800058DC
    // 0x801D1C7C: addiu       $a1, $a1, 0x1C34
    ctx->r5 = ADD32(ctx->r5, 0X1C34);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1C7C: addiu       $a1, $a1, 0x1C34
    ctx->r5 = ADD32(ctx->r5, 0X1C34);
    after_2:
    // 0x801D1C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1C84:
    // 0x801D1C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D1C88: jr          $ra
    // 0x801D1C8C: nop

    return;
    // 0x801D1C8C: nop

;}
RECOMP_FUNC void M24_FUN_801d1c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D1C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D1C98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D1C9C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D1CA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D1CA4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1CA8: beq         $t6, $zero, L_801D1DE8
    if (ctx->r14 == 0) {
        // 0x801D1CAC: nop
    
            goto L_801D1DE8;
    }
    // 0x801D1CAC: nop

    // 0x801D1CB0: lw          $t7, -0x4E48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E48);
    // 0x801D1CB4: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D1CB8: addiu       $a2, $a2, -0x4E60
    ctx->r6 = ADD32(ctx->r6, -0X4E60);
    // 0x801D1CBC: beq         $t7, $zero, L_801D1DBC
    if (ctx->r15 == 0) {
        // 0x801D1CC0: nop
    
            goto L_801D1DBC;
    }
    // 0x801D1CC0: nop

    // 0x801D1CC4: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D1CC8: jal         0x80005FAC
    // 0x801D1CCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D1CCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D1CD0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D1CD4: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D1CD8: lw          $t9, 0x10E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D1CDC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D1CE0: addiu       $v1, $v1, -0x4E4C
    ctx->r3 = ADD32(ctx->r3, -0X4E4C);
    // 0x801D1CE4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D1CE8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D1CEC: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D1CF0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D1CF4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801D1CF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D1CFC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D1D00: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D1D04: lw          $t4, 0x10E0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D1D08: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D1D10: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D1D14: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D1D18: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D1D1C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D1D20: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D1D24: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D1D28: lw          $t9, 0x10E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10E0);
    // 0x801D1D2C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D30: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D1D34: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D1D38: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D1D3C: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D1D40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D44: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D1D48: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D1D4C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D50: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D1D54: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D1D58: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D5C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D1D60: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D1D64: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D68: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D1D6C: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D1D70: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D74: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D1D78: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D1D7C: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D1D80: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D84: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D1D88: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D1D8C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D90: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D1D94: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D1D98: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D1D9C: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D1DA0: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D1DA4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D1DA8: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D1DAC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D1DB0: lw          $t1, -0x4E44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4E44);
    // 0x801D1DB4: b           L_801D1DD0
    // 0x801D1DB8: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D1DD0;
    // 0x801D1DB8: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D1DBC:
    // 0x801D1DBC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D1DC0: addiu       $v1, $v1, -0x4E4C
    ctx->r3 = ADD32(ctx->r3, -0X4E4C);
    // 0x801D1DC4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D1DC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1DCC: sw          $zero, -0x4E44($at)
    MEM_W(-0X4E44, ctx->r1) = 0;
L_801D1DD0:
    // 0x801D1DD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1DD4: addiu       $a1, $a1, 0x1E08
    ctx->r5 = ADD32(ctx->r5, 0X1E08);
    // 0x801D1DD8: jal         0x800058DC
    // 0x801D1DDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1DDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D1DE0: b           L_801D1DFC
    // 0x801D1DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D1DFC;
    // 0x801D1DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1DE8:
    // 0x801D1DE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1DEC: addiu       $a1, $a1, 0x1C90
    ctx->r5 = ADD32(ctx->r5, 0X1C90);
    // 0x801D1DF0: jal         0x800058DC
    // 0x801D1DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D1DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D1DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D1DFC:
    // 0x801D1DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D1E00: jr          $ra
    // 0x801D1E04: nop

    return;
    // 0x801D1E04: nop

;}
RECOMP_FUNC void M24_FUN_801d1e08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D1E08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D1E0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D1E10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D1E14: jal         0x801CC540
    // 0x801D1E18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D1E18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D1E1C: beq         $v0, $zero, L_801D1E3C
    if (ctx->r2 == 0) {
        // 0x801D1E20: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D1E3C;
    }
    // 0x801D1E20: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1E24: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D1E28: addiu       $a1, $a1, 0x1E08
    ctx->r5 = ADD32(ctx->r5, 0X1E08);
    // 0x801D1E2C: jal         0x800058DC
    // 0x801D1E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D1E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D1E34: b           L_801D2028
    // 0x801D1E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D2028;
    // 0x801D1E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D1E3C:
    // 0x801D1E3C: lw          $t6, -0x4E68($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4E68);
    // 0x801D1E40: beq         $t6, $zero, L_801D1E98
    if (ctx->r14 == 0) {
        // 0x801D1E44: nop
    
            goto L_801D1E98;
    }
    // 0x801D1E44: nop

    // 0x801D1E48: jal         0x80006214
    // 0x801D1E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D1E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D1E50: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1E54: lw          $t7, -0x4E68($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E68);
    // 0x801D1E58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D1E5C: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D1E60: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D1E64: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D1E68: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D1E6C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D1E70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D1E74: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D1E78: jal         0x8013A28C
    // 0x801D1E7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D1E7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D1E80: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D1E84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D1E88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1E8C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D1E90: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D1E94: sw          $zero, -0x4E68($at)
    MEM_W(-0X4E68, ctx->r1) = 0;
L_801D1E98:
    // 0x801D1E98: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D1E9C: lw          $v0, -0x4E64($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E64);
    // 0x801D1EA0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D1EA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D1EA8: beq         $v0, $zero, L_801D1F74
    if (ctx->r2 == 0) {
        // 0x801D1EAC: nop
    
            goto L_801D1F74;
    }
    // 0x801D1EAC: nop

    // 0x801D1EB0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D1EB4: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D1EB8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D1EBC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D1EC0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D1EC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1EC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1ECC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D1ED0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D1ED4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D1ED8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D1EDC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D1EE0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D1EE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D1EE8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D1EEC: nop

    // 0x801D1EF0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D1EF4: beql        $t4, $zero, L_801D1F44
    if (ctx->r12 == 0) {
        // 0x801D1EF8: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D1F44;
    }
    goto skip_0;
    // 0x801D1EF8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D1EFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D1F00: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D1F04: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D1F08: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D1F0C: nop

    // 0x801D1F10: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D1F14: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D1F18: nop

    // 0x801D1F1C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D1F20: bne         $t4, $zero, L_801D1F38
    if (ctx->r12 != 0) {
        // 0x801D1F24: nop
    
            goto L_801D1F38;
    }
    // 0x801D1F24: nop

    // 0x801D1F28: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D1F2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D1F30: b           L_801D1F50
    // 0x801D1F34: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D1F50;
    // 0x801D1F34: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D1F38:
    // 0x801D1F38: b           L_801D1F50
    // 0x801D1F3C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D1F50;
    // 0x801D1F3C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D1F40: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D1F44:
    // 0x801D1F44: nop

    // 0x801D1F48: bltz        $t4, L_801D1F38
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D1F4C: nop
    
            goto L_801D1F38;
    }
    // 0x801D1F4C: nop

L_801D1F50:
    // 0x801D1F50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D1F54: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D1F58: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D1F5C: jal         0x80011140
    // 0x801D1F60: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D1F60: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D1F64: beq         $v0, $zero, L_801D1FEC
    if (ctx->r2 == 0) {
        // 0x801D1F68: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1FEC;
    }
    // 0x801D1F68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1F6C: b           L_801D1FEC
    // 0x801D1F70: sw          $zero, -0x4E64($at)
    MEM_W(-0X4E64, ctx->r1) = 0;
        goto L_801D1FEC;
    // 0x801D1F70: sw          $zero, -0x4E64($at)
    MEM_W(-0X4E64, ctx->r1) = 0;
L_801D1F74:
    // 0x801D1F74: jal         0x80010550
    // 0x801D1F78: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D1F78: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D1F7C: beq         $v0, $zero, L_801D1F94
    if (ctx->r2 == 0) {
        // 0x801D1F80: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D1F94;
    }
    // 0x801D1F80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1F84: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D1F88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D1F8C: b           L_801D1F98
    // 0x801D1F90: sw          $t5, -0x4E40($at)
    MEM_W(-0X4E40, ctx->r1) = ctx->r13;
        goto L_801D1F98;
    // 0x801D1F90: sw          $t5, -0x4E40($at)
    MEM_W(-0X4E40, ctx->r1) = ctx->r13;
L_801D1F94:
    // 0x801D1F94: sw          $zero, -0x4E40($at)
    MEM_W(-0X4E40, ctx->r1) = 0;
L_801D1F98:
    // 0x801D1F98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D1F9C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1FA0: addiu       $t6, $t6, 0x13D8
    ctx->r14 = ADD32(ctx->r14, 0X13D8);
    // 0x801D1FA4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D1FA8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D1FAC: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D1FB0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D1FB4: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D1FB8: addiu       $t2, $t2, 0x13C8
    ctx->r10 = ADD32(ctx->r10, 0X13C8);
    // 0x801D1FBC: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D1FC0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D1FC4: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D1FC8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D1FCC: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D1FD0: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D1FD4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D1FD8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D1FDC: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D1FE0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D1FE4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D1FE8: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D1FEC:
    // 0x801D1FEC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D1FF0: lw          $t7, -0x4E48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E48);
    // 0x801D1FF4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D1FF8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D1FFC: beq         $t7, $zero, L_801D2010
    if (ctx->r15 == 0) {
        // 0x801D2000: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801D2010;
    }
    // 0x801D2000: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D2004: lw          $t8, -0x4E44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4E44);
    // 0x801D2008: lw          $t6, -0x4E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4E4C);
    // 0x801D200C: sb          $t8, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r24;
L_801D2010:
    // 0x801D2010: lw          $t9, -0x4E80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4E80);
    // 0x801D2014: beql        $t9, $zero, L_801D2028
    if (ctx->r25 == 0) {
        // 0x801D2018: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D2028;
    }
    goto skip_1;
    // 0x801D2018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D201C: jal         0x801D2140
    // 0x801D2020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D2140)(rdram, ctx);
        goto after_6;
    // 0x801D2020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801D2024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D2028:
    // 0x801D2028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D202C: jr          $ra
    // 0x801D2030: nop

    return;
    // 0x801D2030: nop

;}
RECOMP_FUNC void M24_FUN_801d2034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2034: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2038: addiu       $v0, $v0, -0x4E80
    ctx->r2 = ADD32(ctx->r2, -0X4E80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d203c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d203c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D203C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2044: beq         $a0, $zero, L_801D2070
    if (ctx->r4 == 0) {
        // 0x801D2048: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D2070;
    }
    // 0x801D2048: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D204C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2050: jal         0x801C0B2C
    // 0x801D2054: sw          $zero, -0x4E50($at)
    MEM_W(-0X4E50, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D2054: sw          $zero, -0x4E50($at)
    MEM_W(-0X4E50, ctx->r1) = 0;
    after_0:
    // 0x801D2058: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D205C: sw          $v0, 0x13E8($at)
    MEM_W(0X13E8, ctx->r1) = ctx->r2;
    // 0x801D2060: sw          $v1, 0x13EC($at)
    MEM_W(0X13EC, ctx->r1) = ctx->r3;
    // 0x801D2064: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2068: b           L_801D2084
    // 0x801D206C: sw          $zero, 0x13F0($at)
    MEM_W(0X13F0, ctx->r1) = 0;
        goto L_801D2084;
    // 0x801D206C: sw          $zero, 0x13F0($at)
    MEM_W(0X13F0, ctx->r1) = 0;
L_801D2070:
    // 0x801D2070: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2074: lw          $a0, 0x13C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C0);
    // 0x801D2078: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D207C: jal         0x8012D844
    // 0x801D2080: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D2080: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D2084:
    // 0x801D2084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D2088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D208C: jr          $ra
    // 0x801D2090: nop

    return;
    // 0x801D2090: nop

;}
RECOMP_FUNC void M24_FUN_801d2094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2094: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2098: jr          $ra
    // 0x801D209C: sw          $a0, -0x4E48($at)
    MEM_W(-0X4E48, ctx->r1) = ctx->r4;
    return;
    // 0x801D209C: sw          $a0, -0x4E48($at)
    MEM_W(-0X4E48, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d20a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d20a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D20A4: jr          $ra
    // 0x801D20A8: sw          $a0, -0x4E44($at)
    MEM_W(-0X4E44, ctx->r1) = ctx->r4;
    return;
    // 0x801D20A8: sw          $a0, -0x4E44($at)
    MEM_W(-0X4E44, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d20ac(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d20ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D20B0: lw          $v0, -0x4E64($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E64);
    // 0x801D20B4: jr          $ra
    // 0x801D20B8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D20B8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d20bc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d20bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20BC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D20C0: lw          $t6, -0x4E64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4E64);
    // 0x801D20C4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D20C8: beq         $t6, $zero, L_801D20D8
    if (ctx->r14 == 0) {
            // 0x801D20CC: nop

    LOOKUP_FUNC(0x801D20D8)(rdram, ctx);
    return;
    }
    // 0x801D20CC: nop

    // 0x801D20D0: jr          $ra
    // 0x801D20D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D20D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d20d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d20d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20D8: lw          $t7, -0x4E68($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4E68);
    // 0x801D20DC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D20E0: beq         $t7, $zero, L_801D20F0
    if (ctx->r15 == 0) {
            // 0x801D20E4: nop

    LOOKUP_FUNC(0x801D20F0)(rdram, ctx);
    return;
    }
    // 0x801D20E4: nop

    // 0x801D20E8: jr          $ra
    // 0x801D20EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D20EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d20f0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d20f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20F0: lw          $v0, -0x4E40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E40);
    // 0x801D20F4: jr          $ra
    // 0x801D20F8: nop

    return;
    // 0x801D20F8: nop

;}
RECOMP_FUNC void M24_FUN_801d20fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D20FC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D2100: jr          $ra
    // 0x801D2104: addiu       $v0, $v0, 0x13C8
    ctx->r2 = ADD32(ctx->r2, 0X13C8);
    return;
    // 0x801D2104: addiu       $v0, $v0, 0x13C8
    ctx->r2 = ADD32(ctx->r2, 0X13C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d2108(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d2108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2108: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D210C: addiu       $v1, $v1, 0x13D8
    ctx->r3 = ADD32(ctx->r3, 0X13D8);
    // 0x801D2110: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D2114: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D2118: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D211C: beql        $a0, $t6, L_801D2130
    if (ctx->r4 == ctx->r14) {
        // 0x801D2120: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D2130;
    }
    goto skip_0;
    // 0x801D2120: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D2124: jr          $ra
    // 0x801D2128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D2128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D212C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D2130:
    // 0x801D2130: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D2134: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D2138: jr          $ra
    // 0x801D213C: nop

    return;
    // 0x801D213C: nop

;}
RECOMP_FUNC void M24_FUN_801d2140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D2144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2148: jal         0x801C0B2C
    // 0x801D214C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D214C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D2150: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D2154: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2158: lw          $t7, 0x13EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13EC);
    // 0x801D215C: lw          $t6, 0x13E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13E8);
    // 0x801D2160: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D2164: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D2168: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D216C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D2170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D2174: jal         0x80034C24
    // 0x801D2178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D2178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D217C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2180: ldc1        $f4, -0x2B50($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2B50);
    // 0x801D2184: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D2188: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x801D218C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D2190: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D2194: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D2198: addiu       $t1, $t1, -0x4E3C
    ctx->r9 = ADD32(ctx->r9, -0X4E3C);
    // 0x801D219C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D21A0: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D21A4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D21A8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D21AC: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D21B0: nop

    // 0x801D21B4: bc1fl       L_801D2294
    if (!c1cs) {
        // 0x801D21B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D2294;
    }
    goto skip_0;
    // 0x801D21B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D21BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D21C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D21C4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D21C8: beq         $v0, $zero, L_801D21EC
    if (ctx->r2 == 0) {
        // 0x801D21CC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D21EC;
    }
    // 0x801D21CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D21D0: beq         $v0, $at, L_801D2208
    if (ctx->r2 == ctx->r1) {
        // 0x801D21D4: addiu       $a1, $zero, 0x31
        ctx->r5 = ADD32(0, 0X31);
            goto L_801D2208;
    }
    // 0x801D21D4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D21D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D21DC: beq         $v0, $at, L_801D2228
    if (ctx->r2 == ctx->r1) {
        // 0x801D21E0: addiu       $a1, $zero, 0x31
        ctx->r5 = ADD32(0, 0X31);
            goto L_801D2228;
    }
    // 0x801D21E0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x801D21E4: b           L_801D2248
    // 0x801D21E8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D2248;
    // 0x801D21E8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D21EC:
    // 0x801D21EC: jal         0x8012D844
    // 0x801D21F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D21F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D21F4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D21F8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D21FC: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x801D2200: b           L_801D2244
    // 0x801D2204: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
        goto L_801D2244;
    // 0x801D2204: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
L_801D2208:
    // 0x801D2208: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D220C: jal         0x8012D844
    // 0x801D2210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D2210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D2214: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2218: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D221C: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x801D2220: b           L_801D2244
    // 0x801D2224: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
        goto L_801D2244;
    // 0x801D2224: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
L_801D2228:
    // 0x801D2228: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D222C: jal         0x8012D844
    // 0x801D2230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D2230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D2234: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2238: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D223C: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x801D2240: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
L_801D2244:
    // 0x801D2244: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D2248:
    // 0x801D2248: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D224C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D2250: bne         $at, $zero, L_801D227C
    if (ctx->r1 != 0) {
        // 0x801D2254: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D227C;
    }
    // 0x801D2254: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D2258: jal         0x801C0B2C
    // 0x801D225C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D225C: nop

    after_5:
    // 0x801D2260: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D2264: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2268: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D226C: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x801D2270: lw          $a0, 0x13F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13F0);
    // 0x801D2274: sw          $v0, 0x13E8($at)
    MEM_W(0X13E8, ctx->r1) = ctx->r2;
    // 0x801D2278: sw          $v1, 0x13EC($at)
    MEM_W(0X13EC, ctx->r1) = ctx->r3;
L_801D227C:
    // 0x801D227C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D2280: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D2284: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D2288: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D228C: nop

    // 0x801D2290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2294:
    // 0x801D2294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D2298: jr          $ra
    // 0x801D229C: nop

    return;
    // 0x801D229C: nop

;}
RECOMP_FUNC void M24_FUN_801d22a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D22A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D22A4: sw          $a0, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->r4;
    // 0x801D22A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D22AC: sw          $zero, -0x4DA8($at)
    MEM_W(-0X4DA8, ctx->r1) = 0;
    // 0x801D22B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D22B4: sw          $zero, -0x4DA4($at)
    MEM_W(-0X4DA4, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d22b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d22b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D22B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D22BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D22C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D22C4: sw          $t6, -0x4D80($at)
    MEM_W(-0X4D80, ctx->r1) = ctx->r14;
    // 0x801D22C8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D22CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D22D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D22D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D22D8: addiu       $t7, $t7, 0x2304
    ctx->r15 = ADD32(ctx->r15, 0X2304);
    // 0x801D22DC: sw          $zero, -0x4DC0($at)
    MEM_W(-0X4DC0, ctx->r1) = 0;
    // 0x801D22E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D22E4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D22E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D22EC: jal         0x8013B570
    // 0x801D22F0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D22F0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D22F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D22F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D22FC: jr          $ra
    // 0x801D2300: nop

    return;
    // 0x801D2300: nop

;}
RECOMP_FUNC void M24_FUN_801d2304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D230C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D2310: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D2314: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D2318: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D231C: beq         $t6, $zero, L_801D2348
    if (ctx->r14 == 0) {
        // 0x801D2320: nop
    
            goto L_801D2348;
    }
    // 0x801D2320: nop

    // 0x801D2324: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x801D2328: jal         0x8012D844
    // 0x801D232C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D232C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D2330: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D2334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D2338: jal         0x800058DC
    // 0x801D233C: addiu       $a1, $a1, 0x2360
    ctx->r5 = ADD32(ctx->r5, 0X2360);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D233C: addiu       $a1, $a1, 0x2360
    ctx->r5 = ADD32(ctx->r5, 0X2360);
    after_1:
    // 0x801D2340: b           L_801D2354
    // 0x801D2344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D2354;
    // 0x801D2344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2348:
    // 0x801D2348: jal         0x800058DC
    // 0x801D234C: addiu       $a1, $a1, 0x2304
    ctx->r5 = ADD32(ctx->r5, 0X2304);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D234C: addiu       $a1, $a1, 0x2304
    ctx->r5 = ADD32(ctx->r5, 0X2304);
    after_2:
    // 0x801D2350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D2354:
    // 0x801D2354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2358: jr          $ra
    // 0x801D235C: nop

    return;
    // 0x801D235C: nop

;}
RECOMP_FUNC void M24_FUN_801d2360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D2364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D236C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D2370: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D2374: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D2378: beq         $t6, $zero, L_801D24B8
    if (ctx->r14 == 0) {
        // 0x801D237C: nop
    
            goto L_801D24B8;
    }
    // 0x801D237C: nop

    // 0x801D2380: lw          $t7, -0x4D88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D88);
    // 0x801D2384: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D2388: addiu       $a2, $a2, -0x4DA0
    ctx->r6 = ADD32(ctx->r6, -0X4DA0);
    // 0x801D238C: beq         $t7, $zero, L_801D248C
    if (ctx->r15 == 0) {
        // 0x801D2390: nop
    
            goto L_801D248C;
    }
    // 0x801D2390: nop

    // 0x801D2394: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D2398: jal         0x80005FAC
    // 0x801D239C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D239C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D23A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D23A4: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D23A8: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D23AC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D23B0: addiu       $v1, $v1, -0x4D8C
    ctx->r3 = ADD32(ctx->r3, -0X4D8C);
    // 0x801D23B4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D23B8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D23BC: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D23C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D23C4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D23C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D23CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D23D0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D23D4: lw          $t4, 0x980($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X980);
    // 0x801D23D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D23DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D23E0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D23E4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D23E8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D23EC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D23F0: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D23F4: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D23F8: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D23FC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D2400: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D2404: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D2408: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D240C: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D2410: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D2414: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D2418: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D241C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D2420: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D2424: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D2428: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D242C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D2430: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D2434: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D2438: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D243C: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D2440: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D2444: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D2448: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D244C: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D2450: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D2454: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D2458: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D245C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D2460: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D2464: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D2468: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D246C: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D2470: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D2474: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D2478: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D247C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D2480: lw          $t1, -0x4D84($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4D84);
    // 0x801D2484: b           L_801D24A0
    // 0x801D2488: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D24A0;
    // 0x801D2488: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D248C:
    // 0x801D248C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D2490: addiu       $v1, $v1, -0x4D8C
    ctx->r3 = ADD32(ctx->r3, -0X4D8C);
    // 0x801D2494: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D2498: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D249C: sw          $zero, -0x4D84($at)
    MEM_W(-0X4D84, ctx->r1) = 0;
L_801D24A0:
    // 0x801D24A0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D24A4: addiu       $a1, $a1, 0x24D8
    ctx->r5 = ADD32(ctx->r5, 0X24D8);
    // 0x801D24A8: jal         0x800058DC
    // 0x801D24AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D24AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D24B0: b           L_801D24CC
    // 0x801D24B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D24CC;
    // 0x801D24B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D24B8:
    // 0x801D24B8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D24BC: addiu       $a1, $a1, 0x2360
    ctx->r5 = ADD32(ctx->r5, 0X2360);
    // 0x801D24C0: jal         0x800058DC
    // 0x801D24C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D24C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D24C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D24CC:
    // 0x801D24CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D24D0: jr          $ra
    // 0x801D24D4: nop

    return;
    // 0x801D24D4: nop

;}
