#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_803762e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803762E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803762E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803762E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803762EC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x803762F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803762F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x803762F8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x803762FC: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80376300(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80376300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376300: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80376304: srl         $a3, $a3, 8
    ctx->r7 = S32(U32(ctx->r7) >> 8);
    // 0x80376308: jal         0x803757E0
    // 0x8037630C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_0;
    // 0x8037630C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80376310: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80376314: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80376318: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x8037631C: srl         $t9, $v1, 24
    ctx->r25 = S32(U32(ctx->r3) >> 24);
    // 0x80376320: beq         $t9, $at, L_80376438
    if (ctx->r25 == ctx->r1) {
        // 0x80376324: srl         $t0, $v1, 16
        ctx->r8 = S32(U32(ctx->r3) >> 16);
            goto L_80376438;
    }
    // 0x80376324: srl         $t0, $v1, 16
    ctx->r8 = S32(U32(ctx->r3) >> 16);
    // 0x80376328: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8037632C: beql        $t1, $zero, L_8037638C
    if (ctx->r9 == 0) {
        // 0x80376330: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_8037638C;
    }
    goto skip_0;
    // 0x80376330: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80376334: jal         0x801C3B3C
    // 0x80376338: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_1;
    // 0x80376338: nop

    after_1:
    // 0x8037633C: bnel        $v0, $zero, L_8037638C
    if (ctx->r2 != 0) {
        // 0x80376340: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_8037638C;
    }
    goto skip_1;
    // 0x80376340: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80376344: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80376348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037634C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376350: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80376354: srl         $t4, $t3, 16
    ctx->r12 = S32(U32(ctx->r11) >> 16);
    // 0x80376358: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8037635C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80376360: bgez        $t5, L_80376374
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80376364: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80376374;
    }
    // 0x80376364: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80376368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037636C: nop

    // 0x80376370: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80376374:
    // 0x80376374: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80376378: jal         0x8012A630
    // 0x8037637C: nop

    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_2;
    // 0x8037637C: nop

    after_2:
    // 0x80376380: bne         $v0, $zero, L_803763AC
    if (ctx->r2 != 0) {
        // 0x80376384: nop
    
            goto L_803763AC;
    }
    // 0x80376384: nop

    // 0x80376388: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
L_8037638C:
    // 0x8037638C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80376390: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80376394: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80376398: bnel        $t9, $zero, L_8037643C
    if (ctx->r25 != 0) {
        // 0x8037639C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037643C;
    }
    goto skip_2;
    // 0x8037639C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803763A0: jal         0x80375A04
    // 0x803763A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80375A04)(rdram, ctx);
        goto after_3;
    // 0x803763A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803763A8: beq         $v0, $zero, L_80376438
    if (ctx->r2 == 0) {
        // 0x803763AC: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80376438;
    }
L_803763AC:
    // 0x803763AC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803763B0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803763B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x803763B8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x803763BC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x803763C0: sh          $a2, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r6;
    // 0x803763C4: sh          $t0, 0x190($v0)
    MEM_H(0X190, ctx->r2) = ctx->r8;
    // 0x803763C8: sh          $t1, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r9;
    // 0x803763CC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x803763D0: lw          $v1, 0xE0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE0);
    // 0x803763D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x803763D8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x803763DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x803763E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x803763E4: lwc1        $f8, 0x4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X4);
    // 0x803763E8: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x803763EC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803763F0: swc1        $f8, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->f8.u32l;
    // 0x803763F4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x803763F8: addiu       $a1, $a1, 0x644C
    ctx->r5 = ADD32(ctx->r5, 0X644C);
    // 0x803763FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376400: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80376404: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80376408: swc1        $f10, 0xF18($v0)
    MEM_W(0XF18, ctx->r2) = ctx->f10.u32l;
    // 0x8037640C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80376410: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80376414: swc1        $f16, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->f16.u32l;
    // 0x80376418: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8037641C: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80376420: sh          $t8, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r24;
    // 0x80376424: swc1        $f0, 0xF04($v0)
    MEM_W(0XF04, ctx->r2) = ctx->f0.u32l;
    // 0x80376428: swc1        $f0, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f0.u32l;
    // 0x8037642C: swc1        $f18, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->f18.u32l;
    // 0x80376430: jal         0x800058DC
    // 0x80376434: sh          $a2, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80376434: sh          $a2, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r6;
    after_4:
L_80376438:
    // 0x80376438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037643C:
    // 0x8037643C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80376440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80376444: jr          $ra
    // 0x80376448: nop

    return;
    // 0x80376448: nop

;}
RECOMP_FUNC void M55_FUN_8037644c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037644C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376454: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80376458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037645C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80376460: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80376464: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80376468: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8037646C: srl         $a3, $a3, 8
    ctx->r7 = S32(U32(ctx->r7) >> 8);
    // 0x80376470: jal         0x803757E0
    // 0x80376474: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_0;
    // 0x80376474: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80376478: bne         $v0, $zero, L_803764AC
    if (ctx->r2 != 0) {
        // 0x8037647C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_803764AC;
    }
    // 0x8037647C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80376480: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80376484: jal         0x8012A94C
    // 0x80376488: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_1;
    // 0x80376488: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8037648C: bne         $v0, $zero, L_803764AC
    if (ctx->r2 != 0) {
        // 0x80376490: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_803764AC;
    }
    // 0x80376490: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80376494: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80376498: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037649C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803764A0: addiu       $a1, $a1, 0x64BC
    ctx->r5 = ADD32(ctx->r5, 0X64BC);
    // 0x803764A4: jal         0x800058DC
    // 0x803764A8: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x803764A8: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    after_2:
L_803764AC:
    // 0x803764AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803764B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803764B4: jr          $ra
    // 0x803764B8: nop

    return;
    // 0x803764B8: nop

;}
RECOMP_FUNC void M55_FUN_803764bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803764BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803764C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803764C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803764C8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x803764CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803764D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x803764D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x803764D8: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x803764DC: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x803764E0: srl         $v0, $t0, 24
    ctx->r2 = S32(U32(ctx->r8) >> 24);
    // 0x803764E4: beql        $v0, $zero, L_80376570
    if (ctx->r2 == 0) {
        // 0x803764E8: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_80376570;
    }
    goto skip_0;
    // 0x803764E8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_0:
    // 0x803764EC: beq         $v0, $at, L_80376504
    if (ctx->r2 == ctx->r1) {
        // 0x803764F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80376504;
    }
    // 0x803764F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803764F4: beql        $v0, $at, L_80376570
    if (ctx->r2 == ctx->r1) {
        // 0x803764F8: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_80376570;
    }
    goto skip_1;
    // 0x803764F8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x803764FC: b           L_8037662C
    // 0x80376500: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8037662C;
    // 0x80376500: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80376504:
    // 0x80376504: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x80376508: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037650C: jal         0x80133A24
    // 0x80376510: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80376510: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80376514: beq         $v0, $zero, L_80376544
    if (ctx->r2 == 0) {
        // 0x80376518: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80376544;
    }
    // 0x80376518: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037651C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80376520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376524: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80376528: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x8037652C: jal         0x803757E0
    // 0x80376530: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_1;
    // 0x80376530: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x80376534: beq         $v0, $zero, L_80376564
    if (ctx->r2 == 0) {
        // 0x80376538: nop
    
            goto L_80376564;
    }
    // 0x80376538: nop

    // 0x8037653C: b           L_8037689C
    // 0x80376540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037689C;
    // 0x80376540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376544:
    // 0x80376544: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80376548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037654C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80376550: lw          $a3, 0x10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X10);
    // 0x80376554: jal         0x803757E0
    // 0x80376558: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_2;
    // 0x80376558: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x8037655C: bnel        $v0, $zero, L_8037689C
    if (ctx->r2 != 0) {
        // 0x80376560: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037689C;
    }
    goto skip_2;
    // 0x80376560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_80376564:
    // 0x80376564: b           L_80376628
    // 0x80376568: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
        goto L_80376628;
    // 0x80376568: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x8037656C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_80376570:
    // 0x80376570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80376574: beq         $v0, $zero, L_803765DC
    if (ctx->r2 == 0) {
        // 0x80376578: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803765DC;
    }
    // 0x80376578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037657C: jal         0x80133A24
    // 0x80376580: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x80376580: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80376584: beq         $v0, $zero, L_803765B4
    if (ctx->r2 == 0) {
        // 0x80376588: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_803765B4;
    }
    // 0x80376588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037658C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80376590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376594: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80376598: lw          $a3, 0x10($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X10);
    // 0x8037659C: jal         0x803757E0
    // 0x803765A0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_4;
    // 0x803765A0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_4:
    // 0x803765A4: beql        $v0, $zero, L_80376628
    if (ctx->r2 == 0) {
        // 0x803765A8: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80376628;
    }
    goto skip_3;
    // 0x803765A8: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_3:
    // 0x803765AC: b           L_8037689C
    // 0x803765B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037689C;
    // 0x803765B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803765B4:
    // 0x803765B4: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x803765B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803765BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x803765C0: lw          $a3, 0x10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X10);
    // 0x803765C4: jal         0x803757E0
    // 0x803765C8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_5;
    // 0x803765C8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_5:
    // 0x803765CC: beql        $v0, $zero, L_80376628
    if (ctx->r2 == 0) {
        // 0x803765D0: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80376628;
    }
    goto skip_4;
    // 0x803765D0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_4:
    // 0x803765D4: b           L_8037689C
    // 0x803765D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037689C;
    // 0x803765D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803765DC:
    // 0x803765DC: lh          $t2, 0x90($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X90);
    // 0x803765E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803765E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x803765E8: beq         $t2, $zero, L_80376614
    if (ctx->r10 == 0) {
        // 0x803765EC: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_80376614;
    }
    // 0x803765EC: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x803765F0: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x803765F4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x803765F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803765FC: jal         0x803757E0
    // 0x80376600: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_6;
    // 0x80376600: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x80376604: beql        $v0, $zero, L_80376628
    if (ctx->r2 == 0) {
        // 0x80376608: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80376628;
    }
    goto skip_5;
    // 0x80376608: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_5:
    // 0x8037660C: b           L_8037689C
    // 0x80376610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037689C;
    // 0x80376610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376614:
    // 0x80376614: jal         0x803757E0
    // 0x80376618: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_7;
    // 0x80376618: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_7:
    // 0x8037661C: bnel        $v0, $zero, L_8037689C
    if (ctx->r2 != 0) {
        // 0x80376620: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037689C;
    }
    goto skip_6;
    // 0x80376620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80376624: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_80376628:
    // 0x80376628: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8037662C:
    // 0x8037662C: sh          $t3, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r11;
    // 0x80376630: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80376634: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037663C: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x80376640: bne         $v0, $at, L_8037665C
    if (ctx->r2 != ctx->r1) {
        // 0x80376644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037665C;
    }
    // 0x80376644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376648: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x8037664C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80376650: sh          $t4, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r12;
    // 0x80376654: lw          $v0, 0x10($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X10);
    // 0x80376658: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
L_8037665C:
    // 0x8037665C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376660: bne         $v0, $at, L_8037667C
    if (ctx->r2 != ctx->r1) {
        // 0x80376664: nop
    
            goto L_8037667C;
    }
    // 0x80376664: nop

    // 0x80376668: jal         0x80375B6C
    // 0x8037666C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80375B6C)(rdram, ctx);
        goto after_8;
    // 0x8037666C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80376670: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80376674: b           L_8037668C
    // 0x80376678: sb          $v0, -0x611F($at)
    MEM_B(-0X611F, ctx->r1) = ctx->r2;
        goto L_8037668C;
    // 0x80376678: sb          $v0, -0x611F($at)
    MEM_B(-0X611F, ctx->r1) = ctx->r2;
L_8037667C:
    // 0x8037667C: jal         0x80375B6C
    // 0x80376680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80375B6C)(rdram, ctx);
        goto after_9;
    // 0x80376680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80376684: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80376688: sb          $v0, -0x611F($at)
    MEM_B(-0X611F, ctx->r1) = ctx->r2;
