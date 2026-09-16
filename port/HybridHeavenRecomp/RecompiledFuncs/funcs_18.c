#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80117204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117204: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80117208: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8011720C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80117210: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80117214:
    // 0x80117214: and         $t6, $a1, $v0
    ctx->r14 = ctx->r5 & ctx->r2;
    // 0x80117218: bne         $t6, $zero, L_80117234
    if (ctx->r14 != 0) {
        // 0x8011721C: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_80117234;
    }
    // 0x8011721C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80117220: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80117224: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80117228: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8011722C: bne         $at, $zero, L_80117214
    if (ctx->r1 != 0) {
        // 0x80117230: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_80117214;
    }
    // 0x80117230: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80117234:
    // 0x80117234: jr          $ra
    // 0x80117238: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80117238: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8011723c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8011723c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011723C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80117240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80117244: jal         0x80005E44
    // 0x80117248: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80117248: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8011724C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80117250: addiu       $a1, $a1, 0x744C
    ctx->r5 = ADD32(ctx->r5, 0X744C);
    // 0x80117254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80117258: jal         0x800058DC
    // 0x8011725C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8011725C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80117260: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80117264: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x80117268: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x8011726C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80117270: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80117274: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80117278: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8011727C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80117280: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x80117284: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80117288: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8011728C: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x80117290: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80117294: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x80117298: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8011729C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801172A0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x801172A4: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x801172A8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801172AC: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x801172B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801172B4: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x801172B8: sh          $t0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r8;
    // 0x801172BC: lw          $t3, 0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XE8);
    // 0x801172C0: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x801172C4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801172C8: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801172CC: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x801172D0: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x801172D4: sw          $t5, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r13;
    // 0x801172D8: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x801172DC: sw          $t6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r14;
    // 0x801172E0: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x801172E4: sw          $t5, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r13;
    // 0x801172E8: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801172EC: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801172F0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801172F4: lhu         $t9, 0x18($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X18);
    // 0x801172F8: sh          $t9, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r25;
    // 0x801172FC: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x80117300: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x80117304: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x80117308: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8011730C: swc1        $f4, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f4.u32l;
    // 0x80117310: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x80117314: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80117318: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8011731C: lwc1        $f6, 0x20($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X20);
    // 0x80117320: swc1        $f6, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f6.u32l;
    // 0x80117324: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x80117328: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x8011732C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80117330: lwc1        $f8, 0x24($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X24);
    // 0x80117334: swc1        $f8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f8.u32l;
    // 0x80117338: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x8011733C: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80117340: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80117344: lwc1        $f10, 0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X28);
    // 0x80117348: swc1        $f10, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f10.u32l;
    // 0x8011734C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x80117350: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x80117354: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x80117358: lwc1        $f16, 0x2C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X2C);
    // 0x8011735C: swc1        $f16, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f16.u32l;
    // 0x80117360: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x80117364: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80117368: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8011736C: lwc1        $f18, 0x30($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80117370: swc1        $f18, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f18.u32l;
    // 0x80117374: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x80117378: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x8011737C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80117380: lwc1        $f4, 0x34($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80117384: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x80117388: lw          $t3, 0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XE8);
    // 0x8011738C: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x80117390: lw          $t2, 0x2C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2C);
    // 0x80117394: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x80117398: swc1        $f6, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f6.u32l;
    // 0x8011739C: lw          $t5, 0xE8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XE8);
    // 0x801173A0: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801173A4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801173A8: lwc1        $f8, 0x3C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x801173AC: swc1        $f8, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f8.u32l;
    // 0x801173B0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801173B4: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801173B8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801173BC: lwc1        $f10, 0x40($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X40);
    // 0x801173C0: swc1        $f10, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f10.u32l;
    // 0x801173C4: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801173C8: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x801173CC: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801173D0: lwc1        $f16, 0x44($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X44);
    // 0x801173D4: swc1        $f16, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f16.u32l;
    // 0x801173D8: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801173DC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801173E0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801173E4: lwc1        $f18, 0x48($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X48);
    // 0x801173E8: swc1        $f18, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f18.u32l;
    // 0x801173EC: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801173F0: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x801173F4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801173F8: lwc1        $f4, 0x4C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x801173FC: swc1        $f4, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f4.u32l;
    // 0x80117400: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x80117404: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80117408: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8011740C: lwc1        $f6, 0x50($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X50);
    // 0x80117410: swc1        $f6, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f6.u32l;
    // 0x80117414: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x80117418: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x8011741C: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x80117420: lwc1        $f8, 0x54($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X54);
    // 0x80117424: swc1        $f8, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f8.u32l;
    // 0x80117428: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x8011742C: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80117430: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80117434: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x80117438: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8011743C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80117440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80117444: jr          $ra
    // 0x80117448: nop

    return;
    // 0x80117448: nop

;}
RECOMP_FUNC void M7_FUN_8011744c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011744C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80117450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80117454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80117458: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8011745C: jal         0x80117204
    // 0x80117460: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80117204)(rdram, ctx);
        goto after_0;
    // 0x80117460: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x80117464: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80117468: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x8011746C: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x80117470: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80117474: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80117478: lw          $t8, 0x258($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X258);
    // 0x8011747C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80117480: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x80117484: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80117488: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8011748C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x80117490: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80117494: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80117498: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x8011749C: lw          $t5, 0xE8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XE8);
    // 0x801174A0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801174A4: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x801174A8: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x801174AC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801174B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801174B4: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x801174B8: sh          $t0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r8;
    // 0x801174BC: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801174C0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801174C4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801174C8: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x801174CC: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801174D0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x801174D4: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x801174D8: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x801174DC: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x801174E0: sw          $t3, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r11;
    // 0x801174E4: lw          $t5, 0xE8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XE8);
    // 0x801174E8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801174EC: lhu         $t7, 0x18($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X18);
    // 0x801174F0: sh          $t7, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r15;
    // 0x801174F4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801174F8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801174FC: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80117500: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80117504: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x80117508: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8011750C: lwc1        $f6, 0x20($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80117510: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x80117514: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x80117518: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8011751C: lwc1        $f8, 0x24($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X24);
    // 0x80117520: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x80117524: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x80117528: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8011752C: lwc1        $f10, 0x28($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X28);
    // 0x80117530: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x80117534: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x80117538: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8011753C: lwc1        $f16, 0x2C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80117540: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x80117544: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x80117548: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8011754C: lwc1        $f18, 0x30($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X30);
    // 0x80117550: swc1        $f18, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f18.u32l;
    // 0x80117554: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x80117558: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8011755C: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x80117560: swc1        $f4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f4.u32l;
    // 0x80117564: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x80117568: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8011756C: lwc1        $f6, 0x38($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80117570: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x80117574: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x80117578: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8011757C: lwc1        $f8, 0x3C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x80117580: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80117584: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x80117588: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8011758C: lwc1        $f10, 0x40($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X40);
    // 0x80117590: swc1        $f10, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f10.u32l;
    // 0x80117594: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x80117598: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8011759C: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x801175A0: swc1        $f16, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f16.u32l;
    // 0x801175A4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801175A8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801175AC: lwc1        $f18, 0x48($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X48);
    // 0x801175B0: swc1        $f18, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f18.u32l;
    // 0x801175B4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801175B8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801175BC: lwc1        $f4, 0x4C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x801175C0: swc1        $f4, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f4.u32l;
    // 0x801175C4: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801175C8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801175CC: lwc1        $f6, 0x50($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X50);
    // 0x801175D0: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x801175D4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801175D8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801175DC: lwc1        $f8, 0x54($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X54);
    // 0x801175E0: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
    // 0x801175E4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801175E8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801175EC: lw          $t0, 0x58($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X58);
    // 0x801175F0: sw          $t0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r8;
    // 0x801175F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801175F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801175FC: jr          $ra
    // 0x80117600: nop

    return;
    // 0x80117600: nop

;}
RECOMP_FUNC void M7_FUN_80117604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117604: nop

    // 0x80117608: nop

    // 0x8011760C: nop

;}
RECOMP_FUNC void M7_FUN_80117610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117610: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80117614: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80117618: lhu         $t6, 0x18E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X18E);
    // 0x8011761C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80117620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80117624: bne         $t6, $zero, L_80117644
    if (ctx->r14 != 0) {
            // 0x80117628: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80117644)(rdram, ctx);
    return;
    }
    // 0x80117628: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8011762C: sh          $a0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r4;
    // 0x80117630: sh          $t7, 0x190($v1)
    MEM_H(0X190, ctx->r3) = ctx->r15;
    // 0x80117634: sh          $a0, 0x1D8($v1)
    MEM_H(0X1D8, ctx->r3) = ctx->r4;
    // 0x80117638: sh          $zero, 0x1DC($v1)
    MEM_H(0X1DC, ctx->r3) = 0;
    // 0x8011763C: jr          $ra
    // 0x80117640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80117640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80117644(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80117644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80117648: jr          $ra
    // 0x8011764C: nop

    return;
    // 0x8011764C: nop

;}
RECOMP_FUNC void M7_FUN_80117650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117650: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80117654: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80117658: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8011765C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80117660: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80117664: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80117668: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8011766C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80117670: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80117674: sub.s       $f16, $f24, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80117678: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8011767C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80117680: sub.s       $f2, $f14, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80117684: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80117688: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8011768C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80117690: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80117694: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x80117698: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x8011769C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x801176A0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801176A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801176A8: jal         0x8002FC20
    // 0x801176AC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801176AC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x801176B0: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801176B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801176B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801176BC: sub.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x801176C0: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801176C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801176C8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801176CC: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801176D0: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x801176D4: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x801176D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801176DC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x801176E0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801176E4: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x801176E8: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801176EC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801176F0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801176F4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801176F8: sub.s       $f18, $f6, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x801176FC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80117700: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80117704: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80117708: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x8011770C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80117710: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80117714: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x80117718: jal         0x8010843C
    // 0x8011771C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_1;
    // 0x8011771C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80117720: beq         $v0, $zero, L_80117760
    if (ctx->r2 == 0) {
        // 0x80117724: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80117760;
    }
    // 0x80117724: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80117728: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8011772C: lwc1        $f6, 0x380($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X380);
    // 0x80117730: lwc1        $f8, 0x384($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X384);
    // 0x80117734: lwc1        $f10, 0x388($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X388);
    // 0x80117738: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x8011773C: sub.s       $f2, $f22, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x80117740: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80117744: sub.s       $f14, $f24, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x80117748: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011774C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80117750: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80117754: jal         0x8002FC20
    // 0x80117758: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x80117758: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x8011775C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
L_80117760:
    // 0x80117760: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80117764: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80117768: jal         0x8002FC20
    // 0x8011776C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x8011776C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x80117770: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80117774: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80117778: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8011777C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80117780: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80117784: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80117788: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8011778C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80117790: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80117794: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80117798: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8011779C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801177A0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801177A4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x801177A8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801177AC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801177B0: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x801177B4: jal         0x8010843C
    // 0x801177B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_4;
    // 0x801177B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801177BC: beq         $v0, $zero, L_80117800
    if (ctx->r2 == 0) {
        // 0x801177C0: lwc1        $f2, 0x54($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80117800;
    }
    // 0x801177C0: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801177C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801177C8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801177CC: lwc1        $f8, 0x380($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X380);
    // 0x801177D0: lwc1        $f10, 0x384($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X384);
    // 0x801177D4: lwc1        $f4, 0x388($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X388);
    // 0x801177D8: sub.s       $f0, $f20, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x801177DC: sub.s       $f2, $f22, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x801177E0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801177E4: sub.s       $f14, $f24, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x801177E8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801177EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801177F0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801177F4: jal         0x8002FC20
    // 0x801177F8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_5;
    // 0x801177F8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_5:
    // 0x801177FC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80117800:
    // 0x80117800: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80117804: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80117808: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8011780C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80117810: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80117814: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80117818: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8011781C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80117820: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80117824: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80117828: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8011782C: addiu       $a3, $a3, -0x6AC0
    ctx->r7 = ADD32(ctx->r7, -0X6AC0);
    // 0x80117830: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80117834: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80117838: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8011783C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80117840: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80117844: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80117848: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8011784C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80117850: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80117854: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80117858: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8011785C: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80117860: mfhi        $t0
    ctx->r8 = hi;
    // 0x80117864: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80117868: bne         $v0, $zero, L_80117874
    if (ctx->r2 != 0) {
        // 0x8011786C: nop
    
            goto L_80117874;
    }
    // 0x8011786C: nop

    // 0x80117870: break       7
    do_break(2148628592);
L_80117874:
    // 0x80117874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80117878: bne         $v0, $at, L_8011788C
    if (ctx->r2 != ctx->r1) {
        // 0x8011787C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8011788C;
    }
    // 0x8011787C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80117880: bne         $t9, $at, L_8011788C
    if (ctx->r25 != ctx->r1) {
        // 0x80117884: nop
    
            goto L_8011788C;
    }
    // 0x80117884: nop

    // 0x80117888: break       6
    do_break(2148628616);
L_8011788C:
    // 0x8011788C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80117890: nop

    // 0x80117894: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x80117898: mfhi        $t5
    ctx->r13 = hi;
    // 0x8011789C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x801178A0: bne         $v0, $zero, L_801178AC
    if (ctx->r2 != 0) {
        // 0x801178A4: nop
    
            goto L_801178AC;
    }
    // 0x801178A4: nop

    // 0x801178A8: break       7
    do_break(2148628648);
L_801178AC:
    // 0x801178AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801178B0: bne         $v0, $at, L_801178C4
    if (ctx->r2 != ctx->r1) {
        // 0x801178B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801178C4;
    }
    // 0x801178B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801178B8: bne         $t4, $at, L_801178C4
    if (ctx->r12 != ctx->r1) {
        // 0x801178BC: nop
    
            goto L_801178C4;
    }
    // 0x801178BC: nop

    // 0x801178C0: break       6
    do_break(2148628672);
L_801178C4:
    // 0x801178C4: jal         0x8001DFFC
    // 0x801178C8: nop

    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_6;
    // 0x801178C8: nop

    after_6:
    // 0x801178CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801178D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801178D4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801178D8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801178DC: jr          $ra
    // 0x801178E0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801178E0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801178e4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801178e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801178E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801178E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801178EC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801178F0: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801178F4: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801178F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801178FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80117900: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80117904: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80117908: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8011790C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80117910: jal         0x8001EAD0
    // 0x80117914: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80117914: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x80117918: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8011791C: ldc1        $f6, -0x64E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X64E0);
    // 0x80117920: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x80117924: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80117928: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8011792C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80117930: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80117934: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80117938: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8011793C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80117940: sub.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d - ctx->f8.d;
    // 0x80117944: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80117948: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8011794C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80117950: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80117954: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x80117958: lwc1        $f18, 0x320($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X320);
    // 0x8011795C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80117960: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80117964: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80117968: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8011796C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80117970: add.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f10.d + ctx->f16.d;
    // 0x80117974: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80117978: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8011797C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80117980: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x80117984: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80117988: jal         0x8001EB64
    // 0x8011798C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8011798C: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_1:
    // 0x80117990: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80117994: ldc1        $f18, -0x64D8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X64D8);
    // 0x80117998: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x8011799C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801179A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801179A4: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x801179A8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801179AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x801179B0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x801179B4: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801179B8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801179BC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801179C0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801179C4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801179C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801179CC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801179D0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801179D4: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x801179D8: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801179DC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801179E0: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801179E4: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x801179E8: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801179EC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801179F0: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801179F4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801179F8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801179FC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80117A00: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80117A04: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x80117A08: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80117A0C: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80117A10: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80117A14: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80117A18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80117A1C: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80117A20: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80117A24: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80117A28: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80117A2C: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x80117A30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80117A34: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80117A38: jal         0x801084C4
    // 0x80117A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_2;
    // 0x80117A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80117A40: beq         $v0, $zero, L_80117A68
    if (ctx->r2 == 0) {
        // 0x80117A44: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80117A68;
    }
    // 0x80117A44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80117A48: lwc1        $f8, 0x374($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X374);
    // 0x80117A4C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x80117A50: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80117A54: lwc1        $f10, 0x378($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X378);
    // 0x80117A58: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80117A5C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80117A60: lwc1        $f16, 0x37C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X37C);
    // 0x80117A64: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
L_80117A68:
    // 0x80117A68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80117A6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80117A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80117A74: jr          $ra
    // 0x80117A78: nop

    return;
    // 0x80117A78: nop

