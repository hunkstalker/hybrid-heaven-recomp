#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801cedd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEDD4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CEDD8: lw          $v0, -0x52D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52D4);
    // 0x801CEDDC: jr          $ra
    // 0x801CEDE0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801CEDE0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cede4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cede4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEDE4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CEDE8: lw          $t6, -0x52D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X52D4);
    // 0x801CEDEC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CEDF0: beq         $t6, $zero, L_801CEE00
    if (ctx->r14 == 0) {
            // 0x801CEDF4: nop

    LOOKUP_FUNC(0x801CEE00)(rdram, ctx);
    return;
    }
    // 0x801CEDF4: nop

    // 0x801CEDF8: jr          $ra
    // 0x801CEDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CEDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cee00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cee00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE00: lw          $t7, -0x52D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X52D8);
    // 0x801CEE04: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CEE08: beq         $t7, $zero, L_801CEE18
    if (ctx->r15 == 0) {
            // 0x801CEE0C: nop

    LOOKUP_FUNC(0x801CEE18)(rdram, ctx);
    return;
    }
    // 0x801CEE0C: nop

    // 0x801CEE10: jr          $ra
    // 0x801CEE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CEE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cee18(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cee18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE18: lw          $v0, -0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52CC);
    // 0x801CEE1C: jr          $ra
    // 0x801CEE20: nop

    return;
    // 0x801CEE20: nop

