#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M99_FUN_8038c600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C600: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038C604: lw          $v0, -0x2710($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2710);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c608(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C610: beq         $v0, $zero, L_8038C768
    if (ctx->r2 == 0) {
        // 0x8038C614: slti        $at, $v0, 0x9
        ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
            goto L_8038C768;
    }
    // 0x8038C614: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8038C618: beql        $at, $zero, L_8038C76C
    if (ctx->r1 == 0) {
        // 0x8038C61C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8038C76C;
    }
    goto skip_0;
    // 0x8038C61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8038C620: jal         0x8038C778
    // 0x8038C624: nop

    LOOKUP_FUNC(0x8038C778)(rdram, ctx);
        goto after_0;
    // 0x8038C624: nop

    after_0:
    // 0x8038C628: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038C62C: lw          $t6, -0x24B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X24B8);
    // 0x8038C630: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8038C634: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8038C638: beq         $t6, $zero, L_8038C690
    if (ctx->r14 == 0) {
        // 0x8038C63C: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_8038C690;
    }
    // 0x8038C63C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8038C640: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8038C644: lw          $t7, 0xE8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C648: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8038C64C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x8038C650: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8038C654: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8038C658: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8038C65C: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8038C660: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8038C664: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8038C668: lwc1        $f18, 0x38($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8038C66C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8038C670: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8038C674: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8038C678: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8038C67C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8038C680: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8038C684: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8038C688: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8038C68C: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_8038C690:
    // 0x8038C690: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8038C694: beq         $v0, $zero, L_8038C768
    if (ctx->r2 == 0) {
        // 0x8038C698: addiu       $a1, $a1, -0x4410
        ctx->r5 = ADD32(ctx->r5, -0X4410);
            goto L_8038C768;
    }
    // 0x8038C698: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x8038C69C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8038C6A0: lw          $t8, 0xE8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C6A4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8038C6A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8038C6AC: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8038C6B0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038C6B4: addiu       $t6, $t6, -0x1F90
    ctx->r14 = ADD32(ctx->r14, -0X1F90);
    // 0x8038C6B8: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8038C6BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8038C6C0: swc1        $f10, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f10.u32l;
    // 0x8038C6C4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8038C6C8: lw          $t9, 0xE8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C6CC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8038C6D0: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x8038C6D4: lwc1        $f16, 0x34($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8038C6D8: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8038C6DC: swc1        $f4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f4.u32l;
    // 0x8038C6E0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8038C6E4: lw          $t0, 0xE8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C6E8: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8038C6EC: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x8038C6F0: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8038C6F4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8038C6F8: swc1        $f16, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f16.u32l;
    // 0x8038C6FC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8038C700: lw          $t1, 0xE8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C704: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8038C708: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x8038C70C: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8038C710: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8038C714: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8038C718: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8038C71C: lw          $t2, 0xE8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C720: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8038C724: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8038C728: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8038C72C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8038C730: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x8038C734: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8038C738: lw          $t3, 0xE8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE8);
    // 0x8038C73C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8038C740: lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X2C);
    // 0x8038C744: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8038C748: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8038C74C: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
    // 0x8038C750: lw          $t4, -0x2710($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2710);
    // 0x8038C754: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8038C758: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8038C75C: lw          $t7, -0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, -0XC);
    // 0x8038C760: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8038C764: sw          $t8, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->r24;
L_8038C768:
    // 0x8038C768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8038C76C:
    // 0x8038C76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C770: jr          $ra
    // 0x8038C774: nop

    return;
    // 0x8038C774: nop