;}
RECOMP_FUNC void M7_FUN_80117a7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80117A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80117A84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80117A88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80117A8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80117A90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80117A94: jal         0x8001EB64
    // 0x80117A98: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80117A98: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80117A9C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80117AA0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80117AA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80117AA8: ldc1        $f6, -0x64D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X64D0);
    // 0x80117AAC: lw          $t6, 0xE0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE0);
    // 0x80117AB0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80117AB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80117AB8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80117ABC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80117AC0: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80117AC4: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80117AC8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80117ACC: sub.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d - ctx->f8.d;
    // 0x80117AD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80117AD4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80117AD8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80117ADC: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80117AE0: lw          $t9, 0xE0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE0);
    // 0x80117AE4: lwc1        $f18, 0x320($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X320);
    // 0x80117AE8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80117AEC: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x80117AF0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80117AF4: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80117AF8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80117AFC: add.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f10.d + ctx->f16.d;
    // 0x80117B00: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80117B04: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80117B08: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x80117B0C: jal         0x8001EAD0
    // 0x80117B10: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80117B10: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80117B14: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80117B18: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80117B1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80117B20: ldc1        $f18, -0x64C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X64C8);
    // 0x80117B24: lw          $t3, 0xE0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XE0);
    // 0x80117B28: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80117B2C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80117B30: mul.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80117B34: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80117B38: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80117B3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80117B40: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80117B44: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80117B48: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80117B4C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80117B50: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80117B54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80117B58: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80117B5C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80117B60: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80117B64: lw          $t5, 0xE0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XE0);
    // 0x80117B68: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80117B6C: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80117B70: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80117B74: lw          $t7, 0xE0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE0);
    // 0x80117B78: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80117B7C: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80117B80: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80117B84: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80117B88: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80117B8C: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80117B90: lw          $t9, 0xE0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE0);
    // 0x80117B94: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x80117B98: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80117B9C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80117BA0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80117BA4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80117BA8: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80117BAC: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80117BB0: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80117BB4: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80117BB8: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x80117BBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80117BC0: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80117BC4: jal         0x801084C4
    // 0x80117BC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_2;
    // 0x80117BC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80117BCC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80117BD0: beq         $v0, $zero, L_80117BFC
    if (ctx->r2 == 0) {
        // 0x80117BD4: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_80117BFC;
    }
    // 0x80117BD4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80117BD8: lwc1        $f8, 0x374($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X374);
    // 0x80117BDC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80117BE0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x80117BE4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80117BE8: lwc1        $f10, 0x378($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X378);
    // 0x80117BEC: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80117BF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80117BF4: lwc1        $f16, 0x37C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X37C);
    // 0x80117BF8: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
L_80117BFC:
    // 0x80117BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80117C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80117C04: jr          $ra
    // 0x80117C08: nop

    return;
    // 0x80117C08: nop

;}
RECOMP_FUNC void M7_FUN_80117c0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117C0C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80117C10: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80117C14: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80117C18: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80117C1C: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80117C20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80117C24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80117C28: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80117C2C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80117C30: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80117C34: jal         0x801178E4
    // 0x80117C38: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    LOOKUP_FUNC(0x801178E4)(rdram, ctx);
        goto after_0;
    // 0x80117C38: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80117C3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80117C40: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80117C44: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80117C48: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80117C4C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80117C50: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80117C54: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80117C58: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80117C5C: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x80117C60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80117C64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80117C68: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80117C6C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80117C70: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80117C74: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80117C78: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80117C7C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80117C80: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80117C84: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80117C88: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80117C8C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80117C90: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80117C94: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80117C98: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80117C9C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80117CA0: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80117CA4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80117CA8: addiu       $a0, $a0, -0x6AA8
    ctx->r4 = ADD32(ctx->r4, -0X6AA8);
    // 0x80117CAC: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80117CB0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80117CB4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80117CB8: jal         0x8011AAF4
    // 0x80117CBC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x80117CBC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80117CC0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80117CC4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80117CC8: jr          $ra
    // 0x80117CCC: nop

    return;
    // 0x80117CCC: nop

;}
RECOMP_FUNC void M7_FUN_80117cd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117CD0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80117CD4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80117CD8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80117CDC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80117CE0: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80117CE4: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x80117CE8: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x80117CEC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80117CF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80117CF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80117CF8: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    // 0x80117CFC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80117D00: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x80117D04: jal         0x80117A7C
    // 0x80117D08: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    LOOKUP_FUNC(0x80117A7C)(rdram, ctx);
        goto after_0;
    // 0x80117D08: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x80117D0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80117D10: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80117D14: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80117D18: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80117D1C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80117D20: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80117D24: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80117D28: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80117D2C: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x80117D30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80117D34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80117D38: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80117D3C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80117D40: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80117D44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80117D48: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80117D4C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80117D50: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80117D54: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80117D58: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80117D5C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80117D60: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80117D64: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80117D68: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80117D6C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80117D70: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80117D74: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80117D78: addiu       $a0, $a0, -0x6A64
    ctx->r4 = ADD32(ctx->r4, -0X6A64);
    // 0x80117D7C: addiu       $a1, $zero, 0xFB
    ctx->r5 = ADD32(0, 0XFB);
    // 0x80117D80: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80117D84: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80117D88: jal         0x8011AAF4
    // 0x80117D8C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x80117D8C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80117D90: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80117D94: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80117D98: jr          $ra
    // 0x80117D9C: nop

    return;
    // 0x80117D9C: nop

;}
RECOMP_FUNC void M7_FUN_80117da0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117DA0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80117DA4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80117da8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80117da8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117DA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80117DAC: lhu         $v0, 0xEF0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XEF0);
    // 0x80117DB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80117DB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80117DB8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80117DBC: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x80117DC0: beq         $t7, $zero, L_80117DF8
    if (ctx->r15 == 0) {
        // 0x80117DC4: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80117DF8;
    }
    // 0x80117DC4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80117DC8: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x80117DCC: addiu       $v1, $v1, 0x6BF8
    ctx->r3 = ADD32(ctx->r3, 0X6BF8);
    // 0x80117DD0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80117DD4: andi        $t1, $v0, 0xDFFF
    ctx->r9 = ctx->r2 & 0XDFFF;
    // 0x80117DD8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80117DDC: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80117DE0: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80117DE4: bgtz        $t0, L_80117E04
    if (SIGNED(ctx->r8) > 0) {
        // 0x80117DE8: nop
    
            goto L_80117E04;
    }
    // 0x80117DE8: nop

    // 0x80117DEC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80117DF0: b           L_80117E04
    // 0x80117DF4: sh          $t1, 0xEF0($a2)
    MEM_H(0XEF0, ctx->r6) = ctx->r9;
        goto L_80117E04;
    // 0x80117DF4: sh          $t1, 0xEF0($a2)
    MEM_H(0XEF0, ctx->r6) = ctx->r9;
L_80117DF8:
    // 0x80117DF8: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x80117DFC: addiu       $v1, $v1, 0x6BF8
    ctx->r3 = ADD32(ctx->r3, 0X6BF8);
    // 0x80117E00: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_80117E04:
    // 0x80117E04: lui         $t2, 0x8021
    ctx->r10 = S32(0X8021 << 16);
    // 0x80117E08: addiu       $t2, $t2, 0x6B90
    ctx->r10 = ADD32(ctx->r10, 0X6B90);
    // 0x80117E0C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80117E10: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80117E14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80117E18: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x80117E1C: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x80117E20: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80117E24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80117E28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80117E2C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80117E30: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80117E34: jal         0x80011140
    // 0x80117E38: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80117E38: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x80117E3C: beq         $v0, $zero, L_80117E4C
    if (ctx->r2 == 0) {
        // 0x80117E40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80117E4C;
    }
    // 0x80117E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80117E44: b           L_80117E50
    // 0x80117E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80117E50;
    // 0x80117E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80117E4C:
    // 0x80117E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80117E50:
    // 0x80117E50: jr          $ra
    // 0x80117E54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80117E54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80117e58(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80117e58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80117E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80117E60: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80117E64: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80117E68: addiu       $a1, $a1, -0x446E
    ctx->r5 = ADD32(ctx->r5, -0X446E);
    // 0x80117E6C: jal         0x80119F9C
    // 0x80117E70: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_0;
    // 0x80117E70: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    after_0:
    // 0x80117E74: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80117E78: jal         0x8011A0F0
    // 0x80117E7C: addiu       $a0, $a0, -0x446C
    ctx->r4 = ADD32(ctx->r4, -0X446C);
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_1;
    // 0x80117E7C: addiu       $a0, $a0, -0x446C
    ctx->r4 = ADD32(ctx->r4, -0X446C);
    after_1:
    // 0x80117E80: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80117E84: lw          $v0, -0x4328($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4328);
    // 0x80117E88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117E8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80117E90: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80117E94: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80117E98: addiu       $a1, $a1, -0x4468
    ctx->r5 = ADD32(ctx->r5, -0X4468);
    // 0x80117E9C: lwc1        $f4, 0x3C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x80117EA0: addiu       $a0, $a0, -0x446A
    ctx->r4 = ADD32(ctx->r4, -0X446A);
    // 0x80117EA4: swc1        $f4, -0x4458($at)
    MEM_W(-0X4458, ctx->r1) = ctx->f4.u32l;
    // 0x80117EA8: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80117EAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117EB0: lwc1        $f6, 0x40($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X40);
    // 0x80117EB4: swc1        $f6, -0x4454($at)
    MEM_W(-0X4454, ctx->r1) = ctx->f6.u32l;
    // 0x80117EB8: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80117EBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117EC0: lwc1        $f8, 0x44($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X44);
    // 0x80117EC4: swc1        $f8, -0x4450($at)
    MEM_W(-0X4450, ctx->r1) = ctx->f8.u32l;
    // 0x80117EC8: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80117ECC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117ED0: lwc1        $f10, 0x30($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X30);
    // 0x80117ED4: swc1        $f10, -0x4464($at)
    MEM_W(-0X4464, ctx->r1) = ctx->f10.u32l;
    // 0x80117ED8: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x80117EDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117EE0: lwc1        $f16, 0x34($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80117EE4: swc1        $f16, -0x4460($at)
    MEM_W(-0X4460, ctx->r1) = ctx->f16.u32l;
    // 0x80117EE8: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x80117EEC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117EF0: lwc1        $f18, 0x38($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X38);
    // 0x80117EF4: jal         0x80119F9C
    // 0x80117EF8: swc1        $f18, -0x445C($at)
    MEM_W(-0X445C, ctx->r1) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_2;
    // 0x80117EF8: swc1        $f18, -0x445C($at)
    MEM_W(-0X445C, ctx->r1) = ctx->f18.u32l;
    after_2:
    // 0x80117EFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F00: lwc1        $f4, -0x4458($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4458);
    // 0x80117F04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F08: lwc1        $f6, -0x4464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80117F0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F10: lwc1        $f8, -0x4454($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4454);
    // 0x80117F14: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F18: lwc1        $f10, -0x4460($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80117F1C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80117F20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F24: lwc1        $f16, -0x4450($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4450);
    // 0x80117F28: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80117F2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F30: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80117F34: lwc1        $f18, -0x445C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80117F38: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80117F3C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80117F40: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80117F44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80117F48: jal         0x8002FC20
    // 0x80117F4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x80117F4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x80117F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80117F54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80117F58: swc1        $f0, -0x444C($at)
    MEM_W(-0X444C, ctx->r1) = ctx->f0.u32l;
    // 0x80117F5C: jr          $ra
    // 0x80117F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80117F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80117f64(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80117f64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117F64: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80117F68: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80117f6c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80117f6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117F6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80117F70: lhu         $v0, 0xEF0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XEF0);
    // 0x80117F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80117F78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80117F7C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80117F80: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x80117F84: beq         $t7, $zero, L_80117FBC
    if (ctx->r15 == 0) {
        // 0x80117F88: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80117FBC;
    }
    // 0x80117F88: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80117F8C: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x80117F90: addiu       $v1, $v1, 0x6BF8
    ctx->r3 = ADD32(ctx->r3, 0X6BF8);
    // 0x80117F94: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80117F98: andi        $t1, $v0, 0xDFFF
    ctx->r9 = ctx->r2 & 0XDFFF;
    // 0x80117F9C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80117FA0: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80117FA4: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80117FA8: bgtzl       $t0, L_80117FCC
    if (SIGNED(ctx->r8) > 0) {
        // 0x80117FAC: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80117FCC;
    }
    goto skip_0;
    // 0x80117FAC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80117FB0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80117FB4: b           L_80117FC8
    // 0x80117FB8: sh          $t1, 0xEF0($a2)
    MEM_H(0XEF0, ctx->r6) = ctx->r9;
        goto L_80117FC8;
    // 0x80117FB8: sh          $t1, 0xEF0($a2)
    MEM_H(0XEF0, ctx->r6) = ctx->r9;
L_80117FBC:
    // 0x80117FBC: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x80117FC0: addiu       $v1, $v1, 0x6BF8
    ctx->r3 = ADD32(ctx->r3, 0X6BF8);
    // 0x80117FC4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_80117FC8:
    // 0x80117FC8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_80117FCC:
    // 0x80117FCC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80117FD0: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x80117FD4: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x80117FD8: lui         $t4, 0x8021
    ctx->r12 = S32(0X8021 << 16);
    // 0x80117FDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80117FE0: bne         $t3, $at, L_80117FF8
    if (ctx->r11 != ctx->r1) {
        // 0x80117FE4: addiu       $t4, $t4, 0x6B90
        ctx->r12 = ADD32(ctx->r12, 0X6B90);
            goto L_80117FF8;
    }
    // 0x80117FE4: addiu       $t4, $t4, 0x6B90
    ctx->r12 = ADD32(ctx->r12, 0X6B90);
    // 0x80117FE8: jal         0x80010550
    // 0x80117FEC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80117FEC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_0:
    // 0x80117FF0: b           L_8011802C
    // 0x80117FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8011802C;
    // 0x80117FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80117FF8:
    // 0x80117FF8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80117FFC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80118000: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80118004: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80118008: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x8011800C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80118010: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80118014: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80118018: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8011801C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80118020: jal         0x80011140
    // 0x80118024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x80118024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80118028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8011802C:
    // 0x8011802C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80118030: jr          $ra
    // 0x80118034: nop

    return;
    // 0x80118034: nop

;}
RECOMP_FUNC void M7_FUN_80118038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118038: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8011803C: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80118040(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80118040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80118044: lh          $t6, 0xA2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XA2);
    // 0x80118048: lh          $t7, 0xA4($t0)
    ctx->r15 = MEM_H(ctx->r8, 0XA4);
    // 0x8011804C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80118050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80118054: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80118058: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8011805C: addiu       $a3, $a3, -0x6A20
    ctx->r7 = ADD32(ctx->r7, -0X6A20);
    // 0x80118060: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80118064: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80118068: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8011806C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80118070: jal         0x8001DFFC
    // 0x80118074: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8001DFFC)(rdram, ctx);
        goto after_0;
    // 0x80118074: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80118078: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8011807C: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x80118080: lh          $v1, 0xA2($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XA2);
    // 0x80118084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80118088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8011808C: bgez        $v1, L_8011809C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80118090: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8011809C;
    }
    // 0x80118090: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80118094: b           L_8011809C
    // 0x80118098: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8011809C;
    // 0x80118098: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8011809C:
    // 0x8011809C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x801180A0: bnel        $at, $zero, L_801180C0
    if (ctx->r1 != 0) {
        // 0x801180A4: mtc1        $zero, $f9
        ctx->f_odd[(9 - 1) * 2] = 0;
            goto L_801180C0;
    }
    goto skip_0;
    // 0x801180A4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    skip_0:
    // 0x801180A8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801180AC: nop

    // 0x801180B0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801180B4: b           L_801180CC
    // 0x801180B8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
        goto L_801180CC;
    // 0x801180B8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801180BC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
L_801180C0:
    // 0x801180C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801180C4: nop

    // 0x801180C8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
L_801180CC:
    // 0x801180CC: lh          $v1, 0xA4($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XA4);
    // 0x801180D0: bgez        $v1, L_801180E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801180D4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801180E0;
    }
    // 0x801180D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801180D8: b           L_801180E0
    // 0x801180DC: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801180E0;
    // 0x801180DC: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801180E0:
    // 0x801180E0: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x801180E4: bnel        $at, $zero, L_80118110
    if (ctx->r1 != 0) {
        // 0x801180E8: mtc1        $zero, $f5
        ctx->f_odd[(5 - 1) * 2] = 0;
            goto L_80118110;
    }
    goto skip_1;
    // 0x801180E8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    skip_1:
    // 0x801180EC: lb          $t8, 0x18($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X18);
    // 0x801180F0: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801180F4: mflo        $t9
    ctx->r25 = lo;
    // 0x801180F8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801180FC: nop

    // 0x80118100: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80118104: b           L_8011811C
    // 0x80118108: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
        goto L_8011811C;
    // 0x80118108: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8011810C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
