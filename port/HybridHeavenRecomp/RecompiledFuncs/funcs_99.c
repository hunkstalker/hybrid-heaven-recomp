#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_80230318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230320: bne         $a0, $zero, L_80230330
    if (ctx->r4 != 0) {
        // 0x80230324: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80230330;
    }
    // 0x80230324: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80230328: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8023032C: addiu       $a2, $a2, -0x3FC4
    ctx->r6 = ADD32(ctx->r6, -0X3FC4);
L_80230330:
    // 0x80230330: bne         $a1, $zero, L_80230340
    if (ctx->r5 != 0) {
        // 0x80230334: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80230340;
    }
    // 0x80230334: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80230338: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8023033C: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_80230340:
    // 0x80230340: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80230344: jal         0x8022B640
    // 0x80230348: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_0;
    // 0x80230348: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8023034C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80230350: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80230354: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80230358: lbu         $v1, 0x2D8($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2D8);
    // 0x8023035C: bnel        $v1, $at, L_802303F0
    if (ctx->r3 != ctx->r1) {
        // 0x80230360: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_802303F0;
    }
    goto skip_0;
    // 0x80230360: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_0:
    // 0x80230364: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x80230368: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8023036C: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80230370: bne         $at, $zero, L_8023039C
    if (ctx->r1 != 0) {
        // 0x80230374: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8023039C;
    }
    // 0x80230374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80230378: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8023037C: lwc1        $f4, -0x3880($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3880);
    // 0x80230380: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80230384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80230388: nop

    // 0x8023038C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80230390: nop

    // 0x80230394: bc1fl       L_802303E0
    if (!c1cs) {
        // 0x80230398: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_802303E0;
    }
    goto skip_1;
    // 0x80230398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_8023039C:
    // 0x8023039C: sb          $v0, 0x2D9($a2)
    MEM_B(0X2D9, ctx->r6) = ctx->r2;
    // 0x802303A0: bne         $v1, $zero, L_802303CC
    if (ctx->r3 != 0) {
        // 0x802303A4: sb          $v0, 0x2DB($a2)
        MEM_B(0X2DB, ctx->r6) = ctx->r2;
            goto L_802303CC;
    }
    // 0x802303A4: sb          $v0, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = ctx->r2;
    // 0x802303A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x802303AC: lwc1        $f8, -0x3880($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3880);
    // 0x802303B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x802303B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x802303B8: nop

    // 0x802303BC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x802303C0: nop

    // 0x802303C4: bc1f        L_802303D4
    if (!c1cs) {
        // 0x802303C8: nop
    
            goto L_802303D4;
    }
    // 0x802303C8: nop

L_802303CC:
    // 0x802303CC: b           L_80230474
    // 0x802303D0: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
        goto L_80230474;
    // 0x802303D0: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
L_802303D4:
    // 0x802303D4: b           L_80230474
    // 0x802303D8: sb          $zero, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = 0;
        goto L_80230474;
    // 0x802303D8: sb          $zero, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = 0;
    // 0x802303DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802303E0:
    // 0x802303E0: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x802303E4: b           L_80230474
    // 0x802303E8: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
        goto L_80230474;
    // 0x802303E8: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
    // 0x802303EC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_802303F0:
    // 0x802303F0: bne         $v1, $at, L_80230448
    if (ctx->r3 != ctx->r1) {
        // 0x802303F4: sll         $t6, $v0, 24
        ctx->r14 = S32(ctx->r2 << 24);
            goto L_80230448;
    }
    // 0x802303F4: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x802303F8: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x802303FC: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80230400: bne         $at, $zero, L_8023042C
    if (ctx->r1 != 0) {
        // 0x80230404: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8023042C;
    }
    // 0x80230404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80230408: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8023040C: lwc1        $f16, -0x3880($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3880);
    // 0x80230410: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80230414: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80230418: nop

    // 0x8023041C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80230420: nop

    // 0x80230424: bc1fl       L_8023043C
    if (!c1cs) {
        // 0x80230428: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8023043C;
    }
    goto skip_2;
    // 0x80230428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
L_8023042C:
    // 0x8023042C: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x80230430: b           L_80230474
    // 0x80230434: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
        goto L_80230474;
    // 0x80230434: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
    // 0x80230438: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8023043C:
    // 0x8023043C: sb          $v0, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = ctx->r2;
    // 0x80230440: b           L_80230474
    // 0x80230444: sb          $zero, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = 0;
        goto L_80230474;
    // 0x80230444: sb          $zero, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = 0;
L_80230448:
    // 0x80230448: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8023044C: bne         $v1, $at, L_80230460
    if (ctx->r3 != ctx->r1) {
        // 0x80230450: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80230460;
    }
    // 0x80230450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80230454: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x80230458: b           L_80230474
    // 0x8023045C: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
        goto L_80230474;
    // 0x8023045C: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
L_80230460:
    // 0x80230460: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80230464: bne         $v1, $at, L_80230474
    if (ctx->r3 != ctx->r1) {
        // 0x80230468: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80230474;
    }
    // 0x80230468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8023046C: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x80230470: sb          $v0, 0x2DA($a1)
    MEM_B(0X2DA, ctx->r5) = ctx->r2;
L_80230474:
    // 0x80230474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80230478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8023047C: jr          $ra
    // 0x80230480: nop

    return;
    // 0x80230480: nop

;}
RECOMP_FUNC void M10_FUN_80230484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80230488: sb          $v0, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = ctx->r2;
    // 0x8023048C: jr          $ra
    // 0x80230490: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    return;
    // 0x80230490: sb          $v0, 0x2D9($a0)
    MEM_B(0X2D9, ctx->r4) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230494(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80230494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230494: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80230498: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x8023049C: addiu       $t7, $t7, -0x1CDC
    ctx->r15 = ADD32(ctx->r15, -0X1CDC);
    // 0x802304A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802304A4: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x802304A8: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
L_802304AC:
    // 0x802304AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x802304B0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x802304B4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x802304B8: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x802304BC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x802304C0: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x802304C4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x802304C8: bne         $t7, $t0, L_802304AC
    if (ctx->r15 != ctx->r8) {
        // 0x802304CC: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_802304AC;
    }
    // 0x802304CC: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x802304D0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x802304D4: jal         0x80378EBC
    // 0x802304D8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    LOOKUP_FUNC(0x80378EBC)(rdram, ctx);
        goto after_0;
    // 0x802304D8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    after_0:
    // 0x802304DC: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x802304E0: bne         $at, $zero, L_802304EC
    if (ctx->r1 != 0) {
        // 0x802304E4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_802304EC;
    }
    // 0x802304E4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x802304E8: addiu       $v1, $zero, 0x63
    ctx->r3 = ADD32(0, 0X63);
L_802304EC:
    // 0x802304EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802304F0: addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // 0x802304F4: lbu         $v0, 0x18($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18);
    // 0x802304F8: jr          $ra
    // 0x802304FC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x802304FC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230500(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80230500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230500: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80230504: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80230508: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8023050C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80230510: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80230514: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80230518: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8023051C: jal         0x80378EBC
    // 0x80230520: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    LOOKUP_FUNC(0x80378EBC)(rdram, ctx);
        goto after_0;
    // 0x80230520: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80230524: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80230528: blez        $v0, L_8023062C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8023052C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8023062C;
    }
    // 0x8023052C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80230530: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80230534: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80230538: mflo        $t7
    ctx->r15 = lo;
    // 0x8023053C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80230540: bne         $s2, $zero, L_8023054C
    if (ctx->r18 != 0) {
        // 0x80230544: nop
    
            goto L_8023054C;
    }
    // 0x80230544: nop

    // 0x80230548: break       7
    do_break(2149778760);
L_8023054C:
    // 0x8023054C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80230550: bne         $s2, $at, L_80230564
    if (ctx->r18 != ctx->r1) {
        // 0x80230554: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80230564;
    }
    // 0x80230554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80230558: bne         $t6, $at, L_80230564
    if (ctx->r14 != ctx->r1) {
        // 0x8023055C: nop
    
            goto L_80230564;
    }
    // 0x8023055C: nop

    // 0x80230560: break       6
    do_break(2149778784);
L_80230564:
    // 0x80230564: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80230568: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8023056C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80230570: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80230574: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80230578: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8023057C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80230580: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80230584: ctc1        $s3, $FpcCsr
    set_cop1_cs(ctx->r19);
    // 0x80230588: nop

    // 0x8023058C: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x80230590: cfc1        $s3, $FpcCsr
    ctx->r19 = get_cop1_cs();
    // 0x80230594: nop

    // 0x80230598: andi        $at, $s3, 0x4
    ctx->r1 = ctx->r19 & 0X4;
    // 0x8023059C: andi        $s3, $s3, 0x78
    ctx->r19 = ctx->r19 & 0X78;
    // 0x802305A0: beq         $s3, $zero, L_802305F0
    if (ctx->r19 == 0) {
        // 0x802305A4: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_802305F0;
    }
    // 0x802305A4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x802305A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x802305AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x802305B0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x802305B4: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x802305B8: ctc1        $s3, $FpcCsr
    set_cop1_cs(ctx->r19);
    // 0x802305BC: nop

    // 0x802305C0: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x802305C4: cfc1        $s3, $FpcCsr
    ctx->r19 = get_cop1_cs();
    // 0x802305C8: nop

    // 0x802305CC: andi        $s3, $s3, 0x78
    ctx->r19 = ctx->r19 & 0X78;
    // 0x802305D0: bne         $s3, $zero, L_802305E8
    if (ctx->r19 != 0) {
        // 0x802305D4: nop
    
            goto L_802305E8;
    }
    // 0x802305D4: nop

    // 0x802305D8: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x802305DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802305E0: b           L_80230600
    // 0x802305E4: or          $s3, $s3, $at
    ctx->r19 = ctx->r19 | ctx->r1;
        goto L_80230600;
    // 0x802305E4: or          $s3, $s3, $at
    ctx->r19 = ctx->r19 | ctx->r1;
L_802305E8:
    // 0x802305E8: b           L_80230600
    // 0x802305EC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
        goto L_80230600;
    // 0x802305EC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_802305F0:
    // 0x802305F0: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x802305F4: nop

    // 0x802305F8: bltz        $s3, L_802305E8
    if (SIGNED(ctx->r19) < 0) {
        // 0x802305FC: nop
    
            goto L_802305E8;
    }
    // 0x802305FC: nop

L_80230600:
    // 0x80230600: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80230604: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x80230608: nop

L_8023060C:
    // 0x8023060C: jal         0x8022B640
    // 0x80230610: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_1;
    // 0x80230610: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    after_1:
    // 0x80230614: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80230618: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8023061C: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80230620: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80230624: bne         $at, $zero, L_8023060C
    if (ctx->r1 != 0) {
        // 0x80230628: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_8023060C;
    }
    // 0x80230628: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
L_8023062C:
    // 0x8023062C: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x80230630: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x80230634: bgez        $s1, L_8023064C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80230638: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8023064C;
    }
    // 0x80230638: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8023063C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80230640: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80230644: nop

    // 0x80230648: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8023064C:
    // 0x8023064C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80230650: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80230654: bgez        $t9, L_8023066C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80230658: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8023066C;
    }
    // 0x80230658: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8023065C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80230660: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80230664: nop

    // 0x80230668: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8023066C:
    // 0x8023066C: div.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80230670: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80230674: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80230678: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8023067C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80230680: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80230684: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80230688: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8023068C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80230690: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80230694: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x80230698: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8023069C: ctc1        $s1, $FpcCsr
    set_cop1_cs(ctx->r17);
    // 0x802306A0: nop

    // 0x802306A4: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x802306A8: cfc1        $s1, $FpcCsr
    ctx->r17 = get_cop1_cs();
    // 0x802306AC: nop

    // 0x802306B0: andi        $s1, $s1, 0x78
    ctx->r17 = ctx->r17 & 0X78;
    // 0x802306B4: beql        $s1, $zero, L_80230708
    if (ctx->r17 == 0) {
        // 0x802306B8: mfc1        $s1, $f4
        ctx->r17 = (int32_t)ctx->f4.u32l;
            goto L_80230708;
    }
    goto skip_0;
    // 0x802306B8: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x802306BC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x802306C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x802306C4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x802306C8: sub.d       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f16.d - ctx->f4.d;
    // 0x802306CC: ctc1        $s1, $FpcCsr
    set_cop1_cs(ctx->r17);
    // 0x802306D0: nop

    // 0x802306D4: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x802306D8: cfc1        $s1, $FpcCsr
    ctx->r17 = get_cop1_cs();
    // 0x802306DC: nop

    // 0x802306E0: andi        $s1, $s1, 0x78
    ctx->r17 = ctx->r17 & 0X78;
    // 0x802306E4: bne         $s1, $zero, L_802306FC
    if (ctx->r17 != 0) {
        // 0x802306E8: nop
    
            goto L_802306FC;
    }
    // 0x802306E8: nop

    // 0x802306EC: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x802306F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802306F4: b           L_80230714
    // 0x802306F8: or          $s1, $s1, $at
    ctx->r17 = ctx->r17 | ctx->r1;
        goto L_80230714;
    // 0x802306F8: or          $s1, $s1, $at
    ctx->r17 = ctx->r17 | ctx->r1;
L_802306FC:
    // 0x802306FC: b           L_80230714
    // 0x80230700: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_80230714;
    // 0x80230700: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80230704: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
L_80230708:
    // 0x80230708: nop

    // 0x8023070C: bltz        $s1, L_802306FC
    if (SIGNED(ctx->r17) < 0) {
        // 0x80230710: nop
    
            goto L_802306FC;
    }
    // 0x80230710: nop

L_80230714:
    // 0x80230714: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80230718: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8023071C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80230720: jr          $ra
    // 0x80230724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80230724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80230728(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80230728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8023072C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230730: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80230734: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80230738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8023073C: jal         0x80230500
    // 0x80230740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80230500)(rdram, ctx);
        goto after_0;
    // 0x80230740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80230744: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230748: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8023074C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80230750: lw          $t2, 0x2D4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230754: lhu         $t9, 0x54($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X54);
    // 0x80230758: lhu         $t8, 0x54($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X54);
    // 0x8023075C: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x80230760: lhu         $t7, 0x52($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X52);
    // 0x80230764: lhu         $t6, 0x52($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X52);
    // 0x80230768: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8023076C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80230770: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80230774: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x80230778: lh          $t8, 0x56($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X56);
    // 0x8023077C: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x80230780: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x80230784: lh          $t6, 0xAA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XAA);
    // 0x80230788: lb          $t4, 0x2D($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X2D);
    // 0x8023078C: andi        $t9, $t8, 0x3F00
    ctx->r25 = ctx->r24 & 0X3F00;
    // 0x80230790: sra         $t2, $t9, 8
    ctx->r10 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80230794: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80230798: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8023079C: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x802307A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802307A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x802307A8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x802307AC: lbu         $t1, 0x399($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X399);
    // 0x802307B0: addu        $t0, $t6, $v0
    ctx->r8 = ADD32(ctx->r14, ctx->r2);
    // 0x802307B4: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x802307B8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x802307BC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x802307C0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x802307C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802307C8: bgez        $t1, L_802307DC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x802307CC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_802307DC;
    }
    // 0x802307CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802307D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802307D4: nop

    // 0x802307D8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_802307DC:
    // 0x802307DC: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x802307E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x802307E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x802307E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x802307EC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x802307F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x802307F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x802307F8: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x802307FC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80230800: add.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d + ctx->f6.d;
    // 0x80230804: trunc.w.d   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80230808: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8023080C: nop

    // 0x80230810: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80230814: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80230818: jal         0x80230494
    // 0x8023081C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80230494)(rdram, ctx);
        goto after_1;
    // 0x8023081C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80230820: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230824: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230828: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8023082C: lw          $v1, 0x2D4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230830: lw          $t2, 0x38($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X38);
    // 0x80230834: lh          $t0, 0x1C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1C);
    // 0x80230838: lbu         $t9, 0xA($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XA);
    // 0x8023083C: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80230840: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x80230844: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80230848: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x8023084C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80230850: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x80230854: lh          $t9, 0xAA($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XAA);
    // 0x80230858: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8023085C: lb          $t6, 0x15($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X15);
    // 0x80230860: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230864: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80230868: lbu         $t2, 0xAC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XAC);
    // 0x8023086C: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80230870: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x80230874: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80230878: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8023087C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80230880: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80230884: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80230888: mflo        $t7
    ctx->r15 = lo;
    // 0x8023088C: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x80230890: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80230894: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80230898: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x8023089C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802308A0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x802308A4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x802308A8: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x802308AC: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x802308B0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x802308B4: nop

    // 0x802308B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802308BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802308C0: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x802308C4: beql        $at, $zero, L_802308F8
    if (ctx->r1 == 0) {
        // 0x802308C8: sb          $zero, 0x2DA($a2)
        MEM_B(0X2DA, ctx->r6) = 0;
            goto L_802308F8;
    }
    goto skip_0;
    // 0x802308C8: sb          $zero, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = 0;
    skip_0:
    // 0x802308CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x802308D0: sb          $v1, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = ctx->r3;
    // 0x802308D4: sb          $v1, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = ctx->r3;
    // 0x802308D8: sb          $v1, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = ctx->r3;
    // 0x802308DC: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x802308E0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x802308E4: bne         $at, $zero, L_80230920
    if (ctx->r1 != 0) {
        // 0x802308E8: addiu       $t1, $v0, -0x5
        ctx->r9 = ADD32(ctx->r2, -0X5);
            goto L_80230920;
    }
    // 0x802308E8: addiu       $t1, $v0, -0x5
    ctx->r9 = ADD32(ctx->r2, -0X5);
    // 0x802308EC: b           L_80230920
    // 0x802308F0: sb          $t1, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r9;
        goto L_80230920;
    // 0x802308F0: sb          $t1, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r9;
    // 0x802308F4: sb          $zero, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = 0;
L_802308F8:
    // 0x802308F8: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x802308FC: sb          $v1, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = ctx->r3;
    // 0x80230900: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x80230904: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80230908: slti        $at, $v0, 0xEB
    ctx->r1 = SIGNED(ctx->r2) < 0XEB ? 1 : 0;
    // 0x8023090C: beq         $at, $zero, L_8023091C
    if (ctx->r1 == 0) {
        // 0x80230910: addiu       $t9, $v0, 0x14
        ctx->r25 = ADD32(ctx->r2, 0X14);
            goto L_8023091C;
    }
    // 0x80230910: addiu       $t9, $v0, 0x14
    ctx->r25 = ADD32(ctx->r2, 0X14);
    // 0x80230914: b           L_80230920
    // 0x80230918: sb          $t9, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r25;
        goto L_80230920;
    // 0x80230918: sb          $t9, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r25;
L_8023091C:
    // 0x8023091C: sb          $t8, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r24;
L_80230920:
    // 0x80230920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80230924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80230928: jr          $ra
    // 0x8023092C: nop

    return;
    // 0x8023092C: nop

;}
RECOMP_FUNC void M10_FUN_80230930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80230934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230938: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8023093C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80230940: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80230944: jal         0x80230500
    // 0x80230948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80230500)(rdram, ctx);
        goto after_0;
    // 0x80230948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8023094C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230950: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80230954: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80230958: lw          $t6, 0x2D4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2D4);
    // 0x8023095C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80230960: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x80230964: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80230968: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8023096C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80230970: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80230974: lh          $v1, 0xAA($t9)
    ctx->r3 = MEM_H(ctx->r25, 0XAA);
    // 0x80230978: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x8023097C: bgez        $v1, L_80230990
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80230980: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80230990;
    }
    // 0x80230980: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80230984: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80230988: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8023098C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_80230990:
    // 0x80230990: lhu         $t2, 0x52($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X52);
    // 0x80230994: lhu         $t3, 0x52($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X52);
    // 0x80230998: lh          $t7, 0x56($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X56);
    // 0x8023099C: lhu         $t4, 0x54($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X54);
    // 0x802309A0: lhu         $t5, 0x54($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X54);
    // 0x802309A4: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x802309A8: andi        $t8, $t7, 0x3F00
    ctx->r24 = ctx->r15 & 0X3F00;
    // 0x802309AC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x802309B0: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x802309B4: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x802309B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x802309BC: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x802309C0: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x802309C4: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x802309C8: lbu         $t5, 0x399($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X399);
    // 0x802309CC: addu        $t0, $t4, $a1
    ctx->r8 = ADD32(ctx->r12, ctx->r5);
    // 0x802309D0: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x802309D4: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x802309D8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x802309DC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x802309E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802309E4: bgez        $t5, L_802309F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x802309E8: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_802309F8;
    }
    // 0x802309E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x802309EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x802309F0: nop

    // 0x802309F4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_802309F8:
    // 0x802309F8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x802309FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230A00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80230A04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80230A08: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80230A0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80230A10: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80230A14: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80230A18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80230A1C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80230A20: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80230A24: add.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d + ctx->f6.d;
    // 0x80230A28: trunc.w.d   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80230A2C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80230A30: nop

    // 0x80230A34: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80230A38: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80230A3C: jal         0x80230494
    // 0x80230A40: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80230494)(rdram, ctx);
        goto after_1;
    // 0x80230A40: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80230A44: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230A48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230A4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80230A50: lw          $a0, 0x2D4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230A54: lw          $t9, 0x38($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X38);
    // 0x80230A58: lh          $t0, 0x1C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1C);
    // 0x80230A5C: lbu         $t8, 0xA($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA);
    // 0x80230A60: sll         $t2, $t9, 6
    ctx->r10 = S32(ctx->r25 << 6);
    // 0x80230A64: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x80230A68: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80230A6C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80230A70: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80230A74: addu        $a1, $a3, $t6
    ctx->r5 = ADD32(ctx->r7, ctx->r14);
    // 0x80230A78: lh          $t6, 0xAA($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XAA);
    // 0x80230A7C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80230A80: lb          $t5, 0x15($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X15);
    // 0x80230A84: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230A88: lbu         $t2, 0xAC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XAC);
    // 0x80230A8C: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x80230A90: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80230A94: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80230A98: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80230A9C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80230AA0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80230AA4: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80230AA8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80230AAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80230AB0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80230AB4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230AB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230ABC: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80230AC0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80230AC4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80230AC8: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80230ACC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80230AD0: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80230AD4: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80230AD8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80230ADC: nop

    // 0x80230AE0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230AE4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230AE8: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80230AEC: bne         $at, $zero, L_80230B1C
    if (ctx->r1 != 0) {
        // 0x80230AF0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80230B1C;
    }
    // 0x80230AF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80230AF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80230AF8: sb          $v1, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = ctx->r3;
    // 0x80230AFC: sb          $zero, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = 0;
    // 0x80230B00: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x80230B04: sb          $v1, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = ctx->r3;
    // 0x80230B08: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80230B0C: bne         $at, $zero, L_80230B48
    if (ctx->r1 != 0) {
        // 0x80230B10: addiu       $t6, $v0, -0xA
        ctx->r14 = ADD32(ctx->r2, -0XA);
            goto L_80230B48;
    }
    // 0x80230B10: addiu       $t6, $v0, -0xA
    ctx->r14 = ADD32(ctx->r2, -0XA);
    // 0x80230B14: b           L_80230B48
    // 0x80230B18: sb          $t6, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r14;
        goto L_80230B48;
    // 0x80230B18: sb          $t6, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r14;
L_80230B1C:
    // 0x80230B1C: sb          $zero, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = 0;
    // 0x80230B20: sb          $v1, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = ctx->r3;
    // 0x80230B24: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x80230B28: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x80230B2C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80230B30: slti        $at, $v0, 0xD7
    ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
    // 0x80230B34: beq         $at, $zero, L_80230B44
    if (ctx->r1 == 0) {
        // 0x80230B38: addiu       $t8, $v0, 0x28
        ctx->r24 = ADD32(ctx->r2, 0X28);
            goto L_80230B44;
    }
    // 0x80230B38: addiu       $t8, $v0, 0x28
    ctx->r24 = ADD32(ctx->r2, 0X28);
    // 0x80230B3C: b           L_80230B48
    // 0x80230B40: sb          $t8, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r24;
        goto L_80230B48;
    // 0x80230B40: sb          $t8, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r24;
L_80230B44:
    // 0x80230B44: sb          $t9, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r25;
L_80230B48:
    // 0x80230B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80230B4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80230B50: jr          $ra
    // 0x80230B54: nop

    return;
    // 0x80230B54: nop

;}
RECOMP_FUNC void M10_FUN_80230b58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80230B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230B60: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80230B64: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80230B68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80230B6C: jal         0x80230500
    // 0x80230B70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80230500)(rdram, ctx);
        goto after_0;
    // 0x80230B70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80230B74: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230B78: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80230B7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80230B80: lw          $a1, 0x2D4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230B84: andi        $t2, $v0, 0xFFFF
    ctx->r10 = ctx->r2 & 0XFFFF;
    // 0x80230B88: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x80230B8C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230B90: mflo        $t7
    ctx->r15 = lo;
    // 0x80230B94: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80230B98: lh          $v1, 0xAA($t8)
    ctx->r3 = MEM_H(ctx->r24, 0XAA);
    // 0x80230B9C: bgez        $v1, L_80230BB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80230BA0: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80230BB4;
    }
    // 0x80230BA0: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80230BA4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80230BA8: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x80230BAC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230BB0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80230BB4:
    // 0x80230BB4: lbu         $t5, 0x1A($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1A);
    // 0x80230BB8: lhu         $t9, 0x52($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X52);
    // 0x80230BBC: lhu         $t4, 0x52($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X52);
    // 0x80230BC0: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230BC4: lhu         $t5, 0x54($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X54);
    // 0x80230BC8: subu        $t1, $t9, $t4
    ctx->r9 = SUB32(ctx->r25, ctx->r12);
    // 0x80230BCC: lhu         $t4, 0x54($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X54);
    // 0x80230BD0: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80230BD4: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80230BD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80230BDC: mflo        $t6
    ctx->r14 = lo;
    // 0x80230BE0: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80230BE4: lh          $t7, 0xAA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAA);
    // 0x80230BE8: lbu         $t8, 0xA8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA8);
    // 0x80230BEC: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80230BF0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230BF4: lh          $t8, 0x56($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X56);
    // 0x80230BF8: andi        $t4, $t8, 0x3F00
    ctx->r12 = ctx->r24 & 0X3F00;
    // 0x80230BFC: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80230C00: lbu         $t4, 0x399($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X399);
    // 0x80230C04: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80230C08: mflo        $t9
    ctx->r25 = lo;
    // 0x80230C0C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80230C10: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x80230C14: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x80230C18: addu        $t8, $t6, $t2
    ctx->r24 = ADD32(ctx->r14, ctx->r10);
    // 0x80230C1C: addu        $t0, $t8, $v1
    ctx->r8 = ADD32(ctx->r24, ctx->r3);
    // 0x80230C20: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80230C24: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80230C28: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80230C2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80230C30: bgez        $t4, L_80230C44
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80230C34: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80230C44;
    }
    // 0x80230C34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80230C38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80230C3C: nop

    // 0x80230C40: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80230C44:
    // 0x80230C44: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80230C48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230C4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80230C50: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80230C54: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80230C58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80230C5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80230C60: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80230C64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80230C68: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80230C6C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80230C70: add.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d + ctx->f6.d;
    // 0x80230C74: trunc.w.d   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80230C78: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80230C7C: nop

    // 0x80230C80: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80230C84: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80230C88: jal         0x80230494
    // 0x80230C8C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80230494)(rdram, ctx);
        goto after_1;
    // 0x80230C8C: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80230C90: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80230C94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230C98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80230C9C: lw          $a1, 0x2D4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230CA0: lw          $t6, 0x38($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X38);
    // 0x80230CA4: lh          $t0, 0x1C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1C);
    // 0x80230CA8: lbu         $t5, 0xA($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XA);
    // 0x80230CAC: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x80230CB0: srl         $t4, $t8, 29
    ctx->r12 = S32(U32(ctx->r24) >> 29);
    // 0x80230CB4: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80230CB8: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x80230CBC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80230CC0: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x80230CC4: lh          $t8, 0xAA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XAA);
    // 0x80230CC8: addu        $t7, $a1, $t4
    ctx->r15 = ADD32(ctx->r5, ctx->r12);
    // 0x80230CCC: lb          $t5, 0x15($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X15);
    // 0x80230CD0: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80230CD4: lbu         $t9, 0x4($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X4);
    // 0x80230CD8: lbu         $t7, 0xAC($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAC);
    // 0x80230CDC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80230CE0: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80230CE4: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80230CE8: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80230CEC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80230CF0: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80230CF4: subu        $t8, $t9, $t5
    ctx->r24 = SUB32(ctx->r25, ctx->r13);
    // 0x80230CF8: mflo        $t4
    ctx->r12 = lo;
    // 0x80230CFC: addu        $v1, $t6, $t4
    ctx->r3 = ADD32(ctx->r14, ctx->r12);
    // 0x80230D00: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230D04: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230D08: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80230D0C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80230D10: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80230D14: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80230D18: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80230D1C: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80230D20: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80230D24: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80230D28: nop

    // 0x80230D2C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230D30: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230D34: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80230D38: beq         $at, $zero, L_80230D98
    if (ctx->r1 == 0) {
        // 0x80230D3C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80230D98;
    }
    // 0x80230D3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80230D40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80230D44: sb          $v1, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = ctx->r3;
    // 0x80230D48: lw          $t4, 0x2D4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X2D4);
    // 0x80230D4C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80230D50: addiu       $t8, $t8, 0x42A0
    ctx->r24 = ADD32(ctx->r24, 0X42A0);
    // 0x80230D54: lbu         $t7, 0x1A($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1A);
    // 0x80230D58: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80230D5C: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x80230D60: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x80230D64: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80230D68: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80230D6C: sw          $t6, 0x2D4($a2)
    MEM_W(0X2D4, ctx->r6) = ctx->r14;
    // 0x80230D70: sb          $t7, 0x2D9($a2)
    MEM_B(0X2D9, ctx->r6) = ctx->r15;
    // 0x80230D74: sb          $zero, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = 0;
    // 0x80230D78: sb          $v1, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = ctx->r3;
    // 0x80230D7C: sb          $zero, 0x2DB($a3)
    MEM_B(0X2DB, ctx->r7) = 0;
    // 0x80230D80: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x80230D84: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80230D88: bne         $at, $zero, L_80230DC4
    if (ctx->r1 != 0) {
        // 0x80230D8C: addiu       $t4, $v0, -0x14
        ctx->r12 = ADD32(ctx->r2, -0X14);
            goto L_80230DC4;
    }
    // 0x80230D8C: addiu       $t4, $v0, -0x14
    ctx->r12 = ADD32(ctx->r2, -0X14);
    // 0x80230D90: b           L_80230DC4
    // 0x80230D94: sb          $t4, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r12;
        goto L_80230DC4;
    // 0x80230D94: sb          $t4, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r12;
L_80230D98:
    // 0x80230D98: sb          $zero, 0x2DA($a2)
    MEM_B(0X2DA, ctx->r6) = 0;
    // 0x80230D9C: sb          $v1, 0x2DA($a3)
    MEM_B(0X2DA, ctx->r7) = ctx->r3;
    // 0x80230DA0: lbu         $v0, 0x399($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X399);
    // 0x80230DA4: sb          $zero, 0x2DB($a2)
    MEM_B(0X2DB, ctx->r6) = 0;
    // 0x80230DA8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80230DAC: slti        $at, $v0, 0xAF
    ctx->r1 = SIGNED(ctx->r2) < 0XAF ? 1 : 0;
    // 0x80230DB0: beq         $at, $zero, L_80230DC0
    if (ctx->r1 == 0) {
        // 0x80230DB4: addiu       $t7, $v0, 0x50
        ctx->r15 = ADD32(ctx->r2, 0X50);
            goto L_80230DC0;
    }
    // 0x80230DB4: addiu       $t7, $v0, 0x50
    ctx->r15 = ADD32(ctx->r2, 0X50);
    // 0x80230DB8: b           L_80230DC4
    // 0x80230DBC: sb          $t7, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r15;
        goto L_80230DC4;
    // 0x80230DBC: sb          $t7, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r15;
L_80230DC0:
    // 0x80230DC0: sb          $t9, 0x399($a2)
    MEM_B(0X399, ctx->r6) = ctx->r25;
L_80230DC4:
    // 0x80230DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80230DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80230DCC: jr          $ra
    // 0x80230DD0: nop

    return;
    // 0x80230DD0: nop