;}
RECOMP_FUNC void M99_FUN_8038c778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C778: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8038C77C: addiu       $a3, $a3, -0x2710
    ctx->r7 = ADD32(ctx->r7, -0X2710);
    // 0x8038C780: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c784(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8038C788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C78C: blez        $v1, L_8038C810
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8038C790: slti        $at, $v1, 0x9
        ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
            goto L_8038C810;
    }
    // 0x8038C790: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x8038C794: beq         $at, $zero, L_8038C810
    if (ctx->r1 == 0) {
        // 0x8038C798: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_8038C810;
    }
    // 0x8038C798: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8038C79C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038C7A0: addiu       $t7, $t7, -0x1F90
    ctx->r15 = ADD32(ctx->r15, -0X1F90);
    // 0x8038C7A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8038C7A8: lw          $a0, -0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X10);
    // 0x8038C7AC: lw          $a1, -0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, -0XC);
    // 0x8038C7B0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8038C7B4: jal         0x8038C824
    // 0x8038C7B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8038C824)(rdram, ctx);
        goto after_0;
    // 0x8038C7B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8038C7BC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8038C7C0: addiu       $a3, $a3, -0x2710
    ctx->r7 = ADD32(ctx->r7, -0X2710);
    // 0x8038C7C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8038C7C8: beq         $v0, $zero, L_8038C810
    if (ctx->r2 == 0) {
        // 0x8038C7CC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8038C810;
    }
    // 0x8038C7CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8038C7D0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8038C7D4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038C7D8: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8038C7DC: lw          $v1, -0x24CC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X24CC);
    // 0x8038C7E0: sll         $a2, $a1, 4
    ctx->r6 = S32(ctx->r5 << 4);
    // 0x8038C7E4: addu        $t9, $v1, $a2
    ctx->r25 = ADD32(ctx->r3, ctx->r6);
    // 0x8038C7E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8038C7EC: bnel        $t0, $zero, L_8038C800
    if (ctx->r8 != 0) {
        // 0x8038C7F0: lw          $t1, 0x0($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X0);
            goto L_8038C800;
    }
    goto skip_0;
    // 0x8038C7F0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8038C7F4: b           L_8038C814
    // 0x8038C7F8: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
        goto L_8038C814;
    // 0x8038C7F8: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8038C7FC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_8038C800:
    // 0x8038C800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038C804: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8038C808: b           L_8038C814
    // 0x8038C80C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
        goto L_8038C814;
    // 0x8038C80C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_8038C810:
    // 0x8038C810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038C814:
    // 0x8038C814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038C81C: jr          $ra
    // 0x8038C820: nop

    return;
    // 0x8038C820: nop

;}
RECOMP_FUNC void M99_FUN_8038c824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C824: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038C828: addiu       $a2, $a2, -0x24CC
    ctx->r6 = ADD32(ctx->r6, -0X24CC);
    // 0x8038C82C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8038C830: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038C834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038C838: beq         $t6, $zero, L_8038C854
    if (ctx->r14 == 0) {
        // 0x8038C83C: addiu       $v1, $v1, -0x24CC
        ctx->r3 = ADD32(ctx->r3, -0X24CC);
            goto L_8038C854;
    }
    // 0x8038C83C: addiu       $v1, $v1, -0x24CC
    ctx->r3 = ADD32(ctx->r3, -0X24CC);
    // 0x8038C840: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_8038C844:
    // 0x8038C844: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8038C848: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8038C84C: bnel        $t7, $zero, L_8038C844
    if (ctx->r15 != 0) {
        // 0x8038C850: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_8038C844;
    }
    goto skip_0;
    // 0x8038C850: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_8038C854:
    // 0x8038C854: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8038C858: bne         $at, $zero, L_8038C868
    if (ctx->r1 != 0) {
            // 0x8038C85C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x8038C868)(rdram, ctx);
    return;
    }
    // 0x8038C85C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8038C860: jr          $ra
    // 0x8038C864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8038C864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c868(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C868: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8038C86C: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8038C870: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8038C874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038C878: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8038C87C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8038C880: beql        $a3, $t0, L_8038C8A0
    if (ctx->r7 == ctx->r8) {
        // 0x8038C884: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8038C8A0;
    }
    goto skip_0;
    // 0x8038C884: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8038C888: lw          $t1, 0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X10);
L_8038C88C:
    // 0x8038C88C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8038C890: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8038C894: bnel        $a3, $t1, L_8038C88C
    if (ctx->r7 != ctx->r9) {
        // 0x8038C898: lw          $t1, 0x10($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X10);
            goto L_8038C88C;
    }
    goto skip_1;
    // 0x8038C898: lw          $t1, 0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x8038C89C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8038C8A0:
    // 0x8038C8A0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8038C8A4: bne         $at, $zero, L_8038C8B4
    if (ctx->r1 != 0) {
            // 0x8038C8A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8038C8B4)(rdram, ctx);
    return;
    }
    // 0x8038C8A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038C8AC: jr          $ra
    // 0x8038C8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8038C8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c8b4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c8b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C8B4: jr          $ra
    // 0x8038C8B8: nop

    return;
    // 0x8038C8B8: nop