L_80118110:
    // 0x80118110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80118114: nop

    // 0x80118118: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_8011811C:
    // 0x8011811C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80118120: nop

    // 0x80118124: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80118128: nop

    // 0x8011812C: bc1fl       L_80118140
    if (!c1cs) {
        // 0x80118130: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80118140;
    }
    goto skip_2;
    // 0x80118130: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_2:
    // 0x80118134: b           L_80118140
    // 0x80118138: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
        goto L_80118140;
    // 0x80118138: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x8011813C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_80118140:
    // 0x80118140: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80118144: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80118148: bc1fl       L_8011815C
    if (!c1cs) {
        // 0x8011814C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8011815C;
    }
    goto skip_3;
    // 0x8011814C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_3:
    // 0x80118150: b           L_8011815C
    // 0x80118154: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8011815C;
    // 0x80118154: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80118158: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8011815C:
    // 0x8011815C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80118160: nop

    // 0x80118164: bc1fl       L_801181B0
    if (!c1cs) {
        // 0x80118168: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_801181B0;
    }
    goto skip_4;
    // 0x80118168: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_4:
    // 0x8011816C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80118170: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80118174: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80118178: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8011817C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80118180: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x80118184: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80118188: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8011818C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80118190: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80118194: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x80118198: trunc.w.d   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8011819C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x801181A0: nop

    // 0x801181A4: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x801181A8: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x801181AC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_801181B0:
    // 0x801181B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801181B4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x801181B8: bc1fl       L_801181CC
    if (!c1cs) {
        // 0x801181BC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_801181CC;
    }
    goto skip_5;
    // 0x801181BC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_5:
    // 0x801181C0: b           L_801181CC
    // 0x801181C4: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
        goto L_801181CC;
    // 0x801181C4: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x801181C8: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_801181CC:
    // 0x801181CC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x801181D0: nop

    // 0x801181D4: bc1fl       L_801181E8
    if (!c1cs) {
        // 0x801181D8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_801181E8;
    }
    goto skip_6;
    // 0x801181D8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_6:
    // 0x801181DC: b           L_801181E8
    // 0x801181E0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_801181E8;
    // 0x801181E0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x801181E4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_801181E8:
    // 0x801181E8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x801181EC: nop

    // 0x801181F0: bc1tl       L_80118258
    if (c1cs) {
        // 0x801181F4: lui         $at, 0x4500
        ctx->r1 = S32(0X4500 << 16);
            goto L_80118258;
    }
    goto skip_7;
    // 0x801181F4: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    skip_7:
    // 0x801181F8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801181FC: nop

    // 0x80118200: bc1fl       L_80118214
    if (!c1cs) {
        // 0x80118204: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80118214;
    }
    goto skip_8;
    // 0x80118204: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_8:
    // 0x80118208: b           L_80118214
    // 0x8011820C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80118214;
    // 0x8011820C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80118210: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80118214:
    // 0x80118214: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80118218: nop

    // 0x8011821C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80118220: nop

    // 0x80118224: bc1f        L_801182DC
    if (!c1cs) {
        // 0x80118228: nop
    
            goto L_801182DC;
    }
    // 0x80118228: nop

    // 0x8011822C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80118230: nop

    // 0x80118234: bc1fl       L_80118248
    if (!c1cs) {
        // 0x80118238: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80118248;
    }
    goto skip_9;
    // 0x80118238: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_9:
    // 0x8011823C: b           L_80118248
    // 0x80118240: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_80118248;
    // 0x80118240: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80118244: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80118248:
    // 0x80118248: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8011824C: nop

    // 0x80118250: bc1f        L_801182DC
    if (!c1cs) {
        // 0x80118254: lui         $at, 0x4500
        ctx->r1 = S32(0X4500 << 16);
            goto L_801182DC;
    }
    // 0x80118254: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
L_80118258:
    // 0x80118258: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8011825C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80118260: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80118264: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80118268: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8011826C: ldc1        $f18, -0x64C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X64C0);
    // 0x80118270: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80118274: lh          $t8, -0x4468($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4468);
    // 0x80118278: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8011827C: cvt.d.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.d = CVT_D_W(ctx->f6.u32l);
    // 0x80118280: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80118284: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80118288: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8011828C: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x80118290: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80118294: div.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80118298: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x8011829C: sub.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f10.d - ctx->f0.d;
    // 0x801182A0: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x801182A4: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x801182A8: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801182AC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x801182B0: nop

    // 0x801182B4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801182B8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801182BC: bgez        $v1, L_801182CC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801182C0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801182CC;
    }
    // 0x801182C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801182C4: b           L_801182CC
    // 0x801182C8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801182CC;
    // 0x801182C8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801182CC:
    // 0x801182CC: slti        $at, $v0, 0x800
    ctx->r1 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // 0x801182D0: beq         $at, $zero, L_801182DC
    if (ctx->r1 == 0) {
        // 0x801182D4: nop
    
            goto L_801182DC;
    }
    // 0x801182D4: nop

    // 0x801182D8: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_801182DC:
    // 0x801182DC: lw          $t1, 0x36F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X36F4);
    // 0x801182E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801182E4: beq         $t1, $zero, L_801182EC
    if (ctx->r9 == 0) {
        // 0x801182E8: nop
    
            goto L_801182EC;
    }
    // 0x801182E8: nop

L_801182EC:
    // 0x801182EC: jr          $ra
    // 0x801182F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801182F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801182f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801182f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801182F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801182F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801182FC: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80118300: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80118304: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80118308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8011830C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80118310: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80118314: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80118318: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8011831C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80118320: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80118324: jal         0x8001EB64
    // 0x80118328: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80118328: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8011832C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80118330: jal         0x8001EB64
    // 0x80118334: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80118334: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_1:
    // 0x80118338: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8011833C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80118340: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80118344: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x80118348: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8011834C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80118350: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80118354: lw          $t6, 0xE0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE0);
    // 0x80118358: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8011835C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80118360: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80118364: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80118368: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8011836C: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80118370: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80118374: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80118378: sub.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d - ctx->f16.d;
    // 0x8011837C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80118380: jal         0x8001EAD0
    // 0x80118384: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80118384: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    after_2:
    // 0x80118388: lw          $t9, 0xE0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XE0);
    // 0x8011838C: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x80118390: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80118394: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80118398: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8011839C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801183A0: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801183A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801183A8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801183AC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x801183B0: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801183B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801183B8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801183BC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801183C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801183C4: add.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f18.d + ctx->f4.d;
    // 0x801183C8: sub.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d - ctx->f8.d;
    // 0x801183CC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801183D0: jal         0x8001EB64
    // 0x801183D4: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801183D4: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    after_3:
    // 0x801183D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801183DC: jal         0x8001EAD0
    // 0x801183E0: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x801183E0: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_4:
    // 0x801183E4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801183E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801183EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801183F0: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x801183F4: lw          $t2, 0xE0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XE0);
    // 0x801183F8: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801183FC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80118400: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80118404: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80118408: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8011840C: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80118410: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80118414: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80118418: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8011841C: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x80118420: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80118424: jal         0x8001EB64
    // 0x80118428: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80118428: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    after_5:
    // 0x8011842C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80118430: jal         0x8001EB64
    // 0x80118434: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x80118434: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_6:
    // 0x80118438: lw          $t5, 0xE0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XE0);
    // 0x8011843C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80118440: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x80118444: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80118448: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8011844C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80118450: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80118454: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80118458: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8011845C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80118460: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80118464: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80118468: jal         0x8001EAD0
    // 0x8011846C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x8011846C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    after_7:
    // 0x80118470: lw          $t8, 0xE0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XE0);
    // 0x80118474: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x80118478: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8011847C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80118480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80118484: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80118488: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8011848C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80118490: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80118494: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80118498: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8011849C: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x801184A0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801184A4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x801184A8: jal         0x8001EB64
    // 0x801184AC: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x801184AC: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    after_8:
    // 0x801184B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801184B4: jal         0x8001EAD0
    // 0x801184B8: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x801184B8: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_9:
    // 0x801184BC: lw          $t1, 0xE0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XE0);
    // 0x801184C0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801184C4: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801184C8: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801184CC: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x801184D0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x801184D4: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801184D8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801184DC: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x801184E0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801184E4: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x801184E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801184EC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801184F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801184F4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801184F8: jr          $ra
    // 0x801184FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801184FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80118500(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80118500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118500: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80118504: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80118508: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x8011850C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80118510: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80118514: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80118518: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x8011851C: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80118520: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80118524: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x80118528: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8011852C: addiu       $v1, $v1, -0x446E
    ctx->r3 = ADD32(ctx->r3, -0X446E);
    // 0x80118530: subu        $t6, $t3, $t2
    ctx->r14 = SUB32(ctx->r11, ctx->r10);
    // 0x80118534: addiu       $v0, $v0, -0x4470
    ctx->r2 = ADD32(ctx->r2, -0X4470);
    // 0x80118538: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x8011853C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80118540: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80118544: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x80118548: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x8011854C: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x80118550: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x80118554: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80118558: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8011855C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80118560: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80118564: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80118568: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8011856C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80118570: jal         0x801182F4
    // 0x80118574: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    LOOKUP_FUNC(0x801182F4)(rdram, ctx);
        goto after_0;
    // 0x80118574: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_0:
    // 0x80118578: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8011857C: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x80118580: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80118584: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80118588: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8011858C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80118590: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80118594: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80118598: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8011859C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801185A0: sub.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801185A4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801185A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801185AC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x801185B0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801185B4: addiu       $a0, $a0, -0x69B0
    ctx->r4 = ADD32(ctx->r4, -0X69B0);
    // 0x801185B8: mul.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x801185BC: addiu       $a1, $zero, 0x1AD
    ctx->r5 = ADD32(0, 0X1AD);
    // 0x801185C0: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x801185C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801185C8: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801185CC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801185D0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801185D4: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x801185D8: lwc1        $f12, 0x34($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801185DC: sub.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801185E0: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801185E4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801185E8: mul.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x801185EC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801185F0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801185F4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801185F8: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x801185FC: lwc1        $f14, 0x38($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80118600: sub.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x80118604: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80118608: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x8011860C: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80118610: add.d       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f10.d + ctx->f4.d;
    // 0x80118614: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80118618: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8011861C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80118620: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80118624: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80118628: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8011862C: sub.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80118630: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80118634: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80118638: add.d       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f10.d + ctx->f8.d;
    // 0x8011863C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80118640: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80118644: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80118648: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8011864C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80118650: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80118654: sub.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80118658: cvt.d.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.d = CVT_D_S(ctx->f6.fl);
    // 0x8011865C: mul.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80118660: add.d       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f10.d + ctx->f6.d;
    // 0x80118664: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80118668: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x8011866C: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80118670: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80118674: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80118678: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8011867C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80118680: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80118684: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80118688: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8011868C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80118690: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80118694: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80118698: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x8011869C: add.d       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f10.d + ctx->f6.d;
    // 0x801186A0: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801186A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801186A8: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x801186AC: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801186B0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801186B4: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801186B8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801186BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801186C0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801186C4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801186C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801186CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801186D0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801186D4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801186D8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801186DC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801186E0: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801186E4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x801186E8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801186EC: jal         0x8011AAF4
    // 0x801186F0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801186F0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801186F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x801186F8: jal         0x80117DA0
    // 0x801186FC: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    LOOKUP_FUNC(0x80117DA0)(rdram, ctx);
        goto after_2;
    // 0x801186FC: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    after_2:
    // 0x80118700: bne         $v0, $zero, L_80118758
    if (ctx->r2 != 0) {
        // 0x80118704: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_80118758;
    }
    // 0x80118704: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80118708: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8011870C: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80118710: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118714: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80118718: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8011871C: addiu       $a1, $a1, -0x7898
    ctx->r5 = ADD32(ctx->r5, -0X7898);
    // 0x80118720: lh          $t9, 0x12($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X12);
    // 0x80118724: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80118728: subu        $t3, $t8, $t9
    ctx->r11 = SUB32(ctx->r24, ctx->r25);
    // 0x8011872C: andi        $t2, $t3, 0x1FFF
    ctx->r10 = ctx->r11 & 0X1FFF;
    // 0x80118730: sh          $t2, -0x4470($at)
    MEM_H(-0X4470, ctx->r1) = ctx->r10;
    // 0x80118734: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118738: sh          $zero, -0x446E($at)
    MEM_H(-0X446E, ctx->r1) = 0;
    // 0x8011873C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118740: sh          $zero, -0x4468($at)
    MEM_H(-0X4468, ctx->r1) = 0;
    // 0x80118744: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80118748: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8011874C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118750: jal         0x800058DC
    // 0x80118754: swc1        $f10, -0x4448($at)
    MEM_W(-0X4448, ctx->r1) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80118754: swc1        $f10, -0x4448($at)
    MEM_W(-0X4448, ctx->r1) = ctx->f10.u32l;
    after_3:
L_80118758:
    // 0x80118758: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8011875C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80118760: jr          $ra
    // 0x80118764: nop

    return;
    // 0x80118764: nop

;}
RECOMP_FUNC void M7_FUN_80118768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118768: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8011876C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80118770: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80118774: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80118778: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8011877C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80118780: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80118784: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80118788: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8011878C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80118790: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    // 0x80118794: lhu         $t7, 0xEF0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XEF0);
    // 0x80118798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8011879C: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x801187A0: beql        $t8, $zero, L_801187D4
    if (ctx->r24 == 0) {
        // 0x801187A4: lhu         $t1, 0x9E($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X9E);
            goto L_801187D4;
    }
    goto skip_0;
    // 0x801187A4: lhu         $t1, 0x9E($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X9E);
    skip_0:
    // 0x801187A8: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x801187AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801187B0: jal         0x80117C0C
    // 0x801187B4: sb          $t9, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r25;
    LOOKUP_FUNC(0x80117C0C)(rdram, ctx);
        goto after_0;
    // 0x801187B4: sb          $t9, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r25;
    after_0:
    // 0x801187B8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x801187BC: addiu       $a1, $a1, -0x6690
    ctx->r5 = ADD32(ctx->r5, -0X6690);
    // 0x801187C0: jal         0x800058DC
    // 0x801187C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801187C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801187C8: b           L_80118B60
    // 0x801187CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80118B60;
    // 0x801187CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801187D0: lhu         $t1, 0x9E($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X9E);
L_801187D4:
    // 0x801187D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801187D8: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x801187DC: beql        $t2, $zero, L_80118804
    if (ctx->r10 == 0) {
        // 0x801187E0: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_80118804;
    }
    goto skip_1;
    // 0x801187E0: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x801187E4: lhu         $t3, 0x18E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X18E);
    // 0x801187E8: bnel        $t3, $zero, L_80118804
    if (ctx->r11 != 0) {
        // 0x801187EC: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_80118804;
    }
    goto skip_2;
    // 0x801187EC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x801187F0: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x801187F4: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x801187F8: bne         $t5, $zero, L_80118828
    if (ctx->r13 != 0) {
        // 0x801187FC: nop
    
            goto L_80118828;
    }
    // 0x801187FC: nop

    // 0x80118800: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
L_80118804:
    // 0x80118804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80118808: jal         0x80117C0C
    // 0x8011880C: sb          $t6, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r14;
    LOOKUP_FUNC(0x80117C0C)(rdram, ctx);
        goto after_2;
    // 0x8011880C: sb          $t6, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r14;
    after_2:
    // 0x80118810: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80118814: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80118818: jal         0x800058DC
    // 0x8011881C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8011881C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80118820: b           L_80118B60
    // 0x80118824: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80118B60;
    // 0x80118824: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80118828:
    // 0x80118828: jal         0x80117F64
    // 0x8011882C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80117F64)(rdram, ctx);
        goto after_4;
    // 0x8011882C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80118830: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118834: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80118838: addiu       $a1, $a1, -0x446E
    ctx->r5 = ADD32(ctx->r5, -0X446E);
    // 0x8011883C: jal         0x80118038
    // 0x80118840: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    LOOKUP_FUNC(0x80118038)(rdram, ctx);
        goto after_5;
    // 0x80118840: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    after_5:
    // 0x80118844: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118848: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8011884C: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x80118850: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x80118854: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x80118858: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x8011885C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80118860: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80118864: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80118868: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8011886C: lh          $a1, -0x446E($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X446E);
    // 0x80118870: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118874: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x80118878: jal         0x801182F4
    // 0x8011887C: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    LOOKUP_FUNC(0x801182F4)(rdram, ctx);
        goto after_6;
    // 0x8011887C: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    after_6:
    // 0x80118880: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118884: jal         0x8001EB64
    // 0x80118888: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x80118888: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    after_7:
    // 0x8011888C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118890: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118894: jal         0x8001EB64
    // 0x80118898: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x80118898: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8011889C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801188A0: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x801188A4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801188A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801188AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801188B0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801188B4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801188B8: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801188BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801188C0: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x801188C4: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801188C8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801188CC: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x801188D0: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801188D4: jal         0x8001EAD0
    // 0x801188D8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_9;
    // 0x801188D8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x801188DC: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x801188E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801188E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801188E8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801188EC: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801188F0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801188F4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801188F8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801188FC: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118900: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80118904: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80118908: jal         0x8001EB64
    // 0x8011890C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_10;
    // 0x8011890C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80118910: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118914: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118918: jal         0x8001EAD0
    // 0x8011891C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x8011891C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80118920: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80118924: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x80118928: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8011892C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80118930: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80118934: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80118938: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x8011893C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80118940: lwc1        $f12, 0x84($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80118944: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80118948: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8011894C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80118950: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x80118954: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80118958: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8011895C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80118960: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x80118964: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80118968: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8011896C: jal         0x801084C4
    // 0x80118970: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_12;
    // 0x80118970: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80118974: beq         $v0, $zero, L_801189C8
    if (ctx->r2 == 0) {
        // 0x80118978: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801189C8;
    }
    // 0x80118978: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8011897C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80118980: lwc1        $f10, 0x380($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X380);
    // 0x80118984: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80118988: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8011898C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80118990: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80118994: lwc1        $f6, 0x384($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X384);
    // 0x80118998: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8011899C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801189A0: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801189A4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x801189A8: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801189AC: lwc1        $f8, 0x388($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X388);
    // 0x801189B0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801189B4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801189B8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801189BC: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x801189C0: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801189C4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