;}
RECOMP_FUNC void M10_FUN_80230dd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80230DD4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80230DD8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80230DDC: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80230DE0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80230DE4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80230DE8: addiu       $t7, $a3, -0x44C
    ctx->r15 = ADD32(ctx->r7, -0X44C);
    // 0x80230DEC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80230DF0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80230DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80230DF8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80230DFC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80230E00: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80230E04: bne         $t7, $t0, L_80230E18
    if (ctx->r15 != ctx->r8) {
        // 0x80230E08: or          $t6, $a3, $zero
        ctx->r14 = ctx->r7 | 0;
            goto L_80230E18;
    }
    // 0x80230E08: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x80230E0C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80230E10: b           L_80230E20
    // 0x80230E14: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
        goto L_80230E20;
    // 0x80230E14: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_80230E18:
    // 0x80230E18: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80230E1C: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_80230E20:
    // 0x80230E20: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80230E24: subu        $v0, $a1, $a2
    ctx->r2 = SUB32(ctx->r5, ctx->r6);
    // 0x80230E28: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80230E2C: bne         $t8, $t0, L_80230E40
    if (ctx->r24 != ctx->r8) {
        // 0x80230E30: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80230E40;
    }
    // 0x80230E30: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230E34: lw          $t9, 0x444($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X444);
    // 0x80230E38: b           L_80230E48
    // 0x80230E3C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80230E48;
    // 0x80230E3C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80230E40:
    // 0x80230E40: lw          $t1, 0x448($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X448);
    // 0x80230E44: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80230E48:
    // 0x80230E48: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80230E4C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80230E50: bgezl       $t3, L_80230E60
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80230E54: lhu         $v0, 0x300($a3)
        ctx->r2 = MEM_HU(ctx->r7, 0X300);
            goto L_80230E60;
    }
    goto skip_0;
    // 0x80230E54: lhu         $v0, 0x300($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X300);
    skip_0:
    // 0x80230E58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80230E5C: lhu         $v0, 0x300($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X300);
L_80230E60:
    // 0x80230E60: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80230E64: beql        $at, $zero, L_80230ED0
    if (ctx->r1 == 0) {
        // 0x80230E68: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80230ED0;
    }
    goto skip_1;
    // 0x80230E68: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_1:
    // 0x80230E6C: lbu         $t4, 0x2D9($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2D9);
    // 0x80230E70: slti        $at, $t4, 0x52
    ctx->r1 = SIGNED(ctx->r12) < 0X52 ? 1 : 0;
    // 0x80230E74: beq         $at, $zero, L_80230ECC
    if (ctx->r1 == 0) {
        // 0x80230E78: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80230ECC;
    }
    // 0x80230E78: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80230E7C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80230E80: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230E84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80230E88: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80230E8C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80230E90: mfhi        $t5
    ctx->r13 = hi;
    // 0x80230E94: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80230E98: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80230E9C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80230EA0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80230EA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80230EA8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80230EAC: div.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80230EB0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80230EB4: add.d       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f18.d + ctx->f12.d;
    // 0x80230EB8: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80230EBC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80230EC0: nop

    // 0x80230EC4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230EC8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80230ECC:
    // 0x80230ECC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_80230ED0:
    // 0x80230ED0: lbu         $a0, 0x2D8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2D8);
    // 0x80230ED4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80230ED8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230EDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80230EE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80230EE4: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80230EE8: beql        $at, $zero, L_80231108
    if (ctx->r1 == 0) {
        // 0x80230EEC: lw          $t1, 0x54($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X54);
            goto L_80231108;
    }
    goto skip_2;
    // 0x80230EEC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80230EF0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80230EF4: lwc1        $f0, 0x2F4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2F4);
    // 0x80230EF8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80230EFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80230F00: ldc1        $f8, -0x4D8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4D8);
    // 0x80230F04: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80230F08: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80230F0C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80230F10: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80230F14: c.le.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d <= ctx->f8.d;
    // 0x80230F18: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80230F1C: add.d       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f18.d + ctx->f12.d;
    // 0x80230F20: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80230F24: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80230F28: nop

    // 0x80230F2C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230F30: bc1f        L_80230F94
    if (!c1cs) {
        // 0x80230F34: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80230F94;
    }
    // 0x80230F34: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80230F38: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80230F3C: addiu       $a1, $a1, -0x68D4
    ctx->r5 = ADD32(ctx->r5, -0X68D4);
    // 0x80230F40: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x80230F44: jal         0x80005670
    // 0x80230F48: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x80230F48: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80230F4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80230F50: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80230F54: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80230F58: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80230F5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80230F60: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80230F64: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80230F68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80230F6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80230F70: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80230F74: sb          $t8, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r24;
    // 0x80230F78: bgez        $v1, L_80230F84
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80230F7C: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80230F84;
    }
    // 0x80230F7C: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80230F80: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
L_80230F84:
    // 0x80230F84: sra         $v1, $at, 1
    ctx->r3 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80230F88: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80230F8C: b           L_8023107C
    // 0x80230F90: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_8023107C;
    // 0x80230F90: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80230F94:
    // 0x80230F94: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80230F98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80230F9C: nop

    // 0x80230FA0: c.le.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d <= ctx->f2.d;
    // 0x80230FA4: nop

    // 0x80230FA8: bc1fl       L_80231080
    if (!c1cs) {
        // 0x80230FAC: addiu       $t8, $t0, 0x44C
        ctx->r24 = ADD32(ctx->r8, 0X44C);
            goto L_80231080;
    }
    goto skip_3;
    // 0x80230FAC: addiu       $t8, $t0, 0x44C
    ctx->r24 = ADD32(ctx->r8, 0X44C);
    skip_3:
    // 0x80230FB0: lbu         $t9, 0x30C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X30C);
    // 0x80230FB4: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80230FB8: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80230FBC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80230FC0: bne         $at, $zero, L_8023107C
    if (ctx->r1 != 0) {
        // 0x80230FC4: sb          $t1, 0x30C($a3)
        MEM_B(0X30C, ctx->r7) = ctx->r9;
            goto L_8023107C;
    }
    // 0x80230FC4: sb          $t1, 0x30C($a3)
    MEM_B(0X30C, ctx->r7) = ctx->r9;
    // 0x80230FC8: lhu         $t2, 0x302($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X302);
    // 0x80230FCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80230FD0: slti        $at, $t2, 0x14
    ctx->r1 = SIGNED(ctx->r10) < 0X14 ? 1 : 0;
    // 0x80230FD4: beq         $at, $zero, L_80230FE4
    if (ctx->r1 == 0) {
        // 0x80230FD8: nop
    
            goto L_80230FE4;
    }
    // 0x80230FD8: nop

    // 0x80230FDC: b           L_80230FE4
    // 0x80230FE0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
        goto L_80230FE4;
    // 0x80230FE0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
L_80230FE4:
    // 0x80230FE4: lb          $t3, 0x2D($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X2D);
    // 0x80230FE8: subu        $t5, $t4, $a0
    ctx->r13 = SUB32(ctx->r12, ctx->r4);
    // 0x80230FEC: div         $zero, $t3, $t5
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r13)));
    // 0x80230FF0: mfhi        $t6
    ctx->r14 = hi;
    // 0x80230FF4: bne         $t5, $zero, L_80231000
    if (ctx->r13 != 0) {
        // 0x80230FF8: nop
    
            goto L_80231000;
    }
    // 0x80230FF8: nop

    // 0x80230FFC: break       7
    do_break(2149781500);
L_80231000:
    // 0x80231000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80231004: bne         $t5, $at, L_80231018
    if (ctx->r13 != ctx->r1) {
        // 0x80231008: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80231018;
    }
    // 0x80231008: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8023100C: bne         $t3, $at, L_80231018
    if (ctx->r11 != ctx->r1) {
        // 0x80231010: nop
    
            goto L_80231018;
    }
    // 0x80231010: nop

    // 0x80231014: break       6
    do_break(2149781524);
L_80231018:
    // 0x80231018: bnel        $t6, $zero, L_80231080
    if (ctx->r14 != 0) {
        // 0x8023101C: addiu       $t8, $t0, 0x44C
        ctx->r24 = ADD32(ctx->r8, 0X44C);
            goto L_80231080;
    }
    goto skip_4;
    // 0x8023101C: addiu       $t8, $t0, 0x44C
    ctx->r24 = ADD32(ctx->r8, 0X44C);
    skip_4:
    // 0x80231020: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80231024: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80231028: addiu       $a1, $a1, -0x68D4
    ctx->r5 = ADD32(ctx->r5, -0X68D4);
    // 0x8023102C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80231030: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80231034: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80231038: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8023103C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80231040: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x80231044: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231048: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8023104C: nop

    // 0x80231050: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231054: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231058: jal         0x80005670
    // 0x8023105C: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x8023105C: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_1:
    // 0x80231060: sb          $zero, 0x90($v0)
    MEM_B(0X90, ctx->r2) = 0;
    // 0x80231064: jal         0x80020718
    // 0x80231068: addiu       $a0, $zero, 0x21B
    ctx->r4 = ADD32(0, 0X21B);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x80231068: addiu       $a0, $zero, 0x21B
    ctx->r4 = ADD32(0, 0X21B);
    after_2:
    // 0x8023106C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80231070: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80231074: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80231078: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
L_8023107C:
    // 0x8023107C: addiu       $t8, $t0, 0x44C
    ctx->r24 = ADD32(ctx->r8, 0X44C);
L_80231080:
    // 0x80231080: bnel        $a3, $t8, L_80231094
    if (ctx->r7 != ctx->r24) {
        // 0x80231084: lw          $a0, 0xDC($t0)
        ctx->r4 = MEM_W(ctx->r8, 0XDC);
            goto L_80231094;
    }
    goto skip_5;
    // 0x80231084: lw          $a0, 0xDC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XDC);
    skip_5:
    // 0x80231088: b           L_80231094
    // 0x8023108C: lw          $a0, 0xEC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XEC);
        goto L_80231094;
    // 0x8023108C: lw          $a0, 0xEC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XEC);
    // 0x80231090: lw          $a0, 0xDC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XDC);
L_80231094:
    // 0x80231094: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x80231098: jal         0x8022DA7C
    // 0x8023109C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8022DA7C)(rdram, ctx);
        goto after_3;
    // 0x8023109C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_3:
    // 0x802310A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x802310A4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x802310A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x802310AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x802310B0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802310B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x802310B8: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802310BC: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x802310C0: bne         $v0, $zero, L_802310FC
    if (ctx->r2 != 0) {
        // 0x802310C4: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_802310FC;
    }
    // 0x802310C4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x802310C8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802310CC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x802310D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x802310D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802310D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x802310DC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802310E0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x802310E4: add.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d + ctx->f12.d;
    // 0x802310E8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x802310EC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x802310F0: nop

    // 0x802310F4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802310F8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_802310FC:
    // 0x802310FC: b           L_80231124
    // 0x80231100: lbu         $a0, 0x2D8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2D8);
        goto L_80231124;
    // 0x80231100: lbu         $a0, 0x2D8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2D8);
    // 0x80231104: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
L_80231108:
    // 0x80231108: lbu         $t2, 0x2DB($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2DB);
    // 0x8023110C: bnel        $t2, $zero, L_80231128
    if (ctx->r10 != 0) {
        // 0x80231110: lbu         $t5, 0x2DD($a3)
        ctx->r13 = MEM_BU(ctx->r7, 0X2DD);
            goto L_80231128;
    }
    goto skip_6;
    // 0x80231110: lbu         $t5, 0x2DD($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2DD);
    skip_6:
    // 0x80231114: lbu         $t4, 0x30C($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X30C);
    // 0x80231118: lbu         $a0, 0x2D8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2D8);
    // 0x8023111C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80231120: sb          $t3, 0x30C($a3)
    MEM_B(0X30C, ctx->r7) = ctx->r11;
L_80231124:
    // 0x80231124: lbu         $t5, 0x2DD($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2DD);
L_80231128:
    // 0x80231128: beql        $t5, $zero, L_8023117C
    if (ctx->r13 == 0) {
        // 0x8023112C: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_8023117C;
    }
    goto skip_7;
    // 0x8023112C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x80231130: beq         $a0, $zero, L_80231140
    if (ctx->r4 == 0) {
        // 0x80231134: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80231140;
    }
    // 0x80231134: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80231138: bnel        $a0, $at, L_8023117C
    if (ctx->r4 != ctx->r1) {
        // 0x8023113C: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_8023117C;
    }
    goto skip_8;
    // 0x8023113C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    skip_8:
L_80231140:
    // 0x80231140: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80231144: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80231148: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8023114C: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80231150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80231154: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80231158: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8023115C: sb          $zero, 0x2DB($t7)
    MEM_B(0X2DB, ctx->r15) = 0;
    // 0x80231160: lbu         $a0, 0x2D8($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2D8);
    // 0x80231164: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231168: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8023116C: nop

    // 0x80231170: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231174: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231178: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8023117C:
    // 0x8023117C: addiu       $t9, $t0, 0x7E8
    ctx->r25 = ADD32(ctx->r8, 0X7E8);
    // 0x80231180: bnel        $t8, $t9, L_80231588
    if (ctx->r24 != ctx->r25) {
        // 0x80231184: slti        $at, $a0, 0xB
        ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
            goto L_80231588;
    }
    goto skip_9;
    // 0x80231184: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    skip_9:
    // 0x80231188: lw          $t1, 0x448($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X448);
    // 0x8023118C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80231190: lbu         $t2, 0x74($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X74);
    // 0x80231194: bnel        $t2, $at, L_80231588
    if (ctx->r10 != ctx->r1) {
        // 0x80231198: slti        $at, $a0, 0xB
        ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
            goto L_80231588;
    }
    goto skip_10;
    // 0x80231198: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    skip_10:
    // 0x8023119C: lbu         $t4, 0x2D9($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2D9);
    // 0x802311A0: sltiu       $at, $t4, 0x56
    ctx->r1 = ctx->r12 < 0X56 ? 1 : 0;
    // 0x802311A4: beq         $at, $zero, L_80231530
    if (ctx->r1 == 0) {
        // 0x802311A8: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80231530;
    }
    // 0x802311A8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x802311AC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802311B0: addu        $at, $at, $t4
    gpr jr_addend_802311B8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x802311B4: lw          $t4, -0x4D0($at)
    ctx->r12 = ADD32(ctx->r1, -0X4D0);
    // 0x802311B8: jr          $t4
    // 0x802311BC: nop

    switch (jr_addend_802311B8 >> 2) {
        case 0: goto L_802311C0; break;
        case 1: goto L_802311C0; break;
        case 2: goto L_80231218; break;
        case 3: goto L_80231218; break;
        case 4: goto L_80231270; break;
        case 5: goto L_80231270; break;
        case 6: goto L_802312C8; break;
        case 7: goto L_802312C8; break;
        case 8: goto L_802311C0; break;
        case 9: goto L_802311C0; break;
        case 10: goto L_80231218; break;
        case 11: goto L_80231218; break;
        case 12: goto L_80231270; break;
        case 13: goto L_80231270; break;
        case 14: goto L_80231378; break;
        case 15: goto L_80231378; break;
        case 16: goto L_80231378; break;
        case 17: goto L_80231378; break;
        case 18: goto L_80231378; break;
        case 19: goto L_80231378; break;
        case 20: goto L_802313D0; break;
        case 21: goto L_802313D0; break;
        case 22: goto L_802313D0; break;
        case 23: goto L_802313D0; break;
        case 24: goto L_802313D0; break;
        case 25: goto L_802313D0; break;
        case 26: goto L_80231320; break;
        case 27: goto L_80231320; break;
        case 28: goto L_80231320; break;
        case 29: goto L_80231320; break;
        case 30: goto L_80231320; break;
        case 31: goto L_80231320; break;
        case 32: goto L_80231428; break;
        case 33: goto L_80231428; break;
        case 34: goto L_80231530; break;
        case 35: goto L_80231428; break;
        case 36: goto L_80231428; break;
        case 37: goto L_80231530; break;
        case 38: goto L_80231530; break;
        case 39: goto L_80231530; break;
        case 40: goto L_80231530; break;
        case 41: goto L_80231530; break;
        case 42: goto L_80231530; break;
        case 43: goto L_80231530; break;
        case 44: goto L_80231530; break;
        case 45: goto L_80231530; break;
        case 46: goto L_80231530; break;
        case 47: goto L_80231530; break;
        case 48: goto L_80231530; break;
        case 49: goto L_80231530; break;
        case 50: goto L_80231530; break;
        case 51: goto L_80231530; break;
        case 52: goto L_80231530; break;
        case 53: goto L_80231530; break;
        case 54: goto L_80231530; break;
        case 55: goto L_80231530; break;
        case 56: goto L_802314D8; break;
        case 57: goto L_80231480; break;
        case 58: goto L_80231480; break;
        case 59: goto L_80231480; break;
        case 60: goto L_80231480; break;
        case 61: goto L_80231480; break;
        case 62: goto L_80231530; break;
        case 63: goto L_80231530; break;
        case 64: goto L_80231530; break;
        case 65: goto L_802314D8; break;
        case 66: goto L_802314D8; break;
        case 67: goto L_802314D8; break;
        case 68: goto L_802314D8; break;
        case 69: goto L_802314D8; break;
        case 70: goto L_802314D8; break;
        case 71: goto L_802314D8; break;
        case 72: goto L_802314D8; break;
        case 73: goto L_802314D8; break;
        case 74: goto L_802314D8; break;
        case 75: goto L_802314D8; break;
        case 76: goto L_802314D8; break;
        case 77: goto L_80231530; break;
        case 78: goto L_80231530; break;
        case 79: goto L_80231530; break;
        case 80: goto L_80231378; break;
        case 81: goto L_80231378; break;
        case 82: goto L_80231428; break;
        case 83: goto L_80231428; break;
        case 84: goto L_80231270; break;
        case 85: goto L_802311C0; break;
        default: switch_error(__func__, 0x802311B8, 0x8023FB30);
    }
    // 0x802311BC: nop

L_802311C0:
    // 0x802311C0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x802311C4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802311C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x802311CC: lw          $t5, 0x334($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X334);
    // 0x802311D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802311D4: lbu         $t6, 0x5B($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5B);
    // 0x802311D8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x802311DC: bgez        $t6, L_802311F0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x802311E0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_802311F0;
    }
    // 0x802311E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802311E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802311E8: nop

    // 0x802311EC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_802311F0:
    // 0x802311F0: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x802311F4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x802311F8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x802311FC: add.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f18.d + ctx->f12.d;
    // 0x80231200: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231204: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80231208: nop

    // 0x8023120C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231210: b           L_80231584
    // 0x80231214: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x80231214: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231218:
    // 0x80231218: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8023121C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80231220: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80231224: lw          $t9, 0x334($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X334);
    // 0x80231228: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8023122C: lbu         $t1, 0x5C($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X5C);
    // 0x80231230: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80231234: bgez        $t1, L_80231248
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80231238: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80231248;
    }
    // 0x80231238: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8023123C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231240: nop

    // 0x80231244: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80231248:
    // 0x80231248: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8023124C: div.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80231250: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80231254: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x80231258: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8023125C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231260: nop

    // 0x80231264: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231268: b           L_80231584
    // 0x8023126C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x8023126C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231270:
    // 0x80231270: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80231274: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80231278: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8023127C: lw          $t3, 0x334($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X334);
    // 0x80231280: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80231284: lbu         $t5, 0x5E($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X5E);
    // 0x80231288: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8023128C: bgez        $t5, L_802312A0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80231290: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_802312A0;
    }
    // 0x80231290: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231294: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231298: nop

    // 0x8023129C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_802312A0:
    // 0x802312A0: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x802312A4: div.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x802312A8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802312AC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x802312B0: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x802312B4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x802312B8: nop

    // 0x802312BC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802312C0: b           L_80231584
    // 0x802312C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x802312C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_802312C8:
    // 0x802312C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x802312CC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802312D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x802312D4: lw          $t8, 0x334($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X334);
    // 0x802312D8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802312DC: lbu         $t9, 0x5D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5D);
    // 0x802312E0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x802312E4: bgez        $t9, L_802312F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x802312E8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_802312F8;
    }
    // 0x802312E8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802312EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802312F0: nop

    // 0x802312F4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_802312F8:
    // 0x802312F8: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x802312FC: div.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80231300: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80231304: add.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f18.d + ctx->f12.d;
    // 0x80231308: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8023130C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231310: nop

    // 0x80231314: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231318: b           L_80231584
    // 0x8023131C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x8023131C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231320:
    // 0x80231320: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80231324: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80231328: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8023132C: lw          $t4, 0x334($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X334);
    // 0x80231330: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231334: lbu         $t3, 0x5F($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X5F);
    // 0x80231338: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8023133C: bgez        $t3, L_80231350
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80231340: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80231350;
    }
    // 0x80231340: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80231344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231348: nop

    // 0x8023134C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80231350:
    // 0x80231350: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80231354: div.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80231358: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8023135C: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x80231360: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231364: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80231368: nop

    // 0x8023136C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231370: b           L_80231584
    // 0x80231374: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x80231374: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231378:
    // 0x80231378: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8023137C: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80231380: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80231384: lw          $t7, 0x334($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X334);
    // 0x80231388: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8023138C: lbu         $t8, 0x60($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X60);
    // 0x80231390: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80231394: bgez        $t8, L_802313A8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80231398: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_802313A8;
    }
    // 0x80231398: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8023139C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802313A0: nop

    // 0x802313A4: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_802313A8:
    // 0x802313A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x802313AC: div.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x802313B0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802313B4: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x802313B8: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x802313BC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x802313C0: nop

    // 0x802313C4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802313C8: b           L_80231584
    // 0x802313CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x802313CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_802313D0:
    // 0x802313D0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x802313D4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802313D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x802313DC: lw          $t2, 0x334($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X334);
    // 0x802313E0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802313E4: lbu         $t4, 0x62($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X62);
    // 0x802313E8: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x802313EC: bgez        $t4, L_80231400
    if (SIGNED(ctx->r12) >= 0) {
        // 0x802313F0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80231400;
    }
    // 0x802313F0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802313F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802313F8: nop

    // 0x802313FC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80231400:
    // 0x80231400: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80231404: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80231408: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8023140C: add.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f18.d + ctx->f12.d;
    // 0x80231410: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231414: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80231418: nop

    // 0x8023141C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231420: b           L_80231584
    // 0x80231424: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x80231424: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231428:
    // 0x80231428: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8023142C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80231430: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80231434: lw          $t6, 0x334($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X334);
    // 0x80231438: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8023143C: lbu         $t7, 0x61($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X61);
    // 0x80231440: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80231444: bgez        $t7, L_80231458
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80231448: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80231458;
    }
    // 0x80231448: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8023144C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231450: nop

    // 0x80231454: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80231458:
    // 0x80231458: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8023145C: div.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80231460: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80231464: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x80231468: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8023146C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231470: nop

    // 0x80231474: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231478: b           L_80231584
    // 0x8023147C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x8023147C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231480:
    // 0x80231480: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80231484: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80231488: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8023148C: lw          $t1, 0x334($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X334);
    // 0x80231490: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80231494: lbu         $t2, 0x64($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X64);
    // 0x80231498: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8023149C: bgez        $t2, L_802314B0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x802314A0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_802314B0;
    }
    // 0x802314A0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x802314A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x802314A8: nop

    // 0x802314AC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_802314B0:
    // 0x802314B0: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x802314B4: div.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x802314B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x802314BC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x802314C0: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x802314C4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x802314C8: nop

    // 0x802314CC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802314D0: b           L_80231584
    // 0x802314D4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x802314D4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_802314D8:
    // 0x802314D8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x802314DC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802314E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x802314E4: lw          $t5, 0x334($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X334);
    // 0x802314E8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802314EC: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x802314F0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x802314F4: bgez        $t6, L_80231508
    if (SIGNED(ctx->r14) >= 0) {
        // 0x802314F8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80231508;
    }
    // 0x802314F8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802314FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231500: nop

    // 0x80231504: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80231508:
    // 0x80231508: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8023150C: div.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80231510: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80231514: add.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f18.d + ctx->f12.d;
    // 0x80231518: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8023151C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231520: nop

    // 0x80231524: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231528: b           L_80231584
    // 0x8023152C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231584;
    // 0x8023152C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231530:
    // 0x80231530: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80231534: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80231538: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8023153C: lw          $t9, 0x334($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X334);
    // 0x80231540: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231544: lbu         $t1, 0x63($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X63);
    // 0x80231548: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8023154C: bgez        $t1, L_80231560
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80231550: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80231560;
    }
    // 0x80231550: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80231554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80231558: nop

    // 0x8023155C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80231560:
    // 0x80231560: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80231564: div.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80231568: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8023156C: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x80231570: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231574: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80231578: nop

    // 0x8023157C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231580: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231584:
    // 0x80231584: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
L_80231588:
    // 0x80231588: beql        $at, $zero, L_80231874
    if (ctx->r1 == 0) {
        // 0x8023158C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80231874;
    }
    goto skip_11;
    // 0x8023158C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_11:
    // 0x80231590: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80231594: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80231598: lbu         $a0, 0x75($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X75);
    // 0x8023159C: beq         $a0, $at, L_802315BC
    if (ctx->r4 == ctx->r1) {
        // 0x802315A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_802315BC;
    }
    // 0x802315A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802315A4: beq         $a0, $at, L_802316A4
    if (ctx->r4 == ctx->r1) {
        // 0x802315A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_802316A4;
    }
    // 0x802315A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x802315AC: beql        $a0, $at, L_80231790
    if (ctx->r4 == ctx->r1) {
        // 0x802315B0: lbu         $v0, 0x2D9($a3)
        ctx->r2 = MEM_BU(ctx->r7, 0X2D9);
            goto L_80231790;
    }
    goto skip_12;
    // 0x802315B0: lbu         $v0, 0x2D9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2D9);
    skip_12:
    // 0x802315B4: b           L_80231874
    // 0x802315B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_80231874;
    // 0x802315B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_802315BC:
    // 0x802315BC: lbu         $v0, 0x2D9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2D9);
    // 0x802315C0: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x802315C4: bne         $at, $zero, L_802315DC
    if (ctx->r1 != 0) {
        // 0x802315C8: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_802315DC;
    }
    // 0x802315C8: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x802315CC: beq         $v0, $at, L_802315DC
    if (ctx->r2 == ctx->r1) {
        // 0x802315D0: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_802315DC;
    }
    // 0x802315D0: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x802315D4: bnel        $v0, $at, L_80231614
    if (ctx->r2 != ctx->r1) {
        // 0x802315D8: slti        $at, $v0, 0x25
        ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
            goto L_80231614;
    }
    goto skip_13;
    // 0x802315D8: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    skip_13:
L_802315DC:
    // 0x802315DC: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x802315E0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802315E4: ldc1        $f10, -0x378($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X378);
    // 0x802315E8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802315EC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x802315F0: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x802315F4: add.d       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f6.d + ctx->f12.d;
    // 0x802315F8: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x802315FC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80231600: nop

    // 0x80231604: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231608: b           L_80231870
    // 0x8023160C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x8023160C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231610: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
L_80231614:
    // 0x80231614: bne         $at, $zero, L_8023163C
    if (ctx->r1 != 0) {
        // 0x80231618: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_8023163C;
    }
    // 0x80231618: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8023161C: beq         $v0, $at, L_8023163C
    if (ctx->r2 == ctx->r1) {
        // 0x80231620: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_8023163C;
    }
    // 0x80231620: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x80231624: beq         $v0, $at, L_8023163C
    if (ctx->r2 == ctx->r1) {
        // 0x80231628: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_8023163C;
    }
    // 0x80231628: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8023162C: beq         $v0, $at, L_8023163C
    if (ctx->r2 == ctx->r1) {
        // 0x80231630: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8023163C;
    }
    // 0x80231630: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80231634: bnel        $v0, $at, L_80231674
    if (ctx->r2 != ctx->r1) {
        // 0x80231638: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_80231674;
    }
    goto skip_14;
    // 0x80231638: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_14:
L_8023163C:
    // 0x8023163C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80231640: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231644: ldc1        $f6, -0x370($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X370);
    // 0x80231648: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8023164C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80231650: mul.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80231654: add.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f16.d + ctx->f12.d;
    // 0x80231658: trunc.w.d   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x8023165C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231660: nop

    // 0x80231664: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231668: b           L_80231870
    // 0x8023166C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x8023166C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231670: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_80231674:
    // 0x80231674: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231678: ldc1        $f16, -0x368($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X368);
    // 0x8023167C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231680: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80231684: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80231688: add.d       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f18.d + ctx->f12.d;
    // 0x8023168C: trunc.w.d   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80231690: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80231694: nop

    // 0x80231698: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8023169C: b           L_80231870
    // 0x802316A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x802316A0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_802316A4:
    // 0x802316A4: lbu         $v0, 0x2D9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2D9);
    // 0x802316A8: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x802316AC: bne         $at, $zero, L_802316C4
    if (ctx->r1 != 0) {
        // 0x802316B0: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_802316C4;
    }
    // 0x802316B0: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x802316B4: beq         $v0, $at, L_802316C4
    if (ctx->r2 == ctx->r1) {
        // 0x802316B8: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_802316C4;
    }
    // 0x802316B8: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x802316BC: bnel        $v0, $at, L_802316FC
    if (ctx->r2 != ctx->r1) {
        // 0x802316C0: slti        $at, $v0, 0x25
        ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
            goto L_802316FC;
    }
    goto skip_15;
    // 0x802316C0: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    skip_15:
L_802316C4:
    // 0x802316C4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x802316C8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802316CC: ldc1        $f18, -0x360($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X360);
    // 0x802316D0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x802316D4: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x802316D8: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x802316DC: add.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d + ctx->f12.d;
    // 0x802316E0: trunc.w.d   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x802316E4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x802316E8: nop

    // 0x802316EC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802316F0: b           L_80231870
    // 0x802316F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x802316F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802316F8: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
L_802316FC:
    // 0x802316FC: bne         $at, $zero, L_80231724
    if (ctx->r1 != 0) {
        // 0x80231700: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80231724;
    }
    // 0x80231700: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80231704: beq         $v0, $at, L_80231724
    if (ctx->r2 == ctx->r1) {
        // 0x80231708: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_80231724;
    }
    // 0x80231708: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x8023170C: beq         $v0, $at, L_80231724
    if (ctx->r2 == ctx->r1) {
        // 0x80231710: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_80231724;
    }
    // 0x80231710: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80231714: beq         $v0, $at, L_80231724
    if (ctx->r2 == ctx->r1) {
        // 0x80231718: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_80231724;
    }
    // 0x80231718: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8023171C: bnel        $v0, $at, L_8023175C
    if (ctx->r2 != ctx->r1) {
        // 0x80231720: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_8023175C;
    }
    goto skip_16;
    // 0x80231720: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_16:
L_80231724:
    // 0x80231724: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80231728: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023172C: ldc1        $f8, -0x358($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X358);
    // 0x80231730: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80231734: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80231738: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8023173C: add.d       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f4.d + ctx->f12.d;
    // 0x80231740: trunc.w.d   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80231744: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80231748: nop

    // 0x8023174C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231750: b           L_80231870
    // 0x80231754: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x80231754: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231758: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
L_8023175C:
    // 0x8023175C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231760: ldc1        $f4, -0x350($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X350);
    // 0x80231764: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80231768: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8023176C: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80231770: add.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d + ctx->f12.d;
    // 0x80231774: trunc.w.d   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80231778: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8023177C: nop

    // 0x80231780: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231784: b           L_80231870
    // 0x80231788: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x80231788: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8023178C: lbu         $v0, 0x2D9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2D9);
L_80231790:
    // 0x80231790: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x80231794: bne         $at, $zero, L_802317AC
    if (ctx->r1 != 0) {
        // 0x80231798: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_802317AC;
    }
    // 0x80231798: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x8023179C: beq         $v0, $at, L_802317AC
    if (ctx->r2 == ctx->r1) {
        // 0x802317A0: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_802317AC;
    }
    // 0x802317A0: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x802317A4: bnel        $v0, $at, L_802317E4
    if (ctx->r2 != ctx->r1) {
        // 0x802317A8: slti        $at, $v0, 0x25
        ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
            goto L_802317E4;
    }
    goto skip_17;
    // 0x802317A8: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    skip_17:
L_802317AC:
    // 0x802317AC: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x802317B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802317B4: ldc1        $f10, -0x348($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X348);
    // 0x802317B8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x802317BC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x802317C0: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x802317C4: add.d       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f6.d + ctx->f12.d;
    // 0x802317C8: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x802317CC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x802317D0: nop

    // 0x802317D4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802317D8: b           L_80231870
    // 0x802317DC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x802317DC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802317E0: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
L_802317E4:
    // 0x802317E4: bne         $at, $zero, L_8023180C
    if (ctx->r1 != 0) {
        // 0x802317E8: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_8023180C;
    }
    // 0x802317E8: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x802317EC: beq         $v0, $at, L_8023180C
    if (ctx->r2 == ctx->r1) {
        // 0x802317F0: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_8023180C;
    }
    // 0x802317F0: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x802317F4: beq         $v0, $at, L_8023180C
    if (ctx->r2 == ctx->r1) {
        // 0x802317F8: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_8023180C;
    }
    // 0x802317F8: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x802317FC: beq         $v0, $at, L_8023180C
    if (ctx->r2 == ctx->r1) {
        // 0x80231800: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8023180C;
    }
    // 0x80231800: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80231804: bnel        $v0, $at, L_80231844
    if (ctx->r2 != ctx->r1) {
        // 0x80231808: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_80231844;
    }
    goto skip_18;
    // 0x80231808: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_18:
L_8023180C:
    // 0x8023180C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80231810: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231814: ldc1        $f6, -0x340($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X340);
    // 0x80231818: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8023181C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80231820: mul.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80231824: add.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f16.d + ctx->f12.d;
    // 0x80231828: trunc.w.d   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x8023182C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80231830: nop

    // 0x80231834: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231838: b           L_80231870
    // 0x8023183C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80231870;
    // 0x8023183C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231840: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_80231844:
    // 0x80231844: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231848: ldc1        $f16, -0x338($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X338);
    // 0x8023184C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231850: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80231854: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80231858: add.d       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f18.d + ctx->f12.d;
    // 0x8023185C: trunc.w.d   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80231860: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80231864: nop

    // 0x80231868: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8023186C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231870:
    // 0x80231870: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80231874:
    // 0x80231874: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x80231878: jal         0x8013D3F8
    // 0x8023187C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013D3F8)(rdram, ctx);
        goto after_4;
    // 0x8023187C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_4:
    // 0x80231880: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80231884: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80231888: subu        $t5, $t3, $v0
    ctx->r13 = SUB32(ctx->r11, ctx->r2);
    // 0x8023188C: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80231890: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80231894: mflo        $v1
    ctx->r3 = lo;
    // 0x80231898: nop

    // 0x8023189C: nop

    // 0x802318A0: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x802318A4: mflo        $v1
    ctx->r3 = lo;
    // 0x802318A8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802318AC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802318B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802318B4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x802318B8: mflo        $a0
    ctx->r4 = lo;
    // 0x802318BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x802318C0: jal         0x8022B640
    // 0x802318C4: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_5;
    // 0x802318C4: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    after_5:
    // 0x802318C8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x802318CC: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x802318D0: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x802318D4: lbu         $a0, 0x1033($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X1033);
    // 0x802318D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x802318DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x802318E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802318E4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x802318E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x802318EC: andi        $t6, $a0, 0x7
    ctx->r14 = ctx->r4 & 0X7;
    // 0x802318F0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802318F4: beq         $t6, $zero, L_80231924
    if (ctx->r14 == 0) {
        // 0x802318F8: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_80231924;
    }
    // 0x802318F8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x802318FC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80231900: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x80231904: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80231908: mflo        $v1
    ctx->r3 = lo;
    // 0x8023190C: bgez        $v1, L_80231918
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80231910: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80231918;
    }
    // 0x80231910: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80231914: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
L_80231918:
    // 0x80231918: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
    // 0x8023191C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231920: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80231924:
    // 0x80231924: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80231928: andi        $t3, $a0, 0x8
    ctx->r11 = ctx->r4 & 0X8;
    // 0x8023192C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80231930: lbu         $t9, 0x2DB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2DB);
    // 0x80231934: beql        $t9, $zero, L_802319EC
    if (ctx->r25 == 0) {
        // 0x80231938: slti        $at, $v1, 0x2710
        ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
            goto L_802319EC;
    }
    goto skip_19;
    // 0x80231938: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    skip_19:
    // 0x8023193C: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    // 0x80231940: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80231944: bnel        $v0, $at, L_80231984
    if (ctx->r2 != ctx->r1) {
        // 0x80231948: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80231984;
    }
    goto skip_20;
    // 0x80231948: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_20:
    // 0x8023194C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80231950: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80231954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80231958: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8023195C: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80231960: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80231964: add.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d + ctx->f12.d;
    // 0x80231968: trunc.w.d   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8023196C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80231970: nop

    // 0x80231974: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231978: b           L_802319E8
    // 0x8023197C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_802319E8;
    // 0x8023197C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231980: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_80231984:
    // 0x80231984: bnel        $v0, $at, L_802319C4
    if (ctx->r2 != ctx->r1) {
        // 0x80231988: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_802319C4;
    }
    goto skip_21;
    // 0x80231988: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_21:
    // 0x8023198C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80231990: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80231994: ldc1        $f8, -0x330($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X330);
    // 0x80231998: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8023199C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x802319A0: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x802319A4: add.d       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f4.d + ctx->f12.d;
    // 0x802319A8: trunc.w.d   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x802319AC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x802319B0: nop

    // 0x802319B4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x802319B8: b           L_802319E8
    // 0x802319BC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_802319E8;
    // 0x802319BC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802319C0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_802319C4:
    // 0x802319C4: beq         $v0, $at, L_802319E8
    if (ctx->r2 == ctx->r1) {
        // 0x802319C8: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_802319E8;
    }
    // 0x802319C8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x802319CC: beql        $v0, $at, L_802319EC
    if (ctx->r2 == ctx->r1) {
        // 0x802319D0: slti        $at, $v1, 0x2710
        ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
            goto L_802319EC;
    }
    goto skip_22;
    // 0x802319D0: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    skip_22:
    // 0x802319D4: lbu         $t4, 0x2D8($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2D8);
    // 0x802319D8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x802319DC: beql        $t4, $at, L_802319EC
    if (ctx->r12 == ctx->r1) {
        // 0x802319E0: slti        $at, $v1, 0x2710
        ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
            goto L_802319EC;
    }
    goto skip_23;
    // 0x802319E0: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    skip_23:
    // 0x802319E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_802319E8:
    // 0x802319E8: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
L_802319EC:
    // 0x802319EC: bne         $at, $zero, L_802319F8
    if (ctx->r1 != 0) {
        // 0x802319F0: nop
    
            goto L_802319F8;
    }
    // 0x802319F0: nop

    // 0x802319F4: addiu       $v1, $zero, 0x270F
    ctx->r3 = ADD32(0, 0X270F);
L_802319F8:
    // 0x802319F8: beql        $t3, $zero, L_80231A10
    if (ctx->r11 == 0) {
        // 0x802319FC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80231A10;
    }
    goto skip_24;
    // 0x802319FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_24:
    // 0x80231A00: bnel        $t5, $t0, L_80231A10
    if (ctx->r13 != ctx->r8) {
        // 0x80231A04: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80231A10;
    }
    goto skip_25;
    // 0x80231A04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_25:
    // 0x80231A08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80231A0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80231A10:
    // 0x80231A10: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80231A14: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80231A18: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x80231A1C: jal         0x8023011C
    // 0x80231A20: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8023011C)(rdram, ctx);
        goto after_6;
    // 0x80231A20: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_6:
    // 0x80231A24: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80231A28: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80231A2C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x80231A30: addiu       $a1, $a1, 0x76F0
    ctx->r5 = ADD32(ctx->r5, 0X76F0);
    // 0x80231A34: sh          $v1, 0x40($t6)
    MEM_H(0X40, ctx->r14) = ctx->r3;
    // 0x80231A38: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80231A3C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80231A40: sh          $t7, 0x9A($t8)
    MEM_H(0X9A, ctx->r24) = ctx->r15;
    // 0x80231A44: jal         0x80005670
    // 0x80231A48: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_7;
    // 0x80231A48: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80231A4C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80231A50: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80231A54: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80231A58: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80231A5C: sh          $t9, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r25;
    // 0x80231A60: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80231A64: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80231A68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80231A6C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80231A70: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80231A74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80231A78: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80231A7C: bne         $t1, $t0, L_80231A8C
    if (ctx->r9 != ctx->r8) {
        // 0x80231A80: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80231A8C;
    }
    // 0x80231A80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80231A84: b           L_80231A94
    // 0x80231A88: sb          $zero, 0x96($v0)
    MEM_B(0X96, ctx->r2) = 0;
        goto L_80231A94;
    // 0x80231A88: sb          $zero, 0x96($v0)
    MEM_B(0X96, ctx->r2) = 0;
L_80231A8C:
    // 0x80231A8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80231A90: sb          $t2, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r10;
L_80231A94:
    // 0x80231A94: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80231A98: sb          $zero, 0x97($a2)
    MEM_B(0X97, ctx->r6) = 0;
    // 0x80231A9C: sb          $t4, 0x98($a2)
    MEM_B(0X98, ctx->r6) = ctx->r12;
    // 0x80231AA0: lbu         $t3, 0x2D9($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X2D9);
    // 0x80231AA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80231AA8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80231AAC: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80231AB0: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80231AB4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80231AB8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80231ABC: lbu         $t6, 0x42A5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X42A5);
    // 0x80231AC0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80231AC4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80231AC8: bgez        $t6, L_80231AE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80231ACC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80231AE0;
    }
    // 0x80231ACC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80231AD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80231AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80231AD8: nop

    // 0x80231ADC: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80231AE0:
    // 0x80231AE0: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80231AE4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80231AE8: div.s       $f16, $f6, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80231AEC: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80231AF0: add.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d + ctx->f12.d;
    // 0x80231AF4: trunc.w.d   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80231AF8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80231AFC: nop

    // 0x80231B00: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80231B04: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80231B08: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x80231B0C: jal         0x8022F248
    // 0x80231B10: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8022F248)(rdram, ctx);
        goto after_8;
    // 0x80231B10: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_8:
    // 0x80231B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231B18: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80231B1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80231B20: jr          $ra
    // 0x80231B24: nop

    return;
    // 0x80231B24: nop

;}
RECOMP_FUNC void M10_FUN_80231b28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80231B28: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80231B2C: lbu         $v0, -0x33E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80231b30(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80231b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80231B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80231B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80231B38: bne         $v0, $zero, L_80231B4C
    if (ctx->r2 != 0) {
        // 0x80231B3C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80231B4C;
    }
    // 0x80231B3C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80231B40: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80231B44: b           L_80231B50
    // 0x80231B48: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
        goto L_80231B50;
    // 0x80231B48: addiu       $a0, $a0, -0x3C28
    ctx->r4 = ADD32(ctx->r4, -0X3C28);
L_80231B4C:
    // 0x80231B4C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80231B50:
    // 0x80231B50: bne         $v0, $zero, L_80231B64
    if (ctx->r2 != 0) {
        // 0x80231B54: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80231B64;
    }
    // 0x80231B54: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80231B58: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80231B5C: b           L_80231B68
    // 0x80231B60: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
        goto L_80231B68;
    // 0x80231B60: addiu       $a1, $a1, -0x3FC4
    ctx->r5 = ADD32(ctx->r5, -0X3FC4);
L_80231B64:
    // 0x80231B64: addiu       $a1, $a1, -0x3C28
    ctx->r5 = ADD32(ctx->r5, -0X3C28);
L_80231B68:
    // 0x80231B68: lbu         $v0, 0x2D8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2D8);
    // 0x80231B6C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80231B70: bne         $at, $zero, L_80231B88
    if (ctx->r1 != 0) {
        // 0x80231B74: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80231B88;
    }
    // 0x80231B74: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80231B78: beq         $v0, $at, L_80231B88
    if (ctx->r2 == ctx->r1) {
        // 0x80231B7C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80231B88;
    }
    // 0x80231B7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80231B80: bnel        $v0, $at, L_80231BAC
    if (ctx->r2 != ctx->r1) {
        // 0x80231B84: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80231BAC;
    }
    goto skip_0;
    // 0x80231B84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
L_80231B88:
    // 0x80231B88: lbu         $t6, 0x2D8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80231B8C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80231B90: bnel        $t6, $at, L_80231CD8
    if (ctx->r14 != ctx->r1) {
        // 0x80231B94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80231CD8;
    }
    goto skip_1;
    // 0x80231B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80231B98: jal         0x802302D0
    // 0x80231B9C: nop

    LOOKUP_FUNC(0x802302D0)(rdram, ctx);
        goto after_0;
    // 0x80231B9C: nop

    after_0:
    // 0x80231BA0: b           L_80231CD8
    // 0x80231BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80231BAC:
    // 0x80231BAC: bnel        $v0, $at, L_80231C40
    if (ctx->r2 != ctx->r1) {
        // 0x80231BB0: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80231C40;
    }
    goto skip_2;
    // 0x80231BB0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_2:
    // 0x80231BB4: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80231BB8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80231BBC: bnel        $v0, $at, L_80231BD8
    if (ctx->r2 != ctx->r1) {
        // 0x80231BC0: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80231BD8;
    }
    goto skip_3;
    // 0x80231BC0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_3:
    // 0x80231BC4: jal         0x80230728
    // 0x80231BC8: nop

    LOOKUP_FUNC(0x80230728)(rdram, ctx);
        goto after_1;
    // 0x80231BC8: nop

    after_1:
    // 0x80231BCC: b           L_80231CD8
    // 0x80231BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231BD4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_80231BD8:
    // 0x80231BD8: bnel        $v0, $at, L_80231BF4
    if (ctx->r2 != ctx->r1) {
        // 0x80231BDC: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80231BF4;
    }
    goto skip_4;
    // 0x80231BDC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_4:
    // 0x80231BE0: jal         0x80230930
    // 0x80231BE4: nop

    LOOKUP_FUNC(0x80230930)(rdram, ctx);
        goto after_2;
    // 0x80231BE4: nop

    after_2:
    // 0x80231BE8: b           L_80231CD8
    // 0x80231BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231BF0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_80231BF4:
    // 0x80231BF4: bnel        $v0, $at, L_80231C10
    if (ctx->r2 != ctx->r1) {
        // 0x80231BF8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80231C10;
    }
    goto skip_5;
    // 0x80231BF8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_5:
    // 0x80231BFC: jal         0x80230B58
    // 0x80231C00: nop

    LOOKUP_FUNC(0x80230B58)(rdram, ctx);
        goto after_3;
    // 0x80231C00: nop

    after_3:
    // 0x80231C04: b           L_80231CD8
    // 0x80231C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231C0C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_80231C10:
    // 0x80231C10: bne         $v0, $at, L_80231C20
    if (ctx->r2 != ctx->r1) {
        // 0x80231C14: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80231C20;
    }
    // 0x80231C14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80231C18: b           L_80231CD4
    // 0x80231C1C: sb          $t7, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = ctx->r15;
        goto L_80231CD4;
    // 0x80231C1C: sb          $t7, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = ctx->r15;
L_80231C20:
    // 0x80231C20: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80231C24: beq         $v0, $at, L_80231C34
    if (ctx->r2 == ctx->r1) {
        // 0x80231C28: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80231C34;
    }
    // 0x80231C28: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80231C2C: bnel        $v0, $at, L_80231CD8
    if (ctx->r2 != ctx->r1) {
        // 0x80231C30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80231CD8;
    }
    goto skip_6;
    // 0x80231C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
L_80231C34:
    // 0x80231C34: b           L_80231CD4
    // 0x80231C38: sb          $zero, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = 0;
        goto L_80231CD4;
    // 0x80231C38: sb          $zero, 0x2DB($a0)
    MEM_B(0X2DB, ctx->r4) = 0;
    // 0x80231C3C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_80231C40:
    // 0x80231C40: bne         $at, $zero, L_80231C8C
    if (ctx->r1 != 0) {
        // 0x80231C44: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80231C8C;
    }
    // 0x80231C44: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80231C48: beql        $at, $zero, L_80231C90
    if (ctx->r1 == 0) {
        // 0x80231C4C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80231C90;
    }
    goto skip_7;
    // 0x80231C4C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_7:
    // 0x80231C50: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80231C54: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80231C58: bnel        $v0, $at, L_80231C74
    if (ctx->r2 != ctx->r1) {
        // 0x80231C5C: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80231C74;
    }
    goto skip_8;
    // 0x80231C5C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_8:
    // 0x80231C60: jal         0x80230930
    // 0x80231C64: nop

    LOOKUP_FUNC(0x80230930)(rdram, ctx);
        goto after_4;
    // 0x80231C64: nop

    after_4:
    // 0x80231C68: b           L_80231CD8
    // 0x80231C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231C70: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_80231C74:
    // 0x80231C74: bnel        $v0, $at, L_80231CD8
    if (ctx->r2 != ctx->r1) {
        // 0x80231C78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80231CD8;
    }
    goto skip_9;
    // 0x80231C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80231C7C: jal         0x80230B58
    // 0x80231C80: nop

    LOOKUP_FUNC(0x80230B58)(rdram, ctx);
        goto after_5;
    // 0x80231C80: nop

    after_5:
    // 0x80231C84: b           L_80231CD8
    // 0x80231C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80231C8C:
    // 0x80231C8C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80231C90:
    // 0x80231C90: bnel        $v0, $at, L_80231CBC
    if (ctx->r2 != ctx->r1) {
        // 0x80231C94: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80231CBC;
    }
    goto skip_10;
    // 0x80231C94: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_10:
    // 0x80231C98: lbu         $t8, 0x2D8($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80231C9C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80231CA0: bnel        $t8, $at, L_80231CD8
    if (ctx->r24 != ctx->r1) {
        // 0x80231CA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80231CD8;
    }
    goto skip_11;
    // 0x80231CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80231CA8: jal         0x80230B58
    // 0x80231CAC: nop

    LOOKUP_FUNC(0x80230B58)(rdram, ctx);
        goto after_6;
    // 0x80231CAC: nop

    after_6:
    // 0x80231CB0: b           L_80231CD8
    // 0x80231CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80231CD8;
    // 0x80231CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80231CB8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_80231CBC:
    // 0x80231CBC: beq         $v0, $at, L_80231CCC
    if (ctx->r2 == ctx->r1) {
        // 0x80231CC0: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80231CCC;
    }
    // 0x80231CC0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80231CC4: bnel        $v0, $at, L_80231CD8
    if (ctx->r2 != ctx->r1) {
        // 0x80231CC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80231CD8;
    }
    goto skip_12;
    // 0x80231CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
L_80231CCC:
    // 0x80231CCC: jal         0x80230318
    // 0x80231CD0: nop

    LOOKUP_FUNC(0x80230318)(rdram, ctx);
        goto after_7;
    // 0x80231CD0: nop

    after_7:
L_80231CD4:
    // 0x80231CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80231CD8:
    // 0x80231CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80231CDC: jr          $ra
    // 0x80231CE0: nop

    return;
    // 0x80231CE0: nop

;}
RECOMP_FUNC void M10_FUN_80231ce4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80231CE4: jr          $ra
    // 0x80231CE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80231CE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80231cec(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80231cec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80231CEC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80231CF0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80231CF4: lbu         $t6, 0x1030($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1030);
    // 0x80231CF8: bnel        $t6, $zero, L_80231D30
    if (ctx->r14 != 0) {
        // 0x80231CFC: lbu         $v0, 0xAE4($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XAE4);
            goto L_80231D30;
    }
    goto skip_0;
    // 0x80231CFC: lbu         $v0, 0xAE4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XAE4);
    skip_0:
    // 0x80231D00: lbu         $v0, 0x748($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X748);
    // 0x80231D04: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80231D08: beql        $at, $zero, L_80231D58
    if (ctx->r1 == 0) {
        // 0x80231D0C: lbu         $v0, 0x747($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X747);
            goto L_80231D58;
    }
    goto skip_1;
    // 0x80231D0C: lbu         $v0, 0x747($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X747);
    skip_1:
    // 0x80231D10: lbu         $t7, 0x724($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X724);
    // 0x80231D14: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80231D18: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80231D1C: beql        $t7, $at, L_80231D58
    if (ctx->r15 == ctx->r1) {
        // 0x80231D20: lbu         $v0, 0x747($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X747);
            goto L_80231D58;
    }
    goto skip_2;
    // 0x80231D20: lbu         $v0, 0x747($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X747);
    skip_2:
    // 0x80231D24: b           L_80231D54
    // 0x80231D28: sb          $t8, 0x748($v1)
    MEM_B(0X748, ctx->r3) = ctx->r24;
        goto L_80231D54;
    // 0x80231D28: sb          $t8, 0x748($v1)
    MEM_B(0X748, ctx->r3) = ctx->r24;
    // 0x80231D2C: lbu         $v0, 0xAE4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XAE4);
L_80231D30:
    // 0x80231D30: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80231D34: beql        $at, $zero, L_80231D58
    if (ctx->r1 == 0) {
        // 0x80231D38: lbu         $v0, 0x747($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X747);
            goto L_80231D58;
    }
    goto skip_3;
    // 0x80231D38: lbu         $v0, 0x747($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X747);
    skip_3:
    // 0x80231D3C: lbu         $t9, 0xAC0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XAC0);
    // 0x80231D40: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80231D44: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80231D48: beql        $t9, $at, L_80231D58
    if (ctx->r25 == ctx->r1) {
        // 0x80231D4C: lbu         $v0, 0x747($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X747);
            goto L_80231D58;
    }
    goto skip_4;
    // 0x80231D4C: lbu         $v0, 0x747($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X747);
    skip_4:
    // 0x80231D50: sb          $t0, 0xAE4($v1)
    MEM_B(0XAE4, ctx->r3) = ctx->r8;
L_80231D54:
    // 0x80231D54: lbu         $v0, 0x747($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X747);
L_80231D58:
    // 0x80231D58: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80231D5C: beq         $at, $zero, L_80231D68
    if (ctx->r1 == 0) {
        // 0x80231D60: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80231D68;
    }
    // 0x80231D60: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80231D64: sb          $t1, 0x747($v1)
    MEM_B(0X747, ctx->r3) = ctx->r9;
L_80231D68:
    // 0x80231D68: lbu         $v0, 0xAE3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XAE3);
    // 0x80231D6C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80231D70: beq         $at, $zero, L_80231D7C
    if (ctx->r1 == 0) {
        // 0x80231D74: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80231D7C;
    }
    // 0x80231D74: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80231D78: sb          $t2, 0xAE3($v1)
    MEM_B(0XAE3, ctx->r3) = ctx->r10;
L_80231D7C:
    // 0x80231D7C: jr          $ra
    // 0x80231D80: nop

    return;
    // 0x80231D80: nop

;}
RECOMP_FUNC void M10_FUN_80231d84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80231D84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80231D88: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80231D8C: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80231D90: lbu         $v1, 0x74B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X74B);
    // 0x80231D94: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80231D98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80231D9C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80231DA0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80231DA4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80231DA8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80231DAC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80231DB0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80231DB4: beq         $at, $zero, L_80231FF0
    if (ctx->r1 == 0) {
        // 0x80231DB8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80231FF0;
    }
    // 0x80231DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80231DBC: lhu         $v0, 0x2C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2C);
    // 0x80231DC0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80231DC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80231DC8: beq         $v0, $at, L_80231E00
    if (ctx->r2 == ctx->r1) {
        // 0x80231DCC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80231E00;
    }
    // 0x80231DCC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80231DD0: beq         $v0, $at, L_80231E00
    if (ctx->r2 == ctx->r1) {
        // 0x80231DD4: nop
    
            goto L_80231E00;
    }
    // 0x80231DD4: nop

    // 0x80231DD8: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80231DDC: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80231DE0: beq         $v0, $at, L_80231E00
    if (ctx->r2 == ctx->r1) {
        // 0x80231DE4: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80231E00;
    }
    // 0x80231DE4: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80231DE8: beq         $v0, $at, L_80231E00
    if (ctx->r2 == ctx->r1) {
        // 0x80231DEC: addiu       $at, $zero, 0x5F
        ctx->r1 = ADD32(0, 0X5F);
            goto L_80231E00;
    }
    // 0x80231DEC: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x80231DF0: beq         $v0, $at, L_80231E00
    if (ctx->r2 == ctx->r1) {
        // 0x80231DF4: slti        $at, $v0, 0xB5
        ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
            goto L_80231E00;
    }
    // 0x80231DF4: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x80231DF8: bne         $at, $zero, L_80231E0C
    if (ctx->r1 != 0) {
        // 0x80231DFC: nop
    
            goto L_80231E0C;
    }
    // 0x80231DFC: nop

L_80231E00:
    // 0x80231E00: lbu         $t6, -0x226E($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X226E);
    // 0x80231E04: beql        $t6, $zero, L_80231FF4
    if (ctx->r14 == 0) {
        // 0x80231E08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80231FF4;
    }
    goto skip_0;
    // 0x80231E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80231E0C:
    // 0x80231E0C: bne         $v1, $zero, L_80231EA8
    if (ctx->r3 != 0) {
        // 0x80231E10: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80231EA8;
    }
    // 0x80231E10: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80231E14: jal         0x8022B640
    // 0x80231E18: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_0;
    // 0x80231E18: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x80231E1C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80231E20: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80231E24: andi        $s1, $v1, 0xFF
    ctx->r17 = ctx->r3 & 0XFF;
    // 0x80231E28: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    // 0x80231E2C: jal         0x80379230
    // 0x80231E30: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    LOOKUP_FUNC(0x80379230)(rdram, ctx);
        goto after_1;
    // 0x80231E30: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_1:
    // 0x80231E34: beql        $v0, $zero, L_80231E80
    if (ctx->r2 == 0) {
        // 0x80231E38: slti        $at, $s0, 0x64
        ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
            goto L_80231E80;
    }
    goto skip_1;
    // 0x80231E38: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    skip_1:
L_80231E3C:
    // 0x80231E3C: jal         0x8013D5F4
    // 0x80231E40: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_2;
    // 0x80231E40: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_2:
    // 0x80231E44: jal         0x8022B640
    // 0x80231E48: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_3;
    // 0x80231E48: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_3:
    // 0x80231E4C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80231E50: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80231E54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80231E58: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x80231E5C: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    // 0x80231E60: andi        $s1, $v1, 0xFF
    ctx->r17 = ctx->r3 & 0XFF;
    // 0x80231E64: jal         0x80379230
    // 0x80231E68: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80379230)(rdram, ctx);
        goto after_4;
    // 0x80231E68: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    after_4:
    // 0x80231E6C: beq         $v0, $zero, L_80231E7C
    if (ctx->r2 == 0) {
        // 0x80231E70: slti        $at, $s0, 0x64
        ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
            goto L_80231E7C;
    }
    // 0x80231E70: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x80231E74: bne         $at, $zero, L_80231E3C
    if (ctx->r1 != 0) {
        // 0x80231E78: nop
    
            goto L_80231E3C;
    }
    // 0x80231E78: nop

L_80231E7C:
    // 0x80231E7C: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
L_80231E80:
    // 0x80231E80: bne         $at, $zero, L_80231E98
    if (ctx->r1 != 0) {
        // 0x80231E84: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80231E98;
    }
    // 0x80231E84: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80231E88: jal         0x8013D5F4
    // 0x80231E8C: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_5;
    // 0x80231E8C: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    after_5:
    // 0x80231E90: b           L_80231F64
    // 0x80231E94: nop

        goto L_80231F64;
    // 0x80231E94: nop

L_80231E98:
    // 0x80231E98: jal         0x8013D5F4
    // 0x80231E9C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_6;
    // 0x80231E9C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_6:
    // 0x80231EA0: b           L_80231F64
    // 0x80231EA4: nop

        goto L_80231F64;
    // 0x80231EA4: nop

L_80231EA8:
    // 0x80231EA8: lh          $v0, -0x3FC4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3FC4);
    // 0x80231EAC: slti        $at, $v0, 0x1F4
    ctx->r1 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80231EB0: beq         $at, $zero, L_80231EEC
    if (ctx->r1 == 0) {
        // 0x80231EB4: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80231EEC;
    }
    // 0x80231EB4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80231EB8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80231EBC: mflo        $a0
    ctx->r4 = lo;
    // 0x80231EC0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80231EC4: jal         0x8022B640
    // 0x80231EC8: nop

    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_7;
    // 0x80231EC8: nop

    after_7:
    // 0x80231ECC: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80231ED0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80231ED4: beq         $at, $zero, L_80231EE4
    if (ctx->r1 == 0) {
        // 0x80231ED8: nop
    
            goto L_80231EE4;
    }
    // 0x80231ED8: nop

    // 0x80231EDC: b           L_80231F5C
    // 0x80231EE0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80231F5C;
    // 0x80231EE0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80231EE4:
    // 0x80231EE4: b           L_80231F5C
    // 0x80231EE8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80231F5C;
    // 0x80231EE8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80231EEC:
    // 0x80231EEC: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x80231EF0: beq         $at, $zero, L_80231F2C
    if (ctx->r1 == 0) {
        // 0x80231EF4: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80231F2C;
    }
    // 0x80231EF4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80231EF8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80231EFC: mflo        $a0
    ctx->r4 = lo;
    // 0x80231F00: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80231F04: jal         0x8022B640
    // 0x80231F08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_8;
    // 0x80231F08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_8:
    // 0x80231F0C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80231F10: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80231F14: beq         $at, $zero, L_80231F24
    if (ctx->r1 == 0) {
        // 0x80231F18: nop
    
            goto L_80231F24;
    }
    // 0x80231F18: nop

    // 0x80231F1C: b           L_80231F5C
    // 0x80231F20: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80231F5C;
    // 0x80231F20: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80231F24:
    // 0x80231F24: b           L_80231F5C
    // 0x80231F28: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_80231F5C;
    // 0x80231F28: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80231F2C:
    // 0x80231F2C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80231F30: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80231F34: mflo        $a0
    ctx->r4 = lo;
    // 0x80231F38: addiu       $a0, $a0, -0x9
    ctx->r4 = ADD32(ctx->r4, -0X9);
    // 0x80231F3C: jal         0x8022B640
    // 0x80231F40: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8022B640)(rdram, ctx);
        goto after_9;
    // 0x80231F40: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_9:
    // 0x80231F44: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x80231F48: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80231F4C: beq         $at, $zero, L_80231F5C
    if (ctx->r1 == 0) {
        // 0x80231F50: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80231F5C;
    }
    // 0x80231F50: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80231F54: b           L_80231F5C
    // 0x80231F58: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_80231F5C;
    // 0x80231F58: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80231F5C:
    // 0x80231F5C: jal         0x8013D5F4
    // 0x80231F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_10;
    // 0x80231F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_10:
L_80231F64:
    // 0x80231F64: beq         $s1, $zero, L_80231FF0
    if (ctx->r17 == 0) {
        // 0x80231F68: slti        $at, $s1, 0x26
        ctx->r1 = SIGNED(ctx->r17) < 0X26 ? 1 : 0;
            goto L_80231FF0;
    }
    // 0x80231F68: slti        $at, $s1, 0x26
    ctx->r1 = SIGNED(ctx->r17) < 0X26 ? 1 : 0;
    // 0x80231F6C: beq         $at, $zero, L_80231FF0
    if (ctx->r1 == 0) {
        // 0x80231F70: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80231FF0;
    }
    // 0x80231F70: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80231F74: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80231F78: jal         0x8013D4A0
    // 0x80231F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_11;
    // 0x80231F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80231F80: slti        $at, $v0, 0x63
    ctx->r1 = SIGNED(ctx->r2) < 0X63 ? 1 : 0;
    // 0x80231F84: beq         $at, $zero, L_80231FF0
    if (ctx->r1 == 0) {
        // 0x80231F88: lbu         $t0, 0x43($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X43);
            goto L_80231FF0;
    }
    // 0x80231F88: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x80231F8C: beq         $t0, $zero, L_80231FD0
    if (ctx->r8 == 0) {
        // 0x80231F90: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_80231FD0;
    }
    // 0x80231F90: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80231F94: lhu         $t1, -0x43E4($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X43E4);
    // 0x80231F98: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80231F9C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80231FA0: beq         $t1, $at, L_80231FD0
    if (ctx->r9 == ctx->r1) {
        // 0x80231FA4: lwc1        $f14, 0x34($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80231FD0;
    }
    // 0x80231FA4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80231FA8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80231FAC: lh          $a3, 0x3E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3E);
    // 0x80231FB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80231FB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80231FB8: jal         0x8014ADB4
    // 0x80231FBC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_12;
    // 0x80231FBC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_12:
    // 0x80231FC0: jal         0x8014B36C
    // 0x80231FC4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x8014B36C)(rdram, ctx);
        goto after_13;
    // 0x80231FC4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_13:
    // 0x80231FC8: b           L_80231FF4
    // 0x80231FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80231FF4;
    // 0x80231FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80231FD0:
    // 0x80231FD0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80231FD4: addiu       $t2, $t2, -0x3FC4
    ctx->r10 = ADD32(ctx->r10, -0X3FC4);
    // 0x80231FD8: addu        $v1, $s0, $t2
    ctx->r3 = ADD32(ctx->r16, ctx->r10);
    // 0x80231FDC: lbu         $t3, 0x337($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X337);
    // 0x80231FE0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80231FE4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80231FE8: b           L_80231FF4
    // 0x80231FEC: sb          $t4, 0x337($v1)
    MEM_B(0X337, ctx->r3) = ctx->r12;
        goto L_80231FF4;
    // 0x80231FEC: sb          $t4, 0x337($v1)
    MEM_B(0X337, ctx->r3) = ctx->r12;