;}
RECOMP_FUNC void M99_FUN_8038c8bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C8BC: jr          $ra
    // 0x8038C8C0: nop

    return;
    // 0x8038C8C0: nop

;}
RECOMP_FUNC void M99_FUN_8038c8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C8C4: jr          $ra
    // 0x8038C8C8: nop

    return;
    // 0x8038C8C8: nop

;}
RECOMP_FUNC void M99_FUN_8038c8cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C8CC: nop

;}
RECOMP_FUNC void M99_FUN_8038c8d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C8D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C8D8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C8DC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038C8E0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038C8E4: sw          $zero, -0x2494($at)
    MEM_W(-0X2494, ctx->r1) = 0;
    // 0x8038C8E8: lw          $a1, -0x248C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X248C);
    // 0x8038C8EC: jal         0x8038C9FC
    // 0x8038C8F0: lw          $a0, -0x2490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2490);
    LOOKUP_FUNC(0x8038C9FC)(rdram, ctx);
        goto after_0;
    // 0x8038C8F0: lw          $a0, -0x2490($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2490);
    after_0:
    // 0x8038C8F4: jal         0x801BF6C4
    // 0x8038C8F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_1;
    // 0x8038C8F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8038C8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C900: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038C904: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C908: sw          $t6, -0x2494($at)
    MEM_W(-0X2494, ctx->r1) = ctx->r14;
    // 0x8038C90C: jr          $ra
    // 0x8038C910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038C910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c914(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038C918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038C91C: jal         0x801BF968
    // 0x8038C920: nop

    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038C920: nop

    after_0:
    // 0x8038C924: beq         $v0, $zero, L_8038C958
    if (ctx->r2 == 0) {
        // 0x8038C928: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038C958;
    }
    // 0x8038C928: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C92C: sw          $zero, -0x2490($at)
    MEM_W(-0X2490, ctx->r1) = 0;
    // 0x8038C930: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038C934: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038C938: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038C93C: sw          $zero, -0x248C($at)
    MEM_W(-0X248C, ctx->r1) = 0;
    // 0x8038C940: addiu       $a2, $a2, -0x1F00
    ctx->r6 = ADD32(ctx->r6, -0X1F00);
    // 0x8038C944: addiu       $a0, $a0, -0x24A0
    ctx->r4 = ADD32(ctx->r4, -0X24A0);
    // 0x8038C948: jal         0x801BF850
    // 0x8038C94C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_1;
    // 0x8038C94C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x8038C950: jal         0x8038CA0C
    // 0x8038C954: nop

    LOOKUP_FUNC(0x8038CA0C)(rdram, ctx);
        goto after_2;
    // 0x8038C954: nop

    after_2:
L_8038C958:
    // 0x8038C958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038C95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038C960: jr          $ra
    // 0x8038C964: nop

    return;
    // 0x8038C964: nop

;}
RECOMP_FUNC void M99_FUN_8038c968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C968: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038C96C: jr          $ra
    // 0x8038C970: lw          $v0, -0x2494($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2494);
    return;
    // 0x8038C970: lw          $v0, -0x2494($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2494);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c974(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C974: jr          $ra
    // 0x8038C978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038C978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c97c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c97c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C97C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8038C980: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038C984: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038C988: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8038C98C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8038C990: jal         0x801C276C
    // 0x8038C994: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801C276C)(rdram, ctx);
        goto after_0;
    // 0x8038C994: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8038C998: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x8038C99C: lhu         $t7, 0x3E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3E);
    // 0x8038C9A0: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x8038C9A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8038C9A8: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8038C9AC: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8038C9B0: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x8038C9B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8038C9B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8038C9BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8038C9C0: jal         0x8001E978
    // 0x8038C9C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_1;
    // 0x8038C9C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8038C9C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038C9CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8038C9D0: jr          $ra
    // 0x8038C9D4: nop

    return;
    // 0x8038C9D4: nop