L_8037668C:
    // 0x8037668C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80376690: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80376694: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80376698: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x8037669C: beql        $v0, $zero, L_80376780
    if (ctx->r2 == 0) {
        // 0x803766A0: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_80376780;
    }
    goto skip_7;
    // 0x803766A0: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_7:
    // 0x803766A4: beq         $v0, $at, L_803766BC
    if (ctx->r2 == ctx->r1) {
        // 0x803766A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_803766BC;
    }
    // 0x803766A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803766AC: beql        $v0, $at, L_80376780
    if (ctx->r2 == ctx->r1) {
        // 0x803766B0: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_80376780;
    }
    goto skip_8;
    // 0x803766B0: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_8:
    // 0x803766B4: b           L_80376880
    // 0x803766B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x803766B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_803766BC:
    // 0x803766BC: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x803766C0: jal         0x80133A24
    // 0x803766C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_10;
    // 0x803766C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_10:
    // 0x803766C8: beq         $v0, $zero, L_80376700
    if (ctx->r2 == 0) {
        // 0x803766CC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80376700;
    }
    // 0x803766CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x803766D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x803766D4: sh          $zero, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = 0;
    // 0x803766D8: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x803766DC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803766E0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x803766E4: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x803766E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x803766EC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x803766F0: jal         0x800179B0
    // 0x803766F4: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_11;
    // 0x803766F4: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_11:
    // 0x803766F8: b           L_80376880
    // 0x803766FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x803766FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80376700:
    // 0x80376700: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80376704: sh          $t1, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = ctx->r9;
    // 0x80376708: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8037670C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80376710: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80376714: srl         $t4, $t3, 16
    ctx->r12 = S32(U32(ctx->r11) >> 16);
    // 0x80376718: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8037671C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80376720: jal         0x800179B0
    // 0x80376724: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_12;
    // 0x80376724: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_12:
    // 0x80376728: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8037672C: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x80376730: jal         0x80133980
    // 0x80376734: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_13;
    // 0x80376734: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_13:
    // 0x80376738: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037673C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80376740: sb          $t7, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r15;
    // 0x80376744: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80376748: jal         0x8013D520
    // 0x8037674C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013D520)(rdram, ctx);
        goto after_14;
    // 0x8037674C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80376750: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x80376754: sh          $t8, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r24;
    // 0x80376758: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8037675C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80376760: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80376764: sb          $t9, -0x6120($at)
    MEM_B(-0X6120, ctx->r1) = ctx->r25;
    // 0x80376768: addiu       $a1, $a1, -0x7B5C
    ctx->r5 = ADD32(ctx->r5, -0X7B5C);
    // 0x8037676C: jal         0x80005670
    // 0x80376770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_15;
    // 0x80376770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80376774: b           L_80376880
    // 0x80376778: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x80376778: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8037677C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_80376780:
    // 0x80376780: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80376784: beql        $v0, $zero, L_80376810
    if (ctx->r2 == 0) {
        // 0x80376788: lh          $t2, 0x90($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X90);
            goto L_80376810;
    }
    goto skip_9;
    // 0x80376788: lh          $t2, 0x90($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X90);
    skip_9:
    // 0x8037678C: jal         0x80133A24
    // 0x80376790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_16;
    // 0x80376790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80376794: beq         $v0, $zero, L_803767CC
    if (ctx->r2 == 0) {
        // 0x80376798: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_803767CC;
    }
    // 0x80376798: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8037679C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x803767A0: sh          $zero, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = 0;
    // 0x803767A4: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x803767A8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803767AC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x803767B0: srl         $t3, $t2, 16
    ctx->r11 = S32(U32(ctx->r10) >> 16);
    // 0x803767B4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x803767B8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x803767BC: jal         0x800179B0
    // 0x803767C0: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_17;
    // 0x803767C0: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_17:
    // 0x803767C4: b           L_80376880
    // 0x803767C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x803767C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_803767CC:
    // 0x803767CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x803767D0: sh          $t5, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = ctx->r13;
    // 0x803767D4: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x803767D8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803767DC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x803767E0: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x803767E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x803767E8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x803767EC: jal         0x800179B0
    // 0x803767F0: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_18;
    // 0x803767F0: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_18:
    // 0x803767F4: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x803767F8: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    // 0x803767FC: jal         0x80133980
    // 0x80376800: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_19;
    // 0x80376800: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_19:
    // 0x80376804: b           L_80376880
    // 0x80376808: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x80376808: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8037680C: lh          $t2, 0x90($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X90);
L_80376810:
    // 0x80376810: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80376814: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80376818: beq         $t2, $zero, L_80376850
    if (ctx->r10 == 0) {
        // 0x8037681C: nop
    
            goto L_80376850;
    }
    // 0x8037681C: nop

    // 0x80376820: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80376824: sh          $zero, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = 0;
    // 0x80376828: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x8037682C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80376830: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80376834: srl         $t5, $t4, 16
    ctx->r13 = S32(U32(ctx->r12) >> 16);
    // 0x80376838: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8037683C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80376840: jal         0x800179B0
    // 0x80376844: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_20;
    // 0x80376844: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_20:
    // 0x80376848: b           L_80376880
    // 0x8037684C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80376880;
    // 0x8037684C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80376850:
    // 0x80376850: sh          $t7, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = ctx->r15;
    // 0x80376854: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80376858: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037685C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80376860: srl         $t1, $t9, 16
    ctx->r9 = S32(U32(ctx->r25) >> 16);
    // 0x80376864: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80376868: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8037686C: jal         0x800179B0
    // 0x80376870: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_21;
    // 0x80376870: lw          $a0, -0x7B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7B48);
    after_21:
    // 0x80376874: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80376878: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
    // 0x8037687C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80376880:
    // 0x80376880: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80376884: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376888: addiu       $a1, $a1, 0x68AC
    ctx->r5 = ADD32(ctx->r5, 0X68AC);
    // 0x8037688C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376890: jal         0x800058DC
    // 0x80376894: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_22;
    // 0x80376894: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    after_22:
    // 0x80376898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037689C:
    // 0x8037689C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803768A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803768A4: jr          $ra
    // 0x803768A8: nop

    return;
    // 0x803768A8: nop

;}
RECOMP_FUNC void M55_FUN_803768ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803768AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803768B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803768B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803768B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x803768BC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x803768C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803768C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x803768C8: jal         0x80010550
    // 0x803768CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x803768CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x803768D0: jal         0x800178E8
    // 0x803768D4: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_1;
    // 0x803768D4: nop

    after_1:
    // 0x803768D8: beq         $v0, $zero, L_803769E8
    if (ctx->r2 == 0) {
        // 0x803768DC: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_803769E8;
    }
    // 0x803768DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x803768E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x803768E4: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    // 0x803768E8: lh          $v1, 0x92($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X92);
    // 0x803768EC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x803768F0: bnel        $v1, $at, L_8037697C
    if (ctx->r3 != ctx->r1) {
        // 0x803768F4: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8037697C;
    }
    goto skip_0;
    // 0x803768F4: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x803768F8: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x803768FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376900: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80376904: srl         $t0, $t9, 24
    ctx->r8 = S32(U32(ctx->r25) >> 24);
    // 0x80376908: beql        $t0, $at, L_8037697C
    if (ctx->r8 == ctx->r1) {
        // 0x8037690C: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8037697C;
    }
    goto skip_1;
    // 0x8037690C: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    skip_1:
    // 0x80376910: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80376914: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80376918: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037691C: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x80376920: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80376924: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80376928: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037692C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80376930: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80376934: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80376938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037693C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80376940: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80376944: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x80376948: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8037694C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80376950: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80376954: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80376958: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8037695C: jal         0x80379498
    // 0x80376960: nop

    LOOKUP_FUNC(0x80379498)(rdram, ctx);
        goto after_2;
    // 0x80376960: nop

    after_2:
    // 0x80376964: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80376968: addiu       $a1, $a1, -0x76C0
    ctx->r5 = ADD32(ctx->r5, -0X76C0);
    // 0x8037696C: jal         0x80005670
    // 0x80376970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x80376970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80376974: lh          $v1, 0x92($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X92);
    // 0x80376978: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
L_8037697C:
    // 0x8037697C: bne         $v1, $zero, L_803769E8
    if (ctx->r3 != 0) {
        // 0x80376980: sh          $t2, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r10;
            goto L_803769E8;
    }
    // 0x80376980: sh          $t2, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r10;
    // 0x80376984: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80376988: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037698C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80376990: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80376994: srl         $t5, $t4, 24
    ctx->r13 = S32(U32(ctx->r12) >> 24);
    // 0x80376998: bne         $t5, $at, L_803769C0
    if (ctx->r13 != ctx->r1) {
        // 0x8037699C: nop
    
            goto L_803769C0;
    }
    // 0x8037699C: nop

    // 0x803769A0: jal         0x801FA2E0
    // 0x803769A4: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_4;
    // 0x803769A4: nop

    after_4:
    // 0x803769A8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803769AC: addiu       $a1, $a1, 0x6ADC
    ctx->r5 = ADD32(ctx->r5, 0X6ADC);
    // 0x803769B0: jal         0x800058DC
    // 0x803769B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x803769B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x803769B8: b           L_803769EC
    // 0x803769BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_803769EC;
    // 0x803769BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803769C0:
    // 0x803769C0: lbu         $t6, -0x611F($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X611F);
    // 0x803769C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803769C8: beq         $t6, $zero, L_803769D8
    if (ctx->r14 == 0) {
        // 0x803769CC: nop
    
            goto L_803769D8;
    }
    // 0x803769CC: nop

    // 0x803769D0: jal         0x80375F98
    // 0x803769D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80375F98)(rdram, ctx);
        goto after_6;
    // 0x803769D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_803769D8:
    // 0x803769D8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803769DC: addiu       $a1, $a1, 0x69FC
    ctx->r5 = ADD32(ctx->r5, 0X69FC);
    // 0x803769E0: jal         0x800058DC
    // 0x803769E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x803769E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_803769E8:
    // 0x803769E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803769EC:
    // 0x803769EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803769F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x803769F4: jr          $ra
    // 0x803769F8: nop

    return;
    // 0x803769F8: nop

;}
RECOMP_FUNC void M55_FUN_803769fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803769FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376A04: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80376A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80376A0C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80376A10: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80376A14: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80376A18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80376A1C: srl         $a3, $a3, 8
    ctx->r7 = S32(U32(ctx->r7) >> 8);
    // 0x80376A20: jal         0x803757E0
    // 0x80376A24: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_0;
    // 0x80376A24: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80376A28: bne         $v0, $zero, L_80376A70
    if (ctx->r2 != 0) {
        // 0x80376A2C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80376A70;
    }
    // 0x80376A2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80376A30: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80376A34: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80376A38: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x80376A3C: jal         0x8012A774
    // 0x80376A40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012A774)(rdram, ctx);
        goto after_1;
    // 0x80376A40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80376A44: beq         $v0, $zero, L_80376A70
    if (ctx->r2 == 0) {
        // 0x80376A48: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80376A70;
    }
    // 0x80376A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80376A4C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80376A50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80376A54: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80376A58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80376A5C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376A60: sh          $t9, 0x78($t0)
    MEM_H(0X78, ctx->r8) = ctx->r25;
    // 0x80376A64: sh          $t1, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r9;
    // 0x80376A68: jal         0x800058DC
    // 0x80376A6C: addiu       $a1, $a1, 0x6A80
    ctx->r5 = ADD32(ctx->r5, 0X6A80);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80376A6C: addiu       $a1, $a1, 0x6A80
    ctx->r5 = ADD32(ctx->r5, 0X6A80);
    after_2:
L_80376A70:
    // 0x80376A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376A78: jr          $ra
    // 0x80376A7C: nop

    return;
    // 0x80376A7C: nop

;}
RECOMP_FUNC void M55_FUN_80376a80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376A88: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80376A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80376A90: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80376A94: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80376A98: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80376A9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80376AA0: srl         $a3, $a3, 8
    ctx->r7 = S32(U32(ctx->r7) >> 8);
    // 0x80376AA4: jal         0x803757E0
    // 0x80376AA8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x803757E0)(rdram, ctx);
        goto after_0;
    // 0x80376AA8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80376AAC: bne         $v0, $zero, L_80376ACC
    if (ctx->r2 != 0) {
        // 0x80376AB0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80376ACC;
    }
    // 0x80376AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80376AB4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80376AB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80376ABC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376AC0: addiu       $a1, $a1, 0x62E0
    ctx->r5 = ADD32(ctx->r5, 0X62E0);
    // 0x80376AC4: jal         0x800058DC
    // 0x80376AC8: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80376AC8: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    after_1:
L_80376ACC:
    // 0x80376ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376AD4: jr          $ra
    // 0x80376AD8: nop

    return;
    // 0x80376AD8: nop

