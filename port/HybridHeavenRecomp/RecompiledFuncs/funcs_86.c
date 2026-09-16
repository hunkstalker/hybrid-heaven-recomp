#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801f5104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5104: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F5108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F510C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F5110: lw          $t0, 0x5C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X5C);
    // 0x801F5114: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5118: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x801F511C: sh          $a2, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r6;
    // 0x801F5120: lbu         $t7, 0xAE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAE);
    // 0x801F5124: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801F5128: sb          $zero, 0x92($a0)
    MEM_B(0X92, ctx->r4) = 0;
    // 0x801F512C: bne         $t7, $zero, L_801F513C
    if (ctx->r15 != 0) {
        // 0x801F5130: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_801F513C;
    }
    // 0x801F5130: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5134: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x801F5138: sb          $t8, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r24;
L_801F513C:
    // 0x801F513C: lwc1        $f4, -0x7360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7360);
    // 0x801F5140: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801F5144: addiu       $v1, $v1, 0x6EC4
    ctx->r3 = ADD32(ctx->r3, 0X6EC4);
    // 0x801F5148: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801F514C: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x801F5150: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x801F5154: lui         $t7, 0x1F
    ctx->r15 = S32(0X1F << 16);
    // 0x801F5158: lw          $v0, 0x18($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X18);
    // 0x801F515C: addiu       $t2, $t2, -0x6F74
    ctx->r10 = ADD32(ctx->r10, -0X6F74);
    // 0x801F5160: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801F5164: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x801F5168: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801F516C: beq         $v0, $zero, L_801F5194
    if (ctx->r2 == 0) {
        // 0x801F5170: nop
    
            goto L_801F5194;
    }
    // 0x801F5170: nop

    // 0x801F5174: beq         $v0, $a2, L_801F519C
    if (ctx->r2 == ctx->r6) {
        // 0x801F5178: lui         $t3, 0x8020
        ctx->r11 = S32(0X8020 << 16);
            goto L_801F519C;
    }
    // 0x801F5178: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801F517C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F5180: beq         $v0, $at, L_801F51A8
    if (ctx->r2 == ctx->r1) {
        // 0x801F5184: lui         $t1, 0x8020
        ctx->r9 = S32(0X8020 << 16);
            goto L_801F51A8;
    }
    // 0x801F5184: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F5188: addiu       $t1, $t1, -0x71B4
    ctx->r9 = ADD32(ctx->r9, -0X71B4);
    // 0x801F518C: b           L_801F51C0
    // 0x801F5190: sw          $t1, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r9;
        goto L_801F51C0;
    // 0x801F5190: sw          $t1, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r9;
L_801F5194:
    // 0x801F5194: b           L_801F51C0
    // 0x801F5198: sw          $t2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r10;
        goto L_801F51C0;
    // 0x801F5198: sw          $t2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r10;
L_801F519C:
    // 0x801F519C: addiu       $t3, $t3, -0x71B4
    ctx->r11 = ADD32(ctx->r11, -0X71B4);
    // 0x801F51A0: b           L_801F51C0
    // 0x801F51A4: sw          $t3, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r11;
        goto L_801F51C0;
    // 0x801F51A4: sw          $t3, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r11;
L_801F51A8:
    // 0x801F51A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801F51AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F51B0: lui         $t4, 0x8020
    ctx->r12 = S32(0X8020 << 16);
    // 0x801F51B4: addiu       $t4, $t4, -0x6B54
    ctx->r12 = ADD32(ctx->r12, -0X6B54);
    // 0x801F51B8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x801F51BC: sw          $t4, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r12;
L_801F51C0:
    // 0x801F51C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801F51C4: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801F51C8: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x801F51CC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x801F51D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F51D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801F51D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F51DC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801F51E0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801F51E4: jal         0x8013A1B4
    // 0x801F51E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x801F51E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x801F51EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801F51F0: jal         0x80010550
    // 0x801F51F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x801F51F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801F51F8: jal         0x801F3B5C
    // 0x801F51FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_2;
    // 0x801F51FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801F5200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F5204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F5208: jr          $ra
    // 0x801F520C: nop

    return;
    // 0x801F520C: nop

;}
RECOMP_FUNC void M9_FUN_801f5210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5210: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x801F5214: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F5218: sw          $t0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r8;
    // 0x801F521C: ori         $t7, $t6, 0x60
    ctx->r15 = ctx->r14 | 0X60;
    // 0x801F5220: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x801F5224: ori         $t9, $t7, 0xB00
    ctx->r25 = ctx->r15 | 0XB00;
    // 0x801F5228: jr          $ra
    // 0x801F522C: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    return;
    // 0x801F522C: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f5230(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f5230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F5234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F5238: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F523C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F5240: jal         0x80126968
    // 0x801F5244: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80126968)(rdram, ctx);
        goto after_0;
    // 0x801F5244: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F5248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F524C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F5250: lbu         $t7, 0xAF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAF);
    // 0x801F5254: beq         $t7, $at, L_801F5264
    if (ctx->r15 == ctx->r1) {
        // 0x801F5258: nop
    
            goto L_801F5264;
    }
    // 0x801F5258: nop

    // 0x801F525C: jal         0x8013B5B4
    // 0x801F5260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013B5B4)(rdram, ctx);
        goto after_1;
    // 0x801F5260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_801F5264:
    // 0x801F5264: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801F5268: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801F526C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F5270: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801F5274: sh          $v0, 0x190($v1)
    MEM_H(0X190, ctx->r3) = ctx->r2;
    // 0x801F5278: sh          $v0, 0x192($v1)
    MEM_H(0X192, ctx->r3) = ctx->r2;
    // 0x801F527C: sh          $v0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r2;
    // 0x801F5280: sh          $v0, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r2;
    // 0x801F5284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F528C: jr          $ra
    // 0x801F5290: nop

    return;
    // 0x801F5290: nop

;}
RECOMP_FUNC void M9_FUN_801f5294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5294: lbu         $t6, 0x3E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3E);
    // 0x801F5298: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F529C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F52A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F52A4: bgez        $t6, L_801F52B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F52A8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F52B8;
    }
    // 0x801F52A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F52AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F52B0: nop

    // 0x801F52B4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801F52B8:
    // 0x801F52B8: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801F52BC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F52C0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801F52C4: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801F52C8: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801F52CC: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x801F52D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F52D4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801F52D8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801F52DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F52E0: sub.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d - ctx->f18.d;
    // 0x801F52E4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801F52E8: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x801F52EC: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801F52F0: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x801F52F4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x801F52F8: nop

    // 0x801F52FC: bc1fl       L_801F5314
    if (!c1cs) {
        // 0x801F5300: lw          $t7, 0x30($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X30);
            goto L_801F5314;
    }
    goto skip_0;
    // 0x801F5300: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x801F5304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F5308: jr          $ra
    // 0x801F530C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x801F530C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x801F5310: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
L_801F5314:
    // 0x801F5314: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x801F5318: beq         $t8, $zero, L_801F5364
    if (ctx->r24 == 0) {
        // 0x801F531C: nop
    
            goto L_801F5364;
    }
    // 0x801F531C: nop

    // 0x801F5320: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801F5324: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F5328: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801F532C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x801F5330: nop

    // 0x801F5334: bc1f        L_801F5364
    if (!c1cs) {
        // 0x801F5338: nop
    
            goto L_801F5364;
    }
    // 0x801F5338: nop

    // 0x801F533C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F5340: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F5344: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x801F5348: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x801F534C: nop

    // 0x801F5350: bc1f        L_801F5364
    if (!c1cs) {
        // 0x801F5354: nop
    
            goto L_801F5364;
    }
    // 0x801F5354: nop

    // 0x801F5358: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F535C: nop

    // 0x801F5360: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
L_801F5364:
    // 0x801F5364: jr          $ra
    // 0x801F5368: nop

    return;
    // 0x801F5368: nop

;}
RECOMP_FUNC void M9_FUN_801f536c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F536C: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801F5370: addiu       $v0, $v0, 0x6ED0
    ctx->r2 = ADD32(ctx->r2, 0X6ED0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f5374(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f5374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5374: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F5378: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801F537C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x801F5380: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F5384: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801F5388: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x801F538C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F5390: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x801F5394: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801F5398: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x801F539C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F53A0: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801F53A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801F53A8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801F53AC: jal         0x8013A1B4
    // 0x801F53B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x801F53B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x801F53B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F53B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F53BC: jr          $ra
    // 0x801F53C0: nop

    return;
    // 0x801F53C0: nop

;}
RECOMP_FUNC void M9_FUN_801f53c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F53C4: lh          $t6, 0x92($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X92);
    // 0x801F53C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F53CC: slti        $at, $t6, 0x97
    ctx->r1 = SIGNED(ctx->r14) < 0X97 ? 1 : 0;
    // 0x801F53D0: bne         $at, $zero, L_801F53E0
    if (ctx->r1 != 0) {
            // 0x801F53D4: nop

    LOOKUP_FUNC(0x801F53E0)(rdram, ctx);
    return;
    }
    // 0x801F53D4: nop

    // 0x801F53D8: jr          $ra
    // 0x801F53DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F53DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f53e0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f53e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F53E0: jr          $ra
    // 0x801F53E4: nop

    return;
    // 0x801F53E4: nop

;}
RECOMP_FUNC void M9_FUN_801f53e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F53E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F53EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F53F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F53F4: jal         0x801F48C8
    // 0x801F53F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x801F48C8)(rdram, ctx);
        goto after_0;
    // 0x801F53F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x801F53FC: sb          $v0, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r2;
    // 0x801F5400: jal         0x801F47EC
    // 0x801F5404: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801F47EC)(rdram, ctx);
        goto after_1;
    // 0x801F5404: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801F5408: lbu         $v1, 0x1E($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1E);
    // 0x801F540C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801F5410: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801F5414: bne         $a0, $v1, L_801F542C
    if (ctx->r4 != ctx->r3) {
        // 0x801F5418: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F542C;
    }
    // 0x801F5418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F541C: bne         $a0, $t6, L_801F542C
    if (ctx->r4 != ctx->r14) {
        // 0x801F5420: nop
    
            goto L_801F542C;
    }
    // 0x801F5420: nop

    // 0x801F5424: b           L_801F5460
    // 0x801F5428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801F5460;
    // 0x801F5428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801F542C:
    // 0x801F542C: bne         $a0, $v1, L_801F5444
    if (ctx->r4 != ctx->r3) {
        // 0x801F5430: andi        $t7, $v0, 0xFF
        ctx->r15 = ctx->r2 & 0XFF;
            goto L_801F5444;
    }
    // 0x801F5430: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x801F5434: bne         $t7, $zero, L_801F5444
    if (ctx->r15 != 0) {
        // 0x801F5438: nop
    
            goto L_801F5444;
    }
    // 0x801F5438: nop

    // 0x801F543C: b           L_801F5460
    // 0x801F5440: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801F5460;
    // 0x801F5440: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801F5444:
    // 0x801F5444: bne         $v1, $zero, L_801F545C
    if (ctx->r3 != 0) {
        // 0x801F5448: andi        $t8, $v0, 0xFF
        ctx->r24 = ctx->r2 & 0XFF;
            goto L_801F545C;
    }
    // 0x801F5448: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x801F544C: bnel        $a0, $t8, L_801F5460
    if (ctx->r4 != ctx->r24) {
        // 0x801F5450: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801F5460;
    }
    goto skip_0;
    // 0x801F5450: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_0:
    // 0x801F5454: b           L_801F5460
    // 0x801F5458: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_801F5460;
    // 0x801F5458: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_801F545C:
    // 0x801F545C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801F5460:
    // 0x801F5460: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801F5464: jr          $ra
    // 0x801F5468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801F5468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f546c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f546c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F546C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x801F5470: lw          $t6, -0x4F3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F3C);
    // 0x801F5474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F5478: beq         $t6, $zero, L_801F5488
    if (ctx->r14 == 0) {
            // 0x801F547C: nop

    LOOKUP_FUNC(0x801F5488)(rdram, ctx);
    return;
    }
    // 0x801F547C: nop

    // 0x801F5480: jr          $ra
    // 0x801F5484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F5484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f5488(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f5488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5488: jr          $ra
    // 0x801F548C: nop

    return;
    // 0x801F548C: nop

;}
RECOMP_FUNC void M9_FUN_801f5490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5490: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F5494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F5498: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801F549C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801F54A0: bne         $t8, $zero, L_801F54B0
    if (ctx->r24 != 0) {
            // 0x801F54A4: nop

    LOOKUP_FUNC(0x801F54B0)(rdram, ctx);
    return;
    }
    // 0x801F54A4: nop

    // 0x801F54A8: jr          $ra
    // 0x801F54AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F54AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f54b0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f54b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F54B0: jr          $ra
    // 0x801F54B4: nop

    return;
    // 0x801F54B4: nop

;}
RECOMP_FUNC void M9_FUN_801f54b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F54B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F54BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F54C0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F54C4: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x801F54C8: jal         0x80133A24
    // 0x801F54CC: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801F54CC: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x801F54D0: beq         $v0, $zero, L_801F54E0
    if (ctx->r2 == 0) {
        // 0x801F54D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F54E0;
    }
    // 0x801F54D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F54D8: b           L_801F54E4
    // 0x801F54DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F54E4;
    // 0x801F54DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F54E0:
    // 0x801F54E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F54E4:
    // 0x801F54E4: jr          $ra
    // 0x801F54E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F54E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f54ec(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f54ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F54EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F54F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F54F4: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F54F8: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x801F54FC: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x801F5500: jal         0x801FA13C
    // 0x801F5504: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x801FA13C)(rdram, ctx);
        goto after_0;
    // 0x801F5504: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x801F5508: bne         $v0, $zero, L_801F5518
    if (ctx->r2 != 0) {
        // 0x801F550C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F5518;
    }
    // 0x801F550C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5510: b           L_801F551C
    // 0x801F5514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F551C;
    // 0x801F5514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F5518:
    // 0x801F5518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F551C:
    // 0x801F551C: jr          $ra
    // 0x801F5520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F5520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f5524(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f5524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F5528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F552C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F5530: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x801F5534: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x801F5538: beql        $v0, $zero, L_801F5564
    if (ctx->r2 == 0) {
        // 0x801F553C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F5564;
    }
    goto skip_0;
    // 0x801F553C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F5540: jal         0x80133A24
    // 0x801F5544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801F5544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x801F5548: beq         $v0, $zero, L_801F5558
    if (ctx->r2 == 0) {
        // 0x801F554C: nop
    
            goto L_801F5558;
    }
    // 0x801F554C: nop

    // 0x801F5550: b           L_801F5564
    // 0x801F5554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F5564;
    // 0x801F5554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F5558:
    // 0x801F5558: b           L_801F5564
    // 0x801F555C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801F5564;
    // 0x801F555C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F5560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F5564:
    // 0x801F5564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F556C: jr          $ra
    // 0x801F5570: nop

    return;
    // 0x801F5570: nop