;}
RECOMP_FUNC void M99_FUN_8038c9d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C9D8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8038C9DC: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x8038C9E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8038C9E4: beq         $t6, $zero, L_8038C9F4
    if (ctx->r14 == 0) {
            // 0x8038C9E8: nop

    LOOKUP_FUNC(0x8038C9F4)(rdram, ctx);
    return;
    }
    // 0x8038C9E8: nop

    // 0x8038C9EC: jr          $ra
    // 0x8038C9F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038C9F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c9f4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c9f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C9F4: jr          $ra
    // 0x8038C9F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8038C9F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038c9fc(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038c9fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038C9FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038CA00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8038CA04: jr          $ra
    // 0x8038CA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038CA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca0c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA0C: jr          $ra
    // 0x8038CA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038CA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca14(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038CA18: jr          $ra
    // 0x8038CA1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038CA1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca20(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038CA24: jr          $ra
    // 0x8038CA28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038CA28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca2c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038CA30: jr          $ra
    // 0x8038CA34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8038CA34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca38(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA38: nop

    // 0x8038CA3C: nop

;}
RECOMP_FUNC void M99_FUN_8038ca40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CA48: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CA4C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038CA50: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038CA54: sw          $zero, -0x1EF0($at)
    MEM_W(-0X1EF0, ctx->r1) = 0;
    // 0x8038CA58: lw          $a1, -0x246C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X246C);
    // 0x8038CA5C: jal         0x8038D1A0
    // 0x8038CA60: lw          $a0, -0x2470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2470);
    LOOKUP_FUNC(0x8038D1A0)(rdram, ctx);
        goto after_0;
    // 0x8038CA60: lw          $a0, -0x2470($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2470);
    after_0:
    // 0x8038CA64: jal         0x801BF6C4
    // 0x8038CA68: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_1;
    // 0x8038CA68: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x8038CA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CA70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038CA74: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CA78: sw          $t6, -0x1EF0($at)
    MEM_W(-0X1EF0, ctx->r1) = ctx->r14;
    // 0x8038CA7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CA80: sw          $zero, -0x2474($at)
    MEM_W(-0X2474, ctx->r1) = 0;
    // 0x8038CA84: jr          $ra
    // 0x8038CA88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038CA88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ca8c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ca8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CA8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CA94: jal         0x801BF968
    // 0x8038CA98: nop

    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038CA98: nop

    after_0:
    // 0x8038CA9C: beq         $v0, $zero, L_8038CAD0
    if (ctx->r2 == 0) {
        // 0x8038CAA0: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038CAD0;
    }
    // 0x8038CAA0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CAA4: sw          $zero, -0x2470($at)
    MEM_W(-0X2470, ctx->r1) = 0;
    // 0x8038CAA8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CAAC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038CAB0: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038CAB4: sw          $zero, -0x246C($at)
    MEM_W(-0X246C, ctx->r1) = 0;
    // 0x8038CAB8: addiu       $a2, $a2, -0x1EE8
    ctx->r6 = ADD32(ctx->r6, -0X1EE8);
    // 0x8038CABC: addiu       $a0, $a0, -0x2480
    ctx->r4 = ADD32(ctx->r4, -0X2480);
    // 0x8038CAC0: jal         0x801BF850
    // 0x8038CAC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_1;
    // 0x8038CAC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x8038CAC8: jal         0x8038D1B0
    // 0x8038CACC: nop

    LOOKUP_FUNC(0x8038D1B0)(rdram, ctx);
        goto after_2;
    // 0x8038CACC: nop

    after_2:
L_8038CAD0:
    // 0x8038CAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CAD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CAD8: jr          $ra
    // 0x8038CADC: nop

    return;
    // 0x8038CADC: nop