;}
RECOMP_FUNC void M55_FUN_80376adc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80376AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376AE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80376AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80376AEC: jal         0x801270C0
    // 0x80376AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801270C0)(rdram, ctx);
        goto after_0;
    // 0x80376AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80376AF4: beq         $v0, $zero, L_80376B34
    if (ctx->r2 == 0) {
            // 0x80376AF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80376B34)(rdram, ctx);
    return;
    }
    // 0x80376AF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80376AFC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80376B00: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80376B04: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80376B08: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80376B0C: lw          $t7, 0x38($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X38);
    // 0x80376B10: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80376B14: sh          $t9, 0x3A4($v0)
    MEM_H(0X3A4, ctx->r2) = ctx->r25;
    // 0x80376B18: lw          $t0, 0x38($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X38);
    // 0x80376B1C: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    // 0x80376B20: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x80376B24: jal         0x801268CC
    // 0x80376B28: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x801268CC)(rdram, ctx);
        goto after_1;
    // 0x80376B28: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_1:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80376b2c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80376b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376B2C: jal         0x80020744
    // 0x80376B30: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80376B30: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80376b34(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80376b34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80376B3C: jr          $ra
    // 0x80376B40: nop

    return;
    // 0x80376B40: nop

;}
RECOMP_FUNC void M55_FUN_80376b44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80376B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80376B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376B50: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80376B54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80376B58: jal         0x80149330
    // 0x80376B5C: lbu         $a0, -0x6120($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6120);
    LOOKUP_FUNC(0x80149330)(rdram, ctx);
        goto after_0;
    // 0x80376B5C: lbu         $a0, -0x6120($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6120);
    after_0:
    // 0x80376B60: beql        $v0, $zero, L_80376B74
    if (ctx->r2 == 0) {
        // 0x80376B64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80376B74;
    }
    goto skip_0;
    // 0x80376B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80376B68: jal         0x80005700
    // 0x80376B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80376B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80376B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80376B74:
    // 0x80376B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80376B78: jr          $ra
    // 0x80376B7C: nop

    return;
    // 0x80376B7C: nop

;}
RECOMP_FUNC void M55_FUN_80376b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376B80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80376B84: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x80376B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376B8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80376B90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80376B94: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x80376B98: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80376B9C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80376BA0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80376BA4: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80376BA8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80376BAC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80376BB0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80376BB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80376BB8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80376BBC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80376BC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80376BC4: jal         0x80011140
    // 0x80376BC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80376BC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80376BCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80376BD0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80376BD4: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x80376BD8: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x80376BDC: addiu       $a1, $zero, 0x1AB
    ctx->r5 = ADD32(0, 0X1AB);
    // 0x80376BE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80376be4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80376be4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376BE4: bnel        $t1, $at, L_80376C18
    if (ctx->r9 != ctx->r1) {
        // 0x80376BE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80376C18;
    }
    goto skip_0;
    // 0x80376BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80376BEC: jal         0x80126A0C
    // 0x80376BF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x80376BF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80376BF4: beq         $v0, $zero, L_80376C14
    if (ctx->r2 == 0) {
        // 0x80376BF8: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80376C14;
    }
    // 0x80376BF8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80376BFC: jal         0x8014C138
    // 0x80376C00: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    LOOKUP_FUNC(0x8014C138)(rdram, ctx);
        goto after_1;
    // 0x80376C00: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    after_1:
    // 0x80376C04: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376C08: addiu       $a1, $a1, 0x6C24
    ctx->r5 = ADD32(ctx->r5, 0X6C24);
    // 0x80376C0C: jal         0x800058DC
    // 0x80376C10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80376C10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80376C14:
    // 0x80376C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376C18:
    // 0x80376C18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80376C1C: jr          $ra
    // 0x80376C20: nop

    return;
    // 0x80376C20: nop

;}
RECOMP_FUNC void M55_FUN_80376c24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376C2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80376C30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80376C34: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80376C38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80376C3C: jal         0x80010550
    // 0x80376C40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80376C40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80376C44: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80376C48: jal         0x8014C0A8
    // 0x80376C4C: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_1;
    // 0x80376C4C: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    after_1:
    // 0x80376C50: bnel        $v0, $zero, L_80376C9C
    if (ctx->r2 != 0) {
        // 0x80376C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80376C9C;
    }
    goto skip_0;
    // 0x80376C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80376C58: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80376C5C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80376C60: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80376C64: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80376C68: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x80376C6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80376C70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80376C74: jal         0x80011258
    // 0x80376C78: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x80011258)(rdram, ctx);
        goto after_2;
    // 0x80376C78: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_2:
    // 0x80376C7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80376C80: jal         0x80011198
    // 0x80376C84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_3;
    // 0x80376C84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80376C88: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376C8C: addiu       $a1, $a1, 0x6CA8
    ctx->r5 = ADD32(ctx->r5, 0X6CA8);
    // 0x80376C90: jal         0x800058DC
    // 0x80376C94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80376C94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80376C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80376C9C:
    // 0x80376C9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376CA0: jr          $ra
    // 0x80376CA4: nop

    return;
    // 0x80376CA4: nop

;}
RECOMP_FUNC void M55_FUN_80376ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376CA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80376CAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80376CB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80376CB4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80376CB8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80376CBC: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x80376CC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80376CC4: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    // 0x80376CC8: jal         0x8014B4A0
    // 0x80376CCC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x80376CCC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80376CD0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80376CD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80376CD8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80376CDC: jal         0x801C4908
    // 0x80376CE0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x801C4908)(rdram, ctx);
        goto after_1;
    // 0x80376CE0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_1:
    // 0x80376CE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80376CE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80376CEC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80376CF0: jal         0x8012AE54
    // 0x80376CF4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    LOOKUP_FUNC(0x8012AE54)(rdram, ctx);
        goto after_2;
    // 0x80376CF4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_2:
    // 0x80376CF8: bne         $v0, $zero, L_80376D50
    if (ctx->r2 != 0) {
        // 0x80376CFC: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_80376D50;
    }
    // 0x80376CFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80376D00: jal         0x80011198
    // 0x80376D04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_3;
    // 0x80376D04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80376D08: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x80376D0C: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x80376D10: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80376D14: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80376D18: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80376D1C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80376D20: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80376D24: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80376D28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80376D2C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80376D30: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80376D34: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80376D38: jal         0x80011140
    // 0x80376D3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x80376D3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x80376D40: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376D44: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    // 0x80376D48: jal         0x800058DC
    // 0x80376D4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80376D4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
L_80376D50:
    // 0x80376D50: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x80376D54: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80376D58: ori         $at, $at, 0x3E
    ctx->r1 = ctx->r1 | 0X3E;
    // 0x80376D5C: bne         $t1, $at, L_80376D78
    if (ctx->r9 != ctx->r1) {
        // 0x80376D60: lui         $t2, 0x8039
        ctx->r10 = S32(0X8039 << 16);
            goto L_80376D78;
    }
    // 0x80376D60: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80376D64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80376D68: jal         0x80010550
    // 0x80376D6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x80376D6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80376D70: b           L_80376DB0
    // 0x80376D74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80376DB0;
    // 0x80376D74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80376D78:
    // 0x80376D78: addiu       $t2, $t2, -0x7888
    ctx->r10 = ADD32(ctx->r10, -0X7888);
    // 0x80376D7C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80376D80: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80376D84: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80376D88: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x80376D8C: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x80376D90: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80376D94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80376D98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80376D9C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80376DA0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80376DA4: jal         0x80011140
    // 0x80376DA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_7;
    // 0x80376DA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_7:
    // 0x80376DAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80376DB0:
    // 0x80376DB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80376DB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80376DB8: jr          $ra
    // 0x80376DBC: nop

    return;
    // 0x80376DBC: nop

;}
RECOMP_FUNC void M55_FUN_80376dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376DC0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80376DC4: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x80376DC8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80376DCC: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80376DD0: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80376DD4: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x80376DD8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80376DDC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80376DE0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80376DE4: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80376DE8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80376DEC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80376DF0: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80376DF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80376DF8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80376DFC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80376E00: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80376E04: jal         0x80011140
    // 0x80376E08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80376E08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80376E0C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80376E10: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80376E14: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x80376E18: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x80376E1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80376E20: bnel        $t1, $at, L_80376F78
    if (ctx->r9 != ctx->r1) {
        // 0x80376E24: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80376F78;
    }
    goto skip_0;
    // 0x80376E24: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80376E28: jal         0x8014C194
    // 0x80376E2C: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    LOOKUP_FUNC(0x8014C194)(rdram, ctx);
        goto after_1;
    // 0x80376E2C: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    after_1:
    // 0x80376E30: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80376E34: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    // 0x80376E38: jal         0x8014B4A0
    // 0x80376E3C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_2;
    // 0x80376E3C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x80376E40: lh          $a0, 0x78($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X78);
    // 0x80376E44: addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // 0x80376E48: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80376E4C: jal         0x8001EAD0
    // 0x80376E50: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80376E50: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x80376E54: lui         $at, 0x4023
    ctx->r1 = S32(0X4023 << 16);
    // 0x80376E58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80376E5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80376E60: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80376E64: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80376E68: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80376E6C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80376E70: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80376E74: lui         $at, 0x4031
    ctx->r1 = S32(0X4031 << 16);
    // 0x80376E78: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80376E7C: lh          $a0, 0x78($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X78);
    // 0x80376E80: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80376E84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80376E88: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80376E8C: addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // 0x80376E90: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80376E94: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80376E98: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80376E9C: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x80376EA0: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80376EA4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80376EA8: jal         0x8001EB64
    // 0x80376EAC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x80376EAC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80376EB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80376EB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80376EB8: lui         $at, 0x4023
    ctx->r1 = S32(0X4023 << 16);
    // 0x80376EBC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80376EC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80376EC4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80376EC8: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80376ECC: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80376ED0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80376ED4: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80376ED8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80376EDC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80376EE0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80376EE4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80376EE8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80376EEC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80376EF0: ldc1        $f18, -0x6C90($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6C90);
    // 0x80376EF4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80376EF8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80376EFC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80376F00: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80376F04: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80376F08: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80376F0C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80376F10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80376F14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80376F18: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80376F1C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80376F20: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80376F24: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80376F28: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80376F2C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80376F30: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80376F34: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80376F38: addiu       $a0, $a0, -0x6EF4
    ctx->r4 = ADD32(ctx->r4, -0X6EF4);
    // 0x80376F3C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80376F40: addiu       $a1, $zero, 0x17A
    ctx->r5 = ADD32(0, 0X17A);
    // 0x80376F44: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80376F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80376F4C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80376F50: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80376F54: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80376F58: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80376F5C: jal         0x8011AAF4
    // 0x80376F60: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x80376F60: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80376F64: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80376F68: addiu       $a1, $a1, 0x6F84
    ctx->r5 = ADD32(ctx->r5, 0X6F84);
    // 0x80376F6C: jal         0x800058DC
    // 0x80376F70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80376F70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_6:
    // 0x80376F74: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80376F78:
    // 0x80376F78: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80376F7C: jr          $ra
    // 0x80376F80: nop

    return;
    // 0x80376F80: nop

;}
RECOMP_FUNC void M55_FUN_80376f84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376F84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80376F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376F8C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80376F90: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80376F94: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80376F98: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80376F9C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80376FA0: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x80376FA4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80376FA8: jal         0x8014B4A0
    // 0x80376FAC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x80376FAC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x80376FB0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80376FB4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80376FB8: lw          $t8, 0xE0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE0);
    // 0x80376FBC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80376FC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80376FC4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80376FC8: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80376FCC: ori         $at, $at, 0x59
    ctx->r1 = ctx->r1 | 0X59;
    // 0x80376FD0: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80376FD4: lw          $t0, 0xE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE0);
    // 0x80376FD8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80376FDC: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80376FE0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80376FE4: addiu       $t9, $t9, -0x787C
    ctx->r25 = ADD32(ctx->r25, -0X787C);
    // 0x80376FE8: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80376FEC: lw          $t2, 0xE0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XE0);
    // 0x80376FF0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80376FF4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80376FF8: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80376FFC: lw          $t6, 0xE0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE0);
    // 0x80377000: lh          $t4, 0x2C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2C);
    // 0x80377004: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80377008: addiu       $t5, $t4, 0x1000
    ctx->r13 = ADD32(ctx->r12, 0X1000);
    // 0x8037700C: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    // 0x80377010: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x80377014: beq         $t8, $at, L_80377050
    if (ctx->r24 == ctx->r1) {
        // 0x80377018: nop
    
            goto L_80377050;
    }
    // 0x80377018: nop

    // 0x8037701C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80377020: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80377024: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80377028: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8037702C: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80377030: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80377034: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80377038: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8037703C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80377040: jal         0x80011140
    // 0x80377044: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x80377044: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x80377048: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8037704C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_80377050:
    // 0x80377050: jal         0x8014C0A8
    // 0x80377054: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_2;
    // 0x80377054: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    after_2:
    // 0x80377058: bne         $v0, $zero, L_80377098
    if (ctx->r2 != 0) {
        // 0x8037705C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80377098;
    }
    // 0x8037705C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80377060: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80377064: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377068: addiu       $v0, $v0, -0x23C0
    ctx->r2 = ADD32(ctx->r2, -0X23C0);
    // 0x8037706C: sb          $t3, -0x781C($at)
    MEM_B(-0X781C, ctx->r1) = ctx->r11;
    // 0x80377070: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x80377074: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80377078: addiu       $a1, $a1, -0x7870
    ctx->r5 = ADD32(ctx->r5, -0X7870);
    // 0x8037707C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80377080: jal         0x80005670
    // 0x80377084: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x80377084: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    after_3:
    // 0x80377088: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x8037708C: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, 0X70A8);
    // 0x80377090: jal         0x800058DC
    // 0x80377094: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80377094: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