;}
RECOMP_FUNC void M9_FUN_801f5574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F5578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F557C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F5580: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F5584: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F5588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F558C: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x801F5590: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x801F5594: beql        $v0, $zero, L_801F55D0
    if (ctx->r2 == 0) {
        // 0x801F5598: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F55D0;
    }
    goto skip_0;
    // 0x801F5598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F559C: bne         $a1, $at, L_801F55B4
    if (ctx->r5 != ctx->r1) {
        // 0x801F55A0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_801F55B4;
    }
    // 0x801F55A0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x801F55A4: jal         0x80133980
    // 0x801F55A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801F55A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x801F55AC: b           L_801F55D0
    // 0x801F55B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F55D0;
    // 0x801F55B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F55B4:
    // 0x801F55B4: bne         $v1, $zero, L_801F55C4
    if (ctx->r3 != 0) {
        // 0x801F55B8: nop
    
            goto L_801F55C4;
    }
    // 0x801F55B8: nop

    // 0x801F55BC: jal         0x801339D0
    // 0x801F55C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_1;
    // 0x801F55C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_801F55C4:
    // 0x801F55C4: b           L_801F55D0
    // 0x801F55C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F55D0;
    // 0x801F55C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F55CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F55D0:
    // 0x801F55D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F55D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F55D8: jr          $ra
    // 0x801F55DC: nop

    return;
    // 0x801F55DC: nop

;}
RECOMP_FUNC void M9_FUN_801f55e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F55E0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F55E4: jr          $ra
    // 0x801F55E8: sw          $a0, -0x4F3C($at)
    MEM_W(-0X4F3C, ctx->r1) = ctx->r4;
    return;
    // 0x801F55E8: sw          $a0, -0x4F3C($at)
    MEM_W(-0X4F3C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f55ec(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f55ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F55EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F55F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F55F4: jal         0x801F5490
    // 0x801F55F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801F5490)(rdram, ctx);
        goto after_0;
    // 0x801F55F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801F55FC: bne         $v0, $zero, L_801F560C
    if (ctx->r2 != 0) {
        // 0x801F5600: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F560C;
    }
    // 0x801F5600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F5604: b           L_801F5628
    // 0x801F5608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F5628;
    // 0x801F5608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F560C:
    // 0x801F560C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801F5610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F5614: lbu         $t7, 0xAD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XAD);
    // 0x801F5618: bne         $t7, $zero, L_801F5628
    if (ctx->r15 != 0) {
        // 0x801F561C: nop
    
            goto L_801F5628;
    }
    // 0x801F561C: nop

    // 0x801F5620: b           L_801F5628
    // 0x801F5624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F5628;
    // 0x801F5624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F5628:
    // 0x801F5628: jr          $ra
    // 0x801F562C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F562C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f5630(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f5630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F5634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F5638: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F563C: jal         0x80150584
    // 0x801F5640: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x801F5640: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F5644: beql        $v0, $zero, L_801F5688
    if (ctx->r2 == 0) {
        // 0x801F5648: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F5688;
    }
    goto skip_0;
    // 0x801F5648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F564C: jal         0x80150614
    // 0x801F5650: nop

    LOOKUP_FUNC(0x80150614)(rdram, ctx);
        goto after_1;
    // 0x801F5650: nop

    after_1:
    // 0x801F5654: jal         0x801505E4
    // 0x801F5658: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x801505E4)(rdram, ctx);
        goto after_2;
    // 0x801F5658: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x801F565C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x801F5660: jal         0x8015067C
    // 0x801F5664: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x8015067C)(rdram, ctx);
        goto after_3;
    // 0x801F5664: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    after_3:
    // 0x801F5668: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801F566C: lhu         $v1, 0x1E($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X1E);
    // 0x801F5670: and         $t8, $v1, $v0
    ctx->r24 = ctx->r3 & ctx->r2;
    // 0x801F5674: bnel        $t8, $zero, L_801F5688
    if (ctx->r24 != 0) {
        // 0x801F5678: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F5688;
    }
    goto skip_1;
    // 0x801F5678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801F567C: b           L_801F5688
    // 0x801F5680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F5688;
    // 0x801F5680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F5684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F5688:
    // 0x801F5688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F568C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F5690: jr          $ra
    // 0x801F5694: nop

    return;
    // 0x801F5694: nop

;}
RECOMP_FUNC void M9_FUN_801f5698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5698: jr          $ra
    // 0x801F569C: nop

    return;
    // 0x801F569C: nop

;}
RECOMP_FUNC void M9_FUN_801f56a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F56A0: jr          $ra
    // 0x801F56A4: nop

    return;
    // 0x801F56A4: nop

;}
RECOMP_FUNC void M9_FUN_801f56a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F56A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F56AC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F56B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F56B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F56B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F56BC: sw          $a0, -0x5020($at)
    MEM_W(-0X5020, ctx->r1) = ctx->r4;
    // 0x801F56C0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F56C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F56C8: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x801F56CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801F56D0: beq         $v0, $zero, L_801F56F8
    if (ctx->r2 == 0) {
        // 0x801F56D4: nop
    
            goto L_801F56F8;
    }
    // 0x801F56D4: nop

    // 0x801F56D8: jal         0x80133A24
    // 0x801F56DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801F56DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x801F56E0: beq         $v0, $zero, L_801F56F8
    if (ctx->r2 == 0) {
        // 0x801F56E4: nop
    
            goto L_801F56F8;
    }
    // 0x801F56E4: nop

    // 0x801F56E8: jal         0x80005700
    // 0x801F56EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801F56EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F56F0: b           L_801F57DC
    // 0x801F56F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F57DC;
    // 0x801F56F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F56F8:
    // 0x801F56F8: jal         0x801FA220
    // 0x801F56FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801FA220)(rdram, ctx);
        goto after_2;
    // 0x801F56FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F5700: jal         0x801F5490
    // 0x801F5704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5490)(rdram, ctx);
        goto after_3;
    // 0x801F5704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F5708: beq         $v0, $zero, L_801F578C
    if (ctx->r2 == 0) {
        // 0x801F570C: nop
    
            goto L_801F578C;
    }
    // 0x801F570C: nop

    // 0x801F5710: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x801F5714: beq         $v0, $zero, L_801F5730
    if (ctx->r2 == 0) {
        // 0x801F5718: nop
    
            goto L_801F5730;
    }
    // 0x801F5718: nop

    // 0x801F571C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x801F5720: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F5724: bne         $t7, $at, L_801F5730
    if (ctx->r15 != ctx->r1) {
        // 0x801F5728: nop
    
            goto L_801F5730;
    }
    // 0x801F5728: nop

    // 0x801F572C: sw          $v0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r2;
L_801F5730:
    // 0x801F5730: jal         0x801F54B8
    // 0x801F5734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F54B8)(rdram, ctx);
        goto after_4;
    // 0x801F5734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F5738: beql        $v0, $zero, L_801F5764
    if (ctx->r2 == 0) {
        // 0x801F573C: lw          $t8, 0x38($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X38);
            goto L_801F5764;
    }
    goto skip_0;
    // 0x801F573C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x801F5740: jal         0x801F54EC
    // 0x801F5744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F54EC)(rdram, ctx);
        goto after_5;
    // 0x801F5744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F5748: beq         $v0, $zero, L_801F578C
    if (ctx->r2 == 0) {
        // 0x801F574C: nop
    
            goto L_801F578C;
    }
    // 0x801F574C: nop

    // 0x801F5750: jal         0x80005700
    // 0x801F5754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x801F5754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F5758: b           L_801F57DC
    // 0x801F575C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F57DC;
    // 0x801F575C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F5760: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
L_801F5764:
    // 0x801F5764: lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X10);
    // 0x801F5768: srl         $a0, $v0, 16
    ctx->r4 = S32(U32(ctx->r2) >> 16);
    // 0x801F576C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801F5770: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F5774: jal         0x801FA0B0
    // 0x801F5778: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x801FA0B0)(rdram, ctx);
        goto after_7;
    // 0x801F5778: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_7:
    // 0x801F577C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x801F5780: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x801F5784: jal         0x80133980
    // 0x801F5788: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_8;
    // 0x801F5788: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_8:
L_801F578C:
    // 0x801F578C: jal         0x801F3B5C
    // 0x801F5790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_9;
    // 0x801F5790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x801F5794: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F5798: addiu       $a1, $a1, -0x5F8C
    ctx->r5 = ADD32(ctx->r5, -0X5F8C);
    // 0x801F579C: jal         0x80126CC0
    // 0x801F57A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_10;
    // 0x801F57A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801F57A4: beql        $v0, $zero, L_801F57DC
    if (ctx->r2 == 0) {
        // 0x801F57A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F57DC;
    }
    goto skip_1;
    // 0x801F57A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801F57AC: jal         0x8001F74C
    // 0x801F57B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_11;
    // 0x801F57B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801F57B4: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x801F57B8: lui         $t1, 0x801F
    ctx->r9 = S32(0X801F << 16);
    // 0x801F57BC: addiu       $t1, $t1, 0x57EC
    ctx->r9 = ADD32(ctx->r9, 0X57EC);
    // 0x801F57C0: lhu         $a1, 0x2($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X2);
    // 0x801F57C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F57C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F57CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801F57D0: jal         0x8013B570
    // 0x801F57D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_12;
    // 0x801F57D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x801F57D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F57DC:
    // 0x801F57DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F57E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F57E4: jr          $ra
    // 0x801F57E8: nop

    return;
    // 0x801F57E8: nop

;}
RECOMP_FUNC void M9_FUN_801f57ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F57EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F57F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F57F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F57F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F57FC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F5800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F5804: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x801F5808: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x801F580C: jal         0x801F4AA0
    // 0x801F5810: sb          $t8, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801F4AA0)(rdram, ctx);
        goto after_0;
    // 0x801F5810: sb          $t8, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r24;
    after_0:
    // 0x801F5814: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
    // 0x801F5818: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x801F581C: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801F5820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F5824: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801F5828: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x801F582C: lw          $v0, 0x6D10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D10);
    // 0x801F5830: beq         $v0, $zero, L_801F5840
    if (ctx->r2 == 0) {
        // 0x801F5834: nop
    
            goto L_801F5840;
    }
    // 0x801F5834: nop

    // 0x801F5838: jalr        $v0
    // 0x801F583C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x801F583C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
L_801F5840:
    // 0x801F5840: jal         0x801F5490
    // 0x801F5844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5490)(rdram, ctx);
        goto after_2;
    // 0x801F5844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F5848: beql        $v0, $zero, L_801F5890
    if (ctx->r2 == 0) {
        // 0x801F584C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F5890;
    }
    goto skip_0;
    // 0x801F584C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801F5850: jal         0x801F5524
    // 0x801F5854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5524)(rdram, ctx);
        goto after_3;
    // 0x801F5854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F5858: bne         $v0, $zero, L_801F588C
    if (ctx->r2 != 0) {
        // 0x801F585C: lbu         $t1, 0x27($sp)
        ctx->r9 = MEM_BU(ctx->r29, 0X27);
            goto L_801F588C;
    }
    // 0x801F585C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x801F5860: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F5864: beq         $t1, $at, L_801F588C
    if (ctx->r9 == ctx->r1) {
        // 0x801F5868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F588C;
    }
    // 0x801F5868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F586C: jal         0x801F5574
    // 0x801F5870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F5574)(rdram, ctx);
        goto after_4;
    // 0x801F5870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x801F5874: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801F5878: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801F587C: addiu       $a1, $a1, 0x6E54
    ctx->r5 = ADD32(ctx->r5, 0X6E54);
    // 0x801F5880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F5884: jal         0x80005670
    // 0x801F5888: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x801F5888: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    after_5:
L_801F588C:
    // 0x801F588C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801F5890:
    // 0x801F5890: jal         0x800058DC
    // 0x801F5894: lw          $a1, 0xB0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801F5894: lw          $a1, 0xB0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB0);
    after_6:
    // 0x801F5898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F589C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F58A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F58A4: jr          $ra
    // 0x801F58A8: nop

    return;
    // 0x801F58A8: nop

;}
RECOMP_FUNC void M9_FUN_801f58ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F58AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F58B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F58B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F58B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F58BC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801F58C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F58C4: lw          $t7, 0xA8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA8);
    // 0x801F58C8: jal         0x8001F74C
    // 0x801F58CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x801F58CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x801F58D0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x801F58D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F58D8: sb          $t8, 0xAD($t9)
    MEM_B(0XAD, ctx->r25) = ctx->r24;
    // 0x801F58DC: jal         0x801473F4
    // 0x801F58E0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x801473F4)(rdram, ctx);
        goto after_1;
    // 0x801F58E0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x801F58E4: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x801F58E8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801F58EC: ori         $a1, $a1, 0x2FE
    ctx->r5 = ctx->r5 | 0X2FE;
    // 0x801F58F0: jal         0x800062F8
    // 0x801F58F4: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_2;
    // 0x801F58F4: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    after_2:
    // 0x801F58F8: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801F58FC: addiu       $a1, $a1, 0x6DE0
    ctx->r5 = ADD32(ctx->r5, 0X6DE0);
    // 0x801F5900: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F5904: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x801F5908: jal         0x8014753C
    // 0x801F590C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8014753C)(rdram, ctx);
        goto after_3;
    // 0x801F590C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x801F5910: jal         0x801FA600
    // 0x801F5914: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x801FA600)(rdram, ctx);
        goto after_4;
    // 0x801F5914: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x801F5918: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x801F591C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x801F5920: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801F5924: sh          $t1, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r9;
    // 0x801F5928: addiu       $t2, $zero, -0x800
    ctx->r10 = ADD32(0, -0X800);
    // 0x801F592C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5930: sh          $t2, -0x4F40($at)
    MEM_H(-0X4F40, ctx->r1) = ctx->r10;
    // 0x801F5934: jal         0x801FA410
    // 0x801F5938: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x801FA410)(rdram, ctx);
        goto after_5;
    // 0x801F5938: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x801F593C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F5940: addiu       $a1, $a1, 0x5960
    ctx->r5 = ADD32(ctx->r5, 0X5960);
    // 0x801F5944: jal         0x800058DC
    // 0x801F5948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801F5948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F594C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F5950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F5954: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F5958: jr          $ra
    // 0x801F595C: nop

    return;
    // 0x801F595C: nop