L_80231FF0:
    // 0x80231FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80231FF4:
    // 0x80231FF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80231FF8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80231FFC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80232000: jr          $ra
    // 0x80232004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80232004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232008(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232008: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8023200C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80232010: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x80232014: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x80232018: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8023201C: lhu         $v0, 0x36($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X36);
    // 0x80232020: beq         $a0, $v0, L_802320C8
    if (ctx->r4 == ctx->r2) {
        // 0x80232024: nop
    
            goto L_802320C8;
    }
    // 0x80232024: nop

    // 0x80232028: beq         $a1, $v0, L_802320C8
    if (ctx->r5 == ctx->r2) {
        // 0x8023202C: addiu       $a2, $zero, 0xFD
        ctx->r6 = ADD32(0, 0XFD);
            goto L_802320C8;
    }
    // 0x8023202C: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    // 0x80232030: beq         $a2, $v0, L_802320C8
    if (ctx->r6 == ctx->r2) {
        // 0x80232034: addiu       $a3, $zero, 0x146
        ctx->r7 = ADD32(0, 0X146);
            goto L_802320C8;
    }
    // 0x80232034: addiu       $a3, $zero, 0x146
    ctx->r7 = ADD32(0, 0X146);
    // 0x80232038: beq         $a3, $v0, L_802320C8
    if (ctx->r7 == ctx->r2) {
        // 0x8023203C: addiu       $t0, $zero, 0xFB
        ctx->r8 = ADD32(0, 0XFB);
            goto L_802320C8;
    }
    // 0x8023203C: addiu       $t0, $zero, 0xFB
    ctx->r8 = ADD32(0, 0XFB);
    // 0x80232040: beq         $t0, $v0, L_802320C8
    if (ctx->r8 == ctx->r2) {
        // 0x80232044: addiu       $t1, $zero, 0xFC
        ctx->r9 = ADD32(0, 0XFC);
            goto L_802320C8;
    }
    // 0x80232044: addiu       $t1, $zero, 0xFC
    ctx->r9 = ADD32(0, 0XFC);
    // 0x80232048: beq         $t1, $v0, L_802320C8
    if (ctx->r9 == ctx->r2) {
        // 0x8023204C: addiu       $t2, $zero, 0xF5
        ctx->r10 = ADD32(0, 0XF5);
            goto L_802320C8;
    }
    // 0x8023204C: addiu       $t2, $zero, 0xF5
    ctx->r10 = ADD32(0, 0XF5);
    // 0x80232050: beq         $t2, $v0, L_802320C8
    if (ctx->r10 == ctx->r2) {
        // 0x80232054: addiu       $t3, $zero, 0xF6
        ctx->r11 = ADD32(0, 0XF6);
            goto L_802320C8;
    }
    // 0x80232054: addiu       $t3, $zero, 0xF6
    ctx->r11 = ADD32(0, 0XF6);
    // 0x80232058: beq         $t3, $v0, L_802320C8
    if (ctx->r11 == ctx->r2) {
        // 0x8023205C: addiu       $t4, $zero, 0x147
        ctx->r12 = ADD32(0, 0X147);
            goto L_802320C8;
    }
    // 0x8023205C: addiu       $t4, $zero, 0x147
    ctx->r12 = ADD32(0, 0X147);
    // 0x80232060: beq         $t4, $v0, L_802320C8
    if (ctx->r12 == ctx->r2) {
        // 0x80232064: addiu       $t5, $zero, 0x148
        ctx->r13 = ADD32(0, 0X148);
            goto L_802320C8;
    }
    // 0x80232064: addiu       $t5, $zero, 0x148
    ctx->r13 = ADD32(0, 0X148);
    // 0x80232068: beq         $t5, $v0, L_802320C8
    if (ctx->r13 == ctx->r2) {
        // 0x8023206C: nop
    
            goto L_802320C8;
    }
    // 0x8023206C: nop

    // 0x80232070: lw          $t7, 0xEC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XEC);
    // 0x80232074: lhu         $v0, 0x36($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X36);
    // 0x80232078: beq         $a0, $v0, L_802320C8
    if (ctx->r4 == ctx->r2) {
        // 0x8023207C: nop
    
            goto L_802320C8;
    }
    // 0x8023207C: nop

    // 0x80232080: beq         $a1, $v0, L_802320C8
    if (ctx->r5 == ctx->r2) {
        // 0x80232084: nop
    
            goto L_802320C8;
    }
    // 0x80232084: nop

    // 0x80232088: beq         $a2, $v0, L_802320C8
    if (ctx->r6 == ctx->r2) {
        // 0x8023208C: nop
    
            goto L_802320C8;
    }
    // 0x8023208C: nop

    // 0x80232090: beq         $a3, $v0, L_802320C8
    if (ctx->r7 == ctx->r2) {
        // 0x80232094: nop
    
            goto L_802320C8;
    }
    // 0x80232094: nop

    // 0x80232098: beq         $t0, $v0, L_802320C8
    if (ctx->r8 == ctx->r2) {
        // 0x8023209C: nop
    
            goto L_802320C8;
    }
    // 0x8023209C: nop

    // 0x802320A0: beq         $t1, $v0, L_802320C8
    if (ctx->r9 == ctx->r2) {
        // 0x802320A4: nop
    
            goto L_802320C8;
    }
    // 0x802320A4: nop

    // 0x802320A8: beq         $t2, $v0, L_802320C8
    if (ctx->r10 == ctx->r2) {
        // 0x802320AC: nop
    
            goto L_802320C8;
    }
    // 0x802320AC: nop

    // 0x802320B0: beq         $t3, $v0, L_802320C8
    if (ctx->r11 == ctx->r2) {
        // 0x802320B4: nop
    
            goto L_802320C8;
    }
    // 0x802320B4: nop

    // 0x802320B8: beq         $t4, $v0, L_802320C8
    if (ctx->r12 == ctx->r2) {
        // 0x802320BC: nop
    
            goto L_802320C8;
    }
    // 0x802320BC: nop

    // 0x802320C0: bnel        $t5, $v0, L_802320D4
    if (ctx->r13 != ctx->r2) {
        // 0x802320C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_802320D4;
    }
    goto skip_0;
    // 0x802320C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_802320C8:
    // 0x802320C8: jr          $ra
    // 0x802320CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x802320CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802320D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802320D4:
    // 0x802320D4: jr          $ra
    // 0x802320D8: nop

    return;
    // 0x802320D8: nop

;}
RECOMP_FUNC void M10_FUN_802320dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802320DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x802320E0: jr          $ra
    // 0x802320E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802320E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802320e8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802320e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802320E8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x802320EC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x802320F0: addiu       $t6, $v0, 0x7E8
    ctx->r14 = ADD32(ctx->r2, 0X7E8);
    // 0x802320F4: bnel        $a0, $t6, L_80232120
    if (ctx->r4 != ctx->r14) {
        // 0x802320F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80232120;
    }
    goto skip_0;
    // 0x802320F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x802320FC: lw          $t7, 0x448($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X448);
    // 0x80232100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80232104: lbu         $t8, 0x74($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X74);
    // 0x80232108: bnel        $t8, $at, L_80232120
    if (ctx->r24 != ctx->r1) {
        // 0x8023210C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80232120;
    }
    goto skip_1;
    // 0x8023210C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80232110: lw          $t9, 0x334($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X334);
    // 0x80232114: jr          $ra
    // 0x80232118: lbu         $v0, 0x56($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X56);
    return;
    // 0x80232118: lbu         $v0, 0x56($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X56);
    // 0x8023211C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80232120:
    // 0x80232120: jr          $ra
    // 0x80232124: nop

    return;
    // 0x80232124: nop

;}
RECOMP_FUNC void M10_FUN_80232128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232128: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8023212C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80232130: addiu       $t6, $v1, 0x44C
    ctx->r14 = ADD32(ctx->r3, 0X44C);
    // 0x80232134: bne         $a0, $t6, L_80232144
    if (ctx->r4 != ctx->r14) {
        // 0x80232138: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80232144;
    }
    // 0x80232138: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8023213C: b           L_80232148
    // 0x80232140: lw          $v0, 0xEC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XEC);
        goto L_80232148;
    // 0x80232140: lw          $v0, 0xEC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XEC);
L_80232144:
    // 0x80232144: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
L_80232148:
    // 0x80232148: lbu         $t7, 0x2D9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2D9);
    // 0x8023214C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80232150: bnel        $t7, $at, L_802321F4
    if (ctx->r15 != ctx->r1) {
        // 0x80232154: sb          $t8, 0x2DA($a0)
        MEM_B(0X2DA, ctx->r4) = ctx->r24;
            goto L_802321F4;
    }
    goto skip_0;
    // 0x80232154: sb          $t8, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = ctx->r24;
    skip_0:
    // 0x80232158: lhu         $v1, 0x36($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X36);
    // 0x8023215C: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x80232160: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x80232164: addiu       $at, $zero, 0xF6
        ctx->r1 = ADD32(0, 0XF6);
            goto L_802321E8;
    }
    // 0x80232164: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80232168: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x8023216C: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_802321E8;
    }
    // 0x8023216C: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x80232170: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x80232174: addiu       $at, $zero, 0xFB
        ctx->r1 = ADD32(0, 0XFB);
            goto L_802321E8;
    }
    // 0x80232174: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x80232178: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x8023217C: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_802321E8;
    }
    // 0x8023217C: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80232180: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x80232184: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_802321E8;
    }
    // 0x80232184: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80232188: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x8023218C: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_802321E8;
    }
    // 0x8023218C: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x80232190: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x80232194: addiu       $at, $zero, 0x143
        ctx->r1 = ADD32(0, 0X143);
            goto L_802321E8;
    }
    // 0x80232194: addiu       $at, $zero, 0x143
    ctx->r1 = ADD32(0, 0X143);
    // 0x80232198: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x8023219C: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_802321E8;
    }
    // 0x8023219C: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x802321A0: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321A4: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_802321E8;
    }
    // 0x802321A4: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x802321A8: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321AC: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_802321E8;
    }
    // 0x802321AC: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x802321B0: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321B4: addiu       $at, $zero, 0x149
        ctx->r1 = ADD32(0, 0X149);
            goto L_802321E8;
    }
    // 0x802321B4: addiu       $at, $zero, 0x149
    ctx->r1 = ADD32(0, 0X149);
    // 0x802321B8: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321BC: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_802321E8;
    }
    // 0x802321BC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x802321C0: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321C4: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_802321E8;
    }
    // 0x802321C4: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x802321C8: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321CC: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_802321E8;
    }
    // 0x802321CC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x802321D0: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321D4: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_802321E8;
    }
    // 0x802321D4: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    // 0x802321D8: beq         $v1, $at, L_802321E8
    if (ctx->r3 == ctx->r1) {
        // 0x802321DC: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_802321E8;
    }
    // 0x802321DC: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x802321E0: bnel        $v1, $at, L_802321F4
    if (ctx->r3 != ctx->r1) {
        // 0x802321E4: sb          $t8, 0x2DA($a0)
        MEM_B(0X2DA, ctx->r4) = ctx->r24;
            goto L_802321F4;
    }
    goto skip_1;
    // 0x802321E4: sb          $t8, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = ctx->r24;
    skip_1:
L_802321E8:
    // 0x802321E8: jr          $ra
    // 0x802321EC: sb          $zero, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = 0;
    return;
    // 0x802321EC: sb          $zero, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = 0;
    // 0x802321F0: sb          $t8, 0x2DA($a0)
    MEM_B(0X2DA, ctx->r4) = ctx->r24;
L_802321F4:
    // 0x802321F4: jr          $ra
    // 0x802321F8: nop

    return;
    // 0x802321F8: nop

;}
RECOMP_FUNC void M10_FUN_802321fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802321FC: lbu         $v0, 0x2D8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2D8);
    // 0x80232200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80232204: beq         $v0, $at, L_8023221C
    if (ctx->r2 == ctx->r1) {
        // 0x80232208: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8023221C;
    }
    // 0x80232208: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8023220C: bne         $at, $zero, L_80232260
    if (ctx->r1 != 0) {
        // 0x80232210: slti        $at, $v0, 0x9
        ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
            goto L_80232260;
    }
    // 0x80232210: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80232214: beql        $at, $zero, L_80232264
    if (ctx->r1 == 0) {
        // 0x80232218: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80232264;
    }
    goto skip_0;
    // 0x80232218: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_0:
L_8023221C:
    // 0x8023221C: lw          $t6, 0x2D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D4);
    // 0x80232220: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80232224: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x80232228: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8023222C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80232230: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80232234: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80232238: lh          $v0, 0xAA($t9)
    ctx->r2 = MEM_H(ctx->r25, 0XAA);
    // 0x8023223C: bgez        $v0, L_8023224C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80232240: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8023224C;
    }
    // 0x80232240: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80232244: b           L_8023224C
    // 0x80232248: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8023224C;
    // 0x80232248: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8023224C:
    // 0x8023224C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80232250: mflo        $t0
    ctx->r8 = lo;
    // 0x80232254: sb          $t0, 0x374($a0)
    MEM_B(0X374, ctx->r4) = ctx->r8;
    // 0x80232258: jr          $ra
    // 0x8023225C: nop

    return;
    // 0x8023225C: nop

L_80232260:
    // 0x80232260: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_80232264:
    // 0x80232264: bne         $v0, $at, L_80232270
    if (ctx->r2 != ctx->r1) {
        // 0x80232268: nop
    
            goto L_80232270;
    }
    // 0x80232268: nop

    // 0x8023226C: sb          $zero, 0x374($a0)
    MEM_B(0X374, ctx->r4) = 0;
L_80232270:
    // 0x80232270: jr          $ra
    // 0x80232274: nop

    return;
    // 0x80232274: nop

;}
RECOMP_FUNC void M10_FUN_80232278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232278: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8023227C: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x80232280: lhu         $v0, 0x48($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X48);
    // 0x80232284: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80232288: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8023228C: beql        $at, $zero, L_802322A0
    if (ctx->r1 == 0) {
        // 0x80232290: slti        $at, $v0, 0x10
        ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
            goto L_802322A0;
    }
    goto skip_0;
    // 0x80232290: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    skip_0:
    // 0x80232294: jr          $ra
    // 0x80232298: sh          $t6, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r14;
    return;
    // 0x80232298: sh          $t6, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r14;
    // 0x8023229C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
L_802322A0:
    // 0x802322A0: beq         $at, $zero, L_802322B0
    if (ctx->r1 == 0) {
            // 0x802322A4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x802322B0)(rdram, ctx);
    return;
    }
    // 0x802322A4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x802322A8: jr          $ra
    // 0x802322AC: sh          $t7, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r15;
    return;
    // 0x802322AC: sh          $t7, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802322b0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802322b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802322B0: slti        $at, $v0, 0x18
    ctx->r1 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x802322B4: beq         $at, $zero, L_802322C4
    if (ctx->r1 == 0) {
            // 0x802322B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x802322C4)(rdram, ctx);
    return;
    }
    // 0x802322B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x802322BC: jr          $ra
    // 0x802322C0: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
    return;
    // 0x802322C0: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802322c4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802322c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802322C4: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x802322C8: beq         $at, $zero, L_802322DC
    if (ctx->r1 == 0) {
            // 0x802322CC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x802322DC)(rdram, ctx);
    return;
    }
    // 0x802322CC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x802322D0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x802322D4: jr          $ra
    // 0x802322D8: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
    return;
    // 0x802322D8: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802322dc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802322dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802322DC: sh          $t0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r8;
    // 0x802322E0: jr          $ra
    // 0x802322E4: nop

    return;
    // 0x802322E4: nop

;}
RECOMP_FUNC void M10_FUN_802322e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802322E8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x802322EC: addiu       $t3, $t3, -0x4410
    ctx->r11 = ADD32(ctx->r11, -0X4410);
    // 0x802322F0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x802322F4: addiu       $a2, $a2, -0x23C0
    ctx->r6 = ADD32(ctx->r6, -0X23C0);
    // 0x802322F8: lh          $t6, 0x44E($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X44E);
    // 0x802322FC: lbu         $t7, 0x4EE($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4EE);
    // 0x80232300: lbu         $t8, 0x4EF($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X4EF);
    // 0x80232304: lbu         $t9, 0x4F0($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X4F0);
    // 0x80232308: lbu         $t4, 0x4F1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X4F1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023230c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023230c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023230C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80232310: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80232314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80232318: addiu       $a3, $a3, 0x3CE0
    ctx->r7 = ADD32(ctx->r7, 0X3CE0);
    // 0x8023231C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80232320: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80232324: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80232328: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8023232C: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x80232330: sb          $t7, 0x62($a2)
    MEM_B(0X62, ctx->r6) = ctx->r15;
    // 0x80232334: sb          $t8, 0x63($a2)
    MEM_B(0X63, ctx->r6) = ctx->r24;
    // 0x80232338: sb          $t9, 0x64($a2)
    MEM_B(0X64, ctx->r6) = ctx->r25;
    // 0x8023233C: sb          $t4, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r12;
L_80232340:
    // 0x80232340: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80232344: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80232348: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8023234C: slti        $at, $a1, 0x56
    ctx->r1 = SIGNED(ctx->r5) < 0X56 ? 1 : 0;
    // 0x80232350: mflo        $v0
    ctx->r2 = lo;
    // 0x80232354: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x80232358: lbu         $t6, 0x4F4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4F4);
    // 0x8023235C: lh          $t5, 0x4F6($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4F6);
    // 0x80232360: addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // 0x80232364: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80232368: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8023236C: bne         $t1, $t7, L_8023237C
    if (ctx->r9 != ctx->r15) {
        // 0x80232370: sh          $t5, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r13;
            goto L_8023237C;
    }
    // 0x80232370: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x80232374: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80232378: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_8023237C:
    // 0x8023237C: bne         $at, $zero, L_80232340
    if (ctx->r1 != 0) {
        // 0x80232380: nop
    
            goto L_80232340;
    }
    // 0x80232380: nop

    // 0x80232384: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80232388: addiu       $t9, $t9, -0x3D00
    ctx->r25 = ADD32(ctx->r25, -0X3D00);
    // 0x8023238C: lwl         $t5, 0x0($t9)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r25, 0X0);
    // 0x80232390: lwr         $t5, 0x3($t9)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r25, 0X3);
    // 0x80232394: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80232398: addiu       $t8, $t8, -0x236A
    ctx->r24 = ADD32(ctx->r24, -0X236A);
    // 0x8023239C: swl         $t5, 0x0($t8)
    do_swl(rdram, 0X0, ctx->r24, ctx->r13);
    // 0x802323A0: swr         $t5, 0x3($t8)
    do_swr(rdram, 0X3, ctx->r24, ctx->r13);
    // 0x802323A4: lwl         $t4, 0x4($t9)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r25, 0X4);
    // 0x802323A8: lwl         $t5, 0x8($t9)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r25, 0X8);
    // 0x802323AC: lwr         $t4, 0x7($t9)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r25, 0X7);
    // 0x802323B0: lwr         $t5, 0xB($t9)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r25, 0XB);
    // 0x802323B4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x802323B8: swl         $t4, 0x4($t8)
    do_swl(rdram, 0X4, ctx->r24, ctx->r12);
    // 0x802323BC: swl         $t5, 0x8($t8)
    do_swl(rdram, 0X8, ctx->r24, ctx->r13);
    // 0x802323C0: addiu       $t7, $t7, -0x3F42
    ctx->r15 = ADD32(ctx->r15, -0X3F42);
    // 0x802323C4: swr         $t4, 0x7($t8)
    do_swr(rdram, 0X7, ctx->r24, ctx->r12);
    // 0x802323C8: swr         $t5, 0xB($t8)
    do_swr(rdram, 0XB, ctx->r24, ctx->r13);
    // 0x802323CC: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x802323D0: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x802323D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x802323D8: addiu       $t6, $t6, -0x23B0
    ctx->r14 = ADD32(ctx->r14, -0X23B0);
    // 0x802323DC: swl         $t9, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r25);
    // 0x802323E0: swr         $t9, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r25);
    // 0x802323E4: lwl         $t8, 0x4($t7)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r15, 0X4);
    // 0x802323E8: lwl         $t9, 0x8($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X8);
    // 0x802323EC: lwr         $t8, 0x7($t7)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r15, 0X7);
    // 0x802323F0: lwr         $t9, 0xB($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0XB);
    // 0x802323F4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x802323F8: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x802323FC: swl         $t9, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r25);
    // 0x80232400: addiu       $t5, $t5, -0x3F36
    ctx->r13 = ADD32(ctx->r13, -0X3F36);
    // 0x80232404: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x80232408: swr         $t9, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r25);
    // 0x8023240C: lwl         $t7, 0x0($t5)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r13, 0X0);
    // 0x80232410: lwr         $t7, 0x3($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, 0X3);
    // 0x80232414: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80232418: addiu       $t4, $t4, -0x23A4
    ctx->r12 = ADD32(ctx->r12, -0X23A4);
    // 0x8023241C: swl         $t7, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r15);
    // 0x80232420: swr         $t7, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r15);
    // 0x80232424: lwl         $t6, 0x4($t5)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r13, 0X4);
    // 0x80232428: lwl         $t7, 0x8($t5)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r13, 0X8);
    // 0x8023242C: lwr         $t6, 0x7($t5)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r13, 0X7);
    // 0x80232430: lwr         $t7, 0xB($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, 0XB);
    // 0x80232434: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80232438: swl         $t6, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r14);
    // 0x8023243C: swl         $t7, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r15);
    // 0x80232440: addiu       $t9, $t9, -0x3F5A
    ctx->r25 = ADD32(ctx->r25, -0X3F5A);
    // 0x80232444: swr         $t6, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r14);
    // 0x80232448: swr         $t7, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r15);
    // 0x8023244C: lwl         $t5, 0x0($t9)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r25, 0X0);
    // 0x80232450: lwr         $t5, 0x3($t9)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r25, 0X3);
    // 0x80232454: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80232458: addiu       $t8, $t8, -0x2398
    ctx->r24 = ADD32(ctx->r24, -0X2398);
    // 0x8023245C: swl         $t5, 0x0($t8)
    do_swl(rdram, 0X0, ctx->r24, ctx->r13);
    // 0x80232460: swr         $t5, 0x3($t8)
    do_swr(rdram, 0X3, ctx->r24, ctx->r13);
    // 0x80232464: lwl         $t4, 0x4($t9)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r25, 0X4);
    // 0x80232468: lwl         $t5, 0x8($t9)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r25, 0X8);
    // 0x8023246C: lwr         $t4, 0x7($t9)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r25, 0X7);
    // 0x80232470: lwr         $t5, 0xB($t9)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r25, 0XB);
    // 0x80232474: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80232478: swl         $t4, 0x4($t8)
    do_swl(rdram, 0X4, ctx->r24, ctx->r12);
    // 0x8023247C: swl         $t5, 0x8($t8)
    do_swl(rdram, 0X8, ctx->r24, ctx->r13);
    // 0x80232480: addiu       $t7, $t7, -0x3F4E
    ctx->r15 = ADD32(ctx->r15, -0X3F4E);
    // 0x80232484: swr         $t4, 0x7($t8)
    do_swr(rdram, 0X7, ctx->r24, ctx->r12);
    // 0x80232488: swr         $t5, 0xB($t8)
    do_swr(rdram, 0XB, ctx->r24, ctx->r13);
    // 0x8023248C: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x80232490: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x80232494: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80232498: addiu       $t6, $t6, -0x238C
    ctx->r14 = ADD32(ctx->r14, -0X238C);
    // 0x8023249C: swl         $t9, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r25);
    // 0x802324A0: swr         $t9, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r25);
    // 0x802324A4: lwl         $t8, 0x4($t7)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r15, 0X4);
    // 0x802324A8: lwl         $t9, 0x8($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X8);
    // 0x802324AC: lwr         $t8, 0x7($t7)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r15, 0X7);
    // 0x802324B0: lwr         $t9, 0xB($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0XB);
    // 0x802324B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802324B8: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x802324BC: swl         $t9, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r25);
    // 0x802324C0: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x802324C4: swr         $t9, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r25);
    // 0x802324C8: lhu         $t7, 0x66($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X66);
    // 0x802324CC: lbu         $t8, 0x748($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X748);
    // 0x802324D0: lhu         $t4, 0x82($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X82);
    // 0x802324D4: lbu         $t5, 0x749($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X749);
    // 0x802324D8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x802324DC: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x802324E0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x802324E4: sh          $t6, 0x82($a2)
    MEM_H(0X82, ctx->r6) = ctx->r14;
    // 0x802324E8: bne         $v0, $zero, L_802324F8
    if (ctx->r2 != 0) {
        // 0x802324EC: sh          $t9, 0x66($a2)
        MEM_H(0X66, ctx->r6) = ctx->r25;
            goto L_802324F8;
    }
    // 0x802324EC: sh          $t9, 0x66($a2)
    MEM_H(0X66, ctx->r6) = ctx->r25;
    // 0x802324F0: b           L_802325D0
    // 0x802324F4: sb          $zero, 0x86($a2)
    MEM_B(0X86, ctx->r6) = 0;
        goto L_802325D0;
    // 0x802324F4: sb          $zero, 0x86($a2)
    MEM_B(0X86, ctx->r6) = 0;
L_802324F8:
    // 0x802324F8: lhu         $t4, 0x82($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X82);
    // 0x802324FC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80232500: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80232504: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80232508: bgez        $t4, L_8023251C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8023250C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8023251C;
    }
    // 0x8023250C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80232510: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80232514: nop

    // 0x80232518: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8023251C:
    // 0x8023251C: bgez        $v0, L_80232534
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80232520: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80232534;
    }
    // 0x80232520: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80232524: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80232528: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8023252C: nop

    // 0x80232530: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80232534:
    // 0x80232534: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80232538: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8023253C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80232540: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80232544: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80232548: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8023254C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80232550: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80232554: nop

    // 0x80232558: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8023255C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80232560: nop

    // 0x80232564: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80232568: beql        $t6, $zero, L_802325B8
    if (ctx->r14 == 0) {
        // 0x8023256C: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_802325B8;
    }
    goto skip_0;
    // 0x8023256C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80232570: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80232574: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80232578: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8023257C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80232580: nop

    // 0x80232584: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80232588: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8023258C: nop

    // 0x80232590: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80232594: bne         $t6, $zero, L_802325AC
    if (ctx->r14 != 0) {
        // 0x80232598: nop
    
            goto L_802325AC;
    }
    // 0x80232598: nop

    // 0x8023259C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x802325A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802325A4: b           L_802325C4
    // 0x802325A8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_802325C4;
    // 0x802325A8: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_802325AC:
    // 0x802325AC: b           L_802325C4
    // 0x802325B0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_802325C4;
    // 0x802325B0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x802325B4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_802325B8:
    // 0x802325B8: nop

    // 0x802325BC: bltz        $t6, L_802325AC
    if (SIGNED(ctx->r14) < 0) {
        // 0x802325C0: nop
    
            goto L_802325AC;
    }
    // 0x802325C0: nop

L_802325C4:
    // 0x802325C4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x802325C8: sb          $t6, 0x86($a2)
    MEM_B(0X86, ctx->r6) = ctx->r14;
    // 0x802325CC: nop

L_802325D0:
    // 0x802325D0: lhu         $t4, 0x74($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X74);
    // 0x802325D4: lbu         $t5, 0xAE4($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XAE4);
    // 0x802325D8: lhu         $t7, 0x84($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X84);
    // 0x802325DC: lbu         $t8, 0xAE5($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0XAE5);
    // 0x802325E0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x802325E4: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x802325E8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x802325EC: sh          $t9, 0x84($a2)
    MEM_H(0X84, ctx->r6) = ctx->r25;
    // 0x802325F0: bne         $v0, $zero, L_80232600
    if (ctx->r2 != 0) {
        // 0x802325F4: sh          $t6, 0x74($a2)
        MEM_H(0X74, ctx->r6) = ctx->r14;
            goto L_80232600;
    }
    // 0x802325F4: sh          $t6, 0x74($a2)
    MEM_H(0X74, ctx->r6) = ctx->r14;
    // 0x802325F8: b           L_802326D8
    // 0x802325FC: sb          $zero, 0x87($a2)
    MEM_B(0X87, ctx->r6) = 0;
        goto L_802326D8;
    // 0x802325FC: sb          $zero, 0x87($a2)
    MEM_B(0X87, ctx->r6) = 0;
L_80232600:
    // 0x80232600: lhu         $t7, 0x84($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X84);
    // 0x80232604: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80232608: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8023260C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80232610: bgez        $t7, L_80232624
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80232614: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80232624;
    }
    // 0x80232614: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80232618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8023261C: nop

    // 0x80232620: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80232624:
    // 0x80232624: bgez        $v0, L_8023263C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80232628: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8023263C;
    }
    // 0x80232628: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8023262C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80232630: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80232634: nop

    // 0x80232638: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8023263C:
    // 0x8023263C: div.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80232640: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80232644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80232648: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8023264C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80232650: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80232654: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80232658: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8023265C: nop

    // 0x80232660: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80232664: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80232668: nop

    // 0x8023266C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80232670: beql        $t9, $zero, L_802326C0
    if (ctx->r25 == 0) {
        // 0x80232674: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_802326C0;
    }
    goto skip_1;
    // 0x80232674: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80232678: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8023267C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80232680: sub.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80232684: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80232688: nop

    // 0x8023268C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80232690: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80232694: nop

    // 0x80232698: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8023269C: bne         $t9, $zero, L_802326B4
    if (ctx->r25 != 0) {
        // 0x802326A0: nop
    
            goto L_802326B4;
    }
    // 0x802326A0: nop

    // 0x802326A4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x802326A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802326AC: b           L_802326CC
    // 0x802326B0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_802326CC;
    // 0x802326B0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_802326B4:
    // 0x802326B4: b           L_802326CC
    // 0x802326B8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_802326CC;
    // 0x802326B8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x802326BC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_802326C0:
    // 0x802326C0: nop

    // 0x802326C4: bltz        $t9, L_802326B4
    if (SIGNED(ctx->r25) < 0) {
        // 0x802326C8: nop
    
            goto L_802326B4;
    }
    // 0x802326C8: nop

L_802326CC:
    // 0x802326CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x802326D0: sb          $t9, 0x87($a2)
    MEM_B(0X87, ctx->r6) = ctx->r25;
    // 0x802326D4: nop

L_802326D8:
    // 0x802326D8: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
    // 0x802326DC: jal         0x80379410
    // 0x802326E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80379410)(rdram, ctx);
        goto after_0;
    // 0x802326E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x802326E4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x802326E8: addiu       $t3, $t3, -0x4410
    ctx->r11 = ADD32(ctx->r11, -0X4410);
    // 0x802326EC: lbu         $v0, 0xB7D($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0XB7D);
    // 0x802326F0: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x802326F4: beq         $v0, $at, L_80232810
    if (ctx->r2 == ctx->r1) {
        // 0x802326F8: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80232810;
    }
    // 0x802326F8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x802326FC: beq         $at, $zero, L_80232720
    if (ctx->r1 == 0) {
        // 0x80232700: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80232720;
    }
    // 0x80232700: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232704: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80232708: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x8023270C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80232710: sllv        $t6, $t5, $v0
    ctx->r14 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x80232714: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80232718: b           L_802327F4
    // 0x8023271C: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
        goto L_802327F4;
    // 0x8023271C: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
L_80232720:
    // 0x80232720: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80232724: beq         $at, $zero, L_8023274C
    if (ctx->r1 == 0) {
        // 0x80232728: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8023274C;
    }
    // 0x80232728: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8023272C: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80232730: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x80232734: addiu       $t9, $v0, 0x18
    ctx->r25 = ADD32(ctx->r2, 0X18);
    // 0x80232738: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8023273C: sllv        $t4, $t5, $t9
    ctx->r12 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x80232740: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x80232744: b           L_802327F4
    // 0x80232748: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
        goto L_802327F4;
    // 0x80232748: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_8023274C:
    // 0x8023274C: slti        $at, $v0, 0x18
    ctx->r1 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x80232750: beq         $at, $zero, L_80232778
    if (ctx->r1 == 0) {
        // 0x80232754: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80232778;
    }
    // 0x80232754: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232758: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x8023275C: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80232760: addiu       $t5, $v0, 0x10
    ctx->r13 = ADD32(ctx->r2, 0X10);
    // 0x80232764: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80232768: sllv        $t8, $t9, $t5
    ctx->r24 = S32(ctx->r25 << (ctx->r13 & 31));
    // 0x8023276C: or          $t4, $t7, $t8
    ctx->r12 = ctx->r15 | ctx->r24;
    // 0x80232770: b           L_802327F4
    // 0x80232774: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
        goto L_802327F4;
    // 0x80232774: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