L_80377098:
    // 0x80377098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037709C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x803770A0: jr          $ra
    // 0x803770A4: nop

    return;
    // 0x803770A4: nop

;}
RECOMP_FUNC void M55_FUN_803770a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803770A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803770AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803770B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803770B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803770B8: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x803770BC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x803770C0: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x803770C4: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x803770C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x803770CC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x803770D0: beql        $t7, $at, L_80377134
    if (ctx->r15 == ctx->r1) {
        // 0x803770D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80377134;
    }
    goto skip_0;
    // 0x803770D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803770D8: jal         0x80010550
    // 0x803770DC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x803770DC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x803770E0: beq         $v0, $zero, L_80377130
    if (ctx->r2 == 0) {
        // 0x803770E4: lui         $t8, 0x8021
        ctx->r24 = S32(0X8021 << 16);
            goto L_80377130;
    }
    // 0x803770E4: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x803770E8: addiu       $t8, $t8, 0x6B90
    ctx->r24 = ADD32(ctx->r24, 0X6B90);
    // 0x803770EC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x803770F0: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x803770F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x803770F8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x803770FC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80377100: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80377104: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80377108: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037710C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80377110: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80377114: jal         0x80011140
    // 0x80377118: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x80377118: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x8037711C: beq         $v0, $zero, L_80377130
    if (ctx->r2 == 0) {
        // 0x80377120: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80377130;
    }
    // 0x80377120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80377124: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377128: jal         0x800058DC
    // 0x8037712C: addiu       $a1, $a1, 0x7140
    ctx->r5 = ADD32(ctx->r5, 0X7140);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037712C: addiu       $a1, $a1, 0x7140
    ctx->r5 = ADD32(ctx->r5, 0X7140);
    after_2:
L_80377130:
    // 0x80377130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80377134:
    // 0x80377134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80377138: jr          $ra
    // 0x8037713C: nop

    return;
    // 0x8037713C: nop

;}
RECOMP_FUNC void M55_FUN_80377140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377140: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80377144: lbu         $t6, -0x781C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X781C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80377148(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80377148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037714C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377154: bne         $t6, $zero, L_80377194
    if (ctx->r14 != 0) {
        // 0x80377158: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80377194;
    }
    // 0x80377158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037715C: jal         0x8013EA94
    // 0x80377160: nop

    LOOKUP_FUNC(0x8013EA94)(rdram, ctx);
        goto after_0;
    // 0x80377160: nop

    after_0:
    // 0x80377164: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80377168: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8037716C: lhu         $t7, 0x8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8);
    // 0x80377170: lui         $t9, 0x8038
    ctx->r25 = S32(0X8038 << 16);
    // 0x80377174: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377178: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8037717C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80377180: lhu         $t9, -0x785C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X785C);
    // 0x80377184: addiu       $a1, $a1, 0x71A4
    ctx->r5 = ADD32(ctx->r5, 0X71A4);
    // 0x80377188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8037718C: jal         0x800058DC
    // 0x80377190: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80377190: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    after_1:
L_80377194:
    // 0x80377194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037719C: jr          $ra
    // 0x803771A0: nop

    return;
    // 0x803771A0: nop

;}
RECOMP_FUNC void M55_FUN_803771a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803771A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803771A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803771AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803771B0: jal         0x8013EB2C
    // 0x803771B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013EB2C)(rdram, ctx);
        goto after_0;
    // 0x803771B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x803771B8: beql        $v0, $zero, L_803771DC
    if (ctx->r2 == 0) {
        // 0x803771BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803771DC;
    }
    goto skip_0;
    // 0x803771BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803771C0: jal         0x80142570
    // 0x803771C4: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x803771C4: nop

    after_1:
    // 0x803771C8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803771CC: addiu       $a1, $a1, 0x7478
    ctx->r5 = ADD32(ctx->r5, 0X7478);
    // 0x803771D0: jal         0x800058DC
    // 0x803771D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x803771D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x803771D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803771DC:
    // 0x803771DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803771E0: jr          $ra
    // 0x803771E4: nop

    return;
    // 0x803771E4: nop

;}
RECOMP_FUNC void M55_FUN_803771e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803771E8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x803771EC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x803771F0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x803771F4: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x803771F8: lhu         $t6, 0xEF0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XEF0);
    // 0x803771FC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80377200: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80377204: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80377208: ori         $t7, $t6, 0xD0
    ctx->r15 = ctx->r14 | 0XD0;
    // 0x8037720C: sh          $t7, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r15;
    // 0x80377210: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80377214: jal         0x8014B4A0
    // 0x80377218: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x80377218: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    after_0:
    // 0x8037721C: beql        $v0, $zero, L_8037740C
    if (ctx->r2 == 0) {
        // 0x80377220: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8037740C;
    }
    goto skip_0;
    // 0x80377220: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80377224: jal         0x801269C0
    // 0x80377228: nop

    LOOKUP_FUNC(0x801269C0)(rdram, ctx);
        goto after_1;
    // 0x80377228: nop

    after_1:
    // 0x8037722C: jal         0x8001EAD0
    // 0x80377230: lh          $a0, 0x84($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X84);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80377230: lh          $a0, 0x84($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X84);
    after_2:
    // 0x80377234: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377238: ldc1        $f6, -0x6C88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C88);
    // 0x8037723C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80377240: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80377244: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80377248: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8037724C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80377250: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80377254: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80377258: lh          $a0, 0x84($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X84);
    // 0x8037725C: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80377260: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80377264: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80377268: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8037726C: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x80377270: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80377274: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80377278: jal         0x8001EB64
    // 0x8037727C: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8037727C: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80377280: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80377284: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80377288: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037728C: ldc1        $f8, -0x6C80($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6C80);
    // 0x80377290: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80377294: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80377298: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8037729C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x803772A0: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x803772A4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x803772A8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x803772AC: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x803772B0: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x803772B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x803772B8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x803772BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x803772C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x803772C4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x803772C8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803772CC: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x803772D0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x803772D4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x803772D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x803772DC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x803772E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x803772E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803772E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x803772EC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803772F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x803772F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x803772F8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x803772FC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80377300: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80377304: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80377308: addiu       $a0, $a0, -0x6E94
    ctx->r4 = ADD32(ctx->r4, -0X6E94);
    // 0x8037730C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80377310: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80377314: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80377318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037731C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80377320: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80377324: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80377328: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8037732C: jal         0x8011AAF4
    // 0x80377330: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x80377330: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80377334: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x80377338: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8037733C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80377340: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80377344: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x80377348: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x8037734C: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80377350: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80377354: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x80377358: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x8037735C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80377360: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80377364: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80377368: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x8037736C: lh          $t7, 0x84($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X84);
    // 0x80377370: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80377374: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    // 0x80377378: jal         0x801C4A5C
    // 0x8037737C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_5;
    // 0x8037737C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_5:
    // 0x80377380: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80377384: sh          $t0, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r8;
    // 0x80377388: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8037738C: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80377390: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80377394: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x80377398: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8037739C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x803773A0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x803773A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803773A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803773AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x803773B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x803773B4: jal         0x8001E978
    // 0x803773B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_6;
    // 0x803773B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_6:
    // 0x803773BC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803773C0: sb          $zero, -0x610E($at)
    MEM_B(-0X610E, ctx->r1) = 0;
    // 0x803773C4: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x803773C8: ori         $at, $zero, 0x8002
    ctx->r1 = 0 | 0X8002;
    // 0x803773CC: bnel        $v0, $at, L_803773E8
    if (ctx->r2 != ctx->r1) {
        // 0x803773D0: ori         $at, $zero, 0x8014
        ctx->r1 = 0 | 0X8014;
            goto L_803773E8;
    }
    goto skip_1;
    // 0x803773D0: ori         $at, $zero, 0x8014
    ctx->r1 = 0 | 0X8014;
    skip_1:
    // 0x803773D4: jal         0x80020718
    // 0x803773D8: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_7;
    // 0x803773D8: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_7:
    // 0x803773DC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803773E0: lhu         $v0, -0x4408($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4408);
    // 0x803773E4: ori         $at, $zero, 0x8014
    ctx->r1 = 0 | 0X8014;
L_803773E8:
    // 0x803773E8: bne         $v0, $at, L_803773F8
    if (ctx->r2 != ctx->r1) {
        // 0x803773EC: nop
    
            goto L_803773F8;
    }
    // 0x803773EC: nop

    // 0x803773F0: jal         0x80020718
    // 0x803773F4: addiu       $a0, $zero, 0x232
    ctx->r4 = ADD32(0, 0X232);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_8;
    // 0x803773F4: addiu       $a0, $zero, 0x232
    ctx->r4 = ADD32(0, 0X232);
    after_8:
L_803773F8:
    // 0x803773F8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803773FC: addiu       $a1, $a1, 0x741C
    ctx->r5 = ADD32(ctx->r5, 0X741C);
    // 0x80377400: jal         0x800058DC
    // 0x80377404: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x80377404: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_9:
    // 0x80377408: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8037740C:
    // 0x8037740C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80377410: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80377414: jr          $ra
    // 0x80377418: nop

    return;
    // 0x80377418: nop

;}
RECOMP_FUNC void M55_FUN_8037741c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037741C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377420: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377424: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80377428: addiu       $a1, $a1, -0x610E
    ctx->r5 = ADD32(ctx->r5, -0X610E);
    // 0x8037742C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80377430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377438: slti        $v1, $v0, 0xB
    ctx->r3 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8037743C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80377440: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80377444: beq         $v1, $zero, L_80377468
    if (ctx->r3 == 0) {
        // 0x80377448: sb          $t6, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r14;
            goto L_80377468;
    }
    // 0x80377448: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x8037744C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80377450: jal         0x8014C138
    // 0x80377454: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    LOOKUP_FUNC(0x8014C138)(rdram, ctx);
        goto after_0;
    // 0x80377454: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    after_0:
    // 0x80377458: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x8037745C: addiu       $a1, $a1, 0x7644
    ctx->r5 = ADD32(ctx->r5, 0X7644);
    // 0x80377460: jal         0x800058DC
    // 0x80377464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80377464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80377468:
    // 0x80377468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037746C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377470: jr          $ra
    // 0x80377474: nop

    return;
    // 0x80377474: nop