;}
RECOMP_FUNC void M9_FUN_801f5960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F5964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F5968: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F596C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801F5970: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F5974: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801F5978: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801F597C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801F5980: beq         $v1, $zero, L_801F59A8
    if (ctx->r3 == 0) {
        // 0x801F5984: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801F59A8;
    }
    // 0x801F5984: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801F5988: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801F598C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801F5990: jal         0x80020744
    // 0x801F5994: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x801F5994: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
    after_0:
    // 0x801F5998: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F599C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F59A0: jal         0x800058DC
    // 0x801F59A4: addiu       $a1, $a1, 0x59B8
    ctx->r5 = ADD32(ctx->r5, 0X59B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F59A4: addiu       $a1, $a1, 0x59B8
    ctx->r5 = ADD32(ctx->r5, 0X59B8);
    after_1:
L_801F59A8:
    // 0x801F59A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F59AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F59B0: jr          $ra
    // 0x801F59B4: nop

    return;
    // 0x801F59B4: nop

;}
RECOMP_FUNC void M9_FUN_801f59b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F59B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801F59BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F59C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F59C4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801F59C8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801F59CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F59D0: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x801F59D4: lw          $t7, 0xA8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA8);
    // 0x801F59D8: jal         0x8012C6B4
    // 0x801F59DC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801F59DC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801F59E0: sb          $v0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r2;
    // 0x801F59E4: jal         0x8012C6B4
    // 0x801F59E8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801F59E8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_1:
    // 0x801F59EC: sb          $v0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r2;
    // 0x801F59F0: jal         0x8012C6B4
    // 0x801F59F4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801F59F4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_2:
    // 0x801F59F8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F59FC: sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // 0x801F5A00: jal         0x8001EAD0
    // 0x801F5A04: lh          $a0, -0x4F40($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4F40);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801F5A04: lh          $a0, -0x4F40($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4F40);
    after_3:
    // 0x801F5A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F5A0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F5A10: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F5A14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F5A18: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801F5A1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F5A20: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x801F5A24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F5A28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F5A2C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F5A30: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801F5A34: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5A38: sb          $t8, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r24;
    // 0x801F5A3C: ldc1        $f18, -0x7358($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X7358);
    // 0x801F5A40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F5A44: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F5A48: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801F5A4C: lbu         $a2, 0x38($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X38);
    // 0x801F5A50: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x801F5A54: lbu         $a1, 0x39($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X39);
    // 0x801F5A58: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801F5A5C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801F5A60: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F5A64: nop

    // 0x801F5A68: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x801F5A6C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F5A70: nop

    // 0x801F5A74: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801F5A78: beql        $t2, $zero, L_801F5ACC
    if (ctx->r10 == 0) {
        // 0x801F5A7C: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_801F5ACC;
    }
    goto skip_0;
    // 0x801F5A7C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801F5A80: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F5A84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F5A88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F5A8C: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x801F5A90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F5A94: nop

    // 0x801F5A98: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x801F5A9C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F5AA0: nop

    // 0x801F5AA4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801F5AA8: bne         $t2, $zero, L_801F5AC0
    if (ctx->r10 != 0) {
        // 0x801F5AAC: nop
    
            goto L_801F5AC0;
    }
    // 0x801F5AAC: nop

    // 0x801F5AB0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x801F5AB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5AB8: b           L_801F5AD8
    // 0x801F5ABC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_801F5AD8;
    // 0x801F5ABC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_801F5AC0:
    // 0x801F5AC0: b           L_801F5AD8
    // 0x801F5AC4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_801F5AD8;
    // 0x801F5AC4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801F5AC8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_801F5ACC:
    // 0x801F5ACC: nop

    // 0x801F5AD0: bltz        $t2, L_801F5AC0
    if (SIGNED(ctx->r10) < 0) {
        // 0x801F5AD4: nop
    
            goto L_801F5AC0;
    }
    // 0x801F5AD4: nop

L_801F5AD8:
    // 0x801F5AD8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801F5ADC: jal         0x80147370
    // 0x801F5AE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_4;
    // 0x801F5AE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_4:
    // 0x801F5AE4: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x801F5AE8: lh          $t3, -0x4F40($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4F40);
    // 0x801F5AEC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5AF0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801F5AF4: addiu       $t4, $t3, 0x44
    ctx->r12 = ADD32(ctx->r11, 0X44);
    // 0x801F5AF8: sh          $t4, -0x4F40($at)
    MEM_H(-0X4F40, ctx->r1) = ctx->r12;
    // 0x801F5AFC: jal         0x8012A94C
    // 0x801F5B00: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_5;
    // 0x801F5B00: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_5:
    // 0x801F5B04: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x801F5B08: addiu       $t7, $zero, 0x1D8
    ctx->r15 = ADD32(0, 0X1D8);
    // 0x801F5B0C: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x801F5B10: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801F5B14: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F5B18: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F5B1C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F5B20: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F5B24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F5B28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F5B2C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F5B30: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801F5B34: jal         0x801FCA4C
    // 0x801F5B38: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801FCA4C)(rdram, ctx);
        goto after_6;
    // 0x801F5B38: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x801F5B3C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801F5B40: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801F5B44: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801F5B48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F5B4C: jal         0x801FCAE0
    // 0x801F5B50: addiu       $a3, $zero, 0x1D8
    ctx->r7 = ADD32(0, 0X1D8);
    LOOKUP_FUNC(0x801FCAE0)(rdram, ctx);
        goto after_7;
    // 0x801F5B50: addiu       $a3, $zero, 0x1D8
    ctx->r7 = ADD32(0, 0X1D8);
    after_7:
    // 0x801F5B54: lhu         $t9, 0x3C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F5B58: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x801F5B5C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x801F5B60: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x801F5B64: bne         $v0, $at, L_801F5B7C
    if (ctx->r2 != ctx->r1) {
        // 0x801F5B68: sh          $t8, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r24;
            goto L_801F5B7C;
    }
    // 0x801F5B68: sh          $t8, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r24;
    // 0x801F5B6C: jal         0x801FA51C
    // 0x801F5B70: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x801FA51C)(rdram, ctx);
        goto after_8;
    // 0x801F5B70: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x801F5B74: b           L_801F5B9C
    // 0x801F5B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F5B9C;
    // 0x801F5B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F5B7C:
    // 0x801F5B7C: bne         $v0, $zero, L_801F5B98
    if (ctx->r2 != 0) {
        // 0x801F5B80: addiu       $t0, $zero, 0x14
        ctx->r8 = ADD32(0, 0X14);
            goto L_801F5B98;
    }
    // 0x801F5B80: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x801F5B84: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F5B88: sh          $t0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r8;
    // 0x801F5B8C: addiu       $a1, $a1, 0x5BAC
    ctx->r5 = ADD32(ctx->r5, 0X5BAC);
    // 0x801F5B90: jal         0x800058DC
    // 0x801F5B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801F5B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_801F5B98:
    // 0x801F5B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F5B9C:
    // 0x801F5B9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F5BA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801F5BA4: jr          $ra
    // 0x801F5BA8: nop

    return;
    // 0x801F5BA8: nop

;}
RECOMP_FUNC void M9_FUN_801f5bac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5BAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801F5BB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F5BB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F5BB8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801F5BBC: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x801F5BC0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801F5BC4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801F5BC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801F5BCC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801F5BD0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x801F5BD4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F5BD8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F5BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F5BE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F5BE4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801F5BE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F5BEC: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801F5BF0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F5BF4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F5BF8: nop

    // 0x801F5BFC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801F5C00: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F5C04: nop

    // 0x801F5C08: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F5C0C: beq         $v0, $zero, L_801F5C58
    if (ctx->r2 == 0) {
        // 0x801F5C10: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801F5C58;
    }
    // 0x801F5C10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801F5C14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F5C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F5C1C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801F5C20: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801F5C24: nop

    // 0x801F5C28: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801F5C2C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801F5C30: nop

    // 0x801F5C34: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801F5C38: bne         $v0, $zero, L_801F5C50
    if (ctx->r2 != 0) {
        // 0x801F5C3C: nop
    
            goto L_801F5C50;
    }
    // 0x801F5C3C: nop

    // 0x801F5C40: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801F5C44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5C48: b           L_801F5C68
    // 0x801F5C4C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801F5C68;
    // 0x801F5C4C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801F5C50:
    // 0x801F5C50: b           L_801F5C68
    // 0x801F5C54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801F5C68;
    // 0x801F5C54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801F5C58:
    // 0x801F5C58: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801F5C5C: nop

    // 0x801F5C60: bltz        $v0, L_801F5C50
    if (SIGNED(ctx->r2) < 0) {
        // 0x801F5C64: nop
    
            goto L_801F5C50;
    }
    // 0x801F5C64: nop

L_801F5C68:
    // 0x801F5C68: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x801F5C6C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F5C70: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801F5C74: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801F5C78: bgez        $v0, L_801F5C94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F5C7C: cvt.d.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
            goto L_801F5C94;
    }
    // 0x801F5C7C: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x801F5C80: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801F5C84: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F5C88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F5C8C: nop

    // 0x801F5C90: add.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = ctx->f0.d + ctx->f8.d;
L_801F5C94:
    // 0x801F5C94: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5C98: ldc1        $f6, -0x7350($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X7350);
    // 0x801F5C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5CA0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F5CA4: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x801F5CA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801F5CAC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F5CB0: nop

    // 0x801F5CB4: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x801F5CB8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F5CBC: nop

    // 0x801F5CC0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F5CC4: beql        $a1, $zero, L_801F5D18
    if (ctx->r5 == 0) {
        // 0x801F5CC8: mfc1        $a1, $f16
        ctx->r5 = (int32_t)ctx->f16.u32l;
            goto L_801F5D18;
    }
    goto skip_0;
    // 0x801F5CC8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801F5CCC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F5CD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F5CD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801F5CD8: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x801F5CDC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801F5CE0: nop

    // 0x801F5CE4: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x801F5CE8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801F5CEC: nop

    // 0x801F5CF0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801F5CF4: bne         $a1, $zero, L_801F5D0C
    if (ctx->r5 != 0) {
        // 0x801F5CF8: nop
    
            goto L_801F5D0C;
    }
    // 0x801F5CF8: nop

    // 0x801F5CFC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801F5D00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5D04: b           L_801F5D24
    // 0x801F5D08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801F5D24;
    // 0x801F5D08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801F5D0C:
    // 0x801F5D0C: b           L_801F5D24
    // 0x801F5D10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801F5D24;
    // 0x801F5D10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801F5D14: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
L_801F5D18:
    // 0x801F5D18: nop

    // 0x801F5D1C: bltz        $a1, L_801F5D0C
    if (SIGNED(ctx->r5) < 0) {
        // 0x801F5D20: nop
    
            goto L_801F5D0C;
    }
    // 0x801F5D20: nop

L_801F5D24:
    // 0x801F5D24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F5D28: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801F5D2C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F5D30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F5D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5D38: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F5D3C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x801F5D40: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801F5D44: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801F5D48: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F5D4C: nop

    // 0x801F5D50: cvt.w.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_D(ctx->f4.d);
    // 0x801F5D54: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5D58: nop

    // 0x801F5D5C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F5D60: beql        $a2, $zero, L_801F5DB4
    if (ctx->r6 == 0) {
        // 0x801F5D64: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_801F5DB4;
    }
    goto skip_1;
    // 0x801F5D64: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801F5D68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F5D6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F5D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801F5D74: sub.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d - ctx->f8.d;
    // 0x801F5D78: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801F5D7C: nop

    // 0x801F5D80: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x801F5D84: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801F5D88: nop

    // 0x801F5D8C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801F5D90: bne         $a2, $zero, L_801F5DA8
    if (ctx->r6 != 0) {
        // 0x801F5D94: nop
    
            goto L_801F5DA8;
    }
    // 0x801F5D94: nop

    // 0x801F5D98: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F5D9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5DA0: b           L_801F5DC0
    // 0x801F5DA4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801F5DC0;
    // 0x801F5DA4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801F5DA8:
    // 0x801F5DA8: b           L_801F5DC0
    // 0x801F5DAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801F5DC0;
    // 0x801F5DAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801F5DB0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_801F5DB4:
    // 0x801F5DB4: nop

    // 0x801F5DB8: bltz        $a2, L_801F5DA8
    if (SIGNED(ctx->r6) < 0) {
        // 0x801F5DBC: nop
    
            goto L_801F5DA8;
    }
    // 0x801F5DBC: nop

L_801F5DC0:
    // 0x801F5DC0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5DC4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801F5DC8: ldc1        $f6, -0x7348($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X7348);
    // 0x801F5DCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F5DD0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F5DD4: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x801F5DD8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801F5DDC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F5DE0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F5DE4: nop

    // 0x801F5DE8: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x801F5DEC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F5DF0: nop

    // 0x801F5DF4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F5DF8: beql        $a3, $zero, L_801F5E4C
    if (ctx->r7 == 0) {
        // 0x801F5DFC: mfc1        $a3, $f16
        ctx->r7 = (int32_t)ctx->f16.u32l;
            goto L_801F5E4C;
    }
    goto skip_2;
    // 0x801F5DFC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801F5E00: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F5E04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F5E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F5E0C: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x801F5E10: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801F5E14: nop

    // 0x801F5E18: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x801F5E1C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801F5E20: nop

    // 0x801F5E24: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801F5E28: bne         $a3, $zero, L_801F5E40
    if (ctx->r7 != 0) {
        // 0x801F5E2C: nop
    
            goto L_801F5E40;
    }
    // 0x801F5E2C: nop

    // 0x801F5E30: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801F5E34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F5E38: b           L_801F5E58
    // 0x801F5E3C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801F5E58;
    // 0x801F5E3C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801F5E40:
    // 0x801F5E40: b           L_801F5E58
    // 0x801F5E44: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801F5E58;
    // 0x801F5E44: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801F5E48: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
L_801F5E4C:
    // 0x801F5E4C: nop

    // 0x801F5E50: bltz        $a3, L_801F5E40
    if (SIGNED(ctx->r7) < 0) {
        // 0x801F5E54: nop
    
            goto L_801F5E40;
    }
    // 0x801F5E54: nop

L_801F5E58:
    // 0x801F5E58: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F5E5C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801F5E60: jal         0x80147370
    // 0x801F5E64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80147370)(rdram, ctx);
        goto after_0;
    // 0x801F5E64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x801F5E68: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801F5E6C: jal         0x8012A94C
    // 0x801F5E70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_1;
    // 0x801F5E70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_1:
    // 0x801F5E74: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x801F5E78: addiu       $t6, $zero, 0x1D8
    ctx->r14 = ADD32(0, 0X1D8);
    // 0x801F5E7C: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x801F5E80: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801F5E84: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801F5E88: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F5E8C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F5E90: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F5E94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F5E98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F5E9C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F5EA0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801F5EA4: jal         0x801FCA4C
    // 0x801F5EA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801FCA4C)(rdram, ctx);
        goto after_2;
    // 0x801F5EA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x801F5EAC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801F5EB0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801F5EB4: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801F5EB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F5EBC: jal         0x801FCAE0
    // 0x801F5EC0: addiu       $a3, $zero, 0x1D8
    ctx->r7 = ADD32(0, 0X1D8);
    LOOKUP_FUNC(0x801FCAE0)(rdram, ctx);
        goto after_3;
    // 0x801F5EC0: addiu       $a3, $zero, 0x1D8
    ctx->r7 = ADD32(0, 0X1D8);
    after_3:
    // 0x801F5EC4: lhu         $t7, 0x3C($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F5EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F5ECC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F5ED0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801F5ED4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x801F5ED8: bne         $t9, $zero, L_801F5EE8
    if (ctx->r25 != 0) {
        // 0x801F5EDC: sh          $t8, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r24;
            goto L_801F5EE8;
    }
    // 0x801F5EDC: sh          $t8, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r24;
    // 0x801F5EE0: jal         0x800058DC
    // 0x801F5EE4: addiu       $a1, $a1, 0x5EFC
    ctx->r5 = ADD32(ctx->r5, 0X5EFC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F5EE4: addiu       $a1, $a1, 0x5EFC
    ctx->r5 = ADD32(ctx->r5, 0X5EFC);
    after_4:
L_801F5EE8:
    // 0x801F5EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F5EEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F5EF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801F5EF4: jr          $ra
    // 0x801F5EF8: nop

    return;
    // 0x801F5EF8: nop

;}
RECOMP_FUNC void M9_FUN_801f5efc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5EFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F5F00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F5F04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F5F08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F5F0C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801F5F10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F5F14: jal         0x801FA570
    // 0x801F5F18: lw          $a0, 0xA8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XA8);
    LOOKUP_FUNC(0x801FA570)(rdram, ctx);
        goto after_0;
    // 0x801F5F18: lw          $a0, 0xA8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XA8);
    after_0:
    // 0x801F5F1C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801F5F20: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801F5F24: ori         $a1, $a1, 0x900
    ctx->r5 = ctx->r5 | 0X900;
    // 0x801F5F28: jal         0x800062F8
    // 0x801F5F2C: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_1;
    // 0x801F5F2C: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    after_1:
    // 0x801F5F30: jal         0x80147450
    // 0x801F5F34: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x80147450)(rdram, ctx);
        goto after_2;
    // 0x801F5F34: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x801F5F38: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x801F5F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F5F40: jal         0x80005700
    // 0x801F5F44: sb          $zero, 0xAD($t8)
    MEM_B(0XAD, ctx->r24) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801F5F44: sb          $zero, 0xAD($t8)
    MEM_B(0XAD, ctx->r24) = 0;
    after_3:
    // 0x801F5F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F5F4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F5F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F5F54: jr          $ra
    // 0x801F5F58: nop

    return;
    // 0x801F5F58: nop