;}
RECOMP_FUNC void M99_FUN_8038cae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CAE0: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CAE4: jr          $ra
    // 0x8038CAE8: lw          $v0, -0x1EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1EF0);
    return;
    // 0x8038CAE8: lw          $v0, -0x1EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1EF0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038caec(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038caec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CAEC: jr          $ra
    // 0x8038CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038caf4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038caf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CAF4: blez        $a2, L_8038CB58
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8038CAF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8038CB58;
    }
    // 0x8038CAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038CAFC: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8038CB00: beq         $a3, $zero, L_8038CB28
    if (ctx->r7 == 0) {
        // 0x8038CB04: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8038CB28;
    }
    // 0x8038CB04: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8038CB08:
    // 0x8038CB08: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8038CB0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8038CB10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8038CB14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8038CB18: bne         $v1, $v0, L_8038CB08
    if (ctx->r3 != ctx->r2) {
        // 0x8038CB1C: sb          $t6, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r14;
            goto L_8038CB08;
    }
    // 0x8038CB1C: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
    // 0x8038CB20: beq         $v0, $a2, L_8038CB58
    if (ctx->r2 == ctx->r6) {
        // 0x8038CB24: nop
    
            goto L_8038CB58;
    }
    // 0x8038CB24: nop

L_8038CB28:
    // 0x8038CB28: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8038CB2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8038CB30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8038CB34: sb          $t7, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r15;
    // 0x8038CB38: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8038CB3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8038CB40: sb          $t8, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r24;
    // 0x8038CB44: lbu         $t9, -0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, -0X2);
    // 0x8038CB48: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x8038CB4C: lbu         $t0, -0x1($a1)
    ctx->r8 = MEM_BU(ctx->r5, -0X1);
    // 0x8038CB50: bne         $v0, $a2, L_8038CB28
    if (ctx->r2 != ctx->r6) {
        // 0x8038CB54: sb          $t0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r8;
            goto L_8038CB28;
    }
    // 0x8038CB54: sb          $t0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r8;
L_8038CB58:
    // 0x8038CB58: jr          $ra
    // 0x8038CB5C: nop

    return;
    // 0x8038CB5C: nop

;}
RECOMP_FUNC void M99_FUN_8038cb60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CB60: lui         $t6, 0x65
    ctx->r14 = S32(0X65 << 16);
    // 0x8038CB64: ori         $t6, $t6, 0xC816
    ctx->r14 = ctx->r14 | 0XC816;
    // 0x8038CB68: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CB6C: sw          $t6, -0x1ECC($at)
    MEM_W(-0X1ECC, ctx->r1) = ctx->r14;
    // 0x8038CB70: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038CB74: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CB78: addiu       $v1, $v1, -0x1EC4
    ctx->r3 = ADD32(ctx->r3, -0X1EC4);
    // 0x8038CB7C: sw          $zero, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = 0;
    // 0x8038CB80: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8038CB84: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8038CB88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8038CB8C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CB90: addiu       $v0, $v0, -0x1ED8
    ctx->r2 = ADD32(ctx->r2, -0X1ED8);
    // 0x8038CB94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8038CB98: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038CB9C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038CBA0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cba4(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cba4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CBA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CBA8: addiu       $t7, $t7, -0x33D8
    ctx->r15 = ADD32(ctx->r15, -0X33D8);
    // 0x8038CBAC: addiu       $t8, $t8, -0x333C
    ctx->r24 = ADD32(ctx->r24, -0X333C);
    // 0x8038CBB0: addiu       $t9, $t9, -0x32F4
    ctx->r25 = ADD32(ctx->r25, -0X32F4);
    // 0x8038CBB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CBB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038CBBC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8038CBC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8038CBC4: bc1f        L_8038CBD8
    if (!c1cs) {
        // 0x8038CBC8: sw          $t9, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r25;
            goto L_8038CBD8;
    }
    // 0x8038CBC8: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x8038CBCC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8038CBD0: jal         0x801C0D04
    // 0x8038CBD4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x8038CBD4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
L_8038CBD8:
    // 0x8038CBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CBDC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8038CBE0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CBE8: jr          $ra
    // 0x8038CBEC: sw          $t0, -0x1EC0($at)
    MEM_W(-0X1EC0, ctx->r1) = ctx->r8;
    return;
    // 0x8038CBEC: sw          $t0, -0x1EC0($at)
    MEM_W(-0X1EC0, ctx->r1) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cbf0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cbf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CBF0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CBF4: lw          $t6, -0x1EC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1EC8);
    // 0x8038CBF8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cbfc(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cbfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CBFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CC00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8038CC04: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8038CC08: lw          $t9, -0x1ED8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1ED8);
    // 0x8038CC0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CC10: jalr        $t9
    // 0x8038CC14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038CC14: nop

    after_0:
    // 0x8038CC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CC20: jr          $ra
    // 0x8038CC24: nop

    return;
    // 0x8038CC24: nop