;}
RECOMP_FUNC void M55_FUN_80377478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377478: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8037747C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80377480: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80377484: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80377488: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8037748C: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    // 0x80377490: jal         0x8014B4A0
    // 0x80377494: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x80377494: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_0:
    // 0x80377498: jal         0x8001EAD0
    // 0x8037749C: lh          $a0, 0x74($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X74);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8037749C: lh          $a0, 0x74($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X74);
    after_1:
    // 0x803774A0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803774A4: ldc1        $f6, -0x6C78($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C78);
    // 0x803774A8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x803774AC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x803774B0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x803774B4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x803774B8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x803774BC: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x803774C0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x803774C4: lh          $a0, 0x74($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X74);
    // 0x803774C8: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x803774CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x803774D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x803774D4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x803774D8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x803774DC: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x803774E0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x803774E4: jal         0x8001EB64
    // 0x803774E8: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x803774E8: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x803774EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x803774F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x803774F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803774F8: ldc1        $f8, -0x6C70($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6C70);
    // 0x803774FC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80377500: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80377504: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80377508: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8037750C: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80377510: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80377514: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80377518: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8037751C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80377520: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80377524: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80377528: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8037752C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80377530: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80377534: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80377538: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8037753C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80377540: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80377544: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80377548: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8037754C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80377550: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80377554: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80377558: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037755C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80377560: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80377564: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80377568: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8037756C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80377570: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80377574: addiu       $a0, $a0, -0x6E18
    ctx->r4 = ADD32(ctx->r4, -0X6E18);
    // 0x80377578: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8037757C: addiu       $a1, $zero, 0x212
    ctx->r5 = ADD32(0, 0X212);
    // 0x80377580: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80377584: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80377588: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8037758C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80377590: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80377594: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80377598: jal         0x8011AAF4
    // 0x8037759C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_3;
    // 0x8037759C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x803775A0: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803775A4: addiu       $a1, $a1, 0x75C0
    ctx->r5 = ADD32(ctx->r5, 0X75C0);
    // 0x803775A8: jal         0x800058DC
    // 0x803775AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x803775AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_4:
    // 0x803775B0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x803775B4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x803775B8: jr          $ra
    // 0x803775BC: nop

    return;
    // 0x803775BC: nop

;}
RECOMP_FUNC void M55_FUN_803775c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803775C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803775C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803775C8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803775CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803775D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x803775D4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x803775D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x803775DC: jal         0x8014B4A0
    // 0x803775E0: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x803775E0: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    after_0:
    // 0x803775E4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803775E8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803775EC: lw          $t6, 0xE0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE0);
    // 0x803775F0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x803775F4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x803775F8: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x803775FC: lw          $t8, 0xE0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE0);
    // 0x80377600: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80377604: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80377608: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x8037760C: lw          $t1, 0xE0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XE0);
    // 0x80377610: lh          $t0, 0x3C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3C);
    // 0x80377614: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80377618: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x8037761C: jal         0x8014C138
    // 0x80377620: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    LOOKUP_FUNC(0x8014C138)(rdram, ctx);
        goto after_1;
    // 0x80377620: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    after_1:
    // 0x80377624: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377628: addiu       $a1, $a1, 0x7644
    ctx->r5 = ADD32(ctx->r5, 0X7644);
    // 0x8037762C: jal         0x800058DC
    // 0x80377630: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80377630: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x80377634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377638: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8037763C: jr          $ra
    // 0x80377640: nop

    return;
    // 0x80377640: nop

;}
RECOMP_FUNC void M55_FUN_80377644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377648: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037764C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377650: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80377654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377658: lhu         $a0, -0x4408($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4408);
    // 0x8037765C: jal         0x8014C0A8
    // 0x80377660: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_0;
    // 0x80377660: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80377664: bne         $v0, $zero, L_8037768C
    if (ctx->r2 != 0) {
        // 0x80377668: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8037768C;
    }
    // 0x80377668: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8037766C: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x80377670: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80377674: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377678: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8037767C: sw          $t7, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r15;
    // 0x80377680: addiu       $a1, $a1, 0x769C
    ctx->r5 = ADD32(ctx->r5, 0X769C);
    // 0x80377684: jal         0x800058DC
    // 0x80377688: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80377688: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_8037768C:
    // 0x8037768C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377694: jr          $ra
    // 0x80377698: nop

    return;
    // 0x80377698: nop

;}
RECOMP_FUNC void M55_FUN_8037769c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037769C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803776A0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803776A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803776A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803776AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803776B0: addiu       $t7, $t7, -0x7888
    ctx->r15 = ADD32(ctx->r15, -0X7888);
    // 0x803776B4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x803776B8: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x803776BC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x803776C0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x803776C4: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x803776C8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x803776CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x803776D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x803776D4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x803776D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x803776DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803776E0: jal         0x80011140
    // 0x803776E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x803776E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x803776E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x803776EC: lui         $v1, 0x168
    ctx->r3 = S32(0X168 << 16);
    // 0x803776F0: ori         $v1, $v1, 0x3E
    ctx->r3 = ctx->r3 | 0X3E;
    // 0x803776F4: addiu       $v0, $a1, 0x1C
    ctx->r2 = ADD32(ctx->r5, 0X1C);
    // 0x803776F8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x803776FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80377700: bnel        $v1, $t1, L_80377750
    if (ctx->r3 != ctx->r9) {
        // 0x80377704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80377750;
    }
    goto skip_0;
    // 0x80377704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80377708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037770C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80377710: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80377714: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80377718: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8037771C: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80377720: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80377724: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80377728: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037772C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80377730: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80377734: jal         0x8013A28C
    // 0x80377738: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x80377738: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8037773C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377740: addiu       $a1, $a1, 0x775C
    ctx->r5 = ADD32(ctx->r5, 0X775C);
    // 0x80377744: jal         0x800058DC
    // 0x80377748: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80377748: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8037774C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80377750:
    // 0x80377750: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80377754: jr          $ra
    // 0x80377758: nop

    return;
    // 0x80377758: nop

;}
RECOMP_FUNC void M55_FUN_8037775c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037775C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80377760: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80377764: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80377768: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8037776C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80377770: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80377774: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80377778: jal         0x80010550
    // 0x8037777C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037777C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80377780: beql        $v0, $zero, L_8037796C
    if (ctx->r2 == 0) {
        // 0x80377784: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8037796C;
    }
    goto skip_0;
    // 0x80377784: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80377788: jal         0x80126E88
    // 0x8037778C: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x8037778C: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    after_1:
    // 0x80377790: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80377794: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x80377798: jal         0x8014C194
    // 0x8037779C: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    LOOKUP_FUNC(0x8014C194)(rdram, ctx);
        goto after_2;
    // 0x8037779C: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    after_2:
    // 0x803777A0: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    // 0x803777A4: jal         0x8014B4A0
    // 0x803777A8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_3;
    // 0x803777A8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_3:
    // 0x803777AC: jal         0x8001EAD0
    // 0x803777B0: lh          $a0, 0x80($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X80);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x803777B0: lh          $a0, 0x80($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X80);
    after_4:
    // 0x803777B4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803777B8: ldc1        $f6, -0x6C68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C68);
    // 0x803777BC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x803777C0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x803777C4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x803777C8: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x803777CC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x803777D0: lh          $a0, 0x80($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X80);
    // 0x803777D4: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x803777D8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x803777DC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x803777E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x803777E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x803777E8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x803777EC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x803777F0: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x803777F4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x803777F8: jal         0x8001EB64
    // 0x803777FC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x803777FC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80377800: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377804: ldc1        $f6, -0x6C60($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C60);
    // 0x80377808: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8037780C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80377810: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80377814: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80377818: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8037781C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80377820: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80377824: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80377828: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8037782C: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80377830: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x80377834: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80377838: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037783C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80377840: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80377844: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80377848: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x8037784C: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x80377850: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80377854: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x80377858: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8037785C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80377860: jal         0x8010843C
    // 0x80377864: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_6;
    // 0x80377864: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80377868: beq         $v0, $zero, L_80377884
    if (ctx->r2 == 0) {
        // 0x8037786C: lwc1        $f18, 0x68($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80377884;
    }
    // 0x8037786C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80377870: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x80377874: lwc1        $f8, 0x384($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X384);
    // 0x80377878: lwc1        $f18, 0x388($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X388);
    // 0x8037787C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80377880: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
L_80377884:
    // 0x80377884: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80377888: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8037788C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80377890: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80377894: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80377898: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8037789C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x803778A0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x803778A4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x803778A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x803778AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x803778B0: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x803778B4: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x803778B8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803778BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x803778C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x803778C4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x803778C8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x803778CC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x803778D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x803778D4: addiu       $a0, $a0, -0x6DD0
    ctx->r4 = ADD32(ctx->r4, -0X6DD0);
    // 0x803778D8: addiu       $a1, $zero, 0x265
    ctx->r5 = ADD32(0, 0X265);
    // 0x803778DC: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x803778E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x803778E4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x803778E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x803778EC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x803778F0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x803778F4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x803778F8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x803778FC: jal         0x8011AAF4
    // 0x80377900: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_7;
    // 0x80377900: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80377904: lhu         $t0, 0xEF0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XEF0);
    // 0x80377908: lui         $t2, 0x8021
    ctx->r10 = S32(0X8021 << 16);
    // 0x8037790C: addiu       $t2, $t2, 0x6B90
    ctx->r10 = ADD32(ctx->r10, 0X6B90);
    // 0x80377910: andi        $t1, $t0, 0xFFAF
    ctx->r9 = ctx->r8 & 0XFFAF;
    // 0x80377914: sh          $t1, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r9;
    // 0x80377918: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8037791C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80377920: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80377924: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x80377928: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x8037792C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80377930: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80377934: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80377938: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8037793C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80377940: jal         0x80011140
    // 0x80377944: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_8;
    // 0x80377944: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x80377948: jal         0x8001F6FC
    // 0x8037794C: nop

    LOOKUP_FUNC(0x8001F6FC)(rdram, ctx);
        goto after_9;
    // 0x8037794C: nop

    after_9:
    // 0x80377950: jal         0x8001F74C
    // 0x80377954: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_10;
    // 0x80377954: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    after_10:
    // 0x80377958: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037795C: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80377960: jal         0x800058DC
    // 0x80377964: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80377964: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_11:
    // 0x80377968: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8037796C:
    // 0x8037796C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80377970: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80377974: jr          $ra
    // 0x80377978: nop

    return;
    // 0x80377978: nop

;}
RECOMP_FUNC void M55_FUN_8037797c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037797C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80377980: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80377984: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80377988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037798C: jal         0x8001F74C
    // 0x80377990: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80377990: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    after_0:
    // 0x80377994: sb          $zero, 0x79($s0)
    MEM_B(0X79, ctx->r16) = 0;
    // 0x80377998: sb          $zero, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = 0;
    // 0x8037799C: sb          $zero, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = 0;
    // 0x803779A0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x803779A4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x803779A8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x803779AC: jal         0x8001EAD0
    // 0x803779B0: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x803779B0: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_1:
    // 0x803779B4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x803779B8: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x803779BC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x803779C0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x803779C4: jal         0x8001EB64
    // 0x803779C8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x803779C8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_2:
    // 0x803779CC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x803779D0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803779D4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x803779D8: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x803779DC: ldc1        $f2, -0x6C58($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6C58);
    // 0x803779E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x803779E4: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x803779E8: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x803779EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x803779F0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x803779F4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x803779F8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x803779FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80377A00: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80377A04: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80377A08: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80377A0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80377A10: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80377A14: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80377A18: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80377A1C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80377A20: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80377A24: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x80377A28: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80377A2C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80377A30: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80377A34: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80377A38: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80377A3C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80377A40: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80377A44: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80377A48: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80377A4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80377A50: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x80377A54: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80377A58: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x80377A5C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80377A60: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80377A64: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80377A68: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80377A6C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80377A70: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80377A74: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80377A78: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80377A7C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80377A80: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80377A84: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80377A88: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80377A8C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x80377A90: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80377A94: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80377A98: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80377A9C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80377AA0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80377AA4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80377AA8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80377AAC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80377AB0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80377AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80377AB8: jal         0x80377BA0
    // 0x80377ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80377BA0)(rdram, ctx);
        goto after_3;
    // 0x80377ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80377AC0: sb          $zero, 0x98($v0)
    MEM_B(0X98, ctx->r2) = 0;
    // 0x80377AC4: jal         0x80020718
    // 0x80377AC8: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_4;
    // 0x80377AC8: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_4:
    // 0x80377ACC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377AD0: addiu       $a1, $a1, 0x7AF0
    ctx->r5 = ADD32(ctx->r5, 0X7AF0);
    // 0x80377AD4: jal         0x800058DC
    // 0x80377AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80377AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80377ADC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80377AE0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80377AE4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80377AE8: jr          $ra
    // 0x80377AEC: nop

    return;
    // 0x80377AEC: nop