;}
RECOMP_FUNC void M9_FUN_801f5f5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5F5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F5F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F5F64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F5F68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F5F6C: lbu         $t6, 0xAF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAF);
    // 0x801F5F70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801F5F74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F5F78: jal         0x801270C0
    // 0x801F5F7C: sb          $t6, -0x33DC($at)
    MEM_B(-0X33DC, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801270C0)(rdram, ctx);
        goto after_0;
    // 0x801F5F7C: sb          $t6, -0x33DC($at)
    MEM_B(-0X33DC, ctx->r1) = ctx->r14;
    after_0:
    // 0x801F5F80: beq         $v0, $zero, L_801F5FF4
    if (ctx->r2 == 0) {
        // 0x801F5F84: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_801F5FF4;
    }
    // 0x801F5F84: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801F5F88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801F5F8C: sh          $t7, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r15;
    // 0x801F5F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F5F94: jal         0x801F5574
    // 0x801F5F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801F5574)(rdram, ctx);
        goto after_1;
    // 0x801F5F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801F5F9C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x801F5FA0: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x801F5FA4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801F5FA8: bne         $t0, $zero, L_801F5FC0
    if (ctx->r8 != 0) {
        // 0x801F5FAC: nop
    
            goto L_801F5FC0;
    }
    // 0x801F5FAC: nop

    // 0x801F5FB0: jal         0x801F55E0
    // 0x801F5FB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F55E0)(rdram, ctx);
        goto after_2;
    // 0x801F5FB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801F5FB8: b           L_801F5FCC
    // 0x801F5FBC: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
        goto L_801F5FCC;
    // 0x801F5FBC: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
L_801F5FC0:
    // 0x801F5FC0: jal         0x801F55E0
    // 0x801F5FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801F55E0)(rdram, ctx);
        goto after_3;
    // 0x801F5FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801F5FC8: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
L_801F5FCC:
    // 0x801F5FCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801F5FD0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801F5FD4: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x801F5FD8: jal         0x80020744
    // 0x801F5FDC: sh          $t3, -0x406C($at)
    MEM_H(-0X406C, ctx->r1) = ctx->r11;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x801F5FDC: sh          $t3, -0x406C($at)
    MEM_H(-0X406C, ctx->r1) = ctx->r11;
    after_4:
    // 0x801F5FE0: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801F5FE4: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    // 0x801F5FE8: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x801F5FEC: jal         0x801268CC
    // 0x801F5FF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x801268CC)(rdram, ctx);
        goto after_5;
    // 0x801F5FF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_5:
L_801F5FF4:
    // 0x801F5FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F5FF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F5FFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F6000: jr          $ra
    // 0x801F6004: nop

    return;
    // 0x801F6004: nop

;}
RECOMP_FUNC void M9_FUN_801f6008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F600C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F6010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F6014: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801F6018: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801F601C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6020: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801F6024: jal         0x80010550
    // 0x801F6028: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801F6028: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F602C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6030: jal         0x801F48C8
    // 0x801F6034: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801F48C8)(rdram, ctx);
        goto after_1;
    // 0x801F6034: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x801F6038: beq         $v0, $zero, L_801F6058
    if (ctx->r2 == 0) {
        // 0x801F603C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801F6058;
    }
    // 0x801F603C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F6040: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801F6044: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6048: addiu       $a1, $a1, 0x60D8
    ctx->r5 = ADD32(ctx->r5, 0X60D8);
    // 0x801F604C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6050: jal         0x800058DC
    // 0x801F6054: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F6054: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    after_2:
L_801F6058:
    // 0x801F6058: jal         0x801C3B3C
    // 0x801F605C: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_3;
    // 0x801F605C: nop

    after_3:
    // 0x801F6060: bnel        $v0, $zero, L_801F60C8
    if (ctx->r2 != 0) {
        // 0x801F6064: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F60C8;
    }
    goto skip_0;
    // 0x801F6064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801F6068: lbu         $t8, 0xAE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F606C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6070: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6074: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801F6078: bgez        $t8, L_801F608C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801F607C: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F608C;
    }
    // 0x801F607C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6080: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6084: nop

    // 0x801F6088: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F608C:
    // 0x801F608C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6090: jal         0x801F3FFC
    // 0x801F6094: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_4;
    // 0x801F6094: nop

    after_4:
    // 0x801F6098: beql        $v0, $zero, L_801F60C8
    if (ctx->r2 == 0) {
        // 0x801F609C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F60C8;
    }
    goto skip_1;
    // 0x801F609C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801F60A0: jal         0x801F53E8
    // 0x801F60A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_5;
    // 0x801F60A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F60A8: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F60AC: jal         0x801F5230
    // 0x801F60B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_6;
    // 0x801F60B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F60B4: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F60B8: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F60BC: jal         0x800058DC
    // 0x801F60C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F60C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801F60C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F60C8:
    // 0x801F60C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F60CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F60D0: jr          $ra
    // 0x801F60D4: nop

    return;
    // 0x801F60D4: nop

;}
RECOMP_FUNC void M9_FUN_801f60d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F60D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F60DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F60E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F60E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F60E8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F60EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F60F0: jal         0x801F5630
    // 0x801F60F4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801F5630)(rdram, ctx);
        goto after_0;
    // 0x801F60F4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F60F8: beq         $v0, $zero, L_801F6130
    if (ctx->r2 == 0) {
        // 0x801F60FC: nop
    
            goto L_801F6130;
    }
    // 0x801F60FC: nop

    // 0x801F6100: jal         0x801F55EC
    // 0x801F6104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_1;
    // 0x801F6104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F6108: beq         $v0, $zero, L_801F6130
    if (ctx->r2 == 0) {
        // 0x801F610C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F6130;
    }
    // 0x801F610C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6110: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6114: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6118: addiu       $a1, $a1, 0x74FC
    ctx->r5 = ADD32(ctx->r5, 0X74FC);
    // 0x801F611C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6120: jal         0x800058DC
    // 0x801F6124: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F6124: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    after_2:
    // 0x801F6128: b           L_801F62CC
    // 0x801F612C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F62CC;
    // 0x801F612C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6130:
    // 0x801F6130: jal         0x801C3B3C
    // 0x801F6134: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_3;
    // 0x801F6134: nop

    after_3:
    // 0x801F6138: bne         $v0, $zero, L_801F61A4
    if (ctx->r2 != 0) {
        // 0x801F613C: nop
    
            goto L_801F61A4;
    }
    // 0x801F613C: nop

    // 0x801F6140: lbu         $t9, 0xAE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6148: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F614C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801F6150: bgez        $t9, L_801F6164
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801F6154: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6164;
    }
    // 0x801F6154: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F615C: nop

    // 0x801F6160: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6164:
    // 0x801F6164: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6168: jal         0x801F3FFC
    // 0x801F616C: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_4;
    // 0x801F616C: nop

    after_4:
    // 0x801F6170: beq         $v0, $zero, L_801F61A4
    if (ctx->r2 == 0) {
        // 0x801F6174: nop
    
            goto L_801F61A4;
    }
    // 0x801F6174: nop

    // 0x801F6178: jal         0x801F53E8
    // 0x801F617C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_5;
    // 0x801F617C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F6180: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6184: jal         0x801F5230
    // 0x801F6188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_6;
    // 0x801F6188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F618C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6190: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6194: jal         0x800058DC
    // 0x801F6198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F6198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801F619C: b           L_801F62CC
    // 0x801F61A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F62CC;
    // 0x801F61A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F61A4:
    // 0x801F61A4: jal         0x801F55EC
    // 0x801F61A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_8;
    // 0x801F61A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801F61AC: beq         $v0, $zero, L_801F62C8
    if (ctx->r2 == 0) {
        // 0x801F61B0: lui         $t0, 0x8022
        ctx->r8 = S32(0X8022 << 16);
            goto L_801F62C8;
    }
    // 0x801F61B0: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x801F61B4: addiu       $t0, $t0, -0x5018
    ctx->r8 = ADD32(ctx->r8, -0X5018);
    // 0x801F61B8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801F61BC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801F61C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F61C4: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801F61C8: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801F61CC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F61D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F61D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F61D8: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801F61DC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801F61E0: jal         0x8012CE9C
    // 0x801F61E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_9;
    // 0x801F61E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_9:
    // 0x801F61E8: bnel        $v0, $zero, L_801F62CC
    if (ctx->r2 != 0) {
        // 0x801F61EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F62CC;
    }
    goto skip_0;
    // 0x801F61EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F61F0: jal         0x801F4A48
    // 0x801F61F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F4A48)(rdram, ctx);
        goto after_10;
    // 0x801F61F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801F61F8: lbu         $t4, 0x93($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X93);
    // 0x801F61FC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801F6200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6204: beq         $t4, $zero, L_801F6284
    if (ctx->r12 == 0) {
        // 0x801F6208: nop
    
            goto L_801F6284;
    }
    // 0x801F6208: nop

    // 0x801F620C: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x801F6210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6214: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6218: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801F621C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F6220: jal         0x801F474C
    // 0x801F6224: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_11;
    // 0x801F6224: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_11:
    // 0x801F6228: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F622C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x801F6230: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x801F6234: mfhi        $v1
    ctx->r3 = hi;
    // 0x801F6238: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801F623C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801F6240: beq         $v1, $zero, L_801F62BC
    if (ctx->r3 == 0) {
        // 0x801F6244: sh          $t6, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r14;
            goto L_801F62BC;
    }
    // 0x801F6244: sh          $t6, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r14;
    // 0x801F6248: jal         0x8012C6B4
    // 0x801F624C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x801F624C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x801F6250: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801F6254: beq         $at, $zero, L_801F62BC
    if (ctx->r1 == 0) {
        // 0x801F6258: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F62BC;
    }
    // 0x801F6258: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F625C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6264: jal         0x801F3B6C
    // 0x801F6268: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x801F3B6C)(rdram, ctx);
        goto after_13;
    // 0x801F6268: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    after_13:
    // 0x801F626C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6270: addiu       $a1, $a1, 0x62DC
    ctx->r5 = ADD32(ctx->r5, 0X62DC);
    // 0x801F6274: jal         0x800058DC
    // 0x801F6278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x801F6278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x801F627C: b           L_801F62C0
    // 0x801F6280: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_801F62C0;
    // 0x801F6280: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_801F6284:
    // 0x801F6284: jal         0x801F42E4
    // 0x801F6288: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    LOOKUP_FUNC(0x801F42E4)(rdram, ctx);
        goto after_15;
    // 0x801F6288: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    after_15:
    // 0x801F628C: lh          $t9, 0x94($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X94);
    // 0x801F6290: lh          $t0, 0x96($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X96);
    // 0x801F6294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6298: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801F629C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801F62A0: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F62A4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F62A8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801F62AC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F62B0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801F62B4: jal         0x801F474C
    // 0x801F62B8: nop

    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_16;
    // 0x801F62B8: nop

    after_16:
L_801F62BC:
    // 0x801F62BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_801F62C0:
    // 0x801F62C0: jal         0x80010550
    // 0x801F62C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_17;
    // 0x801F62C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
L_801F62C8:
    // 0x801F62C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F62CC:
    // 0x801F62CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F62D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F62D4: jr          $ra
    // 0x801F62D8: nop

    return;
    // 0x801F62D8: nop

;}
RECOMP_FUNC void M9_FUN_801f62dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F62DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F62E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F62E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F62E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F62EC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F62F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F62F4: jal         0x801C3B3C
    // 0x801F62F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F62F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F62FC: bnel        $v0, $zero, L_801F636C
    if (ctx->r2 != 0) {
        // 0x801F6300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F636C;
    }
    goto skip_0;
    // 0x801F6300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801F6304: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F630C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6310: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F6314: bgez        $t7, L_801F6328
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F6318: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6328;
    }
    // 0x801F6318: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F631C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6320: nop

    // 0x801F6324: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6328:
    // 0x801F6328: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F632C: jal         0x801F3FFC
    // 0x801F6330: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6330: nop

    after_1:
    // 0x801F6334: beql        $v0, $zero, L_801F636C
    if (ctx->r2 == 0) {
        // 0x801F6338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F636C;
    }
    goto skip_1;
    // 0x801F6338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801F633C: jal         0x801F53E8
    // 0x801F6340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F6344: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6348: jal         0x801F5230
    // 0x801F634C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F634C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6350: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6354: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6358: jal         0x800058DC
    // 0x801F635C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F635C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F6360: b           L_801F63D0
    // 0x801F6364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F63D0;
    // 0x801F6364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F6368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801F636C:
    // 0x801F636C: jal         0x8012A94C
    // 0x801F6370: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_5;
    // 0x801F6370: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_5:
    // 0x801F6374: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x801F6378: addiu       $t8, $t8, -0x4FE8
    ctx->r24 = ADD32(ctx->r24, -0X4FE8);
    // 0x801F637C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F6380: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801F6384: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6388: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801F638C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801F6390: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6394: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6398: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F639C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801F63A0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F63A4: jal         0x8012CE9C
    // 0x801F63A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801F63A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x801F63AC: bne         $v0, $zero, L_801F63CC
    if (ctx->r2 != 0) {
        // 0x801F63B0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801F63CC;
    }
    // 0x801F63B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F63B4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801F63B8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F63BC: addiu       $a1, $a1, 0x60D8
    ctx->r5 = ADD32(ctx->r5, 0X60D8);
    // 0x801F63C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F63C4: jal         0x800058DC
    // 0x801F63C8: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F63C8: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    after_7:
L_801F63CC:
    // 0x801F63CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F63D0:
    // 0x801F63D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F63D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F63D8: jr          $ra
    // 0x801F63DC: nop

    return;
    // 0x801F63DC: nop