L_80232778:
    // 0x80232778: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8023277C: beq         $at, $zero, L_802327A4
    if (ctx->r1 == 0) {
        // 0x80232780: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_802327A4;
    }
    // 0x80232780: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232784: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80232788: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x8023278C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80232790: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80232794: sllv        $t7, $t5, $t9
    ctx->r15 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x80232798: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8023279C: b           L_802327F4
    // 0x802327A0: sb          $t8, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r24;
        goto L_802327F4;
    // 0x802327A0: sb          $t8, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r24;
L_802327A4:
    // 0x802327A4: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x802327A8: beq         $at, $zero, L_802327CC
    if (ctx->r1 == 0) {
        // 0x802327AC: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_802327CC;
    }
    // 0x802327AC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x802327B0: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x802327B4: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x802327B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x802327BC: sllv        $t9, $t5, $v0
    ctx->r25 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x802327C0: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x802327C4: b           L_802327F4
    // 0x802327C8: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
        goto L_802327F4;
    // 0x802327C8: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
L_802327CC:
    // 0x802327CC: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x802327D0: beq         $at, $zero, L_802327F4
    if (ctx->r1 == 0) {
        // 0x802327D4: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_802327F4;
    }
    // 0x802327D4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x802327D8: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x802327DC: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x802327E0: addiu       $t8, $v0, 0x18
    ctx->r24 = ADD32(ctx->r2, 0X18);
    // 0x802327E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x802327E8: sllv        $t4, $t5, $t8
    ctx->r12 = S32(ctx->r13 << (ctx->r24 & 31));
    // 0x802327EC: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x802327F0: sb          $t9, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r25;
L_802327F4:
    // 0x802327F4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x802327F8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x802327FC: bne         $v0, $at, L_80232810
    if (ctx->r2 != ctx->r1) {
        // 0x80232800: addiu       $v1, $v1, -0x2284
        ctx->r3 = ADD32(ctx->r3, -0X2284);
            goto L_80232810;
    }
    // 0x80232800: addiu       $v1, $v1, -0x2284
    ctx->r3 = ADD32(ctx->r3, -0X2284);
    // 0x80232804: lbu         $t6, 0x7($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X7);
    // 0x80232808: ori         $t5, $t6, 0x3
    ctx->r13 = ctx->r14 | 0X3;
    // 0x8023280C: sb          $t5, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r13;
L_80232810:
    // 0x80232810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80232814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80232818: jr          $ra
    // 0x8023281C: nop

    return;
    // 0x8023281C: nop

;}
RECOMP_FUNC void M10_FUN_80232820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232820: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232824: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80232828: addiu       $a0, $a0, -0x225C
    ctx->r4 = ADD32(ctx->r4, -0X225C);
    // 0x8023282C: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x80232830: lbu         $t6, 0x88($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X88);
    // 0x80232834: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x80232838: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8023283C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80232840: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80232844: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80232848: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023284C: ldc1        $f8, -0x328($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X328);
    // 0x80232850: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80232854: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80232858: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8023285C: lhu         $t9, 0x49A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X49A);
    // 0x80232860: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80232864: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80232868: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8023286C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80232870: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80232874: bgez        $t9, L_8023288C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80232878: add.d       $f16, $f10, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
            goto L_8023288C;
    }
    // 0x80232878: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x8023287C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80232880: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80232884: nop

    // 0x80232888: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_8023288C:
    // 0x8023288C: mul.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80232890: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80232894: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80232898: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8023289C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x802328A0: nop

    // 0x802328A4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x802328A8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x802328AC: nop

    // 0x802328B0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x802328B4: beql        $t1, $zero, L_80232908
    if (ctx->r9 == 0) {
        // 0x802328B8: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_80232908;
    }
    goto skip_0;
    // 0x802328B8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x802328BC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x802328C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x802328C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x802328C8: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x802328CC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x802328D0: nop

    // 0x802328D4: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x802328D8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x802328DC: nop

    // 0x802328E0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x802328E4: bne         $t1, $zero, L_802328FC
    if (ctx->r9 != 0) {
        // 0x802328E8: nop
    
            goto L_802328FC;
    }
    // 0x802328E8: nop

    // 0x802328EC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x802328F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802328F4: b           L_80232914
    // 0x802328F8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80232914;
    // 0x802328F8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_802328FC:
    // 0x802328FC: b           L_80232914
    // 0x80232900: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80232914;
    // 0x80232900: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80232904: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_80232908:
    // 0x80232908: nop

    // 0x8023290C: bltz        $t1, L_802328FC
    if (SIGNED(ctx->r9) < 0) {
        // 0x80232910: nop
    
            goto L_802328FC;
    }
    // 0x80232910: nop

L_80232914:
    // 0x80232914: lbu         $t2, 0x89($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X89);
    // 0x80232918: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x8023291C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80232920: sh          $t1, 0x49A($v0)
    MEM_H(0X49A, ctx->r2) = ctx->r9;
    // 0x80232924: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80232928: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8023292C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80232930: ldc1        $f16, -0x320($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X320);
    // 0x80232934: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80232938: lhu         $t5, 0x49C($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X49C);
    // 0x8023293C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80232940: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80232944: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80232948: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8023294C: bgez        $t5, L_80232964
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80232950: add.d       $f8, $f4, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f4.d + ctx->f0.d;
            goto L_80232964;
    }
    // 0x80232950: add.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f4.d + ctx->f0.d;
    // 0x80232954: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80232958: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8023295C: nop

    // 0x80232960: add.d       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f18.d + ctx->f6.d;
L_80232964:
    // 0x80232964: mul.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x80232968: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8023296C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80232970: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80232974: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80232978: nop

    // 0x8023297C: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x80232980: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80232984: nop

    // 0x80232988: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8023298C: beql        $t7, $zero, L_802329E0
    if (ctx->r15 == 0) {
        // 0x80232990: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_802329E0;
    }
    goto skip_1;
    // 0x80232990: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80232994: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80232998: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8023299C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x802329A0: sub.d       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f16.d - ctx->f4.d;
    // 0x802329A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x802329A8: nop

    // 0x802329AC: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x802329B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x802329B4: nop

    // 0x802329B8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x802329BC: bne         $t7, $zero, L_802329D4
    if (ctx->r15 != 0) {
        // 0x802329C0: nop
    
            goto L_802329D4;
    }
    // 0x802329C0: nop

    // 0x802329C4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x802329C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802329CC: b           L_802329EC
    // 0x802329D0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_802329EC;
    // 0x802329D0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_802329D4:
    // 0x802329D4: b           L_802329EC
    // 0x802329D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_802329EC;
    // 0x802329D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x802329DC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_802329E0:
    // 0x802329E0: nop

    // 0x802329E4: bltz        $t7, L_802329D4
    if (SIGNED(ctx->r15) < 0) {
        // 0x802329E8: nop
    
            goto L_802329D4;
    }
    // 0x802329E8: nop

L_802329EC:
    // 0x802329EC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x802329F0: jr          $ra
    // 0x802329F4: sh          $t7, 0x49C($v0)
    MEM_H(0X49C, ctx->r2) = ctx->r15;
    return;
    // 0x802329F4: sh          $t7, 0x49C($v0)
    MEM_H(0X49C, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802329f8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802329f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802329F8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802329FC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x80232A00: lbu         $v0, 0x748($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X748);
    // 0x80232A04: lbu         $v1, 0xAE4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XAE4);
    // 0x80232A08: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80232A0C: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80232A10: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80232A14: bne         $at, $zero, L_80232A48
    if (ctx->r1 != 0) {
            // 0x80232A18: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    LOOKUP_FUNC(0x80232A48)(rdram, ctx);
    return;
    }
    // 0x80232A18: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x80232A1C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232A20: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x80232A24: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80232A28: lbu         $t7, -0x2338($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2338);
    // 0x80232A2C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80232A30: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80232A34: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80232A38: beq         $at, $zero, L_80232A78
    if (ctx->r1 == 0) {
        // 0x80232A3C: nop
    
        LOOKUP_FUNC(0x80232A78)(rdram, ctx);
        return;
    }
    // 0x80232A3C: nop

    // 0x80232A40: jr          $ra
    // 0x80232A44: sb          $t9, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r25;
    return;
    // 0x80232A44: sb          $t9, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232a48(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232a48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232A48: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80232A4C: bne         $at, $zero, L_80232A78
    if (ctx->r1 != 0) {
        // 0x80232A50: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80232A78;
    }
    // 0x80232A50: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80232A54: addiu       $v1, $v1, -0x225C
    ctx->r3 = ADD32(ctx->r3, -0X225C);
    // 0x80232A58: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80232A5C: lbu         $t1, -0x2337($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2337);
    // 0x80232A60: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80232A64: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80232A68: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80232A6C: beq         $at, $zero, L_80232A78
    if (ctx->r1 == 0) {
        // 0x80232A70: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80232A78;
    }
    // 0x80232A70: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80232A74: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
L_80232A78:
    // 0x80232A78: jr          $ra
    // 0x80232A7C: nop

    return;
    // 0x80232A7C: nop

;}
RECOMP_FUNC void M10_FUN_80232a80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232A80: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80232A84: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x80232A88: lbu         $v0, 0x1D($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1D);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232a8c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232a8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232A8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80232A90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80232A94: bne         $v0, $zero, L_80232B14
    if (ctx->r2 != 0) {
        // 0x80232A98: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80232B14;
    }
    // 0x80232A98: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80232A9C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80232AA0: lbu         $t6, -0x3CB8($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3CB8);
    // 0x80232AA4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80232AA8: lbu         $t8, -0x3CC8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X3CC8);
    // 0x80232AAC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80232AB0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80232AB4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80232AB8: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x80232ABC: bne         $t8, $zero, L_80232AC8
    if (ctx->r24 != 0) {
        // 0x80232AC0: nop
    
            goto L_80232AC8;
    }
    // 0x80232AC0: nop

    // 0x80232AC4: break       7
    do_break(2149788356);
L_80232AC8:
    // 0x80232AC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80232ACC: bne         $t8, $at, L_80232AE0
    if (ctx->r24 != ctx->r1) {
        // 0x80232AD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80232AE0;
    }
    // 0x80232AD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80232AD4: bne         $t7, $at, L_80232AE0
    if (ctx->r15 != ctx->r1) {
        // 0x80232AD8: nop
    
            goto L_80232AE0;
    }
    // 0x80232AD8: nop

    // 0x80232ADC: break       6
    do_break(2149788380);
L_80232AE0:
    // 0x80232AE0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80232AE4: lhu         $t0, -0x3CB6($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X3CB6);
    // 0x80232AE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80232AEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80232AF0: nop

    // 0x80232AF4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80232AF8: mflo        $t1
    ctx->r9 = lo;
    // 0x80232AFC: subu        $v0, $t9, $t1
    ctx->r2 = SUB32(ctx->r25, ctx->r9);
    // 0x80232B00: addiu       $v0, $v0, 0x46
    ctx->r2 = ADD32(ctx->r2, 0X46);
    // 0x80232B04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232B08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80232B0C: b           L_80232BB0
    // 0x80232B10: sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
        goto L_80232BB0;
    // 0x80232B10: sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
L_80232B14:
    // 0x80232B14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80232B18: bne         $v0, $at, L_80232B64
    if (ctx->r2 != ctx->r1) {
        // 0x80232B1C: lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
            goto L_80232B64;
    }
    // 0x80232B1C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80232B20: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80232B24: lhu         $t7, -0x3CB6($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3CB6);
    // 0x80232B28: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80232B2C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80232B30: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80232B34: lbu         $t4, -0x3CC8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X3CC8);
    // 0x80232B38: lbu         $t2, -0x3CB8($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3CB8);
    // 0x80232B3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80232B40: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80232B44: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80232B48: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x80232B4C: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
    // 0x80232B50: addiu       $v0, $v0, 0x5F
    ctx->r2 = ADD32(ctx->r2, 0X5F);
    // 0x80232B54: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232B58: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80232B5C: b           L_80232BB0
    // 0x80232B60: sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
        goto L_80232BB0;
    // 0x80232B60: sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
L_80232B64:
    // 0x80232B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80232B68: bne         $v0, $at, L_80232BB0
    if (ctx->r2 != ctx->r1) {
        // 0x80232B6C: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_80232BB0;
    }
    // 0x80232B6C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80232B70: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80232B74: lhu         $t3, -0x3CB6($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X3CB6);
    // 0x80232B78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80232B7C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80232B80: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80232B84: lbu         $t1, -0x3CC8($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X3CC8);
    // 0x80232B88: lbu         $t0, -0x3CB8($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X3CB8);
    // 0x80232B8C: mflo        $t5
    ctx->r13 = lo;
    // 0x80232B90: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80232B94: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80232B98: subu        $t4, $t9, $t2
    ctx->r12 = SUB32(ctx->r25, ctx->r10);
    // 0x80232B9C: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x80232BA0: addiu       $v0, $v0, 0x5F
    ctx->r2 = ADD32(ctx->r2, 0X5F);
    // 0x80232BA4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232BA8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80232BAC: sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
L_80232BB0:
    // 0x80232BB0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80232BB4: lh          $v0, 0x2($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2);
    // 0x80232BB8: addiu       $a0, $a0, -0x3FC4
    ctx->r4 = ADD32(ctx->r4, -0X3FC4);
L_80232BBC:
    // 0x80232BBC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80232BC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80232BC4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80232BC8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80232BCC: mflo        $t7
    ctx->r15 = lo;
    // 0x80232BD0: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80232BD4: lbu         $t8, 0xAC($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XAC);
    // 0x80232BD8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80232BDC: bnel        $at, $zero, L_80232BF4
    if (ctx->r1 != 0) {
        // 0x80232BE0: slti        $at, $v1, 0x22
        ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
            goto L_80232BF4;
    }
    goto skip_0;
    // 0x80232BE0: slti        $at, $v1, 0x22
    ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
    skip_0:
    // 0x80232BE4: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80232BE8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232BEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80232BF0: slti        $at, $v1, 0x22
    ctx->r1 = SIGNED(ctx->r3) < 0X22 ? 1 : 0;
L_80232BF4:
    // 0x80232BF4: bne         $at, $zero, L_80232BBC
    if (ctx->r1 != 0) {
        // 0x80232BF8: nop
    
            goto L_80232BBC;
    }
    // 0x80232BF8: nop

    // 0x80232BFC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80232C00: lbu         $v1, -0x3CEC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X3CEC);
    // 0x80232C04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80232C08: addiu       $t9, $t9, -0x23C0
    ctx->r25 = ADD32(ctx->r25, -0X23C0);
    // 0x80232C0C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80232C10: bne         $at, $zero, L_80232C30
    if (ctx->r1 != 0) {
        // 0x80232C14: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80232C30;
    }
    // 0x80232C14: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80232C18: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x80232C1C: beql        $at, $zero, L_80232C34
    if (ctx->r1 == 0) {
        // 0x80232C20: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80232C34;
    }
    goto skip_1;
    // 0x80232C20: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_1:
    // 0x80232C24: addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // 0x80232C28: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232C2C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80232C30:
    // 0x80232C30: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_80232C34:
    // 0x80232C34: beql        $a0, $at, L_80232C50
    if (ctx->r4 == ctx->r1) {
        // 0x80232C38: addiu       $v0, $v0, -0x1E
        ctx->r2 = ADD32(ctx->r2, -0X1E);
            goto L_80232C50;
    }
    goto skip_2;
    // 0x80232C38: addiu       $v0, $v0, -0x1E
    ctx->r2 = ADD32(ctx->r2, -0X1E);
    skip_2:
    // 0x80232C3C: lhu         $t0, 0x886($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X886);
    // 0x80232C40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80232C44: bne         $t0, $at, L_80232C58
    if (ctx->r8 != ctx->r1) {
        // 0x80232C48: nop
    
            goto L_80232C58;
    }
    // 0x80232C48: nop

    // 0x80232C4C: addiu       $v0, $v0, -0x1E
    ctx->r2 = ADD32(ctx->r2, -0X1E);
L_80232C50:
    // 0x80232C50: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80232C54: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80232C58:
    // 0x80232C58: bgezl       $v0, L_80232C68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80232C5C: slti        $at, $v0, 0x5F
        ctx->r1 = SIGNED(ctx->r2) < 0X5F ? 1 : 0;
            goto L_80232C68;
    }
    goto skip_3;
    // 0x80232C5C: slti        $at, $v0, 0x5F
    ctx->r1 = SIGNED(ctx->r2) < 0X5F ? 1 : 0;
    skip_3:
    // 0x80232C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80232C64: slti        $at, $v0, 0x5F
    ctx->r1 = SIGNED(ctx->r2) < 0X5F ? 1 : 0;
L_80232C68:
    // 0x80232C68: bnel        $at, $zero, L_80232C7C
    if (ctx->r1 != 0) {
        // 0x80232C6C: slti        $at, $v0, 0x55
        ctx->r1 = SIGNED(ctx->r2) < 0X55 ? 1 : 0;
            goto L_80232C7C;
    }
    goto skip_4;
    // 0x80232C6C: slti        $at, $v0, 0x55
    ctx->r1 = SIGNED(ctx->r2) < 0X55 ? 1 : 0;
    skip_4:
    // 0x80232C70: b           L_80232CDC
    // 0x80232C74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80232CDC;
    // 0x80232C74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80232C78: slti        $at, $v0, 0x55
    ctx->r1 = SIGNED(ctx->r2) < 0X55 ? 1 : 0;
L_80232C7C:
    // 0x80232C7C: bnel        $at, $zero, L_80232C90
    if (ctx->r1 != 0) {
        // 0x80232C80: slti        $at, $v0, 0x46
        ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
            goto L_80232C90;
    }
    goto skip_5;
    // 0x80232C80: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    skip_5:
    // 0x80232C84: b           L_80232CDC
    // 0x80232C88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80232CDC;
    // 0x80232C88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80232C8C: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
L_80232C90:
    // 0x80232C90: bnel        $at, $zero, L_80232CA4
    if (ctx->r1 != 0) {
        // 0x80232C94: slti        $at, $v0, 0x32
        ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
            goto L_80232CA4;
    }
    goto skip_6;
    // 0x80232C94: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    skip_6:
    // 0x80232C98: b           L_80232CDC
    // 0x80232C9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80232CDC;
    // 0x80232C9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80232CA0: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
L_80232CA4:
    // 0x80232CA4: bnel        $at, $zero, L_80232CB8
    if (ctx->r1 != 0) {
        // 0x80232CA8: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_80232CB8;
    }
    goto skip_7;
    // 0x80232CA8: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    skip_7:
    // 0x80232CAC: b           L_80232CDC
    // 0x80232CB0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80232CDC;
    // 0x80232CB0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80232CB4: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
L_80232CB8:
    // 0x80232CB8: bnel        $at, $zero, L_80232CCC
    if (ctx->r1 != 0) {
        // 0x80232CBC: slti        $at, $v0, 0xF
        ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
            goto L_80232CCC;
    }
    goto skip_8;
    // 0x80232CBC: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    skip_8:
    // 0x80232CC0: b           L_80232CDC
    // 0x80232CC4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80232CDC;
    // 0x80232CC4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80232CC8: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
L_80232CCC:
    // 0x80232CCC: bne         $at, $zero, L_80232CDC
    if (ctx->r1 != 0) {
        // 0x80232CD0: addiu       $v1, $zero, 0x6
        ctx->r3 = ADD32(0, 0X6);
            goto L_80232CDC;
    }
    // 0x80232CD0: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80232CD4: b           L_80232CDC
    // 0x80232CD8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80232CDC;
    // 0x80232CD8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80232CDC:
    // 0x80232CDC: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x80232CE0: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x80232CE4: lhu         $a0, 0x8E($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8E);
    // 0x80232CE8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80232CEC: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80232CF0: beq         $at, $zero, L_80232CFC
    if (ctx->r1 == 0) {
        // 0x80232CF4: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_80232CFC;
    }
    // 0x80232CF4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x80232CF8: sh          $t2, 0x8E($v0)
    MEM_H(0X8E, ctx->r2) = ctx->r10;
L_80232CFC:
    // 0x80232CFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80232D00: jr          $ra
    // 0x80232D04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80232D04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232d08(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232D08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80232D0C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80232D10: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80232D14: lhu         $t7, 0x86($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X86);
    // 0x80232D18: lhu         $t6, 0x84($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X84);
    // 0x80232D1C: lhu         $t9, 0x88($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X88);
    // 0x80232D20: lhu         $t2, 0x8A($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8A);
    // 0x80232D24: lhu         $t4, 0x8C($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X8C);
    // 0x80232D28: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80232D2C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80232D30: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80232D34: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80232D38: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80232D3C: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x80232D40: mflo        $a2
    ctx->r6 = lo;
    // 0x80232D44: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80232D48: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x80232D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80232D50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80232D54: addiu       $t0, $a2, 0x5
    ctx->r8 = ADD32(ctx->r6, 0X5);
    // 0x80232D58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80232D5C: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
L_80232D60:
    // 0x80232D60: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80232D64: lhu         $t7, 0x84($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X84);
    // 0x80232D68: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x80232D6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80232D70: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80232D74: beq         $at, $zero, L_80232D8C
    if (ctx->r1 == 0) {
        // 0x80232D78: sllv        $t1, $t9, $t8
        ctx->r9 = S32(ctx->r25 << (ctx->r24 & 31));
            goto L_80232D8C;
    }
    // 0x80232D78: sllv        $t1, $t9, $t8
    ctx->r9 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80232D7C: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x80232D80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80232D84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80232D88: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80232D8C:
    // 0x80232D8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80232D90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80232D94: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80232D98: bnel        $at, $zero, L_80232D60
    if (ctx->r1 != 0) {
        // 0x80232D9C: sll         $t5, $a3, 1
        ctx->r13 = S32(ctx->r7 << 1);
            goto L_80232D60;
    }
    goto skip_0;
    // 0x80232D9C: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    skip_0:
    // 0x80232DA0: beql        $v0, $zero, L_80232E88
    if (ctx->r2 == 0) {
        // 0x80232DA4: sb          $v0, 0x397($a0)
        MEM_B(0X397, ctx->r4) = ctx->r2;
            goto L_80232E88;
    }
    goto skip_1;
    // 0x80232DA4: sb          $v0, 0x397($a0)
    MEM_B(0X397, ctx->r4) = ctx->r2;
    skip_1:
    // 0x80232DA8: lbu         $t2, 0x2D9($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2D9);
    // 0x80232DAC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80232DB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80232DB4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80232DB8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80232DBC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80232DC0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80232DC4: lbu         $t4, 0x42AB($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X42AB);
    // 0x80232DC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80232DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80232DD0: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x80232DD4: beq         $t5, $zero, L_80232E84
    if (ctx->r13 == 0) {
        // 0x80232DD8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80232E84;
    }
L_80232DD8:
    // 0x80232DD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80232DDC: sllv        $t7, $t6, $a1
    ctx->r15 = S32(ctx->r14 << (ctx->r5 & 31));
    // 0x80232DE0: and         $t9, $a2, $t7
    ctx->r25 = ctx->r6 & ctx->r15;
    // 0x80232DE4: beq         $t9, $zero, L_80232E70
    if (ctx->r25 == 0) {
        // 0x80232DE8: sll         $t8, $a3, 1
        ctx->r24 = S32(ctx->r7 << 1);
            goto L_80232E70;
    }
    // 0x80232DE8: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x80232DEC: lhu         $t1, 0x84($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X84);
    // 0x80232DF0: lhu         $t2, 0x86($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X86);
    // 0x80232DF4: lhu         $t4, 0x88($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X88);
    // 0x80232DF8: lhu         $t6, 0x8A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8A);
    // 0x80232DFC: lhu         $t9, 0x8C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X8C);
    // 0x80232E00: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80232E04: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80232E08: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x80232E0C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80232E10: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80232E14: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80232E18: lhu         $t2, 0x82($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X82);
    // 0x80232E1C: lh          $t5, 0x2B8($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2B8);
    // 0x80232E20: mflo        $t1
    ctx->r9 = lo;
    // 0x80232E24: nop

    // 0x80232E28: nop

    // 0x80232E2C: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80232E30: mflo        $t3
    ctx->r11 = lo;
    // 0x80232E34: nop

    // 0x80232E38: nop

    // 0x80232E3C: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x80232E40: mflo        $t4
    ctx->r12 = lo;
    // 0x80232E44: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x80232E48: sh          $t6, 0x2B8($a1)
    MEM_H(0X2B8, ctx->r5) = ctx->r14;
    // 0x80232E4C: bne         $t1, $zero, L_80232E58
    if (ctx->r9 != 0) {
        // 0x80232E50: nop
    
            goto L_80232E58;
    }
    // 0x80232E50: nop

    // 0x80232E54: break       7
    do_break(2149789268);
L_80232E58:
    // 0x80232E58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80232E5C: bne         $t1, $at, L_80232E70
    if (ctx->r9 != ctx->r1) {
        // 0x80232E60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80232E70;
    }
    // 0x80232E60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80232E64: bne         $t3, $at, L_80232E70
    if (ctx->r11 != ctx->r1) {
        // 0x80232E68: nop
    
            goto L_80232E70;
    }
    // 0x80232E68: nop

    // 0x80232E6C: break       6
    do_break(2149789292);
L_80232E70:
    // 0x80232E70: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80232E74: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80232E78: slti        $at, $a3, 0x6
    ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x80232E7C: bne         $at, $zero, L_80232DD8
    if (ctx->r1 != 0) {
        // 0x80232E80: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80232DD8;
    }
    // 0x80232E80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80232E84:
    // 0x80232E84: sb          $v0, 0x397($a0)
    MEM_B(0X397, ctx->r4) = ctx->r2;
L_80232E88:
    // 0x80232E88: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80232E8C: jr          $ra
    // 0x80232E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80232E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232e94(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232e94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232E94: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80232E98: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80232E9C: lbu         $t6, 0x1030($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1030);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80232ea0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80232ea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232EA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80232EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80232EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80232EAC: bne         $t6, $zero, L_80232EC0
    if (ctx->r14 != 0) {
        // 0x80232EB0: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80232EC0;
    }
    // 0x80232EB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80232EB4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80232EB8: b           L_80232EC8
    // 0x80232EBC: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
        goto L_80232EC8;
    // 0x80232EBC: addiu       $s0, $s0, -0x3FC4
    ctx->r16 = ADD32(ctx->r16, -0X3FC4);
L_80232EC0:
    // 0x80232EC0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80232EC4: addiu       $s0, $s0, -0x3C28
    ctx->r16 = ADD32(ctx->r16, -0X3C28);
L_80232EC8:
    // 0x80232EC8: addiu       $t7, $v1, 0x44C
    ctx->r15 = ADD32(ctx->r3, 0X44C);
    // 0x80232ECC: bne         $s0, $t7, L_80232EE0
    if (ctx->r16 != ctx->r15) {
        // 0x80232ED0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80232EE0;
    }
    // 0x80232ED0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80232ED4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80232ED8: b           L_80232EE8
    // 0x80232EDC: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
        goto L_80232EE8;
    // 0x80232EDC: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_80232EE0:
    // 0x80232EE0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80232EE4: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_80232EE8:
    // 0x80232EE8: lw          $v0, 0xDC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XDC);
    // 0x80232EEC: bnel        $t8, $v0, L_80232F04
    if (ctx->r24 != ctx->r2) {
        // 0x80232EF0: lw          $a0, 0x5C($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X5C);
            goto L_80232F04;
    }
    goto skip_0;
    // 0x80232EF0: lw          $a0, 0x5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X5C);
    skip_0:
    // 0x80232EF4: lw          $t9, 0xEC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEC);
    // 0x80232EF8: b           L_80232F04
    // 0x80232EFC: lw          $a0, 0x5C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X5C);
        goto L_80232F04;
    // 0x80232EFC: lw          $a0, 0x5C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X5C);
    // 0x80232F00: lw          $a0, 0x5C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X5C);
L_80232F04:
    // 0x80232F04: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    // 0x80232F08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80232F0C: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x80232F10: bne         $at, $zero, L_80232F20
    if (ctx->r1 != 0) {
        // 0x80232F14: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80232F20;
    }
    // 0x80232F14: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80232F18: bnel        $v1, $at, L_80232F88
    if (ctx->r3 != ctx->r1) {
        // 0x80232F1C: lbu         $t3, 0x2DA($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X2DA);
            goto L_80232F88;
    }
    goto skip_1;
    // 0x80232F1C: lbu         $t3, 0x2DA($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2DA);
    skip_1:
L_80232F20:
    // 0x80232F20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80232F24: jal         0x8022EE7C
    // 0x80232F28: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8022EE7C)(rdram, ctx);
        goto after_0;
    // 0x80232F28: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80232F2C: jal         0x8022DB40
    // 0x80232F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8022DB40)(rdram, ctx);
        goto after_1;
    // 0x80232F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80232F34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80232F38: jal         0x8022F0E0
    // 0x80232F3C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8022F0E0)(rdram, ctx);
        goto after_2;
    // 0x80232F3C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    after_2:
    // 0x80232F40: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80232F44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80232F48: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x80232F4C: jal         0x80230DD4
    // 0x80232F50: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80230DD4)(rdram, ctx);
        goto after_3;
    // 0x80232F50: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_3:
    // 0x80232F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80232F58: jal         0x80232D08
    // 0x80232F5C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80232D08)(rdram, ctx);
        goto after_4;
    // 0x80232F5C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_4:
    // 0x80232F60: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80232F64: lbu         $t0, 0x396($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X396);
    // 0x80232F68: beql        $t0, $zero, L_80232FDC
    if (ctx->r8 == 0) {
        // 0x80232F6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80232FDC;
    }
    goto skip_2;
    // 0x80232F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80232F70: lbu         $t1, 0x30($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X30);
    // 0x80232F74: sb          $zero, 0x396($a3)
    MEM_B(0X396, ctx->r7) = 0;
    // 0x80232F78: andi        $t2, $t1, 0xFFE1
    ctx->r10 = ctx->r9 & 0XFFE1;
    // 0x80232F7C: b           L_80232FD8
    // 0x80232F80: sb          $t2, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r10;
        goto L_80232FD8;
    // 0x80232F80: sb          $t2, 0x30($a3)
    MEM_B(0X30, ctx->r7) = ctx->r10;
    // 0x80232F84: lbu         $t3, 0x2DA($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2DA);
L_80232F88:
    // 0x80232F88: beql        $t3, $zero, L_80232FDC
    if (ctx->r11 == 0) {
        // 0x80232F8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80232FDC;
    }
    goto skip_3;
    // 0x80232F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80232F90: lbu         $t4, 0x9C($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X9C);
    // 0x80232F94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80232F98: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80232F9C: bne         $t4, $at, L_80232FAC
    if (ctx->r12 != ctx->r1) {
        // 0x80232FA0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80232FAC;
    }
    // 0x80232FA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80232FA4: sb          $t5, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r13;
    // 0x80232FA8: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
L_80232FAC:
    // 0x80232FAC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80232FB0: bnel        $v1, $at, L_80232FC8
    if (ctx->r3 != ctx->r1) {
        // 0x80232FB4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80232FC8;
    }
    goto skip_4;
    // 0x80232FB4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_4:
    // 0x80232FB8: jal         0x80379904
    // 0x80232FBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x80379904)(rdram, ctx);
        goto after_5;
    // 0x80232FBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80232FC0: lbu         $v1, 0x2D8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2D8);
    // 0x80232FC4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_80232FC8:
    // 0x80232FC8: bne         $v1, $at, L_80232FD8
    if (ctx->r3 != ctx->r1) {
        // 0x80232FCC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80232FD8;
    }
    // 0x80232FCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80232FD0: jal         0x8037A884
    // 0x80232FD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037A884)(rdram, ctx);
        goto after_6;
    // 0x80232FD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
L_80232FD8:
    // 0x80232FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80232FDC:
    // 0x80232FDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80232FE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80232FE4: jr          $ra
    // 0x80232FE8: nop

    return;
    // 0x80232FE8: nop

;}
RECOMP_FUNC void M10_FUN_80232fec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80232FEC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80232FF0: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80232FF4: lw          $a3, 0xDC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XDC);
    // 0x80232FF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80232FFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80233000: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80233004: bne         $a0, $a3, L_80233014
    if (ctx->r4 != ctx->r7) {
        // 0x80233008: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80233014;
    }
    // 0x80233008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8023300C: b           L_80233018
    // 0x80233010: lw          $a0, 0x444($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X444);
        goto L_80233018;
    // 0x80233010: lw          $a0, 0x444($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X444);
L_80233014:
    // 0x80233014: lw          $a0, 0x448($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X448);
L_80233018:
    // 0x80233018: bne         $a2, $a3, L_8023302C
    if (ctx->r6 != ctx->r7) {
        // 0x8023301C: addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
            goto L_8023302C;
    }
    // 0x8023301C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80233020: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80233024: b           L_80233034
    // 0x80233028: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
        goto L_80233034;
    // 0x80233028: addiu       $a3, $a3, -0x3FC4
    ctx->r7 = ADD32(ctx->r7, -0X3FC4);