;}
RECOMP_FUNC void M99_FUN_8038cc28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CC28: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CC2C: lwc1        $f0, -0x1EC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1EC4);
    // 0x8038CC30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cc34(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cc34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CC3C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8038CC40: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    // 0x8038CC44: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038CC48: bc1f        L_8038CC9C
    if (!c1cs) {
        // 0x8038CC4C: nop
    
            goto L_8038CC9C;
    }
    // 0x8038CC4C: nop

    // 0x8038CC50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8038CC54: jal         0x801C0DE4
    // 0x8038CC58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x8038CC58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8038CC5C: beq         $v0, $zero, L_8038CC90
    if (ctx->r2 == 0) {
        // 0x8038CC60: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038CC90;
    }
    // 0x8038CC60: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CC64: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8038CC68: jal         0x801C0EB0
    // 0x8038CC6C: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x8038CC6C: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_1:
    // 0x8038CC70: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038CC74: jal         0x8038CD1C
    // 0x8038CC78: lw          $a0, -0x1EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1EC0);
    LOOKUP_FUNC(0x8038CD1C)(rdram, ctx);
        goto after_2;
    // 0x8038CC78: lw          $a0, -0x1EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1EC0);
    after_2:
    // 0x8038CC7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038CC80: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CC84: sw          $t6, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = ctx->r14;
    // 0x8038CC88: b           L_8038CCB4
    // 0x8038CC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8038CCB4;
    // 0x8038CC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CC90:
    // 0x8038CC90: sw          $zero, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = 0;
    // 0x8038CC94: b           L_8038CCB4
    // 0x8038CC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8038CCB4;
    // 0x8038CC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CC9C:
    // 0x8038CC9C: jal         0x8038CD1C
    // 0x8038CCA0: lw          $a0, -0x1EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1EC0);
    LOOKUP_FUNC(0x8038CD1C)(rdram, ctx);
        goto after_3;
    // 0x8038CCA0: lw          $a0, -0x1EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1EC0);
    after_3:
    // 0x8038CCA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8038CCA8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CCAC: sw          $t7, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = ctx->r15;
    // 0x8038CCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CCB4:
    // 0x8038CCB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CCB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CCBC: jr          $ra
    // 0x8038CCC0: nop

    return;
    // 0x8038CCC0: nop

;}
RECOMP_FUNC void M99_FUN_8038ccc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CCC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CCC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CCCC: jal         0x800178E8
    // 0x8038CCD0: nop

    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x8038CCD0: nop

    after_0:
    // 0x8038CCD4: beq         $v0, $zero, L_8038CCF0
    if (ctx->r2 == 0) {
        // 0x8038CCD8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8038CCF0;
    }
    // 0x8038CCD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8038CCDC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8038CCE0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CCE4: sw          $t6, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = ctx->r14;
    // 0x8038CCE8: b           L_8038CCFC
    // 0x8038CCEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8038CCFC;
    // 0x8038CCEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CCF0:
    // 0x8038CCF0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CCF4: sw          $t7, -0x1EC8($at)
    MEM_W(-0X1EC8, ctx->r1) = ctx->r15;
    // 0x8038CCF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CCFC:
    // 0x8038CCFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CD00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CD04: jr          $ra
    // 0x8038CD08: nop

    return;
    // 0x8038CD08: nop

;}
RECOMP_FUNC void M99_FUN_8038cd0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CD0C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CD10: sw          $zero, -0x1ECC($at)
    MEM_W(-0X1ECC, ctx->r1) = 0;
    // 0x8038CD14: jr          $ra
    // 0x8038CD18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8038CD18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cd1c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cd1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CD1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CD20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CD24: jal         0x800179B0
    // 0x8038CD28: nop

    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x8038CD28: nop

    after_0:
    // 0x8038CD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CD34: jr          $ra
    // 0x8038CD38: nop

    return;
    // 0x8038CD38: nop