;}
RECOMP_FUNC void M24_FUN_801cee24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE24: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CEE28: jr          $ra
    // 0x801CEE2C: addiu       $v0, $v0, 0x11F8
    ctx->r2 = ADD32(ctx->r2, 0X11F8);
    return;
    // 0x801CEE2C: addiu       $v0, $v0, 0x11F8
    ctx->r2 = ADD32(ctx->r2, 0X11F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cee30(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cee30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE30: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CEE34: addiu       $v1, $v1, 0x1208
    ctx->r3 = ADD32(ctx->r3, 0X1208);
    // 0x801CEE38: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CEE3C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CEE40: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801CEE44: beql        $a0, $t6, L_801CEE58
    if (ctx->r4 == ctx->r14) {
        // 0x801CEE48: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801CEE58;
    }
    goto skip_0;
    // 0x801CEE48: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801CEE4C: jr          $ra
    // 0x801CEE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CEE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CEE54: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801CEE58:
    // 0x801CEE58: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801CEE5C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CEE60: jr          $ra
    // 0x801CEE64: nop

    return;
    // 0x801CEE64: nop

;}
RECOMP_FUNC void M24_FUN_801cee68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEE6C: jr          $ra
    // 0x801CEE70: sw          $a0, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = ctx->r4;
    return;
    // 0x801CEE70: sw          $a0, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cee74(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cee74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEE74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CEE78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CEE7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CEE80: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CEE84: beq         $a0, $zero, L_801CEEDC
    if (ctx->r4 == 0) {
        // 0x801CEE88: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801CEEDC;
    }
    // 0x801CEE88: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801CEE8C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CEE90: jal         0x80006214
    // 0x801CEE94: lw          $a0, 0x11F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11F0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CEE94: lw          $a0, 0x11F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11F0);
    after_0:
    // 0x801CEE98: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801CEE9C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801CEEA0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801CEEA4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CEEA8: lw          $a0, 0x11F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11F0);
    // 0x801CEEAC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CEEB0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CEEB4: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801CEEB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801CEEBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CEEC0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801CEEC4: jal         0x801C3370
    // 0x801CEEC8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801CEEC8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x801CEECC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CEED0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEED4: b           L_801CEEE4
    // 0x801CEED8: sw          $t9, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r25;
        goto L_801CEEE4;
    // 0x801CEED8: sw          $t9, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r25;
L_801CEEDC:
    // 0x801CEEDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEEE0: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
L_801CEEE4:
    // 0x801CEEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CEEE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CEEEC: jr          $ra
    // 0x801CEEF0: nop

    return;
    // 0x801CEEF0: nop

;}
RECOMP_FUNC void M24_FUN_801ceef4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEEF4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CEEF8: lw          $v0, -0x52C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52C4);
    // 0x801CEEFC: jr          $ra
    // 0x801CEF00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801CEF00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cef04(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cef04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEF04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEF08: jr          $ra
    // 0x801CEF0C: sw          $a0, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = ctx->r4;
    return;
    // 0x801CEF0C: sw          $a0, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cef10(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cef10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEF10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEF14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801CEF18: jr          $ra
    // 0x801CEF1C: sb          $a0, -0x52A4($at)
    MEM_B(-0X52A4, ctx->r1) = ctx->r4;
    return;
    // 0x801CEF1C: sb          $a0, -0x52A4($at)
    MEM_B(-0X52A4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cef20(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cef20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CEF20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CEF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CEF28: jal         0x801C0B2C
    // 0x801CEF2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CEF2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CEF30: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CEF34: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CEF38: lw          $t7, 0x121C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X121C);
    // 0x801CEF3C: lw          $t6, 0x1218($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1218);
    // 0x801CEF40: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801CEF44: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801CEF48: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801CEF4C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801CEF50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CEF54: jal         0x80034C24
    // 0x801CEF58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801CEF58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CEF5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CEF60: ldc1        $f4, -0x2BC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BC0);
    // 0x801CEF64: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CEF68: addiu       $a3, $a3, 0x1220
    ctx->r7 = ADD32(ctx->r7, 0X1220);
    // 0x801CEF6C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CEF70: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801CEF74: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CEF78: addiu       $t1, $t1, -0x529C
    ctx->r9 = ADD32(ctx->r9, -0X529C);
    // 0x801CEF7C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801CEF80: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801CEF84: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801CEF88: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CEF8C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801CEF90: nop

    // 0x801CEF94: bc1fl       L_801CF074
    if (!c1cs) {
        // 0x801CEF98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CF074;
    }
    goto skip_0;
    // 0x801CEF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CEF9C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801CEFA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CEFA4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CEFA8: beq         $v0, $zero, L_801CEFCC
    if (ctx->r2 == 0) {
        // 0x801CEFAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CEFCC;
    }
    // 0x801CEFAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CEFB0: beq         $v0, $at, L_801CEFE8
    if (ctx->r2 == ctx->r1) {
        // 0x801CEFB4: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_801CEFE8;
    }
    // 0x801CEFB4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CEFB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CEFBC: beq         $v0, $at, L_801CF008
    if (ctx->r2 == ctx->r1) {
        // 0x801CEFC0: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_801CF008;
    }
    // 0x801CEFC0: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801CEFC4: b           L_801CF028
    // 0x801CEFC8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801CF028;
    // 0x801CEFC8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CEFCC:
    // 0x801CEFCC: jal         0x8012D844
    // 0x801CEFD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801CEFD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CEFD4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CEFD8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CEFDC: addiu       $a3, $a3, 0x1220
    ctx->r7 = ADD32(ctx->r7, 0X1220);
    // 0x801CEFE0: b           L_801CF024
    // 0x801CEFE4: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
        goto L_801CF024;
    // 0x801CEFE4: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
L_801CEFE8:
    // 0x801CEFE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CEFEC: jal         0x8012D844
    // 0x801CEFF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801CEFF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801CEFF4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CEFF8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CEFFC: addiu       $a3, $a3, 0x1220
    ctx->r7 = ADD32(ctx->r7, 0X1220);
    // 0x801CF000: b           L_801CF024
    // 0x801CF004: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
        goto L_801CF024;
    // 0x801CF004: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
L_801CF008:
    // 0x801CF008: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CF00C: jal         0x8012D844
    // 0x801CF010: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801CF010: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801CF014: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF018: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF01C: addiu       $a3, $a3, 0x1220
    ctx->r7 = ADD32(ctx->r7, 0X1220);
    // 0x801CF020: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
L_801CF024:
    // 0x801CF024: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CF028:
    // 0x801CF028: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801CF02C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801CF030: bne         $at, $zero, L_801CF05C
    if (ctx->r1 != 0) {
        // 0x801CF034: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801CF05C;
    }
    // 0x801CF034: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801CF038: jal         0x801C0B2C
    // 0x801CF03C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801CF03C: nop

    after_5:
    // 0x801CF040: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF044: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF048: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF04C: addiu       $a3, $a3, 0x1220
    ctx->r7 = ADD32(ctx->r7, 0X1220);
    // 0x801CF050: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
    // 0x801CF054: sw          $v0, 0x1218($at)
    MEM_W(0X1218, ctx->r1) = ctx->r2;
    // 0x801CF058: sw          $v1, 0x121C($at)
    MEM_W(0X121C, ctx->r1) = ctx->r3;
L_801CF05C:
    // 0x801CF05C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801CF060: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801CF064: mfhi        $t3
    ctx->r11 = hi;
    // 0x801CF068: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801CF06C: nop

    // 0x801CF070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF074:
    // 0x801CF074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CF078: jr          $ra
    // 0x801CF07C: nop

    return;
    // 0x801CF07C: nop

;}
RECOMP_FUNC void M24_FUN_801cf080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF088: jal         0x80006214
    // 0x801CF08C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CF08C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF090: jal         0x801C354C
    // 0x801CF094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801CF094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801CF098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF09C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CF0A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0A4: sw          $t6, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r14;
    // 0x801CF0A8: jr          $ra
    // 0x801CF0AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CF0AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf0b0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf0b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF0B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0B4: sw          $a0, 0x1230($at)
    MEM_W(0X1230, ctx->r1) = ctx->r4;
    // 0x801CF0B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0BC: sw          $zero, -0x5204($at)
    MEM_W(-0X5204, ctx->r1) = 0;
    // 0x801CF0C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0C4: sw          $zero, -0x5200($at)
    MEM_W(-0X5200, ctx->r1) = 0;
    // 0x801CF0C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CF0D0: sw          $t6, -0x51F8($at)
    MEM_W(-0X51F8, ctx->r1) = ctx->r14;
    // 0x801CF0D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0D8: sw          $zero, -0x5220($at)
    MEM_W(-0X5220, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf0dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf0dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CF0E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0E4: sw          $zero, -0x521C($at)
    MEM_W(-0X521C, ctx->r1) = 0;
    // 0x801CF0E8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CF0EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CF0F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CF0F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF0F8: addiu       $t7, $t7, -0xEDC
    ctx->r15 = ADD32(ctx->r15, -0XEDC);
    // 0x801CF0FC: sw          $zero, -0x51F4($at)
    MEM_W(-0X51F4, ctx->r1) = 0;
    // 0x801CF100: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CF104: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF10C: jal         0x8013B570
    // 0x801CF110: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801CF110: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801CF114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CF118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CF11C: jr          $ra
    // 0x801CF120: nop

    return;
    // 0x801CF120: nop

;}
RECOMP_FUNC void M24_FUN_801cf124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF12C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CF130: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CF134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF138: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF13C: beq         $t6, $zero, L_801CF168
    if (ctx->r14 == 0) {
        // 0x801CF140: nop
    
            goto L_801CF168;
    }
    // 0x801CF140: nop

    // 0x801CF144: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF148: jal         0x8012D844
    // 0x801CF14C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801CF14C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF150: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CF158: jal         0x800058DC
    // 0x801CF15C: addiu       $a1, $a1, -0xE80
    ctx->r5 = ADD32(ctx->r5, -0XE80);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CF15C: addiu       $a1, $a1, -0xE80
    ctx->r5 = ADD32(ctx->r5, -0XE80);
    after_1:
    // 0x801CF160: b           L_801CF174
    // 0x801CF164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CF174;
    // 0x801CF164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF168:
    // 0x801CF168: jal         0x800058DC
    // 0x801CF16C: addiu       $a1, $a1, -0xEDC
    ctx->r5 = ADD32(ctx->r5, -0XEDC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CF16C: addiu       $a1, $a1, -0xEDC
    ctx->r5 = ADD32(ctx->r5, -0XEDC);
    after_2:
    // 0x801CF170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF174:
    // 0x801CF174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CF178: jr          $ra
    // 0x801CF17C: nop

    return;
    // 0x801CF17C: nop

;}
RECOMP_FUNC void M24_FUN_801cf180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CF184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CF188: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801CF18C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CF190: jal         0x801CC540
    // 0x801CF194: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801CF194: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CF198: beq         $v0, $zero, L_801CF1B8
    if (ctx->r2 == 0) {
        // 0x801CF19C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801CF1B8;
    }
    // 0x801CF19C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF1A0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF1A4: addiu       $a1, $a1, -0xE80
    ctx->r5 = ADD32(ctx->r5, -0XE80);
    // 0x801CF1A8: jal         0x800058DC
    // 0x801CF1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CF1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CF1B0: b           L_801CF3AC
    // 0x801CF1B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801CF3AC;
    // 0x801CF1B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CF1B8:
    // 0x801CF1B8: lw          $t6, -0x5204($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5204);
    // 0x801CF1BC: beq         $t6, $zero, L_801CF210
    if (ctx->r14 == 0) {
        // 0x801CF1C0: nop
    
            goto L_801CF210;
    }
    // 0x801CF1C0: nop

    // 0x801CF1C4: jal         0x80006214
    // 0x801CF1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801CF1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801CF1CC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF1D0: lw          $t7, -0x5204($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5204);
    // 0x801CF1D4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801CF1D8: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801CF1DC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801CF1E0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801CF1E4: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801CF1E8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CF1EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CF1F0: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801CF1F4: jal         0x8013A28C
    // 0x801CF1F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801CF1F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CF1FC: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801CF200: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CF204: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF208: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801CF20C: sw          $zero, -0x5204($at)
    MEM_W(-0X5204, ctx->r1) = 0;
L_801CF210:
    // 0x801CF210: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF214: lw          $v0, -0x5200($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5200);
    // 0x801CF218: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF21C: beq         $v0, $zero, L_801CF2E8
    if (ctx->r2 == 0) {
        // 0x801CF220: nop
    
            goto L_801CF2E8;
    }
    // 0x801CF220: nop

    // 0x801CF224: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801CF228: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801CF22C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CF230: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801CF234: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801CF238: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CF23C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CF240: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801CF244: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801CF248: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF24C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CF250: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CF254: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CF258: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CF25C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CF260: nop

    // 0x801CF264: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CF268: beql        $t4, $zero, L_801CF2B8
    if (ctx->r12 == 0) {
        // 0x801CF26C: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801CF2B8;
    }
    goto skip_0;
    // 0x801CF26C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801CF270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CF274: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CF278: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CF27C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CF280: nop

    // 0x801CF284: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CF288: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CF28C: nop

    // 0x801CF290: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CF294: bne         $t4, $zero, L_801CF2AC
    if (ctx->r12 != 0) {
        // 0x801CF298: nop
    
            goto L_801CF2AC;
    }
    // 0x801CF298: nop

    // 0x801CF29C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801CF2A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CF2A4: b           L_801CF2C4
    // 0x801CF2A8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801CF2C4;
    // 0x801CF2A8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801CF2AC:
    // 0x801CF2AC: b           L_801CF2C4
    // 0x801CF2B0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801CF2C4;
    // 0x801CF2B0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CF2B4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801CF2B8:
    // 0x801CF2B8: nop

    // 0x801CF2BC: bltz        $t4, L_801CF2AC
    if (SIGNED(ctx->r12) < 0) {
        // 0x801CF2C0: nop
    
            goto L_801CF2AC;
    }
    // 0x801CF2C0: nop

L_801CF2C4:
    // 0x801CF2C4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CF2C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CF2CC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801CF2D0: jal         0x80011140
    // 0x801CF2D4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801CF2D4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801CF2D8: beq         $v0, $zero, L_801CF360
    if (ctx->r2 == 0) {
        // 0x801CF2DC: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CF360;
    }
    // 0x801CF2DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF2E0: b           L_801CF360
    // 0x801CF2E4: sw          $zero, -0x5200($at)
    MEM_W(-0X5200, ctx->r1) = 0;
        goto L_801CF360;
    // 0x801CF2E4: sw          $zero, -0x5200($at)
    MEM_W(-0X5200, ctx->r1) = 0;
L_801CF2E8:
    // 0x801CF2E8: jal         0x80010550
    // 0x801CF2EC: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801CF2EC: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801CF2F0: beq         $v0, $zero, L_801CF308
    if (ctx->r2 == 0) {
        // 0x801CF2F4: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CF308;
    }
    // 0x801CF2F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF2F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CF2FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF300: b           L_801CF30C
    // 0x801CF304: sw          $t5, -0x51F8($at)
    MEM_W(-0X51F8, ctx->r1) = ctx->r13;
        goto L_801CF30C;
    // 0x801CF304: sw          $t5, -0x51F8($at)
    MEM_W(-0X51F8, ctx->r1) = ctx->r13;
L_801CF308:
    // 0x801CF308: sw          $zero, -0x51F8($at)
    MEM_W(-0X51F8, ctx->r1) = 0;
L_801CF30C:
    // 0x801CF30C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF310: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF314: addiu       $t6, $t6, 0x1248
    ctx->r14 = ADD32(ctx->r14, 0X1248);
    // 0x801CF318: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801CF31C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801CF320: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801CF324: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CF328: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801CF32C: addiu       $t2, $t2, 0x1238
    ctx->r10 = ADD32(ctx->r10, 0X1238);
    // 0x801CF330: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801CF334: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801CF338: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801CF33C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801CF340: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801CF344: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801CF348: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801CF34C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801CF350: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801CF354: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801CF358: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801CF35C: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801CF360:
    // 0x801CF360: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF364: lw          $t7, -0x5220($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5220);
    // 0x801CF368: beq         $t7, $zero, L_801CF378
    if (ctx->r15 == 0) {
        // 0x801CF36C: nop
    
            goto L_801CF378;
    }
    // 0x801CF36C: nop

    // 0x801CF370: jal         0x801CF5A0
    // 0x801CF374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CF5A0)(rdram, ctx);
        goto after_6;
    // 0x801CF374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801CF378:
    // 0x801CF378: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CF37C: lw          $t8, -0x521C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X521C);
    // 0x801CF380: beq         $t8, $zero, L_801CF390
    if (ctx->r24 == 0) {
        // 0x801CF384: nop
    
            goto L_801CF390;
    }
    // 0x801CF384: nop

    // 0x801CF388: jal         0x801CF700
    // 0x801CF38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CF700)(rdram, ctx);
        goto after_7;
    // 0x801CF38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_801CF390:
    // 0x801CF390: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF394: lw          $t6, -0x51F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51F4);
    // 0x801CF398: beql        $t6, $zero, L_801CF3AC
    if (ctx->r14 == 0) {
        // 0x801CF39C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801CF3AC;
    }
    goto skip_1;
    // 0x801CF39C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801CF3A0: jal         0x801CF860
    // 0x801CF3A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CF860)(rdram, ctx);
        goto after_8;
    // 0x801CF3A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801CF3A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CF3AC:
    // 0x801CF3AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801CF3B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CF3B4: jr          $ra
    // 0x801CF3B8: nop

    return;
    // 0x801CF3B8: nop

;}
RECOMP_FUNC void M24_FUN_801cf3bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF3BC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF3C0: lw          $v0, -0x5200($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5200);
    // 0x801CF3C4: jr          $ra
    // 0x801CF3C8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801CF3C8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf3cc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf3cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF3CC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF3D0: lw          $t6, -0x5200($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5200);
    // 0x801CF3D4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF3D8: beq         $t6, $zero, L_801CF3E8
    if (ctx->r14 == 0) {
            // 0x801CF3DC: nop

    LOOKUP_FUNC(0x801CF3E8)(rdram, ctx);
    return;
    }
    // 0x801CF3DC: nop

    // 0x801CF3E0: jr          $ra
    // 0x801CF3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CF3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf3e8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf3e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF3E8: lw          $t7, -0x5204($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5204);
    // 0x801CF3EC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF3F0: beq         $t7, $zero, L_801CF400
    if (ctx->r15 == 0) {
            // 0x801CF3F4: nop

    LOOKUP_FUNC(0x801CF400)(rdram, ctx);
    return;
    }
    // 0x801CF3F4: nop

    // 0x801CF3F8: jr          $ra
    // 0x801CF3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CF3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf400(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF400: lw          $v0, -0x51F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51F8);
    // 0x801CF404: jr          $ra
    // 0x801CF408: nop

    return;
    // 0x801CF408: nop