L_8023302C:
    // 0x8023302C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80233030: addiu       $a3, $a3, -0x3C28
    ctx->r7 = ADD32(ctx->r7, -0X3C28);
L_80233034:
    // 0x80233034: lhu         $t0, 0x36($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X36);
    // 0x80233038: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8023303C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80233040: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x80233044: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80233084;
    }
    // 0x80233044: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80233048: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x8023304C: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_80233084;
    }
    // 0x8023304C: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x80233050: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x80233054: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_80233084;
    }
    // 0x80233054: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x80233058: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x8023305C: addiu       $at, $zero, 0x58
        ctx->r1 = ADD32(0, 0X58);
            goto L_80233084;
    }
    // 0x8023305C: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x80233060: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x80233064: addiu       $at, $zero, 0x59
        ctx->r1 = ADD32(0, 0X59);
            goto L_80233084;
    }
    // 0x80233064: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80233068: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x8023306C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80233084;
    }
    // 0x8023306C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80233070: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x80233074: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80233084;
    }
    // 0x80233074: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80233078: beq         $t0, $at, L_80233084
    if (ctx->r8 == ctx->r1) {
        // 0x8023307C: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80233084;
    }
    // 0x8023307C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80233080: bne         $t0, $at, L_80233280
    if (ctx->r8 != ctx->r1) {
        // 0x80233084: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80233280;
    }
L_80233084:
    // 0x80233084: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_80233088:
    // 0x80233088: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023308C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80233090: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80233094: slti        $at, $a2, 0xE
    ctx->r1 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // 0x80233098: mflo        $t6
    ctx->r14 = lo;
    // 0x8023309C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x802330A0: lh          $t8, 0xAA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XAA);
    // 0x802330A4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x802330A8: bne         $at, $zero, L_80233088
    if (ctx->r1 != 0) {
        // 0x802330AC: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_80233088;
    }
    // 0x802330AC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x802330B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802330B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_802330B8:
    // 0x802330B8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802330BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x802330C0: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x802330C4: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x802330C8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x802330CC: mflo        $t9
    ctx->r25 = lo;
    // 0x802330D0: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x802330D4: lh          $t3, 0xFE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XFE);
    // 0x802330D8: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x802330DC: bne         $at, $zero, L_802330B8
    if (ctx->r1 != 0) {
        // 0x802330E0: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_802330B8;
    }
    // 0x802330E0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x802330E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802330E8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_802330EC:
    // 0x802330EC: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802330F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x802330F4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x802330F8: slti        $at, $a2, 0x25
    ctx->r1 = SIGNED(ctx->r6) < 0X25 ? 1 : 0;
    // 0x802330FC: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80233100: mflo        $t4
    ctx->r12 = lo;
    // 0x80233104: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80233108: lh          $t6, 0x188($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X188);
    // 0x8023310C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80233110: bne         $at, $zero, L_802330EC
    if (ctx->r1 != 0) {
        // 0x80233114: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_802330EC;
    }
    // 0x80233114: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80233118: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8023311C: addu        $t1, $t7, $a1
    ctx->r9 = ADD32(ctx->r15, ctx->r5);
    // 0x80233120: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x80233124: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x80233128: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8023312C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80233130: beq         $at, $zero, L_80233140
    if (ctx->r1 == 0) {
        // 0x80233134: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_80233140;
    }
    // 0x80233134: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80233138: jr          $ra
    // 0x8023313C: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
    return;
    // 0x8023313C: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
L_80233140:
    // 0x80233140: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80233144: beq         $at, $zero, L_802331A8
    if (ctx->r1 == 0) {
        // 0x80233148: slt         $at, $t0, $a2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_802331A8;
    }
    // 0x80233148: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8023314C: beq         $at, $zero, L_802331A8
    if (ctx->r1 == 0) {
        // 0x80233150: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_802331A8;
    }
    // 0x80233150: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80233154: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80233158: mflo        $t8
    ctx->r24 = lo;
    // 0x8023315C: nop

    // 0x80233160: nop

    // 0x80233164: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x80233168: bne         $t1, $zero, L_80233174
    if (ctx->r9 != 0) {
        // 0x8023316C: nop
    
            goto L_80233174;
    }
    // 0x8023316C: nop

    // 0x80233170: break       7
    do_break(2149790064);
L_80233174:
    // 0x80233174: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80233178: bne         $t1, $at, L_8023318C
    if (ctx->r9 != ctx->r1) {
        // 0x8023317C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8023318C;
    }
    // 0x8023317C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80233180: bne         $t8, $at, L_8023318C
    if (ctx->r24 != ctx->r1) {
        // 0x80233184: nop
    
            goto L_8023318C;
    }
    // 0x80233184: nop

    // 0x80233188: break       6
    do_break(2149790088);
L_8023318C:
    // 0x8023318C: mflo        $t9
    ctx->r25 = lo;
    // 0x80233190: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x80233194: bnel        $at, $zero, L_802331AC
    if (ctx->r1 != 0) {
        // 0x80233198: slt         $at, $a2, $a3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_802331AC;
    }
    goto skip_0;
    // 0x80233198: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    skip_0:
    // 0x8023319C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x802331A0: jr          $ra
    // 0x802331A4: sb          $t2, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r10;
    return;
    // 0x802331A4: sb          $t2, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r10;
L_802331A8:
    // 0x802331A8: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
L_802331AC:
    // 0x802331AC: beq         $at, $zero, L_80233214
    if (ctx->r1 == 0) {
        // 0x802331B0: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_80233214;
    }
    // 0x802331B0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x802331B4: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x802331B8: beql        $at, $zero, L_80233218
    if (ctx->r1 == 0) {
        // 0x802331BC: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80233218;
    }
    goto skip_1;
    // 0x802331BC: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    skip_1:
    // 0x802331C0: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802331C4: mflo        $t3
    ctx->r11 = lo;
    // 0x802331C8: nop

    // 0x802331CC: nop

    // 0x802331D0: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x802331D4: bne         $t1, $zero, L_802331E0
    if (ctx->r9 != 0) {
        // 0x802331D8: nop
    
            goto L_802331E0;
    }
    // 0x802331D8: nop

    // 0x802331DC: break       7
    do_break(2149790172);
L_802331E0:
    // 0x802331E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x802331E4: bne         $t1, $at, L_802331F8
    if (ctx->r9 != ctx->r1) {
        // 0x802331E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_802331F8;
    }
    // 0x802331E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802331EC: bne         $t3, $at, L_802331F8
    if (ctx->r11 != ctx->r1) {
        // 0x802331F0: nop
    
            goto L_802331F8;
    }
    // 0x802331F0: nop

    // 0x802331F4: break       6
    do_break(2149790196);
L_802331F8:
    // 0x802331F8: mflo        $t4
    ctx->r12 = lo;
    // 0x802331FC: slti        $at, $t4, 0x29
    ctx->r1 = SIGNED(ctx->r12) < 0X29 ? 1 : 0;
    // 0x80233200: bnel        $at, $zero, L_80233218
    if (ctx->r1 != 0) {
        // 0x80233204: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80233218;
    }
    goto skip_2;
    // 0x80233204: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    skip_2:
    // 0x80233208: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8023320C: jr          $ra
    // 0x80233210: sb          $t5, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r13;
    return;
    // 0x80233210: sb          $t5, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r13;
L_80233214:
    // 0x80233214: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
L_80233218:
    // 0x80233218: beq         $at, $zero, L_8023327C
    if (ctx->r1 == 0) {
        // 0x8023321C: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8023327C;
    }
    // 0x8023321C: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80233220: beql        $at, $zero, L_80233280
    if (ctx->r1 == 0) {
        // 0x80233224: sb          $zero, 0x75($a0)
        MEM_B(0X75, ctx->r4) = 0;
            goto L_80233280;
    }
    goto skip_3;
    // 0x80233224: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
    skip_3:
    // 0x80233228: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023322C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80233230: mflo        $t6
    ctx->r14 = lo;
    // 0x80233234: nop

    // 0x80233238: nop

    // 0x8023323C: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x80233240: bne         $t1, $zero, L_8023324C
    if (ctx->r9 != 0) {
        // 0x80233244: nop
    
            goto L_8023324C;
    }
    // 0x80233244: nop

    // 0x80233248: break       7
    do_break(2149790280);
L_8023324C:
    // 0x8023324C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80233250: bne         $t1, $at, L_80233264
    if (ctx->r9 != ctx->r1) {
        // 0x80233254: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80233264;
    }
    // 0x80233254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80233258: bne         $t6, $at, L_80233264
    if (ctx->r14 != ctx->r1) {
        // 0x8023325C: nop
    
            goto L_80233264;
    }
    // 0x8023325C: nop

    // 0x80233260: break       6
    do_break(2149790304);
L_80233264:
    // 0x80233264: mflo        $t7
    ctx->r15 = lo;
    // 0x80233268: slti        $at, $t7, 0x29
    ctx->r1 = SIGNED(ctx->r15) < 0X29 ? 1 : 0;
    // 0x8023326C: bnel        $at, $zero, L_80233280
    if (ctx->r1 != 0) {
        // 0x80233270: sb          $zero, 0x75($a0)
        MEM_B(0X75, ctx->r4) = 0;
            goto L_80233280;
    }
    goto skip_4;
    // 0x80233270: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
    skip_4:
    // 0x80233274: jr          $ra
    // 0x80233278: sb          $t8, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r24;
    return;
    // 0x80233278: sb          $t8, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r24;
L_8023327C:
    // 0x8023327C: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
L_80233280:
    // 0x80233280: jr          $ra
    // 0x80233284: nop

    return;
    // 0x80233284: nop

;}
RECOMP_FUNC void M10_FUN_80233288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80233288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023328C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80233290: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80233294: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80233298: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8023329C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x802332A0: addiu       $t7, $t7, 0x3CE0
    ctx->r15 = ADD32(ctx->r15, 0X3CE0);
    // 0x802332A4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x802332A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x802332AC: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x802332B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802332B4: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x802332B8: beq         $at, $zero, L_802332C8
    if (ctx->r1 == 0) {
        // 0x802332BC: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_802332C8;
    }
    // 0x802332BC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x802332C0: jal         0x80378CF0
    // 0x802332C4: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
    LOOKUP_FUNC(0x80378CF0)(rdram, ctx);
        goto after_0;
    // 0x802332C4: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
    after_0:
L_802332C8:
    // 0x802332C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802332CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802332D0: jr          $ra
    // 0x802332D4: nop

    return;
    // 0x802332D4: nop

;}
RECOMP_FUNC void M10_FUN_802332d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802332D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x802332DC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x802332E0: lhu         $v0, 0x2C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802332e4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802332e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802332E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802332E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x802332EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x802332F0: beq         $v0, $at, L_80233304
    if (ctx->r2 == ctx->r1) {
        // 0x802332F4: lw          $v1, 0xEC($a0)
        ctx->r3 = MEM_W(ctx->r4, 0XEC);
            goto L_80233304;
    }
    // 0x802332F4: lw          $v1, 0xEC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XEC);
    // 0x802332F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x802332FC: bnel        $v0, $at, L_80233318
    if (ctx->r2 != ctx->r1) {
        // 0x80233300: lhu         $v0, 0x36($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X36);
            goto L_80233318;
    }
    goto skip_0;
    // 0x80233300: lhu         $v0, 0x36($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X36);
    skip_0:
L_80233304:
    // 0x80233304: jal         0x80020718
    // 0x80233308: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x80233308: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_0:
    // 0x8023330C: b           L_802333F0
    // 0x80233310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x80233310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80233314: lhu         $v0, 0x36($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X36);
L_80233318:
    // 0x80233318: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x8023331C: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233320: addiu       $at, $zero, 0x149
        ctx->r1 = ADD32(0, 0X149);
            goto L_80233364;
    }
    // 0x80233320: addiu       $at, $zero, 0x149
    ctx->r1 = ADD32(0, 0X149);
    // 0x80233324: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233328: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80233364;
    }
    // 0x80233328: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8023332C: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233330: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80233364;
    }
    // 0x80233330: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x80233334: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233338: addiu       $at, $zero, 0xFB
        ctx->r1 = ADD32(0, 0XFB);
            goto L_80233364;
    }
    // 0x80233338: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x8023333C: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233340: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_80233364;
    }
    // 0x80233340: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80233344: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233348: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_80233364;
    }
    // 0x80233348: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8023334C: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233350: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80233364;
    }
    // 0x80233350: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80233354: beq         $v0, $at, L_80233364
    if (ctx->r2 == ctx->r1) {
        // 0x80233358: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80233364;
    }
    // 0x80233358: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8023335C: bnel        $v0, $at, L_80233378
    if (ctx->r2 != ctx->r1) {
        // 0x80233360: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_80233378;
    }
    goto skip_1;
    // 0x80233360: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    skip_1:
L_80233364:
    // 0x80233364: jal         0x80020718
    // 0x80233368: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x80233368: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_1:
    // 0x8023336C: b           L_802333F0
    // 0x80233370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x80233370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80233374: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
L_80233378:
    // 0x80233378: bnel        $v0, $at, L_80233394
    if (ctx->r2 != ctx->r1) {
        // 0x8023337C: addiu       $at, $zero, 0x11D
        ctx->r1 = ADD32(0, 0X11D);
            goto L_80233394;
    }
    goto skip_2;
    // 0x8023337C: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
    skip_2:
    // 0x80233380: jal         0x80020718
    // 0x80233384: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x80233384: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_2:
    // 0x80233388: b           L_802333F0
    // 0x8023338C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x8023338C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80233390: addiu       $at, $zero, 0x11D
    ctx->r1 = ADD32(0, 0X11D);
L_80233394:
    // 0x80233394: bnel        $v0, $at, L_802333B0
    if (ctx->r2 != ctx->r1) {
        // 0x80233398: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_802333B0;
    }
    goto skip_3;
    // 0x80233398: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    skip_3:
    // 0x8023339C: jal         0x80020718
    // 0x802333A0: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_3;
    // 0x802333A0: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_3:
    // 0x802333A4: b           L_802333F0
    // 0x802333A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x802333A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802333AC: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
L_802333B0:
    // 0x802333B0: bnel        $v0, $at, L_802333CC
    if (ctx->r2 != ctx->r1) {
        // 0x802333B4: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_802333CC;
    }
    goto skip_4;
    // 0x802333B4: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    skip_4:
    // 0x802333B8: jal         0x80020718
    // 0x802333BC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_4;
    // 0x802333BC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_4:
    // 0x802333C0: b           L_802333F0
    // 0x802333C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x802333C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x802333C8: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
L_802333CC:
    // 0x802333CC: bne         $v0, $at, L_802333E4
    if (ctx->r2 != ctx->r1) {
        // 0x802333D0: nop
    
            goto L_802333E4;
    }
    // 0x802333D0: nop

    // 0x802333D4: jal         0x80020718
    // 0x802333D8: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x802333D8: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_5:
    // 0x802333DC: b           L_802333F0
    // 0x802333E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802333F0;
    // 0x802333E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802333E4:
    // 0x802333E4: jal         0x80020718
    // 0x802333E8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_6;
    // 0x802333E8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_6:
    // 0x802333EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802333F0:
    // 0x802333F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802333F4: jr          $ra
    // 0x802333F8: nop

    return;
    // 0x802333F8: nop

;}
RECOMP_FUNC void M10_FUN_802333fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802333FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80233400: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80233404: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80233408: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8023340C: lh          $t8, 0x2B8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2B8);
    // 0x80233410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80233414: bgez        $t8, L_80233424
    if (SIGNED(ctx->r24) >= 0) {
            // 0x80233418: nop

    LOOKUP_FUNC(0x80233424)(rdram, ctx);
    return;
    }
    // 0x80233418: nop

    // 0x8023341C: jr          $ra
    // 0x80233420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80233420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80233424(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80233424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80233424: jr          $ra
    // 0x80233428: nop

    return;
    // 0x80233428: nop

;}
RECOMP_FUNC void M10_FUN_8023342c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023342C: nop

;}
RECOMP_FUNC void M10_FUN_80233430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80233430: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80233434: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80233438: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x8023343C: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x80233440: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x80233444: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x80233448: jal         0x8001EB64
    // 0x8023344C: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8023344C: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    after_0:
    // 0x80233450: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233454: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80233458: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8023345C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80233460: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x80233464: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80233468: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x8023346C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80233470: jal         0x8001EAD0
    // 0x80233474: swc1        $f10, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80233474: swc1        $f10, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80233478: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8023347C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233480: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x80233484: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80233488: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x8023348C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80233490: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x80233494: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80233498: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8023349C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802334A0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x802334A4: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x802334A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802334AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802334B0: swc1        $f4, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f4.u32l;
    // 0x802334B4: jal         0x8001EB64
    // 0x802334B8: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x802334B8: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    after_2:
    // 0x802334BC: lwc1        $f10, 0x11C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x802334C0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802334C4: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x802334C8: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x802334CC: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x802334D0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x802334D4: lwc1        $f8, 0x3C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x802334D8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x802334DC: jal         0x8001EAD0
    // 0x802334E0: swc1        $f16, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x802334E0: swc1        $f16, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x802334E4: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x802334E8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x802334EC: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x802334F0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x802334F4: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x802334F8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x802334FC: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80233500: lwc1        $f6, 0x44($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80233504: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233508: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8023350C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80233510: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80233514: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233518: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8023351C: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80233520: jal         0x8001EB64
    // 0x80233524: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80233524: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_4:
    // 0x80233528: lwc1        $f16, 0x11C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8023352C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80233530: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x80233534: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80233538: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    // 0x8023353C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80233540: lwc1        $f18, 0x3C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80233544: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80233548: jal         0x8001EAD0
    // 0x8023354C: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x8023354C: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80233550: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233554: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233558: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x8023355C: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80233560: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x80233564: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80233568: addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // 0x8023356C: lwc1        $f10, 0x44($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80233570: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233574: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233578: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8023357C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80233580: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233584: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233588: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
    // 0x8023358C: jal         0x8001EB64
    // 0x80233590: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x80233590: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_6:
    // 0x80233594: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233598: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8023359C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x802335A0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x802335A4: lh          $a0, 0x56($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X56);
    // 0x802335A8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x802335AC: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x802335B0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x802335B4: jal         0x8001EAD0
    // 0x802335B8: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x802335B8: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x802335BC: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x802335C0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x802335C4: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x802335C8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x802335CC: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x802335D0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x802335D4: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x802335D8: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x802335DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802335E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802335E4: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x802335E8: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x802335EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802335F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802335F4: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x802335F8: jal         0x8001EB64
    // 0x802335FC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x802335FC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_8:
    // 0x80233600: lwc1        $f10, 0x11C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233604: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80233608: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8023360C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80233610: lh          $a0, 0x52($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X52);
    // 0x80233614: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80233618: lwc1        $f8, 0x3C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x8023361C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80233620: jal         0x8001EAD0
    // 0x80233624: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x80233624: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80233628: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8023362C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233630: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x80233634: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80233638: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x8023363C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80233640: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80233644: lwc1        $f6, 0x44($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80233648: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8023364C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233650: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80233654: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80233658: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8023365C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233660: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x80233664: jal         0x8001EB64
    // 0x80233668: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x80233668: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    after_10:
    // 0x8023366C: lwc1        $f16, 0x11C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233670: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80233674: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x80233678: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8023367C: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x80233680: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80233684: lwc1        $f18, 0x3C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80233688: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8023368C: jal         0x8001EAD0
    // 0x80233690: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x80233690: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80233694: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233698: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8023369C: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x802336A0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x802336A4: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x802336A8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x802336AC: addiu       $a0, $a0, -0xC00
    ctx->r4 = ADD32(ctx->r4, -0XC00);
    // 0x802336B0: lwc1        $f10, 0x44($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X44);
    // 0x802336B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802336B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802336BC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x802336C0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x802336C4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x802336C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x802336CC: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x802336D0: jal         0x8001EB64
    // 0x802336D4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x802336D4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_12:
    // 0x802336D8: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x802336DC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802336E0: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x802336E4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x802336E8: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    // 0x802336EC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x802336F0: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x802336F4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x802336F8: jal         0x8001EAD0
    // 0x802336FC: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x802336FC: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80233700: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233704: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233708: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x8023370C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80233710: lh          $a0, 0x11A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X11A);
    // 0x80233714: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80233718: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8023371C: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80233720: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233724: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233728: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8023372C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80233730: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80233734: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80233738: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x8023373C: jal         0x8001EB64
    // 0x80233740: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_14;
    // 0x80233740: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_14:
    // 0x80233744: lwc1        $f10, 0x11C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233748: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8023374C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x80233750: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80233754: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    // 0x80233758: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8023375C: lwc1        $f8, 0x3C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80233760: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80233764: jal         0x8001EAD0
    // 0x80233768: swc1        $f16, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x80233768: swc1        $f16, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8023376C: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80233770: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233774: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x80233778: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8023377C: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80233780: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80233784: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80233788: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8023378C: lwc1        $f2, 0x44($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80233790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80233794: sub.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80233798: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8023379C: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x802337A0: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x802337A4: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x802337A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x802337AC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x802337B0: jal         0x801085D4
    // 0x802337B4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_16;
    // 0x802337B4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x802337B8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x802337BC: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x802337C0: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x802337C4: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x802337C8: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x802337CC: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x802337D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802337D4: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x802337D8: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x802337DC: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x802337E0: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x802337E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x802337E8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x802337EC: jal         0x801085D4
    // 0x802337F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_17;
    // 0x802337F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x802337F4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802337F8: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x802337FC: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80233800: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80233804: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x80233808: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8023380C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80233810: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x80233814: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x80233818: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x8023381C: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80233820: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80233824: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80233828: jal         0x801085D4
    // 0x8023382C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_18;
    // 0x8023382C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x80233830: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80233834: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x80233838: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8023383C: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80233840: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80233844: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80233848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8023384C: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x80233850: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x80233854: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x80233858: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8023385C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80233860: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80233864: jal         0x801085D4
    // 0x80233868: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_19;
    // 0x80233868: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x8023386C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80233870: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x80233874: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80233878: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8023387C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80233880: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80233884: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80233888: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x8023388C: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x80233890: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x80233894: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x80233898: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8023389C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x802338A0: jal         0x801085D4
    // 0x802338A4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_20;
    // 0x802338A4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_20:
    // 0x802338A8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x802338AC: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x802338B0: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x802338B4: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x802338B8: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x802338BC: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x802338C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x802338C4: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x802338C8: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x802338CC: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x802338D0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x802338D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x802338D8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x802338DC: jal         0x801085D4
    // 0x802338E0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_21;
    // 0x802338E0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x802338E4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x802338E8: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x802338EC: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x802338F0: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x802338F4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x802338F8: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x802338FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80233900: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x80233904: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x80233908: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x8023390C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80233910: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80233914: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80233918: jal         0x801085D4
    // 0x8023391C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_22;
    // 0x8023391C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_22:
    // 0x80233920: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80233924: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x80233928: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8023392C: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80233930: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80233934: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80233938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8023393C: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x80233940: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x80233944: lw          $a3, 0x44($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X44);
    // 0x80233948: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8023394C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80233950: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80233954: jal         0x801085D4
    // 0x80233958: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801085D4)(rdram, ctx);
        goto after_23;
    // 0x80233958: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x8023395C: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233960: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
    // 0x80233964: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80233968: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x8023396C: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80233970: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80233974: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80233978: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x8023397C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80233980: lw          $ra, 0xA0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA0);
    // 0x80233984: beq         $at, $zero, L_80234210
    if (ctx->r1 == 0) {
        // 0x80233988: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_80234210;
    }
    // 0x80233988: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8023398C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80233990: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80233994: addu        $at, $at, $t8
    gpr jr_addend_8023399C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80233998: lw          $t8, 0x508($at)
    ctx->r24 = ADD32(ctx->r1, 0X508);
    // 0x8023399C: jr          $t8
    // 0x802339A0: nop

    switch (jr_addend_8023399C >> 2) {
        case 0: goto L_80234108; break;
        case 1: goto L_80233C4C; break;
        case 2: goto L_80233B30; break;
        case 3: goto L_80233A60; break;
        case 4: goto L_802339A4; break;
        case 5: goto L_80233DB4; break;
        case 6: goto L_80233E84; break;
        case 7: goto L_80233FA0; break;
        default: switch_error(__func__, 0x8023399C, 0x80240508);
    }
    // 0x802339A0: nop

L_802339A4:
    // 0x802339A4: beql        $t0, $zero, L_80233A4C
    if (ctx->r8 == 0) {
        // 0x802339A8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A4C;
    }
    goto skip_0;
    // 0x802339A8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    skip_0:
    // 0x802339AC: bne         $t1, $zero, L_802339C0
    if (ctx->r9 != 0) {
        // 0x802339B0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_802339C0;
    }
    // 0x802339B0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x802339B4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x802339B8: b           L_80233A54
    // 0x802339BC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233A54;
    // 0x802339BC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_802339C0:
    // 0x802339C0: bne         $t2, $zero, L_802339D4
    if (ctx->r10 != 0) {
        // 0x802339C4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_802339D4;
    }
    // 0x802339C4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x802339C8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x802339CC: b           L_80233A54
    // 0x802339D0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233A54;
    // 0x802339D0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_802339D4:
    // 0x802339D4: bne         $t3, $zero, L_802339E8
    if (ctx->r11 != 0) {
        // 0x802339D8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_802339E8;
    }
    // 0x802339D8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x802339DC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x802339E0: b           L_80233A54
    // 0x802339E4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233A54;
    // 0x802339E4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_802339E8:
    // 0x802339E8: bne         $t4, $zero, L_802339FC
    if (ctx->r12 != 0) {
        // 0x802339EC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_802339FC;
    }
    // 0x802339EC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x802339F0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x802339F4: b           L_80233A54
    // 0x802339F8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233A54;
    // 0x802339F8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_802339FC:
    // 0x802339FC: bne         $v0, $zero, L_80233A10
    if (ctx->r2 != 0) {
        // 0x80233A00: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A10;
    }
    // 0x80233A00: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A04: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80233A08: b           L_80233A54
    // 0x80233A0C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233A54;
    // 0x80233A0C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233A10:
    // 0x80233A10: bne         $t5, $zero, L_80233A24
    if (ctx->r13 != 0) {
        // 0x80233A14: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A24;
    }
    // 0x80233A14: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A18: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80233A1C: b           L_80233A54
    // 0x80233A20: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233A54;
    // 0x80233A20: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233A24:
    // 0x80233A24: bne         $ra, $zero, L_80233A3C
    if (ctx->r31 != 0) {
        // 0x80233A28: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A3C;
    }
    // 0x80233A28: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A2C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A30: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80233A34: b           L_80233A54
    // 0x80233A38: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233A54;
    // 0x80233A38: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233A3C:
    // 0x80233A3C: lh          $t8, 0x11A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X11A);
    // 0x80233A40: b           L_80233A54
    // 0x80233A44: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233A54;
    // 0x80233A44: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80233A48: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_80233A4C:
    // 0x80233A4C: lh          $t9, 0x11A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X11A);
    // 0x80233A50: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233A54:
    // 0x80233A54: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233A58: b           L_80234214
    // 0x80233A5C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233A5C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233A60:
    // 0x80233A60: beq         $t2, $zero, L_80233B04
    if (ctx->r10 == 0) {
        // 0x80233A64: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80233B04;
    }
    // 0x80233A64: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233A68: bne         $t0, $zero, L_80233A7C
    if (ctx->r8 != 0) {
        // 0x80233A6C: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A7C;
    }
    // 0x80233A6C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A70: lh          $t6, 0x11A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X11A);
    // 0x80233A74: b           L_80233B28
    // 0x80233A78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233B28;
    // 0x80233A78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233A7C:
    // 0x80233A7C: bne         $t4, $zero, L_80233A90
    if (ctx->r12 != 0) {
        // 0x80233A80: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233A90;
    }
    // 0x80233A80: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A84: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80233A88: b           L_80233B28
    // 0x80233A8C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233B28;
    // 0x80233A8C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233A90:
    // 0x80233A90: bne         $t1, $zero, L_80233AA4
    if (ctx->r9 != 0) {
        // 0x80233A94: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233AA4;
    }
    // 0x80233A94: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233A98: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80233A9C: b           L_80233B28
    // 0x80233AA0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233B28;
    // 0x80233AA0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233AA4:
    // 0x80233AA4: bne         $t5, $zero, L_80233AB8
    if (ctx->r13 != 0) {
        // 0x80233AA8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233AB8;
    }
    // 0x80233AA8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233AAC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80233AB0: b           L_80233B28
    // 0x80233AB4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233B28;
    // 0x80233AB4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233AB8:
    // 0x80233AB8: bne         $t3, $zero, L_80233ACC
    if (ctx->r11 != 0) {
        // 0x80233ABC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233ACC;
    }
    // 0x80233ABC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233AC0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80233AC4: b           L_80233B28
    // 0x80233AC8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233B28;
    // 0x80233AC8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233ACC:
    // 0x80233ACC: bne         $ra, $zero, L_80233AE0
    if (ctx->r31 != 0) {
        // 0x80233AD0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233AE0;
    }
    // 0x80233AD0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233AD4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80233AD8: b           L_80233B28
    // 0x80233ADC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233B28;
    // 0x80233ADC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233AE0:
    // 0x80233AE0: bne         $v0, $zero, L_80233AF8
    if (ctx->r2 != 0) {
        // 0x80233AE4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233AF8;
    }
    // 0x80233AE4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233AE8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233AEC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80233AF0: b           L_80233B28
    // 0x80233AF4: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233B28;
    // 0x80233AF4: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233AF8:
    // 0x80233AF8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80233AFC: b           L_80233B28
    // 0x80233B00: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233B28;
    // 0x80233B00: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233B04:
    // 0x80233B04: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B08: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80233B0C: bne         $t0, $zero, L_80233B28
    if (ctx->r8 != 0) {
        // 0x80233B10: sh          $t6, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r14;
            goto L_80233B28;
    }
    // 0x80233B10: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80233B14: bne         $t2, $zero, L_80233B28
    if (ctx->r10 != 0) {
        // 0x80233B18: nop
    
            goto L_80233B28;
    }
    // 0x80233B18: nop

    // 0x80233B1C: bne         $t1, $zero, L_80233B28
    if (ctx->r9 != 0) {
        // 0x80233B20: lh          $t7, 0x11A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X11A);
            goto L_80233B28;
    }
    // 0x80233B20: lh          $t7, 0x11A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X11A);
    // 0x80233B24: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233B28:
    // 0x80233B28: b           L_80234214
    // 0x80233B2C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233B2C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233B30:
    // 0x80233B30: beq         $t4, $zero, L_80233BD4
    if (ctx->r12 == 0) {
        // 0x80233B34: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80233BD4;
    }
    // 0x80233B34: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233B38: bne         $t0, $zero, L_80233B4C
    if (ctx->r8 != 0) {
        // 0x80233B3C: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233B4C;
    }
    // 0x80233B3C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B40: lh          $t8, 0x11A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X11A);
    // 0x80233B44: b           L_80233C44
    // 0x80233B48: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233C44;
    // 0x80233B48: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233B4C:
    // 0x80233B4C: bne         $t2, $zero, L_80233B60
    if (ctx->r10 != 0) {
        // 0x80233B50: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233B60;
    }
    // 0x80233B50: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B54: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80233B58: b           L_80233C44
    // 0x80233B5C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233C44;
    // 0x80233B5C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233B60:
    // 0x80233B60: bne         $t5, $zero, L_80233B74
    if (ctx->r13 != 0) {
        // 0x80233B64: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233B74;
    }
    // 0x80233B64: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B68: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80233B6C: b           L_80233C44
    // 0x80233B70: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233C44;
    // 0x80233B70: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233B74:
    // 0x80233B74: bne         $ra, $zero, L_80233B88
    if (ctx->r31 != 0) {
        // 0x80233B78: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233B88;
    }
    // 0x80233B78: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B7C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80233B80: b           L_80233C44
    // 0x80233B84: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233C44;
    // 0x80233B84: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233B88:
    // 0x80233B88: bne         $t1, $zero, L_80233B9C
    if (ctx->r9 != 0) {
        // 0x80233B8C: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233B9C;
    }
    // 0x80233B8C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233B90: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80233B94: b           L_80233C44
    // 0x80233B98: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233C44;
    // 0x80233B98: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233B9C:
    // 0x80233B9C: bne         $v0, $zero, L_80233BB0
    if (ctx->r2 != 0) {
        // 0x80233BA0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233BB0;
    }
    // 0x80233BA0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233BA4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80233BA8: b           L_80233C44
    // 0x80233BAC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233C44;
    // 0x80233BAC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233BB0:
    // 0x80233BB0: bne         $t3, $zero, L_80233BC8
    if (ctx->r11 != 0) {
        // 0x80233BB4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233BC8;
    }
    // 0x80233BB4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233BB8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233BBC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80233BC0: b           L_80233C44
    // 0x80233BC4: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233C44;
    // 0x80233BC4: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233BC8:
    // 0x80233BC8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80233BCC: b           L_80233C44
    // 0x80233BD0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233C44;
    // 0x80233BD0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233BD4:
    // 0x80233BD4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233BD8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80233BDC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80233BE0: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x80233BE4: bne         $t0, $zero, L_80233BF8
    if (ctx->r8 != 0) {
        // 0x80233BE8: sh          $t8, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r24;
            goto L_80233BF8;
    }
    // 0x80233BE8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80233BEC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80233BF0: beq         $t9, $zero, L_80233BF8
    if (ctx->r25 == 0) {
        // 0x80233BF4: nop
    
            goto L_80233BF8;
    }
    // 0x80233BF4: nop