;}
RECOMP_FUNC void M55_FUN_80377af0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377AF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377AFC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80377B00: jal         0x800058DC
    // 0x80377B04: addiu       $a1, $a1, 0x7B18
    ctx->r5 = ADD32(ctx->r5, 0X7B18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80377B04: addiu       $a1, $a1, 0x7B18
    ctx->r5 = ADD32(ctx->r5, 0X7B18);
    after_0:
    // 0x80377B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377B10: jr          $ra
    // 0x80377B14: nop

    return;
    // 0x80377B14: nop

;}
RECOMP_FUNC void M55_FUN_80377b18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377B20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377B24: lhu         $t6, 0x2C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2C);
    // 0x80377B28: blezl       $t6, L_80377B3C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80377B2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80377B3C;
    }
    goto skip_0;
    // 0x80377B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80377B30: jal         0x80005700
    // 0x80377B34: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80377B34: nop

    after_0:
    // 0x80377B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80377B3C:
    // 0x80377B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377B40: jr          $ra
    // 0x80377B44: nop

    return;
    // 0x80377B44: nop

;}
RECOMP_FUNC void M55_FUN_80377b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377B48: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80377B4C: addiu       $v1, $v0, -0x7818
    ctx->r3 = ADD32(ctx->r2, -0X7818);
    // 0x80377B50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80377B54: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
    // 0x80377B58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80377B5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80377B60: beq         $a2, $t6, L_80377B94
    if (ctx->r6 == ctx->r14) {
        // 0x80377B64: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80377B94;
    }
    // 0x80377B64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80377B68: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80377B6C: addiu       $t7, $t7, -0x7818
    ctx->r15 = ADD32(ctx->r15, -0X7818);
    // 0x80377B70: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
L_80377B74:
    // 0x80377B74: bnel        $v0, $a1, L_80377B88
    if (ctx->r2 != ctx->r5) {
        // 0x80377B78: lbu         $a1, 0x14($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X14);
            goto L_80377B88;
    }
    goto skip_0;
    // 0x80377B78: lbu         $a1, 0x14($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X14);
    skip_0:
    // 0x80377B7C: jr          $ra
    // 0x80377B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80377B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80377B84: lbu         $a1, 0x14($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X14);
L_80377B88:
    // 0x80377B88: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80377B8C: bne         $a2, $a1, L_80377B74
    if (ctx->r6 != ctx->r5) {
        // 0x80377B90: nop
    
            goto L_80377B74;
    }
    // 0x80377B90: nop

L_80377B94:
    // 0x80377B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80377B98: jr          $ra
    // 0x80377B9C: nop

    return;
    // 0x80377B9C: nop

;}
RECOMP_FUNC void M55_FUN_80377ba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80377BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80377BAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80377BB0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80377BB4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80377BB8: jal         0x80377B48
    // 0x80377BBC: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    LOOKUP_FUNC(0x80377B48)(rdram, ctx);
        goto after_0;
    // 0x80377BBC: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    after_0:
    // 0x80377BC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80377BC4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80377BC8: addiu       $a1, $a1, -0x7800
    ctx->r5 = ADD32(ctx->r5, -0X7800);
    // 0x80377BCC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80377BD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80377BD4: jal         0x80005670
    // 0x80377BD8: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x80377BD8: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    after_1:
    // 0x80377BDC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80377BE0: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80377BE4: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80377BE8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80377BEC: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x80377BF0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80377BF4: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x80377BF8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80377BFC: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x80377C00: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x80377C04: sb          $t7, 0x78($v0)
    MEM_B(0X78, ctx->r2) = ctx->r15;
    // 0x80377C08: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x80377C0C: sb          $t8, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r24;
    // 0x80377C10: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x80377C14: sb          $t9, 0x7A($v0)
    MEM_B(0X7A, ctx->r2) = ctx->r25;
    // 0x80377C18: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x80377C1C: sb          $t0, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r8;
    // 0x80377C20: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x80377C24: sb          $t1, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r9;
    // 0x80377C28: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x80377C2C: sb          $t2, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r10;
    // 0x80377C30: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x80377C34: sb          $t3, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r11;
    // 0x80377C38: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x80377C3C: sb          $t4, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = ctx->r12;
    // 0x80377C40: lbu         $t5, 0x57($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X57);
    // 0x80377C44: sb          $t5, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r13;
    // 0x80377C48: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x80377C4C: sb          $t6, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r14;
    // 0x80377C50: lbu         $t7, 0x5F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5F);
    // 0x80377C54: sb          $t7, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r15;
    // 0x80377C58: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x80377C5C: sb          $t8, 0x83($v0)
    MEM_B(0X83, ctx->r2) = ctx->r24;
    // 0x80377C60: lbu         $t9, 0x67($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X67);
    // 0x80377C64: sb          $t9, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r25;
    // 0x80377C68: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x80377C6C: sb          $t0, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r8;
    // 0x80377C70: lbu         $t1, 0x6F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X6F);
    // 0x80377C74: sb          $t1, 0x86($v0)
    MEM_B(0X86, ctx->r2) = ctx->r9;
    // 0x80377C78: lbu         $t2, 0x73($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X73);
    // 0x80377C7C: sb          $t2, 0x87($v0)
    MEM_B(0X87, ctx->r2) = ctx->r10;
    // 0x80377C80: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x80377C84: sw          $t3, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r11;
    // 0x80377C88: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80377C8C: sw          $t4, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r12;
    // 0x80377C90: lhu         $t5, 0x7A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X7A);
    // 0x80377C94: sh          $zero, 0x92($v0)
    MEM_H(0X92, ctx->r2) = 0;
    // 0x80377C98: sh          $t5, 0x90($v0)
    MEM_H(0X90, ctx->r2) = ctx->r13;
    // 0x80377C9C: lbu         $t6, 0x77($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X77);
    // 0x80377CA0: sb          $t6, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r14;
    // 0x80377CA4: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80377CA8: sb          $t7, 0x95($v0)
    MEM_B(0X95, ctx->r2) = ctx->r15;
    // 0x80377CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80377CB4: jr          $ra
    // 0x80377CB8: nop

    return;
    // 0x80377CB8: nop

;}
RECOMP_FUNC void M55_FUN_80377cbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377CBC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80377CC0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80377CC4: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80377CC8: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80377CCC: lbu         $t6, 0x7F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7F);
    // 0x80377CD0: lbu         $t7, 0x83($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X83);
    // 0x80377CD4: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
    // 0x80377CD8: lbu         $t9, 0x8B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X8B);
    // 0x80377CDC: lbu         $t0, 0x8F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X8F);
    // 0x80377CE0: lbu         $t1, 0x93($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X93);
    // 0x80377CE4: lbu         $t2, 0x97($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X97);
    // 0x80377CE8: lbu         $t3, 0x9B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X9B);
    // 0x80377CEC: lbu         $t4, 0x9F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X9F);
    // 0x80377CF0: lhu         $t5, 0xA2($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XA2);
    // 0x80377CF4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80377CF8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80377CFC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80377D00: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80377D04: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80377D08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80377D0C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80377D10: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80377D14: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80377D18: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80377D1C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80377D20: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80377D24: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80377D28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80377D2C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80377D30: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80377D34: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80377D38: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80377D3C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80377D40: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80377D44: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80377D48: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80377D4C: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80377D50: jal         0x80377BA0
    // 0x80377D54: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80377BA0)(rdram, ctx);
        goto after_0;
    // 0x80377D54: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    after_0:
    // 0x80377D58: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80377D5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80377D60: jr          $ra
    // 0x80377D64: nop

    return;
    // 0x80377D64: nop

;}
RECOMP_FUNC void M55_FUN_80377d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377D68: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80377D6C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80377D70: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80377D74: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80377D78: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80377D7C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80377D80: lw          $t7, 0x1CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1CEC);
    // 0x80377D84: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80377D88: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80377D8C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80377D90: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80377D94: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80377D98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80377D9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80377DA0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80377DA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80377DA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80377DAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80377DB0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80377DB4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80377DB8: lw          $t0, 0x88($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X88);
    // 0x80377DBC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80377DC0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80377DC4: addiu       $t1, $t1, -0x7890
    ctx->r9 = ADD32(ctx->r9, -0X7890);
    // 0x80377DC8: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x80377DCC: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80377DD0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80377DD4: addiu       $s3, $s3, -0x5908
    ctx->r19 = ADD32(ctx->r19, -0X5908);
    // 0x80377DD8: addiu       $s0, $s0, -0x6108
    ctx->r16 = ADD32(ctx->r16, -0X6108);
    // 0x80377DDC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80377DE0: addiu       $s7, $zero, 0x30F
    ctx->r23 = ADD32(0, 0X30F);
    // 0x80377DE4: lhu         $fp, 0x0($v0)
    ctx->r30 = MEM_HU(ctx->r2, 0X0);
    // 0x80377DE8: beq         $t1, $t0, L_80377DF8
    if (ctx->r9 == ctx->r8) {
        // 0x80377DEC: lhu         $v1, 0x2($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X2);
            goto L_80377DF8;
    }
    // 0x80377DEC: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x80377DF0: lui         $s7, 0x6
    ctx->r23 = S32(0X6 << 16);
    // 0x80377DF4: ori         $s7, $s7, 0x30F
    ctx->r23 = ctx->r23 | 0X30F;
L_80377DF8:
    // 0x80377DF8: bne         $t1, $t0, L_80377E14
    if (ctx->r9 != ctx->r8) {
        // 0x80377DFC: lui         $a3, 0x8039
        ctx->r7 = S32(0X8039 << 16);
            goto L_80377E14;
    }
    // 0x80377DFC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80377E00: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80377E04: addiu       $a3, $a3, -0x7728
    ctx->r7 = ADD32(ctx->r7, -0X7728);
    // 0x80377E08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80377E0C: b           L_80377E20
    // 0x80377E10: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_80377E20;
    // 0x80377E10: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_80377E14:
    // 0x80377E14: addiu       $a3, $a3, -0x7788
    ctx->r7 = ADD32(ctx->r7, -0X7788);
    // 0x80377E18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80377E1C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_80377E20:
    // 0x80377E20: lbu         $v0, 0x94($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X94);
    // 0x80377E24: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80377E28: addiu       $s5, $zero, 0x1000
    ctx->r21 = ADD32(0, 0X1000);
    // 0x80377E2C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80377E30: bne         $at, $zero, L_80377E40
    if (ctx->r1 != 0) {
        // 0x80377E34: lui         $s4, 0x8039
        ctx->r20 = S32(0X8039 << 16);
            goto L_80377E40;
    }
    // 0x80377E34: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x80377E38: sb          $t8, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r24;
    // 0x80377E3C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
L_80377E40:
    // 0x80377E40: blez        $v0, L_80377F08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80377E44: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80377F08;
    }
    // 0x80377E44: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80377E48: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377E4C: lwc1        $f20, -0x6C50($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6C50);
    // 0x80377E50: addiu       $s4, $s4, -0x77EC
    ctx->r20 = ADD32(ctx->r20, -0X77EC);