L_801189C8:
    // 0x801189C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801189CC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801189D0: lw          $t2, 0xE8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XE8);
    // 0x801189D4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801189D8: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801189DC: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801189E0: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801189E4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801189E8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801189EC: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801189F0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801189F4: nop

    // 0x801189F8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801189FC: jal         0x8002FC20
    // 0x80118A00: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_13;
    // 0x80118A00: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_13:
    // 0x80118A04: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80118A08: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80118A0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80118A10: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80118A14: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80118A18: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80118A1C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80118A20: bc1f        L_80118A34
    if (!c1cs) {
        // 0x80118A24: nop
    
            goto L_80118A34;
    }
    // 0x80118A24: nop

    // 0x80118A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80118A2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118A30: swc1        $f6, -0x4448($at)
    MEM_W(-0X4448, ctx->r1) = ctx->f6.u32l;
L_80118A34:
    // 0x80118A34: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x80118A38: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80118A3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118A40: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x80118A44: lwc1        $f16, -0x4448($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4448);
    // 0x80118A48: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80118A4C: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80118A50: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    // 0x80118A54: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80118A58: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80118A5C: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80118A60: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80118A64: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80118A68: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80118A6C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80118A70: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80118A74: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80118A78: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80118A7C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80118A80: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x80118A84: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80118A88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80118A8C: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80118A90: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80118A94: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x80118A98: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80118A9C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80118AA0: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80118AA4: jal         0x80117650
    // 0x80118AA8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80117650)(rdram, ctx);
        goto after_14;
    // 0x80118AA8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80118AAC: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80118AB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80118AB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80118AB8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80118ABC: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80118AC0: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80118AC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80118AC8: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80118ACC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80118AD0: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80118AD4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80118AD8: lw          $t5, -0x4328($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4328);
    // 0x80118ADC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80118AE0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80118AE4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80118AE8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80118AEC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80118AF0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80118AF4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80118AF8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80118AFC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80118B00: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80118B04: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80118B08: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80118B0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80118B10: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80118B14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80118B18: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80118B1C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80118B20: addiu       $a0, $a0, -0x68A8
    ctx->r4 = ADD32(ctx->r4, -0X68A8);
    // 0x80118B24: addiu       $a1, $zero, 0x20B
    ctx->r5 = ADD32(0, 0X20B);
    // 0x80118B28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80118B2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80118B30: jal         0x8011AAF4
    // 0x80118B34: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_15;
    // 0x80118B34: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80118B38: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80118B3C: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x80118B40: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80118B44: lh          $t9, -0x4470($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4470);
    // 0x80118B48: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80118B4C: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x80118B50: subu        $t3, $t0, $t9
    ctx->r11 = SUB32(ctx->r8, ctx->r25);
    // 0x80118B54: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x80118B58: sh          $t4, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r12;
    // 0x80118B5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80118B60:
    // 0x80118B60: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80118B64: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80118B68: jr          $ra
    // 0x80118B6C: nop

    return;
    // 0x80118B6C: nop

;}
RECOMP_FUNC void M7_FUN_80118b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80118B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80118B78: jal         0x80117DA0
    // 0x80118B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80117DA0)(rdram, ctx);
        goto after_0;
    // 0x80118B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80118B80: bnel        $v0, $zero, L_80118BA4
    if (ctx->r2 != 0) {
        // 0x80118B84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80118BA4;
    }
    goto skip_0;
    // 0x80118B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80118B88: jal         0x80117E58
    // 0x80118B8C: nop

    LOOKUP_FUNC(0x80117E58)(rdram, ctx);
        goto after_1;
    // 0x80118B8C: nop

    after_1:
    // 0x80118B90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80118B94: addiu       $a1, $a1, -0x7450
    ctx->r5 = ADD32(ctx->r5, -0X7450);
    // 0x80118B98: jal         0x800058DC
    // 0x80118B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80118B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80118BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80118BA4:
    // 0x80118BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80118BA8: jr          $ra
    // 0x80118BAC: nop

    return;
    // 0x80118BAC: nop

;}
RECOMP_FUNC void M7_FUN_80118bb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80118BB0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80118BB4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80118BB8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80118BBC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80118BC0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80118BC4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80118BC8: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x80118BCC: swc1        $f20, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f20.u32l;
    // 0x80118BD0: swc1        $f20, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f20.u32l;
    // 0x80118BD4: swc1        $f20, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f20.u32l;
    // 0x80118BD8: lhu         $t6, 0xEF0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XEF0);
    // 0x80118BDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80118BE0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80118BE4: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80118BE8: beq         $t7, $zero, L_80118C94
    if (ctx->r15 == 0) {
        // 0x80118BEC: addiu       $a0, $a0, -0x681C
        ctx->r4 = ADD32(ctx->r4, -0X681C);
            goto L_80118C94;
    }
    // 0x80118BEC: addiu       $a0, $a0, -0x681C
    ctx->r4 = ADD32(ctx->r4, -0X681C);
    // 0x80118BF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118BF4: lwc1        $f4, -0x4464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118BF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118BFC: lwc1        $f6, -0x4460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118C00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118C04: lwc1        $f8, -0x445C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80118C08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118C0C: lwc1        $f10, -0x4458($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4458);
    // 0x80118C10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118C14: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80118C18: lwc1        $f4, -0x4454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4454);
    // 0x80118C1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118C20: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80118C24: lwc1        $f6, -0x4450($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4450);
    // 0x80118C28: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x80118C2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80118C30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80118C34: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80118C38: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80118C3C: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x80118C40: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80118C44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80118C48: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80118C4C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80118C50: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80118C54: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80118C58: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80118C5C: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80118C60: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80118C64: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80118C68: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80118C6C: addiu       $a1, $zero, 0x235
    ctx->r5 = ADD32(0, 0X235);
    // 0x80118C70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80118C74: jal         0x8011AAF4
    // 0x80118C78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80118C78: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80118C7C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80118C80: addiu       $a1, $a1, -0x6690
    ctx->r5 = ADD32(ctx->r5, -0X6690);
    // 0x80118C84: jal         0x800058DC
    // 0x80118C88: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80118C88: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_1:
    // 0x80118C8C: b           L_801190E4
    // 0x80118C90: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_801190E4;
    // 0x80118C90: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80118C94:
    // 0x80118C94: lhu         $t3, 0x9E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X9E);
    // 0x80118C98: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80118C9C: addiu       $a0, $a0, -0x67AC
    ctx->r4 = ADD32(ctx->r4, -0X67AC);
    // 0x80118CA0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80118CA4: beq         $t4, $zero, L_80118CC4
    if (ctx->r12 == 0) {
        // 0x80118CA8: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_80118CC4;
    }
    // 0x80118CA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80118CAC: lhu         $t5, 0x18E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X18E);
    // 0x80118CB0: bne         $t5, $zero, L_80118CC4
    if (ctx->r13 != 0) {
        // 0x80118CB4: nop
    
            goto L_80118CC4;
    }
    // 0x80118CB4: nop

    // 0x80118CB8: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80118CBC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80118CC0: bne         $t7, $zero, L_80118D64
    if (ctx->r15 != 0) {
        // 0x80118CC4: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80118D64;
    }
L_80118CC4:
    // 0x80118CC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CC8: lwc1        $f10, -0x4464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118CCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CD0: lwc1        $f4, -0x4460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118CD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CD8: lwc1        $f6, -0x445C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80118CDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CE0: lwc1        $f8, -0x4458($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4458);
    // 0x80118CE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CE8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80118CEC: lwc1        $f10, -0x4454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4454);
    // 0x80118CF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118CF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80118CF8: lwc1        $f4, -0x4450($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4450);
    // 0x80118CFC: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x80118D00: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80118D04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80118D08: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80118D0C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80118D10: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x80118D14: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80118D18: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80118D1C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80118D20: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80118D24: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80118D28: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80118D2C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80118D30: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80118D34: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80118D38: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80118D3C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80118D40: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    // 0x80118D44: jal         0x8011AAF4
    // 0x80118D48: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x80118D48: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80118D4C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80118D50: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80118D54: jal         0x800058DC
    // 0x80118D58: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80118D58: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_3:
    // 0x80118D5C: b           L_801190E4
    // 0x80118D60: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_801190E4;
    // 0x80118D60: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80118D64:
    // 0x80118D64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80118D68: jal         0x80117F64
    // 0x80118D6C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80117F64)(rdram, ctx);
        goto after_4;
    // 0x80118D6C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    after_4:
    // 0x80118D70: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118D74: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80118D78: addiu       $a1, $a1, -0x446E
    ctx->r5 = ADD32(ctx->r5, -0X446E);
    // 0x80118D7C: jal         0x80118038
    // 0x80118D80: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    LOOKUP_FUNC(0x80118038)(rdram, ctx);
        goto after_5;
    // 0x80118D80: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    after_5:
    // 0x80118D84: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118D88: jal         0x8001EB64
    // 0x80118D8C: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x80118D8C: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    after_6:
    // 0x80118D90: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118D94: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118D98: jal         0x8001EB64
    // 0x80118D9C: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x80118D9C: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80118DA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118DA4: lwc1        $f8, -0x444C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x80118DA8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80118DAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118DB0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118DB4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80118DB8: lwc1        $f8, -0x4464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118DBC: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118DC0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80118DC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80118DC8: jal         0x8001EAD0
    // 0x80118DCC: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x80118DCC: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80118DD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118DD4: lwc1        $f4, -0x444C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x80118DD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118DDC: lwc1        $f8, -0x4460($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118DE0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80118DE4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118DE8: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118DEC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80118DF0: jal         0x8001EB64
    // 0x80118DF4: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x80118DF4: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80118DF8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118DFC: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118E00: jal         0x8001EAD0
    // 0x80118E04: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x80118E04: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80118E08: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80118E0C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80118E10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118E14: lwc1        $f4, -0x444C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x80118E18: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80118E1C: lw          $t3, 0xE8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE8);
    // 0x80118E20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118E24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80118E28: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x80118E2C: lwc1        $f4, -0x445C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80118E30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80118E34: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80118E38: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118E3C: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118E40: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80118E44: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80118E48: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80118E4C: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80118E50: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80118E54: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80118E58: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80118E5C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80118E60: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80118E64: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80118E68: lwc1        $f12, 0x44($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80118E6C: sub.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80118E70: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80118E74: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80118E78: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80118E7C: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80118E80: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80118E84: jal         0x8001EB64
    // 0x80118E88: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_11;
    // 0x80118E88: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80118E8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118E90: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118E94: jal         0x8001EB64
    // 0x80118E98: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x80118E98: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80118E9C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80118EA0: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80118EA4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80118EA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80118EAC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80118EB0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80118EB4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80118EB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118EBC: lwc1        $f8, -0x4464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118EC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118EC4: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118EC8: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80118ECC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80118ED0: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80118ED4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80118ED8: jal         0x8001EAD0
    // 0x80118EDC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_13;
    // 0x80118EDC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80118EE0: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80118EE4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80118EE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80118EEC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80118EF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118EF4: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80118EF8: lwc1        $f8, -0x4460($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118EFC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118F00: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x80118F04: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80118F08: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x80118F0C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80118F10: jal         0x8001EB64
    // 0x80118F14: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_14;
    // 0x80118F14: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80118F18: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80118F1C: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80118F20: jal         0x8001EAD0
    // 0x80118F24: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_15;
    // 0x80118F24: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x80118F28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118F2C: lwc1        $f2, -0x445C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80118F30: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80118F34: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80118F38: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80118F3C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80118F40: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80118F44: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80118F48: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80118F4C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80118F50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118F54: lwc1        $f12, -0x4464($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118F58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118F5C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80118F60: lwc1        $f14, -0x4460($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118F64: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80118F68: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80118F6C: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80118F70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80118F74: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80118F78: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80118F7C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80118F80: jal         0x801084C4
    // 0x80118F84: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_16;
    // 0x80118F84: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80118F88: beq         $v0, $zero, L_80118FD8
    if (ctx->r2 == 0) {
        // 0x80118F8C: lwc1        $f16, 0x70($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
            goto L_80118FD8;
    }
    // 0x80118F8C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80118F90: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x80118F94: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80118F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118F9C: lwc1        $f8, -0x4464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118FA0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80118FA4: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80118FA8: lwc1        $f10, 0x384($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X384);
    // 0x80118FAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118FB0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80118FB4: lwc1        $f8, -0x4460($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118FB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118FBC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80118FC0: lwc1        $f10, 0x388($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X388);
    // 0x80118FC4: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80118FC8: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80118FCC: lwc1        $f6, -0x445C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X445C);
    // 0x80118FD0: b           L_80118FF0
    // 0x80118FD4: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80118FF0;
    // 0x80118FD4: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
L_80118FD8:
    // 0x80118FD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118FDC: lwc1        $f0, -0x4464($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80118FE0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118FE4: lwc1        $f2, -0x4460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x80118FE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80118FEC: lwc1        $f18, -0x445C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X445C);
L_80118FF0:
    // 0x80118FF0: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
    // 0x80118FF4: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80118FF8: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80118FFC: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x80119000: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80119004: lwc1        $f12, 0x30($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80119008: lwc1        $f14, 0x34($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8011900C: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x80119010: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80119014: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x80119018: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x8011901C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80119020: jal         0x80117650
    // 0x80119024: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80117650)(rdram, ctx);
        goto after_17;
    // 0x80119024: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x80119028: lwc1        $f0, 0x9C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8011902C: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80119030: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80119034: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80119038: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8011903C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80119040: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x80119044: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80119048: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8011904C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80119050: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80119054: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x80119058: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8011905C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80119060: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80119064: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80119068: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8011906C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80119070: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80119074: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80119078: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8011907C: lwc1        $f10, 0x1C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80119080: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80119084: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80119088: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8011908C: addiu       $a0, $a0, -0x6734
    ctx->r4 = ADD32(ctx->r4, -0X6734);
    // 0x80119090: addiu       $a1, $zero, 0x26D
    ctx->r5 = ADD32(0, 0X26D);
    // 0x80119094: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80119098: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8011909C: jal         0x8011AAF4
    // 0x801190A0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_18;
    // 0x801190A0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x801190A4: addiu       $a0, $sp, 0x6E
    ctx->r4 = ADD32(ctx->r29, 0X6E);
    // 0x801190A8: jal         0x80119F9C
    // 0x801190AC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_19;
    // 0x801190AC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x801190B0: lw          $t0, 0xE8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE8);
    // 0x801190B4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801190B8: lh          $a2, -0x446C($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X446C);
    // 0x801190BC: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801190C0: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    // 0x801190C4: lh          $a1, 0x6C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X6C);
    // 0x801190C8: addiu       $t1, $v0, 0x4C
    ctx->r9 = ADD32(ctx->r2, 0X4C);
    // 0x801190CC: addiu       $t2, $v0, 0x50
    ctx->r10 = ADD32(ctx->r2, 0X50);
    // 0x801190D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801190D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801190D8: jal         0x8011A148
    // 0x801190DC: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_20;
    // 0x801190DC: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    after_20:
    // 0x801190E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801190E4:
    // 0x801190E4: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801190E8: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801190EC: jr          $ra
    // 0x801190F0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801190F0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801190f4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801190f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801190F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801190F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801190FC: jal         0x80117DA0
    // 0x80119100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80117DA0)(rdram, ctx);
        goto after_0;
    // 0x80119100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80119104: bnel        $v0, $zero, L_80119128
    if (ctx->r2 != 0) {
        // 0x80119108: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80119128;
    }
    goto skip_0;
    // 0x80119108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8011910C: jal         0x80117E58
    // 0x80119110: nop

    LOOKUP_FUNC(0x80117E58)(rdram, ctx);
        goto after_1;
    // 0x80119110: nop

    after_1:
    // 0x80119114: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80119118: addiu       $a1, $a1, -0x6EC4
    ctx->r5 = ADD32(ctx->r5, -0X6EC4);
    // 0x8011911C: jal         0x800058DC
    // 0x80119120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80119120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80119124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80119128:
    // 0x80119128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011912C: jr          $ra
    // 0x80119130: nop

    return;
    // 0x80119130: nop

;}
RECOMP_FUNC void M7_FUN_80119134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119134: jr          $ra
    // 0x80119138: nop

    return;
    // 0x80119138: nop