;}
RECOMP_FUNC void M24_FUN_801cf40c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF40C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF410: jr          $ra
    // 0x801CF414: addiu       $v0, $v0, 0x1238
    ctx->r2 = ADD32(ctx->r2, 0X1238);
    return;
    // 0x801CF414: addiu       $v0, $v0, 0x1238
    ctx->r2 = ADD32(ctx->r2, 0X1238);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf418(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF418: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CF41C: addiu       $v1, $v1, 0x1248
    ctx->r3 = ADD32(ctx->r3, 0X1248);
    // 0x801CF420: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CF424: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CF428: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801CF42C: beql        $a0, $t6, L_801CF440
    if (ctx->r4 == ctx->r14) {
        // 0x801CF430: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801CF440;
    }
    goto skip_0;
    // 0x801CF430: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801CF434: jr          $ra
    // 0x801CF438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CF438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CF43C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801CF440:
    // 0x801CF440: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801CF444: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CF448: jr          $ra
    // 0x801CF44C: nop

    return;
    // 0x801CF44C: nop

;}
RECOMP_FUNC void M24_FUN_801cf450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF450: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF454: addiu       $v0, $v0, -0x5220
    ctx->r2 = ADD32(ctx->r2, -0X5220);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf458(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF460: beq         $a0, $zero, L_801CF48C
    if (ctx->r4 == 0) {
        // 0x801CF464: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801CF48C;
    }
    // 0x801CF464: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801CF468: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF46C: jal         0x801C0B2C
    // 0x801CF470: sw          $zero, -0x51FC($at)
    MEM_W(-0X51FC, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CF470: sw          $zero, -0x51FC($at)
    MEM_W(-0X51FC, ctx->r1) = 0;
    after_0:
    // 0x801CF474: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF478: sw          $v0, 0x1258($at)
    MEM_W(0X1258, ctx->r1) = ctx->r2;
    // 0x801CF47C: sw          $v1, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->r3;
    // 0x801CF480: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF484: b           L_801CF4A0
    // 0x801CF488: sw          $zero, 0x1260($at)
    MEM_W(0X1260, ctx->r1) = 0;
        goto L_801CF4A0;
    // 0x801CF488: sw          $zero, 0x1260($at)
    MEM_W(0X1260, ctx->r1) = 0;
L_801CF48C:
    // 0x801CF48C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF490: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    // 0x801CF494: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF498: jal         0x8012D844
    // 0x801CF49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801CF49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801CF4A0:
    // 0x801CF4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CF4A8: jr          $ra
    // 0x801CF4AC: nop

    return;
    // 0x801CF4AC: nop

;}
RECOMP_FUNC void M24_FUN_801cf4b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF4B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF4B4: addiu       $v0, $v0, -0x521C
    ctx->r2 = ADD32(ctx->r2, -0X521C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf4b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf4b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF4B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF4C0: beq         $a0, $zero, L_801CF4F0
    if (ctx->r4 == 0) {
        // 0x801CF4C4: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801CF4F0;
    }
    // 0x801CF4C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801CF4C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801CF4CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF4D0: jal         0x801C0B2C
    // 0x801CF4D4: sw          $t7, -0x51FC($at)
    MEM_W(-0X51FC, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CF4D4: sw          $t7, -0x51FC($at)
    MEM_W(-0X51FC, ctx->r1) = ctx->r15;
    after_0:
    // 0x801CF4D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF4DC: sw          $v0, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r2;
    // 0x801CF4E0: sw          $v1, 0x126C($at)
    MEM_W(0X126C, ctx->r1) = ctx->r3;
    // 0x801CF4E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF4E8: b           L_801CF504
    // 0x801CF4EC: sw          $zero, 0x1270($at)
    MEM_W(0X1270, ctx->r1) = 0;
        goto L_801CF504;
    // 0x801CF4EC: sw          $zero, 0x1270($at)
    MEM_W(0X1270, ctx->r1) = 0;
L_801CF4F0:
    // 0x801CF4F0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF4F4: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    // 0x801CF4F8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF4FC: jal         0x8012D844
    // 0x801CF500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801CF500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801CF504:
    // 0x801CF504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CF50C: jr          $ra
    // 0x801CF510: nop

    return;
    // 0x801CF510: nop

;}
RECOMP_FUNC void M24_FUN_801cf514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CF518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CF51C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CF520: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CF524: beq         $a0, $zero, L_801CF578
    if (ctx->r4 == 0) {
        // 0x801CF528: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801CF578;
    }
    // 0x801CF528: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801CF52C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF530: jal         0x80006214
    // 0x801CF534: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CF534: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    after_0:
    // 0x801CF538: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801CF53C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801CF540: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF544: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    // 0x801CF548: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CF54C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CF550: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801CF554: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801CF558: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CF55C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CF560: jal         0x801C3370
    // 0x801CF564: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801CF564: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x801CF568: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CF56C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF570: b           L_801CF580
    // 0x801CF574: sw          $t8, -0x51F4($at)
    MEM_W(-0X51F4, ctx->r1) = ctx->r24;
        goto L_801CF580;
    // 0x801CF574: sw          $t8, -0x51F4($at)
    MEM_W(-0X51F4, ctx->r1) = ctx->r24;
L_801CF578:
    // 0x801CF578: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF57C: sw          $zero, -0x51F4($at)
    MEM_W(-0X51F4, ctx->r1) = 0;
L_801CF580:
    // 0x801CF580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CF584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CF588: jr          $ra
    // 0x801CF58C: nop

    return;
    // 0x801CF58C: nop

;}
RECOMP_FUNC void M24_FUN_801cf590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF590: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CF594: lw          $v0, -0x51F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51F4);
    // 0x801CF598: jr          $ra
    // 0x801CF59C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801CF59C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf5a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf5a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF5A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CF5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF5A8: jal         0x801C0B2C
    // 0x801CF5AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CF5AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF5B0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF5B4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF5B8: lw          $t7, 0x125C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X125C);
    // 0x801CF5BC: lw          $t6, 0x1258($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1258);
    // 0x801CF5C0: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801CF5C4: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801CF5C8: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801CF5CC: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801CF5D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CF5D4: jal         0x80034C24
    // 0x801CF5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801CF5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CF5DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF5E0: ldc1        $f4, -0x2BB0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BB0);
    // 0x801CF5E4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF5E8: addiu       $a3, $a3, 0x1260
    ctx->r7 = ADD32(ctx->r7, 0X1260);
    // 0x801CF5EC: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CF5F0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801CF5F4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CF5F8: addiu       $t1, $t1, -0x51F0
    ctx->r9 = ADD32(ctx->r9, -0X51F0);
    // 0x801CF5FC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801CF600: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801CF604: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801CF608: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CF60C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801CF610: nop

    // 0x801CF614: bc1fl       L_801CF6F4
    if (!c1cs) {
        // 0x801CF618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CF6F4;
    }
    goto skip_0;
    // 0x801CF618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CF61C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801CF620: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CF624: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF628: beq         $v0, $zero, L_801CF64C
    if (ctx->r2 == 0) {
        // 0x801CF62C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CF64C;
    }
    // 0x801CF62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF630: beq         $v0, $at, L_801CF668
    if (ctx->r2 == ctx->r1) {
        // 0x801CF634: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801CF668;
    }
    // 0x801CF634: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF638: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CF63C: beq         $v0, $at, L_801CF688
    if (ctx->r2 == ctx->r1) {
        // 0x801CF640: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801CF688;
    }
    // 0x801CF640: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF644: b           L_801CF6A8
    // 0x801CF648: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801CF6A8;
    // 0x801CF648: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CF64C:
    // 0x801CF64C: jal         0x8012D844
    // 0x801CF650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801CF650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CF654: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF658: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF65C: addiu       $a3, $a3, 0x1260
    ctx->r7 = ADD32(ctx->r7, 0X1260);
    // 0x801CF660: b           L_801CF6A4
    // 0x801CF664: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
        goto L_801CF6A4;
    // 0x801CF664: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