L_80233BF8:
    // 0x80233BF8: bne         $t0, $zero, L_80233C28
    if (ctx->r8 != 0) {
        // 0x80233BFC: nop
    
            goto L_80233C28;
    }
    // 0x80233BFC: nop

    // 0x80233C00: bne         $t2, $zero, L_80233C28
    if (ctx->r10 != 0) {
        // 0x80233C04: nop
    
            goto L_80233C28;
    }
    // 0x80233C04: nop

    // 0x80233C08: bne         $t1, $zero, L_80233C28
    if (ctx->r9 != 0) {
        // 0x80233C0C: lh          $t6, 0x11A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X11A);
            goto L_80233C28;
    }
    // 0x80233C0C: lh          $t6, 0x11A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X11A);
    // 0x80233C10: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80233C14: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80233C18: beq         $t7, $zero, L_80233C44
    if (ctx->r15 == 0) {
        // 0x80233C1C: nop
    
            goto L_80233C44;
    }
    // 0x80233C1C: nop

    // 0x80233C20: b           L_80233C44
    // 0x80233C24: nop

        goto L_80233C44;
    // 0x80233C24: nop

L_80233C28:
    // 0x80233C28: bne         $t2, $zero, L_80233C44
    if (ctx->r10 != 0) {
        // 0x80233C2C: nop
    
            goto L_80233C44;
    }
    // 0x80233C2C: nop

    // 0x80233C30: bne         $t0, $zero, L_80233C44
    if (ctx->r8 != 0) {
        // 0x80233C34: nop
    
            goto L_80233C44;
    }
    // 0x80233C34: nop

    // 0x80233C38: bne         $t4, $zero, L_80233C44
    if (ctx->r12 != 0) {
        // 0x80233C3C: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_80233C44;
    }
    // 0x80233C3C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80233C40: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233C44:
    // 0x80233C44: b           L_80234214
    // 0x80233C48: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233C48: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233C4C:
    // 0x80233C4C: beq         $t5, $zero, L_80233CF0
    if (ctx->r13 == 0) {
        // 0x80233C50: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80233CF0;
    }
    // 0x80233C50: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233C54: bne         $t0, $zero, L_80233C68
    if (ctx->r8 != 0) {
        // 0x80233C58: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233C68;
    }
    // 0x80233C58: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233C5C: lh          $t9, 0x11A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X11A);
    // 0x80233C60: b           L_80233DAC
    // 0x80233C64: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233DAC;
    // 0x80233C64: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233C68:
    // 0x80233C68: bne         $t4, $zero, L_80233C7C
    if (ctx->r12 != 0) {
        // 0x80233C6C: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233C7C;
    }
    // 0x80233C6C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233C70: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80233C74: b           L_80233DAC
    // 0x80233C78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233DAC;
    // 0x80233C78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233C7C:
    // 0x80233C7C: bne         $ra, $zero, L_80233C90
    if (ctx->r31 != 0) {
        // 0x80233C80: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233C90;
    }
    // 0x80233C80: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233C84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80233C88: b           L_80233DAC
    // 0x80233C8C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233DAC;
    // 0x80233C8C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233C90:
    // 0x80233C90: bne         $t2, $zero, L_80233CA4
    if (ctx->r10 != 0) {
        // 0x80233C94: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233CA4;
    }
    // 0x80233C94: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233C98: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80233C9C: b           L_80233DAC
    // 0x80233CA0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233DAC;
    // 0x80233CA0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233CA4:
    // 0x80233CA4: bne         $v0, $zero, L_80233CB8
    if (ctx->r2 != 0) {
        // 0x80233CA8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233CB8;
    }
    // 0x80233CA8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233CAC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80233CB0: b           L_80233DAC
    // 0x80233CB4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233DAC;
    // 0x80233CB4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233CB8:
    // 0x80233CB8: bne         $t3, $zero, L_80233CCC
    if (ctx->r11 != 0) {
        // 0x80233CBC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233CCC;
    }
    // 0x80233CBC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233CC0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80233CC4: b           L_80233DAC
    // 0x80233CC8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233DAC;
    // 0x80233CC8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233CCC:
    // 0x80233CCC: bne         $t1, $zero, L_80233CE4
    if (ctx->r9 != 0) {
        // 0x80233CD0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233CE4;
    }
    // 0x80233CD0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233CD4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233CD8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80233CDC: b           L_80233DAC
    // 0x80233CE0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233DAC;
    // 0x80233CE0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233CE4:
    // 0x80233CE4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80233CE8: b           L_80233DAC
    // 0x80233CEC: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233DAC;
    // 0x80233CEC: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233CF0:
    // 0x80233CF0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233CF4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80233CF8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80233CFC: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x80233D00: bne         $t0, $zero, L_80233D1C
    if (ctx->r8 != 0) {
        // 0x80233D04: sh          $t9, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r25;
            goto L_80233D1C;
    }
    // 0x80233D04: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80233D08: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80233D0C: beq         $t6, $zero, L_80233D30
    if (ctx->r14 == 0) {
        // 0x80233D10: nop
    
            goto L_80233D30;
    }
    // 0x80233D10: nop

    // 0x80233D14: b           L_80233D30
    // 0x80233D18: nop

        goto L_80233D30;
    // 0x80233D18: nop

L_80233D1C:
    // 0x80233D1C: bne         $t2, $zero, L_80233D30
    if (ctx->r10 != 0) {
        // 0x80233D20: nop
    
            goto L_80233D30;
    }
    // 0x80233D20: nop

    // 0x80233D24: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80233D28: beq         $t7, $zero, L_80233D30
    if (ctx->r15 == 0) {
        // 0x80233D2C: nop
    
            goto L_80233D30;
    }
    // 0x80233D2C: nop

L_80233D30:
    // 0x80233D30: bne         $t0, $zero, L_80233D60
    if (ctx->r8 != 0) {
        // 0x80233D34: nop
    
            goto L_80233D60;
    }
    // 0x80233D34: nop

    // 0x80233D38: bne         $t2, $zero, L_80233D60
    if (ctx->r10 != 0) {
        // 0x80233D3C: nop
    
            goto L_80233D60;
    }
    // 0x80233D3C: nop

    // 0x80233D40: bne         $t1, $zero, L_80233D60
    if (ctx->r9 != 0) {
        // 0x80233D44: lh          $t8, 0x11A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X11A);
            goto L_80233D60;
    }
    // 0x80233D44: lh          $t8, 0x11A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X11A);
    // 0x80233D48: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80233D4C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80233D50: beq         $t9, $zero, L_80233DAC
    if (ctx->r25 == 0) {
        // 0x80233D54: nop
    
            goto L_80233DAC;
    }
    // 0x80233D54: nop

    // 0x80233D58: b           L_80233DAC
    // 0x80233D5C: nop

        goto L_80233DAC;
    // 0x80233D5C: nop

L_80233D60:
    // 0x80233D60: bne         $t2, $zero, L_80233D90
    if (ctx->r10 != 0) {
        // 0x80233D64: nop
    
            goto L_80233D90;
    }
    // 0x80233D64: nop

    // 0x80233D68: bne         $t0, $zero, L_80233D90
    if (ctx->r8 != 0) {
        // 0x80233D6C: nop
    
            goto L_80233D90;
    }
    // 0x80233D6C: nop

    // 0x80233D70: bne         $t4, $zero, L_80233D90
    if (ctx->r12 != 0) {
        // 0x80233D74: lw          $t6, 0x5C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X5C);
            goto L_80233D90;
    }
    // 0x80233D74: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80233D78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80233D7C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80233D80: beq         $t7, $zero, L_80233DAC
    if (ctx->r15 == 0) {
        // 0x80233D84: nop
    
            goto L_80233DAC;
    }
    // 0x80233D84: nop

    // 0x80233D88: b           L_80233DAC
    // 0x80233D8C: nop

        goto L_80233DAC;
    // 0x80233D8C: nop

L_80233D90:
    // 0x80233D90: bne         $t4, $zero, L_80233DAC
    if (ctx->r12 != 0) {
        // 0x80233D94: nop
    
            goto L_80233DAC;
    }
    // 0x80233D94: nop

    // 0x80233D98: bne         $t2, $zero, L_80233DAC
    if (ctx->r10 != 0) {
        // 0x80233D9C: nop
    
            goto L_80233DAC;
    }
    // 0x80233D9C: nop

    // 0x80233DA0: bne         $t5, $zero, L_80233DAC
    if (ctx->r13 != 0) {
        // 0x80233DA4: lw          $t8, 0x58($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X58);
            goto L_80233DAC;
    }
    // 0x80233DA4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80233DA8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233DAC:
    // 0x80233DAC: b           L_80234214
    // 0x80233DB0: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233DB0: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233DB4:
    // 0x80233DB4: beq         $t1, $zero, L_80233E58
    if (ctx->r9 == 0) {
        // 0x80233DB8: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80233E58;
    }
    // 0x80233DB8: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233DBC: bne         $t0, $zero, L_80233DD0
    if (ctx->r8 != 0) {
        // 0x80233DC0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233DD0;
    }
    // 0x80233DC0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233DC4: lh          $t9, 0x11A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X11A);
    // 0x80233DC8: b           L_80233E7C
    // 0x80233DCC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233E7C;
    // 0x80233DCC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233DD0:
    // 0x80233DD0: bne         $t3, $zero, L_80233DE4
    if (ctx->r11 != 0) {
        // 0x80233DD4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233DE4;
    }
    // 0x80233DD4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233DD8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80233DDC: b           L_80233E7C
    // 0x80233DE0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233E7C;
    // 0x80233DE0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233DE4:
    // 0x80233DE4: bne         $t2, $zero, L_80233DF8
    if (ctx->r10 != 0) {
        // 0x80233DE8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233DF8;
    }
    // 0x80233DE8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233DEC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80233DF0: b           L_80233E7C
    // 0x80233DF4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233E7C;
    // 0x80233DF4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233DF8:
    // 0x80233DF8: bne         $v0, $zero, L_80233E0C
    if (ctx->r2 != 0) {
        // 0x80233DFC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233E0C;
    }
    // 0x80233DFC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E00: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80233E04: b           L_80233E7C
    // 0x80233E08: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233E7C;
    // 0x80233E08: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233E0C:
    // 0x80233E0C: bne         $t4, $zero, L_80233E20
    if (ctx->r12 != 0) {
        // 0x80233E10: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233E20;
    }
    // 0x80233E10: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E14: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80233E18: b           L_80233E7C
    // 0x80233E1C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233E7C;
    // 0x80233E1C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233E20:
    // 0x80233E20: bne         $ra, $zero, L_80233E34
    if (ctx->r31 != 0) {
        // 0x80233E24: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233E34;
    }
    // 0x80233E24: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E28: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80233E2C: b           L_80233E7C
    // 0x80233E30: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233E7C;
    // 0x80233E30: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233E34:
    // 0x80233E34: bne         $t5, $zero, L_80233E4C
    if (ctx->r13 != 0) {
        // 0x80233E38: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233E4C;
    }
    // 0x80233E38: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E3C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E40: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80233E44: b           L_80233E7C
    // 0x80233E48: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233E7C;
    // 0x80233E48: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233E4C:
    // 0x80233E4C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80233E50: b           L_80233E7C
    // 0x80233E54: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233E7C;
    // 0x80233E54: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233E58:
    // 0x80233E58: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E5C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80233E60: bne         $t0, $zero, L_80233E7C
    if (ctx->r8 != 0) {
        // 0x80233E64: sh          $t9, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r25;
            goto L_80233E7C;
    }
    // 0x80233E64: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80233E68: bne         $t2, $zero, L_80233E7C
    if (ctx->r10 != 0) {
        // 0x80233E6C: nop
    
            goto L_80233E7C;
    }
    // 0x80233E6C: nop

    // 0x80233E70: bne         $t1, $zero, L_80233E7C
    if (ctx->r9 != 0) {
        // 0x80233E74: lh          $t6, 0x11A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X11A);
            goto L_80233E7C;
    }
    // 0x80233E74: lh          $t6, 0x11A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X11A);
    // 0x80233E78: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233E7C:
    // 0x80233E7C: b           L_80234214
    // 0x80233E80: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233E80: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233E84:
    // 0x80233E84: beq         $t3, $zero, L_80233F28
    if (ctx->r11 == 0) {
        // 0x80233E88: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80233F28;
    }
    // 0x80233E88: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233E8C: bne         $t0, $zero, L_80233EA0
    if (ctx->r8 != 0) {
        // 0x80233E90: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233EA0;
    }
    // 0x80233E90: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233E94: lh          $t7, 0x11A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X11A);
    // 0x80233E98: b           L_80233F98
    // 0x80233E9C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233F98;
    // 0x80233E9C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233EA0:
    // 0x80233EA0: bne         $t1, $zero, L_80233EB4
    if (ctx->r9 != 0) {
        // 0x80233EA4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233EB4;
    }
    // 0x80233EA4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233EA8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80233EAC: b           L_80233F98
    // 0x80233EB0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233F98;
    // 0x80233EB0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233EB4:
    // 0x80233EB4: bne         $v0, $zero, L_80233EC8
    if (ctx->r2 != 0) {
        // 0x80233EB8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233EC8;
    }
    // 0x80233EB8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233EBC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80233EC0: b           L_80233F98
    // 0x80233EC4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233F98;
    // 0x80233EC4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233EC8:
    // 0x80233EC8: bne         $ra, $zero, L_80233EDC
    if (ctx->r31 != 0) {
        // 0x80233ECC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233EDC;
    }
    // 0x80233ECC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233ED0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80233ED4: b           L_80233F98
    // 0x80233ED8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233F98;
    // 0x80233ED8: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233EDC:
    // 0x80233EDC: bne         $t2, $zero, L_80233EF0
    if (ctx->r10 != 0) {
        // 0x80233EE0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233EF0;
    }
    // 0x80233EE0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233EE4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80233EE8: b           L_80233F98
    // 0x80233EEC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80233F98;
    // 0x80233EEC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233EF0:
    // 0x80233EF0: bne         $t5, $zero, L_80233F04
    if (ctx->r13 != 0) {
        // 0x80233EF4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233F04;
    }
    // 0x80233EF4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233EF8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80233EFC: b           L_80233F98
    // 0x80233F00: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80233F98;
    // 0x80233F00: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233F04:
    // 0x80233F04: bne         $t4, $zero, L_80233F1C
    if (ctx->r12 != 0) {
        // 0x80233F08: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233F1C;
    }
    // 0x80233F08: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233F0C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233F10: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80233F14: b           L_80233F98
    // 0x80233F18: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80233F98;
    // 0x80233F18: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233F1C:
    // 0x80233F1C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80233F20: b           L_80233F98
    // 0x80233F24: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80233F98;
    // 0x80233F24: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233F28:
    // 0x80233F28: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233F2C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80233F30: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80233F34: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x80233F38: bne         $t0, $zero, L_80233F4C
    if (ctx->r8 != 0) {
        // 0x80233F3C: sh          $t7, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r15;
            goto L_80233F4C;
    }
    // 0x80233F3C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80233F40: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80233F44: beq         $t8, $zero, L_80233F4C
    if (ctx->r24 == 0) {
        // 0x80233F48: nop
    
            goto L_80233F4C;
    }
    // 0x80233F48: nop

L_80233F4C:
    // 0x80233F4C: bne         $t0, $zero, L_80233F7C
    if (ctx->r8 != 0) {
        // 0x80233F50: nop
    
            goto L_80233F7C;
    }
    // 0x80233F50: nop

    // 0x80233F54: bne         $t2, $zero, L_80233F7C
    if (ctx->r10 != 0) {
        // 0x80233F58: nop
    
            goto L_80233F7C;
    }
    // 0x80233F58: nop

    // 0x80233F5C: bne         $t1, $zero, L_80233F7C
    if (ctx->r9 != 0) {
        // 0x80233F60: lh          $t9, 0x11A($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X11A);
            goto L_80233F7C;
    }
    // 0x80233F60: lh          $t9, 0x11A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X11A);
    // 0x80233F64: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80233F68: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80233F6C: beq         $t6, $zero, L_80233F98
    if (ctx->r14 == 0) {
        // 0x80233F70: nop
    
            goto L_80233F98;
    }
    // 0x80233F70: nop

    // 0x80233F74: b           L_80233F98
    // 0x80233F78: nop

        goto L_80233F98;
    // 0x80233F78: nop

L_80233F7C:
    // 0x80233F7C: bne         $t1, $zero, L_80233F98
    if (ctx->r9 != 0) {
        // 0x80233F80: nop
    
            goto L_80233F98;
    }
    // 0x80233F80: nop

    // 0x80233F84: bne         $t0, $zero, L_80233F98
    if (ctx->r8 != 0) {
        // 0x80233F88: nop
    
            goto L_80233F98;
    }
    // 0x80233F88: nop

    // 0x80233F8C: bne         $t3, $zero, L_80233F98
    if (ctx->r11 != 0) {
        // 0x80233F90: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80233F98;
    }
    // 0x80233F90: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80233F94: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233F98:
    // 0x80233F98: b           L_80234214
    // 0x80233F9C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80233F9C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80233FA0:
    // 0x80233FA0: beq         $v0, $zero, L_80234044
    if (ctx->r2 == 0) {
        // 0x80233FA4: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80234044;
    }
    // 0x80233FA4: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80233FA8: bne         $t0, $zero, L_80233FBC
    if (ctx->r8 != 0) {
        // 0x80233FAC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233FBC;
    }
    // 0x80233FAC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233FB0: lh          $t8, 0x11A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X11A);
    // 0x80233FB4: b           L_80234100
    // 0x80233FB8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80234100;
    // 0x80233FB8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80233FBC:
    // 0x80233FBC: bne         $t3, $zero, L_80233FD0
    if (ctx->r11 != 0) {
        // 0x80233FC0: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233FD0;
    }
    // 0x80233FC0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233FC4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80233FC8: b           L_80234100
    // 0x80233FCC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80234100;
    // 0x80233FCC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80233FD0:
    // 0x80233FD0: bne         $ra, $zero, L_80233FE4
    if (ctx->r31 != 0) {
        // 0x80233FD4: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233FE4;
    }
    // 0x80233FD4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233FD8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80233FDC: b           L_80234100
    // 0x80233FE0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80234100;
    // 0x80233FE0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80233FE4:
    // 0x80233FE4: bne         $t1, $zero, L_80233FF8
    if (ctx->r9 != 0) {
        // 0x80233FE8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80233FF8;
    }
    // 0x80233FE8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80233FEC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80233FF0: b           L_80234100
    // 0x80233FF4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80234100;
    // 0x80233FF4: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80233FF8:
    // 0x80233FF8: bne         $t5, $zero, L_8023400C
    if (ctx->r13 != 0) {
        // 0x80233FFC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_8023400C;
    }
    // 0x80233FFC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234000: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80234004: b           L_80234100
    // 0x80234008: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80234100;
    // 0x80234008: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_8023400C:
    // 0x8023400C: bne         $t4, $zero, L_80234020
    if (ctx->r12 != 0) {
        // 0x80234010: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234020;
    }
    // 0x80234010: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234014: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80234018: b           L_80234100
    // 0x8023401C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80234100;
    // 0x8023401C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80234020:
    // 0x80234020: bne         $t2, $zero, L_80234038
    if (ctx->r10 != 0) {
        // 0x80234024: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234038;
    }
    // 0x80234024: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234028: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8023402C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80234030: b           L_80234100
    // 0x80234034: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80234100;
    // 0x80234034: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80234038:
    // 0x80234038: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8023403C: b           L_80234100
    // 0x80234040: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80234100;
    // 0x80234040: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80234044:
    // 0x80234044: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234048: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8023404C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80234050: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x80234054: bne         $t0, $zero, L_80234070
    if (ctx->r8 != 0) {
        // 0x80234058: sh          $t8, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r24;
            goto L_80234070;
    }
    // 0x80234058: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8023405C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80234060: beq         $t9, $zero, L_80234084
    if (ctx->r25 == 0) {
        // 0x80234064: nop
    
            goto L_80234084;
    }
    // 0x80234064: nop

    // 0x80234068: b           L_80234084
    // 0x8023406C: nop

        goto L_80234084;
    // 0x8023406C: nop

L_80234070:
    // 0x80234070: bne         $t1, $zero, L_80234084
    if (ctx->r9 != 0) {
        // 0x80234074: nop
    
            goto L_80234084;
    }
    // 0x80234074: nop

    // 0x80234078: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8023407C: beq         $t6, $zero, L_80234084
    if (ctx->r14 == 0) {
        // 0x80234080: nop
    
            goto L_80234084;
    }
    // 0x80234080: nop

L_80234084:
    // 0x80234084: bne         $t0, $zero, L_802340B4
    if (ctx->r8 != 0) {
        // 0x80234088: nop
    
            goto L_802340B4;
    }
    // 0x80234088: nop

    // 0x8023408C: bne         $t2, $zero, L_802340B4
    if (ctx->r10 != 0) {
        // 0x80234090: nop
    
            goto L_802340B4;
    }
    // 0x80234090: nop

    // 0x80234094: bne         $t1, $zero, L_802340B4
    if (ctx->r9 != 0) {
        // 0x80234098: lh          $t7, 0x11A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X11A);
            goto L_802340B4;
    }
    // 0x80234098: lh          $t7, 0x11A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X11A);
    // 0x8023409C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x802340A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x802340A4: beq         $t8, $zero, L_80234100
    if (ctx->r24 == 0) {
        // 0x802340A8: nop
    
            goto L_80234100;
    }
    // 0x802340A8: nop

    // 0x802340AC: b           L_80234100
    // 0x802340B0: nop

        goto L_80234100;
    // 0x802340B0: nop

L_802340B4:
    // 0x802340B4: bne         $t1, $zero, L_802340E4
    if (ctx->r9 != 0) {
        // 0x802340B8: nop
    
            goto L_802340E4;
    }
    // 0x802340B8: nop

    // 0x802340BC: bne         $t0, $zero, L_802340E4
    if (ctx->r8 != 0) {
        // 0x802340C0: nop
    
            goto L_802340E4;
    }
    // 0x802340C0: nop

    // 0x802340C4: bne         $t3, $zero, L_802340E4
    if (ctx->r11 != 0) {
        // 0x802340C8: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_802340E4;
    }
    // 0x802340C8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x802340CC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x802340D0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x802340D4: beq         $t6, $zero, L_80234100
    if (ctx->r14 == 0) {
        // 0x802340D8: nop
    
            goto L_80234100;
    }
    // 0x802340D8: nop

    // 0x802340DC: b           L_80234100
    // 0x802340E0: nop

        goto L_80234100;
    // 0x802340E0: nop

L_802340E4:
    // 0x802340E4: bne         $t3, $zero, L_80234100
    if (ctx->r11 != 0) {
        // 0x802340E8: nop
    
            goto L_80234100;
    }
    // 0x802340E8: nop

    // 0x802340EC: bne         $t1, $zero, L_80234100
    if (ctx->r9 != 0) {
        // 0x802340F0: nop
    
            goto L_80234100;
    }
    // 0x802340F0: nop

    // 0x802340F4: bne         $v0, $zero, L_80234100
    if (ctx->r2 != 0) {
        // 0x802340F8: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_80234100;
    }
    // 0x802340F8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x802340FC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80234100:
    // 0x80234100: b           L_80234214
    // 0x80234104: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x80234104: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80234108:
    // 0x80234108: beq         $ra, $zero, L_80234198
    if (ctx->r31 == 0) {
        // 0x8023410C: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_80234198;
    }
    // 0x8023410C: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80234110: bne         $v0, $zero, L_80234124
    if (ctx->r2 != 0) {
        // 0x80234114: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234124;
    }
    // 0x80234114: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234118: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8023411C: b           L_80234208
    // 0x80234120: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80234208;
    // 0x80234120: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80234124:
    // 0x80234124: bne         $t5, $zero, L_80234138
    if (ctx->r13 != 0) {
        // 0x80234128: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234138;
    }
    // 0x80234128: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8023412C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80234130: b           L_80234208
    // 0x80234134: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80234208;
    // 0x80234134: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80234138:
    // 0x80234138: bne         $t3, $zero, L_8023414C
    if (ctx->r11 != 0) {
        // 0x8023413C: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_8023414C;
    }
    // 0x8023413C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234140: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80234144: b           L_80234208
    // 0x80234148: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80234208;
    // 0x80234148: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_8023414C:
    // 0x8023414C: bne         $t4, $zero, L_80234160
    if (ctx->r12 != 0) {
        // 0x80234150: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234160;
    }
    // 0x80234150: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234154: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80234158: b           L_80234208
    // 0x8023415C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_80234208;
    // 0x8023415C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80234160:
    // 0x80234160: bne         $t1, $zero, L_80234174
    if (ctx->r9 != 0) {
        // 0x80234164: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80234174;
    }
    // 0x80234164: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234168: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8023416C: b           L_80234208
    // 0x80234170: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80234208;
    // 0x80234170: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80234174:
    // 0x80234174: bne         $t2, $zero, L_8023418C
    if (ctx->r10 != 0) {
        // 0x80234178: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_8023418C;
    }
    // 0x80234178: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8023417C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80234180: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80234184: b           L_80234208
    // 0x80234188: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80234208;
    // 0x80234188: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_8023418C:
    // 0x8023418C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80234190: b           L_80234208
    // 0x80234194: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80234208;
    // 0x80234194: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80234198:
    // 0x80234198: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8023419C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x802341A0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x802341A4: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x802341A8: bne         $t3, $zero, L_802341BC
    if (ctx->r11 != 0) {
        // 0x802341AC: sh          $t7, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r15;
            goto L_802341BC;
    }
    // 0x802341AC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x802341B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x802341B4: beq         $t8, $zero, L_802341BC
    if (ctx->r24 == 0) {
        // 0x802341B8: nop
    
            goto L_802341BC;
    }
    // 0x802341B8: nop

L_802341BC:
    // 0x802341BC: bne         $t3, $zero, L_802341EC
    if (ctx->r11 != 0) {
        // 0x802341C0: nop
    
            goto L_802341EC;
    }
    // 0x802341C0: nop

    // 0x802341C4: bne         $t1, $zero, L_802341EC
    if (ctx->r9 != 0) {
        // 0x802341C8: nop
    
            goto L_802341EC;
    }
    // 0x802341C8: nop

    // 0x802341CC: bne         $v0, $zero, L_802341EC
    if (ctx->r2 != 0) {
        // 0x802341D0: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_802341EC;
    }
    // 0x802341D0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x802341D4: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x802341D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x802341DC: beq         $t6, $zero, L_80234208
    if (ctx->r14 == 0) {
        // 0x802341E0: nop
    
            goto L_80234208;
    }
    // 0x802341E0: nop

    // 0x802341E4: b           L_80234208
    // 0x802341E8: nop

        goto L_80234208;
    // 0x802341E8: nop

L_802341EC:
    // 0x802341EC: bne         $t4, $zero, L_80234208
    if (ctx->r12 != 0) {
        // 0x802341F0: nop
    
            goto L_80234208;
    }
    // 0x802341F0: nop

    // 0x802341F4: bne         $t2, $zero, L_80234208
    if (ctx->r10 != 0) {
        // 0x802341F8: nop
    
            goto L_80234208;
    }
    // 0x802341F8: nop

    // 0x802341FC: bne         $t5, $zero, L_80234208
    if (ctx->r13 != 0) {
        // 0x80234200: lw          $t7, 0x58($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X58);
            goto L_80234208;
    }
    // 0x80234200: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80234204: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80234208:
    // 0x80234208: b           L_80234214
    // 0x8023420C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
        goto L_80234214;
    // 0x8023420C: lbu         $v1, -0x1C70($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1C70);
L_80234210:
    // 0x80234210: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_80234214:
    // 0x80234214: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x80234218: lh          $t8, 0x11A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X11A);
    // 0x8023421C: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80234220: addiu       $a3, $a3, -0x1C70
    ctx->r7 = ADD32(ctx->r7, -0X1C70);
    // 0x80234224: bne         $t8, $v0, L_8023423C
    if (ctx->r24 != ctx->r2) {
        // 0x80234228: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8023423C;
    }
    // 0x80234228: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8023422C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80234230: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80234234: b           L_802342C8
    // 0x80234238: sb          $t9, -0x1C70($at)
    MEM_B(-0X1C70, ctx->r1) = ctx->r25;
        goto L_802342C8;
    // 0x80234238: sb          $t9, -0x1C70($at)
    MEM_B(-0X1C70, ctx->r1) = ctx->r25;
L_8023423C:
    // 0x8023423C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80234240: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80234244: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80234248: bne         $t6, $v0, L_80234258
    if (ctx->r14 != ctx->r2) {
        // 0x8023424C: nop
    
            goto L_80234258;
    }
    // 0x8023424C: nop

    // 0x80234250: b           L_802342C8
    // 0x80234254: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
        goto L_802342C8;
    // 0x80234254: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_80234258:
    // 0x80234258: bne         $t8, $v0, L_8023426C
    if (ctx->r24 != ctx->r2) {
        // 0x8023425C: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_8023426C;
    }
    // 0x8023425C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80234260: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80234264: b           L_802342C8
    // 0x80234268: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
        goto L_802342C8;
    // 0x80234268: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_8023426C:
    // 0x8023426C: bne         $t6, $v0, L_80234280
    if (ctx->r14 != ctx->r2) {
        // 0x80234270: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_80234280;
    }
    // 0x80234270: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80234274: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80234278: b           L_802342C8
    // 0x8023427C: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
        goto L_802342C8;
    // 0x8023427C: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_80234280:
    // 0x80234280: bne         $t8, $v0, L_80234294
    if (ctx->r24 != ctx->r2) {
        // 0x80234284: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_80234294;
    }
    // 0x80234284: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80234288: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8023428C: b           L_802342C8
    // 0x80234290: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
        goto L_802342C8;
    // 0x80234290: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_80234294:
    // 0x80234294: bne         $t6, $v0, L_802342A8
    if (ctx->r14 != ctx->r2) {
        // 0x80234298: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_802342A8;
    }
    // 0x80234298: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8023429C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x802342A0: b           L_802342C8
    // 0x802342A4: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
        goto L_802342C8;
    // 0x802342A4: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_802342A8:
    // 0x802342A8: bne         $t8, $v0, L_802342BC
    if (ctx->r24 != ctx->r2) {
        // 0x802342AC: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_802342BC;
    }
    // 0x802342AC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x802342B0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x802342B4: b           L_802342C8
    // 0x802342B8: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
        goto L_802342C8;
    // 0x802342B8: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_802342BC:
    // 0x802342BC: bnel        $t6, $v0, L_802342CC
    if (ctx->r14 != ctx->r2) {
        // 0x802342C0: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_802342CC;
    }
    goto skip_1;
    // 0x802342C0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    skip_1:
    // 0x802342C4: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_802342C8:
    // 0x802342C8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_802342CC:
    // 0x802342CC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x802342D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x802342D4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x802342D8: addiu       $a3, $a3, 0x468
    ctx->r7 = ADD32(ctx->r7, 0X468);
    // 0x802342DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x802342E0: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x802342E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x802342E8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x802342EC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x802342F0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x802342F4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x802342F8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x802342FC: jal         0x8001DFFC
    // 0x80234300: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_24;
    // 0x80234300: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_24:
    // 0x80234304: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80234308: addiu       $a3, $a3, -0x1C70
    ctx->r7 = ADD32(ctx->r7, -0X1C70);
    // 0x8023430C: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80234310: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80234314: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80234318: bne         $v0, $zero, L_8023432C
    if (ctx->r2 != 0) {
        // 0x8023431C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_8023432C;
    }
    // 0x8023431C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80234320: lui         $ra, 0x8024
    ctx->r31 = S32(0X8024 << 16);
    // 0x80234324: b           L_80234334
    // 0x80234328: addiu       $ra, $ra, 0x4C0
    ctx->r31 = ADD32(ctx->r31, 0X4C0);
        goto L_80234334;
    // 0x80234328: addiu       $ra, $ra, 0x4C0
    ctx->r31 = ADD32(ctx->r31, 0X4C0);