;}
RECOMP_FUNC void M7_FUN_8011913c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011913C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80119140(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80119140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119140: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80119144: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80119148: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8011914C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80119150: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80119154: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80119158: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8011915C: lhu         $t6, 0xEF0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XEF0);
    // 0x80119160: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80119164: beql        $t7, $zero, L_801191A4
    if (ctx->r15 == 0) {
        // 0x80119168: lhu         $t0, 0x9E($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X9E);
            goto L_801191A4;
    }
    goto skip_0;
    // 0x80119168: lhu         $t0, 0x9E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X9E);
    skip_0:
    // 0x8011916C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x80119170: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80119174: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80119178: sb          $t8, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r24;
    // 0x8011917C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80119180: jal         0x80117CD0
    // 0x80119184: lh          $a1, -0x4470($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4470);
    LOOKUP_FUNC(0x80117CD0)(rdram, ctx);
        goto after_0;
    // 0x80119184: lh          $a1, -0x4470($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4470);
    after_0:
    // 0x80119188: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8011918C: addiu       $a1, $a1, -0x6690
    ctx->r5 = ADD32(ctx->r5, -0X6690);
    // 0x80119190: jal         0x800058DC
    // 0x80119194: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80119194: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_1:
    // 0x80119198: b           L_80119B18
    // 0x8011919C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80119B18;
    // 0x8011919C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801191A0: lhu         $t0, 0x9E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X9E);
L_801191A4:
    // 0x801191A4: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x801191A8: beql        $t1, $zero, L_801191D0
    if (ctx->r9 == 0) {
        // 0x801191AC: lw          $t6, 0x24($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X24);
            goto L_801191D0;
    }
    goto skip_1;
    // 0x801191AC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x801191B0: lhu         $t2, 0x18E($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X18E);
    // 0x801191B4: bnel        $t2, $zero, L_801191D0
    if (ctx->r10 != 0) {
        // 0x801191B8: lw          $t6, 0x24($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X24);
            goto L_801191D0;
    }
    goto skip_2;
    // 0x801191B8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    skip_2:
    // 0x801191BC: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x801191C0: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x801191C4: bne         $t4, $zero, L_80119200
    if (ctx->r12 != 0) {
        // 0x801191C8: nop
    
            goto L_80119200;
    }
    // 0x801191C8: nop

    // 0x801191CC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
L_801191D0:
    // 0x801191D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801191D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801191D8: sb          $t5, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r13;
    // 0x801191DC: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x801191E0: jal         0x80117CD0
    // 0x801191E4: lh          $a1, -0x4470($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4470);
    LOOKUP_FUNC(0x80117CD0)(rdram, ctx);
        goto after_2;
    // 0x801191E4: lh          $a1, -0x4470($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4470);
    after_2:
    // 0x801191E8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801191EC: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x801191F0: jal         0x800058DC
    // 0x801191F4: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801191F4: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_3:
    // 0x801191F8: b           L_80119B18
    // 0x801191FC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80119B18;
    // 0x801191FC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80119200:
    // 0x80119200: jal         0x80117F64
    // 0x80119204: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80117F64)(rdram, ctx);
        goto after_4;
    // 0x80119204: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_4:
    // 0x80119208: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8011920C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80119210: addiu       $a1, $a1, -0x446E
    ctx->r5 = ADD32(ctx->r5, -0X446E);
    // 0x80119214: jal         0x80118038
    // 0x80119218: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    LOOKUP_FUNC(0x80118038)(rdram, ctx);
        goto after_5;
    // 0x80119218: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    after_5:
    // 0x8011921C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80119220: addiu       $v0, $v0, -0x446E
    ctx->r2 = ADD32(ctx->r2, -0X446E);
    // 0x80119224: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80119228: slti        $at, $a0, 0x601
    ctx->r1 = SIGNED(ctx->r4) < 0X601 ? 1 : 0;
    // 0x8011922C: bne         $at, $zero, L_8011923C
    if (ctx->r1 != 0) {
        // 0x80119230: addiu       $t7, $zero, 0x600
        ctx->r15 = ADD32(0, 0X600);
            goto L_8011923C;
    }
    // 0x80119230: addiu       $t7, $zero, 0x600
    ctx->r15 = ADD32(0, 0X600);
    // 0x80119234: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80119238: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
L_8011923C:
    // 0x8011923C: slti        $at, $a0, -0x600
    ctx->r1 = SIGNED(ctx->r4) < -0X600 ? 1 : 0;
    // 0x80119240: beq         $at, $zero, L_80119250
    if (ctx->r1 == 0) {
        // 0x80119244: addiu       $t8, $zero, -0x600
        ctx->r24 = ADD32(0, -0X600);
            goto L_80119250;
    }
    // 0x80119244: addiu       $t8, $zero, -0x600
    ctx->r24 = ADD32(0, -0X600);
    // 0x80119248: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8011924C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
L_80119250:
    // 0x80119250: jal         0x8001EB64
    // 0x80119254: nop

    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x80119254: nop

    after_6:
    // 0x80119258: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8011925C: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x80119260: jal         0x8001EB64
    // 0x80119264: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x80119264: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80119268: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8011926C: lwc1        $f4, -0x444C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x80119270: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80119274: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80119278: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x8011927C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80119280: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119284: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80119288: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x8011928C: lwc1        $f4, 0x3C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80119290: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80119294: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80119298: jal         0x8001EAD0
    // 0x8011929C: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x8011929C: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x801192A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801192A4: lwc1        $f4, -0x444C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x801192A8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801192AC: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x801192B0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801192B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801192B8: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801192BC: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x801192C0: lwc1        $f8, 0x40($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X40);
    // 0x801192C4: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801192C8: jal         0x8001EB64
    // 0x801192CC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x801192CC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x801192D0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801192D4: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x801192D8: jal         0x8001EAD0
    // 0x801192DC: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x801192DC: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x801192E0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x801192E4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801192E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801192EC: lwc1        $f4, -0x444C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X444C);
    // 0x801192F0: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801192F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801192F8: lw          $v0, -0x4328($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4328);
    // 0x801192FC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80119300: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80119304: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80119308: lw          $v1, -0x4330($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4330);
    // 0x8011930C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80119310: lwc1        $f4, 0x44($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X44);
    // 0x80119314: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80119318: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8011931C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80119320: lw          $t0, 0x36F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X36F4);
    // 0x80119324: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119328: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x8011932C: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x80119330: lw          $t5, 0x2C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2C);
    // 0x80119334: lwc1        $f12, 0x3C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x80119338: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8011933C: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80119340: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80119344: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80119348: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8011934C: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80119350: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80119354: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80119358: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x8011935C: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80119360: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x80119364: lwc1        $f10, 0x40($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80119368: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8011936C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x80119370: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80119374: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80119378: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x8011937C: sub.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d - ctx->f2.d;
    // 0x80119380: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80119384: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x80119388: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8011938C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x80119390: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80119394: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x80119398: lwc1        $f14, 0x44($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8011939C: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801193A0: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x801193A4: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x801193A8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801193AC: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x801193B0: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x801193B4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801193B8: beq         $t0, $zero, L_8011970C
    if (ctx->r8 == 0) {
        // 0x801193BC: swc1        $f10, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
            goto L_8011970C;
    }
    // 0x801193BC: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x801193C0: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801193C4: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801193C8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801193CC: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801193D0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801193D4: nop

    // 0x801193D8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801193DC: jal         0x8002FC20
    // 0x801193E0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_11;
    // 0x801193E0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_11:
    // 0x801193E4: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801193E8: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801193EC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801193F0: jal         0x8001EF38
    // 0x801193F4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_12;
    // 0x801193F4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_12:
    // 0x801193F8: andi        $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 & 0X1000;
    // 0x801193FC: beq         $t1, $zero, L_8011944C
    if (ctx->r9 == 0) {
        // 0x80119400: lwc1        $f10, 0xC4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
            goto L_8011944C;
    }
    // 0x80119400: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119404: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119408: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8011940C: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119410: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119414: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119418: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8011941C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119420: nop

    // 0x80119424: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80119428: jal         0x8002FC20
    // 0x8011942C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_13;
    // 0x8011942C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_13:
    // 0x80119430: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119434: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119438: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8011943C: jal         0x8001EF38
    // 0x80119440: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_14;
    // 0x80119440: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_14:
    // 0x80119444: b           L_8011948C
    // 0x80119448: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
        goto L_8011948C;
    // 0x80119448: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
L_8011944C:
    // 0x8011944C: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119450: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119454: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119458: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8011945C: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80119460: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119464: nop

    // 0x80119468: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011946C: jal         0x8002FC20
    // 0x80119470: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_15;
    // 0x80119470: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_15:
    // 0x80119474: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119478: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8011947C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80119480: jal         0x8001EF38
    // 0x80119484: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_16;
    // 0x80119484: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_16:
    // 0x80119488: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
L_8011948C:
    // 0x8011948C: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119490: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119494: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119498: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011949C: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801194A0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801194A4: nop

    // 0x801194A8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801194AC: jal         0x8002FC20
    // 0x801194B0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_17;
    // 0x801194B0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_17:
    // 0x801194B4: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801194B8: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801194BC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801194C0: jal         0x8001EF38
    // 0x801194C4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_18;
    // 0x801194C4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    after_18:
    // 0x801194C8: andi        $t2, $v0, 0x1000
    ctx->r10 = ctx->r2 & 0X1000;
    // 0x801194CC: beq         $t2, $zero, L_80119520
    if (ctx->r10 == 0) {
        // 0x801194D0: lwc1        $f4, 0xC4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
            goto L_80119520;
    }
    // 0x801194D0: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801194D4: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801194D8: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801194DC: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801194E0: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801194E4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801194E8: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801194EC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801194F0: nop

    // 0x801194F4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801194F8: jal         0x8002FC20
    // 0x801194FC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_19;
    // 0x801194FC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_19:
    // 0x80119500: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119504: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119508: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8011950C: jal         0x8001EF38
    // 0x80119510: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_20;
    // 0x80119510: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_20:
    // 0x80119514: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x80119518: b           L_80119560
    // 0x8011951C: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
        goto L_80119560;
    // 0x8011951C: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
L_80119520:
    // 0x80119520: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119524: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119528: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8011952C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119530: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80119534: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119538: nop

    // 0x8011953C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80119540: jal         0x8002FC20
    // 0x80119544: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_21;
    // 0x80119544: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_21:
    // 0x80119548: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8011954C: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119550: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80119554: jal         0x8001EF38
    // 0x80119558: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_22;
    // 0x80119558: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_22:
    // 0x8011955C: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
L_80119560:
    // 0x80119560: bgez        $v1, L_80119640
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80119564: lwc1        $f4, 0xC4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
            goto L_80119640;
    }
    // 0x80119564: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119568: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8011956C: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119570: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119574: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119578: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8011957C: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80119580: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119584: nop

    // 0x80119588: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011958C: jal         0x8002FC20
    // 0x80119590: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_23;
    // 0x80119590: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_23:
    // 0x80119594: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119598: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8011959C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801195A0: jal         0x8001EF38
    // 0x801195A4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_24;
    // 0x801195A4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_24:
    // 0x801195A8: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x801195AC: beq         $t3, $zero, L_801195FC
    if (ctx->r11 == 0) {
        // 0x801195B0: lwc1        $f6, 0xC4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
            goto L_801195FC;
    }
    // 0x801195B0: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801195B4: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801195B8: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801195BC: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801195C0: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801195C4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801195C8: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801195CC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801195D0: nop

    // 0x801195D4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801195D8: jal         0x8002FC20
    // 0x801195DC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_25;
    // 0x801195DC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_25:
    // 0x801195E0: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801195E4: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801195E8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801195EC: jal         0x8001EF38
    // 0x801195F0: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_26;
    // 0x801195F0: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    after_26:
    // 0x801195F4: b           L_8011970C
    // 0x801195F8: nop

        goto L_8011970C;
    // 0x801195F8: nop

L_801195FC:
    // 0x801195FC: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119600: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119604: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119608: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8011960C: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80119610: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119614: nop

    // 0x80119618: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011961C: jal         0x8002FC20
    // 0x80119620: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_27;
    // 0x80119620: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_27:
    // 0x80119624: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119628: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8011962C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80119630: jal         0x8001EF38
    // 0x80119634: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_28;
    // 0x80119634: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_28:
    // 0x80119638: b           L_8011970C
    // 0x8011963C: nop

        goto L_8011970C;
    // 0x8011963C: nop

L_80119640:
    // 0x80119640: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119644: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119648: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8011964C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119650: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80119654: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119658: nop

    // 0x8011965C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80119660: jal         0x8002FC20
    // 0x80119664: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_29;
    // 0x80119664: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_29:
    // 0x80119668: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8011966C: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119670: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80119674: jal         0x8001EF38
    // 0x80119678: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_30;
    // 0x80119678: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_30:
    // 0x8011967C: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x80119680: beq         $t4, $zero, L_801196D0
    if (ctx->r12 == 0) {
        // 0x80119684: lwc1        $f8, 0xC4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
            goto L_801196D0;
    }
    // 0x80119684: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119688: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8011968C: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119690: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119694: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119698: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8011969C: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801196A0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801196A4: nop

    // 0x801196A8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801196AC: jal         0x8002FC20
    // 0x801196B0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_31;
    // 0x801196B0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_31:
    // 0x801196B4: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801196B8: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801196BC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801196C0: jal         0x8001EF38
    // 0x801196C4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_32;
    // 0x801196C4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_32:
    // 0x801196C8: b           L_8011970C
    // 0x801196CC: nop

        goto L_8011970C;
    // 0x801196CC: nop

L_801196D0:
    // 0x801196D0: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801196D4: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801196D8: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801196DC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801196E0: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801196E4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801196E8: nop

    // 0x801196EC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801196F0: jal         0x8002FC20
    // 0x801196F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_33;
    // 0x801196F4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_33:
    // 0x801196F8: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801196FC: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119700: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80119704: jal         0x8001EF38
    // 0x80119708: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_34;
    // 0x80119708: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    after_34:
L_8011970C:
    // 0x8011970C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119710: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80119714: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x80119718: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x8011971C: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x80119720: addiu       $t8, $sp, 0xB0
    ctx->r24 = ADD32(ctx->r29, 0XB0);
    // 0x80119724: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80119728: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8011972C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80119730: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80119734: lh          $a1, -0x446E($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X446E);
    // 0x80119738: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x8011973C: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x80119740: jal         0x8011E480
    // 0x80119744: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    LOOKUP_FUNC(0x8011E480)(rdram, ctx);
        goto after_35;
    // 0x80119744: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    after_35:
    // 0x80119748: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8011974C: jal         0x8001EB64
    // 0x80119750: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_36;
    // 0x80119750: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    after_36:
    // 0x80119754: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119758: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x8011975C: jal         0x8001EB64
    // 0x80119760: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_37;
    // 0x80119760: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x80119764: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80119768: lui         $at, 0x401A
    ctx->r1 = S32(0X401A << 16);
    // 0x8011976C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80119770: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80119774: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80119778: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8011977C: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80119780: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119784: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119788: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x8011978C: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80119790: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80119794: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80119798: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8011979C: jal         0x8001EAD0
    // 0x801197A0: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_38;
    // 0x801197A0: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    after_38:
    // 0x801197A4: lui         $at, 0x401A
    ctx->r1 = S32(0X401A << 16);
    // 0x801197A8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801197AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801197B0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801197B4: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801197B8: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801197BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801197C0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801197C4: lh          $a0, -0x446E($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X446E);
    // 0x801197C8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801197CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801197D0: jal         0x8001EB64
    // 0x801197D4: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_39;
    // 0x801197D4: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    after_39:
    // 0x801197D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801197DC: lh          $a0, -0x4470($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4470);
    // 0x801197E0: jal         0x8001EAD0
    // 0x801197E4: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_40;
    // 0x801197E4: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_40:
    // 0x801197E8: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801197EC: lui         $at, 0x401A
    ctx->r1 = S32(0X401A << 16);
    // 0x801197F0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801197F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801197F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801197FC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80119800: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80119804: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119808: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8011980C: lwc1        $f14, 0xC0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119810: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80119814: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80119818: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x8011981C: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80119820: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80119824: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80119828: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x8011982C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80119830: swc1        $f2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f2.u32l;
    // 0x80119834: jal         0x801084C4
    // 0x80119838: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_41;
    // 0x80119838: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_41:
    // 0x8011983C: beq         $v0, $zero, L_80119890
    if (ctx->r2 == 0) {
        // 0x80119840: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80119890;
    }
    // 0x80119840: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80119844: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80119848: lwc1        $f4, 0x380($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X380);
    // 0x8011984C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80119850: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119854: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119858: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8011985C: lwc1        $f8, 0x384($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X384);
    // 0x80119860: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80119864: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80119868: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011986C: swc1        $f4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f4.u32l;
    // 0x80119870: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119874: lwc1        $f10, 0x388($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X388);
    // 0x80119878: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8011987C: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80119880: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80119884: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80119888: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8011988C: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