L_801CF668:
    // 0x801CF668: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CF66C: jal         0x8012D844
    // 0x801CF670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801CF670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801CF674: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF678: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF67C: addiu       $a3, $a3, 0x1260
    ctx->r7 = ADD32(ctx->r7, 0X1260);
    // 0x801CF680: b           L_801CF6A4
    // 0x801CF684: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
        goto L_801CF6A4;
    // 0x801CF684: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
L_801CF688:
    // 0x801CF688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CF68C: jal         0x8012D844
    // 0x801CF690: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801CF690: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801CF694: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF698: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF69C: addiu       $a3, $a3, 0x1260
    ctx->r7 = ADD32(ctx->r7, 0X1260);
    // 0x801CF6A0: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
L_801CF6A4:
    // 0x801CF6A4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CF6A8:
    // 0x801CF6A8: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801CF6AC: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801CF6B0: bne         $at, $zero, L_801CF6DC
    if (ctx->r1 != 0) {
        // 0x801CF6B4: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801CF6DC;
    }
    // 0x801CF6B4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801CF6B8: jal         0x801C0B2C
    // 0x801CF6BC: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801CF6BC: nop

    after_5:
    // 0x801CF6C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF6C4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF6C8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF6CC: addiu       $a3, $a3, 0x1260
    ctx->r7 = ADD32(ctx->r7, 0X1260);
    // 0x801CF6D0: lw          $a0, 0x1260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1260);
    // 0x801CF6D4: sw          $v0, 0x1258($at)
    MEM_W(0X1258, ctx->r1) = ctx->r2;
    // 0x801CF6D8: sw          $v1, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->r3;