;}
RECOMP_FUNC void M99_FUN_8038cd3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CD3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CD44: jal         0x800179B0
    // 0x8038CD48: nop

    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x8038CD48: nop

    after_0:
    // 0x8038CD4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CD50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8038CD54: sh          $zero, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = 0;
    // 0x8038CD58: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CD5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038CD60: sw          $t6, -0x2474($at)
    MEM_W(-0X2474, ctx->r1) = ctx->r14;
    // 0x8038CD64: jr          $ra
    // 0x8038CD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8038CD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cd6c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cd6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CD6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8038CD70: jr          $ra
    // 0x8038CD74: sh          $a0, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = ctx->r4;
    return;
    // 0x8038CD74: sh          $a0, -0x40BE($at)
    MEM_H(-0X40BE, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cd78(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cd78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CD78: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8038CD7C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8038CD80: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8038CD84: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CD88: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8038CD8C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8038CD90: div         $zero, $t0, $t9
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r25)));
    // 0x8038CD94: mflo        $t1
    ctx->r9 = lo;
    // 0x8038CD98: addiu       $v0, $v0, -0x2468
    ctx->r2 = ADD32(ctx->r2, -0X2468);
    // 0x8038CD9C: bne         $t9, $zero, L_8038CDA8
    if (ctx->r25 != 0) {
        // 0x8038CDA0: nop
    
            goto L_8038CDA8;
    }
    // 0x8038CDA0: nop

    // 0x8038CDA4: break       7
    do_break(2151206308);
L_8038CDA8:
    // 0x8038CDA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8038CDAC: bne         $t9, $at, L_8038CDC0
    if (ctx->r25 != ctx->r1) {
        // 0x8038CDB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8038CDC0;
    }
    // 0x8038CDB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038CDB4: bne         $t0, $at, L_8038CDC0
    if (ctx->r8 != ctx->r1) {
        // 0x8038CDB8: nop
    
            goto L_8038CDC0;
    }
    // 0x8038CDB8: nop

    // 0x8038CDBC: break       6
    do_break(2151206332);
L_8038CDC0:
    // 0x8038CDC0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CDC4: sw          $t1, -0x2458($at)
    MEM_W(-0X2458, ctx->r1) = ctx->r9;
    // 0x8038CDC8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8038CDCC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CDD0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8038CDD4: sw          $t2, -0x2454($at)
    MEM_W(-0X2454, ctx->r1) = ctx->r10;
    // 0x8038CDD8: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8038CDDC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CDE0: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8038CDE4: sw          $t3, -0x2450($at)
    MEM_W(-0X2450, ctx->r1) = ctx->r11;
    // 0x8038CDE8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CDEC: addiu       $t4, $t4, -0x31A8
    ctx->r12 = ADD32(ctx->r12, -0X31A8);
    // 0x8038CDF0: addiu       $t5, $t5, -0x318C
    ctx->r13 = ADD32(ctx->r13, -0X318C);
    // 0x8038CDF4: addiu       $t6, $t6, -0x30F0
    ctx->r14 = ADD32(ctx->r14, -0X30F0);
    // 0x8038CDF8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8038CDFC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8038CE00: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8038CE04: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CE08: sw          $zero, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = 0;
    // 0x8038CE0C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8038CE10: ori         $t7, $t7, 0x2222
    ctx->r15 = ctx->r15 | 0X2222;
    // 0x8038CE14: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CE18: jr          $ra
    // 0x8038CE1C: sw          $t7, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = ctx->r15;
    return;
    // 0x8038CE1C: sw          $t7, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ce20(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ce20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CE20: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CE24: lw          $t6, -0x245C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X245C);
    // 0x8038CE28: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ce2c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ce2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CE2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CE30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8038CE34: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8038CE38: lw          $t9, -0x2468($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2468);
    // 0x8038CE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CE40: jalr        $t9
    // 0x8038CE44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038CE44: nop

    after_0:
    // 0x8038CE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CE50: jr          $ra
    // 0x8038CE54: nop

    return;
    // 0x8038CE54: nop