L_80119890:
    // 0x80119890: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80119894: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80119898: lw          $v0, 0xE8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE8);
    // 0x8011989C: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801198A0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x801198A4: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x801198A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801198AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801198B0: lwc1        $f0, 0x30($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X30);
    // 0x801198B4: lwc1        $f14, 0xC0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801198B8: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x801198BC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801198C0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801198C4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801198C8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801198CC: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x801198D0: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801198D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801198D8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801198DC: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    // 0x801198E0: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801198E4: lwc1        $f2, 0x38($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801198E8: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801198EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801198F0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801198F4: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801198F8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x801198FC: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80119900: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80119904: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80119908: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8011990C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80119910: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80119914: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80119918: jal         0x80117650
    // 0x8011991C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80117650)(rdram, ctx);
        goto after_42;
    // 0x8011991C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_42:
    // 0x80119920: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119924: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119928: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8011992C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80119930: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80119934: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80119938: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8011993C: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119940: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80119944: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80119948: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x8011994C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80119950: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80119954: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80119958: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8011995C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80119960: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80119964: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80119968: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8011996C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80119970: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x80119974: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80119978: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8011997C: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80119980: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80119984: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80119988: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8011998C: addiu       $a0, $a0, -0x65EC
    ctx->r4 = ADD32(ctx->r4, -0X65EC);
    // 0x80119990: addiu       $a1, $zero, 0x310
    ctx->r5 = ADD32(0, 0X310);
    // 0x80119994: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x80119998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8011999C: jal         0x8011AAF4
    // 0x801199A0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_43;
    // 0x801199A0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_43:
    // 0x801199A4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801199A8: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801199AC: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801199B0: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801199B4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801199B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801199BC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801199C0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801199C4: sub.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801199C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801199CC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801199D0: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801199D4: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x801199D8: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801199DC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801199E0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801199E4: sub.d       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f8.d - ctx->f6.d;
    // 0x801199E8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801199EC: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801199F0: mul.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x801199F4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801199F8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801199FC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80119A00: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80119A04: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80119A08: jal         0x8002FC20
    // 0x80119A0C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_44;
    // 0x80119A0C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_44:
    // 0x80119A10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80119A14: ldc1        $f4, -0x64B8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X64B8);
    // 0x80119A18: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80119A1C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80119A20: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80119A24: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80119A28: bc1f        L_80119A3C
    if (!c1cs) {
        // 0x80119A2C: nop
    
            goto L_80119A3C;
    }
    // 0x80119A2C: nop

    // 0x80119A30: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80119A34: b           L_80119AD4
    // 0x80119A38: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
        goto L_80119AD4;
    // 0x80119A38: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
L_80119A3C:
    // 0x80119A3C: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x80119A40: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80119A44: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80119A48: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x80119A4C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80119A50: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80119A54: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80119A58: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80119A5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80119A60: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80119A64: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80119A68: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80119A6C: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80119A70: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80119A74: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80119A78: sub.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f4.d - ctx->f10.d;
    // 0x80119A7C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80119A80: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80119A84: mul.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x80119A88: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80119A8C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80119A90: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80119A94: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80119A98: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x80119A9C: jal         0x8002FC20
    // 0x80119AA0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_45;
    // 0x80119AA0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_45:
    // 0x80119AA4: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x80119AA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80119AAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80119AB0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80119AB4: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80119AB8: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80119ABC: nop

    // 0x80119AC0: bc1fl       L_80119AD8
    if (!c1cs) {
        // 0x80119AC4: addiu       $a0, $sp, 0xA2
        ctx->r4 = ADD32(ctx->r29, 0XA2);
            goto L_80119AD8;
    }
    goto skip_3;
    // 0x80119AC4: addiu       $a0, $sp, 0xA2
    ctx->r4 = ADD32(ctx->r29, 0XA2);
    skip_3:
    // 0x80119AC8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80119ACC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80119AD0: sb          $t0, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r8;
L_80119AD4:
    // 0x80119AD4: addiu       $a0, $sp, 0xA2
    ctx->r4 = ADD32(ctx->r29, 0XA2);
L_80119AD8:
    // 0x80119AD8: jal         0x80119F9C
    // 0x80119ADC: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_46;
    // 0x80119ADC: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    after_46:
    // 0x80119AE0: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80119AE4: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x80119AE8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80119AEC: lh          $a2, -0x446C($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X446C);
    // 0x80119AF0: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x80119AF4: lh          $a0, 0xA2($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XA2);
    // 0x80119AF8: lh          $a1, 0xA0($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XA0);
    // 0x80119AFC: addiu       $t4, $v0, 0x4C
    ctx->r12 = ADD32(ctx->r2, 0X4C);
    // 0x80119B00: addiu       $t5, $v0, 0x50
    ctx->r13 = ADD32(ctx->r2, 0X50);
    // 0x80119B04: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80119B08: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80119B0C: jal         0x8011A148
    // 0x80119B10: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_47;
    // 0x80119B10: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    after_47:
    // 0x80119B14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80119B18:
    // 0x80119B18: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80119B1C: jr          $ra
    // 0x80119B20: nop

    return;
    // 0x80119B20: nop

;}
RECOMP_FUNC void M7_FUN_80119b24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80119B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80119B2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80119B30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80119B34: jal         0x80117610
    // 0x80119B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80117610)(rdram, ctx);
        goto after_0;
    // 0x80119B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80119B3C: beq         $v0, $zero, L_80119B70
    if (ctx->r2 == 0) {
        // 0x80119B40: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80119B70;
    }
    // 0x80119B40: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119B44: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80119B48: addiu       $a1, $a1, -0x446E
    ctx->r5 = ADD32(ctx->r5, -0X446E);
    // 0x80119B4C: jal         0x80119F9C
    // 0x80119B50: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_1;
    // 0x80119B50: addiu       $a0, $a0, -0x4470
    ctx->r4 = ADD32(ctx->r4, -0X4470);
    after_1:
    // 0x80119B54: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80119B58: jal         0x8011A0F0
    // 0x80119B5C: addiu       $a0, $a0, -0x446C
    ctx->r4 = ADD32(ctx->r4, -0X446C);
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_2;
    // 0x80119B5C: addiu       $a0, $a0, -0x446C
    ctx->r4 = ADD32(ctx->r4, -0X446C);
    after_2:
    // 0x80119B60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80119B64: addiu       $a1, $a1, -0x6480
    ctx->r5 = ADD32(ctx->r5, -0X6480);
    // 0x80119B68: jal         0x800058DC
    // 0x80119B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80119B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_80119B70:
    // 0x80119B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80119B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80119B78: jr          $ra
    // 0x80119B7C: nop

    return;
    // 0x80119B7C: nop

;}
RECOMP_FUNC void M7_FUN_80119b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119B80: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80119B84: lhu         $t6, -0x4372($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4372);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80119b88(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80119b88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80119B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80119B90: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80119B94: bne         $t7, $zero, L_80119BA8
    if (ctx->r15 != 0) {
        // 0x80119B98: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80119BA8;
    }
    // 0x80119B98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80119B9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80119BA0: jal         0x800058DC
    // 0x80119BA4: addiu       $a1, $a1, -0x6448
    ctx->r5 = ADD32(ctx->r5, -0X6448);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80119BA4: addiu       $a1, $a1, -0x6448
    ctx->r5 = ADD32(ctx->r5, -0X6448);
    after_0:
L_80119BA8:
    // 0x80119BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80119BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80119BB0: jr          $ra
    // 0x80119BB4: nop

    return;
    // 0x80119BB4: nop

;}
RECOMP_FUNC void M7_FUN_80119bb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119BB8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80119BBC: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x80119BC0: lhu         $t6, 0x1DC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1DC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80119bc4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80119bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80119BC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80119BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80119BD0: bne         $t6, $at, L_80119C0C
    if (ctx->r14 != ctx->r1) {
        // 0x80119BD4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80119C0C;
    }
    // 0x80119BD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80119BD8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80119BDC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80119BE0: addiu       $v1, $v1, 0x3874
    ctx->r3 = ADD32(ctx->r3, 0X3874);
    // 0x80119BE4: addiu       $v0, $v0, 0x3878
    ctx->r2 = ADD32(ctx->r2, 0X3878);
    // 0x80119BE8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80119BEC: sh          $t7, 0x1DA($a2)
    MEM_H(0X1DA, ctx->r6) = ctx->r15;
    // 0x80119BF0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80119BF4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80119BF8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80119BFC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80119C00: sb          $zero, 0x3870($at)
    MEM_B(0X3870, ctx->r1) = 0;
    // 0x80119C04: jal         0x800058DC
    // 0x80119C08: addiu       $a1, $a1, -0x544
    ctx->r5 = ADD32(ctx->r5, -0X544);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80119C08: addiu       $a1, $a1, -0x544
    ctx->r5 = ADD32(ctx->r5, -0X544);
    after_0:
L_80119C0C:
    // 0x80119C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80119C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80119C14: jr          $ra
    // 0x80119C18: nop

    return;
    // 0x80119C18: nop

;}
RECOMP_FUNC void M7_FUN_80119c1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119C1C: nop

;}
RECOMP_FUNC void M7_FUN_80119c20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119C20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80119C24: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80119C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80119C2C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80119C30: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80119C34: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80119C38: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80119C3C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119C40: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80119C44: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80119C48: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80119C4C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80119C50: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80119C54: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80119C58: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80119C5C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80119C60: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80119C64: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80119C68: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80119C6C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80119C70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80119C74: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80119C78: jal         0x8002FC20
    // 0x80119C7C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80119C7C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_0:
    // 0x80119C80: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80119C84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80119C88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80119C8C: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80119C90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80119C94: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80119C98: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80119C9C: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80119CA0: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80119CA4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80119CA8: nop

    // 0x80119CAC: bc1fl       L_80119CC0
    if (!c1cs) {
        // 0x80119CB0: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80119CC0;
    }
    goto skip_0;
    // 0x80119CB0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x80119CB4: b           L_80119D28
    // 0x80119CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80119D28;
    // 0x80119CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80119CBC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80119CC0:
    // 0x80119CC0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80119CC4: bc1fl       L_80119D14
    if (!c1cs) {
        // 0x80119CC8: swc1        $f18, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
            goto L_80119D14;
    }
    goto skip_1;
    // 0x80119CC8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    skip_1:
    // 0x80119CCC: div.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80119CD0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80119CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80119CD8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80119CDC: div.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80119CE0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80119CE4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80119CE8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80119CEC: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80119CF0: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80119CF4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80119CF8: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80119CFC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80119D00: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80119D04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80119D08: b           L_80119D28
    // 0x80119D0C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_80119D28;
    // 0x80119D0C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80119D10: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_80119D14:
    // 0x80119D14: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80119D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80119D1C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80119D20: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80119D24: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
L_80119D28:
    // 0x80119D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80119D2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80119D30: jr          $ra
    // 0x80119D34: nop

    return;
    // 0x80119D34: nop

;}
RECOMP_FUNC void M7_FUN_80119d38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119D38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80119D3C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80119D40: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80119D44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80119D48: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80119D4C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80119D50: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80119D54: nop

    // 0x80119D58: bc1fl       L_80119D6C
    if (!c1cs) {
        // 0x80119D5C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80119D6C;
    }
    goto skip_0;
    // 0x80119D5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80119D60: jr          $ra
    // 0x80119D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80119D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80119D68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80119D6C:
    // 0x80119D6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80119D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80119D74: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80119D78: nop

    // 0x80119D7C: bc1fl       L_80119D90
    if (!c1cs) {
        // 0x80119D80: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_80119D90;
    }
    goto skip_1;
    // 0x80119D80: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    skip_1:
    // 0x80119D84: b           L_80119D90
    // 0x80119D88: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
        goto L_80119D90;
    // 0x80119D88: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80119D8C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80119D90:
    // 0x80119D90: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80119D94: nop

    // 0x80119D98: bc1fl       L_80119DAC
    if (!c1cs) {
        // 0x80119D9C: mov.s       $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
            goto L_80119DAC;
    }
    goto skip_2;
    // 0x80119D9C: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    skip_2:
    // 0x80119DA0: b           L_80119DAC
    // 0x80119DA4: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
        goto L_80119DAC;
    // 0x80119DA4: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
    // 0x80119DA8: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80119DAC:
    // 0x80119DAC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80119DB0: nop

    // 0x80119DB4: bc1fl       L_80119E1C
    if (!c1cs) {
        // 0x80119DB8: swc1        $f12, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
            goto L_80119E1C;
    }
    goto skip_3;
    // 0x80119DB8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    skip_3:
    // 0x80119DBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80119DC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80119DC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80119DC8: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80119DCC: nop

    // 0x80119DD0: bc1fl       L_80119DE4
    if (!c1cs) {
        // 0x80119DD4: mov.s       $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
            goto L_80119DE4;
    }
    goto skip_4;
    // 0x80119DD4: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    skip_4:
    // 0x80119DD8: b           L_80119DE4
    // 0x80119DDC: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
        goto L_80119DE4;
    // 0x80119DDC: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
    // 0x80119DE0: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80119DE4:
    // 0x80119DE4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80119DE8: nop

    // 0x80119DEC: bc1f        L_80119DFC
    if (!c1cs) {
        // 0x80119DF0: nop
    
            goto L_80119DFC;
    }
    // 0x80119DF0: nop

    // 0x80119DF4: b           L_80119DFC
    // 0x80119DF8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80119DFC;
    // 0x80119DF8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80119DFC:
    // 0x80119DFC: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80119E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80119E04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80119E08: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80119E0C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80119E10: jr          $ra
    // 0x80119E14: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80119E14: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80119E18: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_80119E1C:
    // 0x80119E1C: jr          $ra
    // 0x80119E20: nop

    return;
    // 0x80119E20: nop

;}
RECOMP_FUNC void M7_FUN_80119e24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119E24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80119E28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80119E2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80119E30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80119E34: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80119E38: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80119E3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80119E40: jal         0x80119F9C
    // 0x80119E44: addiu       $a0, $sp, 0x36
    ctx->r4 = ADD32(ctx->r29, 0X36);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_0;
    // 0x80119E44: addiu       $a0, $sp, 0x36
    ctx->r4 = ADD32(ctx->r29, 0X36);
    after_0:
    // 0x80119E48: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80119E4C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80119E50: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80119E54: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80119E58: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80119E5C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80119E60: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x80119E64: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80119E68: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80119E6C: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x80119E70: jal         0x8011A06C
    // 0x80119E74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011A06C)(rdram, ctx);
        goto after_1;
    // 0x80119E74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80119E78: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x80119E7C: lh          $t1, 0x46($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X46);
    // 0x80119E80: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80119E84: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80119E88: subu        $v1, $t1, $a2
    ctx->r3 = SUB32(ctx->r9, ctx->r6);
    // 0x80119E8C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80119E90: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80119E94: andi        $t4, $v1, 0x1000
    ctx->r12 = ctx->r3 & 0X1000;
    // 0x80119E98: beq         $t4, $zero, L_80119EB4
    if (ctx->r12 == 0) {
        // 0x80119E9C: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80119EB4;
    }
    // 0x80119E9C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80119EA0: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x80119EA4: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x80119EA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80119EAC: b           L_80119EC0
    // 0x80119EB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80119EC0;
    // 0x80119EB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80119EB4:
    // 0x80119EB4: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x80119EB8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80119EBC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80119EC0:
    // 0x80119EC0: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x80119EC4: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80119EC8: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80119ECC: mflo        $t5
    ctx->r13 = lo;
    // 0x80119ED0: bgez        $t5, L_80119F00
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80119ED4: nop
    
            goto L_80119F00;
    }
    // 0x80119ED4: nop

    // 0x80119ED8: bgez        $v0, L_80119EE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80119EDC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80119EE8;
    }
    // 0x80119EDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80119EE0: b           L_80119EE8
    // 0x80119EE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80119EE8;
    // 0x80119EE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80119EE8:
    // 0x80119EE8: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x80119EEC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80119EF0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80119EF4: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80119EF8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80119EFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80119F00:
    // 0x80119F00: bne         $t0, $zero, L_80119F10
    if (ctx->r8 != 0) {
        // 0x80119F04: nop
    
            goto L_80119F10;
    }
    // 0x80119F04: nop

    // 0x80119F08: b           L_80119F8C
    // 0x80119F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80119F8C;
    // 0x80119F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80119F10:
    // 0x80119F10: bgez        $v0, L_80119F20
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80119F14: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80119F20;
    }
    // 0x80119F14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80119F18: b           L_80119F20
    // 0x80119F1C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_80119F20;
    // 0x80119F1C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80119F20:
    // 0x80119F20: bgez        $t0, L_80119F30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80119F24: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80119F30;
    }
    // 0x80119F24: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80119F28: b           L_80119F30
    // 0x80119F2C: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
        goto L_80119F30;
    // 0x80119F2C: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