L_801CF6DC:
    // 0x801CF6DC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801CF6E0: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801CF6E4: mfhi        $t3
    ctx->r11 = hi;
    // 0x801CF6E8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801CF6EC: nop

    // 0x801CF6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF6F4:
    // 0x801CF6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CF6F8: jr          $ra
    // 0x801CF6FC: nop

    return;
    // 0x801CF6FC: nop

;}
RECOMP_FUNC void M24_FUN_801cf700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CF704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF708: jal         0x801C0B2C
    // 0x801CF70C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801CF70C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF710: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CF714: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF718: lw          $t7, 0x126C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X126C);
    // 0x801CF71C: lw          $t6, 0x1268($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1268);
    // 0x801CF720: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801CF724: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801CF728: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801CF72C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801CF730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CF734: jal         0x80034C24
    // 0x801CF738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801CF738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801CF73C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF740: ldc1        $f4, -0x2BA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BA8);
    // 0x801CF744: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF748: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x801CF74C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801CF750: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801CF754: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CF758: addiu       $t1, $t1, -0x5178
    ctx->r9 = ADD32(ctx->r9, -0X5178);
    // 0x801CF75C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801CF760: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801CF764: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801CF768: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801CF76C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801CF770: nop

    // 0x801CF774: bc1fl       L_801CF854
    if (!c1cs) {
        // 0x801CF778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CF854;
    }
    goto skip_0;
    // 0x801CF778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CF77C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801CF780: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801CF784: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF788: beq         $v0, $zero, L_801CF7AC
    if (ctx->r2 == 0) {
        // 0x801CF78C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801CF7AC;
    }
    // 0x801CF78C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF790: beq         $v0, $at, L_801CF7C8
    if (ctx->r2 == ctx->r1) {
        // 0x801CF794: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801CF7C8;
    }
    // 0x801CF794: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801CF79C: beq         $v0, $at, L_801CF7E8
    if (ctx->r2 == ctx->r1) {
        // 0x801CF7A0: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801CF7E8;
    }
    // 0x801CF7A0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801CF7A4: b           L_801CF808
    // 0x801CF7A8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801CF808;
    // 0x801CF7A8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CF7AC:
    // 0x801CF7AC: jal         0x8012D844
    // 0x801CF7B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801CF7B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801CF7B4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF7B8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF7BC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x801CF7C0: b           L_801CF804
    // 0x801CF7C4: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
        goto L_801CF804;
    // 0x801CF7C4: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
L_801CF7C8:
    // 0x801CF7C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CF7CC: jal         0x8012D844
    // 0x801CF7D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801CF7D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801CF7D4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF7D8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF7DC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x801CF7E0: b           L_801CF804
    // 0x801CF7E4: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
        goto L_801CF804;
    // 0x801CF7E4: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
L_801CF7E8:
    // 0x801CF7E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CF7EC: jal         0x8012D844
    // 0x801CF7F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801CF7F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801CF7F4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF7F8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF7FC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x801CF800: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