;}
RECOMP_FUNC void M99_FUN_8038ce58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CE58: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CE5C: sw          $zero, -0x244C($at)
    MEM_W(-0X244C, ctx->r1) = 0;
    // 0x8038CE60: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CE64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038CE68: sw          $t6, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = ctx->r14;
    // 0x8038CE6C: jr          $ra
    // 0x8038CE70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8038CE70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ce74(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ce74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CE74: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038CE78: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CE7C: lw          $t6, -0x2458($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2458);
    // 0x8038CE80: lw          $v1, -0x244C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X244C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038ce84(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038ce84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CE84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CE8C: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8038CE90: beq         $at, $zero, L_8038CEDC
    if (ctx->r1 == 0) {
        // 0x8038CE94: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_8038CEDC;
    }
    // 0x8038CE94: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CE98: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CE9C: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8038CEA0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8038CEA4: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8038CEA8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8038CEAC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8038CEB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8038CEB4: lw          $t9, -0x2450($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2450);
    // 0x8038CEB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8038CEBC: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8038CEC0: beq         $at, $zero, L_8038CED0
    if (ctx->r1 == 0) {
        // 0x8038CEC4: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8038CED0;
    }
    // 0x8038CEC4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CEC8: b           L_8038CF00
    // 0x8038CECC: sw          $t1, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = ctx->r9;
        goto L_8038CF00;
    // 0x8038CECC: sw          $t1, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = ctx->r9;
L_8038CED0:
    // 0x8038CED0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CED4: b           L_8038CEF0
    // 0x8038CED8: sw          $zero, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = 0;
        goto L_8038CEF0;
    // 0x8038CED8: sw          $zero, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = 0;
L_8038CEDC:
    // 0x8038CEDC: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8038CEE0: jal         0x8038CD6C
    // 0x8038CEE4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038CEE4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x8038CEE8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8038CEEC: lw          $v1, -0x244C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X244C);
L_8038CEF0:
    // 0x8038CEF0: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8038CEF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CEF8: sw          $t2, -0x244C($at)
    MEM_W(-0X244C, ctx->r1) = ctx->r10;
    // 0x8038CEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8038CF00:
    // 0x8038CF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CF04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CF08: jr          $ra
    // 0x8038CF0C: nop

    return;
    // 0x8038CF0C: nop

;}
RECOMP_FUNC void M99_FUN_8038cf10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CF10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CF18: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CF1C: sw          $zero, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = 0;
    // 0x8038CF20: jal         0x8038CD6C
    // 0x8038CF24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038CF24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8038CF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8038CF34: jr          $ra
    // 0x8038CF38: nop

    return;
    // 0x8038CF38: nop

;}
RECOMP_FUNC void M99_FUN_8038cf3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CF3C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8038CF40: addiu       $v0, $v0, -0x2444
    ctx->r2 = ADD32(ctx->r2, -0X2444);
    // 0x8038CF44: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CF48: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038CF4C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038CF50: addiu       $t6, $t6, -0x3034
    ctx->r14 = ADD32(ctx->r14, -0X3034);
    // 0x8038CF54: addiu       $t7, $t7, -0x3018
    ctx->r15 = ADD32(ctx->r15, -0X3018);
    // 0x8038CF58: addiu       $t8, $t8, -0x2FE0
    ctx->r24 = ADD32(ctx->r24, -0X2FE0);
    // 0x8038CF5C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8038CF60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8038CF64: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8038CF68: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cf6c(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cf6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CF6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CF70: sw          $zero, -0x2438($at)
    MEM_W(-0X2438, ctx->r1) = 0;
    // 0x8038CF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CF78: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038CF7C: jal         0x8038CD6C
    // 0x8038CF80: sw          $a1, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = ctx->r5;
    LOOKUP_FUNC(0x8038CD6C)(rdram, ctx);
        goto after_0;
    // 0x8038CF80: sw          $a1, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = ctx->r5;
    after_0:
    // 0x8038CF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CF8C: jr          $ra
    // 0x8038CF90: nop

    return;
    // 0x8038CF90: nop

;}
RECOMP_FUNC void M99_FUN_8038cf94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CF94: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038CF98: lw          $t6, -0x2438($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2438);
    // 0x8038CF9C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038cfa0(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038cfa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038CFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038CFA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8038CFA8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8038CFAC: lw          $t9, -0x2444($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2444);
    // 0x8038CFB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038CFB4: jalr        $t9
    // 0x8038CFB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038CFB8: nop

    after_0:
    // 0x8038CFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038CFC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038CFC4: jr          $ra
    // 0x8038CFC8: nop

    return;
    // 0x8038CFC8: nop

;}