L_80119F30:
    // 0x80119F30: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80119F34: beq         $at, $zero, L_80119F68
    if (ctx->r1 == 0) {
        // 0x80119F38: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_80119F68;
    }
    // 0x80119F38: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80119F3C: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x80119F40: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80119F44: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80119F48: sh          $a2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r6;
    // 0x80119F4C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80119F50: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x80119F54: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80119F58: jal         0x8011A148
    // 0x80119F5C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_2;
    // 0x80119F5C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_2:
    // 0x80119F60: b           L_80119F8C
    // 0x80119F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80119F8C;
    // 0x80119F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80119F68:
    // 0x80119F68: andi        $a2, $t1, 0x1FFF
    ctx->r6 = ctx->r9 & 0X1FFF;
    // 0x80119F6C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80119F70: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80119F74: sh          $a2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r6;
    // 0x80119F78: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x80119F7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80119F80: jal         0x8011A148
    // 0x80119F84: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_3;
    // 0x80119F84: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_3:
    // 0x80119F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80119F8C:
    // 0x80119F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80119F90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80119F94: jr          $ra
    // 0x80119F98: nop

    return;
    // 0x80119F98: nop

;}
RECOMP_FUNC void M7_FUN_80119f9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80119F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80119FA0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80119FA4: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x80119FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80119FAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80119FB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80119FB4: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80119FB8: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80119FBC: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80119FC0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80119FC4: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80119FC8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80119FCC: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80119FD0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80119FD4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80119FD8: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80119FDC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80119FE0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80119FE4: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80119FE8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80119FEC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80119FF0: jal         0x8002FC20
    // 0x80119FF4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80119FF4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x80119FF8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80119FFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8011A000: jal         0x8001EF38
    // 0x8011A004: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x8011A004: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8011A008: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8011A00C: andi        $t7, $v0, 0x1FFF
    ctx->r15 = ctx->r2 & 0X1FFF;
    // 0x8011A010: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8011A014: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8011A018: jal         0x8001EF38
    // 0x8011A01C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8011A01C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8011A020: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x8011A024: beq         $t9, $zero, L_8011A048
    if (ctx->r25 == 0) {
        // 0x8011A028: lwc1        $f14, 0x18($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8011A048;
    }
    // 0x8011A028: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8011A02C: jal         0x8001EF38
    // 0x8011A030: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x8011A030: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8011A034: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8011A038: andi        $t0, $v0, 0x1FFF
    ctx->r8 = ctx->r2 & 0X1FFF;
    // 0x8011A03C: addiu       $t1, $t0, -0x2000
    ctx->r9 = ADD32(ctx->r8, -0X2000);
    // 0x8011A040: b           L_8011A05C
    // 0x8011A044: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
        goto L_8011A05C;
    // 0x8011A044: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_8011A048:
    // 0x8011A048: jal         0x8001EF38
    // 0x8011A04C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x8011A04C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8011A050: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8011A054: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x8011A058: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_8011A05C:
    // 0x8011A05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011A060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011A064: jr          $ra
    // 0x8011A068: nop

    return;
    // 0x8011A068: nop

;}
RECOMP_FUNC void M7_FUN_8011a06c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A06C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011A070: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8011A074: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011A078: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x8011A07C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8011A080: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8011A084: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
    // 0x8011A088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011A08C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8011A090: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8011A094: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8011A098: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8011A09C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8011A0A0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8011A0A4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8011A0A8: jal         0x80130C40
    // 0x8011A0AC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_0;
    // 0x8011A0AC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8011A0B0: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x8011A0B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8011A0B8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8011A0BC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8011A0C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8011A0C4: jal         0x80130C40
    // 0x8011A0C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_1;
    // 0x8011A0C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8011A0CC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8011A0D0: jal         0x8001EF38
    // 0x8011A0D4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8011A0D4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8011A0D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8011A0DC: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // 0x8011A0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011A0E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011A0E8: jr          $ra
    // 0x8011A0EC: nop

    return;
    // 0x8011A0EC: nop

;}
RECOMP_FUNC void M7_FUN_8011a0f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A0F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011A0F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011A0F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011A0FC: addiu       $a0, $sp, 0x26
    ctx->r4 = ADD32(ctx->r29, 0X26);
    // 0x8011A100: jal         0x80119F9C
    // 0x8011A104: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_0;
    // 0x8011A104: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8011A108: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8011A10C: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x8011A110: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8011A114: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x8011A118: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8011A11C: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x8011A120: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8011A124: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x8011A128: lw          $a3, 0x4C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4C);
    // 0x8011A12C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8011A130: jal         0x8011A06C
    // 0x8011A134: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011A06C)(rdram, ctx);
        goto after_1;
    // 0x8011A134: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8011A138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8011A13C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011A140: jr          $ra
    // 0x8011A144: nop

    return;
    // 0x8011A144: nop

;}
RECOMP_FUNC void M7_FUN_8011a148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011A14C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8011A150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011A154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8011A158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8011A15C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8011A160: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8011A164: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8011A168: jal         0x8001EB64
    // 0x8011A16C: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8011A16C: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x8011A170: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8011A174: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8011A178: jal         0x8001EAD0
    // 0x8011A17C: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8011A17C: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x8011A180: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8011A184: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x8011A188: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8011A18C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8011A190: jal         0x80130C40
    // 0x8011A194: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_2;
    // 0x8011A194: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_2:
    // 0x8011A198: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x8011A19C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8011A1A0: jal         0x80130C40
    // 0x8011A1A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_3;
    // 0x8011A1A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8011A1A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011A1AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011A1B0: jr          $ra
    // 0x8011A1B4: nop

    return;
    // 0x8011A1B4: nop

;}
RECOMP_FUNC void M7_FUN_8011a1b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A1B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011A1BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011A1C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8011A1C4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8011A1C8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8011A1CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8011A1D0: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8011A1D4: lwc1        $f8, 0x2E4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X2E4);
    // 0x8011A1D8: lwc1        $f10, 0x2BC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X2BC);
    // 0x8011A1DC: lwc1        $f4, 0x2FC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2FC);
    // 0x8011A1E0: lwc1        $f6, 0x2D4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2D4);
    // 0x8011A1E4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011A1E8: lwc1        $f16, 0x2F0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X2F0);
    // 0x8011A1EC: lwc1        $f18, 0x2C8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C8);
    // 0x8011A1F0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8011A1F4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011A1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011A1FC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8011A200: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8011A204: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8011A208: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8011A20C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8011A210: jal         0x8002FC20
    // 0x8011A214: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8011A214: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8011A218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8011A21C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8011A220: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8011A224: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8011A228: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8011A22C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8011A230: bc1fl       L_8011A244
    if (!c1cs) {
        // 0x8011A234: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8011A244;
    }
    goto skip_0;
    // 0x8011A234: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8011A238: b           L_8011A244
    // 0x8011A23C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8011A244;
    // 0x8011A23C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8011A240: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8011A244:
    // 0x8011A244: ldc1        $f4, -0x6180($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6180);
    // 0x8011A248: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8011A24C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8011A250: nop

    // 0x8011A254: bc1tl       L_8011A2C8
    if (c1cs) {
        // 0x8011A258: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8011A2C8;
    }
    goto skip_1;
    // 0x8011A258: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x8011A25C: lw          $t7, 0xE8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A260: lwc1        $f6, 0x2BC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2BC);
    // 0x8011A264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8011A268: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8011A26C: swc1        $f6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f6.u32l;
    // 0x8011A270: lw          $t9, 0xE8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A274: lwc1        $f10, 0x2C8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X2C8);
    // 0x8011A278: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8011A27C: swc1        $f10, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f10.u32l;
    // 0x8011A280: lw          $t1, 0xE8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A284: lwc1        $f8, 0x2D4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X2D4);
    // 0x8011A288: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x8011A28C: swc1        $f8, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f8.u32l;
    // 0x8011A290: lw          $t3, 0xE8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A294: lwc1        $f16, 0x2E4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X2E4);
    // 0x8011A298: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x8011A29C: swc1        $f16, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f16.u32l;
    // 0x8011A2A0: lw          $t5, 0xE8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A2A4: lwc1        $f18, 0x2F0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2F0);
    // 0x8011A2A8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8011A2AC: swc1        $f18, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
    // 0x8011A2B0: lw          $t7, 0xE8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XE8);
    // 0x8011A2B4: lwc1        $f4, 0x2FC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2FC);
    // 0x8011A2B8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8011A2BC: b           L_8011A2C8
    // 0x8011A2C0: swc1        $f4, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f4.u32l;
        goto L_8011A2C8;
    // 0x8011A2C0: swc1        $f4, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f4.u32l;
    // 0x8011A2C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8011A2C8:
    // 0x8011A2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011A2CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011A2D0: jr          $ra
    // 0x8011A2D4: nop

    return;
    // 0x8011A2D4: nop

;}
RECOMP_FUNC void M7_FUN_8011a2d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A2D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8011A2DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8011A2E0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8011A2E4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8011A2E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8011A2EC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8011A2F0: lwc1        $f0, 0x30C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X30C);
    // 0x8011A2F4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8011A2F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8011A2FC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8011A300: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8011A304: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x8011A308: nop

    // 0x8011A30C: bc1fl       L_8011A340
    if (!c1cs) {
        // 0x8011A310: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8011A340;
    }
    goto skip_0;
    // 0x8011A310: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x8011A314: ldc1        $f6, -0x6178($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6178);
    // 0x8011A318: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x8011A31C: nop

    // 0x8011A320: bc1fl       L_8011A340
    if (!c1cs) {
        // 0x8011A324: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8011A340;
    }
    goto skip_1;
    // 0x8011A324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x8011A328: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x8011A32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8011A330: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8011A334: jr          $ra
    // 0x8011A338: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    return;
    // 0x8011A338: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x8011A33C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8011A340:
    // 0x8011A340: jr          $ra
    // 0x8011A344: nop

    return;
    // 0x8011A344: nop

;}
RECOMP_FUNC void M7_FUN_8011a348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A348: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011A34C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011A350: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8011A354: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8011A358: addiu       $t7, $t7, -0x4410
    ctx->r15 = ADD32(ctx->r15, -0X4410);
    // 0x8011A35C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8011A360: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8011A364: lh          $t8, 0x31A($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X31A);
    // 0x8011A368: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8011A36C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011A370: bne         $t8, $at, L_8011A380
    if (ctx->r24 != ctx->r1) {
        // 0x8011A374: addiu       $a0, $sp, 0x26
        ctx->r4 = ADD32(ctx->r29, 0X26);
            goto L_8011A380;
    }
    // 0x8011A374: addiu       $a0, $sp, 0x26
    ctx->r4 = ADD32(ctx->r29, 0X26);
    // 0x8011A378: b           L_8011A3C4
    // 0x8011A37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8011A3C4;
    // 0x8011A37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011A380:
    // 0x8011A380: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8011A384: jal         0x80119F9C
    // 0x8011A388: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_0;
    // 0x8011A388: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8011A38C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8011A390: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x8011A394: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8011A398: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x8011A39C: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8011A3A0: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x8011A3A4: lh          $a2, 0x31A($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X31A);
    // 0x8011A3A8: addiu       $t0, $v0, 0x4C
    ctx->r8 = ADD32(ctx->r2, 0X4C);
    // 0x8011A3AC: addiu       $t1, $v0, 0x50
    ctx->r9 = ADD32(ctx->r2, 0X50);
    // 0x8011A3B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8011A3B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8011A3B8: jal         0x8011A148
    // 0x8011A3BC: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_1;
    // 0x8011A3BC: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    after_1:
    // 0x8011A3C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011A3C4:
    // 0x8011A3C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8011A3C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011A3CC: jr          $ra
    // 0x8011A3D0: nop

    return;
    // 0x8011A3D0: nop