;}
RECOMP_FUNC void M9_FUN_801f63e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F63E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F63E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F63E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F63EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F63F0: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F63F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F63F8: jal         0x801F5630
    // 0x801F63FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801F5630)(rdram, ctx);
        goto after_0;
    // 0x801F63FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6400: beq         $v0, $zero, L_801F6438
    if (ctx->r2 == 0) {
        // 0x801F6404: nop
    
            goto L_801F6438;
    }
    // 0x801F6404: nop

    // 0x801F6408: jal         0x801F55EC
    // 0x801F640C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_1;
    // 0x801F640C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F6410: beq         $v0, $zero, L_801F6438
    if (ctx->r2 == 0) {
        // 0x801F6414: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F6438;
    }
    // 0x801F6414: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6418: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801F641C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6420: addiu       $a1, $a1, 0x74FC
    ctx->r5 = ADD32(ctx->r5, 0X74FC);
    // 0x801F6424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6428: jal         0x800058DC
    // 0x801F642C: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F642C: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    after_2:
    // 0x801F6430: b           L_801F6524
    // 0x801F6434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6524;
    // 0x801F6434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6438:
    // 0x801F6438: jal         0x801C3B3C
    // 0x801F643C: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_3;
    // 0x801F643C: nop

    after_3:
    // 0x801F6440: bne         $v0, $zero, L_801F64AC
    if (ctx->r2 != 0) {
        // 0x801F6444: nop
    
            goto L_801F64AC;
    }
    // 0x801F6444: nop

    // 0x801F6448: lbu         $t9, 0xAE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6450: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6454: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801F6458: bgez        $t9, L_801F646C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801F645C: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F646C;
    }
    // 0x801F645C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6464: nop

    // 0x801F6468: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F646C:
    // 0x801F646C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6470: jal         0x801F3FFC
    // 0x801F6474: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_4;
    // 0x801F6474: nop

    after_4:
    // 0x801F6478: beq         $v0, $zero, L_801F64AC
    if (ctx->r2 == 0) {
        // 0x801F647C: nop
    
            goto L_801F64AC;
    }
    // 0x801F647C: nop

    // 0x801F6480: jal         0x801F53E8
    // 0x801F6484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_5;
    // 0x801F6484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F6488: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F648C: jal         0x801F5230
    // 0x801F6490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_6;
    // 0x801F6490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F6494: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6498: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F649C: jal         0x800058DC
    // 0x801F64A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F64A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801F64A4: b           L_801F6524
    // 0x801F64A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6524;
    // 0x801F64A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F64AC:
    // 0x801F64AC: jal         0x801F55EC
    // 0x801F64B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_8;
    // 0x801F64B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801F64B4: beq         $v0, $zero, L_801F6520
    if (ctx->r2 == 0) {
        // 0x801F64B8: lui         $t0, 0x8022
        ctx->r8 = S32(0X8022 << 16);
            goto L_801F6520;
    }
    // 0x801F64B8: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x801F64BC: addiu       $t0, $t0, -0x5008
    ctx->r8 = ADD32(ctx->r8, -0X5008);
    // 0x801F64C0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801F64C4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801F64C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F64CC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801F64D0: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801F64D4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F64D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F64DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F64E0: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801F64E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801F64E8: jal         0x8012CE9C
    // 0x801F64EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_9;
    // 0x801F64EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_9:
    // 0x801F64F0: bne         $v0, $zero, L_801F6520
    if (ctx->r2 != 0) {
        // 0x801F64F4: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_801F6520;
    }
    // 0x801F64F4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801F64F8: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x801F64FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6500: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6504: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801F6508: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F650C: jal         0x801F474C
    // 0x801F6510: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_10;
    // 0x801F6510: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_10:
    // 0x801F6514: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6518: jal         0x80010550
    // 0x801F651C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_11;
    // 0x801F651C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
L_801F6520:
    // 0x801F6520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6524:
    // 0x801F6524: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6528: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F652C: jr          $ra
    // 0x801F6530: nop

    return;
    // 0x801F6530: nop

;}
RECOMP_FUNC void M9_FUN_801f6534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6534: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6538: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F653C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6540: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6544: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F654C: jal         0x801C3B3C
    // 0x801F6550: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F6550: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6554: bne         $v0, $zero, L_801F65C0
    if (ctx->r2 != 0) {
        // 0x801F6558: nop
    
            goto L_801F65C0;
    }
    // 0x801F6558: nop

    // 0x801F655C: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6564: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6568: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F656C: bgez        $t7, L_801F6580
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F6570: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6580;
    }
    // 0x801F6570: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6578: nop

    // 0x801F657C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6580:
    // 0x801F6580: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6584: jal         0x801F3FFC
    // 0x801F6588: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6588: nop

    after_1:
    // 0x801F658C: beq         $v0, $zero, L_801F65C0
    if (ctx->r2 == 0) {
        // 0x801F6590: nop
    
            goto L_801F65C0;
    }
    // 0x801F6590: nop

    // 0x801F6594: jal         0x801F53E8
    // 0x801F6598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F659C: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F65A0: jal         0x801F5230
    // 0x801F65A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F65A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F65A8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F65AC: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F65B0: jal         0x800058DC
    // 0x801F65B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F65B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F65B8: b           L_801F670C
    // 0x801F65BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F670C;
    // 0x801F65BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F65C0:
    // 0x801F65C0: jal         0x801F55EC
    // 0x801F65C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_5;
    // 0x801F65C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F65C8: beq         $v0, $zero, L_801F6708
    if (ctx->r2 == 0) {
        // 0x801F65CC: lui         $t8, 0x8022
        ctx->r24 = S32(0X8022 << 16);
            goto L_801F6708;
    }
    // 0x801F65CC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x801F65D0: addiu       $t8, $t8, -0x5018
    ctx->r24 = ADD32(ctx->r24, -0X5018);
    // 0x801F65D4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F65D8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801F65DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F65E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801F65E4: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801F65E8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F65EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F65F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F65F4: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801F65F8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F65FC: jal         0x8012CE9C
    // 0x801F6600: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801F6600: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x801F6604: bnel        $v0, $zero, L_801F670C
    if (ctx->r2 != 0) {
        // 0x801F6608: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F670C;
    }
    goto skip_0;
    // 0x801F6608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F660C: lbu         $t2, 0x9C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X9C);
    // 0x801F6610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6614: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6618: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801F661C: bgez        $t2, L_801F6630
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801F6620: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F6630;
    }
    // 0x801F6620: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F6624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F6628: nop

    // 0x801F662C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801F6630:
    // 0x801F6630: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F6634: jal         0x801F442C
    // 0x801F6638: nop

    LOOKUP_FUNC(0x801F442C)(rdram, ctx);
        goto after_7;
    // 0x801F6638: nop

    after_7:
    // 0x801F663C: beq         $v0, $zero, L_801F66C0
    if (ctx->r2 == 0) {
        // 0x801F6640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F66C0;
    }
    // 0x801F6640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6644: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801F6648: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801F664C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6650: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6654: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801F6658: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F665C: jal         0x801F474C
    // 0x801F6660: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_8;
    // 0x801F6660: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_8:
    // 0x801F6664: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F6668: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x801F666C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x801F6670: mfhi        $v1
    ctx->r3 = hi;
    // 0x801F6674: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801F6678: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801F667C: beq         $v1, $zero, L_801F66FC
    if (ctx->r3 == 0) {
        // 0x801F6680: sh          $t4, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r12;
            goto L_801F66FC;
    }
    // 0x801F6680: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x801F6684: jal         0x8012C6B4
    // 0x801F6688: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x801F6688: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x801F668C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801F6690: beq         $at, $zero, L_801F66FC
    if (ctx->r1 == 0) {
        // 0x801F6694: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801F66FC;
    }
    // 0x801F6694: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801F6698: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801F669C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F66A0: jal         0x801F3B6C
    // 0x801F66A4: sh          $t5, 0x78($t6)
    MEM_H(0X78, ctx->r14) = ctx->r13;
    LOOKUP_FUNC(0x801F3B6C)(rdram, ctx);
        goto after_10;
    // 0x801F66A4: sh          $t5, 0x78($t6)
    MEM_H(0X78, ctx->r14) = ctx->r13;
    after_10:
    // 0x801F66A8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F66AC: addiu       $a1, $a1, 0x671C
    ctx->r5 = ADD32(ctx->r5, 0X671C);
    // 0x801F66B0: jal         0x800058DC
    // 0x801F66B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801F66B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801F66B8: b           L_801F6700
    // 0x801F66BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_801F6700;
    // 0x801F66BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_801F66C0:
    // 0x801F66C0: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x801F66C4: jal         0x801F42E4
    // 0x801F66C8: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    LOOKUP_FUNC(0x801F42E4)(rdram, ctx);
        goto after_12;
    // 0x801F66C8: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    after_12:
    // 0x801F66CC: lh          $t7, 0x94($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X94);
    // 0x801F66D0: lh          $t8, 0x96($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X96);
    // 0x801F66D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F66D8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801F66DC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801F66E0: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F66E4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F66E8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F66EC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F66F0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801F66F4: jal         0x801F474C
    // 0x801F66F8: nop

    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_13;
    // 0x801F66F8: nop

    after_13:
L_801F66FC:
    // 0x801F66FC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_801F6700:
    // 0x801F6700: jal         0x80010550
    // 0x801F6704: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_14;
    // 0x801F6704: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
L_801F6708:
    // 0x801F6708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F670C:
    // 0x801F670C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6714: jr          $ra
    // 0x801F6718: nop

    return;
    // 0x801F6718: nop

;}
RECOMP_FUNC void M9_FUN_801f671c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F671C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6720: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6724: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6728: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F672C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6734: jal         0x801C3B3C
    // 0x801F6738: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F6738: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F673C: bnel        $v0, $zero, L_801F67AC
    if (ctx->r2 != 0) {
        // 0x801F6740: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F67AC;
    }
    goto skip_0;
    // 0x801F6740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801F6744: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F674C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6750: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F6754: bgez        $t7, L_801F6768
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F6758: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6768;
    }
    // 0x801F6758: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F675C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6760: nop

    // 0x801F6764: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6768:
    // 0x801F6768: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F676C: jal         0x801F3FFC
    // 0x801F6770: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6770: nop

    after_1:
    // 0x801F6774: beql        $v0, $zero, L_801F67AC
    if (ctx->r2 == 0) {
        // 0x801F6778: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F67AC;
    }
    goto skip_1;
    // 0x801F6778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801F677C: jal         0x801F53E8
    // 0x801F6780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F6784: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6788: jal         0x801F5230
    // 0x801F678C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F678C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6790: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6794: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6798: jal         0x800058DC
    // 0x801F679C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F679C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F67A0: b           L_801F6810
    // 0x801F67A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6810;
    // 0x801F67A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F67A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801F67AC:
    // 0x801F67AC: jal         0x8012A94C
    // 0x801F67B0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_5;
    // 0x801F67B0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_5:
    // 0x801F67B4: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x801F67B8: addiu       $t8, $t8, -0x4FE8
    ctx->r24 = ADD32(ctx->r24, -0X4FE8);
    // 0x801F67BC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F67C0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801F67C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F67C8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801F67CC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801F67D0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F67D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F67D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F67DC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801F67E0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F67E4: jal         0x8012CE9C
    // 0x801F67E8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801F67E8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x801F67EC: bne         $v0, $zero, L_801F680C
    if (ctx->r2 != 0) {
        // 0x801F67F0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801F680C;
    }
    // 0x801F67F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F67F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801F67F8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F67FC: addiu       $a1, $a1, 0x6534
    ctx->r5 = ADD32(ctx->r5, 0X6534);
    // 0x801F6800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6804: jal         0x800058DC
    // 0x801F6808: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F6808: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    after_7:
L_801F680C:
    // 0x801F680C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6810:
    // 0x801F6810: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6818: jr          $ra
    // 0x801F681C: nop

    return;
    // 0x801F681C: nop

;}
RECOMP_FUNC void M9_FUN_801f6820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6820: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6824: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6828: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F682C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6830: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6834: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6838: jal         0x801C3B3C
    // 0x801F683C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F683C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6840: bne         $v0, $zero, L_801F68AC
    if (ctx->r2 != 0) {
        // 0x801F6844: nop
    
            goto L_801F68AC;
    }
    // 0x801F6844: nop

    // 0x801F6848: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F684C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6850: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6854: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F6858: bgez        $t7, L_801F686C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F685C: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F686C;
    }
    // 0x801F685C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6864: nop

    // 0x801F6868: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F686C:
    // 0x801F686C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6870: jal         0x801F3FFC
    // 0x801F6874: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6874: nop

    after_1:
    // 0x801F6878: beq         $v0, $zero, L_801F68AC
    if (ctx->r2 == 0) {
        // 0x801F687C: nop
    
            goto L_801F68AC;
    }
    // 0x801F687C: nop

    // 0x801F6880: jal         0x801F53E8
    // 0x801F6884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F6888: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F688C: jal         0x801F5230
    // 0x801F6890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F6890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6894: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6898: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F689C: jal         0x800058DC
    // 0x801F68A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F68A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F68A4: b           L_801F6A2C
    // 0x801F68A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6A2C;
    // 0x801F68A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F68AC:
    // 0x801F68AC: jal         0x801F55EC
    // 0x801F68B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_5;
    // 0x801F68B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F68B4: beql        $v0, $zero, L_801F6A2C
    if (ctx->r2 == 0) {
        // 0x801F68B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F6A2C;
    }
    goto skip_0;
    // 0x801F68B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F68BC: lbu         $t8, 0x9C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9C);
    // 0x801F68C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F68C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F68C8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801F68CC: bgez        $t8, L_801F68E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801F68D0: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F68E0;
    }
    // 0x801F68D0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F68D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F68D8: nop

    // 0x801F68DC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801F68E0:
    // 0x801F68E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F68E4: jal         0x801F442C
    // 0x801F68E8: nop

    LOOKUP_FUNC(0x801F442C)(rdram, ctx);
        goto after_6;
    // 0x801F68E8: nop

    after_6:
    // 0x801F68EC: beq         $v0, $zero, L_801F698C
    if (ctx->r2 == 0) {
        // 0x801F68F0: lui         $t1, 0x8022
        ctx->r9 = S32(0X8022 << 16);
            goto L_801F698C;
    }
    // 0x801F68F0: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x801F68F4: lbu         $t9, 0x9D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9D);
    // 0x801F68F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F68FC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6900: bne         $t9, $zero, L_801F6910
    if (ctx->r25 != 0) {
        // 0x801F6904: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6910;
    }
    // 0x801F6904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6908: jal         0x801F3B6C
    // 0x801F690C: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x801F3B6C)(rdram, ctx);
        goto after_7;
    // 0x801F690C: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    after_7:
L_801F6910:
    // 0x801F6910: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x801F6914: addiu       $t2, $t2, -0x5008
    ctx->r10 = ADD32(ctx->r10, -0X5008);
    // 0x801F6918: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801F691C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801F6920: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6924: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x801F6928: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x801F692C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6930: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6934: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F6938: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801F693C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801F6940: jal         0x8012CE9C
    // 0x801F6944: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_8;
    // 0x801F6944: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x801F6948: bne         $v0, $zero, L_801F6A28
    if (ctx->r2 != 0) {
        // 0x801F694C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6A28;
    }
    // 0x801F694C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6950: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6954: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F6958: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F695C: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x801F6960: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x801F6964: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F6968: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x801F696C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801F6970: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801F6974: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F6978: jal         0x801F474C
    // 0x801F697C: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_9;
    // 0x801F697C: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_9:
    // 0x801F6980: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6984: b           L_801F6A1C
    // 0x801F6988: sb          $t7, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r15;
        goto L_801F6A1C;
    // 0x801F6988: sb          $t7, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r15;