L_801CF804:
    // 0x801CF804: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801CF808:
    // 0x801CF808: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x801CF80C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801CF810: bne         $at, $zero, L_801CF83C
    if (ctx->r1 != 0) {
        // 0x801CF814: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801CF83C;
    }
    // 0x801CF814: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801CF818: jal         0x801C0B2C
    // 0x801CF81C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801CF81C: nop

    after_5:
    // 0x801CF820: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF824: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CF828: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CF82C: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x801CF830: lw          $a0, 0x1270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1270);
    // 0x801CF834: sw          $v0, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r2;
    // 0x801CF838: sw          $v1, 0x126C($at)
    MEM_W(0X126C, ctx->r1) = ctx->r3;
L_801CF83C:
    // 0x801CF83C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801CF840: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801CF844: mfhi        $t3
    ctx->r11 = hi;
    // 0x801CF848: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801CF84C: nop

    // 0x801CF850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF854:
    // 0x801CF854: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CF858: jr          $ra
    // 0x801CF85C: nop

    return;
    // 0x801CF85C: nop

;}
RECOMP_FUNC void M24_FUN_801cf860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF868: jal         0x80006214
    // 0x801CF86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CF86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF870: jal         0x801C354C
    // 0x801CF874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801CF874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801CF878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CF87C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CF880: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF884: sw          $t6, -0x51F4($at)
    MEM_W(-0X51F4, ctx->r1) = ctx->r14;
    // 0x801CF888: jr          $ra
    // 0x801CF88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801CF88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf890(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF890: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF894: sw          $a0, -0x5150($at)
    MEM_W(-0X5150, ctx->r1) = ctx->r4;
    // 0x801CF898: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF89C: sw          $zero, -0x5134($at)
    MEM_W(-0X5134, ctx->r1) = 0;
    // 0x801CF8A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF8A4: sw          $zero, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cf8a8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cf8a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF8A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CF8AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF8B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CF8B4: sw          $t6, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r14;
    // 0x801CF8B8: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801CF8BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CF8C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801CF8C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CF8C8: addiu       $t7, $t7, -0x70C
    ctx->r15 = ADD32(ctx->r15, -0X70C);
    // 0x801CF8CC: sw          $zero, -0x510C($at)
    MEM_W(-0X510C, ctx->r1) = 0;
    // 0x801CF8D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801CF8D4: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    // 0x801CF8D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF8DC: jal         0x8013B570
    // 0x801CF8E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801CF8E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801CF8E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CF8E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CF8EC: jr          $ra
    // 0x801CF8F0: nop

    return;
    // 0x801CF8F0: nop

;}
RECOMP_FUNC void M24_FUN_801cf8f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF8F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF8F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF8FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CF900: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CF904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801CF908: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF90C: beq         $t6, $zero, L_801CF938
    if (ctx->r14 == 0) {
        // 0x801CF910: nop
    
            goto L_801CF938;
    }
    // 0x801CF910: nop

    // 0x801CF914: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801CF918: jal         0x8012D844
    // 0x801CF91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801CF91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801CF920: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CF924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CF928: jal         0x800058DC
    // 0x801CF92C: addiu       $a1, $a1, -0x6B0
    ctx->r5 = ADD32(ctx->r5, -0X6B0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CF92C: addiu       $a1, $a1, -0x6B0
    ctx->r5 = ADD32(ctx->r5, -0X6B0);
    after_1:
    // 0x801CF930: b           L_801CF944
    // 0x801CF934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CF944;
    // 0x801CF934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF938:
    // 0x801CF938: jal         0x800058DC
    // 0x801CF93C: addiu       $a1, $a1, -0x70C
    ctx->r5 = ADD32(ctx->r5, -0X70C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CF93C: addiu       $a1, $a1, -0x70C
    ctx->r5 = ADD32(ctx->r5, -0X70C);
    after_2:
    // 0x801CF940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CF944:
    // 0x801CF944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CF948: jr          $ra
    // 0x801CF94C: nop

    return;
    // 0x801CF94C: nop

;}
RECOMP_FUNC void M24_FUN_801cf950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CF950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CF954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CF958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CF95C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801CF960: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801CF964: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CF968: beq         $t6, $zero, L_801CFAA8
    if (ctx->r14 == 0) {
        // 0x801CF96C: nop
    
            goto L_801CFAA8;
    }
    // 0x801CF96C: nop

    // 0x801CF970: lw          $t7, -0x5118($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5118);
    // 0x801CF974: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CF978: addiu       $a2, $a2, -0x512C
    ctx->r6 = ADD32(ctx->r6, -0X512C);
    // 0x801CF97C: beq         $t7, $zero, L_801CFA7C
    if (ctx->r15 == 0) {
        // 0x801CF980: nop
    
            goto L_801CFA7C;
    }
    // 0x801CF980: nop

    // 0x801CF984: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801CF988: jal         0x80005FAC
    // 0x801CF98C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801CF98C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801CF990: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801CF994: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801CF998: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801CF99C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CF9A0: addiu       $v1, $v1, -0x511C
    ctx->r3 = ADD32(ctx->r3, -0X511C);
    // 0x801CF9A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801CF9A8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801CF9AC: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801CF9B0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801CF9B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CF9B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801CF9BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801CF9C0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801CF9C4: lw          $t4, 0x980($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X980);
    // 0x801CF9C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CF9CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CF9D0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801CF9D4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CF9D8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801CF9DC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801CF9E0: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801CF9E4: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801CF9E8: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801CF9EC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801CF9F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CF9F4: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801CF9F8: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801CF9FC: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801CFA00: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA04: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801CFA08: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801CFA0C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA10: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801CFA14: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801CFA18: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA1C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801CFA20: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801CFA24: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA28: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801CFA2C: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801CFA30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA34: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CFA38: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801CFA3C: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801CFA40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA44: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801CFA48: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801CFA4C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA50: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801CFA54: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801CFA58: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA5C: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801CFA60: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801CFA64: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801CFA68: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801CFA6C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801CFA70: lw          $t1, -0x5114($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5114);
    // 0x801CFA74: b           L_801CFA90
    // 0x801CFA78: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801CFA90;
    // 0x801CFA78: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801CFA7C:
    // 0x801CFA7C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CFA80: addiu       $v1, $v1, -0x511C
    ctx->r3 = ADD32(ctx->r3, -0X511C);
    // 0x801CFA84: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801CFA88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFA8C: sw          $zero, -0x5114($at)
    MEM_W(-0X5114, ctx->r1) = 0;
L_801CFA90:
    // 0x801CFA90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFA94: addiu       $a1, $a1, -0x538
    ctx->r5 = ADD32(ctx->r5, -0X538);
    // 0x801CFA98: jal         0x800058DC
    // 0x801CFA9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CFA9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801CFAA0: b           L_801CFABC
    // 0x801CFAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801CFABC;
    // 0x801CFAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CFAA8:
    // 0x801CFAA8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFAAC: addiu       $a1, $a1, -0x6B0
    ctx->r5 = ADD32(ctx->r5, -0X6B0);
    // 0x801CFAB0: jal         0x800058DC
    // 0x801CFAB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CFAB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801CFAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CFABC:
    // 0x801CFABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CFAC0: jr          $ra
    // 0x801CFAC4: nop

    return;
    // 0x801CFAC4: nop

;}
RECOMP_FUNC void M24_FUN_801cfac8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFAC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CFACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CFAD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801CFAD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CFAD8: jal         0x801CC540
    // 0x801CFADC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801CFADC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801CFAE0: beq         $v0, $zero, L_801CFB00
    if (ctx->r2 == 0) {
        // 0x801CFAE4: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801CFB00;
    }
    // 0x801CFAE4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CFAE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CFAEC: addiu       $a1, $a1, -0x538
    ctx->r5 = ADD32(ctx->r5, -0X538);
    // 0x801CFAF0: jal         0x800058DC
    // 0x801CFAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CFAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801CFAF8: b           L_801CFD18
    // 0x801CFAFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801CFD18;
    // 0x801CFAFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CFB00:
    // 0x801CFB00: lw          $t6, -0x5134($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5134);
    // 0x801CFB04: beq         $t6, $zero, L_801CFB58
    if (ctx->r14 == 0) {
        // 0x801CFB08: nop
    
            goto L_801CFB58;
    }
    // 0x801CFB08: nop

    // 0x801CFB0C: jal         0x80006214
    // 0x801CFB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801CFB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801CFB14: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CFB18: lw          $t7, -0x5134($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5134);
    // 0x801CFB1C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801CFB20: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801CFB24: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801CFB28: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801CFB2C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801CFB30: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801CFB34: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CFB38: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801CFB3C: jal         0x8013A28C
    // 0x801CFB40: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801CFB40: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801CFB44: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801CFB48: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CFB4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFB50: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801CFB54: sw          $zero, -0x5134($at)
    MEM_W(-0X5134, ctx->r1) = 0;