;}
RECOMP_FUNC void M7_FUN_8011a3d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A3D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8011A3D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8011A3DC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8011A3E0: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8011A3E4: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A3E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8011A3EC: sb          $zero, 0x44($sp)
    MEM_B(0X44, ctx->r29) = 0;
    // 0x8011A3F0: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8011A3F4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8011A3F8: addiu       $v0, $v0, 0x3EE0
    ctx->r2 = ADD32(ctx->r2, 0X3EE0);
    // 0x8011A3FC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8011A400: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8011A404: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x8011A408: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8011A40C: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
    // 0x8011A410: lw          $t7, 0xE8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A414: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8011A418: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x8011A41C: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8011A420: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8011A424: jal         0x8011A0F0
    // 0x8011A428: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_0;
    // 0x8011A428: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    after_0:
    // 0x8011A42C: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A430: lwc1        $f4, 0x2CC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x8011A434: lwc1        $f6, 0x2D8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x8011A438: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8011A43C: lwc1        $f8, 0x2B8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2B8);
    // 0x8011A440: lw          $a3, 0x2C0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C0);
    // 0x8011A444: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8011A448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8011A44C: addiu       $a0, $v1, 0x30
    ctx->r4 = ADD32(ctx->r3, 0X30);
    // 0x8011A450: addiu       $a1, $v1, 0x34
    ctx->r5 = ADD32(ctx->r3, 0X34);
    // 0x8011A454: addiu       $a2, $v1, 0x38
    ctx->r6 = ADD32(ctx->r3, 0X38);
    // 0x8011A458: jal         0x80119C20
    // 0x8011A45C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80119C20)(rdram, ctx);
        goto after_1;
    // 0x8011A45C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8011A460: lw          $t9, 0xE8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A464: sb          $v0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r2;
    // 0x8011A468: lwc1        $f10, 0x2F4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x8011A46C: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8011A470: lwc1        $f16, 0x300($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X300);
    // 0x8011A474: lwc1        $f18, 0x2E0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x8011A478: lw          $a3, 0x2E8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2E8);
    // 0x8011A47C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8011A480: addiu       $a0, $v1, 0x3C
    ctx->r4 = ADD32(ctx->r3, 0X3C);
    // 0x8011A484: addiu       $a1, $v1, 0x40
    ctx->r5 = ADD32(ctx->r3, 0X40);
    // 0x8011A488: addiu       $a2, $v1, 0x44
    ctx->r6 = ADD32(ctx->r3, 0X44);
    // 0x8011A48C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8011A490: jal         0x80119C20
    // 0x8011A494: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80119C20)(rdram, ctx);
        goto after_2;
    // 0x8011A494: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8011A498: lw          $t0, 0xE8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A49C: sb          $v0, 0x46($sp)
    MEM_B(0X46, ctx->r29) = ctx->r2;
    // 0x8011A4A0: lw          $a1, 0x310($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X310);
    // 0x8011A4A4: lw          $a0, 0x2C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2C);
    // 0x8011A4A8: lw          $a2, 0x308($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X308);
    // 0x8011A4AC: jal         0x80119D38
    // 0x8011A4B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    LOOKUP_FUNC(0x80119D38)(rdram, ctx);
        goto after_3;
    // 0x8011A4B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8011A4B4: sb          $v0, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r2;
    // 0x8011A4B8: addiu       $a0, $sp, 0x42
    ctx->r4 = ADD32(ctx->r29, 0X42);
    // 0x8011A4BC: jal         0x80119F9C
    // 0x8011A4C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_4;
    // 0x8011A4C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8011A4C4: lw          $t1, 0xE8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A4C8: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    // 0x8011A4CC: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x8011A4D0: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x8011A4D4: lh          $a2, 0x3E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3E);
    // 0x8011A4D8: addiu       $t2, $v1, 0x4C
    ctx->r10 = ADD32(ctx->r3, 0X4C);
    // 0x8011A4DC: addiu       $t3, $v1, 0x50
    ctx->r11 = ADD32(ctx->r3, 0X50);
    // 0x8011A4E0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8011A4E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8011A4E8: jal         0x8011A148
    // 0x8011A4EC: addiu       $a3, $v1, 0x48
    ctx->r7 = ADD32(ctx->r3, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_5;
    // 0x8011A4EC: addiu       $a3, $v1, 0x48
    ctx->r7 = ADD32(ctx->r3, 0X48);
    after_5:
    // 0x8011A4F0: lh          $v0, 0x318($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X318);
    // 0x8011A4F4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8011A4F8: beql        $v1, $v0, L_8011A530
    if (ctx->r3 == ctx->r2) {
        // 0x8011A4FC: lw          $t5, 0xE8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XE8);
            goto L_8011A530;
    }
    goto skip_0;
    // 0x8011A4FC: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
    skip_0:
    // 0x8011A500: lh          $a3, 0x31C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X31C);
    // 0x8011A504: beql        $v1, $a3, L_8011A530
    if (ctx->r3 == ctx->r7) {
        // 0x8011A508: lw          $t5, 0xE8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XE8);
            goto L_8011A530;
    }
    goto skip_1;
    // 0x8011A508: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
    skip_1:
    // 0x8011A50C: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A510: lw          $v1, 0x2C($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2C);
    // 0x8011A514: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8011A518: addiu       $a0, $v1, 0x48
    ctx->r4 = ADD32(ctx->r3, 0X48);
    // 0x8011A51C: addiu       $a1, $v1, 0x4C
    ctx->r5 = ADD32(ctx->r3, 0X4C);
    // 0x8011A520: jal         0x80119E24
    // 0x8011A524: addiu       $a2, $v1, 0x50
    ctx->r6 = ADD32(ctx->r3, 0X50);
    LOOKUP_FUNC(0x80119E24)(rdram, ctx);
        goto after_6;
    // 0x8011A524: addiu       $a2, $v1, 0x50
    ctx->r6 = ADD32(ctx->r3, 0X50);
    after_6:
    // 0x8011A528: sb          $v0, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r2;
    // 0x8011A52C: lw          $t5, 0xE8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE8);
L_8011A530:
    // 0x8011A530: lwc1        $f6, 0x324($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X324);
    // 0x8011A534: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8011A538: lw          $v1, 0x2C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X2C);
    // 0x8011A53C: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8011A540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8011A544: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8011A548: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
    // 0x8011A54C: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A550: lwc1        $f16, 0x324($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X324);
    // 0x8011A554: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8011A558: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8011A55C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8011A560: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8011A564: lb          $t8, 0x46($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X46);
    // 0x8011A568: lb          $t7, 0x47($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X47);
    // 0x8011A56C: lwc1        $f4, 0x324($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X324);
    // 0x8011A570: lb          $t0, 0x45($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X45);
    // 0x8011A574: lb          $t2, 0x44($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X44);
    // 0x8011A578: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8011A57C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8011A580: swc1        $f4, 0x3EE0($at)
    MEM_W(0X3EE0, ctx->r1) = ctx->f4.u32l;
    // 0x8011A584: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8011A588: swc1        $f6, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->f6.u32l;
    // 0x8011A58C: or          $v0, $t1, $t2
    ctx->r2 = ctx->r9 | ctx->r10;
    // 0x8011A590: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8011A594: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8011A598: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8011A59C: jr          $ra
    // 0x8011A5A0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    return;
    // 0x8011A5A0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8011a5a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8011a5a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A5A4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8011A5A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8011A5AC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8011A5B0: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8011A5B4: lw          $v1, 0xE8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A5B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8011A5BC: sb          $zero, 0x64($sp)
    MEM_B(0X64, ctx->r29) = 0;
    // 0x8011A5C0: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A5C4: lwc1        $f10, 0x2CC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x8011A5C8: lwc1        $f16, 0x2D8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x8011A5CC: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8011A5D0: lwc1        $f18, 0x2B8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2B8);
    // 0x8011A5D4: lw          $a3, 0x2C0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C0);
    // 0x8011A5D8: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8011A5DC: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A5E0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8011A5E4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8011A5E8: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x8011A5EC: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8011A5F0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8011A5F4: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A5F8: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8011A5FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8011A600: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8011A604: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8011A608: jal         0x80119C20
    // 0x8011A60C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80119C20)(rdram, ctx);
        goto after_0;
    // 0x8011A60C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8011A610: lw          $v1, 0xE8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A614: sb          $v0, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r2;
    // 0x8011A618: lwc1        $f10, 0x2F4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x8011A61C: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A620: lwc1        $f16, 0x300($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X300);
    // 0x8011A624: lwc1        $f18, 0x2E0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x8011A628: lwc1        $f4, 0x3C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x8011A62C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8011A630: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8011A634: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8011A638: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A63C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8011A640: lw          $a3, 0x2E8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2E8);
    // 0x8011A644: lwc1        $f6, 0x40($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X40);
    // 0x8011A648: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8011A64C: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A650: lwc1        $f8, 0x44($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X44);
    // 0x8011A654: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8011A658: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8011A65C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8011A660: jal         0x80119C20
    // 0x8011A664: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80119C20)(rdram, ctx);
        goto after_1;
    // 0x8011A664: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8011A668: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A66C: sb          $v0, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r2;
    // 0x8011A670: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8011A674: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8011A678: lw          $a1, 0x310($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X310);
    // 0x8011A67C: lw          $a2, 0x308($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X308);
    // 0x8011A680: lwc1        $f4, 0x1C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8011A684: jal         0x80119D38
    // 0x8011A688: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80119D38)(rdram, ctx);
        goto after_2;
    // 0x8011A688: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8011A68C: lh          $t0, 0x318($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X318);
    // 0x8011A690: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8011A694: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x8011A698: beq         $v1, $t0, L_8011A6F4
    if (ctx->r3 == ctx->r8) {
        // 0x8011A69C: sra         $t1, $t1, 24
        ctx->r9 = S32(SIGNED(ctx->r9) >> 24);
            goto L_8011A6F4;
    }
    // 0x8011A69C: sra         $t1, $t1, 24
    ctx->r9 = S32(SIGNED(ctx->r9) >> 24);
    // 0x8011A6A0: lh          $a3, 0x31C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X31C);
    // 0x8011A6A4: beql        $v1, $a3, L_8011A6F8
    if (ctx->r3 == ctx->r7) {
        // 0x8011A6A8: lb          $t9, 0x67($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X67);
            goto L_8011A6F8;
    }
    goto skip_0;
    // 0x8011A6A8: lb          $t9, 0x67($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X67);
    skip_0:
    // 0x8011A6AC: lw          $v1, 0xE8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A6B0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8011A6B4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8011A6B8: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A6BC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8011A6C0: lwc1        $f6, 0x48($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8011A6C4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8011A6C8: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A6CC: lwc1        $f8, 0x4C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8011A6D0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8011A6D4: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x8011A6D8: lwc1        $f10, 0x50($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X50);
    // 0x8011A6DC: sb          $t1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r9;
    // 0x8011A6E0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8011A6E4: jal         0x80119E24
    // 0x8011A6E8: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80119E24)(rdram, ctx);
        goto after_3;
    // 0x8011A6E8: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8011A6EC: lb          $t1, 0x65($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X65);
    // 0x8011A6F0: sb          $v0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r2;
L_8011A6F4:
    // 0x8011A6F4: lb          $t9, 0x67($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X67);
L_8011A6F8:
    // 0x8011A6F8: lb          $t2, 0x66($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X66);
    // 0x8011A6FC: lb          $t5, 0x64($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X64);
    // 0x8011A700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8011A704: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8011A708: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x8011A70C: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x8011A710: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8011A714: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8011A718: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8011A71C: jr          $ra
    // 0x8011A720: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    return;
    // 0x8011A720: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8011a724(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8011a724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A724: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8011A728: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8011A72C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8011A730: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8011A734: jal         0x8011A0F0
    // 0x8011A738: addiu       $a0, $sp, 0x32
    ctx->r4 = ADD32(ctx->r29, 0X32);
    LOOKUP_FUNC(0x8011A0F0)(rdram, ctx);
        goto after_0;
    // 0x8011A738: addiu       $a0, $sp, 0x32
    ctx->r4 = ADD32(ctx->r29, 0X32);
    after_0:
    // 0x8011A73C: jal         0x8011A1B8
    // 0x8011A740: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x8011A1B8)(rdram, ctx);
        goto after_1;
    // 0x8011A740: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    after_1:
    // 0x8011A744: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8011A748: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8011A74C: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A750: lwc1        $f6, 0x324($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X324);
    // 0x8011A754: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8011A758: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8011A75C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8011A760: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8011A764: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x8011A768: lw          $t7, 0xE8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A76C: lwc1        $f16, 0x324($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X324);
    // 0x8011A770: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8011A774: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8011A778: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8011A77C: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8011A780: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8011A784: jal         0x8011A2D8
    // 0x8011A788: swc1        $f4, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011A2D8)(rdram, ctx);
        goto after_2;
    // 0x8011A788: swc1        $f4, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8011A78C: addiu       $a0, $sp, 0x36
    ctx->r4 = ADD32(ctx->r29, 0X36);
    // 0x8011A790: jal         0x80119F9C
    // 0x8011A794: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80119F9C)(rdram, ctx);
        goto after_3;
    // 0x8011A794: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x8011A798: lw          $t8, 0xE8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A79C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x8011A7A0: lh          $a1, 0x34($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X34);
    // 0x8011A7A4: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8011A7A8: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x8011A7AC: addiu       $t9, $v0, 0x4C
    ctx->r25 = ADD32(ctx->r2, 0X4C);
    // 0x8011A7B0: addiu       $t0, $v0, 0x50
    ctx->r8 = ADD32(ctx->r2, 0X50);
    // 0x8011A7B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8011A7B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8011A7BC: jal         0x8011A148
    // 0x8011A7C0: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    LOOKUP_FUNC(0x8011A148)(rdram, ctx);
        goto after_4;
    // 0x8011A7C0: addiu       $a3, $v0, 0x48
    ctx->r7 = ADD32(ctx->r2, 0X48);
    after_4:
    // 0x8011A7C4: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8011A7C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8011A7CC: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x8011A7D0: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x8011A7D4: lh          $t3, 0x31A($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X31A);
    // 0x8011A7D8: beql        $t3, $at, L_8011A7EC
    if (ctx->r11 == ctx->r1) {
        // 0x8011A7DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8011A7EC;
    }
    goto skip_0;
    // 0x8011A7DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8011A7E0: jal         0x8011A348
    // 0x8011A7E4: nop

    LOOKUP_FUNC(0x8011A348)(rdram, ctx);
        goto after_5;
    // 0x8011A7E4: nop

    after_5:
    // 0x8011A7E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8011A7EC:
    // 0x8011A7EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8011A7F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8011A7F4: jr          $ra
    // 0x8011A7F8: nop

    return;
    // 0x8011A7F8: nop

;}
RECOMP_FUNC void M7_FUN_8011a7fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A7FC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8011A800: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8011A804: lbu         $t6, 0x254($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X254);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8011a808(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8011a808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011A80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011A810: sb          $zero, 0x2AD($v1)
    MEM_B(0X2AD, ctx->r3) = 0;
    // 0x8011A814: sb          $zero, 0x2B5($v1)
    MEM_B(0X2B5, ctx->r3) = 0;
    // 0x8011A818: bne         $t6, $zero, L_8011A868
    if (ctx->r14 != 0) {
        // 0x8011A81C: sw          $zero, 0x2B0($v1)
        MEM_W(0X2B0, ctx->r3) = 0;
            goto L_8011A868;
    }
    // 0x8011A81C: sw          $zero, 0x2B0($v1)
    MEM_W(0X2B0, ctx->r3) = 0;
    // 0x8011A820: lbu         $t7, 0x255($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X255);
    // 0x8011A824: bnel        $t7, $zero, L_8011A86C
    if (ctx->r15 != 0) {
        // 0x8011A828: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8011A86C;
    }
    goto skip_0;
    // 0x8011A828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8011A82C: lbu         $t8, 0x256($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X256);
    // 0x8011A830: bnel        $t8, $zero, L_8011A86C
    if (ctx->r24 != 0) {
        // 0x8011A834: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8011A86C;
    }
    goto skip_1;
    // 0x8011A834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8011A838: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x8011A83C: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8011A840: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8011A844: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8011A848: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8011A84C: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8011A850: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8011A854: jal         0x8001EF38
    // 0x8011A858: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8011A858: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8011A85C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8011A860: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8011A864: sh          $v0, 0x232($v1)
    MEM_H(0X232, ctx->r3) = ctx->r2;
L_8011A868:
    // 0x8011A868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8011A86C:
    // 0x8011A86C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011A870: jr          $ra
    // 0x8011A874: nop

    return;
    // 0x8011A874: nop

;}
RECOMP_FUNC void M7_FUN_8011a878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011A878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011A87C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011A880: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8011A884: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8011A888: lw          $t6, 0xE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE8);
    // 0x8011A88C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011A890: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8011A894: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8011A898: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8011A89C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8011A8A0: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8011A8A4: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8011A8A8: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8011A8AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8011A8B0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011A8B4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8011A8B8: nop

    // 0x8011A8BC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011A8C0: jal         0x8002FC20
    // 0x8011A8C4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8011A8C4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x8011A8C8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8011A8CC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8011A8D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8011A8D4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8011A8D8: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8011A8DC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8011A8E0: nop

    // 0x8011A8E4: bc1fl       L_8011A8F4
    if (!c1cs) {
        // 0x8011A8E8: lbu         $t8, 0x234($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X234);
            goto L_8011A8F4;
    }
    goto skip_0;
    // 0x8011A8E8: lbu         $t8, 0x234($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X234);
    skip_0:
    // 0x8011A8EC: sb          $t7, 0x234($s0)
    MEM_B(0X234, ctx->r16) = ctx->r15;
    // 0x8011A8F0: lbu         $t8, 0x234($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X234);
L_8011A8F4:
    // 0x8011A8F4: beql        $t8, $zero, L_8011A9D4
    if (ctx->r24 == 0) {
        // 0x8011A8F8: lw          $t4, 0xE8($s0)
        ctx->r12 = MEM_W(ctx->r16, 0XE8);
            goto L_8011A9D4;
    }
    goto skip_1;
    // 0x8011A8F8: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
    skip_1:
    // 0x8011A8FC: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x8011A900: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8011A904: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8011A908: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8011A90C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8011A910: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8011A914: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011A918: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8011A91C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8011A920: nop

    // 0x8011A924: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011A928: jal         0x8002FC20
    // 0x8011A92C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8011A92C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8011A930: lh          $v0, 0xA2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA2);
    // 0x8011A934: lh          $v1, 0xA4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XA4);
    // 0x8011A938: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8011A93C: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8011A940: mflo        $t0
    ctx->r8 = lo;
    // 0x8011A944: nop

    // 0x8011A948: nop

    // 0x8011A94C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8011A950: mflo        $t1
    ctx->r9 = lo;
    // 0x8011A954: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8011A958: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8011A95C: jal         0x8002FC20
    // 0x8011A960: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x8011A960: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_2:
    // 0x8011A964: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8011A968: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8011A96C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8011A970: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8011A974: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8011A978: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8011A97C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8011A980: bc1tl       L_8011A9A4
    if (c1cs) {
        // 0x8011A984: lw          $t3, 0xE8($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XE8);
            goto L_8011A9A4;
    }
    goto skip_2;
    // 0x8011A984: lw          $t3, 0xE8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE8);
    skip_2:
    // 0x8011A988: ldc1        $f6, -0x6170($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6170);
    // 0x8011A98C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8011A990: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8011A994: nop

    // 0x8011A998: bc1fl       L_8011A9FC
    if (!c1cs) {
        // 0x8011A99C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8011A9FC;
    }
    goto skip_3;
    // 0x8011A99C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8011A9A0: lw          $t3, 0xE8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE8);
L_8011A9A4:
    // 0x8011A9A4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8011A9A8: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8011A9AC: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8011A9B0: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8011A9B4: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8011A9B8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8011A9BC: jal         0x8001EF38
    // 0x8011A9C0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x8011A9C0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    after_3:
    // 0x8011A9C4: sh          $v0, 0x232($s0)
    MEM_H(0X232, ctx->r16) = ctx->r2;
    // 0x8011A9C8: b           L_8011A9F8
    // 0x8011A9CC: sb          $zero, 0x234($s0)
    MEM_B(0X234, ctx->r16) = 0;
        goto L_8011A9F8;
    // 0x8011A9CC: sb          $zero, 0x234($s0)
    MEM_B(0X234, ctx->r16) = 0;
    // 0x8011A9D0: lw          $t4, 0xE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE8);
L_8011A9D4:
    // 0x8011A9D4: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x8011A9D8: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8011A9DC: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8011A9E0: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8011A9E4: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8011A9E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8011A9EC: jal         0x8001EF38
    // 0x8011A9F0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x8011A9F0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_4:
    // 0x8011A9F4: sh          $v0, 0x232($s0)
    MEM_H(0X232, ctx->r16) = ctx->r2;
L_8011A9F8:
    // 0x8011A9F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8011A9FC:
    // 0x8011A9FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8011AA00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8011AA04: jr          $ra
    // 0x8011AA08: nop

    return;
    // 0x8011AA08: nop

;}
RECOMP_FUNC void M7_FUN_8011aa0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011AA0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011AA10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011AA14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8011AA18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8011AA1C: jal         0x8011A3D4
    // 0x8011AA20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8011A3D4)(rdram, ctx);
        goto after_0;
    // 0x8011AA20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8011AA24: beq         $v0, $zero, L_8011AA3C
    if (ctx->r2 == 0) {
        // 0x8011AA28: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8011AA3C;
    }
    // 0x8011AA28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8011AA2C: jal         0x800058DC
    // 0x8011AA30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8011AA30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8011AA34: b           L_8011AA48
    // 0x8011AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8011AA48;
    // 0x8011AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8011AA3C:
    // 0x8011AA3C: jal         0x8011AA88
    // 0x8011AA40: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8011AA88)(rdram, ctx);
        goto after_2;
    // 0x8011AA40: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8011AA44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8011AA48:
    // 0x8011AA48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011AA4C: jr          $ra
    // 0x8011AA50: nop

    return;
    // 0x8011AA50: nop

;}