L_801F698C:
    // 0x801F698C: lbu         $t8, 0x9D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9D);
    // 0x801F6990: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F6994: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6998: bne         $t8, $at, L_801F69A8
    if (ctx->r24 != ctx->r1) {
        // 0x801F699C: addiu       $t1, $t1, -0x5018
        ctx->r9 = ADD32(ctx->r9, -0X5018);
            goto L_801F69A8;
    }
    // 0x801F699C: addiu       $t1, $t1, -0x5018
    ctx->r9 = ADD32(ctx->r9, -0X5018);
    // 0x801F69A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801F69A4: sh          $t9, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r25;
L_801F69A8:
    // 0x801F69A8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801F69AC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801F69B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F69B4: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801F69B8: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x801F69BC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F69C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F69C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F69C8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801F69CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801F69D0: jal         0x8012CE9C
    // 0x801F69D4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_10;
    // 0x801F69D4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x801F69D8: bne         $v0, $zero, L_801F6A28
    if (ctx->r2 != 0) {
        // 0x801F69DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6A28;
    }
    // 0x801F69DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F69E0: jal         0x801F42E4
    // 0x801F69E4: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    LOOKUP_FUNC(0x801F42E4)(rdram, ctx);
        goto after_11;
    // 0x801F69E4: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    after_11:
    // 0x801F69E8: lh          $t5, 0x94($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X94);
    // 0x801F69EC: lh          $t6, 0x96($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X96);
    // 0x801F69F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F69F4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801F69F8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801F69FC: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6A00: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F6A04: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F6A08: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F6A0C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801F6A10: jal         0x801F474C
    // 0x801F6A14: nop

    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_12;
    // 0x801F6A14: nop

    after_12:
    // 0x801F6A18: sb          $zero, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = 0;
L_801F6A1C:
    // 0x801F6A1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6A20: jal         0x80010550
    // 0x801F6A24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_13;
    // 0x801F6A24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
L_801F6A28:
    // 0x801F6A28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6A2C:
    // 0x801F6A2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6A34: jr          $ra
    // 0x801F6A38: nop

    return;
    // 0x801F6A38: nop

;}
RECOMP_FUNC void M9_FUN_801f6a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6A3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6A40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6A44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6A48: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6A4C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6A54: jal         0x801C3B3C
    // 0x801F6A58: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F6A58: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6A5C: bne         $v0, $zero, L_801F6AC8
    if (ctx->r2 != 0) {
        // 0x801F6A60: nop
    
            goto L_801F6AC8;
    }
    // 0x801F6A60: nop

    // 0x801F6A64: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6A6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6A70: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F6A74: bgez        $t7, L_801F6A88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F6A78: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6A88;
    }
    // 0x801F6A78: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6A7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6A80: nop

    // 0x801F6A84: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6A88:
    // 0x801F6A88: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6A8C: jal         0x801F3FFC
    // 0x801F6A90: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6A90: nop

    after_1:
    // 0x801F6A94: beq         $v0, $zero, L_801F6AC8
    if (ctx->r2 == 0) {
        // 0x801F6A98: nop
    
            goto L_801F6AC8;
    }
    // 0x801F6A98: nop

    // 0x801F6A9C: jal         0x801F53E8
    // 0x801F6AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F6AA4: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6AA8: jal         0x801F5230
    // 0x801F6AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F6AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6AB0: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6AB4: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6AB8: jal         0x800058DC
    // 0x801F6ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F6ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F6AC0: b           L_801F6C48
    // 0x801F6AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6C48;
    // 0x801F6AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6AC8:
    // 0x801F6AC8: jal         0x801F55EC
    // 0x801F6ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_5;
    // 0x801F6ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F6AD0: beql        $v0, $zero, L_801F6C48
    if (ctx->r2 == 0) {
        // 0x801F6AD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F6C48;
    }
    goto skip_0;
    // 0x801F6AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F6AD8: lbu         $t8, 0x9C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9C);
    // 0x801F6ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6AE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6AE4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801F6AE8: bgez        $t8, L_801F6AFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801F6AEC: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F6AFC;
    }
    // 0x801F6AEC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F6AF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F6AF4: nop

    // 0x801F6AF8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801F6AFC:
    // 0x801F6AFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801F6B00: jal         0x801F4514
    // 0x801F6B04: nop

    LOOKUP_FUNC(0x801F4514)(rdram, ctx);
        goto after_6;
    // 0x801F6B04: nop

    after_6:
    // 0x801F6B08: beq         $v0, $zero, L_801F6BA8
    if (ctx->r2 == 0) {
        // 0x801F6B0C: lui         $t1, 0x8022
        ctx->r9 = S32(0X8022 << 16);
            goto L_801F6BA8;
    }
    // 0x801F6B0C: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x801F6B10: lbu         $t9, 0x9D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9D);
    // 0x801F6B14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F6B18: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6B1C: bne         $t9, $zero, L_801F6B2C
    if (ctx->r25 != 0) {
        // 0x801F6B20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6B2C;
    }
    // 0x801F6B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6B24: jal         0x801F3B6C
    // 0x801F6B28: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x801F3B6C)(rdram, ctx);
        goto after_7;
    // 0x801F6B28: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    after_7:
L_801F6B2C:
    // 0x801F6B2C: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x801F6B30: addiu       $t2, $t2, -0x5008
    ctx->r10 = ADD32(ctx->r10, -0X5008);
    // 0x801F6B34: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801F6B38: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801F6B3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6B40: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x801F6B44: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x801F6B48: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6B50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F6B54: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801F6B58: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801F6B5C: jal         0x8012CE9C
    // 0x801F6B60: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_8;
    // 0x801F6B60: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x801F6B64: bne         $v0, $zero, L_801F6C44
    if (ctx->r2 != 0) {
        // 0x801F6B68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6C44;
    }
    // 0x801F6B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6B6C: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6B70: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F6B74: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F6B78: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x801F6B7C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x801F6B80: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F6B84: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x801F6B88: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801F6B8C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801F6B90: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F6B94: jal         0x801F474C
    // 0x801F6B98: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_9;
    // 0x801F6B98: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_9:
    // 0x801F6B9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6BA0: b           L_801F6C38
    // 0x801F6BA4: sb          $t7, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r15;
        goto L_801F6C38;
    // 0x801F6BA4: sb          $t7, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r15;
L_801F6BA8:
    // 0x801F6BA8: lbu         $t8, 0x9D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9D);
    // 0x801F6BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F6BB0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6BB4: bne         $t8, $at, L_801F6BC4
    if (ctx->r24 != ctx->r1) {
        // 0x801F6BB8: addiu       $t1, $t1, -0x5018
        ctx->r9 = ADD32(ctx->r9, -0X5018);
            goto L_801F6BC4;
    }
    // 0x801F6BB8: addiu       $t1, $t1, -0x5018
    ctx->r9 = ADD32(ctx->r9, -0X5018);
    // 0x801F6BBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801F6BC0: sh          $t9, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r25;
L_801F6BC4:
    // 0x801F6BC4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801F6BC8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801F6BCC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6BD0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801F6BD4: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x801F6BD8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6BDC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6BE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F6BE4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801F6BE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801F6BEC: jal         0x8012CE9C
    // 0x801F6BF0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_10;
    // 0x801F6BF0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x801F6BF4: bne         $v0, $zero, L_801F6C44
    if (ctx->r2 != 0) {
        // 0x801F6BF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6C44;
    }
    // 0x801F6BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6BFC: jal         0x801F42E4
    // 0x801F6C00: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    LOOKUP_FUNC(0x801F42E4)(rdram, ctx);
        goto after_11;
    // 0x801F6C00: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    after_11:
    // 0x801F6C04: lh          $t5, 0x94($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X94);
    // 0x801F6C08: lh          $t6, 0x96($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X96);
    // 0x801F6C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6C10: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801F6C14: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801F6C18: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6C1C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F6C20: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F6C24: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801F6C28: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801F6C2C: jal         0x801F474C
    // 0x801F6C30: nop

    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_12;
    // 0x801F6C30: nop

    after_12:
    // 0x801F6C34: sb          $zero, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = 0;
L_801F6C38:
    // 0x801F6C38: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6C3C: jal         0x80010550
    // 0x801F6C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_13;
    // 0x801F6C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
L_801F6C44:
    // 0x801F6C44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6C48:
    // 0x801F6C48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6C4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6C50: jr          $ra
    // 0x801F6C54: nop

    return;
    // 0x801F6C54: nop

;}
RECOMP_FUNC void M9_FUN_801f6c58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6C58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6C5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6C60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6C64: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6C68: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6C6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6C70: jal         0x801F4A48
    // 0x801F6C74: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801F4A48)(rdram, ctx);
        goto after_0;
    // 0x801F6C74: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6C78: jal         0x801F55EC
    // 0x801F6C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_1;
    // 0x801F6C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F6C80: bne         $v0, $zero, L_801F6CB4
    if (ctx->r2 != 0) {
        // 0x801F6C84: nop
    
            goto L_801F6CB4;
    }
    // 0x801F6C84: nop

    // 0x801F6C88: lbu         $t7, 0x93($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X93);
    // 0x801F6C8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F6C90: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6C94: beq         $t7, $zero, L_801F6CB4
    if (ctx->r15 == 0) {
        // 0x801F6C98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6CB4;
    }
    // 0x801F6C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6C9C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6CA0: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    // 0x801F6CA4: jal         0x800058DC
    // 0x801F6CA8: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F6CA8: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    after_2:
    // 0x801F6CAC: b           L_801F6E3C
    // 0x801F6CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6E3C;
    // 0x801F6CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6CB4:
    // 0x801F6CB4: jal         0x801F5630
    // 0x801F6CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5630)(rdram, ctx);
        goto after_3;
    // 0x801F6CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6CBC: beq         $v0, $zero, L_801F6CF4
    if (ctx->r2 == 0) {
        // 0x801F6CC0: nop
    
            goto L_801F6CF4;
    }
    // 0x801F6CC0: nop

    // 0x801F6CC4: jal         0x801F55EC
    // 0x801F6CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_4;
    // 0x801F6CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F6CCC: beq         $v0, $zero, L_801F6CF4
    if (ctx->r2 == 0) {
        // 0x801F6CD0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801F6CF4;
    }
    // 0x801F6CD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F6CD4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6CD8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6CDC: addiu       $a1, $a1, 0x74FC
    ctx->r5 = ADD32(ctx->r5, 0X74FC);
    // 0x801F6CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6CE4: jal         0x800058DC
    // 0x801F6CE8: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F6CE8: sh          $t0, 0x78($t1)
    MEM_H(0X78, ctx->r9) = ctx->r8;
    after_5:
    // 0x801F6CEC: b           L_801F6E3C
    // 0x801F6CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6E3C;
    // 0x801F6CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6CF4:
    // 0x801F6CF4: jal         0x801C3B3C
    // 0x801F6CF8: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_6;
    // 0x801F6CF8: nop

    after_6:
    // 0x801F6CFC: bne         $v0, $zero, L_801F6D68
    if (ctx->r2 != 0) {
        // 0x801F6D00: nop
    
            goto L_801F6D68;
    }
    // 0x801F6D00: nop

    // 0x801F6D04: lbu         $t2, 0xAE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6D0C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6D10: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801F6D14: bgez        $t2, L_801F6D28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801F6D18: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6D28;
    }
    // 0x801F6D18: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6D1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6D20: nop

    // 0x801F6D24: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6D28:
    // 0x801F6D28: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6D2C: jal         0x801F3FFC
    // 0x801F6D30: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_7;
    // 0x801F6D30: nop

    after_7:
    // 0x801F6D34: beq         $v0, $zero, L_801F6D68
    if (ctx->r2 == 0) {
        // 0x801F6D38: nop
    
            goto L_801F6D68;
    }
    // 0x801F6D38: nop

    // 0x801F6D3C: jal         0x801F53E8
    // 0x801F6D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_8;
    // 0x801F6D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801F6D44: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6D48: jal         0x801F5230
    // 0x801F6D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_9;
    // 0x801F6D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801F6D50: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6D54: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6D58: jal         0x800058DC
    // 0x801F6D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801F6D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801F6D60: b           L_801F6E3C
    // 0x801F6D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6E3C;
    // 0x801F6D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6D68:
    // 0x801F6D68: jal         0x801F55EC
    // 0x801F6D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_11;
    // 0x801F6D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801F6D70: beq         $v0, $zero, L_801F6E38
    if (ctx->r2 == 0) {
        // 0x801F6D74: lui         $t3, 0x8022
        ctx->r11 = S32(0X8022 << 16);
            goto L_801F6E38;
    }
    // 0x801F6D74: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x801F6D78: addiu       $t3, $t3, -0x5018
    ctx->r11 = ADD32(ctx->r11, -0X5018);
    // 0x801F6D7C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801F6D80: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801F6D84: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6D88: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x801F6D8C: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x801F6D90: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6D94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6D98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F6D9C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801F6DA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801F6DA4: jal         0x8012CE9C
    // 0x801F6DA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_12;
    // 0x801F6DA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_12:
    // 0x801F6DAC: bne         $v0, $zero, L_801F6E38
    if (ctx->r2 != 0) {
        // 0x801F6DB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6E38;
    }
    // 0x801F6DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6DB4: jal         0x801F42E4
    // 0x801F6DB8: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    LOOKUP_FUNC(0x801F42E4)(rdram, ctx);
        goto after_13;
    // 0x801F6DB8: lhu         $a1, 0x9A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X9A);
    after_13:
    // 0x801F6DBC: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F6DC0: blez        $v0, L_801F6DD0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801F6DC4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_801F6DD0;
    }
    // 0x801F6DC4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801F6DC8: b           L_801F6E2C
    // 0x801F6DCC: sh          $t7, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r15;
        goto L_801F6E2C;
    // 0x801F6DCC: sh          $t7, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r15;
L_801F6DD0:
    // 0x801F6DD0: lbu         $t8, 0x93($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X93);
    // 0x801F6DD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801F6DD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6DDC: beq         $t8, $zero, L_801F6DFC
    if (ctx->r24 == 0) {
        // 0x801F6DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6DFC;
    }
    // 0x801F6DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6DE4: jal         0x801F3B6C
    // 0x801F6DE8: sh          $t9, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r25;
    LOOKUP_FUNC(0x801F3B6C)(rdram, ctx);
        goto after_14;
    // 0x801F6DE8: sh          $t9, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r25;
    after_14:
    // 0x801F6DEC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6DF0: addiu       $a1, $a1, 0x6E4C
    ctx->r5 = ADD32(ctx->r5, 0X6E4C);
    // 0x801F6DF4: jal         0x800058DC
    // 0x801F6DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801F6DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_801F6DFC:
    // 0x801F6DFC: lh          $t1, 0x94($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X94);
    // 0x801F6E00: lh          $t2, 0x96($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X96);
    // 0x801F6E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6E08: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801F6E0C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801F6E10: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F6E14: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F6E18: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801F6E1C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801F6E20: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801F6E24: jal         0x801F474C
    // 0x801F6E28: nop

    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_16;
    // 0x801F6E28: nop

    after_16:
L_801F6E2C:
    // 0x801F6E2C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6E30: jal         0x80010550
    // 0x801F6E34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_17;
    // 0x801F6E34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
L_801F6E38:
    // 0x801F6E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6E3C:
    // 0x801F6E3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6E40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6E44: jr          $ra
    // 0x801F6E48: nop

    return;
    // 0x801F6E48: nop

;}
RECOMP_FUNC void M9_FUN_801f6e4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6E4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6E50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6E54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6E58: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6E5C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6E60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6E64: jal         0x801C3B3C
    // 0x801F6E68: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F6E68: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6E6C: bnel        $v0, $zero, L_801F6EDC
    if (ctx->r2 != 0) {
        // 0x801F6E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6EDC;
    }
    goto skip_0;
    // 0x801F6E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801F6E74: lbu         $t7, 0xAE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6E7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6E80: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F6E84: bgez        $t7, L_801F6E98
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F6E88: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6E98;
    }
    // 0x801F6E88: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6E8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6E90: nop

    // 0x801F6E94: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6E98:
    // 0x801F6E98: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6E9C: jal         0x801F3FFC
    // 0x801F6EA0: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F6EA0: nop

    after_1:
    // 0x801F6EA4: beql        $v0, $zero, L_801F6EDC
    if (ctx->r2 == 0) {
        // 0x801F6EA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F6EDC;
    }
    goto skip_1;
    // 0x801F6EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801F6EAC: jal         0x801F53E8
    // 0x801F6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_2;
    // 0x801F6EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F6EB4: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6EB8: jal         0x801F5230
    // 0x801F6EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_3;
    // 0x801F6EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F6EC0: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6EC4: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F6EC8: jal         0x800058DC
    // 0x801F6ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F6ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F6ED0: b           L_801F6F40
    // 0x801F6ED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F6F40;
    // 0x801F6ED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F6ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801F6EDC:
    // 0x801F6EDC: jal         0x8012A94C
    // 0x801F6EE0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_5;
    // 0x801F6EE0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_5:
    // 0x801F6EE4: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x801F6EE8: addiu       $t8, $t8, -0x4FE8
    ctx->r24 = ADD32(ctx->r24, -0X4FE8);
    // 0x801F6EEC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F6EF0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x801F6EF4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F6EF8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801F6EFC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801F6F00: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F6F04: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6F08: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F6F0C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801F6F10: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F6F14: jal         0x8012CE9C
    // 0x801F6F18: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_6;
    // 0x801F6F18: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x801F6F1C: bne         $v0, $zero, L_801F6F3C
    if (ctx->r2 != 0) {
        // 0x801F6F20: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801F6F3C;
    }
    // 0x801F6F20: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F6F24: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6F28: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6F2C: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    // 0x801F6F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6F34: jal         0x800058DC
    // 0x801F6F38: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F6F38: sh          $t2, 0x78($t3)
    MEM_H(0X78, ctx->r11) = ctx->r10;
    after_7:
L_801F6F3C:
    // 0x801F6F3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6F40:
    // 0x801F6F40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F6F44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F6F48: jr          $ra
    // 0x801F6F4C: nop

    return;
    // 0x801F6F4C: nop

;}
RECOMP_FUNC void M9_FUN_801f6f50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F6F50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F6F54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F6F58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F6F5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F6F60: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F6F64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F6F68: jal         0x801F5630
    // 0x801F6F6C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801F5630)(rdram, ctx);
        goto after_0;
    // 0x801F6F6C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F6F70: beq         $v0, $zero, L_801F6FA8
    if (ctx->r2 == 0) {
        // 0x801F6F74: nop
    
            goto L_801F6FA8;
    }
    // 0x801F6F74: nop

    // 0x801F6F78: jal         0x801F55EC
    // 0x801F6F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_1;
    // 0x801F6F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F6F80: beq         $v0, $zero, L_801F6FA8
    if (ctx->r2 == 0) {
        // 0x801F6F84: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F6FA8;
    }
    // 0x801F6F84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F6F88: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801F6F8C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F6F90: addiu       $a1, $a1, 0x74FC
    ctx->r5 = ADD32(ctx->r5, 0X74FC);
    // 0x801F6F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6F98: jal         0x800058DC
    // 0x801F6F9C: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F6F9C: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    after_2:
    // 0x801F6FA0: b           L_801F70D0
    // 0x801F6FA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F70D0;
    // 0x801F6FA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F6FA8:
    // 0x801F6FA8: jal         0x801C3B3C
    // 0x801F6FAC: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_3;
    // 0x801F6FAC: nop

    after_3:
    // 0x801F6FB0: bne         $v0, $zero, L_801F701C
    if (ctx->r2 != 0) {
        // 0x801F6FB4: nop
    
            goto L_801F701C;
    }
    // 0x801F6FB4: nop

    // 0x801F6FB8: lbu         $t9, 0xAE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F6FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F6FC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F6FC4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801F6FC8: bgez        $t9, L_801F6FDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801F6FCC: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F6FDC;
    }
    // 0x801F6FCC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F6FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F6FD4: nop

    // 0x801F6FD8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F6FDC:
    // 0x801F6FDC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F6FE0: jal         0x801F3FFC
    // 0x801F6FE4: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_4;
    // 0x801F6FE4: nop

    after_4:
    // 0x801F6FE8: beq         $v0, $zero, L_801F701C
    if (ctx->r2 == 0) {
        // 0x801F6FEC: nop
    
            goto L_801F701C;
    }
    // 0x801F6FEC: nop

    // 0x801F6FF0: jal         0x801F53E8
    // 0x801F6FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53E8)(rdram, ctx);
        goto after_5;
    // 0x801F6FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F6FF8: sb          $v0, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r2;
    // 0x801F6FFC: jal         0x801F5230
    // 0x801F7000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_6;
    // 0x801F7000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F7004: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7008: addiu       $a1, $a1, 0x70E0
    ctx->r5 = ADD32(ctx->r5, 0X70E0);
    // 0x801F700C: jal         0x800058DC
    // 0x801F7010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F7010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801F7014: b           L_801F70D0
    // 0x801F7018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801F70D0;
    // 0x801F7018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F701C:
    // 0x801F701C: jal         0x801F55EC
    // 0x801F7020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F55EC)(rdram, ctx);
        goto after_8;
    // 0x801F7020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801F7024: beq         $v0, $zero, L_801F70CC
    if (ctx->r2 == 0) {
        // 0x801F7028: lui         $t0, 0x8022
        ctx->r8 = S32(0X8022 << 16);
            goto L_801F70CC;
    }
    // 0x801F7028: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x801F702C: addiu       $t0, $t0, -0x5008
    ctx->r8 = ADD32(ctx->r8, -0X5008);
    // 0x801F7030: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801F7034: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801F7038: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F703C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801F7040: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x801F7044: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F7048: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801F704C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F7050: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801F7054: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801F7058: jal         0x8012CE9C
    // 0x801F705C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_9;
    // 0x801F705C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_9:
    // 0x801F7060: bnel        $v0, $zero, L_801F70D0
    if (ctx->r2 != 0) {
        // 0x801F7064: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F70D0;
    }
    goto skip_0;
    // 0x801F7064: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F7068: jal         0x801F4A48
    // 0x801F706C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F4A48)(rdram, ctx);
        goto after_10;
    // 0x801F706C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801F7070: lbu         $t4, 0x93($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X93);
    // 0x801F7074: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801F7078: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801F707C: bne         $t4, $zero, L_801F7094
    if (ctx->r12 != 0) {
        // 0x801F7080: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F7094;
    }
    // 0x801F7080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F7084: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7088: sh          $t5, 0x78($t6)
    MEM_H(0X78, ctx->r14) = ctx->r13;
    // 0x801F708C: jal         0x800058DC
    // 0x801F7090: addiu       $a1, $a1, 0x6C58
    ctx->r5 = ADD32(ctx->r5, 0X6C58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801F7090: addiu       $a1, $a1, 0x6C58
    ctx->r5 = ADD32(ctx->r5, 0X6C58);
    after_11:
L_801F7094:
    // 0x801F7094: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F7098: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F709C: lh          $a1, 0x90($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X90);
    // 0x801F70A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F70A4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801F70A8: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x801F70AC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801F70B0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801F70B4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F70B8: jal         0x801F474C
    // 0x801F70BC: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F474C)(rdram, ctx);
        goto after_12;
    // 0x801F70BC: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_12:
    // 0x801F70C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F70C4: jal         0x80010550
    // 0x801F70C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_13;
    // 0x801F70C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
L_801F70CC:
    // 0x801F70CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F70D0:
    // 0x801F70D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F70D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F70D8: jr          $ra
    // 0x801F70DC: nop

    return;
    // 0x801F70DC: nop

;}
RECOMP_FUNC void M9_FUN_801f70e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F70E0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801F70E4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801F70E8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801F70EC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801F70F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801F70F4: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F70F8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x801F70FC: jal         0x8013A334
    // 0x801F7100: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F7100: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x801F7104: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F7108: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F710C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7110: lwc1        $f0, -0x7340($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7340);
    // 0x801F7114: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F7118: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801F711C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F7120: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F7124: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x801F7128: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801F712C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F7130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F7134: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801F7138: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801F713C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F7140: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F7144: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801F7148: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x801F714C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F7150: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801F7154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801F7158: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F715C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801F7160: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F7164: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801F7168: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801F716C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F7170: jal         0x801F3C90
    // 0x801F7174: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_1;
    // 0x801F7174: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801F7178: beql        $v0, $zero, L_801F73E0
    if (ctx->r2 == 0) {
        // 0x801F717C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801F73E0;
    }
    goto skip_0;
    // 0x801F717C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801F7180: lbu         $a0, 0xAF($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XAF);
    // 0x801F7184: beq         $a0, $zero, L_801F719C
    if (ctx->r4 == 0) {
        // 0x801F7188: nop
    
            goto L_801F719C;
    }
    // 0x801F7188: nop

    // 0x801F718C: jal         0x801FA374
    // 0x801F7190: nop

    LOOKUP_FUNC(0x801FA374)(rdram, ctx);
        goto after_2;
    // 0x801F7190: nop

    after_2:
    // 0x801F7194: b           L_801F71A4
    // 0x801F7198: nop

        goto L_801F71A4;
    // 0x801F7198: nop

L_801F719C:
    // 0x801F719C: jal         0x801FA2E0
    // 0x801F71A0: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_3;
    // 0x801F71A0: nop

    after_3:
L_801F71A4:
    // 0x801F71A4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F71A8: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F71AC: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x801F71B0: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x801F71B4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F71B8: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801F71BC: addiu       $s0, $s0, -0x4FD8
    ctx->r16 = ADD32(ctx->r16, -0X4FD8);
    // 0x801F71C0: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x801F71C4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F71C8: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x801F71CC: lw          $a3, 0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC);
    // 0x801F71D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F71D4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F71D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F71DC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F71E0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F71E4: jal         0x801F4620
    // 0x801F71E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_4;
    // 0x801F71E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x801F71EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F71F0: jal         0x80147768
    // 0x801F71F4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_5;
    // 0x801F71F4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_5:
    // 0x801F71F8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801F71FC: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x801F7200: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801F7204: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x801F7208: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801F720C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x801F7210: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801F7214: jal         0x8012C6B4
    // 0x801F7218: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801F7218: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    after_6:
    // 0x801F721C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x801F7220: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x801F7224: sll         $a1, $t0, 24
    ctx->r5 = S32(ctx->r8 << 24);
    // 0x801F7228: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801F722C: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x801F7230: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x801F7234: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x801F7238: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x801F723C: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x801F7240: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x801F7244: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x801F7248: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x801F724C: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x801F7250: addiu       $t4, $t4, -0x4FD0
    ctx->r12 = ADD32(ctx->r12, -0X4FD0);
    // 0x801F7254: addiu       $t3, $t3, -0x4FD4
    ctx->r11 = ADD32(ctx->r11, -0X4FD4);
    // 0x801F7258: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x801F725C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801F7260: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801F7264: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801F7268: sb          $t0, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r8;
    // 0x801F726C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7274: jal         0x80130AA0
    // 0x801F7278: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_7;
    // 0x801F7278: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_7:
    // 0x801F727C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801F7280: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801F7284: lw          $v0, 0xE0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE0);
    // 0x801F7288: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801F728C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F7290: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x801F7294: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F7298: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F729C: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x801F72A0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801F72A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F72A8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801F72AC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x801F72B0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801F72B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F72B8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x801F72BC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801F72C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F72C4: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F72C8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801F72CC: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x801F72D0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F72D4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801F72D8: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801F72DC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801F72E0: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801F72E4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801F72E8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801F72EC: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F72F0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801F72F4: lwc1        $f12, 0x30($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801F72F8: lwc1        $f14, 0x34($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801F72FC: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    // 0x801F7300: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801F7304: jal         0x8010843C
    // 0x801F7308: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_8;
    // 0x801F7308: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x801F730C: beq         $v0, $zero, L_801F73CC
    if (ctx->r2 == 0) {
        // 0x801F7310: lb          $t0, 0x4A($sp)
        ctx->r8 = MEM_B(ctx->r29, 0X4A);
            goto L_801F73CC;
    }
    // 0x801F7310: lb          $t0, 0x4A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4A);
    // 0x801F7314: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x801F7318: sll         $t0, $t0, 24
    ctx->r8 = S32(ctx->r8 << 24);
    // 0x801F731C: sra         $t0, $t0, 24
    ctx->r8 = S32(SIGNED(ctx->r8) >> 24);
    // 0x801F7320: sll         $a1, $t0, 3
    ctx->r5 = S32(ctx->r8 << 3);
    // 0x801F7324: subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // 0x801F7328: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x801F732C: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x801F7330: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x801F7334: subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // 0x801F7338: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x801F733C: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x801F7340: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x801F7344: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F7348: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801F734C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801F7350: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7358: jal         0x80130AA0
    // 0x801F735C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_9;
    // 0x801F735C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_9:
    // 0x801F7360: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801F7364: lw          $v0, -0x4330($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4330);
    // 0x801F7368: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F736C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F7370: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x801F7374: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F7378: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F737C: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x801F7380: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F7384: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F7388: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x801F738C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801F7390: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801F7394: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801F7398: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801F739C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801F73A0: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x801F73A4: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F73A8: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x801F73AC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801F73B0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x801F73B4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801F73B8: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x801F73BC: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801F73C0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801F73C4: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x801F73C8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_801F73CC:
    // 0x801F73CC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F73D0: addiu       $a1, $a1, 0x73F0
    ctx->r5 = ADD32(ctx->r5, 0X73F0);
    // 0x801F73D4: jal         0x800058DC
    // 0x801F73D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801F73D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x801F73DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801F73E0:
    // 0x801F73E0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801F73E4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801F73E8: jr          $ra
    // 0x801F73EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801F73EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f73f0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f73f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F73F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801F73F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801F73F8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801F73FC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801F7400: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F7404: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F7408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F740C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x801F7410: lbu         $t7, 0xAF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAF);
    // 0x801F7414: beql        $t7, $at, L_801F7460
    if (ctx->r15 == ctx->r1) {
        // 0x801F7418: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_801F7460;
    }
    goto skip_0;
    // 0x801F7418: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    skip_0:
    // 0x801F741C: jal         0x8012A94C
    // 0x801F7420: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_0;
    // 0x801F7420: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_0:
    // 0x801F7424: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x801F7428: addiu       $t8, $t8, 0x6EE8
    ctx->r24 = ADD32(ctx->r24, 0X6EE8);
    // 0x801F742C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F7430: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801F7434: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801F7438: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x801F743C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x801F7440: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F7444: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x801F7448: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F744C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801F7450: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F7454: jal         0x8012CE9C
    // 0x801F7458: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_1;
    // 0x801F7458: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x801F745C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_801F7460:
    // 0x801F7460: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x801F7464: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801F7468: jal         0x8013A334
    // 0x801F746C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801F746C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x801F7470: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7474: lwc1        $f0, -0x733C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X733C);
    // 0x801F7478: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x801F747C: addiu       $v1, $v1, -0x4FD8
    ctx->r3 = ADD32(ctx->r3, -0X4FD8);
    // 0x801F7480: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801F7484: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F7488: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F748C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F7490: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801F7494: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801F7498: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801F749C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x801F74A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F74A4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801F74A8: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x801F74AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F74B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801F74B4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F74B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801F74BC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801F74C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801F74C4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801F74C8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801F74CC: jal         0x801F3C90
    // 0x801F74D0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_3;
    // 0x801F74D0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801F74D4: beq         $v0, $zero, L_801F74E8
    if (ctx->r2 == 0) {
        // 0x801F74D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F74E8;
    }
    // 0x801F74D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F74DC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F74E0: jal         0x800058DC
    // 0x801F74E4: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F74E4: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    after_4:
L_801F74E8:
    // 0x801F74E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801F74EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801F74F0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801F74F4: jr          $ra
    // 0x801F74F8: nop

    return;
    // 0x801F74F8: nop

;}
RECOMP_FUNC void M9_FUN_801f74fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F74FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7500: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801F7504: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7508: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F750C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F7510: addiu       $t7, $t7, 0x6EB8
    ctx->r15 = ADD32(ctx->r15, 0X6EB8);
    // 0x801F7514: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801F7518: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801F751C: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801F7520: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801F7524: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x801F7528: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F752C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801F7530: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F7534: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801F7538: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801F753C: jal         0x8012CE9C
    // 0x801F7540: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801F7540: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801F7544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F754C: jr          $ra
    // 0x801F7550: nop

    return;
    // 0x801F7550: nop

;}
RECOMP_FUNC void M9_FUN_801f7554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7554: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F7558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F755C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F7560: jal         0x80150584
    // 0x801F7564: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x801F7564: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F7568: beql        $v0, $zero, L_801F75A4
    if (ctx->r2 == 0) {
        // 0x801F756C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F75A4;
    }
    goto skip_0;
    // 0x801F756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F7570: jal         0x80150614
    // 0x801F7574: nop

    LOOKUP_FUNC(0x80150614)(rdram, ctx);
        goto after_1;
    // 0x801F7574: nop

    after_1:
    // 0x801F7578: jal         0x801505E4
    // 0x801F757C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x801505E4)(rdram, ctx);
        goto after_2;
    // 0x801F757C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x801F7580: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x801F7584: jal         0x8015067C
    // 0x801F7588: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x8015067C)(rdram, ctx);
        goto after_3;
    // 0x801F7588: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    after_3:
    // 0x801F758C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x801F7590: beq         $t6, $zero, L_801F75A0
    if (ctx->r14 == 0) {
        // 0x801F7594: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_801F75A0;
    }
    // 0x801F7594: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801F7598: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801F759C: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
L_801F75A0:
    // 0x801F75A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F75A4:
    // 0x801F75A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F75A8: jr          $ra
    // 0x801F75AC: nop

    return;
    // 0x801F75AC: nop

;}
RECOMP_FUNC void M9_FUN_801f75b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F75B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F75B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F75B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F75BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F75C0: jal         0x801C3B3C
    // 0x801F75C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F75C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F75C8: bnel        $v0, $zero, L_801F7628
    if (ctx->r2 != 0) {
        // 0x801F75CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F7628;
    }
    goto skip_0;
    // 0x801F75CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801F75D0: lbu         $t6, 0xAE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F75D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F75D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F75DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F75E0: bgez        $t6, L_801F75F4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F75E4: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F75F4;
    }
    // 0x801F75E4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F75E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F75EC: nop

    // 0x801F75F0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F75F4:
    // 0x801F75F4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F75F8: jal         0x801F3FFC
    // 0x801F75FC: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F75FC: nop

    after_1:
    // 0x801F7600: beql        $v0, $zero, L_801F7628
    if (ctx->r2 == 0) {
        // 0x801F7604: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F7628;
    }
    goto skip_1;
    // 0x801F7604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801F7608: jal         0x801F5230
    // 0x801F760C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F760C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F7610: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7614: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x801F7618: addiu       $a1, $a1, 0x7638
    ctx->r5 = ADD32(ctx->r5, 0X7638);
    // 0x801F761C: jal         0x800058DC
    // 0x801F7620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801F7620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F7624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F7628:
    // 0x801F7628: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F762C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F7630: jr          $ra
    // 0x801F7634: nop

    return;
    // 0x801F7634: nop

;}
RECOMP_FUNC void M9_FUN_801f7638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7638: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801F763C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801F7640: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801F7644: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801F7648: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801F764C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F7650: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F7654: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x801F7658: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x801F765C: lh          $t7, 0x90($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X90);
    // 0x801F7660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F7668: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x801F766C: sh          $t8, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r24;
    // 0x801F7670: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x801F7674: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x801F7678: bnel        $at, $zero, L_801F768C
    if (ctx->r1 != 0) {
        // 0x801F767C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801F768C;
    }
    goto skip_0;
    // 0x801F767C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x801F7680: sh          $t9, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r25;
    // 0x801F7684: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x801F7688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801F768C:
    // 0x801F768C: jal         0x80147AF0
    // 0x801F7690: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_0;
    // 0x801F7690: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_0:
    // 0x801F7694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7698: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801F769C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801F76A0: jal         0x80147AA8
    // 0x801F76A4: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_1;
    // 0x801F76A4: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_1:
    // 0x801F76A8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x801F76AC: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x801F76B0: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x801F76B4: jal         0x8013A334
    // 0x801F76B8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801F76B8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x801F76BC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801F76C0: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x801F76C4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F76C8: lwc1        $f0, -0x7338($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7338);
    // 0x801F76CC: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801F76D0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801F76D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F76D8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F76DC: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x801F76E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801F76E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F76E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F76EC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801F76F0: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801F76F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F76F8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F76FC: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801F7700: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801F7704: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F7708: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801F770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F7710: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F7714: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801F7718: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F771C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801F7720: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801F7724: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F7728: jal         0x801F3C90
    // 0x801F772C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_3;
    // 0x801F772C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801F7730: beq         $v0, $zero, L_801F7914
    if (ctx->r2 == 0) {
        // 0x801F7734: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_801F7914;
    }
    // 0x801F7734: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x801F7738: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801F773C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801F7740: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F7744: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801F7748: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801F774C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801F7750: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801F7754: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801F7758: jal         0x801F4620
    // 0x801F775C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_4;
    // 0x801F775C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x801F7760: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801F7764: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x801F7768: addiu       $t4, $sp, 0x7C
    ctx->r12 = ADD32(ctx->r29, 0X7C);
    // 0x801F776C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F7770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7778: lhu         $a1, 0x12($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X12);
    // 0x801F777C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801F7780: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801F7784: jal         0x80130AA0
    // 0x801F7788: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_5;
    // 0x801F7788: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_5:
    // 0x801F778C: addiu       $t5, $sp, 0x78
    ctx->r13 = ADD32(ctx->r29, 0X78);
    // 0x801F7790: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x801F7794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801F7798: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801F779C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F77A0: addiu       $a1, $zero, 0x31C
    ctx->r5 = ADD32(0, 0X31C);
    // 0x801F77A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F77A8: jal         0x80130AA0
    // 0x801F77AC: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_6;
    // 0x801F77AC: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_6:
    // 0x801F77B0: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801F77B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801F77B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F77BC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801F77C0: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F77C4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F77C8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F77CC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F77D0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801F77D4: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F77D8: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801F77DC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F77E0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801F77E4: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x801F77E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801F77EC: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x801F77F0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801F77F4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801F77F8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F77FC: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801F7800: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F7804: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x801F7808: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801F780C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801F7810: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801F7814: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F7818: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F781C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F7820: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F7824: jal         0x801F4620
    // 0x801F7828: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_7;
    // 0x801F7828: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x801F782C: addiu       $t1, $sp, 0x6C
    ctx->r9 = ADD32(ctx->r29, 0X6C);
    // 0x801F7830: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x801F7834: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801F7838: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F783C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7840: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x801F7844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7848: jal         0x80130AA0
    // 0x801F784C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_8;
    // 0x801F784C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_8:
    // 0x801F7850: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801F7854: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801F7858: jal         0x80147734
    // 0x801F785C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80147734)(rdram, ctx);
        goto after_9;
    // 0x801F785C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_9:
    // 0x801F7860: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F7864: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F7868: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F786C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F7870: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F7874: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F7878: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801F787C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801F7880: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801F7884: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F7888: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801F788C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801F7890: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801F7894: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F7898: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F789C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F78A0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F78A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801F78A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801F78AC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801F78B0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801F78B4: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801F78B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801F78BC: addiu       $a0, $a0, -0x76A8
    ctx->r4 = ADD32(ctx->r4, -0X76A8);
    // 0x801F78C0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801F78C4: addiu       $a1, $zero, 0x6CF
    ctx->r5 = ADD32(0, 0X6CF);
    // 0x801F78C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F78CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F78D0: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x801F78D4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F78D8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F78DC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801F78E0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801F78E4: jal         0x8011AAF4
    // 0x801F78E8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_10;
    // 0x801F78E8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x801F78EC: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x801F78F0: addiu       $a1, $a1, 0x6E68
    ctx->r5 = ADD32(ctx->r5, 0X6E68);
    // 0x801F78F4: jal         0x80005670
    // 0x801F78F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_11;
    // 0x801F78F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801F78FC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7900: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7904: sw          $v0, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = ctx->r2;
    // 0x801F7908: addiu       $a1, $a1, 0x7928
    ctx->r5 = ADD32(ctx->r5, 0X7928);
    // 0x801F790C: jal         0x800058DC
    // 0x801F7910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x801F7910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_801F7914:
    // 0x801F7914: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801F7918: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801F791C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801F7920: jr          $ra
    // 0x801F7924: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801F7924: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f7928(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f7928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7928: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801F792C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801F7930: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801F7934: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801F7938: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F793C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F7940: lwc1        $f4, 0x50($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X50);
    // 0x801F7944: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7948: ldc1        $f8, -0x7330($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X7330);
    // 0x801F794C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F7950: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7954: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801F7958: ldc1        $f16, -0x7328($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X7328);
    // 0x801F795C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F7960: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801F7964: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F7968: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F796C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801F7970: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801F7974: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801F7978: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F797C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801F7980: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F7984: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F7988: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F798C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801F7990: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801F7994: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F7998: addiu       $a0, $a0, -0x766C
    ctx->r4 = ADD32(ctx->r4, -0X766C);
    // 0x801F799C: addiu       $a1, $zero, 0x6DD
    ctx->r5 = ADD32(0, 0X6DD);
    // 0x801F79A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F79A4: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x801F79A8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801F79AC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801F79B0: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801F79B4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801F79B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F79BC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801F79C0: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801F79C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F79C8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801F79CC: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801F79D0: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801F79D4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F79D8: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801F79DC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801F79E0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801F79E4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801F79E8: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x801F79EC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801F79F0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801F79F4: jal         0x8011AAF4
    // 0x801F79F8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801F79F8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801F79FC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x801F7A00: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x801F7A04: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801F7A08: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    // 0x801F7A0C: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801F7A10: lwc1        $f16, 0x50($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X50);
    // 0x801F7A14: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F7A18: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F7A1C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7A20: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801F7A24: lwc1        $f6, 0x34($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X34);
    // 0x801F7A28: addiu       $a1, $a1, 0x7A5C
    ctx->r5 = ADD32(ctx->r5, 0X7A5C);
    // 0x801F7A2C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F7A30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801F7A34: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801F7A38: nop

    // 0x801F7A3C: bc1fl       L_801F7A50
    if (!c1cs) {
        // 0x801F7A40: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801F7A50;
    }
    goto skip_0;
    // 0x801F7A40: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801F7A44: jal         0x800058DC
    // 0x801F7A48: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F7A48: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    after_1:
    // 0x801F7A4C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801F7A50:
    // 0x801F7A50: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801F7A54: jr          $ra
    // 0x801F7A58: nop

    return;
    // 0x801F7A58: nop

;}
RECOMP_FUNC void M9_FUN_801f7a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7A64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7A68: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801F7A6C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F7A70: slti        $v1, $v0, 0x51
    ctx->r3 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    // 0x801F7A74: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801F7A78: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801F7A7C: beq         $v1, $zero, L_801F7AB8
    if (ctx->r3 == 0) {
        // 0x801F7A80: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801F7AB8;
    }
    // 0x801F7A80: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801F7A84: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F7A88: lw          $a0, -0x501C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X501C);
    // 0x801F7A8C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F7A90: addiu       $a1, $a1, -0x7D2C
    ctx->r5 = ADD32(ctx->r5, -0X7D2C);
    // 0x801F7A94: beq         $a0, $zero, L_801F7AA8
    if (ctx->r4 == 0) {
        // 0x801F7A98: nop
    
            goto L_801F7AA8;
    }
    // 0x801F7A98: nop

    // 0x801F7A9C: jal         0x800058DC
    // 0x801F7AA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801F7AA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F7AA4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_801F7AA8:
    // 0x801F7AA8: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7AAC: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    // 0x801F7AB0: jal         0x800058DC
    // 0x801F7AB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F7AB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_801F7AB8:
    // 0x801F7AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7AC0: jr          $ra
    // 0x801F7AC4: nop

    return;
    // 0x801F7AC4: nop

;}
RECOMP_FUNC void M9_FUN_801f7ac8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F7ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F7AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F7AD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F7AD8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801F7ADC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7AE0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801F7AE4: jal         0x80147AA8
    // 0x801F7AE8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_0;
    // 0x801F7AE8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_0:
    // 0x801F7AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7AF0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801F7AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7AF8: jal         0x80147AF0
    // 0x801F7AFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_1;
    // 0x801F7AFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801F7B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F7B04: addiu       $t6, $zero, -0x1000
    ctx->r14 = ADD32(0, -0X1000);
    // 0x801F7B08: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7B0C: addiu       $a1, $a1, 0x7B2C
    ctx->r5 = ADD32(ctx->r5, 0X7B2C);
    // 0x801F7B10: sh          $t6, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r14;
    // 0x801F7B14: jal         0x800058DC
    // 0x801F7B18: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F7B18: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    after_2:
    // 0x801F7B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F7B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F7B24: jr          $ra
    // 0x801F7B28: nop

    return;
    // 0x801F7B28: nop

;}