L_80377E54:
    // 0x80377E54: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x80377E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80377E5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80377E60: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80377E64: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80377E68: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80377E6C: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80377E70: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x80377E74: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x80377E78: sh          $fp, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r30;
    // 0x80377E7C: sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
    // 0x80377E80: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80377E84: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x80377E88: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80377E8C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80377E90: sw          $s7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r23;
    // 0x80377E94: swc1        $f20, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f20.u32l;
    // 0x80377E98: swc1        $f20, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f20.u32l;
    // 0x80377E9C: swc1        $f20, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f20.u32l;
    // 0x80377EA0: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
    // 0x80377EA4: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80377EA8: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80377EAC: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x80377EB0: sw          $t2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r10;
    // 0x80377EB4: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x80377EB8: sw          $t3, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r11;
    // 0x80377EBC: lw          $t2, 0xC($s4)
    ctx->r10 = MEM_W(ctx->r20, 0XC);
    // 0x80377EC0: sh          $s5, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r21;
    // 0x80377EC4: sw          $t2, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r10;
    // 0x80377EC8: sw          $s0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r16;
    // 0x80377ECC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80377ED0: sh          $v1, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r3;
    // 0x80377ED4: jal         0x80146088
    // 0x80377ED8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80146088)(rdram, ctx);
        goto after_0;
    // 0x80377ED8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    after_0:
    // 0x80377EDC: lbu         $t4, 0x94($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X94);
    // 0x80377EE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80377EE4: addu        $s6, $s6, $v0
    ctx->r22 = ADD32(ctx->r22, ctx->r2);
    // 0x80377EE8: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80377EEC: andi        $s6, $s6, 0xFF
    ctx->r22 = ctx->r22 & 0XFF;
    // 0x80377EF0: lhu         $v1, 0x58($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X58);
    // 0x80377EF4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80377EF8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80377EFC: bne         $at, $zero, L_80377E54
    if (ctx->r1 != 0) {
        // 0x80377F00: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_80377E54;
    }
    // 0x80377F00: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80377F04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80377F08:
    // 0x80377F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80377F0C: jal         0x80006214
    // 0x80377F10: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80377F10: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80377F14: lbu         $t5, 0x94($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X94);
    // 0x80377F18: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80377F1C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80377F20: blez        $t5, L_80377F8C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80377F24: addiu       $v1, $v1, -0x2578
        ctx->r3 = ADD32(ctx->r3, -0X2578);
            goto L_80377F8C;
    }
    // 0x80377F24: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x80377F28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80377F2C:
    // 0x80377F2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80377F30: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80377F34: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80377F38: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x80377F3C: lbu         $t7, 0x78($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X78);
    // 0x80377F40: sb          $t7, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r15;
    // 0x80377F44: lbu         $t8, 0x79($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X79);
    // 0x80377F48: sb          $t8, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r24;
    // 0x80377F4C: lbu         $t9, 0x7A($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X7A);
    // 0x80377F50: sb          $t9, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r25;
    // 0x80377F54: lbu         $t2, 0x7B($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X7B);
    // 0x80377F58: sb          $t2, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r10;
    // 0x80377F5C: lbu         $t3, 0x80($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X80);
    // 0x80377F60: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80377F64: lbu         $t4, 0x81($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X81);
    // 0x80377F68: sb          $t4, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r12;
    // 0x80377F6C: lbu         $t5, 0x82($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X82);
    // 0x80377F70: sb          $t5, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r13;
    // 0x80377F74: lbu         $t6, 0x83($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X83);
    // 0x80377F78: sb          $t6, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r14;
    // 0x80377F7C: lbu         $t7, 0x94($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X94);
    // 0x80377F80: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80377F84: bnel        $at, $zero, L_80377F2C
    if (ctx->r1 != 0) {
        // 0x80377F88: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80377F2C;
    }
    goto skip_0;
    // 0x80377F88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
L_80377F8C:
    // 0x80377F8C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80377F90: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80377F94: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80377F98: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80377F9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80377FA0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80377FA4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80377FA8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80377FAC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80377FB0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80377FB4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80377FB8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80377FBC: jr          $ra
    // 0x80377FC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80377FC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80377fc4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80377fc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377FC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377FCC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80377FD0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80377FD4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80377FD8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80377FDC: lw          $t7, 0x1CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1CEC);
    // 0x80377FE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80377FE4: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x80377FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377FEC: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80377FF0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80377FF4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80377FF8: jal         0x80377D68
    // 0x80377FFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    LOOKUP_FUNC(0x80377D68)(rdram, ctx);
        goto after_0;
    // 0x80377FFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_0:
    // 0x80378000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80378004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80378008: jr          $ra
    // 0x8037800C: nop

    return;
    // 0x8037800C: nop

;}
RECOMP_FUNC void M55_FUN_80378010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80378014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80378018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037801C: jal         0x800058DC
    // 0x80378020: lw          $a1, 0x8C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80378020: lw          $a1, 0x8C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8C);
    after_0:
    // 0x80378024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80378028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037802C: jr          $ra
    // 0x80378030: nop

    return;
    // 0x80378030: nop

;}
RECOMP_FUNC void M55_FUN_80378034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80378038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037803C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80378040: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80378044: lhu         $t6, 0x2C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2C);
    // 0x80378048: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8037804C: jal         0x80005700
    // 0x80378050: sh          $t7, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r15;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80378050: sh          $t7, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r15;
    after_0:
    // 0x80378054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80378058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037805C: jr          $ra
    // 0x80378060: nop

    return;
    // 0x80378060: nop

;}
RECOMP_FUNC void M55_FUN_80378064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378064: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80378068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037806C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80378070: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80378074: sb          $zero, 0x37($sp)
    MEM_B(0X37, ctx->r29) = 0;
    // 0x80378078: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037807C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80378080: sb          $t6, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r14;
    // 0x80378084: addiu       $a1, $zero, 0x371
    ctx->r5 = ADD32(0, 0X371);
    // 0x80378088: addiu       $a3, $sp, 0x37
    ctx->r7 = ADD32(ctx->r29, 0X37);
    // 0x8037808C: jal         0x80377FC4
    // 0x80378090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80377FC4)(rdram, ctx);
        goto after_0;
    // 0x80378090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80378094: beq         $v0, $zero, L_803780A8
    if (ctx->r2 == 0) {
        // 0x80378098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_803780A8;
    }
    // 0x80378098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037809C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803780A0: jal         0x800058DC
    // 0x803780A4: addiu       $a1, $a1, -0x7FCC
    ctx->r5 = ADD32(ctx->r5, -0X7FCC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x803780A4: addiu       $a1, $a1, -0x7FCC
    ctx->r5 = ADD32(ctx->r5, -0X7FCC);
    after_1:
L_803780A8:
    // 0x803780A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x803780AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x803780B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803780B4: addiu       $a1, $zero, 0x371
    ctx->r5 = ADD32(0, 0X371);
    // 0x803780B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803780BC: jal         0x8012D814
    // 0x803780C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_2;
    // 0x803780C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x803780C4: jal         0x80006214
    // 0x803780C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x803780C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803780CC: lbu         $t8, 0x94($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X94);
    // 0x803780D0: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x803780D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x803780D8: blez        $t8, L_80378154
    if (SIGNED(ctx->r24) <= 0) {
        // 0x803780DC: ori         $a3, $a3, 0xCCCD
        ctx->r7 = ctx->r7 | 0XCCCD;
            goto L_80378154;
    }
    // 0x803780DC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x803780E0: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x803780E4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x803780E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803780EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x803780F0: ldc1        $f0, -0x6C48($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6C48);
    // 0x803780F4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x803780F8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
L_803780FC:
    // 0x803780FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80378100: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80378104: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80378108: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8037810C: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80378110: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80378114: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80378118: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8037811C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80378120: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80378124: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80378128: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x8037812C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80378130: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80378134: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80378138: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037813C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80378140: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80378144: lbu         $t0, 0x94($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X94);
    // 0x80378148: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8037814C: bnel        $at, $zero, L_803780FC
    if (ctx->r1 != 0) {
        // 0x80378150: lw          $t9, 0x0($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X0);
            goto L_803780FC;
    }
    goto skip_0;
    // 0x80378150: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_80378154:
    // 0x80378154: lbu         $a0, 0x78($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X78);
    // 0x80378158: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x8037815C: jal         0x801CD924
    // 0x80378160: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    LOOKUP_FUNC(0x801CD924)(rdram, ctx);
        goto after_4;
    // 0x80378160: lbu         $a2, 0x7A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X7A);
    after_4:
    // 0x80378164: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378168: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037816C: sh          $zero, -0x5708($at)
    MEM_H(-0X5708, ctx->r1) = 0;
    // 0x80378170: addiu       $a1, $a1, -0x7E70
    ctx->r5 = ADD32(ctx->r5, -0X7E70);
    // 0x80378174: jal         0x800058DC
    // 0x80378178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80378178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8037817C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80378180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80378184: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80378188: jr          $ra
    // 0x8037818C: nop

    return;
    // 0x8037818C: nop

;}
RECOMP_FUNC void M55_FUN_80378190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378190: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80378194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80378198: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037819C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803781A0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x803781A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803781A8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x803781AC: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x803781B0: jal         0x8012D7A8
    // 0x803781B4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8012D7A8)(rdram, ctx);
        goto after_0;
    // 0x803781B4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x803781B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803781BC: jal         0x801CD878
    // 0x803781C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801CD878)(rdram, ctx);
        goto after_1;
    // 0x803781C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x803781C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803781C8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803781CC: lw          $t0, 0xDC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XDC);
    // 0x803781D0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x803781D4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x803781D8: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x803781DC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803781E0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x803781E4: lbu         $t9, 0x4C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4C);
    // 0x803781E8: sb          $t9, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r25;
    // 0x803781EC: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x803781F0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x803781F4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x803781F8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x803781FC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80378200: lbu         $t5, 0x4D($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4D);
    // 0x80378204: sb          $t5, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r13;
    // 0x80378208: lw          $t2, 0xDC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XDC);
    // 0x8037820C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80378210: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x80378214: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80378218: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8037821C: lbu         $t9, 0x4E($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X4E);
    // 0x80378220: sb          $t9, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r25;
    // 0x80378224: lw          $t8, 0xDC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XDC);
    // 0x80378228: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8037822C: lw          $t0, 0x24($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X24);
    // 0x80378230: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80378234: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80378238: lbu         $t5, 0x4F($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X4F);
    // 0x8037823C: sb          $t5, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r13;
    // 0x80378240: lbu         $a3, 0x4B($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X4B);
    // 0x80378244: lbu         $a2, 0x4A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4A);
    // 0x80378248: lbu         $a1, 0x49($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X49);
    // 0x8037824C: jal         0x801CD994
    // 0x80378250: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    LOOKUP_FUNC(0x801CD994)(rdram, ctx);
        goto after_2;
    // 0x80378250: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    after_2:
    // 0x80378254: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x80378258: lhu         $t2, 0x90($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X90);
    // 0x8037825C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80378260: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80378264: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80378268: slt         $v1, $t3, $v0
    ctx->r3 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037826C: bne         $v1, $zero, L_80378284
    if (ctx->r3 != 0) {
        // 0x80378270: sh          $t9, 0x92($s0)
        MEM_H(0X92, ctx->r16) = ctx->r25;
            goto L_80378284;
    }
    // 0x80378270: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
    // 0x80378274: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80378278: lhu         $t6, 0x2C($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X2C);
    // 0x8037827C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80378280: beq         $t7, $zero, L_803782D4
    if (ctx->r15 == 0) {
        // 0x80378284: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_803782D4;
    }
L_80378284:
    // 0x80378284: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
L_80378288:
    // 0x80378288: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x8037828C: lbu         $t8, 0x78($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X78);
    // 0x80378290: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x80378294: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80378298: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8037829C: lbu         $t0, 0x7C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7C);
    // 0x803782A0: lbu         $t1, 0x80($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X80);
    // 0x803782A4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x803782A8: sb          $t0, 0x78($v0)
    MEM_B(0X78, ctx->r2) = ctx->r8;
    // 0x803782AC: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x803782B0: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x803782B4: sb          $t5, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r13;
    // 0x803782B8: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x803782BC: lbu         $t2, 0x84($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X84);
    // 0x803782C0: sb          $t2, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r10;
    // 0x803782C4: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x803782C8: sb          $t3, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r11;
    // 0x803782CC: bne         $at, $zero, L_80378288
    if (ctx->r1 != 0) {
        // 0x803782D0: sh          $zero, 0x92($s0)
        MEM_H(0X92, ctx->r16) = 0;
            goto L_80378288;
    }
    // 0x803782D0: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
L_803782D4:
    // 0x803782D4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803782D8: addiu       $a0, $a0, -0x5708
    ctx->r4 = ADD32(ctx->r4, -0X5708);
    // 0x803782DC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x803782E0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803782E4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x803782E8: slti        $v1, $v0, 0x50
    ctx->r3 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x803782EC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x803782F0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x803782F4: beq         $v1, $zero, L_80378300
    if (ctx->r3 == 0) {
        // 0x803782F8: sh          $t9, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r25;
            goto L_80378300;
    }
    // 0x803782F8: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x803782FC: sb          $zero, -0x781C($at)
    MEM_B(-0X781C, ctx->r1) = 0;
L_80378300:
    // 0x80378300: lbu         $t4, -0x781C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X781C);
    // 0x80378304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378308: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037830C: bnel        $t4, $zero, L_80378320
    if (ctx->r12 != 0) {
        // 0x80378310: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80378320;
    }
    goto skip_0;
    // 0x80378310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80378314: jal         0x800058DC
    // 0x80378318: addiu       $a1, $a1, -0x7FCC
    ctx->r5 = ADD32(ctx->r5, -0X7FCC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80378318: addiu       $a1, $a1, -0x7FCC
    ctx->r5 = ADD32(ctx->r5, -0X7FCC);
    after_3:
    // 0x8037831C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80378320:
    // 0x80378320: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80378324: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80378328: jr          $ra
    // 0x8037832C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037832C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378330(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378330: jr          $ra
    // 0x80378334: nop

    return;
    // 0x80378334: nop

;}
RECOMP_FUNC void M55_FUN_80378338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378338: nop

    // 0x8037833C: nop