L_8023432C:
    // 0x8023432C: lui         $ra, 0x8024
    ctx->r31 = S32(0X8024 << 16);
    // 0x80234330: addiu       $ra, $ra, 0x4C4
    ctx->r31 = ADD32(ctx->r31, 0X4C4);
L_80234334:
    // 0x80234334: bne         $v0, $at, L_80234348
    if (ctx->r2 != ctx->r1) {
        // 0x80234338: addiu       $a2, $zero, 0x78
        ctx->r6 = ADD32(0, 0X78);
            goto L_80234348;
    }
    // 0x80234338: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8023433C: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80234340: b           L_80234350
    // 0x80234344: addiu       $t5, $t5, 0x4C8
    ctx->r13 = ADD32(ctx->r13, 0X4C8);
        goto L_80234350;
    // 0x80234344: addiu       $t5, $t5, 0x4C8
    ctx->r13 = ADD32(ctx->r13, 0X4C8);
L_80234348:
    // 0x80234348: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x8023434C: addiu       $t5, $t5, 0x4CC
    ctx->r13 = ADD32(ctx->r13, 0X4CC);
L_80234350:
    // 0x80234350: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80234354: bne         $v0, $at, L_80234368
    if (ctx->r2 != ctx->r1) {
        // 0x80234358: lui         $a3, 0x8024
        ctx->r7 = S32(0X8024 << 16);
            goto L_80234368;
    }
    // 0x80234358: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8023435C: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80234360: b           L_80234370
    // 0x80234364: addiu       $t3, $t3, 0x4D0
    ctx->r11 = ADD32(ctx->r11, 0X4D0);
        goto L_80234370;
    // 0x80234364: addiu       $t3, $t3, 0x4D0
    ctx->r11 = ADD32(ctx->r11, 0X4D0);
L_80234368:
    // 0x80234368: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x8023436C: addiu       $t3, $t3, 0x4D4
    ctx->r11 = ADD32(ctx->r11, 0X4D4);
L_80234370:
    // 0x80234370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80234374: bne         $v0, $at, L_80234388
    if (ctx->r2 != ctx->r1) {
        // 0x80234378: addiu       $a3, $a3, 0x494
        ctx->r7 = ADD32(ctx->r7, 0X494);
            goto L_80234388;
    }
    // 0x80234378: addiu       $a3, $a3, 0x494
    ctx->r7 = ADD32(ctx->r7, 0X494);
    // 0x8023437C: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x80234380: b           L_80234390
    // 0x80234384: addiu       $t4, $t4, 0x4D8
    ctx->r12 = ADD32(ctx->r12, 0X4D8);
        goto L_80234390;
    // 0x80234384: addiu       $t4, $t4, 0x4D8
    ctx->r12 = ADD32(ctx->r12, 0X4D8);
L_80234388:
    // 0x80234388: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x8023438C: addiu       $t4, $t4, 0x4DC
    ctx->r12 = ADD32(ctx->r12, 0X4DC);
L_80234390:
    // 0x80234390: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80234394: bne         $v0, $at, L_802343A8
    if (ctx->r2 != ctx->r1) {
        // 0x80234398: lui         $t2, 0x8024
        ctx->r10 = S32(0X8024 << 16);
            goto L_802343A8;
    }
    // 0x80234398: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x8023439C: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x802343A0: b           L_802343AC
    // 0x802343A4: addiu       $t2, $t2, 0x4E0
    ctx->r10 = ADD32(ctx->r10, 0X4E0);
        goto L_802343AC;
    // 0x802343A4: addiu       $t2, $t2, 0x4E0
    ctx->r10 = ADD32(ctx->r10, 0X4E0);
L_802343A8:
    // 0x802343A8: addiu       $t2, $t2, 0x4E4
    ctx->r10 = ADD32(ctx->r10, 0X4E4);
L_802343AC:
    // 0x802343AC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x802343B0: bne         $v0, $at, L_802343C4
    if (ctx->r2 != ctx->r1) {
        // 0x802343B4: lui         $t1, 0x8024
        ctx->r9 = S32(0X8024 << 16);
            goto L_802343C4;
    }
    // 0x802343B4: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x802343B8: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x802343BC: b           L_802343C8
    // 0x802343C0: addiu       $t1, $t1, 0x4E8
    ctx->r9 = ADD32(ctx->r9, 0X4E8);
        goto L_802343C8;
    // 0x802343C0: addiu       $t1, $t1, 0x4E8
    ctx->r9 = ADD32(ctx->r9, 0X4E8);
L_802343C4:
    // 0x802343C4: addiu       $t1, $t1, 0x4EC
    ctx->r9 = ADD32(ctx->r9, 0X4EC);
L_802343C8:
    // 0x802343C8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x802343CC: bne         $v0, $at, L_802343E0
    if (ctx->r2 != ctx->r1) {
        // 0x802343D0: lui         $v1, 0x8024
        ctx->r3 = S32(0X8024 << 16);
            goto L_802343E0;
    }
    // 0x802343D0: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x802343D4: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x802343D8: b           L_802343E4
    // 0x802343DC: addiu       $v1, $v1, 0x4F0
    ctx->r3 = ADD32(ctx->r3, 0X4F0);
        goto L_802343E4;
    // 0x802343DC: addiu       $v1, $v1, 0x4F0
    ctx->r3 = ADD32(ctx->r3, 0X4F0);
L_802343E0:
    // 0x802343E0: addiu       $v1, $v1, 0x4F4
    ctx->r3 = ADD32(ctx->r3, 0X4F4);
L_802343E4:
    // 0x802343E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x802343E8: bne         $v0, $at, L_802343FC
    if (ctx->r2 != ctx->r1) {
        // 0x802343EC: lui         $t0, 0x8024
        ctx->r8 = S32(0X8024 << 16);
            goto L_802343FC;
    }
    // 0x802343EC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x802343F0: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x802343F4: b           L_80234400
    // 0x802343F8: addiu       $t0, $t0, 0x4F8
    ctx->r8 = ADD32(ctx->r8, 0X4F8);
        goto L_80234400;
    // 0x802343F8: addiu       $t0, $t0, 0x4F8
    ctx->r8 = ADD32(ctx->r8, 0X4F8);
L_802343FC:
    // 0x802343FC: addiu       $t0, $t0, 0x4FC
    ctx->r8 = ADD32(ctx->r8, 0X4FC);
L_80234400:
    // 0x80234400: bne         $v0, $zero, L_80234410
    if (ctx->r2 != 0) {
        // 0x80234404: lui         $v0, 0x8024
        ctx->r2 = S32(0X8024 << 16);
            goto L_80234410;
    }
    // 0x80234404: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80234408: b           L_80234418
    // 0x8023440C: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, 0X500);
        goto L_80234418;
    // 0x8023440C: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, 0X500);
L_80234410:
    // 0x80234410: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80234414: addiu       $v0, $v0, 0x504
    ctx->r2 = ADD32(ctx->r2, 0X504);
L_80234418:
    // 0x80234418: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8023441C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80234420: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80234424: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80234428: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8023442C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80234430: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80234434: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80234438: jal         0x8001DFFC
    // 0x8023443C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_25;
    // 0x8023443C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_25:
    // 0x80234440: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80234444: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x80234448: jr          $ra
    // 0x8023444C: nop

    return;
    // 0x8023444C: nop

;}
RECOMP_FUNC void M10_FUN_80234450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234450: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x80234454: addiu       $v1, $v1, 0x7E8
    ctx->r3 = ADD32(ctx->r3, 0X7E8);
    // 0x80234458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023445C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80234460: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80234464:
    // 0x80234464: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80234468: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8023446C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80234470: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80234474: mflo        $t6
    ctx->r14 = lo;
    // 0x80234478: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8023447C: bne         $at, $zero, L_80234464
    if (ctx->r1 != 0) {
        // 0x80234480: sb          $a1, 0x8($t7)
        MEM_B(0X8, ctx->r15) = ctx->r5;
            goto L_80234464;
    }
    // 0x80234480: sb          $a1, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r5;
    // 0x80234484: jr          $ra
    // 0x80234488: nop

    return;
    // 0x80234488: nop

;}
RECOMP_FUNC void M10_FUN_8023448c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023448C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80234490: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80234494: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80234498: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8023449C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x802344A0: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    // 0x802344A4: jal         0x80006214
    // 0x802344A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x802344A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x802344AC: lbu         $t0, 0x4B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4B);
    // 0x802344B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802344B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x802344B8: lh          $t1, 0x4E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4E);
    // 0x802344BC: sb          $v0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r2;
    // 0x802344C0: bne         $t0, $at, L_80234520
    if (ctx->r8 != ctx->r1) {
        // 0x802344C4: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80234520;
    }
    // 0x802344C4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x802344C8: lh          $t6, 0x52($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X52);
    // 0x802344CC: addiu       $a3, $t1, 0x20
    ctx->r7 = ADD32(ctx->r9, 0X20);
    // 0x802344D0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x802344D4: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x802344D8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x802344DC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x802344E0: addiu       $t3, $zero, 0x220
    ctx->r11 = ADD32(0, 0X220);
    // 0x802344E4: addiu       $t7, $t6, 0x7A
    ctx->r15 = ADD32(ctx->r14, 0X7A);
    // 0x802344E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x802344EC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x802344F0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x802344F4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x802344F8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x802344FC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80234500: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x80234504: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x80234508: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023450C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80234510: jal         0x80146208
    // 0x80234514: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x80234514: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80234518: b           L_8023457C
    // 0x8023451C: lbu         $t3, 0x3E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3E);
        goto L_8023457C;
    // 0x8023451C: lbu         $t3, 0x3E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3E);
L_80234520:
    // 0x80234520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80234524: bne         $v1, $at, L_80234578
    if (ctx->r3 != ctx->r1) {
        // 0x80234528: addiu       $a1, $sp, 0x3F
        ctx->r5 = ADD32(ctx->r29, 0X3F);
            goto L_80234578;
    }
    // 0x80234528: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x8023452C: lh          $t4, 0x52($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X52);
    // 0x80234530: addiu       $a3, $t1, 0x60
    ctx->r7 = ADD32(ctx->r9, 0X60);
    // 0x80234534: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80234538: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8023453C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80234540: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80234544: addiu       $t9, $zero, 0x220
    ctx->r25 = ADD32(0, 0X220);
    // 0x80234548: addiu       $t5, $t4, 0x7A
    ctx->r13 = ADD32(ctx->r12, 0X7A);
    // 0x8023454C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80234550: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80234554: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80234558: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8023455C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80234560: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80234564: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80234568: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8023456C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80234570: jal         0x80146208
    // 0x80234574: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x80234574: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
L_80234578:
    // 0x80234578: lbu         $t3, 0x3E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3E);
L_8023457C:
    // 0x8023457C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80234580: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x80234584: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80234588: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x8023458C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80234590: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80234594: jal         0x80145310
    // 0x80234598: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x80234598: lbu         $a2, 0x5B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X5B);
    after_3:
    // 0x8023459C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x802345A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x802345A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x802345A8: jr          $ra
    // 0x802345AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x802345AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802345b0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802345b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802345B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x802345B4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x802345B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x802345BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x802345C0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x802345C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x802345C8: jal         0x80006214
    // 0x802345CC: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x802345CC: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    after_0:
    // 0x802345D0: lh          $a3, 0x4E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X4E);
    // 0x802345D4: lh          $t6, 0x52($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X52);
    // 0x802345D8: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x802345DC: addiu       $a3, $a3, 0x6C
    ctx->r7 = ADD32(ctx->r7, 0X6C);
    // 0x802345E0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x802345E4: addiu       $t8, $zero, 0x68
    ctx->r24 = ADD32(0, 0X68);
    // 0x802345E8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x802345EC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x802345F0: addiu       $t1, $zero, 0x220
    ctx->r9 = ADD32(0, 0X220);
    // 0x802345F4: addiu       $t7, $t6, 0x7A
    ctx->r15 = ADD32(ctx->r14, 0X7A);
    // 0x802345F8: sb          $v0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r2;
    // 0x802345FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80234600: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80234604: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80234608: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8023460C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80234610: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80234614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80234618: addiu       $a1, $sp, 0x3F
    ctx->r5 = ADD32(ctx->r29, 0X3F);
    // 0x8023461C: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80234620: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80234624: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80234628: jal         0x80146208
    // 0x8023462C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8023462C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_1:
    // 0x80234630: lbu         $t4, 0x3E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3E);
    // 0x80234634: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80234638: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8023463C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80234640: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80234644: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80234648: jal         0x801451C0
    // 0x8023464C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x8023464C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_2:
    // 0x80234650: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80234654: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80234658: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8023465C: jr          $ra
    // 0x80234660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80234660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234664(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80234664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234664: jr          $ra
    // 0x80234668: nop

    return;
    // 0x80234668: nop

;}
RECOMP_FUNC void M10_FUN_8023466c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023466C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80234670: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80234674: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80234678: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8023467C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80234680: lb          $t6, 0xA3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA3);
    // 0x80234684: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80234688: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8023468C: blez        $t6, L_8023470C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80234690: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8023470C;
    }
    // 0x80234690: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80234694: lb          $t7, 0xA5($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XA5);
L_80234698:
    // 0x80234698: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8023469C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x802346A0: bne         $s0, $t7, L_802346E4
    if (ctx->r16 != ctx->r15) {
        // 0x802346A4: addiu       $a1, $zero, 0xD
        ctx->r5 = ADD32(0, 0XD);
            goto L_802346E4;
    }
    // 0x802346A4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x802346A8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x802346AC: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x802346B0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x802346B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x802346B8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x802346BC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x802346C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x802346C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x802346C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x802346CC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x802346D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x802346D4: jal         0x801453CC
    // 0x802346D8: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x802346D8: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_0:
    // 0x802346DC: b           L_802346F4
    // 0x802346E0: lb          $t5, 0xA3($s1)
    ctx->r13 = MEM_B(ctx->r17, 0XA3);
        goto L_802346F4;
    // 0x802346E0: lb          $t5, 0xA3($s1)
    ctx->r13 = MEM_B(ctx->r17, 0XA3);
L_802346E4:
    // 0x802346E4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x802346E8: jal         0x80145310
    // 0x802346EC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x802346EC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x802346F0: lb          $t5, 0xA3($s1)
    ctx->r13 = MEM_B(ctx->r17, 0XA3);
L_802346F4:
    // 0x802346F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x802346F8: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802346FC: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80234700: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80234704: bnel        $at, $zero, L_80234698
    if (ctx->r1 != 0) {
        // 0x80234708: lb          $t7, 0xA5($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XA5);
            goto L_80234698;
    }
    goto skip_0;
    // 0x80234708: lb          $t7, 0xA5($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XA5);
    skip_0:
L_8023470C:
    // 0x8023470C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80234710: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80234714: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80234718: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8023471C: jr          $ra
    // 0x80234720: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80234720: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234724(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80234724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80234728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8023472C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80234730: lb          $t6, 0xA2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA2);
    // 0x80234734: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80234738: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x8023473C: beq         $t6, $zero, L_80234760
    if (ctx->r14 == 0) {
        // 0x80234740: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80234760;
    }
    // 0x80234740: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80234744: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80234748: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x8023474C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80234750: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80234754: lbu         $t9, 0x22($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X22);
    // 0x80234758: b           L_802347F0
    // 0x8023475C: sb          $t9, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r25;
        goto L_802347F0;
    // 0x8023475C: sb          $t9, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r25;
L_80234760:
    // 0x80234760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80234764: beql        $a2, $at, L_802347A0
    if (ctx->r6 == ctx->r1) {
        // 0x80234768: lw          $t3, 0x0($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X0);
            goto L_802347A0;
    }
    goto skip_0;
    // 0x80234768: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8023476C: beq         $a2, $zero, L_80234784
    if (ctx->r6 == 0) {
        // 0x80234770: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80234784;
    }
    // 0x80234770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80234774: beql        $a2, $at, L_802347B8
    if (ctx->r6 == ctx->r1) {
        // 0x80234778: lb          $t5, 0xA1($a0)
        ctx->r13 = MEM_B(ctx->r4, 0XA1);
            goto L_802347B8;
    }
    goto skip_1;
    // 0x80234778: lb          $t5, 0xA1($a0)
    ctx->r13 = MEM_B(ctx->r4, 0XA1);
    skip_1:
    // 0x8023477C: b           L_802347F4
    // 0x80234780: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_802347F4;
    // 0x80234780: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80234784:
    // 0x80234784: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80234788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8023478C: sb          $v0, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r2;
    // 0x80234790: lw          $t2, 0x4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4);
    // 0x80234794: b           L_802347F0
    // 0x80234798: sb          $v0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r2;
        goto L_802347F0;
    // 0x80234798: sb          $v0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r2;
    // 0x8023479C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
L_802347A0:
    // 0x802347A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802347A4: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
    // 0x802347A8: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x802347AC: b           L_802347F0
    // 0x802347B0: sb          $v0, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r2;
        goto L_802347F0;
    // 0x802347B0: sb          $v0, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r2;
    // 0x802347B4: lb          $t5, 0xA1($a0)
    ctx->r13 = MEM_B(ctx->r4, 0XA1);
L_802347B8:
    // 0x802347B8: lb          $t6, 0xA0($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA0);
    // 0x802347BC: bnel        $t5, $t6, L_802347E0
    if (ctx->r13 != ctx->r14) {
        // 0x802347C0: lw          $t9, 0x0($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X0);
            goto L_802347E0;
    }
    goto skip_2;
    // 0x802347C0: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x802347C4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x802347C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802347CC: sb          $v0, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r2;
    // 0x802347D0: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x802347D4: b           L_802347F0
    // 0x802347D8: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
        goto L_802347F0;
    // 0x802347D8: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x802347DC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
L_802347E0:
    // 0x802347E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802347E4: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
    // 0x802347E8: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x802347EC: sb          $v0, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r2;
L_802347F0:
    // 0x802347F0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_802347F4:
    // 0x802347F4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x802347F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802347FC: jal         0x80145310
    // 0x80234800: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80234800: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80234804: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80234808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8023480C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80234810: jal         0x80145310
    // 0x80234814: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x80234814: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_1:
    // 0x80234818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023481C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80234820: jr          $ra
    // 0x80234824: nop

    return;
    // 0x80234824: nop

;}
RECOMP_FUNC void M10_FUN_80234828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8023482C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80234830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80234834: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80234838: lbu         $t7, 0xA9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XA9);
    // 0x8023483C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80234840: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80234844: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80234848: beql        $t8, $zero, L_8023486C
    if (ctx->r24 == 0) {
        // 0x8023484C: lw          $a0, 0x4($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X4);
            goto L_8023486C;
    }
    goto skip_0;
    // 0x8023484C: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    skip_0:
    // 0x80234850: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x80234854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80234858: jal         0x80145310
    // 0x8023485C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x8023485C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80234860: b           L_80234878
    // 0x80234864: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
        goto L_80234878;
    // 0x80234864: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80234868: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
L_8023486C:
    // 0x8023486C: jal         0x80145310
    // 0x80234870: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x80234870: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80234874: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
L_80234878:
    // 0x80234878: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8023487C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80234880: lbu         $t2, 0xA9($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XA9);
    // 0x80234884: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80234888: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8023488C: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80234890: beq         $t3, $zero, L_802348B0
    if (ctx->r11 == 0) {
        // 0x80234894: nop
    
            goto L_802348B0;
    }
    // 0x80234894: nop

    // 0x80234898: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8023489C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802348A0: jal         0x80145310
    // 0x802348A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_2;
    // 0x802348A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x802348A8: b           L_802348BC
    // 0x802348AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_802348BC;
    // 0x802348AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802348B0:
    // 0x802348B0: jal         0x80145310
    // 0x802348B4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_3;
    // 0x802348B4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_3:
    // 0x802348B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_802348BC:
    // 0x802348BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x802348C0: jr          $ra
    // 0x802348C4: nop

    return;
    // 0x802348C4: nop

;}
RECOMP_FUNC void M10_FUN_802348c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802348C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x802348CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x802348D0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x802348D4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x802348D8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802348DC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x802348E0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x802348E4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x802348E8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x802348EC: bgez        $t7, L_802348FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x802348F0: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_802348FC;
    }
    // 0x802348F0: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x802348F4: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x802348F8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_802348FC:
    // 0x802348FC: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x80234900: addiu       $t0, $t9, 0xA0
    ctx->r8 = ADD32(ctx->r25, 0XA0);
    // 0x80234904: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80234908: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8023490C: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x80234910: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80234914: bgez        $t2, L_80234924
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80234918: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80234924;
    }
    // 0x80234918: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8023491C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80234920: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80234924:
    // 0x80234924: subu        $t4, $a2, $t3
    ctx->r12 = SUB32(ctx->r6, ctx->r11);
    // 0x80234928: addiu       $t5, $t4, 0xA0
    ctx->r13 = ADD32(ctx->r12, 0XA0);
    // 0x8023492C: jr          $ra
    // 0x80234930: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x80234930: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234934(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80234934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234934: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80234938: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8023493C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80234940: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80234944: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80234948: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8023494C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80234950: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80234954: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80234958: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8023495C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80234960: lw          $s6, 0x98($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X98);
    // 0x80234964: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80234968: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8023496C: jal         0x8037F58C
    // 0x80234970: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x8037F58C)(rdram, ctx);
        goto after_0;
    // 0x80234970: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80234974: lb          $t6, 0xA3($s4)
    ctx->r14 = MEM_B(ctx->r20, 0XA3);
    // 0x80234978: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8023497C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80234980: blez        $t6, L_80234ACC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80234984: lui         $fp, 0x8024
        ctx->r30 = S32(0X8024 << 16);
            goto L_80234ACC;
    }
    // 0x80234984: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x80234988: addiu       $fp, $fp, 0x7E8
    ctx->r30 = ADD32(ctx->r30, 0X7E8);
    // 0x8023498C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80234990:
    // 0x80234990: jal         0x8013C8F0
    // 0x80234994: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    LOOKUP_FUNC(0x8013C8F0)(rdram, ctx);
        goto after_1;
    // 0x80234994: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    after_1:
    // 0x80234998: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8023499C: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x802349A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x802349A4: addu        $s0, $fp, $t7
    ctx->r16 = ADD32(ctx->r30, ctx->r15);
    // 0x802349A8: bne         $s1, $zero, L_802349C0
    if (ctx->r17 != 0) {
        // 0x802349AC: sb          $v0, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r2;
            goto L_802349C0;
    }
    // 0x802349AC: sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // 0x802349B0: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x802349B4: addiu       $t8, $t8, 0x530
    ctx->r24 = ADD32(ctx->r24, 0X530);
    // 0x802349B8: b           L_802349EC
    // 0x802349BC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_802349EC;
    // 0x802349BC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_802349C0:
    // 0x802349C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x802349C4: bne         $s1, $at, L_802349DC
    if (ctx->r17 != ctx->r1) {
        // 0x802349C8: addiu       $a0, $s1, -0x2
        ctx->r4 = ADD32(ctx->r17, -0X2);
            goto L_802349DC;
    }
    // 0x802349C8: addiu       $a0, $s1, -0x2
    ctx->r4 = ADD32(ctx->r17, -0X2);
    // 0x802349CC: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x802349D0: addiu       $t9, $t9, 0x540
    ctx->r25 = ADD32(ctx->r25, 0X540);
    // 0x802349D4: b           L_802349EC
    // 0x802349D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_802349EC;
    // 0x802349D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_802349DC:
    // 0x802349DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x802349E0: jal         0x8013D16C
    // 0x802349E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x8013D16C)(rdram, ctx);
        goto after_2;
    // 0x802349E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x802349E8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_802349EC:
    // 0x802349EC: lb          $s2, 0xA2($s4)
    ctx->r18 = MEM_B(ctx->r20, 0XA2);
    // 0x802349F0: lb          $t0, 0xA3($s4)
    ctx->r8 = MEM_B(ctx->r20, 0XA3);
    // 0x802349F4: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x802349F8: negu        $at, $s2
    ctx->r1 = SUB32(0, ctx->r18);
    // 0x802349FC: sll         $s2, $at, 3
    ctx->r18 = S32(ctx->r1 << 3);
    // 0x80234A00: addu        $s2, $s2, $at
    ctx->r18 = ADD32(ctx->r18, ctx->r1);
    // 0x80234A04: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x80234A08: subu        $s2, $s2, $at
    ctx->r18 = SUB32(ctx->r18, ctx->r1);
    // 0x80234A0C: negu        $at, $t0
    ctx->r1 = SUB32(0, ctx->r8);
    // 0x80234A10: sll         $t1, $at, 3
    ctx->r9 = S32(ctx->r1 << 3);
    // 0x80234A14: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80234A18: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80234A1C: addu        $t1, $t1, $at
    ctx->r9 = ADD32(ctx->r9, ctx->r1);
    // 0x80234A20: sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18 << 3);
    // 0x80234A24: addu        $s3, $t1, $t2
    ctx->r19 = ADD32(ctx->r9, ctx->r10);
    // 0x80234A28: addiu       $s2, $s2, 0xA0
    ctx->r18 = ADD32(ctx->r18, 0XA0);
    // 0x80234A2C: addiu       $s3, $s3, 0x85
    ctx->r19 = ADD32(ctx->r19, 0X85);
    // 0x80234A30: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80234A34: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80234A38: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80234A3C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80234A40: sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // 0x80234A44: sh          $s3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r19;
    // 0x80234A48: jal         0x80006214
    // 0x80234A4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80234A4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80234A50: sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18 << 16);
    // 0x80234A54: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80234A58: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80234A5C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80234A60: addiu       $t6, $zero, 0x220
    ctx->r14 = ADD32(0, 0X220);
    // 0x80234A64: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80234A68: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80234A6C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80234A70: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80234A74: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80234A78: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80234A7C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80234A80: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80234A84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80234A88: addiu       $a1, $sp, 0x76
    ctx->r5 = ADD32(ctx->r29, 0X76);
    // 0x80234A8C: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80234A90: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80234A94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80234A98: jal         0x80146208
    // 0x80234A9C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x80234A9C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x80234AA0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80234AA4: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x80234AA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80234AAC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80234AB0: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x80234AB4: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x80234AB8: lb          $t1, 0xA3($s4)
    ctx->r9 = MEM_B(ctx->r20, 0XA3);
    // 0x80234ABC: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80234AC0: slt         $at, $s5, $t1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80234AC4: bnel        $at, $zero, L_80234990
    if (ctx->r1 != 0) {
        // 0x80234AC8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80234990;
    }
    goto skip_0;
    // 0x80234AC8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80234ACC:
    // 0x80234ACC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80234AD0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80234AD4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80234AD8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80234ADC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80234AE0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80234AE4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80234AE8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80234AEC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80234AF0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80234AF4: jr          $ra
    // 0x80234AF8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80234AF8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234afc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80234afc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234AFC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80234B00: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80234B04: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80234B08: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80234B0C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80234B10: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80234B14: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80234B18: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80234B1C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80234B20: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80234B24: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80234B28: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80234B2C: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
    // 0x80234B30: lb          $t6, 0xA3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA3);
    // 0x80234B34: lw          $a2, 0xB0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XB0);
    // 0x80234B38: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80234B3C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80234B40: blez        $t6, L_80234CB8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80234B44: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80234CB8;
    }
    // 0x80234B44: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80234B48: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80234B4C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80234B50: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x80234B54: lb          $t7, 0xA1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XA1);
L_80234B58:
    // 0x80234B58: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80234B5C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80234B60: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80234B64: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80234B68: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80234B6C: addiu       $t0, $t0, 0x7E8
    ctx->r8 = ADD32(ctx->r8, 0X7E8);
    // 0x80234B70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80234B74: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80234B78: mflo        $t8
    ctx->r24 = lo;
    // 0x80234B7C: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x80234B80: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // 0x80234B84: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80234B88: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x80234B8C: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x80234B90: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80234B94: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80234B98: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80234B9C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80234BA0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80234BA4: sb          $t5, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r13;
    // 0x80234BA8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80234BAC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80234BB0: jal         0x8023A1D4
    // 0x80234BB4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x8023A1D4)(rdram, ctx);
        goto after_0;
    // 0x80234BB4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80234BB8: lb          $s3, 0xA2($s1)
    ctx->r19 = MEM_B(ctx->r17, 0XA2);
    // 0x80234BBC: bgez        $v0, L_80234BCC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80234BC0: sra         $s6, $v0, 1
        ctx->r22 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80234BCC;
    }
    // 0x80234BC0: sra         $s6, $v0, 1
    ctx->r22 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80234BC4: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80234BC8: sra         $s6, $at, 1
    ctx->r22 = S32(SIGNED(ctx->r1) >> 1);
L_80234BCC:
    // 0x80234BCC: negu        $at, $s3
    ctx->r1 = SUB32(0, ctx->r19);
    // 0x80234BD0: sll         $s3, $at, 3
    ctx->r19 = S32(ctx->r1 << 3);
    // 0x80234BD4: lb          $t8, 0xA3($s1)
    ctx->r24 = MEM_B(ctx->r17, 0XA3);
    // 0x80234BD8: addu        $s3, $s3, $at
    ctx->r19 = ADD32(ctx->r19, ctx->r1);
    // 0x80234BDC: sll         $s3, $s3, 2
    ctx->r19 = S32(ctx->r19 << 2);
    // 0x80234BE0: subu        $s3, $s3, $at
    ctx->r19 = SUB32(ctx->r19, ctx->r1);
    // 0x80234BE4: sll         $t0, $s2, 3
    ctx->r8 = S32(ctx->r18 << 3);
    // 0x80234BE8: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x80234BEC: sll         $t9, $at, 3
    ctx->r25 = S32(ctx->r1 << 3);
    // 0x80234BF0: addu        $t0, $t0, $s2
    ctx->r8 = ADD32(ctx->r8, ctx->r18);
    // 0x80234BF4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80234BF8: addu        $t9, $t9, $at
    ctx->r25 = ADD32(ctx->r25, ctx->r1);
    // 0x80234BFC: sll         $s3, $s3, 3
    ctx->r19 = S32(ctx->r19 << 3);
    // 0x80234C00: addu        $s4, $t9, $t0
    ctx->r20 = ADD32(ctx->r25, ctx->r8);
    // 0x80234C04: addiu       $s3, $s3, 0xA0
    ctx->r19 = ADD32(ctx->r19, 0XA0);
    // 0x80234C08: addiu       $s4, $s4, 0x85
    ctx->r20 = ADD32(ctx->r20, 0X85);
    // 0x80234C0C: sll         $s6, $s6, 24
    ctx->r22 = S32(ctx->r22 << 24);
    // 0x80234C10: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80234C14: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80234C18: sra         $s6, $s6, 24
    ctx->r22 = S32(SIGNED(ctx->r22) >> 24);
    // 0x80234C1C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80234C20: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80234C24: jal         0x80006214
    // 0x80234C28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80234C28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80234C2C: sll         $s7, $v0, 24
    ctx->r23 = S32(ctx->r2 << 24);
    // 0x80234C30: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x80234C34: sll         $t1, $s6, 3
    ctx->r9 = S32(ctx->r22 << 3);
    // 0x80234C38: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80234C3C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80234C40: addiu       $t4, $zero, 0x220
    ctx->r12 = ADD32(0, 0X220);
    // 0x80234C44: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80234C48: sra         $s7, $s7, 24
    ctx->r23 = S32(SIGNED(ctx->r23) >> 24);
    // 0x80234C4C: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x80234C50: sh          $s4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r20;
    // 0x80234C54: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80234C58: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80234C5C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80234C60: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80234C64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80234C68: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80234C6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80234C70: addiu       $a1, $sp, 0x7D
    ctx->r5 = ADD32(ctx->r29, 0X7D);
    // 0x80234C74: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80234C78: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80234C7C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80234C80: jal         0x80146208
    // 0x80234C84: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x80234C84: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x80234C88: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80234C8C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x80234C90: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80234C94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80234C98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80234C9C: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x80234CA0: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x80234CA4: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x80234CA8: lb          $t0, 0xA3($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XA3);
    // 0x80234CAC: slt         $at, $s5, $t0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80234CB0: bnel        $at, $zero, L_80234B58
    if (ctx->r1 != 0) {
        // 0x80234CB4: lb          $t7, 0xA1($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XA1);
            goto L_80234B58;
    }
    goto skip_0;
    // 0x80234CB4: lb          $t7, 0xA1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XA1);
    skip_0:
L_80234CB8:
    // 0x80234CB8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80234CBC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80234CC0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80234CC4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80234CC8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80234CCC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80234CD0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80234CD4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80234CD8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80234CDC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80234CE0: jr          $ra
    // 0x80234CE4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80234CE4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234ce8(rdram, ctx);
;}