L_801CFB58:
    // 0x801CFB58: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFB5C: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x801CFB60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CFB64: beq         $v0, $zero, L_801CFC30
    if (ctx->r2 == 0) {
        // 0x801CFB68: nop
    
            goto L_801CFC30;
    }
    // 0x801CFB68: nop

    // 0x801CFB6C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801CFB70: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801CFB74: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801CFB78: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801CFB7C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801CFB80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CFB84: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CFB88: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801CFB8C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801CFB90: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801CFB94: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CFB98: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801CFB9C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CFBA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CFBA4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CFBA8: nop

    // 0x801CFBAC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CFBB0: beql        $t4, $zero, L_801CFC00
    if (ctx->r12 == 0) {
        // 0x801CFBB4: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801CFC00;
    }
    goto skip_0;
    // 0x801CFBB4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801CFBB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CFBBC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801CFBC0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CFBC4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801CFBC8: nop

    // 0x801CFBCC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CFBD0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801CFBD4: nop

    // 0x801CFBD8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801CFBDC: bne         $t4, $zero, L_801CFBF4
    if (ctx->r12 != 0) {
        // 0x801CFBE0: nop
    
            goto L_801CFBF4;
    }
    // 0x801CFBE0: nop

    // 0x801CFBE4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801CFBE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CFBEC: b           L_801CFC0C
    // 0x801CFBF0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801CFC0C;
    // 0x801CFBF0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801CFBF4:
    // 0x801CFBF4: b           L_801CFC0C
    // 0x801CFBF8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801CFC0C;
    // 0x801CFBF8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801CFBFC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801CFC00:
    // 0x801CFC00: nop

    // 0x801CFC04: bltz        $t4, L_801CFBF4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801CFC08: nop
    
            goto L_801CFBF4;
    }
    // 0x801CFC08: nop

L_801CFC0C:
    // 0x801CFC0C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801CFC10: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801CFC14: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801CFC18: jal         0x80011140
    // 0x801CFC1C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801CFC1C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801CFC20: beq         $v0, $zero, L_801CFCDC
    if (ctx->r2 == 0) {
        // 0x801CFC24: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CFCDC;
    }
    // 0x801CFC24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFC28: b           L_801CFCDC
    // 0x801CFC2C: sw          $zero, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = 0;
        goto L_801CFCDC;
    // 0x801CFC2C: sw          $zero, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = 0;
L_801CFC30:
    // 0x801CFC30: jal         0x80010550
    // 0x801CFC34: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801CFC34: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801CFC38: beq         $v0, $zero, L_801CFC50
    if (ctx->r2 == 0) {
        // 0x801CFC3C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801CFC50;
    }
    // 0x801CFC3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFC40: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801CFC44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFC48: b           L_801CFC54
    // 0x801CFC4C: sw          $t5, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r13;
        goto L_801CFC54;
    // 0x801CFC4C: sw          $t5, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r13;
L_801CFC50:
    // 0x801CFC50: sw          $zero, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = 0;
L_801CFC54:
    // 0x801CFC54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CFC58: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CFC5C: addiu       $t6, $t6, 0x1290
    ctx->r14 = ADD32(ctx->r14, 0X1290);
    // 0x801CFC60: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801CFC64: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CFC68: addiu       $t2, $t2, -0x3FD8
    ctx->r10 = ADD32(ctx->r10, -0X3FD8);
    // 0x801CFC6C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801CFC70: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CFC74: addiu       $t1, $t1, 0x1280
    ctx->r9 = ADD32(ctx->r9, 0X1280);
    // 0x801CFC78: lw          $t0, 0x5C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X5C);
    // 0x801CFC7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFC80: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CFC84: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x801CFC88: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x801CFC8C: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, 0X12A0);
    // 0x801CFC90: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x801CFC94: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x801CFC98: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x801CFC9C: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x801CFCA0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801CFCA4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801CFCA8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801CFCAC: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801CFCB0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x801CFCB4: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x801CFCB8: sw          $a1, -0x514C($at)
    MEM_W(-0X514C, ctx->r1) = ctx->r5;
    // 0x801CFCBC: jal         0x8013A334
    // 0x801CFCC0: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x801CFCC0: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    after_6:
    // 0x801CFCC4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CFCC8: addiu       $a0, $a0, 0x12B0
    ctx->r4 = ADD32(ctx->r4, 0X12B0);
    // 0x801CFCCC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CFCD0: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    // 0x801CFCD4: jal         0x8013A334
    // 0x801CFCD8: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_7;
    // 0x801CFCD8: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_7:
L_801CFCDC:
    // 0x801CFCDC: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801CFCE0: lw          $t5, -0x5118($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5118);
    // 0x801CFCE4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CFCE8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CFCEC: beq         $t5, $zero, L_801CFD00
    if (ctx->r13 == 0) {
        // 0x801CFCF0: lui         $t8, 0x801E
        ctx->r24 = S32(0X801E << 16);
            goto L_801CFD00;
    }
    // 0x801CFCF0: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CFCF4: lw          $t7, -0x5114($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5114);
    // 0x801CFCF8: lw          $t6, -0x511C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X511C);
    // 0x801CFCFC: sb          $t7, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r15;
L_801CFD00:
    // 0x801CFD00: lw          $t8, -0x510C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X510C);
    // 0x801CFD04: beql        $t8, $zero, L_801CFD18
    if (ctx->r24 == 0) {
        // 0x801CFD08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801CFD18;
    }
    goto skip_1;
    // 0x801CFD08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801CFD0C: jal         0x801CFE90
    // 0x801CFD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801CFE90)(rdram, ctx);
        goto after_8;
    // 0x801CFD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801CFD14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801CFD18:
    // 0x801CFD18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801CFD1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CFD20: jr          $ra
    // 0x801CFD24: nop

    return;
    // 0x801CFD24: nop

;}
RECOMP_FUNC void M24_FUN_801cfd28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFD2C: jr          $ra
    // 0x801CFD30: sw          $a0, -0x5118($at)
    MEM_W(-0X5118, ctx->r1) = ctx->r4;
    return;
    // 0x801CFD30: sw          $a0, -0x5118($at)
    MEM_W(-0X5118, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd34(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFD38: jr          $ra
    // 0x801CFD3C: sw          $a0, -0x5114($at)
    MEM_W(-0X5114, ctx->r1) = ctx->r4;
    return;
    // 0x801CFD3C: sw          $a0, -0x5114($at)
    MEM_W(-0X5114, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd40(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD40: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFD44: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x801CFD48: jr          $ra
    // 0x801CFD4C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801CFD4C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd50(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD50: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CFD54: lw          $t6, -0x5130($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5130);
    // 0x801CFD58: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CFD5C: beq         $t6, $zero, L_801CFD6C
    if (ctx->r14 == 0) {
            // 0x801CFD60: nop

    LOOKUP_FUNC(0x801CFD6C)(rdram, ctx);
    return;
    }
    // 0x801CFD60: nop

    // 0x801CFD64: jr          $ra
    // 0x801CFD68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CFD68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd6c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD6C: lw          $t7, -0x5134($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5134);
    // 0x801CFD70: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFD74: beq         $t7, $zero, L_801CFD84
    if (ctx->r15 == 0) {
            // 0x801CFD78: nop

    LOOKUP_FUNC(0x801CFD84)(rdram, ctx);
    return;
    }
    // 0x801CFD78: nop

    // 0x801CFD7C: jr          $ra
    // 0x801CFD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CFD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd84(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD84: lw          $v0, -0x5110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5110);
    // 0x801CFD88: jr          $ra
    // 0x801CFD8C: nop

    return;
    // 0x801CFD8C: nop

;}
RECOMP_FUNC void M24_FUN_801cfd90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD90: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFD94: jr          $ra
    // 0x801CFD98: addiu       $v0, $v0, 0x1280
    ctx->r2 = ADD32(ctx->r2, 0X1280);
    return;
    // 0x801CFD98: addiu       $v0, $v0, 0x1280
    ctx->r2 = ADD32(ctx->r2, 0X1280);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfd9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfd9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFD9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CFDA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CFDA4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801CFDA8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801CFDAC: beq         $a0, $zero, L_801CFE00
    if (ctx->r4 == 0) {
        // 0x801CFDB0: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801CFE00;
    }
    // 0x801CFDB0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801CFDB4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CFDB8: jal         0x80006214
    // 0x801CFDBC: lw          $a0, -0x5150($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5150);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801CFDBC: lw          $a0, -0x5150($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5150);
    after_0:
    // 0x801CFDC0: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801CFDC4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801CFDC8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CFDCC: lw          $a0, -0x5150($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5150);
    // 0x801CFDD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801CFDD4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801CFDD8: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801CFDDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801CFDE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801CFDE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801CFDE8: jal         0x801C3370
    // 0x801CFDEC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801CFDEC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x801CFDF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CFDF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFDF8: b           L_801CFE08
    // 0x801CFDFC: sw          $t8, -0x510C($at)
    MEM_W(-0X510C, ctx->r1) = ctx->r24;
        goto L_801CFE08;
    // 0x801CFDFC: sw          $t8, -0x510C($at)
    MEM_W(-0X510C, ctx->r1) = ctx->r24;
L_801CFE00:
    // 0x801CFE00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CFE04: sw          $zero, -0x510C($at)
    MEM_W(-0X510C, ctx->r1) = 0;
L_801CFE08:
    // 0x801CFE08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CFE0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CFE10: jr          $ra
    // 0x801CFE14: nop

    return;
    // 0x801CFE14: nop

;}
RECOMP_FUNC void M24_FUN_801cfe18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE18: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFE1C: lw          $v0, -0x510C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X510C);
    // 0x801CFE20: jr          $ra
    // 0x801CFE24: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801CFE24: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfe28(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfe28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE28: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CFE2C: addiu       $v1, $v1, 0x1290
    ctx->r3 = ADD32(ctx->r3, 0X1290);
    // 0x801CFE30: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CFE34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801CFE38: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801CFE3C: beql        $a0, $t6, L_801CFE50
    if (ctx->r4 == ctx->r14) {
        // 0x801CFE40: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801CFE50;
    }
    goto skip_0;
    // 0x801CFE40: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801CFE44: jr          $ra
    // 0x801CFE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801CFE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801CFE4C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801CFE50:
    // 0x801CFE50: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801CFE54: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801CFE58: jr          $ra
    // 0x801CFE5C: nop

    return;
    // 0x801CFE5C: nop

;}
RECOMP_FUNC void M24_FUN_801cfe60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE60: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFE64: jr          $ra
    // 0x801CFE68: lw          $v0, -0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5150);
    return;
    // 0x801CFE68: lw          $v0, -0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5150);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfe6c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfe6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE6C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFE70: jr          $ra
    // 0x801CFE74: lw          $v0, -0x514C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X514C);
    return;
    // 0x801CFE74: lw          $v0, -0x514C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X514C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfe78(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cfe78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CFE78: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CFE7C: jr          $ra
    // 0x801CFE80: addiu       $v0, $v0, 0x12A0
    ctx->r2 = ADD32(ctx->r2, 0X12A0);
    return;
    // 0x801CFE80: addiu       $v0, $v0, 0x12A0
    ctx->r2 = ADD32(ctx->r2, 0X12A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cfe84(rdram, ctx);
;}