;}
RECOMP_FUNC void M55_FUN_80378340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80378344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80378348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037834C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80378350: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80378354: jal         0x80149330
    // 0x80378358: lbu         $a0, -0x56F6($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X56F6);
    LOOKUP_FUNC(0x80149330)(rdram, ctx);
        goto after_0;
    // 0x80378358: lbu         $a0, -0x56F6($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X56F6);
    after_0:
    // 0x8037835C: beql        $v0, $zero, L_80378370
    if (ctx->r2 == 0) {
        // 0x80378360: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80378370;
    }
    goto skip_0;
    // 0x80378360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80378364: jal         0x80005700
    // 0x80378368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80378368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8037836C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80378370:
    // 0x80378370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80378374: jr          $ra
    // 0x80378378: nop

    return;
    // 0x80378378: nop

;}
RECOMP_FUNC void M55_FUN_8037837c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037837C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80378380: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80378384: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80378388: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8037838C: addiu       $t6, $zero, 0xA6
    ctx->r14 = ADD32(0, 0XA6);
    // 0x80378390: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80378394: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80378398: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037839C: addiu       $t0, $zero, 0xCB
    ctx->r8 = ADD32(0, 0XCB);
    // 0x803783A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803783A4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x803783A8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x803783AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x803783B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803783B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803783B8: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x803783BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x803783C0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x803783C4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x803783C8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x803783CC: jal         0x802169AC
    // 0x803783D0: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x802169AC)(rdram, ctx);
        goto after_0;
    // 0x803783D0: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_0:
    // 0x803783D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803783D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x803783DC: jal         0x80145348
    // 0x803783E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_1;
    // 0x803783E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x803783E4: addiu       $t1, $zero, 0xA6
    ctx->r9 = ADD32(0, 0XA6);
    // 0x803783E8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x803783EC: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x803783F0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x803783F4: addiu       $t5, $zero, 0xCB
    ctx->r13 = ADD32(0, 0XCB);
    // 0x803783F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x803783FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80378400: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80378404: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80378408: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8037840C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80378410: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80378414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378418: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x8037841C: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    // 0x80378420: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80378424: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80378428: jal         0x802169AC
    // 0x8037842C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x802169AC)(rdram, ctx);
        goto after_2;
    // 0x8037842C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x80378430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378434: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80378438: jal         0x80145348
    // 0x8037843C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_3;
    // 0x8037843C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80378440: addiu       $t7, $zero, 0xA6
    ctx->r15 = ADD32(0, 0XA6);
    // 0x80378444: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80378448: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8037844C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80378450: addiu       $t1, $zero, 0xCB
    ctx->r9 = ADD32(0, 0XCB);
    // 0x80378454: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80378458: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8037845C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80378460: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80378464: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80378468: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8037846C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80378470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378474: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x80378478: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037847C: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    // 0x80378480: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80378484: jal         0x802169AC
    // 0x80378488: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x802169AC)(rdram, ctx);
        goto after_4;
    // 0x80378488: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x8037848C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378490: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80378494: jal         0x80145348
    // 0x80378498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_5;
    // 0x80378498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8037849C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803784A0: addiu       $a1, $a1, -0x7B40
    ctx->r5 = ADD32(ctx->r5, -0X7B40);
    // 0x803784A4: jal         0x800058DC
    // 0x803784A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x803784A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x803784AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x803784B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x803784B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x803784B8: jr          $ra
    // 0x803784BC: nop

    return;
    // 0x803784BC: nop

;}
RECOMP_FUNC void M55_FUN_803784c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803784C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803784C4: jr          $ra
    // 0x803784C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x803784C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803784cc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803784cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803784CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803784D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803784D4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x803784D8: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x803784DC: lbu         $t7, 0x182($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X182);
    // 0x803784E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803784E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803784E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803784EC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x803784F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803784F4: bne         $t7, $zero, L_8037879C
    if (ctx->r15 != 0) {
            // 0x803784F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8037879C)(rdram, ctx);
    return;
    }
    // 0x803784F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x803784FC: lbu         $t8, 0x187($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X187);
    // 0x80378500: bnel        $t8, $zero, L_803787A0
    if (ctx->r24 != 0) {
            // 0x80378504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x803787A0)(rdram, ctx);
    return;
    }
    goto skip_0;
    // 0x80378504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80378508: jal         0x8001F75C
    // 0x8037850C: lw          $a0, 0xDC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XDC);
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_0;
    // 0x8037850C: lw          $a0, 0xDC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XDC);
    after_0:
    // 0x80378510: jal         0x8001F6E4
    // 0x80378514: nop

    LOOKUP_FUNC(0x8001F6E4)(rdram, ctx);
        goto after_1;
    // 0x80378514: nop

    after_1:
    // 0x80378518: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037851C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80378520: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378524: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80378528: ori         $t0, $t9, 0xE0
    ctx->r8 = ctx->r25 | 0XE0;
    // 0x8037852C: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x80378530: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80378534: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80378538: lhu         $t1, 0xEF0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XEF0);
    // 0x8037853C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80378540: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
    // 0x80378544: ori         $t2, $t1, 0xC0
    ctx->r10 = ctx->r9 | 0XC0;
    // 0x80378548: sh          $t2, 0xEF0($s1)
    MEM_H(0XEF0, ctx->r17) = ctx->r10;
    // 0x8037854C: sh          $zero, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = 0;
    // 0x80378550: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378554: sw          $zero, -0x5700($at)
    MEM_W(-0X5700, ctx->r1) = 0;
    // 0x80378558: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037855C: sh          $zero, -0x56F8($at)
    MEM_H(-0X56F8, ctx->r1) = 0;
    // 0x80378560: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378564: sb          $zero, -0x56F6($at)
    MEM_B(-0X56F6, ctx->r1) = 0;
    // 0x80378568: jal         0x80126A0C
    // 0x8037856C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_2;
    // 0x8037856C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80378570: beq         $v0, $zero, L_8037879C
    if (ctx->r2 == 0) {
            // 0x80378574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8037879C)(rdram, ctx);
    return;
    }
    // 0x80378574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80378578: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037857C: jal         0x800113D0
    // 0x80378580: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_3;
    // 0x80378580: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    after_3:
    // 0x80378584: jal         0x80116E80
    // 0x80378588: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_4;
    // 0x80378588: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x8037858C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80378590: jal         0x80011198
    // 0x80378594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_5;
    // 0x80378594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80378598: jal         0x8014C068
    // 0x8037859C: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    LOOKUP_FUNC(0x8014C068)(rdram, ctx);
        goto after_6;
    // 0x8037859C: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    after_6:
    // 0x803785A0: beq         $v0, $zero, L_8037873C
    if (ctx->r2 == 0) {
            // 0x803785A4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x8037873C)(rdram, ctx);
    return;
    }
    // 0x803785A4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x803785A8: jal         0x8014C1F0
    // 0x803785AC: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_7;
    // 0x803785AC: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    after_7:
    // 0x803785B0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x803785B4: beq         $v1, $zero, L_803786B0
    if (ctx->r3 == 0) {
            // 0x803785B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x803786B0)(rdram, ctx);
    return;
    }
    // 0x803785B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x803785BC: beq         $v1, $at, L_80378628
    if (ctx->r3 == ctx->r1) {
        // 0x803785C0: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_80378628;
    }
    // 0x803785C0: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x803785C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803785C8: bne         $v1, $at, L_803786B0
    if (ctx->r3 != ctx->r1) {
            // 0x803785CC: nop

    LOOKUP_FUNC(0x803786B0)(rdram, ctx);
    return;
    }
    // 0x803785CC: nop

    // 0x803785D0: lhu         $t3, 0x244($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X244);
    // 0x803785D4: lui         $t4, 0x8021
    ctx->r12 = S32(0X8021 << 16);
    // 0x803785D8: addiu       $t4, $t4, 0x6B90
    ctx->r12 = ADD32(ctx->r12, 0X6B90);
    // 0x803785DC: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    // 0x803785E0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x803785E4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x803785E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x803785EC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x803785F0: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x803785F4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x803785F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803785FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80378600: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80378604: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80378608: jal         0x80011140
    // 0x8037860C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_8;
    // 0x8037860C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_8:
    // 0x80378610: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80378614: addiu       $a1, $a1, 0x6B80
    ctx->r5 = ADD32(ctx->r5, 0X6B80);
    // 0x80378618: jal         0x800058DC
    // 0x8037861C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x8037861C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80378620: b           L_803787A0
    // 0x80378624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x803787A0)(rdram, ctx);
    return;
    // 0x80378624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80378628:
    // 0x80378628: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037862C: addiu       $v0, $v0, -0x56FC
    ctx->r2 = ADD32(ctx->r2, -0X56FC);
    // 0x80378630: addiu       $t8, $t8, -0x766C
    ctx->r24 = ADD32(ctx->r24, -0X766C);
    // 0x80378634: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80378638: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x8037863C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80378640: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80378644: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x80378648: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8037864C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80378650: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80378654: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80378658: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037865c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037865c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037865C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80378660: jal         0x80011140
    // 0x80378664: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80378664: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x80378668: jal         0x8014B3F0
    // 0x8037866C: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    LOOKUP_FUNC(0x8014B3F0)(rdram, ctx);
        goto after_1;
    // 0x8037866C: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    after_1:
    // 0x80378670: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378674: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80378678: sb          $v0, -0x56F6($at)
    MEM_B(-0X56F6, ctx->r1) = ctx->r2;
    // 0x8037867C: addiu       $a1, $a1, -0x76AC
    ctx->r5 = ADD32(ctx->r5, -0X76AC);
    // 0x80378680: jal         0x80005670
    // 0x80378684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x80378684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80378688: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8037868C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80378690: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80378694: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80378698: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8037869C: addiu       $a1, $a1, -0x7810
    ctx->r5 = ADD32(ctx->r5, -0X7810);
    // 0x803786A0: jal         0x800058DC
    // 0x803786A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x803786A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803786A8: b           L_803787A0
    // 0x803786AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x803787A0)(rdram, ctx);
    return;
    // 0x803786AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803786b0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803786b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803786B0: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x803786B4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803786B8: addiu       $v0, $v0, -0x56FC
    ctx->r2 = ADD32(ctx->r2, -0X56FC);
    // 0x803786BC: addiu       $t6, $t6, -0x7684
    ctx->r14 = ADD32(ctx->r14, -0X7684);
    // 0x803786C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x803786C4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x803786C8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x803786CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x803786D0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x803786D4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x803786D8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x803786DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803786E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x803786E4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x803786E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x803786EC: jal         0x80011140
    // 0x803786F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x803786F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x803786F4: jal         0x8014B3F0
    // 0x803786F8: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    LOOKUP_FUNC(0x8014B3F0)(rdram, ctx);
        goto after_1;
    // 0x803786F8: lhu         $a0, 0x244($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X244);
    after_1:
    // 0x803786FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378700: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80378704: sb          $v0, -0x56F6($at)
    MEM_B(-0X56F6, ctx->r1) = ctx->r2;
    // 0x80378708: addiu       $a1, $a1, -0x76AC
    ctx->r5 = ADD32(ctx->r5, -0X76AC);
    // 0x8037870C: jal         0x80005670
    // 0x80378710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x80378710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80378714: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x80378718: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8037871C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80378720: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80378724: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x80378728: addiu       $a1, $a1, -0x7810
    ctx->r5 = ADD32(ctx->r5, -0X7810);
    // 0x8037872C: jal         0x800058DC
    // 0x80378730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80378730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80378734: b           L_803787A0
    // 0x80378738: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x803787A0)(rdram, ctx);
    return;
    // 0x80378738: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037873c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037873c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037873C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80378740: addiu       $v0, $v0, -0x56FC
    ctx->r2 = ADD32(ctx->r2, -0X56FC);
    // 0x80378744: addiu       $t4, $t4, -0x7684
    ctx->r12 = ADD32(ctx->r12, -0X7684);
    // 0x80378748: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8037874C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80378750: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80378754: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80378758: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8037875C: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x80378760: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378764(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378764: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80378768: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037876C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x80378770: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80378774: jal         0x80011140
    // 0x80378778: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80378778: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8037877C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80378780: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80378784: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80378788: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8037878C: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x80378790: addiu       $a1, $a1, -0x7810
    ctx->r5 = ADD32(ctx->r5, -0X7810);
    // 0x80378794: jal         0x800058DC
    // 0x80378798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80378798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037879c(rdram, ctx);
;}
